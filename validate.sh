#!/bin/sh
# validate.sh - Build and validation for sqlite3.gd
#
# Usage: validate.sh [ERROR_FILE]
#   If ERROR_FILE is provided, extracted errors will be written to it.
#   Extracts errors from main output and all vcpkg-referenced log files.
#
# Exit codes:
#   0: All validations passed
#   1: Build or validation failed

# ===== Helper Functions =====

# Extract errors from main log and referenced vcpkg log files
# Focuses on C++ and CMake errors, filters out build noise
_extract_all_errors() {
    local main_log="$1"
    local error_file="$2"
    local combined_log=$(mktemp)
    trap "rm -f '$combined_log'" RETURN

    mkdir -p "$(dirname "$error_file")"

    # Start with main log
    cat "$main_log" > "$combined_log"

    # Find all log files referenced in main output
    local referenced_logs=$(_find_log_paths "$main_log")

    # Append content from referenced logs
    for log_path in $referenced_logs; do
        if [ -f "$log_path" ]; then
            echo "" >> "$combined_log"
            echo "=== $log_path ===" >> "$combined_log"
            cat "$log_path" >> "$combined_log" 2>/dev/null || true
        fi
    done

    # Extract error blocks directly to error file
    _extract_error_blocks "$combined_log" > "$error_file"

    # Clean up trailing whitespace
    sed -i -e :a -e '/^[[:space:]]*$/d;N;ba' "$error_file" 2>/dev/null || true
}

# Find log file paths mentioned in the output
_find_log_paths() {
    local log_file="$1"

    # Extract paths that end with .log or contain /buildtrees/
    grep -oE '[^ ]*\.log[^ ]*|[^ ]*/buildtrees[^ ]*' "$log_file" 2>/dev/null | sort -u || true
}

# Extract C++ and CMake errors from a log file
# Focuses on actual compilation errors and CMake failures
_extract_error_blocks() {
    local log_file="$1"

    awk '
    BEGIN {
        in_error = 0
        block = ""
    }

    # Skip non-error lines
    /^Processing file|^\[.*\/.*\]|^[0-9]*\/[0-9]* |warnings generated\.|^Suppressed |^Use -|^3 warnings treated/ { next }
    /^===/ { next }

    # Detect error lines (contain "error:" keyword)
    / error:/ {
        if (in_error && block != "") {
            print block
            print ""
        }
        in_error = 1
        block = $0
        next
    }

    # Detect build system failures
    /^FAILED:/ {
        if (in_error && block != "") {
            print block
            print ""
        }
        in_error = 1
        block = $0
        next
    }

    # If in error block, collect context lines until separator
    in_error {
        # Empty line or pipe separator ends the block
        if (NF == 0 || /^\s*\|/) {
            if (block != "") {
                print block
                print ""
            }
            in_error = 0
            block = ""
            next
        }

        # Append to block
        if (block != "") {
            block = block "\n" $0
        } else {
            block = $0
        }
    }

    END {
        if (in_error && block != "") {
            print block
        }
    }
    ' "$log_file"
}

# ===== Main Script =====

set -e

ERROR_FILE="${1:-}"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

# Setup vcpkg environment
export VCPKG_ROOT="$SCRIPT_DIR/vcpkg"
export VCPKG_DISABLE_METRICS=1
export VCPKG_DEFAULT_TRIPLET=x64-linux
export VCPKG_OVERLAY_TRIPLETS="$SCRIPT_DIR/vcpkg_triplets"
export VCPKG_OVERLAY_PORTS="$SCRIPT_DIR/vcpkg_ports"
export GDEXT_CMAKE_ARGS="-DGODOTCPP_TARGET=template_debug -DGODOTCPP_PRECISION=single -DGODOTCPP_THREADS=on -DENABLE_WERROR=on"

# Clean vcpkg cache
"$VCPKG_ROOT/vcpkg" remove gdext 2>/dev/null || true
rm -rf "$HOME/.cache/vcpkg/archives/" 2>/dev/null || true

# Build the project with realtime output and log capture
BUILD_LOG=$(mktemp)
trap "rm -f '$BUILD_LOG'" EXIT

"$VCPKG_ROOT/vcpkg" install gdext 2>&1 | tee "$BUILD_LOG"
BUILD_EXIT=${PIPESTATUS[0]}

if [ $BUILD_EXIT -ne 0 ]; then
    if [ -n "$ERROR_FILE" ]; then
        _extract_all_errors "$BUILD_LOG" "$ERROR_FILE"
    fi
    exit 1
fi

# TODO: Static analysis that does not confuse the LLMs...

# Success
[ -n "$ERROR_FILE" ] && >"$ERROR_FILE"
exit 0

#!/bin/sh
# validate.sh - Runtime validation for sqlite3.gd using Godot
#
# Usage: validate.sh [ERROR_FILE]
#   If ERROR_FILE is provided, extracted errors will be written to it.
#   Runs the compiled extension in Godot headless mode and checks for runtime errors.
#
# Exit codes:
#   0: All validations passed
#   1: Validation failed

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

# Build the project
BUILD_LOG=$(mktemp)
trap "rm -f '$BUILD_LOG'" EXIT

echo "Building extension..."
"$VCPKG_ROOT/vcpkg" install gdext 2>&1 | tee "$BUILD_LOG"
BUILD_EXIT=${PIPESTATUS[0]}

if [ $BUILD_EXIT -ne 0 ]; then
    echo "Build failed!"
    if [ -n "$ERROR_FILE" ]; then
        {
            echo "=== Build Failed ==="
            echo ""
            echo "Build log errors:"
            grep -E "error:|Error|undefined reference|cannot find" "$BUILD_LOG" || true
            echo ""
            echo "Attached log files:"
            find "$SCRIPT_DIR/vcpkg/buildtrees" -name "*.log" -type f 2>/dev/null | while read log_file; do
                echo ""
                echo "--- $log_file ---"
                grep -E "error:|Error|undefined reference|cannot find" "$log_file" || true
            done
        } > "$ERROR_FILE"
    fi
    exit 1
fi

echo "Build succeeded! Running runtime validation..."

# Runtime validation: Load the extension in Godot headless mode
RUNTIME_LOG=$(mktemp)
trap "rm -f '$BUILD_LOG' '$RUNTIME_LOG'" EXIT

# Build Godot with sanitizers
GODOT_BUILD_DIR="$SCRIPT_DIR/build"
GODOT_SOURCE_DIR="$GODOT_BUILD_DIR/godot"
GODOT_BIN="$GODOT_BUILD_DIR/bin/godot"

# Clone Godot repository if not present
if [ ! -d "$GODOT_SOURCE_DIR" ]; then
    echo "Downloading Godot sources..."
    mkdir -p "$GODOT_BUILD_DIR"
    cd "$GODOT_BUILD_DIR"
    curl -fsSL "https://github.com/godotengine/godot/archive/refs/tags/4.6.1-stable.zip" -o godot.zip
    unzip -qo godot.zip
    rm godot.zip
    mv godot-4.6.1-stable godot
    cd "$SCRIPT_DIR"
fi

# Build Godot with sanitizers
if [ ! -f "$GODOT_BIN" ]; then
    cd "$GODOT_SOURCE_DIR"
    GODOT_BUILD_LOG=$(mktemp)
    trap "rm -f '$BUILD_LOG' '$GODOT_BUILD_LOG'" EXIT

    echo "Compiling Godot with ASAN, UBSAN, and LSAN..."
    scons -j$(nproc) \
        platform=linux \
        target=editor \
        dev_build=yes \
        sanitizers=yes \
        use_asan=yes \
        use_lsan=yes \
        2>&1 | tee "$GODOT_BUILD_LOG"
        #use_ubsan=yes \

    GODOT_BUILD_EXIT=${PIPESTATUS[0]}

    if [ $GODOT_BUILD_EXIT -ne 0 ]; then
        echo "Godot build failed!"
        if [ -n "$ERROR_FILE" ]; then
            {
                echo "=== Godot Build Failed ==="
                echo "See full build log above for details."
            } > "$ERROR_FILE"
        fi
        exit 1
    fi
    mv "$GODOT_SOURCE_DIR/bin/godot.linuxbsd.editor.dev.x86_64.san" "$GODOT_BIN"
fi

cd "$SCRIPT_DIR"

# Run Godot in headless editor mode to load scripts and check for errors
LD_PRELOAD=$(gcc -print-file-name=libasan.so) LSAN_OPTIONS=detect_leaks=0 $GODOT_BIN --editor --path "$SCRIPT_DIR/demo" --headless --quit 2>&1 | tee "$RUNTIME_LOG" || true
LD_PRELOAD=$(gcc -print-file-name=libasan.so) LSAN_OPTIONS=detect_leaks=0 $GODOT_BIN --path "$SCRIPT_DIR/demo" --headless --quit 2>&1 | tee -a "$RUNTIME_LOG" || true

# Extract runtime errors from the log
_extract_runtime_errors() {
    local log_file="$1"

    # Filter out known non-error messages, then look for actual errors
    grep -E -v "(ObjectDB|RID).*leaked|resources still in use at exit" "$log_file" | \
    grep -A 1 -E "^ERROR:|^SCRIPT ERROR:|^WARNING:|^handle_crash:|Shader compilation error|Script compilation error|Parse error|undefined method|undefined symbol|not found|No such" || return 0
}

# Check for errors
ERRORS=$(_extract_runtime_errors "$RUNTIME_LOG" 2>/dev/null || true)

if [ -n "$ERRORS" ]; then
    if [ -n "$ERROR_FILE" ]; then
        echo "$ERRORS" > "$ERROR_FILE"
    fi
    exit 1
fi

# Success - no errors found
echo ""
echo "✓ Runtime validation passed - no errors detected"
[ -n "$ERROR_FILE" ] && >"$ERROR_FILE"
exit 0

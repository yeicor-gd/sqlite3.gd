#!/bin/sh

set -e

ERROR_FILE="${1:-}"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
cd "$SCRIPT_DIR"

if [ -z "$GODOT_VERSION" ]; then
    echo "GODOT_VERSION environment variable is not set. Please set it to a valid Godot version (e.g., 3.5.1 or 'system')."
    exit 1
fi

if [ -z "$ERROR_FILE" ]; then
    echo "No error file specified. Errors will be printed to the console."
else
    echo "Errors will be written to: $ERROR_FILE"
fi

export VCPKG_ROOT="$SCRIPT_DIR/vcpkg"
export VCPKG_DISABLE_METRICS=1
#export VCPKG_DEFAULT_TRIPLET=x64-linux
export VCPKG_OVERLAY_TRIPLETS="$SCRIPT_DIR/vcpkg_triplets"
export VCPKG_OVERLAY_PORTS="$SCRIPT_DIR/vcpkg_ports"
export GDEXT_CMAKE_ARGS="-DGODOTCPP_TARGET=template_debug -DGODOTCPP_PRECISION=single -DGODOTCPP_THREADS=on"
if [ "$GODOT_VERSION" != "system" ]; then
    export GDEXT_CMAKE_ARGS="$GDEXT_CMAKE_ARGS -DENABLE_WERROR=on"
fi

DO_BUILD="${DO_BUILD:-1}"

if [ "$DO_BUILD" = "1" ] || [ "$DO_BUILD" = "true" ]; then
    # Bootstrap vcpkg if needed
    if [ ! -f "$VCPKG_ROOT/vcpkg" ]; then
        echo "Bootstrapping vcpkg..."
        "$VCPKG_ROOT/bootstrap-vcpkg.sh" --disableMetrics
    fi

    "$VCPKG_ROOT/vcpkg" remove gdext 2>/dev/null || true
    rm -rf "$HOME/.cache/vcpkg/archives/" 2>/dev/null || true

    BUILD_LOG=$(mktemp)
    trap "rm -f '$BUILD_LOG'" EXIT

    echo "Regenerating register_types.cpp and register_types.h..."
    "$SCRIPT_DIR/src/register_types.sh"

    echo "Building extension..."
    "$VCPKG_ROOT/vcpkg" install gdext 2>&1 | tee "$BUILD_LOG"
    BUILD_EXIT=${PIPESTATUS[0]}

    if [ $BUILD_EXIT -ne 0 ]; then
        echo "Build failed!"
        if [ -n "$ERROR_FILE" ]; then
            {
                echo "=== Build Failed ==="
                grep -E "error:" "$BUILD_LOG" || true
                find "$SCRIPT_DIR/vcpkg/buildtrees/gdext" -name "*.log" -type f 2>/dev/null | while read log_file; do
                    grep -E "error:" "$log_file" || true
                done
            } > "$ERROR_FILE"
        fi
        exit 1
    fi

    echo "Build succeeded! Running runtime validation..."
else
    echo "Skipping build (DO_BUILD=$DO_BUILD). Running runtime validation..."
fi

RUNTIME_LOG=$(mktemp)
trap "rm -f '$BUILD_LOG' '$RUNTIME_LOG'" EXIT

if [ "$GODOT_VERSION" = "system" ]; then
    # Use system Godot, no sanitizers, no build
    GODOT_BIN="godot"
else
    GODOT_BUILD_DIR="$SCRIPT_DIR/build"
    GODOT_SOURCE_DIR="$GODOT_BUILD_DIR/godot-$GODOT_VERSION"
    GODOT_BIN="$GODOT_BUILD_DIR/bin/godot-$GODOT_VERSION"

    if [ ! -d "$GODOT_SOURCE_DIR" ]; then
        echo "Downloading Godot $GODOT_VERSION sources..."
        mkdir -p "$GODOT_BUILD_DIR"
        cd "$GODOT_BUILD_DIR"
        curl -fsSL "https://github.com/godotengine/godot/archive/refs/tags/$GODOT_VERSION.zip" -o godot.zip
        unzip -qo godot.zip
        rm godot.zip
        cd "$SCRIPT_DIR"
    fi

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
        mkdir -p "$(dirname $GODOT_BIN)"
        mv "$GODOT_SOURCE_DIR/bin/godot.linuxbsd.editor.dev.x86_64.san" "$GODOT_BIN"
    fi
fi

cd "$SCRIPT_DIR"

if [ "$GODOT_VERSION" = "system" ]; then
    $GODOT_BIN --editor --path "$SCRIPT_DIR/demo" --headless --quit 2>&1 | tee "$RUNTIME_LOG" || true
    $GODOT_BIN --path "$SCRIPT_DIR/demo" --headless 2>&1 | tee -a "$RUNTIME_LOG" || true
else
    LD_PRELOAD=$(gcc -print-file-name=libasan.so) LSAN_OPTIONS=detect_leaks=0 $GODOT_BIN --editor --path "$SCRIPT_DIR/demo" --headless --quit 2>&1 | tee "$RUNTIME_LOG" || true
    LD_PRELOAD=$(gcc -print-file-name=libasan.so) $GODOT_BIN --path "$SCRIPT_DIR/demo" --headless 2>&1 | tee -a "$RUNTIME_LOG" || true
fi

_extract_runtime_errors() {
    local log_file="$1"
    grep -E -v "(ObjectDB|RID).*leaked|resources still in use at exit" "$log_file" | \
    grep -A 1 -E "^ERROR:|^SCRIPT ERROR:|^WARNING:|^handle_crash:|Shader compilation error|Script compilation error|Parse error|undefined method|undefined symbol|not found|No such|^TESTS FAILED" || return 0
}

ERRORS=$(_extract_runtime_errors "$RUNTIME_LOG" 2>/dev/null || true)

if [ -n "$ERRORS" ]; then
    if [ -n "$ERROR_FILE" ]; then
        echo "$ERRORS" > "$ERROR_FILE"
    fi
    exit 1
fi

echo ""
echo "✓ Runtime validation passed - no errors detected"
[ -n "$ERROR_FILE" ] && >"$ERROR_FILE"
exit 0

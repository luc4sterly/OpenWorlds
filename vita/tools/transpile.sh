#!/bin/bash
# Transpiles Java classes to a C++ project with Clearwing VM and builds it
# for this machine (host), to run and test what will later run on the Vita.
#
#   vita/tools/transpile.sh <work dir> <main class> <class dir or jar>...
#
# <work dir>/dist is the C++ project, <work dir>/build/dist the program.
# A config.json in <work dir> is used if present (Clearwing's options);
# otherwise runtime checks (null, bounds, division) stay on.
# Needs vita/tools/setup-clearwing.sh first, cmake, ninja, a C++20 compiler,
# zlib, zziplib and libffi (Debian/Ubuntu: zlib1g-dev libzzip-dev libffi-dev).
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
CW="${OPENWORLDS_CLEARWING_DIR:-$REPO/build/vita/clearwing}"
[ $# -ge 3 ] || { echo "usage: $0 <work dir> <main class> <classes>..." >&2; exit 2; }
WORK="$1"; MAIN="$2"; shift 2
[ -d "$CW/classes/transpiler" ] || { echo "run vita/tools/setup-clearwing.sh first" >&2; exit 1; }

mkdir -p "$WORK"
WORK="$(cd "$WORK" && pwd)"
[ -f "$WORK/config.json" ] || echo '{"useValueChecks": true}' > "$WORK/config.json"

# The runtime the transpiler scans (java/**, regexodus/**) is whatever is on its class path:
# our own runtime classes (vita/runtime, when built) go before Clearwing's.
CP="$(ls "$CW"/m2/*.jar | tr '\n' ':')$CW/classes/annotations:$CW/classes/transpiler"
[ -d "$REPO/build/vita/runtime" ] && CP="$CP:$REPO/build/vita/runtime"
CP="$CP:$CW/classes/runtime:$CW/src/runtime/res"

rm -rf "$WORK/dist"
if ! JAVA_TOOL_OPTIONS= java -Xmx6g -cp "$CP" com.thelogicmaster.clearwing.Transpiler \
      -i "$@" -o "$WORK/dist" -m "$MAIN" -c "$WORK/config.json" -p true > "$WORK/transpile.log" 2>&1; then
   grep -v "^Picked up" "$WORK/transpile.log" | tail -30
   exit 1
fi
echo "[transpile] $(find "$WORK/dist/src" -name '*.cpp' | wc -l | tr -d ' ') C++ files in $WORK/dist"

LAUNCHER=""
command -v ccache >/dev/null 2>&1 && LAUNCHER="-DCMAKE_CXX_COMPILER_LAUNCHER=ccache"
GEN=""
command -v ninja >/dev/null 2>&1 && GEN="-G Ninja"
cmake -S "$WORK/dist" -B "$WORK/build" $GEN -DCMAKE_BUILD_TYPE=Release $LAUNCHER > "$WORK/cmake.log" 2>&1 \
   || { tail -20 "$WORK/cmake.log"; exit 1; }
JOBS="${JOBS:-$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)}"
cmake --build "$WORK/build" -j "$JOBS" > "$WORK/build.log" 2>&1 \
   || { grep -m 20 "error" "$WORK/build.log"; exit 1; }
echo "[transpile] built $WORK/build/dist"

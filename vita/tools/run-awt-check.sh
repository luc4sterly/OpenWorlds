#!/bin/bash
# Builds our java.awt (vita/runtime) and runs vita/test/awt/AwtCheck on a
# desktop JVM limited to java.base, on a screen in memory.
#
#   vita/tools/run-awt-check.sh [picture dir]     (default build/vita/awt-check)
#
# The runtime is compiled against java.base alone (extracted from the JDK's
# jmods), so anything it uses beyond java.base and itself fails to build.
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
OUT="${1:-$REPO/build/vita/awt-check}"
JAVA_HOME_DIR="$(dirname "$(dirname "$(readlink -f "$(command -v javac)")")")"
BASE="$REPO/build/vita/javabase"
RT="$REPO/build/vita/runtime"
TESTCLS="$REPO/build/vita/awt-check-classes"
export JAVA_TOOL_OPTIONS=

if [ ! -d "$BASE/classes/java/lang" ]; then
   [ -f "$JAVA_HOME_DIR/jmods/java.base.jmod" ] || { echo "no jmods in $JAVA_HOME_DIR (a JDK with jmods is needed)" >&2; exit 1; }
   rm -rf "$BASE"
   mkdir -p "$BASE"
   jmod extract --dir "$BASE" "$JAVA_HOME_DIR/jmods/java.base.jmod"
   rm -f "$BASE/classes/module-info.class"
fi

rm -rf "$RT" "$TESTCLS"
mkdir -p "$RT" "$TESTCLS" "$OUT"
find "$REPO/vita/runtime/src" -name '*.java' > "$RT.sources"
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE/classes" -encoding UTF-8 -d "$RT" @"$RT.sources" 2>&1 \
   | grep -v "^Note:\|^warning: \[options\]" || true
[ -f "$RT/java/awt/Component.class" ] || { echo "the runtime did not build" >&2; exit 1; }
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE/classes:$RT" -encoding UTF-8 -d "$TESTCLS" "$REPO/vita/test/awt/AwtCheck.java" 2>&1 \
   | grep -v "^Note:\|^warning: \[options\]" || true

exec java --limit-modules java.base -Xbootclasspath/a:"$RT" -Dopenworlds.screen=headless \
   -Dopenworlds.fonts="$REPO/vita/runtime/fonts;/usr/share/fonts/truetype/liberation" \
   -cp "$TESTCLS" AwtCheck "$OUT"

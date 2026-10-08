#!/bin/bash
# Runs programs of vita/test/conformance on a desktop JVM twice: with the
# JDK's own classes and with ours (vita/runtime, on java.base alone), and
# compares the outputs. Quicker than run-conformance.sh (no transpiling) to
# check the parts of the runtime that are ours, javax.sound for one.
#
#   vita/tools/run-runtime-conformance.sh [Program...]   (default: SoundConformance)
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
WORK="$REPO/build/vita/runtime-conformance"
RT="$REPO/build/vita/runtime"
BASE="$REPO/build/vita/javabase/classes"
export JAVA_TOOL_OPTIONS=
PROGRAMS="$*"
[ -n "$PROGRAMS" ] || PROGRAMS="SoundConformance"
[ -d "$BASE/java/lang" ] || { echo "run vita/tools/run-awt-check.sh first (it extracts java.base)" >&2; exit 1; }

# our runtime, against java.base alone
rm -rf "$RT"; mkdir -p "$RT"
find "$REPO/vita/runtime/src" -name '*.java' > "$RT.sources"
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE" -encoding UTF-8 -d "$RT" @"$RT.sources" 2>&1 | grep -v "^Note:\|^warning: \[options\]" || true

rm -rf "$WORK"; mkdir -p "$WORK/jdk" "$WORK/ours"
SOURCES=""
for P in $PROGRAMS; do SOURCES="$SOURCES $REPO/vita/test/conformance/$P.java"; done
javac -nowarn --release 8 -encoding UTF-8 -d "$WORK/jdk" $SOURCES 2>&1 | grep -v "^warning\|^Note:" || true
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE:$RT" -encoding UTF-8 -d "$WORK/ours" $SOURCES 2>&1 \
   | grep -v "^warning\|^Note:" || true

FAILED=0
for P in $PROGRAMS; do
   rm -rf "$WORK/$P"; mkdir -p "$WORK/$P/jdk-dir" "$WORK/$P/ours-dir"
   java -Djava.awt.headless=true -cp "$WORK/jdk" "conformance.$P" "$WORK/$P/jdk-dir" "$REPO" > "$WORK/$P/jdk.txt" 2>&1 || true
   java --limit-modules java.base -Xbootclasspath/a:"$RT" -Dopenworlds.screen=headless -cp "$WORK/ours" "conformance.$P" "$WORK/$P/ours-dir" "$REPO" \
      > "$WORK/$P/ours.txt" 2>&1 || true
   if diff "$WORK/$P/jdk.txt" "$WORK/$P/ours.txt" > "$WORK/$P/diff.txt"; then
      echo "[runtime-conformance] $P OK: $(wc -l < "$WORK/$P/jdk.txt" | tr -d ' ') lines, ours the same as the JDK's"
   else
      echo "[runtime-conformance] $P: $(grep -c '^<' "$WORK/$P/diff.txt") lines differ (JDK <, ours >):"
      cat "$WORK/$P/diff.txt"
      FAILED=1
   fi
done
exit $FAILED

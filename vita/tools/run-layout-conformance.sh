#!/bin/bash
# Lays out the same components with the JDK's layout managers (headless)
# and with ours (vita/runtime on java.base alone) and shows the differences.
# Ours are JDK 1.4.2's; LayoutConformance.java lists the known differences
# with today's JDK.
#
#   vita/tools/run-layout-conformance.sh
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
WORK="$REPO/build/vita/layout-conformance"
RT="$REPO/build/vita/runtime"
export JAVA_TOOL_OPTIONS=
[ -f "$RT/java/awt/GridBagLayout.class" ] || { echo "build the runtime first: vita/tools/run-awt-check.sh" >&2; exit 1; }

rm -rf "$WORK"
mkdir -p "$WORK/jdk" "$WORK/ours"
javac -nowarn -d "$WORK/jdk" "$REPO/vita/test/awt/LayoutConformance.java"
javac -nowarn -source 8 -target 8 -bootclasspath "$REPO/build/vita/javabase/classes:$RT" -d "$WORK/ours" \
   "$REPO/vita/test/awt/LayoutConformance.java" 2>&1 | grep -v "^warning: \[options\]" || true
java -Djava.awt.headless=true -cp "$WORK/jdk" LayoutConformance > "$WORK/jdk.txt"
java --limit-modules java.base -Xbootclasspath/a:"$RT" -cp "$WORK/ours" LayoutConformance > "$WORK/ours.txt"
if diff "$WORK/jdk.txt" "$WORK/ours.txt" > "$WORK/diff.txt"; then
   echo "identical: $(wc -l < "$WORK/jdk.txt" | tr -d ' ') layouts"
else
   echo "$(grep -c '^<' "$WORK/diff.txt") of $(wc -l < "$WORK/jdk.txt" | tr -d ' ') layouts differ (JDK <, ours >):"
   cat "$WORK/diff.txt"
fi

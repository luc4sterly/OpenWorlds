#!/bin/bash
# Runs the programs of vita/test/conformance on a JVM and transpiled by
# Clearwing VM (built for this machine) and compares the outputs: they must
# be identical.
#
#   vita/tools/run-conformance.sh [Program...]     (default: all of them)
#
# Needs vita/tools/setup-clearwing.sh first (and what vita/tools/transpile.sh needs).
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
WORK="$REPO/build/vita/conformance"
PROGRAMS="$*"
[ -n "$PROGRAMS" ] || PROGRAMS="Conformance RuntimeConformance NetConformance SoundConformance"

rm -rf "$WORK/classes"; mkdir -p "$WORK/classes"
JAVA_TOOL_OPTIONS= javac -nowarn --release 8 -encoding UTF-8 -d "$WORK/classes" \
   "$REPO"/vita/test/conformance/*.java 2>&1 | grep -v "^warning\|^Picked up\|^Note:" || true

FAILED=0
for P in $PROGRAMS; do
   W="$WORK/$P"
   mkdir -p "$W"
   # each run gets an empty directory to work in (the programs that need one)
   rm -rf "$W/jvm-dir" "$W/native-dir"; mkdir -p "$W/jvm-dir" "$W/native-dir"
   JAVA_TOOL_OPTIONS= java -Dstdout.encoding=UTF-8 -cp "$WORK/classes" "conformance.$P" "$W/jvm-dir" "$REPO" > "$W/jvm.txt" 2> "$W/jvm.err"
   "$HERE/transpile.sh" "$W" "conformance.$P" "$WORK/classes"
   if ! timeout 120 "$W/build/dist" "$W/native-dir" "$REPO" > "$W/native.txt" 2> "$W/native.err"; then
      echo "[conformance] $P: the transpiled program failed"; tail "$W/native.txt" "$W/native.err"; FAILED=1; continue
   fi
   if diff "$W/jvm.txt" "$W/native.txt"; then
      echo "[conformance] $P OK: $(wc -l < "$W/jvm.txt" | tr -d ' ') lines, the same as on the JVM"
   else
      echo "[conformance] $P: the transpiled output differs from the JVM's (above: < JVM, > transpiled)"
      FAILED=1
   fi
done
exit $FAILED

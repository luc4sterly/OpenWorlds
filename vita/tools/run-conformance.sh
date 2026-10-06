#!/bin/bash
# Runs vita/test/conformance on a JVM and transpiled by Clearwing VM (built
# for this machine) and compares the two outputs: they must be identical.
#
#   vita/tools/run-conformance.sh
#
# Needs vita/tools/setup-clearwing.sh first (and what vita/tools/transpile.sh needs).
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
WORK="$REPO/build/vita/conformance"

rm -rf "$WORK/classes"; mkdir -p "$WORK/classes"
JAVA_TOOL_OPTIONS= javac -nowarn --release 8 -encoding UTF-8 -d "$WORK/classes" \
   "$REPO/vita/test/conformance/Conformance.java" 2>&1 | grep -v "^warning\|^Picked up" || true
java -Dstdout.encoding=UTF-8 -cp "$WORK/classes" conformance.Conformance > "$WORK/jvm.txt" 2> "$WORK/jvm.err"
"$HERE/transpile.sh" "$WORK" conformance.Conformance "$WORK/classes"
# The program prints everything at the end of its own buffered stdout
timeout 120 "$WORK/build/dist" > "$WORK/native.txt" 2> "$WORK/native.err" || { echo "[conformance] the transpiled program failed"; tail "$WORK/native.txt"; exit 1; }
if diff "$WORK/jvm.txt" "$WORK/native.txt"; then
   echo "[conformance] OK: $(wc -l < "$WORK/jvm.txt" | tr -d ' ') lines, the same as on the JVM"
else
   echo "[conformance] the transpiled output differs from the JVM's (above: < JVM, > transpiled)"
   exit 1
fi

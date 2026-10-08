#!/bin/bash
# Compares the runtime's character encodings (java.nio.charset.Coding of the
# patched Clearwing runtime) with the JDK's on random input, on a JVM.
#
#   vita/tools/run-coding-fuzz.sh
#
# Needs vita/tools/setup-clearwing.sh first (for the patched source).
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
SRC="$REPO/build/vita/clearwing/src/runtime/src/java/nio/charset/Coding.java"
WORK="$REPO/build/vita/coding-fuzz"
[ -f "$SRC" ] || { echo "run vita/tools/setup-clearwing.sh first" >&2; exit 1; }
rm -rf "$WORK"; mkdir -p "$WORK/src/codingtest" "$WORK/classes"
sed 's/^package java.nio.charset;/package codingtest;/' "$SRC" > "$WORK/src/codingtest/Coding.java"
cp "$REPO/vita/test/coding/CodingFuzz.java" "$WORK/src/codingtest/"
export JAVA_TOOL_OPTIONS=
javac -nowarn -d "$WORK/classes" "$WORK/src/codingtest/"*.java
exec java -cp "$WORK/classes" codingtest.CodingFuzz

#!/bin/bash
# Build reproducible del cliente ORIGINAL con el puente portable:
# copia source/ (pristino, Vineflower) + apply_mock.sh + bridge/ a
# editor/.build-gamma (ignorado por git, misma profundidad para que
# apply_mock.sh encuentre tools/ y docs/), aplica mock y puente, y compila
# a editor/.build-gamma/out. No modifica source/.
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
B="$REPO/editor/.build-gamma"
JDK="$REPO/tools/jdk/Contents/Home/bin"
[ -x "$JDK/javac" ] || JDK="$(dirname "$(command -v javac)")"
rm -rf "$B"
mkdir -p "$B"
cp -R "$HERE/source" "$HERE/bridge" "$HERE/apply_mock.sh" "$B/"
(cd "$B" && bash apply_mock.sh)
find "$B/source" -name '*.java' > "$B/sources.txt"
mkdir -p "$B/out"
"$JDK/javac" --release 8 -nowarn -encoding UTF-8 -d "$B/out" @"$B/sources.txt" 2>&1 | grep -v '^Note:' || true
n=$(find "$B/out" -name '*.class' | wc -l | tr -d ' ')
echo "clases compiladas: $n"
[ "$n" -gt 0 ]

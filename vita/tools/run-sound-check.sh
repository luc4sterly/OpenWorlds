#!/bin/bash
# Builds our runtime (vita/runtime) and runs vita/test/sound/SoundCheck on a
# desktop JVM limited to java.base, with the sound written to a WAV file
# (build/vita/sound-check/out.wav) instead of a sound card.
#
#   vita/tools/run-sound-check.sh
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
OUT="$REPO/build/vita/sound-check"
RT="$REPO/build/vita/runtime"
BASE="$REPO/build/vita/javabase/classes"
export JAVA_TOOL_OPTIONS=
[ -d "$BASE/java/lang" ] || { echo "run vita/tools/run-awt-check.sh first (it extracts java.base)" >&2; exit 1; }

rm -rf "$RT" "$OUT"
mkdir -p "$RT" "$OUT/classes"
find "$REPO/vita/runtime/src" -name '*.java' > "$RT.sources"
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE" -encoding UTF-8 -d "$RT" @"$RT.sources" 2>&1 | grep -v "^Note:\|^warning: \[options\]" || true
javac -nowarn -source 8 -target 8 -bootclasspath "$BASE:$RT" -encoding UTF-8 -d "$OUT/classes" "$REPO/vita/test/sound/SoundCheck.java" 2>&1 \
   | grep -v "^Note:\|^warning: \[options\]" || true
exec java --limit-modules java.base -Xbootclasspath/a:"$RT" -Dopenworlds.audio=wav:"$OUT/out.wav" -cp "$OUT/classes" SoundCheck

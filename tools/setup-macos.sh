#!/usr/bin/env bash
# setup-macos.sh — gets a Mac ready to develop OpenWorlds, WITHOUT Homebrew
# (Homebrew no longer supports Intel Macs). Everything stays inside the repo,
# gitignored, with no sudo and without touching /Library:
#
#   1. Checks for python3 (it comes with the Command Line Tools).
#   2. Portable JDK 25 (Eclipse Temurin, tar.gz from api.adoptium.net) in
#      tools/jdk/, checked by SHA-256. build_gamma.sh, run_gamma.sh and the
#      tools/ scripts put it first on the PATH by themselves.
#   3. Builds the formats/ readers and the original client with the bridge
#      (build_gamma.sh).
#
# Usage: tools/setup-macos.sh   (idempotent, can be run several times)
set -u
set -o pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
JDK_FEATURE=25
JDK_DIR="$ROOT/tools/jdk"
JDK_HOME="$JDK_DIR/Contents/Home"

case "$(uname -m)" in
   x86_64) ADOPT_ARCH="x64";;
   arm64) ADOPT_ARCH="aarch64";;
   *) echo "[setup] unsupported architecture: $(uname -m)"; exit 2;;
esac

echo "=== OpenWorlds setup macOS ($(uname -m), no Homebrew) ==="

# --- 1. python3 (Command Line Tools) ---
if /usr/bin/python3 --version >/dev/null 2>&1; then
   echo "[setup] python: $(/usr/bin/python3 --version 2>&1)"
else
   echo "[setup] python3 is missing: install the Command Line Tools with"
   echo "        xcode-select --install"
   echo "        and run this script again."
   exit 2
fi

# --- 2. JDK portable ---
if [ -x "$JDK_HOME/bin/java" ]; then
   echo "[setup] JDK already installed: $("$JDK_HOME/bin/java" -version 2>&1 | head -n 1)"
else
   API="https://api.adoptium.net/v3/assets/latest/$JDK_FEATURE/hotspot?architecture=$ADOPT_ARCH&image_type=jdk&os=mac&vendor=eclipse"
   META="$(curl -fsSL "$API" | /usr/bin/python3 -c '
import json, sys
p = json.load(sys.stdin)[0]["binary"]["package"]
print(p["link"], p["checksum"], p["name"])')" \
      || { echo "[setup] ERROR querying api.adoptium.net"; exit 3; }
   read -r URL SUM NAME <<<"$META"
   TMP="$(mktemp -d)"
   trap 'rm -rf "$TMP"' EXIT
   echo "[setup] downloading $NAME..."
   curl -fL --progress-bar -o "$TMP/$NAME" "$URL" \
      || { echo "[setup] ERROR downloading $URL"; exit 3; }
   echo "$SUM  $TMP/$NAME" | shasum -a 256 -c - >/dev/null \
      || { echo "[setup] ERROR: SHA-256 of $NAME does not match Adoptium's"; exit 3; }
   mkdir -p "$TMP/x"
   tar -xzf "$TMP/$NAME" -C "$TMP/x" || { echo "[setup] ERROR extracting $NAME"; exit 3; }
   # The tarball holds jdk-<ver>/Contents/Home: the whole bundle root is moved.
   SRC_HOME="$(find "$TMP/x" -maxdepth 3 -type d -path '*/Contents/Home' | head -n 1)"
   [ -n "$SRC_HOME" ] || { echo "[setup] ERROR: $NAME has no Contents/Home"; exit 3; }
   rm -rf "$JDK_DIR"
   mv "$(dirname "$(dirname "$SRC_HOME")")" "$JDK_DIR"
   echo "[setup] JDK installed: $("$JDK_HOME/bin/java" -version 2>&1 | head -n 1)"
fi
export JAVA_HOME="$JDK_HOME"
export PATH="$JAVA_HOME/bin:$PATH"

# --- 3. Build ---
echo "[setup] compiling formats/src..."
mkdir -p "$ROOT/formats/out"
# shellcheck disable=SC2046
javac -nowarn -encoding UTF-8 -d "$ROOT/formats/out" $(find "$ROOT/formats/src" -name "*.java") \
   || { echo "[setup] compilation ERROR"; exit 3; }
echo "[setup] compiling the original client with the bridge (build_gamma.sh)..."
bash "$ROOT/editor/worldsplayer_source_editor-main/build_gamma.sh" >/dev/null \
   || { echo "[setup] the bridge does not compile (editor/.build-gamma/javac.log)"; exit 3; }

echo ""
echo "=== OK. To play: tools/build-dist.sh and open build/dist/OpenWorlds/OpenWorlds.command ==="
echo "  (or the CI .zip; for diagnostics: editor/worldsplayer_source_editor-main/run_gamma.sh)"

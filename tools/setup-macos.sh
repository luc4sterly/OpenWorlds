#!/usr/bin/env bash
# setup-macos.sh — deja un Mac listo para desarrollar OpenWorlds, SIN Homebrew
# (Homebrew ya no soporta Macs Intel). Todo queda dentro del repo, gitignored,
# sin sudo ni tocar /Library:
#
#   1. Comprueba python3 (lo traen las Command Line Tools).
#   2. JDK 25 portable (Eclipse Temurin, tar.gz de api.adoptium.net) en
#      tools/jdk/, verificado por SHA-256. build_gamma.sh, run_gamma.sh y los
#      scripts de tools/ lo ponen por delante del PATH solos.
#   3. Compila los lectores de formats/ y el cliente original con el puente
#      (build_gamma.sh).
#
# Uso: tools/setup-macos.sh   (idempotente, se puede correr varias veces)
set -u
set -o pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
JDK_FEATURE=25
JDK_DIR="$ROOT/tools/jdk"
JDK_HOME="$JDK_DIR/Contents/Home"

case "$(uname -m)" in
   x86_64) ADOPT_ARCH="x64";;
   arm64) ADOPT_ARCH="aarch64";;
   *) echo "[setup] arquitectura no soportada: $(uname -m)"; exit 2;;
esac

echo "=== OpenWorlds setup macOS ($(uname -m), sin Homebrew) ==="

# --- 1. python3 (Command Line Tools) ---
if /usr/bin/python3 --version >/dev/null 2>&1; then
   echo "[setup] python: $(/usr/bin/python3 --version 2>&1)"
else
   echo "[setup] falta python3: instala las Command Line Tools con"
   echo "        xcode-select --install"
   echo "        y vuelve a correr este script."
   exit 2
fi

# --- 2. JDK portable ---
if [ -x "$JDK_HOME/bin/java" ]; then
   echo "[setup] JDK ya instalado: $("$JDK_HOME/bin/java" -version 2>&1 | head -n 1)"
else
   API="https://api.adoptium.net/v3/assets/latest/$JDK_FEATURE/hotspot?architecture=$ADOPT_ARCH&image_type=jdk&os=mac&vendor=eclipse"
   META="$(curl -fsSL "$API" | /usr/bin/python3 -c '
import json, sys
p = json.load(sys.stdin)[0]["binary"]["package"]
print(p["link"], p["checksum"], p["name"])')" \
      || { echo "[setup] ERROR consultando api.adoptium.net"; exit 3; }
   read -r URL SUM NAME <<<"$META"
   TMP="$(mktemp -d)"
   trap 'rm -rf "$TMP"' EXIT
   echo "[setup] descargando $NAME..."
   curl -fL --progress-bar -o "$TMP/$NAME" "$URL" \
      || { echo "[setup] ERROR descargando $URL"; exit 3; }
   echo "$SUM  $TMP/$NAME" | shasum -a 256 -c - >/dev/null \
      || { echo "[setup] ERROR: SHA-256 de $NAME no coincide con Adoptium"; exit 3; }
   mkdir -p "$TMP/x"
   tar -xzf "$TMP/$NAME" -C "$TMP/x" || { echo "[setup] ERROR extrayendo $NAME"; exit 3; }
   # El tar trae jdk-<ver>/Contents/Home: se mueve la raiz del bundle entera.
   SRC_HOME="$(find "$TMP/x" -maxdepth 3 -type d -path '*/Contents/Home' | head -n 1)"
   [ -n "$SRC_HOME" ] || { echo "[setup] ERROR: $NAME sin Contents/Home"; exit 3; }
   rm -rf "$JDK_DIR"
   mv "$(dirname "$(dirname "$SRC_HOME")")" "$JDK_DIR"
   echo "[setup] JDK instalado: $("$JDK_HOME/bin/java" -version 2>&1 | head -n 1)"
fi
export JAVA_HOME="$JDK_HOME"
export PATH="$JAVA_HOME/bin:$PATH"

# --- 3. Compilar ---
echo "[setup] compilando formats/src..."
mkdir -p "$ROOT/formats/out"
# shellcheck disable=SC2046
javac -nowarn -encoding UTF-8 -d "$ROOT/formats/out" $(find "$ROOT/formats/src" -name "*.java") \
   || { echo "[setup] ERROR de compilación"; exit 3; }
echo "[setup] compilando el cliente original con el puente (build_gamma.sh)..."
bash "$ROOT/editor/worldsplayer_source_editor-main/build_gamma.sh" >/dev/null \
   || { echo "[setup] el puente no compila (editor/.build-gamma/javac.log)"; exit 3; }

echo ""
echo "=== OK. Para jugar: tools/build-dist.sh y abre build/dist/OpenWorlds/OpenWorlds.command ==="
echo "  (o el .zip de la CI; para diagnóstico: editor/worldsplayer_source_editor-main/run_gamma.sh)"

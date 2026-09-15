#!/usr/bin/env bash
# setup-macos.sh — deja un Mac listo para desarrollar FreeWorlds, SIN Homebrew
# (Homebrew ya no soporta Macs Intel). Todo queda dentro del repo, gitignored,
# sin sudo ni tocar /Library:
#
#   1. Comprueba python3 (lo traen las Command Line Tools).
#   2. JDK 25 portable (Eclipse Temurin, tar.gz de api.adoptium.net) en
#      tools/jdk/, verificado por SHA-256. run-game.sh e install-launcher.sh
#      lo ponen por delante del PATH solos.
#   3. LWJGL 3.4.3: jars comunes + natives de la arquitectura de este Mac
#      (natives-macos en Intel, natives-macos-arm64 en Apple Silicon) en
#      tools/lwjgl/, verificados contra el .sha1 de Maven Central.
#   4. Compila client/src y corre la sonda WorldViewer --list-rooms.
#
# node no se instala: solo lo usa el harness RWX (tools/rwx-harness, ya
# 118/118) y tools/node es binario Linux. No hace falta para jugar.
#
# Uso: tools/setup-macos.sh   (idempotente, se puede correr varias veces)
set -u
set -o pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
JDK_FEATURE=25
JDK_DIR="$ROOT/tools/jdk"
JDK_HOME="$JDK_DIR/Contents/Home"
LWJGL_VER="3.4.3"
LWJGL_DIR="$ROOT/tools/lwjgl"

case "$(uname -m)" in
   x86_64) ADOPT_ARCH="x64"; LWJGL_NATIVES="natives-macos";;
   arm64) ADOPT_ARCH="aarch64"; LWJGL_NATIVES="natives-macos-arm64";;
   *) echo "[setup] arquitectura no soportada: $(uname -m)"; exit 2;;
esac

echo "=== FreeWorlds setup macOS ($(uname -m), sin Homebrew) ==="

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

# --- 3. LWJGL ---
mkdir -p "$LWJGL_DIR"
BASE="https://repo1.maven.org/maven2/org/lwjgl"
dl() { # dl url dest
   local url="$1" dest="$2" want got
   if [ -f "$dest" ]; then echo "[setup] ya existe: $(basename "$dest")"; return 0; fi
   echo "[setup] descargando $(basename "$dest")..."
   want="$(curl -fsSL "$url.sha1" | cut -c1-40)" \
      || { echo "[setup] ERROR descargando $url.sha1"; exit 3; }
   curl -fsSL -o "$dest.part" "$url" \
      || { rm -f "$dest.part"; echo "[setup] ERROR descargando $url"; exit 3; }
   got="$(shasum -a 1 "$dest.part" | cut -c1-40)"
   if [ "$want" != "$got" ]; then
      rm -f "$dest.part"; echo "[setup] ERROR: SHA-1 de $(basename "$dest") no coincide"; exit 3
   fi
   mv "$dest.part" "$dest"
}
for art in lwjgl lwjgl-glfw lwjgl-opengl; do
   dl "$BASE/$art/$LWJGL_VER/$art-$LWJGL_VER.jar" "$LWJGL_DIR/$art-$LWJGL_VER.jar"
   dl "$BASE/$art/$LWJGL_VER/$art-$LWJGL_VER-$LWJGL_NATIVES.jar" "$LWJGL_DIR/$art-$LWJGL_VER-$LWJGL_NATIVES.jar"
done

# --- 4. Compilar + sonda ---
WORLD="$ROOT/assets/WorldsPlayer/GroundZero/groundzero.world"
echo "[setup] compilando client/src..."
# shellcheck disable=SC2046
javac -cp "$LWJGL_DIR/*" -d "$ROOT/client/out" $(find "$ROOT/client/src" -name "*.java") \
   || { echo "[setup] ERROR de compilación"; exit 3; }
echo "[setup] sonda WorldViewer --list-rooms..."
java -XstartOnFirstThread -cp "$ROOT/client/out:$LWJGL_DIR/*" \
   net.freeworlds.render.WorldViewer "$WORLD" --list-rooms \
   || { echo "[setup] la sonda falló"; exit 3; }

echo ""
echo "=== OK. Para jugar: tools/run-game.sh ==="
echo "  (usa tools/jdk solo; GLFW en macOS exige -XstartOnFirstThread y run-game.sh ya lo pone)"

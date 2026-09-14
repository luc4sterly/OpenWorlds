#!/usr/bin/env bash
# setup-macos.sh — deja un Mac listo para desarrollar FreeWorlds.
#
# Hace (idempotente, se puede correr varias veces):
#   1. Verifica/instala Homebrew, JDK 25 (Temurin), node LTS, python3.
#   2. Descarga LWJGL 3.4.3 con natives de macOS (x64 + arm64) a tools/lwjgl/.
#      (Ese dir está gitignored: en Linux lleva natives-linux, en Mac
#      natives-macos — run-game.sh usa el wildcard tools/lwjgl/* tal cual.)
#   3. Instala deps npm del harness RWX (tools/rwx-harness) con el node
#      del sistema (NO tools/node, que es binario Linux ELF gitignored).
#   4. Compila client/src y corre sonda WorldViewer --list-rooms.
#
# Uso: tools/setup-macos.sh
set -u
set -o pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
LWJGL_VER="3.4.3"
LWJGL_DIR="$ROOT/tools/lwjgl"
ARCH="$(uname -m)"

echo "=== FreeWorlds setup macOS (arch: $ARCH) ==="

# --- 1. Homebrew ---
if ! command -v brew >/dev/null 2>&1; then
   echo "[setup] instalando Homebrew..."
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   if [ "$ARCH" = "arm64" ] && [ -x /opt/homebrew/bin/brew ]; then
      eval "$(/opt/homebrew/bin/brew shellenv)"
   fi
else
   echo "[setup] brew OK: $(brew --version | head -n 1)"
fi

# --- 2. JDK / node / python ---
for pkg in temurin node python3; do
   if brew list --cask "$pkg" >/dev/null 2>&1 || brew list "$pkg" >/dev/null 2>&1; then
      echo "[setup] $pkg ya instalado"
   else
      echo "[setup] instalando $pkg..."
      if [ "$pkg" = "temurin" ]; then
         brew install --cask temurin || brew install --cask temurin@25 || brew install openjdk@25
      else
         brew install "$pkg"
      fi
   fi
done
echo "[setup] java: $(java -version 2>&1 | head -n 1)"
echo "[setup] node: $(node --version 2>/dev/null || echo 'NO ENCONTRADO')"
echo "[setup] python: $(python3 --version 2>/dev/null || echo 'NO ENCONTRADO')"

# --- 3. LWJGL macOS natives ---
mkdir -p "$LWJGL_DIR"
BASE="https://repo1.maven.org/maven2/org/lwjgl"
dl() { # dl group/artifact/file
   local url="$1" dest="$2"
   if [ -f "$dest" ]; then echo "[setup] ya existe: $(basename "$dest")";
   else echo "[setup] descargando $(basename "$dest")..."; curl -fsSL -o "$dest" "$url"; fi
}
for mod in lwjgl glfw opengl; do
   if [ "$mod" = "lwjgl" ]; then art="lwjgl"; grp="org/lwjgl/lwjgl"; else art="lwjgl-$mod"; grp="org/lwjgl/lwjgl-$mod"; fi
   dl "$BASE/$grp/$LWJGL_VER/$art-$LWJGL_VER.jar" "$LWJGL_DIR/$art-$LWJGL_VER.jar"
   # Ambos classifiers: el Mac que sea usa el suyo, el otro queda inerte.
   dl "$BASE/$grp/$LWJGL_VER/$art-$LWJGL_VER-natives-macos.jar" "$LWJGL_DIR/$art-$LWJGL_VER-natives-macos.jar"
   dl "$BASE/$grp/$LWJGL_VER/$art-$LWJGL_VER-natives-macos-arm64.jar" "$LWJGL_DIR/$art-$LWJGL_VER-natives-macos-arm64.jar"
done

# --- 4. Harness RWX (node del sistema, no tools/node que es Linux) ---
if [ -f "$ROOT/tools/rwx-harness/package.json" ]; then
   echo "[setup] npm install en tools/rwx-harness..."
   (cd "$ROOT/tools/rwx-harness" && npm install)
fi

# --- 5. Compilar + sonda ---
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
echo "  (GLFW en macOS exige -XstartOnFirstThread; run-game.sh ya lo pone solo.)"

#!/usr/bin/env bash
# run-original.sh — arranca el cliente ORIGINAL WorldsPlayer 2004
# (bin/java.exe 1.4.2_05 + gamma.dll + RWL21.DLL reales) bajo Wine.
#
# No reimplementa nada: es el juego de verdad (RenderWare real,
# avatares reales, UI real). Lo unico anadido es el entorno:
# prefijo Wine + fuentes + Xvfb si no hay X.
#
# Uso:
#   tools/run-original.sh [--display :N] [--wine-prefix dir] [--client-dir dir]
#
# - Copia assets/WorldsPlayer a ~/.freeworlds-client (una vez; despues
#   reutiliza para no ensuciar el repo con logs/caches del original).
# - Sin X utilizable, levanta Xvfb propio (100-110) como run-game.sh.
# - La linea de arranque es la del propio run.exe original:
#   bin\javaw.exe -Xbootclasspath:... -cp .;lib\gammacls.zip
#   NET.worlds.console.Gamma -home . -dllpath bin
#   (se usa java.exe en vez de javaw.exe para ver el log en consola).
set -u
set -o pipefail

# readlink -f es GNU-only; en macOS se resuelve via cd/pwd.
if command -v greadlink >/dev/null 2>&1; then
   ROOT="$(greadlink -f "$(dirname "$0")/..")"
elif readlink -f "$(dirname "$0")/.." >/dev/null 2>&1; then
   ROOT="$(readlink -f "$(dirname "$0")/..")"
else
   ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
fi
if [ "$(uname -s)" = "Darwin" ]; then
   echo "[run-original] macOS: el cliente original 2004 (x86 Win32 + gamma.dll)"
   echo "  no corre con Wine vanilla en Apple Silicon. Opciones:"
   echo "  - CrossOver / Whisky / Parallels + Windows ARM, o"
   echo "  - usar tools/run-game.sh (visor portable, el camino principal)."
   echo "  Sigo solo si pasas --force-macos con tu Wine ya configurado."
   if [ "${1:-}" != "--force-macos" ]; then exit 2; fi
   shift
fi
CLIENT_HOME="$HOME/.freeworlds-client"
WINEPREFIX="$HOME/.wine-fw-orig"
DISPLAY_WANT=""

while [ $# -gt 0 ]; do
   case "$1" in
      --display) DISPLAY_WANT="$2"; shift 2;;
      --wine-prefix) WINEPREFIX="$2"; shift 2;;
      --client-dir) CLIENT_HOME="$2"; shift 2;;
      *) echo "uso: $0 [--display :N] [--wine-prefix dir] [--client-dir dir]"; exit 2;;
   esac
done

# --- cliente (copia privada, el original escribe logs/caches en su CWD) ---
if [ ! -f "$CLIENT_HOME/bin/java.exe" ]; then
   echo "[run-original] copiando cliente a $CLIENT_HOME (una vez)..."
   rm -rf "$CLIENT_HOME"
   cp -r "$ROOT/assets/WorldsPlayer" "$CLIENT_HOME"
fi

# --- prefijo Wine + fuentes (el cliente aborta sin C:\windows\Fonts) ---
export WINEPREFIX
export WINEDEBUG=-all
if [ ! -d "$WINEPREFIX/drive_c/windows" ]; then
   echo "[run-original] creando prefijo Wine en $WINEPREFIX..."
   timeout 100 winecfg >/dev/null 2>&1
fi
mkdir -p "$WINEPREFIX/drive_c/windows/Fonts"
if [ -z "$(ls "$WINEPREFIX/drive_c/windows/Fonts" 2>/dev/null)" ]; then
   echo "[run-original] instalando fuentes Liberation en el prefijo..."
   cp /usr/share/fonts/liberation-sans-fonts/*.ttf "$WINEPREFIX/drive_c/windows/Fonts/" 2>/dev/null \
   || cp /usr/share/fonts/*/*.ttf "$WINEPREFIX/drive_c/windows/Fonts/" 2>/dev/null \
   || { echo "[run-original] ERROR: no hay TTFs en /usr/share/fonts"; exit 3; }
fi

# --- display (igual que run-game.sh) ---
XVFB_PID=""
trap '[ -n "$XVFB_PID" ] && kill "$XVFB_PID" 2>/dev/null' EXIT
disp_ok() { [ -S "/tmp/.X11-unix/X${1#:}" ]; }
if [ -n "$DISPLAY_WANT" ]; then
   export DISPLAY="$DISPLAY_WANT"
fi
if [ -z "${DISPLAY:-}" ] || ! disp_ok "$DISPLAY"; then
   for n in $(seq 100 110); do
      if [ ! -S "/tmp/.X11-unix/X$n" ]; then
         Xvfb ":$n" -screen 0 1024x768x24 >/tmp/xvfb-run-original-$n.log 2>&1 &
         XVFB_PID=$!
         export DISPLAY=":$n"
         for _ in $(seq 1 50); do disp_ok "$DISPLAY" && break; sleep 0.2; done
         echo "[run-original] Xvfb propio en DISPLAY=$DISPLAY (pid $XVFB_PID)"
         break
      fi
   done
   if [ -z "${DISPLAY:-}" ] || ! disp_ok "$DISPLAY"; then
      echo "[run-original] ERROR: sin X utilizable y no se pudo levantar Xvfb"; exit 4
   fi
else
   echo "[run-original] usando DISPLAY=$DISPLAY existente"
fi

echo "[run-original] cliente: $CLIENT_HOME | prefijo: $WINEPREFIX | display: $DISPLAY"
echo "[run-original] sal del juego desde su propia ventana (Quit). Controles: flechas andar."
cd "$CLIENT_HOME"
# Linea original de run.exe (con java.exe para conservar la consola).
exec wine bin/java.exe \
   "-Xbootclasspath:lib\i18ncls.zip;lib\rt.jar" \
   "-cp" ".;lib\gammacls.zip" \
   NET.worlds.console.Gamma -home . -dllpath bin

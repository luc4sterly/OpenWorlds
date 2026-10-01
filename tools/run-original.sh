#!/usr/bin/env bash
# run-original.sh — starts the ORIGINAL 2004 WorldsPlayer client
# (the real bin/java.exe 1.4.2_05 + gamma.dll + RWL21.DLL) under Wine.
#
# It reimplements nothing: this is the real game (real RenderWare, real
# avatars, real UI). The only thing added is the environment: Wine
# prefix + fonts + Xvfb if there is no X.
#
# Usage:
#   tools/run-original.sh [--display :N] [--wine-prefix dir] [--client-dir dir]
#
# - Copies assets/WorldsPlayer to ~/.openworlds-client (once; afterwards it
#   reuses it, so the original's logs/caches don't litter the repo).
# - Without a usable X, starts its own Xvfb (100-110).
# - The command line is the original run.exe's own:
#   bin\javaw.exe -Xbootclasspath:... -cp .;lib\gammacls.zip
#   NET.worlds.console.Gamma -home . -dllpath bin
#   (java.exe is used instead of javaw.exe to see the log on the console).
set -u
set -o pipefail

# readlink -f is GNU-only; on macOS it is resolved via cd/pwd.
if command -v greadlink >/dev/null 2>&1; then
   ROOT="$(greadlink -f "$(dirname "$0")/..")"
elif readlink -f "$(dirname "$0")/.." >/dev/null 2>&1; then
   ROOT="$(readlink -f "$(dirname "$0")/..")"
else
   ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
fi
if [ "$(uname -s)" = "Darwin" ]; then
   echo "[run-original] macOS: the original 2004 client (x86 Win32 + gamma.dll)"
   echo "  does not run on vanilla Wine on Apple Silicon. Options:"
   echo "  - CrossOver / Whisky / Parallels + Windows ARM, or"
   echo "  - use the OpenWorlds launcher (tools/build-dist.sh) or run_gamma.sh: the"
   echo "    same client with the portable bridge, no Wine (the main path)."
   echo "  I only go on if you pass --force-macos with your Wine already set up."
   if [ "${1:-}" != "--force-macos" ]; then exit 2; fi
   shift
fi
CLIENT_HOME="$HOME/.openworlds-client"
WINEPREFIX="$HOME/.wine-fw-orig"
DISPLAY_WANT=""

while [ $# -gt 0 ]; do
   case "$1" in
      --display) DISPLAY_WANT="$2"; shift 2;;
      --wine-prefix) WINEPREFIX="$2"; shift 2;;
      --client-dir) CLIENT_HOME="$2"; shift 2;;
      *) echo "usage: $0 [--display :N] [--wine-prefix dir] [--client-dir dir]"; exit 2;;
   esac
done

# --- client (private copy, the original writes logs/caches into its CWD) ---
if [ ! -f "$CLIENT_HOME/bin/java.exe" ]; then
   echo "[run-original] copying the client to $CLIENT_HOME (once)..."
   rm -rf "$CLIENT_HOME"
   cp -r "$ROOT/assets/WorldsPlayer" "$CLIENT_HOME"
fi

# --- Wine prefix + fonts (the client aborts without C:\windows\Fonts) ---
export WINEPREFIX
export WINEDEBUG=-all
if [ ! -d "$WINEPREFIX/drive_c/windows" ]; then
   echo "[run-original] creating the Wine prefix in $WINEPREFIX..."
   timeout 100 winecfg >/dev/null 2>&1
fi
mkdir -p "$WINEPREFIX/drive_c/windows/Fonts"
if [ -z "$(ls "$WINEPREFIX/drive_c/windows/Fonts" 2>/dev/null)" ]; then
   echo "[run-original] installing the Liberation fonts in the prefix..."
   cp /usr/share/fonts/liberation-sans-fonts/*.ttf "$WINEPREFIX/drive_c/windows/Fonts/" 2>/dev/null \
   || cp /usr/share/fonts/*/*.ttf "$WINEPREFIX/drive_c/windows/Fonts/" 2>/dev/null \
   || { echo "[run-original] ERROR: no TTFs in /usr/share/fonts"; exit 3; }
fi

# --- display ---
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
         echo "[run-original] own Xvfb on DISPLAY=$DISPLAY (pid $XVFB_PID)"
         break
      fi
   done
   if [ -z "${DISPLAY:-}" ] || ! disp_ok "$DISPLAY"; then
      echo "[run-original] ERROR: no usable X and Xvfb could not be started"; exit 4
   fi
else
   echo "[run-original] using the existing DISPLAY=$DISPLAY"
fi

echo "[run-original] client: $CLIENT_HOME | prefix: $WINEPREFIX | display: $DISPLAY"
echo "[run-original] quit the game from its own window (Quit). Controls: arrow keys to walk."
cd "$CLIENT_HOME"
# The original run.exe command line (with java.exe to keep the console).
exec wine bin/java.exe \
   "-Xbootclasspath:lib\i18ncls.zip;lib\rt.jar" \
   "-cp" ".;lib\gammacls.zip" \
   NET.worlds.console.Gamma -home . -dllpath bin

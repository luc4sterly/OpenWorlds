#!/usr/bin/env bash
# install-launcher.sh — instala el icono "FreeWorlds" en el menú de
# aplicaciones (doble clic para jugar, sin abrir terminal).
#
# Lo que hace:
#   1. Compila client/src si hace falta (igual que run-game.sh --build).
#   2. Escribe ~/.local/share/applications/freeworlds.desktop con las
#      rutas ABSOLUTAS de este repo (Exec=.../tools/run-game.sh --detach).
#   3. Refresca la base de .desktop si hay update-desktop-database.
#
# Uso: tools/install-launcher.sh [--room SALA] [args extra del visor...]
#   P. ej.: tools/install-launcher.sh --room LizCave -- --inside
#   (todo lo que vaya tras -- se guarda tal cual en el icono).
set -u
# readlink -f es GNU-only; en macOS se resuelve via cd/pwd.
if command -v greadlink >/dev/null 2>&1; then
   ROOT="$(greadlink -f "$(dirname "$0")/..")"
elif readlink -f "$(dirname "$0")/.." >/dev/null 2>&1; then
   ROOT="$(readlink -f "$(dirname "$0")/..")"
else
   ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
fi
# JDK portable de tools/setup-macos.sh (ver run-game.sh).
if [ -x "$ROOT/tools/jdk/Contents/Home/bin/java" ]; then
   export JAVA_HOME="$ROOT/tools/jdk/Contents/Home"
   export PATH="$JAVA_HOME/bin:$PATH"
fi
if [ "$(uname -s)" = "Darwin" ]; then
   echo "[launcher] macOS no usa .desktop. Usa Spotlight/Automator, o lanza:"
   echo "  tools/run-game.sh $*"
   echo "Sonda de compilación igualmente válida — continúo con build+sonda."
fi
ROOM="Reception"
EXTRA=()
while [ $# -gt 0 ]; do
   case "$1" in
      --room) ROOM="$2"; shift 2;;
      --) shift; while [ $# -gt 0 ]; do EXTRA+=("$1"); shift; done;;
      *) EXTRA+=("$1"); shift;;
   esac
done

# --- compilar si hace falta + sonda sin ventana (nunca abre ventana:
# WorldViewer <world> --list-rooms solo lista y sale) ---
WORLD="$ROOT/assets/WorldsPlayer/GroundZero/groundzero.world"
if [ ! -f "$ROOT/client/out/net/freeworlds/render/WorldViewer.class" ] || \
   [ -n "$(find "$ROOT/client/src" -name '*.java' -newer "$ROOT/client/out/net/freeworlds/render/WorldViewer.class" 2>/dev/null)" ]; then
   echo "[launcher] compilando client/src..."
   # shellcheck disable=SC2046
   javac -cp "$ROOT/tools/lwjgl/*" -d "$ROOT/client/out" $(find "$ROOT/client/src" -name "*.java") \
      || { echo "[launcher] la compilación falló"; exit 3; }
fi
java -cp "$ROOT/client/out:$ROOT/tools/lwjgl/*" \
   net.freeworlds.render.WorldViewer "$WORLD" --list-rooms >/dev/null \
   || { echo "[launcher] la sonda falló; revisa rutas/clases"; exit 3; }

# PNG con arte real del juego (mejor que el .ico de Windows, que GNOME no
# siempre sabe leer). Si algún día se mueve, el icono cae al genérico.
ICON="$ROOT/docs/renders/world_spawn_reception_kiosk.png"
[ -f "$ICON" ] || ICON="applications-games"
APPDIR="$HOME/.local/share/applications"
mkdir -p "$APPDIR"
DESK="$APPDIR/freeworlds.desktop"
ARGS_STR=""
for a in ${EXTRA[@]+"${EXTRA[@]}"}; do ARGS_STR="$ARGS_STR $a"; done
cat > "$DESK" <<EOF
[Desktop Entry]
Type=Application
Name=FreeWorlds
Comment=Cliente preservado de Worlds Chat — GroundZero ($ROOM)
Exec=$ROOT/tools/run-game.sh $ROOM$ARGS_STR --detach
Icon=$ICON
Terminal=false
Categories=Game;
StartupNotify=false
EOF
chmod +x "$DESK"
command -v update-desktop-database >/dev/null && update-desktop-database "$APPDIR" 2>/dev/null
echo "[launcher] instalado: $DESK"
grep -E "^(Name|Exec)" "$DESK"
echo "[launcher] buscalo como 'FreeWorlds' en el menú de aplicaciones."

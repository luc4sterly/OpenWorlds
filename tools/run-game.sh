#!/usr/bin/env bash
# run-game.sh — lanza el visor jugable (WorldViewer) y lo logea.
#
# Uso:
#   tools/run-game.sh [sala] [args del WorldViewer...] [--log-dir dir] [--display :N] [--build] [--no-shot] [--detach]
#
# - Sin args: abre GroundZero en ventana, cámara interior en el spawn real
#   del cliente (worlds.ini RestartAt: Reception (1872,1229,150), mirando
#   al kiosko — ver worlds-chat-project.md, sección Z-up/spawn).
# - --detach: lanza en segundo plano y devuelve la terminal al instante
#   (imprime PID + log); sin --detach el juego bloquea la terminal hasta
#   ESC/salir, que es lo normal para ver sus mensajes en directo.
# - Con args: primer posicional no-flag = sala; resto pasa tal cual al
#   WorldViewer (--inside, --window, --screenshot, --eye/--look/--up...).
# - Si no hay X utilizable (DISPLAY ausente o sin socket), levanta un Xvfb
#   propio en el primer display libre 100-110 y lo mata al salir.
# - --build recompila client/src antes de lanzar.
# - En modo batch (con --screenshot/ALL/--list-rooms explícitos) añade
#   --screenshot logs/<sala>-<timestamp>.png salvo --no-shot.
# - Todo (cabecera con entorno + stdout/stderr del juego + resumen) queda en
#   logs/worldviewer-<sala>-<timestamp>.log. Imprime el tail al terminar.
#
# Ejemplos:
#   tools/run-game.sh                                     # ventana GroundZero (spawn real)
#   tools/run-game.sh LizCave --inside
#   tools/run-game.sh Reception --screenshot /tmp/r.png  # batch, sin ventana
set -u
set -o pipefail

# Portable repo-root resolution: readlink -f is GNU-only (fails on macOS).
# macOS: plain readlink without -f; fallback to cd/dirname.
resolve_root() {
   local src="$1"
   if command -v greadlink >/dev/null 2>&1; then
      greadlink -f "$src/.."
   elif readlink -f "$src/.." >/dev/null 2>&1; then
      readlink -f "$src/.."
   else
      (cd "$src/.." && pwd -P)
   fi
}
ROOT="$(resolve_root "$(dirname "$0")")"
IS_MAC=0
[ "$(uname -s)" = "Darwin" ] && IS_MAC=1
# JDK portable de tools/setup-macos.sh (sin Homebrew) por delante del PATH:
# en macOS /usr/bin/java es solo un stub que falla sin JDK instalado.
if [ -x "$ROOT/tools/jdk/Contents/Home/bin/java" ]; then
   export JAVA_HOME="$ROOT/tools/jdk/Contents/Home"
   export PATH="$JAVA_HOME/bin:$PATH"
fi
WORLD="$ROOT/assets/WorldsPlayer/GroundZero/groundzero.world"
ROOM="Reception"
LOGDIR="$ROOT/logs"
DISPLAY_WANT=""
BUILD=0
AUTOSHOT=1
DETACH=0
VIEWER_ARGS=()

# Parseo: primer posicional no-flag = sala; resto pasa al WorldViewer.
ARGS=()
while [ $# -gt 0 ]; do
   case "$1" in
      --log-dir) LOGDIR="$2"; shift 2;;
      --display) DISPLAY_WANT="$2"; shift 2;;
       --build) BUILD=1; shift;;
       --no-shot) AUTOSHOT=0; shift;;
       --detach) DETACH=1; shift;;
      --) shift; while [ $# -gt 0 ]; do ARGS+=("$1"); shift; done;;
      *) if [ "$ROOM" = "Reception" ] && [ ${#ARGS[@]} -eq 0 ] && [[ "$1" != -* ]]; then
            ROOM="$1"; shift
         else
            ARGS+=("$1"); shift
         fi;;
   esac
done

mkdir -p "$LOGDIR"
STAMP="$(date +%Y%m%d-%H%M%S)"
LOG="$LOGDIR/worldviewer-${ROOM}-${STAMP}.log"

# --- build opcional / auto ---
if [ "$BUILD" = 0 ]; then
   # Auto-recompila si hay fuentes mas nuevas que las clases (evita
   # ventanas "sin texturas" por binario stale tras un git pull/sesion).
   if [ -n "$(find "$ROOT/client/src" -name '*.java' -newer "$ROOT/client/out/net/freeworlds/render/WorldViewer.class" 2>/dev/null)" ]; then
      echo "[run-game] fuentes mas nuevas que clases: recompilando..."
      BUILD=1
   fi
fi
if [ "$BUILD" = 1 ]; then
   echo "[run-game] compilando client/src..." | tee -a "$LOG"
   # shellcheck disable=SC2046
   javac -cp "$ROOT/tools/lwjgl/*" -d "$ROOT/client/out" $(find "$ROOT/client/src" -name "*.java") 2>&1 | tee -a "$LOG"
   if [ "${PIPESTATUS[0]}" -ne 0 ]; then echo "[run-game] ERROR de compilacion" | tee -a "$LOG"; exit 3; fi
fi
if [ ! -f "$ROOT/client/out/net/freeworlds/render/WorldViewer.class" ]; then
   echo "[run-game] ERROR: client/out sin compilar. Usa --build." | tee -a "$LOG"; exit 3
fi

# --- display: usar el pedido / existente, o levantar Xvfb propio ---
# macOS: GLFW abre ventana nativa (Cocoa), no hace falta X11/Xvfb nunca.
XVFB_PID=""
if [ "$IS_MAC" = 1 ]; then
   if [ -n "$DISPLAY_WANT" ]; then
      export DISPLAY="$DISPLAY_WANT"
   fi
   echo "[run-game] macOS detectado: ventana nativa Cocoa, sin Xvfb" | tee -a "$LOG"
else
# En --detach el juego sigue vivo al salir del script: no matar el Xvfb
# propio (se deja anotado en el log para matarlo a mano).
cleanup_xvfb() { [ "$DETACH" = 1 ] || { [ -n "$XVFB_PID" ] && kill "$XVFB_PID" 2>/dev/null; }; }
trap cleanup_xvfb EXIT
disp_ok() { [ -S "/tmp/.X11-unix/X${1#:}" ]; }
if [ -n "$DISPLAY_WANT" ]; then
   export DISPLAY="$DISPLAY_WANT"
fi
if [ -z "${DISPLAY:-}" ] || ! disp_ok "$DISPLAY"; then
   for n in $(seq 100 110); do
      if [ ! -S "/tmp/.X11-unix/X$n" ]; then
         Xvfb ":$n" -screen 0 1024x768x24 >/tmp/xvfb-run-game-$n.log 2>&1 &
         XVFB_PID=$!
         export DISPLAY=":$n"
         for _ in $(seq 1 50); do disp_ok "$DISPLAY" && break; sleep 0.2; done
         echo "[run-game] Xvfb propio en DISPLAY=$DISPLAY (pid $XVFB_PID)" | tee -a "$LOG"
         break
      fi
   done
   if [ -z "${DISPLAY:-}" ] || ! disp_ok "$DISPLAY"; then
      echo "[run-game] ERROR: sin X utilizable y no se pudo levantar Xvfb" | tee -a "$LOG"; exit 4
   fi
else
   echo "[run-game] usando DISPLAY=$DISPLAY existente" | tee -a "$LOG"
fi
fi

# --- screenshot automatico (solo modos batch de 1 sala sin salida propia) ---
# Sin args de visor: modo ventana GroundZero en el spawn real (no batch).
# Ventana normal (no fullscreen: el fullscreen provoco estado HIDDEN
# contra el VMware maximizado en esta maquina) + auto-focus via
# bring_to_front.py al aparecer.
if [ ${#ARGS[@]} -eq 0 ] && [ "$ROOM" = "Reception" ]; then
   ARGS=(--play)
   AUTOSHOT=0
   echo "[run-game] sin args: modo juego en spawn real Reception (avatar, WASD; ESC para salir)"
fi
HAS_OUT=0
# bash 3.2 de macOS + set -u: "${ARGS[@]}" vacio es "unbound variable";
# de ahi ${ARGS[@]+...} / ${ARGS[*]:-} en todo lo que corre en Mac.
for a in ${ARGS[@]+"${ARGS[@]}"}; do
   case "$a" in --screenshot|--screenshot-dir) HAS_OUT=1;; esac
done
if [ "$AUTOSHOT" = 1 ] && [ "$HAS_OUT" = 0 ]; then
   case " ${ARGS[*]:-} " in
      *" ALL "*|*" --list-rooms "*) ;;
      *) SHOT="$LOGDIR/${ROOM}-${STAMP}.png"
         ARGS+=(--screenshot "$SHOT");;
   esac
fi

# --- cabecera del log ---
{
echo "=== FreeWorlds run-game $(date +%Y-%m-%dT%H:%M:%S%z) ==="
echo "room: $ROOM"
echo "display: ${DISPLAY:-(macOS, sin X11)}"
echo "java: $(java -version 2>&1 | head -n 1)"
echo "git: $(git -C "$ROOT" rev-parse --short HEAD 2>/dev/null || echo ?) $(git -C "$ROOT" status --short | head -n 5 | tr '\n' ';')"
echo "cmd: java -cp client/out:tools/lwjgl/* net.freeworlds.render.WorldViewer $WORLD $ROOM ${ARGS[*]:-}"
echo "log: $LOG"
echo "--- juego ---"
} | tee -a "$LOG"

# --- lanzar y logear ---
# Si es modo ventana, traerla al frente sola cuando aparezca (en
# sesiones con varias areas de trabajo o apps maximizadas la ventana
# puede abrirse en otro escritorio o detras - verificado con xprop en
# esta maquina). El focuser espera hasta 30s (cubre la decodificacion
# de texturas al arrancar) y falla en silencio si no hay X.
# En macOS se omite: es X11-only, Cocoa trae su ventana al frente sola.
if [ "$IS_MAC" = 0 ]; then
case " ${ARGS[*]} " in
   *" --window "*|*" --fullscreen "*|*" --inside "*|*" --play "*)
      (python3 "$ROOT/tools/bring_to_front.py" --title "FreeWorlds World Viewer" >>"$LOG" 2>&1 &) ;;
esac
fi
if [ "$DETACH" = 1 ]; then
   # Fondo: la terminal vuelve al instante. El log queda en $LOG.
   # macOS: GLFW exige -XstartOnFirstThread en el hilo principal.
   MAC_OPTS=""
   [ "$IS_MAC" = 1 ] && MAC_OPTS="-XstartOnFirstThread"
   # shellcheck disable=SC2086
   nohup java $MAC_OPTS -cp "$ROOT/client/out:$ROOT/tools/lwjgl/*" \
      net.freeworlds.render.WorldViewer "$WORLD" "$ROOM" ${ARGS[@]+"${ARGS[@]}"} >>"$LOG" 2>&1 &
   PID=$!
   {
   echo "--- lanzado en fondo ---"
   echo "pid: $PID"
   echo "log: $LOG"
   [ -n "$XVFB_PID" ] && echo "xvfb: DISPLAY=$DISPLAY pid $XVFB_PID (matalo al terminar: kill $XVFB_PID $PID)"
   echo "para salir del juego: ESC en su ventana o kill $PID"
   } | tee -a "$LOG"
   exit 0
fi
# shellcheck disable=SC2086
if [ "$IS_MAC" = 1 ]; then
   java -XstartOnFirstThread -cp "$ROOT/client/out:$ROOT/tools/lwjgl/*" \
      net.freeworlds.render.WorldViewer "$WORLD" "$ROOM" ${ARGS[@]+"${ARGS[@]}"} 2>&1 | tee -a "$LOG"
else
java -cp "$ROOT/client/out:$ROOT/tools/lwjgl/*" \
   net.freeworlds.render.WorldViewer "$WORLD" "$ROOM" ${ARGS[@]+"${ARGS[@]}"} 2>&1 | tee -a "$LOG"
fi
CODE=${PIPESTATUS[0]}

{
echo "--- resumen ---"
echo "exit: $CODE"
grep -E "^(Room|Interior camera|Drew|Screenshot written|Texture coverage)" "$LOG" | tail -n 8
} | tee -a "$LOG"

exit "$CODE"

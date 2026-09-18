#!/bin/bash
# Arranca el cliente ORIGINAL decompilado (NET.worlds.console.Gamma) con el
# puente portable de bridge/, desde una copia de la instalacion 2004
# (assets/WorldsPlayer) para no escribir en el repo. Requiere haber
# ejecutado build_gamma.sh (ver bridge/README.md).
#
# Uso: editor/worldsplayer_source_editor-main/run_gamma.sh [URL_DE_MUNDO]
#   sin URL arranca como el original (home:NewWorld.world hasta el login);
#   p. ej. home:GroundZero/groundzero.world entra directo en GroundZero
#   (argumento de linea de comandos del propio Gamma.main).
# Directorio de trabajo: $FREEWORLDS_GAMMA_DIR o $TMPDIR/freeworlds-gamma.
# Diagnostico: JAVA_OPTS="-Dfreeworlds.dumpFrames=DIR [-Dfreeworlds.dumpSeconds=10,20]
#   [-Dfreeworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...]" (ver bridge/README.md).
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
JAVA="$REPO/tools/jdk/Contents/Home/bin/java"
[ -x "$JAVA" ] || JAVA=java
CWD="${FREEWORLDS_GAMMA_DIR:-${TMPDIR:-/tmp}/freeworlds-gamma}"
mkdir -p "$CWD"
# cachedir siempre desde el original: un cache.open huerfano de una salida sucia
# hace que el cliente descarte todo el indice.
rm -rf "$CWD/cachedir"
cp -R "$REPO/assets/WorldsPlayer/." "$CWD/"
cd "$CWD"

# El host original (us1.worlds.net) ya no existe: se levanta un servidor local
# (tools/local-upgrade-server.py) y la copia de worlds.ini apunta a el.
# FREEWORLDS_NO_LOCAL_SERVER=1 conserva el upgradeServer original.
if [ -z "${FREEWORLDS_NO_LOCAL_SERVER:-}" ]; then
   SRVLOG="$CWD/upgrade-server.log"
   python3 "$REPO/tools/local-upgrade-server.py" --root "$REPO/assets/WorldsPlayer" >"$SRVLOG.port" 2>"$SRVLOG" &
   SRV_PID=$!
   trap 'kill $SRV_PID 2>/dev/null' EXIT
   PORT=""
   for _ in $(seq 1 50); do
      PORT="$(sed -n 's/^PORT=//p' "$SRVLOG.port" 2>/dev/null)"
      [ -n "$PORT" ] && break
      sleep 0.1
   done
   [ -n "$PORT" ] || { echo "run_gamma: el servidor local no arranco (ver $SRVLOG)" >&2; exit 1; }
   for f in worlds.ini worlds.dst; do
      [ -f "$f" ] && sed -i.bak "s#^upgradeServer=.*#upgradeServer=http://127.0.0.1:$PORT/3DCDup#" "$f" && rm -f "$f.bak"
   done
   echo "run_gamma: upgradeServer local en http://127.0.0.1:$PORT/3DCDup (log: $SRVLOG)"
fi
"$JAVA" ${JAVA_OPTS:-} -cp ".:$REPO/editor/.build-gamma/out" NET.worlds.console.Gamma "$@"

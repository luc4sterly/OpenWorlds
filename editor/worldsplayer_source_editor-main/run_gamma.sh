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
# Directorio de trabajo: $OPENWORLDS_GAMMA_DIR o $TMPDIR/openworlds-gamma.
# Diagnostico: JAVA_OPTS="-Dopenworlds.dumpFrames=DIR [-Dopenworlds.dumpSeconds=10,20]
#   [-Dopenworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...]" (ver bridge/README.md).
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
JAVA="$REPO/tools/jdk/Contents/Home/bin/java"
[ -x "$JAVA" ] || JAVA=java
CWD="${OPENWORLDS_GAMMA_DIR:-${TMPDIR:-/tmp}/openworlds-gamma}"
mkdir -p "$CWD"
# cachedir siempre desde el original: un cache.open huerfano de una salida sucia
# hace que el cliente descarte todo el indice.
rm -rf "$CWD/cachedir"
cp -R "$REPO/assets/WorldsPlayer/." "$CWD/"
cd "$CWD"

# Servidor local de actualizaciones (tools/local-upgrade-server.py): sirve la
# instalacion de assets/ al instante y la copia de worlds.ini apunta a el. Lo
# que falta (paquetes de mundo, vestuario de avatares, el mapa del universo)
# lo pide al upgradeServer original, http://us1.worlds.net/3DCDup, que hoy es
# el espejo de LibreWorlds, y lo guarda en build/mirror-cache, como el
# lanzador. OPENWORLDS_MIRROR=URL usa otro espejo y OPENWORLDS_MIRROR=0 ninguno.
# OPENWORLDS_NO_LOCAL_SERVER=1 conserva el upgradeServer original.
if [ -z "${OPENWORLDS_NO_LOCAL_SERVER:-}" ]; then
   SRVLOG="$CWD/upgrade-server.log"
   MIRROR="${OPENWORLDS_MIRROR-$(sed -n 's/^[Uu]pgrade[Ss]erver=//p' worlds.ini 2>/dev/null | head -1 | tr -d '\r')}"
   case "$MIRROR" in 0|none|"") MIRROR_ARGS="" ;; *) MIRROR_ARGS="--mirror $MIRROR --cache $REPO/build/mirror-cache" ;; esac
   python3 "$REPO/tools/local-upgrade-server.py" --root "$REPO/assets/WorldsPlayer" $MIRROR_ARGS >"$SRVLOG.port" 2>"$SRVLOG" &
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
   echo "run_gamma: upgradeServer local en http://127.0.0.1:$PORT/3DCDup${MIRROR_ARGS:+, lo que falte de $MIRROR} (log: $SRVLOG)"
fi

# Consola: con LogFile=Gamma.Log en [Gamma] (worlds.ini) el cliente manda
# System.out/err a Gamma.Log.open (LogFile.open, como en 2004); desde que el
# mock de IniFile no distingue mayusculas esa clave si se encuentra. Los
# diagnosticos del arnes (-Dopenworlds.*) y los scripts (run-whirl-duo.sh...)
# leen la consola, asi que por defecto se vacia LogFile en la copia de trabajo
# (config, no logica: con LogFile vacio LogFile.open no redirige).
# OPENWORLDS_GAMMA_LOG=1 conserva el Gamma.Log original.
if [ -z "${OPENWORLDS_GAMMA_LOG:-}" ] && [ -f worlds.ini ]; then
   perl -pi -e 's/^logfile=[^\r\n]*/LogFile=/i' worlds.ini
fi

# WorldServer: OPENWORLDS_SERVER=host:puerto (p. ej. el whirl local de
# tools/run-whirl.sh) usa el mecanismo del propio cliente: la clave
# [Runtime] WorldServer= de override.ini (NetUpdate.<clinit>) sustituye en
# World.setWorldServerURL todo worldserver://www.3dcd.com[:puerto] (la URL por
# defecto de World.defaultServerURL, que es la que llevan los .world) por
# worldserver://host:puerto. Sin la variable, el original (www.3dcd.com ya no
# existe: el cliente acaba en modo monousuario, error #205).
# OPENWORLDS_USER=nombre deja ese usuario como User0 en la seccion [host:puerto]
# de worlds.ini, que es la que lee LoginWizard (Galaxy.getIniSection): la
# pantalla de entrada sale con el nombre puesto y sin contrasena guardada.
# OPENWORLDS_NETDEBUG=N pone netdebug=N en [Gamma] (bits de Galaxy/WorldServer
# .getDebugLevel(): 4 sessionInit, 32 tipo de servidor, 64 paquetes...).
if [ -n "${OPENWORLDS_SERVER:-}" ]; then
   python3 - "$OPENWORLDS_SERVER" "${OPENWORLDS_USER:-}" "${OPENWORLDS_NETDEBUG:-}" <<'PY'
import sys, re
server, user, netdebug = sys.argv[1], sys.argv[2], sys.argv[3]
def set_key(path, section, key, value):
    try:
        lines = open(path, newline="").read().splitlines()
    except FileNotFoundError:
        lines = []
    out, i, found_sec, done = [], 0, False, False
    for ln in lines:
        m = re.match(r"\s*\[(.*)\]\s*$", ln)
        if m and found_sec and not done:
            out.append("%s=%s" % (key, value)); done = True
        if m:
            found_sec = (m.group(1) == section)
        if found_sec and re.match(r"\s*%s\s*=" % re.escape(key), ln, re.I):
            if not done:
                out.append("%s=%s" % (key, value)); done = True
            continue
        out.append(ln)
    if not done:
        if not found_sec:
            out.append("[%s]" % section)
        out.append("%s=%s" % (key, value))
    open(path, "w", newline="").write("\r\n".join(out) + "\r\n")
set_key("override.ini", "Runtime", "WorldServer", "worldserver://" + server)
if user:
    set_key("worlds.ini", server, "User0", user)
if netdebug:
    set_key("worlds.ini", "Gamma", "netdebug", netdebug)
PY
   echo "run_gamma: WorldServer=worldserver://$OPENWORLDS_SERVER${OPENWORLDS_USER:+ (User0=$OPENWORLDS_USER)}"
fi

# OPENWORLDS_LOGIN=contrasena (arnes, solo contra un servidor local de pruebas)
# arranca por tools/net-probe/LoginDriver: rellena la contrasena en el
# LoginWizard real y pulsa su boton Sign-In con eventos AWT, como una persona.
# Ver docs/net-local-whirl.md. OPENWORLDS_CHAT=MS:texto;... escribe en la linea
# de chat y -Dopenworlds.dumpChat=MS,... vuelca el area de chat.
MAIN=NET.worlds.console.Gamma
CP=".:$REPO/editor/.build-gamma/out"
if [ -n "${OPENWORLDS_LOGIN:-}${OPENWORLDS_CHAT:-}" ]; then
   DRV="$REPO/editor/.build-gamma/net-probe-driver"
   mkdir -p "$DRV"
   "$(dirname "$JAVA")/javac" --release 8 -nowarn -encoding UTF-8 -cp "$REPO/editor/.build-gamma/out" \
      -d "$DRV" "$REPO/tools/net-probe/LoginDriver.java"
   CP="$CP:$DRV"
   MAIN=LoginDriver
fi
set +e
"$JAVA" ${JAVA_OPTS:-} -cp "$CP" $MAIN "$@"
RC=$?
# Instalar un mundo o una actualizacion: el cliente pide gdkup.exe y se
# cierra. gdkup.exe no corre fuera de Windows, asi que el puente deja la
# peticion en gdkup.pending (NativeSysProcess.createProcSpecial) y aqui se
# aplica con el gdkup en Java (NET.worlds.core.GdkUp). Con su codigo 10 el
# cliente se arranca otra vez con lo que pide la linea run.exe del guion
# (world:restart), como hace el lanzador (Session).
while [ -f gdkup.pending ]; do
   GARGS="$(tr -d '\r\n' < gdkup.pending)"
   rm -f gdkup.pending
   echo "run_gamma: actualizacion pendiente: gdkup $GARGS"
   "$JAVA" -cp "$REPO/editor/.build-gamma/out" NET.worlds.core.GdkUp $GARGS > gdkup.out 2>&1
   GRC=$?
   cat gdkup.out
   [ "$GRC" -eq 10 ] || break
   RESTART="$(sed -n 's/^\[gdkup\] reinicio: *//p' gdkup.out | tail -1)"
   echo "run_gamma: reinicio tras la actualizacion: ${RESTART:-world:restart}"
   "$JAVA" ${JAVA_OPTS:-} -cp "$CP" $MAIN ${RESTART:-world:restart}
   RC=$?
done
exit $RC

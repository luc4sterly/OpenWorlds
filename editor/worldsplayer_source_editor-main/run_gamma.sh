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

# Consola: con LogFile=Gamma.Log en [Gamma] (worlds.ini) el cliente manda
# System.out/err a Gamma.Log.open (LogFile.open, como en 2004); desde que el
# mock de IniFile no distingue mayusculas esa clave si se encuentra. Los
# diagnosticos del arnes (-Dfreeworlds.*) y los scripts (run-whirl-duo.sh...)
# leen la consola, asi que por defecto se vacia LogFile en la copia de trabajo
# (config, no logica: con LogFile vacio LogFile.open no redirige).
# FREEWORLDS_GAMMA_LOG=1 conserva el Gamma.Log original.
if [ -z "${FREEWORLDS_GAMMA_LOG:-}" ] && [ -f worlds.ini ]; then
   perl -pi -e 's/^logfile=[^\r\n]*/LogFile=/i' worlds.ini
fi

# WorldServer: FREEWORLDS_SERVER=host:puerto (p. ej. el whirl local de
# tools/run-whirl.sh) usa el mecanismo del propio cliente: la clave
# [Runtime] WorldServer= de override.ini (NetUpdate.<clinit>) sustituye en
# World.setWorldServerURL todo worldserver://www.3dcd.com[:puerto] (la URL por
# defecto de World.defaultServerURL, que es la que llevan los .world) por
# worldserver://host:puerto. Sin la variable, el original (www.3dcd.com ya no
# existe: el cliente acaba en modo monousuario, error #205).
# FREEWORLDS_USER=nombre deja ese usuario como User0 en la seccion [host:puerto]
# de worlds.ini, que es la que lee LoginWizard (Galaxy.getIniSection): la
# pantalla de entrada sale con el nombre puesto y sin contrasena guardada.
# FREEWORLDS_NETDEBUG=N pone netdebug=N en [Gamma] (bits de Galaxy/WorldServer
# .getDebugLevel(): 4 sessionInit, 32 tipo de servidor, 64 paquetes...).
if [ -n "${FREEWORLDS_SERVER:-}" ]; then
   python3 - "$FREEWORLDS_SERVER" "${FREEWORLDS_USER:-}" "${FREEWORLDS_NETDEBUG:-}" <<'PY'
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
   echo "run_gamma: WorldServer=worldserver://$FREEWORLDS_SERVER${FREEWORLDS_USER:+ (User0=$FREEWORLDS_USER)}"
fi

# FREEWORLDS_LOGIN=contrasena (arnes, solo contra un servidor local de pruebas)
# arranca por tools/net-probe/LoginDriver: rellena la contrasena en el
# LoginWizard real y pulsa su boton Sign-In con eventos AWT, como una persona.
# Ver docs/net-local-whirl.md. FREEWORLDS_CHAT=MS:texto;... escribe en la linea
# de chat y -Dfreeworlds.dumpChat=MS,... vuelca el area de chat.
MAIN=NET.worlds.console.Gamma
CP=".:$REPO/editor/.build-gamma/out"
if [ -n "${FREEWORLDS_LOGIN:-}${FREEWORLDS_CHAT:-}" ]; then
   DRV="$REPO/editor/.build-gamma/net-probe-driver"
   mkdir -p "$DRV"
   "$(dirname "$JAVA")/javac" --release 8 -nowarn -encoding UTF-8 -cp "$REPO/editor/.build-gamma/out" \
      -d "$DRV" "$REPO/tools/net-probe/LoginDriver.java"
   CP="$CP:$DRV"
   MAIN=LoginDriver
fi
"$JAVA" ${JAVA_OPTS:-} -cp "$CP" $MAIN "$@"

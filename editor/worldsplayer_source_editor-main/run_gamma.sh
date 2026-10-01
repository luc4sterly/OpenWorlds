#!/bin/bash
# Starts the ORIGINAL decompiled client (NET.worlds.console.Gamma) with the
# portable bridge of bridge/, from a copy of the 2004 install
# (assets/WorldsPlayer) so as not to write into the repo. Requires having
# run build_gamma.sh (see bridge/README.md).
#
# Usage: editor/worldsplayer_source_editor-main/run_gamma.sh [WORLD_URL]
#   without a URL it starts like the original (home:NewWorld.world until the login);
#   e.g. home:GroundZero/groundzero.world goes straight into GroundZero
#   (a command-line argument of Gamma.main itself).
# Working directory: $OPENWORLDS_GAMMA_DIR or $TMPDIR/openworlds-gamma.
# Diagnostics: JAVA_OPTS="-Dopenworlds.dumpFrames=DIR [-Dopenworlds.dumpSeconds=10,20]
#   [-Dopenworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...]" (see bridge/README.md).
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
JAVA="$REPO/tools/jdk/Contents/Home/bin/java"
[ -x "$JAVA" ] || JAVA=java
CWD="${OPENWORLDS_GAMMA_DIR:-${TMPDIR:-/tmp}/openworlds-gamma}"
mkdir -p "$CWD"
# cachedir always from the original: an orphan cache.open left by an unclean
# exit makes the client throw the whole index away.
rm -rf "$CWD/cachedir"
cp -R "$REPO/assets/WorldsPlayer/." "$CWD/"
cd "$CWD"

# Local upgrade server (tools/local-upgrade-server.py): it serves the install
# of assets/ instantly and the copy of worlds.ini points at it. What is
# missing (world packages, avatar outfits, the universe map) it asks of the
# original upgradeServer, http://us1.worlds.net/3DCDup, which today is the
# LibreWorlds mirror, and keeps it in build/mirror-cache, like the
# launcher. OPENWORLDS_MIRROR=URL uses another mirror and OPENWORLDS_MIRROR=0 none.
# OPENWORLDS_NO_LOCAL_SERVER=1 keeps the original upgradeServer.
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
   [ -n "$PORT" ] || { echo "run_gamma: the local server did not start (see $SRVLOG)" >&2; exit 1; }
   for f in worlds.ini worlds.dst; do
      [ -f "$f" ] && sed -i.bak "s#^upgradeServer=.*#upgradeServer=http://127.0.0.1:$PORT/3DCDup#" "$f" && rm -f "$f.bak"
   done
   echo "run_gamma: local upgradeServer at http://127.0.0.1:$PORT/3DCDup${MIRROR_ARGS:+, whatever is missing from $MIRROR} (log: $SRVLOG)"
fi

# Console: with LogFile=Gamma.Log in [Gamma] (worlds.ini) the client sends
# System.out/err to Gamma.Log.open (LogFile.open, as in 2004); since the
# IniFile mock became case-insensitive that key is found. The harness
# diagnostics (-Dopenworlds.*) and the net-probe scripts read
# the console, so by default LogFile is emptied in the working copy
# (config, not logic: with an empty LogFile, LogFile.open does not redirect).
# OPENWORLDS_GAMMA_LOG=1 keeps the original Gamma.Log.
if [ -z "${OPENWORLDS_GAMMA_LOG:-}" ] && [ -f worlds.ini ]; then
   perl -pi -e 's/^logfile=[^\r\n]*/LogFile=/i' worlds.ini
fi

# WorldServer: OPENWORLDS_SERVER=host:port (e.g. a J Solar Server on this
# machine, 127.0.0.1:6650) uses the client's own mechanism: the key
# [Runtime] WorldServer= of override.ini (NetUpdate.<clinit>) replaces, in
# World.setWorldServerURL, every worldserver://www.3dcd.com[:port] (the
# default URL of World.defaultServerURL, the one the .world files carry) with
# worldserver://host:port. Without the variable, the original (www.3dcd.com no
# longer exists: the client ends up in single-user mode, error #205).
# OPENWORLDS_USER=name sets that user as User0 in the [host:port] section
# of worlds.ini, the one LoginWizard reads (Galaxy.getIniSection): the
# sign-in screen comes up with the name filled in and no saved password.
# OPENWORLDS_NETDEBUG=N sets netdebug=N in [Gamma] (bits of Galaxy/WorldServer
# .getDebugLevel(): 4 sessionInit, 32 server type, 64 packets...).
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

# OPENWORLDS_LOGIN=password (harness, only against a local test server)
# starts through tools/net-probe/LoginDriver: it fills in the password in the
# real LoginWizard and presses its Sign-In button with AWT events, like a person.
# See docs/net-local-server.md. OPENWORLDS_CHAT=MS:text;... types into the chat
# line and -Dopenworlds.dumpChat=MS,... dumps the chat area.
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
# Installing a world or an update: the client asks for gdkup.exe and exits.
# gdkup.exe does not run outside Windows, so the bridge leaves the request
# in gdkup.pending (NativeSysProcess.createProcSpecial) and here it is
# applied with the gdkup in Java (NET.worlds.core.GdkUp). With its code 10
# the client is started again with what the script's run.exe line asks for
# (world:restart), as the launcher does (Session).
while [ -f gdkup.pending ]; do
   GARGS="$(tr -d '\r\n' < gdkup.pending)"
   rm -f gdkup.pending
   echo "run_gamma: pending update: gdkup $GARGS"
   "$JAVA" -cp "$REPO/editor/.build-gamma/out" NET.worlds.core.GdkUp $GARGS > gdkup.out 2>&1
   GRC=$?
   cat gdkup.out
   [ "$GRC" -eq 10 ] || break
   RESTART="$(sed -n 's/^\[gdkup\] restart: *//p' gdkup.out | tail -1)"
   echo "run_gamma: restart after the update: ${RESTART:-world:restart}"
   "$JAVA" ${JAVA_OPTS:-} -cp "$CP" $MAIN ${RESTART:-world:restart}
   RC=$?
done
exit $RC

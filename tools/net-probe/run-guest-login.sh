#!/usr/bin/env bash
# Builds the JNI mock + the network probes and runs GuestLoginProbe
# against Worlio's anonymous guest server (gippsland.worlio.com:8265), like
# the run documented in README.md (the 2026-09-10 full login against the
# real guest server), but reproducible on macOS without Xvfb (native AWT
# via Cocoa).
#
# It touches nothing versioned: it copies editor/worldsplayer_source_editor-main/
# (with its pristine source/) and assets/WorldsPlayer/ into a temporary
# working directory outside the repo, applies the mock and compiles there.
# One network connection per run (GuestLoginProbe closes it at the end).
#
# Usage:
#   tools/net-probe/run-guest-login.sh [workdir] [host] [port] [nick] [password] [clientVersion]
# All arguments are optional; the host/port/nick/etc. defaults are the same
# as GuestLoginProbe.main's (see that file). "workdir" defaults to a new
# directory under $TMPDIR (or /tmp if it is not set); it is created if it
# does not exist and reused if it does (so the build can be inspected after
# running the script).
#
# JDK: uses tools/jdk/Contents/Home/bin/{java,javac} if it exists next to
# the repo (the portable JDK documented in docs/worlds-chat-project.md),
# otherwise falls back to "java"/"javac" on the PATH. bash 3.2 compatible
# (stock macOS).
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

WORKDIR="${1:-}"
if [ -z "$WORKDIR" ]; then
   WORKDIR="$(mktemp -d "${TMPDIR:-/tmp}/openworlds-net-guest-login.XXXXXX")"
fi
mkdir -p "$WORKDIR"
echo "== workdir: $WORKDIR =="

# host/port/nick/password/clientVersion (args 2..6) are forwarded AS IS
# to GuestLoginProbe.main -- only the ones the user actually gave on the
# command line, so that the probe's real defaults (random FWProbeNNN nick,
# password=null, etc.) keep applying instead of this script overriding
# them with "" (which in Java is NOT the same as "absent").
PROBE_ARGS=()
if [ "$#" -ge 2 ]; then PROBE_ARGS+=("$2"); fi
if [ "$#" -ge 3 ]; then PROBE_ARGS+=("$3"); fi
if [ "$#" -ge 4 ]; then PROBE_ARGS+=("$4"); fi
if [ "$#" -ge 5 ]; then PROBE_ARGS+=("$5"); fi
if [ "$#" -ge 6 ]; then PROBE_ARGS+=("$6"); fi
HOST="${2:-gippsland.worlio.com}"
PORT="${3:-8265}"

# tools/jdk/ is a portable, uninstalled JDK (Temurin 25), not versioned -
# it only physically exists in the main checkout (git worktrees don't
# share untracked files). It is tried there first (in case this script
# runs from the main checkout itself), then at this Mac's known absolute
# path, and only if neither exists does it fall back to java/javac on the
# PATH (which on this Mac is a stub, see docs/worlds-chat-project.md).
MAIN_CHECKOUT_JDK="/Users/lucas/Developer/OpenWorlds/tools/jdk/Contents/Home/bin"
if [ -x "$REPO_ROOT/tools/jdk/Contents/Home/bin/javac" ]; then
   JAVAC="$REPO_ROOT/tools/jdk/Contents/Home/bin/javac"
   JAVA="$REPO_ROOT/tools/jdk/Contents/Home/bin/java"
elif [ -x "$MAIN_CHECKOUT_JDK/javac" ]; then
   JAVAC="$MAIN_CHECKOUT_JDK/javac"
   JAVA="$MAIN_CHECKOUT_JDK/java"
else
   JAVAC="javac"
   JAVA="java"
fi
echo "== JDK: $("$JAVA" -version 2>&1 | head -1) =="

# 1. Replicate the layout apply_mock.sh needs (ROOT=../..):
#    <workdir>/editor/worldsplayer_source_editor-main/apply_mock.sh
#    <workdir>/tools/jni_mock.py
#    <workdir>/docs/native-methods-callers.md
echo "== [1/6] copying editor/ + tools/jni_mock.py + docs/native-methods-callers.md =="
mkdir -p "$WORKDIR/tools" "$WORKDIR/docs"
rm -rf "$WORKDIR/editor"
mkdir -p "$WORKDIR/editor"
cp -R "$REPO_ROOT/editor/worldsplayer_source_editor-main" "$WORKDIR/editor/worldsplayer_source_editor-main"
cp "$REPO_ROOT/tools/jni_mock.py" "$WORKDIR/tools/jni_mock.py"
cp "$REPO_ROOT/docs/native-methods-callers.md" "$WORKDIR/docs/native-methods-callers.md"

# 2. Apply the JNI mock to the COPY (never to the real repo).
echo "== [2/6] applying apply_mock.sh =="
( cd "$WORKDIR/editor/worldsplayer_source_editor-main" && ./apply_mock.sh )

# 3. Compile the mocked client. --release 8: the decompiled source/ does not
#    compile with a modern javac because of netPacketReader's bare yield().
echo "== [3/6] javac --release 8 of the mocked client (out/) =="
CLIENT_SRC_DIR="$WORKDIR/editor/worldsplayer_source_editor-main"
rm -rf "$CLIENT_SRC_DIR/out"
mkdir -p "$CLIENT_SRC_DIR/out"
SOURCES_LIST="$WORKDIR/mock-sources.txt"
( cd "$CLIENT_SRC_DIR" && find source -name '*.java' > "$SOURCES_LIST" )
( cd "$CLIENT_SRC_DIR" && "$JAVAC" --release 8 -nowarn -d out -cp source "@$SOURCES_LIST" ) \
   2> "$WORKDIR/compile-mock.log" || {
      echo "FAILED compiling the mock, see $WORKDIR/compile-mock.log" >&2
      cat "$WORKDIR/compile-mock.log" >&2
      exit 1
   }
CLASS_COUNT=$(find "$CLIENT_SRC_DIR/out" -name '*.class' | wc -l | tr -d ' ')
echo "compiled $CLASS_COUNT classes"

# 4. Compile the tools/net-probe/ probes against that out/.
echo "== [4/6] javac --release 8 of the probes (NetProbe + NET/worlds/network/*Probe*) =="
PROBE_OUT="$WORKDIR/probeout"
rm -rf "$PROBE_OUT"
mkdir -p "$PROBE_OUT"
"$JAVAC" --release 8 -nowarn -cp "$CLIENT_SRC_DIR/out" -d "$PROBE_OUT" \
   "$SCRIPT_DIR/NetProbe.java" \
   "$SCRIPT_DIR/NET/worlds/network/HandshakeProbe.java" \
   "$SCRIPT_DIR/NET/worlds/network/AutoServerProbe.java" \
   "$SCRIPT_DIR/NET/worlds/network/GuestLoginProbe.java" \
   "$SCRIPT_DIR/NET/worlds/network/MinimalServerHandler.java" \
   2> "$WORKDIR/compile-probes.log" || {
      echo "FAILED compiling the probes, see $WORKDIR/compile-probes.log" >&2
      cat "$WORKDIR/compile-probes.log" >&2
      exit 1
   }
echo "probes compiled OK"

# 5. Clean copy of assets/WorldsPlayer as the CWD (same as run_mock.sh:
#    IniFile needs the real worlds.ini, and the original is never written
#    to - logs/caches/ini stay only in this temporary copy).
echo "== [5/6] copying assets/WorldsPlayer as a clean CWD =="
CWD_DIR="$WORKDIR/guest-login-cwd"
rm -rf "$CWD_DIR"
mkdir -p "$CWD_DIR"
cp -R "$REPO_ROOT/assets/WorldsPlayer/." "$CWD_DIR/"

# 6. GuestLoginProbe [host] [port] [nickname] [password?] [clientVersion?]
#    A single connection, closed by itself at the end (see GuestLoginProbe.
#    main). Empty nick -> the probe generates one (random FWProbeNNN).
echo "== [6/6] running GuestLoginProbe against $HOST:$PORT =="
set +e
(
   cd "$CWD_DIR"
   "$JAVA" -cp ".:$PROBE_OUT:$CLIENT_SRC_DIR/out" \
      NET.worlds.network.GuestLoginProbe "${PROBE_ARGS[@]+"${PROBE_ARGS[@]}"}"
)
STATUS=$?
set -e
echo "== GuestLoginProbe exit=$STATUS =="
exit $STATUS

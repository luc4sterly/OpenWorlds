#!/usr/bin/env bash
# Starts the REAL NET.worlds.console.Gamma (main) flow, with the mock, from
# a copy of assets/WorldsPlayer as the CWD - to see how far it gets on
# macOS today (native, no Xvfb). It reimplements NOTHING: it calls the real
# main() as is. It kills the process after ~60s if it is still alive (Gamma
# has no clean exit without an interactive UI) and, if it is still alive,
# takes a jstack before killing it, as evidence of which thread/stack it is
# blocked in.
#
# Reuses the same mock+probes as run-guest-login.sh if they are already
# compiled in the workdir (so as not to recompile 722 sources twice);
# otherwise it compiles from scratch.
#
# Usage: tools/net-probe/run-gamma-main.sh [workdir] [timeout_seconds]
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

WORKDIR="${1:-}"
if [ -z "$WORKDIR" ]; then
   WORKDIR="$(mktemp -d "${TMPDIR:-/tmp}/openworlds-net-gamma-main.XXXXXX")"
fi
mkdir -p "$WORKDIR"
TIMEOUT="${2:-60}"
echo "== workdir: $WORKDIR (timeout ${TIMEOUT}s) =="

MAIN_CHECKOUT_JDK="/Users/lucas/Developer/OpenWorlds/tools/jdk/Contents/Home/bin"
if [ -x "$REPO_ROOT/tools/jdk/Contents/Home/bin/javac" ]; then
   JAVAC="$REPO_ROOT/tools/jdk/Contents/Home/bin/javac"
   JAVA="$REPO_ROOT/tools/jdk/Contents/Home/bin/java"
   JSTACK="$REPO_ROOT/tools/jdk/Contents/Home/bin/jstack"
elif [ -x "$MAIN_CHECKOUT_JDK/javac" ]; then
   JAVAC="$MAIN_CHECKOUT_JDK/javac"
   JAVA="$MAIN_CHECKOUT_JDK/java"
   JSTACK="$MAIN_CHECKOUT_JDK/jstack"
else
   JAVAC="javac"
   JAVA="java"
   JSTACK="jstack"
fi
echo "== JDK: $("$JAVA" -version 2>&1 | head -1) =="

CLIENT_SRC_DIR="$WORKDIR/editor/worldsplayer_source_editor-main"
if [ ! -d "$CLIENT_SRC_DIR/out" ] || [ -z "$(find "$CLIENT_SRC_DIR/out" -name '*.class' -print -quit 2>/dev/null)" ]; then
   echo "== compiling the mock (not found in $CLIENT_SRC_DIR/out) =="
   mkdir -p "$WORKDIR/tools" "$WORKDIR/docs"
   rm -rf "$WORKDIR/editor"
   mkdir -p "$WORKDIR/editor"
   cp -R "$REPO_ROOT/editor/worldsplayer_source_editor-main" "$CLIENT_SRC_DIR"
   cp "$REPO_ROOT/tools/jni_mock.py" "$WORKDIR/tools/jni_mock.py"
   cp "$REPO_ROOT/docs/native-methods-callers.md" "$WORKDIR/docs/native-methods-callers.md"
   ( cd "$CLIENT_SRC_DIR" && ./apply_mock.sh )
   mkdir -p "$CLIENT_SRC_DIR/out"
   SOURCES_LIST="$WORKDIR/mock-sources.txt"
   ( cd "$CLIENT_SRC_DIR" && find source -name '*.java' > "$SOURCES_LIST" )
   ( cd "$CLIENT_SRC_DIR" && "$JAVAC" --release 8 -nowarn -d out -cp source "@$SOURCES_LIST" ) \
      2> "$WORKDIR/compile-mock.log" || {
         echo "FAILED compiling the mock, see $WORKDIR/compile-mock.log" >&2
         cat "$WORKDIR/compile-mock.log" >&2
         exit 1
      }
   echo "compiled $(find "$CLIENT_SRC_DIR/out" -name '*.class' | wc -l | tr -d ' ') classes"
else
   echo "== mock already compiled in $CLIENT_SRC_DIR/out, reusing it =="
fi

CWD_DIR="$WORKDIR/gamma-cwd"
rm -rf "$CWD_DIR"
mkdir -p "$CWD_DIR"
cp -R "$REPO_ROOT/assets/WorldsPlayer/." "$CWD_DIR/"

STDOUT_LOG="$WORKDIR/gamma-stdout.log"
JSTACK_LOG="$WORKDIR/gamma-jstack.txt"

echo "== launching NET.worlds.console.Gamma (max ${TIMEOUT}s) =="
(
   cd "$CWD_DIR"
   # exec: $! must be the JVM's PID, not the subshell's; without exec,
   # jstack/kill acted on the subshell and the JVM was left orphaned.
   exec "$JAVA" -cp ".:$CLIENT_SRC_DIR/out" NET.worlds.console.Gamma
) > "$STDOUT_LOG" 2>&1 &
GAMMA_PID=$!

# Early jstack (does not kill the process): the real startup does a
# synchronous teleport to NewWorld.world that can block the "Gamma Main"
# thread in CacheFile.waitUntilLoaded, waiting for a real HTTP download by
# a "File Downloader N" thread - if the process ends on its own before
# this (possible: cache already warm or a short timeout), this is the only
# snapshot of those threads we get.
sleep 3
EARLY_JSTACK_LOG="$WORKDIR/gamma-jstack-early.txt"
if kill -0 "$GAMMA_PID" 2>/dev/null; then
   "$JSTACK" "$GAMMA_PID" > "$EARLY_JSTACK_LOG" 2>&1 || echo "early jstack failed" >&2
   echo "early jstack (at ~3s): $EARLY_JSTACK_LOG"
else
   echo "process already finished at ~3s, no early jstack"
fi

# Wait for it to finish on its own, or up to TIMEOUT seconds.
SECS=3
while kill -0 "$GAMMA_PID" 2>/dev/null; do
   if [ "$SECS" -ge "$TIMEOUT" ]; then
      echo "== still alive at ${TIMEOUT}s: jstack before killing =="
      "$JSTACK" "$GAMMA_PID" > "$JSTACK_LOG" 2>&1 || echo "jstack failed (see $JSTACK_LOG)" >&2
      kill -9 "$GAMMA_PID" 2>/dev/null || true
      break
   fi
   sleep 2
   SECS=$((SECS + 2))
done
wait "$GAMMA_PID" 2>/dev/null
STATUS=$?
echo "== Gamma finished/killed after ~${SECS}s, exit(wait)=$STATUS =="
echo "stdout: $STDOUT_LOG"
if [ -f "$JSTACK_LOG" ]; then
   echo "jstack: $JSTACK_LOG"
fi
echo "== last 40 lines of stdout =="
tail -40 "$STDOUT_LOG"

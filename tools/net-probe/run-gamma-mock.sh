#!/usr/bin/env bash
# Starts the REAL NET.worlds.console.Gamma.main flow (decompiled 2004 client
# + mock JNI bridge) from a fresh copy of assets/WorldsPlayer as the CWD,
# takes thread dumps of it with jstack and kills it when the time is up.
# macOS: native Cocoa AWT (the splash/console show up on screen). Linux:
# needs DISPLAY (X/Xvfb).
#
# Usage: tools/net-probe/run-gamma-mock.sh [Gamma argv...]
# Variables: FW_NET_WORK, JDK_BIN (see lib-build.sh);
#   GAMMA_SECONDS  maximum lifetime of the process (default 60)
#   JSTACK_AT      seconds (space-separated) at which to dump the threads
#                  (default "20 50")
# Output in $WORK/gamma/: stdout.log (stdout+stderr), jstack-<s>.txt, and the
# copy of the install with whatever the client wrote (cachedir).
# WATCH the size: with the current mock the client lives in Main.mainLoop and
# every frame logs its natives: ~226 MB / 5.2 M lines of stdout.log in 60 s.
# Network: the real client resolves and downloads from its upgradeServer
# (us1.worlds.net, HTTP) - it opens no WorldServer connection and no login.
set -euo pipefail
HERE="$(cd "$(dirname "$0")" && pwd)"
. "$HERE/lib-build.sh"

find_jdk
init_work
build_mock

RUN="$WORK/gamma"
copy_install "$RUN/WorldsPlayer"
LOG="$RUN/stdout.log"
rm -f "$RUN"/jstack-*.txt
LIMIT="${GAMMA_SECONDS:-60}"
echo "run: Gamma.main $* (CWD: $RUN/WorldsPlayer, log: $LOG, limit ${LIMIT}s)"
cd "$RUN/WorldsPlayer"
start=$(date +%s)
"$JAVA" -cp ".:$WORK/out" NET.worlds.console.Gamma "$@" >"$LOG" 2>&1 &
pid=$!

alive() { kill -0 "$pid" 2>/dev/null; }
elapsed=0
for t in ${JSTACK_AT:-20 50}; do
  while alive && [ "$elapsed" -lt "$t" ] && [ "$elapsed" -lt "$LIMIT" ]; do
    sleep 1
    elapsed=$(( $(date +%s) - start ))
  done
  if alive && [ "$elapsed" -lt "$LIMIT" ]; then
    "$JSTACK" -l "$pid" >"$RUN/jstack-$t.txt" 2>&1 || true
    echo "jstack @${elapsed}s -> $RUN/jstack-$t.txt"
  fi
done
while alive && [ "$elapsed" -lt "$LIMIT" ]; do
  sleep 1
  elapsed=$(( $(date +%s) - start ))
done

set +e
if alive; then
  echo "alive after ${elapsed}s: kill"
  kill "$pid" 2>/dev/null
  sleep 2
  alive && kill -9 "$pid" 2>/dev/null
  wait "$pid" 2>/dev/null
  echo "exit=killed"
else
  wait "$pid"
  echo "exit=$? after ${elapsed}s (exited on its own)"
fi
set -e
echo "--- last lines of $LOG ---"
tail -25 "$LOG"

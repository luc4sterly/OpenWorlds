#!/usr/bin/env bash
# Arranca el flujo REAL NET.worlds.console.Gamma.main (cliente 2004 decompilado
# + puente JNI mock) desde una copia fresca de assets/WorldsPlayer como CWD,
# le hace volcados de hilos con jstack y lo mata al acabar el plazo.
# macOS: AWT nativo Cocoa (la splash/consola aparecen en pantalla). Linux:
# requiere DISPLAY (X/Xvfb).
#
# Uso: tools/net-probe/run-gamma-mock.sh [argv de Gamma...]
# Variables: FW_NET_WORK, JDK_BIN (ver lib-build.sh);
#   GAMMA_SECONDS  vida maxima del proceso (defecto 60)
#   JSTACK_AT      segundos (separados por espacio) en que volcar hilos
#                  (defecto "20 50")
# Salida en $WORK/gamma/: stdout.log (stdout+stderr), jstack-<s>.txt, y la
# copia de la instalacion con lo que el cliente escribio (Gamma.Log, cachedir).
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
echo "run: Gamma.main $* (CWD: $RUN/WorldsPlayer, log: $LOG, limite ${LIMIT}s)"
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
  echo "vivo tras ${elapsed}s: kill"
  kill "$pid" 2>/dev/null
  sleep 2
  alive && kill -9 "$pid" 2>/dev/null
  wait "$pid" 2>/dev/null
  echo "exit=killed"
else
  wait "$pid"
  echo "exit=$? tras ${elapsed}s (salio solo)"
fi
set -e
echo "--- ultimas lineas de $LOG ---"
tail -25 "$LOG"

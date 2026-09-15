#!/usr/bin/env bash
# Construye el cliente mockeado + las sondas de red en un directorio de
# trabajo FUERA del repo y ejecuta GuestLoginProbe contra el guest de Worlio.
# Portable macOS (bash 3.2, sin Homebrew/Xvfb: AWT abre Cocoa nativo) y Linux
# (ahi hace falta DISPLAY con X/Xvfb: Console.<clinit> crea un Frame AWT).
#
# Uso:
#   tools/net-probe/run-guest-login.sh [host] [port] [nick] [password] [clientVersion]
#   tools/net-probe/run-guest-login.sh --build-only
# Sin argv la sonda usa gippsland.worlio.com 8265, nick aleatorio FWProbeNNN,
# sin password y clientVersion 2004080500 (valor real de gamma.dll, ver
# README). NUNCA pongas credenciales en este script: el password va solo por
# argv y solo para una cuenta propia registrada a mano. Una conexion por
# ejecucion; la sonda la cierra al terminar.
#
# Variables: FW_NET_WORK, JDK_BIN (ver lib-build.sh); PROBE_TIMEOUT segundos
# antes de matar la sonda (defecto 150; la sonda tiene sus propios plazos
# 20+25+45 s y termina con System.exit).
set -euo pipefail
HERE="$(cd "$(dirname "$0")" && pwd)"
. "$HERE/lib-build.sh"

find_jdk
init_work
build_mock
if [ "${1:-}" = "--build-only" ]; then
  echo "build-only: listo"
  exit 0
fi

RUN="$WORK/guest-login"
copy_install "$RUN/WorldsPlayer"
LOG="$RUN/guest-login.log"
echo "run: GuestLoginProbe $* (CWD: $RUN/WorldsPlayer, log: $LOG)"
cd "$RUN/WorldsPlayer"
"$JAVA" -cp ".:$WORK/probeout:$WORK/out" NET.worlds.network.GuestLoginProbe "$@" >"$LOG" 2>&1 &
pid=$!
( sleep "${PROBE_TIMEOUT:-150}"; kill "$pid" 2>/dev/null && echo "WATCHDOG: sonda matada tras ${PROBE_TIMEOUT:-150}s" >>"$LOG" ) &
wd=$!
set +e
wait "$pid"
rc=$?
kill "$wd" 2>/dev/null
wait "$wd" 2>/dev/null
set -e
echo "exit=$rc"
echo "--- resumen ---"
grep -e 'state ->' -e 'final state' -e 'recv(SESSINIT' -e 'recv(TEXT' -e 'threw' \
     -e 'WATCHDOG' -e 'closed cleanly' "$LOG" || true
exit "$rc"

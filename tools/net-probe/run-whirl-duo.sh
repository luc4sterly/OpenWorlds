#!/bin/bash
# Prueba H3 (docs/net-local-whirl.md): dos clientes ORIGINALES bajo el puente
# portable contra un whirl local, en la misma sala; A escribe en el chat y B
# vuelca su area de chat. Requiere editor/worldsplayer_source_editor-main/build_gamma.sh.
#
# Uso: tools/net-probe/run-whirl-duo.sh DIR_SALIDA
#   DIR_SALIDA/srv          whirl (Config.toml, whirl.log) via tools/run-whirl.sh
#   DIR_SALIDA/cliA, cliB   directorios de trabajo de cada cliente (OPENWORLDS_GAMMA_DIR)
#   DIR_SALIDA/runA.log, runB.log   consola de cada cliente (netdebug 1253)
#   (los intentos fallidos quedan como runX.intentoN.log)
# Secuencia: arranca B y espera a que tenga sesion en el hub (SESSINIT del
# RoomServer); arranca A, espera su sesion; A escribe DUO_TEXT a los
# DUO_CHAT_A_MS ms (15000) de cerrarse su LoginWizard y, 5 s despues, DUO_SPAWN
# ("/spawn fuwn", orden de prueba de whirl que difunde REGOBJID+TELEPORT+PROPUPD
# de un avatar ficticio: ejercita la creacion de Drone del cliente, cosa que
# whirl no hace para los usuarios reales; DUO_SPAWN= la desactiva). B y A
# vuelcan chat y Drones cada 10 s; se para todo DUO_TAIL s (15) despues.
# Carrera del cliente original (docs/net-local-whirl.md): contra un servidor
# en la misma maquina, WSConnecting puede llamar a WorldServer.setSocket antes
# de que WorldServer asigne _connectThread (NPE en getBackupHosts, la conexion
# queda colgada en el estado 4). Si pasa, se reintenta ese cliente (hasta 3
# veces) y se cuenta.
# Nombres y contrasena de prueba: solo para el whirl local (no valida contrasenas).
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
OUT="${1:?uso: run-whirl-duo.sh DIR_SALIDA}"
mkdir -p "$OUT"
OUT="$(cd "$OUT" && pwd)"
WORLD="${DUO_WORLD:-home:GroundZero/groundzero.world}"
TEXT="${DUO_TEXT:-hola desde A}"
CHAT_MS="${DUO_CHAT_A_MS:-15000}"
SPAWN="${DUO_SPAWN-/spawn fuwn}"
TAIL="${DUO_TAIL:-15}"
RUN="$REPO/editor/worldsplayer_source_editor-main/run_gamma.sh"
OUTCLS="$REPO/editor/.build-gamma/out"
[ -d "$OUTCLS" ] || { echo "run-whirl-duo: falta build_gamma.sh" >&2; exit 1; }

# Mata solo la JVM cuyo cwd es el directorio de ese cliente (otros agentes
# corren la misma clase con el mismo classpath).
kill_client() {
   for p in $(pgrep -f "$OUTCLS" || true); do
      cwd="$(lsof -a -p "$p" -d cwd -Fn 2>/dev/null | sed -n 's/^n//p')"
      if [ "$cwd" = "$1" ]; then kill "$p" 2>/dev/null || true; fi
   done
}

"$REPO/tools/run-whirl.sh" "$OUT/srv"
trap '"$REPO/tools/run-whirl.sh" --stop "$OUT/srv" >/dev/null; kill_client "$OUT/cliA"; kill_client "$OUT/cliB"' EXIT

start_client() { # nombre usuario opciones-java guion-de-chat
   (
      export OPENWORLDS_GAMMA_DIR="$OUT/cli$1"
      export OPENWORLDS_SERVER=127.0.0.1:6650
      export OPENWORLDS_USER="$2"
      export OPENWORLDS_LOGIN=fwtest1
      export OPENWORLDS_NETDEBUG=1253
      export OPENWORLDS_CHAT="$4"
      export JAVA_OPTS="-Xmx512m $3"
      exec "$RUN" "$WORLD" > "$OUT/run$1.log" 2>&1
   ) &
}

# 0 = sesion en el hub; 2 = carrera de _connectThread; 1 = nada en 90 s
wait_session() {
   for _ in $(seq 1 90); do
      grep -q "5673: recv(SESSINIT" "$OUT/run$1.log" 2>/dev/null && return 0
      grep -q "_connectThread\" is null" "$OUT/run$1.log" 2>/dev/null && return 2
      sleep 1
   done
   return 1
}

RACES=0
client_up() { # nombre usuario opciones-java guion-de-chat
   for n in 1 2 3; do
      start_client "$@"
      rc=0; wait_session "$1" || rc=$?
      [ "$rc" = 0 ] && { echo "run-whirl-duo: $1 con sesion en el hub (intento $n)"; return 0; }
      kill_client "$OUT/cli$1"; sleep 1
      mv "$OUT/run$1.log" "$OUT/run$1.intento$n.log"
      if [ "$rc" = 2 ]; then
         RACES=$((RACES + 1))
         echo "run-whirl-duo: $1 intento $n: carrera de _connectThread (NPE), se reintenta"
      else
         echo "run-whirl-duo: $1 intento $n: sin sesion en 90 s"
      fi
   done
   return 1
}

DUMPS=""
for s in 30 40 50 60 70 80 90 100 110 120 130 140 150 160 170 180; do DUMPS="$DUMPS,${s}000"; done
SCRIPT="$CHAT_MS:$TEXT"
[ -n "$SPAWN" ] && SCRIPT="$SCRIPT;$((CHAT_MS + 5000)):$SPAWN"
client_up B FWTestB "-Dopenworlds.dumpChat=${DUMPS#,} -Dopenworlds.dumpDrones=${DUMPS#,} ${DUO_EXTRA_B:-}" ""
client_up A FWTestA "-Dopenworlds.dumpDrones=${DUMPS#,} ${DUO_EXTRA_A:-}" "$SCRIPT"
sleep $((CHAT_MS / 1000 + 5 + TAIL))
kill_client "$OUT/cliA"
kill_client "$OUT/cliB"
sleep 1
echo "run-whirl-duo: carreras de _connectThread en esta ejecucion: $RACES"

echo "== whirl: sesiones, teleports y texto =="
grep -E "session initialization|received teleport|registered object|received text|broadcasted text" "$OUT/srv/.whirl/whirl.log" || true
for n in A B; do
   echo "== cliente $n: sesion, objetos remotos y chat =="
   grep -E "recv\(SESSINIT|recv\(REGOBJID|recv\(APPRACTR|recv\(TELEPORT|recv\(LONGLOC|recv\(TEXT|recv\(PROPUPD|sendText|\[DRIVER|Exception" "$OUT/run$n.log" | grep -v "^\s*at " | sed 's/^\[[0-9]*\] //' | sort | uniq -c || true
   grep "\[CHAT" "$OUT/run$n.log" | tail -8 || true
   grep "\[DRONES" "$OUT/run$n.log" | tail -4 || true
done

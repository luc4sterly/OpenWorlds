#!/bin/bash
# Arranca whirl (server/whirl, WorldServer de terceros, sin tocar su codigo)
# en local para probar el cliente original con sesion (docs/net-local-whirl.md).
#
# Uso: tools/run-whirl.sh [DIR_DE_TRABAJO]
#   DIR_DE_TRABAJO (por defecto $TMPDIR/freeworlds-whirl) recibe .whirl/Config.toml
#   y .whirl/whirl.log; whirl lee SIEMPRE .whirl/ relativo a su cwd (lib.rs fija
#   DATABASE_URL=.whirl/db.sqlite3 y whirl_config lee .whirl/Config.toml), asi
#   que nada se escribe en el repo.
# Variables:
#   WHIRL_BIN   binario (por defecto server/whirl/target/debug/whirl de este arbol,
#               o el de la copia principal si el worktree no lo tiene compilado)
#   WHIRL_IP    IP donde escuchan distributor y hub (por defecto 127.0.0.1). Es
#               tambien la IP que el distributor manda al cliente en REDIRID
#               (redirect_id.rs), asi que tiene que ser alcanzable por el cliente.
#   WHIRL_PORT  puerto del distributor/AutoServer (por defecto 6650)
#   WHIRL_HUB_PORT  puerto del hub/RoomServer (por defecto 5673)
#   WHIRL_LOG_LEVEL 1=info 2=debug 3=trace (por defecto 3: vuelca cada paquete)
# Escribe el PID en DIR/.whirl/whirl.pid. Para pararlo: tools/run-whirl.sh --stop [DIR]
#
# Solo se arrancan distributor y hub: la API HTTP (axum) no la usa el cliente.
# El prompt interactivo de whirl se deja ACTIVADO con un stdin que nunca manda
# nada: con el prompt desactivado, cli.rs espera en
# `loop { std::thread::sleep(Duration::default()) }` (sleep de 0 = un nucleo al
# 100 %); con el prompt, read_line se bloquea sin gastar CPU.
set -eu
if [ "${1:-}" = "--stop" ]; then
   D="${2:-${TMPDIR:-/tmp}/freeworlds-whirl}"
   for f in whirl.pid stdin.pid; do
      [ -f "$D/.whirl/$f" ] && kill "$(cat "$D/.whirl/$f")" 2>/dev/null
      rm -f "$D/.whirl/$f"
   done
   rm -f "$D/.whirl/stdin.fifo"
   echo "run-whirl: parado ($D)"
   exit 0
fi
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/.." && pwd)"
DIR="${1:-${TMPDIR:-/tmp}/freeworlds-whirl}"
BIN="${WHIRL_BIN:-$REPO/server/whirl/target/debug/whirl}"
[ -x "$BIN" ] || BIN="/Users/lucas/Developer/FreeWorlds/server/whirl/target/debug/whirl"
[ -x "$BIN" ] || { echo "run-whirl: no hay binario de whirl (compilar con cargo en server/whirl)" >&2; exit 1; }
IP="${WHIRL_IP:-127.0.0.1}"
PORT="${WHIRL_PORT:-6650}"
HUB="${WHIRL_HUB_PORT:-5673}"
LEVEL="${WHIRL_LOG_LEVEL:-3}"

mkdir -p "$DIR/.whirl"
cat > "$DIR/.whirl/Config.toml" <<EOF
# Generado por tools/run-whirl.sh a partir de server/whirl/.whirl/Config.example.toml
version = "0.1.0"

[whirlsplash]
worldsmaster_username = "WORLDSMASTER"
ip = "$IP"
api.port = 8080

[whirlsplash.prompt]
enable = true
ps1 = "[WORLDSMASTER@Whirlsplash ~]$"

[whirlsplash.log]
enable = true
level = $LEVEL
everything = false
test = false
file = false

[distributor]
worldsmaster_greeting = "Welcome to Whirlsplash!"
port = $PORT

[hub]
port = $HUB
EOF

cd "$DIR"
# stdin: un FIFO en el que un `tail -f /dev/null` mantiene abierto el extremo de
# escritura sin escribir nunca (ver cabecera). Los dos PID quedan anotados.
rm -f "$DIR/.whirl/stdin.fifo"
mkfifo "$DIR/.whirl/stdin.fifo"
tail -f /dev/null > "$DIR/.whirl/stdin.fifo" &
echo $! > "$DIR/.whirl/stdin.pid"
"$BIN" run distributor,hub < "$DIR/.whirl/stdin.fifo" > "$DIR/.whirl/whirl.log" 2>&1 &
PID=$!
echo "$PID" > "$DIR/.whirl/whirl.pid"
for _ in 1 2 3 4 5 6 7 8 9 10; do
   grep -q "listening at $IP:$HUB" "$DIR/.whirl/whirl.log" 2>/dev/null \
      && grep -q "listening at $IP:$PORT" "$DIR/.whirl/whirl.log" 2>/dev/null && break
   kill -0 "$PID" 2>/dev/null || { echo "run-whirl: whirl termino (ver $DIR/.whirl/whirl.log)" >&2; cat "$DIR/.whirl/whirl.log" >&2; kill "$(cat "$DIR/.whirl/stdin.pid")" 2>/dev/null; exit 1; }
   sleep 0.5
done
echo "run-whirl: pid $PID, distributor $IP:$PORT, hub $IP:$HUB (log: $DIR/.whirl/whirl.log)"

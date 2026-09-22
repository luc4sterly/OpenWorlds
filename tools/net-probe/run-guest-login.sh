#!/usr/bin/env bash
# Construye el mock JNI + las sondas de red y ejecuta GuestLoginProbe
# contra el guest anonimo de Worlio (gippsland.worlio.com:8265), igual que
# la corrida documentada en README.md ("LOGIN COMPLETO contra el guest
# real"), pero reproducible en macOS sin Xvfb (AWT nativo via Cocoa).
#
# No toca nada versionado: copia editor/worldsplayer_source_editor-main/
# (con su source/ pristino) y assets/WorldsPlayer/ a un directorio de
# trabajo temporal fuera del repo, aplica el mock y compila ahi. Una
# conexion de red por ejecucion (GuestLoginProbe la cierra al terminar).
#
# Uso:
#   tools/net-probe/run-guest-login.sh [workdir] [host] [port] [nick] [password] [clientVersion]
# Todos los argumentos son opcionales; los defaults de host/port/nick/etc.
# son los mismos que GuestLoginProbe.main (ver ese fichero). "workdir" por
# defecto es un directorio nuevo bajo $TMPDIR (o /tmp si no esta definido);
# si no existe se crea, si existe se reutiliza (permite inspeccionar la
# compilacion despues de correr el script).
#
# JDK: usa tools/jdk/Contents/Home/bin/{java,javac} si existe junto al
# repo (JDK portable documentado en docs/worlds-chat-project.md), si no cae a
# "java"/"javac" del PATH. bash 3.2 compatible (macOS de serie).
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

WORKDIR="${1:-}"
if [ -z "$WORKDIR" ]; then
   WORKDIR="$(mktemp -d "${TMPDIR:-/tmp}/freeworlds-net-guest-login.XXXXXX")"
fi
mkdir -p "$WORKDIR"
echo "== workdir: $WORKDIR =="

# host/port/nick/password/clientVersion (args 2..6) se reenvian TAL CUAL
# a GuestLoginProbe.main -- solo los que el usuario dio de verdad en la
# linea de comandos, para que sigan aplicando los defaults reales de la
# sonda (nick aleatorio FWProbeNNN, password=null, etc.) en vez de que
# este script los pise con "" (que en Java NO es lo mismo que "ausente").
PROBE_ARGS=()
if [ "$#" -ge 2 ]; then PROBE_ARGS+=("$2"); fi
if [ "$#" -ge 3 ]; then PROBE_ARGS+=("$3"); fi
if [ "$#" -ge 4 ]; then PROBE_ARGS+=("$4"); fi
if [ "$#" -ge 5 ]; then PROBE_ARGS+=("$5"); fi
if [ "$#" -ge 6 ]; then PROBE_ARGS+=("$6"); fi
HOST="${2:-gippsland.worlio.com}"
PORT="${3:-8265}"

# tools/jdk/ es un JDK portable sin instalar (Temurin 25), no versionado -
# solo existe fisicamente en el checkout principal (los worktrees git no
# comparten ficheros sin trackear). Se prueba ahi primero (por si este
# script corre desde el propio checkout principal), luego la ruta
# absoluta conocida de este Mac, y solo si ninguna existe se cae al
# java/javac del PATH (que en este Mac es un stub, ver docs/worlds-chat-project.md).
MAIN_CHECKOUT_JDK="/Users/lucas/Developer/FreeWorlds/tools/jdk/Contents/Home/bin"
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

# 1. Replicar la estructura que apply_mock.sh necesita (ROOT=../..):
#    <workdir>/editor/worldsplayer_source_editor-main/apply_mock.sh
#    <workdir>/tools/jni_mock.py
#    <workdir>/docs/native-methods-callers.md
echo "== [1/6] copiando editor/ + tools/jni_mock.py + docs/native-methods-callers.md =="
mkdir -p "$WORKDIR/tools" "$WORKDIR/docs"
rm -rf "$WORKDIR/editor"
mkdir -p "$WORKDIR/editor"
cp -R "$REPO_ROOT/editor/worldsplayer_source_editor-main" "$WORKDIR/editor/worldsplayer_source_editor-main"
cp "$REPO_ROOT/tools/jni_mock.py" "$WORKDIR/tools/jni_mock.py"
cp "$REPO_ROOT/docs/native-methods-callers.md" "$WORKDIR/docs/native-methods-callers.md"

# 2. Aplicar el mock JNI sobre la COPIA (nunca sobre el repo real).
echo "== [2/6] aplicando apply_mock.sh =="
( cd "$WORKDIR/editor/worldsplayer_source_editor-main" && ./apply_mock.sh )

# 3. Compilar el cliente mockeado. --release 8: el source/ decompilado no
#    compila con javac moderno por el yield() pelado de netPacketReader.
echo "== [3/6] javac --release 8 del cliente mockeado (out/) =="
CLIENT_SRC_DIR="$WORKDIR/editor/worldsplayer_source_editor-main"
rm -rf "$CLIENT_SRC_DIR/out"
mkdir -p "$CLIENT_SRC_DIR/out"
SOURCES_LIST="$WORKDIR/mock-sources.txt"
( cd "$CLIENT_SRC_DIR" && find source -name '*.java' > "$SOURCES_LIST" )
( cd "$CLIENT_SRC_DIR" && "$JAVAC" --release 8 -nowarn -d out -cp source "@$SOURCES_LIST" ) \
   2> "$WORKDIR/compile-mock.log" || {
      echo "FALLO compilando el mock, ver $WORKDIR/compile-mock.log" >&2
      cat "$WORKDIR/compile-mock.log" >&2
      exit 1
   }
CLASS_COUNT=$(find "$CLIENT_SRC_DIR/out" -name '*.class' | wc -l | tr -d ' ')
echo "compiladas $CLASS_COUNT clases"

# 4. Compilar las sondas de tools/net-probe/ contra ese out/.
echo "== [4/6] javac --release 8 de las sondas (NetProbe + NET/worlds/network/*Probe*) =="
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
      echo "FALLO compilando las sondas, ver $WORKDIR/compile-probes.log" >&2
      cat "$WORKDIR/compile-probes.log" >&2
      exit 1
   }
echo "sondas compiladas OK"

# 5. Copia limpia de assets/WorldsPlayer como CWD (igual que run_mock.sh:
#    IniFile necesita el worlds.ini real, y jamas se escribe sobre el
#    original - logs/caches/ini quedan solo en esta copia temporal).
echo "== [5/6] copiando assets/WorldsPlayer como CWD limpio =="
CWD_DIR="$WORKDIR/guest-login-cwd"
rm -rf "$CWD_DIR"
mkdir -p "$CWD_DIR"
cp -R "$REPO_ROOT/assets/WorldsPlayer/." "$CWD_DIR/"

# 6. GuestLoginProbe [host] [port] [nickname] [password?] [clientVersion?]
#    Una sola conexion, se cierra sola al terminar (ver GuestLoginProbe.
#    main). Nick vacio -> lo genera la propia sonda (FWProbeNNN aleatorio).
echo "== [6/6] ejecutando GuestLoginProbe contra $HOST:$PORT =="
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

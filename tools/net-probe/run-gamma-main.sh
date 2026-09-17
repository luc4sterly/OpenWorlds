#!/usr/bin/env bash
# Arranca el flujo REAL NET.worlds.console.Gamma (main), con el mock, desde
# una copia de assets/WorldsPlayer como CWD - para ver hasta donde llega
# hoy en macOS (nativo, sin Xvfb). NO reimplementa nada: llama al main()
# real tal cual. Mata el proceso a los ~60s si sigue vivo (Gamma no tiene
# salida limpia sin UI interactiva) y, si sigue vivo, saca un jstack antes
# de matarlo como evidencia de en que hilo/pila esta bloqueado.
#
# Reutiliza el mismo mock+sondas que run-guest-login.sh si ya estan
# compiladas en el workdir (para no recompilar 722 fuentes dos veces);
# si no, compila desde cero.
#
# Uso: tools/net-probe/run-gamma-main.sh [workdir] [timeout_seconds]
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

WORKDIR="${1:-}"
if [ -z "$WORKDIR" ]; then
   WORKDIR="$(mktemp -d "${TMPDIR:-/tmp}/freeworlds-net-gamma-main.XXXXXX")"
fi
mkdir -p "$WORKDIR"
TIMEOUT="${2:-60}"
echo "== workdir: $WORKDIR (timeout ${TIMEOUT}s) =="

MAIN_CHECKOUT_JDK="/Users/lucas/Developer/FreeWorlds/tools/jdk/Contents/Home/bin"
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
   echo "== compilando el mock (no encontrado en $CLIENT_SRC_DIR/out) =="
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
         echo "FALLO compilando el mock, ver $WORKDIR/compile-mock.log" >&2
         cat "$WORKDIR/compile-mock.log" >&2
         exit 1
      }
   echo "compiladas $(find "$CLIENT_SRC_DIR/out" -name '*.class' | wc -l | tr -d ' ') clases"
else
   echo "== mock ya compilado en $CLIENT_SRC_DIR/out, reutilizando =="
fi

CWD_DIR="$WORKDIR/gamma-cwd"
rm -rf "$CWD_DIR"
mkdir -p "$CWD_DIR"
cp -R "$REPO_ROOT/assets/WorldsPlayer/." "$CWD_DIR/"

STDOUT_LOG="$WORKDIR/gamma-stdout.log"
JSTACK_LOG="$WORKDIR/gamma-jstack.txt"

echo "== lanzando NET.worlds.console.Gamma (max ${TIMEOUT}s) =="
(
   cd "$CWD_DIR"
   # exec: $! debe ser el PID de la JVM, no el de la subshell; sin exec,
   # jstack/kill actuaban sobre la subshell y la JVM quedaba huerfana.
   exec "$JAVA" -cp ".:$CLIENT_SRC_DIR/out" NET.worlds.console.Gamma
) > "$STDOUT_LOG" 2>&1 &
GAMMA_PID=$!

# jstack temprano (no mata el proceso): el arranque real hace una
# teleport sincrona a NewWorld.world que puede bloquear el hilo "Gamma
# Main" en CacheFile.waitUntilLoaded esperando una descarga HTTP de
# verdad de un hilo "File Downloader N" - si el proceso termina solo
# antes de esto (posible: cache ya caliente o timeout corto), esta es la
# unica foto de esos hilos que se consigue.
sleep 3
EARLY_JSTACK_LOG="$WORKDIR/gamma-jstack-early.txt"
if kill -0 "$GAMMA_PID" 2>/dev/null; then
   "$JSTACK" "$GAMMA_PID" > "$EARLY_JSTACK_LOG" 2>&1 || echo "jstack temprano fallo" >&2
   echo "jstack temprano (a los ~3s): $EARLY_JSTACK_LOG"
else
   echo "proceso ya terminado a los ~3s, sin jstack temprano"
fi

# Espera a que termine solo, o hasta TIMEOUT segundos.
SECS=3
while kill -0 "$GAMMA_PID" 2>/dev/null; do
   if [ "$SECS" -ge "$TIMEOUT" ]; then
      echo "== sigue vivo a los ${TIMEOUT}s: jstack antes de matar =="
      "$JSTACK" "$GAMMA_PID" > "$JSTACK_LOG" 2>&1 || echo "jstack fallo (ver $JSTACK_LOG)" >&2
      kill -9 "$GAMMA_PID" 2>/dev/null || true
      break
   fi
   sleep 2
   SECS=$((SECS + 2))
done
wait "$GAMMA_PID" 2>/dev/null
STATUS=$?
echo "== Gamma terminado/matado tras ~${SECS}s, exit(wait)=$STATUS =="
echo "stdout: $STDOUT_LOG"
if [ -f "$JSTACK_LOG" ]; then
   echo "jstack: $JSTACK_LOG"
fi
echo "== ultimas 40 lineas de stdout =="
tail -40 "$STDOUT_LOG"

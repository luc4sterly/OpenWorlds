#!/usr/bin/env bash
# run-checks.sh — runner de comprobaciones unitarias del hito H0 de
# docs/roadmap.md: compila y ejecuta todos los *Check.java que haya bajo
# client/test/** (classpath de las clases de client/) y bajo
# editor/worldsplayer_source_editor-main/bridge/test/ (classpath
# editor/.build-gamma/out). Contrato (COMUN.md): un *Check es una clase con
# `main` que sale con codigo 0 si pasa, != 0 si falla.
#
# Uso:
#   tools/run-checks.sh [--no-bridge] [--client-build DIR]
#     --no-bridge        no construye ni ejecuta los checks de bridge/test
#                         (utils si no quieres pagar build_gamma.sh).
#     --client-build DIR reusa un build ya compilado de client/src+test en
#                         DIR en vez de compilar uno propio - lo usa
#                         verify-corpus.sh para no compilar dos veces.
#
# Si bridge/test tiene *Check.java pero editor/.build-gamma/out no existe
# todavia, este script llama a build_gamma.sh primero (compila el puente
# completo: puede tardar). Si bridge/test no tiene ningun *Check.java no se
# toca el puente para nada (ni se construye).
#
# bash 3.2 compatible: sin arrays vacios bajo `set -u`.
set -eu
set -o pipefail

resolve_root() {
   local src="$1"
   if command -v greadlink >/dev/null 2>&1; then
      greadlink -f "$src/.."
   elif readlink -f "$src/.." >/dev/null 2>&1; then
      readlink -f "$src/.."
   else
      (cd "$src/.." && pwd -P)
   fi
}
ROOT="$(resolve_root "$(dirname "$0")")"
cd "$ROOT"

if [ -x "$ROOT/tools/jdk/Contents/Home/bin/java" ]; then
   JAVA_HOME="$ROOT/tools/jdk/Contents/Home"
   export JAVA_HOME
   PATH="$JAVA_HOME/bin:$PATH"
   export PATH
fi

NO_BRIDGE=0
CLIENT_BUILD=""
while [ $# -gt 0 ]; do
   case "$1" in
      --no-bridge) NO_BRIDGE=1; shift ;;
      --client-build) CLIENT_BUILD="$2"; shift 2 ;;
      -h|--help)
         echo "Uso: $0 [--no-bridge] [--client-build DIR]"
         exit 0 ;;
      *)
         echo "Argumento desconocido: $1" >&2
         exit 2 ;;
   esac
done

JMEM="-Xmx512m"
WORK="$(mktemp -d "${TMPDIR:-/tmp}/fw-run-checks.XXXXXX")"
OWN_CLIENT_BUILD=0
cleanup() { rm -rf "$WORK"; }
trap cleanup EXIT

FAILED=0
ROWS="$WORK/rows.txt"
: > "$ROWS"
N_TOTAL=0

report() {
   # report <grupo> <clase> <estado(PASA|FALLA)> <detalle>
   printf '%s\t%s\t%s\t%s\n' "$1" "$2" "$3" "$4" >> "$ROWS"
   N_TOTAL=$((N_TOTAL + 1))
   if [ "$3" = "FALLA" ]; then
      FAILED=1
   fi
}

# class_name_for_java_file <fichero.java>  ->  FQN (paquete.Clase o Clase si no hay `package`)
class_name_for_java_file() {
   local f="$1" pkg base
   pkg="$(grep -m1 -E '^package ' "$f" 2>/dev/null | sed -E 's/^package[[:space:]]+([A-Za-z0-9_.]+);.*/\1/')"
   base="$(basename "$f" .java)"
   if [ -n "$pkg" ]; then
      echo "$pkg.$base"
   else
      echo "$base"
   fi
}

# ---------------------------------------------------------------------
# client/test/**/*Check.java
# ---------------------------------------------------------------------
CLIENT_CHECKS="$WORK/client-checks.txt"
if [ -d "$ROOT/client/test" ]; then
   find "$ROOT/client/test" -name "*Check.java" 2>/dev/null | sort > "$CLIENT_CHECKS" || true
else
   : > "$CLIENT_CHECKS"
fi
N_CLIENT_CHECKS=$(wc -l < "$CLIENT_CHECKS" | tr -d ' ')

if [ -n "$CLIENT_BUILD" ]; then
   echo "--- client: reusando build ya compilado en $CLIENT_BUILD ---"
else
   echo "--- client: compilando client/src + client/test ---"
   CLIENT_BUILD="$WORK/client-out"
   OWN_CLIENT_BUILD=1
   mkdir -p "$CLIENT_BUILD"
   SRC_LIST="$WORK/client-sources.txt"
   : > "$SRC_LIST"
   find "$ROOT/client/src" -name "*.java" >> "$SRC_LIST"
   if [ -d "$ROOT/client/test" ]; then
      find "$ROOT/client/test" -name "*.java" >> "$SRC_LIST"
   fi
   javac -cp "$ROOT/tools/lwjgl/*" -d "$CLIENT_BUILD" @"$SRC_LIST"
   echo "compilado OK -> $CLIENT_BUILD"
fi

if [ "$N_CLIENT_CHECKS" -eq 0 ]; then
   echo "0 *Check.java en client/test — nada que ejecutar ahi"
else
   echo "$N_CLIENT_CHECKS *Check.java encontrados en client/test:"
   while IFS= read -r f; do
      CLS="$(class_name_for_java_file "$f")"
      REL="${f#"$ROOT"/}"
      set +e
      java $JMEM -cp "$CLIENT_BUILD" "$CLS" > "$WORK/last.txt" 2>&1
      RC=$?
      set -e
      if [ "$RC" -eq 0 ]; then
         echo "  PASA  $REL"
         report "client" "$CLS" "PASA" "exit 0"
      else
         echo "  FALLA $REL (exit $RC)"
         sed 's/^/    /' "$WORK/last.txt"
         report "client" "$CLS" "FALLA" "exit $RC"
      fi
   done < "$CLIENT_CHECKS"
fi
echo

# ---------------------------------------------------------------------
# editor/worldsplayer_source_editor-main/bridge/test/*Check.java
# ---------------------------------------------------------------------
BRIDGE_DIR="$ROOT/editor/worldsplayer_source_editor-main"
BRIDGE_TEST_DIR="$BRIDGE_DIR/bridge/test"
BRIDGE_CHECKS="$WORK/bridge-checks.txt"
if [ -d "$BRIDGE_TEST_DIR" ]; then
   find "$BRIDGE_TEST_DIR" -name "*Check.java" 2>/dev/null | sort > "$BRIDGE_CHECKS" || true
else
   : > "$BRIDGE_CHECKS"
fi
N_BRIDGE_CHECKS=$(wc -l < "$BRIDGE_CHECKS" | tr -d ' ')

echo "--- bridge: $N_BRIDGE_CHECKS *Check.java en bridge/test ---"
if [ "$N_BRIDGE_CHECKS" -eq 0 ]; then
   echo "0 *Check.java en bridge/test — nada que construir ni ejecutar ahi"
elif [ "$NO_BRIDGE" -eq 1 ]; then
   echo "--no-bridge: se saltan los $N_BRIDGE_CHECKS *Check.java de bridge/test"
else
   BRIDGE_OUT="$(cd "$BRIDGE_DIR/.." 2>/dev/null && pwd)/.build-gamma/out"
   if [ ! -d "$BRIDGE_OUT" ]; then
      echo "editor/.build-gamma/out no existe: construyendo con build_gamma.sh (puede tardar) ..."
      "$BRIDGE_DIR/build_gamma.sh"
   elif [ -n "$(find "$BRIDGE_DIR/bridge/NET" "$BRIDGE_DIR/bridge" "$BRIDGE_DIR/apply_mock.sh" "$BRIDGE_DIR/build_gamma.sh" \
                  "$ROOT/client/src/net/freeworlds/cmp" "$ROOT/client/src/net/freeworlds/rwg" "$ROOT/client/src/net/freeworlds/bod" \
                  -maxdepth 4 \( -name '*.java' -o -name '*.patch' -o -name '*.sh' \) -not -path '*/bridge/test/*' \
                  -newer "$BRIDGE_OUT" 2>/dev/null | head -1)" ]; then
      # Una build vieja compila los checks contra clases que ya no existen
      # (o peor, los pasa contra codigo que ya cambio): se rehace.
      echo "editor/.build-gamma/out es anterior a cambios del puente: reconstruyendo con build_gamma.sh ..."
      "$BRIDGE_DIR/build_gamma.sh"
   fi
   if [ ! -d "$BRIDGE_OUT" ]; then
      echo "build_gamma.sh no dejo $BRIDGE_OUT - no se pueden ejecutar los checks de bridge/test" >&2
      report "bridge" "(build_gamma.sh)" "FALLA" "no genero $BRIDGE_OUT"
   else
      BRIDGE_TEST_BUILD="$WORK/bridge-test-out"
      mkdir -p "$BRIDGE_TEST_BUILD"
      javac -cp "$BRIDGE_OUT" -d "$BRIDGE_TEST_BUILD" @"$BRIDGE_CHECKS"
      while IFS= read -r f; do
         CLS="$(class_name_for_java_file "$f")"
         REL="${f#"$ROOT"/}"
         set +e
         java $JMEM -cp "$BRIDGE_OUT:$BRIDGE_TEST_BUILD" "$CLS" > "$WORK/last.txt" 2>&1
         RC=$?
         set -e
         if [ "$RC" -eq 0 ]; then
            echo "  PASA  $REL"
            report "bridge" "$CLS" "PASA" "exit 0"
         else
            echo "  FALLA $REL (exit $RC)"
            sed 's/^/    /' "$WORK/last.txt"
            report "bridge" "$CLS" "FALLA" "exit $RC"
         fi
      done < "$BRIDGE_CHECKS"
   fi
fi
echo

# ---------------------------------------------------------------------
# resumen
# ---------------------------------------------------------------------
echo "--- resumen run-checks ---"
if [ "$N_TOTAL" -eq 0 ]; then
   echo "0 *Check.java encontrados en total (client/test ni bridge/test tienen ninguno todavia)"
else
   printf '%-10s %-55s %-6s %s\n' "Grupo" "Clase" "Estado" "Detalle"
   while IFS="$(printf '\t')" read -r a b c d; do
      printf '%-10s %-55s %-6s %s\n' "$a" "$b" "$c" "$d"
   done < "$ROWS"
   N_PASA=$(awk -F'\t' '$3=="PASA"{n++} END{print n+0}' "$ROWS")
   echo
   echo "$N_PASA / $N_TOTAL checks OK"
fi

if [ "$FAILED" -eq 1 ]; then
   exit 1
fi
exit 0

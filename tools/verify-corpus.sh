#!/usr/bin/env bash
# verify-corpus.sh — runner de regresion del hito H0 de docs/roadmap.md:
# un solo comando que compila formats/ (src + test) y vuelve a ejecutar,
# contra el corpus real de assets/, los recuentos que CLAUDE.md da por ✅.
# Si alguna cifra cambia, imprime la tabla con esperado/obtenido y sale con
# codigo != 0 - es lo unico que hasta ahora se reejecutaba a mano en cada
# auditoria (docs/worlds-chat-project.md, seccion "AUDITORIA", 2026-09-15).
#
# Que compara y de donde sale cada cifra (puntos de entrada reales, todos
# en formats/src salvo el marcado [formats/test]):
#   .seq 231/231      SeqExtractMain -q sobre TODOS los .seq de
#                     assets/WorldsPlayer/cachedir y
#                     assets/gammatutorial-samples/base-avatars.
#   .bod 51/51        BodExtractMain, mismos dos directorios, *.bod.
#   .cmp 159/159      [formats/test] CmpMovCorpusCheck (net.openworlds.corpus):
#   .mov 52/52        no existia ningun *Main que decodificara el corpus
#                     agregado (CmpStage2 solo compara un fichero de
#                     evidencia capturada a mano). Extrae tex/*.cmp y
#                     tex/*.mov de assets/WorldsPlayer/GroundZero/content.zip
#                     con java.util.zip (sin depender de `unzip`) y decodifica
#                     cada uno con CmpTexture.loadRaw/loadMov, sobre CmpFrames,
#                     el mismo decodificador que usa el puente.
#
# Las filas RWX 118/118 (y contra three-rwx-loader), .world 25/578/103 y
# nombres de avatar 146/148 se quitaron el 2026-09-26 junto con el motor
# nuevo: sus lectores solo los usaba el. Estan en el historial de git
# (client/src hasta el commit 8cd795d).
#
# Uso:
#   tools/verify-corpus.sh [--no-checks] [--no-bridge]
#     --no-checks   no llama a run-checks.sh al final.
#     --no-bridge   se pasa tal cual a run-checks.sh (ver ese script).
#
# bash 3.2 compatible: sin arrays vacios bajo `set -u` (se usan ficheros de
# lista + bucles `while read` en vez de arrays donde el corpus podria
# quedar vacio).
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

RUN_CHECKS=1
PASS_NO_BRIDGE=0
for arg in "$@"; do
   case "$arg" in
      --no-checks) RUN_CHECKS=0 ;;
      --no-bridge) PASS_NO_BRIDGE=1 ;;
      -h|--help)
         echo "Uso: $0 [--no-checks] [--no-bridge]"
         exit 0 ;;
      *)
         echo "Argumento desconocido: $arg" >&2
         exit 2 ;;
   esac
done

JMEM="-Xmx512m"
BUILD="$(mktemp -d "${TMPDIR:-/tmp}/fw-verify-corpus.XXXXXX")"
cleanup() { rm -rf "$BUILD"; }
trap cleanup EXIT

echo "=== OpenWorlds verify-corpus $(date +%Y-%m-%dT%H:%M:%S%z) ==="
echo "root: $ROOT"
echo "build temporal: $BUILD"
echo

echo "--- compilando formats/src + formats/test ---"
SRC_LIST="$BUILD/sources.txt"
: > "$SRC_LIST"
find "$ROOT/formats/src" -name "*.java" >> "$SRC_LIST"
if [ -d "$ROOT/formats/test" ]; then
   find "$ROOT/formats/test" -name "*.java" >> "$SRC_LIST"
fi
N_SRC=$(wc -l < "$SRC_LIST" | tr -d ' ')
javac -d "$BUILD" @"$SRC_LIST"
echo "compilado OK: $N_SRC ficheros -> $BUILD"
echo

FAILED=0
ROWS="$BUILD/rows.txt"
: > "$ROWS"

row() {
   # row <formato> <esperado> <obtenido> <estado(OK|FALLO|SALTADO)>
   printf '%s\t%s\t%s\t%s\n' "$1" "$2" "$3" "$4" >> "$ROWS"
   if [ "$4" = "FALLO" ]; then
      FAILED=1
   fi
}

CAP="$BUILD/cap.txt"
capture() {
   # capture <cmd...>  ->  stdout+stderr en $CAP, codigo en $CAP_RC (nunca aborta con set -e)
   set +e
   "$@" > "$CAP" 2>&1
   CAP_RC=$?
   set -e
}

# ---------------------------------------------------------------------
# .seq: 231/231
# ---------------------------------------------------------------------
SEQ_LIST="$BUILD/seq-files.txt"
find "$ROOT/assets/WorldsPlayer/cachedir" "$ROOT/assets/gammatutorial-samples/base-avatars" -iname "*.seq" 2>/dev/null | sort > "$SEQ_LIST" || true
SEQ_TOTAL=$(wc -l < "$SEQ_LIST" | tr -d ' ')
if [ "$SEQ_TOTAL" -gt 0 ]; then
   set +e
   xargs -n 10000 java $JMEM -cp "$BUILD" net.openworlds.bod.SeqExtractMain -q < "$SEQ_LIST" > "$CAP" 2>&1
   CAP_RC=$?
   set -e
   SEQ_LINE="$(grep -E '/ [0-9]+ files fully consumed' "$CAP" | tail -n 1)"
   SEQ_OK="$(echo "$SEQ_LINE" | sed -E 's#^([0-9]+) / ([0-9]+).*#\1#')"
   SEQ_OF="$(echo "$SEQ_LINE" | sed -E 's#^([0-9]+) / ([0-9]+).*#\2#')"
   if [ "${SEQ_OK:-0}" = "231" ] && [ "${SEQ_OF:-0}" = "231" ]; then
      row ".seq" "231/231" "$SEQ_OK/$SEQ_OF" "OK"
   else
      row ".seq" "231/231" "${SEQ_OK:-?}/${SEQ_OF:-?} (total encontrado: $SEQ_TOTAL)" "FALLO"
      cat "$CAP"
   fi
else
   row ".seq" "231/231" "0 ficheros encontrados" "FALLO"
fi

# ---------------------------------------------------------------------
# .bod: 51/51
# ---------------------------------------------------------------------
BOD_LIST="$BUILD/bod-files.txt"
find "$ROOT/assets/WorldsPlayer/cachedir" "$ROOT/assets/gammatutorial-samples/base-avatars" -iname "*.bod" 2>/dev/null | sort > "$BOD_LIST" || true
BOD_TOTAL=$(wc -l < "$BOD_LIST" | tr -d ' ')
if [ "$BOD_TOTAL" -gt 0 ]; then
   set +e
   xargs -n 10000 java $JMEM -cp "$BUILD" net.openworlds.bod.BodExtractMain < "$BOD_LIST" > "$CAP" 2>&1
   CAP_RC=$?
   set -e
   BOD_LINE="$(grep -E '/ [0-9]+ files fully consumed' "$CAP" | tail -n 1)"
   BOD_OK="$(echo "$BOD_LINE" | sed -E 's#^([0-9]+) / ([0-9]+).*#\1#')"
   BOD_OF="$(echo "$BOD_LINE" | sed -E 's#^([0-9]+) / ([0-9]+).*#\2#')"
   if [ "${BOD_OK:-0}" = "51" ] && [ "${BOD_OF:-0}" = "51" ]; then
      row ".bod" "51/51" "$BOD_OK/$BOD_OF" "OK"
   else
      row ".bod" "51/51" "${BOD_OK:-?}/${BOD_OF:-?} (total encontrado: $BOD_TOTAL)" "FALLO"
      cat "$CAP"
   fi
else
   row ".bod" "51/51" "0 ficheros encontrados" "FALLO"
fi

# ---------------------------------------------------------------------
# .cmp / .mov: 159/159, 52/52 (content.zip, ver CmpMovCorpusCheck)
# ---------------------------------------------------------------------
CONTENT_ZIP="$ROOT/assets/WorldsPlayer/GroundZero/content.zip"
if [ -f "$CONTENT_ZIP" ]; then
   capture java $JMEM -cp "$BUILD" net.openworlds.corpus.CmpMovCorpusCheck "$CONTENT_ZIP"
   CMP_LINE="$(grep -E '^CMP ' "$CAP" || true)"
   MOV_LINE="$(grep -E '^MOV ' "$CAP" || true)"
   if [ "$CAP_RC" -eq 0 ]; then
      row ".cmp" "159/159" "$(echo "$CMP_LINE" | sed -E 's/^CMP //')" "OK"
      row ".mov" "52/52" "$(echo "$MOV_LINE" | sed -E 's/^MOV //')" "OK"
   else
      row ".cmp" "159/159" "$(echo "$CMP_LINE" | sed -E 's/^CMP //')" "FALLO"
      row ".mov" "52/52" "$(echo "$MOV_LINE" | sed -E 's/^MOV //')" "FALLO"
      cat "$CAP"
   fi
else
   row ".cmp" "159/159" "no existe $CONTENT_ZIP" "FALLO"
   row ".mov" "52/52" "no existe $CONTENT_ZIP" "FALLO"
fi

# ---------------------------------------------------------------------
# Tabla final
# ---------------------------------------------------------------------
echo
echo "--- resultado ---"
printf '%-32s %-14s %-46s %s\n' "Formato" "Esperado" "Obtenido" "Estado"
printf '%-32s %-14s %-46s %s\n' "-------" "--------" "--------" "------"
while IFS="$(printf '\t')" read -r a b c d; do
   printf '%-32s %-14s %-46s %s\n' "$a" "$b" "$c" "$d"
done < "$ROWS"
echo

if [ "$FAILED" -eq 1 ]; then
   echo "*** al menos una cifra no coincide con lo esperado (regresion) ***"
fi

# ---------------------------------------------------------------------
# run-checks.sh (reusa este mismo build ya compilado)
# ---------------------------------------------------------------------
if [ "$RUN_CHECKS" -eq 1 ]; then
   echo
   echo "--- run-checks.sh ---"
   set +e
   if [ "$PASS_NO_BRIDGE" -eq 1 ]; then
      "$ROOT/tools/run-checks.sh" --no-bridge --formats-build "$BUILD"
   else
      "$ROOT/tools/run-checks.sh" --formats-build "$BUILD"
   fi
   CHECKS_RC=$?
   set -e
   if [ "$CHECKS_RC" -ne 0 ]; then
      FAILED=1
   fi
else
   echo
   echo "(--no-checks: se salta run-checks.sh)"
fi

if [ "$FAILED" -eq 1 ]; then
   exit 1
fi
echo "=== verify-corpus: sin fallos ==="
exit 0

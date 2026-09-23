#!/usr/bin/env bash
# verify-corpus.sh — runner de regresion del hito H0 de docs/roadmap.md:
# un solo comando que compila client/ (src + test) y vuelve a ejecutar,
# contra el corpus real de assets/, los recuentos que CLAUDE.md da por ✅.
# Si alguna cifra cambia, imprime la tabla con esperado/obtenido y sale con
# codigo != 0 - es lo unico que hasta ahora se reejecutaba a mano en cada
# auditoria (docs/worlds-chat-project.md, seccion "AUDITORIA", 2026-09-15).
#
# Que compara y de donde sale cada cifra (puntos de entrada reales, todos
# en client/src salvo el marcado [client/test], nuevo de esta sesion):
#   RWX 118/118      RwxExtractMain, 1 fichero por invocacion (igual que
#                     tools/rwx-harness/compare.py). Corpus: union de
#                     assets/GROUNDZERO/*.RWX (59) y
#                     assets/WorldsPlayer/GroundZero/tex/*.rwx (59) - el
#                     mismo conjunto que docs/rwx-parser-progress.md.
#   .world 25/578/103 WorldExtractMain sobre
#                     assets/WorldsPlayer/GroundZero/groundzero.world
#                     ("Rooms:", "Total nodes...:", "Total shapes...:").
#   .seq 231/231      SeqExtractMain -q sobre TODOS los .seq de
#                     assets/WorldsPlayer/cachedir y
#                     assets/gammatutorial-samples/base-avatars.
#   .bod 51/51        BodExtractMain, mismos dos directorios, *.bod.
#   .cmp 159/159      [client/test] CmpMovCorpusCheck (net.freeworlds.corpus):
#   .mov 52/52        no existia ningun *Main que decodificara el corpus
#                     agregado (CmpStage2 solo compara un fichero de
#                     evidencia capturada a mano). Extrae tex/*.cmp y
#                     tex/*.mov de assets/WorldsPlayer/GroundZero/content.zip
#                     con java.util.zip (sin depender de `unzip`) y decodifica
#                     cada uno con CmpTexture.loadRaw/loadMov, el camino real
#                     del pipeline de materiales.
#   avatares 146/148  AvatarNameMain --todos ("decodificados sin anomalias:").
#
# RWX contra three-rwx-loader (JS) necesita node; tools/node (historico) es
# un ELF de Linux y no corre en este Mac. Desde 2026-09-23 hay un node
# oficial darwin-x64 en tools/node-macos/ (gitignored, provisionar aparte y
# enlazar en el worktree: ver COMUN.md) - si esta ahi (o hay node en PATH) y
# tools/rwx-harness/node_modules existe, este script llama de verdad a
# tools/rwx-harness/compare.py (con FREEWORLDS_NODE_BIN/FREEWORLDS_CLIENT_OUT,
# variables anadidas a compare.py para esto - ver ese fichero) sobre los 118
# .rwx y compara la geometria real, ya no solo "no lanza excepcion". Si
# falta node o node_modules lo dice y SALTA esa fila (no la simula).
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

echo "=== FreeWorlds verify-corpus $(date +%Y-%m-%dT%H:%M:%S%z) ==="
echo "root: $ROOT"
echo "build temporal: $BUILD"
echo

echo "--- compilando client/src + client/test ---"
SRC_LIST="$BUILD/sources.txt"
: > "$SRC_LIST"
find "$ROOT/client/src" -name "*.java" >> "$SRC_LIST"
if [ -d "$ROOT/client/test" ]; then
   find "$ROOT/client/test" -name "*.java" >> "$SRC_LIST"
fi
N_SRC=$(wc -l < "$SRC_LIST" | tr -d ' ')
javac -cp "$ROOT/tools/lwjgl/*" -d "$BUILD" @"$SRC_LIST"
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
# RWX: 118/118 (lado Java)
# ---------------------------------------------------------------------
RWX_LIST="$BUILD/rwx-files.txt"
find "$ROOT/assets/GROUNDZERO" "$ROOT/assets/WorldsPlayer/GroundZero/tex" -iname "*.rwx" 2>/dev/null | sort > "$RWX_LIST" || true
RWX_TOTAL=$(wc -l < "$RWX_LIST" | tr -d ' ')
RWX_OK=0
if [ "$RWX_TOTAL" -gt 0 ]; then
   while IFS= read -r f; do
      capture java $JMEM -cp "$BUILD" net.freeworlds.rwx.RwxExtractMain "$f"
      OUT="$(cat "$CAP")"
      case "$OUT" in
         *'"error"'*) echo "  RWX FALLO: $f"; head -c 300 "$CAP"; echo ;;
         *) RWX_OK=$((RWX_OK + 1)) ;;
      esac
   done < "$RWX_LIST"
fi
if [ "$RWX_OK" -eq 118 ] && [ "$RWX_TOTAL" -eq 118 ]; then
   row "RWX (Java)" "118/118" "$RWX_OK/$RWX_TOTAL" "OK"
else
   row "RWX (Java)" "118/118" "$RWX_OK/$RWX_TOTAL" "FALLO"
fi

# tools/rwx-harness/compare.py (mismo corpus RWX_LIST) corre el JS real
# (three-rwx-loader via extract.mjs) contra RwxExtractMain y compara la
# geometria - la unica comparacion independiente que tenemos para RWX (el
# recuento OK/OK de arriba solo prueba que el lado Java no lanza excepcion,
# no que el resultado sea correcto). Necesita: (a) un node que corra en
# este Mac - tools/node es un ELF de Linux, de ahi que se comprueben
# tools/node-macos/bin/node y el PATH primero - y (b)
# tools/rwx-harness/node_modules (jsdom etc., gitignored: enlazar desde el
# repo principal como tools/jdk/tools/lwjgl, ver COMUN.md). Si falta
# cualquiera de las dos, se dice exactamente que falta y se SALTA - no se
# fabrica un resultado.
NODE_BIN=""
if [ -x "$ROOT/tools/node-macos/bin/node" ]; then
   NODE_BIN="$ROOT/tools/node-macos/bin/node"
elif command -v node >/dev/null 2>&1; then
   NODE_BIN="$(command -v node)"
fi

if [ -z "$NODE_BIN" ]; then
   row "RWX vs three-rwx-loader (JS)" "118/118" "sin node usable" "SALTADO (no hay tools/node-macos/bin/node ni node en PATH - tools/node es ELF de Linux; no se simula)"
elif [ ! -d "$ROOT/tools/rwx-harness/node_modules" ]; then
   row "RWX vs three-rwx-loader (JS)" "118/118" "node OK ($NODE_BIN) pero falta tools/rwx-harness/node_modules" "SALTADO (enlaza node_modules desde el repo principal; no se simula)"
else
   echo "--- RWX vs three-rwx-loader (JS): $RWX_TOTAL ficheros, un proceso node + uno java cada uno (varios minutos) ---"
   set +e
   FREEWORLDS_NODE_BIN="$NODE_BIN" FREEWORLDS_CLIENT_OUT="$BUILD" \
      python3 -u "$ROOT/tools/rwx-harness/compare.py" --files-from "$RWX_LIST" 2>&1 | tee "$CAP"
   CMP_RC=$?
   set -e
   JS_OK=$(grep -c '^OK ' "$CAP" || true)
   JS_DIFF=$(grep -c '^DIFERENCIAS' "$CAP" || true)
   JS_FALLA=$(grep -c '^FALLA' "$CAP" || true)
   JS_TOTAL=$((JS_OK + JS_DIFF + JS_FALLA))
   DETALLE="$JS_OK OK / $JS_DIFF con diferencias / $JS_FALLA fallan (de $JS_TOTAL)"
   if [ "$CMP_RC" -eq 0 ] && [ "$JS_OK" -eq 118 ] && [ "$JS_TOTAL" -eq 118 ]; then
      row "RWX vs three-rwx-loader (JS)" "118/118" "$DETALLE" "OK"
   else
      row "RWX vs three-rwx-loader (JS)" "118/118" "$DETALLE" "FALLO"
      echo "  detalle de lo que no fue OK (no se toca el parser: solo se informa):"
      grep -E '^(DIFERENCIAS|FALLA)' "$CAP" || true
   fi
fi

# ---------------------------------------------------------------------
# .world: 25 salas / 578 nodos / 103 objetos
# ---------------------------------------------------------------------
WORLD_FILE="$ROOT/assets/WorldsPlayer/GroundZero/groundzero.world"
if [ -f "$WORLD_FILE" ]; then
   capture java $JMEM -cp "$BUILD" net.freeworlds.world.WorldExtractMain "$WORLD_FILE"
   if [ "$CAP_RC" -eq 0 ]; then
      ROOMS=$(grep -E '^Rooms: ' "$CAP" | sed -E 's/^Rooms: ([0-9]+).*/\1/' || echo "?")
      NODES=$(grep -E '^Total nodes' "$CAP" | sed -E 's/.*: ([0-9]+)$/\1/' || echo "?")
      SHAPES=$(grep -E '^Total shapes' "$CAP" | sed -E 's/.*: ([0-9]+)$/\1/' || echo "?")
      if [ "$ROOMS" = "25" ] && [ "$NODES" = "578" ] && [ "$SHAPES" = "103" ]; then
         row ".world (GroundZero)" "25 salas / 578 nodos / 103 obj" "$ROOMS salas / $NODES nodos / $SHAPES obj" "OK"
      else
         row ".world (GroundZero)" "25 salas / 578 nodos / 103 obj" "$ROOMS salas / $NODES nodos / $SHAPES obj" "FALLO"
      fi
   else
      row ".world (GroundZero)" "25 salas / 578 nodos / 103 obj" "excepcion (ver arriba)" "FALLO"
      cat "$CAP"
   fi
else
   row ".world (GroundZero)" "25 salas / 578 nodos / 103 obj" "no existe $WORLD_FILE" "FALLO"
fi

# ---------------------------------------------------------------------
# .seq: 231/231
# ---------------------------------------------------------------------
SEQ_LIST="$BUILD/seq-files.txt"
find "$ROOT/assets/WorldsPlayer/cachedir" "$ROOT/assets/gammatutorial-samples/base-avatars" -iname "*.seq" 2>/dev/null | sort > "$SEQ_LIST" || true
SEQ_TOTAL=$(wc -l < "$SEQ_LIST" | tr -d ' ')
if [ "$SEQ_TOTAL" -gt 0 ]; then
   set +e
   xargs -n 10000 java $JMEM -cp "$BUILD" net.freeworlds.bod.SeqExtractMain -q < "$SEQ_LIST" > "$CAP" 2>&1
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
   xargs -n 10000 java $JMEM -cp "$BUILD" net.freeworlds.bod.BodExtractMain < "$BOD_LIST" > "$CAP" 2>&1
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
   capture java $JMEM -cp "$BUILD" net.freeworlds.corpus.CmpMovCorpusCheck "$CONTENT_ZIP"
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
# Nombres de avatar: 146/148 limpios
# ---------------------------------------------------------------------
capture java $JMEM -cp "$BUILD" net.freeworlds.avatar.AvatarNameMain --todos
if [ "$CAP_RC" -eq 0 ]; then
   AV_LINE="$(grep -E '^decodificados sin anomalias:' "$CAP" || true)"
   AV_OK="$(echo "$AV_LINE" | sed -E 's#^decodificados sin anomalias: ([0-9]+)/([0-9]+).*#\1#')"
   AV_OF="$(echo "$AV_LINE" | sed -E 's#^decodificados sin anomalias: ([0-9]+)/([0-9]+).*#\2#')"
   if [ "${AV_OK:-0}" = "146" ] && [ "${AV_OF:-0}" = "148" ]; then
      row "Nombres de avatar" "146/148" "$AV_OK/$AV_OF" "OK"
   else
      row "Nombres de avatar" "146/148" "${AV_OK:-?}/${AV_OF:-?}" "FALLO"
      cat "$CAP"
   fi
else
   row "Nombres de avatar" "146/148" "excepcion (ver arriba)" "FALLO"
   cat "$CAP"
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
      "$ROOT/tools/run-checks.sh" --no-bridge --client-build "$BUILD"
   else
      "$ROOT/tools/run-checks.sh" --client-build "$BUILD"
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

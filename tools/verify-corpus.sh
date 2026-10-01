#!/usr/bin/env bash
# verify-corpus.sh — regression runner for milestone H0 of docs/roadmap.md:
# a single command that compiles formats/ (src + test) and re-runs, against
# the real corpus in assets/, the counts that CLAUDE.md marks as ✅.
# If any figure changes, it prints the table with expected/got and exits
# with a code != 0 - until now this was the one thing re-run by hand in
# every audit (docs/worlds-chat-project.md, section "AUDIT", 2026-09-15).
#
# What it compares and where each figure comes from (real entry points, all
# in formats/src except the one marked [formats/test]):
#   .seq 231/231      SeqExtractMain -q over ALL the .seq files in
#                     assets/WorldsPlayer/cachedir and
#                     assets/gammatutorial-samples/base-avatars.
#   .bod 51/51        BodExtractMain, same two directories, *.bod.
#   .cmp 159/159      [formats/test] CmpMovCorpusCheck (net.openworlds.corpus):
#   .mov 52/52        there was no *Main that decoded the aggregate corpus
#                     (CmpStage2 only compares one file of hand-captured
#                     evidence). It extracts tex/*.cmp and tex/*.mov from
#                     assets/WorldsPlayer/GroundZero/content.zip with
#                     java.util.zip (no dependency on `unzip`) and decodes
#                     each one with CmpTexture.loadRaw/loadMov, on top of
#                     CmpFrames, the same decoder the bridge uses.
#
# The RWX 118/118 (and against three-rwx-loader), .world 25/578/103 and
# avatar name 146/148 rows were removed on 2026-09-26 together with the new
# engine: only it used their readers. They are in the git history
# (client/src up to commit 8cd795d).
#
# Usage:
#   tools/verify-corpus.sh [--no-checks] [--no-bridge]
#     --no-checks   don't call run-checks.sh at the end.
#     --no-bridge   passed as is to run-checks.sh (see that script).
#
# bash 3.2 compatible: no empty arrays under `set -u` (list files +
# `while read` loops are used instead of arrays wherever the corpus could
# come out empty).
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
         echo "Usage: $0 [--no-checks] [--no-bridge]"
         exit 0 ;;
      *)
         echo "Unknown argument: $arg" >&2
         exit 2 ;;
   esac
done

JMEM="-Xmx512m"
BUILD="$(mktemp -d "${TMPDIR:-/tmp}/fw-verify-corpus.XXXXXX")"
cleanup() { rm -rf "$BUILD"; }
trap cleanup EXIT

echo "=== OpenWorlds verify-corpus $(date +%Y-%m-%dT%H:%M:%S%z) ==="
echo "root: $ROOT"
echo "temporary build: $BUILD"
echo

echo "--- compiling formats/src + formats/test ---"
SRC_LIST="$BUILD/sources.txt"
: > "$SRC_LIST"
find "$ROOT/formats/src" -name "*.java" >> "$SRC_LIST"
if [ -d "$ROOT/formats/test" ]; then
   find "$ROOT/formats/test" -name "*.java" >> "$SRC_LIST"
fi
N_SRC=$(wc -l < "$SRC_LIST" | tr -d ' ')
javac -d "$BUILD" @"$SRC_LIST"
echo "compiled OK: $N_SRC files -> $BUILD"
echo

FAILED=0
ROWS="$BUILD/rows.txt"
: > "$ROWS"

row() {
   # row <format> <expected> <got> <status(OK|FAIL|SKIPPED)>
   printf '%s\t%s\t%s\t%s\n' "$1" "$2" "$3" "$4" >> "$ROWS"
   if [ "$4" = "FAIL" ]; then
      FAILED=1
   fi
}

CAP="$BUILD/cap.txt"
capture() {
   # capture <cmd...>  ->  stdout+stderr in $CAP, exit code in $CAP_RC (never aborts under set -e)
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
      row ".seq" "231/231" "${SEQ_OK:-?}/${SEQ_OF:-?} (total found: $SEQ_TOTAL)" "FAIL"
      cat "$CAP"
   fi
else
   row ".seq" "231/231" "0 files found" "FAIL"
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
      row ".bod" "51/51" "${BOD_OK:-?}/${BOD_OF:-?} (total found: $BOD_TOTAL)" "FAIL"
      cat "$CAP"
   fi
else
   row ".bod" "51/51" "0 files found" "FAIL"
fi

# ---------------------------------------------------------------------
# .cmp / .mov: 159/159, 52/52 (content.zip, see CmpMovCorpusCheck)
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
      row ".cmp" "159/159" "$(echo "$CMP_LINE" | sed -E 's/^CMP //')" "FAIL"
      row ".mov" "52/52" "$(echo "$MOV_LINE" | sed -E 's/^MOV //')" "FAIL"
      cat "$CAP"
   fi
else
   row ".cmp" "159/159" "$CONTENT_ZIP does not exist" "FAIL"
   row ".mov" "52/52" "$CONTENT_ZIP does not exist" "FAIL"
fi

# ---------------------------------------------------------------------
# Final table
# ---------------------------------------------------------------------
echo
echo "--- result ---"
printf '%-32s %-14s %-46s %s\n' "Format" "Expected" "Got" "Status"
printf '%-32s %-14s %-46s %s\n' "------" "--------" "---" "------"
while IFS="$(printf '\t')" read -r a b c d; do
   printf '%-32s %-14s %-46s %s\n' "$a" "$b" "$c" "$d"
done < "$ROWS"
echo

if [ "$FAILED" -eq 1 ]; then
   echo "*** at least one figure does not match the expected one (regression) ***"
fi

# ---------------------------------------------------------------------
# run-checks.sh (reuses this same, already compiled build)
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
   echo "(--no-checks: skipping run-checks.sh)"
fi

if [ "$FAILED" -eq 1 ]; then
   exit 1
fi
echo "=== verify-corpus: no failures ==="
exit 0

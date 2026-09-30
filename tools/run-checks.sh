#!/usr/bin/env bash
# run-checks.sh - runs every unit check of the repository: compiles and runs
# each *Check.java under formats/test/** (classpath: the formats/ classes),
# editor/worldsplayer_source_editor-main/bridge/test/ (classpath:
# editor/.build-gamma/out), launcher/test/** (the launcher and ui/ modules)
# and server/test/** (J Solar Server and ui/).
# Contract: a *Check is a class with a `main` that exits 0 when it passes and
# non-zero when it fails.
#
# Usage:
#   tools/run-checks.sh [--no-bridge] [--formats-build DIR]
#     --no-bridge         neither builds nor runs the checks of bridge/test
#                         (handy when you do not want to pay for build_gamma.sh).
#     --formats-build DIR reuses a build of formats/src+test already compiled in
#                         DIR instead of compiling one; verify-corpus.sh uses it
#                         so as not to compile twice.
#
# If bridge/test has *Check.java files but editor/.build-gamma/out does not
# exist yet (or is older than the bridge sources), this script calls
# build_gamma.sh first (it compiles the whole bridge: it can take a while).
#
# bash 3.2 compatible: no empty arrays under `set -u`.
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
FORMATS_BUILD=""
while [ $# -gt 0 ]; do
   case "$1" in
      --no-bridge) NO_BRIDGE=1; shift ;;
      --formats-build) FORMATS_BUILD="$2"; shift 2 ;;
      -h|--help)
         echo "Usage: $0 [--no-bridge] [--formats-build DIR]"
         exit 0 ;;
      *)
         echo "Unknown argument: $1" >&2
         exit 2 ;;
   esac
done

JMEM="-Xmx512m"
WORK="$(mktemp -d "${TMPDIR:-/tmp}/fw-run-checks.XXXXXX")"
cleanup() { rm -rf "$WORK"; }
trap cleanup EXIT

FAILED=0
ROWS="$WORK/rows.txt"
: > "$ROWS"
N_TOTAL=0

report() {
   # report <group> <class> <state (PASS|FAIL)> <detail>
   printf '%s\t%s\t%s\t%s\n' "$1" "$2" "$3" "$4" >> "$ROWS"
   N_TOTAL=$((N_TOTAL + 1))
   if [ "$3" = "FAIL" ]; then
      FAILED=1
   fi
}

# class_name_for_java_file <file.java>  ->  FQN (package.Class, or Class without a `package`)
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

# run_check <group> <classpath> <file.java>
run_check() {
   local group="$1" cp="$2" f="$3" cls rel rc
   cls="$(class_name_for_java_file "$f")"
   rel="${f#"$ROOT"/}"
   set +e
   java $JMEM -cp "$cp" "$cls" > "$WORK/last.txt" 2>&1
   rc=$?
   set -e
   if [ "$rc" -eq 0 ]; then
      echo "  PASS  $rel"
      report "$group" "$cls" "PASS" "exit 0"
   else
      echo "  FAIL  $rel (exit $rc)"
      sed 's/^/    /' "$WORK/last.txt"
      report "$group" "$cls" "FAIL" "exit $rc"
   fi
}

# ---------------------------------------------------------------------
# formats/test/**/*Check.java
# ---------------------------------------------------------------------
FORMATS_CHECKS="$WORK/formats-checks.txt"
if [ -d "$ROOT/formats/test" ]; then
   find "$ROOT/formats/test" -name "*Check.java" 2>/dev/null | sort > "$FORMATS_CHECKS" || true
else
   : > "$FORMATS_CHECKS"
fi
N_FORMATS_CHECKS=$(wc -l < "$FORMATS_CHECKS" | tr -d ' ')

if [ -n "$FORMATS_BUILD" ]; then
   echo "--- formats: reusing the build in $FORMATS_BUILD ---"
else
   echo "--- formats: compiling formats/src + formats/test ---"
   FORMATS_BUILD="$WORK/formats-out"
   mkdir -p "$FORMATS_BUILD"
   SRC_LIST="$WORK/formats-sources.txt"
   : > "$SRC_LIST"
   find "$ROOT/formats/src" -name "*.java" >> "$SRC_LIST"
   if [ -d "$ROOT/formats/test" ]; then
      find "$ROOT/formats/test" -name "*.java" >> "$SRC_LIST"
   fi
   javac -d "$FORMATS_BUILD" @"$SRC_LIST"
   echo "compiled -> $FORMATS_BUILD"
fi

if [ "$N_FORMATS_CHECKS" -eq 0 ]; then
   echo "no *Check.java in formats/test"
else
   echo "$N_FORMATS_CHECKS *Check.java in formats/test:"
   while IFS= read -r f; do
      run_check formats "$FORMATS_BUILD" "$f"
   done < "$FORMATS_CHECKS"
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

echo "--- bridge: $N_BRIDGE_CHECKS *Check.java in bridge/test ---"
if [ "$N_BRIDGE_CHECKS" -eq 0 ]; then
   echo "no *Check.java in bridge/test: nothing to build or run there"
elif [ "$NO_BRIDGE" -eq 1 ]; then
   echo "--no-bridge: skipping the $N_BRIDGE_CHECKS *Check.java of bridge/test"
else
   BRIDGE_OUT="$(cd "$BRIDGE_DIR/.." 2>/dev/null && pwd)/.build-gamma/out"
   if [ ! -d "$BRIDGE_OUT" ]; then
      echo "editor/.build-gamma/out does not exist: building it with build_gamma.sh (it takes a while) ..."
      "$BRIDGE_DIR/build_gamma.sh"
   elif [ -n "$(find "$BRIDGE_DIR/bridge/NET" "$BRIDGE_DIR/bridge" "$BRIDGE_DIR/apply_mock.sh" "$BRIDGE_DIR/build_gamma.sh" \
                  "$ROOT/formats/src/net/openworlds/cmp" "$ROOT/formats/src/net/openworlds/rwg" "$ROOT/formats/src/net/openworlds/bod" \
                  -maxdepth 4 \( -name '*.java' -o -name '*.patch' -o -name '*.sh' \) -not -path '*/bridge/test/*' \
                  -newer "$BRIDGE_OUT" 2>/dev/null | head -1)" ]; then
      # an old build would compile the checks against classes that are gone
      # (or, worse, pass them against code that has changed): rebuild it
      echo "editor/.build-gamma/out is older than changes to the bridge: rebuilding with build_gamma.sh ..."
      "$BRIDGE_DIR/build_gamma.sh"
   fi
   if [ ! -d "$BRIDGE_OUT" ]; then
      echo "build_gamma.sh did not make $BRIDGE_OUT: the checks of bridge/test cannot run" >&2
      report "bridge" "(build_gamma.sh)" "FAIL" "no $BRIDGE_OUT"
   else
      BRIDGE_TEST_BUILD="$WORK/bridge-test-out"
      mkdir -p "$BRIDGE_TEST_BUILD"
      javac -cp "$BRIDGE_OUT" -d "$BRIDGE_TEST_BUILD" @"$BRIDGE_CHECKS"
      while IFS= read -r f; do
         run_check bridge "$BRIDGE_OUT:$BRIDGE_TEST_BUILD" "$f"
      done < "$BRIDGE_CHECKS"
   fi
fi
echo

# ---------------------------------------------------------------------
# Java modules on the shared ui/ module: launcher/ and server/ (J Solar
# Server), each with its src/, resources/ and test/**/*Check.java
# ---------------------------------------------------------------------
# module_checks <name>
module_checks() {
   local name="$1" list build n
   list="$WORK/$name-checks.txt"
   if [ -d "$ROOT/$name/test" ]; then
      find "$ROOT/$name/test" -name "*Check.java" 2>/dev/null | sort > "$list" || true
   else
      : > "$list"
   fi
   n=$(wc -l < "$list" | tr -d ' ')
   echo "--- $name: $n *Check.java in $name/test ---"
   if [ "$n" -gt 0 ]; then
      build="$WORK/$name-out"
      mkdir -p "$build"
      find "$ROOT/ui/src" "$ROOT/$name/src" "$ROOT/$name/test" -name "*.java" > "$WORK/$name-sources.txt"
      javac --release 17 -nowarn -encoding UTF-8 -d "$build" @"$WORK/$name-sources.txt"
      cp -R "$ROOT/ui/resources/." "$build/"
      if [ -d "$ROOT/$name/resources" ]; then
         cp -R "$ROOT/$name/resources/." "$build/"
      fi
      while IFS= read -r f; do
         run_check "$name" "$build" "$f"
      done < "$list"
   fi
   echo
}

module_checks launcher
module_checks server

# ---------------------------------------------------------------------
# summary
# ---------------------------------------------------------------------
echo "--- run-checks summary ---"
if [ "$N_TOTAL" -eq 0 ]; then
   echo "no *Check.java found at all"
else
   printf '%-10s %-55s %-6s %s\n' "Group" "Class" "State" "Detail"
   while IFS="$(printf '\t')" read -r a b c d; do
      printf '%-10s %-55s %-6s %s\n' "$a" "$b" "$c" "$d"
   done < "$ROWS"
   N_PASS=$(awk -F'\t' '$3=="PASS"{n++} END{print n+0}' "$ROWS")
   echo
   echo "$N_PASS / $N_TOTAL checks OK"
fi

if [ "$FAILED" -eq 1 ]; then
   exit 1
fi
exit 0

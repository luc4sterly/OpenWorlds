#!/usr/bin/env bash
# decompile-all.sh — regenerates decompiled-native/ with headless Ghidra: the
# game binaries that are decompiled whole (ExportAllDecompiled.java) and, in
# all of them, the functions reachable only through table pointers
# (ScanVtablesAndExport.java), merged by address into each one's INDEX.txt,
# with their summary in VTABLES-report.txt.
#
# Usage: GHIDRA_HOME=/path/ghidra_12.1.3_PUBLIC tools/ghidra-scripts/decompile-all.sh [binary...]
#   GHIDRA_PROJ   Ghidra project folder (default ~/ghidra-fw; outside the repo)
#   JAVA_HOME     JDK 21 (Ghidra won't start without it)
#   With no arguments it does them all; with names (e.g. gdkup.exe) only those.
#
# gamma.dll is not in the list: its dump (2537 functions, 881 of them via
# vtables) is older and was made with the same two scripts; see
# decompiled-native/README.md. The .text ranges come from the PE header.
#
# bash 3.2 compatible.
set -eu

REPO="$(cd "$(dirname "$0")/../.." && pwd)"
: "${GHIDRA_HOME:?GHIDRA_HOME not set (the ghidra_12.1.3_PUBLIC folder)}"
GH="$GHIDRA_HOME/support/analyzeHeadless"
PROJ="${GHIDRA_PROJ:-$HOME/ghidra-fw}"
mkdir -p "$PROJ"
cd "$REPO"

# binary | output folder | .text start | .text end | mode (all / vtables only)
TABLE="assets/WorldsPlayer/run.exe|decompiled-native/run_exe|00401000|00407be0|all
assets/WorldsPlayer/bin/gdkup.exe|decompiled-native/gdkup_exe|00401000|00407400|all
assets/WorldsPlayer/sfmain.exe|decompiled-native/sfmain_exe|00401000|00434200|all
assets/WorldsPlayer/bin/RWDL8D21.DLL|decompiled-native/rwdl8d21_dll|10001000|10062360|all
assets/WorldsPlayer/bin/RWDLDD21.DLL|decompiled-native/rwdldd21_dll|10001000|10032930|all
assets/WorldsPlayer/bin/rwdlmd21.dll|decompiled-native/rwdlmd21_dll|10001000|100697e0|all
assets/WorldsPlayer/bin/RWL21.DLL|decompiled-native/rwl21_dll|10001000|100505d0|vtables
assets/WorldsPlayer/bin/RWDL6D21.DLL|decompiled-native/rwdl6d21_dll|10001000|10068c90|vtables"

wanted() {
   [ $# -eq 0 ] && return 0
   local b="$1"
   shift
   for w in "$@"; do
      [ "$(echo "$w" | tr 'A-Z' 'a-z')" = "$(echo "$b" | tr 'A-Z' 'a-z')" ] && return 0
   done
   return 1
}

echo "$TABLE" | while IFS='|' read -r bin out ts te mode; do
   name="$(basename "$bin")"
   wanted "$name" "$@" || continue
   echo "=== $name -> $out ($mode)"
   if [ "$mode" = all ]; then
      rm -rf "$out"
      mkdir -p "$out"
      "$GH" "$PROJ" FW -import "$bin" -overwrite -scriptPath tools/ghidra-scripts \
         -postScript ExportAllDecompiled.java "$out" > "$PROJ/$name.export.log" 2>&1
   else
      "$GH" "$PROJ" FW -import "$bin" -overwrite > "$PROJ/$name.import.log" 2>&1
   fi
   rm -rf "$out/.vt"
   "$GH" "$PROJ" FW -process "$name" -noanalysis -scriptPath tools/ghidra-scripts \
      -postScript ScanVtablesAndExport.java "$out/.vt" "$ts" "$te" > "$PROJ/$name.vt.log" 2>&1
   # merge: the new .c files next to the others and the index sorted by address
   if ls "$out/.vt/"*.c > /dev/null 2>&1; then
      cp "$out/.vt/"*.c "$out/"
   fi
   {
      head -1 "$out/INDEX.txt"
      { tail -n +2 "$out/INDEX.txt"; grep -v '^#' "$out/.vt/NEW_INDEX.txt" 2>/dev/null || true; } | sort -u
   } > "$out/INDEX.txt.new"
   mv "$out/INDEX.txt.new" "$out/INDEX.txt"
   cp "$out/.vt/report.txt" "$out/VTABLES-report.txt"
   rm -rf "$out/.vt"
   echo "    $(($(wc -l < "$out/INDEX.txt") - 1)) functions; $(grep '^created=' "$out/VTABLES-report.txt") via vtables"
done

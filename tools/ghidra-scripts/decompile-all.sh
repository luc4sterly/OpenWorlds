#!/usr/bin/env bash
# decompile-all.sh — regenera decompiled-native/ con Ghidra headless: los
# binarios del juego que se decompilan enteros (ExportAllDecompiled.java) y,
# en todos, las funciones alcanzables solo por punteros de tablas
# (ScanVtablesAndExport.java), fusionadas en el INDEX.txt de cada uno por
# direccion, con su resumen en VTABLES-report.txt.
#
# Uso: GHIDRA_HOME=/ruta/ghidra_12.1.3_PUBLIC tools/ghidra-scripts/decompile-all.sh [binario...]
#   GHIDRA_PROJ   carpeta del proyecto Ghidra (por defecto ~/ghidra-fw; fuera del repo)
#   JAVA_HOME     JDK 21 (Ghidra no arranca sin el)
#   Sin argumentos hace todos; con nombres (p. ej. gdkup.exe) solo esos.
#
# gamma.dll no esta en la lista: su volcado (2537 funciones, 881 de ellas por
# vtable) es anterior y se hizo con los mismos dos scripts; ver
# decompiled-native/README.md. Los rangos de .text salen de la cabecera PE.
#
# bash 3.2 compatible.
set -eu

REPO="$(cd "$(dirname "$0")/../.." && pwd)"
: "${GHIDRA_HOME:?GHIDRA_HOME sin definir (carpeta de ghidra_12.1.3_PUBLIC)}"
GH="$GHIDRA_HOME/support/analyzeHeadless"
PROJ="${GHIDRA_PROJ:-$HOME/ghidra-fw}"
mkdir -p "$PROJ"
cd "$REPO"

# binario | carpeta de salida | inicio .text | fin .text | modo (todo / solo vtables)
TABLE="assets/WorldsPlayer/run.exe|decompiled-native/run_exe|00401000|00407be0|todo
assets/WorldsPlayer/bin/gdkup.exe|decompiled-native/gdkup_exe|00401000|00407400|todo
assets/WorldsPlayer/sfmain.exe|decompiled-native/sfmain_exe|00401000|00434200|todo
assets/WorldsPlayer/bin/RWDL8D21.DLL|decompiled-native/rwdl8d21_dll|10001000|10062360|todo
assets/WorldsPlayer/bin/RWDLDD21.DLL|decompiled-native/rwdldd21_dll|10001000|10032930|todo
assets/WorldsPlayer/bin/rwdlmd21.dll|decompiled-native/rwdlmd21_dll|10001000|100697e0|todo
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
   if [ "$mode" = todo ]; then
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
   # fusion: los .c nuevos junto a los demas y el indice ordenado por direccion
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
   echo "    $(($(wc -l < "$out/INDEX.txt") - 1)) funciones; $(grep '^creadas=' "$out/VTABLES-report.txt") por vtable"
done

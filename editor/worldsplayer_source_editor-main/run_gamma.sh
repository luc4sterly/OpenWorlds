#!/bin/bash
# Arranca el cliente ORIGINAL decompilado (NET.worlds.console.Gamma) con el
# puente portable de bridge/, desde una copia de la instalacion 2004
# (assets/WorldsPlayer) para no escribir en el repo. Requiere haber
# ejecutado build_gamma.sh (ver bridge/README.md).
# Uso: editor/worldsplayer_source_editor-main/run_gamma.sh [DIR_TRABAJO]
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
JAVA="$REPO/tools/jdk/Contents/Home/bin/java"
[ -x "$JAVA" ] || JAVA=java
CWD="${1:-${TMPDIR:-/tmp}/freeworlds-gamma}"
mkdir -p "$CWD"
cp -R "$REPO/assets/WorldsPlayer/." "$CWD/"
cd "$CWD"
exec "$JAVA" -cp ".:$REPO/editor/.build-gamma/out" NET.worlds.console.Gamma

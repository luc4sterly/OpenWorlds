#!/bin/bash
# Arranca el cliente ORIGINAL decompilado (NET.worlds.console.Gamma) con el
# puente portable de bridge/, desde una copia de la instalacion 2004
# (assets/WorldsPlayer) para no escribir en el repo. Requiere haber
# ejecutado build_gamma.sh (ver bridge/README.md).
#
# Uso: editor/worldsplayer_source_editor-main/run_gamma.sh [URL_DE_MUNDO]
#   sin URL arranca como el original (home:NewWorld.world hasta el login);
#   p. ej. home:GroundZero/groundzero.world entra directo en GroundZero
#   (argumento de linea de comandos del propio Gamma.main).
# Directorio de trabajo: $FREEWORLDS_GAMMA_DIR o $TMPDIR/freeworlds-gamma.
# Diagnostico: JAVA_OPTS="-Dfreeworlds.dumpFrames=DIR [-Dfreeworlds.dumpSeconds=10,20]
#   [-Dfreeworlds.scriptKeys=MS:KEYCODE:HOLD_MS,...]" (ver bridge/README.md).
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
JAVA="$REPO/tools/jdk/Contents/Home/bin/java"
[ -x "$JAVA" ] || JAVA=java
CWD="${FREEWORLDS_GAMMA_DIR:-${TMPDIR:-/tmp}/freeworlds-gamma}"
mkdir -p "$CWD"
cp -R "$REPO/assets/WorldsPlayer/." "$CWD/"
cd "$CWD"
exec "$JAVA" ${JAVA_OPTS:-} -cp ".:$REPO/editor/.build-gamma/out" NET.worlds.console.Gamma "$@"

#!/bin/bash
# SessionStart de Claude Code en la web: deja la maquina lista para compilar,
# probar y empaquetar OpenWorlds (lo mismo que se hizo a mano en la sesion
# del 2026-09-26). Idempotente: si algo ya esta, no lo repite. Solo corre en
# la nube; en un Mac/Linux propio usa tools/setup-macos.sh o
# tools/setup-linux.sh.
set -euo pipefail

if [ "${CLAUDE_CODE_REMOTE:-}" != "true" ]; then
   exit 0
fi

cd "${CLAUDE_PROJECT_DIR:-$(cd "$(dirname "$0")/../.." && pwd)}"
exec bash tools/setup-linux.sh --quiet

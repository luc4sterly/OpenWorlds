#!/bin/bash
# SessionStart hook for Claude Code on the web: gets the machine ready to
# build, test and package OpenWorlds (what was done by hand in the
# 2026-09-26 session). Idempotent: whatever is already in place is not
# redone. Only runs in the cloud; on your own Mac/Linux use
# tools/setup-macos.sh or tools/setup-linux.sh.
set -euo pipefail

if [ "${CLAUDE_CODE_REMOTE:-}" != "true" ]; then
   exit 0
fi

cd "${CLAUDE_PROJECT_DIR:-$(cd "$(dirname "$0")/../.." && pwd)}"
exec bash tools/setup-linux.sh --quiet

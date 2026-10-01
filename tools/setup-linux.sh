#!/usr/bin/env bash
# setup-linux.sh — gets a Linux machine (or the Claude Code on the web
# container, via .claude/hooks/session-start.sh) ready to develop
# OpenWorlds. Idempotent, can be run as many times as needed:
#
#   1. System packages (apt, if permitted): xvfb (original client and AWT
#      checks without a display), patch (build_gamma.sh), zip (portable
#      package), fonts-liberation (Arial metrics, the 2004 client's fonts:
#      NativeUiFonts) and, for screenshots in tests, xdotool, imagemagick
#      and x11-apps.
#   2. JDK 17 or newer: the system one; if there is none, a portable
#      Temurin 21 in tools/jdk (checked by SHA-256, like setup-macos.sh).
#   3. Builds the formats/ readers and the bridge (editor/.build-gamma), so
#      that tools/run-checks.sh and tools/verify-corpus.sh start warm.
#
# Usage: tools/setup-linux.sh [--quiet] [--no-build]
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
cd "$ROOT"
QUIET=0
BUILD=1
for a in "$@"; do
   case "$a" in
      --quiet) QUIET=1;;
      --no-build) BUILD=0;;
      *) echo "[setup] unknown argument: $a"; exit 2;;
   esac
done
say() { echo "[setup] $*"; }
run() { if [ "$QUIET" = 1 ]; then "$@" >/dev/null 2>&1; else "$@"; fi; }

# --- 1. system packages ---
PKGS="xvfb patch zip unzip fonts-liberation xdotool imagemagick x11-apps"
if command -v dpkg >/dev/null 2>&1 && command -v apt-get >/dev/null 2>&1; then
   NEED=""
   for p in $PKGS; do
      dpkg -s "$p" >/dev/null 2>&1 || NEED="$NEED $p"
   done
   if [ -n "$NEED" ]; then
      SUDO=""
      if [ "$(id -u)" -ne 0 ]; then
         if command -v sudo >/dev/null 2>&1 && sudo -n true 2>/dev/null; then SUDO="sudo -n"; else SUDO="none"; fi
      fi
      if [ "$SUDO" = "none" ]; then
         say "WARNING: missing packages and no permission to install them:$NEED"
      else
         say "installing:$NEED"
         run $SUDO apt-get update -q || true
         DEBIAN_FRONTEND=noninteractive run $SUDO apt-get install -y -q $NEED \
            || say "WARNING: apt-get could not install:$NEED"
      fi
   fi
else
   say "no apt: install the equivalents of these by hand: $PKGS"
fi

# --- 2. JDK 17+ ---
jdk_ok() { # jdk_ok <dir with bin/javac>
   [ -x "$1/bin/javac" ] || return 1
   local v
   v="$("$1/bin/java" -XshowSettings:properties -version 2>&1 | sed -n 's/^ *java.specification.version = //p')"
   [ -n "$v" ] && [ "${v%%.*}" -ge 17 ]
}
JDK=""
if [ -n "${JAVA_HOME:-}" ] && jdk_ok "$JAVA_HOME"; then
   JDK="$JAVA_HOME"
elif jdk_ok "$ROOT/tools/jdk"; then
   JDK="$ROOT/tools/jdk"
elif command -v javac >/dev/null 2>&1 && jdk_ok "$(cd "$(dirname "$(readlink -f "$(command -v javac)")")/.." && pwd)"; then
   JDK="$(cd "$(dirname "$(readlink -f "$(command -v javac)")")/.." && pwd)"
else
   case "$(uname -m)" in
      x86_64) ARCH=x64;;
      aarch64|arm64) ARCH=aarch64;;
      *) say "no portable JDK for this architecture: $(uname -m)"; exit 2;;
   esac
   say "downloading a portable JDK 21 (Temurin) into tools/jdk..."
   META="$(curl -fsSL "https://api.adoptium.net/v3/assets/latest/21/hotspot?architecture=$ARCH&image_type=jdk&os=linux&vendor=eclipse" \
      | python3 -c 'import json,sys; p=json.load(sys.stdin)[0]["binary"]["package"]; print(p["link"], p["checksum"], p["name"])')"
   read -r URL SUM NAME <<<"$META"
   TMP="$(mktemp -d)"
   curl -fsSL -o "$TMP/$NAME" "$URL"
   echo "$SUM  $TMP/$NAME" | sha256sum -c - >/dev/null || { say "JDK SHA-256 does not match"; exit 3; }
   mkdir -p "$TMP/x"
   tar -xzf "$TMP/$NAME" -C "$TMP/x"
   rm -rf "$ROOT/tools/jdk"
   mv "$TMP/x"/* "$ROOT/tools/jdk"
   rm -rf "$TMP"
   JDK="$ROOT/tools/jdk"
fi
export JAVA_HOME="$JDK"
export PATH="$JDK/bin:$PATH"
say "JDK: $("$JDK/bin/java" -version 2>&1 | grep -v JAVA_TOOL | head -n 1)"

# --- 3. build ---
if [ "$BUILD" = 1 ]; then
   mkdir -p "$ROOT/formats/out"
   find "$ROOT/formats/src" -name '*.java' > "$ROOT/formats/out/.sources"
   "$JDK/bin/javac" -nowarn -encoding UTF-8 -d "$ROOT/formats/out" @"$ROOT/formats/out/.sources" 2>&1 \
      | grep -v '^Picked up JAVA_TOOL_OPTIONS' || true
   rm -f "$ROOT/formats/out/.sources"
   [ -f "$ROOT/formats/out/net/openworlds/cmp/CmpFrames.class" ] || { say "ERROR: formats/ does not compile"; exit 3; }
   run bash "$ROOT/editor/worldsplayer_source_editor-main/build_gamma.sh" || { say "ERROR: the bridge does not compile (editor/.build-gamma/javac.log)"; exit 3; }
   say "formats/out and editor/.build-gamma/out built"
fi
say "ready: tools/run-checks.sh, tools/verify-corpus.sh, tools/build-dist.sh"

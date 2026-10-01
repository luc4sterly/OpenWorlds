# Shared functions (bash 3.2) for run-guest-login.sh and run-gamma-mock.sh.
# Included with `. lib-build.sh`; expects HERE = the tools/net-probe folder.
#
# Builds the mocked client (through build_gamma.sh) and the probes into
# $WORK, and runs the client in a copy of the install there: the client
# writes logs/caches into its CWD, so nothing in the repo (pristine source/,
# assets/WorldsPlayer) is ever touched.
#
# Environment variables:
#   FW_NET_WORK  working directory (default: mktemp -d). If it already holds a
#                complete build, it is reused (delete it to rebuild).
#   JDK_BIN      folder with java/javac/jstack (default: the repo's tools/jdk
#                or, inside a git worktree, the main checkout's: it is
#                gitignored).

REPO="$(cd "$HERE/../.." && pwd)"
EDITOR_REL=editor/worldsplayer_source_editor-main

find_jdk() {
  local cand common main
  if [ -z "${JDK_BIN:-}" ]; then
    for cand in "$REPO/tools/jdk/Contents/Home/bin" "$REPO/tools/jdk/bin"; do
      if [ -x "$cand/javac" ]; then JDK_BIN="$cand"; break; fi
    done
  fi
  if [ -z "${JDK_BIN:-}" ] && command -v git >/dev/null 2>&1; then
    common="$(cd "$REPO" && git rev-parse --path-format=absolute --git-common-dir 2>/dev/null || true)"
    if [ -n "$common" ]; then
      main="$(dirname "$common")"
      for cand in "$main/tools/jdk/Contents/Home/bin" "$main/tools/jdk/bin"; do
        if [ -x "$cand/javac" ]; then JDK_BIN="$cand"; break; fi
      done
    fi
  fi
  if [ -z "${JDK_BIN:-}" ]; then
    # Last resort: PATH (on macOS /usr/bin/java is a stub; it is checked).
    if javac -version >/dev/null 2>&1; then JDK_BIN="$(dirname "$(command -v javac)")"; fi
  fi
  if [ -z "${JDK_BIN:-}" ]; then
    echo "ERROR: cannot find a JDK (tools/jdk or JDK_BIN=...)" >&2
    exit 2
  fi
  JAVA="$JDK_BIN/java"
  JAVAC="$JDK_BIN/javac"
  JSTACK="$JDK_BIN/jstack"
  echo "JDK: $("$JAVA" -version 2>&1 | head -1)"
}

init_work() {
  WORK="${FW_NET_WORK:-}"
  if [ -z "$WORK" ]; then
    WORK="$(mktemp -d "${TMPDIR:-/tmp}/fw-net.XXXXXX")"
  fi
  mkdir -p "$WORK"
  WORK="$(cd "$WORK" && pwd)"
  echo "WORK: $WORK"
}

build_mock() {
  if [ -f "$WORK/out/NET/worlds/console/Gamma.class" ] \
     && [ -f "$WORK/probeout/NET/worlds/network/GuestLoginProbe.class" ]; then
    echo "build: reusing $WORK/out and $WORK/probeout"
    return 0
  fi
  rm -rf "$WORK/out" "$WORK/probeout"
  # The client as the bridge builds it: build_gamma.sh copies the pristine
  # source/, applies the mock and the bridge (apply_mock.sh) and compiles it
  # with the formats/ readers into the gitignored editor/.build-gamma, never
  # in source/. The classes are copied so a later rebuild leaves this one alone.
  echo "build: build_gamma.sh (log: $WORK/build_gamma.log)"
  bash "$REPO/$EDITOR_REL/build_gamma.sh" >"$WORK/build_gamma.log" 2>&1
  cp -R "$REPO/editor/.build-gamma/out" "$WORK/out"
  echo "build: $(find "$WORK/out" -name '*.class' | wc -l | tr -d ' ') classes"

  echo "build: probes (log: $WORK/compile_probes.log)"
  mkdir -p "$WORK/probeout"
  "$JAVAC" --release 8 -encoding UTF-8 -nowarn -cp "$WORK/out" -d "$WORK/probeout" \
     "$HERE"/NET/worlds/network/*.java "$HERE/NetProbe.java" >"$WORK/compile_probes.log" 2>&1
}

# copy_install <dest>: fresh copy of assets/WorldsPlayer (the client's CWD).
copy_install() {
  rm -rf "$1"
  mkdir -p "$(dirname "$1")"
  cp -R "$REPO/assets/WorldsPlayer" "$1"
}

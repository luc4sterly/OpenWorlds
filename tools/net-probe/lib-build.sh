# Funciones comunes (bash 3.2) para run-guest-login.sh y run-gamma-mock.sh.
# Se incluye con `. lib-build.sh`; espera HERE = carpeta tools/net-probe.
#
# Construye el cliente mockeado + sondas en $WORK, FUERA del repo: apply_mock.sh
# reescribe source/ EN EL SITIO y el cliente escribe logs/caches en su CWD, asi
# que nada del repo (source/ pristino, assets/WorldsPlayer) se toca nunca.
#
# Variables de entorno:
#   FW_NET_WORK  directorio de trabajo (defecto: mktemp -d). Si ya contiene un
#                build completo se reutiliza (borralo para reconstruir).
#   JDK_BIN      carpeta con java/javac/jstack (defecto: tools/jdk del repo o,
#                dentro de un git worktree, del checkout principal: es gitignored).

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
    # Ultimo recurso: PATH (en macOS /usr/bin/java es un stub; se comprueba).
    if javac -version >/dev/null 2>&1; then JDK_BIN="$(dirname "$(command -v javac)")"; fi
  fi
  if [ -z "${JDK_BIN:-}" ]; then
    echo "ERROR: no encuentro un JDK (tools/jdk o JDK_BIN=...)" >&2
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
    echo "build: reutilizando $WORK/out y $WORK/probeout"
    return 0
  fi
  rm -rf "$WORK/copy" "$WORK/out" "$WORK/probeout"
  # apply_mock.sh usa ROOT=../.. -> replicar editor/, tools/, docs/.
  mkdir -p "$WORK/copy/$EDITOR_REL" "$WORK/copy/tools" "$WORK/copy/docs"
  cp -R "$REPO/$EDITOR_REL/source" "$WORK/copy/$EDITOR_REL/source"
  cp "$REPO/$EDITOR_REL/apply_mock.sh" "$WORK/copy/$EDITOR_REL/"
  cp "$REPO/tools/jni_mock.py" "$WORK/copy/tools/"
  cp "$REPO/docs/native-methods-callers.md" "$WORK/copy/docs/"
  echo "build: apply_mock.sh (log: $WORK/apply_mock.log)"
  bash "$WORK/copy/$EDITOR_REL/apply_mock.sh" >"$WORK/apply_mock.log" 2>&1

  echo "build: javac --release 8 cliente mockeado (log: $WORK/compile_mock.log)"
  (cd "$WORK/copy/$EDITOR_REL" && find source -name '*.java' >"$WORK/sources.txt")
  mkdir -p "$WORK/out"
  (cd "$WORK/copy/$EDITOR_REL" && "$JAVAC" --release 8 -encoding UTF-8 -nowarn \
     -d "$WORK/out" @"$WORK/sources.txt") >"$WORK/compile_mock.log" 2>&1
  echo "build: $(find "$WORK/out" -name '*.class' | wc -l | tr -d ' ') clases"

  echo "build: sondas (log: $WORK/compile_probes.log)"
  mkdir -p "$WORK/probeout"
  "$JAVAC" --release 8 -encoding UTF-8 -nowarn -cp "$WORK/out" -d "$WORK/probeout" \
     "$HERE"/NET/worlds/network/*.java "$HERE/NetProbe.java" >"$WORK/compile_probes.log" 2>&1
}

# copy_install <destino>: copia fresca de assets/WorldsPlayer (CWD del cliente).
copy_install() {
  rm -rf "$1"
  mkdir -p "$(dirname "$1")"
  cp -R "$REPO/assets/WorldsPlayer" "$1"
}

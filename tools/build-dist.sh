#!/usr/bin/env bash
# build-dist.sh — compila y empaqueta FreeWorlds para jugar sin scripts de
# arranque ni checkout: un lanzador con menu (net.freeworlds.launcher) que
# arranca el cliente original de 2004 (con el puente portable), con los datos
# del juego dentro.
#
# Uso:
#   tools/build-dist.sh                 build/dist/FreeWorlds + build/FreeWorlds-<ver>-portable.zip
#                                       (necesita Java 17+ instalado para jugar)
#   tools/build-dist.sh --app-image     ademas, la app nativa de ESTE sistema con su
#                                       propio Java (jlink + jpackage): .app en macOS,
#                                       carpeta con FreeWorlds(.exe) en Linux/Windows,
#                                       comprimida en build/FreeWorlds-<ver>-<so>-<arq>.*
#   tools/build-dist.sh --package-only  solo el paso de jpackage, sobre un build/dist
#                                       ya hecho (lo usa la CI en macOS y Windows)
#   --no-zip                            sin el .zip portable
#
# Variables: FREEWORLDS_VERSION (por defecto <launcher/VERSION>.<commits>, p. ej.
# 1.0.150: es la que compara el actualizador automatico con las releases),
# FREEWORLDS_COMMIT, FREEWORLDS_UPDATE_REPO (owner/nombre de las releases; por
# defecto $GITHUB_REPOSITORY o luc4sterly/OpenWorlds), JAVA_HOME.
# Salida de ejemplo en la CI: .github/workflows/build.yml.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd -P)"
cd "$ROOT"
APP_IMAGE=0
BUILD=1
ZIP=1
for a in "$@"; do
   case "$a" in
      --app-image) APP_IMAGE=1;;
      --package-only) APP_IMAGE=1; BUILD=0; ZIP=0;;
      --no-zip) ZIP=0;;
      -h|--help) sed -n '2,22p' "$0"; exit 0;;
      *) echo "[dist] argumento desconocido: $a"; exit 2;;
   esac
done

# --- JDK: JAVA_HOME, el portable de tools/ o el del PATH ---
if [ -n "${JAVA_HOME:-}" ] && [ -x "$JAVA_HOME/bin/javac" ]; then
   JDK="$JAVA_HOME"
elif [ -x "$ROOT/tools/jdk/Contents/Home/bin/javac" ]; then
   JDK="$ROOT/tools/jdk/Contents/Home"
elif [ -x "$ROOT/tools/jdk/bin/javac" ]; then
   JDK="$ROOT/tools/jdk"
else
   JDK="$(cd "$(dirname "$(command -v javac)")/.." && pwd -P)"
fi
export JAVA_HOME="$JDK"
export PATH="$JDK/bin:$PATH"
unset JAVA_TOOL_OPTIONS || true
JV="$("$JDK/bin/java" -XshowSettings:properties -version 2>&1 | sed -n 's/^ *java.specification.version = //p')"
echo "[dist] JDK $JV en $JDK"
if [ "${JV%%.*}" -lt 17 ]; then
   echo "[dist] hace falta JDK 17 o mas nuevo"; exit 2
fi

# Version <base>.<commits>: la base (1.0) en launcher/VERSION, el numero de
# commits de la historia (la CI la trae entera). Crece con cada commit de main,
# asi que el actualizador puede comparar versiones; jpackage solo acepta
# numeros y en macOS el primero tiene que ser >= 1.
BASE="$(tr -d ' \r\n' < "$ROOT/launcher/VERSION" 2>/dev/null || echo 1.0)"
NUMVER="${FREEWORLDS_NUMERIC_VERSION:-$BASE.$(git -C "$ROOT" rev-list --count HEAD 2>/dev/null || echo 0)}"
VERSION="${FREEWORLDS_VERSION:-$NUMVER}"
COMMIT="${FREEWORLDS_COMMIT:-$(git -C "$ROOT" rev-parse --short HEAD 2>/dev/null || echo desconocido)}"
if [ -z "${FREEWORLDS_COMMIT:-}" ] && ! git -C "$ROOT" diff --quiet HEAD 2>/dev/null; then
   COMMIT="$COMMIT-dirty"
fi
UPDATE_REPO="${FREEWORLDS_UPDATE_REPO:-${GITHUB_REPOSITORY:-luc4sterly/OpenWorlds}}"
echo "[dist] version $VERSION ($COMMIT), releases de $UPDATE_REPO"
OUT="$ROOT/build"
DIST="$OUT/dist/FreeWorlds"
LIB="$DIST/lib"

if [ "$BUILD" = 1 ]; then
   rm -rf "$OUT/dist" "$OUT/classes"
   mkdir -p "$LIB" "$OUT/classes/launcher"

   echo "[dist] cliente original + puente (build_gamma.sh)"
   bash "$ROOT/editor/worldsplayer_source_editor-main/build_gamma.sh"
   printf 'Main-Class: NET.worlds.console.Gamma\nImplementation-Title: WorldsPlayer (FreeWorlds bridge)\nImplementation-Version: %s\n' "$VERSION" > "$OUT/manifest-gamma.txt"
   "$JDK/bin/jar" cfm "$LIB/worldsplayer.jar" "$OUT/manifest-gamma.txt" -C "$ROOT/editor/.build-gamma/out" .

   echo "[dist] lanzador"
   find "$ROOT/launcher/src" -name '*.java' > "$OUT/launcher-sources.txt"
   "$JDK/bin/javac" --release 17 -nowarn -encoding UTF-8 -d "$OUT/classes/launcher" @"$OUT/launcher-sources.txt"
   cp -R "$ROOT/launcher/resources/." "$OUT/classes/launcher/"
   printf 'Main-Class: net.freeworlds.launcher.Launcher\nImplementation-Title: FreeWorlds\nImplementation-Version: %s\nFreeWorlds-Commit: %s\nFreeWorlds-Update-Repo: %s\n' \
      "$VERSION" "$COMMIT" "$UPDATE_REPO" > "$OUT/manifest-launcher.txt"
   "$JDK/bin/jar" cfm "$LIB/freeworlds-launcher.jar" "$OUT/manifest-launcher.txt" -C "$OUT/classes/launcher" .

   echo "[dist] datos del juego"
   GAME="$DIST/game/assets"
   mkdir -p "$GAME/gammatutorial-samples"
   # la instalacion de 2004 sin su JRE ni sus DLL (bin/, lib/) ni CVS/: con el
   # puente no se usan (ver launcher/.../Install.java)
   (cd "$ROOT/assets" && tar cf - --exclude=CVS --exclude=WorldsPlayer/bin --exclude=WorldsPlayer/lib WorldsPlayer) | (cd "$GAME" && tar xf -)
   cp -R "$ROOT/assets/gammatutorial-samples/base-avatars" "$GAME/gammatutorial-samples/"
   if [ ! -f "$GAME/WorldsPlayer/cachedir/cache.index" ]; then
      echo "[dist] AVISO: sin assets/WorldsPlayer/cachedir/cache.index: los avatares cacheados de 2004 no tendran textura"
   fi

   echo "[dist] lanzadores y README"
   cat > "$DIST/FreeWorlds.sh" <<'EOF'
#!/bin/sh
# FreeWorlds (Linux): necesita Java 17+ (o usa el paquete con Java incluido)
DIR="$(cd "$(dirname "$0")" && pwd -P)"
JAVA="${JAVA_HOME:+$JAVA_HOME/bin/}java"
exec "$JAVA" -jar "$DIR/lib/freeworlds-launcher.jar" "$@"
EOF
   cat > "$DIST/FreeWorlds.command" <<'EOF'
#!/bin/sh
# FreeWorlds (macOS, doble clic): necesita Java 17+ (o usa FreeWorlds.app)
DIR="$(cd "$(dirname "$0")" && pwd -P)"
JAVA="${JAVA_HOME:+$JAVA_HOME/bin/}java"
[ -x /usr/libexec/java_home ] && [ -z "${JAVA_HOME:-}" ] && JH="$(/usr/libexec/java_home -v 17+ 2>/dev/null)" && JAVA="$JH/bin/java"
exec "$JAVA" -Xdock:name=FreeWorlds -jar "$DIR/lib/freeworlds-launcher.jar" "$@"
EOF
   printf '@echo off\r\nrem FreeWorlds (Windows): necesita Java 17+ (o usa el paquete con Java incluido)\r\nstart "" javaw -jar "%%~dp0lib\\freeworlds-launcher.jar" %%*\r\n' > "$DIST/FreeWorlds.bat"
   chmod +x "$DIST/FreeWorlds.sh" "$DIST/FreeWorlds.command"
   cp "$ROOT/tools/dist-README.txt" "$DIST/README.txt"
   echo "$VERSION" > "$DIST/VERSION"

   if [ "$ZIP" = 1 ]; then
      rm -f "$OUT/FreeWorlds-$VERSION-portable.zip"
      if command -v zip >/dev/null 2>&1; then
         (cd "$OUT/dist" && zip -qr -X "$OUT/FreeWorlds-$VERSION-portable.zip" FreeWorlds)
      else
         (cd "$OUT/dist" && "$JDK/bin/jar" cfM "$OUT/FreeWorlds-$VERSION-portable.zip" FreeWorlds)
      fi
      echo "[dist] $OUT/FreeWorlds-$VERSION-portable.zip"
   fi
fi

if [ "$APP_IMAGE" = 1 ]; then
   [ -f "$LIB/freeworlds-launcher.jar" ] || { echo "[dist] falta $LIB: construye antes sin --package-only"; exit 2; }
   case "$(uname -s)" in
      Darwin) OS=macos;;
      MINGW*|MSYS*|CYGWIN*) OS=windows;;
      *) OS=linux;;
   esac
   case "$(uname -m)" in
      x86_64|amd64) ARCH=x64;;
      arm64|aarch64) ARCH=arm64;;
      *) ARCH="$(uname -m)";;
   esac
   echo "[dist] app nativa $OS-$ARCH"
   STAGE="$OUT/jpackage-input"
   rm -rf "$STAGE" "$OUT/runtime" "$OUT/app"
   mkdir -p "$STAGE"
   cp "$LIB"/*.jar "$STAGE/"
   cp -R "$DIST/game" "$STAGE/game"

   # Java propio: jlink SIN --strip-native-commands (el lanzador arranca
   # cada juego con bin/java de este mismo runtime)
   MODS="java.base,java.desktop,java.management,java.logging,jdk.unsupported,jdk.httpserver,jdk.charsets,jdk.crypto.ec"
   if [ "${JV%%.*}" -ge 21 ]; then COMPRESS="--compress=zip-6"; else COMPRESS="--compress=2"; fi
   "$JDK/bin/jlink" --add-modules "$MODS" --strip-debug --no-man-pages --no-header-files $COMPRESS --output "$OUT/runtime"

   ICON_ARGS=()
   if [ "$OS" = macos ] && [ -f "$ROOT/tools/icons/freeworlds.icns" ]; then
      ICON_ARGS=(--icon "$ROOT/tools/icons/freeworlds.icns")
   elif [ "$OS" = windows ] && [ -f "$ROOT/tools/icons/freeworlds.ico" ]; then
      ICON_ARGS=(--icon "$ROOT/tools/icons/freeworlds.ico")
   elif [ "$OS" = linux ] && [ -f "$ROOT/tools/icons/freeworlds.png" ]; then
      ICON_ARGS=(--icon "$ROOT/tools/icons/freeworlds.png")
   fi
   EXTRA=()
   [ "$OS" = macos ] && EXTRA=(--mac-package-identifier net.freeworlds.launcher --mac-package-name FreeWorlds)
   "$JDK/bin/jpackage" --type app-image --name FreeWorlds --app-version "$NUMVER" \
      --vendor "FreeWorlds" --description "Worlds Chat / WorldsPlayer preservado" \
      --input "$STAGE" --main-jar freeworlds-launcher.jar --main-class net.freeworlds.launcher.Launcher \
      --runtime-image "$OUT/runtime" --java-options "-Xmx256m" \
      ${ICON_ARGS[@]+"${ICON_ARGS[@]}"} ${EXTRA[@]+"${EXTRA[@]}"} --dest "$OUT/app"

   NAME="FreeWorlds-$VERSION-$OS-$ARCH"
   case "$OS" in
      macos)
         # firma ad hoc (Apple Silicon no ejecuta codigo sin firmar) y zip con permisos
         codesign --force --deep --sign - "$OUT/app/FreeWorlds.app" || echo "[dist] AVISO: codesign ad hoc fallo"
         rm -f "$OUT/$NAME.zip"
         ditto -c -k --sequesterRsrc --keepParent "$OUT/app/FreeWorlds.app" "$OUT/$NAME.zip"
         echo "[dist] $OUT/$NAME.zip";;
      windows)
         rm -f "$OUT/$NAME.zip"
         powershell -NoProfile -Command "Compress-Archive -Path '$(cygpath -w "$OUT/app/FreeWorlds")' -DestinationPath '$(cygpath -w "$OUT/$NAME.zip")'"
         echo "[dist] $OUT/$NAME.zip";;
      *)
         tar czf "$OUT/$NAME.tar.gz" -C "$OUT/app" FreeWorlds
         echo "[dist] $OUT/$NAME.tar.gz";;
   esac
fi

#!/usr/bin/env bash
# build-dist.sh - builds and packages OpenWorlds so it can be played without
# scripts or a checkout: the game's launcher (net.openworlds.launcher), which
# starts the 2004 client on the portable bridge with the game's data inside,
# and J Solar Server (net.openworlds.solar), the world server with its admin
# window. Both share the ui/ module; the launcher also carries the J Worlds
# Injector (injector/: its engine and built-in patches) and the client's
# source as the bridge builds it (lib/worldsplayer-src.zip), which the
# injector patches and compiles when the game starts.
#
# Usage:
#   tools/build-dist.sh                 build/dist/OpenWorlds and build/dist/JSolarServer, and
#                                       build/OpenWorlds-<ver>-portable.zip and JSolarServer-<ver>-portable.zip
#                                       (these need Java 17+ installed)
#   tools/build-dist.sh --app-image     also THIS system's native apps with their own Java
#                                       (jlink + jpackage): .app on macOS, a folder with the
#                                       program on Linux/Windows, packed as
#                                       build/OpenWorlds-<ver>-<os>-<arch>.* and JSolarServer-<ver>-<os>-<arch>.*
#   tools/build-dist.sh --package-only  only the jpackage step, on a build/dist made before
#                                       (the CI uses it on macOS and Windows)
#   --no-zip                            without the portable .zip files
#
# Variables: OPENWORLDS_VERSION (default <launcher/VERSION>.<commits>, e.g.
# 1.0.150: the automatic updater compares it with the releases'),
# OPENWORLDS_COMMIT, OPENWORLDS_UPDATE_REPO (owner/name of the releases;
# default $GITHUB_REPOSITORY or luc4sterly/OpenWorlds), JAVA_HOME.
# Example run: .github/workflows/build.yml.
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
      -h|--help) sed -n '2,25p' "$0"; exit 0;;
      *) echo "[dist] unknown argument: $a"; exit 2;;
   esac
done

# --- JDK: JAVA_HOME, the portable one in tools/ or the one on the PATH ---
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
echo "[dist] JDK $JV in $JDK"
if [ "${JV%%.*}" -lt 17 ]; then
   echo "[dist] JDK 17 or newer needed"; exit 2
fi

# Version <base>.<commits>: the base (1.0) in launcher/VERSION, the number of
# commits in the history (the CI checks it out whole). It grows with each
# commit on main, so the updater can compare versions; jpackage only takes
# numbers and on macOS the first one must be >= 1.
BASE="$(tr -d ' \r\n' < "$ROOT/launcher/VERSION" 2>/dev/null || echo 1.0)"
NUMVER="${OPENWORLDS_NUMERIC_VERSION:-$BASE.$(git -C "$ROOT" rev-list --count HEAD 2>/dev/null || echo 0)}"
VERSION="${OPENWORLDS_VERSION:-$NUMVER}"
COMMIT="${OPENWORLDS_COMMIT:-$(git -C "$ROOT" rev-parse --short HEAD 2>/dev/null || echo unknown)}"
if [ -z "${OPENWORLDS_COMMIT:-}" ] && ! git -C "$ROOT" diff --quiet HEAD 2>/dev/null; then
   COMMIT="$COMMIT-dirty"
fi
UPDATE_REPO="${OPENWORLDS_UPDATE_REPO:-${GITHUB_REPOSITORY:-luc4sterly/OpenWorlds}}"
echo "[dist] version $VERSION ($COMMIT), releases from $UPDATE_REPO"
OUT="$ROOT/build"
DIST="$OUT/dist/OpenWorlds"
LIB="$DIST/lib"
SDIST="$OUT/dist/JSolarServer"
SLIB="$SDIST/lib"

# javac_module <out dir> <src dirs...>: compiles and copies resources/ next to each src/
javac_module() {
   local out="$1"
   shift
   mkdir -p "$out"
   : > "$out.sources"
   for d in "$@"; do
      find "$ROOT/$d/src" -name '*.java' >> "$out.sources"
   done
   "$JDK/bin/javac" --release 17 -nowarn -encoding UTF-8 -d "$out" @"$out.sources"
   for d in "$@"; do
      if [ -d "$ROOT/$d/resources" ]; then
         cp -R "$ROOT/$d/resources/." "$out/"
      fi
   done
   rm -f "$out.sources"
}

if [ "$BUILD" = 1 ]; then
   rm -rf "$OUT/dist" "$OUT/classes"
   mkdir -p "$LIB" "$SLIB"

   echo "[dist] original client + bridge (build_gamma.sh)"
   bash "$ROOT/editor/worldsplayer_source_editor-main/build_gamma.sh"
   printf 'Main-Class: NET.worlds.console.Gamma\nImplementation-Title: WorldsPlayer (OpenWorlds bridge)\nImplementation-Version: %s\n' "$VERSION" > "$OUT/manifest-gamma.txt"
   "$JDK/bin/jar" cfm "$LIB/worldsplayer.jar" "$OUT/manifest-gamma.txt" -C "$ROOT/editor/.build-gamma/out" .

   echo "[dist] launcher, with the ui module and the J Worlds Injector"
   javac_module "$OUT/classes/launcher" ui injector launcher
   # the injector's built-in patches next to its classes, listed in index.txt
   # ("<patch>/<file>" lines: Patch.builtIn reads them as resources)
   PATCHES="$OUT/classes/launcher/net/openworlds/injector/patches"
   mkdir -p "$PATCHES"
   cp -R "$ROOT/injector/patches/." "$PATCHES/"
   (cd "$ROOT/injector/patches" && find . -mindepth 2 -maxdepth 2 -type f | sed 's|^\./||' | LC_ALL=C sort) > "$PATCHES/index.txt"
   # the client's source as the bridge builds it (the pristine decompiled
   # source with the bridge's patches): what the injector's diffs apply to
   rm -f "$LIB/worldsplayer-src.zip"
   (cd "$ROOT/editor/.build-gamma/source" && "$JDK/bin/jar" cfM "$LIB/worldsplayer-src.zip" .)
   printf 'Main-Class: net.openworlds.launcher.Launcher\nImplementation-Title: OpenWorlds\nImplementation-Version: %s\nOpenWorlds-Commit: %s\nOpenWorlds-Update-Repo: %s\n' \
      "$VERSION" "$COMMIT" "$UPDATE_REPO" > "$OUT/manifest-launcher.txt"
   "$JDK/bin/jar" cfm "$LIB/openworlds-launcher.jar" "$OUT/manifest-launcher.txt" -C "$OUT/classes/launcher" .

   echo "[dist] J Solar Server"
   javac_module "$OUT/classes/server" ui server
   printf 'Main-Class: net.openworlds.solar.Main\nImplementation-Title: J Solar Server\nImplementation-Version: %s\nOpenWorlds-Commit: %s\n' \
      "$VERSION" "$COMMIT" > "$OUT/manifest-server.txt"
   "$JDK/bin/jar" cfm "$SLIB/j-solar-server.jar" "$OUT/manifest-server.txt" -C "$OUT/classes/server" .

   echo "[dist] game data"
   GAME="$DIST/game/assets"
   mkdir -p "$GAME/gammatutorial-samples"
   # the 2004 install without its JRE and DLLs (bin/, lib/) nor CVS/: the
   # bridge does not use them (see launcher/.../Install.java)
   (cd "$ROOT/assets" && tar cf - --exclude=CVS --exclude=WorldsPlayer/bin --exclude=WorldsPlayer/lib WorldsPlayer) | (cd "$GAME" && tar xf -)
   cp -R "$ROOT/assets/gammatutorial-samples/base-avatars" "$GAME/gammatutorial-samples/"
   if [ ! -f "$GAME/WorldsPlayer/cachedir/cache.index" ]; then
      echo "[dist] WARNING: no assets/WorldsPlayer/cachedir/cache.index: the cached 2004 avatars will have no textures"
   fi

   echo "[dist] start scripts and READMEs"
   # launcher_scripts <dir> <name> <jar> <what it is>
   launcher_scripts() {
      local dir="$1" name="$2" jar="$3" what="$4"
      cat > "$dir/$name.sh" <<EOF
#!/bin/sh
# $what (Linux): needs Java 17+ (or use the package with Java included)
DIR="\$(cd "\$(dirname "\$0")" && pwd -P)"
JAVA="\${JAVA_HOME:+\$JAVA_HOME/bin/}java"
exec "\$JAVA" -jar "\$DIR/lib/$jar" "\$@"
EOF
      cat > "$dir/$name.command" <<EOF
#!/bin/sh
# $what (macOS, double click): needs Java 17+ (or use the .app)
DIR="\$(cd "\$(dirname "\$0")" && pwd -P)"
JAVA="\${JAVA_HOME:+\$JAVA_HOME/bin/}java"
[ -x /usr/libexec/java_home ] && [ -z "\${JAVA_HOME:-}" ] && JH="\$(/usr/libexec/java_home -v 17+ 2>/dev/null)" && JAVA="\$JH/bin/java"
exec "\$JAVA" -Xdock:name="$what" -jar "\$DIR/lib/$jar" "\$@"
EOF
      printf '@echo off\r\nrem %s (Windows): needs Java 17+ (or use the package with Java included)\r\nstart "" javaw -jar "%%~dp0lib\\%s" %%*\r\n' "$what" "$jar" > "$dir/$name.bat"
      chmod +x "$dir/$name.sh" "$dir/$name.command"
      echo "$VERSION" > "$dir/VERSION"
   }
   launcher_scripts "$DIST" OpenWorlds openworlds-launcher.jar OpenWorlds
   launcher_scripts "$SDIST" JSolarServer j-solar-server.jar "J Solar Server"
   cp "$ROOT/tools/dist-README.txt" "$DIST/README.txt"
   cp "$ROOT/tools/dist-README-server.txt" "$SDIST/README.txt"

   if [ "$ZIP" = 1 ]; then
      for p in OpenWorlds JSolarServer; do
         rm -f "$OUT/$p-$VERSION-portable.zip"
         if command -v zip >/dev/null 2>&1; then
            (cd "$OUT/dist" && zip -qr -X "$OUT/$p-$VERSION-portable.zip" "$p")
         else
            (cd "$OUT/dist" && "$JDK/bin/jar" cfM "$OUT/$p-$VERSION-portable.zip" "$p")
         fi
         echo "[dist] $OUT/$p-$VERSION-portable.zip"
      done
   fi
fi

if [ "$APP_IMAGE" = 1 ]; then
   [ -f "$LIB/openworlds-launcher.jar" ] || { echo "[dist] $LIB is missing: build first without --package-only"; exit 2; }
   [ -f "$SLIB/j-solar-server.jar" ] || { echo "[dist] $SLIB is missing: build first without --package-only"; exit 2; }
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
   if [ "${JV%%.*}" -ge 21 ]; then COMPRESS="--compress=zip-6"; else COMPRESS="--compress=2"; fi
   rm -rf "$OUT/app"

   # app_image <name> <input dir> <main jar> <main class> <jlink modules> <icon base> <mac id> <description> <java options>
   app_image() {
      local name="$1" input="$2" jar="$3" main="$4" mods="$5" icon="$6" macid="$7" desc="$8" jopts="$9"
      local runtime="$OUT/runtime-$name"
      rm -rf "$runtime"
      # the app's own Java: jlink WITHOUT --strip-native-commands (the
      # launcher starts each game with bin/java of this same runtime)
      "$JDK/bin/jlink" --add-modules "$mods" --strip-debug --no-man-pages --no-header-files $COMPRESS --output "$runtime"
      local icon_args=()
      if [ "$OS" = macos ] && [ -f "$ROOT/tools/icons/$icon.icns" ]; then
         icon_args=(--icon "$ROOT/tools/icons/$icon.icns")
      elif [ "$OS" = windows ] && [ -f "$ROOT/tools/icons/$icon.ico" ]; then
         icon_args=(--icon "$ROOT/tools/icons/$icon.ico")
      elif [ "$OS" = linux ] && [ -f "$ROOT/tools/icons/$icon.png" ]; then
         icon_args=(--icon "$ROOT/tools/icons/$icon.png")
      fi
      local extra=()
      [ "$OS" = macos ] && extra=(--mac-package-identifier "$macid" --mac-package-name "$name")
      "$JDK/bin/jpackage" --type app-image --name "$name" --app-version "$NUMVER" \
         --vendor "OpenWorlds" --description "$desc" \
         --input "$input" --main-jar "$jar" --main-class "$main" \
         --runtime-image "$runtime" --java-options "$jopts" \
         ${icon_args[@]+"${icon_args[@]}"} ${extra[@]+"${extra[@]}"} --dest "$OUT/app"
      local pack="$name-$VERSION-$OS-$ARCH"
      case "$OS" in
         macos)
            # ad hoc signature (Apple Silicon runs no unsigned code) and a zip that keeps permissions
            codesign --force --deep --sign - "$OUT/app/$name.app" || echo "[dist] WARNING: ad hoc codesign failed"
            rm -f "$OUT/$pack.zip"
            ditto -c -k --sequesterRsrc --keepParent "$OUT/app/$name.app" "$OUT/$pack.zip"
            echo "[dist] $OUT/$pack.zip";;
         windows)
            rm -f "$OUT/$pack.zip"
            powershell -NoProfile -Command "Compress-Archive -Path '$(cygpath -w "$OUT/app/$name")' -DestinationPath '$(cygpath -w "$OUT/$pack.zip")'"
            echo "[dist] $OUT/$pack.zip";;
         *)
            tar czf "$OUT/$pack.tar.gz" -C "$OUT/app" "$name"
            echo "[dist] $OUT/$pack.tar.gz";;
      esac
   }

   echo "[dist] native apps $OS-$ARCH"
   STAGE="$OUT/jpackage-input"
   rm -rf "$STAGE"
   mkdir -p "$STAGE"
   cp "$LIB"/*.jar "$LIB"/*.zip "$STAGE/"
   cp -R "$DIST/game" "$STAGE/game"
   # jdk.compiler: the J Worlds Injector compiles the chosen client patches when the game starts
   app_image OpenWorlds "$STAGE" openworlds-launcher.jar net.openworlds.launcher.Launcher \
      "java.base,java.desktop,java.management,java.logging,jdk.unsupported,jdk.httpserver,jdk.charsets,jdk.crypto.ec,jdk.compiler,jdk.zipfs" \
      openworlds net.openworlds.launcher "OpenWorlds: the Worlds 3D chat client" "-Xmx256m"

   SSTAGE="$OUT/jpackage-input-server"
   rm -rf "$SSTAGE"
   mkdir -p "$SSTAGE"
   cp "$SLIB"/*.jar "$SSTAGE/"
   app_image JSolarServer "$SSTAGE" j-solar-server.jar net.openworlds.solar.Main \
      "java.base,java.desktop,java.logging,jdk.crypto.ec" \
      solar net.openworlds.solar "J Solar Server: a world server for OpenWorlds" "-Xmx512m"
fi

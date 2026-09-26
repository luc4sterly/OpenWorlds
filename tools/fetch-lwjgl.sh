#!/usr/bin/env bash
# fetch-lwjgl.sh — descarga LWJGL (lwjgl, glfw, opengl) de Maven Central,
# verificando cada jar contra su .sha1, con reintentos (Maven Central
# responde 429 si se le pide deprisa).
#
# Uso: tools/fetch-lwjgl.sh DESTINO [natives...]
#   natives: linux linux-arm64 macos macos-arm64 windows (por defecto las
#   de esta maquina). "all" = todas (lo que lleva el paquete portable).
# bash 3.2 compatible (macOS).
set -eu

VER="${LWJGL_VERSION:-3.4.3}"
BASE="https://repo1.maven.org/maven2/org/lwjgl"
DEST="${1:?uso: fetch-lwjgl.sh DESTINO [natives...]}"
shift
mkdir -p "$DEST"

if [ $# -eq 0 ]; then
   case "$(uname -s)-$(uname -m)" in
      Linux-x86_64) set -- linux;;
      Linux-aarch64|Linux-arm64) set -- linux-arm64;;
      Darwin-x86_64) set -- macos;;
      Darwin-arm64) set -- macos-arm64;;
      MINGW*|MSYS*|CYGWIN*) set -- windows;;
      *) echo "[lwjgl] plataforma sin natives conocidos: $(uname -s)-$(uname -m)"; exit 2;;
   esac
fi
if [ "$1" = "all" ]; then
   set -- linux linux-arm64 macos macos-arm64 windows
fi

sha1_of() {
   if command -v sha1sum >/dev/null 2>&1; then sha1sum "$1" | cut -c1-40; else shasum -a 1 "$1" | cut -c1-40; fi
}

fetch() { # fetch artefacto fichero
   local art="$1" file="$2" dest="$DEST/$2" want got i
   if [ -s "$dest" ]; then
      return 0
   fi
   for i in 1 2 3 4 5 6; do
      want="$(curl -fsSL "$BASE/$art/$VER/$file.sha1" 2>/dev/null | cut -c1-40)" || want=""
      if [ -n "$want" ] && curl -fsSL -o "$dest.part" "$BASE/$art/$VER/$file"; then
         got="$(sha1_of "$dest.part")"
         if [ "$want" = "$got" ]; then
            mv "$dest.part" "$dest"
            echo "[lwjgl] $file"
            return 0
         fi
         echo "[lwjgl] SHA-1 distinto en $file (intento $i)"
      fi
      rm -f "$dest.part"
      sleep $((i * 3))
   done
   echo "[lwjgl] ERROR: no se pudo descargar $file"
   return 1
}

for art in lwjgl lwjgl-glfw lwjgl-opengl; do
   fetch "$art" "$art-$VER.jar"
   for n in "$@"; do
      fetch "$art" "$art-$VER-natives-$n.jar"
   done
done

#!/bin/bash
# Build reproducible del cliente ORIGINAL con el puente portable:
# copia source/ (pristino, Vineflower) + apply_mock.sh + bridge/ a
# editor/.build-gamma (ignorado por git, misma profundidad para que
# apply_mock.sh encuentre tools/ y docs/), aplica mock y puente, y compila
# a editor/.build-gamma/out. No modifica source/.
set -eu
HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
B="$REPO/editor/.build-gamma"
JDK="$REPO/tools/jdk/Contents/Home/bin"
[ -x "$JDK/javac" ] || JDK="$(dirname "$(command -v javac)")"
rm -rf "$B"
mkdir -p "$B"
cp -R "$HERE/source" "$HERE/bridge" "$HERE/apply_mock.sh" "$B/"
(cd "$B" && bash apply_mock.sh)
# Cache: la instalacion 2004 guarda rutas de Windows (C:\DOCUME~1\...\cachedir\5u.mov)
# y CACHE_DIR usa '\'; en macOS/Linux eso descarta cache.index y se pierden
# las texturas de avatar cacheadas. Se usa el separador del sistema y se
# reubica cada localName en el cachedir real por su nombre de fichero.
python3 - "$B/source/NET/worlds/network/Cache.java" <<'PY'
import sys
p = sys.argv[1]
s = open(p).read()
a = ".replace('/', '\\\\');"
assert a in s
s = s.replace(a, ";", 1)
b = "String var18 = var17.localName.toUpperCase();"
assert b in s
s = s.replace(b, "var17.localName = CACHE_DIR + var17.localName.substring(var17.localName.lastIndexOf('\\\\') + 1);\n         " + b, 1)
open(p, "w").write(s)
PY
# CacheEntry.load(): una entrada ya descargada se da por buena sin re-consultar
# al servidor (el original caducaba a los 8 h y refrescaba; hoy no hay origen
# y un refresco fallido dejaba la textura cacheada inservible).
python3 - "$B/source/NET/worlds/network/CacheEntry.java" <<'PY'
import sys
p = sys.argv[1]
s = open(p).read()
a = "if (this.state != 5 && this.state != 0) {\n"
assert a in s
s = s.replace(a, a + "            if (this.state == 4 || this.state == 7) {\n               this.notifyObservers();\n               return;\n            }\n\n", 1)
open(p, "w").write(s)
PY
find "$B/source" -name '*.java' > "$B/sources.txt"
# parsers verificados de client/ que usa el puente: texturas ScapePic
# (.cmp/.mov), formas .rwg y cuerpos .bod (el .rwx lo interpreta
# bridge/RwxReader, traducido de RWL21)
for d in cmp rwg bod; do
  find "$REPO/client/src/net/freeworlds/$d" -name '*.java' >> "$B/sources.txt"
done
mkdir -p "$B/out"
"$JDK/javac" --release 8 -nowarn -encoding UTF-8 -d "$B/out" @"$B/sources.txt" 2>&1 | grep -v '^Note:' || true
n=$(find "$B/out" -name '*.class' | wc -l | tr -d ' ')
echo "clases compiladas: $n"
[ "$n" -gt 0 ]

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
# Ruido de consola: la traza [NATIVE-MOCK] es del arnes (registra hasta las
# nativas ya implementadas) y pasa a ser opt-in con -Dopenworlds.nativeLog=1
# (JAVA_OPTS); y una textura que no se puede cargar se avisa una sola vez,
# no una por cada Shape que la usa. Solo cambia lo que se imprime.
python3 - "$B/source/NET/worlds/core/NativeMock.java" "$B/source/NET/worlds/scape/Material.java" <<'PY'
import sys
p, m = sys.argv[1], sys.argv[2]
s = open(p).read()
a = "      String key = className + \".\" + method;\n"
assert a in s
s = s.replace(a, "      if (!NATIVE_LOG) {\n         return;\n      }\n" + a, 1)
b = "   private static final java.util.Map<String, Integer> counts"
assert b in s
s = s.replace(b, "   private static final boolean NATIVE_LOG = Boolean.getBoolean(\"openworlds.nativeLog\")\n      || \"1\".equals(System.getProperty(\"openworlds.nativeLog\"));\n\n" + b, 1)
open(p, "w").write(s)
t = open(m).read()
c = "   private void loadError(URL var1) {\n"
assert c in t
t = t.replace(c, "   private static final java.util.Set<String> loadErrorsSeen = java.util.Collections.synchronizedSet(new java.util.HashSet<String>());\n\n" + c + "      if (!loadErrorsSeen.add(String.valueOf(var1))) {\n         return;\n      }\n\n", 1)
open(m, "w").write(t)
PY
# Std.initSyncTime: el primer Std.getSynchronizedTime() (lo llama
# BlackBox.postrender en CADA frame, via Room.postrender) abria un Socket
# SIN timeout a time.worlds.net:37 (RFC 868) dentro del hilo de render.
# worlds.net ya no existe: segun el DNS el connect cuelga hasta el timeout de
# TCP del sistema (75 s en macOS, ~130 s en Linux) con la ventana en negro.
# Ahora la base sale del reloj del sistema (hoy va por NTP) pasado a
# segundos RFC 868 (desde 1900) y con la MISMA resta que el original:
# `var10 -= -1141367296L` es 100*365*86400 desbordado en int, asi que el
# origen real es 1999-12-08 UTC, no el 2000 (se conserva tal cual). Si el
# servidor responde, corrige la base desde un hilo aparte (timeouts de 2 s).
python3 - "$B/source/NET/worlds/core/Std.java" <<'PY'
import sys
p = sys.argv[1]
s = open(p).read()
a = "   static int syncTimeBase;\n"
assert a in s
s = s.replace(a, "   static volatile int syncTimeBase;\n", 1)
start = s.index("            String var2 = IniFile.override().getIniString(\"timeServer\", \"time.worlds.net\");\n")
end = s.index("      } else {\n         syncTimeInited = true;\n         syncTimeBase = 0;")
body = """            long var14 = System.currentTimeMillis() / 1000L + 2208988800L;
            var14 -= -1141367296L;
            syncTimeBase = (int)var14 - getFastTime() / 1000;
            final String var2 = IniFile.override().getIniString("timeServer", "time.worlds.net");
            Thread var13 = new Thread(new Runnable() {
               public void run() {
                  try {
                     InetAddress var3 = InetAddress.getByName(var2);
                     Socket var4 = new Socket();
                     var4.connect(new java.net.InetSocketAddress(var3, 37), 2000);
                     var4.setSoTimeout(2000);
                     InputStream var5 = var4.getInputStream();
                     int var6 = var5.read();
                     int var7 = var5.read();
                     int var8 = var5.read();
                     int var9 = var5.read();
                     var5.close();
                     if ((var6 | var7 | var8 | var9) < 0) {
                        throw new java.io.EOFException("short RFC 868 answer");
                     }
                     long var10 = (var6 << 24) + (var7 << 16) + (var8 << 8) + var9;
                     var10 -= -1141367296L;
                     syncTimeBase = (int)var10 - getFastTime() / 1000;
                     var4.close();
                  } catch (Exception var12) {
                     System.out.println("Error retrieving network time: " + var12);
                  }
               }
            }, "openworlds-timeServer");
            var13.setDaemon(true);
            var13.start();
         }
"""
s = s[:start] + body + s[end:]
open(p, "w").write(s)
PY
# Rutas del cliente de 2004 ("u:/...", minusculas, '\') en cada apertura de
# fichero y Toolkit.getImage: ver bridge/NET/worlds/core/HostPath.java. Sin
# esto no se pintaban los botones de la ventana ni se leia redir.txt.
python3 "$HERE/bridge/host_paths.py" "$HERE/source" "$B/source"
# Fuentes con las metricas del JRE de 2004 (Dialog/SansSerif = Arial...): ver
# bridge/NET/worlds/core/NativeUiFonts.java ("Jse arrow keys" en la barra).
python3 "$HERE/bridge/ui_fonts.py" "$HERE/source" "$B/source"
find "$B/source" -name '*.java' > "$B/sources.txt"
# lectores verificados de formats/ que usa el puente: texturas ScapePic
# (.cmp/.mov), formas .rwg y cuerpos .bod (el .rwx lo interpreta
# bridge/RwxReader, traducido de RWL21)
for d in cmp rwg bod; do
  find "$REPO/formats/src/net/openworlds/$d" -name '*.java' >> "$B/sources.txt"
done
mkdir -p "$B/out"
# El codigo de salida de javac cuenta: antes se perdia en la tuberia y una
# compilacion con errores seguia como buena con las clases que salieran.
if "$JDK/javac" --release 8 -nowarn -encoding UTF-8 -d "$B/out" @"$B/sources.txt" > "$B/javac.log" 2>&1; then
  JAVAC_OK=1
else
  JAVAC_OK=0
fi
grep -v '^Note:' "$B/javac.log" || true
n=$(find "$B/out" -name '*.class' | wc -l | tr -d ' ')
echo "clases compiladas: $n"
if [ "$JAVAC_OK" -ne 1 ]; then
  echo "build_gamma: javac fallo (ver $B/javac.log)" >&2
  exit 1
fi
[ "$n" -gt 0 ]

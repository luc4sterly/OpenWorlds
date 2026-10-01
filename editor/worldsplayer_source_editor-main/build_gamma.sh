#!/bin/bash
# Reproducible build of the ORIGINAL client with the portable bridge:
# copies source/ (pristine, Vineflower) + apply_mock.sh + bridge/ to
# editor/.build-gamma (ignored by git, at the same depth so that
# apply_mock.sh finds tools/ and docs/), applies the mock and the bridge, and
# compiles to editor/.build-gamma/out. It does not modify source/.
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
# Cache: the 2004 install stores Windows paths (C:\DOCUME~1\...\cachedir\5u.mov)
# and CACHE_DIR uses '\'; on macOS/Linux that throws cache.index away and the
# cached avatar textures are lost. The system separator is used and each
# localName is moved into the real cachedir by its file name.
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
# CacheEntry.load(): an entry already downloaded is taken as good without asking
# the server again (the original expired it after 8 h and refreshed it; today
# there is no origin and a failed refresh left the cached texture unusable).
python3 - "$B/source/NET/worlds/network/CacheEntry.java" <<'PY'
import sys
p = sys.argv[1]
s = open(p).read()
a = "if (this.state != 5 && this.state != 0) {\n"
assert a in s
s = s.replace(a, a + "            if (this.state == 4 || this.state == 7) {\n               this.notifyObservers();\n               return;\n            }\n\n", 1)
open(p, "w").write(s)
PY
# Console noise: the [NATIVE-MOCK] trace belongs to the harness (it logs even
# the natives already implemented) and becomes opt-in with -Dopenworlds.nativeLog=1
# (JAVA_OPTS); and a texture that cannot be loaded is reported only once,
# not once per Shape that uses it. Only what is printed changes.
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
# Std.initSyncTime: the first Std.getSynchronizedTime() (called by
# BlackBox.postrender on EVERY frame, through Room.postrender) opened a Socket
# WITHOUT a timeout to time.worlds.net:37 (RFC 868) inside the render thread.
# worlds.net no longer exists: depending on the DNS the connect hangs until the
# system's TCP timeout (75 s on macOS, ~130 s on Linux) with the window black.
# Now the base comes from the system clock (kept by NTP nowadays) converted to
# RFC 868 seconds (since 1900) and with the SAME subtraction as the original:
# `var10 -= -1141367296L` is 100*365*86400 overflowed in an int, so the
# real origin is 1999-12-08 UTC, not 2000 (kept as is). If the server
# answers, it corrects the base from a separate thread (2 s timeouts).
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
# Paths of the 2004 client ("u:/...", lowercase, '\') in every file open
# and Toolkit.getImage: see bridge/NET/worlds/core/HostPath.java. Without
# this the window's buttons were not painted and redir.txt was not read.
python3 "$HERE/bridge/host_paths.py" "$HERE/source" "$B/source"
# Fonts with the metrics of the 2004 JRE (Dialog/SansSerif = Arial...): see
# bridge/NET/worlds/core/NativeUiFonts.java ("Jse arrow keys" in the bar).
python3 "$HERE/bridge/ui_fonts.py" "$HERE/source" "$B/source"
find "$B/source" -name '*.java' > "$B/sources.txt"
# verified readers of formats/ that the bridge uses: ScapePic textures
# (.cmp/.mov), .rwg shapes and .bod bodies (the .rwx is interpreted by
# bridge/RwxReader, translated from RWL21)
for d in cmp rwg bod; do
  find "$REPO/formats/src/net/openworlds/$d" -name '*.java' >> "$B/sources.txt"
done
mkdir -p "$B/out"
# javac's exit code counts: it used to get lost in the pipe, and a build
# with errors went on as good with whatever classes came out.
if "$JDK/javac" --release 8 -nowarn -encoding UTF-8 -d "$B/out" @"$B/sources.txt" > "$B/javac.log" 2>&1; then
  JAVAC_OK=1
else
  JAVAC_OK=0
fi
grep -v '^Note:' "$B/javac.log" || true
n=$(find "$B/out" -name '*.class' | wc -l | tr -d ' ')
echo "compiled classes: $n"
if [ "$JAVAC_OK" -ne 1 ]; then
  echo "build_gamma: javac failed (see $B/javac.log)" >&2
  exit 1
fi
[ "$n" -gt 0 ]

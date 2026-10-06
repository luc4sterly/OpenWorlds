#!/bin/bash
# Gets Clearwing VM (the Java bytecode to C++ transpiler the PSVita build uses),
# at the commit of its v3.1.3 release, applies vita/clearwing/patches and
# builds its transpiler and runtime classes with javac (no Gradle).
#
#   vita/tools/setup-clearwing.sh            # into build/vita/clearwing
#
# Result (what vita/tools/transpile.sh uses):
#   build/vita/clearwing/src         the patched source (runtime C++ under runtime/res)
#   build/vita/clearwing/classes/    annotations/, transpiler/, runtime/
#   build/vita/clearwing/m2/         the transpiler's libraries (Maven Central, SHA-256 checked)
#
# Needs git, curl and a JDK 17 or newer.
set -eu

HERE="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$HERE/../.." && pwd)"
OUT="${OPENWORLDS_CLEARWING_DIR:-$REPO/build/vita/clearwing}"
URL=https://github.com/SwitchGDX/clearwing-vm
COMMIT=46f0ab2f3aa9b87600a6921fd4124206bc34e4a1   # v3.1.3

# group:artifact:version sha256
DEPS="
org.ow2.asm:asm:9.7 adf46d5e34940bdf148ecdd26a9ee8eea94496a72034ff7141066b3eea5c4e9d
org.ow2.asm:asm-util:9.7 37a6414d36641973f1af104937c95d6d921b2ddb4d612c66c5a9f2b13fc14211
org.ow2.asm:asm-commons:9.7 389bc247958e049fc9a0408d398c92c6d370c18035120395d4cba1d9d9304b7a
org.ow2.asm:asm-tree:9.7 62f4b3bc436045c1acb5c3ba2d8ec556ec3369093d7f5d06c747eb04b56d52b1
org.ow2.asm:asm-analysis:9.7 7bc6bcbc21379948a0c8c467fb0f864206e5b818f6bc0b546872f5c9f941556f
org.json:json:20220320 1edf7fcea79a16b8dfdd3bc988ddec7f8908b1f7762fdf00d39acb037542747a
net.sourceforge.argparse4j:argparse4j:0.9.0 9eb3b54043038bc111bf0e15a8f69895244f92e3c2bc2800158578ca711f6117
io.github.classgraph:classgraph:4.8.151 4541dde48ed085345efaa5734f7bc7495c5843589a9c0a4cb9594d9c81735cec
com.github.javaparser:javaparser-core:3.24.9 d3f0be846643e1e48907df4576f9cb6b60f9e7c98799f681b5f1690b99499f4a
com.github.javaparser:javaparser-symbol-solver-core:3.24.9 41f238e570c832846dfa91d78f4bef20858febc7e851366afd9ae39e972480d1
org.javassist:javassist:3.29.2-GA a90ddb25135df9e57ea9bd4e224e219554929758f9bae9965f29f81d60a3293f
com.google.guava:guava:31.1-jre a42edc9cab792e39fe39bb94f3fca655ed157ff87a8af78e1d6ba5b07c4a00ab
com.google.guava:failureaccess:1.0.1 a171ee4c734dd2da837e4b16be9df4661afab72a41adaf31eb84dfdaf936ca26
com.google.code.findbugs:jsr305:3.0.2 766ad2a0783f2687962c8ad74ceecc38a28b9f72a2d085ee438b7813e928d0c7
com.github.tommyettinger:regexodus:0.1.14 0437e14e14b2f8338d3ea1c61440961569ee304dc276cab3652a536c77609fe1
"

say() { echo "[clearwing] $*"; }

sha256() {
   if command -v sha256sum >/dev/null 2>&1; then sha256sum "$1" | cut -d' ' -f1
   else shasum -a 256 "$1" | cut -d' ' -f1; fi
}

mkdir -p "$OUT/m2"

# The libraries, retried: Maven Central answers 429 to quick bursts
echo "$DEPS" | while read -r coord sum; do
   [ -n "$coord" ] || continue
   g="${coord%%:*}"; rest="${coord#*:}"; a="${rest%%:*}"; v="${rest#*:}"
   jar="$OUT/m2/$a-$v.jar"
   if [ -f "$jar" ] && [ "$(sha256 "$jar")" = "$sum" ]; then continue; fi
   url="https://repo1.maven.org/maven2/$(echo "$g" | tr . /)/$a/$v/$a-$v.jar"
   ok=""
   for wait in 2 4 8 16 32; do
      if curl -fsSL --max-time 300 -o "$jar.part" "$url"; then ok=1; break; fi
      say "retrying $a-$v.jar in ${wait}s"; sleep "$wait"
   done
   [ -n "$ok" ] || { say "could not download $url"; exit 1; }
   [ "$(sha256 "$jar.part")" = "$sum" ] || { say "$a-$v.jar: wrong SHA-256"; rm -f "$jar.part"; exit 1; }
   mv "$jar.part" "$jar"
   say "got $a-$v.jar"
done

# The source at the pinned commit, with our patches
SRC="$OUT/src"
if [ ! -d "$SRC/.git" ]; then
   rm -rf "$SRC"
   git init -q "$SRC"
   git -C "$SRC" remote add origin "$URL"
fi
git -C "$SRC" fetch -q --depth 1 origin "$COMMIT"
git -C "$SRC" checkout -q -f "$COMMIT"
git -C "$SRC" clean -qfdx
for p in "$REPO"/vita/clearwing/patches/*.patch; do
   git -C "$SRC" apply --whitespace=nowarn "$p" || { say "patch does not apply: $(basename "$p")"; exit 1; }
done
say "source at $COMMIT + $(ls "$REPO"/vita/clearwing/patches/*.patch | wc -l | tr -d ' ') patches"

# Build: annotations, the transpiler (Java 17) and the runtime classes (Java 8)
CLS="$OUT/classes"
rm -rf "$CLS"; mkdir -p "$CLS/annotations" "$CLS/transpiler" "$CLS/runtime"
CP="$(ls "$OUT"/m2/*.jar | tr '\n' ':')"
find "$SRC/annotations/src" -name '*.java' > "$OUT/annotations.txt"
find "$SRC/transpiler/src" -name '*.java' > "$OUT/transpiler.txt"
find "$SRC/runtime/src" -name '*.java' > "$OUT/runtime.txt"
JAVA_TOOL_OPTIONS= javac -nowarn -encoding UTF-8 -d "$CLS/annotations" @"$OUT/annotations.txt"
JAVA_TOOL_OPTIONS= javac -nowarn -encoding UTF-8 --release 17 -cp "$CP$CLS/annotations" -d "$CLS/transpiler" @"$OUT/transpiler.txt"
# -source 8 (not --release) lets javac compile the runtime's own java.* classes
if ! JAVA_TOOL_OPTIONS= javac -nowarn -encoding UTF-8 -source 8 -target 8 -cp "$OUT/m2/regexodus-0.1.14.jar:$CLS/annotations" \
      -d "$CLS/runtime" @"$OUT/runtime.txt" > "$OUT/runtime-javac.log" 2>&1; then
   cat "$OUT/runtime-javac.log"; exit 1
fi
say "built: $(find "$CLS/transpiler" -name '*.class' | wc -l | tr -d ' ') transpiler classes, $(find "$CLS/runtime" -name '*.class' | wc -l | tr -d ' ') runtime classes"

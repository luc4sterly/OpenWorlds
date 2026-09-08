#!/usr/bin/env bash
# Reapplies the JNI mock bridge on top of a freshly `make decompile`d +
# patched source/ tree: NativeMock.java, the native->stub rewrite
# (tools/jni_mock.py), and the two System.load() call sites in Gamma.java
# that would otherwise abort startup when no native DLL is present.
set -euo pipefail
cd "$(dirname "$0")"
ROOT=../..

mkdir -p source/NET/worlds/core
cat > source/NET/worlds/core/NativeMock.java << 'EOF'
package NET.worlds.core;

/**
 * JNI mock bridge (section 7, tool #4 of worlds-chat-project.md). Every
 * method that was originally `native` (implemented in gamma.dll / the
 * RenderWare driver DLLs) got its body replaced with a call into this class
 * instead, so the client can start and run its networking/UI code paths on
 * any platform without the original Windows DLLs.
 */
public final class NativeMock {
   private NativeMock() {
   }

   public static void log(String className, String method, Object[] args) {
      StringBuilder sb = new StringBuilder();
      sb.append("[NATIVE-MOCK] ").append(className).append('.').append(method).append('(');

      for (int i = 0; i < args.length; i++) {
         if (i > 0) {
            sb.append(", ");
         }

         sb.append(String.valueOf(args[i]));
      }

      sb.append(')');
      System.err.println(sb.toString());
   }
}
EOF

python3 "$ROOT/tools/jni_mock.py" source "$ROOT/docs/native-methods-callers.md"

python3 - << 'PYEOF'
import re
path = "source/NET/worlds/console/Gamma.java"
text = open(path).read()

old1 = '''      System.out.println("Loading: " + earlyURLUnalias(_dllPath + "gamma.dll"));
      System.load(earlyURLUnalias(_dllPath + "gamma.dll"));
      if (var6) {'''
new1 = '''      System.out.println("Loading: " + earlyURLUnalias(_dllPath + "gamma.dll"));

      try {
         System.load(earlyURLUnalias(_dllPath + "gamma.dll"));
      } catch (Error varGammaDllLoad) {
         System.err.println(
            "[NATIVE-MOCK] gamma.dll not loaded (" + varGammaDllLoad
               + ") - every native method now runs as a logging stub, see NET.worlds.core.NativeMock"
         );
      }

      if (var6) {'''
assert old1 in text, "Gamma.java main() System.load pattern not found"
text = text.replace(old1, new1)

old2 = '''   public static void dllLoad(String var0) {
      System.load(NET.worlds.network.URL.make(_dllPath + var0).unalias());
   }'''
new2 = '''   public static void dllLoad(String var0) {
      try {
         System.load(NET.worlds.network.URL.make(_dllPath + var0).unalias());
      } catch (Error varDllLoad) {
         System.err.println("[NATIVE-MOCK] " + var0 + " not loaded (" + varDllLoad + ")");
      }
   }'''
assert old2 in text, "Gamma.java dllLoad() System.load pattern not found"
text = text.replace(old2, new2)

open(path, "w").write(text)
print("Patched Gamma.java System.load call sites")
PYEOF

echo "Mock applied."

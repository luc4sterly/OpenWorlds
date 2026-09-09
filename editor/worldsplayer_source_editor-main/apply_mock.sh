#!/usr/bin/env bash
# Reapplies the JNI mock bridge on top of a freshly `make decompile`d +
# patched source/ tree: NativeMock.java, the native->stub rewrite
# (tools/jni_mock.py), the System.load()/loadLibrary() call sites in
# Gamma.java that would otherwise abort startup or crash on a modern JDK,
# and a small portability fix in NET.worlds.network.URL (real 2004 client
# logic, not a native method - see worlds-chat-project.md sec. 4 for the
# full investigation of why this one was safe to patch this way).
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

   /**
    * Shared by the "smart" mocks (FastDataInput, IniFile) that do real
    * disk I/O: NET.worlds.network.URL.validateFile() lowercases every
    * path it resolves - harmless on the case-insensitive Windows
    * filesystem this client was written for, but it means a literal path
    * built from that scheme almost never matches a real filename on a
    * case-sensitive Linux filesystem (e.g. "newworld.world" vs the real
    * "NewWorld.world"). Walk the path one segment at a time and, for any
    * segment that doesn't match exactly, fall back to a case-insensitive
    * match against the real directory listing - i.e. reproduce the same
    * case-insensitive lookup Windows already does for free.
    */
   public static java.io.File resolveCaseInsensitive(String path) {
      java.io.File exact = new java.io.File(path);
      if (exact.exists()) {
         return exact;
      }

      java.io.File current = new java.io.File(path.startsWith("/") ? "/" : ".");

      for (String part : path.split("/")) {
         if (part.isEmpty()) {
            continue;
         }

         java.io.File candidate = new java.io.File(current, part);
         if (!candidate.exists()) {
            java.io.File[] siblings = current.listFiles();
            if (siblings != null) {
               for (java.io.File sibling : siblings) {
                  if (sibling.getName().equalsIgnoreCase(part)) {
                     candidate = sibling;
                     break;
                  }
               }
            }
         }

         current = candidate;
      }

      return current;
   }
}
EOF

python3 "$ROOT/tools/jni_mock.py" source "$ROOT/docs/native-methods-callers.md"

# "Smart" mock override for FastDataInput (section 7, tool #4 extension -
# see worlds-chat-project.md sec. 4 for the full investigation). Unlike the
# generic NativeMock stubs jni_mock.py just wrote into this file (log +
# return a zero/false/null default), this one does REAL sequential binary
# file I/O by delegating to java.io.DataInputStream. Verified safe:
#   - FastDataInput `implements DataInput` and every method on it IS one of
#     that interface's primitive read methods - no seek/random-access is
#     exposed anywhere in the class, so a plain DataInputStream fulfills
#     the whole contract.
#   - protocol/LibreWorlds-wiki-master/Persister-(.world-etc.)-format.md
#     (third-party, independently reverse-engineered) confirms the on-disk
#     .world/.rwx/etc. format IS Java's own DataInput/DataOutput wire
#     format (2-byte big-endian length-prefixed modified-UTF-8 strings,
#     etc.) - a real DataInputStream is byte-for-byte compatible, not an
#     approximation.
cat > source/NET/worlds/core/FastDataInput.java << 'EOF'
package NET.worlds.core;

import java.io.DataInput;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

public class FastDataInput implements DataInput {
   private DataInputStream in;

   public FastDataInput(String var1) throws IOException {
      nativeInit();
      this.read(var1);
   }

   public void close() {
      NET.worlds.core.NativeMock.log("FastDataInput", "close", new Object[0]);

      try {
         if (this.in != null) {
            this.in.close();
         }
      } catch (IOException var2) {
      }
   }

   public void readFully(byte[] var1) throws IOException {
      this.readFully(var1, 0, var1.length);
   }

   public static void nativeInit() {
      NET.worlds.core.NativeMock.log("FastDataInput", "nativeInit", new Object[0]);
   }

   // The read* methods below deliberately do NOT log every call (unlike
   // the generic NativeMock stubs) - they run once per primitive value in
   // a binary file that can contain many thousands of them, and are pure
   // pass-through to DataInputStream, so there is nothing a per-call log
   // line would add besides noise and slowdown. open()/close() are logged.
   public void readFully(byte[] var1, int var2, int var3) throws IOException {
      this.in.readFully(var1, var2, var3);
   }

   public int skipBytes(int var1) throws IOException {
      return this.in.skipBytes(var1);
   }

   public boolean readBoolean() throws IOException {
      return this.in.readBoolean();
   }

   public byte readByte() throws IOException {
      return this.in.readByte();
   }

   public int readUnsignedByte() throws IOException {
      return this.in.readUnsignedByte();
   }

   public short readShort() throws IOException {
      return this.in.readShort();
   }

   public int readUnsignedShort() throws IOException {
      return this.in.readUnsignedShort();
   }

   public char readChar() throws IOException {
      return this.in.readChar();
   }

   public int readInt() throws IOException {
      return this.in.readInt();
   }

   public long readLong() throws IOException {
      return this.in.readLong();
   }

   public float readFloat() throws IOException {
      return this.in.readFloat();
   }

   public double readDouble() throws IOException {
      return this.in.readDouble();
   }

   public String readLine() throws IOException {
      Debug.assert_(false);
      return null;
   }

   public String readUTF() throws IOException {
      return this.in.readUTF();
   }

   private void read(String var1) throws IOException {
      NET.worlds.core.NativeMock.log("FastDataInput", "read", new Object[]{var1});
      String var2 = var1;
      if (var1.length() > 1 && var1.charAt(1) == ':') {
         // Strip the synthetic single-character "drive" prefix that
         // NET.worlds.network.URL.normalizeCurrentDir() adds on non-Windows
         // platforms (see this script) - real Unix filesystem paths never
         // start with "<char>:". This is specific to running the mock on
         // Linux/Xvfb, not a general Windows-path fix.
         var2 = var1.substring(2);
      }

      this.in = new DataInputStream(new FileInputStream(NativeMock.resolveCaseInsensitive(var2)));
   }
}
EOF

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

# System.loadLibrary("net") is meant to load the legacy Windows helper
# net.dll bundled with the original 2004 JRE (see
# assets/WorldsPlayer/bin/net.dll) - on any modern JDK "net" collides with
# the JDK's OWN internal libnet.so (networking native lib). loadLibrary
# actually *succeeds* here (it just finds the JDK's own library on the
# search path) but registers it under our app classloader; later, when
# Swing's font/NIO code loads the same libnet.so via the bootstrap
# classloader, the JVM throws "already loaded in another classloader" and
# kills the main thread - reproduced in isolation with a 10-line test, see
# docs/xvfb-runtime-trace.log. Skipping this call entirely (it never did
# anything useful outside real Windows anyway) avoids the crash.
old3 = '''         try {
            System.loadLibrary(var5);
         } catch (UnsatisfiedLinkError var34) {
         }'''
new3 = '''         try {
            if (!var5.equals("net")) {
               System.loadLibrary(var5);
            } else {
               System.err.println(
                  "[NATIVE-MOCK] skipping System.loadLibrary(\\"net\\") - collides with"
                     + " the JDK's own libnet.so on modern JDKs and crashes Swing later"
               );
            }
         } catch (UnsatisfiedLinkError var34) {
         }'''
assert old3 in text, "Gamma.java loadLibrary(net) pattern not found"
text = text.replace(old3, new3)

open(path, "w").write(text)
print("Patched Gamma.java System.load call sites")
PYEOF

python3 - << 'PYEOF'
# NET.worlds.network.URL's file: URL scheme structurally assumes a
# single-character drive letter followed by a colon (x:/...) because on
# Windows System.getProperty("user.dir") always looks like "C:/...". On
# Unix it's "/home/user/..." instead, which fails the class's own asserts
# (currentDir.charAt(1)==':' in the static {} block, plus two more in
# normalize()) before the client gets anywhere near real networking.
# Investigated first (see worlds-chat-project.md sec. 4): the only other
# place in the class touching separators already normalizes '\'->'/' at
# declaration time, and the class's one real java.io.File construction
# (searchPath()) uses File.separator on a completely separate code path
# that never touches _url/currentDir - so this is safe to patch by
# synthesizing a fake single-character "drive" ('u', for Unix) rather than
# by loosening the asserts themselves, which would have left the rest of
# the class's x:/... parsing inconsistent.
path = "source/NET/worlds/network/URL.java"
text = open(path).read()

old = '''   private static String currentDir = System.getProperty("user.dir").replace('\\\\', '/');
   private static URL home;
   private static URL file;
   private static boolean useCachedFiles;
   private static URL avatar;'''
new = '''   private static String currentDir = normalizeCurrentDir(System.getProperty("user.dir").replace('\\\\', '/'));
   private static URL home;
   private static URL file;
   private static boolean useCachedFiles;
   private static URL avatar;

   private static String normalizeCurrentDir(String var0) {
      if (var0.length() > 1 && var0.charAt(1) == ':' || var0.startsWith("//")) {
         return var0;
      } else {
         return "u:" + var0;
      }
   }'''
assert old in text, "URL.java currentDir declaration pattern not found"
text = text.replace(old, new)

open(path, "w").write(text)
print("Patched URL.java currentDir (Windows drive-letter assumption)")
PYEOF

python3 - << 'PYEOF'
# NET.worlds.console.Cursor.<clinit> asserts Debug.dAssert(defaultCursor
# != 0) - defaultCursor comes from loadSystemCursor("IDC_ARROW"), a native
# Win32-handle-returning method. This is NOT a Windows-path-style
# portability wall like URL.java/Cache.java - it's the generic native mock
# policy (int natives default to 0) colliding with this codebase's
# Win32 convention that a 0 handle means "failed to load". loadCursor()
# has the exact same shape (checked with `!= 0` at Cursor.java:145) so both
# get the same treatment: return a non-zero placeholder handle instead of
# the generic 0 default, consistent with the existing "push the client
# further" mock philosophy (booleans already default to true for the same
# reason - see tools/jni_mock.py).
path = "source/NET/worlds/console/Cursor.java"
text = open(path).read()

old1 = '''   private static int loadSystemCursor(String var0) {
      NET.worlds.core.NativeMock.log("Cursor", "loadSystemCursor", new Object[]{var0});
      return 0;
   }'''
new1 = '''   private static int loadSystemCursor(String var0) {
      NET.worlds.core.NativeMock.log("Cursor", "loadSystemCursor", new Object[]{var0});
      return 1;
   }'''
assert old1 in text, "Cursor.java loadSystemCursor pattern not found"
text = text.replace(old1, new1)

old2 = '''      NET.worlds.core.NativeMock.log("Cursor", "loadCursor", new Object[]{var0});
      return 0;
   }'''
new2 = '''      NET.worlds.core.NativeMock.log("Cursor", "loadCursor", new Object[]{var0});
      return 1;
   }'''
assert old2 in text, "Cursor.java loadCursor pattern not found"
text = text.replace(old2, new2)

open(path, "w").write(text)
print("Patched Cursor.java loadCursor/loadSystemCursor (native handle default)")
PYEOF

echo "Mock applied."

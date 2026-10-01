package NET.worlds.core;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.RandomAccessFile;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * A world package of the upgrade server made with NSIS: the ones LibreWorlds
 * rebuilt (Dcn10, WorldsChat50, GroundZero37-40/GroundZero40 on
 * us1.worlds.net/3DCDup). gdkup.exe runs it with no arguments, so it installs
 * into $INSTDIR = $EXEDIR, the folder the client downloaded it to
 * (&lt;home&gt;\&lt;World&gt;\&lt;World&gt;N.exe, NetUpdate.getVersions).
 *
 * <p>The three packages are NSIS 3 Unicode installers (UTF-16 strings,
 * NSIS_MAX_STRLEN 8192) with non-solid zlib compression: after the
 * firstheader (0xDEADBEEF "NullsoftInst") come the header block and then one
 * block per file, each an int length (bit 31 = compressed) and raw deflate.
 * Their scripts are three sections ("Check Required Files", then "Copy
 * Files" and "Configure Worlds" in the full packages, "Check Version File"
 * and "Applying Update" in the 37-40 upgrade) and at most one function (the
 * upgrade's trims the line end off ver.txt). This runs them: sections in
 * order when selected (flag 1), .onInit/.onInstSuccess when present, each
 * entry as in NSIS's exec.c (ExecuteCodeSegment: jump targets are
 * entry + 1, 0 = next, EW_RET ends the segment):
 * EW_RET 1, EW_NOP 2 (Goto), EW_ABORT 3, EW_QUIT 4, EW_CALL 5,
 * EW_UPDATETEXT 6 (DetailPrint, to the log), EW_CREATEDIR 11 (SetOutPath
 * when parm1), EW_IFFILEEXISTS 12, EW_SETFLAG 13, EW_EXTRACTFILE 20,
 * EW_DELETEFILE 21, EW_MESSAGEBOX 22 (to the log, as a silent install),
 * EW_ASSIGNVAR 25, EW_STRCMP 26, EW_INTCMP 28, EW_INTOP 29, EW_PUSHPOP 31,
 * EW_WRITEINI 48, EW_READINISTR 49, EW_FCLOSE 54, EW_FOPEN 55, EW_FGETS 57.
 * Any other opcode stops the install with an error instead of being guessed.
 * The error flag (exec_error, read by IfErrors) is not kept: none of the
 * scripts reads it.
 * Strings: 1 = language string, 2 = shell folder (both empty here: none of
 * the three uses them where it matters), 3 = variable, 4 = next character
 * as is; the number after a code is ((c &gt;&gt; 8) &amp; 0x7F) &lt;&lt; 7 | (c &amp; 0x7F).
 * Variables: $0-$9, $R0-$R9, $CMDLINE 20, $INSTDIR 21, $OUTDIR 22, $EXEDIR 23,
 * $LANGUAGE 24, $TEMP 25, $PLUGINSDIR 26, $EXEPATH 27, $EXEFILE 28, then the
 * user's. Windows paths ("$EXEDIR\..\worlds.ini") are taken to the host
 * filesystem with '\' as separator and names matched without case.
 * ⚠️ VERIFY: only this subset (Unicode, non-solid zlib) is read; an ANSI,
 * solid or LZMA/bzip2 installer is refused with an error.
 */
final class NsisPackage {
   private static final int ERR = Integer.MIN_VALUE;
   private static final int INSTDIR = 21;
   private static final int OUTDIR = 22;
   private static final int EXEDIR = 23;

   private final byte[] h;
   private final byte[] file;
   private final int dataBase;
   private final int entriesOff;
   private final int entryCount;
   private final int stringsOff;
   private final int stringsEnd;
   private final String[] vars = new String[1024];
   private final int[] flags = new int[32];
   /** The NSIS stack (Push/Pop/Exch), top first. */
   private final List<String> stack = new ArrayList<String>();
   /** FileOpen handles ("1", "2", ... as the handle variable's text). */
   private final Map<String, RandomAccessFile> handles = new HashMap<String, RandomAccessFile>();
   private int nextHandle = 1;
   private final PrintStream log;
   private int files;
   private int steps;

   private NsisPackage(byte[] file, byte[] header, int dataBase, PrintStream log) {
      this.file = file;
      this.h = header;
      this.dataBase = dataBase;
      this.log = log;
      this.entriesOff = i32(12 + 8);
      this.entryCount = i32(12 + 12);
      this.stringsOff = i32(4 + 8 * 3);
      this.stringsEnd = i32(4 + 8 * 4);
      for (int i = 0; i < vars.length; i++) {
         vars[i] = "";
      }
   }

   /** An NSIS installer: 0xDEADBEEF followed by "NullsoftInst". */
   static boolean is(byte[] d) {
      return firstHeader(d) >= 0;
   }

   private static int firstHeader(byte[] d) {
      int i = WisePackage.indexOf(d, "NullsoftInst".getBytes(), 0);
      while (i >= 8) {
         if (WisePackage.u32(d, i - 4) == 0xDEADBEEFL) {
            return i - 8;
         }
         i = WisePackage.indexOf(d, "NullsoftInst".getBytes(), i + 1);
      }
      return -1;
   }

   /** Installs the package the way the installer would with no arguments; returns the folder it installed to. */
   static String install(File pkg, PrintStream log) throws IOException {
      byte[] d = Files.readAllBytes(pkg.toPath());
      int fh = firstHeader(d);
      if (fh < 0) {
         throw new IOException(pkg + ": not an NSIS installer");
      }
      int headerLen = (int) WisePackage.u32(d, fh + 20);
      int blk = fh + 28;
      long len = WisePackage.u32(d, blk);
      byte[] header;
      if ((len & 0x80000000L) != 0) {
         try {
            header = WisePackage.inflate(d, blk + 4, (int) (len & 0x7fffffffL), headerLen);
         } catch (IOException e) {
            throw new IOException(pkg + ": the NSIS header is not non-solid zlib (" + e.getMessage() + ")");
         }
      } else {
         header = new byte[(int) len];
         System.arraycopy(d, blk + 4, header, 0, header.length);
      }
      NsisPackage p = new NsisPackage(d, header, blk + 4 + (int) (len & 0x7fffffffL), log);
      if (!p.unicode()) {
         throw new IOException(pkg + ": ANSI NSIS installer, not supported");
      }
      File exe = pkg.getAbsoluteFile();
      p.vars[20] = "\"" + winPath(exe) + "\"";
      p.vars[EXEDIR] = winPath(exe.getParentFile());
      p.vars[24] = "1033";
      p.vars[25] = winPath(new File(System.getProperty("java.io.tmpdir")));
      p.vars[27] = winPath(exe);
      p.vars[28] = exe.getName();
      int instdir = p.i32(280);
      p.vars[INSTDIR] = instdir >= 0 ? p.str(instdir) : p.vars[EXEDIR];
      p.vars[OUTDIR] = p.vars[INSTDIR];
      try {
         p.run();
      } finally {
         // the installer process ending closes what the script left open
         for (RandomAccessFile f : p.handles.values()) {
            f.close();
         }
      }
      return p.vars[INSTDIR];
   }

   private boolean unicode() {
      return h.length > stringsOff + 4 && h[stringsOff] == 0 && h[stringsOff + 1] == 0;
   }

   private void run() throws IOException {
      int onInit = i32(108);
      if (onInit >= 0 && segment(onInit) == ERR) {
         throw new IOException("the installer stopped in .onInit");
      }
      int secOff = i32(4 + 8);
      int secCount = i32(4 + 12);
      int secSize = secCount > 0 ? (entriesOff - secOff) / secCount : 0;
      for (int s = 0; s < secCount; s++) {
         int base = secOff + s * secSize;
         int secFlags = i32(base + 8);
         int code = i32(base + 12);
         if ((secFlags & 1) != 0 && code >= 0) {
            log.println("[gdkup] section \"" + str(i32(base)) + "\"");
            if (segment(code) == ERR) {
               throw new IOException("the installer stopped in section \"" + str(i32(base)) + "\"");
            }
         }
      }
      int onSuccess = i32(112);
      if (onSuccess >= 0) {
         segment(onSuccess);
      }
      log.println("[gdkup] " + files + " files in " + hostFile(vars[INSTDIR]));
   }

   /** ExecuteCodeSegment. */
   private int segment(int pos) throws IOException {
      while (pos >= 0 && pos < entryCount) {
         if (op(pos) == 1) {
            return 0;
         }
         if (++steps > 1000000) {
            throw new IOException("the NSIS script does not end");
         }
         int rv = exec(pos);
         if (rv == ERR) {
            return ERR;
         }
         rv = resolveAddr(rv);
         pos = rv == 0 ? pos + 1 : rv - 1;
      }
      return 0;
   }

   private int resolveAddr(int v) {
      return v < 0 ? atoi(vars[-(v + 1)]) : v;
   }

   private int op(int k) {
      return i32(entriesOff + 28 * k);
   }

   private int parm(int k, int n) {
      return i32(entriesOff + 28 * k + 4 + 4 * n);
   }

   private int exec(int k) throws IOException {
      int p0 = parm(k, 0);
      int p1 = parm(k, 1);
      int p2 = parm(k, 2);
      int p3 = parm(k, 3);
      int p4 = parm(k, 4);
      int p5 = parm(k, 5);
      switch (op(k)) {
         case 2:
            return p0;
         case 3:
            log.println("[gdkup] Aborting: \"" + str(p0) + "\"");
            return ERR;
         case 4:
            return ERR;
         case 5: {
            int r = segment(resolveAddr(p0) - 1);
            return r == ERR ? ERR : 0;
         }
         case 6:
            log.println("[gdkup] " + str(p0));
            return 0;
         case 11: {
            String path = str(p0);
            File dir = hostFile(path);
            if (!dir.isDirectory() && !dir.mkdirs()) {
               throw new IOException("cannot create " + dir);
            }
            if (p1 != 0) {
               vars[OUTDIR] = path;
            }
            return 0;
         }
         case 12:
            return hostFile(str(p0)).exists() ? p1 : p2;
         case 13:
            if (p2 == 0 && p0 >= 0 && p0 < flags.length) {
               flags[p0] = atoi(str(p1));
            }
            return 0;
         case 20:
            extract(p0, str(p1), p2, p3, p4);
            return 0;
         case 21:
            delete(str(p0));
            return 0;
         case 22:
            log.println("[gdkup] installer message: " + str(p1));
            return 0;
         case 25: {
            String s = str(p1);
            int newlen = atoi(str(p2));
            int start = atoi(str(p3));
            String out = "";
            if (p2 == 0 || newlen != 0) {
               int l = s.length();
               if (start < 0) {
                  start = l + start;
               }
               if (start >= 0) {
                  out = s.substring(Math.min(start, l));
                  if (newlen != 0) {
                     if (newlen < 0) {
                        newlen = Math.max(0, out.length() + newlen);
                     }
                     if (newlen < out.length()) {
                        out = out.substring(0, newlen);
                     }
                  }
               }
            }
            vars[p0] = out;
            return 0;
         }
         case 26: {
            String a = str(p0);
            String b = str(p1);
            return (p4 == 0 ? a.equalsIgnoreCase(b) : a.equals(b)) ? p2 : p3;
         }
         case 28: {
            int a = atoi(str(p0));
            int b = atoi(str(p1));
            if (p5 == 0) {
               return a < b ? p3 : a > b ? p4 : p2;
            }
            int c = Integer.compare(a ^ Integer.MIN_VALUE, b ^ Integer.MIN_VALUE);
            return c < 0 ? p3 : c > 0 ? p4 : p2;
         }
         case 29:
            vars[p0] = Integer.toString(intOp(atoi(str(p1)), atoi(str(p2)), p3));
            return 0;
         case 31:
            return pushPop(p0, p1, p2);
         case 48: {
            if (p0 == 0 || p1 == 0 || p4 == 0) {
               throw new IOException("WriteINIStr without a section, key or value: not supported");
            }
            File ini = hostFile(str(p3));
            WinIni.put(ini, str(p0), str(p1), str(p2));
            log.println("[gdkup] " + ini.getName() + ": [" + str(p0) + "] " + str(p1) + "=" + str(p2));
            return 0;
         }
         case 49: {
            String v = WinIni.get(hostFile(str(p3)), str(p1), str(p2), null);
            vars[p0] = v == null ? "" : v;
            return 0;
         }
         case 54: {
            RandomAccessFile f = handles.remove(vars[p0]);
            if (f != null) {
               f.close();
            }
            return 0;
         }
         case 55:
            fileOpen(p0, p1, p2, str(p3));
            return 0;
         case 57:
            vars[p1] = fileRead(vars[p0], atoi(str(p2)), p3 != 0);
            return 0;
         default:
            throw new IOException("NSIS opcode " + op(k) + " (entry " + k + ") not supported");
      }
   }

   /**
    * EW_PUSHPOP: parm2 = n exchanges the top with the n-th entry (Exch),
    * else parm1 pops into variable parm0, else parm0 (a string) is pushed.
    * An Exch past the stack's end fails the install as in exec.c (the
    * "installer corrupted" box); a Pop on an empty stack leaves the
    * variable and only sets the error flag, which is not kept here.
    */
   private int pushPop(int p0, int p1, int p2) throws IOException {
      if (p2 != 0) {
         if (p2 >= stack.size()) {
            throw new IOException("Exch: the stack has fewer than " + (p2 + 1) + " elements");
         }
         String top = stack.get(0);
         stack.set(0, stack.get(p2));
         stack.set(p2, top);
      } else if (p1 != 0) {
         if (!stack.isEmpty()) {
            vars[p0] = stack.remove(0);
         }
      } else {
         stack.add(0, str(p0));
      }
      return 0;
   }

   /**
    * EW_DELETEFILE: every file (not folder) matching the name, which may
    * have * and ? in its last part (FindFirstFile); a file that is missing
    * is no error.
    */
   private void delete(String name) {
      File f = hostFile(name);
      String base = f.getName();
      File[] matches;
      if (base.indexOf('*') >= 0 || base.indexOf('?') >= 0) {
         final java.util.regex.Pattern glob = java.util.regex.Pattern.compile(
            java.util.regex.Pattern.quote(base).replace("*", "\\E.*\\Q").replace("?", "\\E.\\Q"),
            java.util.regex.Pattern.CASE_INSENSITIVE);
         File dir = f.getParentFile();
         matches = dir == null ? null : dir.listFiles(new java.io.FileFilter() {
            public boolean accept(File c) {
               return glob.matcher(c.getName()).matches();
            }
         });
      } else {
         matches = new File[]{f};
      }
      if (matches == null) {
         return;
      }
      for (File m : matches) {
         if (m.isFile()) {
            log.println("[gdkup] Delete: " + m + (m.delete() ? "" : " (failed)"));
         }
      }
   }

   /**
    * EW_FOPEN: parm1 = access (GENERIC_READ 0x80000000, GENERIC_WRITE
    * 0x40000000), parm2 = CreateFile disposition (2 CREATE_ALWAYS, 3
    * OPEN_EXISTING, 4 OPEN_ALWAYS). The handle's text goes to the variable,
    * or "" when the file cannot be opened.
    */
   private void fileOpen(int var, int access, int disposition, String name) throws IOException {
      File f = hostFile(name);
      boolean write = (access & 0x40000000) != 0;
      if (disposition == 3 && !f.isFile() || !write && !f.isFile()) {
         vars[var] = "";
         return;
      }
      RandomAccessFile raf = new RandomAccessFile(f, write ? "rw" : "r");
      if (disposition == 2) {
         raf.setLength(0);
      }
      String h = Integer.toString(nextHandle++);
      handles.put(h, raf);
      vars[var] = h;
   }

   /**
    * EW_FGETS in the Unicode build (FileRead): single bytes read as ANSI
    * characters (the files here are ASCII), up to maxlen (0 = nothing).
    * A line keeps its end: after a CR or LF, a different CR/LF is kept and
    * ends the line, anything else is put back. With getchar the character's
    * number is returned instead.
    */
   private String fileRead(String handle, int maxlen, boolean getchar) throws IOException {
      RandomAccessFile f = handles.get(handle);
      StringBuilder out = new StringBuilder();
      if (f == null || maxlen < 1) {
         return "";
      }
      maxlen = Math.min(maxlen, 8191);
      int lc = 0;
      while (out.length() < maxlen) {
         int c = f.read();
         if (c < 0) {
            break;
         }
         if (getchar) {
            return Integer.toString(c);
         }
         if (lc == '\r' || lc == '\n') {
            if (lc == c || c != '\r' && c != '\n') {
               f.seek(f.getFilePointer() - 1);
            } else {
               out.append((char) c);
            }
            break;
         }
         out.append((char) c);
         lc = c;
         if (c == 0) {
            break;
         }
      }
      return out.toString();
   }

   private static int intOp(int v, int v2, int op) {
      switch (op) {
         case 0:
            return v + v2;
         case 1:
            return v - v2;
         case 2:
            return v * v2;
         case 3:
            return v2 != 0 ? v / v2 : 0;
         case 4:
            return v | v2;
         case 5:
            return v & v2;
         case 6:
            return v ^ v2;
         case 7:
            return v == 0 ? 1 : 0;
         case 8:
            return v != 0 || v2 != 0 ? 1 : 0;
         case 9:
            return v != 0 && v2 != 0 ? 1 : 0;
         case 10:
            return v2 != 0 ? v % v2 : 0;
         case 11:
            return v << v2;
         case 12:
            return v >> v2;
         default:
            return v >>> v2;
      }
   }

   /** EW_EXTRACTFILE: overwrite = parm0 &amp; 7 (0 on, 1 off, 3 if newer), name relative to $OUTDIR, FILETIME in parm3/4. */
   private void extract(int flagsParm, String name, int offset, int ftLow, int ftHigh) throws IOException {
      String path = name.length() > 1 && name.charAt(1) == ':' || name.startsWith("\\") ? name : vars[OUTDIR] + "\\" + name;
      File to = hostFile(path);
      long time = ftLow == -1 && ftHigh == -1 ? -1 : fileTime(ftLow, ftHigh);
      int overwrite = flagsParm & 7;
      if (to.exists() && (overwrite == 1 || overwrite == 3 && time >= 0 && to.lastModified() >= time)) {
         log.println("[gdkup] keeping " + to);
         return;
      }
      int at = dataBase + offset;
      long len = WisePackage.u32(file, at);
      byte[] data;
      if ((len & 0x80000000L) != 0) {
         data = WisePackage.inflate(file, at + 4, (int) (len & 0x7fffffffL), -1);
      } else {
         data = new byte[(int) len];
         System.arraycopy(file, at + 4, data, 0, data.length);
      }
      File parent = to.getParentFile();
      if (!parent.isDirectory() && !parent.mkdirs()) {
         throw new IOException("cannot create " + parent);
      }
      OutputStream out = new FileOutputStream(to);
      try {
         out.write(data);
      } finally {
         out.close();
      }
      if (time >= 0) {
         to.setLastModified(time);
      }
      files++;
   }

   /** FILETIME (100 ns since 1601) to Java time. */
   private static long fileTime(int low, int high) {
      long ft = (high & 0xffffffffL) << 32 | (low & 0xffffffffL);
      return ft / 10000L - 11644473600000L;
   }

   /** A string of the string table (UTF-16) with its codes expanded; negative = language string. */
   private String str(int off) {
      if (off < 0) {
         return "";
      }
      StringBuilder sb = new StringBuilder();
      int p = stringsOff + off * 2;
      while (p + 1 < stringsEnd) {
         int c = (h[p] & 255) | (h[p + 1] & 255) << 8;
         p += 2;
         if (c == 0) {
            break;
         }
         if (c >= 1 && c <= 4) {
            int a = (h[p] & 255) | (h[p + 1] & 255) << 8;
            p += 2;
            if (c == 4) {
               sb.append((char) a);
               continue;
            }
            int n = ((a >> 8) & 0x7F) << 7 | (a & 0x7F);
            if (c == 3 && n < vars.length) {
               sb.append(vars[n]);
            }
            continue;
         }
         sb.append((char) c);
      }
      return sb.toString();
   }

   /** NSIS myatoi: optional '-', then 0x hex, leading 0 octal, or decimal, up to the first other character. */
   static int atoi(String s) {
      int i = 0;
      int sign = 1;
      if (s.startsWith("-")) {
         sign = -1;
         i = 1;
      }
      int base = 10;
      if (s.startsWith("0x", i) || s.startsWith("0X", i)) {
         base = 16;
         i += 2;
      } else if (s.startsWith("0", i)) {
         base = 8;
      }
      int v = 0;
      for (; i < s.length(); i++) {
         int d = Character.digit(s.charAt(i), base);
         if (d < 0) {
            break;
         }
         v = v * base + d;
      }
      return sign * v;
   }

   private int i32(int o) {
      return (int) WisePackage.u32(h, o);
   }

   static String winPath(File f) {
      return f.getPath().replace('/', '\\');
   }

   /** A path of the script on the host: '\' and '/' as separators, ".." resolved, existing names matched without case. */
   static File hostFile(String win) {
      String p = win.replace('\\', '/');
      File cur = p.startsWith("/") ? new File("/") : new File(".");
      if (p.length() > 1 && p.charAt(1) == ':') {
         cur = new File(p.substring(0, 2) + File.separator);
         p = p.substring(2);
      }
      for (String part : p.split("/")) {
         if (part.isEmpty() || part.equals(".")) {
            continue;
         }
         if (part.equals("..")) {
            File parent = cur.getAbsoluteFile().getParentFile();
            cur = parent == null ? cur : parent;
            continue;
         }
         cur = GdkUp.child(cur, part);
      }
      return cur;
   }
}

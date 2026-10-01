package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.zip.DataFormatException;
import java.util.zip.Inflater;

/**
 * A world package of the upgrade server made with Wise, the kind of the
 * 2000-2001 worlds (AvatarGallery36, AnimalHouse33, Chaos14, Meteor25,
 * lets62 on us1.worlds.net/3DCDup): a WiseMain self-installing executable
 * whose data is a PKZIP archive. gdkup.exe runs it with no arguments
 * (gdkup_exe/00401d52); on Windows it installs into the client's home,
 * which NetUpdate.loadPatchesAndUpdateScript writes to the registry
 * (InstallDir) right before, for every full install.
 *
 * <p>The first local header of the archive has no name and flag 0x8000 and
 * is not in the central directory: it is the compiled Wise script. What the
 * scripts of the five packages above do, read from their strings and
 * matching the WSE sources that ship in GroundZero/ (custom.wse,
 * custup.wse):
 * <ul>
 * <li>abort with "You can't install ... until you first install Worlds."
 *     when %MAINDIR%\worlds.ini has no [Gamma] UpgradeServer;</li>
 * <li>WORLDDIR = %MAINDIR%\&lt;World&gt;;</li>
 * <li>one "Install File" per archive entry, in the same order, to
 *     %WORLDDIR%\&lt;path&gt;: the archive keeps the upper-case file name, the
 *     destination the real case and the subfolder (tex\Flr-Cel2.rwx,
 *     Wav\Sad5.mid). The Wise runtime that travels in the archive
 *     (FILE0001.DAT with the dialogs, WISE0001.DLL, CTL3D*.DLL,
 *     REBOOTNT.EXE) has no destination: checked on all five, every other
 *     entry has one, in order;</li>
 * <li>[InstalledWorlds]: WORLDNUM = 0, then up by one while
 *     InstalledWorld&lt;WORLDNUM&gt; holds another world; MaxInstalledWorlds
 *     raised to WORLDNUM when lower (all but Chaos14, whose older script only
 *     writes the next line); InstalledWorld&lt;WORLDNUM&gt;=&lt;World&gt;.</li>
 * </ul>
 * Files get the date of their archive entry, as the Wise installer leaves
 * them. Not reproduced: the install log (%MAINDIR%\&lt;World&gt;.log) and the
 * reads of the desktop and Start menu folders, which nothing uses.
 * ⚠️ VERIFY: the script is read by its strings, not by decoding each Wise
 * item; the "same world" test is done without case (NSIS's StrCmp in the
 * newer packages is without case; Wise's If/While is assumed to be).
 */
final class WisePackage {
   private static final String[] RUNTIME = {"FILE0001.DAT", "WISE0001.DLL", "CTL3D.DLL", "CTL3DNT.DLL", "REBOOTNT.EXE"};
   /** Set Variable: fields separated by 0x7F ("0\x7fWORLDDIR\x7f%MAINDIR%\\AvatarGallery\0"). */
   private static final Pattern WORLDDIR = Pattern.compile("WORLDDIR\u007f%MAINDIR%\\\\([^\u0000\u007f\\\\]+)[\u0000\u007f]");
   private static final Pattern DEST = Pattern.compile("%WORLDDIR%\\\\([^\u0000]+)");
   /** Edit INI File: the text of its settings ends in CRLF CRLF. */
   private static final Pattern INI_WORLD = Pattern.compile("InstalledWorld%WORLDNUM%=([^\u0000\u007f\r\n]+)");
   private static final Pattern NO_WORLDS = Pattern.compile("You can't install [^\u0000]*");

   private WisePackage() {
   }

   /** A Wise package: a PE whose first archive entry is the unnamed script (flag 0x8000). */
   static boolean is(byte[] d) {
      if (d.length < 64 || d[0] != 'M' || d[1] != 'Z') {
         return false;
      }
      int o = indexOf(d, new byte[]{'P', 'K', 3, 4}, 0);
      return o > 0 && o + 30 <= d.length && (u16(d, o + 6) & 0x8000) != 0 && u16(d, o + 26) == 0;
   }

   /** Installs the package into mainDir; returns the world name. */
   static String install(File pkg, File mainDir, PrintStream log) throws IOException {
      byte[] d = Files.readAllBytes(pkg.toPath());
      int o = indexOf(d, new byte[]{'P', 'K', 3, 4}, 0);
      if (!is(d)) {
         throw new IOException(pkg + ": not a Wise package");
      }
      String script = new String(inflate(d, o + 30 + u16(d, o + 26) + u16(d, o + 28), (int) u32(d, o + 18), (int) u32(d, o + 22)), "ISO-8859-1");
      Matcher m = WORLDDIR.matcher(script);
      if (!m.find()) {
         throw new IOException(pkg + ": the script does not define WORLDDIR");
      }
      String world = m.group(1);
      List<String> dests = new ArrayList<String>();
      Matcher dm = DEST.matcher(script);
      while (dm.find()) {
         if (!dm.group(1).isEmpty()) {
            dests.add(dm.group(1));
         }
      }
      File ini = GdkUp.child(mainDir, "worlds.ini");
      if (script.contains("UpgradeServer") && WinIni.get(ini, "Gamma", "UpgradeServer", "").isEmpty()) {
         Matcher nw = NO_WORLDS.matcher(script);
         throw new IOException(nw.find() ? nw.group() : "Worlds Not Installed");
      }
      File worldDir = GdkUp.child(mainDir, world);
      int j = 0;
      int n = 0;
      for (Entry e : entries(d)) {
         if (isRuntime(e.name)) {
            continue;
         }
         if (j >= dests.size() || !baseName(dests.get(j)).equalsIgnoreCase(baseName(e.name))) {
            throw new IOException(pkg + ": the entry " + e.name + " has no destination in the script ("
               + (j < dests.size() ? dests.get(j) : "no more destinations") + ")");
         }
         File to = new File(worldDir, dests.get(j).replace('\\', '/'));
         j++;
         File parent = to.getParentFile();
         if (!parent.isDirectory() && !parent.mkdirs()) {
            throw new IOException("cannot create " + parent);
         }
         byte[] data = e.method == 0 ? slice(d, e.dataOffset(d), e.csize) : inflate(d, e.dataOffset(d), e.csize, e.usize);
         OutputStream out = new FileOutputStream(to);
         try {
            out.write(data);
         } finally {
            out.close();
         }
         to.setLastModified(e.time);
         n++;
      }
      log.println("[gdkup] " + pkg.getName() + ": " + n + " files in " + worldDir);
      Matcher im = INI_WORLD.matcher(script);
      if (im.find()) {
         register(ini, im.group(1), script.contains("MaxInstalledWorlds=%WORLDNUM%"), log);
      }
      return world;
   }

   /** The [InstalledWorlds] block of the scripts. */
   static void register(File ini, String world, boolean raiseMax, PrintStream log) throws IOException {
      int num = 0;
      while (true) {
         String cur = WinIni.get(ini, "InstalledWorlds", "InstalledWorld" + num, "");
         if (cur.isEmpty() || cur.equalsIgnoreCase(world)) {
            break;
         }
         num++;
      }
      if (raiseMax && num > atoi(WinIni.get(ini, "InstalledWorlds", "MaxInstalledWorlds", ""))) {
         WinIni.put(ini, "InstalledWorlds", "MaxInstalledWorlds", Integer.toString(num));
      }
      WinIni.put(ini, "InstalledWorlds", "InstalledWorld" + num, world);
      log.println("[gdkup] worlds.ini: InstalledWorld" + num + "=" + world);
   }

   private static int atoi(String s) {
      try {
         return Integer.parseInt(s.trim());
      } catch (NumberFormatException e) {
         return 0;
      }
   }

   private static boolean isRuntime(String name) {
      for (String r : RUNTIME) {
         if (r.equalsIgnoreCase(baseName(name))) {
            return true;
         }
      }
      return false;
   }

   private static String baseName(String p) {
      String s = p.replace('\\', '/');
      return s.substring(s.lastIndexOf('/') + 1);
   }

   /** One entry of the central directory. */
   private static final class Entry {
      String name;
      int method;
      int csize;
      int usize;
      int local;
      long time;

      int dataOffset(byte[] d) throws IOException {
         if (local < 0 || local + 30 > d.length || u32(d, local) != 0x04034b50L) {
            throw new IOException("broken local header: " + name);
         }
         return local + 30 + u16(d, local + 26) + u16(d, local + 28);
      }
   }

   /** The central directory, in its order (EOCD searched from the end). */
   private static List<Entry> entries(byte[] d) throws IOException {
      int eocd = -1;
      for (int i = d.length - 22; i >= Math.max(0, d.length - 65557); i--) {
         if (u32(d, i) == 0x06054b50L) {
            eocd = i;
            break;
         }
      }
      if (eocd < 0) {
         throw new IOException("no central directory");
      }
      int count = u16(d, eocd + 10);
      int p = (int) u32(d, eocd + 16);
      List<Entry> out = new ArrayList<Entry>();
      for (int k = 0; k < count; k++) {
         if (p + 46 > d.length || u32(d, p) != 0x02014b50L) {
            throw new IOException("broken central directory at " + p);
         }
         Entry e = new Entry();
         e.method = u16(d, p + 10);
         e.time = dosTime(u16(d, p + 12), u16(d, p + 14));
         e.csize = (int) u32(d, p + 20);
         e.usize = (int) u32(d, p + 24);
         int nl = u16(d, p + 28);
         int xl = u16(d, p + 30);
         int cl = u16(d, p + 32);
         e.local = (int) u32(d, p + 42);
         e.name = new String(d, p + 46, nl, "ISO-8859-1");
         if (e.method != 0 && e.method != 8) {
            throw new IOException(e.name + ": compression method " + e.method);
         }
         out.add(e);
         p += 46 + nl + xl + cl;
      }
      return out;
   }

   private static long dosTime(int time, int date) {
      Calendar c = Calendar.getInstance();
      c.clear();
      c.set(1980 + (date >> 9), ((date >> 5) & 15) - 1, date & 31, time >> 11, (time >> 5) & 63, (time & 31) * 2);
      return c.getTimeInMillis();
   }

   static byte[] inflate(byte[] d, int off, int csize, int usize) throws IOException {
      Inflater inf = new Inflater(true);
      inf.setInput(d, off, Math.min(csize, d.length - off));
      ByteArrayOutputStream out = new ByteArrayOutputStream(Math.max(usize, 64));
      byte[] buf = new byte[65536];
      try {
         while (!inf.finished()) {
            int k = inf.inflate(buf);
            if (k == 0 && (inf.needsInput() || inf.needsDictionary())) {
               break;
            }
            out.write(buf, 0, k);
         }
      } catch (DataFormatException e) {
         throw new IOException("broken deflate: " + e.getMessage());
      } finally {
         inf.end();
      }
      if (usize >= 0 && out.size() != usize) {
         throw new IOException("inflated size " + out.size() + " instead of " + usize);
      }
      return out.toByteArray();
   }

   private static byte[] slice(byte[] d, int off, int len) {
      byte[] out = new byte[len];
      System.arraycopy(d, off, out, 0, len);
      return out;
   }

   static int indexOf(byte[] d, byte[] pat, int from) {
      outer:
      for (int i = Math.max(0, from); i <= d.length - pat.length; i++) {
         for (int k = 0; k < pat.length; k++) {
            if (d[i + k] != pat[k]) {
               continue outer;
            }
         }
         return i;
      }
      return -1;
   }

   static int u16(byte[] d, int o) {
      return (d[o] & 255) | (d[o + 1] & 255) << 8;
   }

   static long u32(byte[] d, int o) {
      return (d[o] & 255L) | (d[o + 1] & 255L) << 8 | (d[o + 2] & 255L) << 16 | (d[o + 3] & 255L) << 24;
   }
}

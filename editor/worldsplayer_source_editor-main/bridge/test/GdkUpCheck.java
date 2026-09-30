import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.PrintStream;
import java.lang.reflect.Method;
import java.nio.file.Files;
import java.util.Arrays;

import NET.worlds.core.GdkUp;

/**
 * gdkup.exe in Java (NET.worlds.core.GdkUp) with its two installers:
 * WisePackage (assets/packages/Meteor25.exe) and NsisPackage
 * (assets/packages/GroundZero37-40.exe), plus WinIni and NSIS's atoi. The
 * expected values were read by hand in the packages' scripts
 * (assets/packages/README.md) and in gdkup_exe/00401d52 and 00401e75.
 * Exits with 1 if something fails.
 */
public class GdkUpCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   static final String CRLF = "\r\n";

   static void write(File f, String s) throws Exception {
      f.getParentFile().mkdirs();
      Files.write(f.toPath(), s.getBytes("ISO-8859-1"));
   }

   static String read(File f) throws Exception {
      return new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
   }

   static Object[] gdkup(File home, String... args) {
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      PrintStream log = new PrintStream(bytes, true);
      int rc = GdkUp.run(args, home, log);
      String out = bytes.toString();
      System.out.print(out.replaceAll("(?m)^", "      "));
      return new Object[]{rc, out};
   }

   static Object call(String cls, String name, Class<?>[] types, Object... args) throws Exception {
      Method m = Class.forName("NET.worlds.core." + cls).getDeclaredMethod(name, types);
      m.setAccessible(true);
      return m.invoke(null, args);
   }

   static File fresh(File tmp, String name) {
      File d = new File(tmp, name);
      d.mkdirs();
      return d;
   }

   public static void main(String[] a) throws Exception {
      File meteor = new File("assets/packages/Meteor25.exe");
      File gz = new File("assets/packages/GroundZero37-40.exe");
      if (!meteor.isFile() || !gz.isFile()) {
         System.out.println("FAIL assets/packages/*.exe missing (run from the repo root)");
         System.exit(1);
      }
      File tmp = Files.createTempDirectory("gdkupcheck").toFile();

      // --- NSIS myatoi and WinIni, by hand ---
      Class<?>[] S = {String.class};
      check((Integer) call("NsisPackage", "atoi", S, "0x1F") == 31, "atoi 0x1F = 31");
      check((Integer) call("NsisPackage", "atoi", S, "017") == 15, "atoi 017 = 15 (octal)");
      check((Integer) call("NsisPackage", "atoi", S, "-12abc") == -12, "atoi -12abc = -12");
      check((Integer) call("NsisPackage", "atoi", S, "40\r\n") == 40, "atoi 40\\r\\n = 40");
      File ini = new File(tmp, "w.ini");
      write(ini, "[Gamma]\r\nUpgradeServer = http://x/3DCDup/ \r\n\r\n[gamma]\r\nUpgradeServer=segunda\r\n[Other]\r\nk=v\r\n");
      Class<?>[] G = {File.class, String.class, String.class, String.class};
      check("http://x/3DCDup/".equals(call("WinIni", "get", G, ini, "GAMMA", "upgradeserver", "def")),
         "WinIni.get: case-insensitive, spaces stripped, the first section with the name");
      check("def".equals(call("WinIni", "get", G, ini, "Gamma", "nada", "def")), "WinIni.get: missing key -> def");
      call("WinIni", "put", G, ini, "Other", "k", "w");
      call("WinIni", "put", G, ini, "Gamma", "Nueva", "1");
      call("WinIni", "put", G, ini, "Seccion", "a", "b");
      check(read(ini).equals("[Gamma]\r\nUpgradeServer = http://x/3DCDup/ \r\nNueva=1\r\n\r\n[gamma]\r\nUpgradeServer=segunda\r\n"
            + "[Other]\r\nk=w\r\n[Seccion]\r\na=b\r\n"),
         "WinIni.put: changes the value on its line, new key after the last line of its section, new section at the end, CRLF");
      File lf = new File(tmp, "lf.ini");
      call("WinIni", "put", G, lf, "S", "k", "v");
      check(read(lf).equals("[S]\r\nk=v\r\n"), "WinIni.put: new file with CRLF");
      write(lf, "[S]\nk=v\n");
      call("WinIni", "put", G, lf, "S", "j", "w");
      check(read(lf).equals("[S]\nk=v\nj=w\n"), "WinIni.put: a file with LF stays with LF");

      // --- a full run: Wise install, NSIS 37->40, restart ---
      File home = fresh(tmp, "home");
      write(new File(home, "worlds.ini"), "[Gamma]" + CRLF + "UpgradeServer=http://127.0.0.1:1/3DCDup/" + CRLF + CRLF
         + "[InstalledWorlds]" + CRLF + "MaxInstalledWorlds=1" + CRLF + "InstalledWorld0=GroundZero" + CRLF
         + "InstalledWorld1=AvatarGallery" + CRLF);
      write(new File(home, "GroundZero/ver.txt"), "37" + CRLF);
      write(new File(home, "GroundZero/custom.wse"), "x");
      write(new File(home, "GroundZero/custup.wse"), "x");
      write(new File(home, "GroundZero/groundzero.music"), "");
      write(new File(home, "GroundZero/groundzero.world"), "old");
      write(new File(home, "GroundZero/tex/WS_FTP.LOG"), "log");
      write(new File(home, "GroundZero/keep.txt"), "keep");
      Files.copy(meteor.toPath(), new File(fresh(home, "Meteor"), "Meteor25.exe").toPath());
      Files.copy(gz.toPath(), new File(home, "GroundZero/GroundZero37-40.exe").toPath());
      write(new File(home, "updates.lst"), "Meteor\\Meteor25.exe" + CRLF + "GroundZero\\GroundZero37-40.exe" + CRLF
         + "run.exe world:restart" + CRLF);
      Object[] r = gdkup(home, "updates.lst", "4242");
      check((Integer) r[0] == GdkUp.RESTART && ((String) r[1]).contains("[gdkup] reinicio: world:restart"),
         "three lines: ends by asking for the restart with world:restart (code 10)");
      String[] got = new File(home, "Meteor").list();
      Arrays.sort(got);
      check(got.length == 10 && Arrays.asList(got).contains("meteor.world") && !Arrays.asList(got).contains("Meteor25.exe"),
         "Wise: Meteor installed (10 entries above) and its package deleted");
      check(read(new File(home, "worlds.ini")).endsWith("MaxInstalledWorlds=2" + CRLF + "InstalledWorld0=GroundZero" + CRLF
            + "InstalledWorld1=AvatarGallery" + CRLF + "InstalledWorld2=Meteor" + CRLF),
         "Wise: first free slot InstalledWorld2=Meteor and MaxInstalledWorlds 1 -> 2, with CRLF");
      check(read(new File(home, "GroundZero/ver.txt")).equals("40" + CRLF), "NSIS: ver.txt 37 -> 40");
      check(new File(home, "GroundZero/groundzero.world").length() == 205746, "NSIS: new groundzero.world (205746 bytes)");
      check(!new File(home, "GroundZero/custom.wse").exists() && !new File(home, "GroundZero/custup.wse").exists()
            && !new File(home, "GroundZero/groundzero.music").exists() && !new File(home, "GroundZero/tex/WS_FTP.LOG").exists()
            && new File(home, "GroundZero/keep.txt").isFile(),
         "NSIS: deletes the five old ones (case-insensitive; wav\\ws_ftp.log was not there) and nothing else");
      check(!new File(home, "GroundZero/GroundZero37-40.exe").exists(), "NSIS: package deleted");

      // --- the upgrade on another version: the installer stops, gdkup goes on ---
      File h2 = fresh(tmp, "h2");
      write(new File(h2, "worlds.ini"), "[Gamma]" + CRLF + "UpgradeServer=x" + CRLF);
      write(new File(h2, "GroundZero/ver.txt"), "36" + CRLF);
      write(new File(h2, "GroundZero/groundzero.world"), "old");
      Files.copy(gz.toPath(), new File(h2, "GroundZero/GroundZero37-40.exe").toPath());
      write(new File(h2, "updates.lst"), "GroundZero\\GroundZero37-40.exe" + CRLF + "run.exe world:restart" + CRLF);
      r = gdkup(h2, "updates.lst", "1");
      check(((String) r[1]).contains("This update requires world version 37, but found 36. Aborting!"),
         "version 36: the installer's message");
      check(read(new File(h2, "GroundZero/groundzero.world")).equals("old") && read(new File(h2, "GroundZero/ver.txt")).equals("36" + CRLF),
         "version 36: touches nothing");
      check((Integer) r[0] == GdkUp.RESTART && !new File(h2, "GroundZero/GroundZero37-40.exe").exists(),
         "version 36: like gdkup.exe (it does not read the exit code) it deletes the package and goes on to the restart");

      // --- Wise without [Gamma] UpgradeServer ---
      File h3 = fresh(tmp, "h3");
      write(new File(h3, "worlds.ini"), "[InstalledWorlds]" + CRLF + "InstalledWorld0=GroundZero" + CRLF);
      Files.copy(meteor.toPath(), new File(fresh(h3, "Meteor"), "Meteor25.exe").toPath());
      write(new File(h3, "updates.lst"), "Meteor\\Meteor25.exe" + CRLF);
      r = gdkup(h3, "updates.lst", "1");
      check((Integer) r[0] == 0 && ((String) r[1]).contains("You can't install") && new File(h3, "Meteor").list().length == 0,
         "Wise without UpgradeServer: \"You can't install...\", nothing installed, package deleted, normal end (0)");

      // --- lines that cannot start, and bad scripts ---
      File h4 = fresh(tmp, "h4");
      write(new File(h4, "updates.lst"), "Nada\\Nada1.exe" + CRLF + "run.exe world:restart" + CRLF);
      r = gdkup(h4, "updates.lst", "1");
      check((Integer) r[0] == 2 && ((String) r[1]).contains("Internal error - can't execute Nada\\Nada1.exe"),
         "package that does not exist: Internal error - can't execute and end (2), no restart");
      write(new File(h4, "Nada/Nada1.exe"), "no soy un exe");
      r = gdkup(h4, "updates.lst", "1");
      check((Integer) r[0] == 2, "file without MZ: does not start either (2)");
      write(new File(h4, "updates.lst"), "xdelta patch GroundZero\\x.xdz GroundZero\\a GroundZero\\b" + CRLF + "run.exe world:restart" + CRLF);
      write(new File(h4, "GroundZero/x.xdz"), "%XDZ");
      r = gdkup(h4, "updates.lst", "1");
      check((Integer) r[0] == GdkUp.RESTART && !new File(h4, "GroundZero/x.xdz").exists(),
         "xdelta (not supported): counted as finished, the patch is deleted and it goes on");
      write(new File(h4, "vacio.lst"), "");
      check((Integer) gdkup(h4, "vacio.lst", "1")[0] == 1, "empty script: Script file is not valid (1)");
      check((Integer) gdkup(h4, "noexiste.lst", "1")[0] == 1, "script that does not exist (1)");

      System.out.println(fails == 0 ? "GdkUpCheck: all OK" : "GdkUpCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

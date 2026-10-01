import NET.worlds.core.NativeInput;
import NET.worlds.core.NativeUiStartup;
import java.io.File;

/**
 * Startup (0x004098b0 / FUN_00409ce0 / 0x00409e70 / 0x00409e80): the
 * single instance with two real JVMs in a temporary directory of their own,
 * and the volume serial forced by a property.
 *
 * Internal use: "UiStartupCheck second URL AUTOPLAY" is the second instance.
 */
public class UiStartupCheck {
   static int fails = 0;
   static final String CLASSPATH = System.getProperty("java.class.path");

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   static int second(File dir, String url, boolean autoplay) throws Exception {
      String java = System.getProperty("java.home") + File.separator + "bin" + File.separator + "java";
      // absolute classpath: the second JVM starts with another user.dir
      StringBuilder cp = new StringBuilder();
      for (String e : CLASSPATH.split(File.pathSeparator)) {
         cp.append(cp.length() == 0 ? "" : File.pathSeparator).append(new File(e).getAbsolutePath());
      }
      Process p = new ProcessBuilder(java, "-Djava.awt.headless=true", "-Duser.dir=" + dir.getPath(), "-cp", cp.toString(),
         "UiStartupCheck", "second", url, String.valueOf(autoplay)).inheritIO().start();
      return p.waitFor();
   }

   public static void main(String[] a) throws Exception {
      if (a.length == 3 && a[0].equals("second")) {
         long t0 = System.currentTimeMillis();
         boolean r = NativeUiStartup.synchronizeStartup(a[1], Boolean.parseBoolean(a[2]));
         System.out.println("  second instance: synchronizeStartup = " + r + " in " + (System.currentTimeMillis() - t0) + " ms");
         System.exit(r ? 1 : 0);
      }
      File dir = new File(System.getProperty("java.io.tmpdir"), "openworlds-UiStartupCheck-" + System.nanoTime()).getCanonicalFile();
      dir.mkdirs();
      System.setProperty("user.dir", dir.getPath());

      System.setProperty("openworlds.volumeSerial", "0x1A2B3C4D");
      check(NativeUiStartup.volumeInfo() == 0, "getVolumeInfo before computeVolumeInfo = 0 (DAT_0049fa6c in .bss)");
      NativeUiStartup.computeVolumeInfo(null);
      check(NativeUiStartup.volumeInfo() == 0x1A2B3C4D, "forced serial 0x1A2B3C4D");
      System.clearProperty("openworlds.volumeSerial");
      NativeUiStartup.computeVolumeInfo(null);
      System.out.println("  volume serial of " + dir + " (unix:dev) = 0x" + Integer.toHexString(NativeUiStartup.volumeInfo()));

      check(NativeUiStartup.synchronizeStartup("home:A.world", false), "first instance -> true");
      check(second(dir, "home:B.world", true) == 0, "second with autoplay -> false instantly");
      check(NativeUiStartup.instanceReady() == 1, "FUN_00409ce0 publishes the HWND and releases");
      check(NativeUiStartup.instanceReady() == 0, "FUN_00409ce0 the second time -> 0");
      int before = NativeInput.eventCount();
      check(second(dir, "home:GroundZero/groundzero.world", false) == 0, "second without autoplay -> false after sending the URL");
      Thread.sleep(300);
      check(NativeInput.eventCount() == before + 1, "the first one queues a teleport (record type 10)");
      System.out.println(fails == 0 ? "UiStartupCheck: all OK" : "UiStartupCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

import NET.worlds.core.NativeInput;
import NET.worlds.core.NativeUiStartup;
import java.io.File;

/**
 * Startup (0x004098b0 / FUN_00409ce0 / 0x00409e70 / 0x00409e80): la
 * instancia unica con dos JVM reales en un directorio temporal propio, y
 * la serie del volumen forzada por propiedad.
 *
 * Uso interno: "UiStartupCheck segunda URL AUTOPLAY" es la segunda instancia.
 */
public class UiStartupCheck {
   static int fails = 0;
   static final String CLASSPATH = System.getProperty("java.class.path");

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   static int second(File dir, String url, boolean autoplay) throws Exception {
      String java = System.getProperty("java.home") + File.separator + "bin" + File.separator + "java";
      // classpath absoluto: la segunda JVM arranca con otro user.dir
      StringBuilder cp = new StringBuilder();
      for (String e : CLASSPATH.split(File.pathSeparator)) {
         cp.append(cp.length() == 0 ? "" : File.pathSeparator).append(new File(e).getAbsolutePath());
      }
      Process p = new ProcessBuilder(java, "-Djava.awt.headless=true", "-Duser.dir=" + dir.getPath(), "-cp", cp.toString(),
         "UiStartupCheck", "segunda", url, String.valueOf(autoplay)).inheritIO().start();
      return p.waitFor();
   }

   public static void main(String[] a) throws Exception {
      if (a.length == 3 && a[0].equals("segunda")) {
         long t0 = System.currentTimeMillis();
         boolean r = NativeUiStartup.synchronizeStartup(a[1], Boolean.parseBoolean(a[2]));
         System.out.println("  segunda instancia: synchronizeStartup = " + r + " en " + (System.currentTimeMillis() - t0) + " ms");
         System.exit(r ? 1 : 0);
      }
      File dir = new File(System.getProperty("java.io.tmpdir"), "freeworlds-UiStartupCheck-" + System.nanoTime()).getCanonicalFile();
      dir.mkdirs();
      System.setProperty("user.dir", dir.getPath());

      System.setProperty("freeworlds.volumeSerial", "0x1A2B3C4D");
      check(NativeUiStartup.volumeInfo() == 0, "getVolumeInfo antes de computeVolumeInfo = 0 (DAT_0049fa6c en .bss)");
      NativeUiStartup.computeVolumeInfo(null);
      check(NativeUiStartup.volumeInfo() == 0x1A2B3C4D, "serie forzada 0x1A2B3C4D");
      System.clearProperty("freeworlds.volumeSerial");
      NativeUiStartup.computeVolumeInfo(null);
      System.out.println("  serie del volumen de " + dir + " (unix:dev) = 0x" + Integer.toHexString(NativeUiStartup.volumeInfo()));

      check(NativeUiStartup.synchronizeStartup("home:A.world", false), "primera instancia -> true");
      check(second(dir, "home:B.world", true) == 0, "segunda con autoplay -> false al instante");
      check(NativeUiStartup.instanceReady() == 1, "FUN_00409ce0 publica el HWND y libera");
      check(NativeUiStartup.instanceReady() == 0, "FUN_00409ce0 por segunda vez -> 0");
      int before = NativeInput.eventCount();
      check(second(dir, "home:GroundZero/groundzero.world", false) == 0, "segunda sin autoplay -> false tras mandar la URL");
      Thread.sleep(300);
      check(NativeInput.eventCount() == before + 1, "la primera encola un teletransporte (registro tipo 10)");
      System.out.println(fails == 0 ? "UiStartupCheck: todo OK" : "UiStartupCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

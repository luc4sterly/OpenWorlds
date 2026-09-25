import NET.worlds.core.IniFile;

import java.io.File;
import java.lang.reflect.Constructor;
import java.nio.file.Files;

/**
 * Mock de IniFile (apply_mock.sh) frente a GetPrivateProfileString /
 * WritePrivateProfileString de kernel32: seccion y clave sin distinguir
 * mayusculas, y escritura inmediata al fichero (si la clave existe cambia
 * solo el valor; si no, se anade al final de su seccion; si no hay seccion,
 * se crea al final), conservando los finales CRLF.
 */
public class IniPersistCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   static IniFile open(File f, String section) throws Exception {
      Constructor<IniFile> c = IniFile.class.getDeclaredConstructor(String.class, String.class);
      c.setAccessible(true);
      return c.newInstance(f.getAbsolutePath(), section);
   }

   public static void main(String[] a) throws Exception {
      File dir = Files.createTempDirectory("fw-ini").toFile();
      File f = new File(dir, "worlds.ini");
      Files.write(f.toPath(), "[Gamma]\r\nLogFile=Gamma.Log\r\n\r\n[127.0.0.1:6650]\r\nUser0=FWTestA\r\n".getBytes("ISO-8859-1"));

      IniFile g = open(f, "gamma");
      check("Gamma.Log".equals(g.getIniString("logfile", "")), "getIniString(\"logfile\") en [Gamma] con LogFile= -> \"Gamma.Log\"");

      IniFile s = open(f, "127.0.0.1:6650");
      s.setIniString("password0", "xyz");
      s.setIniString("USER0", "FWTestB");
      g.setIniInt("netdebug", 4);
      open(f, "Nueva").setIniString("k", "v");

      String out = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
      String want = "[Gamma]\r\nLogFile=Gamma.Log\r\nnetdebug=4\r\n\r\n[127.0.0.1:6650]\r\nUser0=FWTestB\r\npassword0=xyz\r\n[Nueva]\r\nk=v\r\n";
      check(want.equals(out), "fichero tras escribir = " + want.replace("\r\n", "|") + " (sale " + out.replace("\r\n", "|") + ")");

      // lectura desde cero (otro proceso): lo escrito sigue ahi
      java.lang.reflect.Field cache = IniFile.class.getDeclaredField("cache");
      cache.setAccessible(true);
      ((java.util.Map<?, ?>) cache.get(null)).clear();
      check("xyz".equals(open(f, "127.0.0.1:6650").getIniString("Password0", "")), "Password0 persiste en disco");
      check(4 == open(f, "GAMMA").getIniInt("NetDebug", 0), "netdebug persiste en disco (seccion GAMMA)");

      f.delete();
      dir.delete();
      System.out.println(fails == 0 ? "IniPersistCheck: OK" : "IniPersistCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

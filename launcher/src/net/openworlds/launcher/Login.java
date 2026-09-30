package net.openworlds.launcher;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.file.Files;
import java.util.concurrent.ThreadLocalRandom;

/**
 * Fills in the game's own sign-in for a world server, so the player only
 * presses "Sign In": the 2004 client keeps its known users per server in
 * worlds.ini, section [host:port], as User0 and Password0 (the password
 * encrypted by Console.encode, which the bridge translates from gamma.dll).
 */
final class Login {
   private Login() {
   }

   /** Writes the user (and, if given, the password) for {@code server} into the game copy's worlds.ini. */
   static void prefill(Layout l, String server, String user, String password, Log log) {
      if (server == null || server.trim().isEmpty() || user == null || user.trim().isEmpty()) {
         return;
      }
      String section = server.trim();
      File ini = Install.findNoCase(l.workDir, "worlds.ini");
      if (ini == null) {
         ini = new File(l.workDir, "worlds.ini");
      }
      try {
         Install.setKey(ini, section, "User0", user.trim());
         boolean remembered = false;
         if (password != null && !password.isEmpty()) {
            String enc = encodePassword(l, password);
            if (enc != null) {
               Install.setKey(ini, section, "Password0", enc);
               remembered = true;
            }
         } else {
            remembered = decodePassword(l, Install.getKey(ini, section, "Password0")) != null;
         }
         log.line("[launcher] sign-in on " + section + " as " + user.trim()
            + (remembered ? ", password filled in: press Sign In" : ": type your password in the game"));
      } catch (IOException e) {
         log.line("[launcher] could not prepare the sign-in in " + ini + ": " + e);
      }
   }

   /**
    * A name for a player who typed none: the system account's, with what
    * FriendsListPart.isValidUserName accepts (letters, digits, _ and -, 2 to
    * 16), or "Player".
    */
   static String defaultUser() {
      StringBuilder b = new StringBuilder();
      for (char c : System.getProperty("user.name", "").toCharArray()) {
         if (b.length() < 16 && (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_' || c == '-')) {
            b.append(c);
         }
      }
      return b.length() >= 2 ? b.toString() : "Player";
   }

   /**
    * Console.encode(plain) as this machine's client will decode it: the
    * bridge's NativeUiConsole.encrypt (gamma.dll 0x0040b7f0), loaded from
    * worldsplayer.jar rather than copied, with {@link #volumeSerial}, in hex.
    * null when the bridge is not there.
    */
   static String encodePassword(Layout l, String plain) {
      Object c = cipher(l, "encrypt", new Class<?>[]{String.class, int.class, int.class},
         plain, ThreadLocalRandom.current().nextInt(256), volumeSerial(l.workDir));
      if (!(c instanceof String)) {
         return null;
      }
      StringBuilder hex = new StringBuilder();
      for (char ch : ((String) c).toCharArray()) {
         String h = Integer.toHexString(ch);
         hex.append(h.length() == 1 ? "0" : "").append(h);
      }
      return hex.toString();
   }

   /** Console.decode: the password a Password0 value gives this machine's client, or null. */
   static String decodePassword(Layout l, String hex) {
      if (hex == null || hex.isEmpty() || hex.length() % 2 != 0) {
         return null;
      }
      char[] c = new char[hex.length() / 2];
      try {
         for (int i = 0; i < c.length; i++) {
            c[i] = (char) Integer.parseInt(hex.substring(2 * i, 2 * i + 2), 16);
         }
      } catch (NumberFormatException e) {
         return null;
      }
      Object p = cipher(l, "decrypt", new Class<?>[]{String.class, int.class}, new String(c), volumeSerial(l.workDir));
      return p instanceof String && !((String) p).isEmpty() ? (String) p : null;
   }

   private static Object cipher(Layout l, String method, Class<?>[] types, Object... args) {
      File jar = l.jar("worldsplayer.jar");
      if (!jar.isFile()) {
         return null;
      }
      try (URLClassLoader cl = new URLClassLoader(new URL[]{jar.toURI().toURL()}, null)) {
         return cl.loadClass("NET.worlds.core.NativeUiConsole").getMethod(method, types).invoke(null, args);
      } catch (ReflectiveOperationException | IOException | RuntimeException | LinkageError e) {
         return null;
      }
   }

   /**
    * The volume serial (DAT_0049fa6c) the bridge gives the client, whose
    * working directory is dir: NativeUiStartup.computeVolumeInfo takes
    * unix:dev of it, 0 without the unix view (Windows). Worked out here, not
    * called: on failure it ends the JVM with gamma.dll's assertion.
    */
   static int volumeSerial(File dir) {
      try {
         return (int) ((Number) Files.getAttribute(dir.toPath(), "unix:dev")).longValue();
      } catch (UnsupportedOperationException | IllegalArgumentException | IOException e) {
         return 0;
      }
   }
}

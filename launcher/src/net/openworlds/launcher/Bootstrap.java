package net.openworlds.launcher;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;

/**
 * Hands the start over to a newer OpenWorlds downloaded by the {@link Updater}.
 *
 * <p>The bundled launcher looks at {@code <data>/app/current}; if it names a
 * complete version newer than itself, that version's launcher jar is loaded
 * in a class loader of its own (parent: the platform loader, so none of the
 * bundled launcher's classes leak in) and its {@code main} runs with the same
 * arguments, in this same JVM: same Java, same Dock icon and process. The
 * newer launcher finds its own worldsplayer.jar and game data next to its jar
 * (the portable layout); {@code openworlds.bundledLib} tells it where the
 * app's own files are (e.g. a bundled whirl). A version that fails to start is
 * written to {@code app/bad} and skipped from then on.
 */
final class Bootstrap {
   private Bootstrap() {
   }

   /**
    * Runs the newest downloaded version instead of this one; true if it took
    * over. {@code restart}: the window asks for it after an update, so a
    * launcher that was itself handed the start may hand it on.
    */
   static boolean handOff(String[] args, boolean restart) {
      if (Arrays.asList(args).contains("--smoke") || Arrays.asList(args).contains("--no-update")) {
         return false;
      }
      if (!restart && System.getProperty("openworlds.handedOff") != null) {
         return false;
      }
      Version own = Updater.running();
      if (own == null) {
         return false;
      }
      File root = new File(Layout.dataDir(), "app");
      Version next = Updater.installed(root);
      if (next == null || next.compareTo(own) <= 0 || isBad(root, next)) {
         return false;
      }
      File dir = new File(root, next.text);
      File jar = new File(dir, "lib/openworlds-launcher.jar");
      if (!new File(dir, ".complete").isFile() || !jar.isFile() || !new File(dir, "lib/worldsplayer.jar").isFile()
         || !new File(dir, "game/assets/WorldsPlayer/worlds.ini").isFile()) {
         return false;
      }
      String before = System.getProperty("openworlds.handedOff");
      try {
         System.setProperty("openworlds.handedOff", own.text);
         if (System.getProperty("openworlds.bundledLib") == null) {
            File lib = Layout.codeDirOrNull();
            if (lib != null) {
               System.setProperty("openworlds.bundledLib", lib.getPath());
            }
         }
         URLClassLoader cl = new URLClassLoader("openworlds-" + next.text, new URL[]{jar.toURI().toURL()},
            ClassLoader.getPlatformClassLoader());
         Class<?> main = Class.forName("net.openworlds.launcher.Launcher", true, cl);
         Thread.currentThread().setContextClassLoader(cl);
         System.err.println("[launcher] OpenWorlds " + own + " hands the start over to the downloaded version " + next);
         main.getMethod("main", String[].class).invoke(null, (Object) args);
         return true;
      } catch (InvocationTargetException e) {
         markBad(root, next, e.getCause(), before);
         return false;
      } catch (ReflectiveOperationException | IOException | RuntimeException | LinkageError e) {
         markBad(root, next, e, before);
         return false;
      }
   }

   static boolean isBad(File root, Version v) {
      File f = new File(root, "bad");
      try {
         return f.isFile() && new String(Files.readAllBytes(f.toPath()), StandardCharsets.UTF_8).lines()
            .anyMatch(l -> l.trim().equals(v.text));
      } catch (IOException e) {
         return false;
      }
   }

   private static void markBad(File root, Version v, Throwable why, String handedOffBefore) {
      System.err.println("[launcher] the downloaded version " + v + " does not start (" + why + "); using the bundled one");
      try {
         Files.write(new File(root, "bad").toPath(), (v.text + "\n").getBytes(StandardCharsets.UTF_8),
            StandardOpenOption.CREATE, StandardOpenOption.APPEND);
      } catch (IOException e) {
         // no writable data folder: it will be tried again next time
      }
      if (handedOffBefore == null) {
         System.clearProperty("openworlds.handedOff");
      } else {
         System.setProperty("openworlds.handedOff", handedOffBefore);
      }
   }
}

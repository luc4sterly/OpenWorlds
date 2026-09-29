package net.openworlds.launcher;

import java.io.File;
import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

/**
 * Where everything lives, for the three ways OpenWorlds is run:
 *
 * <ul>
 * <li>app image of jpackage: the jars and {@code game/} next to each other
 *     in the image's {@code app/} directory;</li>
 * <li>portable zip: {@code OpenWorlds/lib/*.jar} and {@code OpenWorlds/game/};</li>
 * <li>repository checkout ({@code tools/build-dist.sh --dev} or an IDE): the
 *     game data is the repo's {@code assets/}.</li>
 * </ul>
 *
 * {@code game/} mirrors the repo's {@code assets/}: {@code assets/WorldsPlayer}
 * (the 2004 install, read-only template) and
 * {@code assets/gammatutorial-samples/base-avatars} (served by the local
 * upgrade server under /3DCDup/avatar/, see UpgradeServer).
 * -Dopenworlds.game=DIR (a directory with {@code assets/} inside) and
 * -Dopenworlds.data=DIR override the lookups.
 */
final class Layout {
   final File libDir;
   final File gameRoot;
   final File template;
   final File baseAvatars;
   final File dataDir;
   final File workDir;
   final File logDir;
   final File settingsFile;

   Layout(File libDir, File gameRoot, File dataDir) {
      this.libDir = libDir;
      this.gameRoot = gameRoot;
      this.template = new File(gameRoot, "assets/WorldsPlayer");
      this.baseAvatars = new File(gameRoot, "assets/gammatutorial-samples/base-avatars");
      this.dataDir = dataDir;
      this.workDir = new File(dataDir, "worldsplayer");
      this.logDir = new File(dataDir, "logs");
      this.settingsFile = new File(dataDir, "launcher.properties");
   }

   static Layout detect() throws IOException {
      File lib = codeDir();
      File game = null;
      String forced = System.getProperty("openworlds.game");
      if (forced != null) {
         game = new File(forced);
      } else {
         File[] candidates = {
            new File(lib, "game"),
            new File(lib.getParentFile(), "game"),
            lib.getParentFile(),                       // repo: build/dist-dev/lib -> ...
            lib.getParentFile().getParentFile(),
            lib.getParentFile().getParentFile() == null ? null : lib.getParentFile().getParentFile().getParentFile(),
         };
         for (File c : candidates) {
            if (c != null && new File(c, "assets/WorldsPlayer/worlds.ini").isFile()) {
               game = c;
               break;
            }
         }
      }
      if (game == null || !new File(game, "assets/WorldsPlayer").isDirectory()) {
         throw new IOException("cannot find the game data (game/assets/WorldsPlayer) next to " + lib
            + "; use -Dopenworlds.game=DIR");
      }
      return new Layout(lib.getCanonicalFile(), game.getCanonicalFile(), dataDir());
   }

   /** Directory of the launcher's jar (or class directory). */
   private static File codeDir() throws IOException {
      File f = codeSource();
      if (f == null) {
         throw new IOException("cannot tell where the launcher is");
      }
      return f.isFile() ? f.getParentFile() : f;
   }

   /** {@link #codeDir()}, or null if it cannot be known. */
   static File codeDirOrNull() {
      try {
         return codeDir();
      } catch (IOException e) {
         return null;
      }
   }

   /** The launcher's jar (or class directory), or null. */
   private static File codeSource() {
      try {
         return new File(Launcher.class.getProtectionDomain().getCodeSource().getLocation().toURI());
      } catch (URISyntaxException | SecurityException | NullPointerException | IllegalArgumentException e) {
         return null;
      }
   }

   private static java.util.jar.Attributes manifest;

   /**
    * A main attribute of the launcher jar's manifest (build-dist.sh writes
    * OpenWorlds-Commit and OpenWorlds-Update-Repo there), or null. Read from
    * the jar itself: the class path of the app has more than one manifest.
    */
   static synchronized String manifestAttribute(String name) {
      if (manifest == null) {
         manifest = new java.util.jar.Attributes();
         File jar = codeSource();
         if (jar != null && jar.isFile()) {
            try (java.util.jar.JarFile j = new java.util.jar.JarFile(jar)) {
               if (j.getManifest() != null) {
                  manifest = j.getManifest().getMainAttributes();
               }
            } catch (IOException e) {
               // no manifest: development build
            }
         }
      }
      return manifest.getValue(name);
   }

   static boolean isWindows() {
      return System.getProperty("os.name", "").toLowerCase(Locale.ROOT).startsWith("windows");
   }

   static boolean isMac() {
      return System.getProperty("os.name", "").toLowerCase(Locale.ROOT).startsWith("mac");
   }

   /** The user's data folder: the install copy, the settings, the logs and the downloaded updates. */
   static File dataDir() {
      String forced = System.getProperty("openworlds.data", System.getenv("OPENWORLDS_DATA"));
      if (forced != null && !forced.isEmpty()) {
         return new File(forced);
      }
      String home = System.getProperty("user.home");
      File dir;
      File old;
      if (isWindows()) {
         String local = System.getenv("LOCALAPPDATA");
         dir = new File(local != null ? local : home, "OpenWorlds");
         old = new File(local != null ? local : home, "FreeWorlds");
      } else if (isMac()) {
         dir = new File(home, "Library/Application Support/OpenWorlds");
         old = new File(home, "Library/Application Support/FreeWorlds");
      } else {
         String xdg = System.getenv("XDG_DATA_HOME");
         String base = xdg != null && !xdg.isEmpty() ? xdg : home + "/.local/share";
         dir = new File(base, "openworlds");
         old = new File(base, "freeworlds");
      }
      // the project used to be called FreeWorlds: its data folder (install
      // copy with the installed worlds, settings) moves over once
      if (!dir.exists() && old.isDirectory() && !old.renameTo(dir)) {
         return old;
      }
      return dir;
   }

   File jar(String name) {
      return new File(libDir, name);
   }

   /** The java launcher of the running runtime (jpackage images keep bin/java, see build-dist.sh). */
   static String javaExecutable() {
      File home = new File(System.getProperty("java.home"));
      File exe = new File(home, isWindows() ? "bin/java.exe" : "bin/java");
      return exe.isFile() ? exe.getPath() : "java";
   }

   static String version() {
      Package p = Launcher.class.getPackage();
      String v = p == null ? null : p.getImplementationVersion();
      return v == null ? "dev" : v;
   }

   /** Version and commit, for the window and the logs ("1.0.150 (65a3e83)"). */
   static String versionLong() {
      String c = manifestAttribute("OpenWorlds-Commit");
      return version() + (c == null || c.isEmpty() ? "" : " (" + c + ")");
   }

   static void deleteTree(Path p) throws IOException {
      if (!Files.exists(p)) {
         return;
      }
      try (java.util.stream.Stream<Path> s = Files.walk(p)) {
         List<Path> all = new ArrayList<>();
         s.forEach(all::add);
         java.util.Collections.reverse(all);
         for (Path q : all) {
            Files.deleteIfExists(q);
         }
      }
   }
}

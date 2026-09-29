package net.freeworlds.launcher;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.AtomicMoveNotSupportedException;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.nio.file.attribute.PosixFilePermissions;
import java.util.Properties;

/** What the launcher remembers between runs (launcher.properties in the data dir). */
final class Settings {
   /** home: URL of the world the original client opens (empty = its own start, the login screen). */
   String world = "home:GroundZero/groundzero.world";
   /** host:port of a world server, empty = no server (single-user). */
   String server = "";
   /** The last "other server" typed, kept while another choice is in use. */
   String customServer = "";
   String user = "";
   /** Ask the install's upgrade server (us1.worlds.net, LibreWorlds' mirror) for what the local copy lacks: worlds, avatars. */
   boolean mirror = true;
   /** 0 = automatic. */
   int rasterThreads = 0;
   /** Frame rate lines in the session log (--fps, for diagnosis; not in the window). */
   boolean showFps = false;
   boolean keepGammaLog = false;
   /** Look for a newer FreeWorlds on GitHub when the launcher opens (see Updater). */
   boolean autoUpdate = true;
   /** Also take test builds (pre-releases). */
   boolean prerelease = false;
   /** Read-only token, only needed while the repository is private. */
   String githubToken = "";
   /** owner/name of the repository with the releases; empty = the one the build names. */
   String updateRepo = "";
   /** When the last automatic check reached GitHub (ms). */
   long lastUpdateCheck = 0;

   static Settings load(File f) {
      Settings s = new Settings();
      if (!f.isFile()) {
         return s;
      }
      Properties p = new Properties();
      try (InputStream in = new FileInputStream(f)) {
         p.load(in);
      } catch (IOException e) {
         return s;
      }
      s.world = p.getProperty("world", s.world);
      s.server = p.getProperty("server", s.server);
      s.user = p.getProperty("user", s.user);
      try {
         s.rasterThreads = Integer.parseInt(p.getProperty("rasterThreads", "0"));
      } catch (NumberFormatException e) {
         s.rasterThreads = 0;
      }
      s.showFps = Boolean.parseBoolean(p.getProperty("showFps", "false"));
      s.mirror = Boolean.parseBoolean(p.getProperty("mirror", "true"));
      s.keepGammaLog = Boolean.parseBoolean(p.getProperty("keepGammaLog", "false"));
      s.customServer = p.getProperty("customServer", s.customServer);
      s.autoUpdate = Boolean.parseBoolean(p.getProperty("autoUpdate", "true"));
      s.prerelease = Boolean.parseBoolean(p.getProperty("prerelease", "false"));
      s.githubToken = p.getProperty("githubToken", "");
      s.updateRepo = p.getProperty("updateRepo", "");
      try {
         s.lastUpdateCheck = Long.parseLong(p.getProperty("lastUpdateCheck", "0"));
      } catch (NumberFormatException e) {
         s.lastUpdateCheck = 0;
      }
      return s;
   }

   /**
    * Writes the settings: to a temporary file first and then over the old one,
    * so a crash never leaves them half written; only the user may read them
    * (the GitHub token is there) where the file system knows permissions.
    */
   synchronized void save(File f) {
      Properties p = new Properties();
      p.setProperty("world", world);
      p.setProperty("server", server);
      p.setProperty("user", user);
      p.setProperty("rasterThreads", Integer.toString(rasterThreads));
      p.setProperty("showFps", Boolean.toString(showFps));
      p.setProperty("mirror", Boolean.toString(mirror));
      p.setProperty("keepGammaLog", Boolean.toString(keepGammaLog));
      p.setProperty("customServer", customServer);
      p.setProperty("autoUpdate", Boolean.toString(autoUpdate));
      p.setProperty("prerelease", Boolean.toString(prerelease));
      p.setProperty("githubToken", githubToken);
      p.setProperty("updateRepo", updateRepo);
      p.setProperty("lastUpdateCheck", Long.toString(lastUpdateCheck));
      f.getParentFile().mkdirs();
      File tmp = new File(f.getPath() + ".tmp");
      try {
         try (OutputStream out = new FileOutputStream(tmp)) {
            p.store(out, "FreeWorlds launcher");
         }
         try {
            Files.setPosixFilePermissions(tmp.toPath(), PosixFilePermissions.fromString("rw-------"));
         } catch (UnsupportedOperationException | IOException e) {
            // Windows: la carpeta de datos ya es del usuario (LOCALAPPDATA)
         }
         try {
            Files.move(tmp.toPath(), f.toPath(), StandardCopyOption.REPLACE_EXISTING, StandardCopyOption.ATOMIC_MOVE);
         } catch (AtomicMoveNotSupportedException e) {
            Files.move(tmp.toPath(), f.toPath(), StandardCopyOption.REPLACE_EXISTING);
         }
      } catch (IOException e) {
         System.err.println("[ajustes] no se pueden guardar en " + f + ": " + e);
      }
   }
}

package net.freeworlds.launcher;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Properties;

/** What the launcher remembers between runs (launcher.properties in the data dir). */
final class Settings {
   /** home: URL of the world the original client opens (empty = its own start, the login screen). */
   String world = "home:GroundZero/groundzero.world";
   /** host:port of a world server, empty = no server (single-user). */
   String server = "";
   String user = "";
   /** Room of the new engine's viewer. */
   String room = "Reception";
   /** 0 = automatic. */
   int rasterThreads = 0;
   boolean showFps = false;
   boolean keepGammaLog = false;

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
      s.room = p.getProperty("room", s.room);
      try {
         s.rasterThreads = Integer.parseInt(p.getProperty("rasterThreads", "0"));
      } catch (NumberFormatException e) {
         s.rasterThreads = 0;
      }
      s.showFps = Boolean.parseBoolean(p.getProperty("showFps", "false"));
      s.keepGammaLog = Boolean.parseBoolean(p.getProperty("keepGammaLog", "false"));
      return s;
   }

   void save(File f) {
      Properties p = new Properties();
      p.setProperty("world", world);
      p.setProperty("server", server);
      p.setProperty("user", user);
      p.setProperty("room", room);
      p.setProperty("rasterThreads", Integer.toString(rasterThreads));
      p.setProperty("showFps", Boolean.toString(showFps));
      p.setProperty("keepGammaLog", Boolean.toString(keepGammaLog));
      f.getParentFile().mkdirs();
      try (OutputStream out = new FileOutputStream(f)) {
         p.store(out, "FreeWorlds launcher");
      } catch (IOException e) {
         System.err.println("[ajustes] no se pueden guardar en " + f + ": " + e);
      }
   }
}

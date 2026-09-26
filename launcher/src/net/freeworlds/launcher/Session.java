package net.freeworlds.launcher;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * One game run in its own JVM: the original client needs the install copy
 * as its working directory (every relative path of the 2004 code, and
 * Gamma's "home:"), and calls System.exit; the new engine needs
 * -XstartOnFirstThread on macOS. Output goes to the session log.
 */
final class Session {
   enum Kind {
      ORIGINAL("worldsplayer"), VIEWER("visor");

      final String logName;

      Kind(String logName) {
         this.logName = logName;
      }
   }

   private final Layout layout;
   private final Settings settings;
   private final Kind kind;
   final Log log;
   private Process process;
   private UpgradeServer upgrade;

   Session(Layout layout, Settings settings, Kind kind) {
      this.layout = layout;
      this.settings = settings;
      this.kind = kind;
      this.log = new Log(layout.logDir, kind.logName);
   }

   /** Prepares and starts the game; returns at once. */
   synchronized void start() throws IOException {
      List<String> cmd = new ArrayList<>();
      cmd.add(Layout.javaExecutable());
      File dir;
      if (kind == Kind.ORIGINAL) {
         Install.prepare(layout, log);
         upgrade = new UpgradeServer(layout.template, layout.baseAvatars, log);
         upgrade.start();
         log.line("[lanzador] servidor local de actualizaciones en http://127.0.0.1:" + upgrade.port() + "/3DCDup");
         Install.configure(layout, upgrade.port(), settings.server, settings.user, settings.keepGammaLog, log);
         cmd.add("-Xmx768m");
         if (Layout.isMac()) {
            cmd.add("-Xdock:name=WorldsPlayer");
         }
         jvmFlags(cmd);
         cmd.add("-cp");
         // "." = the install copy: MessagesBundle*.properties and other
         // resources are loaded from the class path (run_gamma.sh did the same)
         cmd.add("." + File.pathSeparator + layout.jar("worldsplayer.jar").getPath());
         cmd.add("NET.worlds.console.Gamma");
         if (settings.world != null && !settings.world.isEmpty()) {
            cmd.add(settings.world);
         }
         dir = layout.workDir;
      } else {
         cmd.add("-Xmx1g");
         if (Layout.isMac()) {
            cmd.add("-XstartOnFirstThread");
         }
         jvmFlags(cmd);
         cmd.add("-cp");
         cmd.add(layout.jar("freeworlds-client.jar").getPath() + File.pathSeparator + layout.lwjglClassPath());
         cmd.add("net.freeworlds.render.WorldViewer");
         cmd.add(layout.groundZeroWorld().getPath());
         cmd.add(settings.room == null || settings.room.isEmpty() ? "Reception" : settings.room);
         cmd.add("--play");
         dir = layout.dataDir;
         dir.mkdirs();
      }
      log.line("[lanzador] FreeWorlds " + Layout.version() + ", java " + System.getProperty("java.version")
         + " (" + System.getProperty("os.name") + " " + System.getProperty("os.arch") + ")");
      log.line("[lanzador] " + String.join(" ", cmd));
      log.line("[lanzador] directorio: " + dir);
      ProcessBuilder pb = new ProcessBuilder(cmd).directory(dir).redirectErrorStream(true);
      // el JAVA_TOOL_OPTIONS de una maquina ajena ensucia la consola del juego
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      process = pb.start();
      Thread pump = new Thread(() -> {
         try (BufferedReader r = new BufferedReader(new InputStreamReader(process.getInputStream(), StandardCharsets.UTF_8))) {
            for (String s; (s = r.readLine()) != null; ) {
               log.line(s);
            }
         } catch (IOException e) {
            log.line("[lanzador] fin de la salida: " + e);
         }
      }, "freeworlds-output");
      pump.setDaemon(true);
      pump.start();
   }

   private void jvmFlags(List<String> cmd) {
      if (settings.rasterThreads > 0) {
         cmd.add("-Dfreeworlds.rasterThreads=" + settings.rasterThreads);
      }
      if (settings.showFps) {
         cmd.add("-Dfreeworlds.fps=1");
      }
      String extra = System.getenv("FREEWORLDS_JAVA_OPTS");
      if (extra != null && !extra.trim().isEmpty()) {
         for (String s : extra.trim().split("\\s+")) {
            cmd.add(s);
         }
      }
   }

   /** Waits for the game; returns its exit code. */
   int waitFor() throws InterruptedException {
      Process p;
      synchronized (this) {
         p = process;
      }
      int code = p.waitFor();
      finish(code);
      return code;
   }

   boolean isRunning() {
      Process p = process;
      return p != null && p.isAlive();
   }

   synchronized void stop() {
      if (process != null && process.isAlive()) {
         process.destroy();
      }
   }

   private synchronized void finish(int code) {
      if (upgrade != null) {
         upgrade.stop();
         upgrade = null;
      }
      log.line("[lanzador] el juego termino con codigo " + code);
      log.close();
   }
}

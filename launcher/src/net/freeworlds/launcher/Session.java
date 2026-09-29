package net.freeworlds.launcher;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * One run of the original client in its own JVM: it needs the install copy
 * as its working directory (every relative path of the 2004 code, and
 * Gamma's "home:"), and calls System.exit. Output goes to the session log.
 *
 * <p>When the client installs a world or an upgrade it asks for gdkup.exe
 * and quits (NetUpdate.runUpdates, then Main.end); the bridge leaves that
 * request in gdkup.pending. The session then runs the Java gdkup
 * (NET.worlds.core.GdkUp) on the install copy and, as gdkup does with
 * "run.exe world:restart", starts the client again, with the same local
 * upgrade server and log.
 *
 * <p>With a world server on this machine ("whirl local") the session also
 * starts whirl if nothing listens there yet, and stops it at the end
 * ({@link LocalWhirl}); the restarts after an update keep it.
 */
final class Session {
   private final Layout layout;
   private final Settings settings;
   final Log log;
   private Process process;
   private Thread pump;
   private UpgradeServer upgrade;
   private LocalWhirl whirl;
   private volatile boolean stopping;

   Session(Layout layout, Settings settings) {
      this.layout = layout;
      this.settings = settings;
      this.log = new Log(layout.logDir, "worldsplayer");
   }

   /**
    * Prepares and starts the game; returns at once. If a step fails, what
    * was already running (upgrade server, whirl) is stopped again.
    */
   synchronized void start() throws IOException {
      try {
         prepareAndLaunch();
      } catch (IOException | RuntimeException e) {
         log.line("[lanzador] no se pudo arrancar el juego: " + (e.getMessage() == null ? e : e.getMessage()));
         finish(-1);
         throw e;
      }
   }

   private void prepareAndLaunch() throws IOException {
      Install.prepare(layout, log);
      String mirror = settings.mirror ? Install.mirrorOf(layout) : null;
      upgrade = new UpgradeServer(layout.template, layout.baseAvatars, mirror, new File(layout.dataDir, "mirror"), log);
      upgrade.start();
      log.line("[lanzador] servidor local de actualizaciones en http://127.0.0.1:" + upgrade.port() + "/3DCDup"
         + (mirror == null ? " (sin espejo)" : ", lo que falte se pide a " + mirror));
      Install.configure(layout, upgrade.port(), settings.server, settings.user, settings.keepGammaLog, log);
      whirl = LocalWhirl.startIfNeeded(layout, settings.server, log);
      LocalWhirl.prefillLogin(layout, settings.server, settings.user, log);
      log.line("[lanzador] FreeWorlds " + Layout.versionLong() + ", java " + System.getProperty("java.version")
         + " (" + System.getProperty("os.name") + " " + System.getProperty("os.arch") + ")");
      launch(settings.world);
   }

   /** Starts the client with the given world URL (empty: the client's own start). */
   private void launch(String world) throws IOException {
      List<String> cmd = new ArrayList<>();
      cmd.add(Layout.javaExecutable());
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
      if (world != null && !world.isEmpty()) {
         cmd.add(world);
      }
      File dir = layout.workDir;
      log.line("[lanzador] " + String.join(" ", cmd));
      log.line("[lanzador] directorio: " + dir);
      ProcessBuilder pb = new ProcessBuilder(cmd).directory(dir).redirectErrorStream(true);
      // el JAVA_TOOL_OPTIONS de una maquina ajena ensucia la consola del juego
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      Process p = pb.start();
      process = p;
      pump = new Thread(() -> {
         try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream(), StandardCharsets.UTF_8))) {
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

   /** Waits for the game (and its restarts after an update); returns the exit code of the last run. */
   int waitFor() throws InterruptedException {
      while (true) {
         Process p;
         Thread t;
         synchronized (this) {
            p = process;
            t = pump;
         }
         int code = p.waitFor();
         if (t != null) {
            t.join(2000);
         }
         String restart = stopping ? null : pendingUpdate();
         if (restart != null && !stopping) {
            try {
               synchronized (this) {
                  log.line("[lanzador] reinicio tras la actualizacion: " + restart);
                  launch(restart);
               }
               continue;
            } catch (IOException e) {
               log.line("[lanzador] no se pudo reiniciar el cliente: " + e);
            }
         }
         finish(code);
         return code;
      }
   }

   /**
    * gdkup.pending (NativeSysProcess.createProcSpecial): runs GdkUp with its
    * arguments in the install copy; returns the arguments of the restart it
    * asks for, or null.
    */
   private String pendingUpdate() {
      File pending = new File(layout.workDir, "gdkup.pending");
      if (!pending.isFile()) {
         return null;
      }
      List<String> cmd = new ArrayList<>();
      cmd.add(Layout.javaExecutable());
      cmd.add("-cp");
      cmd.add(layout.jar("worldsplayer.jar").getPath());
      cmd.add("NET.worlds.core.GdkUp");
      try {
         for (String a : new String(Files.readAllBytes(pending.toPath()), StandardCharsets.ISO_8859_1).trim().split("\\s+")) {
            if (!a.isEmpty()) {
               cmd.add(a);
            }
         }
         Files.delete(pending.toPath());
         log.line("[lanzador] actualizacion pendiente: " + String.join(" ", cmd.subList(4, cmd.size())));
         ProcessBuilder pb = new ProcessBuilder(cmd).directory(layout.workDir).redirectErrorStream(true);
         pb.environment().remove("JAVA_TOOL_OPTIONS");
         Process g = pb.start();
         String restart = null;
         try (BufferedReader r = new BufferedReader(new InputStreamReader(g.getInputStream(), StandardCharsets.ISO_8859_1))) {
            for (String s; (s = r.readLine()) != null; ) {
               log.line(s);
               if (s.startsWith("[gdkup] reinicio:")) {
                  restart = s.substring("[gdkup] reinicio:".length()).trim();
               }
            }
         }
         int rc = g.waitFor();
         log.line("[lanzador] gdkup termino con codigo " + rc);
         return rc == 10 ? (restart == null || restart.isEmpty() ? "world:restart" : restart) : null;
      } catch (IOException | InterruptedException e) {
         log.line("[lanzador] no se pudo aplicar la actualizacion: " + e);
         return null;
      }
   }

   boolean isRunning() {
      Process p = process;
      return p != null && p.isAlive();
   }

   synchronized void stop() {
      stopping = true;
      if (process != null && process.isAlive()) {
         process.destroy();
      }
   }

   private synchronized void finish(int code) {
      if (upgrade != null) {
         upgrade.stop();
         upgrade = null;
      }
      if (whirl != null) {
         whirl.stop();
         whirl = null;
      }
      log.line("[lanzador] el juego termino con codigo " + code);
      log.close();
   }
}

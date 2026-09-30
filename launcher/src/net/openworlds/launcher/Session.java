package net.openworlds.launcher;

import net.openworlds.injector.Injector;
import net.openworlds.injector.Patch;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CancellationException;

/**
 * One run of the original client in its own JVM: it needs the install copy
 * as its working directory (every relative path of the 2004 code, and
 * Gamma's "home:"), and calls System.exit. Output goes to the session log.
 *
 * <p>A world chosen in the launcher that is not installed yet is installed
 * before the start ({@link WorldInstall}). When the client itself installs a
 * world or an upgrade (the universe map, "Upgrade Now") it asks for
 * gdkup.exe and quits (NetUpdate.runUpdates, then Main.end); the bridge
 * leaves that request in gdkup.pending. The session then runs the Java gdkup
 * (NET.worlds.core.GdkUp) on the install copy and, as gdkup does with
 * "run.exe world:restart", starts the client again, with the same local
 * upgrade server and log.
 *
 * <p>Before the first start, the J Worlds Injector builds the patches the
 * player chose (and the "tls" one for an encrypted server) into classes that
 * go before worldsplayer.jar on the class path; for a world server the
 * game's sign-in is filled in ({@link Login}).
 */
final class Session {
   private final Layout layout;
   private final Settings settings;
   final Log log;
   private volatile Process process;
   private Thread pump;
   private UpgradeServer upgrade;
   /** The J Worlds Injector's classes for this session's patches, or null. */
   private File patchClasses;
   private volatile boolean stopping;
   /** What the preparation is doing, for the window ("Downloading Meteor… 42%"). */
   private volatile WorldInstall.Progress progress = (text, percent) -> { };

   Session(Layout layout, Settings settings) {
      this.layout = layout;
      this.settings = settings;
      this.log = new Log(layout.logDir, "worldsplayer");
   }

   /** Where to report the preparation's steps (called on the thread that runs {@link #start}). */
   void onProgress(WorldInstall.Progress p) {
      progress = p == null ? (text, percent) -> { } : p;
   }

   /**
    * Prepares and starts the game; returns once it runs (after installing the
    * chosen world, if it is not installed yet). If a step fails, what was
    * already running (the upgrade server) is stopped again; {@link #stop}
    * during the preparation ends it with a {@link CancellationException}.
    */
   synchronized void start() throws IOException {
      try {
         prepareAndLaunch();
      } catch (IOException | RuntimeException e) {
         log.line("[launcher] could not start the game: " + (e.getMessage() == null ? e : e.getMessage()));
         finish(-1);
         throw e;
      }
   }

   private void step(String text, int percent) {
      if (stopping) {
         throw new CancellationException("stopped");
      }
      progress.step(text, percent);
   }

   private void prepareAndLaunch() throws IOException {
      step("Getting the game ready…", 0);
      Install.prepare(layout, log);
      String mirror = settings.mirror ? Install.mirrorOf(layout) : null;
      // a world of the list that is not installed yet is installed first,
      // from the mirror, as the game's own download would (but without its
      // detour through GroundZero and a restart)
      String pkg = Install.packageOf(settings.world);
      if (pkg != null && !Install.installed(layout, pkg)) {
         try {
            WorldInstall.install(layout, pkg, mirror, log, this::step);
         } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            throw new IOException("interrupted while installing " + pkg);
         }
      }
      upgrade = new UpgradeServer(layout.template, layout.baseAvatars, mirror, new File(layout.dataDir, "mirror"), log);
      upgrade.start();
      log.line("[launcher] local upgrade server at http://127.0.0.1:" + upgrade.port() + "/3DCDup"
         + (mirror == null ? " (no mirror)" : ", anything missing is fetched from " + mirror));
      Install.configure(layout, upgrade.port(), settings.server, settings.user, settings.keepGammaLog, log);
      Login.prefill(layout, settings.server, settings.user, settings.password, log);
      List<Patch> patches = patches(layout, settings);
      if (!patches.isEmpty()) {
         step("Building the patches…", 100);
      }
      patchClasses = Injector.build(patches, layout.jar("worldsplayer-src.zip"), layout.jar("worldsplayer.jar"),
         new File(layout.dataDir, "injector"), log::line);
      step("Starting WorldsPlayer…", 100);
      log.line("[launcher] OpenWorlds " + Layout.versionLong() + ", java " + System.getProperty("java.version")
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
      cmd.add("." + File.pathSeparator + (patchClasses != null ? patchClasses.getPath() + File.pathSeparator : "")
         + layout.jar("worldsplayer.jar").getPath());
      cmd.add("NET.worlds.console.Gamma");
      if (world != null && !world.isEmpty()) {
         cmd.add(world);
      }
      File dir = layout.workDir;
      log.line("[launcher] " + String.join(" ", cmd));
      log.line("[launcher] directory: " + dir);
      ProcessBuilder pb = new ProcessBuilder(cmd).directory(dir).redirectErrorStream(true);
      // another machine's JAVA_TOOL_OPTIONS would clutter the game's console
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      Process p = pb.start();
      process = p;
      if (stopping) {
         p.destroy();
      }
      pump = new Thread(() -> {
         try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream(), StandardCharsets.UTF_8))) {
            for (String s; (s = r.readLine()) != null; ) {
               log.line(s);
            }
         } catch (IOException e) {
            log.line("[launcher] end of output: " + e);
         }
      }, "openworlds-output");
      pump.setDaemon(true);
      pump.start();
   }

   private void jvmFlags(List<String> cmd) throws IOException {
      if (!settings.server.isEmpty() && settings.encrypted) {
         String pin = Trust.known(layout, settings.server);
         if (pin == null) {
            throw new IOException("The encrypted server " + settings.server + " has not been checked yet (its certificate).");
         }
         // the "tls" patch trusts exactly this certificate
         cmd.add("-Dopenworlds.tls.pin=" + pin);
      }
      if (settings.server.isEmpty()) {
         // "Single player": the client answers "Single-user mode" without showing
         // its "unable to connect" dialog (bridge/natives-launcher.patch)
         cmd.add("-Dopenworlds.singleUser=true");
      }
      if (settings.rasterThreads > 0) {
         cmd.add("-Dopenworlds.rasterThreads=" + settings.rasterThreads);
      }
      if (settings.showFps) {
         cmd.add("-Dopenworlds.fps=1");
      }
      String extra = System.getenv("OPENWORLDS_JAVA_OPTS");
      if (extra != null && !extra.trim().isEmpty()) {
         for (String s : extra.trim().split("\\s+")) {
            cmd.add(s);
         }
      }
   }

   /** The patches to build: the chosen ones, plus "tls" for an encrypted server. */
   static List<Patch> patches(Layout layout, Settings settings) {
      String ids = settings.patches;
      if (!settings.server.isEmpty() && settings.encrypted) {
         ids = ids + ",tls";
      }
      return Patch.pick(Patch.all(userPatches(layout)), ids);
   }

   /** Where the player's own patches go (one folder each, like injector/patches in the repository). */
   static File userPatches(Layout layout) {
      return new File(layout.dataDir, "patches");
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
                  log.line("[launcher] restart after the update: " + restart);
                  launch(restart);
               }
               continue;
            } catch (IOException e) {
               log.line("[launcher] could not restart the client: " + e);
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
         log.line("[launcher] pending update: " + String.join(" ", cmd.subList(4, cmd.size())));
         ProcessBuilder pb = new ProcessBuilder(cmd).directory(layout.workDir).redirectErrorStream(true);
         pb.environment().remove("JAVA_TOOL_OPTIONS");
         Process g = pb.start();
         String restart = null;
         try (BufferedReader r = new BufferedReader(new InputStreamReader(g.getInputStream(), StandardCharsets.ISO_8859_1))) {
            for (String s; (s = r.readLine()) != null; ) {
               log.line(s);
               if (s.startsWith("[gdkup] restart:")) {
                  restart = s.substring("[gdkup] restart:".length()).trim();
               }
            }
         }
         int rc = g.waitFor();
         log.line("[launcher] gdkup ended with code " + rc);
         return rc == 10 ? (restart == null || restart.isEmpty() ? "world:restart" : restart) : null;
      } catch (IOException | InterruptedException e) {
         log.line("[launcher] could not apply the update: " + e);
         return null;
      }
   }

   boolean isRunning() {
      Process p = process;
      return p != null && p.isAlive();
   }

   /** Ends the game, or the preparation before it (not synchronized: start may be busy downloading). */
   void stop() {
      stopping = true;
      Process p = process;
      if (p != null && p.isAlive()) {
         p.destroy();
      }
   }

   private synchronized void finish(int code) {
      if (upgrade != null) {
         upgrade.stop();
         upgrade = null;
      }
      log.line("[launcher] the game ended with code " + code);
      log.close();
   }
}

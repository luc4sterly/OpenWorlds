package net.openworlds.launcher;

import java.awt.GraphicsEnvironment;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

/**
 * OpenWorlds: one entry point for the packaged build (replaces
 * run_gamma.sh and tools/local-upgrade-server.py).
 *
 * <pre>
 *   OpenWorlds                      window with the menu (terminal menu if there is no display)
 *   OpenWorlds --tui                terminal menu
 *   OpenWorlds --original [URL]     the 2004 client straight away (URL: home:GroundZero/groundzero.world...)
 *   OpenWorlds --server HOST:PORT --user NAME   world server for --original (e.g. a local whirl)
 *   OpenWorlds --offline            no world server (single-user)
 *   OpenWorlds --threads N --fps    raster threads of the bridge / frame rate in the log
 *   OpenWorlds --no-mirror | --mirror   do not / do ask us1.worlds.net for what the install lacks
 *   OpenWorlds --update             look for a newer OpenWorlds on GitHub and install it now
 *   OpenWorlds --no-update          neither use a downloaded version nor look for one (this run)
 *   OpenWorlds --smoke SECONDS      CI: run --original for that long and fail unless it drew frames
 *   OpenWorlds --paths | --version | --help
 * </pre>
 *
 * Before anything else, {@link Bootstrap} hands the start to a newer version
 * downloaded by the {@link Updater}, if there is one.
 */
public final class Launcher {
   private Launcher() {
   }

   public static void main(String[] args) throws Exception {
      if (Bootstrap.handOff(args, false)) {
         return;
      }
      // antialiased Swing labels even on a bare X11 without a desktop, and
      // the system proxy for the GitHub queries
      defaultProperty("awt.useSystemAAFontSettings", "on");
      defaultProperty("swing.aatext", "true");
      defaultProperty("java.net.useSystemProxies", "true");
      Layout layout;
      try {
         layout = Layout.detect();
      } catch (IOException e) {
         fatal(e.getMessage());
         return;
      }
      Settings settings = Settings.load(layout.settingsFile);
      String mode = null;
      String modeArg = null;
      int smoke = 0;
      boolean save = false;
      boolean update = false;
      for (int i = 0; i < args.length; i++) {
         String a = args[i];
         String next = i + 1 < args.length && !args[i + 1].startsWith("--") ? args[i + 1] : null;
         switch (a) {
            case "--original":
               mode = "original";
               if (next != null) {
                  modeArg = next;
                  i++;
               }
               break;
            case "--tui":
               mode = "tui";
               break;
            case "--gui":
               mode = "gui";
               break;
            case "--server":
               if (next == null) {
                  fatal("--server needs HOST:PORT");
               }
               settings.server = next;
               i++;
               save = true;
               break;
            case "--user":
               if (next == null) {
                  fatal("--user needs a name");
               }
               settings.user = next;
               i++;
               save = true;
               break;
            case "--offline":
               settings.server = "";
               save = true;
               break;
            case "--threads":
               settings.rasterThreads = Integer.parseInt(next == null ? "0" : next);
               i++;
               break;
            case "--fps":
               settings.showFps = true;
               break;
            case "--mirror":
            case "--no-mirror":
               settings.mirror = a.equals("--mirror");
               save = true;
               break;
            case "--update":
               update = true;
               break;
            case "--no-update":
               System.setProperty("openworlds.noUpdate", "true");
               break;
            case "--smoke":
               System.setProperty("openworlds.noUpdate", "true");
               mode = "original";
               smoke = Integer.parseInt(next == null ? "30" : next);
               settings.showFps = true;
               if (next != null) {
                  i++;
               }
               break;
            case "--paths":
               printPaths(layout);
               return;
            case "--version":
               System.out.println("OpenWorlds " + Layout.version());
               return;
            case "--help":
            case "-h":
               usage();
               return;
            default:
               System.err.println("unknown argument: " + a);
               usage();
               System.exit(2);
         }
      }
      if (save) {
         settings.save(layout.settingsFile);
      }
      if (update) {
         System.exit(Updater.runFromCli(layout, settings));
      }
      if (mode == null) {
         mode = GraphicsEnvironment.isHeadless() ? "tui" : "gui";
      }
      switch (mode) {
         case "original":
            if (modeArg != null) {
               settings.world = modeArg;
            }
            System.exit(smoke > 0 ? smoke(layout, settings, smoke) : run(layout, settings, true));
            break;
         case "tui":
            new TextMenu(layout, settings).run();
            break;
         default:
            if (GraphicsEnvironment.isHeadless()) {
               new TextMenu(layout, settings).run();
            } else {
               LauncherWindow.open(layout, settings, args);
            }
      }
   }

   /** Runs one session in the foreground, echoing its log on this terminal. */
   static int run(Layout layout, Settings settings, boolean echo) throws IOException, InterruptedException {
      Session s = new Session(layout, settings);
      if (echo) {
         s.log.listen(System.out::println);
      }
      Runtime.getRuntime().addShutdownHook(new Thread(s::stop));
      s.start();
      if (echo) {
         System.out.println("[launcher] log: " + s.log.path);
      }
      return s.waitFor();
   }

   /**
    * CI smoke test: the original client must reach the point where the
    * bridge blits camera frames ("[RW] camara ..." diagnostics and fps lines)
    * within the given time; then it is stopped. With a world server on this
    * machine (--server 127.0.0.1:6650) the bundled whirl must also be up.
    */
   static int smoke(Layout layout, Settings settings, int seconds) throws IOException, InterruptedException {
      Session s = new Session(layout, settings);
      final boolean[] drew = {false};
      final boolean[] fps = {false};
      final boolean needWhirl = LocalWhirl.isLocal(settings.server);
      final boolean[] whirl = {false};
      s.log.listen(line -> {
         System.out.println(line);
         if (line.startsWith("[RW] camara ")) {
            drew[0] = true;
         }
         if (line.startsWith("[RW] fps ")) {
            fps[0] = true;
         }
         if (line.startsWith("[whirl] listo") || line.startsWith("[whirl] ya hay un servidor escuchando")) {
            whirl[0] = true;
         }
      });
      s.start();
      long end = System.currentTimeMillis() + seconds * 1000L;
      while (System.currentTimeMillis() < end && s.isRunning() && !(drew[0] && fps[0])) {
         Thread.sleep(250);
      }
      boolean alive = s.isRunning();
      s.stop();
      s.waitFor();
      boolean ok = drew[0] && fps[0] && (!needWhirl || whirl[0]);
      System.out.println("[smoke] drew=" + drew[0] + " fps=" + fps[0] + (needWhirl ? " whirl=" + whirl[0] : "")
         + " still-alive=" + alive + " log=" + s.log.path);
      return ok ? 0 : 1;
   }

   static void printPaths(Layout l) {
      System.out.println("program:   " + l.libDir);
      System.out.println("2004 data: " + l.template);
      System.out.println("avatars:   " + l.baseAvatars);
      System.out.println("user data: " + l.dataDir);
      System.out.println("game copy: " + l.workDir);
      System.out.println("logs:      " + l.logDir);
      System.out.println("java:      " + Layout.javaExecutable());
   }

   static void usage() {
      System.out.println("OpenWorlds " + Layout.version() + "\n"
         + "  (no arguments)            window with the menu (terminal menu if there is no display)\n"
         + "  --tui                     terminal menu\n"
         + "  --original [URL]          the 2004 client (URL home:GroundZero/groundzero.world, empty = login)\n"
         + "  --server HOST:PORT        world server (e.g. a J Solar Server on this machine, 127.0.0.1:6650)\n"
         + "  --user NAME               user name for that server\n"
         + "  --offline                 no server (single player)\n"
         + "  --threads N               raster threads of the bridge (0 = automatic)\n"
         + "  --fps                     frame rate in the log\n"
         + "  --no-mirror | --mirror    do not / do fetch missing worlds and avatars from us1.worlds.net\n"
         + "  --update                  look for a newer version on GitHub and install it now\n"
         + "  --no-update               neither use a downloaded version nor look for one (this run)\n"
         + "  --smoke SECONDS           CI smoke test (fails unless the original client draws)\n"
         + "  --paths | --version | --help");
   }

   private static void defaultProperty(String key, String value) {
      if (System.getProperty(key) == null) {
         System.setProperty(key, value);
      }
   }

   static void fatal(String msg) {
      System.err.println("OpenWorlds: " + msg);
      if (!GraphicsEnvironment.isHeadless()) {
         try {
            javax.swing.JOptionPane.showMessageDialog(null, msg, "OpenWorlds", javax.swing.JOptionPane.ERROR_MESSAGE);
         } catch (Throwable ignored) {
            // no usable display: it already went to the console
         }
      }
      System.exit(1);
   }

   /** Terminal menu, for machines without a display or when asked with --tui. */
   static final class TextMenu {
      private final Layout layout;
      private final Settings settings;
      private final BufferedReader in = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));

      TextMenu(Layout layout, Settings settings) {
         this.layout = layout;
         this.settings = settings;
      }

      void run() throws IOException, InterruptedException {
         Updater updater = new Updater(layout, settings);
         if (settings.autoUpdate) {
            boolean[] told = {false};
            updater.addListener(s -> {
               if (s.phase == Updater.Phase.READY && !told[0]) {
                  told[0] = true;
                  System.out.println("[update] " + Updater.describe(s));
               }
            });
            updater.checkInBackground(false);
         }
         while (true) {
            System.out.println();
            System.out.println("=== OpenWorlds " + Layout.version() + " ===");
            System.out.println(" 1) Play (" + describeWorld(settings.world) + ")");
            System.out.println(" 2) Play from the login screen");
            System.out.println(" 3) World server: " + (settings.server.isEmpty() ? "offline (single player)" : settings.server
               + (settings.user.isEmpty() ? "" : " as " + settings.user)));
            System.out.println(" 4) Options: drawing threads " + (settings.rasterThreads == 0 ? "auto" : settings.rasterThreads)
               + ", download what is missing " + (settings.mirror ? "yes" : "no")
               + ", updates " + (settings.autoUpdate ? "automatic" : "manual"));
            System.out.println(" 5) Check for updates now");
            System.out.println(" 6) Paths");
            System.out.println(" 0) Quit");
            String c = ask("Option");
            if (c == null || c.equals("0") || c.equalsIgnoreCase("q")) {
               settings.save(layout.settingsFile);
               return;
            }
            switch (c) {
               case "1":
                  play(settings.world.isEmpty() ? "home:GroundZero/groundzero.world" : settings.world);
                  break;
               case "2":
                  play("");
                  break;
               case "3":
                  chooseServer();
                  break;
               case "4":
                  options();
                  break;
               case "5":
                  Updater.runFromCli(layout, settings);
                  break;
               case "6":
                  printPaths(layout);
                  break;
               default:
                  System.out.println("Not a valid option: " + c);
            }
         }
      }

      private void play(String world) throws IOException, InterruptedException {
         String keep = settings.world;
         settings.world = world;
         settings.save(layout.settingsFile);
         Launcher.run(layout, settings, true);
         settings.world = keep.isEmpty() ? world : keep;
      }

      private void chooseServer() throws IOException {
         System.out.println(" 1) Offline (single player)");
         System.out.println(" 2) This computer (127.0.0.1:6650)");
         System.out.println(" 3) Another HOST:PORT");
         String c = ask("Server");
         if ("1".equals(c)) {
            settings.server = "";
         } else if ("2".equals(c)) {
            settings.server = "127.0.0.1:6650";
         } else if ("3".equals(c)) {
            String hp = ask("HOST:PORT");
            if (hp != null && hp.contains(":")) {
               settings.server = hp.trim();
            }
         }
         if (!settings.server.isEmpty()) {
            String u = ask("User name (Enter = " + (settings.user.isEmpty() ? "none" : settings.user) + ")");
            if (u != null && !u.isEmpty()) {
               settings.user = u.trim();
            }
         }
         settings.save(layout.settingsFile);
      }

      private void options() throws IOException {
         String t = ask("Drawing threads of the game (0 = auto, now " + settings.rasterThreads + ")");
         if (t != null && !t.isEmpty()) {
            try {
               settings.rasterThreads = Math.max(0, Integer.parseInt(t.trim()));
            } catch (NumberFormatException e) {
               System.out.println("Not a number");
            }
         }
         String m = ask("Download missing worlds and avatars from us1.worlds.net (y/n, now " + (settings.mirror ? "y" : "n") + ")");
         if (m != null && !m.isEmpty()) {
            settings.mirror = m.trim().toLowerCase().startsWith("y");
         }
         String u = ask("Check for updates on start (y/n, now " + (settings.autoUpdate ? "y" : "n") + ")");
         if (u != null && !u.isEmpty()) {
            settings.autoUpdate = u.trim().toLowerCase().startsWith("y");
         }
         settings.save(layout.settingsFile);
      }

      private String ask(String prompt) throws IOException {
         System.out.print(prompt + ": ");
         System.out.flush();
         String s = in.readLine();
         return s == null ? null : s.trim();
      }
   }

   static String describeWorld(String w) {
      if (w == null || w.isEmpty()) {
         return "login screen";
      }
      int hash = w.indexOf('#');
      String n = hash >= 0 ? w.substring(0, hash) : w;
      n = n.substring(n.lastIndexOf('/') + 1);
      int dot = n.lastIndexOf('.');
      return dot > 0 ? n.substring(0, dot) : n;
   }

}

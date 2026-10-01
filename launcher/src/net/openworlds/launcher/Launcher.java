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
 *   OpenWorlds --server HOST[:PORT] --user NAME [--password P] [--encrypted [--trust]]
 *                                   world server for --original (e.g. a J Solar Server)
 *   OpenWorlds --offline            no world server (single-user)
 *   OpenWorlds --patches ID,ID | --list-patches   J Worlds Injector patches for the game
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
      boolean trust = false;
      String serverArg = null;
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
                  fatal("--server needs HOST or HOST:PORT");
               }
               serverArg = next;
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
            case "--password":
               if (next == null) {
                  fatal("--password needs a password");
               }
               settings.password = next;
               i++;
               save = true;
               break;
            case "--encrypted":
               settings.encrypted = true;
               save = true;
               break;
            case "--trust":
               trust = true;
               break;
            case "--offline":
               settings.server = "";
               save = true;
               break;
            case "--patches":
               settings.patches = next == null ? "" : next;
               if (next != null) {
                  i++;
               }
               save = true;
               break;
            case "--list-patches":
               listPatches(layout, settings);
               return;
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
      if (serverArg != null) {
         // after the loop: the default port depends on --encrypted, wherever it is
         String server = serverAddress(serverArg, settings.encrypted);
         if (server == null) {
            fatal("--server needs HOST or HOST:PORT, not " + serverArg);
         }
         settings.server = server;
         settings.customServer = serverArg;
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
            if (!checkServer(layout, settings, trust)) {
               System.exit(3);
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
    * within the given time; then it is stopped. With patches chosen, the
    * J Worlds Injector must have built them first; with a world server, the
    * client must have connected to it.
    */
   static int smoke(Layout layout, Settings settings, int seconds) throws IOException, InterruptedException {
      Session s = new Session(layout, settings);
      final boolean[] drew = {false};
      final boolean[] fps = {false};
      final boolean needPatches = !Session.patches(layout, settings).isEmpty();
      final boolean[] patched = {false};
      final boolean needServer = !settings.server.isEmpty();
      final boolean[] connected = {false};
      s.log.listen(line -> {
         System.out.println(line);
         if (line.startsWith("[RW] camara ")) {
            drew[0] = true;
         }
         if (line.startsWith("[RW] fps ")) {
            fps[0] = true;
         }
         if (line.startsWith("[injector] patches ")) {
            patched[0] = true;
         }
         if (line.startsWith("Connected to ")) {
            connected[0] = true;
         }
      });
      s.start();
      long end = System.currentTimeMillis() + seconds * 1000L;
      while (System.currentTimeMillis() < end && s.isRunning() && !(drew[0] && fps[0] && (!needServer || connected[0]))) {
         Thread.sleep(250);
      }
      boolean alive = s.isRunning();
      s.stop();
      s.waitFor();
      boolean ok = drew[0] && fps[0] && (!needPatches || patched[0]) && (!needServer || connected[0]);
      System.out.println("[smoke] drew=" + drew[0] + " fps=" + fps[0] + (needPatches ? " patches=" + patched[0] : "")
         + (needServer ? " connected=" + connected[0] : "") + " still-alive=" + alive + " log=" + s.log.path);
      return ok ? 0 : 1;
   }

   static void listPatches(Layout layout, Settings settings) {
      java.util.List<String> on = java.util.Arrays.asList(settings.patches.split(","));
      for (net.openworlds.injector.Patch p : net.openworlds.injector.Patch.all(Session.userPatches(layout))) {
         System.out.println((on.contains(p.id) ? "[x] " : "[ ] ") + p.id + " - " + p.name + (p.builtIn ? "" : " (yours)"));
         System.out.println("      " + p.description);
      }
      System.out.println("Your own patches go in " + Session.userPatches(layout));
   }

   /**
    * For --original with an encrypted server: its certificate must be known
    * (see Trust), or accepted now with --trust. Prints what to do otherwise.
    */
   static boolean checkServer(Layout layout, Settings settings, boolean trust) {
      if (settings.server.isEmpty() || !settings.encrypted) {
         return true;
      }
      Trust.Check c = certificate(layout, settings);
      if (c == null || c.trusted()) {
         return c != null;
      }
      if (!trust) {
         System.err.println("  Compare it with the one J Solar Server shows (Settings, Connections; or JSolarServer --fingerprint),"
            + " then run again with --trust.");
         return false;
      }
      Trust.remember(layout, settings.server, c.fingerprint);
      System.out.println("[launcher] trusting " + settings.server + ": " + c.fingerprint);
      return true;
   }

   /**
    * The certificate check of an encrypted server, printed for the player
    * when it is not trusted yet; null for a plain server, or (with the reason
    * printed) when the server does not answer over TLS.
    */
   private static Trust.Check certificate(Layout layout, Settings settings) {
      if (settings.server.isEmpty() || !settings.encrypted) {
         return null;
      }
      Trust.Check c;
      try {
         c = Trust.check(layout, settings.server);
      } catch (IOException e) {
         System.err.println("OpenWorlds: " + settings.server + " does not answer an encrypted connection: " + e.getMessage());
         return null;
      }
      if (!c.trusted()) {
         System.err.println("OpenWorlds: " + (c.changed() ? "THE CERTIFICATE CHANGED for " : "first encrypted connection to ")
            + c.server + "\n  fingerprint: " + c.fingerprint + (c.changed() ? "\n  trusted was: " + c.known : ""));
      }
      return c;
   }

   /** J Solar Server's ports, for an address typed without one. */
   static final int PLAIN_PORT = 6650;
   static final int TLS_PORT = 6651;

   /**
    * A world server as the player typed it ("host" or "host:port", even a
    * worldserver:// URL), with J Solar Server's port for the kind of
    * connection when it has none; null if it is not an address.
    */
   static String serverAddress(String typed, boolean encrypted) {
      String s = typed == null ? "" : typed.trim();
      if (s.regionMatches(true, 0, "worldserver://", 0, 14)) {
         s = s.substring(14);
      }
      while (s.endsWith("/")) {
         s = s.substring(0, s.length() - 1);
      }
      if (s.isEmpty() || s.contains(" ") || s.contains("/")) {
         return null;
      }
      int colon = s.lastIndexOf(':');
      if (colon < 0) {
         return s + ":" + (encrypted ? TLS_PORT : PLAIN_PORT);
      }
      if (colon == 0) {
         return null;
      }
      try {
         int port = Integer.parseInt(s.substring(colon + 1));
         return port > 0 && port < 65536 ? s : null;
      } catch (NumberFormatException e) {
         return null;
      }
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
         + "  --server HOST[:PORT]      world server, a J Solar Server (port 6650, or 6651 encrypted, if none)\n"
         + "  --user NAME               user name for that server (a new name makes an account there)\n"
         + "  --password PASSWORD       its password, filled in the game's sign-in\n"
         + "  --encrypted [--trust]     connect over TLS; --trust accepts a server's certificate the first time\n"
         + "  --offline                 no server (single player)\n"
         + "  --patches ID,ID           J Worlds Injector patches for the game (empty: none); --list-patches lists them\n"
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
            System.out.println(" 3) Server: " + (settings.server.isEmpty() ? "single player" : settings.server
               + (settings.encrypted ? " (encrypted)" : "") + (settings.user.isEmpty() ? "" : " as " + settings.user)));
            System.out.println(" 4) Options: drawing threads " + (settings.rasterThreads == 0 ? "auto" : settings.rasterThreads)
               + ", download what is missing " + (settings.mirror ? "yes" : "no")
               + ", updates " + (settings.autoUpdate ? "automatic" : "manual"));
            System.out.println(" 5) Patches: " + (settings.patches.trim().isEmpty() ? "none" : settings.patches));
            System.out.println(" 6) Check for updates now");
            System.out.println(" 7) Paths");
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
                  patches();
                  break;
               case "6":
                  Updater.runFromCli(layout, settings);
                  break;
               case "7":
                  printPaths(layout);
                  break;
               default:
                  System.out.println("Not a valid option: " + c);
            }
         }
      }

      private void patches() throws IOException {
         java.util.List<net.openworlds.injector.Patch> all = net.openworlds.injector.Patch.all(Session.userPatches(layout));
         java.util.List<String> on = new java.util.ArrayList<>(java.util.Arrays.asList(settings.patches.split(",")));
         on.removeIf(String::isEmpty);
         for (int i = 0; i < all.size(); i++) {
            net.openworlds.injector.Patch p = all.get(i);
            System.out.println(" " + (i + 1) + ") [" + (on.contains(p.id) ? "x" : " ") + "] " + p.name + " - " + p.description);
         }
         String c = ask("Number to turn on/off (Enter = done)");
         try {
            int n = Integer.parseInt(c == null ? "" : c.trim()) - 1;
            if (n >= 0 && n < all.size()) {
               String id = all.get(n).id;
               if (!on.remove(id)) {
                  on.add(id);
               }
               settings.patches = String.join(",", on);
               settings.save(layout.settingsFile);
            }
         } catch (NumberFormatException e) {
            // Enter: done
         }
      }

      private void play(String world) throws IOException, InterruptedException {
         if (!settings.server.isEmpty() && settings.encrypted) {
            Trust.Check c = certificate(layout, settings);
            if (c == null) {
               return;
            }
            if (!c.trusted()) {
               String t = ask("Is it the one J Solar Server shows (Settings, Connections)? Trust it (y/n)");
               if (t == null || !t.trim().toLowerCase(java.util.Locale.ROOT).startsWith("y")) {
                  return;
               }
               Trust.remember(layout, settings.server, c.fingerprint);
            }
         }
         String keep = settings.world;
         settings.world = world;
         settings.save(layout.settingsFile);
         Launcher.run(layout, settings, true);
         settings.world = keep.isEmpty() ? world : keep;
      }

      private void chooseServer() throws IOException {
         System.out.println(" 1) Single player (no server)");
         System.out.println(" 2) Online: a J Solar Server");
         String c = ask("Server");
         if ("1".equals(c)) {
            settings.server = "";
         } else if ("2".equals(c)) {
            String hp = ask("Server address, host or host:port"
               + (settings.customServer.isEmpty() ? "" : " (Enter = " + settings.customServer + ")"));
            if (hp == null) {
               return;
            }
            if (hp.isEmpty()) {
               hp = settings.customServer;
            }
            String e = ask("Encrypted connection (y/n, now " + (settings.encrypted ? "y" : "n") + ")");
            if (e != null && !e.isEmpty()) {
               settings.encrypted = e.trim().toLowerCase(java.util.Locale.ROOT).startsWith("y");
            }
            String server = serverAddress(hp, settings.encrypted);
            if (server == null) {
               System.out.println("Not a server address: " + hp);
               return;
            }
            settings.customServer = hp.trim();
            settings.server = server;
            String u = ask("Your name (Enter = " + (settings.user.isEmpty() ? Login.defaultUser() : settings.user) + ")");
            if (u != null && !u.isEmpty()) {
               settings.user = u.trim();
            } else if (settings.user.isEmpty()) {
               settings.user = Login.defaultUser();
            }
            String pw = ask("Password (Enter = keep; the first time, any password makes your account)");
            if (pw != null && !pw.isEmpty()) {
               settings.password = pw;
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
            settings.mirror = m.trim().toLowerCase(java.util.Locale.ROOT).startsWith("y");
         }
         String u = ask("Check for updates on start (y/n, now " + (settings.autoUpdate ? "y" : "n") + ")");
         if (u != null && !u.isEmpty()) {
            settings.autoUpdate = u.trim().toLowerCase(java.util.Locale.ROOT).startsWith("y");
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

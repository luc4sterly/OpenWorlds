package net.freeworlds.launcher;

import java.awt.GraphicsEnvironment;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

/**
 * FreeWorlds: one entry point for the packaged build (replaces
 * run_gamma.sh and tools/local-upgrade-server.py).
 *
 * <pre>
 *   FreeWorlds                      window with the menu (terminal menu if there is no display)
 *   FreeWorlds --tui                terminal menu
 *   FreeWorlds --original [URL]     the 2004 client straight away (URL: home:GroundZero/groundzero.world...)
 *   FreeWorlds --server HOST:PORT --user NAME   world server for --original (e.g. a local whirl)
 *   FreeWorlds --offline            no world server (single-user)
 *   FreeWorlds --threads N --fps    raster threads of the bridge / frame rate in the log
 *   FreeWorlds --no-mirror | --mirror   do not / do ask us1.worlds.net for what the install lacks
 *   FreeWorlds --update             look for a newer FreeWorlds on GitHub and install it now
 *   FreeWorlds --no-update          neither use a downloaded version nor look for one (this run)
 *   FreeWorlds --smoke SECONDS      CI: run --original for that long and fail unless it drew frames
 *   FreeWorlds --paths | --version | --help
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
      // texto suavizado en las etiquetas de Swing tambien en un X11 sin
      // escritorio; y el proxy del sistema para las consultas a GitHub
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
                  fatal("--server necesita HOST:PUERTO");
               }
               settings.server = next;
               i++;
               save = true;
               break;
            case "--user":
               if (next == null) {
                  fatal("--user necesita un nombre");
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
               System.setProperty("freeworlds.noUpdate", "true");
               break;
            case "--smoke":
               System.setProperty("freeworlds.noUpdate", "true");
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
               System.out.println("FreeWorlds " + Layout.version());
               return;
            case "--help":
            case "-h":
               usage();
               return;
            default:
               System.err.println("argumento desconocido: " + a);
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
         System.out.println("[lanzador] registro: " + s.log.path);
      }
      return s.waitFor();
   }

   /**
    * CI smoke test: the original client must reach the point where the
    * bridge blits camera frames ("[RW] camara ..." diagnostics and fps lines)
    * within the given time; then it is stopped.
    */
   static int smoke(Layout layout, Settings settings, int seconds) throws IOException, InterruptedException {
      Session s = new Session(layout, settings);
      final boolean[] drew = {false};
      final boolean[] fps = {false};
      s.log.listen(line -> {
         System.out.println(line);
         if (line.startsWith("[RW] camara ")) {
            drew[0] = true;
         }
         if (line.startsWith("[RW] fps ")) {
            fps[0] = true;
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
      System.out.println("[smoke] dibuja=" + drew[0] + " fps=" + fps[0] + " seguia vivo=" + alive + " registro=" + s.log.path);
      return drew[0] && fps[0] ? 0 : 1;
   }

   static void printPaths(Layout l) {
      System.out.println("programa:  " + l.libDir);
      System.out.println("datos 2004: " + l.template);
      System.out.println("avatares:  " + l.baseAvatars);
      System.out.println("usuario:   " + l.dataDir);
      System.out.println("copia:     " + l.workDir);
      System.out.println("registros: " + l.logDir);
      System.out.println("java:      " + Layout.javaExecutable());
   }

   static void usage() {
      System.out.println("FreeWorlds " + Layout.version() + "\n"
         + "  (sin argumentos)          ventana con el menu (menu de terminal si no hay pantalla)\n"
         + "  --tui                     menu de terminal\n"
         + "  --original [URL]          cliente original de 2004 (URL home:GroundZero/groundzero.world, vacio = login)\n"
         + "  --server HOST:PUERTO      servidor de mundos (p. ej. un whirl local 127.0.0.1:6650)\n"
         + "  --user NOMBRE             usuario para ese servidor\n"
         + "  --offline                 sin servidor (un jugador)\n"
         + "  --threads N               hilos del rasterizador del puente (0 = automatico)\n"
         + "  --fps                     fotogramas por segundo en el registro\n"
         + "  --no-mirror | --mirror    no pedir / pedir a us1.worlds.net los mundos y avatares que falten\n"
         + "  --update                  buscar una version nueva en GitHub e instalarla ya\n"
         + "  --no-update               ni usar una version descargada ni buscarla (en esta ejecucion)\n"
         + "  --smoke SEGUNDOS          prueba de humo para CI (falla si el original no dibuja)\n"
         + "  --paths | --version | --help");
   }

   private static void defaultProperty(String key, String value) {
      if (System.getProperty(key) == null) {
         System.setProperty(key, value);
      }
   }

   static void fatal(String msg) {
      System.err.println("FreeWorlds: " + msg);
      if (!GraphicsEnvironment.isHeadless()) {
         try {
            javax.swing.JOptionPane.showMessageDialog(null, msg, "FreeWorlds", javax.swing.JOptionPane.ERROR_MESSAGE);
         } catch (Throwable ignored) {
            // sin pantalla utilizable: ya salio por la consola
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
                  System.out.println("[actualizacion] " + Updater.describe(s));
               }
            });
            updater.checkInBackground(false);
         }
         while (true) {
            System.out.println();
            System.out.println("=== FreeWorlds " + Layout.version() + " ===");
            System.out.println(" 1) Jugar: cliente original de 2004 (" + describeWorld(settings.world) + ")");
            System.out.println(" 2) Jugar: cliente original desde la pantalla de login");
            System.out.println(" 3) Servidor de mundos: " + (settings.server.isEmpty() ? "sin conexion (un jugador)" : settings.server
               + (settings.user.isEmpty() ? "" : " como " + settings.user)));
            System.out.println(" 4) Opciones: hilos de dibujo " + (settings.rasterThreads == 0 ? "auto" : settings.rasterThreads)
               + ", descargar lo que falte " + (settings.mirror ? "si" : "no")
               + ", actualizaciones " + (settings.autoUpdate ? "automaticas" : "a mano"));
            System.out.println(" 5) Buscar actualizaciones ahora");
            System.out.println(" 6) Rutas");
            System.out.println(" 0) Salir");
            String c = ask("Opcion");
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
                  System.out.println("Opcion no valida: " + c);
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
         System.out.println(" 1) Sin conexion (un jugador)");
         System.out.println(" 2) whirl local (127.0.0.1:6650)");
         System.out.println(" 3) Otro HOST:PUERTO");
         String c = ask("Servidor");
         if ("1".equals(c)) {
            settings.server = "";
         } else if ("2".equals(c)) {
            settings.server = "127.0.0.1:6650";
         } else if ("3".equals(c)) {
            String hp = ask("HOST:PUERTO");
            if (hp != null && hp.contains(":")) {
               settings.server = hp.trim();
            }
         }
         if (!settings.server.isEmpty()) {
            String u = ask("Usuario (Intro = " + (settings.user.isEmpty() ? "ninguno" : settings.user) + ")");
            if (u != null && !u.isEmpty()) {
               settings.user = u.trim();
            }
         }
         settings.save(layout.settingsFile);
      }

      private void options() throws IOException {
         String t = ask("Hilos de dibujo del cliente original (0 = auto, ahora " + settings.rasterThreads + ")");
         if (t != null && !t.isEmpty()) {
            try {
               settings.rasterThreads = Math.max(0, Integer.parseInt(t.trim()));
            } catch (NumberFormatException e) {
               System.out.println("No es un numero");
            }
         }
         String m = ask("Descargar de us1.worlds.net los mundos y avatares que falten (s/n, ahora " + (settings.mirror ? "s" : "n") + ")");
         if (m != null && !m.isEmpty()) {
            settings.mirror = m.trim().toLowerCase().startsWith("s") || m.trim().toLowerCase().startsWith("y");
         }
         String u = ask("Buscar actualizaciones al abrir (s/n, ahora " + (settings.autoUpdate ? "s" : "n") + ")");
         if (u != null && !u.isEmpty()) {
            settings.autoUpdate = u.trim().toLowerCase().startsWith("s") || u.trim().toLowerCase().startsWith("y");
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
         return "pantalla de login";
      }
      int hash = w.indexOf('#');
      String n = hash >= 0 ? w.substring(0, hash) : w;
      n = n.substring(n.lastIndexOf('/') + 1);
      int dot = n.lastIndexOf('.');
      return dot > 0 ? n.substring(0, dot) : n;
   }

}

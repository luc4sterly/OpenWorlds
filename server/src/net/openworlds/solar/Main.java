package net.openworlds.solar;

import java.awt.GraphicsEnvironment;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

/**
 * J Solar Server's entry point: the admin window, or with --headless (or no
 * display) the server on its own with a small command console.
 */
public final class Main {
   private Main() {
   }

   public static void main(String[] args) throws Exception {
      File data = null;
      boolean headless = GraphicsEnvironment.isHeadless();
      Integer port = null;
      Integer tlsPort = null;
      Boolean tls = null;
      Boolean plain = null;
      String addUser = null;
      String addPass = null;
      boolean addVip = false;
      boolean addAdmin = false;
      boolean printFingerprint = false;
      for (int i = 0; i < args.length; i++) {
         String a = args[i];
         switch (a) {
            case "--headless":
            case "--nogui":
               headless = true;
               break;
            case "--data":
               data = new File(need(args, ++i, a));
               break;
            case "--port":
               port = Integer.parseInt(need(args, ++i, a));
               break;
            case "--tls-port":
               tlsPort = Integer.parseInt(need(args, ++i, a));
               tls = true;
               break;
            case "--tls":
               tls = true;
               break;
            case "--no-tls":
               tls = false;
               break;
            case "--no-plain":
               plain = false;
               break;
            case "--add-user":
               addUser = need(args, ++i, a);
               addPass = need(args, ++i, a);
               break;
            case "--vip":
               addVip = true;
               break;
            case "--admin":
               addAdmin = true;
               break;
            case "--fingerprint":
               printFingerprint = true;
               break;
            case "--version":
               System.out.println("J Solar Server " + SolarServer.version());
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
      if (data == null) {
         data = defaultDataDir();
      }
      SolarServer server = new SolarServer(data);
      boolean changedConfig = false;
      if (port != null) {
         server.config.port = port;
         changedConfig = true;
      }
      if (tlsPort != null) {
         server.config.tlsPort = tlsPort;
         changedConfig = true;
      }
      if (tls != null) {
         server.config.tlsEnabled = tls;
         changedConfig = true;
      }
      if (plain != null) {
         server.config.plainEnabled = plain;
         changedConfig = true;
      }
      if (changedConfig) {
         server.config.save();
      }
      if (addUser != null) {
         server.createAccount(addUser, addPass, addVip, addAdmin);
         System.out.println("account " + addUser + " created in " + data);
         return;
      }
      if (printFingerprint) {
         System.out.println(server.fingerprint());
         return;
      }
      if (headless) {
         runHeadless(server);
      } else {
         AdminWindow.open(server);
      }
   }

   private static String need(String[] args, int i, String opt) {
      if (i >= args.length || args[i].startsWith("--")) {
         System.err.println(opt + " needs a value");
         System.exit(2);
      }
      return args[i];
   }

   static File defaultDataDir() {
      String env = System.getenv("JSOLAR_DATA");
      if (env != null && !env.trim().isEmpty()) {
         return new File(env.trim());
      }
      String prop = System.getProperty("jsolar.data");
      if (prop != null && !prop.trim().isEmpty()) {
         return new File(prop.trim());
      }
      String home = System.getProperty("user.home", ".");
      String os = System.getProperty("os.name", "").toLowerCase(Locale.ROOT);
      if (os.contains("mac")) {
         return new File(home, "Library/Application Support/J Solar Server");
      }
      if (os.contains("win")) {
         String local = System.getenv("LOCALAPPDATA");
         return new File(local != null ? local : home, "J Solar Server");
      }
      String xdg = System.getenv("XDG_DATA_HOME");
      return new File(xdg != null && !xdg.isEmpty() ? new File(xdg) : new File(home, ".local/share"), "j-solar-server");
   }

   static void runHeadless(SolarServer server) throws Exception {
      server.addListener(System.out::println);
      Runtime.getRuntime().addShutdownHook(new Thread(server::stop));
      server.start();
      System.out.println("[solar] data folder: " + server.dataDir.getAbsolutePath() + " - type \"help\" for commands");
      BufferedReader in = new BufferedReader(new InputStreamReader(System.in, StandardCharsets.UTF_8));
      String line;
      while ((line = in.readLine()) != null) {
         line = line.trim();
         if (line.isEmpty()) {
            continue;
         }
         String[] w = line.split("\\s+", 3);
         String cmd = w[0].toLowerCase(Locale.ROOT);
         try {
            switch (cmd) {
               case "help":
                  System.out.println("  status | who | accounts | say TEXT | kick NAME | ban NAME | unban NAME\n"
                     + "  vip NAME | unvip NAME | admin NAME | unadmin NAME | adduser NAME PASSWORD\n"
                     + "  passwd NAME PASSWORD | deluser NAME | fingerprint | stop");
                  break;
               case "status":
                  System.out.println((server.isRunning() ? "running since " + new Date(server.startedAt()) : "stopped")
                     + ", " + server.onlineCount() + " online, " + server.accountList().size() + " accounts");
                  break;
               case "who":
                  for (SolarServer.PlayerInfo p : server.players()) {
                     System.out.println("  " + p.name + (p.room.isEmpty() ? "" : " in " + p.room) + " (" + p.address
                        + (p.secure ? ", encrypted" : "") + ")");
                  }
                  break;
               case "accounts":
                  SimpleDateFormat f = new SimpleDateFormat("yyyy-MM-dd HH:mm");
                  for (SolarServer.AccountInfo a : server.accountList()) {
                     System.out.println("  " + a.name + (a.admin ? " admin" : "") + (a.vip ? " vip" : "")
                        + (a.banned ? " BANNED" : "") + (a.online ? " (online)" : "")
                        + (a.lastSeen > 0 ? ", last seen " + f.format(new Date(a.lastSeen)) : ""));
                  }
                  break;
               case "say":
                  server.broadcast(line.substring(3).trim());
                  break;
               case "kick":
                  System.out.println(server.kick(arg(w, 1), "kicked from the console") ? "done" : "not online");
                  break;
               case "ban":
               case "unban":
                  System.out.println(server.setBanned(arg(w, 1), cmd.equals("ban")) ? "done" : "no such account");
                  break;
               case "vip":
               case "unvip":
                  System.out.println(server.setVip(arg(w, 1), cmd.equals("vip")) ? "done" : "no such account");
                  break;
               case "admin":
               case "unadmin":
                  System.out.println(server.setAdmin(arg(w, 1), cmd.equals("admin")) ? "done" : "no such account");
                  break;
               case "adduser":
                  server.createAccount(arg(w, 1), arg(w, 2), false, false);
                  System.out.println("done");
                  break;
               case "passwd":
                  server.setPassword(arg(w, 1), arg(w, 2));
                  System.out.println("done");
                  break;
               case "deluser":
                  System.out.println(server.deleteAccount(arg(w, 1)) ? "done" : "no such account");
                  break;
               case "fingerprint":
                  System.out.println(server.fingerprint());
                  break;
               case "stop":
               case "quit":
               case "exit":
                  server.stop();
                  System.exit(0);
                  break;
               default:
                  System.out.println("unknown command; type help");
            }
         } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
         }
      }
      // stdin closed (e.g. started from a service): keep serving
      Thread.currentThread().join();
   }

   private static String arg(String[] w, int i) {
      if (i >= w.length) {
         throw new IllegalArgumentException("missing argument");
      }
      return w[i];
   }

   static void usage() {
      System.out.println("J Solar Server " + SolarServer.version() + " - a world server for WorldsPlayer\n"
         + "  (no arguments)          the admin window (the console when there is no display)\n"
         + "  --headless              no window: log on the terminal and a command console\n"
         + "  --data DIR              data folder (settings, accounts, certificate, logs)\n"
         + "  --port N                normal port (default 6650)\n"
         + "  --tls                   also accept encrypted (TLS) connections, on --tls-port (default 6651)\n"
         + "  --tls-port N            the encrypted port\n"
         + "  --no-tls | --no-plain   turn the encrypted / normal port off\n"
         + "  --add-user NAME PASSWORD [--vip] [--admin]   create an account and exit\n"
         + "  --fingerprint           print the encrypted connection's certificate fingerprint and exit\n"
         + "  --version | --help");
   }
}

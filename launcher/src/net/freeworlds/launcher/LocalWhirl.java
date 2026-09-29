package net.freeworlds.launcher;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.URL;
import java.net.URLClassLoader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;
import java.util.Locale;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

/**
 * whirl, the Whirlsplash WorldServer (server/whirl: third-party, Rust, run
 * as it is), started by the launcher so that "whirl local" is one click:
 * when the chosen world server is on this machine (127.x.x.x or localhost)
 * and nothing listens on its port, the session runs
 * {@code whirl run distributor,hub} in {@code <data>/whirl/} before the
 * client and stops it when the game ends (Session.finish; the restarts
 * after installing a world do not stop it). What tools/run-whirl.sh does by
 * hand (docs/net-local-whirl.md), with the same facts about whirl:
 *
 * <ul>
 * <li>it reads {@code .whirl/Config.toml} relative to its working directory
 *     (whirl_config/src/lib.rs:55): the file is written there on every
 *     start, with {@code whirlsplash.ip} = the loopback address of the
 *     choice, which is both the bind address and the address the
 *     distributor sends in REDIRID;</li>
 * <li>its prompt stays enabled and its stdin is a pipe that the launcher
 *     keeps open without writing: with the prompt disabled whirl waits in
 *     {@code loop { sleep(Duration::default()) }} (whirl/src/cli.rs:197-203,
 *     one core at 100 %), and at end of file {@code read_line} returns at
 *     once and the prompt loops (whirl_prompt/src/lib.rs:67-72). The
 *     prompt's {@code exit} (whirl_prompt/src/lib.rs:89) is how it is
 *     stopped;</li>
 * <li>its output also goes through a pipe, copied to
 *     {@code <data>/logs/whirl-<date>.log}: if the launcher dies without
 *     stopping it (SIGKILL), stdin reaches end of file, the prompt writes to
 *     a pipe nobody reads and whirl ends on that error instead of looping
 *     (to a file it would fill the disk);</li>
 * <li>a port that cannot be bound does not end whirl: the {@code unwrap} of
 *     the bind panics inside its tokio task (whirl_server/src/lib.rs:140,
 *     157) and the process goes on without that server. Ready therefore
 *     means the two "now listening at ip:port" lines
 *     (whirl_server/src/lib.rs:77) within {@link #START_TIMEOUT_MS}.</li>
 * </ul>
 *
 * <p>The binary, first found: {@code -Dfreeworlds.whirl} or FREEWORLDS_WHIRL
 * (only that one); {@code <lib>/whirl/whirl[.exe]} (jpackage app image, the
 * jars are in {@code app/}); {@code <lib>/../whirl/} (portable layout,
 * {@code FreeWorlds/lib/}); the same two under {@code -Dfreeworlds.bundledLib}
 * (the lib directory of the installed app when the launcher runs from a
 * version downloaded into the data directory); in a checkout,
 * {@code server/whirl/target/{release,debug}/whirl}.
 */
final class LocalWhirl {
   /** Hub (RoomServer) port of tools/run-whirl.sh; another free one if it is taken. */
   static final int DEFAULT_HUB_PORT = 5673;
   /** whirlsplash.log.level: 1 info, 2 debug (logins, chat, rooms), 3 trace (every packet). */
   static final int LOG_LEVEL = 2;
   static final long START_TIMEOUT_MS = 20000;
   /**
    * Password remembered for a local world server. whirl does not check it:
    * SESSINIT only reads VAR_USERNAME (whirl_server/src/distributor.rs:81,
    * hub.rs:88; VAR_PASSWORD, net/constants.rs:24, is never read).
    */
   static final String LOCAL_PASSWORD = "freeworlds";

   private final File bin;
   private final File dir;
   private final Endpoint where;
   private final int hubPort;
   private final Log log;
   private final Log output;
   private Process process;
   private OutputStream stdin;
   private Thread hook;
   // estado del arranque: lo actualiza el hilo que copia la salida
   private boolean distributorUp;
   private boolean hubUp;
   private boolean ended;
   private boolean stopping;
   private String failure;
   private final Deque<String> tail = new ArrayDeque<>();

   private LocalWhirl(File bin, File dir, Endpoint where, int hubPort, Layout l, Log log) {
      this.bin = bin;
      this.dir = dir;
      this.where = where;
      this.hubPort = hubPort;
      this.log = log;
      this.output = new Log(l.logDir, "whirl");
   }

   /** Loopback address whirl listens on and port of a local "host:port" choice. */
   static final class Endpoint {
      final String ip;
      final int port;

      Endpoint(String ip, int port) {
         this.ip = ip;
         this.port = port;
      }

      @Override
      public String toString() {
         return ip + ":" + port;
      }
   }

   /**
    * The endpoint of a world server choice ("host:port") on this machine:
    * localhost (whirl then listens on 127.0.0.1) or a 127.x.x.x address;
    * null for anything else, an empty choice or a missing port.
    */
   static Endpoint local(String server) {
      if (server == null) {
         return null;
      }
      String s = server.trim();
      int colon = s.lastIndexOf(':');
      if (colon <= 0 || colon == s.length() - 1) {
         return null;
      }
      int port;
      try {
         port = Integer.parseInt(s.substring(colon + 1).trim());
      } catch (NumberFormatException e) {
         return null;
      }
      if (port <= 0 || port > 65535) {
         return null;
      }
      String host = s.substring(0, colon).trim().toLowerCase(Locale.ROOT);
      if (host.equals("localhost")) {
         return new Endpoint("127.0.0.1", port);
      }
      return host.matches("127(\\.\\d{1,3}){3}") ? new Endpoint(host, port) : null;
   }

   static boolean isLocal(String server) {
      return local(server) != null;
   }

   /** Whether this launcher has a whirl to start (bundled, given, or built in the checkout). */
   static boolean available(Layout l) {
      return find(l) != null;
   }

   /** The whirl binary this launcher would run, or null (see the class comment for the order). */
   static File find(Layout l) {
      String exe = Layout.isWindows() ? "whirl.exe" : "whirl";
      String forced = System.getProperty("freeworlds.whirl", System.getenv("FREEWORLDS_WHIRL"));
      if (forced != null && !forced.isEmpty()) {
         File f = new File(forced);
         return runnable(f) ? f : null;
      }
      List<File> c = new ArrayList<>();
      bundled(c, l.libDir, exe);
      String lib = System.getProperty("freeworlds.bundledLib");
      if (lib != null && !lib.isEmpty()) {
         bundled(c, new File(lib), exe);
      }
      File repo = checkout(l);
      if (repo != null) {
         c.add(new File(repo, "server/whirl/target/release/" + exe));
         c.add(new File(repo, "server/whirl/target/debug/" + exe));
      }
      for (File f : c) {
         if (runnable(f)) {
            return f;
         }
      }
      return null;
   }

   private static void bundled(List<File> c, File lib, String exe) {
      c.add(new File(lib, "whirl/" + exe));
      if (lib.getParentFile() != null) {
         c.add(new File(lib.getParentFile(), "whirl/" + exe));
      }
   }

   /** The repository above the launcher or the game data (server/whirl/Cargo.toml), or null. */
   private static File checkout(Layout l) {
      for (File start : new File[]{l.libDir, l.gameRoot}) {
         File d = start;
         for (int i = 0; d != null && i < 6; i++, d = d.getParentFile()) {
            if (new File(d, "server/whirl/Cargo.toml").isFile()) {
               return d;
            }
         }
      }
      return null;
   }

   private static boolean runnable(File f) {
      // una copia que perdio el bit de ejecucion (zip, jpackage) se arregla si se puede
      return f.isFile() && (Layout.isWindows() || f.canExecute() || f.setExecutable(true));
   }

   /** Whether something accepts TCP connections on ip:port (a connect that closes at once: whirl takes it as a disconnect). */
   static boolean listening(String ip, int port) {
      try (Socket s = new Socket()) {
         s.connect(new InetSocketAddress(ip, port), 500);
         return true;
      } catch (IOException e) {
         return false;
      }
   }

   /**
    * Starts whirl for a world server choice on this machine when nothing
    * listens on its port, and waits until the distributor and the hub
    * listen. Returns null when there is nothing to start (a remote server,
    * no server, or one already listening, which is then used).
    *
    * @throws IOException when whirl is needed and there is none, or it does not start
    */
   static LocalWhirl startIfNeeded(Layout l, String server, Log log) throws IOException {
      Endpoint e = local(server);
      if (e == null) {
         return null;
      }
      if (listening(e.ip, e.port)) {
         log.line("[whirl] ya hay un servidor escuchando en " + e + ": se usa ese (no se arranca whirl)");
         return null;
      }
      File bin = find(l);
      if (bin == null) {
         throw new IOException("whirl local: no hay binario de whirl para " + e + " (ni " + new File(l.libDir, "whirl")
            + " ni server/whirl/target de un checkout; compilalo con \"cargo build --release\" en server/whirl"
            + " o da su ruta con -Dfreeworlds.whirl=RUTA o FREEWORLDS_WHIRL)");
      }
      int hub = DEFAULT_HUB_PORT;
      if (hub == e.port || listening(e.ip, hub)) {
         hub = freePort(e.ip);
      }
      LocalWhirl w = new LocalWhirl(bin, new File(l.dataDir, "whirl"), e, hub, l, log);
      w.start();
      return w;
   }

   private static int freePort(String ip) throws IOException {
      try (ServerSocket s = new ServerSocket(0, 1, InetAddress.getByName(ip))) {
         return s.getLocalPort();
      }
   }

   private void start() throws IOException {
      File conf = new File(dir, ".whirl/Config.toml");
      Files.createDirectories(conf.getParentFile().toPath());
      Files.write(conf.toPath(), config().getBytes(StandardCharsets.UTF_8));
      ProcessBuilder pb = new ProcessBuilder(bin.getPath(), "run", "distributor,hub").directory(dir).redirectErrorStream(true);
      // DISABLE_PROMPT=true (heredado, o de un .env que dotenv encuentre subiendo
      // desde dir) dejaria el bucle de sleep(0); EXIT_ON_CLIENT_DISCONNECT=true
      // lo cerraria con la primera desconexion (whirl_server/src/lib.rs:98)
      pb.environment().put("DISABLE_PROMPT", "false");
      pb.environment().put("EXIT_ON_CLIENT_DISCONNECT", "false");
      pb.environment().put("LOG_FILE", "false");
      log.line("[whirl] " + bin + " run distributor,hub (directorio " + dir + ", registro " + output.path + ")");
      Process p = pb.start();
      synchronized (this) {
         process = p;
         // abierto y sin escribir hasta stop(): ver el comentario de la clase
         stdin = p.getOutputStream();
      }
      Thread pump = new Thread(() -> pump(p), "freeworlds-whirl");
      pump.setDaemon(true);
      pump.start();
      hook = new Thread(this::stop, "freeworlds-whirl-stop");
      Runtime.getRuntime().addShutdownHook(hook);
      String err = awaitReady(p);
      if (err != null) {
         synchronized (this) {
            for (String t : tail) {
               log.line("[whirl]   " + t);
            }
         }
         stop();
         throw new IOException("whirl no arranco: " + err + " (registro: " + output.path + ")");
      }
      log.line("[whirl] listo: distributor " + where + ", hub " + where.ip + ":" + hubPort + " (pid " + p.pid() + ")");
   }

   /** The Config.toml of tools/run-whirl.sh (from server/whirl/.whirl/Config.example.toml). */
   private String config() {
      return "# Generado por el lanzador de FreeWorlds (LocalWhirl.java), como tools/run-whirl.sh\n"
         + "version = \"0.1.0\"\n\n"
         + "[whirlsplash]\n"
         + "worldsmaster_username = \"WORLDSMASTER\"\n"
         + "ip = \"" + where.ip + "\"\n"
         + "api.port = 8080\n\n"
         + "[whirlsplash.prompt]\n"
         + "enable = true\n"
         + "ps1 = \"[WORLDSMASTER@Whirlsplash ~]$\"\n\n"
         + "[whirlsplash.log]\n"
         + "enable = true\n"
         + "level = " + LOG_LEVEL + "\n"
         + "everything = false\n"
         + "test = false\n"
         + "file = false\n\n"
         + "[distributor]\n"
         + "worldsmaster_greeting = \"Welcome to Whirlsplash!\"\n"
         + "port = " + where.port + "\n\n"
         + "[hub]\n"
         + "port = " + hubPort + "\n";
   }

   /** Copies whirl's output to its log, notes when both servers listen, and passes errors on to the session log. */
   private void pump(Process p) {
      String distributor = "now listening at " + where;
      String hub = "now listening at " + where.ip + ":" + hubPort;
      try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream(), StandardCharsets.UTF_8))) {
         for (String s; (s = r.readLine()) != null; ) {
            output.line(s);
            // la primera linea llega pegada al prompt ("...~]$ INFO [whirl_server] ...")
            String t = s.trim();
            boolean bad = t.contains("panicked") || t.contains("had a problem and crashed");
            synchronized (this) {
               distributorUp |= t.endsWith(distributor);
               hubUp |= t.endsWith(hub);
               if (bad && failure == null) {
                  failure = t;
               }
               tail.addLast(t);
               if (tail.size() > 8) {
                  tail.removeFirst();
               }
               notifyAll();
            }
            if (bad || t.contains("ERROR [") || t.contains("WARN [")) {
               log.line("[whirl] " + t);
            }
         }
      } catch (IOException e) {
         // fin de la tuberia: el proceso termino
      } finally {
         boolean expected;
         synchronized (this) {
            ended = true;
            expected = stopping;
            notifyAll();
         }
         if (!expected) {
            log.line("[whirl] whirl termino por su cuenta (ver " + output.path + ")");
         }
         output.close();
      }
   }

   /** null when both servers listen, else why not. */
   private synchronized String awaitReady(Process p) {
      long end = System.currentTimeMillis() + START_TIMEOUT_MS;
      while (!(distributorUp && hubUp)) {
         if (failure != null) {
            return failure;
         }
         if (ended || !p.isAlive()) {
            return "whirl termino" + (p.isAlive() ? "" : " con codigo " + p.exitValue());
         }
         long left = end - System.currentTimeMillis();
         if (left <= 0) {
            return "no escucha en " + (distributorUp ? "" : where + " ") + (hubUp ? "" : where.ip + ":" + hubPort + " ")
               + "tras " + START_TIMEOUT_MS / 1000 + " s";
         }
         try {
            wait(Math.min(left, 250));
         } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return "espera interrumpida";
         }
      }
      return null;
   }

   /** Stops whirl: "exit" at its prompt, then the process is destroyed if it is still there. Idempotent. */
   void stop() {
      Process p;
      OutputStream in;
      synchronized (this) {
         p = process;
         in = stdin;
         process = null;
         stdin = null;
         stopping = true;
      }
      if (p == null) {
         return;
      }
      try {
         if (p.isAlive()) {
            try {
               in.write("exit\n".getBytes(StandardCharsets.US_ASCII));
               in.flush();
            } catch (IOException e) {
               // ya no lee: se destruye abajo
            }
            if (!p.waitFor(2, TimeUnit.SECONDS)) {
               p.destroy();
               if (!p.waitFor(2, TimeUnit.SECONDS)) {
                  p.destroyForcibly();
               }
            }
         }
      } catch (InterruptedException e) {
         p.destroyForcibly();
         Thread.currentThread().interrupt();
      }
      try {
         in.close();
      } catch (IOException e) {
         // nada que hacer
      }
      if (hook != null && Thread.currentThread() != hook) {
         try {
            Runtime.getRuntime().removeShutdownHook(hook);
         } catch (IllegalStateException e) {
            // la JVM ya se esta cerrando: el gancho lo parara (no-op)
         }
      }
      log.line("[whirl] parado" + (p.isAlive() ? "" : " (codigo " + p.exitValue() + ")"));
   }

   // ------------------------------------------------------ inicio de sesion

   /**
    * Fills in the 2004 LoginWizard for a world server on this machine, with
    * what the client itself keeps in worlds.ini, section [host:port]
    * (Galaxy.getIniSection): the wizard always opens (Galaxy.setGalaxyType,
    * Galaxy.java:505-508) and only signs in from its Sign In button
    * (LoginWizard.activeCallback, LoginWizard.java:276-281, the only caller
    * of Galaxy.setAuthInfo; nothing in the bytecode sets STATE_AUTO_LOGIN),
    * so what can be done is to open it with both fields filled:
    *
    * <ul>
    * <li>User0: with no user the wizard opens on ACCOUNT_TYPE (LoginWizard.java:160),
    *     whose Next registers through a web page of 2004; the launcher's user,
    *     else the one the client saved, else {@link #defaultUser()};</li>
    * <li>Password0: Console.encode of {@link #LOCAL_PASSWORD} when there is
    *     none that decodes (Console.decode, Console.java:595-615); the wizard
    *     then shows it with "Remember my Password" checked
    *     (LoginWizard.java:380-386) and the user only clicks Sign In.</li>
    * </ul>
    */
   static void prefillLogin(Layout l, String server, String user, Log log) {
      if (local(server) == null) {
         return;
      }
      String section = server.trim();
      File ini = Install.findNoCase(l.workDir, "worlds.ini");
      if (ini == null) {
         ini = new File(l.workDir, "worlds.ini");
      }
      try {
         String name = user == null ? "" : user.trim();
         if (name.isEmpty()) {
            String saved = Install.getKey(ini, section, "User0");
            if (saved == null || saved.isEmpty()) {
               name = defaultUser();
               Install.setKey(ini, section, "User0", name);
            } else {
               name = saved;
            }
         }
         boolean remembered = decodePassword(l, Install.getKey(ini, section, "Password0")) != null;
         if (!remembered) {
            String enc = encodePassword(l, LOCAL_PASSWORD);
            if (enc != null) {
               Install.setKey(ini, section, "Password0", enc);
               remembered = true;
            }
         }
         log.line("[whirl] inicio de sesion en " + section + ": usuario " + name
            + (remembered ? ", contrasena recordada (whirl no la comprueba): en el juego basta con pulsar Sign In"
               : "; escribe cualquier contrasena de 4 o mas letras o cifras (whirl no la comprueba)"));
      } catch (IOException e) {
         log.line("[whirl] no se pudo preparar el inicio de sesion en " + ini + ": " + e);
      }
   }

   /**
    * Name for a local world server when the launcher has none: the system
    * account's, with what FriendsListPart.isValidUserName accepts (letters,
    * digits, _ and -, 2 to 16), or "Jugador".
    */
   static String defaultUser() {
      StringBuilder b = new StringBuilder();
      for (char c : System.getProperty("user.name", "").toCharArray()) {
         if (b.length() < 16 && (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c == '_' || c == '-')) {
            b.append(c);
         }
      }
      return b.length() >= 2 ? b.toString() : "Jugador";
   }

   /**
    * Console.encode(plain) as this machine's client will decode it: the
    * bridge's NativeUiConsole.encrypt (gamma.dll 0x0040b7f0), loaded from
    * worldsplayer.jar rather than copied, with {@link #volumeSerial}, in hex.
    * null when the bridge is not there.
    */
   static String encodePassword(Layout l, String plain) {
      Object c = cipher(l, "encrypt", new Class<?>[]{String.class, int.class, int.class},
         plain, ThreadLocalRandom.current().nextInt(256), volumeSerial(l.workDir));
      if (!(c instanceof String)) {
         return null;
      }
      StringBuilder hex = new StringBuilder();
      for (char ch : ((String) c).toCharArray()) {
         String h = Integer.toHexString(ch);
         hex.append(h.length() == 1 ? "0" : "").append(h);
      }
      return hex.toString();
   }

   /** Console.decode: the password a Password0 value gives this machine's client, or null. */
   static String decodePassword(Layout l, String hex) {
      if (hex == null || hex.isEmpty() || hex.length() % 2 != 0) {
         return null;
      }
      char[] c = new char[hex.length() / 2];
      try {
         for (int i = 0; i < c.length; i++) {
            c[i] = (char) Integer.parseInt(hex.substring(2 * i, 2 * i + 2), 16);
         }
      } catch (NumberFormatException e) {
         return null;
      }
      Object p = cipher(l, "decrypt", new Class<?>[]{String.class, int.class}, new String(c), volumeSerial(l.workDir));
      return p instanceof String && !((String) p).isEmpty() ? (String) p : null;
   }

   private static Object cipher(Layout l, String method, Class<?>[] types, Object... args) {
      File jar = l.jar("worldsplayer.jar");
      if (!jar.isFile()) {
         return null;
      }
      try (URLClassLoader cl = new URLClassLoader(new URL[]{jar.toURI().toURL()}, null)) {
         return cl.loadClass("NET.worlds.core.NativeUiConsole").getMethod(method, types).invoke(null, args);
      } catch (ReflectiveOperationException | IOException | RuntimeException | LinkageError e) {
         return null;
      }
   }

   /**
    * The volume serial (DAT_0049fa6c) the bridge gives the client, whose
    * working directory is dir: NativeUiStartup.computeVolumeInfo takes
    * unix:dev of it, 0 without the unix view (Windows). Worked out here, not
    * called: on failure it ends the JVM with gamma.dll's assertion.
    */
   static int volumeSerial(File dir) {
      try {
         return (int) ((Number) Files.getAttribute(dir.toPath(), "unix:dev")).longValue();
      } catch (UnsupportedOperationException | IllegalArgumentException | IOException e) {
         return 0;
      }
   }
}

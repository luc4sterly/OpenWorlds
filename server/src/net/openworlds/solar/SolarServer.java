package net.openworlds.solar;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.security.GeneralSecurityException;
import java.text.SimpleDateFormat;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.CopyOnWriteArrayList;

/**
 * J Solar Server: a world server for the 2004 WorldsPlayer client, written
 * from the client's own protocol code (NET.worlds.network) and the
 * LibreWorlds wiki (protocol/LibreWorlds-wiki-master/).
 *
 * <p>One port does everything the old distributor, user server and room
 * servers did: the client asks for the server's properties (PROPREQ; we
 * answer "user server with accounts", VAR_SERVERTYPE 1), signs in
 * (SESSINIT), asks for room numbers (ROOMIDRQ, answered with ROOMID on the
 * same connection instead of a REDIRID to another server), subscribes to the
 * rooms it can see (SUBSCRIB) and then reports where it is (TELEPORT,
 * ROOMCHNG, LONGLOC) and what it says (TEXT, WHISPER). The server shows every
 * player to the others subscribed to their room: REGOBJID gives the player a
 * short id in each client, APPRACTR or TELEPORT makes the avatar appear,
 * LONGLOC moves it, PROPUPD carries the avatar and sleep state, and TELEPORT
 * or DISAPPR takes it away.
 *
 * <p>All world state is guarded by one lock; sending only queues bytes on
 * each {@link Client}, so the lock is never held across network I/O.
 */
public final class SolarServer {
   /** Receives what the admin window shows: log lines and "something changed". */
   public interface Listener {
      void log(String line);

      default void changed() {
      }
   }

   /** A player as the admin window lists them. */
   public static final class PlayerInfo {
      public final String name;
      public final String room;
      public final String address;
      public final boolean guest;
      public final boolean vip;
      public final boolean admin;
      public final boolean secure;
      public final long since;

      PlayerInfo(Client c, String room) {
         this.name = c.name;
         this.room = room;
         this.address = c.address;
         this.guest = c.guest;
         this.vip = c.account != null && c.account.vip;
         this.admin = c.account != null && c.account.admin;
         this.secure = c.secure;
         this.since = c.connectedAt;
      }
   }

   /** An account as the admin window lists them. */
   public static final class AccountInfo {
      public final String name;
      public final boolean vip;
      public final boolean admin;
      public final boolean banned;
      public final boolean online;
      public final long created;
      public final long lastSeen;
      public final String avatar;

      AccountInfo(Accounts.Account a, boolean online) {
         this.name = a.name;
         this.vip = a.vip;
         this.admin = a.admin;
         this.banned = a.banned;
         this.online = online;
         this.created = a.created;
         this.lastSeen = a.lastSeen;
         this.avatar = a.avatar;
      }
   }

   private static final int PROTOCOL = 24;
   /** Drone interpolation time sent as VAR_UPDATETIME (in microseconds; the client divides by 1000): the pilot reports every ~0.5 s. */
   private static final String UPDATE_TIME_US = "600000";
   private static final int MAX_LOG = 2000;

   final File dataDir;
   final Config config;
   final Accounts accounts;
   private final Object lock = new Object();
   private final List<Listener> listeners = new CopyOnWriteArrayList<>();
   private final Set<Client> connections = new LinkedHashSet<>();
   /** Signed-in players by lower-case name. */
   private final Map<String, Client> online = new LinkedHashMap<>();
   private final Map<String, Integer> roomIds = new HashMap<>();
   private final Map<Integer, String> roomNames = new HashMap<>();
   /** Shared state of rooms and objects (PROPSET to a room or object), by long ObjID, then property id. */
   private final Map<String, Map<Integer, Props.Prop>> shared = new HashMap<>();
   private final Map<String, Long> kickedUntil = new HashMap<>();
   private final Deque<String> recent = new ArrayDeque<>();
   private int nextRoom = 1;
   private int guestNumber;
   private ServerSocket plain;
   private ServerSocket secure;
   private Tls tls;
   private volatile boolean running;
   private long startedAt;
   private PrintWriter logFile;

   public SolarServer(File dataDir) throws IOException {
      this.dataDir = dataDir;
      dataDir.mkdirs();
      this.config = Config.load(new File(dataDir, "server.properties"));
      if (!config.file.isFile()) {
         config.save();
      }
      this.accounts = Accounts.load(new File(dataDir, "accounts.tsv"));
   }

   public static String version() {
      String v = SolarServer.class.getPackage().getImplementationVersion();
      return v == null ? "dev" : v;
   }

   public void addListener(Listener l) {
      listeners.add(l);
   }

   public void removeListener(Listener l) {
      listeners.remove(l);
   }

   // ================================================================ running

   public boolean isRunning() {
      return running;
   }

   public long startedAt() {
      return startedAt;
   }

   /** Opens the configured ports; throws with a readable message if one cannot be opened. */
   public void start() throws IOException, GeneralSecurityException {
      synchronized (lock) {
         if (running) {
            return;
         }
         if (!config.plainEnabled && !config.tlsEnabled) {
            throw new IOException("Both the normal and the encrypted port are turned off.");
         }
         InetAddress bind = config.bind.isEmpty() || config.bind.equals("0.0.0.0") ? null : InetAddress.getByName(config.bind);
         try {
            if (config.plainEnabled) {
               plain = new ServerSocket(config.port, 50, bind);
            }
            if (config.tlsEnabled) {
               tls = Tls.load(config, dataDir);
               secure = tls.listen(config.tlsPort, bind);
            }
         } catch (IOException | GeneralSecurityException e) {
            closeListeners();
            throw e;
         }
         running = true;
         startedAt = System.currentTimeMillis();
      }
      if (plain != null) {
         accept(plain, false);
         log("[solar] listening on port " + plain.getLocalPort());
      }
      if (secure != null) {
         accept(secure, true);
         log("[solar] listening on port " + secure.getLocalPort() + " (encrypted, TLS; certificate " + tls.fingerprint() + ")");
      }
      log("[solar] ready: " + config.name + " (J Solar Server " + version() + ", " + accounts.size() + " accounts)");
      changed();
   }

   public void stop() {
      List<Client> all;
      synchronized (lock) {
         if (!running) {
            return;
         }
         running = false;
         closeListeners();
         all = new ArrayList<>(connections);
         for (Client c : all) {
            if (c.loggedIn) {
               c.send(text(config.sender, "The server is stopping. See you soon!"));
            }
            c.kick("server stopped");
         }
      }
      log("[solar] stopped");
      changed();
   }

   private void closeListeners() {
      for (ServerSocket s : new ServerSocket[]{plain, secure}) {
         if (s != null) {
            try {
               s.close();
            } catch (IOException ignored) {
               // closing anyway
            }
         }
      }
      plain = null;
      secure = null;
   }

   private void accept(ServerSocket listener, boolean encrypted) {
      Thread t = new Thread(() -> {
         while (running && !listener.isClosed()) {
            try {
               Socket s = listener.accept();
               Client c = new Client(this, s, encrypted);
               synchronized (lock) {
                  connections.add(c);
               }
               c.start();
            } catch (SocketException e) {
               break; // listener closed by stop()
            } catch (IOException e) {
               log("[solar] accept failed: " + e.getMessage());
            }
         }
      }, encrypted ? "solar-accept-tls" : "solar-accept");
      t.setDaemon(true);
      t.start();
   }

   /** The normal port actually listening (useful when the configured one is 0), or -1. */
   public int boundPort() {
      ServerSocket s = plain;
      return s == null ? -1 : s.getLocalPort();
   }

   /** The encrypted port actually listening, or -1. */
   public int boundTlsPort() {
      ServerSocket s = secure;
      return s == null ? -1 : s.getLocalPort();
   }

   /** The TLS certificate fingerprint (loading or creating the certificate if needed). */
   public String fingerprint() throws IOException, GeneralSecurityException {
      Tls t = tls != null ? tls : Tls.load(config, dataDir);
      return t.fingerprint();
   }

   /** Replaces the generated self-signed certificate with a new one (takes effect on the next start). */
   public void regenerateCertificate() throws IOException, GeneralSecurityException {
      Tls.generate(Tls.generatedKeystore(dataDir), config.name);
      tls = null;
      log("[solar] made a new TLS certificate: " + fingerprint());
   }

   // ================================================================ protocol

   /** One packet from a client (reader thread). */
   void handle(Client c, Packet p) throws IOException {
      if (!c.loggedIn && p.command == Packet.SESSINIT) {
         signIn(c, p); // takes the lock itself, after the password work
         return;
      }
      synchronized (lock) {
         if (c.isClosed()) {
            return;
         }
         if (!c.loggedIn) {
            switch (p.command) {
               case Packet.PROPREQ:
                  c.send(serverProperties());
                  break;
               case Packet.SESSEXIT:
                  sessionExit(c);
                  break;
               default:
                  break; // nothing else makes sense before signing in
            }
            return;
         }
         switch (p.command) {
            case Packet.PROPREQ:
               propertyRequest(c, p);
               break;
            case Packet.PROPSET:
               propertySet(c, p);
               break;
            case Packet.ROOMIDRQ:
               roomIdRequest(c, p);
               break;
            case Packet.SUBSCRIB:
               subscribe(c, p);
               break;
            case Packet.UNSUBSCR:
               unsubscribe(c, p.u16());
               break;
            case Packet.SUBDIST:
               break; // everyone in a subscribed room is shown whatever the distance
            case Packet.TELEPORT:
               teleport(c, p);
               break;
            case Packet.ROOMCHNG:
               roomChange(c, p);
               break;
            case Packet.LONGLOC:
               longLoc(c, p.s16(), p.s16(), p.s16(), p.s16());
               break;
            case Packet.SHORTLOC:
               longLoc(c, c.x + (byte) p.u8(), c.y + (byte) p.u8(), c.z, (c.dir + (byte) p.u8() + 360) % 360);
               break;
            case Packet.TEXT:
               text(c, p);
               break;
            case Packet.WHISPER:
               whisper(c, p);
               break;
            case Packet.BUDDYLISTUPDATE:
               buddyUpdate(c, p.utf(), p.u8());
               break;
            case Packet.CHANNEL:
               log("[solar] " + c.name + " changes to channel \"" + p.utf() + "\"");
               break;
            case Packet.SESSEXIT:
               sessionExit(c);
               break;
            default:
               break;
         }
      }
   }

   /** PROPUPD to the connection itself (ObjID 255): what kind of server this is. */
   private byte[] serverProperties() {
      Packet.Out o = new Packet.Out();
      Props.write(o, Props.Prop.text(Props.APPNAME, 0, 0, "J Solar Server"));
      Props.write(o, Props.Prop.text(Props.PROTOCOL, 0, 0, Integer.toString(PROTOCOL)));
      Props.write(o, Props.Prop.text(Props.SERVERTYPE, 0, 0, "1"));
      Props.write(o, Props.Prop.text(Props.UPDATETIME, 0, 0, UPDATE_TIME_US));
      return o.packet(Packet.PO, Packet.PROPUPD);
   }

   /**
    * SESSINIT: signs a player in. Hashing and checking the password (PBKDF2,
    * a good fraction of a second) happens before taking the world's lock, so
    * a sign-in never makes everybody else stutter.
    */
   private void signIn(Client c, Packet p) throws IOException {
      Map<Integer, String> m = Props.readOld(p);
      String user = m.get(Props.USERNAME);
      String password = m.get(Props.PASSWORD);
      String newPassword = m.get(Props.NEW_PASSWD);
      boolean guestLogin = m.containsKey(Props.GUEST) || user == null || user.trim().isEmpty();
      try {
         c.protocol = Integer.parseInt(m.getOrDefault(Props.PROTOCOL, "0").trim());
      } catch (NumberFormatException e) {
         c.protocol = 0;
      }
      Accounts.Account account = null;
      boolean created = false;
      boolean newPasswordSet = false;
      String refusedWhy = null;
      int refusedCode = 0;
      if (!guestLogin) {
         user = user.trim();
         if (!Accounts.validName(user)) {
            refusedCode = Props.NAK_BAD_USER;
            refusedWhy = "\"" + user + "\" is not a valid name";
         } else {
            account = accounts.get(user);
            if (account == null) {
               if (!config.openSignup) {
                  refusedCode = Props.NAK_NO_SUCH_USER;
                  refusedWhy = "no account " + user + " and sign-up is closed";
               } else {
                  try {
                     account = accounts.create(user, password);
                     created = true;
                  } catch (IllegalArgumentException e) {
                     refusedCode = Props.NAK_BAD_PASSWORD;
                     refusedWhy = "cannot create " + user + ": " + e.getMessage();
                  }
               }
            } else if (!Accounts.verify(account, password)) {
               refusedCode = Props.NAK_BAD_PASSWORD;
               refusedWhy = "wrong password for " + account.name;
            }
            if (refusedWhy == null && newPassword != null && !newPassword.isEmpty()) {
               try {
                  accounts.setPassword(account, newPassword);
                  newPasswordSet = true;
               } catch (IllegalArgumentException e) {
                  log("[solar] " + account.name + ": new password refused: " + e.getMessage());
               }
            }
         }
      }
      synchronized (lock) {
         if (c.isClosed()) {
            return;
         }
         if (created || newPasswordSet) {
            saveAccounts();
            log("[solar] " + (created ? "new account: " + account.name + " (from " + c.address + ")"
               : account.name + " changed their password"));
         }
         if (refusedWhy != null) {
            refuse(c, refusedCode, refusedWhy);
            return;
         }
         if (config.maxUsers > 0 && online.size() >= config.maxUsers) {
            refuse(c, Props.NAK_MAX_ORDINARY, "the server is full");
            return;
         }
         String name;
         if (guestLogin) {
            if (!config.guests) {
               refuse(c, Props.NAK_BAD_ACCOUNT, "guests are not allowed");
               return;
            }
            do {
               name = "guest-" + (++guestNumber);
            } while (online.containsKey(Accounts.key(name)) || accounts.get(name) != null);
         } else {
            if (account.banned) {
               refuse(c, Props.NAK_BAD_ACCOUNT, account.name + " is banned");
               return;
            }
            Long until = kickedUntil.get(Accounts.key(account.name));
            if (until != null && until > System.currentTimeMillis()) {
               refuse(c, Props.NAK_BAD_ACCOUNT, account.name + " was kicked a moment ago");
               return;
            }
            name = account.name;
            Client old = online.get(Accounts.key(name));
            if (old != null) {
               old.send(text(config.sender, "You signed in again from somewhere else, so this window was disconnected."));
               old.kick("signed in again elsewhere");
               leaveWorld(old);
            }
         }
         c.name = name;
         c.key = Accounts.key(name);
         c.account = account;
         c.guest = account == null;
         c.loggedIn = true;
         online.put(c.key, c);
         Packet.Out o = new Packet.Out();
         Props.old(o, Props.ERROR, "0");
         Props.old(o, Props.USERNAME, name);
         Props.old(o, Props.PRIV, Integer.toString(account == null ? 0 : account.privileges()));
         c.send(o.packet(Packet.CLIENT, Packet.SESSINIT));
         if (!config.welcome.trim().isEmpty()) {
            c.send(text(config.sender, config.welcomeFor(name)));
         }
         // an empty inventory, as the TRADE service sent it (WhisperManager "&|+inv>")
         c.send(new Packet.Out().longObjId("TRADE").utf("&|+inv>").packet(Packet.CLIENT, Packet.WHISPER));
         for (Client other : online.values()) {
            if (other != c && containsIgnoreCase(other.buddies(), name)) {
               other.send(buddyNotify(name, true));
            }
         }
         if (account != null) {
            account.lastSeen = System.currentTimeMillis();
            saveAccounts();
         }
         log("[solar] " + name + " signed in from " + c.address + (c.secure ? " (encrypted)" : "")
            + (account == null ? " as a guest" : account.admin ? " (admin)" : account.vip ? " (VIP)" : ""));
      }
      changed();
   }

   private void refuse(Client c, int error, String why) {
      Packet.Out o = new Packet.Out();
      Props.old(o, Props.ERROR, Integer.toString(error));
      c.send(o.packet(Packet.CLIENT, Packet.SESSINIT));
      c.kick("refused: " + why);
      log("[solar] refused " + c.address + ": " + why);
   }

   private void sessionExit(Client c) {
      Packet.Out o = new Packet.Out();
      Props.old(o, Props.ERROR, "0");
      c.send(o.packet(Packet.CLIENT, Packet.SESSEXIT));
      c.kick("signed out");
   }

   /** Reader thread's end for a connection (called once, outside any iteration). */
   void disconnected(Client c, String reason) {
      boolean wasOnline;
      synchronized (lock) {
         connections.remove(c);
         // a player replaced by a new sign-in with the same name already left the world then
         wasOnline = c.loggedIn && online.get(c.key) == c;
         if (wasOnline) {
            leaveWorld(c);
            online.remove(c.key);
            for (Client other : online.values()) {
               other.releaseId(c.key);
               if (containsIgnoreCase(other.buddies(), c.name)) {
                  other.send(buddyNotify(c.name, false));
               }
            }
            if (c.account != null) {
               c.account.lastSeen = System.currentTimeMillis();
               saveAccounts();
            }
         }
      }
      if (wasOnline) {
         log("[solar] " + c.name + " left" + (reason == null ? "" : " (" + reason + ")"));
         changed();
      }
   }

   /** Takes a player out of every other client's view. */
   private void leaveWorld(Client c) {
      for (Client v : online.values()) {
         if (v != c && v.shown.remove(c.key)) {
            about(v, c, new Packet.Out(), Packet.DISAPPR);
         }
      }
      c.room = 0;
   }

   // ------------------------------------------------------------ rooms

   private void roomIdRequest(Client c, Packet p) throws IOException {
      String name = p.utf();
      int id = roomId(name);
      c.send(new Packet.Out().utf(name).s16(id).packet(Packet.CLIENT, Packet.ROOMID));
   }

   private int roomId(String name) {
      Integer id = roomIds.get(name);
      if (id == null) {
         id = nextRoom++;
         if (nextRoom > 65000) {
            nextRoom = 1;
         }
         roomIds.put(name, id);
         roomNames.put(id, name);
      }
      return id;
   }

   private void subscribe(Client c, Packet p) throws IOException {
      int room = p.u16();
      if (!roomNames.containsKey(room)) {
         return;
      }
      c.subscribed.add(room);
      for (Client u : online.values()) {
         if (u != c && u.room == room && !c.shown.contains(u.key)) {
            show(c, u, false, 0, 1);
         }
      }
   }

   private void unsubscribe(Client c, int room) {
      c.subscribed.remove(room);
      for (Client u : online.values()) {
         if (u != c && u.room == room && c.shown.contains(u.key)) {
            hide(c, u, false);
         }
      }
   }

   /** Sends {@code o} as command {@code cmd} about player {@code u}: by short ObjID if the viewer has one for them, else by name. */
   private static void about(Client viewer, Client u, Packet.Out o, int cmd) {
      Integer id = viewer.ids.get(u.key);
      viewer.send(id != null ? o.packet(id, cmd) : o.packet(u.name, cmd));
   }

   /** Makes {@code u} appear in {@code viewer}'s client: APPRACTR, or TELEPORT when arriving. */
   private void show(Client viewer, Client u, boolean arriving, int exitType, int entryType) {
      viewer.idFor(u);
      Packet.Out o = new Packet.Out().s16(u.room);
      if (arriving) {
         o.u8(exitType).u8(entryType);
      }
      o.s16(u.x).s16(u.y).s16(u.z).s16(u.dir);
      about(viewer, u, o, arriving ? Packet.TELEPORT : Packet.APPRACTR);
      viewer.shown.add(u.key);
      sendProps(viewer, u, u.props.values());
   }

   /** Takes {@code u} away from {@code viewer}'s client: a TELEPORT out (walking away) or DISAPPR. */
   private void hide(Client viewer, Client u, boolean teleportOut) {
      if (!viewer.shown.remove(u.key)) {
         return;
      }
      if (teleportOut) {
         about(viewer, u, new Packet.Out().s16(0).u8(1).u8(0).s16(u.x).s16(u.y).s16(u.z).s16(u.dir), Packet.TELEPORT);
      } else {
         about(viewer, u, new Packet.Out(), Packet.DISAPPR);
      }
   }

   private void teleport(Client c, Packet p) throws IOException {
      int room = p.u16();
      int exitType = p.u8();
      int entryType = p.u8();
      int x = p.s16();
      int y = p.s16();
      int z = p.s16();
      int dir = p.s16();
      c.x = x;
      c.y = y;
      c.z = z;
      c.dir = dir;
      if (room == 0) {
         // leaving this server's rooms (another world, or signing out)
         for (Client v : online.values()) {
            if (v != c) {
               hide(v, c, true);
            }
         }
         c.room = 0;
         changed();
         return;
      }
      if (!roomNames.containsKey(room)) {
         return;
      }
      boolean moved = c.room != room;
      c.room = room;
      for (Client v : online.values()) {
         if (v == c) {
            continue;
         }
         boolean sees = v.subscribed.contains(room);
         if (v.shown.contains(c.key)) {
            if (sees) {
               about(v, c, new Packet.Out().s16(room).u8(exitType).u8(entryType).s16(x).s16(y).s16(z).s16(dir),
                  Packet.TELEPORT);
            } else {
               hide(v, c, true);
            }
         } else if (sees) {
            show(v, c, true, exitType, entryType);
         }
      }
      if (moved) {
         log("[solar] " + c.name + " is in " + roomLabel(room));
         changed();
      }
   }

   private void roomChange(Client c, Packet p) throws IOException {
      int room = p.u16();
      int x = p.s16();
      int y = p.s16();
      int z = p.s16();
      int dir = p.s16();
      if (!roomNames.containsKey(room)) {
         return;
      }
      c.room = room;
      c.x = x;
      c.y = y;
      c.z = z;
      c.dir = dir;
      for (Client v : online.values()) {
         if (v == c) {
            continue;
         }
         boolean sees = v.subscribed.contains(room);
         if (v.shown.contains(c.key)) {
            if (sees) {
               about(v, c, new Packet.Out().s16(room).s16(x).s16(y).s16(z).s16(dir), Packet.ROOMCHNG);
            } else {
               hide(v, c, false);
            }
         } else if (sees) {
            show(v, c, false, 0, 1);
         }
      }
      changed();
   }

   private void longLoc(Client c, int x, int y, int z, int dir) {
      c.x = x;
      c.y = y;
      c.z = z;
      c.dir = dir;
      if (c.room == 0) {
         return;
      }
      for (Client v : online.values()) {
         if (v != c && v.shown.contains(c.key)) {
            about(v, c, new Packet.Out().s16(x).s16(y).s16(z).s16(dir), Packet.LONGLOC);
         }
      }
   }

   // ------------------------------------------------------------ properties

   private void propertySet(Client c, Packet p) throws IOException {
      p.utf(); // "fromUser", always empty from the client
      List<Props.Prop> list = Props.readNew(p);
      if (list.isEmpty()) {
         return;
      }
      boolean self = p.shortId == Packet.CLIENT || (p.longId != null && p.longId.equalsIgnoreCase(c.name));
      if (self) {
         for (Props.Prop pr : list) {
            c.props.put(pr.id, pr);
            if (pr.id == Props.BITMAP && c.account != null) {
               c.account.avatar = pr.text();
            }
         }
         for (Client v : online.values()) {
            if (v != c && v.shown.contains(c.key)) {
               sendProps(v, c, list);
            }
         }
         changed();
         return;
      }
      // shared state of a room (ObjID 253 = the sender's current room) or of an object in it
      String target;
      int room;
      if (p.shortId == Packet.CURRENT_ROOM) {
         room = c.room;
         target = roomNames.get(room);
      } else if (p.longId != null) {
         target = p.longId;
         Integer r = roomIds.get(target);
         room = r != null ? r : c.room;
      } else {
         return;
      }
      if (target == null || room == 0) {
         return;
      }
      Map<Integer, Props.Prop> state = shared.computeIfAbsent(target, k -> new HashMap<>());
      for (Props.Prop pr : list) {
         state.put(pr.id, pr);
      }
      for (Client v : online.values()) {
         if (v.subscribed.contains(room)) {
            sendProps(v, target, list);
         }
      }
   }

   private void propertyRequest(Client c, Packet p) throws IOException {
      if (p.shortId == Packet.PO) {
         c.send(serverProperties());
         return;
      }
      Set<Integer> wanted = new LinkedHashSet<>();
      while (p.more()) {
         wanted.add(p.u8());
      }
      String target = p.longId;
      if (p.shortId == Packet.CURRENT_ROOM) {
         target = roomNames.get(c.room);
      } else if (target == null) {
         String key = c.keyForId(p.shortId);
         Client u = key == null ? null : online.get(key);
         if (u != null) {
            sendProps(c, u, filter(u.props.values(), wanted));
         }
         return;
      }
      if (target == null) {
         return;
      }
      Client u = online.get(Accounts.key(target));
      if (u != null && u != c) {
         // a drone asking for its avatar (Drone.attachToServer)
         sendProps(c, u.name, filter(u.props.values(), wanted));
         return;
      }
      Map<Integer, Props.Prop> state = shared.get(target);
      if (state != null) {
         sendProps(c, target, filter(state.values(), wanted));
      }
   }

   private static List<Props.Prop> filter(Collection<Props.Prop> props, Set<Integer> wanted) {
      List<Props.Prop> out = new ArrayList<>();
      for (Props.Prop pr : props) {
         if (wanted.isEmpty() || wanted.contains(pr.id)) {
            out.add(pr);
         }
      }
      return out;
   }

   /** PROPUPD about player {@code u}, split over several packets if needed. */
   private static void sendProps(Client to, Client u, Collection<Props.Prop> props) {
      Integer id = to.ids.get(u.key);
      if (id == null) {
         sendProps(to, u.name, props);
         return;
      }
      for (List<Props.Prop> chunk : chunks(props, 250)) {
         Packet.Out o = new Packet.Out();
         for (Props.Prop pr : chunk) {
            Props.write(o, pr);
         }
         to.send(o.packet(id, Packet.PROPUPD));
      }
   }

   /** PROPUPD for a long ObjID (a room, object or player name). */
   private static void sendProps(Client to, String objId, Collection<Props.Prop> props) {
      int room = 250 - 2 - Packet.utfLength(objId);
      if (room < 10) {
         return;
      }
      for (List<Props.Prop> chunk : chunks(props, room)) {
         Packet.Out o = new Packet.Out();
         for (Props.Prop pr : chunk) {
            Props.write(o, pr);
         }
         to.send(o.packet(objId, Packet.PROPUPD));
      }
   }

   private static List<List<Props.Prop>> chunks(Collection<Props.Prop> props, int limit) {
      List<List<Props.Prop>> out = new ArrayList<>();
      List<Props.Prop> cur = new ArrayList<>();
      int size = 0;
      for (Props.Prop pr : props) {
         if (pr.size() > limit) {
            continue; // cannot travel in one packet at all
         }
         if (size + pr.size() > limit && !cur.isEmpty()) {
            out.add(cur);
            cur = new ArrayList<>();
            size = 0;
         }
         cur.add(pr);
         size += pr.size();
      }
      if (!cur.isEmpty()) {
         out.add(cur);
      }
      return out;
   }

   // ------------------------------------------------------------ chat

   private void text(Client c, Packet p) throws IOException {
      p.objIdInData(); // the sender as the client wrote it (empty): the server says who it is
      String msg = p.utf();
      if (msg.isEmpty()) {
         return;
      }
      if (msg.startsWith("/") && command(c, msg)) {
         return;
      }
      boolean action = msg.startsWith("&|+");
      if (!action && c.flooding()) {
         c.send(text(config.sender, "Slow down a little: your last line was not sent."));
         return;
      }
      byte[] packet = text(c.name, msg);
      for (Client v : online.values()) {
         if (v == c || inEarshot(c, v)) {
            v.send(packet);
         }
      }
      if (!action) {
         chat(c.name + (c.room != 0 ? " [" + roomLabel(c.room) + "]" : "") + ": " + msg);
      }
   }

   /**
    * Whether {@code b} hears what {@code a} says: rooms are small and open
    * onto each other, so it is the same room or either of them seeing the
    * other's room (being subscribed to it).
    */
   private static boolean inEarshot(Client a, Client b) {
      return a.room != 0 && b.room != 0
         && (a.room == b.room || b.subscribed.contains(a.room) || a.subscribed.contains(b.room));
   }

   private void whisper(Client c, Packet p) throws IOException {
      String target = p.longId;
      if (target == null) {
         target = c.keyForId(p.shortId);
      }
      p.objIdInData();
      String msg = p.utf();
      if (target == null || target.equalsIgnoreCase("TRADE") || target.equalsIgnoreCase("world")) {
         return; // the old trading and "world" services are not there
      }
      Client to = online.get(Accounts.key(target));
      if (to == null) {
         if (!msg.startsWith("&|+")) {
            c.send(text(config.sender, target + " is not online right now."));
         }
         return;
      }
      if (!msg.startsWith("&|+") && c.flooding()) {
         c.send(text(config.sender, "Slow down a little: your last whisper was not sent."));
         return;
      }
      to.send(new Packet.Out().longObjId(c.name).utf(msg).packet(Packet.CLIENT, Packet.WHISPER));
   }

   private void buddyUpdate(Client c, String buddy, int add) {
      if (!Accounts.validName(buddy)) {
         return;
      }
      Set<String> list = c.buddies();
      if (add != 0) {
         if (!containsIgnoreCase(list, buddy)) {
            list.add(buddy);
         }
         c.send(buddyNotify(buddy, online.containsKey(Accounts.key(buddy))));
      } else {
         list.removeIf(b -> b.equalsIgnoreCase(buddy));
      }
      if (c.account != null) {
         saveAccounts();
      }
   }

   private static byte[] buddyNotify(String name, boolean on) {
      return new Packet.Out().utf(name).u8(on ? 1 : 0).packet(Packet.CLIENT, Packet.BUDDYLISTNOTIFY);
   }

   /** A TEXT packet from {@code sender}, cut to fit one packet. */
   static byte[] text(String sender, String msg) {
      String m = msg;
      while (4 + 2 + Packet.utfLength(sender) + 1 + Packet.utfLength(m) > 255) {
         m = m.substring(0, m.length() - 1);
      }
      return new Packet.Out().longObjId(sender).utf(m).packet(Packet.CLIENT, Packet.TEXT);
   }

   /** Chat commands; false when {@code msg} is not one (then it is said as normal chat). */
   private boolean command(Client c, String msg) {
      String[] w = msg.trim().split("\\s+", 3);
      String cmd = w[0].toLowerCase(Locale.ROOT);
      boolean admin = c.account != null && c.account.admin;
      switch (cmd) {
         case "/help":
            reply(c, "Commands: /who (who is online), /where NAME (which room someone is in)"
               + (admin ? ", and for admins: /say TEXT, /kick NAME, /ban NAME, /unban NAME, /vip NAME" : "") + ".");
            return true;
         case "/who": {
            List<String> names = new ArrayList<>();
            for (Client u : online.values()) {
               names.add(u.name);
            }
            reply(c, names.size() + " online: " + String.join(", ", names));
            return true;
         }
         case "/where": {
            Client u = w.length > 1 ? online.get(Accounts.key(w[1])) : null;
            reply(c, u == null ? "Nobody called " + (w.length > 1 ? w[1] : "that") + " is online."
               : u.name + " is in " + (u.room == 0 ? "no room yet" : roomLabel(u.room)) + ".");
            return true;
         }
         case "/say":
         case "/broadcast":
            if (!admin) {
               return false;
            }
            broadcast(msg.substring(w[0].length()).trim());
            return true;
         case "/kick":
         case "/ban":
         case "/unban":
         case "/vip":
            if (!admin) {
               return false;
            }
            if (w.length < 2) {
               reply(c, "Usage: " + cmd + " NAME");
               return true;
            }
            String result;
            switch (cmd) {
               case "/kick":
                  result = kick(w[1], "kicked by " + c.name) ? w[1] + " was disconnected." : w[1] + " is not online.";
                  break;
               case "/ban":
                  result = setBanned(w[1], true) ? w[1] + " is banned." : "No account " + w[1] + ".";
                  break;
               case "/unban":
                  result = setBanned(w[1], false) ? w[1] + " may come back." : "No account " + w[1] + ".";
                  break;
               default:
                  Accounts.Account a = accounts.get(w[1]);
                  result = a == null ? "No account " + w[1] + "." : setVip(a.name, !a.vip) ? a.name + " is " + (a.vip ? "now VIP." : "no longer VIP.") : "";
            }
            reply(c, result);
            return true;
         default:
            return false;
      }
   }

   private void reply(Client c, String msg) {
      c.send(text(config.sender, msg));
   }

   // ================================================================ admin

   /** A message from the server to everyone online. */
   public void broadcast(String msg) {
      if (msg == null || msg.trim().isEmpty()) {
         return;
      }
      synchronized (lock) {
         byte[] p = text(config.sender, msg.trim());
         for (Client v : online.values()) {
            v.send(p);
         }
      }
      chat(config.sender + " (to everyone): " + msg.trim());
   }

   /** Disconnects a player (who may sign in again after a minute). */
   public boolean kick(String name, String reason) {
      synchronized (lock) {
         Client c = online.get(Accounts.key(name));
         if (c == null) {
            return false;
         }
         c.send(text(config.sender, "You were disconnected by the server" + (reason == null ? "." : ": " + reason + ".")));
         kickedUntil.put(c.key, System.currentTimeMillis() + 60_000);
         c.kick(reason == null ? "kicked" : reason);
         leaveWorld(c);
         return true;
      }
   }

   public boolean setBanned(String name, boolean banned) {
      synchronized (lock) {
         Accounts.Account a = accounts.get(name);
         if (a == null) {
            return false;
         }
         a.banned = banned;
         saveAccounts();
         if (banned) {
            kick(a.name, "banned");
         } else {
            kickedUntil.remove(Accounts.key(a.name));
         }
      }
      log("[solar] " + name + (banned ? " banned" : " unbanned"));
      changed();
      return true;
   }

   /** VIP on or off; a player online sees it the next time they sign in. */
   public boolean setVip(String name, boolean vip) {
      synchronized (lock) {
         Accounts.Account a = accounts.get(name);
         if (a == null) {
            return false;
         }
         a.vip = vip;
         saveAccounts();
         Client c = online.get(Accounts.key(name));
         if (c != null) {
            c.send(text(config.sender, vip ? "You are VIP now! Sign in again to get the VIP features."
               : "Your VIP status was removed."));
         }
      }
      log("[solar] " + name + (vip ? " is VIP" : " is no longer VIP"));
      changed();
      return true;
   }

   public boolean setAdmin(String name, boolean admin) {
      synchronized (lock) {
         Accounts.Account a = accounts.get(name);
         if (a == null) {
            return false;
         }
         a.admin = admin;
         saveAccounts();
      }
      log("[solar] " + name + (admin ? " is an admin" : " is no longer an admin"));
      changed();
      return true;
   }

   /** Creates an account; throws IllegalArgumentException with the reason if it cannot. */
   public void createAccount(String name, String password, boolean vip, boolean admin) {
      synchronized (lock) {
         Accounts.Account a = accounts.create(name, password);
         a.vip = vip;
         a.admin = admin;
         saveAccounts();
      }
      log("[solar] account created: " + name);
      changed();
   }

   public void setPassword(String name, String password) {
      synchronized (lock) {
         Accounts.Account a = accounts.get(name);
         if (a == null) {
            throw new IllegalArgumentException("No account " + name + ".");
         }
         accounts.setPassword(a, password);
         saveAccounts();
      }
      log("[solar] new password for " + name);
   }

   public boolean deleteAccount(String name) {
      boolean ok;
      synchronized (lock) {
         kick(name, "account deleted");
         ok = accounts.delete(name);
         if (ok) {
            saveAccounts();
         }
      }
      if (ok) {
         log("[solar] account deleted: " + name);
         changed();
      }
      return ok;
   }

   public List<PlayerInfo> players() {
      synchronized (lock) {
         List<PlayerInfo> out = new ArrayList<>();
         for (Client c : online.values()) {
            out.add(new PlayerInfo(c, c.room == 0 ? "" : roomLabel(c.room)));
         }
         return out;
      }
   }

   public List<AccountInfo> accountList() {
      synchronized (lock) {
         List<AccountInfo> out = new ArrayList<>();
         for (Accounts.Account a : accounts.list()) {
            out.add(new AccountInfo(a, online.containsKey(Accounts.key(a.name))));
         }
         return out;
      }
   }

   public int onlineCount() {
      synchronized (lock) {
         return online.size();
      }
   }

   /** Recent log and chat lines, oldest first. */
   public List<String> recentLog() {
      synchronized (recent) {
         return new ArrayList<>(recent);
      }
   }

   /** "GroundZero#ChatElevator&lt;channel&gt;" as "GroundZero/ChatElevator". */
   private String roomLabel(int room) {
      String n = roomNames.get(room);
      if (n == null) {
         return "room " + room;
      }
      int lt = n.indexOf('<');
      if (lt > 0) {
         n = n.substring(0, lt);
      }
      return n.replace('#', '/');
   }

   private void saveAccounts() {
      try {
         accounts.save();
      } catch (IOException e) {
         log("[solar] could not save the accounts: " + e.getMessage());
      }
   }

   private static boolean containsIgnoreCase(Collection<String> names, String name) {
      for (String n : names) {
         if (n.equalsIgnoreCase(name)) {
            return true;
         }
      }
      return false;
   }

   // ================================================================ log

   private void chat(String line) {
      log("[chat] " + line);
   }

   void log(String line) {
      String stamped = new SimpleDateFormat("HH:mm:ss").format(new Date()) + " " + line;
      synchronized (recent) {
         recent.addLast(stamped);
         while (recent.size() > MAX_LOG) {
            recent.removeFirst();
         }
         try {
            if (logFile == null) {
               File dir = new File(dataDir, "logs");
               dir.mkdirs();
               logFile = new PrintWriter(new FileWriter(new File(dir,
                  "solar-" + new SimpleDateFormat("yyyy-MM-dd").format(new Date()) + ".log"), true), true);
            }
            logFile.println(stamped);
         } catch (IOException e) {
            // logging must never stop the server
         }
      }
      for (Listener l : listeners) {
         try {
            l.log(stamped);
         } catch (RuntimeException ignored) {
            // a broken listener does not stop the server
         }
      }
   }

   private void changed() {
      for (Listener l : listeners) {
         try {
            l.changed();
         } catch (RuntimeException ignored) {
            // a broken listener does not stop the server
         }
      }
   }
}

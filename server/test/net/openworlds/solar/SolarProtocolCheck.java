package net.openworlds.solar;

import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;
import java.net.SocketTimeoutException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import java.util.List;
import java.util.Map;

/**
 * J Solar Server against scripted clients that speak the protocol as the
 * 2004 client does (same packets, same order): sign-up and sign-in, a wrong
 * password, room numbers, subscribing and teleporting in, seeing the other
 * player (REGOBJID + APPRACTR / TELEPORT, their avatar by PROPUPD), movement,
 * chat, whispers, friends coming and going, shared room state, guests, a ban,
 * and the same sign-in over TLS with the certificate pinned by fingerprint.
 */
public final class SolarProtocolCheck {
   private static int failures;

   public static void main(String[] args) throws Exception {
      Path data = Files.createTempDirectory("solar-check");
      SolarServer server = new SolarServer(data.toFile());
      server.config.port = 0;
      server.config.tlsEnabled = true;
      server.config.tlsPort = 0;
      server.config.welcome = "Welcome {user}";
      server.start();
      try {
         run(server);
      } finally {
         server.stop();
      }
      if (failures > 0) {
         System.out.println("SolarProtocolCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("SolarProtocolCheck: all good");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FAIL  ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static void run(SolarServer server) throws Exception {
      int port = server.boundPort();
      System.out.println("Sign-in:");
      Fake alice = new Fake(new Socket("127.0.0.1", port));
      Packet props = alice.handshakeProps();
      check(props != null && "1".equals(prop(props, Props.SERVERTYPE)), "PROPUPD says user server (VAR_SERVERTYPE 1)");
      Packet si = alice.signIn("Alice", "secret1");
      check(si != null && "0".equals(Props.readOld(si).get(Props.ERROR)), "a new name creates its account and signs in");
      Packet welcome = alice.expect(Packet.TEXT);
      check(welcome != null && welcome.objIdInData().equals("Solar") && welcome.utf().equals("Welcome Alice"),
         "welcome message from the system sender");

      Fake mallory = new Fake(new Socket("127.0.0.1", port));
      mallory.handshakeProps();
      Packet bad = mallory.signIn("alice", "wrong");
      check(bad != null && "13".equals(Props.readOld(bad).get(Props.ERROR)), "wrong password: VAR_ERROR 13 (NAK_BAD_PASSWORD)");
      check(mallory.closedSoon(), "and the connection is closed");

      System.out.println("Rooms and seeing each other:");
      String roomName = "GroundZero#AvatarEnter";
      int room = alice.roomId(roomName);
      check(room > 0, "ROOMIDRQ answered with ROOMID " + room);
      alice.send(new Packet.Out().s16(room).s16(100).s16(200).s16(0).s16(900).packet(Packet.CLIENT, Packet.SUBSCRIB));
      alice.send(propSet(Packet.CLIENT, Props.Prop.text(Props.BITMAP, 64, 1, "avatar:holden.mov")));
      alice.send(new Packet.Out().s16(room).u8(0).u8(1).s16(100).s16(200).s16(0).s16(45).packet(Packet.CLIENT, Packet.TELEPORT));
      alice.roomId(roomName); // a round trip: the server handles a connection's packets in order

      Fake bob = new Fake(new Socket("127.0.0.1", port));
      bob.handshakeProps();
      check("0".equals(Props.readOld(bob.signIn("Bob", "hunter22")).get(Props.ERROR)), "a second player signs in");
      bob.expect(Packet.TEXT);
      check(bob.roomId(roomName) == room, "the same room name gets the same number");
      bob.send(new Packet.Out().s16(room).s16(150).s16(250).s16(0).s16(900).packet(Packet.CLIENT, Packet.SUBSCRIB));
      Packet reg = bob.expect(Packet.REGOBJID);
      String regName = reg == null ? null : reg.utf();
      int aliceId = reg == null ? -1 : reg.u8();
      check("Alice".equals(regName) && aliceId >= 2 && aliceId <= 127, "REGOBJID gives Alice a short id in Bob's client (" + aliceId + ")");
      Packet appear = bob.expect(Packet.APPRACTR);
      int ar = appear == null ? -1 : appear.u16();
      int ax = appear == null ? -1 : appear.s16();
      int ay = appear == null ? -1 : appear.s16();
      check(appear != null && appear.shortId == aliceId && ar == room && ax == 100 && ay == 200,
         "APPRACTR shows Alice where she stands (" + (appear == null ? "none" : appear.shortId + " in " + ar + " @ " + ax + "," + ay) + ")");
      Packet avatar = bob.expect(Packet.PROPUPD);
      check(avatar != null && avatar.shortId == aliceId && "avatar:holden.mov".equals(propNew(avatar, Props.BITMAP)),
         "PROPUPD carries Alice's avatar");

      bob.send(new Packet.Out().s16(room).u8(0).u8(1).s16(150).s16(250).s16(0).s16(90).packet(Packet.CLIENT, Packet.TELEPORT));
      Packet regBob = alice.expect(Packet.REGOBJID);
      int bobId = regBob == null ? -1 : (regBob.utf().equals("Bob") ? regBob.u8() : -1);
      Packet arrive = alice.expect(Packet.TELEPORT);
      check(bobId > 0 && arrive != null && arrive.shortId == bobId && arrive.u16() == room && arrive.u8() == 0 && arrive.u8() == 1,
         "Alice sees Bob arrive (TELEPORT, entry 1)");

      alice.send(new Packet.Out().s16(120).s16(210).s16(0).s16(50).packet(Packet.CLIENT, Packet.LONGLOC));
      Packet moved = bob.expect(Packet.LONGLOC);
      check(moved != null && moved.shortId == aliceId && moved.s16() == 120 && moved.s16() == 210, "Alice's LONGLOC reaches Bob");

      // a drone asks for its properties by name (Drone.attachToServer)
      bob.send(new Packet.Out().packet("Alice", Packet.PROPREQ));
      Packet asked = bob.expect(Packet.PROPUPD);
      check(asked != null && "Alice".equals(asked.longId) && "avatar:holden.mov".equals(propNew(asked, Props.BITMAP)),
         "PROPREQ for a player's name answers with their avatar");

      System.out.println("Chat, whispers, friends:");
      alice.send(new Packet.Out().longObjId("").utf("hello everyone").packet(Packet.CLIENT, Packet.TEXT));
      Packet heard = bob.expect(Packet.TEXT);
      check(heard != null && heard.objIdInData().equals("Alice") && heard.utf().equals("hello everyone"), "Bob hears Alice");
      Packet echo = alice.expect(Packet.TEXT);
      check(echo != null && echo.objIdInData().equals("Alice"), "Alice gets her own line back (the client shows it from the server)");

      bob.send(new Packet.Out().longObjId("").utf("psst").packet("Alice", Packet.WHISPER));
      Packet whisper = alice.expect(Packet.WHISPER);
      check(whisper != null && whisper.objIdInData().equals("Bob") && whisper.utf().equals("psst"), "Bob's whisper reaches Alice only");

      bob.send(new Packet.Out().utf("Alice").u8(1).packet(Packet.CLIENT, Packet.BUDDYLISTUPDATE));
      Packet online = bob.expect(Packet.BUDDYLISTNOTIFY);
      check(online != null && online.utf().equals("Alice") && online.u8() == 1, "adding Alice as a friend: she is online");

      System.out.println("Shared room state:");
      alice.send(propSet(Packet.CURRENT_ROOM, Props.Prop.text(40, 0, 0, "door open")));
      Packet sharedToBob = bob.expect(Packet.PROPUPD);
      check(sharedToBob != null && roomName.equals(sharedToBob.longId) && "door open".equals(propNew(sharedToBob, 40)),
         "PROPSET to the current room reaches the others by the room's name");
      Packet feedback = alice.expect(Packet.PROPUPD);
      check(feedback != null && roomName.equals(feedback.longId), "and comes back to the sender (Sharer waits for it)");

      System.out.println("Leaving:");
      alice.close();
      Packet gone = bob.expect(Packet.DISAPPR);
      check(gone != null && gone.shortId == aliceId, "Alice disconnects: DISAPPR for her in Bob's client");
      Packet offline = bob.expect(Packet.BUDDYLISTNOTIFY);
      check(offline != null && offline.utf().equals("Alice") && offline.u8() == 0, "and Bob's friends list shows her offline");

      System.out.println("Guests and bans:");
      Fake guest = new Fake(new Socket("127.0.0.1", port));
      guest.handshakeProps();
      Packet gsi = guest.signInGuest();
      Map<Integer, String> gp = gsi == null ? null : Props.readOld(gsi);
      check(gp != null && "0".equals(gp.get(Props.ERROR)) && gp.getOrDefault(Props.USERNAME, "").startsWith("guest-"),
         "a guest gets a guest-N name (" + (gp == null ? null : gp.get(Props.USERNAME)) + ")");
      guest.close();

      check(server.setBanned("Bob", true), "ban Bob from the admin side");
      check(bob.closedSoon(), "Bob is disconnected");
      Fake bob2 = new Fake(new Socket("127.0.0.1", port));
      bob2.handshakeProps();
      Packet banned = bob2.signIn("Bob", "hunter22");
      check(banned != null && "14".equals(Props.readOld(banned).get(Props.ERROR)), "a banned account is refused (VAR_ERROR 14)");
      bob2.close();
      server.setBanned("Bob", false);

      System.out.println("Encrypted (TLS):");
      String pin = server.fingerprint();
      String[] seen = {null};
      SSLContext ctx = SSLContext.getInstance("TLS");
      ctx.init(null, new TrustManager[]{new X509TrustManager() {
         @Override
         public void checkClientTrusted(X509Certificate[] chain, String authType) throws CertificateException {
            throw new CertificateException("not a server");
         }

         @Override
         public void checkServerTrusted(X509Certificate[] chain, String authType) throws CertificateException {
            seen[0] = Tls.fingerprint(chain[0]);
            if (!seen[0].equals(pin)) {
               throw new CertificateException("fingerprint " + seen[0] + " is not the pinned " + pin);
            }
         }

         @Override
         public X509Certificate[] getAcceptedIssuers() {
            return new X509Certificate[0];
         }
      }}, null);
      SSLSocket tls = (SSLSocket) ctx.getSocketFactory().createSocket("127.0.0.1", server.boundTlsPort());
      tls.startHandshake();
      check(pin.equals(seen[0]), "the certificate matches the pinned fingerprint " + pin.substring(0, 11) + "...");
      Fake secure = new Fake(tls);
      secure.handshakeProps();
      check("0".equals(Props.readOld(secure.signIn("Bob", "hunter22")).get(Props.ERROR)), "signing in over TLS works");
      boolean listed = false;
      for (SolarServer.PlayerInfo p : server.players()) {
         listed |= p.name.equals("Bob") && p.secure;
      }
      check(listed, "the admin side lists Bob as encrypted");
      secure.close();
   }

   private static byte[] propSet(int objId, Props.Prop p) {
      Packet.Out o = new Packet.Out().utf("");
      Props.write(o, p);
      return o.packet(objId, Packet.PROPSET);
   }

   private static String prop(Packet p, int id) throws IOException {
      return propNew(p, id);
   }

   private static String propNew(Packet p, int id) throws IOException {
      List<Props.Prop> list = Props.readNew(p);
      for (Props.Prop pr : list) {
         if (pr.id == id) {
            return pr.text();
         }
      }
      return null;
   }

   /** A scripted client. */
   private static final class Fake {
      private final Socket socket;
      private final InputStream in;
      private final OutputStream out;

      Fake(Socket socket) throws IOException {
         this.socket = socket;
         socket.setSoTimeout(3000);
         in = new BufferedInputStream(socket.getInputStream());
         out = socket.getOutputStream();
      }

      void send(byte[] p) throws IOException {
         out.write(p);
         out.flush();
      }

      /** The next packet of this command, skipping others; null after 3 s. */
      Packet expect(int command) throws IOException {
         long end = System.currentTimeMillis() + 3000;
         while (System.currentTimeMillis() < end) {
            Packet p;
            try {
               p = Packet.read(in);
            } catch (SocketTimeoutException e) {
               return null;
            }
            if (p == null) {
               return null;
            }
            if (p.command == command) {
               return p;
            }
            if (Boolean.getBoolean("solar.debug")) {
               System.out.println("    (skipped " + p + ")");
            }
         }
         return null;
      }

      Packet handshakeProps() throws IOException {
         send(new Packet.Out().packet(Packet.PO, Packet.PROPREQ));
         return expect(Packet.PROPUPD);
      }

      Packet signIn(String user, String password) throws IOException {
         Packet.Out o = new Packet.Out();
         Props.old(o, Props.PROTOCOL, "24");
         Props.old(o, Props.CLIENT, "1920");
         Props.old(o, Props.USERNAME, user);
         Props.old(o, Props.PASSWORD, password);
         Props.old(o, Props.LOGONOFF, "1");
         send(o.packet(Packet.CLIENT, Packet.SESSINIT));
         return expect(Packet.SESSINIT);
      }

      Packet signInGuest() throws IOException {
         Packet.Out o = new Packet.Out();
         Props.old(o, Props.PROTOCOL, "24");
         Props.old(o, Props.CLIENT, "1920");
         Props.old(o, Props.GUEST, "0");
         Props.old(o, Props.LOGONOFF, "1");
         send(o.packet(Packet.CLIENT, Packet.SESSINIT));
         return expect(Packet.SESSINIT);
      }

      int roomId(String name) throws IOException {
         send(new Packet.Out().utf(name).packet(Packet.CLIENT, Packet.ROOMIDRQ));
         Packet p = expect(Packet.ROOMID);
         if (p == null || !p.utf().equals(name)) {
            return -1;
         }
         return p.u16();
      }

      /** True if the server closes the connection within 3 s. */
      boolean closedSoon() {
         long end = System.currentTimeMillis() + 3000;
         try {
            while (System.currentTimeMillis() < end) {
               if (Packet.read(in) == null) {
                  return true;
               }
            }
         } catch (IOException e) {
            return !(e instanceof SocketTimeoutException);
         }
         return false;
      }

      void close() throws IOException {
         socket.close();
      }
   }
}

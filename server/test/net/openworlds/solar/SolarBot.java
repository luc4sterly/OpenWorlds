package net.openworlds.solar;

import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Socket;

/**
 * A scripted player for trying things out (not a check): signs in to a J
 * Solar Server, enters a room and walks round in a circle, so an original
 * client in the same room sees an avatar move (and animate).
 *
 * <pre>
 *   java -cp ... net.openworlds.solar.SolarBot [--host H] [--port P] [--name N] [--password W]
 *        [--room World#Room] [--x X --y Y --radius R] [--avatar URL] [--say TEXT] [--seconds S]
 * </pre>
 * Defaults: 127.0.0.1:6650, name "Walker", room GroundZero#AvatarEnter,
 * a circle of 250 around (0, 0), the penguin, 300 seconds.
 */
public final class SolarBot {
   private SolarBot() {
   }

   public static void main(String[] args) throws Exception {
      String host = "127.0.0.1";
      int port = 6650;
      String name = "Walker";
      String password = "walker1";
      String room = "GroundZero#AvatarEnter";
      int cx = 0;
      int cy = 0;
      int radius = 250;
      String avatar = null;
      String say = null;
      int seconds = 300;
      for (int i = 0; i + 1 < args.length; i += 2) {
         String v = args[i + 1];
         switch (args[i]) {
            case "--host":
               host = v;
               break;
            case "--port":
               port = Integer.parseInt(v);
               break;
            case "--name":
               name = v;
               break;
            case "--password":
               password = v;
               break;
            case "--room":
               room = v;
               break;
            case "--x":
               cx = Integer.parseInt(v);
               break;
            case "--y":
               cy = Integer.parseInt(v);
               break;
            case "--radius":
               radius = Integer.parseInt(v);
               break;
            case "--avatar":
               avatar = v;
               break;
            case "--say":
               say = v;
               break;
            case "--seconds":
               seconds = Integer.parseInt(v);
               break;
            default:
               throw new IllegalArgumentException("unknown option " + args[i]);
         }
      }
      int[] roomNumber = {0};
      try (Socket s = new Socket(host, port)) {
         s.setTcpNoDelay(true);
         OutputStream out = s.getOutputStream();
         InputStream in = new BufferedInputStream(s.getInputStream());
         String wanted = room;
         Thread reader = new Thread(() -> {
            try {
               Packet p;
               while ((p = Packet.read(in)) != null) {
                  if (p.command == Packet.ROOMID && p.utf().equals(wanted)) {
                     synchronized (roomNumber) {
                        roomNumber[0] = p.u16();
                        roomNumber.notifyAll();
                     }
                  } else if (p.command == Packet.TEXT) {
                     System.out.println("[bot] " + p.objIdInData() + "> " + p.utf());
                  } else if (p.command == Packet.SESSINIT) {
                     System.out.println("[bot] signed in: " + Props.readOld(p));
                  }
               }
            } catch (IOException e) {
               // connection closed
            }
            System.out.println("[bot] disconnected");
            System.exit(0);
         }, "bot-reader");
         reader.setDaemon(true);
         reader.start();
         out.write(new Packet.Out().packet(Packet.PO, Packet.PROPREQ));
         Packet.Out si = new Packet.Out();
         Props.old(si, Props.PROTOCOL, "24");
         Props.old(si, Props.CLIENT, "1920");
         Props.old(si, Props.USERNAME, name);
         Props.old(si, Props.PASSWORD, password);
         out.write(si.packet(Packet.CLIENT, Packet.SESSINIT));
         out.write(new Packet.Out().utf(room).packet(Packet.CLIENT, Packet.ROOMIDRQ));
         out.flush();
         int roomId;
         synchronized (roomNumber) {
            long until = System.currentTimeMillis() + 10_000;
            while (roomNumber[0] == 0 && System.currentTimeMillis() < until) {
               roomNumber.wait(500);
            }
            roomId = roomNumber[0];
         }
         if (roomId == 0) {
            System.out.println("[bot] no room number for " + room + " (wrong password?)");
            return;
         }
         if (avatar != null) {
            Packet.Out ps = new Packet.Out().utf("");
            Props.write(ps, Props.Prop.text(Props.BITMAP, 64, 1, avatar));
            out.write(ps.packet(Packet.CLIENT, Packet.PROPSET));
         }
         out.write(new Packet.Out().s16(roomId).s16(cx).s16(cy).s16(0).s16(2000).packet(Packet.CLIENT, Packet.SUBSCRIB));
         out.write(new Packet.Out().s16(roomId).u8(0).u8(1).s16(cx + radius).s16(cy).s16(0).s16(0)
            .packet(Packet.CLIENT, Packet.TELEPORT));
         out.flush();
         System.out.println("[bot] " + name + " walking in " + room + " (room " + roomId + ")");
         long end = System.currentTimeMillis() + seconds * 1000L;
         double a = 0;
         int n = 0;
         while (System.currentTimeMillis() < end) {
            a += 0.12;
            int x = (int) Math.round(cx + Math.cos(a) * radius);
            int y = (int) Math.round(cy + Math.sin(a) * radius);
            // direction as the client sends it: (-yaw + 90) mod 360, facing along the circle
            int dir = (int) Math.round(((Math.toDegrees(a) + 180) % 360 + 360) % 360);
            out.write(new Packet.Out().s16(x).s16(y).s16(0).s16(dir).packet(Packet.CLIENT, Packet.LONGLOC));
            if (say != null && n++ % 40 == 0) {
               out.write(new Packet.Out().longObjId("").utf(say).packet(Packet.CLIENT, Packet.TEXT));
            }
            out.flush();
            Thread.sleep(500);
         }
         out.write(new Packet.Out().s16(0).u8(1).u8(0).s16(cx).s16(cy).s16(0).s16(0).packet(Packet.CLIENT, Packet.TELEPORT));
         Packet.Out bye = new Packet.Out();
         Props.old(bye, Props.LOGONOFF, "1");
         out.write(bye.packet(Packet.CLIENT, Packet.SESSEXIT));
         out.flush();
         Thread.sleep(500);
      }
   }
}

package NET.worlds.network;

import NET.worlds.core.Std;
import java.net.Socket;

/**
 * Handshake probe — PHASE 3: uses the REAL class the client actually
 * instantiates (AutoServer), not a bare WorldServer.
 *
 * Investigation of the "state 7 kills the Main loop" paradox: WorldServer
 * is effectively abstract (state_XMIT_SI/state_XMIT_AI are
 * Debug.dAssert(false) — the "abstract by assert" pattern of this 90s
 * code). The real client NEVER instantiates a bare WorldServer:
 * ServerURL(String) sets _serverType = "AutoServer" by default (see the
 * constructor, when the URL carries no explicit type segment) and
 * ServerTracker.findOrMake does
 * Class.forName("NET.worlds.network." + type).newInstance() — for a normal
 * connection to a host:port, that is ALWAYS AutoServer.
 *
 * AutoServer.state_XMIT_SI() DOES have real logic: it reads property #15
 * (already present in the real PROPUPD captured from worlds.worlio.com,
 * docs/net-handshake-trace.log: "#15 [DBSTORE /POSSESS] 1"), detects the
 * server type, instantiates the matching concrete subclass (type 1 ->
 * UserServer), hands it the live connection (reuseConnection) and feeds
 * it the same props again (propertyUpdate) — and ONLY THEN sets its own
 * state to 17 (finished, it has specialized). It never touches the
 * dAssert.
 *
 * This probe tests that whole chain against the real server.
 *
 * Usage: java -cp <out> AutoServerProbe [host] [port]
 */
public final class AutoServerProbe extends AutoServer {
   private String connectedHost;
   private boolean socketDone;

   public AutoServerProbe() {
      super();
   }

   @Override
   protected synchronized void setSocket(Socket s, VarErrorException e, String h) {
      super.setSocket(s, e, h);
      this.connectedHost = h;
      this.socketDone = true;
      this.notifyAll();
   }

   public static void main(String[] args) throws Exception {
      String host = args.length > 0 ? args[0] : "worlds.worlio.com";
      int port = args.length > 1 ? Integer.parseInt(args[1]) : 6650;

      NET.worlds.core.Std.initProductName();

      AutoServerProbe probe = new AutoServerProbe();
      // The same "host:port" URL with no type segment that the real
      // client would use for a normal connection -> ServerURL._serverType
      // defaults to literally "AutoServer" (verified by reading
      // ServerURL.java directly, not assumed).
      ServerURL surl = new ServerURL("worldserver://" + host + ":" + port);
      probe.initInstance(Galaxy.getGalaxy("worldserver://" + host + ":" + port), surl);
      probe.state_Initializing();

      synchronized (probe) {
         long deadline = System.currentTimeMillis() + 20000;
         while (!probe.socketDone && System.currentTimeMillis() < deadline) {
            probe.wait(deadline - System.currentTimeMillis());
         }
      }
      if (!probe.socketDone) {
         System.out.println("NO SOCKET CALLBACK within 20s");
         System.exit(1);
      }
      System.out.println("connectedHost=" + probe.connectedHost
         + " state=" + stateName(probe._state.getState()));
      if (probe._sock == null) {
         System.out.println("connect failed: lastError=" + probe._lastError);
         System.exit(1);
      }

      probe.state_XMIT_PROPREQ();
      System.out.println("sent propReq, state=" + stateName(probe._state.getState()));

      int last = -99;
      long end = System.currentTimeMillis() + 25000;
      while (System.currentTimeMillis() < end) {
         int st = probe._state.getState();
         if (st != last) {
            System.out.println("state -> " + stateName(st));
            last = st;
         }
         if (st == 12 || st == 17 || st == -1) {
            break;
         }
         try {
            probe.perFrame(Std.getFastTime());
         } catch (Throwable t) {
            System.out.println("perFrame threw: " + t);
            t.printStackTrace(System.out);
            break;
         }
         Thread.sleep(200);
      }
      System.out.println("final state=" + stateName(probe._state.getState())
         + " serverType(from prop #15)=" + safeGetServerType(probe));
      try {
         if (probe._sock != null) probe._sock.close();
      } catch (Exception ignored) {
      }
      System.out.println("closed cleanly");
      System.exit(0);
   }

   private static int safeGetServerType(AutoServerProbe p) {
      try {
         return p.getServerType();
      } catch (Throwable t) {
         return -999;
      }
   }

   private static String stateName(int s) {
      switch (s) {
         case -1: return "-1 DEAD";
         case 0: return "0 PRECONNECTED";
         case 4: return "4 CONNECTING";
         case 5: return "5 XMIT_PROPREQ";
         case 6: return "6 RCV_PROPS";
         case 7: return "7 XMIT_SI";
         case 8: return "8 RCV_SI_ACK";
         case 9: return "9 XMIT_AI";
         case 10: return "10 RCV_AI_ACK";
         case 11: return "11 XMIT_PROPS";
         case 12: return "12 MAINLOOP";
         case 17: return "17 DISCONNECTED";
         default: return String.valueOf(s);
      }
   }
}

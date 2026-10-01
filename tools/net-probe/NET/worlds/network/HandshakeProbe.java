package NET.worlds.network;

import NET.worlds.core.Std;
import java.net.Socket;

/**
 * Handshake probe against a real WorldServer — PHASE 2: speaks the protocol.
 *
 * A 100% real path through the decompiled client, no UI/console/galaxy:
 *   1. state=4 + WSConnecting (the same as WorldServer.startConnect with
 *      _sock==null) → daemon threads + DNSLookup.lookupAll + Socket.
 *   2. REAL setSocket (super): ServerInputStream + netPacketReader thread
 *      + state 5. Here the host is only captured and notified.
 *   3. REAL state_XMIT_PROPREQ(): sends propReqCmd(ObjID(255)) via
 *      sendNetMsg — the FIRST packet the real client emits.
 *   4. REAL perFrame() in a loop (the state machine driver that normally
 *      runs in the Main loop) to process the reply.
 *
 * With netdebug=1152 in worlds.ini, sendNetMsg itself dumps the sent bytes
 * in hex (bit 1024) plus the description (bit 128), and bit 64 describes
 * what is received: the evidence comes from the real code, not from this
 * probe. A single connection per run, closed at the end.
 *
 * It lives outside source/ (it is a tool) but in the same package because
 * WSConnecting is package-private and setSocket/state/perFrame are
 * protected. Compile with --release 8 against out/worlds-mock.jar.
 *
 * Usage: java -cp <out> HandshakeProbe [host] [port]
 */
public final class HandshakeProbe extends WorldServer {
   private String connectedHost;
   private boolean socketDone;

   public HandshakeProbe() {
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

      // The same thing Gamma.main does at startup (Gamma.java): without it
      // Std.getProductName() blows up on an assert when netPacketReader
      // loads its packet table (whisperCmd -> Console.message ->
      // Console.<clinit> -> new GammaFrame() -> getDefaultTitle()).
      // NOTE: Console.<clinit> creates a real AWT Frame -> X is needed
      // (Xvfb will do, same as for the mocked client).
      NET.worlds.core.Std.initProductName();

      HandshakeProbe probe = new HandshakeProbe();
      // Real initInstance (ObjectMgr + WaitList + _serverURL): without it
      // sendNetMsg->toString->getLongID blows up (NPE on _serverURL).
      // Galaxy.getGalaxy only creates hashtables/trackers, no UI.
      ServerURL surl = new ServerURL("worldserver://" + host + ":" + port);
      probe.initInstance(Galaxy.getGalaxy("worldserver://" + host + ":" + port), surl);
      // REAL state_Initializing (not by hand): registers shortID 255 +
      // the server itself in _objTable (without it, the PROPUPD reply
      // dies with an NPE in ObjectMgr.getObject) and starts WSConnecting
      // with the host/port parsed from _serverURL — the genuine boot.
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
            System.out.println("perFrame threw (coupling boundary): " + t);
            break;
         }
         Thread.sleep(200);
      }
      System.out.println("final state=" + stateName(probe._state.getState()));
      try {
         probe._sock.close();
      } catch (Exception ignored) {
      }
      System.out.println("closed cleanly");

      // Decisive experiment (2): does the assert kill the real Main loop?
      // Registers the server (as findOrMake does via incRefCnt) and runs
      // the GENUINE Main.mainLoop in a thread: if the analysis chain is
      // right, the tick in state 7 propagates AssertionException out of
      // mainLoop (its bytecode has NO exception table) and the thread dies.
      System.out.println("== Main-loop experiment: register + run genuine Main.mainLoop ==");
      probe._state.setState(7);
      NET.worlds.console.Main.register(probe);
      Thread mainLoop = new Thread(new Runnable() {
         public void run() {
            NET.worlds.console.Main.mainLoop();
         }
      }, "MainLoopProbe");
      mainLoop.start();
      Thread.sleep(3000);
      boolean alive = mainLoop.isAlive();
      System.out.println("Main.mainLoop thread alive after 3s? " + alive);
      NET.worlds.console.Main.end();
      mainLoop.join(3000);
      System.out.println("Main.mainLoop thread alive after end()? " + mainLoop.isAlive());
      System.exit(0);
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

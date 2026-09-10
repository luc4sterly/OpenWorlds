package NET.worlds.network;

import NET.worlds.core.Std;
import java.net.Socket;

/**
 * Sonda de handshake contra un WorldServer real — FASE 2: habla protocolo.
 *
 * Camino 100% real del cliente decompilado, sin UI/consola/galaxy:
 *   1. state=4 + WSConnecting (lo mismo que WorldServer.startConnect con
 *      _sock==null) → hilos daemon + DNSLookup.lookupAll + Socket.
 *   2. setSocket REAL (super): ServerInputStream + netPacketReader thread
 *      + estado 5. Aquí solo se captura el host y se notifica.
 *   3. state_XMIT_PROPREQ() REAL: envía propReqCmd(ObjID(255)) vía
 *      sendNetMsg — el PRIMER paquete que el cliente real emite.
 *   4. perFrame() REAL en bucle (el driver de la máquina de estados que
 *      normalmente corre en el Main loop) para procesar la respuesta.
 *
 * Con netdebug=1152 en worlds.ini el propio sendNetMsg vuelca los bytes
 * enviados en hex (bit 1024) más la descripción (bit 128), y bit 64
 * describe lo recibido: la evidencia sale del código real, no de esta
 * sonda. Una sola conexión por ejecución, se cierra al terminar.
 *
 * Vive fuera de source/ (herramienta) pero en el mismo paquete porque
 * WSConnecting es package-private y setSocket/state/perFrame son
 * protected. Compilar con --release 8 contra out/worlds-mock.jar.
 *
 * Uso: java -cp <out> HandshakeProbe [host] [port]
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

      // Lo mismo que Gamma.main hace al arrancar (Gamma.java): sin esto
      // Std.getProductName() revienta en assert cuando netPacketReader
      // carga su tabla de paquetes (whisperCmd -> Console.message ->
      // Console.<clinit> -> new GammaFrame() -> getDefaultTitle()).
      // NOTA: Console.<clinit> crea un Frame AWT real -> hace falta X
      // (Xvfb vale, igual que el cliente mockeado).
      NET.worlds.core.Std.initProductName();

      HandshakeProbe probe = new HandshakeProbe();
      // initInstance real (ObjectMgr + WaitList + _serverURL): sin esto
      // sendNetMsg->toString->getLongID revienta (NPE en _serverURL).
      // Galaxy.getGalaxy solo crea hashtables/trackers, sin UI.
      ServerURL surl = new ServerURL("worldserver://" + host + ":" + port);
      probe.initInstance(Galaxy.getGalaxy("worldserver://" + host + ":" + port), surl);
      // state_Initializing REAL (no manual): registra shortID 255 +
      // el propio server en _objTable (sin esto, el PROPUPD de respuesta
      // muere en NPE en ObjectMgr.getObject) y arranca WSConnecting con
      // el host/puerto parseados de _serverURL — el boot genuino.
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
      long end = System.currentTimeMillis() + 15000;
      while (System.currentTimeMillis() < end) {
         int st = probe._state.getState();
         if (st != last) {
            System.out.println("state -> " + stateName(st));
            last = st;
         }
         if (st != 6) {
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
         case 12: return "12 MAINLOOP";
         case 17: return "17 DISCONNECTED";
         default: return String.valueOf(s);
      }
   }
}

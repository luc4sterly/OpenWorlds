package NET.worlds.network;

import NET.worlds.core.Std;
import java.net.Socket;

/**
 * Sonda de handshake — FASE 3: usa la clase REAL que el cliente
 * instancia de verdad (AutoServer), no WorldServer a pelo.
 *
 * Investigación de la paradoja "estado 7 mata al Main loop": WorldServer
 * es efectivamente abstracta (state_XMIT_SI/state_XMIT_AI son
 * Debug.dAssert(false) — el patrón de "abstracto por assert" de este
 * código de los 90). El cliente real NUNCA instancia WorldServer a
 * pelo: ServerURL(String) pone _serverType = "AutoServer" por defecto
 * (ver el constructor, cuando la URL no trae un segmento de tipo
 * explícito) y ServerTracker.findOrMake hace
 * Class.forName("NET.worlds.network." + type).newInstance() — para una
 * conexión normal a un host:puerto, eso es SIEMPRE AutoServer.
 *
 * AutoServer.state_XMIT_SI() SÍ tiene lógica real: lee la propiedad #15
 * (ya presente en el PROPUPD real capturado de worlds.worlio.com,
 * docs/net-handshake-trace.log: "#15 [DBSTORE /POSSESS] 1"),
 * detecta el tipo de servidor, instancia la subclase concreta
 * correspondiente (tipo 1 -> UserServer), le transfiere la conexión
 * viva (reuseConnection) y la re-alimenta con las mismas props
 * (propertyUpdate) — y SOLO ENTONCES pone su propio estado a 17
 * (terminado, ya se especializó). Nunca toca el dAssert.
 *
 * Este probe prueba esa cadena completa contra el servidor real.
 *
 * Uso: java -cp <out> AutoServerProbe [host] [port]
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
      // Misma URL "host:port" sin segmento de tipo que usaría el
      // cliente real para una conexión normal -> ServerURL._serverType
      // por defecto es literalmente "AutoServer" (verificado leyendo
      // ServerURL.java directamente, no supuesto).
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

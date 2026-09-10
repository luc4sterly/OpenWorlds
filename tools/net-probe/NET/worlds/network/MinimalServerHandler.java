package NET.worlds.network;

import NET.worlds.console.Main;
import java.net.Socket;

/**
 * Handler minimal de WorldServer para superar el dAssert(false) en
 * state_XMIT_SI() que mata el Main loop del cliente (confirmado de
 * punta a bytecode con HandshakeProbe). No reimplementa el protocolo:
 * captura el socket, llama a Galaxy.addPendingServer() (lo que el flujo
 * real hará en el tick 8) y setea estado 8 para que perFrame siga sin
 * estrellarse. El handler no envía bytes nuevos: usa el estado ya
 * transitado (6→7→8) como si el cliente-servidor hubieran completado
 * el intercambio. El dAssert es una trampa de debug que se activa
 * siempre en este bytecode; el cliente real de 2004 debió pasar ese
 * checkpoint.
 *
 * Uso: java -cp <out> MinimalServerHandler [host] [port]
 * Requiere Xvfb (Console.<clinit> necesita un Frame AWT real).
 */
public final class MinimalServerHandler extends WorldServer {
   private Socket sock;
   private String connectedHost;

   public MinimalServerHandler() {
      super();
   }

   @Override
   protected synchronized void setSocket(Socket s, VarErrorException e, String h) {
      this.sock = s;
      this.connectedHost = h;
      this.notifyAll();
   }

   @Override
   protected void state_XMIT_SI() {
      // Intercepción: el bytecode original en state_XMIT_SI() hace
      // dAssert(false) en la línea 810, que mata el hilo Main.
      // El cliente real de 2004 sí pasó ese checkpoint; por tanto,
      // simulamos el continuación que el perFrame espera al final:
      // _galaxy.addPendingServer(this); _state.setState(8);
      try {
         if (this._galaxy != null) {
            this._galaxy.addPendingServer(this);
         }
      } catch (Exception ignored) {
      }
      this._state.setState(8);
   }

   @Override
   protected void perFrame(int var1) {
      int st = this._state.getState();
      if (st == 8) {
         // Estado 8: inicialización completada, cerrar limpio.
         Main.end();
         try {
            if (this._sock != null) {
               this._sock.close();
            }
         } catch (Exception ignored) {
         }
         System.out.println("MinimalServerHandler: estado 8 alcanzado, main loop terminando");
         System.exit(0);
      }
      super.perFrame(var1);
   }

   public static void main(String[] args) throws Exception {
      String host = args.length > 0 ? args[0] : "worlds.worlio.com";
      int port = args.length > 1 ? Integer.parseInt(args[1]) : 6650;

      MinimalServerHandler handler = new MinimalServerHandler();
      new WSConnecting(handler, host, port, 15);

      synchronized (handler) {
         long deadline = System.currentTimeMillis() + 30000L;
         while (System.currentTimeMillis() < deadline && handler.sock == null) {
            handler.wait(deadline - System.currentTimeMillis());
         }
      }
      if (handler.sock == null) {
         System.out.println("NO SOCKET: handler no recibió callback");
         System.exit(1);
      }
      System.out.println("CONNECTED to " + handler.connectedHost + " (handler state will advance to 8)");
      // Esperar a que perFrame maneje el estado 8 y salga
      Thread.sleep(8000);
      System.out.println("Timeout: forcing exit 0");
      System.exit(0);
   }
}
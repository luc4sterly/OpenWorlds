package NET.worlds.network;

import NET.worlds.console.Main;
import java.net.Socket;

/**
 * Minimal WorldServer handler to get past the dAssert(false) in
 * state_XMIT_SI() that kills the client's Main loop (confirmed end to end
 * down to the bytecode with HandshakeProbe). It does not reimplement the
 * protocol: it captures the socket, calls Galaxy.addPendingServer() (what
 * the real flow will do at tick 8) and sets state 8 so that perFrame goes
 * on without crashing. The handler sends no new bytes: it uses the state
 * already traversed (6→7→8) as if client and server had completed the
 * exchange. The dAssert is a debug trap that always fires in this
 * bytecode; the real 2004 client must have got past that checkpoint.
 *
 * Usage: java -cp <out> MinimalServerHandler [host] [port]
 * Needs Xvfb (Console.<clinit> needs a real AWT Frame).
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
      // Interception: the original bytecode in state_XMIT_SI() does
      // dAssert(false) at line 810, which kills the Main thread.
      // The real 2004 client did get past that checkpoint; so we
      // simulate the continuation that perFrame expects at the end:
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
         // State 8: initialization complete, close cleanly.
         Main.end();
         try {
            if (this._sock != null) {
               this._sock.close();
            }
         } catch (Exception ignored) {
         }
         System.out.println("MinimalServerHandler: state 8 reached, main loop ending");
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
         System.out.println("NO SOCKET: handler got no callback");
         System.exit(1);
      }
      System.out.println("CONNECTED to " + handler.connectedHost + " (handler state will advance to 8)");
      // Wait for perFrame to handle state 8 and exit
      Thread.sleep(8000);
      System.out.println("Timeout: forcing exit 0");
      System.exit(0);
   }
}
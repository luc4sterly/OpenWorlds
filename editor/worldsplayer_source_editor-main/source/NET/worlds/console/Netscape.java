package NET.worlds.console;

import java.io.IOException;

public class Netscape implements MainCallback, MainTerminalCallback {
   private INetscapeRegistry _registry = null;
   private NSProtocolHandler _protocolHandler = null;

   public Netscape() {
      Main.register(this);
   }

   public void mainCallback() {
      Main.unregister(this);

      try {
         this._registry = new INetscapeRegistry();
         if ((ActiveX.getDebugLevel() & 16) > 0) {
            System.out.println("OLEDEBUG: Netscape OLE found");
         }

         this._protocolHandler = new NSProtocolHandler();
         this._protocolHandler.activate();
         if ((ActiveX.getDebugLevel() & 16) > 0) {
            System.out.println("OLEDEBUG: NSProtocolHandler started");
         }

         this._protocolHandler.register();
         boolean var1 = this._registry.RegisterProtocol("world", "Gamma.Protocol.1");
         if ((ActiveX.getDebugLevel() & 16) > 0) {
            System.out.println("OLEDEBUG: world: registered with Netscape");
         }
      } catch (IOException var11) {
         if ((ActiveX.getDebugLevel() & 16) > 0) {
            System.out.println("OLEDEBUG: No Netscape: " + var11.getMessage());
         }
      } finally {
         if (this._registry != null) {
            try {
               this._registry.Release();
            } catch (OLEInvalidObjectException var10) {
               var10.printStackTrace(System.out);
            }

            this._registry = null;
         }
      }
   }

   public void terminalCallback() {
      Main.unregister(this);
   }
}

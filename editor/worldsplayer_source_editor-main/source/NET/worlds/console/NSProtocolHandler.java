package NET.worlds.console;

import NET.worlds.scape.TeleportAction;
import java.io.IOException;

public class NSProtocolHandler extends IClassFactory {
   public static final String CLSID_GammaProtocol1 = "{f8535c80-f5ee-11d2-a6ac-0050041a1735}";

   public NSProtocolHandler() throws IOException {
      this.init(createLocal());
   }

   public void activate() throws IOException {
      super.activate("{f8535c80-f5ee-11d2-a6ac-0050041a1735}");
   }

   public void register() {
      super.register("Gamma Protocol Handler", "{f8535c80-f5ee-11d2-a6ac-0050041a1735}", "Gamma.Protocol", "Gamma.Protocol.1");
   }

   public static void newURL(String var0) {
      if ((ActiveX.getDebugLevel() & 16) > 0) {
         System.out.println("OLEDEBUG: Netscape URL: " + var0);
      }

      TeleportAction.teleport(var0, null, true);
      GammaFrame var1 = Console.getFrame();
      int var2 = Window.findWindow(var1.getTitle());
      if (var2 != 0) {
         Window.setWindowState(var2, 0);
         Window.setForegroundWindow(var2);
      }
   }

   public static native int createLocal() throws IOException;
}

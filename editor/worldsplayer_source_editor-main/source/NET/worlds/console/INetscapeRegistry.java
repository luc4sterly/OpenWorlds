package NET.worlds.console;

import java.io.IOException;

public class INetscapeRegistry extends IDispatch {
   public INetscapeRegistry() throws IOException {
      super("Netscape.Registry.1");
   }

   public native boolean RegisterViewer(String var1, String var2) throws IOException;

   public native boolean RegisterProtocol(String var1, String var2) throws IOException;

   public String toString() {
      return "INetscapeRegistry(" + this.internalData() + ")";
   }
}

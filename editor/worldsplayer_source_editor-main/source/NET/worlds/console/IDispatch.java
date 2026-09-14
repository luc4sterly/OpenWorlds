package NET.worlds.console;

import NET.worlds.core.Debug;
import java.io.IOException;

public class IDispatch extends IUnknown {
   private static final String IID_IDispatch = "{00020400-0000-0000-C000-000000000046}";

   public IDispatch(String var1) throws IOException {
      try {
         this.init(var1, "{00020400-0000-0000-C000-000000000046}");
      } catch (IOException var17) {
         IUnknown var3 = new IUnknown(var1);

         try {
            this.init(var3, "{00020400-0000-0000-C000-000000000046}");
         } catch (OLEInvalidObjectException var15) {
            System.out.println("DEBUG: " + this);
            Debug.dAssert(false);
         } finally {
            try {
               var3.Release();
            } catch (OLEInvalidObjectException var14) {
               System.out.println("DEBUG: " + this);
               Debug.dAssert(false);
            }
         }
      }
   }

   public IDispatch(IUnknown var1) throws IOException, OLEInvalidObjectException {
      super(var1, "{00020400-0000-0000-C000-000000000046}");
   }

   public native void Invoke(String var1);

   public String toString() {
      return "IDispatch(" + this.internalData() + ")";
   }
}

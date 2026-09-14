package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.RegKey;
import NET.worlds.core.RegKeyNotFoundException;
import java.io.IOException;

public class IClassFactory extends IUnknown {
   private static final String IID_IClassFactory = "{00000001-0000-0000-C000-000000000046}";
   private long _registerID;

   public IClassFactory() throws IOException {
   }

   public IClassFactory(String var1) throws IOException {
      super(var1, "{00000001-0000-0000-C000-000000000046}");
   }

   public IClassFactory(IUnknown var1) throws IOException, OLEInvalidObjectException {
      super(var1, "{00000001-0000-0000-C000-000000000046}");
   }

   public synchronized void activate(String var1) throws IOException {
      Debug.dAssert(this._registerID == 0L);
      Debug.dAssert(Main.isMainThread());
      if ((ActiveX.getDebugLevel() & 8) > 0) {
         System.out.println(this + ": activating server as " + var1);
      }

      this._registerID = this.nActivate(var1);
      if ((ActiveX.getDebugLevel() & 8) > 0) {
         System.out.println(this + ": successful");
      }
   }

   public synchronized void deactivate() throws IOException {
      Debug.dAssert(this._registerID != 0L);
      Debug.dAssert(Main.isMainThread());
      if ((ActiveX.getDebugLevel() & 8) > 0) {
         System.out.println(this + ": deactivating server");
      }

      this.nDeactivate(this._registerID);
   }

   public synchronized void Release() throws OLEInvalidObjectException {
      if (this._refs == 1 && this._registerID != 0L) {
         if ((ActiveX.getDebugLevel() & 4) > 0) {
            System.out.println(this + ": deactivating before Release");
         }

         try {
            this.deactivate();
         } catch (IOException var2) {
            System.out.println("DEBUG: " + this);
            var2.printStackTrace(System.out);
            Debug.dAssert(false);
         }

         this._registerID = 0L;
      }

      super.Release();
   }

   public String internalData() {
      return "_registerID = " + this._registerID + ", " + super.internalData();
   }

   public String toString() {
      return "IClassFactory(" + this.internalData() + ")";
   }

   public void register(String var1, String var2, String var3, String var4) {
      try {
         RegKey var5 = RegKey.getRootKey(0);
         RegKey var6 = new RegKey(var5, "world\\shell\\open\\command", 0);
         String var7 = var6.getStringValue("");
         int var8 = var7.indexOf(" \"%1\"");
         var7 = var7.substring(0, var8);
         RegKey var9 = new RegKey(var5, "CLSID\\" + var2, 2);
         var9.setStringValue("", var1, false);
         RegKey var10 = new RegKey(var9, "LocalServer32", 2);
         var10.setStringValue("", var7, false);
         var10.close();
         var10 = new RegKey(var9, "ProgID", 2);
         var10.setStringValue("", var4, false);
         var10.close();
         var10 = new RegKey(var9, "VersionIndependentProgID", 2);
         var10.setStringValue("", var3, false);
         var10.close();
         var9.close();
         RegKey var11 = new RegKey(var5, var3, 2);
         var11.setStringValue("", var1, false);
         var10 = new RegKey(var11, "CLSID", 2);
         var10.setStringValue("", var2, false);
         var10.close();
         var10 = new RegKey(var11, "CurVer", 2);
         var10.setStringValue("", var4, false);
         var10.close();
         var11.close();
         RegKey var12 = new RegKey(var5, var4, 2);
         var12.setStringValue("", var1, false);
         var10 = new RegKey(var12, "CLSID", 2);
         var10.setStringValue("", var2, false);
         var10.close();
         var12.close();
      } catch (RegKeyNotFoundException var13) {
         System.out.println("Warning: System Registry not configured properly by Worlds.");
      }
   }

   private native long nActivate(String var1) throws IOException;

   private native void nDeactivate(long var1) throws IOException;
}

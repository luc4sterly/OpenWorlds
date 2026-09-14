package NET.worlds.console;

import NET.worlds.core.Debug;
import java.io.IOException;

public class IUnknown {
   protected int _pInterface = 0;
   protected int _refs = 0;
   private static final String IID_IUnknown = "{00000000-0000-0000-c000-000000000046}";

   public IUnknown() throws IOException {
   }

   protected synchronized void init(int var1) throws IOException {
      Debug.dAssert(var1 != 0);
      ActiveX.init(this);
      this._pInterface = var1;
      this._refs = 1;
   }

   public IUnknown(String var1) throws IOException {
      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println(this + ": constructor: svrID = " + var1);
      }

      ActiveX.init(this);

      try {
         try {
            this._pInterface = ActiveX.getClassFClsID(var1, "{00000000-0000-0000-c000-000000000046}");
            this._refs++;
         } catch (IOException var3) {
            this._pInterface = ActiveX.getClassFProgID(var1, "{00000000-0000-0000-c000-000000000046}");
            this._refs++;
         }
      } catch (IOException var4) {
         ActiveX.uninit(this);
         throw var4;
      }

      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println("IUnknown: constructed " + this);
      }
   }

   public IUnknown(String var1, String var2) throws IOException {
      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println(this + ": constructor: svrID = " + var1 + ", intfID = " + var2);
      }

      this.init(var1, var2);
      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println("IUnknown: constructed " + this);
      }
   }

   protected synchronized void init(String var1, String var2) throws IOException {
      ActiveX.init(this);

      try {
         try {
            this._pInterface = ActiveX.getClassFClsID(var1, var2);
            this._refs++;
         } catch (IOException var4) {
            this._pInterface = ActiveX.getClassFProgID(var1, var2);
            this._refs++;
         }
      } catch (IOException var5) {
         ActiveX.uninit(this);
         throw var5;
      }
   }

   public IUnknown(IUnknown var1, String var2) throws IOException, OLEInvalidObjectException {
      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println(this + ": constructor: parent = " + var1 + ", intfID = " + var2);
      }

      this.init(var1, var2);
      if ((ActiveX.getDebugLevel() & 2) > 0) {
         System.out.println("IUnknown: constructed " + this);
      }
   }

   protected synchronized void init(IUnknown var1, String var2) throws IOException, OLEInvalidObjectException {
      Debug.dAssert(var1 != null);
      ActiveX.init(this);

      try {
         this._pInterface = var1.QueryInterface(var2);
         this._refs = 1;
      } catch (IOException var4) {
         ActiveX.uninit(this);
         throw var4;
      } catch (OLEInvalidObjectException var5) {
         ActiveX.uninit(this);
         throw var5;
      }
   }

   public synchronized void Release() throws OLEInvalidObjectException {
      if ((ActiveX.getDebugLevel() & 4) > 0) {
         System.out.println(this + ": Releasing");
      }

      if (this._pInterface == 0) {
         throw new OLEInvalidObjectException();
      }

      if (this._pInterface != 0 && this._refs > 0) {
         this.true_Release();
      }

      this._refs--;
      if (this._refs == 0) {
         this._pInterface = 0;
         ActiveX.uninit(this);
      }
   }

   public void finalize() {
      if (this._pInterface != 0) {
         while (this._refs > 0) {
            try {
               this.Release();
            } catch (OLEInvalidObjectException var2) {
               System.out.println("DEBUG: " + this);
               Debug.dAssert(false);
            }
         }
      }
   }

   public synchronized void AddRef() throws OLEInvalidObjectException {
      if ((ActiveX.getDebugLevel() & 4) > 0) {
         System.out.println(this + ": AddingRef");
      }

      if (this._pInterface == 0) {
         throw new OLEInvalidObjectException();
      }

      this._refs++;
      this.true_AddRef();
   }

   public native void true_AddRef();

   public native int QueryInterface(String var1) throws IOException, OLEInvalidObjectException;

   public native void true_Release() throws OLEInvalidObjectException;

   protected native int getPtr() throws OLEInvalidObjectException;

   public String internalData() {
      return "_pInterface=" + this._pInterface + ", _refs=" + this._refs;
   }

   public String toString() {
      return "IUnknown(" + this.internalData() + ")";
   }
}

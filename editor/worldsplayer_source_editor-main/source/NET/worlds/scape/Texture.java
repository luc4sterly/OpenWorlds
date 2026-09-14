package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;

public abstract class Texture implements Persister {
   protected int textureID = 0;
   int refs = 1;
   private static Object classCookie = new Object();

   protected Texture() {
   }

   public static native void nativeInit();

   private static native int nativeGetW(int var0);

   public int getW() {
      return nativeGetW(this.textureID);
   }

   private static native int nativeGetH(int var0);

   public int getH() {
      return nativeGetH(this.textureID);
   }

   public URL getURL() {
      URL var1 = null;
      String var2 = this.getName();
      if (var2 != null) {
         try {
            var1 = new URL(URL.getCurDir(), var2);
         } catch (MalformedURLException var4) {
         }
      }

      return var1;
   }

   public void incRef() {
      Debug.dAssert(this.refs > 0);
      if (this.textureID != 0) {
         this.refs++;
      }
   }

   public void copyFrom(int var1, int var2, int var3, int var4, int var5) {
      Debug.dAssert(this.textureID != 0);
      nativeCopyFrom(this.textureID, var1, var2, var3, var4, var5);
   }

   private static native void nativeCopyFrom(int var0, int var1, int var2, int var3, int var4, int var5);

   private static native void nativeRelease(int var0);

   public synchronized void decRef() {
      if (--this.refs <= 0 && this.textureID != 0) {
         nativeRelease(this.textureID);
         this.textureID = 0;
      }
   }

   protected void finalize() {
      if (this.refs > 0) {
         this.refs = 1;
         this.decRef();
         this.refs = 1000000;
      }
   }

   protected String getName() {
      return null;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }

   static {
      nativeInit();
   }
}

package NET.worlds.console;

import NET.worlds.network.URL;

public class ScapePicImage {
   private int hDIB;
   private int width;
   private int height;

   public ScapePicImage(URL var1) {
      nativeInit();
      this.loadImage(var1.unalias());
   }

   public int getWidth() {
      return this.width;
   }

   public int getHeight() {
      return this.height;
   }

   public native void flush();

   public void finalize() {
      this.flush();
   }

   int getDIB() {
      return this.hDIB;
   }

   private native void loadImage(String var1);

   public static native void nativeInit();
}

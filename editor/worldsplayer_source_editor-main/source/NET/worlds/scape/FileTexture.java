package NET.worlds.scape;

import java.io.IOException;

public class FileTexture extends Texture implements Persister {
   private String _urlName;
   private static Object classCookie = new Object();

   public FileTexture(String var1, String var2) {
      this.makeTexture(var1, var2);
   }

   protected FileTexture() {
   }

   public static native void nativeInit();

   public static native FileTexture dictLookup(String var0);

   private native void makeTexture(String var1, String var2);

   public String getName() {
      return this._urlName;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this._urlName);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            String var2 = var1.restoreString();
            this.makeTexture(var2, var2);
            return;
         default:
            throw new TooNewException();
      }
   }

   static {
      nativeInit();
   }
}

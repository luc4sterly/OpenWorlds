package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.IOException;
import java.util.Hashtable;

public class ScapePicMovie implements Persister {
   private static Hashtable movieDict = new Hashtable();
   private ScapePicTexture[] movie;
   private String localName;
   private URL url;
   private int frameCount;
   private int width;
   private int height;
   private static Object classCookie = new Object();

   public ScapePicMovie() {
   }

   public ScapePicMovie(String var1, URL var2) {
      this.localName = var1;
      this.url = var2;
      this.movie = this.getAll();
   }

   public static native void nativeInit();

   public int getW() {
      return this.width;
   }

   public int getH() {
      return this.height;
   }

   public int length() {
      return this.frameCount;
   }

   public URL getURL() {
      return this.url;
   }

   public ScapePicTexture getTexture(int var1) {
      ScapePicTexture var2 = null;
      if (this.movie != null) {
         var2 = this.movie[var1];
         this.movie[var1] = null;
         int var3 = 0;

         while (var3 < this.frameCount && this.movie[var3] == null) {
            var3++;
         }

         if (var3 == this.frameCount) {
            this.movie = null;
         }
      }

      return var2;
   }

   public ScapePicTexture[] getTextures() {
      ScapePicTexture[] var1 = this.movie;
      this.movie = null;
      return var1;
   }

   private synchronized ScapePicTexture[] getAll() {
      String var1 = this.url.getAbsolute();
      ScapePicMovie var2 = (ScapePicMovie)movieDict.get(var1);
      ScapePicTexture[] var3 = null;
      if (var2 != null) {
         this.frameCount = var2.length();
         this.width = var2.getW();
         this.height = var2.getH();
         var3 = this.lookupTextures(var1, this.frameCount, this.width, this.height);
      }

      if (var3 == null) {
         var3 = this.makeTextures(this.localName, var1);
         if (var3 != null && var2 == null) {
            this.frameCount = var3.length;
            this.width = var3[0].getW();
            this.height = var3[0].getH();
            movieDict.put(var1, this);
         }
      }

      return var3;
   }

   private native ScapePicTexture[] lookupTextures(String var1, int var2, int var3, int var4);

   private native ScapePicTexture[] makeTextures(String var1, String var2);

   public void saveState(Saver var1) throws IOException {
      Console.println(Console.message("Obs-ScapePicMov") + this.url);
      var1.saveVersion(2, classCookie);
      this.url.save(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.localName = var1.restoreString();
            this.url = URL.make(this.localName);
            var1.restoreBoolean();
            break;
         case 1:
            this.localName = var1.restoreString();
            this.url = URL.make(this.localName);
            break;
         case 2:
            this.url = URL.restore(var1);
            this.localName = this.url.unalias();
            break;
         default:
            throw new TooNewException();
      }

      this.movie = this.getAll();
   }

   public void postRestore(int var1) {
   }

   public String toString() {
      return this.url.getAbsolute();
   }

   static {
      nativeInit();
   }
}

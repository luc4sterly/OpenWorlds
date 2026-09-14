package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;

public class ScapePicTexture extends Texture implements Persister {
   private int w;
   private int h;
   private String _urlName;
   private ScapePicMovie _movie;
   private int _movieFrame;
   private static Object classCookie = new Object();

   public ScapePicTexture(String var1, String var2) {
      this._urlName = var1;
      this.makeTexture(var1, var2);
   }

   public ScapePicTexture() {
   }

   public static native void nativeInit();

   public int getW() {
      return this.w;
   }

   public int getH() {
      return this.h;
   }

   private native void makeTexture(String var1, String var2);

   public String getName() {
      return this._urlName;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      if (this._movie != null) {
         var1.saveBoolean(true);
         var1.save(this._movie);
         var1.saveInt(this._movieFrame);
      } else {
         var1.saveBoolean(false);
         var1.saveString(this._urlName);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            var1.restoreBoolean();
            break;
         case 1:
            super.restoreState(var1);
            break;
         default:
            throw new TooNewException();
      }

      if (var1.restoreBoolean()) {
         this._movie = (ScapePicMovie)var1.restore();
         this._movieFrame = var1.restoreInt();
         ScapePicTexture var2 = this._movie.getTexture(this._movieFrame);
         if (var2 == null) {
            Object[] var3 = new Object[]{new String("" + this._movieFrame), new String("" + this._movie)};
            Console.println(MessageFormat.format(Console.message("Error-frame"), var3));
         } else {
            this.textureID = var2.textureID;
         }
      } else {
         this._urlName = var1.restoreString();
         this.makeTexture(this._urlName, this._urlName);
      }
   }

   public String toString() {
      return this._movie == null ? this._urlName : this._movie.toString();
   }

   static {
      nativeInit();
   }
}

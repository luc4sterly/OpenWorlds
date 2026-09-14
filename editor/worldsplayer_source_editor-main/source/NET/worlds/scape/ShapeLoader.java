package NET.worlds.scape;

import NET.worlds.network.URL;
import java.util.Enumeration;
import java.util.Vector;

public class ShapeLoader implements BGLoaded {
   Shape shape;
   int binaryParam;
   private int numTexturesLoading;
   private Vector textures;
   private boolean wasError;

   public ShapeLoader(Shape var1) {
      this.shape = var1;
   }

   public Room getBackgroundLoadRoom() {
      return this.shape.getRoom();
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      if (var1 == null) {
         return null;
      } else if (var2.endsWith(".rwg") || var2.endsWith(".RWG")) {
         this.binaryParam = this.loadBinaryFile(var1, var2);
         return new Object();
      } else if (var2.endsWith(".rwx") || var2.endsWith(".RWX")) {
         this.loadTextFile(var1, var2);
         return var1;
      } else {
         return !var2.endsWith(".bod") && !var2.endsWith(".BOD") ? null : var1;
      }
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      if (var1 == null) {
         return false;
      }

      if (this.numTexturesLoading > 0) {
         return true;
      }

      if (!var2.equals(this.shape.realFile)) {
         this.wasError = true;
      } else if (!this.shape.hasClump() && this.shape.isDefault) {
         this.wasError = true;
         if (!this.shape.isLoaded()) {
            this.shape.setState(0, null);
         }
      }

      int var3;
      if (var1 instanceof String) {
         if (!this.wasError) {
            if (var2.endsWith(".bod")) {
               var3 = this.loadBodFile((String)var1, this.shape.getBodPartNum());
            } else {
               var3 = this.finishLoadingTextFile((String)var1);
            }
         } else {
            var3 = 0;
         }
      } else {
         var3 = this.finishLoadingBinaryFile(this.binaryParam, this.wasError);
      }

      if (var3 != 0) {
         this.shape.setState(var3, this.textures);
      }

      if ((var3 == 0 || var3 == -1) && this.textures != null) {
         Enumeration var4 = this.textures.elements();

         while (var4.hasMoreElements()) {
            ((Texture)var4.nextElement()).decRef();
         }
      }

      this.textures = null;
      return false;
   }

   private void startTextureLoad(String var1, URL var2) {
      this.numTexturesLoading++;
      BackgroundLoader.get(new ShapeTextureLoader(this), URL.make(var2, var1), true);
   }

   synchronized void textureLoadEnd(Texture var1) {
      this.numTexturesLoading--;
      if (var1 != null) {
         if (this.textures == null) {
            this.textures = new Vector();
         }

         this.textures.addElement(var1);
      } else {
         this.wasError = true;
      }
   }

   private native void loadTextFile(String var1, URL var2);

   private native int finishLoadingTextFile(String var1);

   private native int loadBodFile(String var1, int var2);

   private native int loadBinaryFile(String var1, URL var2);

   private native int finishLoadingBinaryFile(int var1, boolean var2);
}

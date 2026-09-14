package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.ColorModel;
import java.awt.image.DirectColorModel;
import java.awt.image.ImageConsumer;
import java.awt.image.IndexColorModel;
import java.util.Hashtable;

public class ImageConverter implements ImageConsumer {
   private String urlName;
   private String filename;
   private int width;
   private int height;
   private Image image;
   private boolean done;
   private boolean ok;
   private boolean debug = false;
   private ColorModel model;
   private int transparentColor = -1;
   private int hDIB;
   private int pixelPtr;

   public ImageConverter(String var1, String var2) {
      this.urlName = var1;
      this.filename = var2;
   }

   public static native void nativeInit();

   public synchronized int convert() {
      this.image = Toolkit.getDefaultToolkit().getImage(this.filename);
      this.image.getSource().startProduction(this);

      while (!this.done) {
         try {
            this.wait();
         } catch (InterruptedException var2) {
         }
      }

      int var1 = 0;
      if (this.ok) {
         var1 = this.convertDIBToTexture();
      }

      this.cleanup();
      return var1;
   }

   public void setDimensions(int var1, int var2) {
      if (this.debug) {
         System.out.println("Set dimensions: w " + var1 + " h " + var2);
      }

      this.width = var1;
      this.height = var2;
   }

   public void setProperties(Hashtable var1) {
      if (this.debug) {
         System.out.println("Set properties");
      }
   }

   public void setColorModel(ColorModel var1) {
      if (this.debug) {
         System.out.println("Set color model: " + var1);
      }

      this.model = var1;
      Debug.dAssert(this.width != 0 && this.height != 0);
      int[] var2 = null;
      int var3 = 0;
      if (var1 instanceof IndexColorModel) {
         IndexColorModel var4 = (IndexColorModel)var1;
         var3 = var4.getMapSize();
         this.transparentColor = var4.getTransparentPixel();
         var2 = new int[var3 * 3];

         for (int var5 = 0; var5 < var3; var5++) {
            var2[var5] = var4.getRGB(var5);
         }
      } else {
         DirectColorModel var6 = (DirectColorModel)var1;
         Debug.dAssert(var6.getBlueMask() == 255);
         Debug.dAssert(var6.getGreenMask() == 65280);
         Debug.dAssert(var6.getRedMask() == 16711680);
      }

      this.prepareDIB(this.width, this.height, var3, var2);
   }

   public void setHints(int var1) {
      if (this.debug) {
         System.out
            .println(
               "Set hints: "
                  + ((var1 & 1) != 0 ? " RANDOM " : "")
                  + ((var1 & 2) != 0 ? " TOPDOWNLEFTRIGHT " : "")
                  + ((var1 & 4) != 0 ? " COMPLETESCANS " : "")
                  + ((var1 & 8) != 0 ? " SINGLEPASS " : "")
                  + ((var1 & 16) != 0 ? " SINGLEFRAME " : "")
            );
      }
   }

   public void setPixels(int var1, int var2, int var3, int var4, ColorModel var5, byte[] var6, int var7, int var8) {
      if (this.debug) {
         System.out
            .println("setPixels(byte): x " + var1 + " y " + var2 + " w " + var3 + " h " + var4 + " model " + var5 + " off " + var7 + " scansize " + var8);
      }

      Debug.dAssert(var5 == this.model);
      this.setDIBPixelBytes(var1, var2, var3, var4, var6, var7, var8);
   }

   public void setPixels(int var1, int var2, int var3, int var4, ColorModel var5, int[] var6, int var7, int var8) {
      if (this.debug) {
         System.out.println("setPixels(int): x " + var1 + " y " + var2 + " w " + var3 + " h " + var4 + " model " + var5 + " off " + var7 + " scansize " + var8);
      }

      Debug.dAssert(var5 == this.model);
      this.setDIBPixelInts(var1, var2, var3, var4, var6, var7, var8);
   }

   public synchronized void imageComplete(int var1) {
      if (this.debug) {
         String var2 = null;
         switch (var1) {
            case 1:
               var2 = "ERROR";
               break;
            case 2:
               var2 = "SINGLEDONE";
               break;
            case 3:
               var2 = "STATICDONE";
               break;
            case 4:
               var2 = "ABORTED";
         }

         System.out.println("Image complete: " + var2);
      }

      this.image.getSource().removeConsumer(this);
      this.image.flush();
      this.ok = var1 != 1 && var1 != 4;
      this.done = true;
      this.notify();
   }

   private native void prepareDIB(int var1, int var2, int var3, int[] var4);

   private native void setDIBPixelBytes(int var1, int var2, int var3, int var4, byte[] var5, int var6, int var7);

   private native void setDIBPixelInts(int var1, int var2, int var3, int var4, int[] var5, int var6, int var7);

   private native int convertDIBToTexture();

   private native void cleanup();

   static {
      nativeInit();
   }
}

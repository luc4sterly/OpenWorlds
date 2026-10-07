package java.awt.image;

import java.awt.Transparency;

/** How pixel values map to colours, as java.awt.image.ColorModel (sRGB only). */
public abstract class ColorModel implements Transparency {
   protected int pixel_bits;
   int transparency;
   boolean hasAlpha;
   boolean premultiplied;
   int transferType;

   private static ColorModel RGBdefault;

   protected ColorModel(int bits) {
      this.pixel_bits = bits;
      this.transparency = OPAQUE;
      this.transferType = bits <= 8 ? DataBuffer.TYPE_BYTE : bits <= 16 ? DataBuffer.TYPE_USHORT : DataBuffer.TYPE_INT;
   }

   public static ColorModel getRGBdefault() {
      if (RGBdefault == null) {
         RGBdefault = new DirectColorModel(32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
      }
      return RGBdefault;
   }

   public int getPixelSize() {
      return pixel_bits;
   }

   public boolean hasAlpha() {
      return hasAlpha;
   }

   public boolean isAlphaPremultiplied() {
      return premultiplied;
   }

   public int getTransparency() {
      return transparency;
   }

   public int getTransferType() {
      return transferType;
   }

   public int getNumComponents() {
      return hasAlpha ? 4 : 3;
   }

   public int getNumColorComponents() {
      return 3;
   }

   public abstract int getRed(int pixel);

   public abstract int getGreen(int pixel);

   public abstract int getBlue(int pixel);

   public abstract int getAlpha(int pixel);

   public int getRGB(int pixel) {
      return (getAlpha(pixel) << 24) | (getRed(pixel) << 16) | (getGreen(pixel) << 8) | getBlue(pixel);
   }

   /** The pixel value nearest to an ARGB colour (what setRGB stores). */
   public abstract int pixelOf(int argb);

   public void finalize() {
   }
}

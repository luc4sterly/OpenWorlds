package java.awt.color;

/** Only sRGB exists here. */
public abstract class ColorSpace {
   public static final int CS_sRGB = 1000;
   public static final int CS_LINEAR_RGB = 1004;
   public static final int CS_GRAY = 1003;
   public static final int TYPE_RGB = 5;
   public static final int TYPE_GRAY = 6;

   private static ColorSpace sRGB;

   protected ColorSpace(int type, int numcomponents) {
   }

   public static ColorSpace getInstance(int colorspace) {
      if (sRGB == null) {
         sRGB = new ColorSpace(TYPE_RGB, 3) {
         };
      }
      return sRGB;
   }

   public boolean isCS_sRGB() {
      return true;
   }

   public int getType() {
      return TYPE_RGB;
   }

   public int getNumComponents() {
      return 3;
   }
}

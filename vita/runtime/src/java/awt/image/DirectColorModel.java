package java.awt.image;

/** Pixels as packed bit fields, as java.awt.image.DirectColorModel (the same rounding: c * 255f / max + 0.5f). */
public class DirectColorModel extends ColorModel {
   private final int redMask;
   private final int greenMask;
   private final int blueMask;
   private final int alphaMask;
   private final int[] shifts = new int[4];
   private final int[] bits = new int[4];
   private final float[] scale = new float[4];

   public DirectColorModel(int bits, int rmask, int gmask, int bmask) {
      this(bits, rmask, gmask, bmask, 0);
   }

   public DirectColorModel(int bits, int rmask, int gmask, int bmask, int amask) {
      super(bits);
      redMask = rmask;
      greenMask = gmask;
      blueMask = bmask;
      alphaMask = amask;
      int[] masks = {rmask, gmask, bmask, amask};
      for (int i = 0; i < 4; i++) {
         int m = masks[i];
         int s = 0;
         if (m != 0) {
            while ((m & 1) == 0) {
               m >>>= 1;
               s++;
            }
         }
         int n = Integer.bitCount(masks[i]);
         shifts[i] = s;
         this.bits[i] = n;
         scale[i] = n == 0 ? 1f : 255.0f / ((1 << n) - 1);
      }
      hasAlpha = amask != 0;
      transparency = hasAlpha ? TRANSLUCENT : OPAQUE;
   }

   public DirectColorModel(java.awt.color.ColorSpace space, int bits, int rmask, int gmask, int bmask, int amask, boolean isAlphaPremultiplied,
         int transferType) {
      this(bits, rmask, gmask, bmask, amask);
      this.premultiplied = isAlphaPremultiplied;
      this.transferType = transferType;
   }

   public final int getRedMask() {
      return redMask;
   }

   public final int getGreenMask() {
      return greenMask;
   }

   public final int getBlueMask() {
      return blueMask;
   }

   public final int getAlphaMask() {
      return alphaMask;
   }

   private int component(int pixel, int idx, int mask) {
      int c = (pixel & mask) >>> shifts[idx];
      if (bits[idx] == 8) {
         return c;
      }
      return (int) ((c * scale[idx]) + 0.5f);
   }

   public final int getRed(int pixel) {
      return component(pixel, 0, redMask);
   }

   public final int getGreen(int pixel) {
      return component(pixel, 1, greenMask);
   }

   public final int getBlue(int pixel) {
      return component(pixel, 2, blueMask);
   }

   public final int getAlpha(int pixel) {
      return alphaMask == 0 ? 255 : component(pixel, 3, alphaMask);
   }

   public final int getRGB(int pixel) {
      if (bits[0] == 8 && bits[1] == 8 && bits[2] == 8 && shifts[0] == 16 && shifts[1] == 8 && shifts[2] == 0) {
         return alphaMask == 0 ? pixel | 0xFF000000 : (alphaMask == 0xFF000000 ? pixel : super.getRGB(pixel));
      }
      return super.getRGB(pixel);
   }

   private int pack(int value8, int idx, int mask) {
      int n = bits[idx];
      if (n == 0) {
         return 0;
      }
      int v = n == 8 ? value8 : (int) (value8 * ((1 << n) - 1) / 255.0f + 0.5f);
      return (v << shifts[idx]) & mask;
   }

   public int pixelOf(int argb) {
      return pack((argb >> 16) & 0xFF, 0, redMask) | pack((argb >> 8) & 0xFF, 1, greenMask) | pack(argb & 0xFF, 2, blueMask)
            | pack(argb >>> 24, 3, alphaMask);
   }
}

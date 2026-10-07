package java.awt.image;

/** Pixels as indexes into a palette, as java.awt.image.IndexColorModel. */
public class IndexColorModel extends ColorModel {
   private final int[] rgb;
   private final int mapSize;
   private int transparentIndex = -1;

   public IndexColorModel(int bits, int size, byte[] r, byte[] g, byte[] b) {
      this(bits, size, r, g, b, (byte[]) null);
   }

   public IndexColorModel(int bits, int size, byte[] r, byte[] g, byte[] b, int trans) {
      this(bits, size, r, g, b, (byte[]) null);
      setTransparentPixel(trans);
   }

   public IndexColorModel(int bits, int size, byte[] r, byte[] g, byte[] b, byte[] a) {
      super(bits);
      mapSize = size;
      rgb = new int[Math.max(size, 1)];
      boolean alpha = false;
      for (int i = 0; i < size; i++) {
         int av = a == null ? 255 : a[i] & 0xFF;
         if (av != 255) {
            alpha = true;
         }
         rgb[i] = (av << 24) | ((r[i] & 0xFF) << 16) | ((g[i] & 0xFF) << 8) | (b[i] & 0xFF);
      }
      setAlpha(alpha);
   }

   public IndexColorModel(int bits, int size, byte[] cmap, int start, boolean hasalpha) {
      this(bits, size, cmap, start, hasalpha, -1);
   }

   public IndexColorModel(int bits, int size, byte[] cmap, int start, boolean hasalpha, int trans) {
      super(bits);
      mapSize = size;
      rgb = new int[Math.max(size, 1)];
      int j = start;
      boolean alpha = false;
      for (int i = 0; i < size; i++) {
         int r = cmap[j++] & 0xFF;
         int g = cmap[j++] & 0xFF;
         int b = cmap[j++] & 0xFF;
         int a = hasalpha ? cmap[j++] & 0xFF : 255;
         if (a != 255) {
            alpha = true;
         }
         rgb[i] = (a << 24) | (r << 16) | (g << 8) | b;
      }
      setAlpha(alpha);
      setTransparentPixel(trans);
   }

   public IndexColorModel(int bits, int size, int[] cmap, int start, boolean hasalpha, int trans, int transferType) {
      super(bits);
      mapSize = size;
      rgb = new int[Math.max(size, 1)];
      boolean alpha = false;
      for (int i = 0; i < size; i++) {
         int c = cmap[start + i];
         if (!hasalpha) {
            c |= 0xFF000000;
         }
         if ((c >>> 24) != 255) {
            alpha = true;
         }
         rgb[i] = c;
      }
      setAlpha(alpha);
      setTransparentPixel(trans);
      this.transferType = transferType;
   }

   private void setAlpha(boolean alpha) {
      hasAlpha = alpha;
      transparency = alpha ? TRANSLUCENT : OPAQUE;
   }

   private void setTransparentPixel(int trans) {
      if (trans >= 0 && trans < mapSize) {
         rgb[trans] &= 0x00FFFFFF;
         transparentIndex = trans;
         hasAlpha = true;
         if (transparency == OPAQUE) {
            transparency = BITMASK;
         }
      }
   }

   public final int getMapSize() {
      return mapSize;
   }

   public final int getTransparentPixel() {
      return transparentIndex;
   }

   public final void getReds(byte[] r) {
      for (int i = 0; i < mapSize; i++) {
         r[i] = (byte) (rgb[i] >> 16);
      }
   }

   public final void getGreens(byte[] g) {
      for (int i = 0; i < mapSize; i++) {
         g[i] = (byte) (rgb[i] >> 8);
      }
   }

   public final void getBlues(byte[] b) {
      for (int i = 0; i < mapSize; i++) {
         b[i] = (byte) rgb[i];
      }
   }

   public final void getAlphas(byte[] a) {
      for (int i = 0; i < mapSize; i++) {
         a[i] = (byte) (rgb[i] >>> 24);
      }
   }

   public final void getRGBs(int[] out) {
      System.arraycopy(rgb, 0, out, 0, mapSize);
   }

   public final int getRed(int pixel) {
      return (getRGB(pixel) >> 16) & 0xFF;
   }

   public final int getGreen(int pixel) {
      return (getRGB(pixel) >> 8) & 0xFF;
   }

   public final int getBlue(int pixel) {
      return getRGB(pixel) & 0xFF;
   }

   public final int getAlpha(int pixel) {
      return getRGB(pixel) >>> 24;
   }

   public final int getRGB(int pixel) {
      int i = pixel & ((1 << pixel_bits) - 1);
      return i < mapSize ? rgb[i] : 0;
   }

   public int pixelOf(int argb) {
      int best = 0;
      int bestDist = Integer.MAX_VALUE;
      if ((argb >>> 24) < 128 && transparentIndex >= 0) {
         return transparentIndex;
      }
      for (int i = 0; i < mapSize; i++) {
         int c = rgb[i];
         int dr = ((c >> 16) & 0xFF) - ((argb >> 16) & 0xFF);
         int dg = ((c >> 8) & 0xFF) - ((argb >> 8) & 0xFF);
         int db = (c & 0xFF) - (argb & 0xFF);
         int d = dr * dr + dg * dg + db * db;
         if (d < bestDist) {
            bestDist = d;
            best = i;
         }
      }
      return best;
   }
}

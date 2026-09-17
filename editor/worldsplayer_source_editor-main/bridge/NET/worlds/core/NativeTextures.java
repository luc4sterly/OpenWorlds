package NET.worlds.core;

import java.io.File;
import java.util.HashMap;
import java.util.Map;
import net.freeworlds.cmp.CmpFrames;

/**
 * RenderWare 2.1 textures as gamma.dll creates them on the software driver
 * of a true-colour desktop (FUN_0041a150: depth 16, so DAT_00489568 = 2 and
 * every texture raster is 128x128 16-bit 5-6-5, DAT_00489570 = 32768
 * bytes). Handles share NativeRw's table; RwTextureData is the reference
 * count gamma.dll keeps (FUN_004183e0 / FUN_00418430 / FUN_00418370).
 */
public final class NativeTextures {
   private NativeTextures() {
   }

   /** FUN_00417910: every texture is 0x80 pixels square. */
   public static final int SIZE = 128;

   public static final class Texture {
      /** 5-6-5 pixels, top-down, SIZE * SIZE. */
      public final short[] pixels;
      String name;
      int refs;
      int handle;

      Texture(short[] pixels) {
         this.pixels = pixels;
      }
   }

   private static final Map<String, Texture> dict = new HashMap<String, Texture>();

   public static Texture texture(int h) {
      Object o = NativeRw.get(h);
      return o instanceof Texture ? (Texture) o : null;
   }

   /**
    * FUN_00421420 / FUN_00421560 name: every '\\', ':', '.' and '/' becomes
    * '|', lower-cased (FUN_00450890), then "|" + frame when frame > 0.
    */
   static String dictName(String name, int frame) {
      StringBuilder sb = new StringBuilder(name.length() + 4);
      for (int i = 0; i < name.length(); i++) {
         char c = name.charAt(i);
         sb.append(c == '\\' || c == ':' || c == '.' || c == '/' ? '|' : Character.toLowerCase(c));
      }
      if (frame > 0) {
         sb.append('|').append(frame);
      }
      return sb.toString();
   }

   /** FUN_004183e0: RwFindNamedTexture and bump its reference count. */
   private static synchronized int findNamed(String dictName) {
      Texture t = dict.get(dictName);
      if (t == null) {
         return 0;
      }
      t.refs++;
      return t.handle;
   }

   /** FUN_004182d0: RwCreateUserRaster(128, 128, 16 bpp) + RwCreateTexture, data 1, into the dictionary. */
   private static synchronized int create(String dictName, short[] pixels) {
      Texture t = new Texture(pixels);
      t.refs = 1;
      t.handle = NativeRw.alloc(t);
      if (dictName != null) {
         t.name = dictName;
         dict.put(dictName, t);
      }
      return t.handle;
   }

   /** FUN_00418370 (Texture.nativeRelease): drop one reference, destroy at the last. */
   public static synchronized void release(int h) {
      Texture t = texture(h);
      if (t == null) {
         return;
      }
      if (t.refs < 2) {
         if (t.name != null && dict.get(t.name) == t) {
            dict.remove(t.name);
         }
         NativeRw.release(h);
      } else {
         t.refs--;
      }
   }

   /** FUN_00421420(name, file, frame): named lookup, else read the file (FileTexture). */
   public static int lookupOrRead(String name, String file, int frame) {
      if (name == null) {
         return file == null ? 0 : readTexture(null, file);
      }
      String key = dictName(name, frame);
      int h = findNamed(key);
      if (h == 0 && file != null) {
         h = readTexture(key, file);
      }
      return h;
   }

   /**
    * RwReadTexture(file) via FUN_00418430: an image file becomes a 128x128
    * texture. ⚠️ VERIFICAR against RWL21.DLL: the resampling RW applies to a
    * non-128 image (here: box filter / pixel replication like the ScapePic
    * path) and which formats it accepts (here: what javax.imageio reads).
    */
   private static int readTexture(String dictName, String file) {
      try {
         java.awt.image.BufferedImage img = javax.imageio.ImageIO.read(NativeMock.resolveCaseInsensitive(file));
         if (img == null) {
            return 0;
         }
         int w = img.getWidth();
         int h = img.getHeight();
         int[] rgb = img.getRGB(0, 0, w, h, null, 0, w);
         return create(dictName, to565(stretch(rgb, w, h)));
      } catch (Exception e) {
         return 0;
      }
   }

   /**
    * StretchBlt(HALFTONE) of the decoded image onto the 128x128 DIB
    * (FUN_004222b0). ⚠️ GDI's HALFTONE filter is not specified bit-exactly;
    * sizes that already match are copied, others are box-averaged.
    */
   static int[] stretch(int[] src, int w, int h) {
      int[] out = new int[SIZE * SIZE];
      if (w == SIZE && h == SIZE) {
         System.arraycopy(src, 0, out, 0, out.length);
         return out;
      }
      for (int y = 0; y < SIZE; y++) {
         int y0 = y * h / SIZE;
         int y1 = Math.max(y0 + 1, (y + 1) * h / SIZE);
         for (int x = 0; x < SIZE; x++) {
            int x0 = x * w / SIZE;
            int x1 = Math.max(x0 + 1, (x + 1) * w / SIZE);
            long r = 0, g = 0, b = 0;
            int n = 0;
            for (int yy = y0; yy < y1 && yy < h; yy++) {
               for (int xx = x0; xx < x1 && xx < w; xx++) {
                  int c = src[yy * w + xx];
                  r += c >> 16 & 0xFF;
                  g += c >> 8 & 0xFF;
                  b += c & 0xFF;
                  n++;
               }
            }
            out[y * SIZE + x] = n == 0 ? 0 : (int) (r / n) << 16 | (int) (g / n) << 8 | (int) (b / n);
         }
      }
      return out;
   }

   /** 24-bit to the 5-6-5 DIB (GDI truncates the low bits). */
   static short[] to565(int[] rgb) {
      short[] p = new short[rgb.length];
      for (int i = 0; i < rgb.length; i++) {
         int c = rgb[i];
         p[i] = (short) ((c >> 16 & 0xFF) >> 3 << 11 | (c >> 8 & 0xFF) >> 2 << 5 | (c & 0xFF) >> 3);
      }
      return p;
   }

   /**
    * FUN_00422b30 + FUN_004222b0 + FUN_00421560: decode a ScapePic
    * (.cmp / .mov) into up to maxFrames textures. Returns
    * {handles[], displayW, displayH} or null when the file cannot be read.
    * Palette as FUN_00422b30 builds it for a 16-bit display: file entries,
    * the rest white; the transparent index (255 when mode bit 2) becomes
    * black, the key colour, and every other entry darker than (12, 6, 12)
    * becomes (8, 8, 8) so it is not keyed out.
    */
   public static Object[] makeScapePic(String name, byte[] file, int maxFrames) {
      ScapePic sp;
      try {
         sp = ScapePic.read(file, maxFrames);
      } catch (Exception e) {
         return null;
      }
      CmpFrames img = sp.image;
      int[] pal = new int[256];
      for (int i = 0; i < 256; i++) {
         int[] c = img.palette[i];
         pal[i] = c == null ? 0xFFFFFF : c[0] << 16 | c[1] << 8 | c[2];
      }
      int key = sp.transparent ? 255 : -1;
      for (int i = 0; i < 256; i++) {
         int r = pal[i] >> 16 & 0xFF, g = pal[i] >> 8 & 0xFF, b = pal[i] & 0xFF;
         if (i == key) {
            pal[i] = 0;
         } else if (r < 12 && g < 6 && b < 12) {
            pal[i] = 0x080808;
         }
      }
      int[] handles = new int[img.frames.length];
      for (int f = 0; f < img.frames.length; f++) {
         byte[] idx = img.frames[f];
         int[] rgb = new int[img.width * img.height];
         for (int y = 0; y < img.height; y++) {
            for (int x = 0; x < img.width; x++) {
               rgb[y * img.width + x] = pal[idx[y * img.dibW + x] & 0xFF];
            }
         }
         short[] px = to565(stretch(rgb, img.width, img.height));
         String key2 = name == null ? null : dictName(name, f);
         int h = key2 == null ? 0 : findNamed(key2);
         handles[f] = h != 0 ? h : create(key2, px);
      }
      return new Object[]{handles, sp.displayW, sp.displayH};
   }
}

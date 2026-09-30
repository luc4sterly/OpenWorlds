package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;
import net.openworlds.cmp.CmpFrames;

/**
 * gamma.dll's DIB sections for ImageConverter (GIF/JPEG textures of
 * StandardTexture) and ScapePicImage/ScapePicCanvas.
 *
 * <p>FUN_00422150 (makeDIB): BITMAPINFOHEADER with biHeight = -height (top
 * down), 8 bpp with 256 palette entries if a palette is given, otherwise 32 bpp
 * (BI_RGB, BGRX), and CreateDIBSection. Here a DIB is a byte array with
 * the same padding: an 8 bpp row = (width+3)&~3 bytes, a 32 bpp row = 4*width.
 * The HBITMAP handle and the pointer to the bits are the same entry of a table
 * (the two Java fields, hDIB and pixelPtr, receive the same number).
 */
public final class NativeUiImage {
   private NativeUiImage() {
   }

   static final class Dib {
      final int w;
      final int h;
      final int bpp;
      final int stride;
      final int[] palette;
      final byte[] bits;

      Dib(int w, int h, int[] palette) {
         this.w = w;
         this.h = h;
         this.bpp = palette != null ? 8 : 32;
         this.stride = bpp == 8 ? (w + 3) & ~3 : w * 4;
         this.palette = palette;
         this.bits = new byte[Math.max(0, stride * h)];
      }

      /** 0xRRGGBB color of pixel (x, y). */
      int rgb(int x, int y) {
         if (bpp == 8) {
            return palette[bits[y * stride + x] & 0xFF];
         }
         int o = y * stride + x * 4;
         return (bits[o + 2] & 0xFF) << 16 | (bits[o + 1] & 0xFF) << 8 | (bits[o] & 0xFF);
      }
   }

   private static final List<Dib> dibs = new ArrayList<Dib>();

   static synchronized int add(Dib d) {
      int i = dibs.indexOf(null);
      if (i < 0) {
         dibs.add(d);
         return dibs.size();
      }
      dibs.set(i, d);
      return i + 1;
   }

   static synchronized Dib get(int h) {
      return h >= 1 && h <= dibs.size() ? dibs.get(h - 1) : null;
   }

   /** DeleteObject(HBITMAP). */
   public static synchronized void delete(int h) {
      if (h >= 1 && h <= dibs.size()) {
         dibs.set(h - 1, null);
      }
   }

   // ------------------------------------------------------------ ImageConverter

   /** DAT_004714ac: palette fill up to 256 entries, RGBQUAD ff ff ff 00 = white. */
   static final int PALETTE_FILL = 0xFFFFFF;

   /**
    * ImageConverter.prepareDIB (0x00423670): with colors, the Java palette
    * (ARGB) becomes RGBQUAD by copying the B, G, R bytes and putting 0 in the
    * fourth; it is padded up to 256 with DAT_004714ac. Without colors, a 32 bpp
    * DIB. Returns the handle (hDIB and pixelPtr).
    */
   public static int prepareDIB(int w, int h, int nColors, int[] colors) {
      int[] pal = null;
      if (nColors != 0) {
         pal = new int[256];
         int i = 0;
         for (; i < nColors && i < 256; i++) {
            pal[i] = colors[i] & 0xFFFFFF;
         }
         for (; i < 256; i++) {
            pal[i] = PALETTE_FILL;
         }
      }
      return add(new Dib(w, h, pal));
   }

   /**
    * setDIBPixelBytes (0x00423920): destination pixelPtr + y*((width+3)&~3) + x,
    * w bytes per row, the source advances scansize. The {@code off} offset
    * of ImageConsumer.setPixels is NOT used (the native starts from the
    * start of the array: 0x423958 passes the GetByteArrayElements pointer
    * without adding anything to it).
    */
   public static void setDIBPixelBytes(int dib, int width, int x, int y, int w, int h, byte[] px, int off, int scansize) {
      Dib d = get(dib);
      if (d == null) {
         return;
      }
      int stride = (width + 3) & ~3;
      int dst = y * stride + x;
      int src = 0;
      for (int r = 0; r < h; r++) {
         copy(px, src, d.bits, dst, w);
         dst += stride;
         src += scansize;
      }
   }

   /**
    * setDIBPixelInts (0x004239d0): ⚠️ reproduces a bug of the original. The
    * destination is pixelPtr + y*width + x in BYTES and each row advances
    * width bytes (0x4239fa imul with the width field, 0x423a0d adds x without
    * scaling), even though it copies w*4 bytes per row (shll $2 at 0x423a47)
    * into a 32 bpp DIB whose row is 4*width long. A direct-color image
    * (JPEG) ends up squeezed into the first quarter of the DIB. {@code off}
    * is not used either. The ints are written little endian (B, G, R, A).
    */
   public static void setDIBPixelInts(int dib, int width, int x, int y, int w, int h, int[] px, int off, int scansize) {
      Dib d = get(dib);
      if (d == null) {
         return;
      }
      int dst = y * width + x;
      int src = 0;
      for (int r = 0; r < h; r++) {
         for (int i = 0; i < w; i++) {
            int v = src + i < px.length ? px[src + i] : 0;
            int o = dst + i * 4;
            if (o >= 0 && o + 3 < d.bits.length) {
               d.bits[o] = (byte) v;
               d.bits[o + 1] = (byte) (v >> 8);
               d.bits[o + 2] = (byte) (v >> 16);
               d.bits[o + 3] = (byte) (v >> 24);
            }
         }
         dst += width;
         src += scansize;
      }
   }

   private static void copy(byte[] src, int so, byte[] dst, int dO, int n) {
      for (int i = 0; i < n; i++) {
         if (so + i < src.length && dO + i >= 0 && dO + i < dst.length) {
            dst[dO + i] = src[so + i];
         }
      }
   }

   /**
    * convertDIBToTexture (0x00423a90): FUN_004222b0(hDIB, width, height,
    * transparentColor, urlName, 0). On a 16-bit screen that is the
    * COLORONCOLOR StretchBlt to 128x128 5-6-5 and FUN_00421560(urlName, 0, ...)
    * (NativeTextures.gdiStretchToTexture / userTexture). The transparent
    * color is never actually used: FUN_004222b0 sets it to -1 if
    * DAT_0049d1c0 is 0, and no other gamma.dll function writes
    * DAT_0049d1c0.
    */
   public static int convertDIBToTexture(int dib, int width, int height, int transparentColor, String urlName) {
      Dib d = get(dib);
      if (d == null || width <= 0 || height <= 0) {
         return 0;
      }
      int[] rgb = new int[width * height];
      for (int y = 0; y < height; y++) {
         for (int x = 0; x < width; x++) {
            rgb[y * width + x] = d.rgb(x, y);
         }
      }
      return NativeTextures.userTexture(urlName, 0, NativeTextures.gdiStretchToTexture(rgb, width, height), width, height);
   }

   // ------------------------------------------------------------ ScapePicImage

   /**
    * ScapePicImage.loadImage (0x004103e0): reads the ScapePic; if it is not
    * valid, or if it is transparent (the original formats "ScapePicImage %s
    * cannot use transparency." with wsprintfA and does not show it), it does
    * nothing. Otherwise, an 8 bpp DIB of width (w+3)&~3 and even height
    * (h+1)&~1 with the file's palette (FUN_00421e70: R,G,B -> RGBQUAD),
    * frame 0 (FUN_00443180) and, with odd height, a memmove of the h rows one
    * row down (0x41062b). Returns {hDIB, width, height} or null.
    * ⚠️ VERIFY: the palette entries above the file's own are uninitialized
    * stack in the original (here 0). No callers in the client: none of the
    * 722 classes creates a ScapePicImage.
    */
   public static int[] loadScapePicImage(String path) {
      byte[] file;
      try {
         file = java.nio.file.Files.readAllBytes(new java.io.File(path).toPath());
      } catch (Exception e) {
         return null;
      }
      ScapePic sp;
      try {
         sp = ScapePic.read(file, 1);
      } catch (Exception e) {
         return null;
      }
      if (sp.transparent) {
         return null;
      }
      CmpFrames img = sp.image;
      int stride = (img.width + 3) & ~3;
      int evenH = (img.height + 1) & ~1;
      int[] pal = new int[256];
      for (int i = 0; i < 256; i++) {
         int[] c = img.palette[i];
         pal[i] = c == null ? 0 : c[0] << 16 | c[1] << 8 | c[2];
      }
      Dib d = new Dib(stride, evenH, pal);
      byte[] idx = img.frames[0];
      for (int y = 0; y < img.height; y++) {
         System.arraycopy(idx, y * img.dibW, d.bits, y * d.stride, img.width);
      }
      if (img.height < evenH) {
         System.arraycopy(d.bits, 0, d.bits, (evenH - img.height) * d.stride, d.stride * img.height);
      }
      return new int[]{add(d), img.width, img.height};
   }

   /**
    * ScapePicCanvas.bitBlt (0x00410200): with non-null hwnd and DIB,
    * BitBlt(SRCCOPY) of (sx, sy, w, h) from the DIB to (dx, dy) of the window.
    * The system palette (FUN_0040d7a0/SelectPalette) only matters on an 8-bit
    * screen. AWT equivalent: draw that region on the Graphics of the
    * window's component (NativeWindows.component).
    */
   public static void bitBlt(int hwnd, int dib, int dx, int dy, int sx, int sy, int w, int h) {
      Dib d = get(dib);
      java.awt.Component c = NativeWindows.component(hwnd);
      if (hwnd == 0 || d == null || c == null || w <= 0 || h <= 0) {
         return;
      }
      java.awt.image.BufferedImage img = new java.awt.image.BufferedImage(w, h, java.awt.image.BufferedImage.TYPE_INT_RGB);
      for (int y = 0; y < h; y++) {
         for (int x = 0; x < w; x++) {
            int X = sx + x;
            int Y = sy + y;
            img.setRGB(x, y, X >= 0 && Y >= 0 && X < d.w && Y < d.h ? d.rgb(X, Y) : 0);
         }
      }
      java.awt.Graphics g = c.getGraphics();
      if (g != null) {
         g.drawImage(img, dx, dy, null);
         g.dispose();
      }
   }
}

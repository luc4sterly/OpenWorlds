package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;
import net.openworlds.cmp.CmpFrames;

/**
 * DIB sections de gamma.dll para ImageConverter (texturas GIF/JPEG de
 * StandardTexture) y ScapePicImage/ScapePicCanvas.
 *
 * <p>FUN_00422150 (makeDIB): BITMAPINFOHEADER con biHeight = -alto (de arriba
 * abajo), 8 bpp con 256 entradas de paleta si se le da paleta, si no 32 bpp
 * (BI_RGB, BGRX), y CreateDIBSection. Aqui un DIB es un array de bytes con
 * el mismo relleno: fila de 8 bpp = (ancho+3)&~3 bytes, de 32 bpp = 4*ancho.
 * El handle HBITMAP y el puntero a los bits son la misma entrada de una tabla
 * (los dos campos Java, hDIB y pixelPtr, reciben el mismo numero).
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

      /** Color 0xRRGGBB del pixel (x, y). */
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

   /** DAT_004714ac: relleno de la paleta hasta 256 entradas, RGBQUAD ff ff ff 00 = blanco. */
   static final int PALETTE_FILL = 0xFFFFFF;

   /**
    * ImageConverter.prepareDIB (0x00423670): con colores, la paleta Java
    * (ARGB) pasa a RGBQUAD copiando los bytes B, G, R y poniendo 0 en el
    * cuarto; se rellena hasta 256 con DAT_004714ac. Sin colores, DIB de 32 bpp.
    * Devuelve el handle (hDIB y pixelPtr).
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
    * setDIBPixelBytes (0x00423920): destino pixelPtr + y*((ancho+3)&~3) + x,
    * w bytes por fila, la fuente avanza scansize. El desplazamiento
    * {@code off} de ImageConsumer.setPixels NO se usa (el nativo parte del
    * inicio del array: 0x423958 pasa el puntero de GetByteArrayElements sin
    * sumarle nada).
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
    * setDIBPixelInts (0x004239d0): ⚠️ reproduce un fallo del original. El
    * destino es pixelPtr + y*ancho + x en BYTES y cada fila avanza ancho
    * bytes (0x4239fa imul con el campo width, 0x423a0d suma x sin
    * escalar), aunque copia w*4 bytes por fila (shll $2 en 0x423a47) a un
    * DIB de 32 bpp cuya fila mide 4*ancho. Una imagen de color directo
    * (JPEG) queda comprimida en el primer cuarto del DIB. {@code off} tampoco
    * se usa. Los ints se escriben en little endian (B, G, R, A).
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
    * convertDIBToTexture (0x00423a90): FUN_004222b0(hDIB, ancho, alto,
    * transparentColor, urlName, 0). En pantalla de 16 bits eso es el
    * StretchBlt COLORONCOLOR a 128x128 5-6-5 y FUN_00421560(urlName, 0, ...)
    * (NativeTextures.gdiStretchToTexture / userTexture). El color
    * transparente no llega a usarse: FUN_004222b0 lo pone a -1 si
    * DAT_0049d1c0 es 0, y ninguna otra funcion de gamma.dll escribe
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
    * ScapePicImage.loadImage (0x004103e0): lee el ScapePic; si no es valido,
    * o si es transparente (el original formatea "ScapePicImage %s cannot use
    * transparency." con wsprintfA y no lo muestra), no hace nada. Si no, un
    * DIB de 8 bpp de ancho (w+3)&~3 y alto par (h+1)&~1 con la paleta del
    * fichero (FUN_00421e70: R,G,B -> RGBQUAD), el frame 0 (FUN_00443180) y,
    * con alto impar, memmove de las h filas una fila hacia abajo (0x41062b).
    * Devuelve {hDIB, ancho, alto} o null.
    * ⚠️ VERIFICAR: las entradas de paleta por encima de las del fichero son
    * pila sin inicializar en el original (aqui 0). Sin llamadores en el
    * cliente: ninguna de las 722 clases crea un ScapePicImage.
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
    * ScapePicCanvas.bitBlt (0x00410200): con hwnd y DIB no nulos,
    * BitBlt(SRCCOPY) de (sx, sy, w, h) del DIB a (dx, dy) de la ventana. La
    * paleta de sistema (FUN_0040d7a0/SelectPalette) solo importa en pantalla
    * de 8 bits. Equivalente AWT: dibujar esa region en el Graphics del
    * componente de la ventana (NativeWindows.component).
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

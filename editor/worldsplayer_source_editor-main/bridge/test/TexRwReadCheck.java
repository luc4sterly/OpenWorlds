package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.nio.file.Files;

/**
 * RwReadTexture (RWL21 0x100178f0): lectores BMP (FUN_10021620) y Sun
 * raster (FUN_10021da0), reescalado por área (FUN_10042f30/FUN_10043bf0) a
 * 128x128 o 16x16, y conversión del driver a 5-6-5 (RWDL6D21 FUN_10007a80,
 * negro -> 0x0001). Ficheros sintéticos con valores calculados a mano. Sale
 * con 1 si algo falla.
 */
public final class TexRwReadCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("texrw").toFile();

      // 2x2 de 24 bits (filas de abajo arriba): < 64 de ancho -> 16x16, cada
      // píxel 8x8 exacto (paso 0x2000, 8 filas por fila fuente, norma
      // 2048*2048), guardado replicado 8x8 -> bloques de 64x64.
      //   arriba: rojo, negro   abajo: verde, (8,4,8)
      File f = new File(dir, "a.bmp");
      Files.write(f.toPath(), bmp24(2, 2, new int[]{0xFF0000, 0x000000, 0x00FF00, 0x080408}));
      short[] t = NativeTextures.rwTextureRaster(rwPath(f));
      check("2x2 leída", t != null);
      if (t != null) {
         eq("2x2 arriba-izq rojo", px(t, 0, 0), 0xF800);
         eq("2x2 arriba-izq (63,63)", px(t, 63, 63), 0xF800);
         eq("2x2 arriba-der negro -> 0x0001", px(t, 64, 0), 0x0001);
         eq("2x2 abajo-izq verde", px(t, 0, 64), 0x07E0);
         eq("2x2 abajo-der (8,4,8)", px(t, 127, 127), 0x0821); // 1<<11 | 1<<5 | 1
      }

      // 256x2 de 24 bits -> 128x128: cada columna promedia dos píxeles
      // (paso 0x20000), norma ((128<<16)/256 + 0x80 >> 8) * (0x400000 + 0x80 >> 8)
      // = 128 * 16384; sale floor((p0+p1)/2). R alterna 255/0 -> 127;
      // G = i -> floor((2k + 2k+1)/2) = 2k; B = 0.
      int[] wide = new int[512];
      for (int y = 0; y < 2; y++) {
         for (int i = 0; i < 256; i++) {
            wide[y * 256 + i] = ((i & 1) == 0 ? 0xFF0000 : 0) | i << 8;
         }
      }
      f = new File(dir, "b.bmp");
      Files.write(f.toPath(), bmp24(256, 2, wide));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("256x2 leída", t != null);
      if (t != null) {
         for (int k : new int[]{0, 1, 50, 127}) {
            int want = (127 >> 3) << 11 | ((2 * k) >> 2) << 5;
            eq("256x2 columna " + k + " fila 0", px(t, k, 0), want);
            eq("256x2 columna " + k + " fila 127", px(t, k, 127), want);
         }
      }

      // 32x32 uniforme (200,100,50) -> 16x16: 2x2 píxeles iguales dan el mismo
      // valor (norma 128*128), ya en 5-6-5: 25<<11 | 25<<5 | 6
      int[] uni = new int[32 * 32];
      java.util.Arrays.fill(uni, 200 << 16 | 100 << 8 | 50);
      f = new File(dir, "c.bmp");
      Files.write(f.toPath(), bmp24(32, 32, uni));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("32x32 leída", t != null);
      if (t != null) {
         eq("32x32 -> 16x16 uniforme", px(t, 5, 100), 25 << 11 | 25 << 5 | 6);
      }

      // 8 bits de 128x128: ya mide una textura -> sin reescalar, por la
      // paleta; índice 0 negro -> 0x0001, índice 1 blanco
      byte[] idx = new byte[128 * 128];
      idx[0] = 1; // abajo a la izquierda en el fichero = fila 127
      f = new File(dir, "d.bmp");
      Files.write(f.toPath(), bmp8(128, 128, new int[]{0x000000, 0xFFFFFF}, idx));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("8 bits leída", t != null);
      if (t != null) {
         eq("8 bits (0,127) blanco", px(t, 0, 127), 0xFFFF);
         eq("8 bits (0,0) negro -> 0x0001", px(t, 0, 0), 0x0001);
      }

      // Sun raster de 8 bits 16x16 sin mapa (rampa de grises), tipo 1: ya
      // mide la textura pequeña; índice 200 -> (200,200,200) -> 25<<11|50<<5|25
      byte[] ras = new byte[16 * 16];
      java.util.Arrays.fill(ras, (byte) 200);
      f = new File(dir, "e.ras");
      Files.write(f.toPath(), ras8(16, 16, ras));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("ras leída", t != null);
      if (t != null) {
         eq("ras gris 200", px(t, 99, 3), 25 << 11 | 50 << 5 | 25);
      }

      // formato por la firma, no por la extensión: un BMP llamado .ras
      f = new File(dir, "g.ras");
      Files.write(f.toPath(), bmp24(2, 2, new int[]{0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000}));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      eq("BMP con extensión .ras", t == null ? -1 : px(t, 0, 0), 0xF800);

      // tamaños que FUN_10017b60 rechaza no existen tras reescalar; un fichero
      // sin firma conocida no se lee
      f = new File(dir, "h.bmp");
      Files.write(f.toPath(), new byte[]{'G', 'I', 'F', '8', '9', 'a', 0, 0});
      check("GIF rechazado", NativeTextures.rwTextureRaster(rwPath(f)) == null);

      // RLE8: una fila "3 x idx1, 1 x idx0" y fin de mapa; 4x1 de 8 bits
      f = new File(dir, "i.bmp");
      Files.write(f.toPath(), bmpRle8());
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("RLE8 leída", t != null);
      if (t != null) {
         // 4 de ancho -> 16x16: columnas 0..11 = índice 1 (blanco), 12..15 negro
         eq("RLE8 (0,0)", px(t, 0, 0), 0xFFFF);
         eq("RLE8 (95,0)", px(t, 95, 0), 0xFFFF);
         eq("RLE8 (96,0)", px(t, 96, 0), 0x0001);
      }

      if (failures > 0) {
         System.out.println("TexRwReadCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("TexRwReadCheck: OK");
   }

   /**
    * Ruta absoluta para RW (FUN_10043d50: "letra:" o '\\' delante); una que
    * empieza por '/' RW la toma por relativa y la busca en ".;..". La unidad
    * sintética "u:" es la del parche de URL del puente (NativeMock.localFile).
    */
   static String rwPath(File f) {
      return "u:" + f.getPath();
   }

   static int px(short[] t, int x, int y) {
      return t[y * 128 + x] & 0xFFFF;
   }

   /** BMP de 24 bits, cabecera de 40; rgb[] de arriba abajo. */
   static byte[] bmp24(int w, int h, int[] rgb) {
      int row = w * 3 + 3 & ~3;
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      header(o, 54 + row * h, 54, w, h, 24, 0);
      for (int y = h - 1; y >= 0; y--) {
         for (int x = 0; x < w; x++) {
            int c = rgb[y * w + x];
            o.write(c & 0xFF);
            o.write(c >> 8 & 0xFF);
            o.write(c >> 16 & 0xFF);
         }
         for (int i = w * 3; i < row; i++) {
            o.write(0);
         }
      }
      return o.toByteArray();
   }

   /** BMP de 8 bits; idx[] en el orden del fichero (de abajo arriba). */
   static byte[] bmp8(int w, int h, int[] pal, byte[] idx) {
      int row = w + 3 & ~3;
      int off = 54 + 256 * 4;
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      header(o, off + row * h, off, w, h, 8, 0);
      for (int i = 0; i < 256; i++) {
         int c = i < pal.length ? pal[i] : 0;
         o.write(c & 0xFF);
         o.write(c >> 8 & 0xFF);
         o.write(c >> 16 & 0xFF);
         o.write(0);
      }
      for (int y = 0; y < h; y++) {
         o.write(idx, y * w, w);
         for (int i = w; i < row; i++) {
            o.write(0);
         }
      }
      return o.toByteArray();
   }

   static byte[] bmpRle8() {
      int off = 54 + 256 * 4;
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      byte[] data = {3, 1, 1, 0, 0, 1};
      header(o, off + data.length, off, 4, 1, 8, 1);
      for (int i = 0; i < 256; i++) {
         int c = i == 1 ? 0xFFFFFF : 0;
         o.write(c & 0xFF);
         o.write(c >> 8 & 0xFF);
         o.write(c >> 16 & 0xFF);
         o.write(0);
      }
      o.write(data, 0, data.length);
      return o.toByteArray();
   }

   private static void header(ByteArrayOutputStream o, int size, int off, int w, int h, int bits, int comp) {
      o.write('B');
      o.write('M');
      le32(o, size);
      le32(o, 0);
      le32(o, off);
      le32(o, 40);
      le32(o, w);
      le32(o, h);
      o.write(1);
      o.write(0);
      o.write(bits);
      o.write(0);
      le32(o, comp);
      le32(o, 0);
      le32(o, 2835);
      le32(o, 2835);
      le32(o, 0);
      le32(o, 0);
   }

   static byte[] ras8(int w, int h, byte[] idx) {
      ByteArrayOutputStream o = new ByteArrayOutputStream();
      int[] hd = {0x59a66a95, w, h, 8, w * h, 1, 0, 0};
      for (int v : hd) {
         o.write(v >>> 24);
         o.write(v >> 16 & 0xFF);
         o.write(v >> 8 & 0xFF);
         o.write(v & 0xFF);
      }
      int row = w + 1 & ~1;
      for (int y = 0; y < h; y++) {
         o.write(idx, y * w, w);
         for (int i = w; i < row; i++) {
            o.write(0);
         }
      }
      return o.toByteArray();
   }

   private static void le32(ByteArrayOutputStream o, int v) {
      o.write(v & 0xFF);
      o.write(v >> 8 & 0xFF);
      o.write(v >> 16 & 0xFF);
      o.write(v >>> 24);
   }

   static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FALLA " + what + ": 0x" + Long.toHexString(got) + " (esperado 0x" + Long.toHexString(want) + ")");
      }
   }
}

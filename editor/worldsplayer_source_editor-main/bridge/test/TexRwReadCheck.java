package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.nio.file.Files;

/**
 * RwReadTexture (RWL21 0x100178f0): BMP readers (FUN_10021620) and Sun
 * raster (FUN_10021da0), area rescaling (FUN_10042f30/FUN_10043bf0) to
 * 128x128 or 16x16, and the driver's conversion to 5-6-5 (RWDL6D21
 * FUN_10007a80, black -> 0x0001). Synthetic files with hand-calculated
 * values. Exits with 1 if anything fails.
 */
public final class TexRwReadCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("texrw").toFile();

      // 24-bit 2x2 (rows from bottom to top): < 64 wide -> 16x16, each
      // pixel exactly 8x8 (step 0x2000, 8 rows per source row, norm
      // 2048*2048), stored replicated 8x8 -> blocks of 64x64.
      //   top: red, black   bottom: green, (8,4,8)
      File f = new File(dir, "a.bmp");
      Files.write(f.toPath(), bmp24(2, 2, new int[]{0xFF0000, 0x000000, 0x00FF00, 0x080408}));
      short[] t = NativeTextures.rwTextureRaster(rwPath(f));
      check("2x2 read", t != null);
      if (t != null) {
         eq("2x2 top-left red", px(t, 0, 0), 0xF800);
         eq("2x2 top-left (63,63)", px(t, 63, 63), 0xF800);
         eq("2x2 top-right black -> 0x0001", px(t, 64, 0), 0x0001);
         eq("2x2 bottom-left green", px(t, 0, 64), 0x07E0);
         eq("2x2 bottom-right (8,4,8)", px(t, 127, 127), 0x0821); // 1<<11 | 1<<5 | 1
      }

      // 24-bit 256x2 -> 128x128: each column averages two pixels
      // (step 0x20000), norm ((128<<16)/256 + 0x80 >> 8) * (0x400000 + 0x80 >> 8)
      // = 128 * 16384; gives floor((p0+p1)/2). R alternates 255/0 -> 127;
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
      check("256x2 read", t != null);
      if (t != null) {
         for (int k : new int[]{0, 1, 50, 127}) {
            int want = (127 >> 3) << 11 | ((2 * k) >> 2) << 5;
            eq("256x2 column " + k + " row 0", px(t, k, 0), want);
            eq("256x2 column " + k + " row 127", px(t, k, 127), want);
         }
      }

      // uniform 32x32 (200,100,50) -> 16x16: 2x2 equal pixels give the same
      // value (norm 128*128), already in 5-6-5: 25<<11 | 25<<5 | 6
      int[] uni = new int[32 * 32];
      java.util.Arrays.fill(uni, 200 << 16 | 100 << 8 | 50);
      f = new File(dir, "c.bmp");
      Files.write(f.toPath(), bmp24(32, 32, uni));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("32x32 read", t != null);
      if (t != null) {
         eq("32x32 -> 16x16 uniform", px(t, 5, 100), 25 << 11 | 25 << 5 | 6);
      }

      // 8-bit 128x128: it already measures a texture -> not rescaled, via the
      // palette; index 0 black -> 0x0001, index 1 white
      byte[] idx = new byte[128 * 128];
      idx[0] = 1; // bottom left in the file = row 127
      f = new File(dir, "d.bmp");
      Files.write(f.toPath(), bmp8(128, 128, new int[]{0x000000, 0xFFFFFF}, idx));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("8-bit read", t != null);
      if (t != null) {
         eq("8-bit (0,127) white", px(t, 0, 127), 0xFFFF);
         eq("8-bit (0,0) black -> 0x0001", px(t, 0, 0), 0x0001);
      }

      // 8-bit 16x16 Sun raster without a map (gray ramp), type 1: it already
      // measures the small texture; index 200 -> (200,200,200) -> 25<<11|50<<5|25
      byte[] ras = new byte[16 * 16];
      java.util.Arrays.fill(ras, (byte) 200);
      f = new File(dir, "e.ras");
      Files.write(f.toPath(), ras8(16, 16, ras));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("ras read", t != null);
      if (t != null) {
         eq("ras gray 200", px(t, 99, 3), 25 << 11 | 50 << 5 | 25);
      }

      // format by the signature, not by the extension: a BMP named .ras
      f = new File(dir, "g.ras");
      Files.write(f.toPath(), bmp24(2, 2, new int[]{0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000}));
      t = NativeTextures.rwTextureRaster(rwPath(f));
      eq("BMP with a .ras extension", t == null ? -1 : px(t, 0, 0), 0xF800);

      // sizes that FUN_10017b60 rejects do not exist after rescaling; a file
      // without a known signature is not read
      f = new File(dir, "h.bmp");
      Files.write(f.toPath(), new byte[]{'G', 'I', 'F', '8', '9', 'a', 0, 0});
      check("GIF rejected", NativeTextures.rwTextureRaster(rwPath(f)) == null);

      // RLE8: one row "3 x idx1, 1 x idx0" and end of bitmap; 8-bit 4x1
      f = new File(dir, "i.bmp");
      Files.write(f.toPath(), bmpRle8());
      t = NativeTextures.rwTextureRaster(rwPath(f));
      check("RLE8 read", t != null);
      if (t != null) {
         // 4 wide -> 16x16: columns 0..11 = index 1 (white), 12..15 black
         eq("RLE8 (0,0)", px(t, 0, 0), 0xFFFF);
         eq("RLE8 (95,0)", px(t, 95, 0), 0xFFFF);
         eq("RLE8 (96,0)", px(t, 96, 0), 0x0001);
      }

      if (failures > 0) {
         System.out.println("TexRwReadCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("TexRwReadCheck: OK");
   }

   /**
    * Absolute path for RW (FUN_10043d50: "letter:" or '\\' in front); RW takes
    * one that starts with '/' as relative and looks for it in ".;..". The
    * synthetic drive "u:" is the one from the bridge's URL patch
    * (NativeMock.localFile).
    */
   static String rwPath(File f) {
      return "u:" + f.getPath();
   }

   static int px(short[] t, int x, int y) {
      return t[y * 128 + x] & 0xFFFF;
   }

   /** 24-bit BMP, 40-byte header; rgb[] from top to bottom. */
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

   /** 8-bit BMP; idx[] in file order (from bottom to top). */
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
         System.out.println("FAIL " + what);
      }
   }

   static void eq(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FAIL " + what + ": 0x" + Long.toHexString(got) + " (expected 0x" + Long.toHexString(want) + ")");
      }
   }
}

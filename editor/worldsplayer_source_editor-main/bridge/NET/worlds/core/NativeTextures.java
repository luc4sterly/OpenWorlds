package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import net.openworlds.cmp.CmpFrames;

/**
 * Textures as created by gamma.dll and RenderWare 2.1 with the 16-bit
 * software driver (RWDL6D21) on a true-colour desktop.
 *
 * <p>Three different paths lead to RW's texture dictionary:
 * <ul>
 * <li><b>gamma.dll through GDI</b> ({@code .cmp}/{@code .mov}, text): the
 * image is painted into a DIB and stretched with {@code StretchBlt} onto a
 * 128x128 16-bit 5-6-5 DIB ({@link #gdiStretchToTexture}); the buffer goes
 * to an RW user raster ({@code FUN_004182d0}).</li>
 * <li><b>RwReadTexture</b> ({@code FileTexture}, {@code .bmp}/{@code .ras}):
 * RWL21 reads the file, rescales it itself with an area average and the
 * driver converts it to 5-6-5 ({@link #rwReadRaster}).</li>
 * <li><b>RwGetNamedTexture</b> (the {@code Texture} command of a
 * {@code .rwx}): looks the base name up in the dictionary and, if it is not
 * there, reads it from the shape path {@code ".;.."}
 * ({@link #rwGetNamed}).</li>
 * </ul>
 *
 * <p>The handles share NativeRw's table. Each texture keeps RW's "texture
 * data" ({@code RwSetTextureData}, +0x20), which gamma.dll uses as a
 * reference count (FUN_004183e0 / FUN_00418430 / FUN_00418370); the ones RW
 * reads on its own leave it at 0.
 *
 * <p>The rasterizer (NativeCamera) always samples 128x128; a 16x16 RW raster
 * (images narrower than 64, see {@link Resampler}) is stored replicated 8x8,
 * which gives the same texel with nearest-neighbour sampling: floor(128u)/8
 * == floor(16u).
 */
public final class NativeTextures {
   private NativeTextures() {
   }

   /** FUN_00417910 returns 0x80: the side of every texture gamma.dll creates. */
   public static final int SIZE = 128;

   /**
    * Texture raster sizes of the driver (RWDL6D21 0x10001174..0x10001197
    * copies DAT_100790f0 = 0x80 to device+0x20/+0x24 and DAT_100790f8 = 0x10
    * to device+0x2bc/+0x2c0).
    */
   static final int DEV_TEX = 0x80;
   static final int DEV_TEX_SMALL = 0x10;

   /**
    * RwReadRaster options with which RW reads its textures (DAT_1005ac04):
    * 0x15 in RWL21's .data, 0x14 after the RwSetTextureDithering(2) that
    * gamma.dll does at start-up (FUN_0041a150 -> 0x100193f0: {@code &= ~3}).
    */
   static final int RW_TEXTURE_READ_FLAGS = 0x14;

   public static final class Texture {
      /** 5-6-5, top-down, SIZE * SIZE. */
      public final short[] pixels;
      /** Name it has in the dictionary, or null. */
      String name;
      /** RwGetTextureData (+0x20): gamma.dll's reference count. */
      int data;
      int handle;

      Texture(short[] pixels) {
         this.pixels = pixels;
      }
   }

   // ------------------------------------------------------------------
   // RW texture dictionary (a single one: gamma.dll does not call
   // RwTextureDictBegin/End). Key: the name folded the way FUN_10043f20
   // compares it (only a-z are converted to upper case).
   // ------------------------------------------------------------------

   private static final Map<String, Texture> dict = new HashMap<String, Texture>();

   /** Audit (-Dopenworlds.matStats): name -> "WxH" of the image before stretching it. */
   private static final Map<String, String> source = new java.util.LinkedHashMap<String, String>();

   /** Inventory of what was decoded, for the texture audit. */
   public static synchronized void dumpInventory() {
      System.err.println("[RW] texturas en el diccionario: " + dict.size());
      int stretched = 0;
      for (Map.Entry<String, String> e : source.entrySet()) {
         if (!"128x128".equals(e.getValue())) {
            stretched++;
            System.err.println("[RW]   " + e.getKey() + " origen " + e.getValue() + " -> reescalada a 128x128");
         }
      }
      System.err.println("[RW] texturas con tamaño distinto de 128x128: " + stretched + " de " + source.size());
   }

   public static Texture texture(int h) {
      Object o = NativeRw.get(h);
      return o instanceof Texture ? (Texture) o : null;
   }

   /** FUN_10043f20: name equality without distinguishing a-z from A-Z (nothing else). */
   static String rwFold(String s) {
      StringBuilder b = new StringBuilder(s.length());
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         b.append(c >= 'a' && c <= 'z' ? (char) (c - 0x20) : c);
      }
      return b.toString();
   }

   /**
    * FUN_10043e80: the name RW looks a texture up by. It strips everything
    * up to the last '\\' (DAT_1005a078; '/' does not count) or, if there is
    * none, a leading "X:" drive; and the extension from the last '.' after
    * that point.
    */
   static String rwBaseName(String p) {
      int sep = p.lastIndexOf('\\');
      int start;
      if (sep >= 0) {
         start = sep + 1;
      } else {
         start = p.length() >= 2 && p.charAt(1) == ':' ? 2 : 0;
      }
      int dot = p.lastIndexOf('.');
      int end = dot < 0 || dot <= start ? p.length() : dot;
      return p.substring(start, end);
   }

   /** RwFindNamedTexture (0x100183c0): by base name, without reading anything. */
   static synchronized Texture rwFindNamed(String name) {
      return name == null ? null : dict.get(rwFold(rwBaseName(name)));
   }

   /**
    * RwAddTextureToDict (0x10016890) for a texture that is not yet in any
    * dictionary: if the dictionary already has that name (compared as it is,
    * not by base name) it is error 0x69 and the texture is left out.
    */
   private static synchronized boolean rwAddToDict(String name, Texture t) {
      String k = rwFold(name);
      if (dict.containsKey(k)) {
         return false;
      }
      dict.put(k, t);
      t.name = name;
      return true;
   }

   /** RwDestroyTexture (0x10016b00): takes it out of the dictionary and frees it. */
   private static synchronized void rwDestroy(Texture t) {
      if (t.name != null && dict.get(rwFold(t.name)) == t) {
         dict.remove(rwFold(t.name));
      }
      NativeRw.release(t.handle);
   }

   private static Texture newTexture(short[] pixels) {
      Texture t = new Texture(pixels);
      t.handle = NativeRw.alloc(t);
      return t;
   }

   // ------------------------------------------------------------------
   // gamma.dll: the dictionary with reference counts
   // ------------------------------------------------------------------

   /**
    * FUN_00421420 / FUN_00421560: every '\\', ':', '.' and '/' becomes '|',
    * in lower case with the table of FUN_00450890 (DAT_00482818: A-Z only)
    * and, with frame &gt; 0, "|" (DAT_00471308) + the number in decimal.
    * Without '\\', ':' or '.', RW's base name (FUN_10043e80) is the whole
    * name.
    */
   static String dictName(String name, int frame) {
      StringBuilder sb = new StringBuilder(name.length() + 4);
      for (int i = 0; i < name.length(); i++) {
         char c = name.charAt(i);
         sb.append(c == '\\' || c == ':' || c == '.' || c == '/' ? '|' : c >= 'A' && c <= 'Z' ? (char) (c + 0x20) : c);
      }
      if (frame > 0) {
         sb.append('|').append(frame);
      }
      return sb.toString();
   }

   /**
    * FUN_004183e0: RwFindNamedTexture and raises the count. A texture with
    * data 0 is one that RW read on its own: gamma.dll destroys it and
    * returns 0, so as to read its own.
    */
   static synchronized int findNamed(String key) {
      Texture t = rwFindNamed(key);
      if (t == null) {
         return 0;
      }
      if (t.data == 0) {
         rwDestroy(t);
         return 0;
      }
      t.data++;
      return t.handle;
   }

   /** FUN_004182d0: RwCreateUserRaster(128, 128, 16 bpp) + RwCreateTexture, data 1, into the dictionary. */
   static synchronized int create(String key, short[] pixels, int srcW, int srcH) {
      Texture t = newTexture(pixels);
      t.data = 1;
      if (key != null) {
         source.put(key, srcW + "x" + srcH);
         rwAddToDict(key, t);
      }
      return t.handle;
   }

   /** FUN_00418430: RwReadTexture(file), data 1, into the dictionary under gamma's name. */
   private static synchronized int readTexture(String key, String file) {
      Texture t = rwReadTexture(file);
      if (t == null) {
         return 0;
      }
      t.data = 1;
      if (key != null) {
         rwAddToDict(key, t);
      }
      return t.handle;
   }

   /** FUN_00418370 (Texture.nativeRelease via FUN_00421690): lowers the count and destroys on the last one. */
   public static synchronized void release(int h) {
      Texture t = texture(h);
      if (t == null) {
         return;
      }
      if (t.data < 2) {
         rwDestroy(t);
      } else {
         t.data--;
      }
   }

   /** FUN_00421420(name, file, frame): lookup by name and, if it is missing, RwReadTexture (FileTexture). */
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

   /** FUN_00421560(name, frame, pixels): the dictionary's one if it is already there (and the buffer is thrown away), otherwise a new one. */
   static int userTexture(String name, int frame, short[] px, int srcW, int srcH) {
      if (name == null) {
         return create(null, px, srcW, srcH);
      }
      String key = dictName(name, frame);
      int h = findNamed(key);
      return h != 0 ? h : create(key, px, srcW, srcH);
   }

   // ------------------------------------------------------------------
   // gamma.dll through GDI: FUN_004222b0
   // ------------------------------------------------------------------

   /**
    * FUN_004222b0 on a 16-bit screen (FUN_00417900 == 2): a destination DIB of
    * 128x128 (FUN_00422150: 16 bpp, BI_BITFIELDS f800/07e0/001f, top-down),
    * {@code SetStretchBltMode(hdc, 3)} and
    * {@code StretchBlt(dst, 0,0,128,128, src, 0,0,w,h, SRCCOPY)} (0x422682 /
    * 0x422710); then the bits are copied as they are (FUN_0044df50). The
    * transparency mask of 0x4228a8.. only runs with an 8-bit screen.
    *
    * <p>Mode 3 is COLORONCOLOR (STRETCH_DELETESCANS), not HALFTONE (4): each
    * destination pixel is ONE source pixel, with no colour mixing. Which source
    * pixel each destination pixel takes (the phase of GDI's DDA) is in gdi32, not
    * in our binaries: see {@link #gdiSourceIndex}.
    *
    * @param src 0xRRGGBB colours of the source DIB, w*h, row by row, top to
    * bottom
    */
   static short[] gdiStretchToTexture(int[] src, int w, int h) {
      short[] out = new short[SIZE * SIZE];
      for (int y = 0; y < SIZE; y++) {
         int sy = gdiSourceIndex(y, SIZE, h);
         for (int x = 0; x < SIZE; x++) {
            out[y * SIZE + x] = gdiTo565(src[sy * w + gdiSourceIndex(x, SIZE, w)]);
         }
      }
      return out;
   }

   /**
    * Source pixel of a destination pixel in COLORONCOLOR: {@code d * s / D}
    * (rounded down, left corner of the destination pixel). ⚠️ VERIFY: this
    * is the phase of the ReactOS reimplementation; the one in Windows' gdi32
    * is not in gamma.dll or RWL21. Another phase (pixel centre:
    * {@code (2d+1)s / 2D}) would move at most one source pixel in the
    * columns/rows where they differ; TexStretchCheck quantifies it.
    */
   static int gdiSourceIndex(int d, int dstLen, int srcLen) {
      return (int) ((long) d * srcLen / dstLen);
   }

   /**
    * 24-bit colour of the source DIB to the 5-6-5 bitfields of the
    * destination: the high bits are kept. ⚠️ VERIFY: the colour
    * translation is done by gdi32 (truncation in ReactOS and Wine; it is
    * not in our binaries).
    */
   static short gdiTo565(int c) {
      return (short) ((c >> 16 & 0xFF) >> 3 << 11 | (c >> 8 & 0xFF) >> 2 << 5 | (c & 0xFF) >> 3);
   }

   /**
    * FUN_00422b30 + FUN_004222b0 + FUN_00421560: a ScapePic (.cmp / .mov)
    * into up to maxFrames textures. Returns {handles[], displayW, displayH}
    * or null if the file cannot be read. Palette as FUN_00422b30 builds it
    * for a 16-bit screen: the file's entries and the rest white
    * (DAT_004714a8 = ff ff ff); the transparent index (255 if bit 2 of the
    * mode is set) becomes DAT_0049d1e1 (in .bss, nobody writes it: black,
    * the colour key) and every other entry with R &lt; 12, G &lt; 6 and B
    * &lt; 12 becomes DAT_004714f4 = (8, 8, 8) so as not to become
    * transparent. The source DIB is 8-bit with that palette, width rounded
    * up to a multiple of 4 and height to a multiple of 2, and the StretchBlt
    * takes only the w x h rectangle of the image.
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
         handles[f] = userTexture(name, f, gdiStretchToTexture(rgb, img.width, img.height), img.width, img.height);
      }
      return new Object[]{handles, sp.displayW, sp.displayH};
   }

   // ------------------------------------------------------------------
   // StringTexture: FUN_00424af0 + FUN_00424870
   // ------------------------------------------------------------------

   /** Size in pixels of the text DIB according to FUN_00424870 (0x424961..0x4249b5). */
   static int[] stringExtent(int cx, int cy) {
      if (cx * cy > 0xfffff) {
         // 0x424978: cx = cy / 2^20 (signed division, toward zero); the
         // warning DAT_00471994 goes to the console
         cx = (cy + (cy >> 31 & 0xfffff)) >> 20;
      }
      if (cx == 0 || cy == 0) {
         cx = 8;
         cy = 8;
      }
      return new int[]{cx, cy};
   }

   /**
    * Text and background colours (COLORREF 0x00BBGGRR) after the 16-bit
    * adjustments of 0x424a53..0x424a77: black text -&gt; 0x080808; background
    * 0xfefefe -&gt; 0 (the colour key: transparent background); black
    * background -&gt; 0x080808.
    */
   static int[] stringColors(int fg, int bg) {
      if (fg == 0) {
         fg = 0x080808;
      }
      if (bg == 0xfefefe) {
         bg = 0;
      } else if (bg == 0) {
         bg = 0x080808;
      }
      return new int[]{fg, bg};
   }

   /** java.awt.Color.getRGB() (0xAARRGGBB) to the COLORREF that FUN_00424af0 builds (0x00BBGGRR). */
   static int colorRef(int argb) {
      return (argb >> 8 & 0xFF) << 8 | argb >> 16 & 0xFF | (argb & 0xFF) << 16;
   }

   /** Font face: "Kanji..." (strncmp 5, DAT_00471a48) is ＭＳ ゴシック with SHIFTJIS_CHARSET (0x80). */
   static String stringFace(String font) {
      return font != null && font.startsWith("Kanji") ? "MS Gothic" : font;
   }

   /**
    * StringTexture.makeStringTexture (0x00424af0): the text in a 16-bit DIB
    * of exactly its extent and stretched to 128x128 by FUN_004222b0, outside
    * the dictionary (NULL name). Returns the handle.
    *
    * <p>FUN_00424870: with no characters it paints a " " (DAT_00471958);
    * {@code CreateFontA(size, 0, 0, 0, 400, 0, 0, 0, charset, 0, 0, 2
    * (PROOF_QUALITY), 0, face)} only if the face name is at most 32 bytes
    * long (otherwise, the system font and the warning DAT_0047195c);
    * GetTextExtentPoint32W gives the size; {@code SetTextAlign(0)} (top
    * left) and {@code ExtTextOutW(hdc, 0, 0, 0, NULL, ...)} with the default
    * background mode (OPAQUE), which fills the text box with the background
    * colour, and that box is the whole DIB.
    *
    * <p>⚠️ VERIFY (only this): the glyphs are rasterized by GDI and here by
    * Java2D, without antialiasing (PROOF_QUALITY without font smoothing) and
    * with the cell height of CreateFont (positive height = ascent +
    * descent); the face may not exist on this machine (Java substitutes it,
    * as GDI does) and the width of each glyph comes from its own metrics,
    * not from GDI's.
    */
   public static int makeStringTexture(char[] chars, int length, String font, int size, int foreArgb, int backArgb) {
      if (length == 0) {
         chars = new char[]{' '};
         length = 1;
      }
      String text = new String(chars, 0, Math.min(length, chars.length));
      String face = stringFace(font);
      java.awt.Font f = null;
      if (face != null && face.getBytes(java.nio.charset.StandardCharsets.UTF_8).length <= 0x20) {
         f = cellFont(face, size);
      }
      if (f == null) {
         consolePrintln("Warning: font " + font + " is unavailable; using system default");
         f = cellFont(java.awt.Font.DIALOG, 16);
      }
      java.awt.image.BufferedImage probe = new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_RGB);
      java.awt.Graphics2D pg = probe.createGraphics();
      pg.setFont(f);
      java.awt.FontMetrics fm = pg.getFontMetrics();
      int cx = fm.stringWidth(text);
      // positive height in CreateFont = cell height: GetTextExtentPoint32
      // gives tmHeight, which for a scalable font is that height
      int cy = size > 0 ? size : fm.getAscent() + fm.getDescent();
      pg.dispose();
      if (cx * cy > 0xfffff) {
         consolePrintln("Warning: your font size and string are too large; the texture will be truncated");
      }
      int[] ext = stringExtent(cx, cy);
      int[] col = stringColors(colorRef(foreArgb), colorRef(backArgb));
      java.awt.image.BufferedImage img = new java.awt.image.BufferedImage(ext[0], ext[1], java.awt.image.BufferedImage.TYPE_INT_RGB);
      java.awt.Graphics2D g = img.createGraphics();
      g.setRenderingHint(java.awt.RenderingHints.KEY_TEXT_ANTIALIASING, java.awt.RenderingHints.VALUE_TEXT_ANTIALIAS_OFF);
      g.setRenderingHint(java.awt.RenderingHints.KEY_ANTIALIASING, java.awt.RenderingHints.VALUE_ANTIALIAS_OFF);
      g.setColor(new java.awt.Color(rgbOf(col[1])));
      g.fillRect(0, 0, ext[0], ext[1]);
      g.setColor(new java.awt.Color(rgbOf(col[0])));
      // the filled outline without antialiasing: Java2D's drawString on
      // macOS smooths the glyphs even when asked not to
      java.awt.font.FontRenderContext frc = new java.awt.font.FontRenderContext(null, false, false);
      g.fill(f.createGlyphVector(frc, text).getOutline(0.0F, fm.getAscent()));
      g.dispose();
      int[] rgb = img.getRGB(0, 0, ext[0], ext[1], null, 0, ext[0]);
      for (int i = 0; i < rgb.length; i++) {
         rgb[i] &= 0xFFFFFF;
      }
      return userTexture(null, 0, gdiStretchToTexture(rgb, ext[0], ext[1]), ext[0], ext[1]);
   }

   /** COLORREF 0x00BBGGRR -> 0xRRGGBB. */
   private static int rgbOf(int colorRef) {
      return (colorRef & 0xFF) << 16 | colorRef & 0xFF00 | colorRef >> 16 & 0xFF;
   }

   /** Font whose cell (ascent + descent) measures {@code cell} pixels, like CreateFont with a positive height. */
   private static java.awt.Font cellFont(String face, int cell) {
      java.awt.Font base = new java.awt.Font(face, java.awt.Font.PLAIN, 100);
      java.awt.font.FontRenderContext frc = new java.awt.font.FontRenderContext(null, false, false);
      java.awt.font.LineMetrics lm = base.getLineMetrics("Hg", frc);
      float unit = (lm.getAscent() + lm.getDescent()) / 100.0F;
      if (unit <= 0.0F) {
         return null;
      }
      return base.deriveFont(cell / unit);
   }

   /** FUN_0040b740: the client's Console.println. */
   private static void consolePrintln(String s) {
      try {
         NET.worlds.console.Console.println(s);
      } catch (Throwable e) {
         System.err.println(s);
      }
   }

   // ------------------------------------------------------------------
   // RenderWare: RwReadTexture / RwGetNamedTexture / RwReadRaster
   // ------------------------------------------------------------------

   /**
    * Working directory of the process against which the shape path ".;.." is
    * resolved (RwSetShapePath(DAT_0047061c, 1) in FUN_0041a150). null = the
    * process's own (the original ran in the installation directory, like
    * run_gamma.sh). The checks change it.
    */
   static File rwCwd;

   /** RwGetShapePath: the shape path that gamma.dll left. */
   static final String RW_SHAPE_PATH = ".;..";

   /**
    * RwReadTexture (0x100178f0): a texture (data 0, outside the dictionary)
    * with the raster of FUN_10017b60, or null.
    */
   static Texture rwReadTexture(String file) {
      short[] px = rwTextureRaster(file);
      return px == null ? null : newTexture(px);
   }

   /**
    * RwGetNamedTexture (0x10018900): the dictionary's one by base name and,
    * if it is not there, RwReadNamedTexture (0x100185d0): the raster of
    * FUN_10017b60 (which searches the shape path), data 0, into the
    * dictionary under the base name; if that name was already there, the old
    * one is destroyed and the new one takes its place. What the
    * {@code Texture} command of a .rwx uses (0x10014b00): if it returns 0 the
    * command fails and RwReadShape as a whole returns NULL (0x100163e0 breaks
    * the loop on any command that does not return 1).
    */
   public static synchronized int rwGetNamed(String name) {
      if (name == null) {
         return 0;
      }
      Texture t = rwFindNamed(name);
      if (t != null) {
         return t.handle;
      }
      short[] px = rwTextureRaster(name);
      if (px == null) {
         return 0;
      }
      t = newTexture(px);
      String base = rwBaseName(name);
      Texture old = dict.get(rwFold(base));
      if (old != null) {
         old.name = null;
         dict.remove(rwFold(base));
         NativeRw.release(old.handle);
      }
      dict.put(rwFold(base), t);
      t.name = base;
      return t.handle;
   }

   /**
    * What NativeCamera sees when it draws a shape material: the dictionary
    * lookup of RwGetNamedTexture/RwFindNamedTexture, without reading files
    * (reading from the shape path belongs to {@link #rwGetNamed}, when the
    * script is read) and without touching the count.
    */
   public static Texture find(String name) {
      return rwFindNamed(name);
   }

   /**
    * FUN_10017b60: RwReadRaster(name, DAT_1005ac04), and the raster is only
    * valid if its width is the device's texture width (128, height multiple
    * &gt;= 1) or the small one (16); otherwise, errors 0x16/0x17. It returns
    * frame 0 (RW never advances the frame: gamma.dll does not import
    * RwSetTextureFrame or RwTextureNextFrame) as 128x128 5-6-5.
    */
   static short[] rwTextureRaster(String name) {
      RwRaster r = rwReadRaster(name, RW_TEXTURE_READ_FLAGS);
      if (r == null) {
         return null;
      }
      int rep;
      if (r.w == DEV_TEX && r.h / DEV_TEX >= 1) {
         rep = 1;
      } else if (r.w == DEV_TEX_SMALL && r.h / DEV_TEX_SMALL >= 1) {
         rep = SIZE / DEV_TEX_SMALL;
      } else {
         return null;
      }
      short[] out = new short[SIZE * SIZE];
      for (int y = 0; y < SIZE; y++) {
         for (int x = 0; x < SIZE; x++) {
            int sx = x / rep, sy = y / rep;
            out[y * SIZE + x] = (short) (r.pixels[sy * r.stride / 2 + sx]);
         }
      }
      return out;
   }

   /** RW raster (RwRaster): type 1 palettized, 2 masks; the +0x18.. fields of the C struct. */
   static final class RwRaster {
      int type;
      int depth;
      int rMask, gMask, bMask, aMask;
      /** +0x18 / +0x1c / +0x20 / +0x28 */
      byte[] data;
      int w, h, stride;
      /** +0x34: RGB palette, 3 bytes per entry (256). */
      byte[] palette = new byte[0x300];
      /** Only in the device raster: 5-6-5 (stride in bytes). */
      short[] pixels;
   }

   /**
    * RwReadRaster (0x10026c30) -> FUN_10026cc0(name, options, 0): reads the
    * image (FUN_10021350) and the driver converts it to the device's format
    * (device+0x48 = RWDL6D21 0x1000a840 -> FUN_10007a80). With options 0x14
    * there is no mask (bit 8) or mipmaps (0x40); the flag it passes to the
    * driver is 2 (bit 0x10), which is not used at 16 bits.
    */
   static RwRaster rwReadRaster(String name, int flags) {
      if ((flags & 0x20) != 0 && (flags & 8) == 0) {
         flags |= 8;
      }
      if ((flags & 8) != 0 && (flags & 0x17) != 0) {
         return null;
      }
      RwRaster img = rwReadImage(name, flags);
      if (img == null) {
         return null;
      }
      return rwDeviceRaster(img);
   }

   /**
    * FUN_10021350: looks for the file (FUN_10009ae0) as it is and, failing
    * that, with the extensions .ras, .tex, .env, .bmp, .rle in that order
    * (FUN_10043de0 only adds one if the name has no extension after the last
    * '\\'), and decides the format by the signature, not by the extension:
    * "BM" -&gt; BMP (FUN_10021620, options (f&amp;4)&gt;&gt;2 | 2), 59 a6 6a
    * 95 -&gt; Sun raster (FUN_10021da0, (f&amp;4)&gt;&gt;2 | 4). Nothing
    * else.
    */
   static RwRaster rwReadImage(String name, int flags) {
      if (name == null || (flags & 1) != 0 && (flags & 2) != 0 || (flags & 0xffffff80) != 0) {
         return null;
      }
      File f = rwFindFile(name);
      String[] exts = {".ras", ".tex", ".env", ".bmp", ".rle"};
      for (int i = 0; f == null && i < exts.length; i++) {
         String withExt = rwAddExtension(name, exts[i]);
         if (withExt != null) {
            f = rwFindFile(withExt);
         }
      }
      if (f == null) {
         return null;
      }
      byte[] data;
      try {
         data = java.nio.file.Files.readAllBytes(f.toPath());
      } catch (IOException e) {
         return null;
      }
      RwRaster img = new RwRaster();
      boolean ok;
      if (data.length >= 2 && data[0] == 'B' && data[1] == 'M') {
         ok = rwReadBmp(data, img, (flags & 4) >> 2 | 2);
      } else if (data.length >= 4 && (data[0] & 0xFF) == 0x59 && (data[1] & 0xFF) == 0xa6
            && (data[2] & 0xFF) == 0x6a && (data[3] & 0xFF) == 0x95) {
         ok = rwReadRas(data, img, (flags & 4) >> 2 | 4);
      } else {
         ok = false;
      }
      return ok && img.depth != 0 ? img : null;
   }

   /** FUN_10043de0: name + extension, or null if it already has one after the last '\\'. */
   static String rwAddExtension(String name, String ext) {
      int sep = name.lastIndexOf('\\');
      int dot = name.lastIndexOf(ext.charAt(0));
      if (dot >= 0 && (sep < 0 || sep < dot)) {
         return null;
      }
      return name + ext;
   }

   /**
    * FUN_10009ae0: an absolute name (FUN_10043d50: starts with '\\' or is
    * "letter:") is tried as it is; a relative one, in each entry of the shape
    * path separated by ';' (sscanf "%[^;]"), as entry + '\\' + name
    * (FUN_10043db0). The first one that exists and opens is taken
    * (FUN_10043cb0).
    */
   static File rwFindFile(String name) {
      if (name.isEmpty()) {
         return null;
      }
      char c0 = name.charAt(0);
      boolean absolute = c0 == '\\' || (Character.isLetter(c0) && c0 < 0x80 && name.length() > 1 && name.charAt(1) == ':');
      if (absolute) {
         File f = NativeMock.localFile(name);
         return f.isFile() ? f : null;
      }
      for (String entry : RW_SHAPE_PATH.split(";", -1)) {
         if (entry.isEmpty()) {
            return null;
         }
         String p = (entry + "\\" + name).replace('\\', '/');
         File f = rwCwd == null ? NativeMock.resolveCaseInsensitive(p) : resolveUnder(rwCwd, p);
         if (f.isFile()) {
            return f;
         }
      }
      return null;
   }

   private static File resolveUnder(File dir, String rel) {
      File cur = dir;
      for (String part : rel.split("/")) {
         if (part.isEmpty()) {
            continue;
         }
         File c = new File(cur, part);
         if (!c.exists() && cur.listFiles() != null) {
            for (File s : cur.listFiles()) {
               if (s.getName().equalsIgnoreCase(part)) {
                  c = s;
                  break;
               }
            }
         }
         cur = c;
      }
      return cur;
   }

   private static int u16(byte[] d, int o) {
      return (d[o] & 0xFF) | (d[o + 1] & 0xFF) << 8;
   }

   private static int u32(byte[] d, int o) {
      return u16(d, o) | u16(d, o + 2) << 16;
   }

   /**
    * FUN_10021620: BMP. OS/2 (12) or Windows (40; others: error 0x46)
    * header, 1/4/8/24 bits (32 goes through the 24-bit branch of
    * FUN_10042b80, as it is), uncompressed or RLE8 (compression 1; RLE4 is
    * an error). Palette of min(biClrUsed, 2^bits) entries (or 2^bits if 0).
    * An 8-bit image that already measures what a device texture does is not
    * rescaled (option 1 dropped). Rows from bottom to top (option 2) and
    * BGR -&gt; RGB (option 4).
    */
   static boolean rwReadBmp(byte[] d, RwRaster r, int opt) {
      if (d.length < 18) {
         return false;
      }
      int offBits = u32(d, 10);
      int hdr = u32(d, 14);
      if (d.length < 14 + hdr) {
         return false;
      }
      int w, h, bits, comp, colors;
      if (hdr == 12) {
         w = u16(d, 18);
         h = u16(d, 20);
         bits = (short) u16(d, 24);
         comp = 0;
         colors = 0;
      } else {
         if (d.length < 50) {
            return false;
         }
         w = u32(d, 18);
         h = u32(d, 22);
         bits = (short) u16(d, 28);
         comp = u32(d, 30);
         colors = u32(d, 46);
         if (comp == 2) {
            return false;
         }
      }
      int maxColors = 1 << (bits & 0x1f);
      if (colors < 1 || maxColors < colors) {
         colors = maxColors;
      }
      int p = 14 + hdr;
      if (bits != 24) {
         int entry;
         if (hdr == 12) {
            entry = 3;
         } else if (hdr == 40) {
            entry = 4;
         } else {
            return false;
         }
         // local_400 is 1024 bytes: more than 256 entries (16 bits)
         // overflows the stack in the original; here it is rejected
         if (colors * entry > 0x400 || p + colors * entry > d.length) {
            return false;
         }
         for (int i = 0; i < colors; i++) {
            r.palette[i * 3] = d[p + i * entry + 2];
            r.palette[i * 3 + 1] = d[p + i * entry + 1];
            r.palette[i * 3 + 2] = d[p + i * entry];
         }
      }
      if (offBits < 0 || offBits > d.length) {
         return false;
      }
      p = offBits;
      int rowBytes = (w * bits + 7) / 8 + 3 & ~3;
      // the original reserves (w+7 & ~7)*3 bytes; a 32-bit row wider than
      // that overflows its buffer (undefined behaviour)
      byte[] row = new byte[Math.max((w + 7 & ~7) * 3 + 8, rowBytes)];
      if (bits == 8 && rwNativeTextureSize(w, h)) {
         opt &= ~1;
      }
      Resampler rs = new Resampler();
      for (int y = 0; y < h; y++) {
         if (comp == 0 || bits == 24) {
            if (p + rowBytes > d.length) {
               return false;
            }
            System.arraycopy(d, p, row, 0, rowBytes);
            p += rowBytes;
            rwExpandRow(row, w, bits, r, opt | 4);
            if (!rs.row(row, w, h, y, r, opt)) {
               return false;
            }
         } else {
            if (comp != 1) {
               return false;
            }
            int x = 0;
            boolean end = false;
            while (!end) {
               if (p + 2 > d.length) {
                  return false;
               }
               int n = d[p] & 0xFF;
               int v = d[p + 1] & 0xFF;
               p += 2;
               if (n == 0) {
                  if (v == 0) {
                     end = true;
                  } else if (v == 1) {
                     end = true;
                     y = h - 1;
                  } else if (v == 2) {
                     return false;
                  } else {
                     if (p + v > d.length || x + v > row.length) {
                        return false;
                     }
                     System.arraycopy(d, p, row, x, v);
                     x += v;
                     p += v + (v & 1);
                  }
               } else {
                  for (; n > 0 && x < row.length; n--) {
                     row[x++] = (byte) v;
                  }
               }
            }
            rwExpandRow(row, w, bits, r, opt);
            if (!rs.row(row, w, h, y, r, opt)) {
               return false;
            }
         }
      }
      return (w << 16 | h) != 0;
   }

   /** 8-bit image that already measures what a device texture does (0x100217xx / 0x10021fxx). */
   private static boolean rwNativeTextureSize(int w, int h) {
      return w == DEV_TEX && h / DEV_TEX * DEV_TEX - h == 0
         || DEV_TEX_SMALL != 0 && w == DEV_TEX_SMALL && h / DEV_TEX_SMALL * DEV_TEX_SMALL - h == 0;
   }

   /**
    * FUN_10021da0: Sun raster. Header of 7 big-endian integers after the
    * signature (FUN_10020610); colour map 1 (RGB in three planes) or 2 (each
    * byte, grey); without a map, 1 bit = black/white and 8 bits = grey ramp.
    * Rows aligned to 16 bits; type 2 = byte-wise RLE (0x80 n v; 0x80 0 = a
    * single 0x80); type 3 = RGB (no BGR -&gt; RGB swap); 0 and 1 = BGR;
    * other types read nothing (no depth: FUN_10021350 discards it).
    */
   static boolean rwReadRas(byte[] d, RwRaster r, int opt) {
      if (d.length < 32) {
         return false;
      }
      int[] hd = new int[7];
      for (int i = 0; i < 7; i++) {
         int o = 4 + i * 4;
         hd[i] = (d[o] & 0xFF) << 24 | (d[o + 1] & 0xFF) << 16 | (d[o + 2] & 0xFF) << 8 | d[o + 3] & 0xFF;
      }
      int w = hd[0], h = hd[1], bits = hd[2], type = hd[4], mapType = hd[5], mapLen = hd[6];
      int p = 32;
      if (mapType == 1) {
         if (mapLen / 3 * 3 != mapLen) {
            return false;
         }
         int n = mapLen / 3;
         // local_100 is 256 bytes per plane: more overflows in the original
         if (n > 256 || p + mapLen > d.length) {
            return false;
         }
         for (int c = 0; c < 3; c++) {
            for (int i = 0; i < n; i++) {
               r.palette[i * 3 + c] = d[p++];
            }
         }
      } else if (mapType == 2) {
         if (mapLen > 256 || p + mapLen > d.length) {
            return false;
         }
         for (int i = 0; i < mapLen; i++) {
            r.palette[i * 3] = r.palette[i * 3 + 1] = r.palette[i * 3 + 2] = d[p++];
         }
      }
      if (mapLen == 0) {
         if (bits == 1) {
            r.palette[3] = r.palette[4] = r.palette[5] = (byte) 0xff;
         } else if (bits == 8) {
            for (int i = 0; i < 256; i++) {
               r.palette[i * 3] = r.palette[i * 3 + 1] = r.palette[i * 3 + 2] = (byte) i;
            }
         }
      }
      int rowBytes = (w * bits + 7) / 8 + 1 & ~1;
      byte[] row = new byte[Math.max((w + 7 & ~7) << 2, rowBytes)];
      if (bits == 8 && rwNativeTextureSize(w, h)) {
         opt &= ~1;
      }
      Resampler rs = new Resampler();
      if (type == 2) {
         int x = 0;
         int y = 0;
         while (y < h) {
            if (p >= d.length) {
               return false;
            }
            int b = d[p++] & 0xFF;
            int count = 0;
            int v = b;
            if (b == 0x80) {
               if (p >= d.length) {
                  return false;
               }
               count = d[p++] & 0xFF;
               if (count == 0) {
                  v = 0x80;
               } else {
                  if (p >= d.length) {
                     return false;
                  }
                  v = d[p++] & 0xFF;
               }
            }
            // the original keeps emitting even past the last row; here it does not
            for (int k = 0; k <= count && y < h; k++) {
               row[x++] = (byte) v;
               if (x == rowBytes) {
                  rwExpandRow(row, w, bits, r, opt);
                  if (!rs.row(row, w, h, y, r, opt)) {
                     return false;
                  }
                  x = 0;
                  y++;
               }
            }
         }
      } else if (type == 0 || type == 1 || type == 3) {
         if (type == 3) {
            opt &= ~4;
         }
         for (int y = 0; y < h; y++) {
            if (p + rowBytes > d.length) {
               return false;
            }
            System.arraycopy(d, p, row, 0, rowBytes);
            p += rowBytes;
            rwExpandRow(row, w, bits, r, opt);
            if (!rs.row(row, w, h, y, r, opt)) {
               return false;
            }
         }
      }
      return (w << 16 | h) != 0;
   }

   /**
    * FUN_10042b80: the first row fixes the raster type (8-bit palettized if
    * it is not rescaled and the image is 1/4/8-bit; otherwise 24-bit RGB) and
    * each row is expanded in place: to one-byte indices, or to RGB through
    * the palette; 24 bits swaps BGR -&gt; RGB with option 4; 32 bits keeps
    * bytes 1..3 of each pixel (and then the same swap).
    */
   static void rwExpandRow(byte[] b, int w, int bits, RwRaster r, int opt) {
      if (r.depth == 0) {
         if ((opt & 1) == 0 && (bits == 1 || bits == 4 || bits == 8)) {
            r.depth = 8;
            r.type = 1;
         } else {
            r.depth = 0x18;
            r.type = 2;
            r.rMask = 0xff0000;
            r.gMask = 0xff00;
            r.bMask = 0xff;
         }
      }
      byte[] pal = r.palette;
      if (r.depth != 0x18) {
         if (bits == 1) {
            int n = w + 7 & ~7;
            for (int i = n - 1; i >= 0; i--) {
               b[i] = (byte) ((b[i >> 3] & 0xFF) >> (7 - (i & 7)) & 1);
            }
         } else if (bits == 4) {
            int n = w + 3 & ~3;
            for (int i = n - 1; i >= 0; i--) {
               int v = b[i >> 1] & 0xFF;
               b[i] = (byte) ((i & 1) == 0 ? v >> 4 : v & 0xf);
            }
         }
         return;
      }
      switch (bits) {
         case 1: {
            int n = w + 7 & ~7;
            for (int i = n - 1; i >= 0; i--) {
               int ix = (b[i >> 3] & 0xFF) >> (7 - (i & 7)) & 1;
               putPal(b, i, pal, ix);
            }
            break;
         }
         case 4: {
            int n = w + 3 & ~3;
            for (int i = n - 1; i >= 0; i--) {
               int v = b[i >> 1] & 0xFF;
               putPal(b, i, pal, (i & 1) == 0 ? v >> 4 : v & 0xf);
            }
            break;
         }
         case 8:
            for (int i = w - 1; i >= 0; i--) {
               putPal(b, i, pal, b[i] & 0xFF);
            }
            break;
         case 0x20:
            for (int i = 0; i < w; i++) {
               b[i * 3] = b[i * 4 + 1];
               b[i * 3 + 1] = b[i * 4 + 2];
               b[i * 3 + 2] = b[i * 4 + 3];
            }
            swapRb(b, w, opt);
            break;
         case 0x18:
            swapRb(b, w, opt);
            break;
         default:
            break;
      }
   }

   /** Only writes bytes 3i..3i+2, which the backward pass no longer reads. */
   private static void putPal(byte[] b, int i, byte[] pal, int ix) {
      b[i * 3] = pal[ix * 3];
      b[i * 3 + 1] = pal[ix * 3 + 1];
      b[i * 3 + 2] = pal[ix * 3 + 2];
   }

   private static void swapRb(byte[] b, int w, int opt) {
      if ((opt & 4) != 0) {
         for (int i = 0; i < w; i++) {
            byte t = b[i * 3];
            b[i * 3] = b[i * 3 + 2];
            b[i * 3 + 2] = t;
         }
      }
   }

   /**
    * FUN_10042f30 (RWL21; identical copy in RWDL6D21 0x10005f50): receives
    * the rows one at a time and, with option 1, rescales by area average in
    * 16.16 to a width of 128 (or 16 if the image is narrower than 64) and a
    * height of 128 (or 128*k if height = k*width, a strip of frames);
    * without option 1 it copies the row. Option 2: row y is written to
    * h-1-y. The state is that of DAT_1005b8dc.. and DAT_1005e470.. (one per
    * image here).
    */
   static final class Resampler {
      int[] accR, accG, accB, rowR, rowG, rowB;
      int step;     // DAT_1005e480
      int stepY;    // DAT_1005e484
      int invY;     // DAT_1005e47c
      int norm;     // DAT_1005e470
      int outRow;   // DAT_1005e474
      int fracY;    // DAT_1005e478

      boolean row(byte[] src, int srcW, int srcH, int y, RwRaster r, int opt) {
         if (r.data == null && !init(srcW, srcH, r, opt)) {
            return false;
         }
         if ((opt & 1) == 0) {
            int dst = (opt & 2) == 0 ? y : srcH - y - 1;
            int n = r.depth == 0x18 ? srcW * 3 : srcW;
            System.arraycopy(src, 0, r.data, r.stride * dst, n);
            return true;
         }
         for (int x = 0; x < r.w; x++) {
            int u = step * x;
            int u2 = step + u;
            int vr, vg, vb;
            if (((u2 ^ u) & 0xffff0000) == 0) {
               int wgt = (u2 & 0xffff) - (u & 0xffff);
               int o = (u >> 16) * 3;
               vr = (src[o] & 0xFF) * wgt;
               vg = (src[o + 1] & 0xFF) * wgt;
               vb = (src[o + 2] & 0xFF) * wgt;
            } else {
               vr = vg = vb = 0;
               if ((u & 0xffff) != 0) {
                  int wgt = 0x10000 - (u & 0xffff);
                  int o = (u >> 16) * 3;
                  vr += (src[o] & 0xFF) * wgt;
                  vg += (src[o + 1] & 0xFF) * wgt;
                  vb += (src[o + 2] & 0xFF) * wgt;
                  u += wgt;
               }
               for (; (u & 0xffff0000) < (u2 & 0xffff0000); u += 0x10000) {
                  int o = (u >> 16) * 3;
                  vr += (src[o] & 0xFF) * 0x10000;
                  vg += (src[o + 1] & 0xFF) * 0x10000;
                  vb += (src[o + 2] & 0xFF) * 0x10000;
               }
               int rem = u2 & 0xffff;
               if (rem != 0) {
                  int o = (u >> 16) * 3;
                  vr += (src[o] & 0xFF) * rem;
                  vg += (src[o + 1] & 0xFF) * rem;
                  vb += (src[o + 2] & 0xFF) * rem;
               }
            }
            rowR[x] = vr;
            rowG[x] = vg;
            rowB[x] = vb;
         }
         if (fracY + stepY < 0x10000) {
            for (int x = 0; x < r.w; x++) {
               accR[x] += rowR[x];
               accG[x] += rowG[x];
               accB[x] += rowB[x];
            }
            fracY += stepY;
         } else {
            int neg = -fracY;
            int wv = (neg + 0x10080 >> 8) * (invY + 0x80 >> 8);
            if (wv != 0) {
               int k = wv + 0x80 >> 8;
               for (int x = 0; x < r.w; x++) {
                  accR[x] += (rowR[x] + 0x80 >> 8) * k;
                  accG[x] += (rowG[x] + 0x80 >> 8) * k;
                  accB[x] += (rowB[x] + 0x80 >> 8) * k;
               }
            }
            emit(r, opt);
            int left = stepY - (neg + 0x10000);
            if (left > 0xffff) {
               int k = invY + 0x80 >> 8;
               for (int x = 0; x < r.w; x++) {
                  accR[x] = (rowR[x] + 0x80 >> 8) * k;
                  accG[x] = (rowG[x] + 0x80 >> 8) * k;
                  accB[x] = (rowB[x] + 0x80 >> 8) * k;
               }
               int n = left >>> 16;
               left -= n << 16;
               for (; n > 0; n--) {
                  emit(r, opt);
               }
            }
            int wl = (left + 0x80 >> 8) * (invY + 0x80 >> 8);
            fracY = left;
            if (wl == 0) {
               java.util.Arrays.fill(accR, 0, r.w, 0);
               java.util.Arrays.fill(accG, 0, r.w, 0);
               java.util.Arrays.fill(accB, 0, r.w, 0);
            } else {
               int k = wl + 0x80 >> 8;
               for (int x = 0; x < r.w; x++) {
                  accR[x] = (rowR[x] + 0x80 >> 8) * k;
                  accG[x] = (rowG[x] + 0x80 >> 8) * k;
                  accB[x] = (rowB[x] + 0x80 >> 8) * k;
               }
            }
         }
         if (srcH - y == 1 && outRow != r.h) {
            put(r, (opt & 2) != 0 ? r.h - outRow - 1 : outRow);
         }
         return true;
      }

      private void emit(RwRaster r, int opt) {
         put(r, (opt & 2) != 0 ? r.h - outRow - 1 : outRow);
         outRow++;
      }

      /** FUN_10043bf0: one output row, ((acc+0x80)>>8) * ((norm+0x80)>>8) >> 16, capped at 255. */
      private void put(RwRaster r, int row) {
         if (row < 0 || row >= r.h) {
            return;
         }
         int k = norm + 0x80 >> 8;
         int o = r.stride * row;
         for (int x = 0; x < r.w; x++) {
            r.data[o++] = (byte) Math.min((accR[x] + 0x80 >> 8) * k >> 16, 0xff);
            r.data[o++] = (byte) Math.min((accG[x] + 0x80 >> 8) * k >> 16, 0xff);
            r.data[o++] = (byte) Math.min((accB[x] + 0x80 >> 8) * k >> 16, 0xff);
         }
      }

      private boolean init(int srcW, int srcH, RwRaster r, int opt) {
         if (srcW <= 0 || srcH <= 0) {
            return false;
         }
         if ((opt & 1) == 0) {
            r.h = srcH;
            r.w = srcW;
            r.stride = r.depth * srcW / 8 + 3 & ~3;
            r.data = new byte[srcH * r.stride];
            return true;
         }
         int tw, th;
         if (DEV_TEX_SMALL == 0 || DEV_TEX / 2 <= srcW) {
            tw = DEV_TEX;
            th = DEV_TEX;
         } else {
            tw = DEV_TEX_SMALL;
            th = DEV_TEX_SMALL;
         }
         int ratio = (srcH << 16) / srcW;
         int rowsOut;
         int num;
         if ((ratio & 0xffff) == 0 && 0x10000 < ratio) {
            int k = ratio >> 16;
            r.w = tw;
            r.h = tw * k;
            rowsOut = th * k;
            num = th * ratio;
         } else {
            r.w = tw;
            r.h = th;
            rowsOut = th;
            num = th << 16;
         }
         r.stride = tw * 3 + 3 & ~3;
         r.data = new byte[r.h * r.stride];
         step = (srcW << 16) / tw;
         stepY = num / srcH;
         invY = (srcH << 16) / rowsOut;
         norm = ((tw << 16) / srcW + 0x80 >> 8) * (stepY + 0x80 >> 8);
         accR = new int[tw];
         accG = new int[tw];
         accB = new int[tw];
         rowR = new int[tw];
         rowG = new int[tw];
         rowB = new int[tw];
         outRow = 0;
         fracY = 0;
         return true;
      }
   }

   /**
    * The device raster (RWDL6D21 FUN_10009d40: 16 bits, masks
    * f800/07e0/001f, no alpha) and the conversion of FUN_10007a80: each
    * channel aligned by its high bit to the destination mask (the high bits
    * are kept), through the palette if the raster is 8-bit; without an alpha
    * mask and without option 8, a result of 0 becomes 1 (the low bit of
    * blue) so as not to fall on the transparent texel 0.
    */
   static RwRaster rwDeviceRaster(RwRaster img) {
      if (img.data == null) {
         return null;
      }
      RwRaster dev = new RwRaster();
      dev.type = 2;
      dev.depth = 16;
      dev.rMask = 0xf800;
      dev.gMask = 0x7e0;
      dev.bMask = 0x1f;
      dev.w = img.w;
      dev.h = img.h;
      dev.stride = img.w * 16 / 8 + 3 & ~3;
      dev.pixels = new short[img.h * dev.stride / 2];
      for (int y = 0; y < img.h; y++) {
         for (int x = 0; x < img.w; x++) {
            int r, g, b;
            if (img.type == 1) {
               int ix = img.data[y * img.stride + x] & 0xFF;
               r = img.palette[ix * 3] & 0xFF;
               g = img.palette[ix * 3 + 1] & 0xFF;
               b = img.palette[ix * 3 + 2] & 0xFF;
            } else {
               int o = y * img.stride + x * 3;
               r = img.data[o] & 0xFF;
               g = img.data[o + 1] & 0xFF;
               b = img.data[o + 2] & 0xFF;
            }
            dev.pixels[y * dev.stride / 2 + x] = rwTo565(r, g, b);
         }
      }
      return dev;
   }

   /** FUN_10007a80 for 24 bits (or 8 bits through the palette) -> 5-6-5, black -> 0x0001. */
   static short rwTo565(int r, int g, int b) {
      int v = (r << 8 & 0xf800) | (g << 3 & 0x7e0) | (b >> 3 & 0x1f);
      if (v == 0) {
         // ~blueMask + 1 & blueMask: the low bit of blue
         v = 1;
      }
      return (short) v;
   }
}

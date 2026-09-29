package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import net.openworlds.cmp.CmpFrames;

/**
 * Texturas tal como las crean gamma.dll y RenderWare 2.1 con el driver de
 * software de 16 bits (RWDL6D21) en un escritorio de color real.
 *
 * <p>Tres caminos distintos llegan al diccionario de texturas de RW:
 * <ul>
 * <li><b>gamma.dll por GDI</b> ({@code .cmp}/{@code .mov}, texto): la imagen
 * se pinta en un DIB y se estira con {@code StretchBlt} sobre un DIB de
 * 128x128 a 16 bits 5-6-5 ({@link #gdiStretchToTexture}); el buffer pasa a
 * un raster de usuario de RW ({@code FUN_004182d0}).</li>
 * <li><b>RwReadTexture</b> ({@code FileTexture}, {@code .bmp}/{@code .ras}):
 * RWL21 lee el fichero, lo reescala él mismo con un promedio por área y el
 * driver lo convierte a 5-6-5 ({@link #rwReadRaster}).</li>
 * <li><b>RwGetNamedTexture</b> (el mandato {@code Texture} de un
 * {@code .rwx}): busca por nombre base en el diccionario y, si no está, lo
 * lee de la ruta de formas {@code ".;.."} ({@link #rwGetNamed}).</li>
 * </ul>
 *
 * <p>Los handles comparten la tabla de NativeRw. Cada textura guarda el
 * "texture data" de RW ({@code RwSetTextureData}, +0x20), que gamma.dll usa
 * como cuenta de referencias (FUN_004183e0 / FUN_00418430 / FUN_00418370);
 * las que RW lee por su cuenta lo dejan a 0.
 *
 * <p>El rasterizador (NativeCamera) muestrea siempre 128x128; un raster RW
 * de 16x16 (imágenes de menos de 64 de ancho, ver {@link Resampler})
 * se guarda replicado 8x8, que da el mismo texel con muestreo al más
 * cercano: floor(128u)/8 == floor(16u).
 */
public final class NativeTextures {
   private NativeTextures() {
   }

   /** FUN_00417910 devuelve 0x80: el lado de toda textura que crea gamma.dll. */
   public static final int SIZE = 128;

   /**
    * Tamaños de raster de textura del driver (RWDL6D21 0x10001174..0x10001197
    * copia DAT_100790f0 = 0x80 a dispositivo+0x20/+0x24 y DAT_100790f8 = 0x10
    * a dispositivo+0x2bc/+0x2c0).
    */
   static final int DEV_TEX = 0x80;
   static final int DEV_TEX_SMALL = 0x10;

   /**
    * Opciones de RwReadRaster con que lee RW sus texturas (DAT_1005ac04):
    * 0x15 en el .data de RWL21, 0x14 tras el RwSetTextureDithering(2) que
    * gamma.dll hace al arrancar (FUN_0041a150 -> 0x100193f0: {@code &= ~3}).
    */
   static final int RW_TEXTURE_READ_FLAGS = 0x14;

   public static final class Texture {
      /** 5-6-5, de arriba abajo, SIZE * SIZE. */
      public final short[] pixels;
      /** Nombre con que está en el diccionario, o null. */
      String name;
      /** RwGetTextureData (+0x20): la cuenta de referencias de gamma.dll. */
      int data;
      int handle;

      Texture(short[] pixels) {
         this.pixels = pixels;
      }
   }

   // ------------------------------------------------------------------
   // Diccionario de texturas de RW (uno solo: gamma.dll no llama a
   // RwTextureDictBegin/End). Clave: el nombre plegado como lo compara
   // FUN_10043f20 (solo a-z pasan a mayúsculas).
   // ------------------------------------------------------------------

   private static final Map<String, Texture> dict = new HashMap<String, Texture>();

   /** Auditoría (-Dopenworlds.matStats): nombre -> "WxH" de la imagen antes de estirarla. */
   private static final Map<String, String> source = new java.util.LinkedHashMap<String, String>();

   /** Inventario de lo decodificado, para la auditoría de texturas. */
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

   /** FUN_10043f20: igualdad de nombres sin distinguir a-z de A-Z (nada más). */
   static String rwFold(String s) {
      StringBuilder b = new StringBuilder(s.length());
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         b.append(c >= 'a' && c <= 'z' ? (char) (c - 0x20) : c);
      }
      return b.toString();
   }

   /**
    * FUN_10043e80: el nombre con que RW busca una textura. Quita hasta el
    * último '\\' (DAT_1005a078; '/' no cuenta) o, si no hay ninguno, una
    * unidad "X:" delante; y la extensión desde el último '.' posterior a ese
    * punto.
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

   /** RwFindNamedTexture (0x100183c0): por nombre base, sin leer nada. */
   static synchronized Texture rwFindNamed(String name) {
      return name == null ? null : dict.get(rwFold(rwBaseName(name)));
   }

   /**
    * RwAddTextureToDict (0x10016890) para una textura que aún no está en
    * ninguno: si el diccionario ya tiene ese nombre (comparado tal cual, sin
    * nombre base) es el error 0x69 y la textura se queda fuera.
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

   /** RwDestroyTexture (0x10016b00): la saca del diccionario y la libera. */
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
   // gamma.dll: el diccionario con cuenta de referencias
   // ------------------------------------------------------------------

   /**
    * FUN_00421420 / FUN_00421560: todo '\\', ':', '.' y '/' pasa a '|', en
    * minúsculas con la tabla de FUN_00450890 (DAT_00482818: solo A-Z) y,
    * con frame &gt; 0, "|" (DAT_00471308) + el número en decimal. Sin '\\',
    * ':' ni '.', el nombre base de RW (FUN_10043e80) es el nombre entero.
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
    * FUN_004183e0: RwFindNamedTexture y sube la cuenta. Una textura con data
    * 0 es de las que RW leyó por su cuenta: gamma.dll la destruye y
    * devuelve 0, para leer la suya.
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

   /** FUN_004182d0: RwCreateUserRaster(128, 128, 16 bpp) + RwCreateTexture, data 1, al diccionario. */
   static synchronized int create(String key, short[] pixels, int srcW, int srcH) {
      Texture t = newTexture(pixels);
      t.data = 1;
      if (key != null) {
         source.put(key, srcW + "x" + srcH);
         rwAddToDict(key, t);
      }
      return t.handle;
   }

   /** FUN_00418430: RwReadTexture(file), data 1, al diccionario con el nombre de gamma. */
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

   /** FUN_00418370 (Texture.nativeRelease vía FUN_00421690): baja la cuenta y destruye en la última. */
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

   /** FUN_00421420(name, file, frame): búsqueda con nombre y, si falta, RwReadTexture (FileTexture). */
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

   /** FUN_00421560(name, frame, pixels): la del diccionario si ya está (y el buffer se tira), si no una nueva. */
   static int userTexture(String name, int frame, short[] px, int srcW, int srcH) {
      if (name == null) {
         return create(null, px, srcW, srcH);
      }
      String key = dictName(name, frame);
      int h = findNamed(key);
      return h != 0 ? h : create(key, px, srcW, srcH);
   }

   // ------------------------------------------------------------------
   // gamma.dll por GDI: FUN_004222b0
   // ------------------------------------------------------------------

   /**
    * FUN_004222b0 en pantalla de 16 bits (FUN_00417900 == 2): un DIB destino
    * de 128x128 (FUN_00422150: 16 bpp, BI_BITFIELDS f800/07e0/001f, de
    * arriba abajo), {@code SetStretchBltMode(hdc, 3)} y
    * {@code StretchBlt(dst, 0,0,128,128, src, 0,0,w,h, SRCCOPY)} (0x422682 /
    * 0x422710); después se copian los bits tal cual (FUN_0044df50). La máscara
    * de transparencia de 0x4228a8.. solo corre con pantalla de 8 bits.
    *
    * <p>El modo 3 es COLORONCOLOR (STRETCH_DELETESCANS), no HALFTONE (4):
    * cada píxel destino es UN píxel fuente, sin mezclar colores. Qué píxel
    * fuente toca a cada destino (la fase del DDA de GDI) está en gdi32, no
    * en nuestros binarios: ver {@link #gdiSourceIndex}.
    *
    * @param src colores 0xRRGGBB del DIB fuente, w*h, fila a fila de arriba abajo
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
    * Píxel fuente de un píxel destino en COLORONCOLOR: {@code d * s / D}
    * (redondeo hacia abajo, esquina izquierda del píxel destino). ⚠️
    * VERIFICAR: es la fase de la reimplementación de ReactOS; la de gdi32 de
    * Windows no está en gamma.dll ni en RWL21. Otra fase (centro del píxel:
    * {@code (2d+1)s / 2D}) movería como mucho un píxel fuente en las
    * columnas/filas donde difieren; TexStretchCheck lo cuantifica.
    */
   static int gdiSourceIndex(int d, int dstLen, int srcLen) {
      return (int) ((long) d * srcLen / dstLen);
   }

   /**
    * Color 24 bits del DIB fuente a los bitfields 5-6-5 del destino: se
    * quedan los bits altos. ⚠️ VERIFICAR: la traducción de color la hace
    * gdi32 (truncado en ReactOS y Wine; no está en nuestros binarios).
    */
   static short gdiTo565(int c) {
      return (short) ((c >> 16 & 0xFF) >> 3 << 11 | (c >> 8 & 0xFF) >> 2 << 5 | (c & 0xFF) >> 3);
   }

   /**
    * FUN_00422b30 + FUN_004222b0 + FUN_00421560: un ScapePic (.cmp / .mov)
    * en hasta maxFrames texturas. Devuelve {handles[], displayW, displayH} o
    * null si el fichero no se puede leer. Paleta como la monta FUN_00422b30
    * para pantalla de 16 bits: las entradas del fichero y el resto blanco
    * (DAT_004714a8 = ff ff ff); el índice transparente (255 si el bit 2 del
    * modo) pasa a DAT_0049d1e1 (en .bss, nadie lo escribe: negro, el color
    * clave) y toda otra entrada con R &lt; 12, G &lt; 6 y B &lt; 12 pasa a
    * DAT_004714f4 = (8, 8, 8) para no volverse transparente. El DIB fuente
    * es de 8 bits con esa paleta, ancho redondeado a 4 y alto a 2, y el
    * StretchBlt toma solo el rectángulo w x h de la imagen.
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

   /** Tamaño en píxeles del DIB de texto según FUN_00424870 (0x424961..0x4249b5). */
   static int[] stringExtent(int cx, int cy) {
      if (cx * cy > 0xfffff) {
         // 0x424978: cx = cy / 2^20 (division con signo, hacia cero); el aviso
         // DAT_00471994 va a la consola
         cx = (cy + (cy >> 31 & 0xfffff)) >> 20;
      }
      if (cx == 0 || cy == 0) {
         cx = 8;
         cy = 8;
      }
      return new int[]{cx, cy};
   }

   /**
    * Colores de texto y fondo (COLORREF 0x00BBGGRR) tras los ajustes de
    * 16 bits de 0x424a53..0x424a77: texto negro -&gt; 0x080808; fondo
    * 0xfefefe -&gt; 0 (el color clave: fondo transparente); fondo negro -&gt;
    * 0x080808.
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

   /** java.awt.Color.getRGB() (0xAARRGGBB) al COLORREF que arma FUN_00424af0 (0x00BBGGRR). */
   static int colorRef(int argb) {
      return (argb >> 8 & 0xFF) << 8 | argb >> 16 & 0xFF | (argb & 0xFF) << 16;
   }

   /** Cara de la fuente: "Kanji..." (strncmp 5, DAT_00471a48) es ＭＳ ゴシック con SHIFTJIS_CHARSET (0x80). */
   static String stringFace(String font) {
      return font != null && font.startsWith("Kanji") ? "MS Gothic" : font;
   }

   /**
    * StringTexture.makeStringTexture (0x00424af0): el texto en un DIB de
    * 16 bits de exactamente su extensión y estirado a 128x128 por
    * FUN_004222b0, fuera del diccionario (nombre NULL). Devuelve el handle.
    *
    * <p>FUN_00424870: sin caracteres pinta un " " (DAT_00471958);
    * {@code CreateFontA(size, 0, 0, 0, 400, 0, 0, 0, charset, 0, 0, 2
    * (PROOF_QUALITY), 0, cara)} solo si la cara tiene como mucho 32 bytes
    * (si no, la fuente del sistema y el aviso DAT_0047195c);
    * GetTextExtentPoint32W da el tamaño; {@code SetTextAlign(0)} (arriba a
    * la izquierda) y {@code ExtTextOutW(hdc, 0, 0, 0, NULL, ...)} con el
    * modo de fondo por defecto (OPAQUE), que llena de fondo la caja del
    * texto, que es todo el DIB.
    *
    * <p>⚠️ VERIFICAR (solo esto): los glifos los rasteriza GDI y aquí
    * Java2D, sin antialias (PROOF_QUALITY sin suavizado de fuentes) y con la
    * altura de celda del CreateFont (alto positivo = ascendente +
    * descendente); la cara puede no existir en esta máquina (Java la
    * sustituye, como GDI) y el ancho de cada glifo sale de sus métricas, no
    * de las de GDI.
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
      // alto positivo en CreateFont = alto de celda: GetTextExtentPoint32 da
      // tmHeight, que para una fuente escalable es ese alto
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
      // el contorno relleno sin antialias: drawString de Java2D en macOS
      // suaviza los glifos aunque se le pida que no
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

   /** Fuente cuya celda (ascendente + descendente) mide {@code cell} píxeles, como CreateFont con alto positivo. */
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

   /** FUN_0040b740: Console.println del cliente. */
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
    * Directorio de trabajo del proceso contra el que se resuelve la ruta de
    * formas ".;.." (RwSetShapePath(DAT_0047061c, 1) en FUN_0041a150). null =
    * el del proceso (el original corría en el directorio de instalación, como
    * run_gamma.sh). Las comprobaciones lo cambian.
    */
   static File rwCwd;

   /** RwGetShapePath: la ruta de formas que dejó gamma.dll. */
   static final String RW_SHAPE_PATH = ".;..";

   /**
    * RwReadTexture (0x100178f0): una textura (data 0, fuera del diccionario)
    * con el raster de FUN_10017b60, o null.
    */
   static Texture rwReadTexture(String file) {
      short[] px = rwTextureRaster(file);
      return px == null ? null : newTexture(px);
   }

   /**
    * RwGetNamedTexture (0x10018900): la del diccionario por nombre base y, si
    * no está, RwReadNamedTexture (0x100185d0): el raster de FUN_10017b60 (que
    * busca en la ruta de formas), data 0, al diccionario con el nombre base;
    * si ese nombre ya estaba, la vieja se destruye y la nueva ocupa su
    * sitio. Lo que usa el mandato {@code Texture} de un .rwx (0x10014b00):
    * si devuelve 0 el mandato falla y RwReadShape entero devuelve NULL
    * (0x100163e0 corta el bucle con cualquier mandato que no devuelva 1).
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
    * Lo que ve NativeCamera al dibujar un material de forma: la búsqueda del
    * diccionario de RwGetNamedTexture/RwFindNamedTexture, sin leer ficheros
    * (la lectura de la ruta de formas es de {@link #rwGetNamed}, al leer el
    * script) y sin tocar la cuenta.
    */
   public static Texture find(String name) {
      return rwFindNamed(name);
   }

   /**
    * FUN_10017b60: RwReadRaster(nombre, DAT_1005ac04) y el raster solo vale
    * si su ancho es el de textura del dispositivo (128, alto múltiplo &gt;= 1)
    * o el pequeño (16); si no, errores 0x16/0x17. Devuelve el frame 0 (RW
    * nunca avanza de frame: gamma.dll no importa RwSetTextureFrame ni
    * RwTextureNextFrame) como 128x128 5-6-5.
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

   /** Raster de RW (RwRaster): tipo 1 paletizado, 2 máscaras; los campos +0x18.. del C. */
   static final class RwRaster {
      int type;
      int depth;
      int rMask, gMask, bMask, aMask;
      /** +0x18 / +0x1c / +0x20 / +0x28 */
      byte[] data;
      int w, h, stride;
      /** +0x34: paleta RGB, 3 bytes por entrada (256). */
      byte[] palette = new byte[0x300];
      /** Solo en el raster del dispositivo: 5-6-5 (stride en bytes). */
      short[] pixels;
   }

   /**
    * RwReadRaster (0x10026c30) -> FUN_10026cc0(nombre, opciones, 0): lee la
    * imagen (FUN_10021350) y el driver la convierte al formato del
    * dispositivo (dispositivo+0x48 = RWDL6D21 0x1000a840 -> FUN_10007a80).
    * Con las opciones 0x14 no hay máscara (bit 8) ni mipmaps (0x40); el
    * indicador que pasa al driver es 2 (bit 0x10), que en 16 bits no se usa.
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
    * FUN_10021350: busca el fichero (FUN_10009ae0) tal cual y, si no, con
    * las extensiones .ras, .tex, .env, .bmp, .rle en ese orden (FUN_10043de0
    * solo añade si el nombre no tiene ya extensión tras el último '\\'), y
    * decide el formato por la firma, no por la extensión: "BM" -&gt; BMP
    * (FUN_10021620, opciones (f&amp;4)&gt;&gt;2 | 2), 59 a6 6a 95 -&gt; Sun
    * raster (FUN_10021da0, (f&amp;4)&gt;&gt;2 | 4). Nada más.
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

   /** FUN_10043de0: nombre + extensión, o null si ya tiene una tras el último '\\'. */
   static String rwAddExtension(String name, String ext) {
      int sep = name.lastIndexOf('\\');
      int dot = name.lastIndexOf(ext.charAt(0));
      if (dot >= 0 && (sep < 0 || sep < dot)) {
         return null;
      }
      return name + ext;
   }

   /**
    * FUN_10009ae0: un nombre absoluto (FUN_10043d50: empieza por '\\' o es
    * "letra:") se prueba tal cual; uno relativo, en cada entrada de la ruta
    * de formas separada por ';' (sscanf "%[^;]"), como entrada + '\\' +
    * nombre (FUN_10043db0). Vale el primero que exista y abra (FUN_10043cb0).
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
    * FUN_10021620: BMP. Cabecera OS/2 (12) o Windows (40; otras: error
    * 0x46), 1/4/8/24 bits (32 pasa por la rama de 24 de FUN_10042b80, tal
    * cual), sin comprimir o RLE8 (compresión 1; RLE4 es error). Paleta de
    * min(biClrUsed, 2^bits) entradas (o 2^bits si 0). Una imagen de 8 bits
    * que ya mide lo de una textura del dispositivo no se reescala (opción 1
    * fuera). Filas de abajo arriba (opción 2) y BGR -&gt; RGB (opción 4).
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
         // local_400 son 1024 bytes: más de 256 entradas (16 bits) desborda
         // la pila en el original; aquí se rechaza
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
      // el original reserva (w+7 & ~7)*3 bytes; una fila de 32 bits mas ancha
      // que eso desborda su buffer (comportamiento indefinido)
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

   /** Imagen de 8 bits que ya mide lo de una textura del dispositivo (0x100217xx / 0x10021fxx). */
   private static boolean rwNativeTextureSize(int w, int h) {
      return w == DEV_TEX && h / DEV_TEX * DEV_TEX - h == 0
         || DEV_TEX_SMALL != 0 && w == DEV_TEX_SMALL && h / DEV_TEX_SMALL * DEV_TEX_SMALL - h == 0;
   }

   /**
    * FUN_10021da0: Sun raster. Cabecera de 7 enteros big-endian tras la
    * firma (FUN_10020610); mapa de color 1 (RGB en tres planos) o 2 (cada
    * byte, gris); sin mapa, 1 bit = negro/blanco y 8 bits = rampa de grises.
    * Filas alineadas a 16 bits; tipo 2 = RLE por bytes (0x80 n v; 0x80 0 =
    * un 0x80); tipo 3 = RGB (sin cambio BGR -&gt; RGB); 0 y 1 = BGR; otros
    * tipos no leen nada (sin profundidad: FUN_10021350 lo descarta).
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
         // local_100 son 256 bytes por plano: más desborda en el original
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
            // el original sigue emitiendo aunque pase de la ultima fila; aqui no
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
    * FUN_10042b80: la primera fila fija el tipo del raster (8 bits
    * paletizado si no se reescala y la imagen es de 1/4/8 bits; si no, 24
    * bits RGB) y cada fila se expande en su sitio: a índices de un byte, o a
    * RGB por la paleta; 24 bits cambia BGR -&gt; RGB con la opción 4; 32 bits
    * se queda con los bytes 1..3 de cada píxel (y luego el mismo cambio).
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

   /** Solo escribe los bytes 3i..3i+2, que en el recorrido hacia atrás ya no se leen. */
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
    * FUN_10042f30 (RWL21; copia idéntica en RWDL6D21 0x10005f50): recibe las
    * filas de una en una y, con la opción 1, reescala por promedio de área
    * en 16.16 a 128 de ancho (o a 16 si la imagen mide menos de 64) y alto
    * 128 (o 128*k si alto = k*ancho, una tira de frames); sin la opción 1
    * copia la fila. Opción 2: la fila y se escribe en h-1-y. El estado es el
    * de DAT_1005b8dc.. y DAT_1005e470.. (uno por imagen aquí).
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

      /** FUN_10043bf0: una fila de salida, ((acc+0x80)>>8) * ((norm+0x80)>>8) >> 16, tope 255. */
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
    * El raster del dispositivo (RWDL6D21 FUN_10009d40: 16 bits, máscaras
    * f800/07e0/001f, sin alfa) y la conversión de FUN_10007a80: cada canal
    * alineado por su bit alto a la máscara destino (se quedan los bits
    * altos), por la paleta si el raster es de 8 bits; sin máscara de alfa y
    * sin la opción 8, un resultado 0 pasa a 1 (el bit bajo del azul) para no
    * caer en el texel 0 transparente.
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

   /** FUN_10007a80 para 24 bits (u 8 bits por paleta) -> 5-6-5, negro -> 0x0001. */
   static short rwTo565(int r, int g, int b) {
      int v = (r << 8 & 0xf800) | (g << 3 & 0x7e0) | (b >> 3 & 0x1f);
      if (v == 0) {
         // ~mascaraAzul + 1 & mascaraAzul: el bit bajo del azul
         v = 1;
      }
      return (short) v;
   }
}

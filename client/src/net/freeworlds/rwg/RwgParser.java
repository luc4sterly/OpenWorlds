package net.freeworlds.rwg;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * Lector de .rwg traducido de los binarios: la cabecera la lee gamma.dll
 * (ShapeLoader.loadBinaryFile 0x0041e5d0 -&gt; FUN_0041c970, con
 * FUN_00419af0 y FUN_00419a20) y el resto RenderWare 2.1
 * (RwReadStreamChunk de RWL21.DLL, 0x10039e40), sobre un stream de
 * memoria (RwOpenStream(3, 1, {datos, tamaño}), FUN_004181d0).
 *
 * <p>Todo es big-endian (RW invierte cada entero al leerlo). Un chunk es
 * [tag de 4 bytes][longitud de 4 bytes][contenido], y RW no busca los
 * hijos por posición sino con el bucle de búsqueda que repite en cada
 * lector ({@link #find}): lee un tag; si no es el que busca, salta ese
 * chunk (RwSkipStreamChunk 0x10039cd0) y sigue. Nunca salta al final de un
 * chunk: el stream queda donde lo deja lo leído.
 *
 * <p>Errores: donde RW devuelve FALSE, aquí se lanza
 * {@link RwgFormatException} con el código de error de RW cuando lo hay
 * (0x5a = chunk no encontrado, 0x58 = fin del stream). En el cliente
 * original un FALSE en cualquier punto hace que el CLUM entero no se lea
 * y ShapeLoader.finishLoadingBinaryFile devuelva -1.
 */
public final class RwgParser {
   static final int ZZZ = 0x5A5A5A5B; // "ZZZ["
   static final int CLUM = 0x434C554D;
   static final int RALT = 0x52414C54;
   static final int RAST = 0x52415354;
   static final int DATA = 0x44415441;
   static final int TELT = 0x54454C54;
   static final int MALT = 0x4D414C54;
   static final int ATOM = 0x41544F4D;
   static final int MATX = 0x4D415458;
   static final int VLST = 0x564C5354;
   static final int PLST = 0x504C5354;
   static final int STRT = 0x53545254;
   static final int STNG = 0x53544E47;
   /** FUN_00419af0: las dos palabras que siguen a la longitud de la cabecera. */
   static final int HEADER_MAGIC = 0x13765342;
   /** Registros de VLST que son la caja local, no vértices (RwGetClumpNumVertices 0x10003fe0: n - 8). */
   private static final int BBOX_RECORDS = 8;

   /** Un FALSE de RW, con su código de error (FUN_1000cba0) si lo hay. */
   public static final class RwgFormatException extends IllegalArgumentException {
      public final int rwError;

      RwgFormatException(int rwError, String msg) {
         super(msg + (rwError != 0 ? String.format(" (error RW 0x%x)", rwError) : ""));
         this.rwError = rwError;
      }
   }

   private final byte[] data;
   private int pos;

   private RwgParser(byte[] data) {
      this.data = data;
   }

   public static RwgModel parse(byte[] data) {
      return new RwgParser(data).parseFile();
   }

   // ------------------------------------------------------------ stream

   /** RwReadStream (0x10039890) sobre memoria: n == 0 es error 1; si no quedan n bytes, 0x58. */
   private int take(int n, String what) {
      if (n == 0) {
         throw new RwgFormatException(1, what + ": lectura de 0 bytes");
      }
      if (n < 0 || this.data.length - this.pos < n) {
         throw new RwgFormatException(0x58, what + ": faltan bytes (quieren " + (n & 0xFFFFFFFFL) + ")");
      }
      int at = this.pos;
      this.pos += n;
      return at;
   }

   private int readInt(String what) {
      int at = take(4, what);
      return be(at);
   }

   private int be(int at) {
      return ((this.data[at] & 0xFF) << 24) | ((this.data[at + 1] & 0xFF) << 16)
         | ((this.data[at + 2] & 0xFF) << 8) | (this.data[at + 3] & 0xFF);
   }

   private int[] readInts(int count, String what) {
      int at = take(count * 4, what);
      int[] out = new int[count];
      for (int i = 0; i < count; i++) {
         out[i] = be(at + 4 * i);
      }
      return out;
   }

   /** RwSeekStream (0x10039b10) sobre memoria: 0 no hace nada; pasar del final es 0x58. */
   private void seek(int n, String what) {
      if (n == 0) {
         return;
      }
      long to = (this.pos + n) & 0xFFFFFFFFL;
      if (to > this.data.length) {
         this.pos = this.data.length;
         throw new RwgFormatException(0x58, what + ": salto fuera del stream");
      }
      this.pos = (int) to;
   }

   /**
    * El bucle de búsqueda de chunk que RWL21 repite en cada lector (p. ej.
    * 0x1003a205): lee un tag; si no es el buscado, RwSkipStreamChunk lee su
    * longitud y la salta (0 = nada que saltar). Si algo falla, error 0x5a.
    */
   private void find(int tag, String ctx) {
      while (true) {
         if (this.data.length - this.pos < 4) {
            throw new RwgFormatException(0x5a, ctx + ": no hay chunk " + tagName(tag));
         }
         int t = be(this.pos);
         this.pos += 4;
         if (t == tag) {
            return;
         }
         if (this.data.length - this.pos < 4) {
            throw new RwgFormatException(0x5a, ctx + ": no hay chunk " + tagName(tag));
         }
         int len = be(this.pos);
         this.pos += 4;
         long to = (this.pos + len) & 0xFFFFFFFFL;
         if (len != 0 && to > this.data.length) {
            throw new RwgFormatException(0x5a, ctx + ": saltando " + tagName(t) + " sale del stream buscando " + tagName(tag));
         }
         this.pos = (int) to;
      }
   }

   /** Entrada de RwReadStreamChunk (0x10039e64): la longitud del chunk cuyo tag ya se leyó. */
   private int chunkLength(String ctx) {
      return readInt(ctx + ": longitud");
   }

   /**
    * RwReadStreamChunk(STRT, buf, max) (0x1003b17a): lee min(longitud, max)
    * bytes y salta (longitud - max), con signo. Si la longitud es menor que
    * max, el resto del buffer de RW queda sin escribir (aquí, 0).
    */
   private int[] strt(int max, String ctx) {
      find(STRT, ctx);
      int len = chunkLength(ctx + " STRT");
      int n = Integer.compareUnsigned(max, len) < 0 ? max : len;
      int at = take(n, ctx + " STRT");
      int[] out = new int[max / 4];
      for (int i = 0; i + 4 <= n; i += 4) {
         out[i / 4] = be(at + i);
      }
      seek(len - max, ctx + " STRT");
      return out;
   }

   private static String tagName(int t) {
      return new String(new byte[]{(byte) (t >>> 24), (byte) (t >>> 16), (byte) (t >>> 8), (byte) t},
         StandardCharsets.ISO_8859_1);
   }

   // ------------------------------------------------------------ gamma.dll

   private RwgModel parseFile() {
      // FUN_00419af0: tag "ZZZ[", longitud L, y si L - 8 > 0 las palabras
      // 0x13765342 y 1 (RwReadStreamInt de 8 bytes); si no, 0 y la carga falla.
      if (this.data.length < 4 || be(0) != ZZZ) {
         throw new RwgFormatException(0, "no es un .rwg: falta la cabecera ZZZ[ (FUN_00419af0)");
      }
      this.pos = 4;
      int headerLen = chunkLength("cabecera");
      if (headerLen - 8 <= 0) {
         throw new RwgFormatException(0, "cabecera de " + headerLen + " bytes: FUN_00419af0 exige más de 8");
      }
      int[] magic = readInts(2, "cabecera");
      if (magic[0] != HEADER_MAGIC || magic[1] != 1) {
         throw new RwgFormatException(0, String.format("cabecera 0x%08X/0x%08X, FUN_00419af0 exige 0x%08X/1",
            magic[0], magic[1], HEADER_MAGIC));
      }
      // FUN_00419a20 lee los L - 8 bytes; FUN_0041c970 los recorre como
      // cadenas terminadas en NUL hasta una vacía (y solo entonces da la
      // carga por buena, this+0xc = 1).
      int namesAt = take(headerLen - 8, "lista de texturas de la cabecera");
      int end = namesAt + headerLen - 8;
      List<String> names = new ArrayList<>();
      int p = namesAt;
      boolean closed = false;
      while (p < end) {
         int z = p;
         while (z < end && this.data[z] != 0) {
            z++;
         }
         if (z == end) {
            break;
         }
         if (z == p) {
            closed = true;
            break;
         }
         names.add(new String(this.data, p, z - p, StandardCharsets.ISO_8859_1));
         p = z + 1;
      }
      if (!closed) {
         // ⚠️ el original seguiría leyendo más allá de su buffer; no se imita
         throw new RwgFormatException(0, "la lista de texturas de la cabecera no acaba en un nombre vacío");
      }

      // FUN_00419a60: RwReadStreamChunkType y, solo si es CLUM, RwReadStreamChunk(CLUM)
      int type = readInt("tipo de chunk");
      if (type != CLUM) {
         throw new RwgFormatException(0, "tras la cabecera viene " + tagName(type) + ", no CLUM (FUN_00419a60)");
      }
      return clum(names);
   }

   // ------------------------------------------------------------ RWL21

   /** RwReadStreamChunk(CLUM) (0x1003a03d): RALT, TELT y MALT (las tres listas), y el ATOM raíz. */
   private RwgModel clum(List<String> names) {
      chunkLength("CLUM");
      find(RALT, "CLUM");
      List<RwgRaster> rasters = ralt();
      find(TELT, "CLUM");
      List<RwgTexture> textures = telt();
      find(MALT, "CLUM");
      List<RwgMaterial> materials = malt();
      find(ATOM, "CLUM");
      RwgAtom atom = atom();
      return new RwgModel(names, rasters, textures, materials, atom);
   }

   /** RALT (0x1003c4e3): STRT [n, ?, ?] y n chunks RAST. */
   private List<RwgRaster> ralt() {
      chunkLength("RALT");
      int[] h = strt(12, "RALT");
      List<RwgRaster> out = new ArrayList<>();
      for (int i = 0; i < h[0]; i++) { // 0x1003c5b2: comparación con signo
         find(RAST, "RALT");
         out.add(rast());
      }
      return out;
   }

   /** RAST (0x1003c72a): STRT de 10 enteros y un DATA con los píxeles. ⚠️ sin muestra real. */
   private RwgRaster rast() {
      chunkLength("RAST");
      int[] f = strt(0x28, "RAST");
      find(DATA, "RAST");
      int len = chunkLength("DATA");
      int at = take(len, "DATA");
      byte[] px = new byte[len];
      System.arraycopy(this.data, at, px, 0, len);
      return new RwgRaster(f, px);
   }

   /**
    * TELT (0x1003cb3f): STRT [n, tamaño de registro, ?]; por entrada lee
    * SIEMPRE 0x14 bytes y, si el tamaño de registro es menor que 0x14,
    * además salta (0x14 - tamaño) bytes hacia delante (0x1003cc68); después
    * busca el STNG. Con un registro de 16 bytes (cube.rwg) eso se come el
    * tag STNG y su longitud, y la búsqueda del STNG falla: RW no lee ese
    * fichero.
    */
   private List<RwgTexture> telt() {
      chunkLength("TELT");
      int[] h = strt(12, "TELT");
      List<RwgTexture> out = new ArrayList<>();
      for (int i = 0; Integer.compareUnsigned(i, h[0]) < 0; i++) {
         int[] rec = readInts(5, "TELT registro");
         if (Integer.compareUnsigned(h[1], 0x14) < 0) {
            seek(0x14 - h[1], "TELT registro");
         }
         find(STNG, "TELT");
         out.add(new RwgTexture(rec, stng()));
      }
      return out;
   }

   /** STNG (0x1003b111): longitud 0 -&gt; null; si no, la cadena C que contiene. */
   private String stng() {
      int len = chunkLength("STNG");
      if (len == 0) {
         return null;
      }
      int at = take(len, "STNG");
      int z = at;
      while (z < at + len && this.data[z] != 0) {
         z++;
      }
      return new String(this.data, at, z - at, StandardCharsets.ISO_8859_1);
   }

   /** MALT (0x1003bfce): STRT [n, tamaño de registro, ?]; lee 0x28 bytes por material y salta el resto. */
   private List<RwgMaterial> malt() {
      chunkLength("MALT");
      int[] h = strt(12, "MALT");
      List<RwgMaterial> out = new ArrayList<>();
      for (int i = 0; Integer.compareUnsigned(i, h[0]) < 0; i++) {
         int[] rec = readInts(10, "MALT registro");
         if (Integer.compareUnsigned(h[1], 0x28) > 0) {
            seek(h[1] - 0x28, "MALT registro");
         }
         out.add(new RwgMaterial(rec));
      }
      return out;
   }

   /** ATOM (0x1003b569): STRT de 13, dos MATX, VLST, PLST y los ATOM hijos que diga el STRT[11]. */
   private RwgAtom atom() {
      chunkLength("ATOM");
      int[] h = strt(0x34, "ATOM");
      find(MATX, "ATOM");
      float[] m1 = matx();
      find(MATX, "ATOM");
      float[] m2 = matx();
      find(VLST, "ATOM");
      List<RwgVertex> records = vlst();
      find(PLST, "ATOM");
      List<RwgPolygon> polys = plst();
      int nb = Math.min(BBOX_RECORDS, records.size());
      List<RwgVertex> bbox = new ArrayList<>(records.subList(0, nb));
      List<RwgVertex> verts = new ArrayList<>(records.subList(nb, records.size()));
      for (RwgPolygon poly : polys) {
         for (int idx : poly.vertexIndices) {
            if (idx < 0 || idx >= verts.size()) {
               // RW indexaría su tabla de vértices fuera de rango
               throw new RwgFormatException(0, "PLST: índice " + (idx + 1) + " fuera de 1.." + verts.size());
            }
         }
      }
      RwgAtom a = new RwgAtom(h, m1, m2, bbox, verts, polys);
      for (int i = 0; h[11] != 0 && Integer.compareUnsigned(i, h[11]) < 0; i++) {
         find(ATOM, "ATOM hijo");
         a.children.add(atom());
      }
      return a;
   }

   /** MATX (0x1003c3e8): STRT de 16 reales. */
   private float[] matx() {
      chunkLength("MATX");
      int[] v = strt(0x40, "MATX");
      float[] m = new float[16];
      for (int i = 0; i < 16; i++) {
         m[i] = Float.intBitsToFloat(v[i]);
      }
      return m;
   }

   /**
    * VLST (0x1003b1be): STRT [n, tamaño, banderas]; el registro base es
    * 12 + 12 (bandera 1) + 8 (bandera 2) + 12 (bandera 4) y, si el tamaño
    * declarado es mayor, se salta la diferencia tras cada registro.
    */
   private List<RwgVertex> vlst() {
      chunkLength("VLST");
      int[] h = strt(12, "VLST");
      int f = h[2];
      int base = 12 + ((f & 1) != 0 ? 12 : 0) + ((f & 2) != 0 ? 8 : 0) + ((f & 4) != 0 ? 12 : 0);
      int extra = base < h[1] ? h[1] - base : 0;
      List<RwgVertex> out = new ArrayList<>();
      for (int i = 0; Integer.compareUnsigned(i, h[0]) < 0; i++) {
         int[] xyz = readInts(3, "VLST posición");
         float[] n = new float[3];
         float[] uv = new float[2];
         float[] e = new float[3];
         if ((f & 1) != 0) {
            n = floats(readInts(3, "VLST normal"));
         }
         if ((f & 2) != 0) {
            uv = floats(readInts(2, "VLST uv"));
         }
         if ((f & 4) != 0) {
            e = floats(readInts(3, "VLST bandera 4"));
         }
         out.add(new RwgVertex(Float.intBitsToFloat(xyz[0]), Float.intBitsToFloat(xyz[1]), Float.intBitsToFloat(xyz[2]),
            (f & 1) != 0, n[0], n[1], n[2], (f & 2) != 0, uv[0], uv[1], (f & 4) != 0, e[0], e[1], e[2]));
         seek(extra, "VLST registro");
      }
      return out;
   }

   /**
    * PLST (0x1003a583): STRT [n, tamaño, banderas]; el registro base (sin
    * los índices) es 8 + 12 (bandera 1) + 12 (bandera 4) + 4 (bandera
    * 0x10). Cada polígono pasa por FUN_10001220, que quita los índices
    * repetidos seguidos (y el último si repite el primero) y falla si
    * quedan menos de 3: entonces falla el PLST entero (0x1003a7a0).
    */
   private List<RwgPolygon> plst() {
      chunkLength("PLST");
      int[] h = strt(12, "PLST");
      int f = h[2];
      int base = ((f & 0x10) >>> 2) + ((f & 4) != 0 ? 12 : 0) + 8 + ((f & 1) != 0 ? 12 : 0);
      int extra = base < h[1] ? h[1] - base : 0;
      List<RwgPolygon> out = new ArrayList<>();
      for (int i = 0; Integer.compareUnsigned(i, h[0]) < 0; i++) {
         int[] mn = readInts(2, "PLST registro");
         int[] idx = readInts(mn[1] & 0x3FFFFFFF, "PLST índices");
         int[] kept = compactIndices(idx);
         if (kept.length < 3) {
            throw new RwgFormatException(0, "PLST: polígono " + (i + 1) + " con menos de 3 vértices distintos (FUN_10001220)");
         }
         for (int k = 0; k < kept.length; k++) {
            kept[k] -= 1;
         }
         float[] normal = null;
         float[] ext = null;
         short tag = 0;
         if ((f & 1) != 0) {
            normal = floats(readInts(3, "PLST normal"));
         }
         if ((f & 4) != 0) {
            ext = floats(readInts(3, "PLST bandera 4"));
         }
         if ((f & 0x10) != 0) {
            tag = (short) readInt("PLST tag");
         }
         out.add(new RwgPolygon(mn[0], kept, normal, ext, tag));
         seek(extra, "PLST registro");
      }
      return out;
   }

   /**
    * FUN_10001220 (RWL21): deja un solo índice de cada tirada de índices
    * iguales consecutivos y quita el último si es igual al primero.
    */
   static int[] compactIndices(int[] in) {
      int[] a = in.clone();
      int n = a.length;
      int i = 1;
      int prev = 0;
      while (i < n) {
         int j = i;
         while (j < n && a[j] == a[prev]) {
            j++;
         }
         if (j - i != 0) {
            System.arraycopy(a, j, a, i, n - j);
            n -= j - i;
         }
         prev = i;
         i++;
      }
      if (n > 0 && a[n - 1] == a[0]) {
         n--;
      }
      int[] out = new int[n];
      System.arraycopy(a, 0, out, 0, n);
      return out;
   }

   private static float[] floats(int[] v) {
      float[] out = new float[v.length];
      for (int i = 0; i < v.length; i++) {
         out[i] = Float.intBitsToFloat(v[i]);
      }
      return out;
   }
}

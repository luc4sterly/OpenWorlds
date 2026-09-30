package net.openworlds.rwg;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * .rwg reader translated from the binaries: the header is read by gamma.dll
 * (ShapeLoader.loadBinaryFile 0x0041e5d0 -&gt; FUN_0041c970, with
 * FUN_00419af0 and FUN_00419a20) and the rest by RenderWare 2.1
 * (RwReadStreamChunk of RWL21.DLL, 0x10039e40), over a memory
 * stream (RwOpenStream(3, 1, {data, size}), FUN_004181d0).
 *
 * <p>Everything is big-endian (RW reverses every integer as it reads it). A
 * chunk is [4-byte tag][4-byte length][content], and RW does not look up
 * the children by position but with the search loop that it repeats in each
 * reader ({@link #find}): it reads a tag; if it is not the one being sought,
 * it skips that chunk (RwSkipStreamChunk 0x10039cd0) and goes on. It never
 * skips to the end of a chunk: the stream is left wherever what was read
 * leaves it.
 *
 * <p>Errors: where RW returns FALSE, {@link RwgFormatException} is thrown
 * here with RW's error code when there is one
 * (0x5a = chunk not found, 0x58 = end of stream). In the original
 * client a FALSE at any point makes the whole CLUM unreadable
 * and ShapeLoader.finishLoadingBinaryFile return -1.
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
   /** FUN_00419af0: the two words that follow the header length. */
   static final int HEADER_MAGIC = 0x13765342;
   /** VLST records that are the local box, not vertices (RwGetClumpNumVertices 0x10003fe0: n - 8). */
   private static final int BBOX_RECORDS = 8;

   /** An RW FALSE, with its error code (FUN_1000cba0) if there is one. */
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

   /** RwReadStream (0x10039890) over memory: n == 0 is error 1; if n bytes do not remain, 0x58. */
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

   /** RwSeekStream (0x10039b10) over memory: 0 does nothing; going past the end is 0x58. */
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
    * The chunk search loop that RWL21 repeats in each reader (e.g.
    * 0x1003a205): reads a tag; if it is not the one sought, RwSkipStreamChunk
    * reads its length and skips it (0 = nothing to skip). If anything fails,
    * error 0x5a.
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

   /** Entry of RwReadStreamChunk (0x10039e64): the length of the chunk whose tag was already read. */
   private int chunkLength(String ctx) {
      return readInt(ctx + ": longitud");
   }

   /**
    * RwReadStreamChunk(STRT, buf, max) (0x1003b17a): reads min(length, max)
    * bytes and skips (length - max), signed. If the length is less than
    * max, the rest of RW's buffer is left unwritten (here, 0).
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

   /** What gamma.dll extracts from the header before RW reads anything (FUN_0041c970). */
   public static final class Header {
      /** Texture names in the order in which gamma requests them from Java. */
      public final List<String> names;
      /** The list ended in the empty name: gamma marks the load as good (this+0xc = 1). */
      public final boolean complete;

      Header(List<String> names, boolean complete) {
         this.names = names;
         this.complete = complete;
      }

      /** Each name with ".cmp" (DAT_00470a7c) if it has no '.'. */
      public List<String> textureRequests() {
         List<String> out = new ArrayList<>();
         for (String n : this.names) {
            out.add(n.indexOf('.') < 0 ? n + ".cmp" : n);
         }
         return out;
      }
   }

   /**
    * The header as gamma.dll reads it: FUN_00419af0 (tag "ZZZ[",
    * length L &gt; 8, words 0x13765342 and 1) and FUN_00419a20 + the loop
    * of FUN_0041c970 over the L - 8 bytes. Returns null where gamma never gets
    * to request anything (FUN_00419af0 gives 0 or the read fails).
    */
   public static Header header(byte[] data) {
      RwgParser p = new RwgParser(data);
      try {
         return p.readHeader();
      } catch (RwgFormatException e) {
         return null;
      }
   }

   private Header readHeader() {
      // FUN_00419af0: tag "ZZZ[", length L, and if L - 8 > 0 the words
      // 0x13765342 and 1 (8-byte RwReadStreamInt); otherwise, 0 and the load fails.
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
      // FUN_00419a20 reads the L - 8 bytes; FUN_0041c970 walks them as
      // NUL-terminated strings up to an empty one (and only then considers
      // the load good, this+0xc = 1).
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
      return new Header(names, closed);
   }

   private RwgModel parseFile() {
      Header hd = readHeader();
      if (!hd.complete) {
         // ⚠️ the original would keep reading past its buffer; that is not imitated
         throw new RwgFormatException(0, "la lista de texturas de la cabecera no acaba en un nombre vacío");
      }
      List<String> names = hd.names;

      // FUN_00419a60: RwReadStreamChunkType and, only if it is CLUM, RwReadStreamChunk(CLUM)
      int type = readInt("tipo de chunk");
      if (type != CLUM) {
         throw new RwgFormatException(0, "tras la cabecera viene " + tagName(type) + ", no CLUM (FUN_00419a60)");
      }
      return clum(names);
   }

   // ------------------------------------------------------------ RWL21

   /** RwReadStreamChunk(CLUM) (0x1003a03d): RALT, TELT and MALT (the three lists), and the root ATOM. */
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

   /** RALT (0x1003c4e3): STRT [n, ?, ?] and n RAST chunks. */
   private List<RwgRaster> ralt() {
      chunkLength("RALT");
      int[] h = strt(12, "RALT");
      List<RwgRaster> out = new ArrayList<>();
      for (int i = 0; i < h[0]; i++) { // 0x1003c5b2: signed comparison
         find(RAST, "RALT");
         out.add(rast());
      }
      return out;
   }

   /** RAST (0x1003c72a): STRT of 10 integers and a DATA with the pixels. ⚠️ no real sample. */
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
    * TELT (0x1003cb3f): STRT [n, record size, ?]; for each entry it ALWAYS
    * reads 0x14 bytes and, if the record size is less than 0x14,
    * also skips (0x14 - size) bytes forward (0x1003cc68); then
    * it looks for the STNG. With a 16-byte record (cube.rwg) that eats the
    * STNG tag and its length, and the search for the STNG fails: RW does not
    * read that file.
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

   /** STNG (0x1003b111): length 0 -&gt; null; otherwise, the C string it contains. */
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

   /** MALT (0x1003bfce): STRT [n, record size, ?]; reads 0x28 bytes per material and skips the rest. */
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

   /** ATOM (0x1003b569): STRT of 13, two MATX, VLST, PLST and the child ATOMs that STRT[11] says. */
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
               // RW would index its vertex table out of range
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

   /** MATX (0x1003c3e8): STRT of 16 reals. */
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
    * VLST (0x1003b1be): STRT [n, size, flags]; the base record is
    * 12 + 12 (flag 1) + 8 (flag 2) + 12 (flag 4) and, if the declared
    * size is larger, the difference is skipped after each record.
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
    * PLST (0x1003a583): STRT [n, size, flags]; the base record (without
    * the indices) is 8 + 12 (flag 1) + 12 (flag 4) + 4 (flag
    * 0x10). Each polygon goes through FUN_10001220, which removes
    * consecutive repeated indices (and the last one if it repeats the first)
    * and fails if fewer than 3 remain: then the whole PLST fails (0x1003a7a0).
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
    * FUN_10001220 (RWL21): leaves a single index from each run of
    * consecutive equal indices and removes the last one if it equals the first.
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

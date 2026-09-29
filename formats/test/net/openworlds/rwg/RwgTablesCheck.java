package net.openworlds.rwg;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.nio.file.Files;
import java.util.Arrays;

/**
 * RwgParser contra RWL21 (RwReadStreamChunk 0x10039e40) y gamma.dll
 * (cabecera, FUN_00419af0/FUN_0041c970): tablas TELT/MALT sintéticas con
 * los valores calculados a mano, los casos límite que dicta el binario
 * (TELT de 16 bytes, MALT con registro largo, PLST con índices repetidos)
 * y lo que sale de los .rwg reales del corpus. Sale con 1 si algo falla.
 * Se ejecuta desde la raíz del repo (tools/run-checks.sh).
 */
public final class RwgTablesCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      synthetic();
      teltSixteen();
      maltLongRecord();
      plstCompaction();
      realFiles();
      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("RwgTablesCheck OK");
   }

   // --------------------------------------------------------- sintético

   /**
    * Cabecera con "tex1"; TELT de una entrada [0,0,1,0,1] + STNG "tex1";
    * MALT de un material [1, 0x14, 0x81, 0.5, 0.25, 1.0, 0.75, 0.75, 0, 0];
    * un ATOM con 3 vértices (bbox + 3) y un triángulo con banderas 0x11
    * (normal y tag).
    */
   private static void synthetic() {
      byte[] f = file(new String[]{"tex1"}, 20, 40, new int[][]{{0, 0, 1, 0, 1}}, new String[]{"tex1"},
         new int[][]{mat(1, 0x14, 0x81, 0.5F, 0.25F, 1.0F, 0.75F, 0.75F, 0F, 0F)}, 0x11);
      RwgModel m = RwgParser.parse(f);
      eq("cabecera", m.headerTextures.toString(), "[tex1]");
      eq("pide tex1.cmp (sin '.', FUN_0041c970 + DAT_00470a7c)", m.textureRequests().toString(), "[tex1.cmp]");
      eq("TELT: 1 entrada", m.textures.size(), 1);
      eq("TELT raster 0 = por nombre", m.textures.get(0).rasterIndex, 0);
      eq("TELT nombre", m.textures.get(0).name, "tex1");
      eq("MALT: 1 material", m.materials.size(), 1);
      RwgMaterial mt = m.materials.get(0);
      eq("MALT textura 1", mt.textureIndex, 1);
      // 0x14: no < 4, no < 8, no < 0xc -> 4 (sólido); bit 0 = 0 -> faceta
      eq("MALT geometría (0x14 -> 4)", mt.geometrySampling(), 4);
      eq("MALT luz (bit 0 = 0 -> 1)", mt.lightSampling(), 1);
      // 0x81: & 0x1f = 1 (lit), & 0xc0 = 0x80 (doble cara)
      eq("MALT modos de textura", mt.textureModes(), 1);
      eq("MALT modos de material", mt.materialModes(), 0x80);
      eqf("MALT r", mt.r, 0.5F);
      eqf("MALT g", mt.g, 0.25F);
      eqf("MALT b", mt.b, 1.0F);
      eqf("MALT opacidad", mt.opacity, 0.75F);
      eqf("MALT ambiente", mt.ambient, 0.75F);
      RwgPolygon p = m.atom.polygons.get(0);
      eq("PLST material", p.materialIndex, 1);
      check("materialOf", m.materialOf(p) == mt);
      eq("PLST tag (bandera 0x10)", p.tag, 7);
      eqf("PLST normal z (bandera 1)", p.normal()[2], 1.0F);
      check("PLST sin bandera 4", p.extra == null);
      eq("PLST índices 0-based", Arrays.toString(p.vertexIndices), "[0, 1, 2]");
      eq("VLST: 3 vértices tras la caja", m.atom.vertices.size(), 3);
      check("VLST banderas 7: normal y uv", m.atom.vertices.get(0).hasNormal && m.atom.vertices.get(0).hasUv);
      eqf("VLST u del vértice 2", m.atom.vertices.get(1).u, 1.0F);
      // material 0 y fuera de rango -> ninguno
      check("materialOf(0) = null", m.materialOf(new RwgPolygon(0, new int[3], null, null, (short) 0)) == null);
      check("materialOf(2) = null", m.materialOf(new RwgPolygon(2, new int[3], null, null, (short) 0)) == null);
   }

   /**
    * 0x1003cc68: con registro de TELT de 16 bytes RW lee 0x14 igualmente y
    * salta 0x14 - 16 = 4 más: se come "STNG" y su longitud y la búsqueda
    * del STNG falla (0x5a). Con 20 bytes la misma entrada se lee bien.
    */
   private static void teltSixteen() {
      byte[] bad = file(new String[]{"tex1"}, 16, 40, new int[][]{{0, 1, 0, 1}}, new String[]{"tex1"},
         new int[][]{mat(1, 0x14, 1, 1F, 1F, 1F, 1F, 0.5F, 0.5F, 0F)}, 0x11);
      int err = -1;
      try {
         RwgParser.parse(bad);
      } catch (RwgParser.RwgFormatException e) {
         err = e.rwError;
      }
      eq("TELT de 16 bytes: RW no lo lee (0x5a)", err, 0x5a);
   }

   /** 0x1003c0c0: con tamaño de registro 44 se leen 40 y se saltan 4. */
   private static void maltLongRecord() {
      int[] a = mat(0, 0xc, 0, 0.1F, 0.2F, 0.3F, 1F, 0F, 1F, 0F);
      int[] b = mat(0, 0x1, 4, 0.9F, 0.8F, 0.7F, 0.5F, 0.2F, 0.3F, 0.4F);
      byte[] f = file(new String[0], 20, 44, new int[0][], new String[0], new int[][]{a, b}, 0x11);
      RwgModel m = RwgParser.parse(f);
      eq("MALT largo: 2 materiales", m.materials.size(), 2);
      eqf("MALT largo: r del segundo", m.materials.get(1).r, 0.9F);
      eqf("MALT largo: especular del segundo", m.materials.get(1).specular, 0.4F);
      // 0xc -> no < 0xc -> 4; 0x1 -> < 4 -> 1 (nube de puntos), bit 0 -> luz 2
      eq("MALT 0xc -> geometría 4", m.materials.get(0).geometrySampling(), 4);
      eq("MALT 0x1 -> geometría 1", m.materials.get(1).geometrySampling(), 1);
      eq("MALT 0x1 -> luz 2", m.materials.get(1).lightSampling(), 2);
      eq("MALT modos 4 = filter", m.materials.get(1).textureModes(), 4);
   }

   /** FUN_10001220: tiradas repetidas fuera, el último fuera si repite el primero; &lt; 3 falla. */
   private static void plstCompaction() {
      eq("[1,1,2,3,1] -> [1,2,3]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 1, 2, 3, 1})), "[1, 2, 3]");
      eq("[1,2,2,2,3,4] -> [1,2,3,4]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 2, 2, 3, 4})), "[1, 2, 3, 4]");
      eq("[1,2,1,2] se queda", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 1, 2})), "[1, 2, 1, 2]");
      eq("[1,2,2] -> [1,2]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 2})), "[1, 2]");
   }

   // --------------------------------------------------------- corpus

   private static void realFiles() throws Exception {
      RwgModel idle = RwgParser.parse(read("assets/FIRST/IDLE.RWG"));
      eq("IDLE cabecera", idle.headerTextures.toString(), "[idle]");
      eq("IDLE pide idle.cmp", idle.textureRequests().toString(), "[idle.cmp]");
      eq("IDLE TELT", idle.textures.size() + " " + idle.textures.get(0).rasterIndex + " " + idle.textures.get(0).name, "1 0 idle");
      RwgMaterial im = idle.materials.get(0);
      // bytes: 00000001 00000014 00000002 3f780000 3f7c0000 3f780000 3f800000 3f400000 0 0
      eq("IDLE MALT textura", im.textureIndex, 1);
      eq("IDLE MALT palabra 0x14", im.samplingWord, 0x14);
      eq("IDLE MALT modos 2 (foreshorten, sin lit)", im.textureModes(), 2);
      eqf("IDLE MALT r = 0x3f780000", im.r, 0.96875F);
      eqf("IDLE MALT g = 0x3f7c0000", im.g, 0.984375F);
      eqf("IDLE MALT b", im.b, 0.96875F);
      eqf("IDLE MALT opacidad", im.opacity, 1.0F);
      eqf("IDLE MALT ambiente = 0x3f400000", im.ambient, 0.75F);
      eqf("IDLE MALT difusa", im.diffuse, 0.0F);
      eq("IDLE polígono con material 1", idle.atom.polygons.get(0).materialIndex, 1);
      eq("IDLE estado ON", idle.atom.state(), 2);

      RwgModel e3 = RwgParser.parse(read("assets/gammatutorial-samples/e3.rwg"));
      RwgMaterial em = e3.materials.get(0);
      eq("e3 TELT earthkin", e3.textures.get(0).name, "earthkin");
      eq("e3 MALT palabra 0x15 -> luz por vértice", em.lightSampling(), 2);
      eqf("e3 MALT ambiente = 0x3dcccccd", em.ambient, Float.intBitsToFloat(0x3dcccccd));
      eqf("e3 MALT especular = 0x3f666666", em.specular, Float.intBitsToFloat(0x3f666666));
      eq("e3 tag del ATOM", e3.atom.tag(), 1);

      RwgModel ball = RwgParser.parse(read("assets/gammatutorial-samples/ball.rwg"));
      eq("ball: 512 materiales", ball.materials.size(), 512);
      eq("ball: 512 polígonos", ball.atom.polygons.size(), 512);
      boolean seq = true;
      for (int i = 0; i < 512; i++) {
         seq &= ball.atom.polygons.get(i).materialIndex == i + 1;
      }
      check("ball: el campo que contaba 1..512 es el material", seq);
      eq("ball MALT sin textura", ball.materials.get(0).textureIndex, 0);
      eq("ball MALT lit (modos 1)", ball.materials.get(0).textureModes(), 1);

      RwgModel table = RwgParser.parse(read("assets/gammatutorial-samples/table.rwg"));
      eq("table: 546 polígonos", table.atom.polygons.size(), 546);
      eqf("table MALT g", table.materials.get(0).g, 0.5F);

      RwgModel avatar = RwgParser.parse(read("assets/FIRST/AVATAR.RWG"));
      eq("AVATAR: cabecera vacía", avatar.headerTextures.size(), 0);
      eq("AVATAR: 0 vértices", avatar.atom.vertices.size(), 0);
      eq("AVATAR: 0 polígonos", avatar.atom.polygons.size(), 0);
      eq("AVATAR: estado ON", avatar.atom.state(), 2);

      int err = -1;
      try {
         RwgParser.parse(read("assets/gammatutorial-samples/cube.rwg"));
      } catch (RwgParser.RwgFormatException e) {
         err = e.rwError;
      }
      eq("cube.rwg (TELT de 16 bytes): RW no lo lee", err, 0x5a);
   }

   // --------------------------------------------------------- constructor

   static int[] mat(int tex, int word, int modes, float r, float g, float b, float op, float am, float di, float sp) {
      return new int[]{tex, word, modes, fb(r), fb(g), fb(b), fb(op), fb(am), fb(di), fb(sp)};
   }

   private static int fb(float f) {
      return Float.floatToIntBits(f);
   }

   /** Un .rwg mínimo: 3 vértices (más la caja) y un triángulo con material 1, tag 7 y normal (0,0,1). */
   static byte[] file(String[] names, int teltRec, int maltRec, int[][] telt, String[] tnames, int[][] malt,
                      int plstFlags) {
      Out o = new Out();
      Out h = new Out();
      h.i(0x13765342).i(1);
      for (String n : names) {
         h.s(n).b(0);
      }
      h.b(0);
      while (h.size() % 4 != 0) {
         h.b(0);
      }
      o.tag("ZZZ[").i(h.size()).raw(h);
      Out clum = new Out();
      clum.chunk("RALT", new Out().chunk("STRT", new Out().i(0).i(0).i(0x17)));
      Out t = new Out().chunk("STRT", new Out().i(telt.length).i(teltRec).i(0x17));
      for (int k = 0; k < telt.length; k++) {
         for (int v : telt[k]) {
            t.i(v);
         }
         Out s = new Out().s(tnames[k]).b(0);
         while (s.size() % 4 != 0) {
            s.b(0);
         }
         t.chunk("STNG", s);
      }
      clum.chunk("TELT", t);
      Out m = new Out().chunk("STRT", new Out().i(malt.length).i(maltRec).i(0x17));
      for (int[] rec : malt) {
         for (int v : rec) {
            m.i(v);
         }
         for (int k = 40; k < maltRec; k += 4) {
            m.i(0x7777);
         }
      }
      clum.chunk("MALT", m);
      Out a = new Out().chunk("STRT", new Out().i(1).i(4).i(0).i(0).i(0).i(0).i(0).i(0).i(2).i(1).i(2).i(0).i(fb(1F)));
      float[] id = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
      for (int k = 0; k < 2; k++) {
         Out mx = new Out();
         for (float v : id) {
            mx.i(fb(v));
         }
         a.chunk("MATX", new Out().chunk("STRT", mx));
      }
      Out vl = new Out().chunk("STRT", new Out().i(11).i(44).i(0x17));
      float[][] pts = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}};
      for (int k = 0; k < 8; k++) {
         vl.i(fb((k & 1) != 0 ? 1F : 0F)).i(fb((k & 2) != 0 ? 1F : 0F)).i(0);
         for (int z = 0; z < 8; z++) {
            vl.i(0);
         }
      }
      for (float[] pt : pts) {
         vl.i(fb(pt[0])).i(fb(pt[1])).i(fb(pt[2])).i(0).i(0).i(fb(1F)).i(fb(pt[0])).i(fb(pt[1])).i(0).i(0).i(0);
      }
      a.chunk("VLST", vl);
      int base = 8 + ((plstFlags & 1) != 0 ? 12 : 0) + ((plstFlags & 4) != 0 ? 12 : 0) + ((plstFlags & 0x10) != 0 ? 4 : 0);
      Out pl = new Out().chunk("STRT", new Out().i(1).i(base).i(plstFlags));
      pl.i(1).i(3).i(1).i(2).i(3);
      if ((plstFlags & 1) != 0) {
         pl.i(0).i(0).i(fb(1F));
      }
      if ((plstFlags & 4) != 0) {
         pl.i(0).i(0).i(0);
      }
      if ((plstFlags & 0x10) != 0) {
         pl.i(7);
      }
      a.chunk("PLST", pl);
      clum.chunk("ATOM", a);
      o.chunk("CLUM", clum);
      return o.toByteArray();
   }

   static final class Out extends ByteArrayOutputStream {
      Out i(int v) {
         write(v >>> 24);
         write(v >>> 16);
         write(v >>> 8);
         write(v);
         return this;
      }

      Out b(int v) {
         write(v);
         return this;
      }

      Out s(String t) {
         byte[] x = t.getBytes(java.nio.charset.StandardCharsets.ISO_8859_1);
         write(x, 0, x.length);
         return this;
      }

      Out tag(String t) {
         return s(t);
      }

      Out raw(Out o) {
         byte[] x = o.toByteArray();
         write(x, 0, x.length);
         return this;
      }

      Out chunk(String t, Out body) {
         return tag(t).i(body.size()).raw(body);
      }
   }

   private static byte[] read(String path) throws Exception {
      return Files.readAllBytes(new File(path).toPath());
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, Object got, Object want) {
      if (got == null ? want != null : !got.equals(want)) {
         failures++;
         System.out.println("FALLA " + what + ": " + got + " != " + want);
      }
   }

   private static void eq(String what, int got, int want) {
      eq(what, Integer.valueOf(got), Integer.valueOf(want));
   }

   private static void eqf(String what, float got, float want) {
      if (Float.floatToIntBits(got) != Float.floatToIntBits(want)) {
         failures++;
         System.out.println("FALLA " + what + ": " + got + " != " + want);
      }
   }
}

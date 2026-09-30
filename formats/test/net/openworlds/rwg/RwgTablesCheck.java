package net.openworlds.rwg;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.nio.file.Files;
import java.util.Arrays;

/**
 * RwgParser against RWL21 (RwReadStreamChunk 0x10039e40) and gamma.dll
 * (header, FUN_00419af0/FUN_0041c970): synthetic TELT/MALT tables with
 * the values calculated by hand, the edge cases dictated by the binary
 * (16-byte TELT, MALT with a long record, PLST with repeated indices)
 * and what comes out of the real .rwg files of the corpus. Exits with 1 if anything fails.
 * It is run from the repo root (tools/run-checks.sh).
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
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("RwgTablesCheck OK");
   }

   // --------------------------------------------------------- synthetic

   /**
    * Header with "tex1"; TELT with one entry [0,0,1,0,1] + STNG "tex1";
    * MALT with one material [1, 0x14, 0x81, 0.5, 0.25, 1.0, 0.75, 0.75, 0, 0];
    * an ATOM with 3 vertices (bbox + 3) and a triangle with flags 0x11
    * (normal and tag).
    */
   private static void synthetic() {
      byte[] f = file(new String[]{"tex1"}, 20, 40, new int[][]{{0, 0, 1, 0, 1}}, new String[]{"tex1"},
         new int[][]{mat(1, 0x14, 0x81, 0.5F, 0.25F, 1.0F, 0.75F, 0.75F, 0F, 0F)}, 0x11);
      RwgModel m = RwgParser.parse(f);
      eq("header", m.headerTextures.toString(), "[tex1]");
      eq("requests tex1.cmp (without '.', FUN_0041c970 + DAT_00470a7c)", m.textureRequests().toString(), "[tex1.cmp]");
      eq("TELT: 1 entry", m.textures.size(), 1);
      eq("TELT raster 0 = by name", m.textures.get(0).rasterIndex, 0);
      eq("TELT name", m.textures.get(0).name, "tex1");
      eq("MALT: 1 material", m.materials.size(), 1);
      RwgMaterial mt = m.materials.get(0);
      eq("MALT texture 1", mt.textureIndex, 1);
      // 0x14: not < 4, not < 8, not < 0xc -> 4 (solid); bit 0 = 0 -> facet
      eq("MALT geometry (0x14 -> 4)", mt.geometrySampling(), 4);
      eq("MALT light (bit 0 = 0 -> 1)", mt.lightSampling(), 1);
      // 0x81: & 0x1f = 1 (lit), & 0xc0 = 0x80 (double-sided)
      eq("MALT texture modes", mt.textureModes(), 1);
      eq("MALT material modes", mt.materialModes(), 0x80);
      eqf("MALT r", mt.r, 0.5F);
      eqf("MALT g", mt.g, 0.25F);
      eqf("MALT b", mt.b, 1.0F);
      eqf("MALT opacity", mt.opacity, 0.75F);
      eqf("MALT ambient", mt.ambient, 0.75F);
      RwgPolygon p = m.atom.polygons.get(0);
      eq("PLST material", p.materialIndex, 1);
      check("materialOf", m.materialOf(p) == mt);
      eq("PLST tag (flag 0x10)", p.tag, 7);
      eqf("PLST normal z (flag 1)", p.normal()[2], 1.0F);
      check("PLST without flag 4", p.extra == null);
      eq("PLST 0-based indices", Arrays.toString(p.vertexIndices), "[0, 1, 2]");
      eq("VLST: 3 vertices after the box", m.atom.vertices.size(), 3);
      check("VLST flags 7: normal and uv", m.atom.vertices.get(0).hasNormal && m.atom.vertices.get(0).hasUv);
      eqf("VLST u of vertex 2", m.atom.vertices.get(1).u, 1.0F);
      // material 0 and out of range -> none
      check("materialOf(0) = null", m.materialOf(new RwgPolygon(0, new int[3], null, null, (short) 0)) == null);
      check("materialOf(2) = null", m.materialOf(new RwgPolygon(2, new int[3], null, null, (short) 0)) == null);
   }

   /**
    * 0x1003cc68: with a 16-byte TELT record RW reads 0x14 all the same and
    * skips 0x14 - 16 = 4 more: it swallows "STNG" and its length and the search
    * for the STNG fails (0x5a). With 20 bytes the same entry is read fine.
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
      eq("16-byte TELT: RW does not read it (0x5a)", err, 0x5a);
   }

   /** 0x1003c0c0: with record size 44, 40 are read and 4 are skipped. */
   private static void maltLongRecord() {
      int[] a = mat(0, 0xc, 0, 0.1F, 0.2F, 0.3F, 1F, 0F, 1F, 0F);
      int[] b = mat(0, 0x1, 4, 0.9F, 0.8F, 0.7F, 0.5F, 0.2F, 0.3F, 0.4F);
      byte[] f = file(new String[0], 20, 44, new int[0][], new String[0], new int[][]{a, b}, 0x11);
      RwgModel m = RwgParser.parse(f);
      eq("long MALT: 2 materials", m.materials.size(), 2);
      eqf("long MALT: r of the second", m.materials.get(1).r, 0.9F);
      eqf("long MALT: specular of the second", m.materials.get(1).specular, 0.4F);
      // 0xc -> not < 0xc -> 4; 0x1 -> < 4 -> 1 (point cloud), bit 0 -> light 2
      eq("MALT 0xc -> geometry 4", m.materials.get(0).geometrySampling(), 4);
      eq("MALT 0x1 -> geometry 1", m.materials.get(1).geometrySampling(), 1);
      eq("MALT 0x1 -> light 2", m.materials.get(1).lightSampling(), 2);
      eq("MALT modes 4 = filter", m.materials.get(1).textureModes(), 4);
   }

   /** FUN_10001220: repeated runs removed, the last one removed if it repeats the first; &lt; 3 fails. */
   private static void plstCompaction() {
      eq("[1,1,2,3,1] -> [1,2,3]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 1, 2, 3, 1})), "[1, 2, 3]");
      eq("[1,2,2,2,3,4] -> [1,2,3,4]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 2, 2, 3, 4})), "[1, 2, 3, 4]");
      eq("[1,2,1,2] stays", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 1, 2})), "[1, 2, 1, 2]");
      eq("[1,2,2] -> [1,2]", Arrays.toString(RwgParser.compactIndices(new int[]{1, 2, 2})), "[1, 2]");
   }

   // --------------------------------------------------------- corpus

   private static void realFiles() throws Exception {
      RwgModel idle = RwgParser.parse(read("assets/FIRST/IDLE.RWG"));
      eq("IDLE header", idle.headerTextures.toString(), "[idle]");
      eq("IDLE requests idle.cmp", idle.textureRequests().toString(), "[idle.cmp]");
      eq("IDLE TELT", idle.textures.size() + " " + idle.textures.get(0).rasterIndex + " " + idle.textures.get(0).name, "1 0 idle");
      RwgMaterial im = idle.materials.get(0);
      // bytes: 00000001 00000014 00000002 3f780000 3f7c0000 3f780000 3f800000 3f400000 0 0
      eq("IDLE MALT texture", im.textureIndex, 1);
      eq("IDLE MALT word 0x14", im.samplingWord, 0x14);
      eq("IDLE MALT modes 2 (foreshorten, no lit)", im.textureModes(), 2);
      eqf("IDLE MALT r = 0x3f780000", im.r, 0.96875F);
      eqf("IDLE MALT g = 0x3f7c0000", im.g, 0.984375F);
      eqf("IDLE MALT b", im.b, 0.96875F);
      eqf("IDLE MALT opacity", im.opacity, 1.0F);
      eqf("IDLE MALT ambient = 0x3f400000", im.ambient, 0.75F);
      eqf("IDLE MALT diffuse", im.diffuse, 0.0F);
      eq("IDLE polygon with material 1", idle.atom.polygons.get(0).materialIndex, 1);
      eq("IDLE state ON", idle.atom.state(), 2);

      RwgModel e3 = RwgParser.parse(read("assets/gammatutorial-samples/e3.rwg"));
      RwgMaterial em = e3.materials.get(0);
      eq("e3 TELT earthkin", e3.textures.get(0).name, "earthkin");
      eq("e3 MALT word 0x15 -> per-vertex light", em.lightSampling(), 2);
      eqf("e3 MALT ambient = 0x3dcccccd", em.ambient, Float.intBitsToFloat(0x3dcccccd));
      eqf("e3 MALT specular = 0x3f666666", em.specular, Float.intBitsToFloat(0x3f666666));
      eq("e3 ATOM tag", e3.atom.tag(), 1);

      RwgModel ball = RwgParser.parse(read("assets/gammatutorial-samples/ball.rwg"));
      eq("ball: 512 materials", ball.materials.size(), 512);
      eq("ball: 512 polygons", ball.atom.polygons.size(), 512);
      boolean seq = true;
      for (int i = 0; i < 512; i++) {
         seq &= ball.atom.polygons.get(i).materialIndex == i + 1;
      }
      check("ball: the field that counted 1..512 is the material", seq);
      eq("ball MALT without texture", ball.materials.get(0).textureIndex, 0);
      eq("ball MALT lit (modes 1)", ball.materials.get(0).textureModes(), 1);

      RwgModel table = RwgParser.parse(read("assets/gammatutorial-samples/table.rwg"));
      eq("table: 546 polygons", table.atom.polygons.size(), 546);
      eqf("table MALT g", table.materials.get(0).g, 0.5F);

      RwgModel avatar = RwgParser.parse(read("assets/FIRST/AVATAR.RWG"));
      eq("AVATAR: empty header", avatar.headerTextures.size(), 0);
      eq("AVATAR: 0 vertices", avatar.atom.vertices.size(), 0);
      eq("AVATAR: 0 polygons", avatar.atom.polygons.size(), 0);
      eq("AVATAR: state ON", avatar.atom.state(), 2);

      int err = -1;
      try {
         RwgParser.parse(read("assets/gammatutorial-samples/cube.rwg"));
      } catch (RwgParser.RwgFormatException e) {
         err = e.rwError;
      }
      eq("cube.rwg (16-byte TELT): RW does not read it", err, 0x5a);
   }

   // --------------------------------------------------------- builder

   static int[] mat(int tex, int word, int modes, float r, float g, float b, float op, float am, float di, float sp) {
      return new int[]{tex, word, modes, fb(r), fb(g), fb(b), fb(op), fb(am), fb(di), fb(sp)};
   }

   private static int fb(float f) {
      return Float.floatToIntBits(f);
   }

   /** A minimal .rwg: 3 vertices (plus the box) and a triangle with material 1, tag 7 and normal (0,0,1). */
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
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, Object got, Object want) {
      if (got == null ? want != null : !got.equals(want)) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " != " + want);
      }
   }

   private static void eq(String what, int got, int want) {
      eq(what, Integer.valueOf(got), Integer.valueOf(want));
   }

   private static void eqf(String what, float got, float want) {
      if (Float.floatToIntBits(got) != Float.floatToIntBits(want)) {
         failures++;
         System.out.println("FAIL " + what + ": " + got + " != " + want);
      }
   }
}

package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;
import java.util.List;

/**
 * ShapeLoader.loadBinaryFile / finishLoadingBinaryFile in the bridge
 * (NativeShapes): the header's texture list (FUN_0041c970), the
 * resolution of TELT (RWL21 0x1003cd0b..0x1003ce24), the MALT materials
 * (0x1003c10a..c180) set on the PLST polygons, avatar.rwg's empty ATOM
 * and the 0x004187e0 callback. Values from the corpus's real .rwg files. It
 * is run from the repo root. Exits with 1 if anything fails.
 */
public final class RwgBinaryCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("rwgbin").toFile();
      NativeTextures.rwCwd = dir;

      // --- IDLE.RWG: header "idle" -> requests idle.cmp; TELT "idle" raster 0
      int h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      List<String> req = NativeShapes.binaryTextureRequests(h);
      eq("IDLE requests [idle.cmp]", req.toString(), "[idle.cmp]");
      // without an "idle" texture in the dictionary or an idle.{ras,...} file in ".;..": error 0x5e
      eq("IDLE without texture: the CLUM fails", NativeShapes.readBinary(h, false), 0);

      // with the texture in the dictionary (as ShapeTextureLoader leaves it: base name "idle")
      int idleTex = NativeTextures.userTexture("idle", 0, new short[128 * 128], 128, 128);
      h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      int idle = NativeShapes.readBinary(h, false);
      check("IDLE with texture: clump", idle != 0);
      NativeScene.Clump ic = NativeScene.clump(idle);
      eq("IDLE 4 vertices", ic.verts.size(), 4);
      eq("IDLE 1 polygon", ic.polys.size(), 1);
      NativeScene.Material im = NativeScene.material(ic.polys.get(0).material);
      check("IDLE polygon with material", im != null);
      if (im != null) {
         eq("IDLE texture = the dictionary's", im.texture, idleTex);
         eqf("IDLE color r (0x3f780000)", im.color[0], 0.96875F);
         eqf("IDLE color g (0x3f7c0000)", im.color[1], 0.984375F);
         eqf("IDLE ambient 0.75", im.ambient, 0.75F);
         eqf("IDLE diffuse 0", im.diffuse, 0.0F);
         eqf("IDLE opacity 1", im.opacity, 1.0F);
         eq("IDLE texture modes 2 (foreshorten)", im.textureModes, 2);
         eq("IDLE geometry 4 (word 0x14)", im.geometrySampling, 4);
         eq("IDLE light 1 (bit 0 = 0)", im.lightSampling, 1);
      }
      eq("IDLE hints 2 (callback 0x004187e0, tag 0)", ic.hints, 2);
      eq("IDLE state ON", ic.state, 2);
      eq("IDLE axis alignment (STRT[9] = 4)", ic.axisAlignment, 4);
      check("IDLE vertex normal set (VLST flag 1)", NativeScene.vertexNormal(ic, 0) != null);

      // wasError: finishLoadingBinaryFile reads nothing
      h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      eq("wasError -> 0", NativeShapes.readBinary(h, true), 0);

      // TELT by file: without "earthkin" in the dictionary but with earthkin.bmp in "." (FUN_10021270)
      Files.write(new File(dir, "earthkin.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, new int[]{0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000}));
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/e3.rwg"));
      eq("e3 requests [earthkin.cmp]", NativeShapes.binaryTextureRequests(h).toString(), "[earthkin.cmp]");
      int e3 = NativeShapes.readBinary(h, false);
      check("e3 read with earthkin.bmp from the shapes path", e3 != 0);
      if (e3 != 0) {
         NativeScene.Material em = NativeScene.material(NativeScene.clump(e3).polys.get(0).material);
         NativeTextures.Texture et = NativeTextures.texture(em.texture);
         check("e3 texture read by RwGetNamedTexture", et != null && (et.pixels[0] & 0xFFFF) == 0xF800);
         eq("e3 per-vertex light (word 0x15)", em.lightSampling, 2);
         // the callback sets hints 2 (HS mode 1) and FUN_10033600 turns it into
         // editable (| 4) because e3 has 2400 polygons > 0x3e8 (0x1003362b)
         eq("e3 tag 1 -> hints 2, > 1000 polygons -> 6", NativeScene.clump(e3).hints, 6);
      }

      // --- AVATAR.RWG: empty ATOM = valid, empty clump (not 0)
      h = NativeShapes.openBinary(abs("assets/WorldsPlayer/avatar.rwg"));
      eq("avatar requests nothing", NativeShapes.binaryTextureRequests(h).size(), 0);
      int av = NativeShapes.readBinary(h, false);
      check("avatar.rwg gives a clump", av != 0);
      if (av != 0) {
         eq("avatar 0 vertices", NativeScene.getNumVertices(av), 0);
         eq("avatar state ON", NativeScene.getClumpState(av), 2);
         eq("avatar hints 2", NativeScene.clump(av).hints, 2);
      }

      // --- ball.rwg: 512 materials, polygon i with material i
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/ball.rwg"));
      int ball = NativeShapes.readBinary(h, false);
      check("ball read", ball != 0);
      if (ball != 0) {
         NativeScene.Clump bc = NativeScene.clump(ball);
         eq("ball 512 polygons", bc.polys.size(), 512);
         check("ball distinct materials", bc.polys.get(0).material != bc.polys.get(1).material);
         NativeScene.Material bm = NativeScene.material(bc.polys.get(0).material);
         eqf("ball red 0.96875", bm.color[0], 0.96875F);
         eq("ball lit", bm.textureModes, 1);
         eq("ball without texture", bm.texture, 0);
         eq("ball per-vertex light (0xd)", bm.lightSampling, 2);
      }

      // --- cube.rwg: 16-byte TELT, RW does not read it
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/cube.rwg"));
      eq("cube requests [forest.cmp]", NativeShapes.binaryTextureRequests(h).toString(), "[forest.cmp]");
      eq("cube.rwg -> 0", NativeShapes.readBinary(h, false), 0);

      // --- nonexistent file: the object exists, requests nothing and reads nothing
      h = NativeShapes.openBinary(new File(dir, "missing.rwg").getAbsolutePath());
      check("load object even if there is no file", h != 0);
      eq("nonexistent -> 0", NativeShapes.readBinary(h, false), 0);

      // --- callback 0x004187e0: tag < 0x4000000 -> hints 2; otherwise, state OFF
      int root = NativeScene.createClump();
      int a = NativeScene.createClump();
      int b = NativeScene.createClump();
      int s = NativeScene.createClump();
      NativeScene.setClumpHints(root, 5);
      NativeScene.setClumpTag(a, 0x3ffffff);
      NativeScene.setClumpHints(a, 1);
      NativeScene.setClumpTag(b, 0x4000000);
      NativeScene.setClumpTag(s, 0x40000001);
      NativeScene.addChildToClump(root, a);
      NativeScene.addChildToClump(root, b);
      NativeScene.addChildToClump(a, s);
      NativeShapes.afterLoad(root);
      eq("root tag 0 -> hints 2", NativeScene.clump(root).hints, 2);
      eq("0x3ffffff -> hints 2", NativeScene.clump(a).hints, 2);
      eq("0x3ffffff stays ON", NativeScene.getClumpState(a), 2);
      eq("0x4000000 -> OFF", NativeScene.getClumpState(b), 1);
      eq("0x40000001 (grandchild) -> OFF", NativeScene.getClumpState(s), 1);

      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("RwgBinaryCheck OK");
   }

   private static String abs(String p) {
      return new File(p).getAbsolutePath();
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

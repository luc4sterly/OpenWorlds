package NET.worlds.core;

import java.io.File;
import java.nio.file.Files;
import java.util.List;

/**
 * ShapeLoader.loadBinaryFile / finishLoadingBinaryFile en el puente
 * (NativeShapes): la lista de texturas de la cabecera (FUN_0041c970), la
 * resolución de TELT (RWL21 0x1003cd0b..0x1003ce24), los materiales de
 * MALT (0x1003c10a..c180) puestos en los polígonos de PLST, el ATOM vacío
 * de avatar.rwg y el callback 0x004187e0. Valores de los .rwg reales del
 * corpus. Se ejecuta desde la raíz del repo. Sale con 1 si algo falla.
 */
public final class RwgBinaryCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File dir = Files.createTempDirectory("rwgbin").toFile();
      NativeTextures.rwCwd = dir;

      // --- IDLE.RWG: cabecera "idle" -> pide idle.cmp; TELT "idle" raster 0
      int h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      List<String> req = NativeShapes.binaryTextureRequests(h);
      eq("IDLE pide [idle.cmp]", req.toString(), "[idle.cmp]");
      // sin textura "idle" en el diccionario ni fichero idle.{ras,...} en ".;..": error 0x5e
      eq("IDLE sin textura: el CLUM falla", NativeShapes.readBinary(h, false), 0);

      // con la textura en el diccionario (como la deja ShapeTextureLoader: nombre base "idle")
      int idleTex = NativeTextures.userTexture("idle", 0, new short[128 * 128], 128, 128);
      h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      int idle = NativeShapes.readBinary(h, false);
      check("IDLE con textura: clump", idle != 0);
      NativeScene.Clump ic = NativeScene.clump(idle);
      eq("IDLE 4 vértices", ic.verts.size(), 4);
      eq("IDLE 1 polígono", ic.polys.size(), 1);
      NativeScene.Material im = NativeScene.material(ic.polys.get(0).material);
      check("IDLE polígono con material", im != null);
      if (im != null) {
         eq("IDLE textura = la del diccionario", im.texture, idleTex);
         eqf("IDLE color r (0x3f780000)", im.color[0], 0.96875F);
         eqf("IDLE color g (0x3f7c0000)", im.color[1], 0.984375F);
         eqf("IDLE ambiente 0.75", im.ambient, 0.75F);
         eqf("IDLE difusa 0", im.diffuse, 0.0F);
         eqf("IDLE opacidad 1", im.opacity, 1.0F);
         eq("IDLE modos de textura 2 (foreshorten)", im.textureModes, 2);
         eq("IDLE geometría 4 (palabra 0x14)", im.geometrySampling, 4);
         eq("IDLE luz 1 (bit 0 = 0)", im.lightSampling, 1);
      }
      eq("IDLE hints 2 (callback 0x004187e0, tag 0)", ic.hints, 2);
      eq("IDLE estado ON", ic.state, 2);
      eq("IDLE alineación de ejes (STRT[9] = 4)", ic.axisAlignment, 4);
      check("IDLE normal de vértice puesta (VLST bandera 1)", NativeScene.vertexNormal(ic, 0) != null);

      // wasError: finishLoadingBinaryFile no lee nada
      h = NativeShapes.openBinary(abs("assets/FIRST/IDLE.RWG"));
      eq("wasError -> 0", NativeShapes.readBinary(h, true), 0);

      // TELT por fichero: sin "earthkin" en el diccionario pero con earthkin.bmp en "." (FUN_10021270)
      Files.write(new File(dir, "earthkin.bmp").toPath(), TexRwReadCheck.bmp24(2, 2, new int[]{0xFF0000, 0xFF0000, 0xFF0000, 0xFF0000}));
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/e3.rwg"));
      eq("e3 pide [earthkin.cmp]", NativeShapes.binaryTextureRequests(h).toString(), "[earthkin.cmp]");
      int e3 = NativeShapes.readBinary(h, false);
      check("e3 leído con earthkin.bmp de la ruta de formas", e3 != 0);
      if (e3 != 0) {
         NativeScene.Material em = NativeScene.material(NativeScene.clump(e3).polys.get(0).material);
         NativeTextures.Texture et = NativeTextures.texture(em.texture);
         check("e3 textura leída por RwGetNamedTexture", et != null && (et.pixels[0] & 0xFFFF) == 0xF800);
         eq("e3 luz por vértice (palabra 0x15)", em.lightSampling, 2);
         eq("e3 tag 1 -> hints 2", NativeScene.clump(e3).hints, 2);
      }

      // --- AVATAR.RWG: ATOM vacío = clump válido y vacío (no 0)
      h = NativeShapes.openBinary(abs("assets/WorldsPlayer/avatar.rwg"));
      eq("avatar pide nada", NativeShapes.binaryTextureRequests(h).size(), 0);
      int av = NativeShapes.readBinary(h, false);
      check("avatar.rwg da clump", av != 0);
      if (av != 0) {
         eq("avatar 0 vértices", NativeScene.getNumVertices(av), 0);
         eq("avatar estado ON", NativeScene.getClumpState(av), 2);
         eq("avatar hints 2", NativeScene.clump(av).hints, 2);
      }

      // --- ball.rwg: 512 materiales, el polígono i con el material i
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/ball.rwg"));
      int ball = NativeShapes.readBinary(h, false);
      check("ball leído", ball != 0);
      if (ball != 0) {
         NativeScene.Clump bc = NativeScene.clump(ball);
         eq("ball 512 polígonos", bc.polys.size(), 512);
         check("ball materiales distintos", bc.polys.get(0).material != bc.polys.get(1).material);
         NativeScene.Material bm = NativeScene.material(bc.polys.get(0).material);
         eqf("ball rojo 0.96875", bm.color[0], 0.96875F);
         eq("ball lit", bm.textureModes, 1);
         eq("ball sin textura", bm.texture, 0);
         eq("ball luz por vértice (0xd)", bm.lightSampling, 2);
      }

      // --- cube.rwg: TELT de 16 bytes, RW no lo lee
      h = NativeShapes.openBinary(abs("assets/gammatutorial-samples/cube.rwg"));
      eq("cube pide [forest.cmp]", NativeShapes.binaryTextureRequests(h).toString(), "[forest.cmp]");
      eq("cube.rwg -> 0", NativeShapes.readBinary(h, false), 0);

      // --- fichero inexistente: el objeto existe, pide nada y no lee
      h = NativeShapes.openBinary(new File(dir, "nada.rwg").getAbsolutePath());
      check("objeto de carga aunque no haya fichero", h != 0);
      eq("inexistente -> 0", NativeShapes.readBinary(h, false), 0);

      // --- callback 0x004187e0: tag < 0x4000000 -> hints 2; si no, estado OFF
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
      eq("raíz tag 0 -> hints 2", NativeScene.clump(root).hints, 2);
      eq("0x3ffffff -> hints 2", NativeScene.clump(a).hints, 2);
      eq("0x3ffffff sigue ON", NativeScene.getClumpState(a), 2);
      eq("0x4000000 -> OFF", NativeScene.getClumpState(b), 1);
      eq("0x40000001 (nieto) -> OFF", NativeScene.getClumpState(s), 1);

      if (failures > 0) {
         System.out.println(failures + " fallos");
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

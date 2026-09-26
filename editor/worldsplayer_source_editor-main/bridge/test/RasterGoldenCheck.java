import NET.worlds.core.NativeCamera;
import NET.worlds.core.NativeScene;
import NET.worlds.core.NativeShapes;
import NET.worlds.core.NativeTextures;

import java.io.File;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Enumeration;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * Regresion de pixel del rasterizador del puente (NativeCamera): monta una
 * escena determinista con formas .rwx REALES de GroundZero (texturas .cmp
 * del content.zip registradas por nombre, como hace ShapeLoader antes de
 * RwReadShape) mas quads sinteticos que fuerzan cada camino del driver
 * (textura iluminada, Gouraud, plano, translucido por tramado, doble cara
 * vista por detras, recorte por el plano cercano), y la dibuja desde varias
 * camaras a 3 tamanos (132x130 del AdPart, 468x272 de la ventana por
 * defecto, 1172x848 maximizada). Compara el CRC32 del raster 5-6-5 de cada
 * vista con bridge/test/raster-golden.txt.
 *
 * Sirve para optimizar el motor sin cambiar un pixel: cualquier cambio de
 * resultado (buscado o no) cambia un CRC. Si el cambio es intencionado, se
 * regenera con -Dgolden.write=1 y se explica en el commit.
 * -Dgolden.png=DIR guarda cada vista como PNG para mirarla.
 * -Dgolden.threads=N fuerza N hilos de raster (0 = los del puente).
 */
public final class RasterGoldenCheck {
   private static final String ROOT = System.getProperty("golden.root", ".");
   private static final File GZ = new File(ROOT, "assets/WorldsPlayer/GroundZero");
   private static final File GOLDEN = new File(ROOT, "editor/worldsplayer_source_editor-main/bridge/test/raster-golden.txt");

   public static void main(String[] args) throws Exception {
      int scene = buildScene();
      Map<String, Long> got = new LinkedHashMap<String, Long>();
      int[][] sizes = {{132, 130}, {468, 272}, {1172, 848}};
      float[][] views = {
         // eye x, y, z, look-at x, y, z
         {-600, -900, 260, 400, 300, 60},
         {1500, 1400, 500, 300, 200, 0},
         {300, -200, 40, 300, 600, 90},
         {150, 150, 30, 900, 900, 0},
         {450, -150, -120, 450, 520, 70},
         {-50, 2200, 1400, 500, 400, 0},
      };
      String pngDir = System.getProperty("golden.png");
      long t0 = System.nanoTime();
      int frames = 0;
      for (int[] sz : sizes) {
         int cam = NativeCamera.createCamera(sz[0], sz[1], 0);
         NativeCamera.setViewwindow(cam, 0.6F, 0.6F * sz[1] / sz[0]);
         NativeCamera.setOffsetAndViewport(cam, 0, 0, sz[0], sz[1]);
         for (int v = 0; v < views.length; v++) {
            float[] e = views[v];
            NativeCamera.setPosition(cam, e[0], e[1], e[2]);
            NativeCamera.setLookAt(cam, e[3] - e[0], e[4] - e[1], e[5] - e[2]);
            NativeCamera.setLookUp(cam, 0, 0, 1);
            NativeCamera.setLookAt(cam, e[3] - e[0], e[4] - e[1], e[5] - e[2]);
            NativeCamera.clear(cam, 0.2F, 0.3F, 0.45F);
            NativeCamera.renderScene(scene, cam, 1);
            frames++;
            NativeCamera.Cam c = NativeCamera.cam(cam);
            CRC32 crc = new CRC32();
            for (short s : c.raster) {
               crc.update(s & 0xFF);
               crc.update(s >> 8 & 0xFF);
            }
            String key = sz[0] + "x" + sz[1] + "-v" + v;
            got.put(key, crc.getValue());
            if (pngDir != null) {
               new File(pngDir).mkdirs();
               javax.imageio.ImageIO.write(c.image, "png", new File(pngDir, key + ".png"));
            }
         }
         NativeCamera.destroyCamera(cam);
      }
      long ms = (System.nanoTime() - t0) / 1000000L;
      System.out.println("RasterGoldenCheck: " + frames + " vistas en " + ms + " ms");
      // -Dgolden.bench=N: N frames de cada vista a 1172x848, ms por frame en regimen estable
      int bench = Integer.getInteger("golden.bench", 0);
      if (bench > 0) {
         int cam = NativeCamera.createCamera(1172, 848, 0);
         NativeCamera.setViewwindow(cam, 0.6F, 0.6F * 848 / 1172);
         NativeCamera.setOffsetAndViewport(cam, 0, 0, 1172, 848);
         for (int round = 0; round < 2; round++) {
            long b0 = System.nanoTime();
            for (int i = 0; i < bench; i++) {
               float[] e = views[i % views.length];
               NativeCamera.setPosition(cam, e[0], e[1], e[2]);
               NativeCamera.setLookAt(cam, e[3] - e[0], e[4] - e[1], e[5] - e[2]);
               NativeCamera.setLookUp(cam, 0, 0, 1);
               NativeCamera.setLookAt(cam, e[3] - e[0], e[4] - e[1], e[5] - e[2]);
               NativeCamera.clear(cam, 0.2F, 0.3F, 0.45F);
               NativeCamera.renderScene(scene, cam, 1);
            }
            double per = (System.nanoTime() - b0) / 1e6 / bench;
            System.out.println("bench " + (round == 0 ? "(calentando)" : "") + ": " + String.format("%.2f", per) + " ms/frame a 1172x848");
         }
      }
      if (Boolean.getBoolean("golden.write") || "1".equals(System.getProperty("golden.write"))) {
         StringBuilder sb = new StringBuilder("# CRC32 del raster 5-6-5 por vista (RasterGoldenCheck); regenerar con -Dgolden.write=1\n");
         for (Map.Entry<String, Long> en : got.entrySet()) {
            sb.append(en.getKey()).append(' ').append(Long.toHexString(en.getValue())).append('\n');
         }
         Files.write(GOLDEN.toPath(), sb.toString().getBytes("UTF-8"));
         System.out.println("escrito " + GOLDEN);
         return;
      }
      Map<String, String> want = new LinkedHashMap<String, String>();
      for (String line : Files.readAllLines(GOLDEN.toPath())) {
         if (line.startsWith("#") || line.trim().isEmpty()) {
            continue;
         }
         String[] f = line.trim().split("\\s+");
         want.put(f[0], f[1]);
      }
      int bad = 0;
      for (Map.Entry<String, Long> en : got.entrySet()) {
         String w = want.get(en.getKey());
         String g = Long.toHexString(en.getValue());
         if (!g.equals(w)) {
            System.out.println("FALLA " + en.getKey() + ": crc " + g + ", esperado " + w);
            bad++;
         }
      }
      if (bad != 0 || want.size() != got.size()) {
         System.out.println("FALLA: " + bad + " vistas distintas de " + got.size() + " (golden con " + want.size() + ")");
         System.exit(1);
      }
      System.out.println("RasterGoldenCheck OK (" + got.size() + " vistas identicas al golden)");
   }

   /** Formas reales en rejilla + quads que fuerzan cada camino del rasterizador. */
   private static int buildScene() throws Exception {
      int scene = NativeScene.createScene();
      int sun = NativeScene.createLight(1, -0.4F, -0.5F, -0.75F, 0.9F);
      NativeScene.addLightToScene(scene, sun);
      int fill = NativeScene.createLight(1, 0.7F, 0.2F, -0.3F, 0.5F);
      NativeScene.setLightColor(fill, 0.6F, 0.4F, 0.9F);
      NativeScene.addLightToScene(scene, fill);

      Map<String, byte[]> cmp = new LinkedHashMap<String, byte[]>();
      try (ZipFile z = new ZipFile(new File(GZ, "content.zip"))) {
         for (Enumeration<? extends ZipEntry> en = z.entries(); en.hasMoreElements(); ) {
            ZipEntry ze = en.nextElement();
            String n = ze.getName().toLowerCase();
            if (n.endsWith(".cmp")) {
               cmp.put(n.substring(n.lastIndexOf('/') + 1, n.length() - 4), z.getInputStream(ze).readAllBytes());
            }
         }
      }
      File[] rwx = new File(GZ, "tex").listFiles((d, n) -> n.toLowerCase().endsWith(".rwx"));
      java.util.Arrays.sort(rwx);
      int placed = 0;
      for (File f : rwx) {
         for (String t : NativeShapes.scanTextures(f.getPath())) {
            String base = t.toLowerCase();
            int dot = base.lastIndexOf('.');
            if (dot > 0) {
               base = base.substring(0, dot);
            }
            byte[] data = cmp.get(base);
            if (data != null && NativeTextures.lookupOrRead(base, null, 0) == 0) {
               NativeTextures.makeScapePic(base, data, 1);
            }
         }
         int clump = NativeShapes.readShape(f.getPath()).clump;
         if (clump == 0) {
            continue;
         }
         float[] bb = NativeScene.getClumpLocalBBox(clump);
         float span = bb == null ? 100 : Math.max(Math.max(bb[3] - bb[0], bb[4] - bb[1]), bb[5] - bb[2]);
         float s = span > 0 ? 160.0F / span : 1.0F;
         int gx = placed % 6, gy = placed / 6;
         float[] m = {s, 0, 0, 0, 0, s, 0, 0, 0, 0, s, 0, gx * 180.0F, gy * 180.0F, 0, 1};
         NativeScene.transformClump(clump, m, 1);
         NativeScene.addClumpToScene(scene, clump);
         placed++;
      }
      // Suelo texturizado e iluminado, grande: la mayoria de pixeles en el camino de textura.
      addQuad(scene, texMat(cmp, "aufloor1", 1.0F, 0), -400, -400, -2, 1600, 1600, -2, 8);
      // Pared Gouraud (sin textura, muestreo por vertice) con normales de una rejilla curvada.
      int g = NativeScene.createMaterial();
      NativeScene.setMaterialColor(g, 0.8F, 0.55F, 0.3F);
      NativeScene.setMaterialSurface(g, 0.25F, 0.7F, 0.6F);
      NativeScene.smoothShading(g);
      addBump(scene, g, 1150, -300, 0, 1150, 900, 420, 12);
      // Pared plana sin textura.
      int flat = NativeScene.createMaterial();
      NativeScene.setMaterialColor(flat, 0.3F, 0.8F, 0.4F);
      NativeScene.setMaterialSurface(flat, 0.3F, 0.6F, 0.0F);
      NativeScene.flatShading(flat);
      addQuad(scene, flat, -350, 1100, 0, 900, 1100, 400, 1);
      // Cristal translucido (tramado 8x8) delante de las formas.
      int glass = texMat(cmp, "auwall2", 0.5F, 0);
      addQuad(scene, glass, 100, 250, 0, 700, 250, 250, 1);
      // Doble cara: se ve por detras desde la vista v4 (camara bajo el suelo).
      int both = texMat(cmp, "aured", 1.0F, 0x80);
      addQuad(scene, both, 700, 520, 0, 200, 520, 240, 2);
      System.out.println("RasterGoldenCheck: " + placed + " formas .rwx reales de " + rwx.length + " + 5 superficies de prueba");
      return scene;
   }

   private static int texMat(Map<String, byte[]> cmp, String name, float opacity, int modes) {
      int m = NativeScene.createMaterial();
      NativeScene.setMaterialColor(m, 1, 1, 1);
      NativeScene.setMaterialSurface(m, 0.35F, 0.65F, 0.2F);
      Object[] r = NativeTextures.makeScapePic("golden-" + name, cmp.get(name), 1);
      NativeScene.setMaterialTexture(m, ((int[]) r[0])[0]);
      if (opacity < 1.0F) {
         NativeScene.setMaterialOpacity(m, opacity);
      }
      if (modes != 0) {
         NativeScene.setMaterialModes(m, modes);
      }
      return m;
   }

   /** Rejilla n x n de quads entre (x0,y0,z0) y (x1,y1,z1) (plano z o plano vertical). */
   private static void addQuad(int scene, int mat, float x0, float y0, float z0, float x1, float y1, float z1, int n) {
      int k = NativeScene.createClump();
      boolean horizontal = z0 == z1;
      for (int j = 0; j <= n; j++) {
         for (int i = 0; i <= n; i++) {
            float a = (float) i / n, b = (float) j / n;
            float x, y, z;
            if (horizontal) {
               x = x0 + (x1 - x0) * a;
               y = y0 + (y1 - y0) * b;
               z = z0;
            } else {
               x = x0 + (x1 - x0) * a;
               y = y0 + (y1 - y0) * a;
               z = z0 + (z1 - z0) * b;
            }
            int vi = NativeScene.addVertex(k, x, y, z);
            NativeScene.setVertexUV(k, vi, a * n * 0.75F, b * n * 0.75F);
         }
      }
      addGrid(k, mat, n);
      NativeScene.addClumpToScene(scene, k);
   }

   /** Pared vertical abombada (para que el Gouraud tenga gradiente real). */
   private static void addBump(int scene, int mat, float x0, float y0, float z0, float x1, float y1, float z1, int n) {
      int k = NativeScene.createClump();
      for (int j = 0; j <= n; j++) {
         for (int i = 0; i <= n; i++) {
            float a = (float) i / n, b = (float) j / n;
            float bulge = (float) (Math.sin(a * Math.PI) * Math.sin(b * Math.PI) * 140.0);
            NativeScene.addVertex(k, x0 - bulge, y0 + (y1 - y0) * a, z0 + (z1 - z0) * b);
         }
      }
      addGrid(k, mat, n);
      NativeScene.addClumpToScene(scene, k);
   }

   private static void addGrid(int k, int mat, int n) {
      List<Integer> polys = new ArrayList<Integer>();
      for (int j = 0; j < n; j++) {
         for (int i = 0; i < n; i++) {
            int a = j * (n + 1) + i + 1;
            int b = a + 1;
            int c = a + n + 2;
            int d = a + n + 1;
            polys.add(NativeScene.addPolygon(k, 4, new int[]{a, b, c, d}));
         }
      }
      for (int p : polys) {
         NativeScene.setPolygonMaterial(p, mat);
      }
   }
}

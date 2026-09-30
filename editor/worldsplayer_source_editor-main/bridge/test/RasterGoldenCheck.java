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
 * Pixel regression of the bridge's rasterizer (NativeCamera): builds a
 * deterministic scene with REAL .rwx shapes from GroundZero (the .cmp
 * textures of content.zip registered by name, as ShapeLoader does before
 * RwReadShape) plus synthetic quads that force each path of the driver
 * (lit texture, Gouraud, flat, translucent by dithering, double-sided
 * seen from behind, clipping by the near plane), and draws it from several
 * cameras at 3 sizes (132x130 of the AdPart, 468x272 of the default
 * window, 1172x848 maximized). It compares the CRC32 of each view's 5-6-5
 * raster with bridge/test/raster-golden.txt.
 *
 * It serves to optimize the engine without changing a pixel: any change in
 * the result (intended or not) changes a CRC. If the change is intentional,
 * the file is regenerated with -Dgolden.write=1 and explained in the commit.
 * -Dgolden.png=DIR saves each view as a PNG so it can be looked at.
 * -Dgolden.threads=N forces N raster threads (0 = the bridge's own).
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
      System.out.println("RasterGoldenCheck: " + frames + " views in " + ms + " ms");
      // -Dgolden.bench=N: N frames of each view at 1172x848, ms per frame in steady state
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
            System.out.println("bench " + (round == 0 ? "(warming up)" : "") + ": " + String.format("%.2f", per) + " ms/frame at 1172x848");
         }
      }
      if (Boolean.getBoolean("golden.write") || "1".equals(System.getProperty("golden.write"))) {
         StringBuilder sb = new StringBuilder("# CRC32 del raster 5-6-5 por vista (RasterGoldenCheck); regenerar con -Dgolden.write=1\n");
         for (Map.Entry<String, Long> en : got.entrySet()) {
            sb.append(en.getKey()).append(' ').append(Long.toHexString(en.getValue())).append('\n');
         }
         Files.write(GOLDEN.toPath(), sb.toString().getBytes("UTF-8"));
         System.out.println("written " + GOLDEN);
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
            System.out.println("FAIL " + en.getKey() + ": crc " + g + ", expected " + w);
            bad++;
         }
      }
      if (bad != 0 || want.size() != got.size()) {
         System.out.println("FAIL: " + bad + " views differ out of " + got.size() + " (golden has " + want.size() + ")");
         System.exit(1);
      }
      System.out.println("RasterGoldenCheck OK (" + got.size() + " views identical to the golden)");
   }

   /** Real shapes on a grid + quads that force each path of the rasterizer. */
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
      // Textured, lit floor, large: most pixels on the texture path.
      addQuad(scene, texMat(cmp, "aufloor1", 1.0F, 0), -400, -400, -2, 1600, 1600, -2, 8);
      // Gouraud wall (no texture, per-vertex sampling) with normals from a curved grid.
      int g = NativeScene.createMaterial();
      NativeScene.setMaterialColor(g, 0.8F, 0.55F, 0.3F);
      NativeScene.setMaterialSurface(g, 0.25F, 0.7F, 0.6F);
      NativeScene.smoothShading(g);
      addBump(scene, g, 1150, -300, 0, 1150, 900, 420, 12);
      // Flat wall without texture.
      int flat = NativeScene.createMaterial();
      NativeScene.setMaterialColor(flat, 0.3F, 0.8F, 0.4F);
      NativeScene.setMaterialSurface(flat, 0.3F, 0.6F, 0.0F);
      NativeScene.flatShading(flat);
      addQuad(scene, flat, -350, 1100, 0, 900, 1100, 400, 1);
      // Translucent glass (8x8 dithering) in front of the shapes.
      int glass = texMat(cmp, "auwall2", 0.5F, 0);
      addQuad(scene, glass, 100, 250, 0, 700, 250, 250, 1);
      // Double-sided: seen from behind from view v4 (camera below the floor).
      int both = texMat(cmp, "aured", 1.0F, 0x80);
      addQuad(scene, both, 700, 520, 0, 200, 520, 240, 2);
      System.out.println("RasterGoldenCheck: " + placed + " real .rwx shapes out of " + rwx.length + " + 5 test surfaces");
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

   /** n x n grid of quads between (x0,y0,z0) and (x1,y1,z1) (z plane or vertical plane). */
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

   /** Bulging vertical wall (so that Gouraud has a real gradient). */
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

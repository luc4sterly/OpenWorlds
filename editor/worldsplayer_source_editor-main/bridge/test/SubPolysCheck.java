import NET.worlds.core.NativeScene;

/**
 * Surface.addSubPolys (gamma.dll 0x004206d0) in the bridge
 * (NativeScene.addSubPolys): x/u of vertices 1 and 2, z/v of 1 and 4,
 * first cell rounded down and last one rounded up. Cases
 * calculated by hand on the Rect of Rect.addRwChildren: 1 = (0,0,0) uv
 * (uo, v+vo), 2 = (1,0,0) uv (u+uo, v+vo), 3 = (1,0,1), 4 = (0,0,1) uv
 * (uo, vo).
 */
public final class SubPolysCheck {
   private static int failures;
   /**
    * The UVs are read with RwGetClumpVertexUV, which returns RWL21's 16.16
    * fixed-point value (NativeScene.uvFixed): 0.3 comes back as 0.29998779.
    */
   private static final float TOL = 1.0F / 65536.0F;

   private static int rect(float u, float v, float uo, float vo) {
      int c = NativeScene.createClump();
      NativeScene.addVertex(c, 0, 0, 0);
      NativeScene.addVertex(c, 1, 0, 0);
      NativeScene.addVertex(c, 1, 0, 1);
      NativeScene.addVertex(c, 0, 0, 1);
      NativeScene.setVertexUV(c, 1, uo, v + vo);
      NativeScene.setVertexUV(c, 2, u + uo, v + vo);
      NativeScene.setVertexUV(c, 3, u + uo, vo);
      NativeScene.setVertexUV(c, 4, uo, vo);
      return c;
   }

   /** Cell k: vertices 5+4k.. = (xc,0,za) (xd,0,za) (xd,0,zb) (xc,0,zb), uv (c,a) (d,a) (d,b) (c,b). */
   private static void cell(String what, int clump, int k, float xc, float xd, float za, float zb, float c, float d, float a, float b) {
      int v = 5 + 4 * k;
      float[][] want = {{xc, za, c, a}, {xd, za, d, a}, {xd, zb, d, b}, {xc, zb, c, b}};
      for (int i = 0; i < 4; i++) {
         float[] p = NativeScene.getVertex(clump, v + i);
         float[] t = NativeScene.getVertexUV(clump, v + i);
         float[] got = {p[0], p[2], t[0], t[1]};
         for (int j = 0; j < 4; j++) {
            if (Math.abs(got[j] - want[i][j]) > TOL || p[1] != 0.0F) {
               System.out.println("FAIL " + what + " cell " + k + " vertex " + i + " component " + j + ": " + got[j] + " != " + want[i][j]);
               failures++;
               return;
            }
         }
      }
   }

   private static void count(String what, int[] polys, int clump, int n) {
      if (polys.length != n || NativeScene.getNumVertices(clump) != 4 + 4 * n) {
         System.out.println("FAIL " + what + ": " + polys.length + " polygons / " + NativeScene.getNumVertices(clump) + " vertices, expected " + n + " / " + (4 + 4 * n));
         failures++;
      }
   }

   public static void main(String[] args) {
      // u = v = 1, material 2h*2v*: 4 cells. With vertex 4 for x/u (Ghidra's
      // C) u4 - u1 = 0 and none came out.
      int c = rect(1, 1, 0, 0);
      int[] p = NativeScene.addSubPolys(c, 0, 2, 2);
      count("2x2", p, c, 4);
      if (p.length == 4) {
         // dx = (x2-x1)/(2*(u2-u1)) = 0.5, dz = (z4-z1)/(2*(v4-v1)) = -0.5;
         // row iv = 1 (sv goes down from vRes-1): a = 2, b = 1 -> z 0 .. 0.5
         cell("2x2", c, 0, 0.0F, 0.5F, 0.0F, 0.5F, 0, 1, 1, 0);
         cell("2x2", c, 1, 0.5F, 1.0F, 0.0F, 0.5F, 0, 1, 1, 0);
         cell("2x2", c, 2, 0.0F, 0.5F, 0.5F, 1.0F, 0, 1, 1, 0);
         cell("2x2", c, 3, 0.5F, 1.0F, 0.5F, 1.0F, 0, 1, 1, 0);
      }
      // u = 1.3, v = 1, 1h*1v: uMax = 1.3 -> ceil = 2 columns (with rint
      // it gave 1). dx = 1/1.3; second cell c = 1, d = uHi = 1.3 -> x from
      // 1/1.3 = 0.769231 to 1, u from 0 to 0.3.
      c = rect(1.3F, 1, 0, 0);
      p = NativeScene.addSubPolys(c, 0, 1, 1);
      count("u=1.3", p, c, 2);
      if (p.length == 2) {
         cell("u=1.3", c, 0, 0.0F, 1.0F / 1.3F, 0.0F, 1.0F, 0, 1, 1, 0);
         cell("u=1.3", c, 1, 1.0F / 1.3F, 1.0F, 0.0F, 1.0F, 0, 0.3F, 1, 0);
      }
      // uo = 0.5 (uOff): u from 0.5 to 1.5 -> floor 0, ceil 2: two cells,
      // the first with u 0.5..1 (x 0..0.5) and the second with 0..0.5 (x 0.5..1).
      c = rect(1, 1, 0.5F, 0);
      p = NativeScene.addSubPolys(c, 0, 1, 1);
      count("uo=0.5", p, c, 2);
      if (p.length == 2) {
         cell("uo=0.5", c, 0, 0.0F, 0.5F, 0.0F, 1.0F, 0.5F, 1, 1, 0);
         cell("uo=0.5", c, 1, 0.5F, 1.0F, 0.0F, 1.0F, 0, 0.5F, 1, 0);
      }
      if (failures != 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("SubPolysCheck OK");
   }
}

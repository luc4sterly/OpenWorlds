import NET.worlds.core.NativeCamera;
import NET.worlds.core.NativeScene;

/**
 * RWL21's polygon sorting tree (0x10033750 / 0x10033cc0), the hints mode
 * machine (FUN_10033600) and the range/rounding of the UVs in
 * RwSetClumpVertexUV (0x10017de0) / RwGetClumpVertexUV (0x10017f50) in the
 * bridge. Hand-calculated cases in the comments.
 */
public final class RasterTreeCheck {
   private static int failures;

   private static void expect(String what, boolean ok) {
      if (!ok) {
         System.out.println("FAIL " + what);
         failures++;
      }
   }

   private static int quad(int c, float[] a, float[] b, float[] d, float[] e) {
      int base = NativeScene.getNumVertices(c);
      NativeScene.addVertex(c, a[0], a[1], a[2]);
      NativeScene.addVertex(c, b[0], b[1], b[2]);
      NativeScene.addVertex(c, d[0], d[1], d[2]);
      NativeScene.addVertex(c, e[0], e[1], e[2]);
      return NativeScene.addPolygon(c, 4, new int[]{base + 1, base + 2, base + 3, base + 4});
   }

   private static float[] p(float x, float y, float z) {
      return new float[]{x, y, z};
   }

   public static void main(String[] args) {
      // Synthetic clump:
      //  P0 floor z=0 facing +z (normal (0,0,1), dist 0, area 2)
      //  P1 ceiling z=1 facing +z (dist 1): classify(P0,P1) = 1 -> after P0
      //  P2 z=0.5 facing -z (dist -0.5): each in front of the other -> 3,
      //     joins P0's list
      //  P3 vertical x=0.5, z from -0.5 to 0.5 (normal (1,0,0), dist 0.5):
      //     crosses P0 -> 2 (P0 and P3 in conflict); against P2 -> 1; goes down
      //     the "after" side of P0 (P1), where classify(P1,P3) = -1 -> P1.back.
      // Read in order: P0 (flag 1 first), P2, P3, P1; flags
      // 1,0,1,0 -> runs [1,1,1,1] closed by 0, the first with z.
      int c = NativeScene.createClump();
      quad(c, p(0, 0, 0), p(1, 0, 0), p(1, 1, 0), p(0, 1, 0));
      quad(c, p(0, 0, 1), p(1, 0, 1), p(1, 1, 1), p(0, 1, 1));
      quad(c, p(0, 0, 0.5F), p(0, 1, 0.5F), p(1, 1, 0.5F), p(1, 0, 0.5F));
      quad(c, p(0.5F, 0, -0.5F), p(0.5F, 1, -0.5F), p(0.5F, 1, 0.5F), p(0.5F, 0, 0.5F));
      // adding vertices/polygons sets hint 4 (editable): mode 2, no tree
      expect("mode 2 after editing", NativeScene.getClumpHSMode(c) == 2);
      expect("no tree in mode 2", NativeCamera.sortTreeOf(c) == null);
      NativeScene.setClumpHints(c, 2);
      expect("mode 1 with hints=2", NativeScene.getClumpHSMode(c) == 1);
      int[] t = NativeCamera.sortTreeOf(c);
      int[] want = {0, 2, 3, 1, -1, 1, 1, 1, 1, 0, -1, 1};
      expect("tree " + java.util.Arrays.toString(t) + " != " + java.util.Arrays.toString(want),
         t != null && java.util.Arrays.equals(t, want));
      // moving a vertex (RwSetClumpVertex) goes back to mode 2 and discards the tree
      NativeScene.setVertex(c, 1, 0, 0, 0);
      expect("setVertex -> mode 2", NativeScene.getClumpHSMode(c) == 2 && NativeCamera.sortTreeOf(c) == null);
      NativeScene.setClumpHints(c, 2);
      expect("tree rebuilt", java.util.Arrays.equals(NativeCamera.sortTreeOf(c), want));
      // hints outside 0..7: error 0x30, changes nothing
      NativeScene.setClumpHints(c, 8);
      expect("hints 8 rejected", NativeScene.getClumpHSMode(c) == 1);

      // P0 and P1 alone (two parallel planes facing the same way): P0, P1 without conflict.
      int d = NativeScene.createClump();
      quad(d, p(0, 0, 0), p(1, 0, 0), p(1, 1, 0), p(0, 1, 0));
      quad(d, p(0, 0, 1), p(1, 0, 1), p(1, 1, 1), p(0, 1, 1));
      NativeScene.setClumpHints(d, 2);
      expect("two planes", java.util.Arrays.equals(NativeCamera.sortTreeOf(d), new int[]{0, 1, -1, 2, 0, -1, 0}));

      // More than 1000 polygons: FUN_10033600 adds hint 4 (mode 2, no tree).
      int e = NativeScene.createClump();
      NativeScene.addVertex(e, 0, 0, 0);
      NativeScene.addVertex(e, 1, 0, 0);
      NativeScene.addVertex(e, 0, 1, 0);
      for (int i = 0; i < 1001; i++) {
         NativeScene.addPolygon(e, 3, new int[]{1, 2, 3});
      }
      NativeScene.setClumpHints(e, 2);
      expect(">1000 polygons -> mode 2", NativeScene.getClumpHSMode(e) == 2 && NativeCamera.sortTreeOf(e) == null);

      // UV: 0 <= u,v <= 256 (0x100790fc); outside that, the vertex keeps its own.
      int u = NativeScene.createClump();
      NativeScene.addVertex(u, 0, 0, 0);
      NativeScene.setVertexUV(u, 1, 0.5F, 0.25F);
      float[] uv = NativeScene.getVertexUV(u, 1);
      expect("uv 0.5,0.25 round trip: " + uv[0] + "," + uv[1], uv[0] == 0.5F && uv[1] == 0.25F);
      NativeScene.setVertexUV(u, 1, -0.5F, 0.0F);
      NativeScene.setVertexUV(u, 1, 0.0F, 256.5F);
      NativeScene.setVertexUV(u, 1, 300.0F, 0.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("out-of-range uv rejected: " + uv[0] + "," + uv[1], uv[0] == 0.5F && uv[1] == 0.25F);
      NativeScene.setVertexUV(u, 1, -0.0F, 256.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("-0.0 and 256 accepted: " + uv[0] + "," + uv[1], uv[0] == 0.0F && uv[1] == 256.0F);
      // uvFixed: ftol(t*65536) +0x100 if < 0x10000, -0x100 otherwise.
      expect("uvFixed(0)=0x100", NativeScene.uvFixed(0.0F) == 0x100);
      expect("uvFixed(1)=0xff00", NativeScene.uvFixed(1.0F) == 0xFF00);
      // 0.999: ftol(65470.46) = 65470 + 256 = 65726; the reader adds 0x100
      // (65982, with high bits) and leaves it: 65982/65536 = 1.00680542
      expect("uvFixed(0.999)=65726", NativeScene.uvFixed(0.999F) == 65726);
      NativeScene.setVertexUV(u, 1, 0.999F, 0.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("RwGetClumpVertexUV(0.999) = 1.00680542: " + uv[0], Math.abs(uv[0] - 65982.0F / 65536.0F) < 1.0E-7F);

      if (failures != 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("RasterTreeCheck OK");
   }
}

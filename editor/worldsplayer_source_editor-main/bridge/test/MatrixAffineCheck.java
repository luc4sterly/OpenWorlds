import NET.worlds.core.NativeRw;

/**
 * RwMultiplyMatrix (RWL21.DLL 0x1001db10 -> 0x1005118c) is an AFFINE
 * product: the fourth column of the matrices (elements 3, 7, 11 and 15) is
 * neither read nor written. The Transforms that come from the .world carry
 * RW's internal data there (in the Auditorium's WObject2/ShapeStand:
 * 0x03ddff04 and 0x02890088 read as float, m[15] = 2.0130646e-37), and the
 * earlier 4x4 product lost the parent's translation because of that:
 * everything hanging from a container WObject was drawn at the room origin.
 *
 * Hand-calculated cases: a child with ShapeStand's real matrix under WObject2
 * (24-degree turn and translation (0, 1000, 0)) -> the child's translation is
 * (0, 1000, 0); with clean matrices the result matches the usual 4x4
 * product (same order of sums, bit for bit).
 */
public class MatrixAffineCheck {
   private static int fails;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "ok   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   public static void main(String[] args) {
      float junk7 = Float.intBitsToFloat(0x03ddff04), junk15 = Float.intBitsToFloat(0x02890088);
      // WObject2 (modeling as Transform leaves it in the bridge)
      float[] parent = {0.91354555f, 0.40673667f, 0.0f, -0.0f, -0.40673667f, 0.91354555f, 0.0f, junk7,
         0.0f, 0.0f, 1.0f, -0.0f, 0.0f, 1000.0f, 0.0f, junk15};
      // ShapeStand
      float[] child = {-1.44839405E-5f, -100.00002f, -1.72081E-6f, -0.0f, 3.4228556E-6f, -1.7208107E-6f, 99.99999f, junk7,
         -100.00002f, 1.8298057E-5f, -3.4228542E-6f, 0.58410853f, 0.0f, 0.0f, 0.0f, junk15};
      float[] ltm = new float[16];
      NativeRw.mulInto(child, parent, ltm);
      check(ltm[12] == 0f && ltm[13] == 1000f && ltm[14] == 0f,
         "ShapeStand under WObject2 at (" + ltm[12] + ", " + ltm[13] + ", " + ltm[14] + ") = (0, 1000, 0)");
      check(ltm[3] == 0f && ltm[7] == 0f && ltm[11] == 0f && ltm[15] == 1f, "fourth column of the result (0, 0, 0, 1)");
      // 3x3: the child's row 0 times the parent's rotation
      float want0 = child[0] * parent[0] + child[1] * parent[4] + child[2] * parent[8];
      check(ltm[0] == want0, "element [0][0] = " + ltm[0]);

      // with clean matrices, the same as the usual 4x4
      float[] a = NativeRw.identity();
      NativeRw.rotate(a, 0.3f, 0.5f, 0.8f, 33f, NativeRw.REPLACE);
      NativeRw.translate(a, 12.5f, -7f, 300f, NativeRw.POSTCONCAT);
      float[] b = NativeRw.identity();
      NativeRw.rotate(b, 0f, 0f, 1f, -71f, NativeRw.REPLACE);
      NativeRw.translate(b, -3000f, 45f, 0.25f, NativeRw.POSTCONCAT);
      float[] full = new float[16];
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
            float s = 0f;
            for (int k = 0; k < 4; k++) {
               s += a[i * 4 + k] * b[k * 4 + j];
            }
            full[i * 4 + j] = s;
         }
      }
      float[] got = NativeRw.mul(a, b);
      boolean same = true;
      for (int e = 0; e < 16; e++) {
         same &= Float.floatToIntBits(got[e]) == Float.floatToIntBits(full[e])
            || (got[e] == 0f && full[e] == 0f);
      }
      check(same, "clean matrices: bit for bit the same as the 4x4");

      System.out.println(fails == 0 ? "MatrixAffineCheck: OK" : "MatrixAffineCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

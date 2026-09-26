import NET.worlds.core.NativeRw;

/**
 * RwMultiplyMatrix (RWL21.DLL 0x1001db10 -> 0x1005118c) es un producto
 * AFIN: la cuarta columna de las matrices (elementos 3, 7, 11 y 15) ni se
 * lee ni se escribe. Los Transform que vienen del .world la traen con datos
 * internos de RW (en WObject2/ShapeStand del Auditorium: 0x03ddff04 y
 * 0x02890088 leidos como float, m[15] = 2.0130646e-37), y el producto 4x4
 * de antes perdia con eso la traslacion del padre: todo lo que cuelga de un
 * WObject contenedor se dibujaba en el origen de la sala.
 *
 * Casos a mano: hijo con la matriz real de ShapeStand bajo WObject2
 * (giro de 24 grados y traslacion (0, 1000, 0)) -> la traslacion del hijo es
 * (0, 1000, 0); con matrices limpias el resultado coincide con el producto
 * 4x4 de siempre (mismo orden de sumas, bit a bit).
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
      // WObject2 (modeling tal como lo deja Transform en el puente)
      float[] parent = {0.91354555f, 0.40673667f, 0.0f, -0.0f, -0.40673667f, 0.91354555f, 0.0f, junk7,
         0.0f, 0.0f, 1.0f, -0.0f, 0.0f, 1000.0f, 0.0f, junk15};
      // ShapeStand
      float[] child = {-1.44839405E-5f, -100.00002f, -1.72081E-6f, -0.0f, 3.4228556E-6f, -1.7208107E-6f, 99.99999f, junk7,
         -100.00002f, 1.8298057E-5f, -3.4228542E-6f, 0.58410853f, 0.0f, 0.0f, 0.0f, junk15};
      float[] ltm = new float[16];
      NativeRw.mulInto(child, parent, ltm);
      check(ltm[12] == 0f && ltm[13] == 1000f && ltm[14] == 0f,
         "ShapeStand bajo WObject2 en (" + ltm[12] + ", " + ltm[13] + ", " + ltm[14] + ") = (0, 1000, 0)");
      check(ltm[3] == 0f && ltm[7] == 0f && ltm[11] == 0f && ltm[15] == 1f, "cuarta columna del resultado (0, 0, 0, 1)");
      // 3x3: la fila 0 del hijo por el giro del padre
      float want0 = child[0] * parent[0] + child[1] * parent[4] + child[2] * parent[8];
      check(ltm[0] == want0, "elemento [0][0] = " + ltm[0]);

      // con matrices limpias, igual que el 4x4 de siempre
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
      check(same, "matrices limpias: bit a bit igual que el 4x4");

      System.out.println(fails == 0 ? "MatrixAffineCheck: OK" : "MatrixAffineCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

import NET.worlds.core.NativeCamera;
import NET.worlds.core.NativeScene;

/**
 * Arbol de ordenacion de poligonos de RWL21 (0x10033750 / 0x10033cc0), la
 * maquina de modos de hints (FUN_10033600) y el rango/redondeo de UV de
 * RwSetClumpVertexUV (0x10017de0) / RwGetClumpVertexUV (0x10017f50) en el
 * puente. Casos calculados a mano en los comentarios.
 */
public final class RasterTreeCheck {
   private static int failures;

   private static void expect(String what, boolean ok) {
      if (!ok) {
         System.out.println("FALLA " + what);
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
      // Clump sintetico:
      //  P0 suelo z=0 mirando a +z (normal (0,0,1), dist 0, area 2)
      //  P1 techo z=1 mirando a +z (dist 1): classify(P0,P1) = 1 -> despues de P0
      //  P2 z=0.5 mirando a -z (dist -0.5): cada uno delante del otro -> 3,
      //     se une a la lista de P0
      //  P3 vertical x=0.5, z de -0.5 a 0.5 (normal (1,0,0), dist 0.5):
      //     cruza P0 -> 2 (P0 y P3 en conflicto); contra P2 -> 1; baja al lado
      //     "despues" de P0 (P1), donde classify(P1,P3) = -1 -> P1.back.
      // Lectura en orden: P0 (bandera 1 primero), P2, P3, P1; banderas
      // 1,0,1,0 -> tiradas [1,1,1,1] cerradas por 0, la primera con z.
      int c = NativeScene.createClump();
      quad(c, p(0, 0, 0), p(1, 0, 0), p(1, 1, 0), p(0, 1, 0));
      quad(c, p(0, 0, 1), p(1, 0, 1), p(1, 1, 1), p(0, 1, 1));
      quad(c, p(0, 0, 0.5F), p(0, 1, 0.5F), p(1, 1, 0.5F), p(1, 0, 0.5F));
      quad(c, p(0.5F, 0, -0.5F), p(0.5F, 1, -0.5F), p(0.5F, 1, 0.5F), p(0.5F, 0, 0.5F));
      // anadir vertices/poligonos pone la pista 4 (editable): modo 2, sin arbol
      expect("modo 2 tras editar", NativeScene.getClumpHSMode(c) == 2);
      expect("sin arbol en modo 2", NativeCamera.sortTreeOf(c) == null);
      NativeScene.setClumpHints(c, 2);
      expect("modo 1 con hints=2", NativeScene.getClumpHSMode(c) == 1);
      int[] t = NativeCamera.sortTreeOf(c);
      int[] want = {0, 2, 3, 1, -1, 1, 1, 1, 1, 0, -1, 1};
      expect("arbol " + java.util.Arrays.toString(t) + " != " + java.util.Arrays.toString(want),
         t != null && java.util.Arrays.equals(t, want));
      // mover un vertice (RwSetClumpVertex) vuelve al modo 2 y tira el arbol
      NativeScene.setVertex(c, 1, 0, 0, 0);
      expect("setVertex -> modo 2", NativeScene.getClumpHSMode(c) == 2 && NativeCamera.sortTreeOf(c) == null);
      NativeScene.setClumpHints(c, 2);
      expect("arbol reconstruido", java.util.Arrays.equals(NativeCamera.sortTreeOf(c), want));
      // hints fuera de 0..7: error 0x30, no cambia nada
      NativeScene.setClumpHints(c, 8);
      expect("hints 8 rechazado", NativeScene.getClumpHSMode(c) == 1);

      // P0 y P1 solos (dos planos paralelos mirando igual): P0, P1 sin conflicto.
      int d = NativeScene.createClump();
      quad(d, p(0, 0, 0), p(1, 0, 0), p(1, 1, 0), p(0, 1, 0));
      quad(d, p(0, 0, 1), p(1, 0, 1), p(1, 1, 1), p(0, 1, 1));
      NativeScene.setClumpHints(d, 2);
      expect("dos planos", java.util.Arrays.equals(NativeCamera.sortTreeOf(d), new int[]{0, 1, -1, 2, 0, -1, 0}));

      // Mas de 1000 poligonos: FUN_10033600 anade la pista 4 (modo 2, sin arbol).
      int e = NativeScene.createClump();
      NativeScene.addVertex(e, 0, 0, 0);
      NativeScene.addVertex(e, 1, 0, 0);
      NativeScene.addVertex(e, 0, 1, 0);
      for (int i = 0; i < 1001; i++) {
         NativeScene.addPolygon(e, 3, new int[]{1, 2, 3});
      }
      NativeScene.setClumpHints(e, 2);
      expect(">1000 poligonos -> modo 2", NativeScene.getClumpHSMode(e) == 2 && NativeCamera.sortTreeOf(e) == null);

      // UV: 0 <= u,v <= 256 (0x100790fc); fuera, el vertice conserva la suya.
      int u = NativeScene.createClump();
      NativeScene.addVertex(u, 0, 0, 0);
      NativeScene.setVertexUV(u, 1, 0.5F, 0.25F);
      float[] uv = NativeScene.getVertexUV(u, 1);
      expect("uv 0.5,0.25 ida y vuelta: " + uv[0] + "," + uv[1], uv[0] == 0.5F && uv[1] == 0.25F);
      NativeScene.setVertexUV(u, 1, -0.5F, 0.0F);
      NativeScene.setVertexUV(u, 1, 0.0F, 256.5F);
      NativeScene.setVertexUV(u, 1, 300.0F, 0.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("uv fuera de rango rechazadas: " + uv[0] + "," + uv[1], uv[0] == 0.5F && uv[1] == 0.25F);
      NativeScene.setVertexUV(u, 1, -0.0F, 256.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("-0.0 y 256 aceptadas: " + uv[0] + "," + uv[1], uv[0] == 0.0F && uv[1] == 256.0F);
      // uvFixed: ftol(t*65536) +0x100 si < 0x10000, -0x100 si no.
      expect("uvFixed(0)=0x100", NativeScene.uvFixed(0.0F) == 0x100);
      expect("uvFixed(1)=0xff00", NativeScene.uvFixed(1.0F) == 0xFF00);
      // 0.999: ftol(65470.46) = 65470 + 256 = 65726; el lector suma 0x100
      // (65982, con bits altos) y lo deja: 65982/65536 = 1.00680542
      expect("uvFixed(0.999)=65726", NativeScene.uvFixed(0.999F) == 65726);
      NativeScene.setVertexUV(u, 1, 0.999F, 0.0F);
      uv = NativeScene.getVertexUV(u, 1);
      expect("RwGetClumpVertexUV(0.999) = 1.00680542: " + uv[0], Math.abs(uv[0] - 65982.0F / 65536.0F) < 1.0E-7F);

      if (failures != 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("RasterTreeCheck OK");
   }
}

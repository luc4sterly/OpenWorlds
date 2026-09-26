package net.freeworlds.render;

/**
 * DriverLight: la luz del driver del original (bridge NativeCamera.light y
 * buildRamp, NativeScene.flatShading) con casos calculados a mano.
 *
 * <ul>
 * <li>Luces de sala por defecto (Room.java): vector (-1, 1, -1) blanco y el
 *     opuesto a la mitad; color 255/256 = 0.99609375.</li>
 * <li>Suelo (normal 0,0,1) con ambiente 0.3 y difusa 0.8, objeto sin
 *     transformar: d1 = 1/sqrt(3) = 0.5773503, la segunda luz no llega
 *     (d2 < 0): I = 31*0.3 + 31*0.99609375*0.8*0.5773503 = 9.3 + 14.262434
 *     = 23.562434 -> fila 23.</li>
 * <li>Rampa (FUN_10008d00): fila 23 (x = 0.741935 < 0.75) con la componente
 *     31: (63616 >> 8) * (64962 >> 8) = 248 * 253 = 62744 -> >> 11 = 30;
 *     componente 16: 128 * 253 = 32384 -> 15; fila 31 con 31 -> 0xffff -> 31
 *     -> tope 30; fila 0 con 0 -> 0 -> 1 (el 0 es el transparente).</li>
 * <li>Escala no uniforme (Rect de 2149 x 2 x 400): la luz va al espacio del
 *     objeto con la INVERSA, (1, -1, 1) -> (1/2149, -1/2, 1/400), y se
 *     normaliza: (0.00093, -0.99998, 0.005); con la normal (0, -1, 0),
 *     d = 0.999984 (el coseno en el mundo seria 0.577).</li>
 * </ul>
 */
public class DriverLightCheck {
   private static int fails;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "ok   " : "FAIL ") + what);
      if (!ok) {
         fails++;
      }
   }

   static void near(double got, double want, double tol, String what) {
      boolean ok = Math.abs(got - want) <= tol;
      check(ok, what + " = " + got + (ok ? "" : " (esperado " + want + ")"));
   }

   public static void main(String[] args) {
      // FUN_00417950: auto-iluminado solo con ambiente en (0.7421875, 0.7578125) y sin difusa ni especular
      check(DriverLight.selfLit(0.75f, 0f, 0f), "selfLit(0.75, 0, 0)");
      check(!DriverLight.selfLit(0.5f, 0f, 0f), "!selfLit(0.5, 0, 0)");
      check(!DriverLight.selfLit(0.75f, 0.1f, 0f), "!selfLit(0.75, 0.1, 0)");
      check(!DriverLight.selfLit(0.7421875f, 0f, 0f), "!selfLit(0.7421875, 0, 0) (limite estricto)");

      // RAMP, valores a mano (ver javadoc)
      check(DriverLight.RAMP[23 * 32 + 31] == 30, "RAMP[23][31] = 30");
      check(DriverLight.RAMP[23 * 32 + 16] == 15, "RAMP[23][16] = 15");
      check(DriverLight.RAMP[31 * 32 + 31] == 30, "RAMP[31][31] = 30 (tope 0x1e)");
      check(DriverLight.RAMP[0] == 1, "RAMP[0][0] = 1 (0 reservado)");

      // suelo con la luz por defecto
      DriverLight.room(null, 0xFFFFFF);
      float[] i = new float[3];
      DriverLight.intensity(0.3f, 0.8f, 0f, 0f, 0f, 1f, i);
      near(i[0], 23.562434, 1e-4, "intensidad del suelo (canal r)");
      check(DriverLight.row(i[0]) == 23, "fila 23");
      float[] out = new float[3];
      DriverLight.rampColor(1f, 1f, 1f, i, out);
      near(out[0], 30 / 31.0, 1e-6, "blanco en la fila 23 (r = 30/31)");
      near(out[1], 60 / 63.0, 1e-6, "blanco en la fila 23 (g de 6 bits = 60/63)");
      float[] p = new float[3], s = new float[3];
      DriverLight.rampFactors(i, p, s);
      near(p[0], (23 / 31.0) / 0.75, 1e-6, "P de la fila 23 = x/0.75");
      near(s[0], 0, 0, "S de la fila 23 = 0");
      float[] full = {31f, 31f, 31f};
      DriverLight.rampFactors(full, p, s);
      near(p[0], 0, 1e-6, "P de la fila 31 = 0");
      near(s[0], 32 / 31.0, 1e-6, "S de la fila 31 = 32/31");

      // techo: solo la luz de relleno (mitad), d2 = 1/sqrt(3)
      DriverLight.intensity(0f, 1f, 0f, 0f, 0f, -1f, i);
      near(i[0], 31 * 0.498046875 * 0.5773503, 1e-4, "techo: solo la segunda luz");

      // especular: d > 0.7 suma spec * (floor(256 d)/256)^16; normal hacia la luz, d = 1
      float[] toLight = {0.57735026f, -0.57735026f, 0.57735026f};
      DriverLight.intensity(0f, 0f, 1f, toLight[0], toLight[1], toLight[2], i);
      near(i[0], 31 * 0.99609375 * Math.pow(255 / 256.0, 16), 2e-3, "especular con d = 1 (entrada 256 = (255/256)^16)");

      // escala no uniforme: la inversa y luego normalizar
      float[] wall = {2149, 0, 0, 0, 0, 2, 0, 0, 0, 0, 400, 0, 0, 0, 0, 1};
      DriverLight.object(wall);
      DriverLight.intensity(0f, 1f, 0f, 0f, -1f, 0f, i);
      double lx = 1 / 2149.0, ly = -1 / 2.0, lz = 1 / 400.0, len = Math.sqrt(lx * lx + ly * ly + lz * lz);
      near(i[0], 31 * 0.99609375 * (-ly / len), 1e-3, "pared escalada: d = 0.999984, no 0.577");

      // normal de poligono (RWL21 0x10001100): la del Rect y una degenerada
      float[] n = DriverLight.polygonNormal(new float[][]{{0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {0, 0, 1}});
      check(n[0] == 0f && n[1] == -1f && n[2] == 0f, "normal del Rect = (0,-1,0)");
      n = DriverLight.polygonNormal(new float[][]{{0, 0, 0}, {1, 0, 0}, {2, 0, 0}});
      check(n[0] == 0f && n[1] == 0f && n[2] == 0f, "poligono degenerado = (0,0,0)");

      // la clave de las display lists cambia con la orientacion, no con la traslacion
      DriverLight.object(new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
      long k0 = DriverLight.objectKey();
      DriverLight.object(new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 500, 900, 3, 1});
      check(DriverLight.objectKey() == k0, "clave igual con otra traslacion");
      DriverLight.object(new float[]{0, 1, 0, 0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
      check(DriverLight.objectKey() != k0, "clave distinta girado 90 grados");

      System.out.println(fails == 0 ? "DriverLightCheck: todo OK" : "DriverLightCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

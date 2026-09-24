package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/**
 * VehicleShape (gamma.dll 0x0043f4c0-0x0043f580) sobre NativeSysVehicle:
 * constantes leídas del binario, una caja real de NativeScene con las
 * cuentas hechas a mano (cm -> pies, caja de inercia m/12, ruedas en las
 * esquinas de la cara z mínima) y la rama "Zero-volume" con su cubo de 10
 * pies. Sale con 1 si algo falla.
 */
public final class SysVehicleCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // DAT_00477d88 = 1/30.48 (pies por cm) y DAT_00477dd8 = 1/12 en float
      check("DAT_00477d88 = 1/30.48", Math.abs(NativeSysVehicle.FEET_PER_CM - 1.0 / 30.48) < 1e-17);
      check("DAT_00477dd8 = (float) 1/12", NativeSysVehicle.ONE_TWELFTH == (float) (1.0 / 12.0));

      ByteArrayOutputStream buf = new ByteArrayOutputStream();
      NativeSysVehicle.out = new PrintStream(buf, true);

      // Caja de 2 x 5 x 0.5 pies: (-30.48, -60.96, 0) .. (30.48, 91.44, 15.24) cm
      // en un clump real (FUN_00418900 = origen de la LTM + RwGetClumpBBox).
      int c = NativeScene.createClump();
      NativeScene.addVertex(c, -30.48F, -60.96F, 0.0F);
      NativeScene.addVertex(c, 30.48F, 91.44F, 15.24F);
      NativeSysVehicle.analyzeShape(c, 100.0F);
      // centro: ((max+min)/2) / 30.48 = (0, 15.24/30.48, 7.62/30.48) = (0, 0.5, 0.25)
      near("cog x", NativeSysVehicle.cog(0), 0.0);
      near("cog y", NativeSysVehicle.cog(1), 0.5);
      near("cog z", NativeSysVehicle.cog(2), 0.25);
      // lados Y=5, Z=0.5, X=2; masa/12 = 8.33333: X = 8.3333*(25+0.25), Y = 8.3333*(0.25+4), Z = 8.3333*(4+25)
      near("moi x", NativeSysVehicle.moi(0), 100.0 / 12.0 * 25.25);
      near("moi y", NativeSysVehicle.moi(1), 100.0 / 12.0 * 4.25);
      near("moi z", NativeSysVehicle.moi(2), 100.0 / 12.0 * 29.0);
      // ruedas: x = -1 / 1, y = 3 - 0.5 = 2.5 / -2 - 0.5 = -2.5, z = 0 - 0.25
      double[][] want = {{-1, 2.5, -0.25}, {1, 2.5, -0.25}, {-1, -2.5, -0.25}, {1, -2.5, -0.25}};
      for (int i = 0; i < 4; i++) {
         for (int a = 0; a < 3; a++) {
            near("rueda " + i + " eje " + a, NativeSysVehicle.tire(i, a), want[i][a]);
         }
      }
      String log = buf.toString();
      check("sin cubo de 10 pies", !log.contains("Zero-volume"));
      check("analizada", log.startsWith("Vehicle shape analyzed.\n"));
      check("línea del centro", log.contains("Center of gravity: 0.00, 0.50, 0.25\n"));
      check("línea del tensor", log.contains("Inertial tensor: 210.41"));
      check("rueda 2", log.contains("Tire position 2: -1.00, -2.50, -0.25\n"));

      // lo mismo trasladado 30.48 cm en z: solo el centro y la rueda se mueven con la caja,
      // pero el origen de la LTM (0,0,30.48) queda dentro de la caja y no la agranda
      float[] t = NativeRw.identity();
      NativeRw.translate(t, 0.0F, 0.0F, 30.48F, NativeRw.REPLACE);
      NativeScene.transformClump(c, t, NativeRw.REPLACE);
      NativeSysVehicle.analyzeShape(c, 100.0F);
      near("cog z trasladado", NativeSysVehicle.cog(2), 1.25);
      near("rueda z trasladada (relativa al centro)", NativeSysVehicle.tire(0, 2), -0.25);
      near("moi y igual", NativeSysVehicle.moi(1), 100.0 / 12.0 * 4.25);

      // Volumen cero: un solo punto en (30.48, 0, 0) -> lados 0 -> cubo de 10 pies
      buf.reset();
      NativeSysVehicle.analyzeBox(30.48F, 0.0F, 0.0F, 30.48F, 0.0F, 0.0F, 12.0F);
      log = buf.toString();
      check("aviso de volumen cero", log.startsWith("Zero-volume vehicle shape, modeling 10x10x10 cube.\nVehicle shape analyzed.\n"));
      near("cog x = 1 pie", NativeSysVehicle.cog(0), 1.0);
      check("cog y = 0", NativeSysVehicle.cog(1) == 0.0F);
      // 12 * (float)1/12 = 1.0000000298; * (100 + 100) = 200.00000596 -> float 200.0 exacto
      check("moi = 200.0f exacto", NativeSysVehicle.moi(0) == 200.0F && NativeSysVehicle.moi(1) == 200.0F && NativeSysVehicle.moi(2) == 200.0F);
      check("línea del tensor exacta", log.contains("Inertial tensor: 200.000000 200.000000 200.000000\n"));
      check("rueda x ~ 0", Math.abs(NativeSysVehicle.tire(3, 0)) < 1e-6);
      check("rueda y, z = 0", NativeSysVehicle.tire(3, 1) == 0.0F && NativeSysVehicle.tire(3, 2) == 0.0F);

      // un solo lado nulo basta (0x0043f5f1..0x0043f62b: tres comparaciones con 0.0)
      buf.reset();
      NativeSysVehicle.analyzeBox(0.0F, 0.0F, 0.0F, 30.48F, 30.48F, 0.0F, 12.0F);
      check("z nulo -> cubo", buf.toString().startsWith("Zero-volume"));
      near("cog con cubo", NativeSysVehicle.cog(0), 0.5);
      check("moi del cubo", NativeSysVehicle.moi(2) == 200.0F);

      // índice fuera de 0..3
      boolean threw = false;
      try {
         NativeSysVehicle.tire(4, 0);
      } catch (ArrayIndexOutOfBoundsException e) {
         threw = true;
      }
      check("rueda 4", threw);

      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("SysVehicleCheck OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void near(String what, float got, double want) {
      check(what + ": " + got + " != " + want, Math.abs(got - want) <= 1e-5 * Math.max(1.0, Math.abs(want)));
   }
}

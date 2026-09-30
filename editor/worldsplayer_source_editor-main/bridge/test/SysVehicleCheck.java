package NET.worlds.core;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

/**
 * VehicleShape (gamma.dll 0x0043f4c0-0x0043f580) over NativeSysVehicle:
 * constants read from the binary, a real NativeScene box with the
 * calculations done by hand (cm -> feet, inertia box m/12, tires at the
 * corners of the minimum-z face) and the "Zero-volume" branch with its
 * 10-foot cube. Exits with 1 if anything fails.
 */
public final class SysVehicleCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // DAT_00477d88 = 1/30.48 (feet per cm) and DAT_00477dd8 = 1/12 as float
      check("DAT_00477d88 = 1/30.48", Math.abs(NativeSysVehicle.FEET_PER_CM - 1.0 / 30.48) < 1e-17);
      check("DAT_00477dd8 = (float) 1/12", NativeSysVehicle.ONE_TWELFTH == (float) (1.0 / 12.0));

      ByteArrayOutputStream buf = new ByteArrayOutputStream();
      NativeSysVehicle.out = new PrintStream(buf, true);

      // Box of 2 x 5 x 0.5 feet: (-30.48, -60.96, 0) .. (30.48, 91.44, 15.24) cm
      // in a real clump (FUN_00418900 = LTM origin + RwGetClumpBBox).
      int c = NativeScene.createClump();
      NativeScene.addVertex(c, -30.48F, -60.96F, 0.0F);
      NativeScene.addVertex(c, 30.48F, 91.44F, 15.24F);
      NativeSysVehicle.analyzeShape(c, 100.0F);
      // center: ((max+min)/2) / 30.48 = (0, 15.24/30.48, 7.62/30.48) = (0, 0.5, 0.25)
      near("cog x", NativeSysVehicle.cog(0), 0.0);
      near("cog y", NativeSysVehicle.cog(1), 0.5);
      near("cog z", NativeSysVehicle.cog(2), 0.25);
      // sides Y=5, Z=0.5, X=2; mass/12 = 8.33333: X = 8.3333*(25+0.25), Y = 8.3333*(0.25+4), Z = 8.3333*(4+25)
      near("moi x", NativeSysVehicle.moi(0), 100.0 / 12.0 * 25.25);
      near("moi y", NativeSysVehicle.moi(1), 100.0 / 12.0 * 4.25);
      near("moi z", NativeSysVehicle.moi(2), 100.0 / 12.0 * 29.0);
      // tires: x = -1 / 1, y = 3 - 0.5 = 2.5 / -2 - 0.5 = -2.5, z = 0 - 0.25
      double[][] want = {{-1, 2.5, -0.25}, {1, 2.5, -0.25}, {-1, -2.5, -0.25}, {1, -2.5, -0.25}};
      for (int i = 0; i < 4; i++) {
         for (int a = 0; a < 3; a++) {
            near("tire " + i + " axis " + a, NativeSysVehicle.tire(i, a), want[i][a]);
         }
      }
      String log = buf.toString();
      check("no 10-foot cube", !log.contains("Zero-volume"));
      check("analyzed", log.startsWith("Vehicle shape analyzed.\n"));
      check("center line", log.contains("Center of gravity: 0.00, 0.50, 0.25\n"));
      check("tensor line", log.contains("Inertial tensor: 210.41"));
      check("tire 2", log.contains("Tire position 2: -1.00, -2.50, -0.25\n"));

      // the same translated 30.48 cm in z: only the center and the tire move with the box,
      // but the LTM origin (0,0,30.48) stays inside the box and does not enlarge it
      float[] t = NativeRw.identity();
      NativeRw.translate(t, 0.0F, 0.0F, 30.48F, NativeRw.REPLACE);
      NativeScene.transformClump(c, t, NativeRw.REPLACE);
      NativeSysVehicle.analyzeShape(c, 100.0F);
      near("cog z translated", NativeSysVehicle.cog(2), 1.25);
      near("tire z translated (relative to the center)", NativeSysVehicle.tire(0, 2), -0.25);
      near("moi y unchanged", NativeSysVehicle.moi(1), 100.0 / 12.0 * 4.25);

      // Zero volume: a single point at (30.48, 0, 0) -> sides 0 -> 10-foot cube
      buf.reset();
      NativeSysVehicle.analyzeBox(30.48F, 0.0F, 0.0F, 30.48F, 0.0F, 0.0F, 12.0F);
      log = buf.toString();
      check("zero-volume warning", log.startsWith("Zero-volume vehicle shape, modeling 10x10x10 cube.\nVehicle shape analyzed.\n"));
      near("cog x = 1 foot", NativeSysVehicle.cog(0), 1.0);
      check("cog y = 0", NativeSysVehicle.cog(1) == 0.0F);
      // 12 * (float)1/12 = 1.0000000298; * (100 + 100) = 200.00000596 -> float 200.0 exactly
      check("moi = 200.0f exactly", NativeSysVehicle.moi(0) == 200.0F && NativeSysVehicle.moi(1) == 200.0F && NativeSysVehicle.moi(2) == 200.0F);
      check("exact tensor line", log.contains("Inertial tensor: 200.000000 200.000000 200.000000\n"));
      check("tire x ~ 0", Math.abs(NativeSysVehicle.tire(3, 0)) < 1e-6);
      check("tire y, z = 0", NativeSysVehicle.tire(3, 1) == 0.0F && NativeSysVehicle.tire(3, 2) == 0.0F);

      // a single zero side is enough (0x0043f5f1..0x0043f62b: three comparisons with 0.0)
      buf.reset();
      NativeSysVehicle.analyzeBox(0.0F, 0.0F, 0.0F, 30.48F, 30.48F, 0.0F, 12.0F);
      check("zero z -> cube", buf.toString().startsWith("Zero-volume"));
      near("cog with cube", NativeSysVehicle.cog(0), 0.5);
      check("cube moi", NativeSysVehicle.moi(2) == 200.0F);

      // index outside 0..3
      boolean threw = false;
      try {
         NativeSysVehicle.tire(4, 0);
      } catch (ArrayIndexOutOfBoundsException e) {
         threw = true;
      }
      check("tire 4", threw);

      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("SysVehicleCheck OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void near(String what, float got, double want) {
      check(what + ": " + got + " != " + want, Math.abs(got - want) <= 1e-5 * Math.max(1.0, Math.abs(want)));
   }
}

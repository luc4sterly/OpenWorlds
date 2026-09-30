package NET.worlds.core;

import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Locale;

/**
 * {@code NET.worlds.scape.VehicleShape}: the analysis of a vehicle's
 * shape (gamma.dll 0x0043f580) and its nine reads (0x0043f4c0-0x0043f570).
 * The result lives in .bss globals (0x0049def8-0x0049df3c, zeroed when the
 * DLL is loaded) shared by all vehicles: each read returns
 * the result of the last analysis.
 *
 * <p>nativeAnalyzeShape(clump, mass):
 * <ol>
 * <li>clump 0 -> assertion "nVehicleShape" line 0x46.</li>
 * <li>Box of the clump's tree in the world (FUN_00418900, the same as
 *     {@code NativeAnimator.treeBox}), in cm.</li>
 * <li>Sides in feet: {@code (max - min) * DAT_00477d88} (double
 *     0.03280839895013123 = 1/30.48) stored as float, in the order
 *     Y, Z, X ([ebp-0x48], [ebp-0x44], [ebp-0x40]). If any is 0.0
 *     (DAT_00477d90), printf "Zero-volume vehicle shape, modeling 10x10x10
 *     cube.\n" and all three become 10.0 (DAT_00477dc8).</li>
 * <li>Center of gravity: {@code (max + min) * 0.5} (DAT_00477dd0, double)
 *     stored as float and then {@code * DAT_00477d88}, float again.</li>
 * <li>Squares stored as float and sums of two, also float:
 *     Y²+Z², Z²+X², X²+Y²; if a sum is 0.0, assertion 0x5b / 0x5c / 0x5d
 *     (unreachable after step 3).</li>
 * <li>Moments of inertia of a box: {@code mass * DAT_00477dd8} (float
 *     1/12, 0x3daaaaab) left unrounded, times each sum, rounded to
 *     float.</li>
 * <li>Tires at the four corners of the minimum-z face, relative to the
 *     center: 0 = (xmin, ymax), 1 = (xmax, ymax), 2 = (xmin, ymin),
 *     3 = (xmax, ymin); each coordinate {@code v * DAT_00477d88 - cog}.</li>
 * <li>printf of "Vehicle shape analyzed.\n", the center ("%.2f"), the tensor
 *     ("%f") and the four tires ("%.2f") (0x00477ddc-0x00477ea8).</li>
 * </ol>
 *
 * <p>Precision: the x87 operates at the MSVC CRT's precision (53 bits by
 * default), which is Java's double arithmetic; values are rounded to float
 * exactly where the binary does {@code fstp dword}. ⚠️ VERIFY that
 * nothing changes the x87 precision on this thread (RWL21 loads the control
 * word in CRT routines, e.g. {@code fldcw} at 0x1004e905, without
 * checking who calls them); with 24 or 64 bits some result might
 * differ in the last bit.
 *
 * <p>The CRT's printf writes to the process's descriptor 1, not to the
 * {@code System.out} that {@code LogFile} redirects to the log.
 */
public final class NativeSysVehicle {
   /** DAT_00477d88 (double, bytes 33 c4 0c 31 43 cc a0 3f): feet per cm. */
   static final double FEET_PER_CM = Double.longBitsToDouble(0x3fa0cc43310cc433L);
   /** DAT_00477dd0 (double). */
   static final double HALF = 0.5;
   /** DAT_00477dc8 (float): side of the 10-foot cube. */
   static final float ZERO_VOLUME_SIDE = 10.0F;
   /** DAT_00477dd8 (float, bytes ab aa aa 3d): 1/12 of a box's moment. */
   static final float ONE_TWELFTH = Float.intBitsToFloat(0x3daaaaab);

   /** 0x0049def8, 0x0049defc, 0x0049df00. */
   static final float[] cog = new float[3];
   /** 0x0049df04, 0x0049df08, 0x0049df0c. */
   static final float[] moi = new float[3];
   /** 0x0049df10 + i * 0xc: {x, y, z} of tires 0..3. */
   static final float[] tires = new float[12];

   static PrintStream out = new PrintStream(new FileOutputStream(FileDescriptor.out), true);

   private NativeSysVehicle() {
   }

   /** nativeAnalyzeShape (0x0043f580). */
   public static synchronized void analyzeShape(int clump, float mass) {
      if (clump == 0) {
         NativeAssert.fail("nVehicleShape", 0x46);
      }
      float[] b = NativeAnimator.treeBox(clump);
      analyzeBox(b[0], b[1], b[2], b[3], b[4], b[5], mass);
   }

   /** Everything that follows FUN_00418900 at 0x0043f5b2, on the already measured box (cm). */
   static synchronized void analyzeBox(float minX, float minY, float minZ, float maxX, float maxY, float maxZ, float mass) {
      float sideY = (float) (((double) maxY - minY) * FEET_PER_CM);
      float sideZ = (float) (((double) maxZ - minZ) * FEET_PER_CM);
      float sideX = (float) (((double) maxX - minX) * FEET_PER_CM);
      if (sideY == 0.0F || sideZ == 0.0F || sideX == 0.0F) {
         out.print("Zero-volume vehicle shape, modeling 10x10x10 cube.\n");
         sideY = sideZ = sideX = ZERO_VOLUME_SIDE;
      }
      float cogX = (float) ((float) (((double) maxX + minX) * HALF) * FEET_PER_CM);
      float cogY = (float) ((float) (((double) maxY + minY) * HALF) * FEET_PER_CM);
      float cogZ = (float) ((float) (((double) maxZ + minZ) * HALF) * FEET_PER_CM);
      float zz = (float) ((double) sideZ * sideZ);
      float yy = (float) ((double) sideY * sideY);
      float aboutX = (float) ((double) yy + zz);
      if (aboutX == 0.0F) {
         NativeAssert.fail("nVehicleShape", 0x5b);
      }
      float xx = (float) ((double) sideX * sideX);
      float aboutY = (float) ((double) zz + xx);
      if (aboutY == 0.0F) {
         NativeAssert.fail("nVehicleShape", 0x5c);
      }
      float aboutZ = (float) ((double) xx + yy);
      if (aboutZ == 0.0F) {
         NativeAssert.fail("nVehicleShape", 0x5d);
      }
      double m = (double) mass * ONE_TWELFTH;
      float moiX = (float) (m * aboutX);
      float moiY = (float) (m * aboutY);
      float moiZ = (float) (m * aboutZ);
      float x0 = (float) (minX * FEET_PER_CM - cogX);
      float x1 = (float) (maxX * FEET_PER_CM - cogX);
      float yMax = (float) (maxY * FEET_PER_CM - cogY);
      float yMin = (float) (minY * FEET_PER_CM - cogY);
      float z = (float) (minZ * FEET_PER_CM - cogZ);
      float[] t = {x0, yMax, z, x1, yMax, z, x0, yMin, z, x1, yMin, z};
      System.arraycopy(t, 0, tires, 0, 12);
      cog[0] = cogX;
      cog[1] = cogY;
      cog[2] = cogZ;
      moi[0] = moiX;
      moi[1] = moiY;
      moi[2] = moiZ;
      out.print("Vehicle shape analyzed.\n");
      out.print(String.format(Locale.ROOT, "Center of gravity: %.2f, %.2f, %.2f\n", (double) cogX, (double) cogY, (double) cogZ));
      out.print(String.format(Locale.ROOT, "Inertial tensor: %f %f %f\n", (double) moiX, (double) moiY, (double) moiZ));
      for (int i = 0; i < 4; i++) {
         out.print(String.format(Locale.ROOT, "Tire position %d: %.2f, %.2f, %.2f\n", i, (double) tires[i * 3], (double) tires[i * 3 + 1], (double) tires[i * 3 + 2]));
      }
   }

   /** nativeGetCogX/Y/Z (0x0043f520/530/540): the center of gravity in feet. */
   public static synchronized float cog(int axis) {
      return cog[axis];
   }

   /** nativeGetMoiX/Y/Z (0x0043f550/560/570): the moments of inertia (slug·ft²). */
   public static synchronized float moi(int axis) {
      return moi[axis];
   }

   /**
    * nativeGetTirePosX/Y/Z (0x0043f4c0/4e0/500): {@code DAT_0049df10 + i*0xc
    * + 0/4/8}, without checking the index (outside 0..3 the original reads
    * other globals; here Java's index exception is thrown). The client only
    * asks for 0..3 (VehicleShape.prerender).
    */
   public static synchronized float tire(int i, int axis) {
      if (i < 0 || i > 3) {
         throw new ArrayIndexOutOfBoundsException(i);
      }
      return tires[i * 3 + axis];
   }
}

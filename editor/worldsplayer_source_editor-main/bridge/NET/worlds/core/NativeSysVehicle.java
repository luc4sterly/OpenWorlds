package NET.worlds.core;

import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Locale;

/**
 * {@code NET.worlds.scape.VehicleShape}: el análisis de la forma de un
 * vehículo (gamma.dll 0x0043f580) y sus nueve lecturas (0x0043f4c0-0x0043f570).
 * El resultado vive en globales de .bss (0x0049def8-0x0049df3c, a cero al
 * cargar la DLL) compartidas por todos los vehículos: cada lectura devuelve
 * lo del último análisis.
 *
 * <p>nativeAnalyzeShape(clump, masa):
 * <ol>
 * <li>clump 0 -> aserción "nVehicleShape" línea 0x46.</li>
 * <li>Caja del árbol del clump en el mundo (FUN_00418900, la misma que
 *     {@code NativeAnimator.treeBox}), en cm.</li>
 * <li>Lados en pies: {@code (max - min) * DAT_00477d88} (double
 *     0.03280839895013123 = 1/30.48) guardados como float, en el orden
 *     Y, Z, X ([ebp-0x48], [ebp-0x44], [ebp-0x40]). Si alguno es 0.0
 *     (DAT_00477d90), printf "Zero-volume vehicle shape, modeling 10x10x10
 *     cube.\n" y los tres pasan a 10.0 (DAT_00477dc8).</li>
 * <li>Centro de gravedad: {@code (max + min) * 0.5} (DAT_00477dd0, double)
 *     guardado como float y luego {@code * DAT_00477d88}, otra vez float.</li>
 * <li>Cuadrados guardados como float y sumas de dos, también float:
 *     Y²+Z², Z²+X², X²+Y²; si una suma es 0.0, aserción 0x5b / 0x5c / 0x5d
 *     (inalcanzable tras el paso 3).</li>
 * <li>Momentos de inercia de una caja: {@code masa * DAT_00477dd8} (float
 *     1/12, 0x3daaaaab) sin redondear, por cada suma, a float.</li>
 * <li>Ruedas en las cuatro esquinas de la cara z mínima, relativas al
 *     centro: 0 = (xmin, ymax), 1 = (xmax, ymax), 2 = (xmin, ymin),
 *     3 = (xmax, ymin); cada coordenada {@code v * DAT_00477d88 - cog}.</li>
 * <li>printf de "Vehicle shape analyzed.\n", el centro ("%.2f"), el tensor
 *     ("%f") y las cuatro ruedas ("%.2f") (0x00477ddc-0x00477ea8).</li>
 * </ol>
 *
 * <p>Precisión: el x87 opera con la precisión del CRT de MSVC (53 bits por
 * defecto), que es la aritmética double de Java; se redondea a float
 * exactamente donde el binario hace {@code fstp dword}. ⚠️ VERIFICAR que
 * nada cambie la precisión del x87 en este hilo (RWL21 carga la palabra de
 * control en rutinas del CRT, p. ej. {@code fldcw} en 0x1004e905, sin
 * comprobar quién las llama); con 24 o 64 bits algún resultado podría
 * diferir en el último bit.
 *
 * <p>El printf del CRT escribe en el descriptor 1 del proceso, no en el
 * {@code System.out} que {@code LogFile} redirige al log.
 */
public final class NativeSysVehicle {
   /** DAT_00477d88 (double, bytes 33 c4 0c 31 43 cc a0 3f): pies por cm. */
   static final double FEET_PER_CM = Double.longBitsToDouble(0x3fa0cc43310cc433L);
   /** DAT_00477dd0 (double). */
   static final double HALF = 0.5;
   /** DAT_00477dc8 (float): lado del cubo de 10 pies. */
   static final float ZERO_VOLUME_SIDE = 10.0F;
   /** DAT_00477dd8 (float, bytes ab aa aa 3d): 1/12 del momento de una caja. */
   static final float ONE_TWELFTH = Float.intBitsToFloat(0x3daaaaab);

   /** 0x0049def8, 0x0049defc, 0x0049df00. */
   static final float[] cog = new float[3];
   /** 0x0049df04, 0x0049df08, 0x0049df0c. */
   static final float[] moi = new float[3];
   /** 0x0049df10 + i * 0xc: {x, y, z} de las ruedas 0..3. */
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

   /** Todo lo que sigue a FUN_00418900 en 0x0043f5b2, sobre la caja ya medida (cm). */
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

   /** nativeGetCogX/Y/Z (0x0043f520/530/540): el centro de gravedad en pies. */
   public static synchronized float cog(int axis) {
      return cog[axis];
   }

   /** nativeGetMoiX/Y/Z (0x0043f550/560/570): los momentos de inercia (slug·ft²). */
   public static synchronized float moi(int axis) {
      return moi[axis];
   }

   /**
    * nativeGetTirePosX/Y/Z (0x0043f4c0/4e0/500): {@code DAT_0049df10 + i*0xc
    * + 0/4/8}, sin comprobar el índice (fuera de 0..3 el original lee otras
    * globales; aquí salta la excepción de índice de Java). El cliente solo
    * pide 0..3 (VehicleShape.prerender).
    */
   public static synchronized float tire(int i, int axis) {
      if (i < 0 || i > 3) {
         throw new ArrayIndexOutOfBoundsException(i);
      }
      return tires[i * 3 + axis];
   }
}

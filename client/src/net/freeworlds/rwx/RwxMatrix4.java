package net.freeworlds.rwx;

/**
 * 4x4 matrix matching three.js's Matrix4 conventions exactly (verified by
 * reading three-rwx-loader's source, not assumed - see
 * docs/rwx-format-reference.md): column-major storage (e[0..3]=column 0,
 * e[4..7]=column 1, ...), `multiply(m)` means `this = this * m`, and
 * points are transformed as `v' = M * v` (v as a column vector). The raw
 * 16 values of an RWX `Transform` command are loaded directly into this
 * layout via fromColumnMajor16 (matches Matrix4.fromArray in three.js,
 * which is why "Transform" and "Rotate/Translate/Scale" need different
 * loaders here - see RwxParser).
 */
public final class RwxMatrix4 {
   public final float[] e = new float[16];

   private RwxMatrix4() {
   }

   public static RwxMatrix4 identity() {
      RwxMatrix4 r = new RwxMatrix4();
      r.e[0] = 1;
      r.e[5] = 1;
      r.e[10] = 1;
      r.e[15] = 1;
      return r;
   }

   /** Raw 16 values as they appear in an RWX `Transform` line, column-major (matches Matrix4.fromArray). */
   public static RwxMatrix4 fromColumnMajor16(float[] v) {
      RwxMatrix4 r = new RwxMatrix4();
      System.arraycopy(v, 0, r.e, 0, 16);
      return r;
   }

   public static RwxMatrix4 makeTranslation(float x, float y, float z) {
      RwxMatrix4 r = identity();
      r.e[12] = x;
      r.e[13] = y;
      r.e[14] = z;
      return r;
   }

   public static RwxMatrix4 makeScale(float x, float y, float z) {
      RwxMatrix4 r = identity();
      r.e[0] = x;
      r.e[5] = y;
      r.e[10] = z;
      return r;
   }

   public static RwxMatrix4 makeRotationX(double radians) {
      RwxMatrix4 r = identity();
      double c = Math.cos(radians);
      double s = Math.sin(radians);
      r.e[5] = (float) c;
      r.e[6] = (float) s;
      r.e[9] = (float) -s;
      r.e[10] = (float) c;
      return r;
   }

   public static RwxMatrix4 makeRotationY(double radians) {
      RwxMatrix4 r = identity();
      double c = Math.cos(radians);
      double s = Math.sin(radians);
      r.e[0] = (float) c;
      r.e[2] = (float) -s;
      r.e[8] = (float) s;
      r.e[10] = (float) c;
      return r;
   }

   public static RwxMatrix4 makeRotationZ(double radians) {
      RwxMatrix4 r = identity();
      double c = Math.cos(radians);
      double s = Math.sin(radians);
      r.e[0] = (float) c;
      r.e[1] = (float) s;
      r.e[4] = (float) -s;
      r.e[5] = (float) c;
      return r;
   }

   /** this * other (three.js Matrix4#multiply(m) semantics: this = this * m). */
   public RwxMatrix4 multiply(RwxMatrix4 other) {
      RwxMatrix4 r = new RwxMatrix4();
      float[] a = this.e;
      float[] b = other.e;
      for (int col = 0; col < 4; col++) {
         for (int row = 0; row < 4; row++) {
            float sum = 0f;
            for (int k = 0; k < 4; k++) {
               sum += a[k * 4 + row] * b[col * 4 + k];
            }
            r.e[col * 4 + row] = sum;
         }
      }
      return r;
   }

   /** v' = M * v (column vector), with a homogeneous W divide for full correctness. */
   public RwxVector3 transformPoint(RwxVector3 v) {
      float x = e[0] * v.x + e[4] * v.y + e[8] * v.z + e[12];
      float y = e[1] * v.x + e[5] * v.y + e[9] * v.z + e[13];
      float z = e[2] * v.x + e[6] * v.y + e[10] * v.z + e[14];
      float w = e[3] * v.x + e[7] * v.y + e[11] * v.z + e[15];
      if (w != 0f && w != 1f) {
         x /= w;
         y /= w;
         z /= w;
      }
      return new RwxVector3(x, y, z);
   }
}

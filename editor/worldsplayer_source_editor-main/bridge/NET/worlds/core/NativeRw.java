package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * Portable subset of the RenderWare 2.1 API that gamma.dll's scape natives
 * sit on (RWL21.DLL), reimplemented in Java so the decompiled client can
 * run without Windows. Only what the natives actually call, with the
 * semantics verified in the binaries (docs/seq-animation-reference.md s5):
 *
 * - Matrices are 4x4, row-major, ROW-vector convention (v' = v.M) with the
 *   translation in row 3 (RWL21.DLL 0x1005118c product, 0x1001c89a
 *   RwTranslateMatrix writes +0x30/+0x34/+0x38).
 * - Combine modes (common routine 0x1001c500): 1 = replace,
 *   2 = dest = X.dest (pre-concat), 3 = dest = dest.X (post-concat).
 *
 * Handles are 1-based ints standing in for the RW pointers the natives
 * store in Java int fields (transformID, clumpID, ...); 0 = null.
 */
public final class NativeRw {
   private NativeRw() {
   }

   public static final int REPLACE = 1;
   public static final int PRECONCAT = 2;
   public static final int POSTCONCAT = 3;

   // ------------------------------------------------------------ handles

   private static final List<Object> objects = new ArrayList<Object>();
   private static final List<Integer> free = new ArrayList<Integer>();

   static synchronized int alloc(Object o) {
      if (!free.isEmpty()) {
         int h = free.remove(free.size() - 1);
         objects.set(h - 1, o);
         return h;
      }
      objects.add(o);
      return objects.size();
   }

   static synchronized Object get(int h) {
      return h > 0 && h <= objects.size() ? objects.get(h - 1) : null;
   }

   static synchronized void release(int h) {
      if (h > 0 && h <= objects.size() && objects.get(h - 1) != null) {
         objects.set(h - 1, null);
         free.add(h);
      }
   }

   // ------------------------------------------------------------ matrices

   public static float[] identity() {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
   }

   /** RwCreateMatrix: a new identity matrix. */
   public static int createMatrix() {
      return alloc(identity());
   }

   /** RwDestroyMatrix. */
   public static void destroyMatrix(int h) {
      release(h);
   }

   public static float[] matrix(int h) {
      Object o = get(h);
      return o instanceof float[] ? (float[]) o : null;
   }

   /** out[i][j] = sum_k a[i][k] * b[k][j] (RWL21.DLL 0x1005118c). */
   public static float[] mul(float[] a, float[] b) {
      float[] o = new float[16];
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
            float s = 0f;
            for (int k = 0; k < 4; k++) {
               s += a[i * 4 + k] * b[k * 4 + j];
            }
            o[i * 4 + j] = s;
         }
      }
      return o;
   }

   /** a.b written into out (out must not alias a or b): mul() without the allocation. */
   public static void mulInto(float[] a, float[] b, float[] out) {
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
            float s = 0f;
            for (int k = 0; k < 4; k++) {
               s += a[i * 4 + k] * b[k * 4 + j];
            }
            out[i * 4 + j] = s;
         }
      }
   }

   /** Common combine routine 0x1001c500: writes the result into dest. */
   public static void combine(float[] dest, float[] x, int mode) {
      float[] r;
      if (mode == REPLACE) {
         r = x;
      } else if (mode == PRECONCAT) {
         r = mul(x, dest);
      } else {
         r = mul(dest, x);
      }
      System.arraycopy(r, 0, dest, 0, 16);
   }

   /** RwTranslateMatrix(m, x, y, z, mode). */
   public static void translate(float[] m, float x, float y, float z, int mode) {
      float[] t = identity();
      t[12] = x;
      t[13] = y;
      t[14] = z;
      combine(m, t, mode);
   }

   /** RwScaleMatrix(m, sx, sy, sz, mode). */
   public static void scale(float[] m, float sx, float sy, float sz, int mode) {
      float[] s = identity();
      s[0] = sx;
      s[5] = sy;
      s[10] = sz;
      combine(m, s, mode);
   }

   /**
    * RwRotateMatrix(m, x, y, z, angleDegrees, mode). Rotation about the
    * normalized axis by angle degrees, written for row vectors (the
    * transpose of the column-vector Rodrigues matrix).
    * Verified against RWL21.DLL 0x1001de70 -> 0x1001cb20: degrees, axis
    * normalized, R[0] = {c+t*x*x, t*x*y+s*z, t*x*z-s*y}, ...
    */
   public static void rotate(float[] m, float x, float y, float z, float angleDeg, int mode) {
      combine(m, rotation(x, y, z, angleDeg), mode);
   }

   static float[] rotation(float x, float y, float z, float angleDeg) {
      float len = (float) Math.sqrt(x * x + y * y + z * z);
      if (len == 0f) {
         return identity();
      }
      x /= len;
      y /= len;
      z /= len;
      double a = Math.toRadians(angleDeg);
      float c = (float) Math.cos(a);
      float s = (float) Math.sin(a);
      float t = 1f - c;
      float[] r = identity();
      // column-vector Rodrigues R_col, stored transposed (row vectors)
      r[0] = c + x * x * t;
      r[1] = x * y * t + z * s;
      r[2] = x * z * t - y * s;
      r[4] = x * y * t - z * s;
      r[5] = c + y * y * t;
      r[6] = y * z * t + x * s;
      r[8] = x * z * t + y * s;
      r[9] = y * z * t - x * s;
      r[10] = c + z * z * t;
      return r;
   }

   /** RwTransformMatrix(dest, x, mode). */
   public static void transformMatrix(float[] dest, float[] x, int mode) {
      combine(dest, x.clone(), mode);
   }

   /**
    * RwInvertMatrix(src, dst) (RWL21.DLL 0x1001dbc0): affine inverse. The
    * 3x3 part is adjugate/determinant (left undivided when det == 0, no
    * error); dst row 3 = -(t . A); column 3 = (0,0,0,1); src column 3 is
    * ignored. src must not alias dst.
    */
   public static void invert(float[] src, float[] dst) {
      float[] m = src;
      float[] a = new float[9];
      a[0] = m[5] * m[10] - m[6] * m[9];
      a[1] = m[2] * m[9] - m[1] * m[10];
      a[2] = m[1] * m[6] - m[2] * m[5];
      a[3] = m[6] * m[8] - m[4] * m[10];
      a[4] = m[0] * m[10] - m[2] * m[8];
      a[5] = m[2] * m[4] - m[0] * m[6];
      a[6] = m[4] * m[9] - m[5] * m[8];
      a[7] = m[1] * m[8] - m[0] * m[9];
      a[8] = m[0] * m[5] - m[1] * m[4];
      float det = a[0] * m[0] + a[3] * m[1] + a[6] * m[2];
      if (det != 0.0F) {
         float inv = 1.0F / det;
         for (int i = 0; i < 9; i++) {
            a[i] *= inv;
         }
      }
      float tx = m[12], ty = m[13], tz = m[14];
      for (int r = 0; r < 3; r++) {
         dst[r * 4] = a[r * 3];
         dst[r * 4 + 1] = a[r * 3 + 1];
         dst[r * 4 + 2] = a[r * 3 + 2];
         dst[r * 4 + 3] = 0.0F;
      }
      for (int j = 0; j < 3; j++) {
         dst[12 + j] = -(tx * a[j] + ty * a[3 + j] + tz * a[6 + j]);
      }
      dst[15] = 1.0F;
   }

   private static float[] row(float[] m, int r) {
      return new float[]{m[r * 4], m[r * 4 + 1], m[r * 4 + 2]};
   }

   private static float[] norm(float[] v) {
      float l = (float) Math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
      return l > 0.0F ? new float[]{v[0] / l, v[1] / l, v[2] / l} : new float[]{0, 0, 0};
   }

   private static float[] cross(float[] a, float[] b) {
      return new float[]{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
   }

   private static float dot(float[] a, float[] b) {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
   }

   /**
    * RwOrthoNormalizeMatrix(src, dst) (RWL21.DLL 0x1001db80 -> 0x1001c150):
    * normalize rows 0..2, then rebuild two of them by cross products from
    * the most orthogonal pair. Returns a new matrix.
    */
   public static float[] orthoNormalize(float[] src) {
      float[] r0 = row(src, 0), r1 = row(src, 1), r2 = row(src, 2);
      float l0 = (float) Math.sqrt(dot(r0, r0)), l1 = (float) Math.sqrt(dot(r1, r1)), l2 = (float) Math.sqrt(dot(r2, r2));
      r0 = norm(r0);
      r1 = norm(r1);
      r2 = norm(r2);
      float a = Math.abs(dot(r1, r2)), b = Math.abs(dot(r2, r0)), c = Math.abs(dot(r0, r1));
      int branch;
      if (l0 <= 0.0F) {
         branch = 0;
      } else if (l1 <= 0.0F) {
         branch = 1;
      } else if (l2 <= 0.0F) {
         branch = 2;
      } else if (b > a && c > a) {
         branch = 0;
      } else if (b < a && b < c) {
         branch = 1;
      } else {
         branch = 2;
      }
      if (branch == 0) {
         r0 = norm(cross(r1, r2));
         r2 = norm(cross(r0, r1));
      } else if (branch == 1) {
         r1 = norm(cross(r2, r0));
         r0 = norm(cross(r1, r2));
      } else {
         r2 = norm(cross(r0, r1));
         r1 = norm(cross(r2, r0));
      }
      float[] d = new float[16];
      float[][] rows = {r0, r1, r2};
      for (int r = 0; r < 3; r++) {
         System.arraycopy(rows[r], 0, d, r * 4, 3);
      }
      System.arraycopy(src, 12, d, 12, 4);
      return d;
   }

   /**
    * RwQueryRotateMatrix(m, axis, angle, centre) (RWL21.DLL 0x1001e060):
    * returns {axisX, axisY, axisZ, angleDegrees}. The centre output is not
    * used by any caller in gamma.dll's Transform natives and is omitted.
    */
   public static float[] queryRotate(float[] m) {
      float[] v = {m[6] - m[9], m[8] - m[2], m[1] - m[4]};
      float len = (float) Math.sqrt(dot(v, v));
      float tr1 = m[0] + m[5] + m[10] - 1.0F;
      float[] axis = norm(v);
      float angle = (float) (Math.atan2(len, tr1) * 57.29578);
      if (len <= 0.01F && tr1 <= 0.0F) {
         if (m[0] >= m[5] && m[0] >= m[10]) {
            axis = norm(new float[]{2.0F * (m[0] + 1.0F), m[1] + m[4], m[2] + m[8]});
         } else if (m[5] >= m[10]) {
            axis = norm(new float[]{m[1] + m[4], 2.0F * (m[5] + 1.0F), m[6] + m[9]});
         } else {
            axis = norm(new float[]{m[2] + m[8], m[6] + m[9], 2.0F * (m[10] + 1.0F)});
         }
      }
      return new float[]{axis[0], axis[1], axis[2], angle};
   }

   /** RwTransformPoint: p.M with translation. */
   public static float[] transformPoint(float[] m, float x, float y, float z) {
      return new float[]{
         x * m[0] + y * m[4] + z * m[8] + m[12],
         x * m[1] + y * m[5] + z * m[9] + m[13],
         x * m[2] + y * m[6] + z * m[10] + m[14]};
   }

   /** RwTransformVector: v.M without translation. */
   public static float[] transformVector(float[] m, float x, float y, float z) {
      return new float[]{
         x * m[0] + y * m[4] + z * m[8],
         x * m[1] + y * m[5] + z * m[9],
         x * m[2] + y * m[6] + z * m[10]};
   }
}

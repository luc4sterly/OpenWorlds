package net.freeworlds.world;

/**
 * Cruce de un Portal como en el cliente original: si el portal esta
 * conectado, el paso del piloto por su borde inferior y la transformacion
 * portal-a-portal (_p2pxform) que lleva posicion y orientacion a la sala
 * de enfrente.
 *
 * Matrices: float[16] con la misma disposicion que WNode.matrix y que las
 * de RenderWare 2.1 (filas, vector fila v' = v.M, traslacion en 12..14;
 * RWL21.DLL 0x1005118c). Los modos de combinacion son los de RWL21
 * 0x1001c500: PRE = X.dest, POST = dest.X. Las operaciones RW que hacen
 * falta estan traducidas aqui con la misma semantica que
 * editor/.../bridge/NET/worlds/core/NativeRw.java.
 *
 * Reglas, con su fuente:
 * - Estado: un Portal cruza solo en estado 2 (Portal.portalBumpHandler).
 *   Con referencia al portal lejano, postRestore -&gt; newFarSide -&gt;
 *   estado 2 salvo flag 0x40000; sin ella, reset(): sin farSideRoomName o
 *   con 0x40000, estado -1; en el mismo mundo busca la sala por nombre y
 *   en ella el portal por nombre (findFarSidePortal) o, en modo posicion
 *   (farSideIsPortal = false), usa farx/fary/farz/fartheta del fichero;
 *   con farSideWorld, carga ese mundo (World.load -&gt; loadedURLSelf).
 * - Deteccion: WObject.detectBump solo mira hijos con getBumpable()
 *   (flags bit 1); Portal.getBumpCalc da PassthroughBumpCalc, que corta el
 *   camino del piloto contra el borde inferior del portal
 *   (posicion + (1,0,1).M, solo x/y) con BumpEventTemp.isCollision: solo
 *   se cruza de un lado (el camino a la izquierda del borde, es decir
 *   hacia +Y local).
 * - Transformacion: Portal.setTransform (gamma.dll 0x0041b170) y
 *   recomputeFarPosition (Portal.java) con getYaw (gamma.dll 0x00425440).
 * - Tras el cruce (Portal.portalBumpHandler, WObject.moveThrough): el
 *   piloto avanza hasta el punto de corte mas 0.2 en la direccion del
 *   movimiento (BumpEventTemp.hitPlane), se le aplica _p2pxform
 *   (postBumpPosition.post) y el resto del camino, fullPath*(1-fraccion),
 *   se transforma como vector (postBumpPath).
 */
public final class PortalLink {
   private PortalLink() {
   }

   private static final int PRE = 2;
   private static final int POST = 3;

   // ------------------------------------------------------------ RW 2.1

   static float[] identity() {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
   }

   /** out[i][j] = sum_k a[i][k] * b[k][j] (RWL21.DLL 0x1005118c). */
   static float[] mul(float[] a, float[] b) {
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

   /** Combinacion comun de RWL21 0x1001c500 (2 = X.dest, 3 = dest.X). */
   private static void combine(float[] dest, float[] x, int mode) {
      float[] r = mode == PRE ? mul(x, dest) : mul(dest, x);
      System.arraycopy(r, 0, dest, 0, 16);
   }

   private static void scale(float[] m, float sx, float sy, float sz, int mode) {
      float[] s = identity();
      s[0] = sx;
      s[5] = sy;
      s[10] = sz;
      combine(m, s, mode);
   }

   private static void translate(float[] m, float x, float y, float z, int mode) {
      float[] t = identity();
      t[12] = x;
      t[13] = y;
      t[14] = z;
      combine(m, t, mode);
   }

   /** RwRotateMatrix (RWL21 0x1001de70 -&gt; 0x1001cb20): grados, eje normalizado, para vector fila. */
   private static void rotate(float[] m, float x, float y, float z, float angleDeg, int mode) {
      float len = (float) Math.sqrt(x * x + y * y + z * z);
      float[] r = identity();
      if (len != 0f) {
         x /= len;
         y /= len;
         z /= len;
         double a = Math.toRadians(angleDeg);
         float c = (float) Math.cos(a);
         float s = (float) Math.sin(a);
         float t = 1f - c;
         r[0] = c + x * x * t;
         r[1] = x * y * t + z * s;
         r[2] = x * z * t - y * s;
         r[4] = x * y * t - z * s;
         r[5] = c + y * y * t;
         r[6] = y * z * t + x * s;
         r[8] = x * z * t + y * s;
         r[9] = y * z * t - x * s;
         r[10] = c + z * z * t;
      }
      combine(m, r, mode);
   }

   /** RwInvertMatrix (RWL21 0x1001dbc0): inversa afin por adjunta (sin dividir si det == 0). */
   static float[] invert(float[] m) {
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
      if (det != 0f) {
         float inv = 1f / det;
         for (int i = 0; i < 9; i++) {
            a[i] *= inv;
         }
      }
      float[] d = new float[16];
      for (int r = 0; r < 3; r++) {
         d[r * 4] = a[r * 3];
         d[r * 4 + 1] = a[r * 3 + 1];
         d[r * 4 + 2] = a[r * 3 + 2];
      }
      for (int j = 0; j < 3; j++) {
         d[12 + j] = -(m[12] * a[j] + m[13] * a[3 + j] + m[14] * a[6 + j]);
      }
      d[15] = 1f;
      return d;
   }

   private static float[] row(float[] m, int r) {
      return new float[]{m[r * 4], m[r * 4 + 1], m[r * 4 + 2]};
   }

   private static float dot(float[] a, float[] b) {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
   }

   private static float[] norm(float[] v) {
      float l = (float) Math.sqrt(dot(v, v));
      return l > 0f ? new float[]{v[0] / l, v[1] / l, v[2] / l} : new float[]{0, 0, 0};
   }

   private static float[] cross(float[] a, float[] b) {
      return new float[]{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
   }

   /** RwOrthoNormalizeMatrix (RWL21 0x1001db80 -&gt; 0x1001c150). */
   static float[] orthoNormalize(float[] src) {
      float[] r0 = row(src, 0), r1 = row(src, 1), r2 = row(src, 2);
      float l0 = (float) Math.sqrt(dot(r0, r0)), l1 = (float) Math.sqrt(dot(r1, r1)), l2 = (float) Math.sqrt(dot(r2, r2));
      r0 = norm(r0);
      r1 = norm(r1);
      r2 = norm(r2);
      float a = Math.abs(dot(r1, r2)), b = Math.abs(dot(r2, r0)), c = Math.abs(dot(r0, r1));
      int branch;
      if (l0 <= 0f) {
         branch = 0;
      } else if (l1 <= 0f) {
         branch = 1;
      } else if (l2 <= 0f) {
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

   /** RwTransformPoint: p.M con traslacion. */
   public static float[] transformPoint(float[] m, float x, float y, float z) {
      return new float[]{
         x * m[0] + y * m[4] + z * m[8] + m[12],
         x * m[1] + y * m[5] + z * m[9] + m[13],
         x * m[2] + y * m[6] + z * m[10] + m[14]};
   }

   /** RwTransformVector (y Point3Temp.vectorTimes, gamma.dll 0x0041ace0): v.M sin traslacion. */
   public static float[] transformVector(float[] m, float x, float y, float z) {
      return new float[]{
         x * m[0] + y * m[4] + z * m[8],
         x * m[1] + y * m[5] + z * m[9],
         x * m[2] + y * m[6] + z * m[10]};
   }

   // ------------------------------------------------------------ gamma.dll

   /**
    * Transform.getYaw (gamma.dll 0x00425440): rumbo del eje local +Y en
    * grados, 0 = Norte (+Y), en sentido horario, en [0, 360). Copia la
    * matriz (RwCopyMatrix), deshace la escala propia con RwScaleMatrix
    * modo 2 = pre (FUN_00418b10) por 1/xScale, 1/yScale, 1/zScale (1.0 de
    * DAT_00471bf4), ortonormaliza (FUN_00419890), transforma el vector
    * (0,1,0) (DAT_00471bf8/bfc/c00 = 0, 1, 0) como vector (FUN_0041a0b0 =
    * RwTransformVector) y con r = |(vx,vy)|: si -r &lt; vx &lt; r,
    * yaw = 180 * (0.5*pi - atan2(f, sqrt(1-f*f))) * (1/pi) con f = vx/r
    * (180 en DAT_00471c14, 0.5 en DAT_00471c18, 1/pi en DAT_00471c20);
    * si vx &lt;= -r, 180; si no, 0 (DAT_00471c10). Si vy &lt; 0 cambia de
    * signo; resultado 90 - yaw (DAT_00471c28), +360 (DAT_00471c2c) si
    * queda negativo. Constantes leidas de la seccion .data del binario
    * (ImageBase 0x00400000). Vertical (r = 0): 90.
    */
   public static float getYaw(float[] m, float xScale, float yScale, float zScale) {
      float[] c = m.clone();
      scale(c, 1.0F / xScale, 1.0F / yScale, 1.0F / zScale, PRE);
      float[] n = orthoNormalize(c);
      float[] v = transformVector(n, 0.0F, 1.0F, 0.0F);
      float r = (float) Math.sqrt(v[0] * v[0] + v[1] * v[1]);
      float yaw;
      if (v[0] < r) {
         if (-r < v[0]) {
            double f = v[0] / r;
            double a = Math.atan2(f, Math.sqrt(1.0 - f * f));
            yaw = (float) (180.0F * (float) (0.5 * Math.PI - a) * (1.0 / Math.PI));
         } else {
            yaw = 180.0F;
         }
      } else {
         yaw = 0.0F;
      }
      if (v[1] < 0.0F) {
         yaw = -yaw;
      }
      yaw = 90.0F - yaw;
      if (yaw < 0.0F) {
         yaw += 360.0F;
      }
      return yaw;
   }

   /**
    * Portal.recomputeFarPosition: {farx, fary, farz, fartheta} a partir
    * del Transform PROPIO del portal lejano (getPosition, vectorTimes y
    * getYaw son de su matriz local): posicion + (1,0,1).M en x/y salvo que
    * el portal de ESTE lado sea espejo (flags bit 2), y
    * fartheta = (-getYaw() + 180) % 360 (resto de Java, puede ser negativo).
    */
   public static float[] recomputeFarPosition(WNode far, boolean nearMirror) {
      float[] m = far.matrix;
      float[] off = transformVector(m, 1.0F, 0.0F, 1.0F);
      float x = m[12], y = m[13], z = m[14];
      if (!nearMirror) {
         x += off[0];
         y += off[1];
      }
      float theta = (-getYaw(m, far.xScale, far.yScale, far.zScale) + 180.0F) % 360.0F;
      return new float[]{x, y, z, theta};
   }

   /**
    * Portal.setTransform (gamma.dll 0x0041b170): _p2pxform =
    * inversa(LTM del clump del portal con su escala propia deshecha:
    * RwScaleMatrix pre por 1/escala, FUN_00418b10 con 1.0 de DAT_004708a8;
    * RwInvertMatrix, FUN_00419860); si es espejo (flags &amp; 4) se niegan
    * los elementos 0, 4, 8 y 12 (y el 15 se deja en 1); despues
    * RwRotateMatrix(eje (0,0,1), fartheta, post) (FUN_00418ad0, 0 y 1 de
    * DAT_004708ac/a8) y RwTranslateMatrix(farx, fary, farz, post)
    * (FUN_00418d60).
    */
   public static float[] p2pTransform(float[] nearLtm, float xScale, float yScale, float zScale, boolean mirror,
         float farx, float fary, float farz, float fartheta) {
      float[] s = nearLtm.clone();
      scale(s, 1.0F / xScale, 1.0F / yScale, 1.0F / zScale, PRE);
      float[] m = invert(s);
      if (mirror) {
         m[0] = -m[0];
         m[4] = -m[4];
         m[8] = -m[8];
         m[12] = -m[12];
         if (m[15] != 1.0F) {
            m[15] = 1.0F;
         }
      }
      rotate(m, 0.0F, 0.0F, 1.0F, fartheta, POST);
      translate(m, farx, fary, farz, POST);
      return m;
   }

   /**
    * BumpEventTemp.isCollision(start, dir, sourceAt, path) en 2D (x/y): la
    * fraccion del camino en la que corta el segmento start..start+dir, o
    * -1 si el camino no va hacia la izquierda del segmento (lado que no
    * cruza) y -2 si va hacia ese lado pero no lo corta. Mismo calculo en
    * double que el original.
    */
   public static float isCollision(float sx, float sy, float dx, float dy, float px, float py, float mx, float my) {
      double d = (double) mx * -dy + (double) my * dx;
      if (d > 0.0) {
         float rx = px - sx;
         float ry = py - sy;
         double along = (double) rx * dy - (double) ry * dx;
         double seg = (double) rx * my - (double) mx * ry;
         return seg >= 0.0 && seg <= d && along >= 0.0 && along <= d ? (float) (along / d) : -2.0F;
      }
      return -1.0F;
   }

   /**
    * El piloto ya cruzado: {x, y, z, rumbo} en la sala de destino. p0 es
    * la posicion antes del movimiento, (mx,my,mz) el movimiento del frame,
    * f la fraccion de isCollision y fwd el vector de avance del piloto;
    * rumbo = atan2 del avance transformado por la parte lineal de p2p
    * (el piloto entero se multiplica por _p2pxform).
    */
   public static float[] cross(float[] p2p, float[] p0, float mx, float my, float mz, float f, float[] fwd) {
      float len = (float) Math.sqrt(mx * mx + my * my + mz * mz);
      float hx = p0[0] + mx * f, hy = p0[1] + my * f, hz = p0[2] + mz * f;
      if (len > 0f) {
         hx += mx / len * 0.2F;
         hy += my / len * 0.2F;
         hz += mz / len * 0.2F;
      }
      float[] pos = transformPoint(p2p, hx, hy, hz);
      float[] rest = transformVector(p2p, mx * (1f - f), my * (1f - f), mz * (1f - f));
      float[] dir = transformVector(p2p, fwd[0], fwd[1], fwd[2]);
      return new float[]{pos[0] + rest[0], pos[1] + rest[1], pos[2] + rest[2],
         (float) Math.atan2(dir[1], dir[0])};
   }
}

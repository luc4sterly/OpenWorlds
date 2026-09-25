package net.freeworlds.avatar;

/**
 * El movimiento de un avatar en el motor de animacion de gamma.dll:
 *
 * <ul>
 * <li>el objeto de 0x50 bytes del animador (+0x00, FUN_004313b0, vtable
 *     0x4750d0) que mide cuanto se ha desplazado en horizontal entre dos
 *     posiciones y hacia donde; lo consume update;</li>
 * <li>{@link State}: la estructura de 0x38 bytes del Rep (+4, creada en
 *     FUN_004350c0) con la maquina de estados de los implicitos
 *     (FUN_00434670).</li>
 * </ul>
 *
 * Cuaterniones como float[4] (w, x, y, z); vectores float[3].
 *
 * Portado al cliente propio (2026-09-25) desde el puente
 * (editor/.../bridge/NET/worlds/core/AnimMotion.java), que es la traduccion
 * verificada con bridge/test/Animator*Check.java; aqui solo cambia el paquete.
 */
public final class AnimMotion {
   /** +0x04 (vtable [0] FUN_00431650): ya tiene posicion. */
   boolean hasPos;
   /** +0x0c..+0x14. */
   final float[] pos = new float[3];
   /** +0x18: identidad al crear (FUN_00428f10). */
   float[] quat = {1f, 0f, 0f, 0f};
   /** +0x2c, +0x34, +0x40: los tres se crean con la hora actual (FUN_004279e0). */
   AnimTime time;
   AnimTime dt;
   AnimTime lastUpdate;
   /** +0x3c: 1 hacia delante, 2 hacia atras (vtable [10] FUN_004316d0). */
   int direction;
   /** +0x48: distancia con signo; update la lee y la pone a 0 (vtable [11] FUN_004316e0). */
   float distance;
   /** +0x4c: distancia sin signo (vtable [12] FUN_004316f0). */
   float speed;

   AnimMotion(AnimTime now) {
      this.time = now;
      this.dt = now;
      this.lastUpdate = now;
   }

   /** Maximo de dt entre dos posiciones: {10 s, 0} (DAT_0049dd7c, inicializado en 0x4343f0). */
   static final AnimTime MAX_DT = new AnimTime(10, 0);

   /**
    * FUN_00432a30 (desde moveto/moveby): solo se toma la posicion si es la
    * primera (+0x2c == {0,0}) o si el tiempo cambia y cambia la posicion o
    * la orientacion (FUN_00428eb0: |dot - 1| &gt;= 0.0005). dt = ahora -
    * anterior, limitado a {10 s} con la comparacion sin signo
    * FUN_00427b70 (un dt "negativo" tambien se queda en 10 s).
    */
   void offer(float[] p, float[] q, AnimTime t) {
      boolean take = true;
      if (!this.time.same(AnimTime.ZERO)) {
         boolean changed = false;
         if (!this.time.same(t)) {
            boolean moved = true;
            if (this.pos[0] == p[0] && this.pos[1] == p[1] && this.pos[2] == p[2]) {
               if (!notEqual(this.quat, q)) {
                  moved = false;
               }
            }
            changed = moved;
         }
         take = changed;
      }
      if (take) {
         AnimTime d = t.minus(this.time);
         if (MAX_DT.less(d)) {
            d = MAX_DT;
         }
         this.set(p, q, t, d);
      }
   }

   /**
    * FUN_00431440 (vtable [1]): guarda posicion, orientacion y tiempos; la
    * distancia es la parte horizontal del desplazamiento (se quita la
    * componente sobre el eje Z, DAT_0049dce8 = (0,0,1)). Si en el sistema
    * local del avatar (desplazamiento girado por la inversa de q,
    * FUN_00429170 + FUN_004291c0) la y es &lt;= 0 (DAT_00475070) va hacia
    * atras (+0x3c = 2) y la distancia se niega. La primera vez el
    * desplazamiento es 0.
    */
   void set(float[] p, float[] q, AnimTime t, AnimTime d) {
      float[] old = this.hasPos ? this.pos.clone() : p;
      this.hasPos = true;
      this.pos[0] = p[0];
      this.pos[1] = p[1];
      this.pos[2] = p[2];
      this.quat = q.clone();
      this.time = t;
      this.dt = d;
      float dx = this.pos[0] - old[0];
      float dy = this.pos[1] - old[1];
      float dz = this.pos[2] - old[2];
      float up = dz;
      dz = dz - up;
      float len2 = dz * dz + dx * dx + dy * dy;
      this.speed = len2 < 0f ? Float.NaN : (float) Math.sqrt(len2);
      this.distance = this.speed;
      float[] local = rotate(new float[]{q[0], -q[1], -q[2], -q[3]}, new float[]{dx, dy, dz});
      if (local[1] <= 0f) {
         this.direction = 2;
         this.distance = -this.distance;
      } else {
         this.direction = 1;
      }
   }

   /** vtable [11] FUN_004316e0: devuelve la distancia y la pone a 0. */
   float takeDistance() {
      float d = this.distance;
      this.distance = 0f;
      return d;
   }

   // ------------------------------------------------------------- estado de implicitos

   /** La estructura de 0x38 bytes del Rep (+4). */
   static final class State {
      /** +0x04..+0x0c. */
      final float[] pos = new float[3];
      /** +0x10: identidad (FUN_00428f10). */
      float[] quat = {1f, 0f, 0f, 0f};
      /** +0x24: hora de creacion (FUN_004279e0). */
      AnimTime time;
      /** +0x2c: implicito elegido (1). */
      int state = 1;
      /** +0x30: hora del ultimo cambio ({0,0} = aun no hay). */
      AnimTime lastChange = AnimTime.ZERO;

      State(AnimTime now) {
         this.time = now;
      }

      /** DAT_004754e0..ec: {3, 3, 2, 1} por [misma posicion * 2 + misma orientacion]. */
      static final int[] MOTION = {3, 3, 2, 1};
      static final AnimTime WAIT_AFTER_STILL = new AnimTime(10, 0);
      static final AnimTime WAIT_LENGTH = new AnimTime(30, 0);
      static final AnimTime ENDWAIT_LENGTH = new AnimTime(10, 0);

      /**
       * FUN_004351b0 / FUN_004352f0 (la parte del Rep): la primera vez
       * (+0x30 == {0,0}) apunta la hora y elige 1; si no, FUN_00434670.
       * Luego guarda posicion, orientacion y hora.
       */
      int moved(float[] p, float[] q, AnimTime t) {
         if (this.lastChange.same(AnimTime.ZERO)) {
            this.lastChange = t;
            this.state = 1;
         } else {
            this.state = this.next(p, q, t);
         }
         System.arraycopy(p, 0, this.pos, 0, 3);
         this.quat = q.clone();
         this.time = t;
         return this.state;
      }

      /**
       * FUN_00434670: m = 3 si se ha movido, 2 si solo ha girado (dot de
       * orientaciones fuera de 1 +- 0.0005), 1 si esta quieto.
       * 1 (recien parado): gira -&gt; 2, anda -&gt; 3, 10 s quieto -&gt; 4.
       * 2 (girando): quieto -&gt; 1, anda -&gt; 3.
       * 3 (andando): quieto -&gt; 4, gira -&gt; 2.
       * 4 (wait): gira -&gt; 2, anda -&gt; 3, 30 s -&gt; 5.
       * 5 (endwait): gira -&gt; 2, anda -&gt; 3, 10 s -&gt; 4.
       * Otro estado -&gt; 1. Cada cambio apunta la hora (+0x30).
       */
      int next(float[] p, float[] q, AnimTime t) {
         int samePos = p[0] == this.pos[0] && p[1] == this.pos[1] && p[2] == this.pos[2] ? 1 : 0;
         int sameQuat = notEqual(q, this.quat) ? 0 : 1;
         int m = MOTION[samePos * 2 + sameQuat];
         switch (this.state) {
            case 1:
               if (m == 2 || m == 3) {
                  this.lastChange = t;
                  return m;
               }
               if (this.lastChange.plus(WAIT_AFTER_STILL).lessOrEqual(t)) {
                  this.lastChange = t;
                  return 4;
               }
               return 1;
            case 2:
               if (m == 1 || m == 3) {
                  this.lastChange = t;
                  return m;
               }
               return 2;
            case 3:
               if (m == 1) {
                  this.lastChange = t;
                  return 4;
               }
               if (m == 2) {
                  this.lastChange = t;
                  return 2;
               }
               return 3;
            case 4:
               if (m == 2 || m == 3) {
                  this.lastChange = t;
                  return m;
               }
               if (this.lastChange.plus(WAIT_LENGTH).lessOrEqual(t)) {
                  this.lastChange = t;
                  return 5;
               }
               return 4;
            case 5:
               if (m == 2 || m == 3) {
                  this.lastChange = t;
                  return m;
               }
               if (this.lastChange.plus(ENDWAIT_LENGTH).lessOrEqual(t)) {
                  this.lastChange = t;
                  return 4;
               }
               return 5;
            default:
               return 1;
         }
      }
   }

   // ------------------------------------------------------------- matematicas

   /**
    * FUN_00428eb0 (distinto) = !FUN_00428e60: |dot(a, b) - 1| &lt; 0.0005
    * (DAT_00473414 = 1, DAT_00473418 = 0.0005) es "igual"; dot en el orden
    * z, y, w, x de FUN_00429090.
    */
   static boolean notEqual(float[] a, float[] b) {
      double dot = (double) a[3] * b[3] + (double) a[2] * b[2] + (double) a[0] * b[0] + (double) a[1] * b[1];
      float diff = Math.abs((float) (dot - 1.0));
      return !(diff < 0.0005F);
   }

   /**
    * FUN_00428f40: cuaternion de eje y angulo (radianes): (cos(a/2),
    * eje * sin(a/2)) (DAT_00473420 = 0.5) y normalizado (FUN_00429070).
    */
   static float[] axisAngle(float x, float y, float z, float angle) {
      double h = (double) angle * 0.5;
      float s = (float) Math.sin(h);
      float[] q = {(float) Math.cos(h), x * s, y * s, z * s};
      AnimPose.normalize(q);
      return q;
   }

   /** FUN_004272c0: producto de Hamilton a * b. */
   static float[] mul(float[] a, float[] b) {
      return new float[]{
         a[0] * b[0] - a[1] * b[1] - a[2] * b[2] - a[3] * b[3],
         a[2] * b[3] + a[0] * b[1] + a[1] * b[0] - a[3] * b[2],
         a[3] * b[1] + a[0] * b[2] + a[2] * b[0] - a[1] * b[3],
         a[1] * b[2] + a[0] * b[3] + a[3] * b[0] - a[2] * b[1],
      };
   }

   /** FUN_00426eb0: v' = q (0, v) q^-1 (FUN_00427220 = inversa, (w, -x, -y, -z) / |q|^2). */
   static float[] rotate(float[] q, float[] v) {
      float n = 1.0F / (q[0] * q[0] + q[3] * q[3] + q[1] * q[1] + q[2] * q[2]);
      float[] inv = {q[0] * n, -n * q[1], -n * q[2], -n * q[3]};
      float[] r = mul(q, mul(new float[]{0f, v[0], v[1], v[2]}, inv));
      return new float[]{r[1], r[2], r[3]};
   }
}

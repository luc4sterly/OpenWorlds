package NET.worlds.core;

/**
 * The movement of an avatar in gamma.dll's animation engine:
 *
 * <ul>
 * <li>the animator's 0x50-byte object (+0x00, FUN_004313b0, vtable
 *     0x4750d0) that measures how far it has moved horizontally between two
 *     positions and in which direction; consumed by update;</li>
 * <li>{@link State}: the Rep's 0x38-byte structure (+4, created in
 *     FUN_004350c0) with the state machine of the implicit animations
 *     (FUN_00434670).</li>
 * </ul>
 *
 * Quaternions as float[4] (w, x, y, z); vectors as float[3].
 */
public final class AnimMotion {
   /** +0x04 (vtable [0] FUN_00431650): already has a position. */
   boolean hasPos;
   /** +0x0c..+0x14. */
   final float[] pos = new float[3];
   /** +0x18: identity on creation (FUN_00428f10). */
   float[] quat = {1f, 0f, 0f, 0f};
   /** +0x2c, +0x34, +0x40: all three are created with the current time (FUN_004279e0). */
   AnimTime time;
   AnimTime dt;
   AnimTime lastUpdate;
   /** +0x3c: 1 forwards, 2 backwards (vtable [10] FUN_004316d0). */
   int direction;
   /** +0x48: signed distance; update reads it and sets it to 0 (vtable [11] FUN_004316e0). */
   float distance;
   /** +0x4c: unsigned distance (vtable [12] FUN_004316f0). */
   float speed;

   AnimMotion(AnimTime now) {
      this.time = now;
      this.dt = now;
      this.lastUpdate = now;
   }

   /** Maximum dt between two positions: {10 s, 0} (DAT_0049dd7c, initialized at 0x4343f0). */
   static final AnimTime MAX_DT = new AnimTime(10, 0);

   /**
    * FUN_00432a30 (from moveto/moveby): the position is only taken if it is
    * the first one (+0x2c == {0,0}) or if the time changes and the position
    * or the orientation changes (FUN_00428eb0: |dot - 1| &gt;= 0.0005).
    * dt = now - previous, capped at {10 s} with the unsigned comparison
    * FUN_00427b70 (a "negative" dt also ends up at 10 s).
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
    * FUN_00431440 (vtable [1]): stores position, orientation and times; the
    * distance is the horizontal part of the displacement (the component
    * along the Z axis is removed, DAT_0049dce8 = (0,0,1)). If in the
    * avatar's local frame (displacement rotated by the inverse of q,
    * FUN_00429170 + FUN_004291c0) y is &lt;= 0 (DAT_00475070) it is going
    * backwards (+0x3c = 2) and the distance is negated. The first time the
    * displacement is 0.
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

   /** vtable [11] FUN_004316e0: returns the distance and sets it to 0. */
   float takeDistance() {
      float d = this.distance;
      this.distance = 0f;
      return d;
   }

   // ------------------------------------------------------------- implicit animation state

   /** The Rep's 0x38-byte structure (+4). */
   static final class State {
      /** +0x04..+0x0c. */
      final float[] pos = new float[3];
      /** +0x10: identity (FUN_00428f10). */
      float[] quat = {1f, 0f, 0f, 0f};
      /** +0x24: creation time (FUN_004279e0). */
      AnimTime time;
      /** +0x2c: chosen implicit animation (1). */
      int state = 1;
      /** +0x30: time of the last change ({0,0} = none yet). */
      AnimTime lastChange = AnimTime.ZERO;

      State(AnimTime now) {
         this.time = now;
      }

      /** DAT_004754e0..ec: {3, 3, 2, 1} indexed by [same position * 2 + same orientation]. */
      static final int[] MOTION = {3, 3, 2, 1};
      static final AnimTime WAIT_AFTER_STILL = new AnimTime(10, 0);
      static final AnimTime WAIT_LENGTH = new AnimTime(30, 0);
      static final AnimTime ENDWAIT_LENGTH = new AnimTime(10, 0);

      /**
       * FUN_004351b0 / FUN_004352f0 (the Rep's part): the first time
       * (+0x30 == {0,0}) it records the time and picks 1; otherwise
       * FUN_00434670. Then it stores position, orientation and time.
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
       * FUN_00434670: m = 3 if it has moved, 2 if it has only turned (dot of
       * the orientations outside 1 +- 0.0005), 1 if it is still.
       * 1 (just stopped): turns -&gt; 2, walks -&gt; 3, 10 s still -&gt; 4.
       * 2 (turning): still -&gt; 1, walks -&gt; 3.
       * 3 (walking): still -&gt; 4, turns -&gt; 2.
       * 4 (wait): turns -&gt; 2, walks -&gt; 3, 30 s -&gt; 5.
       * 5 (endwait): turns -&gt; 2, walks -&gt; 3, 10 s -&gt; 4.
       * Any other state -&gt; 1. Each change records the time (+0x30).
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

   // ------------------------------------------------------------- math

   /**
    * FUN_00428eb0 (not equal) = !FUN_00428e60: |dot(a, b) - 1| &lt; 0.0005
    * (DAT_00473414 = 1, DAT_00473418 = 0.0005) counts as "equal"; dot in the
    * z, y, w, x order of FUN_00429090.
    */
   static boolean notEqual(float[] a, float[] b) {
      double dot = (double) a[3] * b[3] + (double) a[2] * b[2] + (double) a[0] * b[0] + (double) a[1] * b[1];
      float diff = Math.abs((float) (dot - 1.0));
      return !(diff < 0.0005F);
   }

   /**
    * FUN_00428f40: axis-angle quaternion (radians): (cos(a/2),
    * axis * sin(a/2)) (DAT_00473420 = 0.5) and normalized (FUN_00429070).
    */
   static float[] axisAngle(float x, float y, float z, float angle) {
      double h = (double) angle * 0.5;
      float s = (float) Math.sin(h);
      float[] q = {(float) Math.cos(h), x * s, y * s, z * s};
      AnimPose.normalize(q);
      return q;
   }

   /** FUN_004272c0: Hamilton product a * b. */
   static float[] mul(float[] a, float[] b) {
      return new float[]{
         a[0] * b[0] - a[1] * b[1] - a[2] * b[2] - a[3] * b[3],
         a[2] * b[3] + a[0] * b[1] + a[1] * b[0] - a[3] * b[2],
         a[3] * b[1] + a[0] * b[2] + a[2] * b[0] - a[1] * b[3],
         a[1] * b[2] + a[0] * b[3] + a[3] * b[0] - a[2] * b[1],
      };
   }

   /** FUN_00426eb0: v' = q (0, v) q^-1 (FUN_00427220 = inverse, (w, -x, -y, -z) / |q|^2). */
   static float[] rotate(float[] q, float[] v) {
      float n = 1.0F / (q[0] * q[0] + q[3] * q[3] + q[1] * q[1] + q[2] * q[2]);
      float[] inv = {q[0] * n, -n * q[1], -n * q[2], -n * q[3]};
      float[] r = mul(q, mul(new float[]{0f, v[0], v[1], v[2]}, inv));
      return new float[]{r[1], r[2], r[3]};
   }
}

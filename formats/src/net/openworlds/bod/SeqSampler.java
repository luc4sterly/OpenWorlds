package net.openworlds.bod;

/**
 * Sampling of a .seq track at an instant, translated from gamma.dll (see
 * docs/seq-animation-reference.md, section 5 "Playback in gamma.dll"):
 *
 * <pre>
 * FUN_00435ab0  index = largest i with time[i] &lt;= t (0 if t &lt; time[0])
 * FUN_00435a10  no keys -&gt; identity (1,0,0,0); last key or exact t
 *               -&gt; the key's value; otherwise, interpolate (i, i+1)
 * FUN_00435b20  dt = (short)(time[j] - time[i]); dt &lt; 1 -&gt; key i;
 *               f = (t - time[i]) / dt; f &lt;= 0 -&gt; key i; f &gt;= 1 -&gt; key j;
 *               0x10: nlerp (FUN_004271c0: lerp of 4 components +
 *               FUN_00426f40: normalizes if |q|^2 &gt; 1e-5), without hemisphere
 *               inversion (that one is only in the transitions, FUN_004292a0);
 *               4: scalar lerp -&gt; (v,0,0,0); 0xc: lerp of (x,y,z) -&gt; (0,x,y,z)
 * </pre>
 *
 * Time is a short in .seq key units (the original receives it as a short:
 * the truncation is kept).
 */
public final class SeqSampler {
   private SeqSampler() {
   }

   /**
    * gamma.dll's name->tag table (strings at fileoff 0x71314, pointers at
    * 0x71420; FUN_004298b0 registers it for tags 1..30). Exact comparison
    * with strcmp (FUN_004296f0 -> FUN_004274b0 -> FUN_0044d730): the mocap
    * joints with no name here (lumbar_*, thorax_*, cervical_*) are not applied.
    * Matches RWXTOBOD.PL up to tag 22; 23..30 differ in name.
    */
   public static final String[] GAMMA_JOINT_NAMES = {
      null, "pelvis", "back", "neck", "head", "rtsternum", "rtshoulder",
      "rtelbow", "rtwrist", "rtfingers", "lfsternum", "lfshoulder", "lfelbow",
      "lfwrist", "lffingers", "rthip", "rtknee", "rtankle", "rttoes",
      "lfhip", "lfknee", "lfankle", "lftoes", "neck2", "tail", "tail2",
      "tail3", "tail4", "obj", "obj2", "obj3",
   };

   /** Keys per second (DAT_00476ec8 = 30.0; its inverse DAT_00476ec0 = 1/30). */
   public static final float KEYS_PER_SECOND = 30f;
   /** Sequence end mode (player field +0x10): stays on the last key. */
   public static final int MODE_HOLD = 1;
   /** Sequence end mode: loop, modulo (duration + 1). */
   public static final int MODE_LOOP = 2;

   /**
    * Key time from the elapsed time, translated from
    * FUN_0043b950 (time driver, {sec,ms}) and FUN_0043b5f0 (distance
    * driver, seconds as a float), which agree on the rule:
    *
    * <pre>
    * t = (short) trunc(seconds * 30)
    * if t &gt; duration:  mode 2 -&gt; t % (duration + 1)   (loop)
    *                     mode 1 -&gt; duration              (last key)
    *                     other  -&gt; playback ends
    * </pre>
    *
    * The product by 30.0f (DAT_00476ec8) is converted to an integer with fistp
    * and the control word set to truncate: 0x43b9ba fnstcw, 0x43b9c0 "or byte
    * [ebp-0x27],0xc" (RC = 11, chop), 0x43b9c4 fldcw, 0x43b9ca fistp (and the
    * same at 0x43b709..0x43b719 of the distance driver). Until
    * 2026-09-25 this had Math.round: 1.5 keys gave 2 and the binary gives 1.
    * Outside the int range (or NaN) fistp gives 0x80000000, whose short is
    * 0. The key is stored as a short (+0x14) and compared with the duration
    * as a signed 16-bit value (0x43b9e7 cmp dx,ax; jle).
    *
    * Returns -1 when playback ends. Meant for seconds
    * &gt;= 0 (the original's time is unsigned; with negative distance
    * the accumulator is first wrapped to [0, duration], FUN_0043b5f0).
    */
   public static int keyTime(float seconds, int duration, int mode) {
      int t = (short) fistpChop((double) seconds * (double) KEYS_PER_SECOND);
      if (t > duration) {
         if (mode == MODE_LOOP) {
            t = duration + 1 > 0 ? t % (duration + 1) : 0;
         } else if (mode == MODE_HOLD) {
            t = duration;
         } else {
            return -1;
         }
      }
      return (short) t;
   }

   /**
    * 32-bit fistp with RC = chop: truncates toward zero; NaN or out of
    * range gives the integer indefinite 0x80000000 like the x87.
    */
   static int fistpChop(double v) {
      if (Double.isNaN(v) || v >= 2147483648.0 || v < -2147483648.0) {
         return Integer.MIN_VALUE;
      }
      return (int) v;
   }

   /** Pose of a figure at an instant: rotation per tag + root translation. */
   public static final class Pose {
      /** Index = tag 1..30; null = no track (the original applies identity). */
      public final float[][] jointQuat = new float[31][];
      /** Root translation already scaled x0.1 (FUN_00434470, DAT_00475490). */
      public final float[] rootTranslation = new float[3];
   }

   /**
    * FUN_00438300 + the part of FUN_00434470 that does not depend on RenderWare.
    * Joints: only 0x10 tracks whose name is in GAMMA_JOINT_NAMES; each sampled
    * quaternion has x and y negated (FUN_004290c0, DAT_00473440=-1).
    * Root: if there are more than 2 extras, (extra0, extra1, extra2) scalars; z
    * is negated if keepRootZ and zeroed otherwise (DAT_00475fec=-1; who passes
    * that flag is not located yet). Extra 3's quaternion is computed in the
    * original but FUN_00434470 does not apply it: omitted here.
    */
   public static Pose pose(SeqParser.SeqData seq, short t, boolean keepRootZ) {
      Pose p = new Pose();
      if (seq.extras.size() > 2) {
         float x = sample(seq.extras.get(0), t)[0];
         float y = sample(seq.extras.get(1), t)[0];
         float z = sample(seq.extras.get(2), t)[0];
         z = keepRootZ ? -z : 0f;
         p.rootTranslation[0] = x * 0.1f;
         p.rootTranslation[1] = y * 0.1f;
         p.rootTranslation[2] = z * 0.1f;
      }
      for (java.util.Map.Entry<String, SeqParser.Track> e : seq.joints.entrySet()) {
         if (e.getValue().sizeFlag != 0x10) {
            continue;
         }
         int tag = tagOf(e.getKey());
         if (tag < 1) {
            continue;
         }
         float[] q = sample(e.getValue(), t);
         q[1] = -q[1];
         q[2] = -q[2];
         p.jointQuat[tag] = q;
      }
      return p;
   }

   /** Tag 1..30 of the name (exact strcmp) or -1. */
   public static int tagOf(String name) {
      for (int i = 1; i < GAMMA_JOINT_NAMES.length; i++) {
         if (GAMMA_JOINT_NAMES[i].equals(name)) {
            return i;
         }
      }
      return -1;
   }

   /**
    * FUN_00427040: row-major 4x4 matrix (RenderWare's row-vector
    * convention) of a quaternion (w,x,y,z), with s = 2/|q|^2.
    */
   public static float[] quatToMatrix(float[] q) {
      float w = q[0], x = q[1], y = q[2], z = q[3];
      float s = 2f / (w * w + z * z + x * x + y * y);
      float ys = y * s, zs = z * s, wxs = w * x * s, xxs = x * x * s;
      float[] m = new float[16];
      m[0] = 1f - (y * ys + z * zs);
      m[1] = x * ys + w * zs;
      m[2] = x * zs - w * ys;
      m[4] = x * ys - w * zs;
      m[5] = 1f - (xxs + z * zs);
      m[6] = y * zs + wxs;
      m[8] = x * zs + w * ys;
      m[9] = y * zs - wxs;
      m[10] = 1f - (xxs + y * ys);
      m[15] = 1f;
      return m;
   }

   /** Value (4 components, w first in quaternions) of the track at instant t. */
   public static float[] sample(SeqParser.Track track, short t) {
      int n = track.keys();
      if (n == 0) {
         return new float[]{1f, 0f, 0f, 0f};
      }
      int i = keyIndex(track, t);
      if (i != n - 1 && t != track.times[i]) {
         return interpolate(track, t, i, i + 1);
      }
      return value(track, i);
   }

   /** FUN_00435ab0 starting from 0: last key with time &lt;= t, or 0. */
   static int keyIndex(SeqParser.Track track, short t) {
      int n = track.keys();
      int i = 0;
      while (i + 1 < n && track.times[i + 1] <= t) {
         i++;
      }
      return i;
   }

   private static float[] interpolate(SeqParser.Track track, short t, int i, int j) {
      short dt = (short) (track.times[j] - (short) track.times[i]);
      if (dt < 1) {
         return value(track, i);
      }
      float f = (float) (t - track.times[i]) / (float) dt;
      if (f <= 0f) {
         return value(track, i);
      }
      if (f >= 1f) {
         return value(track, j);
      }
      float[] a = value(track, i);
      float[] b = value(track, j);
      if (track.sizeFlag == 0x10) {
         float[] q = new float[4];
         for (int k = 0; k < 4; k++) {
            q[k] = (b[k] - a[k]) * f + a[k];
         }
         normalize(q);
         return q;
      }
      if (track.sizeFlag == 4) {
         return new float[]{(b[0] - a[0]) * f + a[0], 0f, 0f, 0f};
      }
      if (track.sizeFlag == 0xc) {
         return new float[]{0f, (b[1] - a[1]) * f + a[1], (b[2] - a[2]) * f + a[2], (b[3] - a[3]) * f + a[3]};
      }
      return a;
   }

   /** Value of a key as the original's 4-component object. */
   private static float[] value(SeqParser.Track track, int i) {
      float[] v = track.values[i];
      if (v.length == 4) {
         return v.clone();
      }
      return new float[]{v[0], 0f, 0f, 0f};
   }

   /** FUN_00426f40: normalizes only if |q|^2 &gt; 1e-5. */
   static void normalize(float[] q) {
      float s = q[0] * q[0] + q[3] * q[3] + q[1] * q[1] + q[2] * q[2];
      if (Math.abs(s) <= 1e-5f) {
         return;
      }
      float len = (float) Math.sqrt(s);
      q[0] /= len;
      q[1] /= len;
      q[2] /= len;
      q[3] /= len;
   }
}

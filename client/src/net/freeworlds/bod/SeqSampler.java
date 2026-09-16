package net.freeworlds.bod;

/**
 * Muestreo de un track .seq en un instante, traducido de gamma.dll (ver
 * docs/seq-animation-reference.md, seccion "Reproduccion"):
 *
 * <pre>
 * FUN_00435ab0  indice = mayor i con time[i] &lt;= t (0 si t &lt; time[0])
 * FUN_00435a10  sin keys -&gt; identidad (1,0,0,0); ultimo key o t exacto
 *               -&gt; valor del key; si no, interpolar (i, i+1)
 * FUN_00435b20  dt = (short)(time[j] - time[i]); dt &lt; 1 -&gt; key i;
 *               f = (t - time[i]) / dt; f &lt;= 0 -&gt; key i; f &gt;= 1 -&gt; key j;
 *               0x10: nlerp (FUN_004271c0: lerp de 4 componentes +
 *               FUN_00426f40: normaliza si |q|^2 &gt; 1e-5), sin inversion de
 *               hemisferio (esa solo esta en las transiciones, FUN_004292a0);
 *               4: lerp del escalar -&gt; (v,0,0,0); 0xc: lerp de (x,y,z) -&gt; (0,x,y,z)
 * </pre>
 *
 * El tiempo es un short en unidades de key del .seq (el original lo
 * recibe como short: se conserva el truncado).
 */
public final class SeqSampler {
   private SeqSampler() {
   }

   /**
    * Tabla nombre->tag de gamma.dll (strings en fileoff 0x71314, punteros en
    * 0x71420; FUN_004298b0 la registra para tags 1..30). Comparacion exacta
    * con strcmp (FUN_004296f0 -> FUN_004274b0 -> FUN_0044d730): los joints
    * mocap sin nombre aqui (lumbar_*, thorax_*, cervical_*) no se aplican.
    * Coincide con RWXTOBOD.PL hasta el tag 22; 23..30 difieren de nombre.
    */
   public static final String[] GAMMA_JOINT_NAMES = {
      null, "pelvis", "back", "neck", "head", "rtsternum", "rtshoulder",
      "rtelbow", "rtwrist", "rtfingers", "lfsternum", "lfshoulder", "lfelbow",
      "lfwrist", "lffingers", "rthip", "rtknee", "rtankle", "rttoes",
      "lfhip", "lfknee", "lfankle", "lftoes", "neck2", "tail", "tail2",
      "tail3", "tail4", "obj", "obj2", "obj3",
   };

   /** Pose de una figura en un instante: rotacion por tag + traslacion de raiz. */
   public static final class Pose {
      /** Indice = tag 1..30; null = sin track (el original aplica identidad). */
      public final float[][] jointQuat = new float[31][];
      /** Traslacion de la raiz ya escalada x0.1 (FUN_00434470, DAT_00475490). */
      public final float[] rootTranslation = new float[3];
   }

   /**
    * FUN_00438300 + la parte de FUN_00434470 que no depende de RenderWare.
    * Joints: solo tracks 0x10 cuyo nombre esta en GAMMA_JOINT_NAMES; a cada
    * cuaternion muestreado se le niegan x e y (FUN_004290c0, DAT_00473440=-1).
    * Raiz: si hay mas de 2 extras, (extra0, extra1, extra2) escalares; z se
    * niega si keepRootZ y si no se anula (DAT_00475fec=-1; quien pasa ese
    * flag no esta localizado aun). El cuaternion del extra 3 se calcula en el
    * original pero FUN_00434470 no lo aplica: aqui se omite.
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

   /** Tag 1..30 del nombre (strcmp exacto) o -1. */
   public static int tagOf(String name) {
      for (int i = 1; i < GAMMA_JOINT_NAMES.length; i++) {
         if (GAMMA_JOINT_NAMES[i].equals(name)) {
            return i;
         }
      }
      return -1;
   }

   /**
    * FUN_00427040: matriz 4x4 fila-mayor (convencion vector fila de
    * RenderWare) de un cuaternion (w,x,y,z), con s = 2/|q|^2.
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

   /** Valor (4 componentes, w primero en cuaterniones) del track en el instante t. */
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

   /** FUN_00435ab0 partiendo de 0: ultimo key con tiempo &lt;= t, o 0. */
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

   /** Valor de un key como objeto de 4 componentes del original. */
   private static float[] value(SeqParser.Track track, int i) {
      float[] v = track.values[i];
      if (v.length == 4) {
         return v.clone();
      }
      return new float[]{v[0], 0f, 0f, 0f};
   }

   /** FUN_00426f40: normaliza solo si |q|^2 &gt; 1e-5. */
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

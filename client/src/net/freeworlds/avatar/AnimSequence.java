package net.freeworlds.avatar;

import net.freeworlds.bod.SeqParser;
import net.freeworlds.bod.SeqSampler;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Una secuencia .seq tal como la usa el motor de animacion de gamma.dll
 * (objeto de FUN_004380f0, 0x254 bytes), mas los ids de joint con los que
 * se ordenan las poses y la biblioteca de la que salen.
 *
 * <ul>
 * <li>ids de joint: registro global (FUN_004296f0) que empieza en 3
 *     (DAT_00473890); FUN_004298b0 da a los tags 1..30 los ids 3..32 en el
 *     orden de la tabla de nombres de gamma.dll (SeqSampler.GAMMA_JOINT_NAMES);
 *     los nombres de joint que no estan en la tabla toman los siguientes;</li>
 * <li>{@link #pose}: FUN_00438300;</li>
 * <li>{@link Library}: sustituye a la cache por nombre de gamma.dll
 *     (FUN_0042fc50 / FUN_0042fc90), que pide NOMBRE.seq a Java
 *     (PendingCacheDrone.downloadSeqFile); aqui se lee de un directorio.</li>
 * </ul>
 *
 * Portado del puente (bridge/NET/worlds/core/AnimSeqCache.java, clase
 * Sequence y registro de ids); la peticion asincrona a Java y la cuenta de
 * referencias de addtype/deltype no se portan: la biblioteca lee el fichero
 * la primera vez que se pide, como la peticion sincrona de FUN_0042fc90.
 */
public final class AnimSequence {
   // ------------------------------------------------------------- ids de joint

   /** Registro nombre -&gt; id (DAT_0049ff68). */
   private static final Map<String, Integer> JOINT_IDS = new HashMap<>();
   /** DAT_00473890: siguiente id libre (1 y 2 son la raiz). */
   private static int nextJointId = 3;
   /** tag -&gt; id (DAT_0049f96c); [0] = 0 (DAT_004738a0). */
   private static final int[] TAG_IDS = new int[SeqSampler.GAMMA_JOINT_NAMES.length];

   static {
      // FUN_004298b0 (desde init): los tags primero, en orden.
      for (int t = 1; t < TAG_IDS.length; t++) {
         TAG_IDS[t] = jointId(SeqSampler.GAMMA_JOINT_NAMES[t]);
      }
   }

   /** FUN_004296f0: id del nombre (strcmp exacto); si es nuevo, el siguiente. */
   static synchronized int jointId(String name) {
      String n = AnimRegistry.str(name);
      Integer id = JOINT_IDS.get(n);
      if (id == null) {
         id = nextJointId++;
         JOINT_IDS.put(n, id);
      }
      return id;
   }

   /** FUN_00429880: id del tag si 0 &lt; tag &lt; 31; si no, 0. */
   public static int tagId(int tag) {
      return tag > 0 && tag < TAG_IDS.length ? TAG_IDS[tag] : 0;
   }

   // ------------------------------------------------------------- secuencia

   public final SeqParser.SeqData data;
   /** Las pistas de joint en el orden del fichero (+0x220). */
   private final List<SeqParser.Track> tracks = new ArrayList<>();
   /** Pares (pista, id) ordenados por id (FUN_00438800 / FUN_00439210). */
   private final int[][] pairs;

   public AnimSequence(SeqParser.SeqData data) {
      this.data = data;
      List<int[]> p = new ArrayList<>();
      for (Map.Entry<String, SeqParser.Track> e : data.joints.entrySet()) {
         p.add(new int[]{this.tracks.size(), jointId(e.getKey())});
         this.tracks.add(e.getValue());
      }
      Collections.sort(p, new Comparator<int[]>() {
         public int compare(int[] a, int[] b) {
            return Integer.compare(a[1], b[1]);
         }
      });
      this.pairs = p.toArray(new int[0][]);
   }

   /** +0x228: duracion en keys (short). */
   public short duration() {
      return (short) this.data.duration;
   }

   /**
    * FUN_00438300: la pose en el key t. Si hay mas de 2 pistas extra, la
    * traslacion de raiz son sus escalares 0..2 y, con mas de 3, la rotacion
    * de raiz el cuaternion 3. Si hay alguna extra se anaden las entradas 1
    * (rotacion, x e y negadas con FUN_004290c0) y 2 (traslacion, z negada
    * por DAT_00475fec = -1 si keepZ, a 0 si no). Luego cada pista de joint:
    * 0x10 -&gt; tipo 6 con x e y negadas; otra -&gt; su escalar, tipo 3 si el
    * tamano es 4 y 0 si no.
    */
   public AnimPose pose(short t, boolean keepZ) {
      List<AnimPose.Entry> out = new ArrayList<>();
      float[] rootQ = {1f, 0f, 0f, 0f};
      float rx = 0f;
      float ry = 0f;
      float rz = 0f;
      List<SeqParser.Track> ex = this.data.extras;
      if (ex.size() > 2) {
         rx = rx + SeqSampler.sample(ex.get(0), t)[0];
         ry = ry + SeqSampler.sample(ex.get(1), t)[0];
         rz = rz + SeqSampler.sample(ex.get(2), t)[0];
         if (ex.size() > 3) {
            rootQ = SeqSampler.sample(ex.get(3), t);
         }
      }
      if (ex.size() > 0) {
         rootQ = rootQ.clone();
         rootQ[1] = rootQ[1] * -1f;
         rootQ[2] = rootQ[2] * -1f;
         out.add(new AnimPose.Entry(1, 1, rootQ));
         out.add(new AnimPose.Entry(2, 2, new float[]{rx, ry, keepZ ? -1f * rz : 0f}));
      }
      for (int[] p : this.pairs) {
         SeqParser.Track tr = this.tracks.get(p[0]);
         float[] s = SeqSampler.sample(tr, t);
         int flag = tr.sizeFlag & 0xFF;
         int kind = flag == 4 ? 3 : (flag == 0x10 ? 6 : 0);
         if (tr.sizeFlag == 0x10) {
            s[1] = s[1] * -1f;
            s[2] = s[2] * -1f;
            out.add(new AnimPose.Entry(p[1], kind, s));
         } else {
            out.add(new AnimPose.Entry(p[1], kind, new float[]{s[0]}));
         }
      }
      return new AnimPose(out);
   }

   // ------------------------------------------------------------- biblioteca

   /**
    * Las secuencias de un directorio de avatares, por nombre sin extension
    * ("common_walk" -&gt; common_walk.seq). El original busca
    * "./avatars\\NOMBRE.seq" en Windows, sin distinguir mayusculas: aqui
    * tambien. Un fichero que no esta o no se puede leer da null (driver
    * vacio, FUN_00437d00), y se recuerda.
    */
   public static final class Library {
      private final File dir;
      private final Map<String, AnimSequence> cache = new HashMap<>();
      private Map<String, File> listing;

      public Library(File dir) {
         this.dir = dir;
      }

      public synchronized AnimSequence get(String name) {
         String key = name.toLowerCase(java.util.Locale.ROOT);
         if (this.cache.containsKey(key)) {
            return this.cache.get(key);
         }
         AnimSequence seq = null;
         File f = this.find(key + ".seq");
         if (f != null) {
            try {
               seq = new AnimSequence(SeqParser.parseFile(f.getPath()));
            } catch (Exception e) {
               System.err.println("AnimSequence: " + f + ": " + e);
            }
         }
         this.cache.put(key, seq);
         return seq;
      }

      private File find(String lowerName) {
         if (this.listing == null) {
            this.listing = new HashMap<>();
            File[] fs = this.dir == null ? null : this.dir.listFiles();
            if (fs != null) {
               for (File f : fs) {
                  this.listing.put(f.getName().toLowerCase(java.util.Locale.ROOT), f);
               }
            }
         }
         return this.listing.get(lowerName);
      }
   }
}

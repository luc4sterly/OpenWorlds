package NET.worlds.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * Las secuencias .seq cargadas por el motor de animacion de gamma.dll:
 *
 * <ul>
 * <li>los ids de joint (FUN_004296f0, registro global que empieza en
 *     DAT_00473890 = 3; FUN_004298b0 da a los tags 1..30 los ids 3..32);</li>
 * <li>el objeto secuencia (FUN_004380f0, 0x254 bytes): los datos del .seq
 *     (client/.../bod/SeqParser, el mismo cargador FUN_00436d50) mas los
 *     pares (pista, id) ordenados por id;</li>
 * <li>la cache por nombre (FUN_0042fc50, entradas de 0x110 bytes ordenadas
 *     por clave "./avatars\\NOMBRE.seq" con cuenta de referencias) y las
 *     peticiones a Java PendingCacheDrone.downloadSeqFile (FUN_00430330 ->
 *     FUN_0044be10) con su respuesta notifySeqLoaded (0x0044bda0);</li>
 * <li>las cuentas por tipo de avatar de addtype/deltype (FUN_0042b100).</li>
 * </ul>
 */
public final class AnimSeqCache {
   private AnimSeqCache() {
   }

   // ------------------------------------------------------------- ids de joint

   /** Registro nombre -&gt; id (DAT_0049ff68, entradas de 0x108 bytes). */
   private static final Map<String, Integer> jointIds = new HashMap<String, Integer>();
   /** DAT_00473890: siguiente id libre (1 y 2 son la raiz). */
   private static int nextJointId = 3;
   /** DAT_0049f96c/f970: tag -&gt; id; [0] = DAT_004738a0 = 0. */
   private static final List<Integer> tagIds = new ArrayList<Integer>();

   /**
    * Tabla de gamma.dll de nombres por tag (punteros en 0x474618 + 8*tag,
    * cadenas desde 0x474514), la que registra FUN_004298b0.
    */
   public static final String[] TAG_NAMES = {
      null, "pelvis", "back", "neck", "head", "rtsternum", "rtshoulder",
      "rtelbow", "rtwrist", "rtfingers", "lfsternum", "lfshoulder", "lfelbow",
      "lfwrist", "lffingers", "rthip", "rtknee", "rtankle", "rttoes",
      "lfhip", "lfknee", "lfankle", "lftoes", "neck2", "tail", "tail2",
      "tail3", "tail4", "obj", "obj2", "obj3",
   };

   /** FUN_004296f0: id del nombre (strcmp exacto); si es nuevo, el siguiente. */
   static synchronized int jointId(String name) {
      String n = AnimRegistry.str(name);
      Integer id = jointIds.get(n);
      if (id == null) {
         id = nextJointId++;
         jointIds.put(n, id);
      }
      return id;
   }

   /** FUN_004298b0 (desde init): una sola vez (guarda DAT_0049fa80). */
   static synchronized void registerTags() {
      if (!tagIds.isEmpty()) {
         return;
      }
      tagIds.add(0);
      for (int t = 1; t < TAG_NAMES.length; t++) {
         tagIds.add(jointId(TAG_NAMES[t]));
      }
   }

   /** FUN_00429880: id del tag si 0 &lt; tag &lt; cuenta; si no, 0. */
   static synchronized int tagId(int tag) {
      return tag > 0 && tag < tagIds.size() ? tagIds.get(tag) : 0;
   }

   // ------------------------------------------------------------- secuencia

   /** El objeto secuencia de FUN_004380f0. */
   public static final class Sequence {
      public final net.openworlds.bod.SeqParser.SeqData data;
      /** Las pistas de joint en el orden del fichero (+0x220). */
      final List<net.openworlds.bod.SeqParser.Track> tracks = new ArrayList<net.openworlds.bod.SeqParser.Track>();
      /** Pares (pista, id) ordenados por id (FUN_00438800 / FUN_00439210). */
      final int[][] pairs;

      public Sequence(net.openworlds.bod.SeqParser.SeqData data) {
         this.data = data;
         List<int[]> p = new ArrayList<int[]>();
         for (Map.Entry<String, net.openworlds.bod.SeqParser.Track> e : data.joints.entrySet()) {
            p.add(new int[]{this.tracks.size(), jointId(e.getKey())});
            this.tracks.add(e.getValue());
         }
         java.util.Collections.sort(p, new java.util.Comparator<int[]>() {
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
       * traslacion de raiz son sus escalares 0..2 y, con mas de 3, la
       * rotacion de raiz el cuaternion 3. Si hay alguna extra se anaden las
       * entradas 1 (rotacion, x e y negadas con FUN_004290c0) y 2 (traslacion,
       * z negada por DAT_00475fec = -1 si keepZ, a 0 si no). Luego cada pista
       * de joint: 0x10 -&gt; tipo 6 con x e y negadas; otra -&gt; su escalar,
       * tipo 3 si el tamano es 4 y 0 si no.
       */
      public AnimPose pose(short t, boolean keepZ) {
         List<AnimPose.Entry> out = new ArrayList<AnimPose.Entry>();
         float[] rootQ = {1f, 0f, 0f, 0f};
         float rx = 0f;
         float ry = 0f;
         float rz = 0f;
         List<net.openworlds.bod.SeqParser.Track> ex = this.data.extras;
         if (ex.size() > 2) {
            rx = rx + net.openworlds.bod.SeqSampler.sample(ex.get(0), t)[0];
            ry = ry + net.openworlds.bod.SeqSampler.sample(ex.get(1), t)[0];
            rz = rz + net.openworlds.bod.SeqSampler.sample(ex.get(2), t)[0];
            if (ex.size() > 3) {
               rootQ = net.openworlds.bod.SeqSampler.sample(ex.get(3), t);
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
            net.openworlds.bod.SeqParser.Track tr = this.tracks.get(p[0]);
            float[] s = net.openworlds.bod.SeqSampler.sample(tr, t);
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
   }

   // ------------------------------------------------------------- cache

   /** Como se piden los .seq a Java: PendingCacheDrone.downloadSeqFile(nombre, sync, objeto). */
   public interface Requester {
      void request(String file, boolean sync, int handle);
   }

   /** Como se lee el fichero que notifica Java (FUN_00403fc0 -&gt; Archive.readBinaryFile). */
   public interface Reader {
      byte[] read(String path);
   }

   public static volatile Requester requester = new Requester() {
      public void request(String file, boolean sync, int handle) {
         NET.worlds.scape.PendingCacheDrone.downloadSeqFile(file, sync, handle);
      }
   };

   public static volatile Reader reader = new Reader() {
      public byte[] read(String path) {
         return Archive.readBinaryFile(path);
      }
   };

   /** Entrada de la cache (0x110 bytes): clave, cuenta (+0x104) y secuencia (+0x108). */
   private static final class CacheEntry {
      int refs;
      Sequence seq;
   }

   /**
    * El objeto de ruta de FUN_004303a0 (0x1004 bytes): el nombre, la clave
    * "./avatars\\NOMBRE.seq" (+0x800) y su cuenta (+0x1000). Su direccion
    * es el int que viaja por Java; aqui un handle.
    */
   private static final class PathObj {
      final String name;
      final String key;
      int refs;
      String local;

      PathObj(String name) {
         this.name = AnimRegistry.str(name);
         this.key = AnimRegistry.str(NativeAnimator.avatarDir() + "\\" + this.name + ".seq");
      }
   }

   private static final TreeMap<String, CacheEntry> cache = new TreeMap<String, CacheEntry>();
   private static final Map<Integer, PathObj> handles = new HashMap<Integer, PathObj>();
   private static int nextHandle = 1;

   private static synchronized int handleOf(PathObj p) {
      int h = nextHandle++;
      handles.put(h, p);
      return h;
   }

   /** FUN_00430490 / FUN_004304a0: la cuenta del objeto de ruta; a 0 se libera. */
   private static synchronized void release(int h) {
      PathObj p = handles.get(h);
      if (p != null && --p.refs == 0) {
         handles.remove(h);
      }
   }

   /**
    * FUN_00430330: pide NOMBRE.seq a Java (sprintf "%s%s" DAT_00474d10 con
    * ".seq" DAT_004754f0) pasandole el objeto de ruta, cuya cuenta sube
    * (FUN_0044be10). Sin el cerrojo: Java puede notificar en este mismo
    * hilo (sync) o en el del BackgroundLoader.
    */
   private static void request(PathObj p, int h, boolean sync) {
      synchronized (AnimSeqCache.class) {
         p.refs++;
      }
      requester.request(p.name + ".seq", sync, h);
   }

   /**
    * FUN_0042ffd0 (desde addtype): si la clave ya esta, sube su cuenta y
    * pide el fichero en asincrono; si no, la inserta con cuenta 1 y sin
    * secuencia, sin pedir nada (se pedira al usarla, FUN_0042fc90).
    */
   static void addRef(String name) {
      if (name == null || name.isEmpty()) {
         return;
      }
      PathObj p = new PathObj(name);
      int h;
      boolean found;
      synchronized (AnimSeqCache.class) {
         p.refs = 1;
         h = handleOf(p);
         CacheEntry e = cache.get(p.key);
         found = e != null;
         if (found) {
            e.refs++;
         } else {
            e = new CacheEntry();
            e.refs = 1;
            cache.put(p.key, e);
         }
      }
      if (found) {
         request(p, h, false);
      }
      release(h);
   }

   /** FUN_004301c0 (desde deltype): baja la cuenta y a 0 borra la entrada (FUN_004309d0). */
   static synchronized void releaseRef(String name) {
      if (name == null || name.isEmpty()) {
         return;
      }
      String key = new PathObj(name).key;
      CacheEntry e = cache.get(key);
      if (e != null && --e.refs == 0) {
         cache.remove(key);
      }
   }

   /**
    * FUN_0042fc90: la secuencia de ese nombre; si la entrada existe pero aun
    * no tiene secuencia, la pide en sincrono y la vuelve a leer. Un nombre
    * que no registro ningun addtype da null (no se pide).
    */
   static Sequence get(String name) {
      PathObj p = new PathObj(name);
      int h;
      boolean ask;
      synchronized (AnimSeqCache.class) {
         p.refs = 1;
         h = handleOf(p);
         CacheEntry e = cache.get(p.key);
         ask = e != null && e.seq == null;
      }
      if (ask) {
         request(p, h, true);
      }
      Sequence s;
      synchronized (AnimSeqCache.class) {
         CacheEntry e = cache.get(p.key);
         s = e == null ? null : e.seq;
      }
      release(h);
      return s;
   }

   /**
    * PendingCacheDrone.notifySeqLoaded (0x0044bda0 -&gt; FUN_004307f0 +
    * FUN_004304e0): lee el fichero, lo analiza y lo guarda en la entrada
    * de la clave del objeto de ruta si sigue en la cache; luego suelta el
    * objeto. ⚠️ VERIFICAR: un .seq que no se puede analizar se descarta
    * aqui; el camino de error de FUN_00436d50 no esta traducido.
    */
   public static void notifySeqLoaded(int handle, String path) {
      PathObj p;
      synchronized (AnimSeqCache.class) {
         p = handles.get(handle);
      }
      if (p == null) {
         return;
      }
      if (path != null) {
         p.local = path;
         byte[] bytes = reader.read(path);
         if (bytes != null) {
            Sequence seq = null;
            try {
               seq = new Sequence(net.openworlds.bod.SeqParser.parse(bytes));
            } catch (RuntimeException ex) {
               System.err.println("[DroneAnimator] " + path + ": " + ex.getMessage());
            }
            if (seq != null) {
               synchronized (AnimSeqCache.class) {
                  CacheEntry e = cache.get(p.key);
                  if (e != null) {
                     e.seq = seq;
                  }
               }
            }
         }
      }
      release(handle);
   }

   /** Para las comprobaciones: cuenta de la entrada o -1. */
   public static synchronized int refs(String name) {
      CacheEntry e = cache.get(new PathObj(name).key);
      return e == null ? -1 : e.refs;
   }

   /** Para las comprobaciones: ¿esta cargada? */
   public static synchronized boolean loaded(String name) {
      CacheEntry e = cache.get(new PathObj(name).key);
      return e != null && e.seq != null;
   }

   // ------------------------------------------------------------- tipos

   /** DAT_0049ff28 (FUN_0042b100): cuenta por tipo de avatar. */
   private static final Map<Integer, Integer> typeRefs = new HashMap<Integer, Integer>();

   /**
    * FUN_0042b160 (DroneAnimator.addtype 0x00416430): la primera vez que se
    * anade un tipo registra en la cache las secuencias de sus implicitos y
    * de sus explicitos (FUN_0042bd30 y FUN_0042bd50). Las que solo salen en
    * bloques changeimp no se registran, y por eso nunca se cargan.
    */
   public static void addType(int type) {
      int before;
      synchronized (AnimSeqCache.class) {
         Integer c = typeRefs.get(type);
         before = c == null ? 0 : c;
         typeRefs.put(type, before + 1);
      }
      if (before != 0) {
         return;
      }
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return;
      }
      for (String s : new ArrayList<String>(t.impValues)) {
         addRef(s);
      }
      for (String s : new ArrayList<String>(t.expValues)) {
         addRef(s);
      }
   }

   /** FUN_0042b280 (DroneAnimator.deltype 0x00416450): a 0 suelta sus secuencias. */
   public static void delType(int type) {
      synchronized (AnimSeqCache.class) {
         Integer c = typeRefs.get(type);
         if (c == null) {
            return;
         }
         int n = c - 1;
         if (n >= 1) {
            typeRefs.put(type, n);
            return;
         }
         typeRefs.put(type, 0);
      }
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return;
      }
      for (String s : new ArrayList<String>(t.impValues)) {
         releaseRef(s);
      }
      for (String s : new ArrayList<String>(t.expValues)) {
         releaseRef(s);
      }
   }
}

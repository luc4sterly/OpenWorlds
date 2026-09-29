package NET.worlds.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

/**
 * The .seq sequences loaded by gamma.dll's animation engine:
 *
 * <ul>
 * <li>the joint ids (FUN_004296f0, a global registry that starts at
 *     DAT_00473890 = 3; FUN_004298b0 gives tags 1..30 the ids 3..32);</li>
 * <li>the sequence object (FUN_004380f0, 0x254 bytes): the .seq data
 *     (client/.../bod/SeqParser, the same loader FUN_00436d50) plus the
 *     (track, id) pairs sorted by id;</li>
 * <li>the cache by name (FUN_0042fc50, 0x110-byte entries sorted by key
 *     "./avatars\\NAME.seq" with a reference count) and the requests to Java
 *     PendingCacheDrone.downloadSeqFile (FUN_00430330 -> FUN_0044be10) with
 *     its answer notifySeqLoaded (0x0044bda0);</li>
 * <li>the counts per avatar type of addtype/deltype (FUN_0042b100).</li>
 * </ul>
 */
public final class AnimSeqCache {
   private AnimSeqCache() {
   }

   // ------------------------------------------------------------- joint ids

   /** Registry name -&gt; id (DAT_0049ff68, 0x108-byte entries). */
   private static final Map<String, Integer> jointIds = new HashMap<String, Integer>();
   /** DAT_00473890: next free id (1 and 2 are the root). */
   private static int nextJointId = 3;
   /** DAT_0049f96c/f970: tag -&gt; id; [0] = DAT_004738a0 = 0. */
   private static final List<Integer> tagIds = new ArrayList<Integer>();

   /**
    * gamma.dll's table of names by tag (pointers at 0x474618 + 8*tag,
    * strings from 0x474514), the one that FUN_004298b0 registers.
    */
   public static final String[] TAG_NAMES = {
      null, "pelvis", "back", "neck", "head", "rtsternum", "rtshoulder",
      "rtelbow", "rtwrist", "rtfingers", "lfsternum", "lfshoulder", "lfelbow",
      "lfwrist", "lffingers", "rthip", "rtknee", "rtankle", "rttoes",
      "lfhip", "lfknee", "lfankle", "lftoes", "neck2", "tail", "tail2",
      "tail3", "tail4", "obj", "obj2", "obj3",
   };

   /** FUN_004296f0: id of the name (exact strcmp); if it is new, the next one. */
   static synchronized int jointId(String name) {
      String n = AnimRegistry.str(name);
      Integer id = jointIds.get(n);
      if (id == null) {
         id = nextJointId++;
         jointIds.put(n, id);
      }
      return id;
   }

   /** FUN_004298b0 (from init): only once (guard: DAT_0049fa80). */
   static synchronized void registerTags() {
      if (!tagIds.isEmpty()) {
         return;
      }
      tagIds.add(0);
      for (int t = 1; t < TAG_NAMES.length; t++) {
         tagIds.add(jointId(TAG_NAMES[t]));
      }
   }

   /** FUN_00429880: id of the tag if 0 &lt; tag &lt; count; otherwise 0. */
   static synchronized int tagId(int tag) {
      return tag > 0 && tag < tagIds.size() ? tagIds.get(tag) : 0;
   }

   // ------------------------------------------------------------- sequence

   /** The sequence object of FUN_004380f0. */
   public static final class Sequence {
      public final net.openworlds.bod.SeqParser.SeqData data;
      /** The joint tracks in file order (+0x220). */
      final List<net.openworlds.bod.SeqParser.Track> tracks = new ArrayList<net.openworlds.bod.SeqParser.Track>();
      /** (track, id) pairs sorted by id (FUN_00438800 / FUN_00439210). */
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

      /** +0x228: duration in keys (short). */
      public short duration() {
         return (short) this.data.duration;
      }

      /**
       * FUN_00438300: the pose at key t. If there are more than 2 extra
       * tracks, the root translation is their scalars 0..2 and, with more than
       * 3, the root rotation is quaternion 3. If there is any extra one,
       * entries 1 (rotation, x and y negated with FUN_004290c0) and 2
       * (translation, z negated by DAT_00475fec = -1 if keepZ, set to 0
       * otherwise) are added. Then each joint track: 0x10 -&gt; type 6 with x
       * and y negated; another -&gt; its scalar, type 3 if the size is 4 and 0
       * otherwise.
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

   /** How the .seq files are requested from Java: PendingCacheDrone.downloadSeqFile(name, sync, object). */
   public interface Requester {
      void request(String file, boolean sync, int handle);
   }

   /** How the file that Java notifies is read (FUN_00403fc0 -&gt; Archive.readBinaryFile). */
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

   /** Cache entry (0x110 bytes): key, count (+0x104) and sequence (+0x108). */
   private static final class CacheEntry {
      int refs;
      Sequence seq;
   }

   /**
    * The path object of FUN_004303a0 (0x1004 bytes): the name, the key
    * "./avatars\\NAME.seq" (+0x800) and its count (+0x1000). Its address
    * is the int that travels through Java; here, a handle.
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

   /** FUN_00430490 / FUN_004304a0: the path object's count; at 0 it is freed. */
   private static synchronized void release(int h) {
      PathObj p = handles.get(h);
      if (p != null && --p.refs == 0) {
         handles.remove(h);
      }
   }

   /**
    * FUN_00430330: asks Java for NAME.seq (sprintf "%s%s" DAT_00474d10
    * with ".seq" DAT_004754f0) passing it the path object, whose count is
    * raised (FUN_0044be10). Without holding the lock: Java may notify on
    * this same thread (sync) or on the BackgroundLoader's.
    */
   private static void request(PathObj p, int h, boolean sync) {
      synchronized (AnimSeqCache.class) {
         p.refs++;
      }
      requester.request(p.name + ".seq", sync, h);
   }

   /**
    * FUN_0042ffd0 (from addtype): if the key is already there, raises
    * its count and requests the file asynchronously; if not, inserts it
    * with count 1 and no sequence, requesting nothing (it will be
    * requested when it is used, FUN_0042fc90).
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

   /** FUN_004301c0 (from deltype): lowers the count and at 0 deletes the entry (FUN_004309d0). */
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
    * FUN_0042fc90: the sequence of that name; if the entry exists but does
    * not have a sequence yet, requests it synchronously and reads it again.
    * A name that no addtype registered gives null (it is not requested).
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
    * FUN_004304e0): reads the file, parses it and stores it in the entry
    * of the path object's key if it is still in the cache; then releases
    * the object. ⚠️ VERIFY: a .seq that cannot be parsed is discarded
    * here; the error path of FUN_00436d50 is not translated.
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

   /** For the checks: the entry's count or -1. */
   public static synchronized int refs(String name) {
      CacheEntry e = cache.get(new PathObj(name).key);
      return e == null ? -1 : e.refs;
   }

   /** For the checks: is it loaded? */
   public static synchronized boolean loaded(String name) {
      CacheEntry e = cache.get(new PathObj(name).key);
      return e != null && e.seq != null;
   }

   // ------------------------------------------------------------- types

   /** DAT_0049ff28 (FUN_0042b100): count per avatar type. */
   private static final Map<Integer, Integer> typeRefs = new HashMap<Integer, Integer>();

   /**
    * FUN_0042b160 (DroneAnimator.addtype 0x00416430): the first time a type
    * is added it registers in the cache the sequences of its implicit and
    * explicit entries (FUN_0042bd30 and FUN_0042bd50). The ones that only
    * appear in changeimp blocks are not registered, and so they are never
    * loaded.
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

   /** FUN_0042b280 (DroneAnimator.deltype 0x00416450): at 0 it releases its sequences. */
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

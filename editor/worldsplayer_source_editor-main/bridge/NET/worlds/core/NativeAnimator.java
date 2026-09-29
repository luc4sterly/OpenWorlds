package NET.worlds.core;

import java.util.Vector;

/**
 * The native methods of NET.worlds.scape.DroneAnimator (gamma.dll
 * 0x00416280.. 0x00416740). The JNI wrappers are thin: the logic is in
 * gamma.dll's animation engine (0x0042b000..0x0043c500), translated here
 * and in the Anim* classes of this package. Evidence by address in each
 * method; summary in docs/seq-animation-reference.md.
 */
public final class NativeAnimator {
   private NativeAnimator() {
   }

   /** DAT_004a0118: the directory that init receives (FUN_0042f6b0). */
   private static String home = ".";

   /**
    * DroneAnimator.init (0x00416280 -> FUN_004349d0): sets the configuration
    * strings (".seq" DAT_004754f0, ".zip" DAT_004754f8, the directory, "\\"
    * DAT_00475500 and "avatars" DAT_00475504 for the "%s/%s" paths
    * DAT_00474cc8), registers the ids of tags 1..30 (FUN_004298b0) and
    * empties the registry (FUN_0042ca50). The wrapper also looks up
    * java.util.Vector for getActionList.
    */
   public static synchronized void init(String path) {
      home = path == null ? "" : AnimRegistry.str(path);
      AnimSeqCache.registerTags();
      AnimRegistry.get().clear();
   }

   /** DAT_0049fe1c / DAT_004a021c: sprintf("%s/%s", directory, "avatars"). */
   static String avatarDir() {
      return home + "/avatars";
   }

   /**
    * DroneAnimator.loadconfig (0x00416360 -> FUN_00434b70): empties the
    * registry and, if there is a path, reads the file with
    * Archive.readTextFile (FUN_00403e80 -> FUN_00403eb0, which strips the
    * CRs) and parses it (FUN_0042cb90). ⚠️ VERIFY: a syntax error is a C++
    * throw whose catch has not been located; here a warning is issued and
    * the types read up to the error are kept.
    */
   public static void loadconfig(String path) {
      AnimRegistry reg = AnimRegistry.get();
      reg.clear();
      if (path == null) {
         return;
      }
      byte[] text = Archive.readTextFile(path);
      if (text == null) {
         return;
      }
      try {
         reg.load(text, path);
      } catch (AnimRegistry.ParseError e) {
         System.err.println("[DroneAnimator] " + path + ": " + e.getMessage());
      }
   }

   /** DroneAnimator.getnameindex (0x004163b0 -> FUN_00434ce0 -> FUN_0042c8a0). */
   public static int getnameindex(String name) {
      int i = AnimRegistry.get().nameIndex(name);
      if (AnimAnimator.LOG) {
         System.out.println("[anim] getnameindex(" + name + ") = " + i + " de " + AnimRegistry.get().size());
      }
      return i;
   }

   /**
    * DroneAnimator.getindexgeom (0x004163f0 -> FUN_00434d10): "" if the
    * type does not exist or has no geometry; otherwise
    * "&lt;dir&gt;/avatars" + "\\" + geometry (FUN_0042f750 + FUN_0042f950 +
    * strcat).
    */
   public static String getindexgeom(int type) {
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t == null) {
         return "";
      }
      String geom = t.attr("geometry");
      if (geom.isEmpty()) {
         return "";
      }
      return avatarDir() + "\\" + geom;
   }

   /**
    * DroneAnimator.getActionList (0x004166c0): a new Vector (FUN_00415a40)
    * with the keys of the type's explicit entries in file order
    * (FUN_00434e50 + callback 0x00416680 -> addElement); empty if the type
    * does not exist.
    */
   public static Vector<String> getActionList(int type) {
      Vector<String> v = new Vector<String>();
      AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
      if (t != null) {
         for (String k : t.expKeys) {
            v.addElement(k);
         }
      }
      return v;
   }

   // ------------------------------------------------------------- types and sequences

   /** DroneAnimator.addtype (0x00416430 -> FUN_00434ec0 -> FUN_0042b160). */
   public static void addtype(int type) {
      if (AnimAnimator.LOG) {
         AnimRegistry.AvatarType t = AnimRegistry.get().type(type);
         System.out.println("[anim] addtype " + type + " " + (t == null ? "?" : t.attr("name")));
      }
      AnimSeqCache.addType(type);
   }

   /** DroneAnimator.deltype (0x00416450 -> FUN_00434ee0 -> FUN_0042b280). */
   public static void deltype(int type) {
      AnimSeqCache.delType(type);
   }

   /**
    * PendingCacheDrone.nativeInit (0x0044bd00): stores the JNIEnv and the
    * ids of downloadSeqFile/getAvatarDatPath. In Java the call is direct
    * (AnimSeqCache.requester): there is nothing to store.
    */
   public static void nativeInit() {
   }

   /** PendingCacheDrone.notifySeqLoaded (0x0044bda0). */
   public static void notifySeqLoaded(int handle, String path) {
      AnimSeqCache.notifySeqLoaded(handle, path);
   }

   // ------------------------------------------------------------- representations

   /** The 8-byte object of CreateRep (FUN_004350c0): the animator. */
   static final class Rep {
      final AnimAnimator animator;
      final AnimMotion.State state;

      Rep(AnimTime now) {
         this.animator = new AnimAnimator(now);
         this.state = new AnimMotion.State(now);
      }
   }

   /** FUN_004279e0: the current time from FUN_00402c10 (Std.nativeGetMillis, NativeInput.millis). */
   static AnimTime now() {
      return AnimTime.ofMillis(NativeInput.millis());
   }

   private static final java.util.Map<Integer, Rep> reps = new java.util.HashMap<Integer, Rep>();
   private static int nextRep = 1;

   static synchronized Rep rep(int h) {
      return reps.get(h);
   }

   /** For the checks: the animator of a CreateRep handle. */
   public static AnimAnimator animator(int h) {
      Rep r = rep(h);
      return r == null ? null : r.animator;
   }

   /**
    * DroneAnimator.CreateRep (0x004164a0): FUN_004350c0(this, 0, 1) -&gt;
    * FUN_00432880 with movement type 0 (the jump at 0x0043293a through the
    * table 0x47542c leads to 0x432941: 0x50-byte object, FUN_004313b0),
    * active = 1 and FUN_00433420. Returns a handle where the original
    * returns the pointer.
    */
   public static synchronized int CreateRep() {
      int h = nextRep++;
      reps.put(h, new Rep(now()));
      return h;
   }

   /** DroneAnimator.DestroyRep (0x004164d0). */
   public static synchronized void DestroyRep(int h) {
      reps.remove(h);
   }

   /** DroneAnimator.endanimations (0x00416500 -> FUN_004351a0 -> FUN_00433420). */
   public static void endanimations(int h) {
      Rep r = rep(h);
      if (r != null) {
         r.animator.reset();
      }
   }

   /**
    * DroneAnimator.animate (0x004165c0 -> FUN_004355a0): the name is
    * lower-cased (FUN_004280b0), looked up among the type's explicit
    * entries (FUN_00433e90) and started (FUN_00432d10 with implicit entry
    * -1); returns its duration in seconds, or 0.0 (DAT_00475524) if it
    * does not exist. The time it receives is converted to {s, ms}
    * (FUN_00427a20) and is not used.
    */
   public static float animate(int h, int type, String name) {
      Rep r = rep(h);
      if (r == null || name == null) {
         return 0.0F;
      }
      int idx = AnimAnimator.explicitIndex(type, AnimRegistry.lower(name));
      if (idx == -1) {
         return 0.0F;
      }
      return r.animator.play(type, -1, idx);
   }

   /** DroneAnimator.getAnimationTime (0x00416620 -> FUN_00435630 -> FUN_00432be0). */
   public static float getAnimationTime(int h, int type, String name) {
      Rep r = rep(h);
      if (r == null || name == null) {
         return 0.0F;
      }
      int idx = AnimAnimator.explicitIndex(type, AnimRegistry.lower(name));
      if (idx == -1) {
         return 0.0F;
      }
      return r.animator.duration(type, idx);
   }

   // ------------------------------------------------------------- movement and pose

   /** pi (DAT_00475530, double) and 1/180 (DAT_00475538, double). */
   private static final double PI = 3.141592653589793;
   private static final double INV_180 = 0.005555555555555556;

   /**
    * DroneAnimator.moveto (0x00416530 -> FUN_004351b0): position (x, y, z),
    * Z-axis orientation (0x49f398 = (0,0,1), initialised at 0x42856c), yaw
    * angle * pi * 1/180 (fild + fmull + fmull, to float) and time in ms.
    * PosableShape passes (short) x/y/z, (short) -yaw in degrees and
    * Std.getRealTime() - 1.
    */
   public static void moveto(int h, int type, short x, short y, short z, short yaw, int time) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] p = {(float) x, (float) y, (float) z};
      float[] q = AnimMotion.axisAngle(0f, 0f, 1f, (float) ((double) yaw * PI * INV_180));
      if (AnimAnimator.LOG && r.state.lastChange.same(AnimTime.ZERO)) {
         System.out.println("[anim] primer moveto rep " + h + " tipo " + type + " en (" + x + "," + y + "," + z + ") yaw " + yaw + " t " + time);
      }
      r.animator.moved(r.state, type, p, q, AnimTime.ofMillis(time));
   }

   /**
    * DroneAnimator.moveby (0x00416580 -> FUN_004352f0): the position of
    * the animator's movement (FUN_00433610) + (dx, dy, 0) and its
    * orientation (FUN_004336a0) multiplied by the turn dyaw (FUN_00429150
    * = Hamilton product, not normalised); then as moveto.
    */
   public static void moveby(int h, int type, short dx, short dy, short dyaw, int time) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] p;
      float[] cur;
      synchronized (r.animator) {
         AnimMotion m = r.animator.motion;
         p = new float[]{m.pos[0] + (float) dx, m.pos[1] + (float) dy, m.pos[2] + 0f};
         cur = m.quat.clone();
      }
      float[] d = AnimMotion.axisAngle(0f, 0f, 1f, (float) ((double) dyaw * PI * INV_180));
      r.animator.moved(r.state, type, p, AnimMotion.mul(cur, d), AnimTime.ofMillis(time));
   }

   /**
    * DroneAnimator.update (0x00416740 -> FUN_00435520 -> FUN_00433710):
    * clump1/clump2 are the clumpIDs of the two WObjects (FUN_00412cf0; 0
    * if null). scale = 10 / (scaleX * (m00 * 1000)) (DAT_00475540,
    * DAT_0047552c), with m00 of the modeling matrix of the figure's first
    * child (the pelvis). PosableShape passes (null, this, getRealTime(),
    * getScaleX(), far): the last one is not used.
    */
   public static void update(int h, int clump1, int clump2, int time, float scaleX, boolean far) {
      Rep r = rep(h);
      if (r == null) {
         return;
      }
      float[] m = new float[16];
      NativeScene.getClumpMatrix(NativeScene.getFirstChild(clump2), m);
      float m1000 = m[0] * 1000.0F;
      float scale = 10.0F / (scaleX * m1000);
      r.animator.update(AnimTime.ofMillis(time), clump1, clump2, scale);
   }

   /**
    * FUN_00434470: applies a pose to the figure. Entries with key &lt; 3:
    * the root translation (key 2) x 0.1 (DAT_00475490) goes to row 3 of the
    * first child's modeling matrix, multiplied by its diagonal
    * (FUN_00431990); the root rotation (key 1) is not applied. Then, for
    * tags 1..30 in order, the joint whose id (FUN_00429880) matches the key
    * receives its quaternion if it is of type 4/5/6 (FUN_00434610:
    * RwFindTaggedClump + matrix from FUN_00427040 + RwTransformClumpJoint
    * replace); a tag with no entry receives the identity; an entry of
    * another type leaves the joint as it was. Null pose: all identity.
    */
   static void applyPose(AnimPose pose, int figure) {
      float[] ident = {1f, 0f, 0f, 0f};
      int tag = 1;
      if (pose != null) {
         java.util.List<AnimPose.Entry> es = pose.entries;
         int i = 0;
         for (; i < es.size() && es.get(i).key < 3; i++) {
            AnimPose.Entry e = es.get(i);
            if (e.key == 2) {
               int child = NativeScene.getFirstChild(figure);
               if (child != 0) {
                  float k = 0.1F;
                  rootTranslation(child, k * e.v[0], k * e.v[1], e.v[2] * k);
               }
            }
         }
         while (tag < 0x1f && i < es.size()) {
            AnimPose.Entry e = es.get(i);
            int id = AnimSeqCache.tagId(tag);
            if (e.key < id) {
               i++;
            } else if (e.key <= id) {
               if (e.kind == 4 || e.kind == 5 || e.kind == 6) {
                  setJoint(figure, tag, e.v);
               }
               tag++;
               i++;
            } else {
               setJoint(figure, tag, ident);
               tag++;
            }
         }
      }
      for (; tag < 0x1f; tag++) {
         setJoint(figure, tag, ident);
      }
   }

   /** FUN_00431990: row 3 of the modeling matrix = diagonal * v (RwTransformClump replace). */
   static void rootTranslation(int clump, float x, float y, float z) {
      if (clump == 0) {
         return;
      }
      float[] m = new float[16];
      NativeScene.getClumpMatrix(clump, m);
      m[12] = m[0] * x;
      m[13] = m[5] * y;
      m[14] = m[10] * z;
      NativeScene.transformClump(clump, m, NativeRw.REPLACE);
   }

   /** FUN_00434610 + FUN_00431870. */
   static void setJoint(int figure, int tag, float[] quat) {
      int c = NativeScene.findTaggedClump(figure, tag);
      if (c == 0) {
         return;
      }
      float[] q = quat.clone();
      AnimPose.normalize(q);
      NativeScene.transformClumpJoint(c, net.openworlds.bod.SeqSampler.quatToMatrix(q), NativeRw.REPLACE);
   }

   /**
    * DroneAnimator.prepFigure (0x00416470 -> FUN_00434f00): the figure's
    * joint matrix = scale 1000 (DAT_0047552c) times a 180-degree turn
    * (DAT_00475528) about (0,1,1) (DAT_00475524/20) (RwScaleMatrix mode 2
    * on top of RwRotateMatrix replace); the first child's translation goes
    * in front of that matrix (RwTranslateMatrix + RwTransformClumpJoint
    * mode 2) and the child's own is set to 0 (FUN_00431990). Then the point
    * (centre x, centre y, minimum z) of the tree's box in the world
    * (FUN_00435690 -> FUN_00418900: origin + RwGetClumpBBox of all of them,
    * 0.5 = DAT_00475544) is brought into the figure's coordinate system
    * (modeling inverse * parent's LTM) and subtracted after the joint (mode
    * 3); with COG = false, only the z.
    */
   public static void prepFigure(int clump, boolean cog) {
      if (clump == 0) {
         return;
      }
      if (AnimAnimator.LOG) {
         float[] l = new float[16];
         NativeScene.getClumpLTM(clump, l);
         System.out.println("[anim] prepFigure clump " + clump + " COG " + cog + " en (" + l[12] + "," + l[13] + "," + l[14] + ")");
      }
      float[] m1 = NativeRw.identity();
      float[] m2 = NativeRw.identity();
      NativeRw.rotate(m1, 0.0F, 1.0F, 1.0F, 180.0F, NativeRw.REPLACE);
      NativeRw.scale(m1, 1000.0F, 1000.0F, 1000.0F, NativeRw.PRECONCAT);
      NativeScene.transformClumpJoint(clump, m1, NativeRw.REPLACE);
      int child = NativeScene.getFirstChild(clump);
      if (child != 0) {
         float[] cm = new float[16];
         NativeScene.getClumpMatrix(child, cm);
         NativeRw.translate(m1, cm[12], cm[13], cm[14], NativeRw.REPLACE);
         NativeScene.transformClumpJoint(clump, m1, NativeRw.PRECONCAT);
         rootTranslation(child, 0f, 0f, 0f);
      }
      float[] box = treeBox(clump);
      float cx = (box[3] + box[0]) * 0.5F;
      float cy = (box[4] + box[1]) * 0.5F;
      float cz = box[2];
      NativeScene.getClumpMatrix(clump, m1);
      int parent = NativeScene.getClumpParent(clump);
      if (parent != 0) {
         NativeScene.getClumpLTM(parent, m2);
         NativeRw.transformMatrix(m1, m2, NativeRw.POSTCONCAT);
      }
      NativeRw.invert(m1, m2);
      float[] p = NativeRw.transformPoint(m2, cx, cy, cz);
      if (!cog) {
         p[1] = 0.0F;
         p[0] = 0.0F;
      }
      NativeRw.translate(m1, -p[0], -p[1], -p[2], NativeRw.REPLACE);
      NativeScene.transformClumpJoint(clump, m1, NativeRw.POSTCONCAT);
   }

   /**
    * FUN_00418900: min = max = RwGetClumpOrigin (translation of the LTM)
    * and then RwForAllClumpsInHierarchyPointer (children first, then the
    * clump itself) with the callback 0x418670, which grows the box with
    * each RwGetClumpBBox (min if it is smaller, max if it is larger).
    */
   static float[] treeBox(int clump) {
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[] b = {ltm[12], ltm[13], ltm[14], ltm[12], ltm[13], ltm[14]};
      grow(clump, b);
      return b;
   }

   private static void grow(int clump, float[] b) {
      for (int k : NativeScene.childHandles(clump)) {
         grow(k, b);
      }
      float[] c = NativeScene.getClumpBBox(clump);
      for (int j = 0; j < 3; j++) {
         if (c[j] < b[j]) {
            b[j] = c[j];
         }
         if (c[3 + j] > b[3 + j]) {
            b[3 + j] = c[3 + j];
         }
      }
   }
}

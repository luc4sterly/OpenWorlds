package net.freeworlds.world;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * Parser for .world files, reimplementing the real client's own generic
 * object-graph serialization protocol ("Persister"/Saver/Restorer) -
 * NOT a bespoke geometry format like RWX/RWG. Every fact below is taken
 * directly from the decompiled Java source (not inferred), primarily
 * NET.worlds.scape.{Restorer,Saver,SuperRoot,Transform,WObject,Shape,
 * World,Room,RoomEnvironment,Surface,Rect,Portal,...} - see
 * docs/world-format-reference.md for the full evidence trail, including
 * a byte-for-byte walkthrough of the real header against
 * assets/GROUNDZERO/GROUNDZERO.WORLD's hex dump.
 *
 * Container protocol (verified byte-exact against the real file header):
 * - UTF string "PERSISTER Worlds, Inc." (restoreString convention: 1
 *   byte bool "isNull" - always false here - then a 2-byte-length-
 *   prefixed UTF-8 string, i.e. exactly java.io.DataInputStream.readUTF).
 * - 4-byte int: persister format version (7 in the real file).
 * - A stream of "restore()" calls: each is [4-byte object id][if not
 *   already seen: 4-byte class id, and if THAT class id not already
 *   seen, the class name as a restoreString][the class's own
 *   restoreState fields, version-cookie-prefixed - see below].
 * - Ends with the UTF string "END PERSISTER".
 *
 * Critical, easy-to-miss detail verified from Restorer.restoreVersion():
 * each class's version int is read from the stream only ONCE per class
 * (cached thereafter for the rest of the file, keyed by a per-class
 * "cookie" - which in the real client is a static field, i.e. one cookie
 * per Java class). This class replicates that with `versionCache` keyed
 * by class name string.
 */
public final class WorldRestorer {
   static boolean DEBUG = "1".equals(System.getenv("WORLD_DEBUG"));

   private final DataInputStream in;
   private final int totalLength;
   private final int version;
   private final Map<Integer, String> classTable = new HashMap<>();
   private final Map<Integer, WNode> objectTable = new HashMap<>();
   private final Map<String, Integer> versionCache = new HashMap<>();

   private int pos() throws IOException {
      return totalLength - in.available();
   }

   private void trace(String label) throws IOException {
      if (DEBUG) {
         System.err.println("  [" + pos() + "] " + label);
      }
   }

   private WorldRestorer(byte[] data) throws IOException {
      this.totalLength = data.length;
      this.in = new DataInputStream(new ByteArrayInputStream(data));
      String header = restoreString();
      if (!"PERSISTER Worlds, Inc.".equals(header)) {
         throw new IOException("not a .world/.rwx persister file: bad header " + header);
      }
      this.version = in.readInt();
      if (version < 1) {
         throw new IOException("bad persister version " + version);
      }
   }

   public static WNode parse(byte[] data) throws IOException {
      WorldRestorer r = new WorldRestorer(data);
      WNode root = r.restore();
      String trailer = r.restoreString();
      if (!"END PERSISTER".equals(trailer)) {
         throw new IOException("format error: expected END PERSISTER trailer, got " + trailer);
      }
      return root;
   }

   // ---- primitive reads (java.io.DataInputStream matches the real
   // client's DataInput usage exactly - no custom decoding needed) ----

   private boolean restoreBoolean() throws IOException {
      return in.readBoolean();
   }

   private int restoreInt() throws IOException {
      return in.readInt();
   }

   private float restoreFloat() throws IOException {
      return in.readFloat();
   }

   private long restoreLong() throws IOException {
      return in.readLong();
   }

   private String restoreString() throws IOException {
      if (restoreBoolean()) {
         return null;
      }
      if (DEBUG) {
         int lenPos = pos();
         int len = in.readUnsignedShort();
         byte[] raw = new byte[len];
         in.readFully(raw);
         String s = new String(raw, java.nio.charset.StandardCharsets.ISO_8859_1);
         System.err.println("  [" + lenPos + "] readUTF len=" + len + " raw=" + s);
         return s;
      }
      return in.readUTF();
   }

   /** Restorer.restoreVersion(): read once per class, then cached for the rest of the file. version==1 files always return 0 (not expected in real content - implemented for completeness). */
   private int restoreVersion(String classKey) throws IOException {
      if (version == 1) {
         return 0;
      }
      Integer cached = versionCache.get(classKey);
      if (cached != null) {
         return cached;
      }
      int v = restoreInt();
      versionCache.put(classKey, v);
      if (DEBUG) {
         System.err.println("[" + pos() + "] version(" + classKey + ") = " + v);
      }
      return v;
   }

   private String restoreClassName() throws IOException {
      int classId = restoreInt();
      String name = classTable.get(classId);
      if (DEBUG) {
         System.err.println("[" + pos() + "] classId=" + classId + " cached=" + name);
      }
      if (name != null) {
         return name;
      }
      name = restoreString();
      classTable.put(classId, name);
      return name;
   }

   /** Restorer.restore(): the generic dispatch every Persister object goes through. */
   WNode restore() throws IOException {
      int objectId = restoreInt();
      WNode existing = objectTable.get(objectId);
      if (existing != null) {
         return existing;
      }
      String className = restoreClassName();
      if (DEBUG) {
         System.err.println("[" + pos() + "] restore#" + objectId + " " + className);
      }
      WNode node = new WNode(className);
      objectTable.put(objectId, node);
      readByClassName(className, node);
      return node;
   }

   private WNode restoreMaybeNull() throws IOException {
      return restoreBoolean() ? null : restore();
   }

   private java.util.List<WNode> restoreVector() throws IOException {
      int count = restoreInt();
      java.util.List<WNode> out = new java.util.ArrayList<>(count);
      for (int i = 0; i < count; i++) {
         out.add(restore());
      }
      return out;
   }

   private java.util.List<WNode> restoreVectorMaybeNull() throws IOException {
      return restoreBoolean() ? restoreVector() : null;
   }

   // ---- class name registry constants (as they appear in the real .world byte stream) ----
   private static final String C_SUPERROOT = "SuperRoot"; // no real Java class of this exact name is Persister-tagged in the stream (SuperRoot itself is abstract-ish base), cookie name chosen for our own cache key clarity
   private static final String C_TRANSFORM = "NET.worlds.scape.Transform";
   private static final String C_WOBJECT = "NET.worlds.scape.WObject";

   /**
    * Dispatch by fully-qualified class name, mirroring exactly what each
    * class's real restoreState() reads (see docs/world-format-reference.md
    * for the verbatim source this was checked against). Every class that
    * can appear in a real .world file's object graph MUST be handled here
    * or the byte stream desyncs silently - there is no generic
    * skip/length-prefix mechanism in this format.
    */
   private void readByClassName(String className, WNode node) throws IOException {
      switch (className) {
         case "NET.worlds.scape.World":
            readWorld(node);
            break;
         case "NET.worlds.core.Hashtable":
            readHashtable(node);
            break;
         case "NET.worlds.scape.WObject":
            // Plain WObject appears directly in real content as an
            // organizational/grouping node with no geometry of its own
            // (e.g. "WObVendMachine1" - a parent grouping several Shape/
            // Rect children into one vending machine prop).
            readWObject(node);
            break;
         case "NET.worlds.scape.Room":
            readRoom(node, "NET.worlds.scape.Room");
            break;
         case "NET.worlds.scape.WrStaircase":
            // WrStaircase.restoreState: super.restoreState(Room) then 1 extra float, no own version cookie.
            readRoom(node, "NET.worlds.scape.Room");
            restoreFloat();
            break;
         case "NET.worlds.scape.RoomEnvironment":
            readRoomEnvironment(node);
            break;
         case "NET.worlds.scape.Shape":
            readShape(node, "NET.worlds.scape.Shape");
            break;
         case "NET.worlds.scape.PosableShape":
            readPosableShape(node);
            break;
         case "NET.worlds.scape.Surface":
            readSurface(node, "NET.worlds.scape.Surface");
            break;
         case "NET.worlds.scape.Rect":
            readRect(node, "NET.worlds.scape.Rect");
            break;
         case "NET.worlds.scape.Portal":
            readPortal(node);
            break;
         case "NET.worlds.scape.WebPageWall":
            readWebPageWall(node);
            break;
         case "NET.worlds.scape.RectPatch":
            readRectPatch(node);
            break;
         case "NET.worlds.scape.Point3":
            readPoint3(node);
            break;
         case "NET.worlds.scape.Material":
            readMaterial(node);
            break;
         case "NET.worlds.scape.ScapePicTexture":
            readScapePicTexture(node);
            break;
         case "NET.worlds.scape.Sharer":
            readSharer(node);
            break;
         case "NET.worlds.scape.SwitchableBehavior":
            readSwitchableBehavior(node, "NET.worlds.scape.SwitchableBehavior");
            break;
         case "NET.worlds.scape.BuildStairs":
            readBuildStairs(node);
            break;
         case "NET.worlds.scape.Billboard":
            readBillboard(node);
            break;
         case "NET.worlds.scape.BumpSensor":
            readSensor(node, "NET.worlds.scape.Sensor");
            break;
         case "NET.worlds.scape.ClickSensor":
            readClickSensor(node);
            break;
         case "NET.worlds.scape.ProximitySensor":
            readProximitySensor(node);
            break;
         case "NET.worlds.scape.SameRoomSensor":
            readSameRoomSensor(node);
            break;
         case "NET.worlds.scape.StartupSensor":
            readStartupSensor(node);
            break;
         case "NET.worlds.scape.AnimateAction":
            readAnimateAction(node);
            break;
         case "NET.worlds.scape.MoveAction":
            readMoveAction(node);
            break;
         case "NET.worlds.scape.PosableAction":
            readPosableAction(node);
            break;
         case "NET.worlds.scape.RPAction":
            readAction(node, "NET.worlds.scape.Action");
            break;
         case "NET.worlds.scape.SelectAvatarAction":
            readSelectAvatarAction(node);
            break;
         case "NET.worlds.scape.SendURLAction":
            readSendURLAction(node);
            break;
         case "NET.worlds.scape.SequenceAction":
            readSequenceAction(node);
            break;
         case "NET.worlds.scape.SetVisibleBumpableAction":
            readSetVisibleBumpableAction(node);
            break;
         case "NET.worlds.scape.TeleportAction":
            readTeleportAction(node);
            break;
         case "NET.worlds.scape.WaitAction":
            readWaitAction(node);
            break;
         default:
            throw new IOException("unhandled .world class (byte stream would desync): " + className);
      }
   }

   // ---- SuperRoot / Transform / WObject: the base chain every spatial node goes through ----

   private void readSuperRoot(WNode node) throws IOException {
      int v = restoreVersion(C_SUPERROOT);
      switch (v) {
         case 0:
            // setOldFlag(), falls through to case 2 logic
         case 2:
            String name = restoreString();
            if (name != null) {
               node.name = name;
            }
            break;
         case 1:
            String name1 = restoreString();
            if (name1 != null) {
               node.name = name1;
            }
            restoreMaybeNull();
            break;
         default:
            throw new IOException("unknown SuperRoot version " + v);
      }
   }

   /**
    * ⚠️ VERIFICAR (evidence-based, not from source code - Transform's
    * native getGuts()/setGuts() are opaque, no Java-side field layout to
    * read): the raw 16 floats read from the file do NOT form a valid
    * OpenGL-ready affine matrix as-is. Two real, consistent problems
    * found by rendering real objects and comparing against known-sane
    * world positions:
    * 1. The 16th float (would-be homogeneous "w") is always 0.0 in
    *    every real sample checked, not 1.0 - left alone this collapses
    *    every transformed vertex's clip-space w toward 0, and the whole
    *    scene silently rendered as nothing (0 GL errors, real triangles
    *    submitted, nothing visible - diagnosed by hand-projecting a real
    *    vertex through the camera pipeline in Python).
    * 2. The 3x3 rotation/scale block, applied as read (raw file order
    *    interpreted directly as OpenGL's column-major convention),
    *    produced visibly degenerate/collapsed geometry once problem #1
    *    was fixed (real objects rendered as near-1D slivers instead of
    *    solid shapes) - consistent with the file storing this block in
    *    row-major order (a row-vector v' = v*M convention) while OpenGL
    *    expects column-major. Transposing the 3x3 block (translation,
    *    which is symmetric at these indices either way, is left as-is)
    *    produced correctly-proportioned real geometry - see
    *    docs/world-format-reference.md for the full evidence trail and
    *    screenshots.
    */
   /**
    * Real evidence for the matrix convention, found in the decompiled
    * client itself (not assumed):
    * - `Transform.printGuts()` (a real, non-native debug method) prints
    *   the 16 floats as `var2[var8*4+var5]` with `var8`=row (outer
    *   loop 0-3), `var5`=column (inner loop 0-3) - i.e. ROW-MAJOR
    *   storage, `index = row*4 + col`.
    * - `Transform.worldVecToObjectVec()` calls
    *   `Point3Temp.make(var1).vectorTimes(var2)` - a POINT is the
    *   receiver/left operand and the Transform/matrix is the argument,
    *   i.e. row-VECTOR semantics: v' = v * M (not the column-vector
    *   v' = M * v that OpenGL's own convention defaults to).
    *
    * With M stored row-major as `matrix[row*4+col]` and used as
    * `v' = v*M`, the OpenGL-ready column-major array for
    * `glMultMatrixf` (which computes `v' = G*v`) needs `G = M^T`. Column-
    * major storage of M^T is `Garray[col*4+row] = M^T[row][col] =
    * M[col][row] = matrix[col*4+row]` - IDENTICAL to the raw row-major
    * array's own indexing. So no transpose is needed: feeding the raw
    * 16 floats directly to `glMultMatrixf` already implements the real
    * client's `v*M` semantics correctly (confirmed: transposing this
    * block was tried in a previous session and made real geometry MORE
    * degenerate, consistent with this derivation - transposing would
    * have produced `v'=M*v`, the wrong convention).
    *
    * What DOES need fixing - found by comparing real parsed matrices
    * against the only 4 values a valid affine row-major matrix can have
    * outside its rotation/scale block: indices 3, 7, 11 (the last
    * column of rows 0-2, mathematically always 0 for an affine
    * transform) and 15 (row 3 col 3, always 1) are NOT reliably those
    * values in the real file - e.g. a real shared object
    * ("WObLOGO"/"Rect843cy", present in both Reception and
    * ReceptionView1 with byte-identical data) reads
    * matrix[3]=1.0021795E-38, matrix[7]=1.3061306E10, matrix[11]=0.125,
    * matrix[15]=0.0 - none of which are valid for an affine matrix.
    * This is consistent across every affected object (not per-context
    * noise), and only affects SOME objects (0 in IconViewRoom1, 1 in
    * Reception, many in ReceptionView1 - which is exactly why
    * IconViewRoom1/Reception rendered mostly fine while
    * ReceptionView1 rendered as degenerate garbage). The most likely
    * explanation: RenderWare's native "guts" representation is really a
    * compact 4x3 affine matrix (3x3 rotation/scale + 3x1 translation),
    * padded to 16 floats for the Java save format, and the padding
    * column was serialized straight from whatever was in native memory
    * at the time rather than being deliberately zeroed - i.e. this is a
    * real quirk/bug of the ORIGINAL client's own save format, not a
    * parsing error on this side. The real native renderer, using a 4x3
    * matrix internally, would never read that 4th column at all - so
    * forcing it to the only mathematically valid affine values ([0,0,0,1])
    * reproduces what the original client actually did, rather than
    * trusting uninitialized bytes it never used.
    */
   private static float[] fixMatrix(float[] m) {
      float[] r = m.clone();
      r[3] = 0.0f;
      r[7] = 0.0f;
      r[11] = 0.0f;
      r[15] = 1.0f;
      return r;
   }

   private void readTransform(WNode node) throws IOException {
      int v = restoreVersion(C_TRANSFORM);
      switch (v) {
         case 1:
            readSuperRoot(node);
            // fall through
         case 0: {
            float s = restoreFloat();
            node.xScale = node.yScale = node.zScale = s;
            float[] m = new float[16];
            for (int i = 0; i < 16; i++) {
               m[i] = restoreFloat();
            }
            node.matrix = fixMatrix(m);
            break;
         }
         case 2: {
            readSuperRoot(node);
            node.xScale = restoreFloat();
            node.yScale = restoreFloat();
            node.zScale = restoreFloat();
            float[] m = new float[16];
            for (int i = 0; i < 16; i++) {
               m[i] = restoreFloat();
            }
            node.matrix = fixMatrix(m);
            break;
         }
         default:
            throw new IOException("unknown Transform version " + v);
      }
   }

   /** WObject.restoreWObjectState - the version param is the real cookie key so subclasses (Room etc.) share WObject's own cache slot correctly. */
   private void readWObject(WNode node) throws IOException {
      int v = restoreVersion(C_WOBJECT);
      java.util.List<WNode> contents = null;
      switch (v) {
         case 0:
         case 1:
            readTransform(node);
            restoreInt(); // flags
            restoreMaybeNull();
            contents = restoreVectorMaybeNull();
            restoreVectorMaybeNull(); // handlers
            break;
         case 2:
         case 3:
            readTransform(node);
            restoreInt(); // flags
            contents = restoreVectorMaybeNull();
            restoreVectorMaybeNull(); // handlers
            restoreVectorMaybeNull(); // actions
            if (v == 3) {
               restore(); // bumpCalc-ish single object (see real source: var1.restore())
            }
            break;
         case 4:
            readTransform(node);
            restoreInt();
            contents = restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restore();
            restoreMaybeNull(); // sharer
            break;
         case 5:
         case 6:
         case 7:
         case 8:
            readTransform(node);
            restoreInt();
            contents = restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restoreMaybeNull(); // bumpCalc
            restoreMaybeNull(); // sharer
            if (v == 6) {
               restoreString();
            }
            break;
         case 9:
            readTransform(node);
            restoreInt();
            contents = restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restoreVectorMaybeNull();
            restoreMaybeNull();
            restoreMaybeNull();
            restoreString(); // tooltip
            break;
         case 10:
            readTransform(node);
            trace("after transform");
            restoreInt();
            trace("after flags");
            contents = restoreVectorMaybeNull();
            trace("after contents");
            restoreVectorMaybeNull();
            trace("after handlers");
            restoreVectorMaybeNull();
            trace("after actions");
            restoreMaybeNull();
            trace("after bumpCalc");
            restoreMaybeNull();
            trace("after sharer");
            restoreString();
            trace("after tooltip");
            restoreBoolean(); // mouseOver
            trace("after mouseOver");
            break;
         default:
            throw new IOException("unknown WObject version " + v);
      }
      if (contents != null) {
         node.children.addAll(contents);
      }
   }

   // ---- concrete spatial classes ----

   private void readShape(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 0:
         case 1:
            readWObject(node);
            String url = restoreUrlString();
            if (url != null) {
               node.geometryUrl = url;
            }
            break;
         default:
            throw new IOException("unknown Shape version " + v);
      }
   }

   /** URL.restore(Restorer): just a plain restoreString() - resolution against the world's own base URL happens outside this class (see WorldModelLoader). */
   private String restoreUrlString() throws IOException {
      return restoreString();
   }

   private void readPosableShape(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.PosableShape");
      switch (v) {
         case 1:
            restoreBoolean(); // COG
            // fall through
         case 0:
            readShape(node, "NET.worlds.scape.Shape");
            break;
         default:
            throw new IOException("unknown PosableShape version " + v);
      }
   }

   private void readSurface(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 0:
            readWObject(node);
            // Material.restore(var1) internally does restoreMaybeNull() (see Material.restore static helper) - a leading bool IS present here.
            restoreMaybeNull();
            break;
         case 1:
            readWObject(node);
            // real source: `this.setMaterial((Material)var1.restore());` - a DIRECT restore(), no leading maybe-null bool (unlike case 0's Material.restore() helper).
            restore();
            break;
         default:
            throw new IOException("unknown Surface version " + v);
      }
   }

   private void readRect(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 0:
         case 1:
            readSurface(node, "NET.worlds.scape.Surface");
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            break;
         case 2:
            readSurface(node, "NET.worlds.scape.Surface");
            restoreFloat();
            restoreFloat();
            break;
         case 3:
            readSurface(node, "NET.worlds.scape.Surface");
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            break;
         case 4:
            readSurface(node, "NET.worlds.scape.Surface");
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreBoolean();
            break;
         default:
            throw new IOException("unknown Rect version " + v);
      }
   }

   private void readPortal(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.Portal");
      if (v >= 0 && v <= 7) {
         // superRestoreState: WObject chain directly (skips Rect/Surface material setup, sets a default black material)
         readWObject(node);
         if (v < 6) {
            if (v == 0) {
               restoreInt();
            }
            restoreFloat();
            restoreFloat();
            restoreFloat();
         }
         restoreBoolean();
         if (v >= 4) {
            restoreString(); // farSidePortalName
         }
         restoreMaybeNull(); // farSidePortal
         if (v == 1) {
            restoreString();
         } else if (v >= 3) {
            restoreString(); // farSideWorld URL (restoreUrlString, always just a string)
            restoreString(); // farSideRoomName
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreMaybeNull(); // Material.restore(var1) #1
            restoreMaybeNull(); // Material.restore(var1) #2
            if (v >= 5) {
               restoreBoolean();
            }
         }
      } else if (v == 8 || v == 9) {
         readRect(node, "NET.worlds.scape.Rect");
         restoreBoolean(); // farSideIsPortal
         if (v >= 9) {
            restoreBoolean(); // allowDownload
         }
         restoreString(); // farSidePortalName
         restoreMaybeNull(); // farSidePortal
         restoreString(); // farSideWorld
         restoreString(); // farSideRoomName
         restoreFloat();
         restoreFloat();
         restoreFloat();
         restoreFloat();
      } else {
         throw new IOException("unknown Portal version " + v);
      }
   }

   private void readWebPageWall(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.WebPageWall");
      if (v < 1 || v > 3) {
         throw new IOException("unknown WebPageWall version " + v);
      }
      readRect(node, "NET.worlds.scape.Rect");
      restoreString();
      restoreString();
      restoreInt();
      restoreInt();
      restoreBoolean();
      restoreBoolean();
      restoreInt();
      restoreInt();
      restoreInt();
      restoreBoolean();
      restoreBoolean();
      if (v >= 2) {
         restoreString();
      }
      if (v >= 3) {
         restoreString();
      }
   }

   private void readRectPatch(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.RectPatch");
      switch (v) {
         case 0:
            readWObject(node);
            restoreFloat();
            restoreFloat();
            for (int i = 0; i < 4; i++) {
               restoreFloat();
            }
            break;
         case 1:
            readWObject(node);
            restoreFloat();
            restoreFloat();
            for (int i = 0; i < 4; i++) {
               restoreFloat();
            }
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreMaybeNull(); // Material.restore(var1) - has an internal leading bool
            restoreMaybeNull();
            restoreMaybeNull();
            restoreMaybeNull();
            restoreMaybeNull();
            break;
         case 2:
            readWObject(node);
            restoreFloat();
            restoreFloat();
            for (int i = 0; i < 4; i++) {
               restoreFloat();
            }
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreMaybeNull(); // Material.restore(var1)
            break;
         default:
            throw new IOException("unknown RectPatch version " + v);
      }
   }

   // ---- Room / RoomEnvironment ----

   private void readRoom(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      readWObject(node);
      switch (v) {
         case 0:
            node.name = restoreString();
            restore();
            if (restoreBoolean()) {
               node.skyColorRGB = restoreInt();
            }
            if (restoreBoolean()) {
               node.groundColorRGB = restoreInt();
            }
            restoreMaybeNull();
            restore(); // defaultPosition
            restore(); // defaultOrientationAxis
            restoreFloat();
            restoreVector();
            restore(); // environment
            break;
         case 1:
         case 2:
            if (restoreBoolean()) {
               node.skyColorRGB = restoreInt();
            }
            if (restoreBoolean()) {
               node.groundColorRGB = restoreInt();
            }
            restoreMaybeNull();
            restore();
            restore();
            restoreFloat();
            restore(); // environment
            break;
         case 3:
         case 4:
            if (restoreBoolean()) {
               node.skyColorRGB = restoreInt();
            }
            if (restoreBoolean()) {
               node.groundColorRGB = restoreInt();
            }
            if (v == 3) {
               restoreMaybeNull();
            }
            restore();
            restore();
            restoreFloat();
            restore(); // environment
            restore(); // infiniteBackground
            break;
         case 5:
         case 6:
         case 7:
            if (restoreBoolean()) {
               node.skyColorRGB = restoreInt();
            }
            trace("Room: after skyColor");
            if (restoreBoolean()) {
               node.groundColorRGB = restoreInt();
            }
            trace("Room: after groundColor");
            restore(); // defaultPosition
            trace("Room: after defaultPosition");
            restore(); // defaultOrientationAxis
            trace("Room: after defaultOrientationAxis");
            restoreFloat();
            trace("Room: after defaultOrientation");
            WNode lightPos = restore(); // Room.lightPosition
            trace("Room: after lightPosition");
            if (lightPos != null) {
               node.lightPosition = new float[]{lightPos.x, lightPos.y, lightPos.z};
            }
            node.lightColorRGB = restoreInt();
            trace("Room: after lightColor");
            restore(); // environment
            trace("Room: after environment");
            restore(); // infiniteBackground
            trace("Room: after infiniteBackground");
            if (v >= 6) {
               restoreString(); // teleportChain
               trace("Room: after teleportChain");
               restoreInt(); // teleportInterval
               trace("Room: after teleportInterval");
            }
            if (v == 7) {
               restoreBoolean(); // allowTeleport
               trace("Room: after allowTeleport");
            }
            break;
         default:
            throw new IOException("unknown Room version " + v);
      }
   }

   private void readRoomEnvironment(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.RoomEnvironment");
      readWObject(node);
      if (v == 0) {
         restore();
      } else if (v != 1) {
         throw new IOException("unknown RoomEnvironment version " + v);
      }
   }

   // ---- World / Hashtable ----

   private void readWorld(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.World");
      readSuperRoot(node);
      node.defaultRoomName = restoreString();
      if (v == 7) {
         String worldServer = restoreString(); // URL.restore
         restoreInt(); // timeoutAge
         restoreBoolean();
      } else if (v >= 8) {
         restoreString(); // worldServerURL
         restoreInt();
         restoreBoolean(); // multiuser
         if (v > 9) {
            restoreBoolean();
         }
         if (v > 10) {
            restoreBoolean();
         }
         if (v > 11) {
            restoreBoolean();
            restoreInt();
            restoreInt();
            restoreString();
         }
         if (v > 12) {
            restoreBoolean();
            restoreBoolean();
            restoreString();
            restoreString();
         }
      } else {
         throw new IOException("unsupported old World version " + v + " (pre-7, restoreOldURL path not implemented - real corpus didn't need it)");
      }
      WNode roomHash = restore();
      node.roomsByName.putAll(roomHash.roomsByName);
   }

   private void readHashtable(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.core.Hashtable");
      if (v != 0) {
         throw new IOException("unknown Hashtable version " + v);
      }
      int count = restoreInt();
      for (int i = 0; i < count; i++) {
         String key;
         if (restoreBoolean()) {
            key = restoreString();
         } else {
            key = restore().toString();
         }
         WNode value = restore();
         if (key != null) {
            node.roomsByName.put(key, value);
         }
      }
   }

   // ---- leaf value types ----

   private void readPoint3(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.Point3");
      if (v != 0) {
         throw new IOException("unknown Point3 version " + v);
      }
      node.x = restoreFloat();
      node.y = restoreFloat();
      node.z = restoreFloat();
   }

   private void readMaterial(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.Material");
      switch (v) {
         case 0:
         case 1:
            if (v == 1) {
               readSuperRoot(node);
            }
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreInt();
            restoreInt();
            restoreInt();
            restoreMaybeNull();
            break;
         case 2:
         case 3:
         case 4:
            readSuperRoot(node);
            restoreFloat();
            restoreFloat();
            restoreFloat();
            restoreFloat();
            if (v > 3) {
               restoreBoolean();
               restoreBoolean();
            }
            restoreInt();
            restoreInt();
            restoreInt();
            String texUrl = restoreString();
            if (v > 2) {
               restoreBoolean();
            }
            if (texUrl == null) {
               restoreMaybeNull();
            }
            break;
         default:
            throw new IOException("unknown Material version " + v);
      }
   }

   private void readScapePicTexture(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.ScapePicTexture");
      switch (v) {
         case 0:
            readTexture();
            restoreBoolean();
            break;
         case 1:
            readTexture();
            break;
         default:
            throw new IOException("unknown ScapePicTexture version " + v);
      }
      if (restoreBoolean()) {
         restore(); // movie
         restoreInt(); // movieFrame
      } else {
         restoreString(); // urlName
      }
   }

   private void readTexture() throws IOException {
      int v = restoreVersion("NET.worlds.scape.Texture");
      if (v != 0) {
         throw new IOException("unknown Texture version " + v);
      }
   }

   // ---- auxiliary WObject-adjacent classes ----

   private void readSharer(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.Sharer");
      switch (v) {
         case 0:
            node.name = restoreString();
            int n = restoreInt();
            for (int i = 0; i < n; i++) {
               restoreString();
            }
            break;
         case 1:
            node.name = restoreString();
            restoreVector();
            break;
         case 2:
            readSuperRoot(node);
            restoreVector();
            break;
         default:
            throw new IOException("unknown Sharer version " + v);
      }
   }

   private void readSwitchableBehavior(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 1:
            readSuperRoot(node);
            // fall through
         case 0:
            restoreBoolean();
            break;
         default:
            throw new IOException("unknown SwitchableBehavior version " + v);
      }
   }

   private void readBuildStairs(WNode node) throws IOException {
      // No version cookie at all in the real source - fields read directly.
      restoreBoolean();
      restoreString();
      restoreFloat();
      restoreFloat();
      restoreFloat();
      restoreFloat();
      restoreFloat();
      restoreFloat();
      restoreInt();
   }

   // ---- Sensor / Attribute / Billboard ----

   private void readSensor(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 1:
         case 2:
            readSuperRoot(node);
            // fall through
         case 0:
            restoreVector(); // actions
            break;
         default:
            throw new IOException("unknown Sensor version " + v);
      }
   }

   private void readClickSensor(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.ClickSensor");
      switch (v) {
         case 0:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreInt();
            break;
         case 1:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreInt();
            restoreBoolean();
            break;
         case 2:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreInt();
            restoreBoolean();
            restoreString();
            break;
         default:
            throw new IOException("unknown ClickSensor version " + v);
      }
   }

   private void readProximitySensor(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.ProximitySensor");
      switch (v) {
         case 1:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreBoolean();
            restoreBoolean();
            restore();
            restore();
            break;
         case 2:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreBoolean();
            restoreBoolean();
            restoreBoolean();
            restore();
            restore();
            break;
         default:
            throw new IOException("unknown ProximitySensor version " + v);
      }
   }

   private void readSameRoomSensor(WNode node) throws IOException {
      int v = readSensorVers(node, "NET.worlds.scape.Sensor");
      if (v > 1) {
         int v2 = restoreVersion("NET.worlds.scape.SameRoomSensor");
         if (v2 != 0) {
            throw new IOException("unknown SameRoomSensor version " + v2);
         }
      }
   }

   /** Sensor.restoreStateVers - like readSensor but returns the version int (SameRoomSensor needs it). */
   private int readSensorVers(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 1:
         case 2:
            readSuperRoot(node);
         case 0:
            restoreVector();
            return v;
         default:
            throw new IOException("unknown Sensor version " + v);
      }
   }

   private void readStartupSensor(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.StartupSensor");
      if (v != 0) {
         throw new IOException("unknown StartupSensor version " + v);
      }
      readSensor(node, "NET.worlds.scape.Sensor");
   }

   private void readAttribute(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 0:
            restoreInt();
            if (restoreBoolean()) {
               restoreInt();
            } else {
               restoreInt();
            }
            break;
         case 1:
         case 2:
            restoreInt();
            restoreInt();
            if (v == 2) {
               restoreInt();
            }
            break;
         case 3:
         case 4:
            readSuperRoot(node);
            restoreInt();
            restoreInt();
            restoreInt();
            if (v == 4) {
               restoreInt();
            }
            break;
         case 5:
            readSensor(node, "NET.worlds.scape.Sensor");
            restoreInt();
            restoreInt();
            restoreInt();
            restoreInt();
            break;
         default:
            throw new IOException("unknown Attribute version " + v);
      }
   }

   private void readBillboard(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.Billboard");
      if (v < 0 || v > 3) {
         throw new IOException("unknown Billboard version " + v);
      }
      readAttribute(node, "NET.worlds.scape.Attribute");
      restoreString();
      restoreString();
      restoreInt();
      restoreInt();
      restoreBoolean();
      if (v >= 1) {
         restoreBoolean();
      }
      if (v >= 2) {
         restoreInt();
         restoreInt();
         restoreInt();
         restoreBoolean();
      }
      if (v >= 3) {
         restoreBoolean(); // isAdBanner
      }
   }

   // ---- Action family ----

   private void readAction(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      switch (v) {
         case 1:
            restoreInt();
            node.name = restoreString();
            // fall through
         case 0:
            // setOldFlag, nothing else
            break;
         case 2:
            readSuperRoot(node);
            restoreInt();
            break;
         case 4:
            restoreString(); // rightMenuLabel
            // fall through
         case 3:
            readSuperRoot(node);
            break;
         default:
            throw new IOException("unknown Action version " + v);
      }
   }

   private void readDialogAction(WNode node, String cookieKey) throws IOException {
      int v = restoreVersion(cookieKey);
      if (v != 0) {
         throw new IOException("unknown DialogAction version " + v);
      }
      readAction(node, "NET.worlds.scape.Action");
      restoreBoolean();
      restoreBoolean();
   }

   private void readAnimateAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.AnimateAction");
      switch (v) {
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            // fall through
         case 0:
            restoreFloat();
            restoreInt();
            restoreString();
            break;
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restoreInt();
            restoreInt();
            restoreString();
            break;
         case 3:
            readAction(node, "NET.worlds.scape.Action");
            restoreBoolean();
            restoreInt();
            restoreInt();
            restoreString();
            break;
         default:
            throw new IOException("unknown AnimateAction version " + v);
      }
   }

   private void readMoveAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.MoveAction");
      switch (v) {
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            // fall through
         case 0:
            restoreFloat();
            restoreInt();
            restore();
            restore();
            restore();
            restore();
            restore();
            restore();
            restoreFloat();
            restoreFloat();
            break;
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restoreInt();
            restoreInt();
            restore();
            restore();
            restore();
            restore();
            restore();
            restore();
            restoreFloat();
            restoreFloat();
            restoreBoolean();
            break;
         case 3:
         case 4:
            readAction(node, "NET.worlds.scape.Action");
            restoreInt();
            restoreInt();
            restore();
            restore();
            restore();
            restore();
            restore();
            restore();
            restoreFloat();
            restoreFloat();
            break;
         case 5:
            readAction(node, "NET.worlds.scape.Action");
            restoreInt();
            restoreInt();
            restore();
            restore();
            restore();
            restore();
            restore();
            restore();
            restoreFloat();
            restoreFloat();
            restoreBoolean();
            break;
         case 6:
            readAction(node, "NET.worlds.scape.Action");
            restoreBoolean();
            restoreInt();
            restoreInt();
            restore();
            restore();
            restore();
            restore();
            restore();
            restore();
            restoreFloat();
            restoreFloat();
            restoreBoolean();
            break;
         default:
            throw new IOException("unknown MoveAction version " + v);
      }
   }

   private void readPosableAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.PosableAction");
      if (v != 0) {
         throw new IOException("unknown PosableAction version " + v);
      }
      readAction(node, "NET.worlds.scape.Action");
      restoreString();
   }

   private void readSelectAvatarAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.SelectAvatarAction");
      switch (v) {
         case 0:
            readAction(node, "NET.worlds.scape.Action");
            restoreString();
            break;
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            restoreString();
            restoreBoolean();
            break;
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restoreString();
            restoreBoolean();
            restoreBoolean();
            break;
         case 3:
         case 4:
            readDialogAction(node, "NET.worlds.scape.DialogAction");
            restoreString();
            if (v >= 4) {
               restoreString();
            }
            break;
         default:
            throw new IOException("unknown SelectAvatarAction version " + v);
      }
   }

   private void readSendURLAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.SendURLAction");
      switch (v) {
         case 1:
            restoreBoolean();
            restoreString();
            restoreString();
            break;
         case 2:
            restoreBoolean();
            restoreString();
            break;
         case 3:
            // dialogActionSkipRestore(var1) = Action.restoreState() directly, bypassing DialogAction's own showDialog/cancelOnly fields.
            readAction(node, "NET.worlds.scape.Action");
            restoreBoolean();
            restoreString();
            break;
         case 4:
            readAction(node, "NET.worlds.scape.Action");
            restoreString();
            break;
         case 5:
            readAction(node, "NET.worlds.scape.Action");
            restoreString();
            restoreBoolean();
            restoreBoolean();
            break;
         case 6:
            // real source: `super.restoreState(var1)` here IS DialogAction.restoreState() (SendURLAction extends DialogAction) - includes its own version cookie + showDialog/cancelOnly bools, unlike the dialogActionSkipRestore() path used by cases 3-5.
            readDialogAction(node, "NET.worlds.scape.DialogAction");
            restoreString();
            restoreString();
            restoreBoolean();
            restoreBoolean();
            break;
         case 7:
            readDialogAction(node, "NET.worlds.scape.DialogAction");
            restoreString();
            restoreString();
            restoreString();
            restoreString();
            restoreBoolean();
            restoreBoolean();
            break;
         case 8:
            readDialogAction(node, "NET.worlds.scape.DialogAction");
            restoreString();
            restoreString();
            restoreString();
            restoreString();
            restoreBoolean();
            restoreBoolean();
            break;
         case 9:
            readDialogAction(node, "NET.worlds.scape.DialogAction");
            restoreString();
            restoreString();
            restoreString();
            restoreString();
            restoreBoolean();
            restoreString();
            break;
         default:
            throw new IOException("unknown SendURLAction version " + v);
      }
   }

   private void readSequenceAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.SequenceAction");
      switch (v) {
         case 0:
            readAction(node, "NET.worlds.scape.Action");
            restoreVector();
            restoreInt();
            restoreBoolean();
            break;
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            restoreVector();
            restoreInt();
            break;
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restoreBoolean();
            restoreVector();
            restoreInt();
            break;
         default:
            throw new IOException("unknown SequenceAction version " + v);
      }
   }

   private void readSetVisibleBumpableAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.SetVisibleBumpableAction");
      switch (v) {
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            // fall through
         case 0:
            restoreBoolean();
            restoreBoolean();
            break;
         default:
            throw new IOException("unknown SetVisibleBumpableAction version " + v);
      }
   }

   private void readTeleportAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.TeleportAction");
      switch (v) {
         case 0:
            readAction(node, "NET.worlds.scape.Action");
            restore();
            restoreInt();
            restoreString();
            restoreString();
            restoreBoolean();
            break;
         case 1:
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restore();
            restoreFloat();
            restore();
            restoreString();
            restoreString();
            restoreBoolean();
            break;
         case 3:
            readAction(node, "NET.worlds.scape.Action");
            restore();
            restoreFloat();
            restore();
            restoreString();
            restoreString();
            restoreBoolean();
            restoreString();
            break;
         default:
            throw new IOException("unknown TeleportAction version " + v);
      }
   }

   private void readWaitAction(WNode node) throws IOException {
      int v = restoreVersion("NET.worlds.scape.WaitAction");
      switch (v) {
         case 0:
            readAction(node, "NET.worlds.scape.Action");
            restoreInt();
            break;
         case 1:
            readAction(node, "NET.worlds.scape.Action");
            restoreFloat();
            restoreLong();
            break;
         case 2:
            readAction(node, "NET.worlds.scape.Action");
            restoreFloat();
            break;
         default:
            throw new IOException("unknown WaitAction version " + v);
      }
   }
}

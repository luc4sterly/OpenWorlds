package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * Portable RenderWare 2.1 scene objects (clumps, scenes, lights, materials)
 * that gamma.dll's scape natives build through RWL21.DLL. Each static
 * method is named after the RW call that the corresponding gamma.dll
 * wrapper makes (map: gamma.dll FUN_004188xx..0041a0xx = EnterCriticalSection
 * + one Rw* call). Handles share NativeRw's 1-based table.
 *
 * Only state is kept here; drawing is a separate step.
 */
public final class NativeScene {
   private NativeScene() {
   }

   public static final class Clump {
      Clump parent;
      final List<Clump> children = new ArrayList<Clump>();
      Scene scene;
      final float[] modeling = NativeRw.identity();
      final float[] joint = NativeRw.identity();
      int tag;
      Object data;
      /** RWL21 10003d60: new clumps are ON (2); 1 = OFF. */
      int state = 2;
      /** Local bbox corners, +-FLT_MAX until a vertex is added (10041cb0). */
      final float[] bbox = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
      int hints = 2;
      /** x, y, z, u, v per vertex; RW vertex indices are 1-based. */
      final List<float[]> verts = new ArrayList<float[]>();
      final List<Polygon> polys = new ArrayList<Polygon>();
      int handle;
   }

   public static final class Polygon {
      final Clump clump;
      final int[] indices;
      int material;
      int handle;

      Polygon(Clump c, int[] idx) {
         this.clump = c;
         this.indices = idx;
      }
   }

   public static final class Scene {
      Object data;
      final List<Clump> clumps = new ArrayList<Clump>();
      final List<Light> lights = new ArrayList<Light>();
      int handle;
   }

   public static final class Light {
      int type;
      final float[] vector = new float[3];
      final float[] color = {1, 1, 1};
      float coneAngle;
      int state = 2;
      Scene scene;
      int handle;
   }

   public static final class Material {
      final float[] color = new float[3];
      float ambient;
      float diffuse;
      float specular;
      float opacity = 1.0F;
      int textureModes = 1;
      /** RW material modes: 0x80 = double sided (RWL21 10051000). */
      int materialModes;
      int lightSampling = 1;
      int refs = 1;
      int texture;
      int handle;
   }

   private static <T> T obj(int h, Class<T> c) {
      Object o = NativeRw.get(h);
      return c.isInstance(o) ? c.cast(o) : null;
   }

   public static Clump clump(int h) {
      return obj(h, Clump.class);
   }

   public static Scene scene(int h) {
      return obj(h, Scene.class);
   }

   public static Material material(int h) {
      return obj(h, Material.class);
   }

   public static Light light(int h) {
      return obj(h, Light.class);
   }

   public static Polygon polygon(int h) {
      return obj(h, Polygon.class);
   }

   // ------------------------------------------------------------ clumps

   /** RwCreateClump(maxVerts, maxPolys). */
   public static int createClump() {
      Clump c = new Clump();
      c.handle = NativeRw.alloc(c);
      return c.handle;
   }

   /** RwAddVertexToClump(clump, x, y, z): returns the 1-based vertex index. */
   public static int addVertex(int h, float x, float y, float z) {
      Clump c = clump(h);
      if (c == null) {
         return 0;
      }
      c.verts.add(new float[]{x, y, z, 0.0F, 0.0F});
      float[] v = {x, y, z};
      for (int i = 0; i < 3; i++) {
         c.bbox[i] = Math.min(c.bbox[i], v[i]);
         c.bbox[3 + i] = Math.max(c.bbox[3 + i], v[i]);
      }
      c.hints |= 4;
      return c.verts.size();
   }

   /** RwSetClumpVertexUV(clump, index, u, v). */
   public static void setVertexUV(int h, int index, float u, float v) {
      Clump c = clump(h);
      if (c != null && index >= 1 && index <= c.verts.size()) {
         float[] vx = c.verts.get(index - 1);
         vx[3] = u;
         vx[4] = v;
      }
   }

   /** RwGetClumpVertex(clump, index, out xyz). */
   public static float[] getVertex(int h, int index) {
      Clump c = clump(h);
      if (c != null && index >= 1 && index <= c.verts.size()) {
         float[] vx = c.verts.get(index - 1);
         return new float[]{vx[0], vx[1], vx[2]};
      }
      return new float[3];
   }

   /** RwGetClumpVertexUV(clump, index, out uv). */
   public static float[] getVertexUV(int h, int index) {
      Clump c = clump(h);
      if (c != null && index >= 1 && index <= c.verts.size()) {
         float[] vx = c.verts.get(index - 1);
         return new float[]{vx[3], vx[4]};
      }
      return new float[2];
   }

   /**
    * RwAddPolygonToClump(clump, nSides, indices) (RWL21 10003830): 1-based
    * indices; consecutive repeats and a last index equal to the first are
    * dropped; fewer than 3 sides left -> NULL. Returns the polygon.
    */
   public static int addPolygon(int h, int n, int[] indices) {
      Clump c = clump(h);
      if (c == null) {
         return 0;
      }
      int[] tmp = new int[n];
      int k = 0;
      for (int i = 0; i < n; i++) {
         if (indices[i] < 1 || indices[i] > c.verts.size()) {
            return 0;
         }
         if (k == 0 || tmp[k - 1] != indices[i]) {
            tmp[k++] = indices[i];
         }
      }
      if (k > 1 && tmp[k - 1] == tmp[0]) {
         k--;
      }
      if (k < 3) {
         return 0;
      }
      int[] idx = new int[k];
      System.arraycopy(tmp, 0, idx, 0, k);
      Polygon p = new Polygon(c, idx);
      c.polys.add(p);
      c.hints |= 4;
      p.handle = NativeRw.alloc(p);
      return p.handle;
   }

   /** RwSetPolygonMaterial(polygon, material). */
   public static void setPolygonMaterial(int poly, int mat) {
      Polygon p = polygon(poly);
      if (p != null) {
         p.material = mat;
      }
   }

   /** RwGetClumpNumVertices. */
   public static int getNumVertices(int h) {
      Clump c = clump(h);
      return c == null ? 0 : c.verts.size();
   }

   public static void setClumpData(int h, Object data) {
      Clump c = clump(h);
      if (c != null) {
         c.data = data;
      }
   }

   public static Object getClumpData(int h) {
      Clump c = clump(h);
      return c == null ? null : c.data;
   }

   public static void setClumpHints(int h, int hints) {
      Clump c = clump(h);
      if (c != null) {
         c.hints = hints;
      }
   }

   public static void setClumpState(int h, int state) {
      Clump c = clump(h);
      if (c != null) {
         c.state = state;
      }
   }

   public static int getClumpState(int h) {
      Clump c = clump(h);
      return c == null ? 0 : c.state;
   }

   public static int getClumpTag(int h) {
      Clump c = clump(h);
      return c == null ? 0 : c.tag;
   }

   public static void setClumpTag(int h, int tag) {
      Clump c = clump(h);
      if (c != null) {
         c.tag = tag;
      }
   }

   /** RwFindTaggedClump(clump, tag): depth-first over the hierarchy. */
   public static int findTaggedClump(int h, int tag) {
      Clump c = clump(h);
      Clump f = c == null ? null : findTagged(c, tag);
      return f == null ? 0 : f.handle;
   }

   private static Clump findTagged(Clump c, int tag) {
      if (c.tag == tag) {
         return c;
      }
      for (Clump k : c.children) {
         Clump f = findTagged(k, tag);
         if (f != null) {
            return f;
         }
      }
      return null;
   }

   public static int getClumpParent(int h) {
      Clump c = clump(h);
      return c == null || c.parent == null ? 0 : c.parent.handle;
   }

   public static int getClumpNumChildren(int h) {
      Clump c = clump(h);
      return c == null ? 0 : c.children.size();
   }

   /**
    * RwAddChildToClump(parent, child) (RWL21 10004500): unhooks the child
    * from any previous parent, appends it, and moves the child's whole
    * subtree into the parent's scene.
    */
   public static void addChildToClump(int parent, int child) {
      Clump p = clump(parent);
      Clump c = clump(child);
      if (p == null || c == null) {
         return;
      }
      removeChildFromClump(child);
      c.parent = p;
      p.children.add(c);
      moveTree(c, p.scene);
   }

   /** RwRemoveChildFromClump(child) (RWL21 10004120): stays in its scene. */
   public static void removeChildFromClump(int child) {
      Clump c = clump(child);
      if (c != null && c.parent != null) {
         c.parent.children.remove(c);
         c.parent = null;
      }
   }

   /** Scene bookkeeping (RWL21 1002c120 / 1002baf0); null = RwDefaultScene. */
   private static void moveTree(Clump c, Scene s) {
      if (c.scene != s) {
         if (c.scene != null) {
            c.scene.clumps.remove(c);
         }
         c.scene = s;
         if (s != null) {
            s.clumps.add(c);
         }
      }
      for (Clump k : c.children) {
         moveTree(k, s);
      }
   }



   /**
    * RwGetClumpOwner (RWL21 1002c540): the clump's own scene; 0 stands for
    * RwDefaultScene, whose data is never set by gamma.dll.
    */
   public static int getClumpOwner(int h) {
      Clump c = clump(h);
      return c == null || c.scene == null ? 0 : c.scene.handle;
   }

   /** RwTransformClump(clump, matrix, mode): the modeling matrix. */
   public static void transformClump(int h, float[] m, int mode) {
      Clump c = clump(h);
      if (c != null) {
         NativeRw.transformMatrix(c.modeling, m, mode);
      }
   }

   /** RwTransformClumpJoint(clump, matrix, mode): the joint matrix. */
   public static void transformClumpJoint(int h, float[] m, int mode) {
      Clump c = clump(h);
      if (c != null) {
         NativeRw.transformMatrix(c.joint, m, mode);
      }
   }

   /** RwGetClumpMatrix(clump, out). */
   public static void getClumpMatrix(int h, float[] out) {
      Clump c = clump(h);
      System.arraycopy(c == null ? NativeRw.identity() : c.modeling, 0, out, 0, 16);
   }

   /** RwGetClumpLTM(clump, out) (RWL21 100047d0): root Joint.Modeling, child Joint.Modeling.ParentLTM. */
   public static void getClumpLTM(int h, float[] out) {
      Clump c = clump(h);
      System.arraycopy(c == null ? NativeRw.identity() : ltm(c), 0, out, 0, 16);
   }

   static float[] ltm(Clump c) {
      float[] m = NativeRw.mul(c.joint, c.modeling);
      return c.parent == null ? m : NativeRw.mul(m, ltm(c.parent));
   }

   /** RwDestroyClump (RWL21 10004240): unhooks, destroys all children, leaves its scene. */
   public static void destroyClump(int h) {
      Clump c = clump(h);
      if (c == null) {
         return;
      }
      removeChildFromClump(h);
      destroyTree(c);
   }

   private static void destroyTree(Clump c) {
      for (Clump k : new ArrayList<Clump>(c.children)) {
         k.parent = null;
         destroyTree(k);
      }
      c.children.clear();
      if (c.scene != null) {
         c.scene.clumps.remove(c);
         c.scene = null;
      }
      for (Polygon p : c.polys) {
         NativeRw.release(p.handle);
      }
      NativeRw.release(c.handle);
   }

   // ------------------------------------------------------------ scenes

   public static int createScene() {
      Scene s = new Scene();
      s.handle = NativeRw.alloc(s);
      return s.handle;
   }

   /** RwDestroyScene. ⚠️ VERIFICAR: assumed to destroy its clumps and lights (not extracted from RWL21). */
   public static void destroyScene(int h) {
      Scene s = scene(h);
      if (s == null) {
         return;
      }
      for (Clump c : new ArrayList<Clump>(s.clumps)) {
         if (c.parent == null && NativeRw.get(c.handle) == c) {
            destroyClump(c.handle);
         }
      }
      for (Light l : s.lights) {
         NativeRw.release(l.handle);
      }
      NativeRw.release(h);
   }

   public static void setSceneData(int h, Object data) {
      Scene s = scene(h);
      if (s != null) {
         s.data = data;
      }
   }

   public static Object getSceneData(int h) {
      Scene s = scene(h);
      return s == null ? null : s.data;
   }

   /** RwAddClumpToScene(scene, clump) (RWL21 1002c570): error 0xF if it has a parent; moves the subtree. */
   public static void addClumpToScene(int scene, int clump) {
      Scene s = scene(scene);
      Clump c = clump(clump);
      if (s == null || c == null || c.parent != null) {
         return;
      }
      moveTree(c, s);
   }

   /** RwRemoveClumpFromScene (RWL21 1002c710): moves the subtree back to RwDefaultScene. */
   public static void removeClumpFromScene(int clump) {
      Clump c = clump(clump);
      if (c != null && c.parent == null && c.scene != null) {
         moveTree(c, null);
      }
   }

   // ------------------------------------------------------------ lights

   /** RwCreateLight(type, x, y, z, brightness) (RWL21 1000e3b0): colour (b, b, b), ON. */
   public static int createLight(int type, float x, float y, float z, float brightness) {
      Light l = new Light();
      l.type = type;
      l.vector[0] = x;
      l.vector[1] = y;
      l.vector[2] = z;
      l.color[0] = l.color[1] = l.color[2] = brightness;
      l.handle = NativeRw.alloc(l);
      return l.handle;
   }

   private static float clamp01(float f) {
      return f < 0.0F ? 0.0F : (f > 1.0F ? 1.0F : f);
   }

   public static void setLightColor(int h, float r, float g, float b) {
      Light l = light(h);
      if (l != null) {
         l.color[0] = clamp01(r);
         l.color[1] = clamp01(g);
         l.color[2] = clamp01(b);
      }
   }

   public static void setLightVector(int h, float x, float y, float z) {
      Light l = light(h);
      if (l != null) {
         l.vector[0] = x;
         l.vector[1] = y;
         l.vector[2] = z;
      }
   }

   public static void addLightToScene(int scene, int light) {
      Scene s = scene(scene);
      Light l = light(light);
      if (s != null && l != null) {
         if (l.scene != null) {
            l.scene.lights.remove(l);
         }
         l.scene = s;
         s.lights.add(l);
      }
   }

   // ------------------------------------------------------------ materials

   /**
    * gamma.dll FUN_00419000: RwCreateMaterial (RWL21 1001b340 defaults) then
    * RwSetMaterialTextureModes(DAT_00489574): 2, or 6 when DAT_00489578 is
    * set (FUN_0041a150). ⚠️ VERIFICAR which applies at run time; 2 here.
    */
   public static int createMaterial() {
      Material m = new Material();
      m.textureModes = 2;
      m.handle = NativeRw.alloc(m);
      return m.handle;
   }

   public static void destroyMaterial(int h) {
      if (material(h) != null) {
         NativeRw.release(h);
      }
   }

   public static void setMaterialColor(int h, float r, float g, float b) {
      Material m = material(h);
      if (m != null) {
         m.color[0] = clamp01(r);
         m.color[1] = clamp01(g);
         m.color[2] = clamp01(b);
      }
   }

   public static void setMaterialSurface(int h, float ambient, float diffuse, float specular) {
      Material m = material(h);
      if (m != null) {
         m.ambient = clamp01(ambient);
         m.diffuse = clamp01(diffuse);
         m.specular = clamp01(specular);
      }
   }

   public static void setMaterialOpacity(int h, float opacity) {
      Material m = material(h);
      if (m != null) {
         m.opacity = clamp01(opacity);
      }
   }

   public static void setMaterialTexture(int h, int texture) {
      Material m = material(h);
      if (m != null) {
         m.texture = texture;
      }
   }
   /**
    * gamma.dll FUN_00417950 (Material not smooth): if 0.7421875 < ambient
    * < 0.7578125 and diffuse == 0 and specular == 0 the material is
    * "self-lit" (texture mode 1 removed); otherwise light sampling 1 and
    * texture mode 1 added.
    */
   public static void flatShading(int h) {
      Material m = material(h);
      if (m == null) {
         return;
      }
      if (0.7421875F < m.ambient && m.ambient < 0.7578125F && m.diffuse == 0.0F && m.specular == 0.0F) {
         m.textureModes &= ~1;
      } else {
         m.lightSampling = 1;
         m.textureModes |= 1;
      }
   }

   /** gamma.dll FUN_00417a10 (smooth): light sampling 2, texture mode 1 added. */
   public static void smoothShading(int h) {
      Material m = material(h);
      if (m != null) {
         m.lightSampling = 2;
         m.textureModes |= 1;
      }
   }

   public static void setMaterialTextureModes(int h, int modes) {
      Material m = material(h);
      if (m != null) {
         m.textureModes = modes;
      }
   }
   /**
    * gamma.dll FUN_00417ac0: take a clump out of its parent and out of its
    * scene (unless that is the default scene, which here is "no scene").
    */
   public static void detachClump(int h) {
      Clump c = clump(h);
      if (c == null) {
         return;
      }
      if (c.parent != null) {
         removeChildFromClump(h);
      }
      if (c.scene != null) {
         removeClumpFromScene(h);
      }
   }

   /**
    * gamma.dll FUN_00418820 (2 = ON) / FUN_00418860 (1 = OFF):
    * RwSetClumpState on the clump, then RwForAllClumpsInHierarchy (post-order,
    * clump included) with callback 0x4185d0 / 0x418600, which sets the
    * same state only on clumps whose data is 0 (descendants that are
    * WObjects of their own keep their state).
    */
   public static void setHierarchyState(int h, int state) {
      Clump c = clump(h);
      if (c == null) {
         return;
      }
      c.state = state;
      if (!c.children.isEmpty()) {
         stateTree(c, state);
      }
   }

   private static void stateTree(Clump c, int state) {
      for (Clump k : c.children) {
         stateTree(k, state);
      }
      if (c.data == null) {
         c.state = state;
      }
   }

   private static void setStateTree(Clump c, int state) {
      c.state = state;
      for (Clump k : c.children) {
         setStateTree(k, state);
      }
   }

   /**
    * RwGetClumpBBox(clump, min, max) (RWL21 10008a30 -> 100088d0): the 8
    * corners of the local vertex bbox through the clump's LTM, as a world
    * AABB; no children. No vertices: min = max = LTM translation.
    * Returns {minX, minY, minZ, maxX, maxY, maxZ}.
    */
   public static float[] getClumpBBox(int h) {
      Clump c = clump(h);
      float[] b = new float[6];
      if (c == null) {
         return b;
      }
      float[] m = ltm(c);
      if (c.verts.isEmpty()) {
         b[0] = b[3] = m[12];
         b[1] = b[4] = m[13];
         b[2] = b[5] = m[14];
         return b;
      }
      b[0] = b[1] = b[2] = Float.MAX_VALUE;
      b[3] = b[4] = b[5] = -Float.MAX_VALUE;
      for (int i = 0; i < 8; i++) {
         float[] p = NativeRw.transformPoint(m, c.bbox[(i & 1) != 0 ? 3 : 0], c.bbox[(i & 2) != 0 ? 4 : 1], c.bbox[(i & 4) != 0 ? 5 : 2]);
         for (int j = 0; j < 3; j++) {
            b[j] = Math.min(b[j], p[j]);
            b[3 + j] = Math.max(b[3 + j], p[j]);
         }
      }
      return b;
   }

   /** RwGetClumpLocalBBox (RWL21 10008ab0): local corners; no vertices -> zeros. */
   public static float[] getClumpLocalBBox(int h) {
      Clump c = clump(h);
      return c == null || c.verts.isEmpty() ? new float[6] : c.bbox.clone();
   }

   private static int round(float f) {
      return (int) Math.rint(f);
   }

   /**
    * Surface.addSubPolys (gamma.dll 0x004206d0): split a 4-vertex surface
    * into hRes x vRes texture tiles per unit of UV, adding 4 new vertices
    * and one quad per tile (vertices from index 5). The corner vertices 1
    * and 4 give x/z and u/v; y is 0 (DAT_004712ac). Flags 0x100000 /
    * 0x80000 are the V / U flip (Surface.setVFlip / setUFlip), which
    * mirror every other tile. Returns the polygon handles (the Java
    * polygonIDs array).
    */
   public static int[] addSubPolys(int clump, int flags, int hRes, int vRes) {
      float[] p1 = getVertex(clump, 1);
      float[] t1 = getVertexUV(clump, 1);
      float x1 = p1[0], z1 = p1[2], u1 = t1[0], v1 = t1[1];
      float[] p4 = getVertex(clump, 4);
      float[] t4 = getVertexUV(clump, 4);
      float x4 = p4[0], z4 = p4[2], u4 = t4[0], v4 = t4[1];
      float u4s = u1 + (u4 - u1);
      float uMin = u4s < u1 ? u4s : u1;
      float v4s = v1 + (v4 - v1);
      float vMin = v4s < v1 ? v4s : v1;
      float uMax = u1 < u4s ? u4s : u1;
      float vMax = v1 < v4s ? v4s : v1;
      int col0 = round(uMin) * hRes;
      int row = round(vMin) * vRes;
      int count = (round(uMax) * hRes - col0) * (round(vMax) * vRes - row);
      int[] polys = new int[count];
      if (count == 0) {
         return polys;
      }
      float vLo = vRes * vMin;
      float vHi = vRes * vMax;
      float uLo = hRes * uMin;
      float uHi = hRes * uMax;
      float dz = (z4 - z1) / (vRes * (v4 - v1));
      float dx = (x4 - x1) / (hRes * (u4 - u1));
      boolean vFlipOn = (flags & 0x100000) != 0;
      boolean uFlipOn = (flags & 0x80000) != 0;
      boolean vFlip = vFlipOn && ((row / vRes) & 1) != 0;
      boolean uFlipStart = uFlipOn && ((col0 / hRes) & 1) != 0;
      int vert = 5;
      int n = 0;
      int[] quad = new int[4];
      for (; row < round(vMax) * vRes; row += vRes) {
         boolean uFlip = uFlipStart;
         for (int col = col0; col < round(uMax) * hRes; col += hRes) {
            int sv = vFlip ? 0 : vRes - 1;
            while (sv > -1 && sv < vRes) {
               int iv = row + sv;
               float a = (float) (iv + 1) <= vHi ? (float) (iv + 1) : vHi;
               float b = !((float) iv < vLo) ? (float) iv : vLo;
               if (a < b) {
                  a = vHi;
                  b = vHi;
               }
               float za = (a - vRes * v1) * dz + z1;
               float zb = (b - vRes * v1) * dz + z1;
               a -= iv;
               b -= iv;
               if (vFlip) {
                  a = 1.0F - a;
                  b = 1.0F - b;
               }
               int su = uFlip ? hRes - 1 : 0;
               while (su > -1 && su < hRes) {
                  int iu = col + su;
                  float c = !((float) iu < uLo) ? (float) iu : uLo;
                  float d = (float) (iu + 1) <= uHi ? (float) (iu + 1) : uHi;
                  if (d < c) {
                     c = uHi;
                     d = uHi;
                  }
                  float xc = (c - hRes * u1) * dx + x1;
                  float xd = (d - hRes * u1) * dx + x1;
                  c -= iu;
                  d -= iu;
                  if (uFlip) {
                     c = 1.0F - c;
                     d = 1.0F - d;
                  }
                  addVertex(clump, xc, 0.0F, za);
                  addVertex(clump, xd, 0.0F, za);
                  addVertex(clump, xd, 0.0F, zb);
                  addVertex(clump, xc, 0.0F, zb);
                  setVertexUV(clump, vert, c, a);
                  setVertexUV(clump, vert + 1, d, a);
                  setVertexUV(clump, vert + 2, d, b);
                  setVertexUV(clump, vert + 3, c, b);
                  quad[0] = vert;
                  quad[1] = vert + 1;
                  quad[2] = vert + 2;
                  quad[3] = vert + 3;
                  polys[n] = addPolygon(clump, 4, quad);
                  vert += 4;
                  n++;
                  su += uFlip ? -1 : 1;
               }
               sv += vFlip ? 1 : -1;
            }
            uFlip ^= uFlipOn;
         }
         vFlip ^= vFlipOn;
      }
      if (n != count) {
         NativeAssert.fail("nSurface", 0x16e);
      }
      return polys;
   }
   /** RwForAllClumpsInHierarchy with gamma.dll callbacks 0x418650 (state 1) / 0x418630 (state 2): every clump, clump included. */
   public static void setTreeState(int h, int state) {
      Clump c = clump(h);
      if (c != null) {
         treeState(c, state);
      }
   }

   private static void treeState(Clump c, int state) {
      for (Clump k : c.children) {
         treeState(k, state);
      }
      c.state = state;
   }

   /** RwGetFirstChildClump. */
   public static int getFirstChild(int h) {
      Clump c = clump(h);
      return c == null || c.children.isEmpty() ? 0 : c.children.get(0).handle;
   }

   /** Root clumps of a scene, in the order they were added. */
   public static List<Clump> sceneRoots(int h) {
      Scene s = scene(h);
      List<Clump> out = new ArrayList<Clump>();
      if (s != null) {
         for (Clump c : s.clumps) {
            if (c.parent == null) {
               out.add(c);
            }
         }
      }
      return out;
   }

   public static List<Light> sceneLights(int h) {
      Scene s = scene(h);
      return s == null ? new ArrayList<Light>() : s.lights;
   }
}

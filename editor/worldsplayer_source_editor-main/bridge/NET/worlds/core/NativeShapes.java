package NET.worlds.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import net.freeworlds.rwx.RwxMaterial;
import net.freeworlds.rwx.RwxModel;
import net.freeworlds.rwx.RwxParser;
import net.freeworlds.rwx.RwxVector3;

/**
 * RwReadShape: what gamma.dll's ShapeLoader.finishLoadingTextFile
 * (0x0041ce20 -> FUN_004199c0) gets from RenderWare when it hands it a
 * .rwx script. RWL21 parses the script itself; here it is parsed with the
 * verified translation in client/src/net/freeworlds/rwx and turned into
 * the same clump: vertices with their UV, one polygon per triangle and one
 * RW material per RWX material.
 *
 * ⚠️ VERIFICAR: the callback gamma runs over the hierarchy afterwards
 * (0x004187e0 without 3D hardware, 0x00418790 with it) is not extracted;
 * here the shape is left with hints 2 and state ON, as a clump read by
 * RwReadShape arrives.
 */
public final class NativeShapes {
   private NativeShapes() {
   }

   /** Texture names the shape asks for, in order of first use. */
   public static final class Shape {
      public int clump;
      public final List<String> textures = new ArrayList<String>();
   }

   public static Shape readShape(String path) {
      Shape out = new Shape();
      byte[] data;
      try {
         java.io.File f = NativeMock.localFile(path);
         data = java.nio.file.Files.readAllBytes(f.toPath());
      } catch (Exception e) {
         return out;
      }
      RwxModel model;
      try {
         model = new RwxParser().parse(new String(data, java.nio.charset.Charset.forName("ISO-8859-1")));
      } catch (RuntimeException e) {
         System.err.println("[RW] RwReadShape(" + path + "): " + e);
         return out;
      }
      if (model.vertices.isEmpty() || model.triangles.isEmpty()) {
         return out;
      }
      int clump = NativeScene.createClump();
      for (int i = 0; i < model.vertices.size(); i++) {
         RwxVector3 v = model.vertices.get(i);
         int idx = NativeScene.addVertex(clump, v.x, v.y, v.z);
         float[] uv = i < model.uvs.size() ? model.uvs.get(i) : null;
         if (uv != null) {
            NativeScene.setVertexUV(clump, idx, uv[0], uv[1]);
         }
      }
      Map<RwxMaterial, Integer> mats = new HashMap<RwxMaterial, Integer>();
      int[] tri = new int[3];
      for (int i = 0; i < model.triangles.size(); i++) {
         int[] t = model.triangles.get(i);
         tri[0] = t[0] + 1;
         tri[1] = t[1] + 1;
         tri[2] = t[2] + 1;
         int poly = NativeScene.addPolygon(clump, 3, tri);
         if (poly == 0) {
            continue;
         }
         RwxMaterial rm = i < model.triangleMaterials.size() ? model.triangleMaterials.get(i) : null;
         if (rm == null) {
            continue;
         }
         Integer mat = mats.get(rm);
         if (mat == null) {
            mat = Integer.valueOf(material(rm, out));
            mats.put(rm, mat);
         }
         NativeScene.setPolygonMaterial(poly, mat.intValue());
      }
      NativeScene.setClumpHints(clump, 2);
      NativeScene.setClumpState(clump, 2);
      out.clump = clump;
      return out;
   }

   private static int material(RwxMaterial rm, Shape out) {
      int m = NativeScene.createMaterial();
      NativeScene.setMaterialColor(m, rm.colorR, rm.colorG, rm.colorB);
      NativeScene.setMaterialSurface(m, rm.effectiveAmbient(), rm.effectiveDiffuse(), rm.specular);
      NativeScene.setMaterialOpacity(m, rm.opacity);
      int modes = 0;
      if (rm.textureModes.contains(RwxMaterial.TextureMode.LIT)) {
         modes |= 1;
      }
      if (rm.textureModes.contains(RwxMaterial.TextureMode.FORESHORTEN)) {
         modes |= 2;
      }
      if (rm.textureModes.contains(RwxMaterial.TextureMode.FILTER)) {
         modes |= 4;
      }
      NativeScene.setMaterialTextureModes(m, modes);
      if (rm.doubleSided) {
         NativeScene.setMaterialModes(m, 0x80);
      }
      if (rm.textureName != null && rm.textureName.length() > 0) {
         NativeScene.setMaterialTextureName(m, rm.textureName);
         if (!out.textures.contains(rm.textureName)) {
            out.textures.add(rm.textureName);
         }
      }
      return m;
   }
   /**
    * ShapeLoader.loadBinaryFile (0x0041e5d0): gamma opens a stream over the
    * file and keeps it until finishLoadingBinaryFile reads the CLUM chunk
    * (0x0041e630 -> FUN_00419a60 -> RwReadStreamChunk). Here the bytes are
    * kept in the handle table and parsed with the .rwg translation in
    * client/src/net/freeworlds/rwg.
    */
   public static int openBinary(String path) {
      try {
         byte[] data = java.nio.file.Files.readAllBytes(NativeMock.localFile(path).toPath());
         return NativeRw.alloc(data);
      } catch (Exception e) {
         return 0;
      }
   }

   /**
    * RwReadStreamChunk(CLUM) over an opened .rwg: one clump with the ATOM's
    * vertices (position and UV) and polygons. ⚠️ the .rwg material and
    * texture tables (MALT/TELT) are not decoded yet, so the shape gets the
    * default material.
    */
   public static int readBinary(int handle, boolean wasError) {
      Object o = NativeRw.get(handle);
      NativeRw.release(handle);
      if (wasError || !(o instanceof byte[])) {
         return 0;
      }
      net.freeworlds.rwg.RwgModel model;
      try {
         model = net.freeworlds.rwg.RwgParser.parse((byte[]) o);
      } catch (RuntimeException e) {
         System.err.println("[RW] RwReadStreamChunk(CLUM): " + e);
         return 0;
      }
      if (model == null || model.atom == null || model.atom.vertices.isEmpty()) {
         return 0;
      }
      int clump = NativeScene.createClump();
      for (net.freeworlds.rwg.RwgVertex v : model.atom.vertices) {
         int idx = NativeScene.addVertex(clump, v.x, v.y, v.z);
         NativeScene.setVertexUV(clump, idx, v.u, v.v);
      }
      int nv = model.atom.vertices.size();
      for (net.freeworlds.rwg.RwgPolygon poly : model.atom.polygons) {
         int[] idx = poly.vertexIndices;
         int[] one = new int[idx.length];
         boolean ok = true;
         for (int i = 0; i < idx.length; i++) {
            one[i] = idx[i] + 1;
            if (one[i] < 1 || one[i] > nv) {
               ok = false;
            }
         }
         if (ok && one.length >= 3) {
            NativeScene.addPolygon(clump, one.length, one);
         }
      }
      NativeScene.setClumpHints(clump, 2);
      NativeScene.setClumpState(clump, 2);
      return clump;
   }
}

package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * What gamma.dll's ShapeLoader gets from RenderWare: RwReadShape for a
 * .rwx script (0x0041ce20 -> FUN_004199c0, interpreter in RwxReader),
 * RwReadStreamChunk(CLUM) for a .rwg (0x0041e630) and the .bod body reader
 * (0x0041e440).
 *
 * ⚠️ VERIFICAR: the callback gamma runs over the hierarchy after reading
 * (0x004187e0 without 3D hardware, 0x00418790 with it) is not extracted.
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
      RwxReader.Result r = RwxReader.read(NativeMock.localFile(path));
      out.clump = r.clump;
      out.textures.addAll(r.textures);
      return out;
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
   /**
    * ShapeLoader.loadBodFile (gamma.dll 0x0041e440): reads the .bod, looks
    * in its part table for the entry whose tag is the requested part
    * number (the native scans the table backwards) and builds that part's
    * clump tree (0x0041e240). A file that cannot be read, a version above
    * 1, no parts, or a part that is not there give an empty clump left in
    * state OFF, and the shape keeps no animatable clump.
    *
    * The part table and the clump tree are read with the .bod translation
    * in client/src/net/freeworlds/bod (from the official RWXTOBOD.PL
    * encoder). A placeholder clump carries its tag with bit 0x8000000 set,
    * which is the tag WObject.addChildToClump looks for when it attaches a
    * part to the body (gamma.dll 0x00412f90).
    */
   public static int readBod(String path, int partNum) {
      byte[] data = null;
      try {
         data = java.nio.file.Files.readAllBytes(NativeMock.localFile(path).toPath());
      } catch (Exception e) {
         data = null;
      }
      net.freeworlds.bod.BodClump part = null;
      if (data != null && data.length > 1 && (data[0] & 0xFF) <= 1 && (data[1] & 0xFF) != 0) {
         try {
            net.freeworlds.bod.BodFile f = net.freeworlds.bod.BodParser.parse(data);
            for (int i = f.parts.size() - 1; i >= 0; i--) {
               if (f.parts.get(i).tag == partNum) {
                  part = f.parts.get(i);
                  break;
               }
            }
         } catch (RuntimeException e) {
            System.err.println("[RW] .bod " + path + ": " + e);
         }
      }
      if (part != null) {
         int c = buildBod(part);
         if (c != 0) {
            return c;
         }
      }
      int empty = NativeScene.createClump();
      if (empty == 0) {
         NativeAssert.fail("nShape", 0x48f);
      }
      NativeScene.setClumpState(empty, 1);
      return empty;
   }

   private static int buildBod(net.freeworlds.bod.BodClump b) {
      int c = NativeScene.createClump();
      if (c == 0) {
         return 0;
      }
      NativeScene.setClumpTag(c, b.placeholder ? b.tag | 0x8000000 : b.tag);
      float[] m = new float[16];
      NativeScene.getClumpMatrix(c, m);
      NativeRw.translate(m, b.tx, b.ty, b.tz, NativeRw.POSTCONCAT);
      NativeScene.transformClump(c, m, NativeRw.REPLACE);
      if (!b.placeholder) {
         if (b.vertices != null) {
            for (net.freeworlds.bod.BodVertex v : b.vertices) {
               int idx = NativeScene.addVertex(c, v.x, v.y, v.z);
               NativeScene.setVertexUV(c, idx, v.u, v.v);
            }
         }
         int mat = 0;
         if (b.triangles != null && !b.triangles.isEmpty()) {
            mat = NativeScene.createMaterial();
            NativeScene.setMaterialColor(mat, b.r / 255.0F, b.g / 255.0F, b.b / 255.0F);
            NativeScene.setMaterialSurface(mat, 0.75F, 0.0F, 0.0F);
            NativeScene.setMaterialTextureModes(mat, 1);
            for (int[] tri : b.triangles) {
               int poly = NativeScene.addPolygon(c, 3, new int[]{tri[0] + 1, tri[1] + 1, tri[2] + 1});
               if (poly != 0) {
                  NativeScene.setPolygonMaterial(poly, mat);
               }
            }
         }
         if (b.children != null) {
            for (net.freeworlds.bod.BodClump ch : b.children) {
               int cc = buildBod(ch);
               if (cc != 0) {
                  NativeScene.addChildToClump(c, cc);
               }
            }
         }
      }
      NativeScene.setClumpHints(c, 2);
      return c;
   }
}

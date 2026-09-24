package NET.worlds.core;

import java.util.ArrayList;
import java.util.List;

/**
 * What gamma.dll's ShapeLoader gets from RenderWare: RwReadShape for a
 * .rwx script (0x0041ce20 -> FUN_004199c0, interpreter in RwxReader),
 * RwReadStreamChunk(CLUM) for a .rwg (0x0041e630 -> FUN_00419a60) and the
 * .bod body reader (0x0041e440).
 *
 * After RwReadShape and after RwReadStreamChunk(CLUM) gamma runs
 * RwForAllClumpsInHierarchy with 0x004187e0 (no 3D hardware, the case of
 * this bridge): see {@link #afterLoad}.
 */
public final class NativeShapes {
   private NativeShapes() {
   }

   /** What FUN_004199c0 gives back. */
   public static final class Shape {
      public int clump;
   }

   /** FUN_004199c0: RwReadShape and then the 0x004187e0 callback over the hierarchy. */
   public static Shape readShape(String path) {
      Shape out = new Shape();
      out.clump = RwxReader.read(NativeMock.localFile(path)).clump;
      if (out.clump != 0) {
         afterLoad(out.clump);
      }
      return out;
   }

   /**
    * ShapeLoader.loadTextFile (gamma.dll 0x0041cba0): before RW reads the
    * script, gamma opens it as a text ifstream (FUN_00411980, mode 1 =
    * in) and, line by line (FUN_0041f300: getline up to 0x400 with '\n'),
    * lower-cases the line (FUN_00450890) and splits it with strtok on
    * " \t\n" (DAT_00470a84). When the first token is exactly "texture" or
    * "textureext" and there is a second token that is not exactly "null"
    * (DAT_00470a9c), it asks Java for that name, with ".bmp"
    * (DAT_00470aa4) appended when the token has no '.'. Only the script
    * itself is scanned (an Include'd file is not).
    *
    * The CRT text mode turns CR LF into LF before gamma sees the line.
    * ⚠️ VERIFICAR, not modeled because no corpus script has them: lines of
    * 0x3ff bytes or more (what the MSVC getline does at the limit) and a
    * Ctrl-Z inside the file (end of file in CRT text mode).
    */
   public static List<String> scanTextures(String path) {
      List<String> out = new ArrayList<String>();
      byte[] data;
      try {
         data = java.nio.file.Files.readAllBytes(NativeMock.localFile(path).toPath());
      } catch (Exception e) {
         return out;
      }
      String text = new String(data, java.nio.charset.StandardCharsets.ISO_8859_1).replace("\r\n", "\n");
      for (String line : text.split("\n", -1)) {
         StringBuilder low = new StringBuilder(line.length());
         for (int i = 0; i < line.length(); i++) {
            char c = line.charAt(i);
            low.append(c >= 'A' && c <= 'Z' ? (char) (c + 0x20) : c);
         }
         java.util.StringTokenizer st = new java.util.StringTokenizer(low.toString(), " \t\n");
         if (!st.hasMoreTokens()) {
            continue;
         }
         String cmd = st.nextToken();
         if (!cmd.equals("texture") && !cmd.equals("textureext")) {
            continue;
         }
         if (!st.hasMoreTokens()) {
            continue;
         }
         String name = st.nextToken();
         if (name.equals("null")) {
            continue;
         }
         out.add(name.indexOf('.') < 0 ? name + ".bmp" : name);
      }
      return out;
   }

   /**
    * gamma.dll 0x004187e0, the RwForAllClumpsInHierarchy callback of
    * FUN_004199c0 / FUN_00419a60 without 3D hardware (DAT_00489578 == 0):
    * RwGetClumpTag; below 0x4000000 (unsigned, {@code jae}) the clump gets
    * RwSetClumpHints(2), otherwise RwSetClumpState(OFF = 1). That hides
    * the "special" clumps (tags 0x20000000 / 0x40000000, see
    * {@link #convertSpecial}) and the .bod placeholders (0x8000000).
    */
   static void afterLoad(int clump) {
      int tag = NativeScene.getClumpTag(clump);
      if (Integer.compareUnsigned(tag, 0x4000000) < 0) {
         NativeScene.setClumpHints(clump, 2);
      } else {
         NativeScene.setClumpState(clump, 1);
      }
      for (int child : NativeScene.childHandles(clump)) {
         afterLoad(child);
      }
   }

   // ------------------------------------------------------------ .rwg

   /** The object FUN_0041c970 builds for ShapeLoader.loadBinaryFile. */
   static final class Binary {
      byte[] data;
      /** this+0xc: the header's texture list ended in the empty name. */
      boolean complete;
      final List<String> requests = new ArrayList<String>();
   }

   /**
    * ShapeLoader.loadBinaryFile (0x0041e5d0 -> FUN_0041c970): gamma reads
    * the whole file into global memory, opens a memory stream over it
    * (FUN_004181d0), reads its own header (FUN_00419af0: "ZZZ[", length,
    * 0x13765342, 1) and the texture list that follows, and asks Java for
    * each name ({@link #binaryTextureRequests}, ".cmp" added when the name
    * has no '.'). The object always exists; a file that cannot be read or
    * a header that fails leaves it incomplete and finishLoadingBinaryFile
    * gives -1.
    */
   public static int openBinary(String path) {
      Binary b = new Binary();
      try {
         b.data = java.nio.file.Files.readAllBytes(NativeMock.localFile(path).toPath());
      } catch (Exception e) {
         b.data = null;
      }
      if (b.data != null) {
         net.freeworlds.rwg.RwgParser.Header h = net.freeworlds.rwg.RwgParser.header(b.data);
         if (h != null) {
            b.requests.addAll(h.textureRequests());
            b.complete = h.complete;
         }
      }
      return NativeRw.alloc(b);
   }

   /** The names FUN_0041c970 passes to ShapeLoader.startTextureLoad, in order. */
   public static List<String> binaryTextureRequests(int handle) {
      Object o = NativeRw.get(handle);
      return o instanceof Binary ? ((Binary) o).requests : new ArrayList<String>();
   }

   /**
    * ShapeLoader.finishLoadingBinaryFile (0x0041e630): without error and
    * with a complete header, FUN_00419a60 reads the CLUM
    * (RwReadStreamChunkType + RwReadStreamChunk(CLUM), RWL21 0x1003a03d)
    * and runs {@link #afterLoad}; the stream and the memory are freed
    * either way. Returns the clump or 0 (the Java side turns 0 into -1).
    */
   public static int readBinary(int handle, boolean wasError) {
      Object o = NativeRw.get(handle);
      NativeRw.release(handle);
      if (wasError || !(o instanceof Binary) || !((Binary) o).complete) {
         return 0;
      }
      net.freeworlds.rwg.RwgModel model;
      try {
         model = net.freeworlds.rwg.RwgParser.parse(((Binary) o).data);
      } catch (RuntimeException e) {
         System.err.println("[RW] RwReadStreamChunk(CLUM): " + e.getMessage());
         return 0;
      }
      int clump = buildClum(model);
      if (clump != 0) {
         afterLoad(clump);
      }
      return clump;
   }

   /**
    * RwReadStreamChunk(CLUM) (0x1003a03d) once the chunks are decoded: the
    * TELT list resolved to textures, one RW material per MALT record, and
    * the ATOM tree. 0 when a TELT entry gives no texture (error 0x5e,
    * 0x1003cf0b), which fails the whole CLUM.
    */
   static int buildClum(net.freeworlds.rwg.RwgModel model) {
      List<Integer> textures = new ArrayList<Integer>();
      for (net.freeworlds.rwg.RwgTexture t : model.textures) {
         int tex = resolveTelt(t);
         if (tex == 0) {
            System.err.println("[RW] RwReadStreamChunk(TELT): no texture for \"" + t.name + "\" (error 0x5e)");
            return 0;
         }
         // 0x1003ce42: added only if the list does not have it yet
         if (!textures.contains(Integer.valueOf(tex))) {
            textures.add(Integer.valueOf(tex));
         }
      }
      List<Integer> materials = new ArrayList<Integer>();
      for (net.freeworlds.rwg.RwgMaterial m : model.materials) {
         materials.add(Integer.valueOf(material(m, textures)));
      }
      return buildAtom(model.atom, materials);
   }

   /**
    * One TELT entry (RWL21 0x1003cd0b..0x1003ce24; gamma passes flags 0 to
    * RwReadStreamChunk, so bit 8 never skips the dictionary):
    * <ul>
    * <li>raster 0: the texture of that name in the dictionary (FUN_100184d0,
    * the current dictionary only: gamma never opens another one) or, if
    * there is none and a file of that name exists in the shape path
    * (FUN_10021270), RwGetNamedTexture;</li>
    * <li>raster != 0: the dictionary, or else a new texture over that RALT
    * raster. ⚠️ sin muestra real: no .rwg of the corpus has rasters and RAST
    * is not converted here, so that case gives 0 (the CLUM fails).</li>
    * </ul>
    */
   static int resolveTelt(net.freeworlds.rwg.RwgTexture t) {
      if (t.name != null) {
         NativeTextures.Texture found = NativeTextures.rwFindNamed(t.name);
         if (found != null) {
            return found.handle;
         }
      }
      if (t.rasterIndex != 0) {
         System.err.println("[RW] RwReadStreamChunk(TELT): raster " + t.rasterIndex
            + " de RALT sin traducir (⚠️ sin muestra real)");
         return 0;
      }
      if (t.name != null && shapeFileExists(t.name)) {
         return NativeTextures.rwGetNamed(t.name);
      }
      return 0;
   }

   /**
    * FUN_10021270: FUN_10009ae0 (the name in the shape path ".;..") as is
    * and then with ".ras", ".tex", ".env", ".bmp", ".rle" (DAT_1005ad00,
    * 1005acf8, 1005acf0, 1005ace8, 1005ace0), each only when the name has
    * no extension yet (FUN_10043de0).
    */
   static boolean shapeFileExists(String name) {
      if (NativeTextures.rwFindFile(name) != null) {
         return true;
      }
      String[] exts = {".ras", ".tex", ".env", ".bmp", ".rle"};
      for (String ext : exts) {
         String withExt = NativeTextures.rwAddExtension(name, ext);
         if (withExt != null && NativeTextures.rwFindFile(withExt) != null) {
            return true;
         }
      }
      return false;
   }

   /**
    * One MALT record (0x1003c10a..0x1003c180) on a fresh RwCreateMaterial:
    * word 0 (sampling) read as RwGetMaterialGeometrySampling /
    * RwGetMaterialLightSampling read it, the byte at +0x30 split into
    * texture modes ({@code & 0x1f}) and material modes ({@code & 0xc0}),
    * color, opacity, surface and the TELT texture (1-based; 0 or out of
    * range = none).
    */
   static int material(net.freeworlds.rwg.RwgMaterial m, List<Integer> textures) {
      int mat = NativeScene.createMaterial();
      NativeScene.setMaterialGeometrySampling(mat, m.geometrySampling());
      NativeScene.setMaterialLightSampling(mat, m.lightSampling());
      NativeScene.setMaterialTextureModes(mat, m.textureModes());
      NativeScene.setMaterialModes(mat, m.materialModes());
      NativeScene.setMaterialColor(mat, m.r, m.g, m.b);
      NativeScene.setMaterialOpacity(mat, m.opacity);
      NativeScene.setMaterialSurface(mat, m.ambient, m.diffuse, m.specular);
      if (m.textureIndex != 0) {
         int i = m.textureIndex;
         NativeScene.setMaterialTexture(mat, i >= 1 && i <= textures.size() ? textures.get(i - 1).intValue() : 0);
      }
      return mat;
   }

   /**
    * RwReadStreamChunk(ATOM) (0x1003b569): RwCreateClump, tag / axis
    * alignment / state from the STRT, the two MATX as modeling (+0xec) and
    * joint (+0x130) matrices, the VLST vertices (after the 8 bounding-box
    * records) with their UV and, with VLST flag 1, their normal; the PLST
    * polygons with their MALT material and tag; the child ATOMs; and
    * RwSetClumpHints(STRT[8]) last.
    *
    * ⚠️ Not carried over, because NativeScene has no place for them: the
    * PLST face normal (RW keeps it at polygon+0x10; the bridge computes
    * its own, 0x10001100), the PLST/VLST flag-4 reals, STRT[0]/[1] and the
    * light sample rate. The vertex normal goes through
    * NativeScene.setVertexNormal, which normalizes it (RW stores it raw;
    * the corpus normals are 1 +- 1e-4). MALT materials are not destroyed at
    * the end as FUN_1003d550 does (it only drops RW's own reference; the
    * polygons keep theirs).
    */
   static int buildAtom(net.freeworlds.rwg.RwgAtom a, List<Integer> materials) {
      int c = NativeScene.createClump();
      if (c == 0) {
         return 0;
      }
      NativeScene.setClumpTag(c, a.tag());
      NativeScene.setClumpAxisAlignment(c, a.axisAlignment());
      NativeScene.setClumpState(c, a.state());
      NativeScene.transformClump(c, a.matrix1.clone(), NativeRw.REPLACE);
      NativeScene.transformClumpJoint(c, a.matrix2.clone(), NativeRw.REPLACE);
      for (net.freeworlds.rwg.RwgVertex v : a.vertices) {
         int idx = NativeScene.addVertex(c, v.x, v.y, v.z);
         if (v.hasUv) {
            NativeScene.setVertexUV(c, idx, v.u, v.v);
         }
         if (v.hasNormal) {
            NativeScene.setVertexNormal(c, idx, v.normalX, v.normalY, v.normalZ);
         }
      }
      for (net.freeworlds.rwg.RwgPolygon p : a.polygons) {
         int[] one = new int[p.vertexIndices.length];
         for (int i = 0; i < one.length; i++) {
            one[i] = p.vertexIndices[i] + 1;
         }
         int poly = NativeScene.addPolygon(c, one.length, one);
         if (poly == 0) {
            continue;
         }
         int mi = p.materialIndex;
         NativeScene.setPolygonMaterial(poly, mi >= 1 && mi <= materials.size() ? materials.get(mi - 1).intValue() : 0);
         if (p.tag != 0) {
            NativeScene.setPolygonTag(poly, p.tag);
         }
      }
      for (net.freeworlds.rwg.RwgAtom child : a.children) {
         int cc = buildAtom(child, materials);
         if (cc != 0) {
            NativeScene.addChildToClump(c, cc);
         }
      }
      NativeScene.setClumpHints(c, a.hints());
      return c;
   }

   // ------------------------------------------------------------ .bod

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

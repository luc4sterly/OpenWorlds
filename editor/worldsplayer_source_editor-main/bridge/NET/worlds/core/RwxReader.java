package NET.worlds.core;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * RwReadShape: the .rwx script interpreter of RWL21.DLL (0x10009bf0, command
 * loop 0x100163e0), translated command by command.
 *
 * ClumpBegin (0x1000f560) freezes the current CTM and starts a new one at
 * identity; the frozen CTM becomes the modeling matrix of the clump the
 * matching ClumpEnd produces (REPLACE), while the CTM built up inside the
 * block is applied to every vertex as it is added (0x10010270). ClumpEnd
 * (0x1000f980) merges the frame's clumps into one, keeps tag / hints / axis
 * alignment from the frame's own clump, re-parents the grandchildren with
 * the source LTM post-concatenated, pops the three stacks and hangs the
 * result on the enclosing frame's clump.
 *
 * Material state is a stack whose top ClumpBegin and MaterialBegin copy
 * (0x1001b790) and whose mutations are copy-on-write (0x1001ba80), so each
 * polygon keeps the material as it stood when the polygon was created.
 *
 * The Texture / TextureExt command (0x10014b00) resolves its texture while
 * the script is read, with RwGetNamedTexture (0x10018900): the dictionary
 * by base name and then the shape path ".;..". A texture that cannot be
 * found fails the command, and a failed command makes the whole
 * RwReadShape return NULL (0x100163e0).
 */
public final class RwxReader {
   private RwxReader() {
   }

   /** Material state; defaults are RwCreateMaterial's (RWL21 0x1001b340). */
   private static final class Mat {
      float r;
      float g;
      float b;
      float ambient;
      float diffuse;
      float specular;
      float opacity = 1.0F;
      int textureModes = 1;
      int materialModes;
      int lightSampling = 1;
      int geometrySampling = 4;
      String texture;
      /** RwSetMaterialTexture of the Texture command: the RW texture handle. */
      int textureHandle;

      Mat copy() {
         Mat m = new Mat();
         m.r = this.r;
         m.g = this.g;
         m.b = this.b;
         m.ambient = this.ambient;
         m.diffuse = this.diffuse;
         m.specular = this.specular;
         m.opacity = this.opacity;
         m.textureModes = this.textureModes;
         m.materialModes = this.materialModes;
         m.lightSampling = this.lightSampling;
         m.geometrySampling = this.geometrySampling;
         m.texture = this.texture;
         m.textureHandle = this.textureHandle;
         return m;
      }

      String key() {
         return this.r + "," + this.g + "," + this.b + "," + this.ambient + "," + this.diffuse + ","
            + this.specular + "," + this.opacity + "," + this.textureModes + "," + this.materialModes
            + "," + this.lightSampling + "," + this.geometrySampling + "," + this.texture + "," + this.textureHandle;
      }
   }

   /** Clump frame of the parser (pool 0x1005a0d0). */
   private static final class Frame {
      float[] ctmAtBegin = NativeRw.identity();
      float[] jointAtBegin = NativeRw.identity();
      final List<Integer> clumps = new ArrayList<Integer>();
      int ctmDepth;
      int jointDepth;
      int matDepth;
      int hints = 2;
      int axisAlignment = 1;
   }

   private static final class Ctx {
      final List<float[]> ctm = new ArrayList<float[]>();
      final List<float[]> joint = new ArrayList<float[]>();
      final List<Mat> mats = new ArrayList<Mat>();
      final List<Frame> frames = new ArrayList<Frame>();
      final Map<String, Integer> protos = new HashMap<String, Integer>();
      final Map<String, Integer> matHandles = new HashMap<String, Integer>();
      boolean inModel;
      /** A command returned FALSE: RwReadShape gives NULL (0x100163e0). */
      boolean failed;
      String protoName;
      int result;
      java.io.File dir;

      Ctx() {
         this.ctm.add(NativeRw.identity());
         this.joint.add(NativeRw.identity());
         this.mats.add(new Mat());
      }

      float[] ctmTop() {
         return this.ctm.get(this.ctm.size() - 1);
      }

      float[] jointTop() {
         return this.joint.get(this.joint.size() - 1);
      }

      Mat mat() {
         return this.mats.get(this.mats.size() - 1);
      }

      Frame frame() {
         return this.frames.isEmpty() ? null : this.frames.get(this.frames.size() - 1);
      }
   }

   /** What RwReadShape gives back: the root clump, or 0. */
   public static final class Result {
      public int clump;
   }

   public static Result read(java.io.File file) {
      Result out = new Result();
      String text;
      try {
         byte[] data = java.nio.file.Files.readAllBytes(file.toPath());
         text = new String(data, java.nio.charset.Charset.forName("ISO-8859-1"));
      } catch (Exception e) {
         return out;
      }
      Ctx c = new Ctx();
      c.dir = file.getParentFile();
      for (String raw : text.split("\r\n|\r|\n")) {
         String[] tok = tokens(raw);
         if (tok.length == 0 || tok[0].startsWith("#")) {
            continue;
         }
         if (!command(c, tok)) {
            break;
         }
      }
      if (c.failed) {
         // 0x100163e0: FUN_1000f2b0 drops the open frames and the result is destroyed
         for (Frame fr : c.frames) {
            for (Integer k : fr.clumps) {
               NativeScene.destroyClump(k.intValue());
            }
         }
         if (c.result != 0) {
            NativeScene.destroyClump(c.result);
         }
         return out;
      }
      out.clump = c.result;
      return out;
   }

   /** readToken (0x100206d0): blanks separate, quotes group, '#' starts a comment. */
   private static String[] tokens(String line) {
      List<String> out = new ArrayList<String>();
      int i = 0;
      int n = line.length();
      while (i < n) {
         char ch = line.charAt(i);
         if (blank(ch)) {
            i++;
            continue;
         }
         if (ch == '#') {
            break;
         }
         StringBuilder sb = new StringBuilder();
         if (ch == '"') {
            i++;
            while (i < n && line.charAt(i) != '"') {
               if (line.charAt(i) == '\\' && i + 1 < n) {
                  i++;
               }
               sb.append(line.charAt(i++));
            }
            i++;
         } else {
            while (i < n && !blank(line.charAt(i))) {
               sb.append(line.charAt(i++));
            }
         }
         out.add(sb.toString());
      }
      return out.toArray(new String[0]);
   }

   private static boolean blank(char c) {
      return c == ' ' || c == '\t' || c == '\r' || c == 11;
   }

   private static float f(String[] t, int i) {
      try {
         return i < t.length ? Float.parseFloat(t[i]) : 0.0F;
      } catch (RuntimeException e) {
         return 0.0F;
      }
   }

   private static int d(String[] t, int i) {
      try {
         return i < t.length ? (int) Float.parseFloat(t[i]) : 0;
      } catch (RuntimeException e) {
         return 0;
      }
   }

   private static boolean command(Ctx c, String[] t) {
      String cmd = t[0].toLowerCase();
      if (cmd.equals("modelbegin")) {
         c.inModel = true;
         System.arraycopy(NativeRw.identity(), 0, c.ctmTop(), 0, 16);
         System.arraycopy(NativeRw.identity(), 0, c.jointTop(), 0, 16);
         c.mats.add(new Mat());
         return true;
      }
      if (cmd.equals("modelend")) {
         c.inModel = false;
         return false;
      }
      if (cmd.equals("clumpbegin")) {
         clumpBegin(c);
         return true;
      }
      if (cmd.equals("clumpend")) {
         int clump = clumpEndCore(c);
         if (clump == 0) {
            return false;
         }
         if (!c.frames.isEmpty()) {
            return true;
         }
         c.result = clump;
         return c.inModel;
      }
      if (cmd.equals("protobegin")) {
         c.protoName = t.length > 1 ? t[1] : "";
         clumpBegin(c);
         return true;
      }
      if (cmd.equals("protoend")) {
         int clump = clumpEndCore(c);
         if (clump != 0 && c.protoName != null) {
            c.protos.put(c.protoName, Integer.valueOf(clump));
         }
         c.protoName = null;
         return true;
      }
      if (cmd.equals("protoinstance") || cmd.equals("protoinstancegeometry")) {
         Integer proto = t.length > 1 ? c.protos.get(t[1]) : null;
         Frame fr = c.frame();
         if (proto != null && fr != null) {
            int copy = NativeScene.duplicateClump(proto.intValue());
            if (copy != 0) {
               preConcatModeling(copy, c.ctmTop());
               fr.clumps.add(Integer.valueOf(copy));
            }
         }
         return true;
      }
      if (cmd.equals("include") || cmd.equals("includegeometry")) {
         Frame fr = c.frame();
         if (fr != null && t.length > 1 && c.dir != null) {
            Result r = read(NativeMock.resolveCaseInsensitive(new java.io.File(c.dir, t[1]).getPath()));
            if (r.clump != 0) {
               preConcatModeling(r.clump, c.ctmTop());
               fr.clumps.add(Integer.valueOf(r.clump));
            }
         }
         return true;
      }
      if (cmd.equals("transformbegin")) {
         c.ctm.add(c.ctmTop().clone());
         return true;
      }
      if (cmd.equals("transformend")) {
         if (c.ctm.size() > 1) {
            c.ctm.remove(c.ctm.size() - 1);
         }
         return true;
      }
      if (cmd.equals("jointtransformbegin")) {
         c.joint.add(c.jointTop().clone());
         return true;
      }
      if (cmd.equals("jointtransformend")) {
         if (c.joint.size() > 1) {
            c.joint.remove(c.joint.size() - 1);
         }
         return true;
      }
      if (cmd.equals("identity")) {
         System.arraycopy(NativeRw.identity(), 0, c.ctmTop(), 0, 16);
         return true;
      }
      if (cmd.equals("identityjoint")) {
         System.arraycopy(NativeRw.identity(), 0, c.jointTop(), 0, 16);
         return true;
      }
      if (cmd.equals("transform") || cmd.equals("transformjoint")) {
         if (t.length >= 17) {
            float[] m = cmd.equals("transform") ? c.ctmTop() : c.jointTop();
            for (int i = 0; i < 16; i++) {
               m[i] = f(t, i + 1);
            }
         }
         return true;
      }
      if (cmd.equals("translate")) {
         NativeRw.translate(c.ctmTop(), f(t, 1), f(t, 2), f(t, 3), NativeRw.PRECONCAT);
         return true;
      }
      if (cmd.equals("scale")) {
         NativeRw.scale(c.ctmTop(), f(t, 1), f(t, 2), f(t, 3), NativeRw.PRECONCAT);
         return true;
      }
      if (cmd.equals("rotate") || cmd.equals("rotatejoint")) {
         float[] m = cmd.equals("rotate") ? c.ctmTop() : c.jointTop();
         NativeRw.rotate(m, f(t, 1), f(t, 2), f(t, 3), f(t, 4), NativeRw.PRECONCAT);
         return true;
      }
      if (cmd.equals("vertex") || cmd.equals("vertexext")) {
         vertex(c, t);
         return true;
      }
      if (cmd.equals("triangle") || cmd.equals("triangleext")) {
         polygon(c, t, 3, 1);
         return true;
      }
      if (cmd.equals("quad") || cmd.equals("quadext")) {
         polygon(c, t, 4, 1);
         return true;
      }
      if (cmd.equals("polygon") || cmd.equals("polygonext")) {
         polygon(c, t, d(t, 1), 2);
         return true;
      }
      if (cmd.equals("tag")) {
         Frame fr = c.frame();
         if (fr != null) {
            NativeScene.setClumpTag(fr.clumps.get(0).intValue(), d(t, 1));
         }
         return true;
      }
      if (cmd.equals("hints") || cmd.equals("addhint") || cmd.equals("removehint")) {
         Frame fr = c.frame();
         if (fr != null) {
            int mask = 0;
            for (int i = 1; i < t.length; i++) {
               String h = t[i].toLowerCase();
               if (h.equals("container")) {
                  mask |= 1;
               } else if (h.equals("hs")) {
                  mask |= 2;
               } else if (h.equals("editable")) {
                  mask |= 4;
               }
            }
            if (cmd.equals("hints")) {
               fr.hints = mask;
            } else if (cmd.equals("addhint")) {
               fr.hints |= mask;
            } else {
               fr.hints &= ~mask;
            }
            NativeScene.setClumpHints(fr.clumps.get(0).intValue(), fr.hints);
         }
         return true;
      }
      if (cmd.equals("axisalignment")) {
         Frame fr = c.frame();
         if (fr != null && t.length > 1) {
            String a = t[1].toLowerCase();
            fr.axisAlignment = a.equals("zorientx") ? 2 : a.equals("zorienty") ? 3 : a.equals("xyz") ? 4 : 1;
            NativeScene.setClumpAxisAlignment(fr.clumps.get(0).intValue(), fr.axisAlignment);
         }
         return true;
      }
      if (cmd.equals("materialbegin")) {
         c.mats.add(c.mat().copy());
         return true;
      }
      if (cmd.equals("materialend")) {
         if (c.mats.size() > 1) {
            c.mats.remove(c.mats.size() - 1);
         }
         return true;
      }
      if (cmd.equals("texture") || cmd.equals("textureext")) {
         if (!texture(c, t)) {
            c.failed = true;
            return false;
         }
         return true;
      }
      material(c, cmd, t);
      return true;
   }

   /**
    * Texture / TextureExt (RWL21 0x10014b00, both entries of the command
    * table at 0x1005a6c0/0x1005a6e0 point here):
    * <ul>
    * <li>no name token: error 5, FALSE;</li>
    * <li>the first 4 characters of the name, A-Z lower-cased, equal to
    * "null" (DAT_1005ab40): no texture, TRUE;</li>
    * <li>then only "mask" (DAT_1005ab38) followed by a raster name may
    * follow; a missing mask name is error 5 and any other word error 4,
    * both FALSE;</li>
    * <li>RwGetNamedTexture(name) ({@link NativeTextures#rwGetNamed}); 0 is
    * FALSE, otherwise it goes on the current material.</li>
    * </ul>
    * ⚠️ VERIFY, not translated: the mask (RwReadMaskRaster 0x10026f80 +
    * RwMaskTexture 0x10019510). No corpus script uses it; the mask is
    * ignored with a warning and the texture set unmasked.
    */
   private static boolean texture(Ctx c, String[] t) {
      if (t.length < 2) {
         return false;
      }
      String name = t[1];
      String head = lowerAZ(name.length() > 4 ? name.substring(0, 4) : name);
      Mat m = c.mat();
      if (head.equals("null")) {
         m.texture = null;
         m.textureHandle = 0;
         return true;
      }
      String mask = null;
      for (int i = 2; i < t.length; i += 2) {
         if (!lowerAZ(t[i]).equals("mask")) {
            return false;
         }
         if (i + 1 >= t.length) {
            return false;
         }
         mask = t[i + 1];
      }
      if (mask != null) {
         System.err.println("[RW] Texture " + name + " mask " + mask + ": mask not translated (⚠️), texture without a mask");
      }
      int tex = NativeTextures.rwGetNamed(name);
      if (tex == 0) {
         System.err.println("[RW] RwReadShape: Texture " + name + " not found: the shape is not read");
         return false;
      }
      m.texture = name;
      m.textureHandle = tex;
      return true;
   }

   private static String lowerAZ(String s) {
      StringBuilder b = new StringBuilder(s.length());
      for (int i = 0; i < s.length(); i++) {
         char ch = s.charAt(i);
         b.append(ch >= 'A' && ch <= 'Z' ? (char) (ch + 0x20) : ch);
      }
      return b.toString();
   }

   private static void preConcatModeling(int clump, float[] ctm) {
      float[] m = new float[16];
      NativeScene.getClumpMatrix(clump, m);
      NativeRw.transformMatrix(m, ctm, NativeRw.PRECONCAT);
      NativeScene.transformClump(clump, m, NativeRw.REPLACE);
   }

   private static void material(Ctx c, String cmd, String[] t) {
      Mat m = c.mat();
      if (cmd.equals("color")) {
         m.r = f(t, 1);
         m.g = f(t, 2);
         m.b = f(t, 3);
      } else if (cmd.equals("ambient")) {
         m.ambient = f(t, 1);
      } else if (cmd.equals("diffuse")) {
         m.diffuse = f(t, 1);
      } else if (cmd.equals("specular")) {
         m.specular = f(t, 1);
      } else if (cmd.equals("surface")) {
         m.ambient = f(t, 1);
         m.diffuse = f(t, 2);
         m.specular = f(t, 3);
      } else if (cmd.equals("opacity")) {
         m.opacity = f(t, 1);
      } else if (cmd.equals("geometrysampling")) {
         String s = t.length > 1 ? t[1].toLowerCase() : "solid";
         m.geometrySampling = s.equals("pointcloud") ? 1 : (s.equals("wireframe") ? 2 : 4);
      } else if (cmd.equals("lightsampling")) {
         String s = t.length > 1 ? t[1].toLowerCase() : "facet";
         m.lightSampling = s.equals("vertex") ? 2 : 1;
      } else if (cmd.equals("texturemode") || cmd.equals("texturemodes")
            || cmd.equals("addtexturemode") || cmd.equals("removetexturemode")) {
         int mask = 0;
         for (int i = 1; i < t.length; i++) {
            String s = t[i].toLowerCase();
            if (s.equals("lit")) {
               mask |= 1;
            } else if (s.equals("foreshorten")) {
               mask |= 2;
            } else if (s.equals("filter")) {
               mask |= 4;
            } else if (s.equals("trilinear")) {
               mask |= 0x10;
            }
         }
         if (cmd.startsWith("add")) {
            m.textureModes |= mask;
         } else if (cmd.startsWith("remove")) {
            m.textureModes &= ~mask;
         } else {
            m.textureModes = mask;
         }
      } else if (cmd.equals("materialmode") || cmd.equals("materialmodes")
            || cmd.equals("addmaterialmode") || cmd.equals("removematerialmode")) {
         int mask = 0;
         for (int i = 1; i < t.length; i++) {
            String s = t[i].toLowerCase();
            if (s.equals("double")) {
               mask |= 0x80;
            } else if (s.equals("decal")) {
               mask |= 0x40;
            }
         }
         if (cmd.startsWith("add")) {
            m.materialModes |= mask;
         } else if (cmd.startsWith("remove")) {
            m.materialModes &= ~mask;
         } else {
            m.materialModes = mask;
         }
      }
   }

   private static void clumpBegin(Ctx c) {
      boolean standalone = !c.inModel && c.frames.isEmpty();
      Frame fr = new Frame();
      fr.matDepth = c.mats.size();
      c.mats.add(standalone ? new Mat() : c.mat().copy());
      fr.ctmDepth = c.ctm.size();
      fr.ctmAtBegin = standalone ? NativeRw.identity() : c.ctmTop().clone();
      c.ctm.add(NativeRw.identity());
      fr.jointDepth = c.joint.size();
      fr.jointAtBegin = standalone ? NativeRw.identity() : c.jointTop().clone();
      c.joint.add(NativeRw.identity());
      fr.clumps.add(Integer.valueOf(NativeScene.createClump()));
      c.frames.add(fr);
   }

   /** ClumpEnd core (0x1000f980). */
   private static int clumpEndCore(Ctx c) {
      if (c.frames.isEmpty()) {
         return 0;
      }
      Frame fr = c.frames.remove(c.frames.size() - 1);
      int nc = NativeScene.createClump();
      for (int i = 0; i < fr.clumps.size(); i++) {
         NativeScene.mergeClump(nc, fr.clumps.get(i).intValue());
      }
      NativeScene.transformClump(nc, fr.ctmAtBegin, NativeRw.REPLACE);
      NativeScene.transformClumpJoint(nc, fr.jointAtBegin, NativeRw.REPLACE);
      int own = fr.clumps.get(0).intValue();
      NativeScene.setClumpTag(nc, NativeScene.getClumpTag(own));
      NativeScene.setClumpHints(nc, fr.hints);
      NativeScene.setClumpAxisAlignment(nc, fr.axisAlignment);
      for (int i = 0; i < fr.clumps.size(); i++) {
         int src = fr.clumps.get(i).intValue();
         float[] ltm = new float[16];
         NativeScene.getClumpLTM(src, ltm);
         int[] children = NativeScene.childHandles(src);
         for (int k = 0; k < children.length; k++) {
            float[] m = new float[16];
            NativeScene.getClumpMatrix(children[k], m);
            NativeRw.transformMatrix(m, ltm, NativeRw.POSTCONCAT);
            NativeScene.transformClump(children[k], m, NativeRw.REPLACE);
            NativeScene.addChildToClump(nc, children[k]);
         }
         NativeScene.destroyClumpOnly(src);
      }
      while (c.ctm.size() > fr.ctmDepth) {
         c.ctm.remove(c.ctm.size() - 1);
      }
      while (c.joint.size() > fr.jointDepth) {
         c.joint.remove(c.joint.size() - 1);
      }
      while (c.mats.size() > fr.matDepth) {
         c.mats.remove(c.mats.size() - 1);
      }
      Frame parent = c.frame();
      if (parent != null) {
         NativeScene.addChildToClump(parent.clumps.get(0).intValue(), nc);
      }
      return nc;
   }

   /** Vertex / VertexExt (0x10010270): the inner CTM is applied to the point. */
   private static void vertex(Ctx c, String[] t) {
      Frame fr = c.frame();
      if (fr == null || t.length < 4) {
         return;
      }
      float[] p = NativeRw.transformPoint(c.ctmTop(), f(t, 1), f(t, 2), f(t, 3));
      int clump = fr.clumps.get(0).intValue();
      int idx = NativeScene.addVertex(clump, p[0], p[1], p[2]);
      int i = 4;
      while (i < t.length) {
         String mod = t[i].toLowerCase();
         if (mod.equals("uv") && i + 2 < t.length) {
            NativeScene.setVertexUV(clump, idx, f(t, i + 1), f(t, i + 2));
            i += 3;
         } else if (mod.equals("normal") && i + 3 < t.length) {
            float[] n = NativeRw.transformVector(c.ctmTop(), f(t, i + 1), f(t, i + 2), f(t, i + 3));
            NativeScene.setVertexNormal(clump, idx, n[0], n[1], n[2]);
            i += 4;
         } else {
            i++;
         }
      }
   }

   /** Triangle / Quad / Polygon: 1-based indices into the frame's own clump. */
   private static void polygon(Ctx c, String[] t, int sides, int first) {
      Frame fr = c.frame();
      if (fr == null || sides < 3 || t.length < first + sides) {
         return;
      }
      int[] idx = new int[sides];
      for (int i = 0; i < sides; i++) {
         idx[i] = d(t, first + i);
      }
      int clump = fr.clumps.get(0).intValue();
      int poly = NativeScene.addPolygon(clump, sides, idx);
      if (poly == 0) {
         return;
      }
      NativeScene.setPolygonMaterial(poly, materialHandle(c));
      for (int i = first + sides; i + 1 < t.length; i++) {
         if (t[i].toLowerCase().equals("tag")) {
            NativeScene.setPolygonTag(poly, d(t, i + 1));
         }
      }
   }

   /** The current material, as copy-on-write leaves it attached to this polygon. */
   private static int materialHandle(Ctx c) {
      Mat m = c.mat();
      String key = m.key();
      Integer h = c.matHandles.get(key);
      if (h != null) {
         return h.intValue();
      }
      int mat = NativeScene.createMaterial();
      NativeScene.setMaterialColor(mat, m.r, m.g, m.b);
      NativeScene.setMaterialSurface(mat, m.ambient, m.diffuse, m.specular);
      NativeScene.setMaterialOpacity(mat, m.opacity);
      NativeScene.setMaterialTextureModes(mat, m.textureModes);
      NativeScene.setMaterialModes(mat, m.materialModes);
      NativeScene.setMaterialLightSampling(mat, m.lightSampling);
      NativeScene.setMaterialGeometrySampling(mat, m.geometrySampling);
      if (m.textureHandle != 0) {
         NativeScene.setMaterialTexture(mat, m.textureHandle);
         NativeScene.setMaterialTextureName(mat, m.texture);
      }
      c.matHandles.put(key, Integer.valueOf(mat));
      return mat;
   }
}

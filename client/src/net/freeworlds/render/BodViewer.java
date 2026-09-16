package net.freeworlds.render;

import net.freeworlds.bod.BodClump;
import net.freeworlds.bod.BodFile;
import net.freeworlds.bod.BodParser;
import net.freeworlds.bod.BodVertex;
import net.freeworlds.bod.SeqParser;
import net.freeworlds.bod.SeqSampler;
import net.freeworlds.rwx.RwxMaterial;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Minimal LWJGL renderer for a parsed .bod avatar in bind pose - the item
 * explicitly listed as NOT done in docs/bod-format-reference.md ("No visual
 * rendering of a decoded .bod avatar yet").
 *
 * Assembly rule is from Worlds Inc.'s own encoder source, not invented:
 * tools/gdk-sdk/RWXTOBOD.PL says "placeholder clumps ... are stub child
 * clumps that have a transform and to which other parts attach. Any
 * transform value in a part is moved into a placeholder in the parent when
 * it is broken up by this program." So every part root's own translation
 * is (0,0,0) in real files (verified: tina.bod, all 16 parts) and a part's
 * world origin is its parent's origin plus the placeholder translation
 * that references it. Part-local vertex coordinates are near-origin
 * (verified per-part bboxes, all within centimeters of local origin), so
 * rendering parts without resolving placeholders would collapse the whole
 * avatar onto one point - the walk below is required, not optional.
 *
 * Deliberately conservative, following docs/render-pipeline-reference.md:
 * fixed-function pipeline only (glBegin/glEnd, GlLighting's real 2-light
 * model from Room.java/RoomEnvironment.addLight), flat per-clump RGB color
 * (.bod stores only flat RGB per clump; sus vertices SI traen UV, pero el
 * nombre de textura sale del nombre del avatar via
 * PosableShape.readTexture/scanTexture -> avatar:<nombre>.cmp/.mov, no de
 * cachedir/45.dat como decia esta nota antes: ver docs/bod-format-reference.md),
 * face normals via cross product (.bod carries no normals at all, so
 * GL_FLAT like RwxViewer - no invented smoothing), both sides visible
 * (winding convention unverified, same discipline as RwgViewer).
 * Pose opcional de un .seq (--seq/--frame), traducida de gamma.dll y
 * RWL21.DLL, sin sistema de huesos inventado (docs/seq-animation-reference.md
 * seccion 5): cada clump de parte con tag 1..30 recibe como matriz de joint
 * el cuaternion muestreado (SeqSampler.pose, identidad si no hay track) y
 * la LTM es la de RenderWare 2.1, LTM = Joint x Modelado x LTM_padre en
 * convencion vector fila (RWL21.DLL 0x10004747/0x10004788); placeholder =
 * clump con solo traslacion de modelado. La traslacion de raiz del .seq se
 * suma a la de la pelvis (prepFigure mueve la de la pelvis a la matriz de
 * la figura y la de raiz sustituye la de modelado de la pelvis). Sin --seq
 * todos los joints son identidad: bind pose, como antes.
 *
 * Usage: java -cp ... net.freeworlds.render.BodViewer <file.bod> [--screenshot out.png] [--wireframe] [--unlit] [--angle N]
 *        [--seq file.seq --frame T [--keep-root-z]]   (T en unidades de key del .seq)
 */
public final class BodViewer {
   /** One world-space triangle with its flat clump color. */
   private static final class PlacedTri {
      float ax, ay, az, bx, by, bz, cx, cy, cz;
      float r, g, b;
   }

   public static void main(String[] args) throws IOException {
      if (args.length < 1) {
         System.err.println("Usage: BodViewer <file.bod> [--screenshot out.png] [--wireframe] [--unlit] [--angle N] [--seq file.seq --frame T [--keep-root-z]]");
         System.exit(2);
      }

      String bodPath = args[0];
      String screenshotPath = null;
      boolean wireframe = false;
      boolean unlit = false;
      float startAngle = 35f;
      String seqPath = null;
      short seqFrame = 0;
      boolean keepRootZ = false;
      for (int i = 1; i < args.length; i++) {
         if (args[i].equals("--screenshot") && i + 1 < args.length) {
            screenshotPath = args[++i];
         } else if (args[i].equals("--wireframe")) {
            wireframe = true;
         } else if (args[i].equals("--unlit")) {
            unlit = true;
         } else if (args[i].equals("--angle") && i + 1 < args.length) {
            startAngle = Float.parseFloat(args[++i]);
         } else if (args[i].equals("--seq") && i + 1 < args.length) {
            seqPath = args[++i];
         } else if (args[i].equals("--frame") && i + 1 < args.length) {
            seqFrame = (short) Integer.parseInt(args[++i]);
         } else if (args[i].equals("--keep-root-z")) {
            keepRootZ = true;
         }
      }
      boolean lit = !wireframe && !unlit;

      byte[] data = Files.readAllBytes(new File(bodPath).toPath());
      BodFile bod = BodParser.parse(data);
      SeqSampler.Pose pose = null;
      if (seqPath != null) {
         SeqParser.SeqData seq = SeqParser.parseFile(seqPath);
         pose = SeqSampler.pose(seq, seqFrame, keepRootZ);
         int applied = 0;
         for (float[] q : pose.jointQuat) {
            if (q != null) {
               applied++;
            }
         }
         System.out.println("Pose " + seqPath + ": frame=" + seqFrame + " duration=" + seq.duration
            + " seqJoints=" + seq.joints.size() + " appliedTags=" + applied + " root=("
            + pose.rootTranslation[0] + "," + pose.rootTranslation[1] + "," + pose.rootTranslation[2] + ")");
      }

      Map<Integer, BodClump> partByTag = new HashMap<>();
      for (BodClump p : bod.parts) {
         partByTag.put(p.tag, p);
      }
      // Root = the part no placeholder references (pelvis(1) in every real
      // file checked). Fall back to pelvis(1), then to the first part -
      // never crash on an unexpected file, report what was chosen.
      Set<Integer> referenced = new HashSet<>();
      for (BodClump p : bod.parts) {
         collectPlaceholders(p, referenced);
      }
      BodClump root = null;
      for (BodClump p : bod.parts) {
         if (!referenced.contains(p.tag)) {
            root = p;
            break;
         }
      }
      if (root == null) {
         root = partByTag.get(1);
      }
      if (root == null && !bod.parts.isEmpty()) {
         root = bod.parts.get(0);
      }
      if (root == null) {
         System.err.println("No parts in " + bodPath);
         System.exit(1);
      }

      List<PlacedTri> tris = new ArrayList<>();
      Set<Integer> visited = new HashSet<>();
      int[] badIndices = new int[1];
      collectClump(root, IDENTITY, pose != null ? pose.rootTranslation : null, pose,
         partByTag, visited, tris, badIndices);
      int orphans = 0;
      for (BodClump p : bod.parts) {
         if (!visited.contains(p.tag)) {
            // Not reachable from the root via placeholders (never seen in
            // the real corpus) - emit at its own translation rather than
            // dropping geometry silently.
            orphans++;
            collectClump(p, IDENTITY, null, pose, partByTag, visited, tris, badIndices);
         }
      }

      float[] bbox = boundingBox(tris);
      float cx = (bbox[0] + bbox[3]) / 2f;
      float cy = (bbox[1] + bbox[4]) / 2f;
      float cz = (bbox[2] + bbox[5]) / 2f;
      float radius = Math.max(0.01f, distance(bbox));
      System.out.println("Loaded " + bodPath + ": parts=" + bod.parts.size()
         + " rootTag=" + root.tag + " placedTris=" + tris.size()
         + " orphans=" + orphans + " badIndices=" + badIndices[0]);
      System.out.printf("world bbox x[%.4f,%.4f] y[%.4f,%.4f] z[%.4f,%.4f]%n",
         bbox[0], bbox[3], bbox[1], bbox[4], bbox[2], bbox[5]);

      GLFWErrorCallback.createPrint(System.err).set();
      // Force X11: this dev environment is a real Wayland desktop session
      // (WAYLAND_DISPLAY set) but we're rendering against a separate Xvfb
      // X11 display for testing - GLFW's platform auto-detection prefers
      // Wayland when the env var is present and fails outright there
      // (no real compositor listening on that socket for this process).
      GlUtil.forceX11OnLinux();
      if (!glfwInit()) {
         throw new IllegalStateException("GLFW init failed");
      }

      glfwDefaultWindowHints();
      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      int width = 800;
      int height = 600;
      long window = glfwCreateWindow(width, height, "FreeWorlds BOD Viewer - " + new File(bodPath).getName(), 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }

      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();

      glEnable(GL_DEPTH_TEST);
      glDisable(GL_CULL_FACE); // winding convention unverified for .bod (same as RWG: real data, unknown convention) - draw both sides rather than risk hiding real geometry
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
      if (lit) {
         GlLighting.init();
         GlLighting.applyCulling(true); // both sides visible, see above
      }

      float angle = startAngle;
      int frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         glViewport(0, 0, width, height);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         GlUtil.perspective(60f, (float) width / height, 0.01f, radius * 10f + 1f);

         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         GlUtil.lookAt(cx, cy + radius * 0.6f, cz + radius * 2.2f, cx, cy, cz, 0, 1, 0);
         glTranslatef(cx, cy, cz);
         glRotatef(angle, 0, 1, 0);
         glTranslatef(-cx, -cy, -cz);

         drawTris(tris, lit);

         angle += 0.6f;
         // Leer ANTES del swap (mismo arreglo que WorldViewer/RwgViewer): tras
         // glfwSwapBuffers el back buffer es indefinido; en macOS salia negro.
         if (screenshotPath != null && frame == 0) {
            GlUtil.saveScreenshot(width, height, screenshotPath);
            System.out.println("Screenshot written to " + screenshotPath);
         }
         glfwSwapBuffers(window);
         glfwPollEvents();
      }

      glfwDestroyWindow(window);
      glfwTerminate();
   }

   private static void collectPlaceholders(BodClump c, Set<Integer> out) {
      if (c.placeholder) {
         out.add(c.tag);
         return; // placeholders never have children (per the format doc)
      }
      for (BodClump child : c.children) {
         collectPlaceholders(child, out);
      }
   }

   /** Identidad 4x4 fila-mayor (convencion vector fila de RenderWare). */
   private static final float[] IDENTITY = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

   private static void collectClump(BodClump c, float[] parentLtm, float[] rootTranslation,
         SeqSampler.Pose pose, Map<Integer, BodClump> partByTag, Set<Integer> visited,
         List<PlacedTri> out, int[] badIndices) {
      if (c.placeholder) {
         return; // only reached if a part root itself were a placeholder, which the format forbids - ignore rather than crash
      }
      visited.add(c.tag);
      // RWL21.DLL: LTM = Joint x Modelado x LTM_padre. Modelado = traslacion
      // propia (+ la de raiz del .seq en la pelvis); joint = cuaternion del
      // tag (RwFindTaggedClump + RwTransformClumpJoint modo 1) o identidad.
      float tx = c.tx;
      float ty = c.ty;
      float tz = c.tz;
      if (rootTranslation != null) {
         tx += rootTranslation[0];
         ty += rootTranslation[1];
         tz += rootTranslation[2];
      }
      float[] ltm = mul(mul(jointMatrix(pose, c.tag), translation(tx, ty, tz)), parentLtm);
      if (!c.vertices.isEmpty() && !c.triangles.isEmpty()) {
         float r = (c.r & 0xFF) / 255f;
         float g = (c.g & 0xFF) / 255f;
         float b = (c.b & 0xFF) / 255f;
         List<BodVertex> v = c.vertices;
         for (int[] t : c.triangles) {
            if (t[0] < 0 || t[1] < 0 || t[2] < 0
               || t[0] >= v.size() || t[1] >= v.size() || t[2] >= v.size()) {
               badIndices[0]++;
               continue;
            }
            BodVertex a = v.get(t[0]);
            BodVertex bb = v.get(t[1]);
            BodVertex cc = v.get(t[2]);
            PlacedTri p = new PlacedTri();
            float[] pa = transform(a, ltm);
            float[] pb = transform(bb, ltm);
            float[] pc = transform(cc, ltm);
            p.ax = pa[0]; p.ay = pa[1]; p.az = pa[2];
            p.bx = pb[0]; p.by = pb[1]; p.bz = pb[2];
            p.cx = pc[0]; p.cy = pc[1]; p.cz = pc[2];
            p.r = r; p.g = g; p.b = b;
            out.add(p);
         }
      }
      for (BodClump child : c.children) {
         if (child.placeholder) {
            BodClump target = partByTag.get(child.tag);
            if (target == null) {
               badIndices[0]++; // placeholder referencing a part not in the table (never seen in corpus) - count, don't crash
               continue;
            }
            // Placeholder = clump sin joint con su traslacion de modelado;
            // la parte cuelga de el (WObject.addChildToClump nativo).
            float[] placeholderLtm = mul(translation(child.tx, child.ty, child.tz), ltm);
            collectClump(target, placeholderLtm, null, pose, partByTag, visited, out, badIndices);
         } else {
            collectClump(child, ltm, null, pose, partByTag, visited, out, badIndices);
         }
      }
   }

   private static float[] jointMatrix(SeqSampler.Pose pose, int tag) {
      if (pose == null || tag < 1 || tag >= pose.jointQuat.length || pose.jointQuat[tag] == null) {
         return IDENTITY;
      }
      return SeqSampler.quatToMatrix(pose.jointQuat[tag]);
   }

   private static float[] translation(float x, float y, float z) {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, x, y, z, 1};
   }

   /** a x b fila-mayor: out[i][j] = sum_k a[i][k] * b[k][j] (producto de RWL21.DLL 0x1005118c). */
   private static float[] mul(float[] a, float[] b) {
      float[] o = new float[16];
      for (int i = 0; i < 4; i++) {
         for (int j = 0; j < 4; j++) {
            float s = 0f;
            for (int k = 0; k < 4; k++) {
               s += a[i * 4 + k] * b[k * 4 + j];
            }
            o[i * 4 + j] = s;
         }
      }
      return o;
   }

   /** v x M (vector fila, w = 1). */
   private static float[] transform(BodVertex v, float[] m) {
      return new float[]{
         v.x * m[0] + v.y * m[4] + v.z * m[8] + m[12],
         v.x * m[1] + v.y * m[5] + v.z * m[9] + m[13],
         v.x * m[2] + v.y * m[6] + v.z * m[10] + m[14]};
   }

   private static void drawTris(List<PlacedTri> tris, boolean lit) {
      // Same bracketing discipline as RwxViewer: material/culling changes
      // are illegal between glBegin/glEnd, so break the batch on color
      // change (assembly emits clump-by-clump, so runs are already grouped).
      float lastR = -1f, lastG = -1f, lastB = -1f;
      boolean inBegin = false;
      for (PlacedTri t : tris) {
         if (t.r != lastR || t.g != lastG || t.b != lastB) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            if (lit) {
               GlLighting.applyMaterial(bodMaterial(t.r, t.g, t.b));
            } else {
               glColor3f(t.r, t.g, t.b);
            }
            lastR = t.r; lastG = t.g; lastB = t.b;
         }
         if (!inBegin) {
            glBegin(GL_TRIANGLES);
            inBegin = true;
         }
         if (lit) {
            float[] n = GlLighting.faceNormal(
               t.ax, t.ay, t.az, t.bx, t.by, t.bz, t.cx, t.cy, t.cz);
            glNormal3f(n[0], n[1], n[2]);
         }
         glVertex3f(t.ax, t.ay, t.az);
         glVertex3f(t.bx, t.by, t.bz);
         glVertex3f(t.cx, t.cy, t.cz);
      }
      if (inBegin) {
         glEnd();
      }
   }

   // ⚠️ VERIFICAR: .bod stores only a flat RGB per clump - RWXTOBOD.PL
   // says "Existing Ambient, Diffuse, and Specular values are ignored, and
   // the intensity of the given Color value used to compute lighting
   // levels", without giving a numeric mapping. These scalars reuse the
   // RwgViewer placeholder convention (ambient 0.3, diffuse 0.8, specular
   // 0.1, opacity 1) - same placeholder, same flag, not a verified RW2
   // constant.
   private static RwxMaterial bodMaterial(float r, float g, float b) {
      RwxMaterial mat = new RwxMaterial();
      mat.colorR = r;
      mat.colorG = g;
      mat.colorB = b;
      mat.opacity = 1.0f;
      mat.ambient = 0.3f;
      mat.diffuse = 0.8f;
      mat.specular = 0.1f;
      mat.doubleSided = true;
      return mat;
   }

   private static float[] boundingBox(List<PlacedTri> tris) {
      float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, minZ = Float.MAX_VALUE;
      float maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE, maxZ = -Float.MAX_VALUE;
      for (PlacedTri t : tris) {
         float[] xs = {t.ax, t.bx, t.cx};
         float[] ys = {t.ay, t.by, t.cy};
         float[] zs = {t.az, t.bz, t.cz};
         for (int i = 0; i < 3; i++) {
            minX = Math.min(minX, xs[i]);
            maxX = Math.max(maxX, xs[i]);
            minY = Math.min(minY, ys[i]);
            maxY = Math.max(maxY, ys[i]);
            minZ = Math.min(minZ, zs[i]);
            maxZ = Math.max(maxZ, zs[i]);
         }
      }
      if (tris.isEmpty()) {
         return new float[]{-1, -1, -1, 1, 1, 1};
      }
      return new float[]{minX, minY, minZ, maxX, maxY, maxZ};
   }

   private static float distance(float[] bbox) {
      float dx = bbox[3] - bbox[0];
      float dy = bbox[4] - bbox[1];
      float dz = bbox[5] - bbox[2];
      return (float) Math.sqrt(dx * dx + dy * dy + dz * dz);
   }
}

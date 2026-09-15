package net.freeworlds.render;

import net.freeworlds.rwg.RwgAtom;
import net.freeworlds.rwg.RwgModel;
import net.freeworlds.rwg.RwgParser;
import net.freeworlds.rwg.RwgPolygon;
import net.freeworlds.rwg.RwgVertex;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Minimal LWJGL renderer for a parsed .rwg ATOM - fase 2 equivalent of
 * RwxViewer, for the RWG/BOD investigation session (see
 * docs/rwg-bod-format-reference.md). Deliberately reuses the exact same
 * bare-bones fixed-function approach as RwxViewer: flat color, no
 * textures/lighting, auto-fit camera. This is NOT an avatar renderer -
 * the only real geometry available (IDLE.RWG) is a single flat quad, not
 * an articulated body (see docs for why: the real .rwg test corpus is
 * degenerate for demonstrating joint hierarchy). Its purpose is only to
 * verify, per-pixel, that the parsed VLST/PLST data is geometrically
 * sane - the same verification discipline used for RWX.
 *
 * Usage: java -cp ... net.freeworlds.render.RwgViewer <file.rwg> [--screenshot out.png] [--wireframe]
 */
public final class RwgViewer {
   public static void main(String[] args) throws IOException {
      if (args.length < 1) {
         System.err.println("Usage: RwgViewer <file.rwg> [--screenshot out.png] [--wireframe]");
         System.exit(2);
      }

      String rwgPath = args[0];
      String screenshotPath = null;
      boolean wireframe = false;
      float startAngle = 35f;
      for (int i = 1; i < args.length; i++) {
         if (args[i].equals("--screenshot") && i + 1 < args.length) {
            screenshotPath = args[++i];
         } else if (args[i].equals("--wireframe")) {
            wireframe = true;
         } else if (args[i].equals("--angle") && i + 1 < args.length) {
            startAngle = Float.parseFloat(args[++i]);
         }
      }

      byte[] data = Files.readAllBytes(new File(rwgPath).toPath());
      RwgModel model = RwgParser.parse(data);
      if (model.atom == null) {
         System.err.println("No ATOM/geometry in " + rwgPath);
         System.exit(1);
      }
      RwgAtom atom = model.atom;
      System.out.println("Loaded " + rwgPath + " (name=\"" + model.name + "\"): "
         + atom.vertices.size() + " vertices, " + atom.polygons.size() + " polygons");

      // Fan-triangulate each polygon (verified structure only covers convex n-gons via a shared first vertex - fine for the one real quad we have).
      int[][] triangles = triangulate(atom);

      float[] bbox = boundingBox(atom.vertices);
      float cx = (bbox[0] + bbox[3]) / 2f;
      float cy = (bbox[1] + bbox[4]) / 2f;
      float cz = (bbox[2] + bbox[5]) / 2f;
      float radius = Math.max(0.01f, distance(bbox));

      GLFWErrorCallback.createPrint(System.err).set();
      GlUtil.forceX11OnLinux();
      if (!glfwInit()) {
         throw new IllegalStateException("GLFW init failed");
      }

      glfwDefaultWindowHints();
      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      int width = 800;
      int height = 600;
      long window = glfwCreateWindow(width, height, "FreeWorlds RWG Viewer - " + new File(rwgPath).getName(), 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }

      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();

      glEnable(GL_DEPTH_TEST);
      glDisable(GL_CULL_FACE); // we don't know real winding/culling convention for this format yet - draw both sides rather than risk an invisible model
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
      boolean lit = !wireframe;
      if (lit) {
         GlLighting.init();
         // RWG doesn't carry RWX-style ambient/diffuse/specular material
         // scalars (not part of what's been decoded from the format yet -
         // see docs/rwg-bod-format-reference.md) - this is a placeholder
         // material, not a real parsed value. ⚠️ VERIFICAR.
         GlLighting.applyMaterial(placeholderMaterial());
         // Winding convention unverified (see triangulate() javadoc) and,
         // empirically, NOT consistent face-to-face in real data: enabling
         // backface culling (tested against cube.rwg) removes the WRONG
         // triangles on some faces (visible holes) rather than fixing
         // anything, so both sides are kept visible. That still leaves a
         // real, disclosed artifact on 2 of cube.rwg's 6 faces (a
         // z-fighting-like grid pattern where the near and far side of the
         // solid render at nearly the same depth from a raking angle) -
         // ⚠️ VERIFICAR, not fixed this session. Core geometry (position +
         // normal data) is unaffected and separately verified - see docs.
         GlLighting.applyCulling(true);
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

         drawTriangles(atom.vertices, triangles, lit);

         angle += 0.6f;
         glfwSwapBuffers(window);
         glfwPollEvents();
      }

      if (screenshotPath != null) {
         GlUtil.saveScreenshot(width, height, screenshotPath);
         System.out.println("Screenshot written to " + screenshotPath);
      }

      glfwDestroyWindow(window);
      glfwTerminate();
   }

   private static int[][] triangulate(RwgAtom atom) {
      // ⚠️ VERIFICAR: for the one real quad seen (IDLE.RWG), the 4 stored
      // vertex indices are in GRID order (top-left, top-right,
      // bottom-left, bottom-right), NOT boundary-loop order - confirmed
      // by rendering: a plain fan (0,1,2)+(0,2,3) produced a concave
      // "chevron" instead of the flat rectangle the real positions form.
      // So for exactly 4 vertices we assume grid order and split as a
      // strip (0,1,2)+(1,3,2); for any other count we fall back to a
      // naive fan, unverified against real data.
      java.util.List<int[]> tris = new java.util.ArrayList<>();
      for (RwgPolygon p : atom.polygons) {
         int[] idx = p.vertexIndices;
         if (idx.length == 4) {
            tris.add(new int[]{idx[0], idx[1], idx[2]});
            tris.add(new int[]{idx[1], idx[3], idx[2]});
         } else {
            for (int i = 1; i + 1 < idx.length; i++) {
               tris.add(new int[]{idx[0], idx[i], idx[i + 1]});
            }
         }
      }
      return tris.toArray(new int[0][]);
   }

   private static void drawTriangles(java.util.List<RwgVertex> vertices, int[][] triangles, boolean lit) {
      if (!lit) {
         glColor3f(0.7f, 0.75f, 0.85f); // arbitrary flat gray-blue - no material/texture info decoded yet for this format
      }
      glBegin(GL_TRIANGLES);
      for (int[] t : triangles) {
         RwgVertex a = vertices.get(t[0]);
         RwgVertex b = vertices.get(t[1]);
         RwgVertex c = vertices.get(t[2]);
         // ⚠️ Real-data finding (cube.rwg): the 8 "plain" vertices with no
         // UV also have an all-zero parsed normal (0,0,0) - a missing-data
         // placeholder, not a real direction - and 2 of the 6 cube faces
         // reference exactly those vertices. Feeding a zero-length normal
         // to GL_NORMALIZE is undefined and breaks lighting for that face
         // (visible as a garbled/transparent-looking triangle before this
         // fix). Same fallback discipline as RwxViewer: fall back to the
         // real geometric (cross-product) face normal whenever the parsed
         // per-vertex normal is degenerate, rather than trusting a zero.
         float[] faceN = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
         emit(a, lit, faceN);
         emit(b, lit, faceN);
         emit(c, lit, faceN);
      }
      glEnd();
   }

   private static void emit(RwgVertex v, boolean lit, float[] fallbackNormal) {
      if (lit) {
         float len2 = v.normalX * v.normalX + v.normalY * v.normalY + v.normalZ * v.normalZ;
         if (len2 > 1e-8f) {
            // Real per-vertex normal parsed straight from the VLST record
            // (see docs/rwg-bod-format-reference.md) - not computed/guessed.
            glNormal3f(v.normalX, v.normalY, v.normalZ);
         } else {
            glNormal3f(fallbackNormal[0], fallbackNormal[1], fallbackNormal[2]);
         }
      }
      glVertex3f(v.x, v.y, v.z);
   }

   private static net.freeworlds.rwx.RwxMaterial placeholderMaterial() {
      net.freeworlds.rwx.RwxMaterial mat = new net.freeworlds.rwx.RwxMaterial();
      mat.colorR = 0.7f;
      mat.colorG = 0.75f;
      mat.colorB = 0.85f;
      mat.opacity = 1.0f;
      mat.ambient = 0.3f;
      mat.diffuse = 0.8f;
      mat.specular = 0.1f;
      return mat;
   }

   private static float[] boundingBox(java.util.List<RwgVertex> vertices) {
      float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, minZ = Float.MAX_VALUE;
      float maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE, maxZ = -Float.MAX_VALUE;
      for (RwgVertex v : vertices) {
         minX = Math.min(minX, v.x);
         minY = Math.min(minY, v.y);
         minZ = Math.min(minZ, v.z);
         maxX = Math.max(maxX, v.x);
         maxY = Math.max(maxY, v.y);
         maxZ = Math.max(maxZ, v.z);
      }
      if (vertices.isEmpty()) {
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

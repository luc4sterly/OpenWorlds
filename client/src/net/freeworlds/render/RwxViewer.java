package net.freeworlds.render;

import net.freeworlds.rwx.RwxMaterial;
import net.freeworlds.rwx.RwxModel;
import net.freeworlds.rwx.RwxParser;
import net.freeworlds.rwx.RwxVector3;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;
import org.lwjgl.system.MemoryStack;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.FloatBuffer;
import java.nio.file.Files;

import javax.imageio.ImageIO;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Minimal LWJGL/OpenGL skeleton for the renderer (fase 2, worlds-chat-
 * project.md sec. 5): loads one .rwx file with net.freeworlds.rwx.RwxParser
 * and draws it. Deliberately NOT trying to replicate RenderWare 2 from the
 * first attempt - fixed-function pipeline (glBegin/glVertex - simplest
 * possible way to get real geometry on screen), flat per-triangle color
 * from the parsed material (no textures, no lighting), auto-fit camera,
 * slow auto-rotation so the shape actually reads as 3D. Refine later.
 *
 * Usage: java -cp ... net.freeworlds.render.RwxViewer <file.rwx> [--screenshot out.png] [--wireframe]
 */
public final class RwxViewer {
   public static void main(String[] args) throws IOException {
      if (args.length < 1) {
         System.err.println("Usage: RwxViewer <file.rwx> [--screenshot out.png] [--wireframe] [--unlit]");
         System.exit(2);
      }

      String rwxPath = args[0];
      String screenshotPath = null;
      boolean wireframe = false;
      boolean unlit = false;
      for (int i = 1; i < args.length; i++) {
         if (args[i].equals("--screenshot") && i + 1 < args.length) {
            screenshotPath = args[++i];
         } else if (args[i].equals("--wireframe")) {
            wireframe = true;
         } else if (args[i].equals("--unlit")) {
            unlit = true;
         }
      }
      boolean lit = !wireframe && !unlit;

      String text = new String(Files.readAllBytes(new File(rwxPath).toPath()), "ISO-8859-1");
      RwxModel model = new RwxParser().parse(text);
      System.out.println(
         "Loaded " + rwxPath + ": " + model.vertices.size() + " vertices, "
            + model.triangles.size() + " triangles, "
            + model.warnings.size() + " warnings"
      );
      for (String w : model.warnings) {
         System.out.println("  warning: " + w);
      }

      float[] bbox = boundingBox(model);
      float cx = (bbox[0] + bbox[3]) / 2f;
      float cy = (bbox[1] + bbox[4]) / 2f;
      float cz = (bbox[2] + bbox[5]) / 2f;
      float radius = Math.max(0.01f, distance(bbox));

      GLFWErrorCallback.createPrint(System.err).set();
      // Force X11: this dev environment is a real Wayland desktop session
      // (WAYLAND_DISPLAY set) but we're rendering against a separate Xvfb
      // X11 display for testing - GLFW's platform auto-detection prefers
      // Wayland when the env var is present and fails outright there
      // (no real compositor listening on that socket for this process).
      glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
      if (!glfwInit()) {
         throw new IllegalStateException("GLFW init failed");
      }

      glfwDefaultWindowHints();
      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE); // offscreen-friendly (Xvfb) - we screenshot via glReadPixels, no need to show
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      int width = 800;
      int height = 600;
      long window = glfwCreateWindow(width, height, "FreeWorlds RWX Viewer - " + new File(rwxPath).getName(), 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }

      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();

      glEnable(GL_DEPTH_TEST);
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);
      if (lit) {
         GlLighting.init();
      }

      float angle = 0f;
      int frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         glViewport(0, 0, width, height);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         perspective(60f, (float) width / height, 0.01f, radius * 10f + 1f);

         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         lookAt(cx, cy, cz + radius * 2.2f, cx, cy, cz, 0, 1, 0);
         glTranslatef(cx, cy, cz);
         glRotatef(angle, 0, 1, 0);
         glTranslatef(-cx, -cy, -cz);

         drawModel(model, lit);

         angle += 0.6f;
         glfwSwapBuffers(window);
         glfwPollEvents();
      }

      if (screenshotPath != null) {
         saveScreenshot(width, height, screenshotPath);
         System.out.println("Screenshot written to " + screenshotPath);
      }

      glfwDestroyWindow(window);
      glfwTerminate();
   }

   private static void drawModel(RwxModel model, boolean lit) {
      // glEnable/glCullFace are illegal between glBegin/glEnd, so material
      // (and its culling mode) can only change with glEnd/glBegin bracketing it.
      RwxMaterial lastMat = null;
      boolean inBegin = false;
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            if (lit) {
               GlLighting.applyMaterial(mat);
               GlLighting.applyCulling(mat.doubleSided);
            } else {
               glColor3f(clamp01(mat.colorR), clamp01(mat.colorG), clamp01(mat.colorB));
            }
            lastMat = mat;
         }
         if (!inBegin) {
            glBegin(GL_TRIANGLES);
            inBegin = true;
         }
         int[] t = model.triangles.get(i);
         RwxVector3 a = model.vertices.get(t[0]);
         RwxVector3 b = model.vertices.get(t[1]);
         RwxVector3 c = model.vertices.get(t[2]);
         if (lit) {
            float[] n = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
            glNormal3f(n[0], n[1], n[2]);
         }
         emitVertex(a);
         emitVertex(b);
         emitVertex(c);
      }
      if (inBegin) {
         glEnd();
      }
   }

   private static void emitVertex(RwxVector3 v) {
      glVertex3f(v.x, v.y, v.z);
   }

   private static float clamp01(float v) {
      return v < 0f ? 0f : (v > 1f ? 1f : v);
   }

   private static float[] boundingBox(RwxModel model) {
      float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, minZ = Float.MAX_VALUE;
      float maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE, maxZ = -Float.MAX_VALUE;
      for (RwxVector3 v : model.vertices) {
         minX = Math.min(minX, v.x);
         minY = Math.min(minY, v.y);
         minZ = Math.min(minZ, v.z);
         maxX = Math.max(maxX, v.x);
         maxY = Math.max(maxY, v.y);
         maxZ = Math.max(maxZ, v.z);
      }
      if (model.vertices.isEmpty()) {
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

   // Fixed-function replacements for the old GLU helpers (not part of core
   // LWJGL 3 bindings) - just the standard textbook formulas.
   private static void perspective(float fovYDeg, float aspect, float near, float far) {
      float fH = (float) Math.tan(Math.toRadians(fovYDeg) / 2) * near;
      float fW = fH * aspect;
      glFrustum(-fW, fW, -fH, fH, near, far);
   }

   private static void lookAt(float ex, float ey, float ez, float cx, float cy, float cz, float ux, float uy, float uz) {
      float[] f = normalize(cx - ex, cy - ey, cz - ez);
      float[] u = normalize(ux, uy, uz);
      float[] s = normalize(f[1] * u[2] - f[2] * u[1], f[2] * u[0] - f[0] * u[2], f[0] * u[1] - f[1] * u[0]);
      float[] u2 = {s[1] * f[2] - s[2] * f[1], s[2] * f[0] - s[0] * f[2], s[0] * f[1] - s[1] * f[0]};

      try (MemoryStack stack = MemoryStack.stackPush()) {
         FloatBuffer m = stack.mallocFloat(16);
         m.put(0, s[0]).put(4, s[1]).put(8, s[2]).put(12, 0);
         m.put(1, u2[0]).put(5, u2[1]).put(9, u2[2]).put(13, 0);
         m.put(2, -f[0]).put(6, -f[1]).put(10, -f[2]).put(14, 0);
         m.put(3, 0).put(7, 0).put(11, 0).put(15, 1);
         glMultMatrixf(m);
         glTranslatef(-ex, -ey, -ez);
      }
   }

   private static float[] normalize(float x, float y, float z) {
      float len = (float) Math.sqrt(x * x + y * y + z * z);
      if (len < 1e-8f) {
         return new float[]{0, 0, 0};
      }
      return new float[]{x / len, y / len, z / len};
   }

   private static void saveScreenshot(int width, int height, String path) throws IOException {
      ByteBuffer buf = ByteBuffer.allocateDirect(width * height * 4);
      glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, buf);

      BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
      for (int y = 0; y < height; y++) {
         for (int x = 0; x < width; x++) {
            int i = (x + (height - 1 - y) * width) * 4; // flip vertically: GL origin is bottom-left
            int r = buf.get(i) & 0xFF;
            int g = buf.get(i + 1) & 0xFF;
            int b = buf.get(i + 2) & 0xFF;
            image.setRGB(x, y, 0xFF000000 | (r << 16) | (g << 8) | b);
         }
      }
      ImageIO.write(image, "png", new File(path));
   }
}

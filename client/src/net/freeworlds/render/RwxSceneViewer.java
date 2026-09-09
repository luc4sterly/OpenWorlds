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
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Loads several real .rwx files and renders them together in one scene
 * (fase 2, paso 4 - "si el tiempo lo permite": ver cómo se comporta el
 * motor con una carga más real, varios objetos a la vez, no uno suelto).
 * Reuses exactly the same lit fixed-function pipeline as RwxViewer/
 * GlLighting - no new rendering technique, just more than one model.
 * Objects are laid out on a simple grid (their own real bounding boxes,
 * not invented spacing) so each is fully visible and not overlapping.
 *
 * Usage: java -cp ... net.freeworlds.render.RwxSceneViewer <file1.rwx> [file2.rwx ...] --screenshot out.png
 */
public final class RwxSceneViewer {
   private static final class Placed {
      final RwxModel model;
      final float[] bbox;
      float offsetX, offsetZ;

      Placed(RwxModel model, float[] bbox) {
         this.model = model;
         this.bbox = bbox;
      }
   }

   public static void main(String[] args) throws IOException {
      List<String> rwxPaths = new ArrayList<>();
      String screenshotPath = null;
      for (int i = 0; i < args.length; i++) {
         if (args[i].equals("--screenshot") && i + 1 < args.length) {
            screenshotPath = args[++i];
         } else {
            rwxPaths.add(args[i]);
         }
      }
      if (rwxPaths.isEmpty()) {
         System.err.println("Usage: RwxSceneViewer <file1.rwx> [file2.rwx ...] --screenshot out.png");
         System.exit(2);
      }

      List<Placed> objects = new ArrayList<>();
      float maxHalfExtent = 0f;
      for (String path : rwxPaths) {
         String text = new String(Files.readAllBytes(new File(path).toPath()), "ISO-8859-1");
         RwxModel model = new RwxParser().parse(text);
         float[] bbox = boundingBox(model);
         System.out.println("Loaded " + path + ": " + model.vertices.size() + " vertices, "
            + model.triangles.size() + " triangles");
         objects.add(new Placed(model, bbox));
         maxHalfExtent = Math.max(maxHalfExtent, Math.max(bbox[3] - bbox[0], bbox[5] - bbox[2]) / 2f);
      }

      // Grid layout: real per-object bounding boxes decide centering, only
      // the grid CELL size (derived from the largest real object) is a
      // layout choice, not fabricated geometry.
      int cols = (int) Math.ceil(Math.sqrt(objects.size()));
      float cell = maxHalfExtent * 2.5f + 0.01f;
      float sceneRadius = 0f;
      for (int i = 0; i < objects.size(); i++) {
         Placed p = objects.get(i);
         int col = i % cols;
         int row = i / cols;
         float cx = (p.bbox[0] + p.bbox[3]) / 2f;
         float cz = (p.bbox[2] + p.bbox[5]) / 2f;
         p.offsetX = col * cell - cx;
         p.offsetZ = row * cell - cz;
         float dist = (float) Math.sqrt(
            Math.pow(col * cell, 2) + Math.pow(row * cell, 2)) + distance(p.bbox);
         sceneRadius = Math.max(sceneRadius, dist);
      }
      float sceneCx = (cols - 1) * cell / 2f;
      float sceneCz = ((objects.size() - 1) / cols) * cell / 2f;

      GLFWErrorCallback.createPrint(System.err).set();
      glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
      if (!glfwInit()) {
         throw new IllegalStateException("GLFW init failed");
      }

      glfwDefaultWindowHints();
      glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

      int width = 1024;
      int height = 768;
      long window = glfwCreateWindow(width, height, "FreeWorlds RWX Scene Viewer", 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }

      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();

      glEnable(GL_DEPTH_TEST);
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      GlLighting.init();

      float angle = 30f;
      int frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         glViewport(0, 0, width, height);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         perspective(60f, (float) width / height, 0.01f, sceneRadius * 3f + 1f);

         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         lookAt(sceneCx, sceneRadius * 0.6f, sceneCz + sceneRadius * 1.3f, sceneCx, 0, sceneCz, 0, 1, 0);
         glTranslatef(sceneCx, 0, sceneCz);
         glRotatef(angle, 0, 1, 0);
         glTranslatef(-sceneCx, 0, -sceneCz);

         for (Placed p : objects) {
            glPushMatrix();
            glTranslatef(p.offsetX, 0, p.offsetZ);
            drawModel(p.model);
            glPopMatrix();
         }

         angle += 0.4f;
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

   private static void drawModel(RwxModel model) {
      RwxMaterial lastMat = null;
      boolean inBegin = false;
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            GlLighting.applyMaterial(mat);
            GlLighting.applyCulling(mat.doubleSided);
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
         float[] n = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
         glNormal3f(n[0], n[1], n[2]);
         glVertex3f(a.x, a.y, a.z);
         glVertex3f(b.x, b.y, b.z);
         glVertex3f(c.x, c.y, c.z);
      }
      if (inBegin) {
         glEnd();
      }
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
            int i = (x + (height - 1 - y) * width) * 4;
            int r = buf.get(i) & 0xFF;
            int g = buf.get(i + 1) & 0xFF;
            int b = buf.get(i + 2) & 0xFF;
            image.setRGB(x, y, 0xFF000000 | (r << 16) | (g << 8) | b);
         }
      }
      ImageIO.write(image, "png", new File(path));
   }
}

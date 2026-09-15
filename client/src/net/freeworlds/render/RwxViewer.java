package net.freeworlds.render;

import net.freeworlds.cmp.CmpTexture;
import net.freeworlds.rwx.RwxMaterial;
import net.freeworlds.rwx.RwxModel;
import net.freeworlds.rwx.RwxParser;
import net.freeworlds.rwx.RwxVector3;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;

import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.file.Files;

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
 * Usage: java -cp ... net.freeworlds.render.RwxViewer <file.rwx> [--screenshot out.png] [--wireframe] [--unlit]
 *        [--texture <dir>/<base>] [--camera top|front] [--doubleside]
 *
 * Texturing (2026-09-10, .cmp round 5): --texture points at a verified-texture
 * resource directory + base name (e.g. assets/cmp-verified/sball), decoded at
 * load time through the real CmpStage2 reconstructor (net.freeworlds.cmp) and
 * applied with the model's parsed UVs. This is a pipeline-capability proof -
 * real verified .cmp pixels landing on geometry - NOT a claim about what the
 * original client shows for the file (sball.rwx itself says Texture NULL; the
 * pairing is an explicit demo override, and material colors are forced to
 * white since the file's own materials are degenerate black). Honoring
 * per-material textureName for arbitrary .cmp files needs the Huffman
 * Stage 1 decoder first (see CmpTexture's doc).
 */
public final class RwxViewer {
   public static void main(String[] args) throws IOException {
      if (args.length < 1) {
         System.err.println("Usage: RwxViewer <file.rwx> [--screenshot out.png] [--wireframe] [--unlit]"
            + " [--texture <dir>/<base>] [--camera top|front] [--doubleside]");
         System.exit(2);
      }

      String rwxPath = args[0];
      String screenshotPath = null;
      boolean wireframe = false;
      boolean unlit = false;
      String textureRef = null;
      boolean cameraTop = false;
      boolean forceDoubleSide = false;
      for (int i = 1; i < args.length; i++) {
         if (args[i].equals("--screenshot") && i + 1 < args.length) {
            screenshotPath = args[++i];
         } else if (args[i].equals("--wireframe")) {
            wireframe = true;
         } else if (args[i].equals("--unlit")) {
            unlit = true;
         } else if (args[i].equals("--texture") && i + 1 < args.length) {
            textureRef = args[++i];
         } else if (args[i].equals("--camera") && i + 1 < args.length) {
            cameraTop = args[++i].equalsIgnoreCase("top");
         } else if (args[i].equals("--doubleside")) {
            forceDoubleSide = true;
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

      CmpTexture texture = null;
      if (textureRef != null) {
         File ref = new File(textureRef);
         texture = CmpTexture.load(ref.getParentFile(), ref.getName());
         long uvMapped = model.uvs.stream().filter(uv -> uv[0] != 0f || uv[1] != 0f).count();
         System.out.println("Texture " + textureRef + ": " + texture.width + "x" + texture.height
            + ", model UVs non-zero on " + uvMapped + "/" + model.uvs.size() + " vertices");
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
      GlUtil.forceX11OnLinux();
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
      int glTexture = 0;
      if (texture != null && !wireframe) {
         glTexture = uploadTexture(texture);
         glEnable(GL_TEXTURE_2D);
      }

      float angle = 0f;
      int frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         glViewport(0, 0, width, height);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         glMatrixMode(GL_PROJECTION);
         glLoadIdentity();
         GlUtil.perspective(60f, (float) width / height, 0.01f, radius * 10f + 1f);

         glMatrixMode(GL_MODELVIEW);
         glLoadIdentity();
         if (cameraTop) {
            GlUtil.lookAt(cx, cy + radius * 2.2f, cz, cx, cy, cz, 0, 0, -1);
         } else {
            GlUtil.lookAt(cx, cy, cz + radius * 2.2f, cx, cy, cz, 0, 1, 0);
         }
         glTranslatef(cx, cy, cz);
         glRotatef(angle, 0, 1, 0);
         glTranslatef(-cx, -cy, -cz);

         drawModel(model, lit, glTexture, forceDoubleSide);

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

   private static void drawModel(RwxModel model, boolean lit, int glTexture, boolean forceDoubleSide) {
      // glEnable/glCullFace are illegal between glBegin/glEnd, so material
      // (and its culling mode) can only change with glEnd/glBegin bracketing it.
      RwxMaterial lastMat = null;
      boolean inBegin = false;
      boolean textured = glTexture != 0;
      if (forceDoubleSide && lit) {
         GlLighting.applyCulling(true);
      }
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            if (lit) {
               if (textured) {
                  // Demo scope (see class doc): the file's own materials are
                  // degenerate black, which under GL_MODULATE would hide any
                  // texture. White lets the verified texture pixels show.
                  glColor3f(1f, 1f, 1f);
               } else {
                  GlLighting.applyMaterial(mat);
               }
               if (!forceDoubleSide) {
                  GlLighting.applyCulling(mat.doubleSided);
               }
            } else if (textured) {
               glColor3f(1f, 1f, 1f);
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
         if (textured) {
            float[] uva = model.uvs.get(t[0]);
            float[] uvb = model.uvs.get(t[1]);
            float[] uvc = model.uvs.get(t[2]);
            glTexCoord2f(uva[0], uva[1]);
            emitVertex(a);
            glTexCoord2f(uvb[0], uvb[1]);
            emitVertex(b);
            glTexCoord2f(uvc[0], uvc[1]);
            emitVertex(c);
         } else {
            emitVertex(a);
            emitVertex(b);
            emitVertex(c);
         }
      }
      if (inBegin) {
         glEnd();
      }
   }

   private static void emitVertex(RwxVector3 v) {
      glVertex3f(v.x, v.y, v.z);
   }

   /** Uploads verified .cmp pixels as an OpenGL texture (RGB, no mipmaps -
    * GL_NEAREST, not LINEAR: RenderWare 2's real fixed-function pipeline is
    * the target, and there is no real evidence it applied bilinear
    * filtering, so the conservative unfiltered choice is used rather than
    * assuming smoothing - see WorldViewer's uploadTexture for the same
    * decision applied scene-wide. REPEAT wrap so the slight >1.0 UV
    * overshoot real files carry doesn't streak). */
   private static int uploadTexture(CmpTexture texture) {
      int id = glGenTextures();
      glBindTexture(GL_TEXTURE_2D, id);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      ByteBuffer buf = ByteBuffer.allocateDirect(texture.rgb.length);
      // GL expects the first row uploaded to be the BOTTOM row: flip the
      // top-down decode (whether RWX v=0 means bottom - the RenderWare
      // convention - is still unverified and noted as such; the histogram
      // proof below is flip-invariant either way).
      int rowBytes = texture.width * 3;
      for (int y = texture.height - 1; y >= 0; y--) {
         buf.put(texture.rgb, y * rowBytes, rowBytes);
      }
      buf.flip();
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height,
         0, GL_RGB, GL_UNSIGNED_BYTE, buf);
      System.out.println("Uploaded texture " + texture.width + "x" + texture.height);
      return id;
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
}

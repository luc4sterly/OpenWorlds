package net.freeworlds.render;

import net.freeworlds.cmp.CmpTexture;
import net.freeworlds.rwx.RwxMaterial;
import net.freeworlds.rwx.RwxModel;
import net.freeworlds.rwx.RwxParser;
import net.freeworlds.rwx.RwxVector3;
import net.freeworlds.world.WNode;
import net.freeworlds.world.WorldRestorer;

import org.lwjgl.glfw.GLFWErrorCallback;
import org.lwjgl.opengl.GL;
import org.lwjgl.system.MemoryStack;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.FloatBuffer;
import java.nio.file.Files;
import java.util.Enumeration;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import static org.lwjgl.glfw.GLFW.*;
import static org.lwjgl.opengl.GL11.*;

/**
 * Loads a real .world file (WorldRestorer), picks one room, and renders
 * every real placed object in it using the exact same lit fixed-function
 * pipeline as RwxViewer/RwxSceneViewer - the point of this session: a
 * real .world positions and draws its own objects, not a handful placed
 * by hand. Geometry URLs ("tex/frame.rwx") are resolved relative to the
 * .world file's own directory (verified in docs/world-format-reference.md
 * against real content in assets/WorldsPlayer/GroundZero/tex/). Each
 * WObject's real 16-float transform matrix (see WNode.matrix) is applied
 * via the GL matrix stack, so the scene graph's own nesting (Room ->
 * RoomEnvironment -> ... -> Shape) composes transforms exactly like the
 * real client's scene graph would - no manual matrix math, no invented
 * layout.
 *
 * avatar: URLs (PosableShape/avatar references) are skipped, not
 * rendered - the RWG parser (see docs/rwg-bod-format-reference.md) is
 * only verified for single-joint geometry, not real articulated
 * avatars, so rendering one here would risk showing something wrong
 * presented as if it were a real avatar. Skipped objects are counted
 * and reported, not silently dropped.
 *
 * Textures (2026-09-11): each material's real "Texture" reference is
 * resolved against the scene's own real texture archive (content.zip,
 * sitting next to the .world file in the real install - see
 * resolveTextureArchive) and decoded through the verified net.freeworlds.
 * cmp pipeline (CmpTexture, backed by Stage2 + - once available - Stage1).
 * No invented pixels: a material whose texture can't be decoded (Stage 1
 * not implemented for it yet, a .bmp-named reference with no loader, or
 * genuinely missing from the archive) keeps its real parsed flat color
 * instead, and is counted/reported, never silently guessed. See
 * resolveTexture()'s javadoc for the exact fallback accounting.
 *
 * Usage: java -cp ... net.freeworlds.render.WorldViewer <file.world> <roomName> [--screenshot out.png]
 *        java -cp ... net.freeworlds.render.WorldViewer <file.world> ALL [--screenshot-dir outdir]
 *        java -cp ... net.freeworlds.render.WorldViewer <file.world> --list-rooms
 */
public final class WorldViewer {
   private static final Map<String, RwxModel> modelCache = new HashMap<>();
   // Display list por modelo unico (clave = instancia de modelCache).
   // Optimizacion de rendimiento period-correct (listas de OpenGL 1.x,
   // la tecnica de la epoca de RenderWare 2): captura la MISMA secuencia
   // glMaterial/glNormal/glVertex que el modo inmediato, pixel-identica,
   // compilada una vez y re-ejecutada por instancia. Valida solo dentro
   // del contexto GL actual — se limpia al crear/destruir cada ventana
   // (modo ALL crea un contexto por sala).
   private static final Map<RwxModel, Integer> displayListCache = new HashMap<>();
   private static File baseDir;
   private static int loadedCount = 0;
   private static int missingCount = 0;
   private static int avatarSkipCount = 0;

   // --- Texturing (real, per-material, see class javadoc) ---
   // GL texture ids are only valid within the GL context that created them
   // (a new context per room in ALL mode - same reason displayListCache is
   // cleared there), so this cache is cleared alongside it.
   private static final Map<String, Integer> glTextureCache = new HashMap<>();
   // Extracted once per baseDir (content.zip's real tex/*.cmp files, see
   // resolveTextureArchive) - NOT committed to git, a runtime-only cache.
   private static File textureArchiveDir;
   private static boolean textureArchiveChecked = false;
   // Real per-material texture-reference accounting across the whole run
   // (persists across rooms in ALL mode) - the honest coverage evidence
   // the session asked for, never rounded up.
   private static final Set<String> texturesResolved = new TreeSet<>();
   private static final Map<String, String> texturesUnresolved = new TreeMap<>(); // name -> reason
   private static int materialTextureRefs = 0; // total non-null Texture directives seen (incl. repeats)

    public static void main(String[] args) throws Exception {
       if (args.length < 2) {
          System.err.println("Usage: WorldViewer <file.world> <roomName|ALL|--list-rooms> [--screenshot out.png] [--screenshot-dir outdir]");
          System.exit(2);
       }
       File worldFile = new File(args[0]);
       String roomArg = args[1];
       String screenshotPath = null;
       String screenshotDir = null;
       for (int i = 2; i < args.length; i++) {
          if (args[i].equals("--screenshot") && i + 1 < args.length) {
             screenshotPath = args[++i];
          } else if (args[i].equals("--screenshot-dir") && i + 1 < args.length) {
             screenshotDir = args[++i];
          }
       }

       baseDir = worldFile.getParentFile();
       byte[] data = Files.readAllBytes(worldFile.toPath());
       WNode world = WorldRestorer.parse(data);

       if (roomArg.equals("--list-rooms")) {
          java.util.List<String> names = new java.util.ArrayList<>(world.roomsByName.keySet());
          java.util.Collections.sort(names);
          for (String n : names) {
             System.out.println(n);
          }
          return;
       }

       java.util.List<String> rooms;
       if (roomArg.equals("ALL")) {
          rooms = new java.util.ArrayList<>(world.roomsByName.keySet());
          java.util.Collections.sort(rooms);
          if (screenshotDir != null) {
             new File(screenshotDir).mkdirs();
          }
       } else {
          rooms = java.util.Collections.singletonList(roomArg);
          if (screenshotDir != null) {
             System.err.println("--screenshot-dir only applies with ALL; ignoring");
             screenshotDir = null;
          }
       }

       boolean first = true;
       for (String roomName : rooms) {
          WNode room = world.roomsByName.get(roomName);
          if (room == null) {
             System.err.println("Room \"" + roomName + "\" not found. Available: " + world.roomsByName.keySet());
             if (!roomArg.equals("ALL")) {
                System.exit(1);
             }
             continue;
          }
          String out = screenshotPath;
          if (roomArg.equals("ALL") && screenshotDir != null) {
             out = new File(screenshotDir, "world_" + roomName + ".png").getPath();
          } else if (roomArg.equals("ALL")) {
             out = null; // sin capturas: solo estadisticas por sala
          }
          if (!first) {
             System.out.println("---");
          }
          first = false;
          renderRoom(room, roomName, out);
       }
       printTextureCoverage();
    }

    /** Real, honest coverage accounting across every room rendered this run
     * - never rounded up, see resolveTexture()'s javadoc for what counts as
     * "resolved" vs "unresolved" and why. */
    private static void printTextureCoverage() {
       int totalNames = texturesResolved.size() + texturesUnresolved.size();
       System.out.println("---");
       System.out.println("Texture coverage: " + texturesResolved.size() + "/" + totalNames
          + " unique texture names decoded (" + materialTextureRefs + " total material references seen)");
       if (!texturesUnresolved.isEmpty()) {
          System.out.println("Unresolved (real color fallback, no invented texture):");
          for (Map.Entry<String, String> e : texturesUnresolved.entrySet()) {
             System.out.println("  " + e.getKey() + ": " + e.getValue());
          }
       }
    }

    private static void renderRoom(WNode room, String roomName, String screenshotPath) throws Exception {
       drawnTriangles = 0;
       drawnObjects = 0;

       // Pre-load all geometry referenced in this room so we can report
       // real counts before opening a window (and compute a scene bounding
       // box from REAL loaded vertex data, not a guess).
       float[] bbox = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
       int[] objectCount = {0};
       int loadedBefore = loadedCount;
       int missingBefore = missingCount;
       int avatarBefore = avatarSkipCount;
       preload(room, identity(), bbox, objectCount);
       System.out.println("Room \"" + roomName + "\": " + objectCount[0] + " objects placed, "
          + (loadedCount - loadedBefore) + " real geometry files loaded, " + (missingCount - missingBefore) + " missing on disk, "
          + (avatarSkipCount - avatarBefore) + " avatar: refs skipped (not rendered - see class javadoc)");
      float radius = Math.max(0.01f, distance(bbox));
      float cx = (bbox[0] + bbox[3]) / 2f;
      float cy = (bbox[1] + bbox[4]) / 2f;
      float cz = (bbox[2] + bbox[5]) / 2f;
      System.out.println("Scene bounding box (real, from loaded geometry): "
         + "[" + bbox[0] + "," + bbox[1] + "," + bbox[2] + "] to [" + bbox[3] + "," + bbox[4] + "," + bbox[5] + "]");

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
      long window = glfwCreateWindow(width, height, "FreeWorlds World Viewer - " + roomName, 0, 0);
      if (window == 0) {
         throw new IllegalStateException("Failed to create GLFW window");
      }
      glfwMakeContextCurrent(window);
      glfwSwapInterval(1);
      GL.createCapabilities();
      displayListCache.clear(); // IDs del contexto anterior (modo ALL) no valen aqui
      glTextureCache.clear(); // GL texture ids: mismo motivo, otro contexto

      glEnable(GL_DEPTH_TEST);
      glClearColor(0.10f, 0.10f, 0.14f, 1f);
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      GlLighting.init();

      float angle = 30f;
      int frames = screenshotPath != null ? 1 : Integer.MAX_VALUE;
      for (int frame = 0; frame < frames && !glfwWindowShouldClose(window); frame++) {
         glViewport(0, 0, width, height);
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

         // Real .world scenes are much bigger than a single RWX prop
         // (this room spans ~6200 units), so a generic small-near/
         // big-far range wastes almost all of [near,far] on empty space
         // in front of the eye before the scene even starts - the real
         // scene content lands at view-space depth ~eyeDistance +-
         // radius, squeezed into a sliver right at the far plane in NDC
         // space, where depth-buffer precision collapses and every
         // fragment's depth rounds to exactly the 1.0 clear value -
         // GL_LESS then rejects everything (0 GL error, real triangles
         // submitted, nothing visible - confirmed by projecting a real
         // vertex by hand and finding ndc.z == 0.9999991). Fix: derive
         // near/far tightly around the actual eye-to-scene distance
         // instead of a generic multiple of radius alone.
         float eyeDistance = (float) Math.sqrt(Math.pow(radius * 0.7, 2) + Math.pow(radius * 1.6, 2));
         float near = Math.max(0.01f, eyeDistance - radius * 1.3f);
         float far = eyeDistance + radius * 1.3f;

          glMatrixMode(GL_PROJECTION);
          glLoadIdentity();
          GlUtil.perspective(60f, (float) width / height, near, far);

          glMatrixMode(GL_MODELVIEW);
          glLoadIdentity();
          GlUtil.lookAt(cx, cy + radius * 0.7f, cz + radius * 1.6f, cx, cy, cz, 0, 1, 0);
         glTranslatef(cx, cy, cz);
         glRotatef(angle, 0, 1, 0);
         glTranslatef(-cx, -cy, -cz);

         drawNode(room);

         angle += 0.3f;
         glfwSwapBuffers(window);
         glfwPollEvents();
      }

      System.out.println("Drew " + drawnObjects + " objects, " + drawnTriangles + " triangles this frame. GL error: " + glGetError());

      if (screenshotPath != null) {
         GlUtil.saveScreenshot(width, height, screenshotPath);
         System.out.println("Screenshot written to " + screenshotPath);
      }

      glfwDestroyWindow(window);
      glfwTerminate();
      displayListCache.clear();
      glTextureCache.clear();
    }

   /** Walk the room's real WObject tree once (no GL context needed) purely to resolve+load geometry and compute a real bounding box. */
   private static void preload(WNode n, float[] parentToWorld, float[] bbox, int[] objectCount) {
      float[] here = n.matrix != null ? multiply(parentToWorld, n.matrix) : parentToWorld;
      if (n.geometryUrl != null) {
         objectCount[0]++;
         if (n.geometryUrl.startsWith("avatar:")) {
            avatarSkipCount++;
         } else {
            RwxModel model = loadModel(n.geometryUrl);
            if (model != null) {
               for (RwxVector3 v : model.vertices) {
                  float[] p = transformPoint(here, v.x, v.y, v.z);
                  bbox[0] = Math.min(bbox[0], p[0]);
                  bbox[1] = Math.min(bbox[1], p[1]);
                  bbox[2] = Math.min(bbox[2], p[2]);
                  bbox[3] = Math.max(bbox[3], p[0]);
                  bbox[4] = Math.max(bbox[4], p[1]);
                  bbox[5] = Math.max(bbox[5], p[2]);
               }
            }
         }
      }
      for (WNode c : n.children) {
         preload(c, here, bbox, objectCount);
      }
   }

   static int drawnTriangles = 0;
   static int drawnObjects = 0;

   private static void drawNode(WNode n) {
      glPushMatrix();
      if (n.matrix != null) {
         try (MemoryStack stack = MemoryStack.stackPush()) {
            FloatBuffer buf = stack.mallocFloat(16);
            buf.put(n.matrix).flip();
            glMultMatrixf(buf);
         }
      }
      if (n.geometryUrl != null && !n.geometryUrl.startsWith("avatar:")) {
         RwxModel model = loadModel(n.geometryUrl);
         if (model != null) {
            drawModel(model);
            drawnTriangles += model.triangles.size();
            drawnObjects++;
         }
      }
      for (WNode c : n.children) {
         drawNode(c);
      }
      glPopMatrix();
   }

   private static RwxModel loadModel(String url) {
      if (modelCache.containsKey(url)) {
         return modelCache.get(url);
      }
      RwxModel model = null;
      File f = resolveCaseInsensitive(baseDir, url);
      if (f != null) {
         try {
            String text = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
            model = new RwxParser().parse(text);
            loadedCount++;
         } catch (Exception e) {
            System.err.println("Failed to parse " + f + ": " + e);
            missingCount++;
         }
      } else {
         missingCount++;
      }
      modelCache.put(url, model);
      return model;
   }

   /** Real filesystems here are case-sensitive but the .world file's URLs don't reliably match real file casing (e.g. "tex/frame.rwx" vs real "Frame.rwx") - resolve by case-insensitive match against real directory listings rather than guessing one casing. */
   private static File resolveCaseInsensitive(File base, String relPath) {
      String[] parts = relPath.split("/");
      File cur = base;
      for (String part : parts) {
         if (cur == null || !cur.isDirectory()) {
            return null;
         }
         File exact = new File(cur, part);
         if (exact.exists()) {
            cur = exact;
            continue;
         }
         File[] listing = cur.listFiles();
         File match = null;
         if (listing != null) {
            for (File f : listing) {
               if (f.getName().equalsIgnoreCase(part)) {
                  match = f;
                  break;
               }
            }
         }
         if (match == null) {
            return null;
         }
         cur = match;
      }
      return (cur != null && cur.isFile()) ? cur : null;
   }

    private static void drawModel(RwxModel model) {
       Integer list = displayListCache.get(model);
       if (list != null) {
          glCallList(list);
          return;
       }
       int id = glGenLists(1);
       glNewList(id, GL_COMPILE);
       emitModelImmediate(model);
       glEndList();
       displayListCache.put(model, id);
       glCallList(id);
    }

     /** Secuencia inmediata original (glMaterial/glNormal/glVertex/glTexCoord por triangulo) — unica fuente de verdad visual; la display list solo la captura. */
    private static void emitModelImmediate(RwxModel model) {
       RwxMaterial lastMat = null;
      boolean inBegin = false;
      boolean texEnabled = false;
      for (int i = 0; i < model.triangles.size(); i++) {
         RwxMaterial mat = model.triangleMaterials.get(i);
         if (mat != lastMat) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            GlLighting.applyMaterial(mat);
            GlLighting.applyCulling(mat.doubleSided);
            int glTex = resolveTexture(mat);
            if (glTex != 0) {
               if (!texEnabled) {
                  glEnable(GL_TEXTURE_2D);
                  texEnabled = true;
               }
               glBindTexture(GL_TEXTURE_2D, glTex);
            } else if (texEnabled) {
               glDisable(GL_TEXTURE_2D);
               texEnabled = false;
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
         float[] n = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
         glNormal3f(n[0], n[1], n[2]);
         float[] uva = model.uvs.get(t[0]);
         float[] uvb = model.uvs.get(t[1]);
         float[] uvc = model.uvs.get(t[2]);
         glTexCoord2f(uva[0], uva[1]);
         glVertex3f(a.x, a.y, a.z);
         glTexCoord2f(uvb[0], uvb[1]);
         glVertex3f(b.x, b.y, b.z);
         glTexCoord2f(uvc[0], uvc[1]);
         glVertex3f(c.x, c.y, c.z);
      }
      if (inBegin) {
         glEnd();
      }
      if (texEnabled) {
         glDisable(GL_TEXTURE_2D);
      }
   }

   /**
    * Resolves a material's real "Texture" reference to a real GL texture id,
    * decoded through net.freeworlds.cmp.CmpTexture - or 0 if it can't be
    * decoded (falls back to the material's own real flat color, applied
    * just above by GlLighting.applyMaterial - never an invented texture).
    * Cached per name so repeat materials (e.g. many objects sharing
    * "grnd1.cmp") don't re-decode. Every call is accounted for in
    * texturesResolved/texturesUnresolved for the session's coverage report,
    * whether or not this exact call hits the cache.
    */
   private static int resolveTexture(RwxMaterial mat) {
      if (mat.textureName == null) {
         return 0;
      }
      materialTextureRefs++;
      String base = mat.textureName.trim();
      int dot = base.lastIndexOf('.');
      String ext = dot >= 0 ? base.substring(dot + 1).toLowerCase() : "";
      String name = (dot >= 0 ? base.substring(0, dot) : base).toLowerCase();
      if (glTextureCache.containsKey(name)) {
         Integer cached = glTextureCache.get(name);
         if (cached != 0) {
            texturesResolved.add(name);
         } else if (!texturesUnresolved.containsKey(name)) {
            texturesUnresolved.put(name, "(cached failure, see first occurrence)");
         }
         return cached;
      }
      if (!ext.equals("cmp") && !ext.isEmpty()) {
         // Real corpus has a handful of .bmp-named references (e.g.
         // "rock1a.bmp") - no BMP loader exists in this pipeline (out of
         // this session's scope), so these are honestly counted as
         // unavailable rather than guessed at or silently dropped.
         texturesUnresolved.put(name, "referenced as ." + ext + ", no loader for that extension");
         glTextureCache.put(name, 0);
         return 0;
      }
      File dir = resolveTextureArchive();
      if (dir == null) {
         texturesUnresolved.put(name, "no texture archive found next to this .world");
         glTextureCache.put(name, 0);
         return 0;
      }
      File cmpFile = new File(dir, name + ".cmp");
      try {
         // CmpTexture.loadRaw: the real Stage 1 Huffman/palette decoder
         // (net.freeworlds.cmp.CmpStage1), verified byte-exact against the
         // real cmpview.exe rendering for all 159 .cmp files in this same
         // GroundZero content.zip (docs/cmp-texture-format-reference.md,
         // "Estado final" section) - no pre-captured streams or hand-voted
         // palette needed, unlike the legacy CmpTexture.load used before.
         CmpTexture tex = CmpTexture.loadRaw(cmpFile);
         int id = uploadTexture(tex);
         glTextureCache.put(name, id);
         texturesResolved.add(name);
         return id;
      } catch (Exception e) {
         // No invented pixels: any failure (file missing from the real
         // archive, or a real decode error) falls back to the material's
         // real flat color, never a guessed texture.
         texturesUnresolved.put(name, String.valueOf(e.getMessage()));
         glTextureCache.put(name, 0);
         return 0;
      }
   }

   /**
    * The real client shipped its texture files in a per-world content
    * archive next to the .world file itself (confirmed: assets/WorldsPlayer/
    * GroundZero/content.zip, a genuine period zip with entries under
    * "tex/*.cmp" - same "tex/" convention as the already-extracted
    * tex/*.rwx geometry sitting alongside it on disk). Extracted once,
    * lazily, to a runtime temp dir (NOT committed - content.zip itself
    * already is, this just unpacks what's already real and tracked) so
    * CmpTexture.load's existing dir+basename file API can be reused as-is.
    */
   private static File resolveTextureArchive() {
      if (textureArchiveChecked) {
         return textureArchiveDir;
      }
      textureArchiveChecked = true;
      File zipFile = resolveCaseInsensitive(baseDir, "content.zip");
      if (zipFile == null) {
         return null;
      }
      File outDir = new File(System.getProperty("java.io.tmpdir"),
         "freeworlds-tex-cache/" + zipFile.getParentFile().getName());
      try (ZipFile zf = new ZipFile(zipFile)) {
         Enumeration<? extends ZipEntry> entries = zf.entries();
         while (entries.hasMoreElements()) {
            ZipEntry e = entries.nextElement();
            String n = e.getName();
            if (e.isDirectory() || !n.toLowerCase().endsWith(".cmp")) {
               continue;
            }
            String flatName = new File(n).getName(); // drop the "tex/" prefix
            File outFile = new File(outDir, flatName);
            if (outFile.exists() && outFile.length() == e.getSize()) {
               continue; // already extracted this run/session, real size match
            }
            outDir.mkdirs();
            try (InputStream in = zf.getInputStream(e);
                 FileOutputStream out = new FileOutputStream(outFile)) {
               byte[] buf = new byte[8192];
               int n2;
               while ((n2 = in.read(buf)) > 0) {
                  out.write(buf, 0, n2);
               }
            }
         }
      } catch (IOException e) {
         System.err.println("Failed to extract texture archive " + zipFile + ": " + e);
         return null;
      }
      textureArchiveDir = outDir;
      return outDir;
   }

   /** Uploads decoded .cmp pixels as a real GL texture. GL_NEAREST, no
    * mipmaps: RenderWare 2's real fixed-function pipeline is the target,
    * not a modern filtered look - this session's explicit scope rule is
    * to add nothing RW2 didn't have, and there is no real evidence here
    * (yet) that it applied bilinear filtering, so the conservative,
    * unfiltered choice is used rather than assuming smoothing. GL_REPEAT:
    * real RWX UVs in this corpus carry a slight &gt;1.0 overshoot (see
    * RwxViewer's texturing note) that would streak under GL_CLAMP. */
   private static int uploadTexture(CmpTexture texture) {
      int id = glGenTextures();
      glBindTexture(GL_TEXTURE_2D, id);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      ByteBuffer buf = ByteBuffer.allocateDirect(texture.rgb.length);
      // GL expects the first row uploaded to be the BOTTOM row: flip the
      // top-down decode (see RwxViewer's texturing note re: v=0 orientation).
      int rowBytes = texture.width * 3;
      for (int y = texture.height - 1; y >= 0; y--) {
         buf.put(texture.rgb, y * rowBytes, rowBytes);
      }
      buf.flip();
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.width, texture.height,
         0, GL_RGB, GL_UNSIGNED_BYTE, buf);
      return id;
   }

   private static float[] identity() {
      return new float[]{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
   }

   /** Column-major 4x4 multiply (a*b), matching the OpenGL/three.js convention RwxMatrix4 already uses - real semantics not yet independently confirmed for WObject's "guts" matrix beyond "the scene renders coherently", see docs/world-format-reference.md. */
   private static float[] multiply(float[] a, float[] b) {
      float[] r = new float[16];
      for (int col = 0; col < 4; col++) {
         for (int row = 0; row < 4; row++) {
            float sum = 0;
            for (int k = 0; k < 4; k++) {
               sum += a[k * 4 + row] * b[col * 4 + k];
            }
            r[col * 4 + row] = sum;
         }
      }
      return r;
   }

   private static float[] transformPoint(float[] m, float x, float y, float z) {
      return new float[]{
         m[0] * x + m[4] * y + m[8] * z + m[12],
         m[1] * x + m[5] * y + m[9] * z + m[13],
         m[2] * x + m[6] * y + m[10] * z + m[14]
      };
   }

    private static float distance(float[] bbox) {
       if (bbox[0] > bbox[3]) {
          return 1f; // no geometry loaded at all
       }
       float dx = bbox[3] - bbox[0];
       float dy = bbox[4] - bbox[1];
       float dz = bbox[5] - bbox[2];
       return (float) Math.sqrt(dx * dx + dy * dy + dz * dz);
    }
}

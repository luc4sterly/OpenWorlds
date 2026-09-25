package net.freeworlds.render;

import net.freeworlds.rwg.RwgAtom;
import net.freeworlds.rwg.RwgMaterial;
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
 * Color por poligono (2026-09-25): el material de MALT que el poligono
 * referencia (RwgModel.materialOf, base 1 como RWL21 0x1003a7bc) da color,
 * opacidad y ambiente/difusa/especular (RwSetMaterialColor/Opacity/Surface
 * en 0x1003c10a..0x1003c180, ver RwgMaterial); sin material, el
 * placeholder de siempre. Texturas y modos de material siguen sin
 * aplicarse aqui (doble cara siempre).
 *
 * ⚠️ cube.rwg (y las capturas docs/renders/cube_rwg_*.png) NO es un .rwg
 * que cargue el RenderWare 2.1 de WorldsPlayer: su TELT tiene registros de
 * 16 bytes y RWL21 lee siempre 0x14 (0x1003cc20 push 0x14; RwReadStream),
 * y si el registro es menor salta 0x14 - tamano mas (0x1003cc6c cmp
 * eax,0x14; RwSeekStream), asi que se come el tag STNG y la busqueda
 * acaba fuera del stream (docs/rwg-bod-format-reference.md, "Consecuencias
 * medidas"). RwgParser reproduce ahora ese error (RwgFormatException
 * "error RW 0x5a") y este visor lo rechaza; esas capturas son del parser
 * antiguo, anterior a la lectura de TELT de RWL21, y no muestran nada que
 * el original dibujara.
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
      RwgModel model;
      try {
         model = RwgParser.parse(data);
      } catch (RwgParser.RwgFormatException e) {
         // Lo que RWL21 tampoco lee (p.ej. cube.rwg, ver javadoc de clase).
         System.err.println(rwgPath + ": RenderWare 2.1 no lo carga: " + e.getMessage());
         System.exit(1);
         return;
      }
      if (model.atom == null) {
         System.err.println("No ATOM/geometry in " + rwgPath);
         System.exit(1);
      }
      RwgAtom atom = model.atom;
      System.out.println("Loaded " + rwgPath + " (name=\"" + model.name + "\"): "
         + atom.vertices.size() + " vertices, " + atom.polygons.size() + " polygons");

      // Fan-triangulate each polygon (verified structure only covers convex n-gons via a shared first vertex - fine for the one real quad we have).
      int[][] triangles = triangulate(atom);
      RwgMaterial[] triMaterial = triangleMaterials(model);
      int withMalt = 0;
      for (RwgMaterial m : triMaterial) {
         if (m != null) {
            withMalt++;
         }
      }
      System.out.println("MALT: " + model.materials.size() + " materiales, " + withMalt + "/" + triMaterial.length
         + " triangulos con material");

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
         // Material por poligono desde MALT (ver drawTriangles); el
         // placeholder solo para poligonos sin material.
         // Double-sided kept: the per-material cull mode of RWG (RWX
         // MaterialModes equivalent) is not decoded yet - ⚠️ VERIFICAR.
         // Winding itself IS consistent in the real data (fan-order normal
         // == stored face normal for every polygon, see triangulate()); the
         // old "holes with culling" and cube.rwg's z-fighting on 2 faces
         // were both caused by the PLST index bug fixed in RwgParser
         // (duplicated coplanar +-Z faces, missing +-Y faces).
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

         drawTriangles(model, triangles, triMaterial, lit);

         angle += 0.6f;
         // Leer ANTES del swap (mismo arreglo que WorldViewer): tras
         // glfwSwapBuffers el back buffer es indefinido — en macOS/Cocoa
         // con ventana invisible salía la captura entera en negro.
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

   private static int[][] triangulate(RwgAtom atom) {
      // PLST polygons are boundary loops (RW polygon / RWX Quad semantics):
      // plain fan (0,i,i+1). Verified against real bytes once indices are
      // resolved past the 8 bounding-box records (RwgParser.parseAtom()):
      // all 456 quads of table.rwg, 6/6 of cube.rwg and IDLE.RWG's quad are
      // convex in loop order, and the fan-order normal equals the stored
      // PLST face normal for all 3466 polygons of cube/ball/table/e3/IDLE.
      // History: the old "grid order" quad split (0,1,2)+(1,3,2) was an
      // artifact of indexing the bounding-box records, which are stored
      // exactly in grid order (-x+y, +x+y, -x-y, +x-y).
      java.util.List<int[]> tris = new java.util.ArrayList<>();
      for (RwgPolygon p : atom.polygons) {
         int[] idx = p.vertexIndices;
         for (int i = 1; i + 1 < idx.length; i++) {
            tris.add(new int[]{idx[0], idx[i], idx[i + 1]});
         }
      }
      return tris.toArray(new int[0][]);
   }

   /** Material de cada triangulo del abanico, en el mismo orden que {@link #triangulate}. */
   private static RwgMaterial[] triangleMaterials(RwgModel model) {
      java.util.List<RwgMaterial> out = new java.util.ArrayList<>();
      for (RwgPolygon p : model.atom.polygons) {
         RwgMaterial m = model.materialOf(p);
         for (int i = 1; i + 1 < p.vertexIndices.length; i++) {
            out.add(m);
         }
      }
      return out.toArray(new RwgMaterial[0]);
   }

   private static void drawTriangles(RwgModel model, int[][] triangles, RwgMaterial[] triMaterial, boolean lit) {
      java.util.List<RwgVertex> vertices = model.atom.vertices;
      boolean first = true;
      RwgMaterial last = null;
      boolean inBegin = false;
      for (int k = 0; k < triangles.length; k++) {
         int[] t = triangles[k];
         RwgMaterial m = triMaterial[k];
         if (first || m != last) {
            if (inBegin) {
               glEnd();
               inBegin = false;
            }
            net.freeworlds.rwx.RwxMaterial mat = m != null ? maltMaterial(m) : placeholderMaterial();
            if (lit) {
               GlLighting.applyMaterial(mat);
            } else {
               glColor3f(mat.colorR, mat.colorG, mat.colorB);
            }
            last = m;
            first = false;
         }
         if (!inBegin) {
            glBegin(GL_TRIANGLES);
            inBegin = true;
         }
         RwgVertex a = vertices.get(t[0]);
         RwgVertex b = vertices.get(t[1]);
         RwgVertex c = vertices.get(t[2]);
         // Defensive fallback only: the all-zero normals once seen here were
         // the 8 bounding-box records (not vertices), which RwgParser no
         // longer exposes as geometry - no real vertex of the 8 .rwg in the
         // repo has a zero normal. A zero-length normal under GL_NORMALIZE
         // is undefined, so fall back to the geometric face normal (same
         // discipline as RwxViewer) rather than trusting it.
         float[] faceN = GlLighting.faceNormal(a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
         emit(a, lit, faceN);
         emit(b, lit, faceN);
         emit(c, lit, faceN);
      }
      if (inBegin) {
         glEnd();
      }
   }

   /** El material de MALT como material fijo: color, opacidad y ambiente/difusa/especular leidos del fichero. */
   private static net.freeworlds.rwx.RwxMaterial maltMaterial(RwgMaterial m) {
      net.freeworlds.rwx.RwxMaterial mat = new net.freeworlds.rwx.RwxMaterial();
      mat.colorR = m.r;
      mat.colorG = m.g;
      mat.colorB = m.b;
      mat.opacity = m.opacity;
      mat.ambient = m.ambient;
      mat.diffuse = m.diffuse;
      mat.specular = m.specular;
      return mat;
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

   /**
    * Poligono sin material (MALT 0 o fuera de rango): RWL21 lo deja sin
    * material y su color lo pone el material por defecto del motor, que no
    * esta traducido. ⚠️ VERIFICAR: este gris-azul es un placeholder, no un
    * valor de RW.
    */
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

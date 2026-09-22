package NET.worlds.core;

import java.awt.Component;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferUShort;
import java.util.ArrayList;
import java.util.List;

/**
 * RenderWare 2.1 cameras as gamma.dll uses them (Camera.renderScene
 * 0x00415190 and the room pass 0x00414aa0), rendering on the software
 * driver into a 16-bit 5-6-5 raster that RwShowCameraImage copies into the
 * canvas window. Handles share NativeRw's table.
 */
public final class NativeCamera {
   private NativeCamera() {
   }

   public static final class Cam {
      public final int width;
      public final int height;
      /** 5-6-5 raster, top-down. */
      public final short[] raster;
      public final BufferedImage image;
      public final float[] ltm = NativeRw.identity();
      public float viewWindowX = 1.0F;
      public float viewWindowY = 1.0F;
      public float viewOffsetX;
      public float viewOffsetY;
      public int vpX;
      public int vpY;
      public int vpW;
      public int vpH;
      public int renderOffX;
      public int renderOffY;
      public final float[] backColor = new float[3];
      public float nearClip;
      public float farClip;
      /** RwSetCameraData: the window the image is shown in. */
      public int data;
      int handle;

      Cam(int w, int h) {
         this.width = w;
         this.height = h;
         this.image = new BufferedImage(w, h, BufferedImage.TYPE_USHORT_565_RGB);
         this.raster = ((DataBufferUShort) this.image.getRaster().getDataBuffer()).getData();
         this.vpW = w;
         this.vpH = h;
      }
   }

   public static Cam cam(int h) {
      Object o = NativeRw.get(h);
      return o instanceof Cam ? (Cam) o : null;
   }

   /**
    * FUN_00418f30: RwCreateCamera(w, h, NULL), RwSetCameraData(hwnd),
    * near clip 4.0 (DAT_00470408), far clip 49152.0 (DAT_0047040c).
    */
   public static synchronized int createCamera(int w, int h, int hwnd) {
      Cam c = new Cam(w, h);
      c.data = hwnd;
      c.nearClip = 4.0F;
      c.farClip = 49152.0F;
      c.handle = NativeRw.alloc(c);
      return c.handle;
   }

   public static synchronized void destroyCamera(int h) {
      if (cam(h) != null) {
         NativeRw.release(h);
      }
   }

   /** Camera cache FUN_00415fb0 (DAT_004a0438): one camera per window, recreated when the size changes. */
   private static final List<int[]> cache = new ArrayList<int[]>();

   public static synchronized int cachedCamera(int hwnd, int w, int h) {
      for (int[] e : cache) {
         if (e[1] == hwnd) {
            if (e[2] == w && e[3] == h) {
               return e[0];
            }
            destroyCamera(e[0]);
            e[0] = createCamera(w, h, e[1]);
            e[2] = w;
            e[3] = h;
            return e[0];
         }
      }
      int c = createCamera(w, h, hwnd);
      cache.add(0, new int[]{c, hwnd, w, h});
      return c;
   }

   /** FUN_00419cb0: RwSetCameraRenderOffset(x, y) + RwSetCameraViewport(0, 0, w, h). */
   public static void setOffsetAndViewport(int h, int x, int y, int w, int hh) {
      Cam c = cam(h);
      if (c != null) {
         c.renderOffX = x;
         c.renderOffY = y;
         c.vpX = 0;
         c.vpY = 0;
         c.vpW = w;
         c.vpH = hh;
      }
   }

   /** FUN_0041a020: RwInvalidateCameraViewport + RwShowCameraImage into the window (GetDC of the camera data). */
   public static void show(int h) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      dumpFrame(c);
      fps(c);
      Component comp = NativeWindows.component(c.data);
      if (comp == null) {
         if (!warnedNoWindow) {
            warnedNoWindow = true;
            System.err.println("[RW] la camara " + c.width + "x" + c.height + " no tiene ventana donde volcar la imagen");
         }
         return;
      }
      // The original blits into the child window's DC. A plain
      // getGraphics() draw on an AWT Canvas is wiped whenever the platform
      // recomposes the window (macOS), so use the canvas' own buffer
      // strategy when it has one and fall back to getGraphics().
      diagnose(c, comp);
      if (comp instanceof java.awt.Canvas) {
         java.awt.Canvas canvas = (java.awt.Canvas) comp;
         java.awt.image.BufferStrategy bs = canvas.getBufferStrategy();
         if (bs == null) {
            try {
               canvas.createBufferStrategy(2);
               bs = canvas.getBufferStrategy();
            } catch (RuntimeException e) {
               bs = null;
            }
         }
         if (bs == null) {
            System.err.println("[RW] sin BufferStrategy en " + c.width + "x" + c.height + ": se pinta con getGraphics()");
         }
         if (bs != null) {
            do {
               do {
                  Graphics bg = bs.getDrawGraphics();
                  try {
                     bg.drawImage(c.image, 0, 0, null);
                  } finally {
                     bg.dispose();
                  }
               } while (bs.contentsRestored());
               bs.show();
            } while (bs.contentsLost());
            return;
         }
      }
      Graphics g = comp.getGraphics();
      if (g != null) {
         try {
            g.drawImage(c.image, 0, 0, null);
         } finally {
            g.dispose();
         }
      }
   }

   private static final java.util.Set<String> diagnosed = new java.util.HashSet<String>();

   /** One line per camera: where the image is being blitted and by which route. */
   private static void diagnose(Cam c, Component comp) {
      String key = c.width + "x" + c.height;
      synchronized (diagnosed) {
         if (!diagnosed.add(key)) {
            return;
         }
      }
      String owner = "";
      for (Component p = comp; p != null; p = p.getParent()) {
         owner = owner + " < " + p.getClass().getName() + "[" + p.getWidth() + "x" + p.getHeight() + " vis=" + p.isVisible() + " show=" + p.isShowing() + "]";
      }
      System.err.println("[RW] camara " + key + " -> " + comp.getClass().getName()
         + " canvas=" + (comp instanceof java.awt.Canvas) + owner);
   }

   /** -Dfreeworlds.fps: frames shown per second on the main camera. */
   private static long fpsMark;
   private static int fpsCount;
   private static long framePaint;
   private static long frameTexPaint;

   /** Pixels written by the rasterizers since the last frame was shown. */
   static long framePixels;
   static long frameTexPixels;

   private static void fps(Cam c) {
      if (System.getProperty("freeworlds.fps") == null || c.width != mainWidth) {
         framePixels = 0L;
         frameTexPixels = 0L;
         return;
      }
      framePaint += framePixels;
      frameTexPaint += frameTexPixels;
      framePixels = 0L;
      frameTexPixels = 0L;
      long now = System.nanoTime();
      if (fpsMark == 0L) {
         fpsMark = now;
      }
      fpsCount++;
      if (now - fpsMark >= 1000000000L) {
         System.err.println("[RW] cobertura: " + framePaint / fpsCount + " px escritos por frame de "
            + c.width * c.height + " (" + 100 * framePaint / fpsCount / (c.width * c.height) + " %), "
            + (framePaint == 0 ? 0 : 100 * frameTexPaint / framePaint) + " % con textura");
         framePaint = 0L;
         frameTexPaint = 0L;
         System.err.println("[RW] fps " + (System.nanoTime() - DUMP_T0) / 1000000000L + "s: "
            + (fpsCount * 1000000000L / (now - fpsMark)) + " (camara " + c.width + "x" + c.height
            + " en " + (int) c.ltm[12] + "," + (int) c.ltm[13] + "," + (int) c.ltm[14]
            + " mirando " + Math.round(c.ltm[8] * 100) / 100.0F + "," + Math.round(c.ltm[9] * 100) / 100.0F
            + "," + Math.round(c.ltm[10] * 100) / 100.0F + ")");
         fpsMark = now;
         fpsCount = 0;
      }
   }

   private static int rangeShot;

   private static boolean warnedNoWindow;
   private static final long DUMP_T0 = System.nanoTime();
   private static final java.util.Set<String> dumpedSeconds = new java.util.HashSet<String>();
   private static final java.util.Map<String, Integer> shownBySize = new java.util.HashMap<String, Integer>();

   /**
    * Harness diagnostic: -Dfreeworlds.dumpFrames=DIR saves frames 1, 10, 100, 1000... of each
    * camera as PNG, or with -Dfreeworlds.dumpSeconds=S1,S2,... the first frame after each second mark.
    */
   private static void dumpFrame(Cam c) {
      String dir = System.getProperty("freeworlds.dumpFrames");
      if (dir == null) {
         return;
      }
      String key = c.width + "x" + c.height;
      Integer prev = shownBySize.get(key);
      int shown = prev == null ? 1 : prev + 1;
      shownBySize.put(key, shown);
      String range = System.getProperty("freeworlds.dumpRange");
      if (range != null) {
         long elapsed = (System.nanoTime() - DUMP_T0) / 1000000000L;
         String[] f = range.split(":");
         if (elapsed < Long.parseLong(f[0]) || rangeShot >= Integer.parseInt(f[1]) || c.width != mainWidth) {
            return;
         }
         try {
            javax.imageio.ImageIO.write(c.image, "png", new java.io.File(dir, "seq-" + (1000 + rangeShot++) + ".png"));
         } catch (java.io.IOException e) {
            System.err.println("dumpFrame: " + e);
         }
         return;
      }
      String secs = System.getProperty("freeworlds.dumpSeconds");
      if (secs != null) {
         long elapsed = (System.nanoTime() - DUMP_T0) / 1000000000L;
         String done = key + "@";
         String hit = null;
         for (String s : secs.split(",")) {
            if (elapsed >= Long.parseLong(s) && !dumpedSeconds.contains(done + s)) {
               hit = s;
            }
         }
         if (hit == null) {
            return;
         }
         for (String s : secs.split(",")) {
            if (Long.parseLong(s) <= Long.parseLong(hit)) {
               dumpedSeconds.add(done + s);
            }
         }
         shown = (int) Long.parseLong(hit);
         key = key + "-s";
      } else {
         int n = shown;
         while (n % 10 == 0) {
            n /= 10;
         }
         if (n != 1) {
            return;
         }
      }
      try {
         javax.imageio.ImageIO.write(c.image, "png", new java.io.File(dir, "frame-" + key + "-" + shown + ".png"));
      } catch (java.io.IOException e) {
         System.err.println("dumpFrame: " + e);
      }
   }

   // ------------------------------------------------------------------
   // Camera state (RWL21.DLL 1000c0e0 and friends)

   /** RwTransformCamera(cam, m, 1) (1000bb50 -> 1001d040): orthonormalize, keep only if det > 0.9. */
   public static void transformCamera(int h, float[] m) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      float[] t = NativeRw.orthoNormalize(m);
      float det = (t[1] * t[6] - t[2] * t[5]) * t[8] + (t[2] * t[4] - t[0] * t[6]) * t[9] + (t[0] * t[5] - t[1] * t[4]) * t[10];
      if (det > 0.9F) {
         System.arraycopy(t, 0, c.ltm, 0, 16);
      }
   }

   public static void setViewwindow(int h, float x, float y) {
      Cam c = cam(h);
      if (c != null && x > 0.0F && y > 0.0F) {
         c.viewWindowX = x;
         c.viewWindowY = y;
      }
   }

   public static void setViewOffset(int h, float x, float y) {
      Cam c = cam(h);
      if (c != null) {
         c.viewOffsetX = x;
         c.viewOffsetY = y;
      }
   }

   /** FUN_004192e0: {renderOffsetX, renderOffsetY, viewportW, viewportH}. */
   public static int[] offsetAndViewport(int h) {
      Cam c = cam(h);
      return c == null ? new int[4] : new int[]{c.renderOffX, c.renderOffY, c.vpW, c.vpH};
   }

   /** RwGetCameraPosition: row 3 of the camera matrix. */
   public static float[] getPosition(int h) {
      Cam c = cam(h);
      return c == null ? new float[3] : new float[]{c.ltm[12], c.ltm[13], c.ltm[14]};
   }

   public static void setPosition(int h, float x, float y, float z) {
      Cam c = cam(h);
      if (c != null) {
         c.ltm[12] = x;
         c.ltm[13] = y;
         c.ltm[14] = z;
      }
   }

   /** Main render window size, kept by Camera.renderScene (DAT_0049fcbc / DAT_0049ff64). */
   public static int mainWidth;
   public static int mainHeight;

   /** RwGetCameraLookAt: row 2 of the camera matrix. */
   public static float[] getLookAt(int h) {
      Cam c = cam(h);
      return c == null ? new float[]{0, 0, 1} : new float[]{c.ltm[8], c.ltm[9], c.ltm[10]};
   }

   /** RwGetCameraLookUp: row 1. */
   public static float[] getLookUp(int h) {
      Cam c = cam(h);
      return c == null ? new float[]{0, 1, 0} : new float[]{c.ltm[4], c.ltm[5], c.ltm[6]};
   }

   /**
    * RwSetCameraLookAt: the new view direction, keeping the up vector; the
    * basis is rebuilt as r0 = normalize(up x at), r1 = normalize(at x r0).
    * ⚠️ VERIFICAR: RWL21's exact reconstruction is not extracted yet.
    */
   public static void setLookAt(int h, float x, float y, float z) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      if (x == 0.0F && y == 0.0F && z == 0.0F) {
         return;
      }
      float[] at = norm3(x, y, z);
      float[] up = {c.ltm[4], c.ltm[5], c.ltm[6]};
      float[] r0 = cross(up, at);
      if (len3(r0) <= 0.0F) {
         r0 = new float[]{c.ltm[0], c.ltm[1], c.ltm[2]};
      } else {
         r0 = norm3(r0[0], r0[1], r0[2]);
      }
      float[] r1 = cross(at, r0);
      setRows(c, r0, norm3(r1[0], r1[1], r1[2]), at);
   }

   /**
    * RwSetCameraLookUp: the new up vector, keeping the view direction.
    * ⚠️ VERIFICAR, como setLookAt.
    */
   public static void setLookUp(int h, float x, float y, float z) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      if (x == 0.0F && y == 0.0F && z == 0.0F) {
         return;
      }
      float[] up = norm3(x, y, z);
      float[] at = {c.ltm[8], c.ltm[9], c.ltm[10]};
      float[] r0 = cross(up, at);
      if (len3(r0) <= 0.0F) {
         // up parallel to at: the view direction is rebuilt from right x up
         r0 = new float[]{c.ltm[0], c.ltm[1], c.ltm[2]};
         at = norm3(r0[1] * up[2] - r0[2] * up[1], r0[2] * up[0] - r0[0] * up[2], r0[0] * up[1] - r0[1] * up[0]);
      } else {
         r0 = norm3(r0[0], r0[1], r0[2]);
      }
      float[] r1 = cross(at, r0);
      setRows(c, r0, norm3(r1[0], r1[1], r1[2]), at);
   }

   private static void setRows(Cam c, float[] r0, float[] r1, float[] r2) {
      c.ltm[0] = r0[0];
      c.ltm[1] = r0[1];
      c.ltm[2] = r0[2];
      c.ltm[4] = r1[0];
      c.ltm[5] = r1[1];
      c.ltm[6] = r1[2];
      c.ltm[8] = r2[0];
      c.ltm[9] = r2[1];
      c.ltm[10] = r2[2];
   }

   private static float[] cross(float[] a, float[] b) {
      return new float[]{a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]};
   }

   private static float len3(float[] v) {
      return (float) Math.sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
   }

   private static float[] norm3(float x, float y, float z) {
      float l = (float) Math.sqrt(x * x + y * y + z * z);
      return l > 0.0F ? new float[]{x / l, y / l, z / l} : new float[]{x, y, z};
   }

   /**
    * gamma.dll FUN_0041b670 + FUN_00419670: the screen rectangle the portal
    * covers. The portal quad goes to camera space and is clipped against
    * Z >= 0.025 (the near clipping gamma sets around the call); then, as
    * RwGetClumpViewportRect does (RWL21 10006a70 / 10006be0), the bounding
    * box of those points is projected - its six faces clipped against the
    * frustum - and the extremes are taken in 16.16 fixed point:
    * x = trunc(trunc(65536*w) * X/Z) >> 16 (floor), w = x2 - x.
    * Nothing visible gives {0, 0, 0, 0}.
    */
   public static int[] portalRect(int clump, int h) {
      Cam c = cam(h);
      NativeScene.Clump k = NativeScene.clump(clump);
      if (c == null || k == null || k.verts.size() < 4) {
         return new int[4];
      }
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[][] quad = new float[4][];
      for (int i = 0; i < 4; i++) {
         float[] v = k.verts.get(i);
         float[] w = NativeRw.transformPoint(ltm, v[0], v[1], v[2]);
         quad[i] = toCamera(c, w[0], w[1], w[2]);
      }
      java.util.List<float[]> poly = new ArrayList<float[]>();
      for (int i = 0; i < 4; i++) {
         float[] a = quad[i];
         float[] b = quad[(i + 1) % 4];
         boolean ina = a[2] >= 0.025F, inb = b[2] >= 0.025F;
         if (ina) {
            poly.add(a);
         }
         if (ina != inb) {
            float t = (0.025F - a[2]) / (b[2] - a[2]);
            poly.add(new float[]{a[0] + (b[0] - a[0]) * t, a[1] + (b[1] - a[1]) * t, 0.025F});
         }
      }
      if (poly.isEmpty()) {
         return new int[4];
      }
      float[] lo = {Float.MAX_VALUE, Float.MAX_VALUE, Float.MAX_VALUE};
      float[] hi = {-Float.MAX_VALUE, -Float.MAX_VALUE, -Float.MAX_VALUE};
      for (float[] p : poly) {
         for (int i = 0; i < 3; i++) {
            lo[i] = Math.min(lo[i], p[i]);
            hi[i] = Math.max(hi[i], p[i]);
         }
      }
      // the eight corners of that box, as six faces clipped against the frustum
      float[][] corner = new float[8][];
      for (int i = 0; i < 8; i++) {
         corner[i] = new float[]{(i & 1) != 0 ? hi[0] : lo[0], (i & 2) != 0 ? hi[1] : lo[1], (i & 4) != 0 ? hi[2] : lo[2]};
      }
      int[][] faces = {{0, 1, 3, 2}, {4, 5, 7, 6}, {0, 1, 5, 4}, {0, 4, 6, 2}, {2, 6, 7, 3}, {1, 3, 7, 5}};
      float minX = Float.MAX_VALUE, minY = Float.MAX_VALUE, maxX = -Float.MAX_VALUE, maxY = -Float.MAX_VALUE;
      boolean any = false;
      for (int[] f : faces) {
         float[][] face = new float[4][];
         for (int i = 0; i < 4; i++) {
            float[] p = corner[f[i]];
            face[i] = new float[]{projX(c, p), projY(c, p), p[2]};
         }
         float[][] cl = clipXYZ(face, c);
         for (float[] p : cl) {
            any = true;
            float nx = p[0] / p[2], ny = p[1] / p[2];
            minX = Math.min(minX, nx);
            maxX = Math.max(maxX, nx);
            minY = Math.min(minY, ny);
            maxY = Math.max(maxY, ny);
         }
      }
      if (!any) {
         return new int[4];
      }
      float fw = (int) (65536.0F * (float) c.vpW);
      float fh = (int) (65536.0F * (float) c.vpH);
      int x = (int) (fw * minX) >> 16;
      int y = (int) (fh * minY) >> 16;
      int x2 = (int) (fw * maxX) >> 16;
      int y2 = (int) (fh * maxY) >> 16;
      return new int[]{x, y, x2 - x, y2 - y};
   }

   private static float[] toCamera(Cam c, float wx, float wy, float wz) {
      float dx = wx - c.ltm[12], dy = wy - c.ltm[13], dz = wz - c.ltm[14];
      return new float[]{
         dx * c.ltm[0] + dy * c.ltm[1] + dz * c.ltm[2],
         dx * c.ltm[4] + dy * c.ltm[5] + dz * c.ltm[6],
         dx * c.ltm[8] + dy * c.ltm[9] + dz * c.ltm[10]};
   }

   private static float projX(Cam c, float[] p) {
      return -0.5F / c.viewWindowX * (p[0] + c.viewOffsetX) + (0.5F + 0.5F * c.viewOffsetX / c.viewWindowX) * p[2];
   }

   private static float projY(Cam c, float[] p) {
      return -0.5F / c.viewWindowY * (p[1] - c.viewOffsetY) + (0.5F - 0.5F * c.viewOffsetY / c.viewWindowY) * p[2];
   }

   /** Clip a polygon of {X, Y, Z} against the six frustum planes. */
   private static float[][] clipXYZ(float[][] poly, Cam c) {
      float[][] p = poly;
      for (int plane = 0; plane < 6 && p.length >= 3; plane++) {
         java.util.List<float[]> out = new ArrayList<float[]>();
         for (int i = 0; i < p.length; i++) {
            float[] a = p[i];
            float[] b = p[(i + 1) % p.length];
            float da = dist(a, plane, c), db = dist(b, plane, c);
            if (da >= 0.0F) {
               out.add(a);
            }
            if (da >= 0.0F != db >= 0.0F) {
               float t = da / (da - db);
               out.add(new float[]{a[0] + (b[0] - a[0]) * t, a[1] + (b[1] - a[1]) * t, a[2] + (b[2] - a[2]) * t});
            }
         }
         p = out.toArray(new float[0][]);
      }
      return p;
   }

   public static float[] getViewwindow(int h) {
      Cam c = cam(h);
      return c == null ? new float[]{1, 1} : new float[]{c.viewWindowX, c.viewWindowY};
   }

   public static float[] getViewOffset(int h) {
      Cam c = cam(h);
      return c == null ? new float[2] : new float[]{c.viewOffsetX, c.viewOffsetY};
   }

   /**
    * gamma.dll FUN_00417f40 (mirrored portal): reverse every row of the
    * viewport rectangle in place, starting at the render offset.
    */
   public static void mirrorViewport(int h) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      for (int y = 0; y < c.vpH; y++) {
         int row = (c.renderOffY + y) * c.width + c.renderOffX;
         if (c.renderOffY + y < 0 || c.renderOffY + y >= c.height) {
            continue;
         }
         int a = 0, b = c.vpW - 1;
         while (a < b) {
            short tmp = c.raster[row + a];
            c.raster[row + a] = c.raster[row + b];
            c.raster[row + b] = tmp;
            a++;
            b--;
         }
      }
   }

   /**
    * gamma.dll FUN_0041b3b0: true when the camera is on the front side of
    * the portal, ((camPos - v1) x e1) . e2 > 0 with e1 = v2 - v1 and
    * e2 = v4 - v1 normalized (both longer than 0.0078125); a degenerate
    * portal is treated as not facing the camera.
    */
   public static boolean portalFacesCamera(int camH, int clump) {
      Cam c = cam(camH);
      NativeScene.Clump k = NativeScene.clump(clump);
      if (c == null || k == null || k.verts.size() < 4) {
         return false;
      }
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[] v1 = world(k, ltm, 0);
      float[] v2 = world(k, ltm, 1);
      float[] v4 = world(k, ltm, 3);
      float e1x = v2[0] - v1[0], e1y = v2[1] - v1[1], e1z = v2[2] - v1[2];
      float e2x = v4[0] - v1[0], e2y = v4[1] - v1[1], e2z = v4[2] - v1[2];
      float l1 = (float) Math.sqrt(e1x * e1x + e1y * e1y + e1z * e1z);
      float l2 = (float) Math.sqrt(e2x * e2x + e2y * e2y + e2z * e2z);
      if (!(l1 > 0.0078125F) || !(l2 > 0.0078125F)) {
         return false;
      }
      float s1 = 1.0F / l1, s2 = 1.0F / l2;
      float dx = c.ltm[12] - v1[0], dy = c.ltm[13] - v1[1], dz = c.ltm[14] - v1[2];
      float v = (dx * e1y * s1 - dy * e1x * s1) * e2z * s2
         + (dy * e1z * s1 - dz * e1y * s1) * e2x * s2
         + (dz * e1x * s1 - dx * e1z * s1) * e2y * s2;
      return v > 0.0F;
   }

   private static float[] world(NativeScene.Clump k, float[] ltm, int i) {
      float[] v = k.verts.get(i);
      return NativeRw.transformPoint(ltm, v[0], v[1], v[2]);
   }

   /**
    * gamma.dll FUN_00417dc0: screen row of the horizon. pitch = atan2(at.z,
    * |at.xy|); half vertical field = atan(viewwindowY * 0.5); outside the
    * field the result is 0 (looking down) or the viewport height (looking
    * up); inside, h/2 - (int)((-pitch / viewwindowY) * h + 0.5).
    */
   public static int horizonRow(int h) {
      Cam c = cam(h);
      if (c == null) {
         return 0;
      }
      double lx = c.ltm[8], ly = c.ltm[9], lz = c.ltm[10];
      double pitch = Math.atan2(lz, Math.sqrt(lx * lx + ly * ly));
      double d1 = -pitch;
      double half = Math.atan2(c.viewWindowY * 0.5, 1.0);
      int vh = c.vpH;
      if (d1 <= -half || !(d1 < half)) {
         return d1 < -half ? vh : 0;
      }
      return (vh >> 1) - (int) ((float) d1 / c.viewWindowY * (float) vh + 0.5);
   }

   /** Material/back colour to the device 5-6-5 value (RWL21 1000a6e0, mat+8: floor(c*65536) >> 11 / >> 10). */
   static int device565(float r, float g, float b) {
      int r5 = Math.min(31, (int) (r * 65536.0F) >> 11);
      int g6 = Math.min(63, (int) (g * 65536.0F) >> 10);
      int b5 = Math.min(31, (int) (b * 65536.0F) >> 11);
      return r5 << 11 | g6 << 5 | b5;
   }

   /**
    * gamma.dll FUN_00418eb0: RwSetCameraBackColor + Begin/RwClearCameraViewport/End:
    * fill the viewport rectangle at the render offset with the back colour.
    * ⚠️ components of exactly 1.0 are clamped to the top value (overflow not checked in RWL21).
    */
   public static void clear(int h, float r, float g, float b) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      c.backColor[0] = r;
      c.backColor[1] = g;
      c.backColor[2] = b;
      short col = (short) device565(r, g, b);
      int x0 = Math.max(0, c.renderOffX), y0 = Math.max(0, c.renderOffY);
      int x1 = Math.min(c.width, c.renderOffX + c.vpW), y1 = Math.min(c.height, c.renderOffY + c.vpH);
      for (int y = y0; y < y1; y++) {
         int row = y * c.width;
         for (int x = x0; x < x1; x++) {
            c.raster[row + x] = col;
         }
      }
   }

   // ------------------------------------------------------------------
   // Scene rendering (software driver RWDL6D21, 16-bit)

   /** Per-camera depth buffer: 1/Z, larger is nearer. */
   private static final java.util.Map<Cam, float[]> zbuffers = new java.util.HashMap<Cam, float[]>();

   private static float[] zbuffer(Cam c) {
      float[] z = zbuffers.get(c);
      if (z == null || z.length != c.width * c.height) {
         z = new float[c.width * c.height];
         zbuffers.put(c, z);
      }
      return z;
   }

   /** Specular table S(d) (driver): (k/256)^16, entries 256 and 257 = (255/256)^16. */
   private static final float[] SPEC = new float[258];

   static {
      for (int k = 0; k < 256; k++) {
         SPEC[k] = (float) Math.pow(k / 256.0, 16.0);
      }
      SPEC[256] = SPEC[257] = (float) Math.pow(255.0 / 256.0, 16.0);
   }

   /**
    * Lighting value per channel on the 0..31 scale (driver 1000d230 /
    * 1000d5c0 / 1000d950): I = 31*amb + sum 31*lc*(dif*d + (d > 0.7 ?
    * spec*S(d) : 0)), d = N.L > 0, L = normalize(-dir . inv(LTM)).
    */
   private static void light(NativeScene.Material m, float nx, float ny, float nz, float[][] lights, float[] out, int nl) {
      for (int ch = 0; ch < 3; ch++) {
         out[ch] = 31.0F * m.ambient;
      }
      for (int li = 0; li < nl; li++) {
         float[] l = lights[li];
         float d = nx * l[0] + ny * l[1] + nz * l[2];
         if (d > 0.0F) {
            float s = d > 0.7F ? m.specular * SPEC[Math.min(257, (int) (d * 256.0F))] : 0.0F;
            for (int ch = 0; ch < 3; ch++) {
               out[ch] += 31.0F * l[3 + ch] * (m.diffuse * d + s);
            }
         }
      }
      for (int ch = 0; ch < 3; ch++) {
         float i = out[ch];
         out[ch] = i >= 31.0F ? 31.0F : (float) ((int) (i * 65536.0F)) / 65536.0F;
      }
   }

   /**
    * Colour ramp of the 16-bit driver: 32x32 bytes indexed
    * [integer part of the light intensity][5-bit material component], the
    * table that RWDL6D21 builds in FUN_10008d00 and that its rasterizers
    * (flat 0x10019920, Gouraud/textured 0x100259e0) read as
    * <code>ramp[(intensity &gt;&gt; 16) * 0x20 + component]</code> with the three
    * channel tables at DAT_10079220 + 0 / 0x400 / 0x800.
    *
    * <p>Read from the binary: the intensity is normalised by
    * <code>_DAT_10078098</code> = 1/31, the curve flag
    * <code>DAT_10079234</code> is 0 (the linear branch; the other one is a
    * sine of x*pi/2) and the threshold <code>DAT_10079238</code> is 0.75.
    * Below it the ramp goes from the device shade colour to the material
    * component, above it from the component to white, both in the driver's
    * 8.8 fixed point with its +0x80 rounding, saturating at 0xffff and
    * clamped to [1, 30] (0 is reserved as the transparent texel). The three
    * tables differ only in that dark end (<code>*DAT_1007bda8</code>[0..2]),
    * which is 0 unless FUN_1000b070 builds a fog table, so one table serves
    * the three channels here.
    */
   private static final byte[] RAMP = buildRamp();

   private static byte[] buildRamp() {
      byte[] t = new byte[32 * 32];
      for (int i = 0; i < 32; i++) {
         float x = i * (1.0F / 31.0F);
         for (int c = 0; c < 32; c++) {
            int comp16 = c << 11;
            int v;
            if (x >= 0.75F) {
               int s = (int) ((x - 0.75F) / 0.25F * 65536.0F);
               v = (0x10080 - (0x10000 - s) & 0xFFFFFF00) + ((comp16 + 0x80) >> 8) * (0x10080 - s >> 8);
            } else {
               int s = (int) (x / 0.75F * 65536.0F);
               v = ((comp16 + 0x80) >> 8) * (s + 0x80 >> 8);
            }
            if (v > 0xFFFF) {
               v = 0xFFFF;
            }
            int out = v >> 11;
            if (out > 0x1E) {
               out = 0x1E;
            }
            t[i * 32 + c] = (byte) (out == 0 ? 1 : out);
         }
      }
      return t;
   }

   private static int litComponent(int m5, float lit) {
      int i = (int) lit;
      return RAMP[(i < 0 ? 0 : i > 31 ? 31 : i) * 32 + m5];
   }

   private static int lit565(int c565, float lr, float lg, float lb) {
      int ir = (int) lr, ig = (int) lg, ib = (int) lb;
      int r = RAMP[(ir < 0 ? 0 : ir > 31 ? 31 : ir) * 32 + (c565 >> 11 & 0x1F)];
      int g = RAMP[(ig < 0 ? 0 : ig > 31 ? 31 : ig) * 32 + (c565 >> 6 & 0x1F)] << 1;
      int b = RAMP[(ib < 0 ? 0 : ib > 31 ? 31 : ib) * 32 + (c565 & 0x1F)];
      return r << 11 | g << 5 | b;
   }

   /** Vertex attributes carried through clipping: X, Y, Z, u, v, lr, lg, lb, wx, wy, wz. */
   private static final int NA = 11;

   /** Render state of one pass. */
   private static int centreShown;
   private static final java.util.Set<String> counted = new java.util.HashSet<String>();

   private static final class Pass {
      int texPixels;
      int flatPixels;
      String centre;
      int clumps;
      int polys;
      int drawn;
      Cam c;
      float[] z;
      float[][] lights;
      boolean pick;
      int pickX;
      int pickY;
      float pickZ;
      NativeScene.Clump picked;
      float[] pickPoint;
      java.util.Map<String, int[]> matPixels;
   }

   /**
    * gamma.dll FUN_00419b90: RwBeginCameraUpdate, RwRenderScene, RwEndCameraUpdate.
    * ⚠️ Order: RW sorts clumps with a BSP and polygons with a per-clump tree
    * (10033750, not extracted); here every pass uses a depth buffer cleared
    * at the start of the pass, which is what those orders approximate.
    */
   public static void renderScene(int scene, int h, int zFlag) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      Pass p = new Pass();
      p.c = c;
      p.z = zbuffer(c);
      java.util.Arrays.fill(p.z, 0.0F);
      if (System.getProperty("freeworlds.matStats") != null && c.width == mainWidth) {
         p.matPixels = new java.util.HashMap<String, int[]>();
      }
      probeHit = null;
      drawScene(p, scene);
      matStats(p, scene);
      if (probeHit != null) {
         long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
         synchronized (probeShown) {
            if (probeShown.add(sec + "/" + scene)) {
               System.err.println("[RW] probe " + sec + "s escena " + scene + " (" + probeX + "," + probeY + "): " + probeHit);
            }
         }
      }
      if (System.getProperty("freeworlds.centrePixel") != null && p.centre != null
            && c.width == mainWidth && (System.nanoTime() - DUMP_T0) / 1000000000L >= 25
            && centreShown++ % 300 == 0) {
         System.err.println("[RW] centro de la vista: " + p.centre);
      }
      if (System.getProperty("freeworlds.countPolys") != null && c.width == mainWidth) {
         long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
         String key = sec + "s escena " + scene + " z=" + zFlag;
         synchronized (counted) {
            if (sec >= Long.parseLong(System.getProperty("freeworlds.countPolys")) && counted.add(key)) {
               System.err.println("[RW] pasada " + key + ": " + p.clumps + " clumps, " + p.polys + " poligonos, " + p.drawn + " dibujados, "
                  + p.texPixels + " px con textura, " + p.flatPixels + " px planos, "
                  + degenerateVertexNormals + " normales de vertice degeneradas (caida a la primera cara)");
            }
         }
      }
   }

   /**
    * RwPickScene via gamma.dll 0x004148f0: the nearest polygon under
    * (round(xPick), round(yPick)); the object is the first clump data up the
    * parents; unpickSpot is the world point.
    */
   public static void pick(int scene, NET.worlds.scape.Camera camObj, int h) {
      Cam c = cam(h);
      if (c == null) {
         return;
      }
      Pass p = new Pass();
      p.c = c;
      p.pick = true;
      p.pickX = (int) Math.rint(camObj.rwPickX());
      p.pickY = (int) Math.rint(camObj.rwPickY());
      p.pickZ = 0.0F;
      drawScene(p, scene);
      if (p.picked == null) {
         return;
      }
      NativeScene.Clump k = p.picked;
      Object data = null;
      while (k != null && (data = k.data) == null) {
         k = k.parent;
      }
      if (data instanceof NET.worlds.scape.WObject) {
         camObj.rwSetPick((NET.worlds.scape.WObject) data,
            NET.worlds.scape.Point3Temp.make(p.pickPoint[0], p.pickPoint[1], p.pickPoint[2]));
      } else {
         camObj.rwSetPick(null, null);
      }
   }

   private static void drawScene(Pass p, int scene) {
      java.util.List<NativeScene.Light> ls = NativeScene.sceneLights(scene);
      java.util.List<float[]> lights = new ArrayList<float[]>();
      for (NativeScene.Light l : ls) {
         if (l.state != 1) {
            lights.add(new float[]{l.vector[0], l.vector[1], l.vector[2], l.color[0], l.color[1], l.color[2]});
         }
      }
      p.lights = lights.toArray(new float[0][]);
      java.util.List<NativeScene.Clump> roots = NativeScene.sceneRoots(scene);
      for (int i = 0; i < roots.size(); i++) {
         drawTree(p, roots.get(i), null, 0);
      }
   }

   /**
    * LTM = Joint . Modeling . LTM(parent), the composition RW keeps per
    * clump. The matrices are taken from a per-depth scratch pool instead of
    * being allocated on every clump of every frame (RW writes into the
    * clump's own LTM, it does not allocate either).
    */
   private static void drawTree(Pass p, NativeScene.Clump k, float[] parentLtm, int depth) {
      float[] ltm = scratch(depth);
      NativeRw.mulInto(k.joint, k.modeling, ltm);
      if (parentLtm != null) {
         float[] tmp = scratch(depth + 1024);
         System.arraycopy(ltm, 0, tmp, 0, 16);
         NativeRw.mulInto(tmp, parentLtm, ltm);
      }
      if (k.state != 1) {
         drawClump(p, k, ltm);
      }
      java.util.List<NativeScene.Clump> kids = k.children;
      for (int i = 0; i < kids.size(); i++) {
         drawTree(p, kids.get(i), ltm, depth + 1);
      }
   }

   private static float[][] scratchPool = new float[2048][];

   private static float[] scratch(int slot) {
      if (slot >= scratchPool.length) {
         float[][] bigger = new float[slot * 2][];
         System.arraycopy(scratchPool, 0, bigger, 0, scratchPool.length);
         scratchPool = bigger;
      }
      float[] m = scratchPool[slot];
      if (m == null) {
         m = new float[16];
         scratchPool[slot] = m;
      }
      return m;
   }

   private static void drawClump(Pass p, NativeScene.Clump k, float[] ltm) {
      int nv = k.verts.size();
      p.clumps++;
      p.polys += k.polys.size();
      if (nv == 0 || k.polys.isEmpty()) {
         return;
      }
      Cam c = p.c;
      float[] m = c.ltm;
      float px = m[12], py = m[13], pz = m[14];
      if (wvBuf.length < nv * 3) {
         wvBuf = new float[nv * 3 * 2];
         cvBuf = new float[nv * 3 * 2];
      }
      float[] wv = wvBuf;
      float[] cv = cvBuf;
      for (int i = 0; i < nv; i++) {
         float[] v = k.verts.get(i);
         float wx = v[0] * ltm[0] + v[1] * ltm[4] + v[2] * ltm[8] + ltm[12];
         float wy = v[0] * ltm[1] + v[1] * ltm[5] + v[2] * ltm[9] + ltm[13];
         float wz = v[0] * ltm[2] + v[1] * ltm[6] + v[2] * ltm[10] + ltm[14];
         wv[i * 3] = wx;
         wv[i * 3 + 1] = wy;
         wv[i * 3 + 2] = wz;
         float dx = wx - px, dy = wy - py, dz = wz - pz;
         float xc = dx * m[0] + dy * m[1] + dz * m[2];
         float yc = dx * m[4] + dy * m[5] + dz * m[6];
         float zc = dx * m[8] + dy * m[9] + dz * m[10];
         cv[i * 3] = -0.5F / c.viewWindowX * (xc + c.viewOffsetX) + (0.5F + 0.5F * c.viewOffsetX / c.viewWindowX) * zc;
         cv[i * 3 + 1] = -0.5F / c.viewWindowY * (yc - c.viewOffsetY) + (0.5F - 0.5F * c.viewOffsetY / c.viewWindowY) * zc;
         cv[i * 3 + 2] = zc;
      }
      // lights in the clump's local space: L = normalize(-dir . inv(LTM))
      float[] inv = invBuf;
      NativeRw.invert(ltm, inv);
      if (llBuf.length < p.lights.length) {
         llBuf = new float[p.lights.length][6];
      }
      float[][] ll = llBuf;
      int nl = p.lights.length;
      for (int i = 0; i < nl; i++) {
         float[] l = p.lights[i];
         float dx = -l[0] * inv[0] - l[1] * inv[4] - l[2] * inv[8];
         float dy = -l[0] * inv[1] - l[1] * inv[5] - l[2] * inv[9];
         float dz = -l[0] * inv[2] - l[1] * inv[6] - l[2] * inv[10];
         float len = (float) Math.sqrt(dx * dx + dy * dy + dz * dz);
         if (len > 0.0F) {
            dx /= len;
            dy /= len;
            dz /= len;
         }
         float[] o = ll[i];
         o[0] = dx;
         o[1] = dy;
         o[2] = dz;
         o[3] = l[3];
         o[4] = l[4];
         o[5] = l[5];
      }
      float[] vnorm = null;
      float[] lit = litBuf;
      float[] faces = faceNormals(k);
      for (int pi = 0; pi < k.polys.size(); pi++) {
         NativeScene.Polygon poly = k.polys.get(pi);
         NativeScene.Material mat = NativeScene.material(poly.material);
         int n = poly.indices.length;
         float[][] vs = polyBuf(n);
         boolean vertexLit = mat != null && mat.lightSampling == 2 && NativeTextures.texture(mat.texture) == null && mat.textureName == null;
         if (mat != null && !vertexLit) {
            light(mat, faces[pi * 3], faces[pi * 3 + 1], faces[pi * 3 + 2], ll, lit, nl);
         }
         if (vertexLit && vnorm == null) {
            vnorm = vertexNormals(k);
         }
         for (int i = 0; i < n; i++) {
            int vi = poly.indices[i] - 1;
            float[] a = vs[i];
            a[0] = cv[vi * 3];
            a[1] = cv[vi * 3 + 1];
            a[2] = cv[vi * 3 + 2];
            float[] src = k.verts.get(vi);
            a[3] = src[3];
            a[4] = src[4];
            if (vertexLit) {
               light(mat, vnorm[vi * 3], vnorm[vi * 3 + 1], vnorm[vi * 3 + 2], ll, lit, nl);
            }
            a[5] = lit[0];
            a[6] = lit[1];
            a[7] = lit[2];
            a[8] = wv[vi * 3];
            a[9] = wv[vi * 3 + 1];
            a[10] = wv[vi * 3 + 2];
         }
         float[][] cl = clip(vs, c);
         if (cl.length < 3) {
            continue;
         }
         p.drawn++;
         int m2 = cl.length;
         float[] sx = new float[m2], sy = new float[m2];
         for (int i = 0; i < m2; i++) {
            sx[i] = cl[i][0] / cl[i][2] * c.vpW + c.renderOffX + c.vpX;
            sy[i] = cl[i][1] / cl[i][2] * c.vpH + c.renderOffY + c.vpY;
         }
         float area = (sx[1] - sx[0]) * (sy[2] - sy[0]) - (sx[2] - sx[0]) * (sy[1] - sy[0]);
         boolean front = area < 0.0F;
         if (!front && (mat == null || (mat.materialModes & 0x80) == 0)) {
            continue;
         }
         NativeTextures.Texture tex = mat == null ? null : NativeTextures.texture(mat.texture);
         if (tex == null && mat != null && mat.textureName != null) {
            tex = NativeTextures.find(mat.textureName);
         }
         float[] facet = vertexLit ? null : facetBuf;
         if (facet != null) {
            facet[0] = lit[0];
            facet[1] = lit[1];
            facet[2] = lit[2];
         }
         // The device renders a polygon as a TRIANGLE FAN from its first
         // vertex: RWDL6D21 0x10025970 (textured/Gouraud) and 0x100198b0
         // (flat) walk the vertex list backwards handing (v0, v[i], v[i+1])
         // to the three-vertex rasterizers 0x100259e0 / 0x10019920, with the
         // winding flipped by the caller's flag. Filling the whole n-gon
         // between its leftmost and rightmost edge crossing, as this did
         // before, covers area outside those triangles whenever the
         // projected polygon is warped or concave, and interpolates the
         // texture and the shading over the wrong domain.
         for (int t = 1; t + 1 < m2; t++) {
            triV[0] = cl[0];
            triV[1] = cl[t];
            triV[2] = cl[t + 1];
            triX[0] = sx[0];
            triX[1] = sx[t];
            triX[2] = sx[t + 1];
            triY[0] = sy[0];
            triY[1] = sy[t];
            triY[2] = sy[t + 1];
            raster(p, triV, triX, triY, mat, tex, k, facet);
         }
      }
   }

   /**
    * Unit polygon normal in local space, RWL21 0x10001100 (the helper the
    * BSP builder 0x10033750 uses for every polygon): the sum of the cross
    * products of consecutive edges taken from the FIRST vertex,
    * cross(v[i] - v[0], v[i+1] - v[0]) for i = 1..n-2 (a triangle fan),
    * then normalised. Before this was Newell's formula, which agrees for a
    * planar polygon but not for a warped quad, and its sign was marked as
    * not extracted; the fan is what the binary does, and its sign is the
    * one that faces the viewer for a front (area < 0) polygon.
    */
   private static float[] polygonNormal(NativeScene.Clump k, NativeScene.Polygon poly) {
      float nx = 0, ny = 0, nz = 0;
      int n = poly.indices.length;
      float[] v0 = k.verts.get(poly.indices[0] - 1);
      for (int i = 1; i + 1 < n; i++) {
         float[] a = k.verts.get(poly.indices[i] - 1);
         float[] b = k.verts.get(poly.indices[i + 1] - 1);
         float ax = a[0] - v0[0], ay = a[1] - v0[1], az = a[2] - v0[2];
         float bx = b[0] - v0[0], by = b[1] - v0[1], bz = b[2] - v0[2];
         nx += ay * bz - az * by;
         ny += az * bx - ax * bz;
         nz += ax * by - ay * bx;
      }
      float len = (float) Math.sqrt(nx * nx + ny * ny + nz * nz);
      if (len == 0.0F) {
         return new float[3];
      }
      float s = NORMAL_SIGN / len;
      return new float[]{nx * s, ny * s, nz * s};
   }

   /**
    * Newell's normal is counter-clockwise-positive in a right-handed frame;
    * RW calls a polygon front when it winds counter-clockwise on screen, so
    * the outward normal of a front face points at the eye. ⚠️ the sign
    * convention of RW's own poly+0x10 normal is not extracted; this one is
    * the one consistent with the culling test.
    */
   private static final float NORMAL_SIGN = 1.0F;

   /**
    * RW vertex normals (vert+0x4c), RWL21 0x10041df0 via
    * RwCalculateClumpVertexNormal (0x10031a60): the UNWEIGHTED sum of the
    * normals of the polygons adjacent to the vertex (vert+0x70 list,
    * vert+0x6c count), normalised. When that sum cancels out exactly
    * (rwLengthNormaliseVector returns <= _DAT_100522e8, which is 0.0f in
    * the binary) RW falls back to the normal of the FIRST adjacent
    * polygon instead of leaving a zero vector, which would light that
    * vertex as pitch black.
    */
   private static float[] vertexNormals(NativeScene.Clump k) {
      if (k.vertNormals != null) {
         return k.vertNormals;
      }
      int nv = k.verts.size();
      float[] out = new float[nv * 3];
      float[][] first = new float[nv][];
      float[] faces = faceNormals(k);
      for (int pi = 0; pi < k.polys.size(); pi++) {
         NativeScene.Polygon poly = k.polys.get(pi);
         float[] nrm = {faces[pi * 3], faces[pi * 3 + 1], faces[pi * 3 + 2]};
         for (int idx : poly.indices) {
            int v = idx - 1;
            out[v * 3] += nrm[0];
            out[v * 3 + 1] += nrm[1];
            out[v * 3 + 2] += nrm[2];
            if (first[v] == null) {
               first[v] = nrm;
            }
         }
      }
      for (int i = 0; i < nv; i++) {
         float x = out[i * 3], y = out[i * 3 + 1], z = out[i * 3 + 2];
         float len = (float) Math.sqrt(x * x + y * y + z * z);
         if (len > 0.0F) {
            out[i * 3] = x / len;
            out[i * 3 + 1] = y / len;
            out[i * 3 + 2] = z / len;
         } else if (first[i] != null) {
            out[i * 3] = first[i][0];
            out[i * 3 + 1] = first[i][1];
            out[i * 3 + 2] = first[i][2];
            degenerateVertexNormals++;
         }
      }
      // A normal set by the shape script wins: RW stores it in vert+0x4c
      // with flag 0x40 of vert+0x48 so RwCalculateClumpVertexNormal leaves
      // it alone, and the rasterizer reads that same field.
      for (int i = 0; i < nv; i++) {
         float[] set = NativeScene.vertexNormal(k, i);
         if (set != null) {
            out[i * 3] = set[0];
            out[i * 3 + 1] = set[1];
            out[i * 3 + 2] = set[2];
         }
      }
      k.vertNormals = out;
      return out;
   }

   /**
    * Face normals of the clump, computed once per geometry like RW's (the
    * BSP builder 0x10033750 keeps the plane of each polygon), not once per
    * polygon per frame.
    */
   private static float[] faceNormals(NativeScene.Clump k) {
      if (k.faceNormals != null) {
         return k.faceNormals;
      }
      float[] out = new float[k.polys.size() * 3];
      for (int i = 0; i < k.polys.size(); i++) {
         float[] n = polygonNormal(k, k.polys.get(i));
         out[i * 3] = n[0];
         out[i * 3 + 1] = n[1];
         out[i * 3 + 2] = n[2];
      }
      k.faceNormals = out;
      return out;
   }

   /** Vertices whose adjacent normals cancelled out and took RW's first-polygon fallback. */
   static int degenerateVertexNormals;

   // Scratch buffers of the draw pass. The original transforms into the
   // driver's own vertex array; here they just keep the frame from
   // allocating a few hundred thousand short-lived arrays.
   private static float[] wvBuf = new float[3 * 64];
   private static float[] cvBuf = new float[3 * 64];
   private static final float[] invBuf = new float[16];
   private static final float[] litBuf = new float[3];
   private static float[][] llBuf = new float[8][6];
   private static final float[][] triV = new float[3][];
   private static final float[] triX = new float[3];
   private static final float[] triY = new float[3];
   private static final float[] facetBuf = new float[3];
   private static float[][][] polyBufs = new float[16][][];

   private static float[][] polyBuf(int n) {
      if (n >= polyBufs.length) {
         float[][][] bigger = new float[n * 2][][];
         System.arraycopy(polyBufs, 0, bigger, 0, polyBufs.length);
         polyBufs = bigger;
      }
      float[][] b = polyBufs[n];
      if (b == null) {
         b = new float[n][NA];
         polyBufs[n] = b;
      }
      return b;
   }

   /** Clip against Z >= near, Z <= far, X >= 0, X <= Z, Y >= 0, Y <= Z (flags 0x10, 0x20, 1, 2, 4, 8). */
   private static float[][] clip(float[][] poly, Cam c) {
      float[][] p = poly;
      for (int plane = 0; plane < 6 && p.length >= 3; plane++) {
         java.util.List<float[]> out = new ArrayList<float[]>();
         for (int i = 0; i < p.length; i++) {
            float[] a = p[i];
            float[] b = p[(i + 1) % p.length];
            float da = dist(a, plane, c), db = dist(b, plane, c);
            if (da >= 0.0F) {
               out.add(a);
            }
            if (da >= 0.0F != db >= 0.0F) {
               float t = da / (da - db);
               float[] r = new float[NA];
               for (int j = 0; j < NA; j++) {
                  r[j] = a[j] + (b[j] - a[j]) * t;
               }
               out.add(r);
            }
         }
         p = out.toArray(new float[0][]);
      }
      return p;
   }

   private static float dist(float[] v, int plane, Cam c) {
      switch (plane) {
         case 0:
            return v[2] - c.nearClip;
         case 1:
            return c.farClip - v[2];
         case 2:
            return v[0];
         case 3:
            return v[2] - v[0];
         case 4:
            return v[1];
         default:
            return v[2] - v[1];
      }
   }

   /**
    * Scanline fill as the 16-bit driver does it (RWDL6D21 0x10027de0 for
    * Gouraud, 0x100259e0 for textured):
    *
    * - fill rule: ixL = floor(xLeft), ixR = floor(xRight), pixels
    *   ixL .. ixR-1 (left inclusive, right exclusive), scanlines taken at
    *   integer y with no half-pixel offset;
    * - untextured: Gouraud interpolated affinely in SCREEN space;
    * - textured: flat shaded through per-polygon colour ramps, with the
    *   perspective division done once every 16 pixels and affine
    *   interpolation inside the span; texel 0 is transparent and the
    *   texture wraps at 128;
    * - translucency: ordered 8x8 screen-door pattern (tables 0x10079240 /
    *   0x10079280), the pixel is skipped when opacity <= threshold.
    */
   private static void raster(Pass p, float[][] cl, float[] sx, float[] sy, NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k, float[] facetLit) {
      Cam c = p.c;
      int n = cl.length;
      float minY = Float.MAX_VALUE, maxY = -Float.MAX_VALUE;
      for (int i = 0; i < n; i++) {
         minY = Math.min(minY, sy[i]);
         maxY = Math.max(maxY, sy[i]);
      }
      int y0 = Math.max(Math.max(0, c.renderOffY), (int) Math.floor(minY));
      int y1 = Math.min(Math.min(c.height, c.renderOffY + c.vpH) - 1, (int) Math.floor(maxY) - 1);
      if (p.pick) {
         if (p.pickY < y0 || p.pickY > y1) {
            return;
         }
         y0 = y1 = p.pickY;
      }
      int base = mat == null ? 0 : device565(mat.color[0], mat.color[1], mat.color[2]);
      boolean litTex = mat != null && (mat.textureModes & 1) != 0;
      int opacity = mat == null ? 255 : (mat.opacity >= 1.0F ? 255 : ((int) (mat.opacity * 65536.0F) >> 8) & 0xFC);
      int xMin = Math.max(0, c.renderOffX), xMax = Math.min(c.width, c.renderOffX + c.vpW) - 1;
      // per vertex: 1/Z and u/Z, v/Z for the texture, plus screen-space lighting and world position
      float[][] pv = new float[n][9];
      for (int i = 0; i < n; i++) {
         float iz = 1.0F / cl[i][2];
         pv[i][0] = iz;
         pv[i][1] = cl[i][3] * iz;
         pv[i][2] = cl[i][4] * iz;
         pv[i][3] = cl[i][5];
         pv[i][4] = cl[i][6];
         pv[i][5] = cl[i][7];
         pv[i][6] = cl[i][8] * iz;
         pv[i][7] = cl[i][9] * iz;
         pv[i][8] = cl[i][10] * iz;
      }
      float[] l = new float[9];
      float[] r = new float[9];
      float[] cur = new float[9];
      // flat colour ramps of the textured path: one lighting value per polygon
      int wrote = 0;
      float flatR = facetLit != null ? facetLit[0] : 31.0F;
      float flatG = facetLit != null ? facetLit[1] : 31.0F;
      float flatB = facetLit != null ? facetLit[2] : 31.0F;
      for (int y = y0; y <= y1; y++) {
         float yc = y;
         float lx = Float.MAX_VALUE, rx = -Float.MAX_VALUE;
         for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            float ya = sy[i], yb = sy[j];
            if (ya == yb || yc < Math.min(ya, yb) || yc >= Math.max(ya, yb)) {
               continue;
            }
            float tt = (yc - ya) / (yb - ya);
            float x = sx[i] + (sx[j] - sx[i]) * tt;
            if (x < lx) {
               lx = x;
               for (int a = 0; a < 9; a++) {
                  l[a] = pv[i][a] + (pv[j][a] - pv[i][a]) * tt;
               }
            }
            if (x > rx) {
               rx = x;
               for (int a = 0; a < 9; a++) {
                  r[a] = pv[i][a] + (pv[j][a] - pv[i][a]) * tt;
               }
            }
         }
         if (lx > rx) {
            continue;
         }
         int xs = Math.max(xMin, (int) Math.floor(lx));
         int xe = Math.min(xMax, (int) Math.floor(rx) - 1);
         if (p.pick) {
            if (p.pickX < xs || p.pickX > xe) {
               continue;
            }
            xs = xe = p.pickX;
         }
         float span = rx - lx;
         int row = y * c.width;
         int ditherRow = DITHER_Y[y & 7];
         for (int x = xs; x <= xe; x++) {
            float tt = span <= 0.0F ? 0.0F : (x - lx) / span;
            for (int a = 0; a < 9; a++) {
               cur[a] = l[a] + (r[a] - l[a]) * tt;
            }
            float iz = cur[0];
            if (iz <= 0.0F) {
               continue;
            }
            float zz = 1.0F / iz;
            if (p.pick) {
               if (iz > p.pickZ) {
                  p.pickZ = iz;
                  p.picked = k;
                  p.pickPoint = new float[]{cur[6] * zz, cur[7] * zz, cur[8] * zz};
               }
               continue;
            }
            int zi = row + x;
            if (iz <= p.z[zi]) {
               continue;
            }
            if (opacity != 255) {
               int d = (DITHER_X[x & 7] ^ ditherRow) & 0xFF;
               if (opacity <= d) {
                  continue;
               }
            }
            int pix;
            if (tex != null) {
               int tu = (int) Math.floor(cur[1] * zz * NativeTextures.SIZE) & 0x7F;
               int tv = (int) Math.floor(cur[2] * zz * NativeTextures.SIZE) & 0x7F;
               int texel = tex.pixels[tv * NativeTextures.SIZE + tu] & 0xFFFF;
               if (texel == 0) {
                  continue;
               }
               pix = litTex ? lit565(texel, flatR, flatG, flatB) : texel;
               p.texPixels++;
            } else {
               pix = lit565(base, cur[3], cur[4], cur[5]);
               p.flatPixels++;
            }
            if (x == c.renderOffX + c.vpW / 2 && y == c.renderOffY + c.vpH / 2 && mat != null) {
               p.centre = "color " + mat.color[0] + "," + mat.color[1] + "," + mat.color[2]
                  + " tex=" + (tex != null ? mat.textureName : "NINGUNA(" + mat.textureName + ")")
                  + " amb=" + mat.ambient + " dif=" + mat.diffuse + " z=" + zz
                  + " clump=" + k.verts.size() + "v/" + k.polys.size() + "p";
            }
            p.z[zi] = iz;
            c.raster[zi] = (short) pix;
            wrote++;
            if (probeX >= 0 && x == probeX && y == probeY && c.width == mainWidth) {
               probeHit = describe(mat, tex, k) + " px=#" + Integer.toHexString(pix)
                  + " mundo=(" + (int) (cur[6] * zz) + "," + (int) (cur[7] * zz) + "," + (int) (cur[8] * zz) + ")";
            }
         }
      }
      framePixels += wrote;
      if (tex != null) {
         frameTexPixels += wrote;
      }
      if (p.matPixels != null && wrote > 0) {
         int[] n2 = p.matPixels.get(describe(mat, tex, k));
         if (n2 == null) {
            p.matPixels.put(describe(mat, tex, k), new int[]{wrote});
         } else {
            n2[0] += wrote;
         }
      }
   }

   /** Material + owner of a polygon, for -Dfreeworlds.matStats. */
   private static String describe(NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k) {
      StringBuilder b = new StringBuilder();
      if (mat == null) {
         b.append("sin material");
      } else {
         b.append("color 565=").append(device565(mat.color[0], mat.color[1], mat.color[2]) >> 11 & 31)
            .append(",").append(device565(mat.color[0], mat.color[1], mat.color[2]) >> 5 & 63)
            .append(",").append(device565(mat.color[0], mat.color[1], mat.color[2]) & 31)
            .append(tex != null ? " CON textura" : mat.texture != 0 ? " textura=" + mat.texture + " SIN cargar"
               : mat.textureName != null ? " textura " + mat.textureName + " SIN resolver" : " SIN textura")
            .append(" modes=").append(mat.textureModes).append("/").append(mat.materialModes)
            .append(" op=").append(mat.opacity);
      }
      NativeScene.Clump o = k;
      Object data = null;
      while (o != null && (data = o.data) == null) {
         o = o.parent;
      }
      if (data instanceof NET.worlds.scape.WObject) {
         NET.worlds.scape.WObject w = (NET.worlds.scape.WObject) data;
         b.append(" obj=").append(w.getClass().getSimpleName()).append(":").append(w.getName());
      } else {
         b.append(" obj=").append(data == null ? "-" : data.getClass().getSimpleName());
      }
      return b.toString();
   }

   /** -Dfreeworlds.probePixel=X,Y: which material/object ends up owning that pixel. */
   private static final int probeX;
   private static final int probeY;
   static {
      String v = System.getProperty("freeworlds.probePixel");
      if (v == null) {
         probeX = -1;
         probeY = -1;
      } else {
         probeX = Integer.parseInt(v.split(",")[0].trim());
         probeY = Integer.parseInt(v.split(",")[1].trim());
      }
   }
   private static String probeHit;
   private static final java.util.Set<String> probeShown = new java.util.HashSet<String>();

   private static final java.util.Set<String> matStatsShown = new java.util.HashSet<String>();

   /** -Dfreeworlds.matStats=SEC: pixels drawn per material/object, once per second from SEC. */
   private static void matStats(Pass p, int scene) {
      if (p.matPixels == null) {
         return;
      }
      long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
      String key = sec + "/" + scene;
      synchronized (matStatsShown) {
         if (sec >= Long.parseLong(System.getProperty("freeworlds.matStats")) && matStatsShown.add("inv" + sec)) {
            NativeTextures.dumpInventory();
         }
         if (sec < Long.parseLong(System.getProperty("freeworlds.matStats")) || !matStatsShown.add(key)) {
            return;
         }
      }
      java.util.List<java.util.Map.Entry<String, int[]>> l =
         new ArrayList<java.util.Map.Entry<String, int[]>>(p.matPixels.entrySet());
      java.util.Collections.sort(l, new java.util.Comparator<java.util.Map.Entry<String, int[]>>() {
         public int compare(java.util.Map.Entry<String, int[]> a, java.util.Map.Entry<String, int[]> b) {
            return b.getValue()[0] - a.getValue()[0];
         }
      });
      Object sd = NativeScene.getSceneData(scene);
      String room = sd instanceof NET.worlds.scape.Room ? ((NET.worlds.scape.Room) sd).getName() : String.valueOf(scene);
      System.err.println("[RW] matStats " + sec + "s sala " + room + " (escena " + scene + "): " + l.size() + " materiales visibles");
      for (int i = 0; i < Math.min(15, l.size()); i++) {
         System.err.println("[RW]   " + l.get(i).getValue()[0] + " px  " + l.get(i).getKey());
      }
   }

   /** Ordered dither of the translucency (driver tables 0x10079240 / 0x10079280). */
   private static final int[] DITHER_X = {0x02, 0x82, 0x20, 0xA0, 0x0A, 0x8A, 0x28, 0xA8};
   private static final int[] DITHER_Y = {0x03, 0xC3, 0x30, 0xF0, 0x0F, 0xCF, 0x3C, 0xFC};

   private static int hash(int x, int y) {
      int h = x * 374761393 + y * 668265263;
      h = (h ^ h >>> 13) * 1274126177;
      return h ^ h >>> 16;
   }

   /**
    * gamma.dll FUN_00417c40: a 4x4 block in the clump-data colour (low 16
    * bits) around the projection of vertex 1, only when it lies 2 pixels
    * inside the viewport (RwGetClumpVertexViewportPosition 10032670).
    */
   public static void highlightMarker(int clump, int h) {
      Cam c = cam(h);
      NativeScene.Clump k = NativeScene.clump(clump);
      if (c == null || k == null || k.verts.isEmpty() || !(k.data instanceof Integer)) {
         return;
      }
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[] v = k.verts.get(0);
      float[] w = NativeRw.transformPoint(ltm, v[0], v[1], v[2]);
      float[] m = c.ltm;
      float dx = w[0] - m[12], dy = w[1] - m[13], dz = w[2] - m[14];
      float xc = dx * m[0] + dy * m[1] + dz * m[2];
      float yc = dx * m[4] + dy * m[5] + dz * m[6];
      float zc = dx * m[8] + dy * m[9] + dz * m[10];
      if (!(zc >= c.nearClip && zc < c.farClip)) {
         return;
      }
      float X = -0.5F / c.viewWindowX * (xc + c.viewOffsetX) + (0.5F + 0.5F * c.viewOffsetX / c.viewWindowX) * zc;
      float Y = -0.5F / c.viewWindowY * (yc - c.viewOffsetY) + (0.5F - 0.5F * c.viewOffsetY / c.viewWindowY) * zc;
      int sx = (int) Math.rint(X / zc * c.vpW * 65536.0F) >> 16;
      int sy = (int) Math.rint(Y / zc * c.vpH * 65536.0F) >> 16;
      if (sx < 0 || sx >= c.vpW || sy < 0 || sy >= c.vpH) {
         return;
      }
      if (sx - 2 < 0 || sx + 1 > c.vpW - 1 || sy - 2 < 0 || sy + 1 > c.vpH - 1) {
         return;
      }
      short col = (short) ((Integer) k.data).intValue();
      for (int yy = sy - 2; yy <= sy + 1; yy++) {
         for (int xx = sx - 2; xx <= sx + 1; xx++) {
            c.raster[yy * c.width + xx] = col;
         }
      }
   }
}

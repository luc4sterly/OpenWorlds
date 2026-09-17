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
   private static void light(NativeScene.Material m, float nx, float ny, float nz, float[][] lights, float[] out) {
      for (int ch = 0; ch < 3; ch++) {
         out[ch] = 31.0F * m.ambient;
      }
      for (float[] l : lights) {
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

   /** Lit component (driver 10019920): below 0.75 scale down, above blend to white; clamp [1, 30]. */
   private static int litComponent(int m5, float lit) {
      float x = lit / 31.0F;
      int out;
      if (x < 0.75F) {
         out = (int) Math.floor(m5 * (x / 0.75F));
      } else {
         float s = (x - 0.75F) / 0.25F;
         out = (int) Math.floor(32.0F * (m5 / 32.0F * (1.0F - s) + s));
      }
      return out < 1 ? 1 : (out > 30 ? 30 : out);
   }

   private static int lit565(int c565, float lr, float lg, float lb) {
      int r = litComponent(c565 >> 11 & 0x1F, lr);
      int g = litComponent(c565 >> 6 & 0x1F, lg) << 1;
      int b = litComponent(c565 & 0x1F, lb);
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
      drawScene(p, scene);
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
                  + p.texPixels + " px con textura, " + p.flatPixels + " px planos");
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
      for (NativeScene.Clump root : NativeScene.sceneRoots(scene)) {
         drawTree(p, root, null);
      }
   }

   private static void drawTree(Pass p, NativeScene.Clump k, float[] parentLtm) {
      float[] ltm = NativeRw.mul(NativeRw.mul(k.joint, k.modeling), parentLtm == null ? NativeRw.identity() : parentLtm);
      if (k.state != 1) {
         drawClump(p, k, ltm);
      }
      for (NativeScene.Clump child : new ArrayList<NativeScene.Clump>(k.children)) {
         drawTree(p, child, ltm);
      }
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
      float[] wv = new float[nv * 3];
      float[] cv = new float[nv * 3];
      for (int i = 0; i < nv; i++) {
         float[] v = k.verts.get(i);
         float[] w = NativeRw.transformPoint(ltm, v[0], v[1], v[2]);
         wv[i * 3] = w[0];
         wv[i * 3 + 1] = w[1];
         wv[i * 3 + 2] = w[2];
         float dx = w[0] - px, dy = w[1] - py, dz = w[2] - pz;
         float xc = dx * m[0] + dy * m[1] + dz * m[2];
         float yc = dx * m[4] + dy * m[5] + dz * m[6];
         float zc = dx * m[8] + dy * m[9] + dz * m[10];
         cv[i * 3] = -0.5F / c.viewWindowX * (xc + c.viewOffsetX) + (0.5F + 0.5F * c.viewOffsetX / c.viewWindowX) * zc;
         cv[i * 3 + 1] = -0.5F / c.viewWindowY * (yc - c.viewOffsetY) + (0.5F - 0.5F * c.viewOffsetY / c.viewWindowY) * zc;
         cv[i * 3 + 2] = zc;
      }
      // lights in the clump's local space: L = normalize(-dir . inv(LTM))
      float[] inv = new float[16];
      NativeRw.invert(ltm, inv);
      float[][] ll = new float[p.lights.length][];
      for (int i = 0; i < ll.length; i++) {
         float[] l = p.lights[i];
         float[] d = NativeRw.transformVector(inv, -l[0], -l[1], -l[2]);
         float len = (float) Math.sqrt(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]);
         if (len > 0.0F) {
            d[0] /= len;
            d[1] /= len;
            d[2] /= len;
         }
         ll[i] = new float[]{d[0], d[1], d[2], l[3], l[4], l[5]};
      }
      float[] vnorm = null;
      float[] lit = new float[3];
      for (NativeScene.Polygon poly : k.polys) {
         NativeScene.Material mat = NativeScene.material(poly.material);
         int n = poly.indices.length;
         float[] nrm = polygonNormal(k, poly);
         float[][] vs = new float[n][NA];
         boolean vertexLit = mat != null && mat.lightSampling == 2;
         if (mat != null && !vertexLit) {
            light(mat, nrm[0], nrm[1], nrm[2], ll, lit);
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
               light(mat, vnorm[vi * 3], vnorm[vi * 3 + 1], vnorm[vi * 3 + 2], ll, lit);
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
         raster(p, cl, sx, sy, mat, tex, k, vertexLit ? null : lit.clone());
      }
   }

   /** Unit polygon normal in local space; the sign is the one that faces the viewer for a front (area < 0) polygon. */
   private static float[] polygonNormal(NativeScene.Clump k, NativeScene.Polygon poly) {
      float nx = 0, ny = 0, nz = 0;
      int n = poly.indices.length;
      for (int i = 0; i < n; i++) {
         float[] a = k.verts.get(poly.indices[i] - 1);
         float[] b = k.verts.get(poly.indices[(i + 1) % n] - 1);
         nx += (a[1] - b[1]) * (a[2] + b[2]);
         ny += (a[2] - b[2]) * (a[0] + b[0]);
         nz += (a[0] - b[0]) * (a[1] + b[1]);
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

   /** ⚠️ RW vertex normals (vert+0x4c) are not extracted: average of the adjacent polygon normals. */
   private static float[] vertexNormals(NativeScene.Clump k) {
      int nv = k.verts.size();
      float[] out = new float[nv * 3];
      for (NativeScene.Polygon poly : k.polys) {
         float[] nrm = polygonNormal(k, poly);
         for (int idx : poly.indices) {
            out[(idx - 1) * 3] += nrm[0];
            out[(idx - 1) * 3 + 1] += nrm[1];
            out[(idx - 1) * 3 + 2] += nrm[2];
         }
      }
      for (int i = 0; i < nv; i++) {
         float x = out[i * 3], y = out[i * 3 + 1], z = out[i * 3 + 2];
         float len = (float) Math.sqrt(x * x + y * y + z * z);
         if (len > 0.0F) {
            out[i * 3] = x / len;
            out[i * 3 + 1] = y / len;
            out[i * 3 + 2] = z / len;
         }
      }
      return out;
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
    * Scanline fill of a convex polygon with perspective-correct u, v (texture
    * mode 0x2 FORESHORTEN), lighting and world position, texel 0
    * transparent, 128x128 wrap, translucency as a screen-door test against
    * the opacity byte.
    * ⚠️ fill rule, Gouraud interpolation space and the dither pattern are not extracted.
    */
   private static void raster(Pass p, float[][] cl, float[] sx, float[] sy, NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k, float[] facetLit) {
      Cam c = p.c;
      int n = cl.length;
      float minY = Float.MAX_VALUE, maxY = -Float.MAX_VALUE;
      for (int i = 0; i < n; i++) {
         minY = Math.min(minY, sy[i]);
         maxY = Math.max(maxY, sy[i]);
      }
      int y0 = Math.max(Math.max(0, c.renderOffY), (int) Math.ceil(minY - 0.5F));
      int y1 = Math.min(Math.min(c.height, c.renderOffY + c.vpH) - 1, (int) Math.ceil(maxY - 0.5F) - 1);
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
      // per vertex: 1/Z and attribute/Z for u, v, lr, lg, lb, wx, wy, wz
      float[][] pv = new float[n][9];
      for (int i = 0; i < n; i++) {
         float iz = 1.0F / cl[i][2];
         pv[i][0] = iz;
         for (int a = 0; a < 8; a++) {
            pv[i][1 + a] = cl[i][3 + a] * iz;
         }
      }
      float[] l = new float[9];
      float[] r = new float[9];
      float[] cur = new float[9];
      for (int y = y0; y <= y1; y++) {
         float yc = y + 0.5F;
         float lx = Float.MAX_VALUE, rx = -Float.MAX_VALUE;
         for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            float ya = sy[i], yb = sy[j];
            if (ya == yb || yc < Math.min(ya, yb) || yc >= Math.max(ya, yb)) {
               continue;
            }
            float t = (yc - ya) / (yb - ya);
            float x = sx[i] + (sx[j] - sx[i]) * t;
            if (x < lx) {
               lx = x;
               for (int a = 0; a < 9; a++) {
                  l[a] = pv[i][a] + (pv[j][a] - pv[i][a]) * t;
               }
            }
            if (x > rx) {
               rx = x;
               for (int a = 0; a < 9; a++) {
                  r[a] = pv[i][a] + (pv[j][a] - pv[i][a]) * t;
               }
            }
         }
         if (lx > rx) {
            continue;
         }
         int xs = Math.max(xMin, (int) Math.ceil(lx - 0.5F));
         int xe = Math.min(xMax, (int) Math.ceil(rx - 0.5F) - 1);
         if (p.pick) {
            if (p.pickX < xs || p.pickX > xe) {
               continue;
            }
            xs = xe = p.pickX;
         }
         float span = rx - lx;
         int row = y * c.width;
         for (int x = xs; x <= xe; x++) {
            float t = span <= 0.0F ? 0.0F : (x + 0.5F - lx) / span;
            for (int a = 0; a < 9; a++) {
               cur[a] = l[a] + (r[a] - l[a]) * t;
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
            if (opacity != 255 && (hash(x, y) & 0xFF) >= opacity) {
               continue;
            }
            int pix;
            float lr, lg, lb;
            if (facetLit != null) {
               // light sampling 1: one value per polygon (poly+4/8/0xC), not interpolated
               lr = facetLit[0];
               lg = facetLit[1];
               lb = facetLit[2];
            } else {
               lr = cur[3] * zz;
               lg = cur[4] * zz;
               lb = cur[5] * zz;
            }
            if (tex != null) {
               int tu = (int) Math.floor(cur[1] * zz * NativeTextures.SIZE) & 0x7F;
               int tv = (int) Math.floor(cur[2] * zz * NativeTextures.SIZE) & 0x7F;
               int texel = tex.pixels[tv * NativeTextures.SIZE + tu] & 0xFFFF;
               if (texel == 0) {
                  continue;
               }
               pix = litTex ? lit565(texel, lr, lg, lb) : texel;
            } else {
               pix = lit565(base, lr, lg, lb);
            }
            p.z[zi] = iz;
            c.raster[zi] = (short) pix;
            if (tex != null) {
               p.texPixels++;
            } else {
               p.flatPixels++;
            }
            if (x == c.renderOffX + c.vpW / 2 && y == c.renderOffY + c.vpH / 2 && mat != null) {
               p.centre = "color " + mat.color[0] + "," + mat.color[1] + "," + mat.color[2]
                  + " tex=" + (tex != null ? mat.textureName : "NINGUNA(" + mat.textureName + ")")
                  + " amb=" + mat.ambient + " dif=" + mat.diffuse + " z=" + (1.0F / iz)
                  + " clump=" + k.verts.size() + "v/" + k.polys.size() + "p";
            }
         }
      }
   }

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

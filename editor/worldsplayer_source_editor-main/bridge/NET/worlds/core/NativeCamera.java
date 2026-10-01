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

      /** What show() blits: the raster converted to 0xRRGGBB (see SCREEN_RGB). */
      BufferedImage screen;
      int[] screenPixels;

      Cam(int w, int h) {
         this.width = w;
         this.height = h;
         this.image = new BufferedImage(w, h, BufferedImage.TYPE_USHORT_565_RGB);
         this.raster = ((DataBufferUShort) this.image.getRaster().getDataBuffer()).getData();
         this.vpW = w;
         this.vpH = h;
      }

      /** The raster as 0xRRGGBB, for drawing to the screen. */
      BufferedImage screenImage() {
         if (this.screen == null) {
            this.screen = new BufferedImage(this.width, this.height, BufferedImage.TYPE_INT_RGB);
            this.screenPixels = ((java.awt.image.DataBufferInt) this.screen.getRaster().getDataBuffer()).getData();
         }
         short[] src = this.raster;
         int[] dst = this.screenPixels;
         int[] lut = SCREEN_RGB;
         for (int i = 0; i < src.length; i++) {
            dst[i] = lut[src[i] & 0xFFFF];
         }
         return this.screen;
      }
   }

   /**
    * 5-6-5 to 0xRRGGBB exactly as Java2D converts a TYPE_USHORT_565_RGB
    * image when it draws one (its ColorModel.getRGB): drawing the 565 image
    * directly went through the generic per-pixel blit loop
    * (MaskBlit$General on X11), the slowest part of a frame in a big
    * window. Same colours on screen, one table lookup per pixel.
    */
   private static final int[] SCREEN_RGB = screenTable();

   private static int[] screenTable() {
      java.awt.image.ColorModel cm = new BufferedImage(1, 1, BufferedImage.TYPE_USHORT_565_RGB).getColorModel();
      int[] t = new int[65536];
      for (int i = 0; i < t.length; i++) {
         t[i] = cm.getRGB(i) & 0xFFFFFF;
      }
      return t;
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
            System.err.println("[RW] the camera " + c.width + "x" + c.height + " has no window to blit the image into");
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
            System.err.println("[RW] no BufferStrategy on " + c.width + "x" + c.height + ": painting with getGraphics()");
         }
         if (bs != null) {
            BufferedImage img = c.screenImage();
            do {
               do {
                  Graphics bg = bs.getDrawGraphics();
                  try {
                     bg.drawImage(img, 0, 0, null);
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
            g.drawImage(c.screenImage(), 0, 0, null);
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
      System.err.println("[RW] camera " + key + " -> " + comp.getClass().getName()
         + " canvas=" + (comp instanceof java.awt.Canvas) + owner);
   }

   /** -Dopenworlds.fps: frames shown per second on the main camera. */
   private static long fpsMark;
   private static int fpsCount;
   private static long framePaint;
   private static long frameTexPaint;

   /** Pixels written by the rasterizers since the last frame was shown. */
   static long framePixels;
   static long frameTexPixels;

   private static void fps(Cam c) {
      if (System.getProperty("openworlds.fps") == null || c.width != mainWidth) {
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
         System.err.println("[RW] coverage: " + framePaint / fpsCount + " px written per frame of "
            + c.width * c.height + " (" + 100 * framePaint / fpsCount / (c.width * c.height) + " %), "
            + (framePaint == 0 ? 0 : 100 * frameTexPaint / framePaint) + " % textured");
         framePaint = 0L;
         frameTexPaint = 0L;
         System.err.println("[RW] fps " + (System.nanoTime() - DUMP_T0) / 1000000000L + "s: "
            + (fpsCount * 1000000000L / (now - fpsMark)) + " (camera " + c.width + "x" + c.height
            + " at " + (int) c.ltm[12] + "," + (int) c.ltm[13] + "," + (int) c.ltm[14]
            + " facing " + Math.round(c.ltm[8] * 100) / 100.0F + "," + Math.round(c.ltm[9] * 100) / 100.0F
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
    * Harness diagnostic: -Dopenworlds.dumpFrames=DIR saves frames 1, 10, 100, 1000... of each
    * camera as PNG, or with -Dopenworlds.dumpSeconds=S1,S2,... the first frame after each second mark.
    */
   private static void dumpFrame(Cam c) {
      String dir = System.getProperty("openworlds.dumpFrames");
      if (dir == null) {
         return;
      }
      String key = c.width + "x" + c.height;
      Integer prev = shownBySize.get(key);
      int shown = prev == null ? 1 : prev + 1;
      shownBySize.put(key, shown);
      String range = System.getProperty("openworlds.dumpRange");
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
      String secs = System.getProperty("openworlds.dumpSeconds");
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
    * ⚠️ VERIFY: RWL21's exact reconstruction is not extracted yet.
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
    * ⚠️ VERIFY, as with setLookAt.
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

   /**
    * WObject.nativeInCamSpace (gamma.dll 0x00413910): null when there is
    * no camera or clump or when RwGetClumpState is not 2 (0x00419570);
    * otherwise RwGetClumpOrigin (RWL21 0x10005930, the LTM translation)
    * through RwInvertMatrix of RwGetCameraLTM (0x004191d0 -> 0x00419860)
    * with RwTransformPoint (0x0041a080).
    */
   public static float[] inCamSpace(int camH, int clump) {
      Cam c = cam(camH);
      if (c == null || NativeScene.clump(clump) == null || NativeScene.getClumpState(clump) != 2) {
         return null;
      }
      float[] ltm = new float[16];
      NativeScene.getClumpLTM(clump, ltm);
      float[] inv = new float[16];
      NativeRw.invert(c.ltm, inv);
      float[] p = NativeRw.transformPoint(inv, ltm[12], ltm[13], ltm[14]);
      Object d = NativeScene.getClumpData(clump);
      if (System.getProperty("openworlds.traceInCamSpace") != null && inCamTraced.add(d)) {
         System.err.println("[RW] inCamSpace " + (d == null ? "-" : d.getClass().getSimpleName() + ":" + d)
            + " -> (" + p[0] + "," + p[1] + "," + p[2] + ")");
      }
      return p;
   }

   /** -Dopenworlds.traceInCamSpace: first point got by each object. */
   private static final java.util.Set<Object> inCamTraced = java.util.Collections.synchronizedSet(new java.util.HashSet<Object>());

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
      if (System.getProperty("openworlds.matStats") != null && c.width == mainWidth) {
         p.matPixels = new java.util.HashMap<String, int[]>();
      }
      probeHit = null;
      TRIS.clear();
      drawScene(p, scene);
      rasterize(p);
      matStats(p, scene);
      dumpScene(scene, c);
      if (probeHit != null) {
         long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
         synchronized (probeShown) {
            if (probeShown.add(sec + "/" + scene)) {
               System.err.println("[RW] probe " + sec + "s scene " + scene + " (" + probeX + "," + probeY + "): " + probeHit);
            }
         }
      }
      if (System.getProperty("openworlds.centrePixel") != null && p.centre != null
            && c.width == mainWidth && (System.nanoTime() - DUMP_T0) / 1000000000L >= 25
            && centreShown++ % 300 == 0) {
         System.err.println("[RW] centre of the view: " + p.centre);
      }
      if (System.getProperty("openworlds.countPolys") != null && c.width == mainWidth) {
         long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
         String key = sec + "s scene " + scene + " z=" + zFlag;
         synchronized (counted) {
            if (sec >= Long.parseLong(System.getProperty("openworlds.countPolys")) && counted.add(key)) {
               System.err.println("[RW] pass " + key + ": " + p.clumps + " clumps, " + p.polys + " polygons, " + p.drawn + " drawn, "
                  + p.texPixels + " px textured, " + p.flatPixels + " px flat, "
                  + degenerateVertexNormals + " degenerate vertex normals (fell back to the first face)");
            }
         }
      }
   }

   /** -Dopenworlds.dumpScene=SEC: the clump tree of every scene drawn by the main camera, once, from SEC seconds. */
   private static final String DUMP_SCENE = System.getProperty("openworlds.dumpScene");
   private static final java.util.Set<Integer> scenesDumped = new java.util.HashSet<Integer>();

   private static void dumpScene(int scene, Cam c) {
      if (DUMP_SCENE == null || c.width != mainWidth
            || (System.nanoTime() - DUMP_T0) / 1000000000L < Long.parseLong(DUMP_SCENE)) {
         return;
      }
      synchronized (scenesDumped) {
         if (!scenesDumped.add(Integer.valueOf(scene))) {
            return;
         }
      }
      Object owner = NativeScene.getSceneData(scene);
      StringBuilder b = new StringBuilder("[RW] scene " + scene + " (" + describeData(owner) + "):\n");
      java.util.List<NativeScene.Clump> roots = NativeScene.sceneRoots(scene);
      for (int i = 0; i < roots.size(); i++) {
         dumpTree(b, roots.get(i), null, 1);
      }
      System.err.print(b);
   }

   private static void dumpTree(StringBuilder b, NativeScene.Clump k, float[] parentLtm, int depth) {
      float[] ltm = new float[16];
      NativeRw.mulInto(k.joint, k.modeling, ltm);
      if (parentLtm != null) {
         float[] tmp = ltm.clone();
         NativeRw.mulInto(tmp, parentLtm, ltm);
      }
      for (int i = 0; i < depth; i++) {
         b.append("  ");
      }
      b.append(describeData(k.data)).append(" state=").append(k.state)
         .append(" vert=").append(k.verts.size()).append(" pol=").append(k.polys.size())
         .append(String.format(" at (%.0f,%.0f,%.0f)", ltm[12], ltm[13], ltm[14]));
      if (System.getProperty("openworlds.dumpSceneMatrices") != null) {
         b.append(" modeling=").append(java.util.Arrays.toString(k.modeling)).append(" joint=").append(java.util.Arrays.toString(k.joint));
      }
      b.append('\n');
      for (NativeScene.Clump child : k.children) {
         dumpTree(b, child, ltm, depth + 1);
      }
   }

   private static String describeData(Object o) {
      if (o == null) {
         return "-";
      }
      String cls = o.getClass().getName();
      cls = cls.substring(cls.lastIndexOf('.') + 1);
      return o instanceof NET.worlds.scape.SuperRoot ? cls + ":" + ((NET.worlds.scape.SuperRoot) o).getName() : cls;
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
      // Hint mode 1 draws in the order of the clump's sort tree
      // (0x10032b50 -> 0x10033ed0); modes 0 and 2 in clump order.
      SortTree tree = NativeScene.hsMode(k.hints) == 1 ? k.sortTree : null;
      for (int oi = 0; oi < k.polys.size(); oi++) {
         int pi = tree == null ? oi : tree.index[oi];
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
         int m2 = clip(vs, n, c);
         float[][] cl = clipResult;
         if (m2 < 3) {
            continue;
         }
         p.drawn++;
         if (sxBuf.length < m2) {
            sxBuf = new float[m2 * 2];
            syBuf = new float[m2 * 2];
         }
         float[] sx = sxBuf, sy = syBuf;
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
         if (!p.pick) {
            // The driver's own triangles (see Raster.rasterTri): the fan is walked
            // from its LAST triangle back to the first, (v0, v[i], v[i+1])
            // for a front polygon and (v0, v[i+1], v[i]) for the back of a
            // double-sided one (the 0x10000 flag the caller passes). They
            // are recorded in that order and drawn by rasterize().
            for (int t = m2 - 2; t >= 1; t--) {
               if (front) {
                  TRIS.add(cl[0], cl[t], cl[t + 1], mat, tex, k, facet, c);
               } else {
                  TRIS.add(cl[0], cl[t + 1], cl[t], mat, tex, k, facet, c);
               }
            }
            continue;
         }
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

   // ------------------------------------------------------------------
   // Triangle setup and spans of the 16-bit driver (RWDL6D21)

   /**
    * Reciprocal table DAT_10079214 (0x2080 bytes), built in the driver's
    * open (0x1000a008..0x1000a03e): for dx = -32..32 and dy = 1..31,
    * entry [(dx + 32) * 32 + dy] = (dx << 16) / dy with idiv (truncation
    * toward zero); entry dy = 0 of each row is never written.
    */
   static final int[] RECIP = buildRecip();

   private static int[] buildRecip() {
      int[] t = new int[65 * 32];
      for (int row = 0, num = -0x200000; num <= 0x200000; num += 0x10000, row += 32) {
         for (int dy = 1; dy < 32; dy++) {
            t[row + dy] = num / dy;
         }
      }
      return t;
   }

   /**
    * Edge slope in 16.16 as every triangle setup computes it (0x100259e0,
    * 0x10019fa0, 0x1002d200...): dy = 1 -> dx << 16, dy = 2 -> dx * 0x8000,
    * |dx| < 32 and dy < 32 -> the reciprocal table (base + 0x1000 = row
    * dx = 0), otherwise (dx << 16) / dy with idiv.
    */
   public static int slope(int dx, int dy) {
      if (dy == 1) {
         return dx * 0x10000;
      }
      if (dy == 2) {
         return dx * 0x8000;
      }
      if (dy < 32 && -32 < dx && dx < 32) {
         return RECIP[(dx + 32) * 32 + dy];
      }
      return dx * 0x10000 / dy;
   }

   /** 512.0f (_DAT_10078100) and 1/512 (_DAT_100780f8) of the textured setups. */
   private static final float UV_SCALE = 0.001953125F;

   /**
    * Screen position in 16.16 of a clipped vertex, as the driver's vertex
    * transform (0x10069650, perspective branch, FPU set to 24-bit
    * precision) stores it: round-to-nearest of X * (1/Z) * (vpW * 65536),
    * relative to the viewport.
    */
   static int screen16(float x, float z, int size) {
      float f = 1.0F / z;
      float s = (float) (int) (size * 65536.0);
      return (int) Math.rint(x * f * s);
   }

   /** One vertex of the driver triangle: screen 16.16, camera Z, UV fixed, lighting, 1/Z and world position. */
   private static final class DVert {
      int x16;
      int y16;
      float z;
      int u;
      int v;
      float[] a;
   }

   /** Edge state of one side of the triangle, stepped once per scanline. */
   private static final class Edge {
      int x;
      int dx;
      /** perspective terms q, u*q, v*q (floats, 0x1007f440.. / 0x1007f458..) */
      float q;
      float dq;
      float uq;
      float duq;
      float vq;
      float dvq;
      /** 1/Z and lighting r, g, b, linear per scanline (bridge approximation of the depth / colour setup) */
      final float[] at = new float[4];
      final float[] dat = new float[4];

      void set(DVert s, float qs, float uqs, float vqs, DVert e, float qe, float uqe, float vqe, int dy, int xs16, int slope) {
         this.x = xs16;
         this.dx = slope;
         float inv = 1.0F / (float) dy;
         this.q = qs;
         this.uq = uqs;
         this.vq = vqs;
         this.dq = (qe - qs) * inv;
         this.duq = (uqe - uqs) * inv;
         this.dvq = (vqe - vqs) * inv;
         for (int i = 0; i < 4; i++) {
            float a = i == 0 ? 1.0F / s.z : s.a[4 + i];
            float b = i == 0 ? 1.0F / e.z : e.a[4 + i];
            this.at[i] = a;
            this.dat[i] = (b - a) * inv;
         }
      }

      void step() {
         this.x += this.dx;
         this.q = this.q + this.dq;
         this.uq = this.uq + this.duq;
         this.vq = this.vq + this.dvq;
         for (int i = 0; i < 4; i++) {
            this.at[i] += this.dat[i];
         }
      }
   }


   /** Dither words 0x10079240 (x) and 0x10079280 (y): each is the previous one xor (itself >>> 6). */
   public static final int[] DITHER_COLS = {0x08022002, 0x08222882, 0x0802a020, 0x0822aaa0, 0x0802200a, 0x0822288a, 0x0802a028, 0x0822aaa8,
      0x08022002, 0x08222882, 0x0802a020, 0x0822aaa0, 0x0802200a, 0x0822288a, 0x0802a028, 0x0822aaa8};
   static final int[] DITHER_ROWS = {0x0c033003, 0x0c333cc3, 0x0c03f030, 0x0c33fff0, 0x0c03300f, 0x0c333ccf, 0x0c03f03c, 0x0c33fffc,
      0x0c033003, 0x0c333cc3, 0x0c03f030, 0x0c33fff0, 0x0c03300f, 0x0c333ccf, 0x0c03f03c, 0x0c33fffc};

   private static int clampRamp(float f) {
      int i = (int) f;
      return i < 0 ? 0 : i > 31 ? 31 : i;
   }

   /** (g | r << 16) << 8 (0x100259e0). */
   public static int packRG(int r, int g) {
      return (g | r << 16) << 8;
   }

   /** Two 8.8 steps in one word, the low one sign-corrected: (hi << 16 | lo & 0xffff) + (lo & 0x8000) * -2. */
   public static int pack(int hi, int lo) {
      return (hi << 16 | lo & 0xFFFF) + (lo & 0x8000) * -2;
   }

   /**
    * Step of a colour over n rows or pixels as the setups divide it:
    * diff (in 8.8, i.e. components * 256) when n is 1, diff >> 1 when n
    * is 2, idiv otherwise.
    */
   static int div(int diff5, int n) {
      int diff = diff5 * 0x100;
      if (diff == 0 || n == 1) {
         return diff;
      }
      if (n == 2) {
         return diff >> 1;
      }
      return diff / n;
   }

   /**
    * One Gouraud pixel of 0x1006a340: R and B take the integer part of
    * their accumulators; G adds its fraction to the dither byte and the
    * carry goes into G (it can overflow into R's low bit, as the add is
    * done on the byte that holds R << 5 and G). Returns the 5-6-5 value.
    */
   public static int gouraudPixel(int accRG, int accB, int thr) {
      int r = accRG >>> 24;
      int gInt = accRG >>> 8 & 0xFF;
      int gFrac = accRG & 0xFF;
      int carry = gFrac + (thr & 0xFF) > 0xFF ? 1 : 0;
      int e = r << 5;
      e = (e & ~0xFF) | ((e & 0xFF) + gInt + carry & 0xFF);
      e <<= 6;
      e |= accB >>> 8 & 0xFF;
      return e & 0xFFFF;
   }

   /**
    * Texture coordinates of one span as 0x1002cbb0 packs them: v in bits
    * 0..13 (texel = bits 7..13) and u in bits 16..31 (texel = bits
    * 25..31), both from 16.16 values with 9 fractional bits per texel.
    * cnt <= 16: linear between the perspective-correct ends, step =
    * (end - start) * (float)(1/cnt) truncated. cnt > 16: q, uq, vq advance
    * by 16 * (1/cnt) of the span per block; at each block end u, v are
    * divided again (512/q) and the 16 pixels step by
    * ((dv & 0xfffc0) >> 6) | ((du & ~15) << 12); the tail divides by the
    * right edge and steps by (start - end) / -n (idiv). Returns the packed
    * value for each pixel in out[0..cnt-1].
    */
   public static int[] texSpan(float qa, float uqa, float vqa, float qb, float uqb, float vqb, int cnt, int[] out) {
      if (out == null || out.length < cnt) {
         out = new int[Math.max(cnt, 16)];
      }
      float invf = (float) (1.0 / cnt);
      if (cnt <= 16) {
         double aa = 512.0 / qa;
         double bb = 512.0 / qb;
         double ul = uqa * aa, vl = vqa * aa;
         int pk = (ftol(vl) & 0x3fffc) >>> 2 | ftol(ul) << 16;
         int dvv = ftol((vqb * bb - vl) * invf);
         int duu = ftol((uqb * bb - ul) * invf);
         int step = (dvv & 0x3fffc) >>> 2 | duu << 16;
         for (int i = 0; i < cnt; i++) {
            out[i] = pk;
            pk += step;
         }
         return out;
      }
      double f16 = (double) invf * 16.0;
      float dU16 = (float) ((uqb - uqa) * f16);
      float dV16 = (float) ((vqb - vqa) * f16);
      float dQ16 = (float) (f16 * (qb - qa));
      double aa = 512.0 / qa;
      int u0 = ftol(uqa * aa);
      int v0 = ftol(aa * vqa);
      float uq = uqa, vq = vqa, q = qa;
      int blocks = cnt >> 4;
      int o = 0;
      for (int bl = 0; bl < blocks; bl++) {
         uq = (float) ((double) uq + dU16);
         vq = (float) ((double) vq + dV16);
         q = (float) ((double) dQ16 + q);
         double r = 512.0 / q;
         int u1 = ftol(uq * r);
         int v1 = ftol(r * vq);
         int step = ((v1 - v0) & 0xfffc0) >>> 6 | ((u1 - u0) & ~0xf) << 12;
         int pk = (v0 & 0xfffc) >>> 2 | u0 << 16;
         for (int i = 0; i < 16; i++) {
            out[o++] = pk;
            pk += step;
         }
         u0 = u1;
         v0 = v1;
      }
      int n = o - cnt;
      if (n < 0) {
         double r = 512.0 / qb;
         int pk = (v0 & 0xfffc) >>> 2 | u0 << 16;
         int dvv = (v0 - ftol(vqb * r)) / n;
         int duu = (u0 - ftol(r * uqb)) / n;
         int step = (dvv & 0xfffc) >>> 2 | duu << 16;
         while (o < cnt) {
            out[o++] = pk;
            pk += step;
         }
      }
      return out;
   }

   /** __ftol (RWDL6D21 0x1005ff48): truncation to 64 bits, low 32 kept. */
   static int ftol(double d) {
      return (int) (long) d;
   }

   /** Texel of a packed span value (0x1002cd8b..0x1002cda1). */
   public static int texelIndex(int pk) {
      return ((pk >>> 7) & 0x7F) * NativeTextures.SIZE + (pk >>> 25);
   }

   // ------------------------------------------------------------------
   // Deferred triangles, drawn in horizontal bands

   /**
    * The triangles of the current pass, in the order the clump pass hands
    * them to the driver (drawClump), with their clipped vertices copied:
    * the clip buffers are reused by the next polygon.
    */
   private static final TriList TRIS = new TriList();

   private static final class TriList {
      int n;
      float[][] v = new float[3 * 256][];
      NativeScene.Material[] mat = new NativeScene.Material[256];
      NativeTextures.Texture[] tex = new NativeTextures.Texture[256];
      NativeScene.Clump[] clump = new NativeScene.Clump[256];
      boolean[] facetLit = new boolean[256];
      float[] facet = new float[3 * 256];
      /** Rows the triangle can write, [rowLo, rowHi), from its 16.16 screen y (see Raster.rasterTri). */
      int[] rowLo = new int[256];
      int[] rowHi = new int[256];

      void add(float[] a, float[] b, float[] d, NativeScene.Material m, NativeTextures.Texture t, NativeScene.Clump k, float[] f, Cam c) {
         if (n == mat.length) {
            int cap = n * 2;
            v = java.util.Arrays.copyOf(v, cap * 3);
            mat = java.util.Arrays.copyOf(mat, cap);
            tex = java.util.Arrays.copyOf(tex, cap);
            clump = java.util.Arrays.copyOf(clump, cap);
            facetLit = java.util.Arrays.copyOf(facetLit, cap);
            facet = java.util.Arrays.copyOf(facet, cap * 3);
            rowLo = java.util.Arrays.copyOf(rowLo, cap);
            rowHi = java.util.Arrays.copyOf(rowHi, cap);
         }
         copy(3 * n, a);
         copy(3 * n + 1, b);
         copy(3 * n + 2, d);
         mat[n] = m;
         tex[n] = t;
         clump[n] = k;
         facetLit[n] = f != null;
         if (f != null) {
            facet[3 * n] = f[0];
            facet[3 * n + 1] = f[1];
            facet[3 * n + 2] = f[2];
         }
         // the setup starts at the vertex with the smallest 16.16 y and fills
         // rows (yTop >> 16) .. (yBottom >> 16) - 1, plus the render offset
         int ya = screen16(a[1], a[2], c.vpH), yb = screen16(b[1], b[2], c.vpH), yd = screen16(d[1], d[2], c.vpH);
         int oy = c.renderOffY + c.vpY;
         rowLo[n] = (Math.min(ya, Math.min(yb, yd)) >> 16) + oy;
         rowHi[n] = (Math.max(ya, Math.max(yb, yd)) >> 16) + oy;
         n++;
      }

      private void copy(int slot, float[] src) {
         float[] dst = v[slot];
         if (dst == null) {
            dst = new float[NA];
            v[slot] = dst;
         }
         System.arraycopy(src, 0, dst, 0, NA);
      }

      void clear() {
         java.util.Arrays.fill(mat, 0, n, null);
         java.util.Arrays.fill(tex, 0, n, null);
         java.util.Arrays.fill(clump, 0, n, null);
         n = 0;
      }
   }

   /**
    * -Dopenworlds.rasterThreads=N: threads that draw the bands of a pass
    * (default: the processors, at most 8; 1 = everything on the render
    * thread, as before).
    */
   static final int RASTER_THREADS = rasterThreads();

   /** Below this many viewport pixels a pass is drawn on the render thread alone. */
   private static final int PARALLEL_MIN_PIXELS = 40000;

   private static int rasterThreads() {
      int n = Math.min(8, Runtime.getRuntime().availableProcessors());
      String v = System.getProperty("openworlds.rasterThreads");
      if (v != null) {
         try {
            n = Integer.parseInt(v.trim());
         } catch (NumberFormatException e) {
            System.err.println("[RW] openworlds.rasterThreads is not a number: " + v);
         }
      }
      return Math.max(1, Math.min(64, n));
   }

   private static final Raster[] RASTERS = new Raster[RASTER_THREADS];
   private static java.util.concurrent.ExecutorService pool;

   private static synchronized java.util.concurrent.ExecutorService pool() {
      if (pool == null) {
         final java.util.concurrent.atomic.AtomicInteger id = new java.util.concurrent.atomic.AtomicInteger();
         pool = java.util.concurrent.Executors.newFixedThreadPool(RASTER_THREADS - 1, new java.util.concurrent.ThreadFactory() {
            public Thread newThread(Runnable r) {
               Thread t = new Thread(r, "openworlds-raster-" + id.incrementAndGet());
               t.setDaemon(true);
               return t;
            }
         });
      }
      return pool;
   }

   private static Raster raster(int i) {
      Raster r = RASTERS[i];
      if (r == null) {
         r = new Raster();
         RASTERS[i] = r;
      }
      return r;
   }

   /**
    * Draws the recorded triangles. The viewport rows are split into bands
    * that the render thread and the raster threads take one at a time;
    * each band walks the WHOLE list in order and a triangle only writes its
    * own rows, so every pixel receives the same writes in the same order as
    * drawing the list once from top to bottom: the frame is identical
    * (bridge/test/RasterGoldenCheck). A triangle's rows above the band are
    * still stepped (edges, Gouraud accumulators, dither word), exactly as
    * rows above the viewport were; below the band nothing is left to write.
    */
   private static void rasterize(final Pass p) {
      final TriList tl = TRIS;
      if (tl.n == 0) {
         return;
      }
      Cam c = p.c;
      final int y0 = Math.max(0, c.renderOffY);
      int y1 = Math.min(c.height, c.renderOffY + c.vpH);
      int rows = y1 - y0;
      int threads = RASTER_THREADS;
      if ((long) c.vpW * rows < PARALLEL_MIN_PIXELS || rows < 2 * threads) {
         threads = 1;
      }
      try {
         if (threads == 1) {
            Raster r = raster(0);
            r.reset(p);
            r.band(p, tl, y0, y1);
            r.merge(p);
            return;
         }
         final int bands = Math.min(rows, threads * 4);
         final int perBand = (rows + bands - 1) / bands;
         final int yEnd = y1;
         final java.util.concurrent.atomic.AtomicInteger next = new java.util.concurrent.atomic.AtomicInteger();
         final java.util.concurrent.CountDownLatch done = new java.util.concurrent.CountDownLatch(threads - 1);
         final Throwable[] failure = new Throwable[1];
         for (int t = 0; t < threads; t++) {
            raster(t).reset(p);
         }
         for (int t = 1; t < threads; t++) {
            final Raster r = raster(t);
            pool().execute(new Runnable() {
               public void run() {
                  try {
                     drawBands(p, tl, r, next, bands, perBand, y0, yEnd);
                  } catch (Throwable e) {
                     synchronized (failure) {
                        failure[0] = e;
                     }
                  } finally {
                     done.countDown();
                  }
               }
            });
         }
         drawBands(p, tl, raster(0), next, bands, perBand, y0, yEnd);
         try {
            done.await();
         } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
         }
         synchronized (failure) {
            if (failure[0] instanceof RuntimeException) {
               throw (RuntimeException) failure[0];
            }
            if (failure[0] instanceof Error) {
               throw (Error) failure[0];
            }
         }
         for (int t = 0; t < threads; t++) {
            raster(t).merge(p);
         }
      } finally {
         tl.clear();
      }
   }

   private static void drawBands(Pass p, TriList tl, Raster r, java.util.concurrent.atomic.AtomicInteger next, int bands, int perBand, int y0, int y1) {
      for (int b = next.getAndIncrement(); b < bands; b = next.getAndIncrement()) {
         int lo = y0 + b * perBand;
         int hi = Math.min(y1, lo + perBand);
         if (lo < hi) {
            r.band(p, tl, lo, hi);
         }
      }
   }

   /**
    * One raster thread's copy of the driver's per-triangle state (the
    * RWDL6D21 globals: vertices, edges 0x1007f440.., Gouraud 0x1007f2c0..,
    * span buffer) plus its counters, drawing the rows [bandMin, bandMax).
    */
   private static final class Raster {
      private final DVert[] dv = {new DVert(), new DVert(), new DVert()};
      private final Edge edgeA = new Edge();
      private final Edge edgeB = new Edge();
      private int[] spanUV = new int[64];
      private final float[] facetBuf = new float[3];
      private final int[] colT = new int[3];
      private final int[] col3 = new int[3];
      private final int[] col4 = new int[3];

      // Gouraud state of 0x100259e0 / span 0x1006a340: R and G of the left
      // edge packed in one 32-bit word (R 8.8 in bits 16..31, G 8.8 in bits
      // 0..15, carries included: 0x1007f2c0), its per-line step (0x1007f2c4)
      // and per-pixel gradient (0x1007f2c8); B 8.8 apart (0x1007f2cc /
      // 0x1007f2d0 / 0x1007f2d4); the row dither word (0x1007f2a4).
      private boolean gouraud;
      private int gAcc;
      private int gStep;
      private int gGrad;
      private int bAcc;
      private int bStep;
      private int bGrad;
      private int rowDither;

      private int bandMin;
      private int bandMax;
      private long pixels;
      private long texPixels;
      private int texPx;
      private int flatPx;
      private String probe;
      private java.util.Map<String, int[]> matPx;

      void reset(Pass p) {
         pixels = 0L;
         texPixels = 0L;
         texPx = 0;
         flatPx = 0;
         probe = null;
         matPx = p.matPixels == null ? null : new java.util.HashMap<String, int[]>();
      }

      /** Counters of this thread into the pass and the frame totals. */
      void merge(Pass p) {
         framePixels += pixels;
         frameTexPixels += texPixels;
         p.texPixels += texPx;
         p.flatPixels += flatPx;
         if (probe != null) {
            probeHit = probe;
         }
         if (matPx != null) {
            for (java.util.Map.Entry<String, int[]> e : matPx.entrySet()) {
               int[] n2 = p.matPixels.get(e.getKey());
               if (n2 == null) {
                  p.matPixels.put(e.getKey(), e.getValue());
               } else {
                  n2[0] += e.getValue()[0];
               }
            }
         }
      }

      void band(Pass p, TriList tl, int lo, int hi) {
         bandMin = lo;
         bandMax = hi;
         for (int i = 0; i < tl.n; i++) {
            if (tl.rowHi[i] <= lo || tl.rowLo[i] >= hi) {
               continue;
            }
            float[] facetLit = null;
            if (tl.facetLit[i]) {
               facetLit = facetBuf;
               facetLit[0] = tl.facet[3 * i];
               facetLit[1] = tl.facet[3 * i + 1];
               facetLit[2] = tl.facet[3 * i + 2];
            }
            rasterTri(p, tl.v[3 * i], tl.v[3 * i + 1], tl.v[3 * i + 2], tl.mat[i], tl.tex[i], tl.clump[i], facetLit);
         }
      }

      private DVert dvert(int i, float[] c, Cam cam) {
         DVert d = dv[i];
         d.x16 = screen16(c[0], c[2], cam.vpW);
         d.y16 = screen16(c[1], c[2], cam.vpH);
         d.z = c[2];
         d.u = NativeScene.uvFixed(c[3]);
         d.v = NativeScene.uvFixed(c[4]);
         d.a = c;
         return d;
      }

      /** Ramp outputs (5 bits) of a vertex for the material colour: R, G (top 5 of 6), B (0x100259e0 head). */
      private int[] vertexColour(DVert d, int c565, int[] out) {
         int ir = clampRamp(d.a[5]), ig = clampRamp(d.a[6]), ib = clampRamp(d.a[7]);
         out[0] = RAMP[ir * 32 + (c565 >> 11 & 0x1F)];
         out[1] = RAMP[ig * 32 + (c565 >> 6 & 0x1F)];
         out[2] = RAMP[ib * 32 + (c565 & 0x1F)];
         return out;
      }

      /**
       * A triangle as the 16-bit driver fills it, from the setups 0x100259e0
       * (Gouraud), 0x10019fa0 (flat) and 0x1002d200 (textured, perspective),
       * which share their geometry:
       *
       * - the vertices are rotated, keeping their cyclic order, so the first
       *   has the smallest 16.16 y; from then on only the INTEGER parts of x
       *   and y are used (the vertex snaps to the pixel grid);
       * - edge a runs top -> second vertex (left), edge b top -> third (right),
       *   with 16.16 slopes from slope(); a triangle whose right edge is not
       *   at least one unit to the right is dropped (wrong winding);
       * - each scanline first steps both edges and then fills
       *   x = (xa >> 16) .. (xb >> 16) - 1 (the span routine 0x1002cbb0 /
       *   0x1006a340): the first row drawn, y_top, already uses the edge one
       *   step down;
       * - textured: per-vertex q_i = Z_j * Z_k and u_i * (1/512) * q_i
       *   (u in RWL21's fixed 16.16, NativeScene.uvFixed), stepped per line
       *   along each edge in float; spans of up to 16 pixels interpolate
       *   linearly between the perspective-correct ends, longer spans divide
       *   once every 16 pixels (texSpan);
       * - texel 0 is transparent.
       *
       * The depth buffer and the untextured shading keep the bridge's
       * approximation (1/Z and lighting linear in screen space along the same
       * edges), see ⚠️ in bridge/README.md.
       */
      void rasterTri(Pass p, float[] c0, float[] c1, float[] c2, NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k, float[] facetLit) {
         Cam c = p.c;
         DVert a = dvert(0, c0, c), b = dvert(1, c1, c), d = dvert(2, c2, c);
         // rotation to the top vertex (0x1002d200 head)
         DVert t0 = a, t1 = b, t2 = d;
         if (b.y16 < a.y16) {
            if (b.y16 < d.y16) {
               t0 = b;
               t1 = d;
               t2 = a;
            } else {
               t0 = d;
               t1 = a;
               t2 = b;
            }
         } else if (d.y16 < a.y16) {
            t0 = d;
            t1 = a;
            t2 = b;
         }
         int yT = t0.y16 >> 16, xT = t0.x16 >> 16;
         int y3 = t1.y16 >> 16, x3 = t1.x16 >> 16;
         int y4 = t2.y16 >> 16, x4 = t2.x16 >> 16;
         // q_i = product of the other two camera Z (0x1007f330/334/338) and u*q, v*q
         float qT = t2.z * t1.z, q3 = t2.z * t0.z, q4 = t1.z * t0.z;
         float uT = (float) t0.u * UV_SCALE * qT, vT = (float) t0.v * UV_SCALE * qT;
         float u3 = (float) t1.u * UV_SCALE * q3, v3 = (float) t1.v * UV_SCALE * q3;
         float u4 = (float) t2.u * UV_SCALE * q4, v4 = (float) t2.v * UV_SCALE * q4;
         int dy1 = y3 - yT;
         int row = yT;
         // untextured, opaque, per-vertex lit: the Gouraud triangle 0x100259e0
         gouraud = tex == null && facetLit == null && mat != null && mat.opacity >= 1.0F;
         int[] cT = null, c3 = null, c4 = null;
         if (gouraud) {
            int base = device565(mat.color[0], mat.color[1], mat.color[2]);
            cT = vertexColour(t0, base, colT);
            c3 = vertexColour(t1, base, col3);
            c4 = vertexColour(t2, base, col4);
            rowDither = DITHER_ROWS[(c.vpY & 7) + (yT & 7)];
         }
         if (dy1 < 1) {
            if (xT - x3 < 1) {
               return;
            }
            int dy = y4 - y3;
            if (dy == 0) {
               return;
            }
            if (gouraud) {
               // colour from the second vertex; across x towards the top one
               int w = xT - x3;
               gAcc = packRG(c3[0], c3[1]);
               gStep = pack(div(c4[0] - c3[0], dy), div(c4[1] - c3[1], dy));
               gGrad = pack(div(cT[0] - c3[0], w), div(cT[1] - c3[1], w));
               bAcc = c3[2] << 8;
               bStep = (short) div(c4[2] - c3[2], dy);
               bGrad = (short) div(cT[2] - c3[2], w);
            }
            edgeA.set(t1, q3, u3, v3, t2, q4, u4, v4, dy, x3 << 16, slope(x4 - x3, dy));
            edgeB.set(t0, qT, uT, vT, t2, q4, u4, v4, dy, xT << 16, slope(x4 - xT, dy));
            spans(p, row, dy, mat, tex, k, facetLit);
            return;
         }
         int dxa = slope(x3 - xT, dy1);
         int dy2 = y4 - yT;
         if (dy2 < 1) {
            if (x4 - xT < 1) {
               return;
            }
            if (gouraud) {
               int w = x4 - xT;
               gAcc = packRG(cT[0], cT[1]);
               gStep = pack(div(c3[0] - cT[0], dy1), div(c3[1] - cT[1], dy1));
               gGrad = pack(div(c4[0] - cT[0], w), div(c4[1] - cT[1], w));
               bAcc = cT[2] << 8;
               bStep = (short) div(c3[2] - cT[2], dy1);
               bGrad = (short) div(c4[2] - cT[2], w);
            }
            edgeA.set(t0, qT, uT, vT, t1, q3, u3, v3, dy1, xT << 16, dxa);
            edgeB.set(t2, q4, u4, v4, t1, q3, u3, v3, dy1, x4 << 16, slope(x3 - x4, dy1));
            spans(p, row, dy1, mat, tex, k, facetLit);
            return;
         }
         int dxb = slope(x4 - xT, dy2);
         if (dxb - dxa < 1) {
            return;
         }
         edgeA.set(t0, qT, uT, vT, t1, q3, u3, v3, dy1, xT << 16, dxa);
         edgeB.set(t0, qT, uT, vT, t2, q4, u4, v4, dy2, xT << 16, dxb);
         if (gouraud) {
            // per line along edge a; across x from the difference of the two
            // edges' per-line steps over the difference of their slopes
            int w = dxb - dxa;
            gAcc = packRG(cT[0], cT[1]);
            gStep = pack(div(c3[0] - cT[0], dy1), div(c3[1] - cT[1], dy1));
            int dr = div(c4[0] - cT[0], dy2) - (gStep >> 16);
            gGrad = dr != 0 ? dr * 0x10000 / w << 16 : 0;
            int dg = div(c4[1] - cT[1], dy2) - (short) gStep;
            if (dg != 0) {
               int u = gGrad | dg * 0x10000 / w & 0xFFFF;
               gGrad = u + (u & 0x8000) * -2;
            }
            bAcc = cT[2] << 8;
            bStep = (short) div(c3[2] - cT[2], dy1);
            int db = div(c4[2] - cT[2], dy2) - (short) bStep;
            bGrad = db != 0 ? (short) (db * 0x10000 / w) : 0;
         }
         if (dy1 < dy2) {
            row = spans(p, row, dy1, mat, tex, k, facetLit);
            int rest = dy2 - dy1;
            edgeA.set(t1, q3, u3, v3, t2, q4, u4, v4, rest, x3 << 16, slope(x4 - x3, rest));
            if (gouraud) {
               // the accumulators carry on; only edge a's per-line step changes
               gStep = pack(div(c4[0] - c3[0], rest), div(c4[1] - c3[1], rest));
               bStep = (short) div(c4[2] - c3[2], rest);
            }
            spans(p, row, rest, mat, tex, k, facetLit);
         } else {
            row = spans(p, row, dy2, mat, tex, k, facetLit);
            int rest = dy1 - dy2;
            if (rest == 0) {
               return;
            }
            edgeB.set(t2, q4, u4, v4, t1, q3, u3, v3, rest, x4 << 16, slope(x3 - x4, rest));
            spans(p, row, rest, mat, tex, k, facetLit);
         }
      }

      /**
       * count scanlines from row; returns the next row. Rows outside the
       * viewport or above the band are stepped without writing; once a row
       * is below the band (or the viewport) no later row of the triangle can
       * be written, so it stops there. Per pixel, only what the pixel's path
       * needs is interpolated (1/Z always; the flat lighting only for the
       * untextured non-Gouraud path) with the same float operations as
       * before, and the viewport columns are clamped once per row instead of
       * tested per pixel (a skipped column had no side effect).
       */
      int spans(Pass p, int row, int count, NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k, float[] facetLit) {
         Cam c = p.c;
         int base = mat == null ? 0 : device565(mat.color[0], mat.color[1], mat.color[2]);
         boolean litTex = mat != null && (mat.textureModes & 1) != 0;
         int opacity = mat == null ? 255 : (mat.opacity >= 1.0F ? 255 : ((int) (mat.opacity * 65536.0F) >> 8) & 0xFC);
         float flatR = facetLit != null ? facetLit[0] : 31.0F;
         float flatG = facetLit != null ? facetLit[1] : 31.0F;
         float flatB = facetLit != null ? facetLit[2] : 31.0F;
         // lit565(texel, flatR, flatG, flatB) with its three ramp rows taken once
         int rampR = clampRamp(flatR) * 32, rampG = clampRamp(flatG) * 32, rampB = clampRamp(flatB) * 32;
         short[] texels = tex == null ? null : tex.pixels;
         int ox = c.renderOffX + c.vpX, oy = c.renderOffY + c.vpY;
         int xMin = Math.max(0, c.renderOffX), xMax = Math.min(c.width, c.renderOffX + c.vpW);
         int yMin = Math.max(Math.max(0, c.renderOffY), bandMin);
         int yMax = Math.min(Math.min(c.height, c.renderOffY + c.vpH), bandMax);
         float[] zb = p.z;
         short[] out = c.raster;
         int width = c.width;
         int end = row + count;
         int wrote = 0;
         for (int r = 0; r < count; r++, row++) {
            int y = row + oy;
            if (y >= yMax) {
               break;
            }
            edgeA.step();
            edgeB.step();
            int xl = edgeA.x >> 16, xr = edgeB.x >> 16;
            int cnt = xr - xl;
            int thr = 0, acc = 0, accB = 0;
            if (gouraud) {
               gAcc += gStep;
               bAcc += bStep;
               acc = gAcc;
               accB = bAcc;
               thr = DITHER_COLS[(c.vpX & 7) + (xl & 7)];
               thr = (thr & ~0xFF) | ((thr ^ rowDither) & 0xFF);
               rowDither ^= rowDither >>> 6;
            }
            if (cnt <= 0 || y < yMin) {
               continue;
            }
            int[] uv = null;
            if (tex != null) {
               uv = spanUV = texSpan(edgeA.q, edgeA.uq, edgeA.vq, edgeB.q, edgeB.uq, edgeB.vq, cnt, spanUV);
            }
            int rowBase = y * width;
            int ditherRow = DITHER_Y[y & 7];
            float invCnt = 1.0F / cnt;
            int x0 = xl + ox;
            int iStart = xMin - x0;
            if (iStart < 0) {
               iStart = 0;
            }
            int iEnd = xMax - x0;
            if (iEnd > cnt) {
               iEnd = cnt;
            }
            float a0 = edgeA.at[0], d0 = edgeB.at[0] - a0;
            float a1 = edgeA.at[1], d1 = edgeB.at[1] - a1;
            float a2 = edgeA.at[2], d2 = edgeB.at[2] - a2;
            float a3 = edgeA.at[3], d3 = edgeB.at[3] - a3;
            for (int i = iStart; i < iEnd; i++) {
               int x = x0 + i;
               float tt = i * invCnt;
               float iz = a0 + d0 * tt;
               int zi = rowBase + x;
               int gpix = 0;
               if (gouraud) {
                  gpix = gouraudPixel(acc, accB, thr);
                  acc += gGrad;
                  accB += bGrad;
                  thr ^= thr >>> 6;
               }
               if (iz <= zb[zi]) {
                  continue;
               }
               if (opacity != 255) {
                  int dd = (DITHER_X[x & 7] ^ ditherRow) & 0xFF;
                  if (opacity <= dd) {
                     continue;
                  }
               }
               int pix;
               if (texels != null) {
                  int texel = texels[texelIndex(uv[i])] & 0xFFFF;
                  if (texel == 0) {
                     continue;
                  }
                  pix = litTex
                     ? RAMP[rampR + (texel >> 11 & 0x1F)] << 11 | RAMP[rampG + (texel >> 6 & 0x1F)] << 6 | RAMP[rampB + (texel & 0x1F)]
                     : texel;
                  texPx++;
               } else if (gouraud) {
                  pix = gpix;
                  flatPx++;
               } else {
                  pix = lit565(base, a1 + d1 * tt, a2 + d2 * tt, a3 + d3 * tt);
                  flatPx++;
               }
               zb[zi] = iz;
               out[zi] = (short) pix;
               wrote++;
               if (probeX >= 0 && x == probeX && y == probeY && c.width == mainWidth) {
                  probe = describe(mat, tex, k) + " px=#" + Integer.toHexString(pix);
               }
            }
         }
         pixels += wrote;
         if (tex != null) {
            texPixels += wrote;
         }
         if (matPx != null && wrote > 0) {
            String key = describe(mat, tex, k);
            int[] n2 = matPx.get(key);
            if (n2 == null) {
               matPx.put(key, new int[]{wrote});
            } else {
               n2[0] += wrote;
            }
         }
         return end;
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

   // ------------------------------------------------------------------
   // Polygon sort tree of a clump in hint mode 1 (RWL21 0x10033750)

   /**
    * What RWL21 keeps on a clump in hint mode 1 (rwHS without
    * rwEDITABLE): the polygons in drawing order (clump+0xac), the lengths
    * of the runs that alternate between "no depth test" and "depth test"
    * (clump+0xa8, closed by a 0) and whether the first run is a depth-test
    * one (clump+0xa4). Built once when the clump enters mode 1, not per
    * frame; the order does not depend on the camera.
    */
   public static final class SortTree {
      final NativeScene.Polygon[] order;
      /** The same order as indices into the clump's polygon list. */
      final int[] index;
      final int[] runs;
      final boolean firstConflict;

      SortTree(NativeScene.Polygon[] order, int[] index, int[] runs, boolean firstConflict) {
         this.order = order;
         this.index = index;
         this.runs = runs;
         this.firstConflict = firstConflict;
      }
   }

   /** Tree node of 0x10033750 (0x28 bytes from pool DAT_1005af00). */
   private static final class SortNode {
      /** +0: polygons that go before this one; +4: after; +8: next node that shares this place. */
      SortNode back;
      SortNode front;
      SortNode next;
      /** +0xc: unit normal; +0x18: plane distance; +0x1c: length of the normal sum. */
      float nx;
      float ny;
      float nz;
      float dist;
      float area;
      /** +0x20: the polygon, by index in the clump; +0x24: conflict flag. */
      int poly;
      int conflict;
   }

   /** RwDotProduct (RWL21 0x10051164): (a0*b0 + a1*b1) + a2*b2 on the x87 stack. */
   static double dot(float ax, float ay, float az, float bx, float by, float bz) {
      return ((double) ax * bx + (double) ay * by) + (double) az * bz;
   }

   /**
    * RWL21 0x10001100 for the sort tree: the centroid (RwAddVector from
    * the first vertex, then RwScaleVector by 1/n; out[0..2]), the fan sum
    * of cross(v[i]-v0, v[i+1]-v0) normalised (out[3..5]) and its length
    * before normalising (the return value, out[6]).
    */
   static float[] polygonPlane(NativeScene.Clump k, NativeScene.Polygon poly) {
      int n = poly.indices.length;
      float[] v0 = k.verts.get(poly.indices[0] - 1);
      float cx = v0[0], cy = v0[1], cz = v0[2];
      for (int i = 1; i < n; i++) {
         float[] v = k.verts.get(poly.indices[i] - 1);
         cx = cx + v[0];
         cy = cy + v[1];
         cz = cz + v[2];
      }
      float inv = (float) (1.0 / n);
      cx *= inv;
      cy *= inv;
      cz *= inv;
      float sx = 0.0F, sy = 0.0F, sz = 0.0F;
      float[] a = k.verts.get(poly.indices[1] - 1);
      float ax = a[0] - v0[0], ay = a[1] - v0[1], az = a[2] - v0[2];
      for (int i = 2; i < n; i++) {
         float[] b = k.verts.get(poly.indices[i] - 1);
         float bx = b[0] - v0[0], by = b[1] - v0[1], bz = b[2] - v0[2];
         sx = sx + (float) ((double) ay * bz - (double) az * by);
         sy = sy + (float) ((double) az * bx - (double) ax * bz);
         sz = sz + (float) ((double) ax * by - (double) ay * bx);
         ax = bx;
         ay = by;
         az = bz;
      }
      float len = (float) Math.sqrt(dot(sx, sy, sz, sx, sy, sz));
      if (len > 0.0F) {
         float r = 1.0F / len;
         sx *= r;
         sy *= r;
         sz *= r;
      }
      return new float[]{cx, cy, cz, sx, sy, sz, len};
   }

   /** 0.001f (RWL21 _DAT_10052268), the plane thickness of the classifier. */
   private static final float PLANE_EPS = 0.001F;

   /**
    * RWL21 0x10033cc0(A, B): how polygon B has to be ordered against A,
    * from the side of each other's plane their vertices lie on. A vertex
    * is in front when dot - dist > 0.001 (fcom on the unrounded value); it
    * is on the plane when the value rounded to float has its bits, as
    * unsigned, at most 0xba83126f (so -0.001f..0.001), and behind
    * otherwise. Returns 0 (same polygon), 3 (either order), -1 (B before
    * A), 1 (B after A) or 2 (they cross: depth test needed).
    */
   static int classify(NativeScene.Clump k, SortNode a, SortNode b) {
      if (a.poly == b.poly) {
         return 0;
      }
      int[] ib = k.polys.get(b.poly).indices;
      int[] ia = k.polys.get(a.poly).indices;
      int front1 = 0, on1 = 0;
      for (int idx : ib) {
         float[] v = k.verts.get(idx - 1);
         double d = dot(a.nx, a.ny, a.nz, v[0], v[1], v[2]) - a.dist;
         if (d > PLANE_EPS) {
            front1++;
         } else if (Integer.toUnsignedLong(Float.floatToRawIntBits((float) d)) <= 0xba83126fL) {
            on1++;
         }
      }
      int front2 = 0, on2 = 0;
      for (int idx : ia) {
         float[] v = k.verts.get(idx - 1);
         double d = dot(b.nx, b.ny, b.nz, v[0], v[1], v[2]) - b.dist;
         if (d > PLANE_EPS) {
            front2++;
         } else if (Integer.toUnsignedLong(Float.floatToRawIntBits((float) d)) <= 0xba83126fL) {
            on2++;
         }
      }
      int nb = ib.length, na = ia.length;
      if (front1 == 0 && front2 == 0) {
         return 3;
      }
      if (on1 == nb - front1 && na - front2 == on2) {
         return 3;
      }
      if (front1 == 0) {
         return -1;
      }
      if (on1 == nb - front1) {
         return 1;
      }
      if (front2 == 0) {
         return 1;
      }
      return na - front2 - on2 == 0 ? -1 : 2;
   }

   /**
    * RWL21 0x10033750, run when a clump enters hint mode 1 (FUN_10033600,
    * or 0x100329e0 when a locked bulk edit ends): one node per polygon, in
    * clump order, with the plane of 0x10001100 (dist = centroid . normal);
    * each node is inserted from the root comparing it with every node of
    * the list at that place (0x10033cc0): with no before/after answer it
    * joins the list, otherwise it goes down to the side whose nodes add up
    * the larger area (after on a tie), and the nodes of the other side
    * that disagree, plus the new one, are marked as conflicting, as are
    * both nodes of a crossing pair. The tree is then read in order (before
    * side, the list, after side); each list is written with the nodes of
    * the current run's flag first. Consecutive nodes with the same flag
    * form the runs. Null for a clump without polygons (0x10033750 then
    * returns without arrays).
    */
   static SortTree buildSortTree(NativeScene.Clump k) {
      int n = k.polys.size();
      if (n == 0) {
         return null;
      }
      SortNode[] nodes = new SortNode[n];
      for (int i = 0; i < n; i++) {
         SortNode s = new SortNode();
         float[] pl = polygonPlane(k, k.polys.get(i));
         s.poly = i;
         s.area = pl[6];
         s.nx = pl[3];
         s.ny = pl[4];
         s.nz = pl[5];
         s.dist = (float) dot(pl[0], pl[1], pl[2], s.nx, s.ny, s.nz);
         nodes[i] = s;
      }
      SortNode root = null;
      List<SortNode> before = new ArrayList<SortNode>();
      List<SortNode> after = new ArrayList<SortNode>();
      for (int i = 0; i < n; i++) {
         SortNode s = nodes[i];
         if (root == null) {
            root = s;
            continue;
         }
         SortNode cur = root;
         while (true) {
            before.clear();
            after.clear();
            float areaBefore = 0.0F, areaAfter = 0.0F;
            for (SortNode m = cur; m != null; m = m.next) {
               int r = classify(k, m, s);
               if (r == -1) {
                  before.add(m);
                  areaBefore = areaBefore + m.area;
               } else if (r == 1) {
                  after.add(m);
                  areaAfter = areaAfter + m.area;
               } else if (r == 2) {
                  m.conflict = 1;
                  s.conflict = 1;
               }
            }
            int side;
            if (before.isEmpty() && after.isEmpty()) {
               side = 3;
            } else if (areaAfter < areaBefore) {
               if (!after.isEmpty()) {
                  for (SortNode m : after) {
                     m.conflict = 1;
                  }
                  s.conflict = 1;
               }
               side = -1;
            } else {
               if (!before.isEmpty()) {
                  for (SortNode m : before) {
                     m.conflict = 1;
                  }
                  s.conflict = 1;
               }
               side = 1;
            }
            if (side == -1) {
               if (cur.back != null) {
                  cur = cur.back;
                  continue;
               }
               cur.back = s;
            } else if (side == 1) {
               if (cur.front != null) {
                  cur = cur.front;
                  continue;
               }
               cur.front = s;
            } else {
               s.next = cur.next;
               cur.next = s;
            }
            break;
         }
      }
      // in-order walk with an explicit stack (0x10033a5a..0x10033b13)
      SortNode[] out = new SortNode[n];
      int count = 0;
      int flag = 0;
      SortNode[] stack = new SortNode[n];
      int sp = 0;
      SortNode walk = root;
      while (true) {
         for (; walk != null; walk = walk.back) {
            stack[sp++] = walk;
         }
         if (sp == 0) {
            break;
         }
         SortNode top = stack[--sp];
         if (count == 0) {
            flag = top.conflict;
         }
         for (SortNode m = top; m != null; m = m.next) {
            if (m.conflict == flag) {
               out[count++] = m;
            }
         }
         for (SortNode m = top; m != null; m = m.next) {
            if (m.conflict != flag) {
               out[count++] = m;
            }
         }
         flag = out[count - 1].conflict;
         walk = top.front;
      }
      // runs (0x10033be3..0x10033c7f)
      NativeScene.Polygon[] order = new NativeScene.Polygon[n];
      int[] index = new int[n];
      int[] runs = new int[n + 1];
      int runIdx = 0, len = 0, cur = out[0].conflict;
      for (int i = 0; i < n; i++) {
         if (out[i].conflict != cur) {
            runs[runIdx++] = len;
            len = 0;
            cur = out[i].conflict;
         }
         len++;
         order[i] = k.polys.get(out[i].poly);
         index[i] = out[i].poly;
      }
      runs[runIdx] = len;
      int[] trimmed = new int[runIdx + 2];
      System.arraycopy(runs, 0, trimmed, 0, runIdx + 1);
      return new SortTree(order, index, trimmed, out[0].conflict != 0);
   }

   /**
    * For the checks: the sort tree of a clump as polygon indices (0-based,
    * clump order) in drawing order, then -1, the run lengths (ending in
    * 0), -1 and the flag of the first run. Null when there is no tree.
    */
   public static int[] sortTreeOf(int clump) {
      NativeScene.Clump k = NativeScene.clump(clump);
      if (k == null || k.sortTree == null) {
         return null;
      }
      SortTree t = k.sortTree;
      int[] out = new int[t.order.length + t.runs.length + 3];
      int o = 0;
      for (int i : t.index) {
         out[o++] = i;
      }
      out[o++] = -1;
      for (int r : t.runs) {
         out[o++] = r;
      }
      out[o++] = -1;
      out[o] = t.firstConflict ? 1 : 0;
      return out;
   }

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

   /** Output of clip(): the clipped polygon's vertices, valid until the next call. */
   private static float[][] clipResult;
   private static float[][] clipA = new float[32][];
   private static float[][] clipB = new float[32][];
   /** Vertices created by the clipper; reused from one polygon to the next. */
   private static float[][] clipPool = new float[64][];
   private static float[] sxBuf = new float[32];
   private static float[] syBuf = new float[32];

   /**
    * Clip against Z >= near, Z <= far, X >= 0, X <= Z, Y >= 0, Y <= Z (flags
    * 0x10, 0x20, 1, 2, 4, 8), one plane after another (Sutherland-Hodgman).
    * Returns the vertex count; the vertices are in clipResult. A polygon
    * with every vertex inside every plane comes back as it is, which is
    * what the plane loop gives for it anyway. The per-plane lists and new
    * vertices come from reused buffers instead of being allocated for every
    * polygon of every frame (the values are the same: same operations in
    * the same order).
    */
   private static int clip(float[][] poly, int n, Cam c) {
      boolean inside = true;
      float near = c.nearClip, far = c.farClip;
      for (int i = 0; i < n; i++) {
         float[] v = poly[i];
         float x = v[0], y = v[1], z = v[2];
         if (!(z - near >= 0.0F) || !(far - z >= 0.0F) || !(x >= 0.0F) || !(z - x >= 0.0F)
               || !(y >= 0.0F) || !(z - y >= 0.0F)) {
            inside = false;
            break;
         }
      }
      if (inside) {
         clipResult = poly;
         return n;
      }
      int used = 0;
      float[][] src = poly;
      int sn = n;
      float[][] dst = clipA;
      for (int plane = 0; plane < 6 && sn >= 3; plane++) {
         if (dst.length < sn * 2) {
            dst = new float[sn * 4][];
            if (src == clipA) {
               clipB = dst;
            } else {
               clipA = dst;
            }
         }
         int dn = 0;
         for (int i = 0; i < sn; i++) {
            float[] a = src[i];
            float[] b = src[i + 1 == sn ? 0 : i + 1];
            float da = dist(a, plane, c), db = dist(b, plane, c);
            if (da >= 0.0F) {
               dst[dn++] = a;
            }
            if (da >= 0.0F != db >= 0.0F) {
               float t = da / (da - db);
               if (used == clipPool.length) {
                  clipPool = java.util.Arrays.copyOf(clipPool, used * 2);
               }
               float[] r = clipPool[used];
               if (r == null) {
                  r = new float[NA];
                  clipPool[used] = r;
               }
               used++;
               for (int j = 0; j < NA; j++) {
                  r[j] = a[j] + (b[j] - a[j]) * t;
               }
               dst[dn++] = r;
            }
         }
         src = dst;
         sn = dn;
         dst = src == clipA ? clipB : clipA;
      }
      clipResult = src;
      return sn;
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
                  + " tex=" + (tex != null ? mat.textureName : "NONE(" + mat.textureName + ")")
                  + " amb=" + mat.ambient + " dif=" + mat.diffuse + " z=" + zz
                  + " clump=" + k.verts.size() + "v/" + k.polys.size() + "p";
            }
            p.z[zi] = iz;
            c.raster[zi] = (short) pix;
            wrote++;
            if (probeX >= 0 && x == probeX && y == probeY && c.width == mainWidth) {
               probeHit = describe(mat, tex, k) + " px=#" + Integer.toHexString(pix)
                  + " world=(" + (int) (cur[6] * zz) + "," + (int) (cur[7] * zz) + "," + (int) (cur[8] * zz) + ")";
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

   /** Material + owner of a polygon, for -Dopenworlds.matStats. */
   private static String describe(NativeScene.Material mat, NativeTextures.Texture tex, NativeScene.Clump k) {
      StringBuilder b = new StringBuilder();
      if (mat == null) {
         b.append("no material");
      } else {
         b.append("color 565=").append(device565(mat.color[0], mat.color[1], mat.color[2]) >> 11 & 31)
            .append(",").append(device565(mat.color[0], mat.color[1], mat.color[2]) >> 5 & 63)
            .append(",").append(device565(mat.color[0], mat.color[1], mat.color[2]) & 31)
            .append(tex != null ? " WITH texture" : mat.texture != 0 ? " texture=" + mat.texture + " NOT loaded"
               : mat.textureName != null ? " texture " + mat.textureName + " NOT resolved" : " NO texture")
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

   /** -Dopenworlds.probePixel=X,Y: which material/object ends up owning that pixel. */
   private static final int probeX;
   private static final int probeY;
   static {
      String v = System.getProperty("openworlds.probePixel");
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

   /** -Dopenworlds.matStats=SEC: pixels drawn per material/object, once per second from SEC. */
   private static void matStats(Pass p, int scene) {
      if (p.matPixels == null) {
         return;
      }
      long sec = (System.nanoTime() - DUMP_T0) / 1000000000L;
      String key = sec + "/" + scene;
      synchronized (matStatsShown) {
         if (sec >= Long.parseLong(System.getProperty("openworlds.matStats")) && matStatsShown.add("inv" + sec)) {
            NativeTextures.dumpInventory();
         }
         if (sec < Long.parseLong(System.getProperty("openworlds.matStats")) || !matStatsShown.add(key)) {
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
      System.err.println("[RW] matStats " + sec + "s room " + room + " (scene " + scene + "): " + l.size() + " visible materials");
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

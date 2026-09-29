package net.freeworlds.launcher;

import javax.swing.JComponent;
import javax.swing.Timer;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RadialGradientPaint;
import java.awt.Rectangle;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Path2D;
import java.awt.geom.Point2D;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The logo's planet, drawn live: the same 80-face icosphere, light,
 * continents and ring as tools/icons/make_icons.py (at rest it is the icon),
 * turning slowly about its own axis. The animation stops while hidden or
 * paused (the game's software rasterizer wants the CPU).
 */
final class PlanetView extends JComponent {
   // make_icons.py: rot(v, radians(-14), radians(28)), luz norm(-0.55, 0.62, 0.56)
   private static final double TILT_X = Math.toRadians(-14);
   private static final double TILT_Y = Math.toRadians(28);
   private static final double[] LIGHT = norm(new double[]{-0.55, 0.62, 0.56});
   private static final int[][] SEA = {{30, 34, 118}, {84, 214, 240}};
   private static final int[][] LAND = {{12, 56, 66}, {150, 245, 196}};
   /** A turn every 90 s. */
   private static final double SPIN_PER_MS = 2 * Math.PI / 90000.0;

   private final double[][] verts;
   private final int[][] faces;
   private final boolean[] land;
   private final double radius;
   private final Timer timer;
   /** Animation clock (ms): only runs while the planet turns, so pausing freezes it in place. */
   private double clock;
   private long last;
   private boolean paused;

   PlanetView(double radius) {
      this.radius = radius;
      List<double[]> v = new ArrayList<>();
      List<int[]> f = new ArrayList<>();
      icosphere(v, f);
      verts = v.toArray(new double[0][]);
      faces = f.toArray(new int[0][]);
      // los continentes van pegados al planeta: la funcion del icono se evalua
      // en la posicion inclinada de reposo, asi que con giro 0 sale el icono
      land = new boolean[faces.length];
      for (int i = 0; i < faces.length; i++) {
         double[] c = tilt(centroid(verts[faces[i][0]], verts[faces[i][1]], verts[faces[i][2]]));
         land[i] = Math.sin(4.1 * c[0] + 1.3) + Math.sin(3.3 * c[1] + 0.4) + Math.cos(5.2 * c[2] - 0.9) > 1.05;
      }
      setOpaque(false);
      int w = (int) Math.ceil(radius * 3.4);
      int h = (int) Math.ceil(radius * 3.3);
      setPreferredSize(new Dimension(w, h));
      setMinimumSize(new Dimension(w, h));
      timer = new Timer(33, e -> tick());
      timer.setCoalesce(true);
      addHierarchyListener(e -> updateTimer());
   }

   /** Stops or restarts the turning (e.g. while the game runs). */
   void setPaused(boolean p) {
      paused = p;
      updateTimer();
   }

   private void updateTimer() {
      boolean run = !paused && isShowing();
      if (run && !timer.isRunning()) {
         last = System.currentTimeMillis();
         timer.start();
      } else if (!run && timer.isRunning()) {
         timer.stop();
      }
   }

   private void tick() {
      long now = System.currentTimeMillis();
      clock += Math.min(now - last, 250);
      last = now;
      repaint();
   }

   @Override
   protected void paintComponent(Graphics g) {
      Graphics2D g2 = Theme.smooth(g);
      double k = radius / 236.0;     // el icono esta dibujado con R = 236
      double cx = getWidth() / 2.0;
      // flota un poco: 3 px (con R = 120) arriba y abajo cada 7 s
      double cy = getHeight() / 2.0 + Math.sin(clock / 7000.0 * 2 * Math.PI) * 3 * radius / 120;
      float glowR = (float) (radius + 150 * k);
      g2.setPaint(new RadialGradientPaint(new Point2D.Double(cx, cy), glowR, new float[]{0f, 1f},
         new Color[]{Theme.alpha(Theme.GLOW, 115), Theme.alpha(Theme.GLOW, 0)}));
      g2.fill(new Ellipse2D.Double(cx - glowR, cy - glowR, 2 * glowR, 2 * glowR));

      double rx = 372 * k;
      double ry = 96 * k;
      float rw = (float) (30 * k);
      ring(g2, cx, cy, rx, ry, rw, true);
      planet(g2, cx, cy, k);
      ring(g2, cx, cy, rx, ry, rw, false);
      g2.dispose();
   }

   private void planet(Graphics2D g2, double cx, double cy, double k) {
      double[][] p = new double[verts.length][];
      double spin = clock * SPIN_PER_MS;
      double c = Math.cos(spin);
      double s = Math.sin(spin);
      for (int i = 0; i < verts.length; i++) {
         double[] v = verts[i];
         // giro sobre el eje propio (y del objeto) y luego la inclinacion del icono
         p[i] = tilt(new double[]{v[0] * c + v[2] * s, v[1], -v[0] * s + v[2] * c});
      }
      List<double[]> order = new ArrayList<>();
      for (int i = 0; i < faces.length; i++) {
         double[] a = p[faces[i][0]];
         double[] b = p[faces[i][1]];
         double[] d = p[faces[i][2]];
         double[] u = {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
         double[] w = {d[0] - a[0], d[1] - a[1], d[2] - a[2]};
         double[] n = norm(new double[]{u[1] * w[2] - u[2] * w[1], u[2] * w[0] - u[0] * w[2], u[0] * w[1] - u[1] * w[0]});
         double[] cen = centroid(a, b, d);
         if (dot(n, cen) < 0) {
            n = new double[]{-n[0], -n[1], -n[2]};
         }
         if (n[2] <= 0.02) {
            continue;
         }
         double lit = 0.3 + 0.7 * Math.pow(Math.max(0, dot(n, LIGHT)), 1.05);
         order.add(new double[]{cen[2], i, lit});
      }
      order.sort((x, y) -> Double.compare(x[0], y[0]));
      g2.setStroke(new BasicStroke((float) (1.5 * k), BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND));
      Path2D.Double tri = new Path2D.Double();
      for (double[] o : order) {
         int i = (int) o[1];
         int[][] pal = land[i] ? LAND : SEA;
         double lit = o[2];
         g2.setColor(new Color(lerp(pal[0][0], pal[1][0], lit), lerp(pal[0][1], pal[1][1], lit), lerp(pal[0][2], pal[1][2], lit)));
         tri.reset();
         for (int j = 0; j < 3; j++) {
            double[] v = p[faces[i][j]];
            double x = cx + radius * v[0];
            double y = cy - radius * v[1];
            if (j == 0) {
               tri.moveTo(x, y);
            } else {
               tri.lineTo(x, y);
            }
         }
         tri.closePath();
         g2.fill(tri);
         g2.draw(tri);
      }
   }

   /** Half of the ring: the back one (behind the planet) or the front one, turned -17 degrees. */
   private static void ring(Graphics2D g, double cx, double cy, double rx, double ry, float width, boolean back) {
      Graphics2D g2 = (Graphics2D) g.create();
      g2.rotate(Math.toRadians(-17), cx, cy);
      double big = rx * 4;
      g2.clip(new Rectangle.Double(cx - big, back ? cy - big : cy, 2 * big, big));
      g2.setPaint(Theme.ring((float) (cx - rx), (float) (cx + rx), (float) cy));
      g2.setStroke(new BasicStroke(width));
      g2.draw(new Ellipse2D.Double(cx - rx, cy - ry, 2 * rx, 2 * ry));
      g2.dispose();
   }

   private static int lerp(int a, int b, double t) {
      return Math.max(0, Math.min(255, (int) Math.round(a + (b - a) * t)));
   }

   private static double[] tilt(double[] v) {
      double x = v[0], y = v[1], z = v[2];
      double c = Math.cos(TILT_X), s = Math.sin(TILT_X);
      double y2 = y * c - z * s;
      double z2 = y * s + z * c;
      c = Math.cos(TILT_Y);
      s = Math.sin(TILT_Y);
      return new double[]{x * c + z2 * s, y2, -x * s + z2 * c};
   }

   private static double[] centroid(double[] a, double[] b, double[] c) {
      return new double[]{(a[0] + b[0] + c[0]) / 3, (a[1] + b[1] + c[1]) / 3, (a[2] + b[2] + c[2]) / 3};
   }

   private static double dot(double[] a, double[] b) {
      return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
   }

   private static double[] norm(double[] v) {
      double l = Math.sqrt(dot(v, v));
      return new double[]{v[0] / l, v[1] / l, v[2] / l};
   }

   /** make_icons.py icosphere(1): the icosahedron with each face split in four. */
   private static void icosphere(List<double[]> verts, List<int[]> faces) {
      double t = (1 + Math.sqrt(5)) / 2;
      double[][] base = {{-1, t, 0}, {1, t, 0}, {-1, -t, 0}, {1, -t, 0}, {0, -1, t}, {0, 1, t},
         {0, -1, -t}, {0, 1, -t}, {t, 0, -1}, {t, 0, 1}, {-t, 0, -1}, {-t, 0, 1}};
      for (double[] v : base) {
         verts.add(norm(v));
      }
      int[][] ico = {{0, 11, 5}, {0, 5, 1}, {0, 1, 7}, {0, 7, 10}, {0, 10, 11}, {1, 5, 9}, {5, 11, 4}, {11, 10, 2},
         {10, 7, 6}, {7, 1, 8}, {3, 9, 4}, {3, 4, 2}, {3, 2, 6}, {3, 6, 8}, {3, 8, 9}, {4, 9, 5}, {2, 4, 11},
         {6, 2, 10}, {8, 6, 7}, {9, 8, 1}};
      Map<Long, Integer> cache = new HashMap<>();
      for (int[] f : ico) {
         int ab = mid(verts, cache, f[0], f[1]);
         int bc = mid(verts, cache, f[1], f[2]);
         int ca = mid(verts, cache, f[2], f[0]);
         faces.add(new int[]{f[0], ab, ca});
         faces.add(new int[]{f[1], bc, ab});
         faces.add(new int[]{f[2], ca, bc});
         faces.add(new int[]{ab, bc, ca});
      }
   }

   private static int mid(List<double[]> verts, Map<Long, Integer> cache, int a, int b) {
      long key = ((long) Math.min(a, b) << 32) | Math.max(a, b);
      Integer hit = cache.get(key);
      if (hit != null) {
         return hit;
      }
      double[] va = verts.get(a);
      double[] vb = verts.get(b);
      verts.add(norm(new double[]{(va[0] + vb[0]) / 2, (va[1] + vb[1]) / 2, (va[2] + vb[2]) / 2}));
      cache.put(key, verts.size() - 1);
      return verts.size() - 1;
   }
}

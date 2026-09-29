package net.openworlds.launcher;

import javax.swing.JPanel;
import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsConfiguration;
import java.awt.LayoutManager;
import java.awt.RadialGradientPaint;
import java.awt.Transparency;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Path2D;
import java.awt.geom.Point2D;
import java.awt.image.BufferedImage;
import java.util.Random;

/**
 * The night of the logo's tile as a window background: the diagonal indigo
 * gradient, a faint violet haze and stars with the icon's two sparkles. Drawn
 * once per size into an image, so animating the planet on top costs nothing.
 */
class SpaceBackground extends JPanel {
   private BufferedImage cache;
   private final boolean sparkles;

   SpaceBackground(LayoutManager layout) {
      this(layout, true);
   }

   /** {@code sparkles}: the icon's four-pointed stars; dialogs go without, they would fall on their cards. */
   SpaceBackground(LayoutManager layout, boolean sparkles) {
      super(layout);
      this.sparkles = sparkles;
      setOpaque(true);
      setBackground(Theme.SKY_BOTTOM);
   }

   @Override
   protected void paintComponent(Graphics g) {
      int w = getWidth();
      int h = getHeight();
      if (w <= 0 || h <= 0) {
         return;
      }
      GraphicsConfiguration gc = getGraphicsConfiguration();
      double scale = gc == null ? 1 : gc.getDefaultTransform().getScaleX();
      int iw = (int) Math.ceil(w * scale);
      int ih = (int) Math.ceil(h * scale);
      if (cache == null || cache.getWidth() != iw || cache.getHeight() != ih) {
         cache = gc == null ? new BufferedImage(iw, ih, BufferedImage.TYPE_INT_RGB)
            : gc.createCompatibleImage(iw, ih, Transparency.OPAQUE);
         Graphics2D c = Theme.smooth(cache.getGraphics());
         c.scale(scale, scale);
         paintSky(c, w, h, sparkles);
         c.dispose();
      }
      g.drawImage(cache, 0, 0, w, h, null);
   }

   static void paintSky(Graphics2D g, int w, int h, boolean sparkles) {
      g.setPaint(new GradientPaint(0, 0, Theme.SKY_TOP, w, h, Theme.SKY_BOTTOM));
      g.fillRect(0, 0, w, h);
      // violet haze at the top left, where the icon has its light
      float r = Math.max(w, h) * 0.75f;
      g.setPaint(new RadialGradientPaint(new Point2D.Float(w * 0.18f, h * 0.12f), r, new float[]{0f, 1f},
         new Color[]{new Color(0x6a, 0x4c, 0xd8, 60), new Color(0x6a, 0x4c, 0xd8, 0)}));
      g.fillRect(0, 0, w, h);
      // stars: the icon's rules (radius 2.5-7 of 1024, opacity 0.35-0.95),
      // at the window's scale and with a fixed seed
      Random rnd = new Random(7);
      int n = Math.max(24, w * h / 7000);
      for (int i = 0; i < n; i++) {
         double x = rnd.nextDouble() * w;
         double y = rnd.nextDouble() * h;
         double s = 0.5 + rnd.nextDouble() * rnd.nextDouble() * 1.9;
         int a = (int) (255 * (0.25 + rnd.nextDouble() * 0.7));
         g.setColor(new Color(255, 255, 255, a));
         g.fill(new Ellipse2D.Double(x - s, y - s, 2 * s, 2 * s));
      }
      if (!sparkles) {
         return;
      }
      // the sparkles on the planet's side: the card on the right would hide them
      sparkle(g, w * 0.06, h * 0.13, 11, 0.9f);
      sparkle(g, w * 0.43, h * 0.08, 7, 0.7f);
      sparkle(g, w * 0.04, h * 0.72, 8, 0.75f);
      sparkle(g, w * 0.46, h * 0.9, 6, 0.6f);
   }

   /** The icon's four-pointed sparkle (make_icons.py sparkle()). */
   static void sparkle(Graphics2D g, double x, double y, double s, float opacity) {
      Path2D.Double p = new Path2D.Double();
      p.moveTo(x, y - s);
      p.quadTo(x, y, x + s, y);
      p.quadTo(x, y, x, y + s);
      p.quadTo(x, y, x - s, y);
      p.quadTo(x, y, x, y - s);
      p.closePath();
      g.setColor(new Color(1f, 1f, 1f, opacity));
      g.fill(p);
   }
}

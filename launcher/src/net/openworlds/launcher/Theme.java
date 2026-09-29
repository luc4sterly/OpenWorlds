package net.openworlds.launcher;

import java.awt.Color;
import java.awt.Font;
import java.awt.FontFormatException;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.LinearGradientPaint;
import java.awt.RenderingHints;
import java.io.IOException;
import java.io.InputStream;

/**
 * The launcher's look, taken from the logo (tools/icons/make_icons.py): the
 * indigo night of the tile, the cyan glow, the sea and land of the low-poly
 * planet and the coral-to-gold ring. Text is Poppins (SIL OFL, bundled in
 * fonts/ with its licence) so the window looks the same on every system.
 */
final class Theme {
   private Theme() {
   }

   // the icon's background: diagonal gradient #2d1d72 -> #0a0724
   static final Color SKY_TOP = new Color(0x2d, 0x1d, 0x72);
   static final Color SKY_BOTTOM = new Color(0x0a, 0x07, 0x24);
   /** The planet's glow (#4fd6ff at 45 % in the icon). */
   static final Color GLOW = new Color(0x4f, 0xd6, 0xff);
   // ring: #ff5e62 -> #ff9f43 (0.55) -> #ffd166
   static final Color RING_A = new Color(0xff, 0x5e, 0x62);
   static final Color RING_B = new Color(0xff, 0x9f, 0x43);
   static final Color RING_C = new Color(0xff, 0xd1, 0x66);
   // the planet's sea and land, lit end
   static final Color SEA = new Color(84, 214, 240);
   static final Color LAND = new Color(150, 245, 196);

   static final Color TEXT = new Color(0xf3, 0xf1, 0xff);
   static final Color MUTED = new Color(0xa9, 0xa5, 0xd8);
   static final Color FAINT = new Color(0x77, 0x72, 0xa8);
   /** Dark text on the ring's gradient (5.9:1 contrast with the coral). */
   static final Color INK = new Color(0x1a, 0x0f, 0x3d);
   static final Color CARD = new Color(255, 255, 255, 15);
   static final Color CARD_EDGE = new Color(255, 255, 255, 30);
   static final Color FIELD = new Color(10, 7, 36, 150);
   static final Color FIELD_EDGE = new Color(255, 255, 255, 38);
   static final Color HOVER = new Color(255, 255, 255, 20);
   static final Color SELECTED = new Color(84, 214, 240, 46);
   static final Color ERROR = new Color(0xff, 0x8a, 0x8a);

   private static Font regular;
   private static Font medium;
   private static Font semibold;
   private static Font bold;

   /** Loads the bundled fonts; the logical SansSerif stands in for any that fails. */
   static synchronized void init() {
      if (regular != null) {
         return;
      }
      regular = load("Poppins-Regular.ttf", Font.PLAIN);
      medium = load("Poppins-Medium.ttf", Font.PLAIN);
      semibold = load("Poppins-SemiBold.ttf", Font.BOLD);
      bold = load("Poppins-Bold.ttf", Font.BOLD);
   }

   private static Font load(String name, int fallbackStyle) {
      try (InputStream in = Theme.class.getResourceAsStream("fonts/" + name)) {
         if (in != null) {
            Font f = Font.createFont(Font.TRUETYPE_FONT, in);
            GraphicsEnvironment.getLocalGraphicsEnvironment().registerFont(f);
            return f;
         }
      } catch (IOException | FontFormatException | RuntimeException e) {
         System.err.println("[launcher] font " + name + " not available: " + e);
      }
      return new Font(Font.SANS_SERIF, fallbackStyle, 12);
   }

   static Font regular(float size) {
      init();
      return regular.deriveFont(size);
   }

   static Font medium(float size) {
      init();
      return medium.deriveFont(size);
   }

   static Font semibold(float size) {
      init();
      return semibold.deriveFont(size);
   }

   static Font bold(float size) {
      init();
      return bold.deriveFont(size);
   }

   /** Graphics2D with antialiasing for shapes and text. */
   static Graphics2D smooth(Graphics g) {
      Graphics2D g2 = (Graphics2D) g.create();
      g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
      g2.setRenderingHint(RenderingHints.KEY_FRACTIONALMETRICS, RenderingHints.VALUE_FRACTIONALMETRICS_ON);
      g2.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
      g2.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
      return g2;
   }

   /** The ring's gradient across [x0, x1], as in the logo (#ff5e62, #ff9f43 at 55 %, #ffd166). */
   static LinearGradientPaint ring(float x0, float x1, float y) {
      if (x1 - x0 < 1f) {
         x1 = x0 + 1f;
      }
      return new LinearGradientPaint(x0, y, x1, y, new float[]{0f, 0.55f, 1f}, new Color[]{RING_A, RING_B, RING_C});
   }

   static Color alpha(Color c, int a) {
      return new Color(c.getRed(), c.getGreen(), c.getBlue(), Math.max(0, Math.min(255, a)));
   }

   static Color mix(Color a, Color b, float t) {
      t = Math.max(0f, Math.min(1f, t));
      return new Color(Math.round(a.getRed() + (b.getRed() - a.getRed()) * t),
         Math.round(a.getGreen() + (b.getGreen() - a.getGreen()) * t),
         Math.round(a.getBlue() + (b.getBlue() - a.getBlue()) * t),
         Math.round(a.getAlpha() + (b.getAlpha() - a.getAlpha()) * t));
   }
}

package net.openworlds.ui;

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
 * The look of the OpenWorlds apps, taken from their icons
 * (tools/icons/make_icons.py). Two palettes: {@link Palette#WORLDS}, the
 * game launcher's indigo night with the cyan glow, the sea and land of the
 * planet and the coral-to-gold ring; and {@link Palette#SOLAR}, J Solar
 * Server's purple night with a violet glow and a lavender-to-pink ring.
 * An app picks its palette once, before it builds any window
 * ({@link #use}). Text is Poppins (SIL OFL, bundled in fonts/ with its
 * licence) so the windows look the same on every system.
 */
public final class Theme {
   private Theme() {
   }

   public enum Palette { WORLDS, SOLAR }

   /** The window background: a diagonal gradient from SKY_TOP to SKY_BOTTOM. */
   public static Color SKY_TOP;
   public static Color SKY_BOTTOM;
   /** A soft haze at the top left of the background, where the icon has its light. */
   public static Color HAZE;
   /** The planet's glow. */
   public static Color GLOW;
   /** The ring's gradient, also on primary buttons. */
   public static Color RING_A;
   public static Color RING_B;
   public static Color RING_C;
   /** Accent for focus, selection and links. */
   public static Color SEA;
   /** "Good" state: installed, running, online. */
   public static Color LAND;
   public static Color TEXT;
   public static Color MUTED;
   public static Color FAINT;
   /** Dark text on the ring's gradient. */
   public static Color INK;
   /** Cards: a dark base, a light veil and a hairline edge. */
   public static Color CARD_BASE;
   public static Color CARD;
   public static Color CARD_EDGE;
   public static Color FIELD;
   public static Color FIELD_OFF;
   public static Color FIELD_EDGE;
   public static Color HOVER;
   public static Color SELECTED;
   public static Color ERROR;
   /** Tooltip background. */
   public static Color TIP;

   private static Palette palette;

   static {
      use(Palette.WORLDS);
   }

   public static Palette palette() {
      return palette;
   }

   /** Switches the colours; call it before building any window. */
   public static void use(Palette p) {
      palette = p;
      TEXT = new Color(0xf3, 0xf1, 0xff);
      CARD = new Color(255, 255, 255, 15);
      CARD_EDGE = new Color(255, 255, 255, 30);
      FIELD_EDGE = new Color(255, 255, 255, 38);
      HOVER = new Color(255, 255, 255, 20);
      ERROR = new Color(0xff, 0x8a, 0x8a);
      if (p == Palette.SOLAR) {
         // solar.svg: background #43177a -> #12051f, glow #c77dff,
         // ring #a78bfa -> #e879f9 (0.55) -> #f9a8d4
         SKY_TOP = new Color(0x43, 0x17, 0x7a);
         SKY_BOTTOM = new Color(0x12, 0x05, 0x1f);
         HAZE = new Color(0xb0, 0x5c, 0xe8);
         GLOW = new Color(0xc7, 0x7d, 0xff);
         RING_A = new Color(0xa7, 0x8b, 0xfa);
         RING_B = new Color(0xe8, 0x79, 0xf9);
         RING_C = new Color(0xf9, 0xa8, 0xd4);
         SEA = new Color(0xd8, 0xb4, 0xfe);
         LAND = new Color(0x9a, 0xf0, 0xc7);
         MUTED = new Color(0xc2, 0xb0, 0xe6);
         FAINT = new Color(0x8e, 0x78, 0xb8);
         INK = new Color(0x22, 0x0a, 0x3a);
         CARD_BASE = new Color(24, 7, 44, 170);
         FIELD = new Color(20, 5, 36, 150);
         FIELD_OFF = new Color(20, 5, 36, 70);
         SELECTED = new Color(0xd8, 0xb4, 0xfe, 46);
         TIP = new Color(0x2c, 0x10, 0x4c);
      } else {
         // openworlds.svg: background #2d1d72 -> #0a0724, glow #4fd6ff,
         // ring #ff5e62 -> #ff9f43 (0.55) -> #ffd166
         SKY_TOP = new Color(0x2d, 0x1d, 0x72);
         SKY_BOTTOM = new Color(0x0a, 0x07, 0x24);
         HAZE = new Color(0x6a, 0x4c, 0xd8);
         GLOW = new Color(0x4f, 0xd6, 0xff);
         RING_A = new Color(0xff, 0x5e, 0x62);
         RING_B = new Color(0xff, 0x9f, 0x43);
         RING_C = new Color(0xff, 0xd1, 0x66);
         SEA = new Color(84, 214, 240);
         LAND = new Color(150, 245, 196);
         MUTED = new Color(0xa9, 0xa5, 0xd8);
         FAINT = new Color(0x77, 0x72, 0xa8);
         // 5.9:1 contrast with the coral
         INK = new Color(0x1a, 0x0f, 0x3d);
         CARD_BASE = new Color(14, 9, 44, 165);
         FIELD = new Color(10, 7, 36, 150);
         FIELD_OFF = new Color(10, 7, 36, 70);
         SELECTED = new Color(84, 214, 240, 46);
         TIP = new Color(0x1d, 0x16, 0x4a);
      }
   }

   private static Font regular;
   private static Font medium;
   private static Font semibold;
   private static Font bold;

   /** Loads the bundled fonts; the logical SansSerif stands in for any that fails. */
   public static synchronized void init() {
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
         System.err.println("[ui] font " + name + " not available: " + e);
      }
      return new Font(Font.SANS_SERIF, fallbackStyle, 12);
   }

   public static Font regular(float size) {
      init();
      return regular.deriveFont(size);
   }

   public static Font medium(float size) {
      init();
      return medium.deriveFont(size);
   }

   public static Font semibold(float size) {
      init();
      return semibold.deriveFont(size);
   }

   public static Font bold(float size) {
      init();
      return bold.deriveFont(size);
   }

   /** Graphics2D with antialiasing for shapes and text. */
   public static Graphics2D smooth(Graphics g) {
      Graphics2D g2 = (Graphics2D) g.create();
      g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
      g2.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);
      g2.setRenderingHint(RenderingHints.KEY_FRACTIONALMETRICS, RenderingHints.VALUE_FRACTIONALMETRICS_ON);
      g2.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
      g2.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);
      return g2;
   }

   /** The ring's gradient across [x0, x1], as in the icon (RING_A, RING_B at 55 %, RING_C). */
   public static LinearGradientPaint ring(float x0, float x1, float y) {
      if (x1 - x0 < 1f) {
         x1 = x0 + 1f;
      }
      return new LinearGradientPaint(x0, y, x1, y, new float[]{0f, 0.55f, 1f}, new Color[]{RING_A, RING_B, RING_C});
   }

   public static Color alpha(Color c, int a) {
      return new Color(c.getRed(), c.getGreen(), c.getBlue(), Math.max(0, Math.min(255, a)));
   }

   public static Color mix(Color a, Color b, float t) {
      t = Math.max(0f, Math.min(1f, t));
      return new Color(Math.round(a.getRed() + (b.getRed() - a.getRed()) * t),
         Math.round(a.getGreen() + (b.getGreen() - a.getGreen()) * t),
         Math.round(a.getBlue() + (b.getBlue() - a.getBlue()) * t),
         Math.round(a.getAlpha() + (b.getAlpha() - a.getAlpha()) * t));
   }
}

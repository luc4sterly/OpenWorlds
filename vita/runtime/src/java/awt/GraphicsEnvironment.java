package java.awt;

import java.awt.image.BufferedImage;
import java.util.Locale;

import net.openworlds.awt.Fonts;

/** The one screen, as java.awt.GraphicsEnvironment. */
public class GraphicsEnvironment {
   private static GraphicsEnvironment local;
   private final GraphicsDevice screen = new GraphicsDevice();

   protected GraphicsEnvironment() {
   }

   public static synchronized GraphicsEnvironment getLocalGraphicsEnvironment() {
      if (local == null) {
         local = new GraphicsEnvironment();
      }
      return local;
   }

   public static boolean isHeadless() {
      return false;
   }

   public boolean isHeadlessInstance() {
      return false;
   }

   public GraphicsDevice[] getScreenDevices() {
      return new GraphicsDevice[]{screen};
   }

   public GraphicsDevice getDefaultScreenDevice() {
      return screen;
   }

   public Graphics2D createGraphics(BufferedImage img) {
      return new SurfaceGraphics(img);
   }

   public Font[] getAllFonts() {
      String[] names = Fonts.familyNames();
      Font[] fonts = new Font[names.length];
      for (int i = 0; i < names.length; i++) {
         fonts[i] = new Font(names[i], Font.PLAIN, 1);
      }
      return fonts;
   }

   public String[] getAvailableFontFamilyNames() {
      return Fonts.familyNames();
   }

   public String[] getAvailableFontFamilyNames(Locale l) {
      return Fonts.familyNames();
   }

   public Point getCenterPoint() {
      Dimension d = WindowSystem.screenSize();
      return new Point(d.width / 2, d.height / 2);
   }

   public Rectangle getMaximumWindowBounds() {
      Dimension d = WindowSystem.screenSize();
      return new Rectangle(0, 0, d.width, d.height);
   }
}

package java.awt;

/** An sRGB colour with alpha, as java.awt.Color (same brighter/darker/HSB arithmetic). */
public class Color implements java.io.Serializable {
   public static final Color white = new Color(255, 255, 255);
   public static final Color WHITE = white;
   public static final Color lightGray = new Color(192, 192, 192);
   public static final Color LIGHT_GRAY = lightGray;
   public static final Color gray = new Color(128, 128, 128);
   public static final Color GRAY = gray;
   public static final Color darkGray = new Color(64, 64, 64);
   public static final Color DARK_GRAY = darkGray;
   public static final Color black = new Color(0, 0, 0);
   public static final Color BLACK = black;
   public static final Color red = new Color(255, 0, 0);
   public static final Color RED = red;
   public static final Color pink = new Color(255, 175, 175);
   public static final Color PINK = pink;
   public static final Color orange = new Color(255, 200, 0);
   public static final Color ORANGE = orange;
   public static final Color yellow = new Color(255, 255, 0);
   public static final Color YELLOW = yellow;
   public static final Color green = new Color(0, 255, 0);
   public static final Color GREEN = green;
   public static final Color magenta = new Color(255, 0, 255);
   public static final Color MAGENTA = magenta;
   public static final Color cyan = new Color(0, 255, 255);
   public static final Color CYAN = cyan;
   public static final Color blue = new Color(0, 0, 255);
   public static final Color BLUE = blue;

   private static final double FACTOR = 0.7;

   /** 0xAARRGGBB */
   int value;

   public Color(int r, int g, int b) {
      this(r, g, b, 255);
   }

   public Color(int r, int g, int b, int a) {
      check(r, g, b, a);
      value = ((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
   }

   public Color(int rgb) {
      value = 0xFF000000 | rgb;
   }

   public Color(int rgba, boolean hasAlpha) {
      value = hasAlpha ? rgba : 0xFF000000 | rgba;
   }

   public Color(float r, float g, float b) {
      this((int) (r * 255 + 0.5), (int) (g * 255 + 0.5), (int) (b * 255 + 0.5));
   }

   public Color(float r, float g, float b, float a) {
      this((int) (r * 255 + 0.5), (int) (g * 255 + 0.5), (int) (b * 255 + 0.5), (int) (a * 255 + 0.5));
   }

   private static void check(int r, int g, int b, int a) {
      if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255) {
         throw new IllegalArgumentException("Color parameter outside of expected range");
      }
   }

   public int getRed() {
      return (value >> 16) & 0xFF;
   }

   public int getGreen() {
      return (value >> 8) & 0xFF;
   }

   public int getBlue() {
      return value & 0xFF;
   }

   public int getAlpha() {
      return (value >>> 24) & 0xFF;
   }

   public int getRGB() {
      return value;
   }

   public int getTransparency() {
      int a = getAlpha();
      return a == 255 ? 1 : a == 0 ? 2 : 3;
   }

   public Color brighter() {
      int r = getRed();
      int g = getGreen();
      int b = getBlue();
      int alpha = getAlpha();
      int i = (int) (1.0 / (1.0 - FACTOR));
      if (r == 0 && g == 0 && b == 0) {
         return new Color(i, i, i, alpha);
      }
      if (r > 0 && r < i) {
         r = i;
      }
      if (g > 0 && g < i) {
         g = i;
      }
      if (b > 0 && b < i) {
         b = i;
      }
      return new Color(Math.min((int) (r / FACTOR), 255), Math.min((int) (g / FACTOR), 255), Math.min((int) (b / FACTOR), 255), alpha);
   }

   public Color darker() {
      return new Color(Math.max((int) (getRed() * FACTOR), 0), Math.max((int) (getGreen() * FACTOR), 0),
            Math.max((int) (getBlue() * FACTOR), 0), getAlpha());
   }

   public static Color decode(String nm) throws NumberFormatException {
      int i = Integer.decode(nm).intValue();
      return new Color((i >> 16) & 0xFF, (i >> 8) & 0xFF, i & 0xFF);
   }

   public static Color getColor(String nm) {
      return getColor(nm, null);
   }

   public static Color getColor(String nm, Color v) {
      Integer intval = Integer.getInteger(nm);
      if (intval == null) {
         return v;
      }
      int i = intval.intValue();
      return new Color((i >> 16) & 0xFF, (i >> 8) & 0xFF, i & 0xFF);
   }

   public static Color getColor(String nm, int v) {
      Integer intval = Integer.getInteger(nm);
      int i = (intval != null) ? intval.intValue() : v;
      return new Color((i >> 16) & 0xFF, (i >> 8) & 0xFF, i & 0xFF);
   }

   public static int HSBtoRGB(float hue, float saturation, float brightness) {
      int r = 0, g = 0, b = 0;
      if (saturation == 0) {
         r = g = b = (int) (brightness * 255.0f + 0.5f);
      } else {
         float h = (hue - (float) Math.floor(hue)) * 6.0f;
         float f = h - (float) Math.floor(h);
         float p = brightness * (1.0f - saturation);
         float q = brightness * (1.0f - saturation * f);
         float t = brightness * (1.0f - (saturation * (1.0f - f)));
         switch ((int) h) {
            case 0:
               r = (int) (brightness * 255.0f + 0.5f);
               g = (int) (t * 255.0f + 0.5f);
               b = (int) (p * 255.0f + 0.5f);
               break;
            case 1:
               r = (int) (q * 255.0f + 0.5f);
               g = (int) (brightness * 255.0f + 0.5f);
               b = (int) (p * 255.0f + 0.5f);
               break;
            case 2:
               r = (int) (p * 255.0f + 0.5f);
               g = (int) (brightness * 255.0f + 0.5f);
               b = (int) (t * 255.0f + 0.5f);
               break;
            case 3:
               r = (int) (p * 255.0f + 0.5f);
               g = (int) (q * 255.0f + 0.5f);
               b = (int) (brightness * 255.0f + 0.5f);
               break;
            case 4:
               r = (int) (t * 255.0f + 0.5f);
               g = (int) (p * 255.0f + 0.5f);
               b = (int) (brightness * 255.0f + 0.5f);
               break;
            case 5:
               r = (int) (brightness * 255.0f + 0.5f);
               g = (int) (p * 255.0f + 0.5f);
               b = (int) (q * 255.0f + 0.5f);
               break;
         }
      }
      return 0xff000000 | (r << 16) | (g << 8) | b;
   }

   public static float[] RGBtoHSB(int r, int g, int b, float[] hsbvals) {
      float hue, saturation, brightness;
      if (hsbvals == null) {
         hsbvals = new float[3];
      }
      int cmax = (r > g) ? r : g;
      if (b > cmax) {
         cmax = b;
      }
      int cmin = (r < g) ? r : g;
      if (b < cmin) {
         cmin = b;
      }
      brightness = ((float) cmax) / 255.0f;
      saturation = cmax != 0 ? ((float) (cmax - cmin)) / ((float) cmax) : 0;
      if (saturation == 0) {
         hue = 0;
      } else {
         float redc = ((float) (cmax - r)) / ((float) (cmax - cmin));
         float greenc = ((float) (cmax - g)) / ((float) (cmax - cmin));
         float bluec = ((float) (cmax - b)) / ((float) (cmax - cmin));
         if (r == cmax) {
            hue = bluec - greenc;
         } else if (g == cmax) {
            hue = 2.0f + redc - bluec;
         } else {
            hue = 4.0f + greenc - redc;
         }
         hue = hue / 6.0f;
         if (hue < 0) {
            hue = hue + 1.0f;
         }
      }
      hsbvals[0] = hue;
      hsbvals[1] = saturation;
      hsbvals[2] = brightness;
      return hsbvals;
   }

   public static Color getHSBColor(float h, float s, float b) {
      return new Color(HSBtoRGB(h, s, b));
   }

   public float[] getRGBColorComponents(float[] compArray) {
      float[] f = compArray == null ? new float[3] : compArray;
      f[0] = getRed() / 255f;
      f[1] = getGreen() / 255f;
      f[2] = getBlue() / 255f;
      return f;
   }

   public boolean equals(Object obj) {
      return obj instanceof Color && ((Color) obj).getRGB() == getRGB();
   }

   public int hashCode() {
      return value;
   }

   public String toString() {
      return getClass().getName() + "[r=" + getRed() + ",g=" + getGreen() + ",b=" + getBlue() + "]";
   }
}

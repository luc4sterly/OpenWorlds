package net.openworlds.awt;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;

/**
 * The fonts behind java.awt.Font. The names the 2004 client asked for are
 * mapped as its JRE 1.4 mapped them on Windows (dialog and sansserif to
 * Arial, serif to Times New Roman, monospaced to Courier New) and drawn
 * with the Liberation fonts, which have the same metrics (the bridge's
 * NativeUiFonts does the same on the desktop).
 *
 * Where: -Dopenworlds.fonts=dir[;dir...], a "fonts" folder next to the
 * program (the Vita's app0:/fonts), or the system's Liberation fonts.
 */
public final class Fonts {
   private Fonts() {
   }

   public static final int PLAIN = 0;
   public static final int BOLD = 1;
   public static final int ITALIC = 2;

   private static final String SANS = "LiberationSans";
   private static final String SERIF = "LiberationSerif";
   private static final String MONO = "LiberationMono";

   private static final HashMap<String, TrueTypeFont> files = new HashMap<String, TrueTypeFont>();
   private static final HashMap<String, FontFace> faces = new HashMap<String, FontFace>();

   /** The Liberation family for a font name, as the 2004 JRE resolved it. */
   public static String family(String name) {
      String n = name == null ? "dialog" : name.trim().toLowerCase();
      if (n.equals("serif") || n.equals("timesroman") || n.equals("times new roman") || n.equals("times")
            || n.startsWith("liberation serif") || n.equals("tinos")) {
         return SERIF;
      }
      if (n.equals("monospaced") || n.equals("dialoginput") || n.equals("courier") || n.equals("courier new")
            || n.startsWith("liberation mono") || n.equals("cousine")) {
         return MONO;
      }
      return SANS;
   }

   /** The family name java.awt.Font.getFamily reports. */
   public static String familyName(String name) {
      String f = family(name);
      if (f == SERIF) {
         return "Times New Roman";
      }
      if (f == MONO) {
         return "Courier New";
      }
      return "Arial";
   }

   public static FontFace face(String name, int style, float size) {
      String fam = family(name);
      String key = fam + "/" + style + "/" + size;
      synchronized (faces) {
         FontFace f = faces.get(key);
         if (f == null) {
            f = new FontFace(file(fam, style), size);
            faces.put(key, f);
         }
         return f;
      }
   }

   private static TrueTypeFont file(String family, int style) {
      String suffix;
      switch (style & (BOLD | ITALIC)) {
         case BOLD:
            suffix = "-Bold.ttf";
            break;
         case ITALIC:
            suffix = "-Italic.ttf";
            break;
         case BOLD | ITALIC:
            suffix = "-BoldItalic.ttf";
            break;
         default:
            suffix = "-Regular.ttf";
      }
      String fileName = family + suffix;
      synchronized (files) {
         TrueTypeFont f = files.get(fileName);
         if (f != null) {
            return f;
         }
         byte[] data = find(fileName);
         if (data == null && style != PLAIN) {
            return file(family, PLAIN);
         }
         if (data == null && family != SANS) {
            return file(SANS, style);
         }
         if (data == null) {
            throw new IllegalStateException("no font " + fileName + " (looked in " + searchPath() + ")");
         }
         f = new TrueTypeFont(data, fileName);
         files.put(fileName, f);
         return f;
      }
   }

   private static String searchPath() {
      StringBuilder b = new StringBuilder();
      for (String d : dirs()) {
         if (b.length() > 0) {
            b.append(", ");
         }
         b.append(d);
      }
      return b.toString();
   }

   private static String[] dirs() {
      String prop = System.getProperty("openworlds.fonts");
      String[] fixed = {"fonts", "app0:/fonts", "app0:fonts", "/usr/share/fonts/truetype/liberation", "/usr/share/fonts/truetype/liberation2",
            "/usr/share/fonts/liberation", "/usr/share/fonts/liberation-sans", "/usr/share/fonts/liberation-serif",
            "/usr/share/fonts/liberation-mono", "/usr/local/share/fonts", "/Library/Fonts"};
      if (prop == null || prop.length() == 0) {
         return fixed;
      }
      String[] p = prop.split(";");
      String[] all = new String[p.length + fixed.length];
      System.arraycopy(p, 0, all, 0, p.length);
      System.arraycopy(fixed, 0, all, p.length, fixed.length);
      return all;
   }

   private static byte[] find(String fileName) {
      for (String d : dirs()) {
         File f = new File(d, fileName);
         if (f.isFile()) {
            try {
               return read(new FileInputStream(f));
            } catch (IOException e) {
               // the next one
            }
         }
      }
      InputStream in = Fonts.class.getResourceAsStream("/fonts/" + fileName);
      if (in != null) {
         try {
            return read(in);
         } catch (IOException e) {
            return null;
         }
      }
      return null;
   }

   private static byte[] read(InputStream in) throws IOException {
      try {
         ByteArrayOutputStream out = new ByteArrayOutputStream();
         byte[] buf = new byte[65536];
         int n;
         while ((n = in.read(buf)) > 0) {
            out.write(buf, 0, n);
         }
         return out.toByteArray();
      } finally {
         in.close();
      }
   }

   /** The family names getAvailableFontFamilyNames reports. */
   public static String[] familyNames() {
      return new String[]{"Arial", "Courier New", "Dialog", "DialogInput", "Monospaced", "SansSerif", "Serif", "Times New Roman"};
   }
}

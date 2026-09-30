package NET.worlds.core;

import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Locale;
import java.util.Map;
import java.util.Set;

/**
 * Platform, not gamma.dll: the fonts with which the 2004 client measured its
 * interface. The installation's JRE 1.4 (assets/WorldsPlayer/lib/
 * font.properties) resolved the logical names to Windows fonts:
 * dialog.0 and sansserif.0 = Arial, serif.0 = Times New Roman, monospaced.0
 * and dialoginput.0 = Courier New; and Windows replaced Helvetica with Arial
 * (FontSubstitutes). A modern JDK resolves them to DejaVu Sans (Linux) or
 * Lucida Grande (macOS), which are wider: the status bar text did not fit
 * in its 93 px cell ("Jse arrow keys") and other labels were cut off in the
 * same way.
 *
 * build_gamma.sh (bridge/ui_fonts.py) changes each {@code new Font(name,
 * style, size)} of the decompiled Java to {@link #font} and gives
 * GammaFrame the AWT default font of the time ({@link #windowFont}:
 * Dialog 12 = Arial 12). The font chosen is the 2004 one if it is installed
 * (Arial on macOS and Windows) or one with the same metrics (Liberation /
 * Arimo / Tinos / Cousine on Linux); if there is none, the requested name,
 * as before.
 */
public final class NativeUiFonts {
   private NativeUiFonts() {
   }

   private static final Map<String, String[]> SUBSTITUTES = new HashMap<String, String[]>();

   static {
      String[] arial = {"Arial", "Liberation Sans", "Arimo", "Helvetica"};
      String[] times = {"Times New Roman", "Liberation Serif", "Tinos", "Times"};
      String[] courier = {"Courier New", "Liberation Mono", "Cousine", "Courier"};
      SUBSTITUTES.put("dialog", arial);
      SUBSTITUTES.put("sansserif", arial);
      SUBSTITUTES.put("arial", arial);
      SUBSTITUTES.put("helvetica", arial);
      SUBSTITUTES.put("serif", times);
      SUBSTITUTES.put("times new roman", times);
      SUBSTITUTES.put("timesroman", times);
      SUBSTITUTES.put("monospaced", courier);
      SUBSTITUTES.put("dialoginput", courier);
      SUBSTITUTES.put("courier new", courier);
      SUBSTITUTES.put("courier", courier);
   }

   private static Set<String> installed;

   private static synchronized Set<String> installed() {
      if (installed == null) {
         installed = new HashSet<String>();
         try {
            for (String f : GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames(Locale.ROOT)) {
               installed.add(f.toLowerCase(Locale.ROOT));
            }
         } catch (Throwable e) {
            // no font list: the names are used as they are
         }
      }
      return installed;
   }

   /** The family the 2004 client would have got for this name, as installed here. */
   public static String family(String name) {
      if (name == null) {
         return null;
      }
      String[] subs = SUBSTITUTES.get(name.trim().toLowerCase(Locale.ROOT));
      if (subs == null || Boolean.getBoolean("openworlds.modernFonts")) {
         return name;
      }
      Set<String> have = installed();
      for (String s : subs) {
         if (have.contains(s.toLowerCase(Locale.ROOT))) {
            return s;
         }
      }
      return name;
   }

   /** new Font(name, style, size) of the decompiled client. */
   public static Font font(String name, int style, int size) {
      return new Font(family(name), style, size);
   }

   /** AWT's default component font of the 2004 JRE (Dialog, plain, 12 = Arial 12). */
   public static Font windowFont() {
      return font("Dialog", Font.PLAIN, 12);
   }
}

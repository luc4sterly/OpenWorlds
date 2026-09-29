package NET.worlds.core;

import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Locale;
import java.util.Map;
import java.util.Set;

/**
 * Plataforma, no gamma.dll: las fuentes con que el cliente de 2004 media su
 * interfaz. El JRE 1.4 de la instalacion (assets/WorldsPlayer/lib/
 * font.properties) resolvia los nombres logicos a fuentes de Windows:
 * dialog.0 y sansserif.0 = Arial, serif.0 = Times New Roman, monospaced.0 y
 * dialoginput.0 = Courier New; y Windows sustituia Helvetica por Arial
 * (FontSubstitutes). Un JDK moderno los resuelve a DejaVu Sans (Linux) o
 * Lucida Grande (macOS), mas anchas: el texto de la barra de estado no
 * cabia en su celda de 93 px ("Jse arrow keys") y otras etiquetas se
 * cortaban igual.
 *
 * build_gamma.sh (bridge/ui_fonts.py) cambia cada {@code new Font(nombre,
 * estilo, tamano)} del Java decompilado por {@link #font} y le da a
 * GammaFrame la fuente por defecto de AWT de entonces ({@link #windowFont}:
 * Dialog 12 = Arial 12). La fuente elegida es la de 2004 si esta instalada
 * (Arial en macOS y Windows) o una con sus mismas metricas (Liberation /
 * Arimo / Tinos / Cousine en Linux); si no hay ninguna, el nombre pedido,
 * como antes.
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
            // sin lista de fuentes: se usan los nombres tal cual
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

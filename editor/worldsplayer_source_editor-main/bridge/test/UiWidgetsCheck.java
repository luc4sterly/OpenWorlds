import java.io.File;
import java.lang.reflect.Method;
import java.util.List;

/**
 * Parte determinista de Cursor (0x0040bed0, 0x0040bd70), RightMenu
 * (0x00405550.., WM_COMMAND 100..199), FileSysDialog (0x004051d0) y
 * RenderCanvasOverlay (0x0043ef30). Casos calculados a mano.
 */
public class UiWidgetsCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   static Object call(String cls, String name, Class<?>[] types, Object... args) throws Exception {
      Method m = Class.forName("NET.worlds.core." + cls).getDeclaredMethod(name, types);
      m.setAccessible(true);
      return m.invoke(null, args);
   }

   @SuppressWarnings("unchecked")
   public static void main(String[] a) throws Exception {
      Class<?>[] S = {String.class};
      int arrow = (Integer) call("NativeUiCursor", "loadSystemCursor", S, "IDC_ARROW");
      check(arrow != 0 && arrow == (Integer) call("NativeUiCursor", "loadSystemCursor", S, "IDC_ARROW"), "IDC_ARROW: handle fijo distinto de 0");
      check((Integer) call("NativeUiCursor", "loadSystemCursor", S, "idc_arrow") == 0, "strcmp distingue mayusculas -> 0");
      check((Integer) call("NativeUiCursor", "loadSystemCursor", S, "IDC_HAND") == 0, "IDC_HAND no esta en la tabla de 12 -> 0");
      check((Integer) call("NativeUiCursor", "loadCursor", S, (Object) null) == 0, "loadCursor(null) -> 0 (eax=0 en 0x40bd71)");
      File cur = new File("assets/WorldsPlayer/DRAG.CUR");
      if (cur.exists()) {
         Object[] r = (Object[]) call("NativeUiCursor", "decodeCur", new Class<?>[]{byte[].class}, java.nio.file.Files.readAllBytes(cur.toPath()));
         java.awt.image.BufferedImage img = (java.awt.image.BufferedImage) r[0];
         java.awt.Point hot = (java.awt.Point) r[1];
         // entrada ICO: 20 20 00 00 | 10 00 0d 00 -> 32x32, punto caliente (16, 13)
         check(img.getWidth() == 32 && img.getHeight() == 32 && hot.x == 16 && hot.y == 13, "DRAG.CUR 32x32, punto caliente (16,13)");
         // la esquina (0,0) es la ultima fila del DIB: mascara AND a 1 y XOR 0 -> transparente
         check((img.getRGB(0, 0) >>> 24) == 0, "DRAG.CUR (0,0) transparente");
      } else {
         System.out.println("(sin assets/WorldsPlayer/DRAG.CUR: ejecutar desde la raiz del repo)");
      }

      check("Edit Properties...".equals(call("NativeUiMenu", "label", S, "Edit Properties...")), "etiqueta sin '&' igual");
      check("Save & Go".equals(call("NativeUiMenu", "label", S, "&Save && Go")), "'&S' tecla de acceso, '&&' -> '&'");
      Class<?>[] I = {int.class};
      call("NativeUiMenu", "command", I, 99);
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 0, "WM_COMMAND 99 fuera de 100..199 -> no cuenta");
      call("NativeUiMenu", "command", I, 150);
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 150, "WM_COMMAND 150 -> checkPressed 150");
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 0, "checkPressed pone DAT_0049ff2c a 0");

      List<String> pats = (List<String>) call("NativeUiFileDialog", "patterns", S, "Worlds (*.world)|*.world|Todos|*.*");
      check(pats.size() == 2 && pats.get(0).equals("*.world"), "filtros: patrones en las posiciones impares");
      Class<?>[] SL = {String.class, List.class};
      check((Boolean) call("NativeUiFileDialog", "matches", SL, "Home.WORLD", pats.subList(0, 1)), "*.world acepta Home.WORLD");
      check(!(Boolean) call("NativeUiFileDialog", "matches", SL, "a.rwx", pats.subList(0, 1)), "*.world rechaza a.rwx");
      String[] sp = (String[]) call("NativeUiFileDialog", "split", S, "C:\\x.world");
      check("C:\\".equals(sp[0]) && "x.world".equals(sp[1]), "\"C:\\x.world\" -> dir \"C:\\\" (separador tras ':'), fichero x.world");
      sp = (String[]) call("NativeUiFileDialog", "split", S, "a\\b\\c.world");
      check("a\\b".equals(sp[0]) && "c.world".equals(sp[1]), "\"a\\b\\c.world\" -> dir a\\b");
      sp = (String[]) call("NativeUiFileDialog", "split", S, "c.world");
      check(sp[0] == null && "c.world".equals(sp[1]), "sin separador: sin directorio inicial");

      Class<?>[] SZ = {int.class, int.class, int.class, int.class};
      int[] s = (int[]) call("NativeUiOverlay", "size", SZ, 641, 250, 25, 50);
      check(s[0] == 160 && s[1] == 125, "641*25*0.01 = 160.25 -> 160; 250*50*0.01 = 125");
      s = (int[]) call("NativeUiOverlay", "size", SZ, 3, 5, 50, 50);
      check(s[0] == 2 && s[1] == 2, "ROUND x87 al par: 1.5 -> 2, 2.5 -> 2");
      System.out.println(fails == 0 ? "UiWidgetsCheck: todo OK" : "UiWidgetsCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

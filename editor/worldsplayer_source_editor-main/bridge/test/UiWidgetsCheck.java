import java.io.File;
import java.lang.reflect.Method;
import java.util.List;

/**
 * Deterministic part of Cursor (0x0040bed0, 0x0040bd70), RightMenu
 * (0x00405550.., WM_COMMAND 100..199), FileSysDialog (0x004051d0) and
 * RenderCanvasOverlay (0x0043ef30). Hand-calculated cases.
 */
public class UiWidgetsCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
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
      check(arrow != 0 && arrow == (Integer) call("NativeUiCursor", "loadSystemCursor", S, "IDC_ARROW"), "IDC_ARROW: fixed handle other than 0");
      check((Integer) call("NativeUiCursor", "loadSystemCursor", S, "idc_arrow") == 0, "strcmp is case-sensitive -> 0");
      check((Integer) call("NativeUiCursor", "loadSystemCursor", S, "IDC_HAND") == 0, "IDC_HAND is not in the table of 12 -> 0");
      check((Integer) call("NativeUiCursor", "loadCursor", S, (Object) null) == 0, "loadCursor(null) -> 0 (eax=0 at 0x40bd71)");
      File cur = new File("assets/WorldsPlayer/DRAG.CUR");
      if (cur.exists()) {
         Object[] r = (Object[]) call("NativeUiCursor", "decodeCur", new Class<?>[]{byte[].class}, java.nio.file.Files.readAllBytes(cur.toPath()));
         java.awt.image.BufferedImage img = (java.awt.image.BufferedImage) r[0];
         java.awt.Point hot = (java.awt.Point) r[1];
         // ICO entry: 20 20 00 00 | 10 00 0d 00 -> 32x32, hot spot (16, 13)
         check(img.getWidth() == 32 && img.getHeight() == 32 && hot.x == 16 && hot.y == 13, "DRAG.CUR 32x32, hot spot (16,13)");
         // corner (0,0) is the last row of the DIB: AND mask at 1 and XOR 0 -> transparent
         check((img.getRGB(0, 0) >>> 24) == 0, "DRAG.CUR (0,0) transparent");
      } else {
         System.out.println("(no assets/WorldsPlayer/DRAG.CUR: run from the repo root)");
      }

      check("Edit Properties...".equals(call("NativeUiMenu", "label", S, "Edit Properties...")), "label without '&' unchanged");
      check("Save & Go".equals(call("NativeUiMenu", "label", S, "&Save && Go")), "'&S' access key, '&&' -> '&'");
      Class<?>[] I = {int.class};
      call("NativeUiMenu", "command", I, 99);
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 0, "WM_COMMAND 99 outside 100..199 -> does not count");
      call("NativeUiMenu", "command", I, 150);
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 150, "WM_COMMAND 150 -> checkPressed 150");
      check((Integer) call("NativeUiMenu", "checkPressed", new Class<?>[0]) == 0, "checkPressed sets DAT_0049ff2c to 0");

      List<String> pats = (List<String>) call("NativeUiFileDialog", "patterns", S, "Worlds (*.world)|*.world|All|*.*");
      check(pats.size() == 2 && pats.get(0).equals("*.world"), "filters: patterns at the odd positions");
      Class<?>[] SL = {String.class, List.class};
      check((Boolean) call("NativeUiFileDialog", "matches", SL, "Home.WORLD", pats.subList(0, 1)), "*.world accepts Home.WORLD");
      check(!(Boolean) call("NativeUiFileDialog", "matches", SL, "a.rwx", pats.subList(0, 1)), "*.world rejects a.rwx");
      String[] sp = (String[]) call("NativeUiFileDialog", "split", S, "C:\\x.world");
      check("C:\\".equals(sp[0]) && "x.world".equals(sp[1]), "\"C:\\x.world\" -> dir \"C:\\\" (separator after ':'), file x.world");
      sp = (String[]) call("NativeUiFileDialog", "split", S, "a\\b\\c.world");
      check("a\\b".equals(sp[0]) && "c.world".equals(sp[1]), "\"a\\b\\c.world\" -> dir a\\b");
      sp = (String[]) call("NativeUiFileDialog", "split", S, "c.world");
      check(sp[0] == null && "c.world".equals(sp[1]), "no separator: no initial directory");

      Class<?>[] SZ = {int.class, int.class, int.class, int.class};
      int[] s = (int[]) call("NativeUiOverlay", "size", SZ, 641, 250, 25, 50);
      check(s[0] == 160 && s[1] == 125, "641*25*0.01 = 160.25 -> 160; 250*50*0.01 = 125");
      s = (int[]) call("NativeUiOverlay", "size", SZ, 3, 5, 50, 50);
      check(s[0] == 2 && s[1] == 2, "x87 ROUND to even: 1.5 -> 2, 2.5 -> 2");
      System.out.println(fails == 0 ? "UiWidgetsCheck: all OK" : "UiWidgetsCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

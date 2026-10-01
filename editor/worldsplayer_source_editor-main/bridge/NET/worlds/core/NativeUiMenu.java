package NET.worlds.core;

import java.awt.Component;
import java.awt.MenuItem;
import java.awt.Point;
import java.awt.PopupMenu;
import java.util.ArrayList;
import java.util.List;

/**
 * Context menu (RightMenu, 0x00405550..0x00405670) with an AWT
 * {@link PopupMenu} instead of Win32's HMENU.
 *
 * <ul>
 * <li>create (0x004055e0): CreatePopupMenu -&gt; handle.
 * <li>nativeAdd (0x00405550): AppendMenuA(MF_STRING, id, text); if it fails
 * (invalid handle), assertion "nRightMenu" line 0x20.
 * <li>addSeparator (0x004055b0): AppendMenuA(MF_SEPARATOR); assertion 0x27.
 * <li>show (0x004055f0): DAT_0049ff2c = 0, DAT_004890b0 = menu and
 * SendMessage(hwnd, 0x4c8) -&gt; FUN_00405670: GetCursorPos and
 * TrackPopupMenu(menu, TPM_RIGHTBUTTON, x, y, hwnd). The choice arrives as
 * WM_COMMAND and the WndProc (0x0040c970) stores it in DAT_0049ff2c only if
 * the id is between 100 and 199.
 * <li>discard (0x00405620): DestroyMenu if not 0; assertion 0x3c if it fails.
 * <li>checkPressed (0x00405650): returns DAT_0049ff2c and sets it to 0.
 * </ul>
 * TrackPopupMenu blocks until the menu is closed; here the menu is
 * shown on the AWT thread and show returns earlier. It changes nothing: the
 * client polls checkPressed on every mainCallback and does nothing in between.
 */
public final class NativeUiMenu {
   private NativeUiMenu() {
   }

   private static final List<PopupMenu> menus = new ArrayList<PopupMenu>();
   /** DAT_0049ff2c. */
   private static volatile int pressed;

   public static synchronized int create() {
      menus.add(new PopupMenu());
      return menus.size();
   }

   static synchronized PopupMenu get(int h) {
      return h >= 1 && h <= menus.size() ? menus.get(h - 1) : null;
   }

   /**
    * Win32 menu text: '&amp;' marks the access key (the following letter is
    * underlined, AWT has no such underline) and "&amp;&amp;" is a literal
    * '&amp;'.
    */
   static String label(String s) {
      StringBuilder b = new StringBuilder();
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         if (c == '&') {
            if (i + 1 < s.length() && s.charAt(i + 1) == '&') {
               b.append('&');
               i++;
            }
            continue;
         }
         b.append(c);
      }
      return b.toString();
   }

   public static void add(String text, final int id, int menu) {
      PopupMenu m = get(menu);
      if (m == null) {
         NativeAssert.fail("nRightMenu", 0x20);
         return;
      }
      MenuItem it = new MenuItem(label(text == null ? "" : text));
      it.addActionListener(new java.awt.event.ActionListener() {
         public void actionPerformed(java.awt.event.ActionEvent e) {
            command(id);
         }
      });
      m.add(it);
   }

   public static void addSeparator(int menu) {
      PopupMenu m = get(menu);
      if (m == null) {
         NativeAssert.fail("nRightMenu", 0x27);
         return;
      }
      m.addSeparator();
   }

   /** WM_COMMAND in the WndProc 0x0040c970: only ids 100..199. */
   static void command(int id) {
      if (id > 99 && id < 200) {
         pressed = id & 0xffff;
      }
   }

   public static void show(int hwnd, int menu) {
      pressed = 0;
      final PopupMenu m = get(menu);
      final Component c = NativeWindows.component(hwnd);
      if (m == null || c == null) {
         // TrackPopupMenu fails with an invalid menu or window: the original
         // writes it to the log and asserts "nRightMenu" line 0x4e
         System.err.println("Error from TrackPopupMenu: menu " + menu + " window " + hwnd);
         NativeAssert.fail("nRightMenu", 0x4e);
         return;
      }
      java.awt.EventQueue.invokeLater(new Runnable() {
         public void run() {
            if (m.getParent() != c) {
               c.add(m);
            }
            Point p = java.awt.MouseInfo.getPointerInfo().getLocation();
            Point o = c.getLocationOnScreen();
            m.show(c, p.x - o.x, p.y - o.y);
         }
      });
   }

   public static void discard(int menu) {
      if (menu == 0) {
         return;
      }
      final PopupMenu m = get(menu);
      if (m == null) {
         NativeAssert.fail("nRightMenu", 0x3c);
         return;
      }
      synchronized (NativeUiMenu.class) {
         menus.set(menu - 1, null);
      }
      java.awt.EventQueue.invokeLater(new Runnable() {
         public void run() {
            java.awt.MenuContainer parent = m.getParent();
            if (parent instanceof Component) {
               ((Component) parent).remove(m);
            }
         }
      });
   }

   public static int checkPressed() {
      int v = pressed;
      pressed = 0;
      return v;
   }
}

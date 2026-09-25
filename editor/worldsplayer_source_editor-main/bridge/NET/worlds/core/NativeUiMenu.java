package NET.worlds.core;

import java.awt.Component;
import java.awt.MenuItem;
import java.awt.Point;
import java.awt.PopupMenu;
import java.util.ArrayList;
import java.util.List;

/**
 * Menu contextual (RightMenu, 0x00405550..0x00405670) con un
 * {@link PopupMenu} de AWT en lugar del HMENU de Win32.
 *
 * <ul>
 * <li>create (0x004055e0): CreatePopupMenu -&gt; handle.
 * <li>nativeAdd (0x00405550): AppendMenuA(MF_STRING, id, texto); si falla
 * (handle no valido), asercion "nRightMenu" linea 0x20.
 * <li>addSeparator (0x004055b0): AppendMenuA(MF_SEPARATOR); asercion 0x27.
 * <li>show (0x004055f0): DAT_0049ff2c = 0, DAT_004890b0 = menu y
 * SendMessage(hwnd, 0x4c8) -&gt; FUN_00405670: GetCursorPos y
 * TrackPopupMenu(menu, TPM_RIGHTBUTTON, x, y, hwnd). La eleccion llega como
 * WM_COMMAND y la WndProc (0x0040c970) la guarda en DAT_0049ff2c solo si
 * el id esta entre 100 y 199.
 * <li>discard (0x00405620): DestroyMenu si no es 0; asercion 0x3c si falla.
 * <li>checkPressed (0x00405650): devuelve DAT_0049ff2c y lo pone a 0.
 * </ul>
 * TrackPopupMenu bloquea hasta que se cierra el menu; aqui el menu se
 * muestra en el hilo de AWT y show vuelve antes. No cambia nada: el cliente
 * sondea checkPressed en cada mainCallback y no hace nada entre medias.
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
    * Texto de menu de Win32: '&amp;' marca la tecla de acceso (se subraya la
    * letra siguiente, AWT no tiene ese subrayado) y "&amp;&amp;" es un '&amp;'
    * literal.
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

   /** WM_COMMAND en la WndProc 0x0040c970: solo ids 100..199. */
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
         // TrackPopupMenu falla con un menu o ventana no validos: el original
         // lo escribe en el log y afirma "nRightMenu" linea 0x4e
         System.err.println("Error from TrackPopupMenu: menu " + menu + " ventana " + hwnd);
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

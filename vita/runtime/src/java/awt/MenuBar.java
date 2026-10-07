package java.awt;

import java.awt.event.KeyEvent;
import java.util.Enumeration;
import java.util.Vector;

/** A frame's menu bar, as java.awt.MenuBar (drawn by {@link MenuWindow#paintMenuBar}). */
public class MenuBar extends MenuComponent implements MenuContainer {
   Vector<Menu> menus = new Vector<Menu>();
   Menu helpMenu;

   private static int nameCounter;

   public MenuBar() {
   }

   String constructComponentName() {
      synchronized (MenuBar.class) {
         return "menubar" + nameCounter++;
      }
   }

   public void addNotify() {
      synchronized (getTreeLock()) {
         displayable = true;
         int n = getMenuCount();
         for (int i = 0; i < n; i++) {
            getMenu(i).addNotify();
         }
      }
   }

   public void removeNotify() {
      synchronized (getTreeLock()) {
         int n = getMenuCount();
         for (int i = 0; i < n; i++) {
            getMenu(i).removeNotify();
         }
         super.removeNotify();
      }
   }

   public Menu getHelpMenu() {
      return helpMenu;
   }

   public void setHelpMenu(Menu m) {
      synchronized (getTreeLock()) {
         if (helpMenu == m) {
            return;
         }
         if (helpMenu != null) {
            remove(helpMenu);
         }
         if (m != null && m.parent != this) {
            add(m);
         }
         helpMenu = m;
         if (m != null) {
            m.isHelpMenu = true;
            m.parent = this;
         }
      }
      barChanged();
   }

   public Menu add(Menu m) {
      synchronized (getTreeLock()) {
         if (m.parent != null) {
            m.parent.remove(m);
         }
         menus.addElement(m);
         m.parent = this;
         if (displayable && !m.displayable) {
            m.addNotify();
         }
      }
      barChanged();
      return m;
   }

   public void remove(int index) {
      synchronized (getTreeLock()) {
         Menu m = getMenu(index);
         menus.removeElementAt(index);
         if (displayable) {
            m.removeNotify();
            m.parent = null;
         }
         if (helpMenu == m) {
            helpMenu = null;
            m.isHelpMenu = false;
         }
      }
      barChanged();
      PopupWindow.menusChanged();
   }

   public void remove(MenuComponent m) {
      synchronized (getTreeLock()) {
         int index = menus.indexOf(m);
         if (index >= 0) {
            remove(index);
         }
      }
   }

   public int getMenuCount() {
      return countMenus();
   }

   /** @deprecated */
   @Deprecated
   public int countMenus() {
      return menus.size();
   }

   public Menu getMenu(int i) {
      return menus.elementAt(i);
   }

   public synchronized Enumeration<MenuShortcut> shortcuts() {
      Vector<MenuShortcut> shortcuts = new Vector<MenuShortcut>();
      int nmenus = getMenuCount();
      for (int i = 0; i < nmenus; i++) {
         collectShortcuts(getMenu(i), shortcuts);
      }
      return shortcuts.elements();
   }

   private static void collectShortcuts(Menu m, Vector<MenuShortcut> out) {
      int n = m.getItemCount();
      for (int i = 0; i < n; i++) {
         MenuItem mi = m.getItem(i);
         if (mi instanceof Menu) {
            collectShortcuts((Menu) mi, out);
         } else if (mi.getShortcut() != null) {
            out.addElement(mi.getShortcut());
         }
      }
   }

   public MenuItem getShortcutMenuItem(MenuShortcut s) {
      int nmenus = getMenuCount();
      for (int i = 0; i < nmenus; i++) {
         MenuItem mi = getMenu(i).getShortcutMenuItem(s);
         if (mi != null) {
            return mi;
         }
      }
      return null;
   }

   /** As the JDK: only with the menu shortcut key (Ctrl) down. */
   boolean handleShortcut(KeyEvent e) {
      int id = e.getID();
      if (id != KeyEvent.KEY_PRESSED && id != KeyEvent.KEY_RELEASED) {
         return false;
      }
      int accelKey = Toolkit.getDefaultToolkit().getMenuShortcutKeyMask();
      if ((e.getModifiers() & accelKey) == 0) {
         return false;
      }
      int nmenus = getMenuCount();
      for (int i = 0; i < nmenus; i++) {
         Menu m = getMenu(i);
         if (m.handleShortcut(e)) {
            return true;
         }
      }
      return false;
   }

   public void deleteShortcut(MenuShortcut s) {
      int nmenus = getMenuCount();
      for (int i = 0; i < nmenus; i++) {
         getMenu(i).deleteShortcut(s);
      }
   }

   /** Windows redrew the bar after a change (DrawMenuBar). */
   void barChanged() {
      MenuContainer p = parent;
      if (p instanceof Frame) {
         WindowSystem.decorationsChanged((Frame) p);
      }
   }
}

package java.awt;

import java.awt.event.KeyEvent;
import java.util.Vector;

/** A menu of items (and submenus), as java.awt.Menu. */
public class Menu extends MenuItem implements MenuContainer {
   Vector<MenuItem> items = new Vector<MenuItem>();
   boolean tearOff;
   boolean isHelpMenu;

   private static int nameCounter;

   public Menu() {
      this("", false);
   }

   public Menu(String label) {
      this(label, false);
   }

   public Menu(String label, boolean tearOff) {
      super(label);
      this.tearOff = tearOff;
   }

   String constructComponentName() {
      synchronized (Menu.class) {
         return "menu" + nameCounter++;
      }
   }

   public void addNotify() {
      synchronized (getTreeLock()) {
         displayable = true;
         int n = getItemCount();
         for (int i = 0; i < n; i++) {
            MenuItem mi = getItem(i);
            mi.parent = this;
            mi.addNotify();
         }
      }
   }

   public void removeNotify() {
      synchronized (getTreeLock()) {
         int n = getItemCount();
         for (int i = 0; i < n; i++) {
            getItem(i).removeNotify();
         }
         super.removeNotify();
      }
   }

   public boolean isTearOff() {
      return tearOff;
   }

   public int getItemCount() {
      return countItems();
   }

   /** @deprecated */
   @Deprecated
   public int countItems() {
      return items.size();
   }

   public MenuItem getItem(int index) {
      return items.elementAt(index);
   }

   public MenuItem add(MenuItem mi) {
      synchronized (getTreeLock()) {
         if (mi.parent != null) {
            mi.parent.remove(mi);
         }
         items.addElement(mi);
         mi.parent = this;
         if (displayable) {
            mi.addNotify();
         }
      }
      changed();
      return mi;
   }

   public void add(String label) {
      add(new MenuItem(label));
   }

   public void insert(MenuItem menuitem, int index) {
      synchronized (getTreeLock()) {
         if (index < 0) {
            throw new IllegalArgumentException("index less than zero.");
         }
         int nitems = getItemCount();
         Vector<MenuItem> tempItems = new Vector<MenuItem>();
         // as the JDK: the items from index on come out and go back after the new one
         for (int i = index; i < nitems; i++) {
            tempItems.addElement(getItem(index));
            remove(index);
         }
         add(menuitem);
         for (int i = 0; i < tempItems.size(); i++) {
            add(tempItems.elementAt(i));
         }
      }
   }

   public void insert(String label, int index) {
      insert(new MenuItem(label), index);
   }

   public void addSeparator() {
      add("-");
   }

   public void insertSeparator(int index) {
      synchronized (getTreeLock()) {
         if (index < 0) {
            throw new IllegalArgumentException("index less than zero.");
         }
         int nitems = getItemCount();
         Vector<MenuItem> tempItems = new Vector<MenuItem>();
         for (int i = index; i < nitems; i++) {
            tempItems.addElement(getItem(index));
            remove(index);
         }
         addSeparator();
         for (int i = 0; i < tempItems.size(); i++) {
            add(tempItems.elementAt(i));
         }
      }
   }

   public void remove(int index) {
      synchronized (getTreeLock()) {
         MenuItem mi = getItem(index);
         items.removeElementAt(index);
         // as the JDK, which only did this when the menu had a peer
         if (displayable) {
            mi.removeNotify();
            mi.parent = null;
         }
      }
      changed();
   }

   public void remove(MenuComponent item) {
      synchronized (getTreeLock()) {
         int index = items.indexOf(item);
         if (index >= 0) {
            remove(index);
         }
      }
   }

   public void removeAll() {
      synchronized (getTreeLock()) {
         int nitems = getItemCount();
         for (int i = nitems - 1; i >= 0; i--) {
            remove(i);
         }
      }
   }

   boolean handleShortcut(KeyEvent e) {
      int nitems = getItemCount();
      for (int i = 0; i < nitems; i++) {
         MenuItem item = getItem(i);
         if (item.handleShortcut(e)) {
            return true;
         }
      }
      return false;
   }

   MenuItem getShortcutMenuItem(MenuShortcut s) {
      int nitems = getItemCount();
      for (int i = 0; i < nitems; i++) {
         MenuItem mi = getItem(i).getShortcutMenuItem(s);
         if (mi != null) {
            return mi;
         }
      }
      return null;
   }

   void deleteShortcut(MenuShortcut s) {
      int nitems = getItemCount();
      for (int i = 0; i < nitems; i++) {
         getItem(i).deleteShortcut(s);
      }
   }

   /** A Menu is never a separator, whatever its label. */
   boolean isSeparator() {
      return false;
   }

   public String paramString() {
      return super.paramString() + ",tearOff=" + tearOff + ",isHelpMenu=" + isHelpMenu;
   }
}

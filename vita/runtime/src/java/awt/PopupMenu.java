package java.awt;

/**
 * A menu shown at a point of a component, as java.awt.PopupMenu. As on
 * Windows (TrackPopupMenu), show() returns once the menu is closed; on the
 * event dispatch thread other events keep being dispatched meanwhile.
 */
public class PopupMenu extends Menu {
   private static int nameCounter;

   public PopupMenu() {
      this("");
   }

   public PopupMenu(String label) {
      super(label);
   }

   String constructComponentName() {
      synchronized (PopupMenu.class) {
         return "popup" + nameCounter++;
      }
   }

   public MenuContainer getParent() {
      return super.getParent();
   }

   public void addNotify() {
      synchronized (getTreeLock()) {
         // a PopupMenu whose parent is not a Component is a plain Menu
         super.addNotify();
      }
   }

   public void show(Component origin, int x, int y) {
      MenuContainer localParent = parent;
      if (localParent == null) {
         throw new NullPointerException("parent is null");
      }
      if (!(localParent instanceof Component)) {
         throw new IllegalArgumentException("PopupMenus with non-Component parents cannot be shown");
      }
      Component compParent = (Component) localParent;
      if (compParent != origin && compParent instanceof Container && !((Container) compParent).isAncestorOf(origin)) {
         throw new IllegalArgumentException("origin not in parent's hierarchy");
      }
      if (!compParent.displayable || !compParent.isShowing()) {
         throw new RuntimeException("parent not showing on screen");
      }
      if (!displayable) {
         addNotify();
      }
      Point p = origin.locationOnScreen();
      final MenuWindow shown = MenuWindow.showPopup(this, origin, p.x + x, p.y + y);
      if (shown == null) {
         return;
      }
      if (EventQueue.isDispatchThread()) {
         EventQueue.pumpWhile(new EventQueue.Condition() {
            public boolean holds() {
               return shown.isOpen();
            }
         });
      } else {
         shown.awaitClosed();
      }
   }
}

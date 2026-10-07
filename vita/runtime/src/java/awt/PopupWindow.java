package java.awt;

import java.awt.event.PaintEvent;
import java.util.ArrayList;

/**
 * A window that pops up over the others and takes the pointer and the keys
 * while it is open: menus ({@link MenuWindow}) and a Choice's list
 * ({@link ChoiceList}), Windows' modal menu loop.
 *
 * They run on WindowSystem's input thread, as Windows ran menus on the
 * toolkit thread: a thread waiting in PopupMenu.show() (Windows' show()
 * returned only once the menu closed) never stops them, the event thread
 * included. Their state is guarded by {@link #POPUP}. Rule: nothing done
 * while holding POPUP takes the AWT tree lock, because client code calls in
 * here (Menu.add, PopupMenu.show...) while holding the tree lock.
 */
abstract class PopupWindow extends Window {
   static final Object POPUP = new Object();
   /** Open popups, the root first. Guarded by POPUP. */
   private static final ArrayList<PopupWindow> open = new ArrayList<PopupWindow>();
   private static volatile int openCount;

   /** The window of the component that opened the root popup. */
   Window invoker;
   private volatile boolean isOpen;

   PopupWindow() {
      super();
      // not one of the application's windows (Window.getWindows)
      synchronized (allWindows) {
         allWindows.remove(this);
      }
      focusableWindowState = false;
   }

   static boolean anyOpen() {
      return openCount > 0;
   }

   boolean isOpen() {
      return isOpen;
   }

   /** The root popup, or null. Under POPUP. */
   static PopupWindow root() {
      return open.isEmpty() ? null : open.get(0);
   }

   /** The popup opened last, or null. Under POPUP. */
   static PopupWindow top() {
      return open.isEmpty() ? null : open.get(open.size() - 1);
   }

   static PopupWindow[] openPopups() {
      return open.toArray(new PopupWindow[open.size()]);
   }

   /** Shows this popup with these screen bounds over every other window. Under POPUP. */
   void popUp(int sx, int sy, int w, int h) {
      x = sx;
      y = sy;
      width = Math.max(1, w);
      height = Math.max(1, h);
      // no addNotify (it takes the tree lock): a popup needs nothing of it
      displayable = true;
      valid = true;
      if (background == null) {
         background = Theme.CONTROL;
      }
      if (foreground == null) {
         foreground = Color.black;
      }
      if (font == null) {
         font = Theme.MENU_FONT;
      }
      visible = true;
      isOpen = true;
      open.add(this);
      openCount = open.size();
      WindowSystem.windowShown(this);
      paintSelf();
   }

   /** Moves or resizes an open popup. Under POPUP. */
   void moveTo(int sx, int sy, int w, int h) {
      if (sx == x && sy == y && w == width && h == height) {
         paintSelf();
         return;
      }
      Rectangle old = new Rectangle(x, y, width, height);
      x = sx;
      y = sy;
      width = Math.max(1, w);
      height = Math.max(1, h);
      WindowSystem.windowBoundsChanged(this, old, old.width != width || old.height != height);
      paintSelf();
   }

   /** Closes this popup and the ones opened from it. Under POPUP. */
   void popDown() {
      int i = open.indexOf(this);
      if (i < 0) {
         return;
      }
      while (open.size() > i) {
         PopupWindow p = open.remove(open.size() - 1);
         openCount = open.size();
         p.isOpen = false;
         p.visible = false;
         WindowSystem.windowHidden(p);
         p.displayable = false;
         p.pixels = null;
         p.closed();
      }
      POPUP.notifyAll();
      EventQueue.wakeUp();
   }

   /** Called once closed (under POPUP). */
   void closed() {
   }

   /** Waits (not on the event thread) until this popup is closed. */
   void awaitClosed() {
      synchronized (POPUP) {
         while (isOpen) {
            try {
               POPUP.wait();
            } catch (InterruptedException e) {
               Thread.currentThread().interrupt();
               return;
            }
         }
      }
   }

   static void closeAll() {
      synchronized (POPUP) {
         closeAllLocked();
      }
   }

   static void closeAllLocked() {
      PopupWindow r = root();
      if (r != null) {
         r.popDown();
      }
   }

   /** A window other than a popup went away: the popups it opened go too. */
   static void windowGone(Window w) {
      if (openCount == 0) {
         return;
      }
      synchronized (POPUP) {
         PopupWindow r = root();
         if (r != null && (r.invoker == w || r.invoker == null)) {
            r.popDown();
         }
      }
   }

   /** Something a menu shows changed: the open menus are measured and drawn again. */
   static void menusChanged() {
      if (openCount == 0) {
         return;
      }
      synchronized (POPUP) {
         for (PopupWindow p : openPopups()) {
            if (p.isOpen) {
               p.contentChanged();
            }
         }
      }
   }

   void contentChanged() {
      paintSelf();
   }

   /** Draws the popup now, on this thread. Under POPUP. */
   void paintSelf() {
      if (isOpen) {
         WindowSystem.paintNow(this, null, false);
      }
   }

   // ------------------------------------------------------------- input (input thread)

   static void pointer(int id, int sx, int sy, int button, int modifiers, long when) {
      synchronized (POPUP) {
         PopupWindow r = root();
         if (r != null) {
            r.rootPointer(popupAt(sx, sy), id, sx, sy, button, modifiers, when);
         }
      }
   }

   static void key(boolean press, int keyCode, char keyChar, int modifiers) {
      synchronized (POPUP) {
         PopupWindow r = root();
         if (r != null) {
            r.rootKey(press, keyCode, keyChar, modifiers);
         }
      }
   }

   static void wheel(int sx, int sy, int rotation) {
      synchronized (POPUP) {
         PopupWindow r = root();
         if (r != null) {
            PopupWindow at = popupAt(sx, sy);
            r.rootWheel(at != null ? at : top(), rotation);
         }
      }
   }

   private static PopupWindow popupAt(int sx, int sy) {
      for (int i = open.size() - 1; i >= 0; i--) {
         PopupWindow p = open.get(i);
         if (sx >= p.x && sy >= p.y && sx < p.x + p.width && sy < p.y + p.height) {
            return p;
         }
      }
      return null;
   }

   /** A pointer event while popups are open (at: the popup under it, or null). */
   abstract void rootPointer(PopupWindow at, int id, int sx, int sy, int button, int modifiers, long when);

   abstract void rootKey(boolean press, int keyCode, char keyChar, int modifiers);

   abstract void rootWheel(PopupWindow at, int rotation);

   // ------------------------------------------------------------- as a window

   /** Paint events (from showing or resizing) draw it; nothing else reaches a popup. */
   void dispatchEventImpl(AWTEvent e) {
      if (e instanceof PaintEvent) {
         synchronized (POPUP) {
            paintSelf();
         }
      }
   }

   boolean callsPaint() {
      return false;
   }

   /** No children, and no tree lock (see the class comment). */
   public Component[] getComponents() {
      return new Component[0];
   }

   public int countComponents() {
      return 0;
   }

   public boolean isShowing() {
      return isOpen && super.isShowing();
   }

   public void show() {
      throw new UnsupportedOperationException("popups are opened by their menu or choice");
   }

   static Dimension screenSize() {
      return WindowSystem.screenSize();
   }
}

package java.awt;

import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

import net.openworlds.awt.Screen;

/**
 * What the native window system did for the JDK's AWT: windows on the
 * screen and their order, composing their pixels into the screen, painting
 * components into their window, and turning the screen's input (touch,
 * buttons, a mouse, a keyboard) into AWT events for the component under the
 * pointer or with the focus.
 *
 * There is one screen and no real windows: a Frame fills the screen (the
 * Vita's 960x544, or a window of that size on Linux), dialogs and menus are
 * drawn over it.
 */
final class WindowSystem {
   private WindowSystem() {
   }

   private static final Object LOCK = new Object();
   private static Screen screen;
   private static int screenWidth;
   private static int screenHeight;
   private static int[] composed;
   /** Bottom to top. */
   private static final ArrayList<Window> stack = new ArrayList<Window>();
   private static Rectangle dirty;
   private static Window active;
   private static final int DESKTOP = 0xFF000000;

   static void init() {
      synchronized (LOCK) {
         if (screen != null) {
            return;
         }
         screen = Screen.get();
         screenWidth = screen.width();
         screenHeight = screen.height();
         composed = new int[screenWidth * screenHeight];
         java.util.Arrays.fill(composed, DESKTOP);
         dirty = new Rectangle(0, 0, screenWidth, screenHeight);
         Thread compositor = new Thread("AWT-Screen") {
            public void run() {
               composeLoop();
            }
         };
         compositor.setDaemon(true);
         compositor.start();
         Thread input = new Thread("AWT-Input") {
            public void run() {
               inputLoop();
            }
         };
         input.setDaemon(true);
         input.start();
      }
   }

   static Dimension screenSize() {
      init();
      return new Dimension(screenWidth, screenHeight);
   }

   static Screen screen() {
      init();
      return screen;
   }

   // ------------------------------------------------------------------ windows

   static boolean isOnScreen(Window w) {
      synchronized (LOCK) {
         return stack.contains(w);
      }
   }

   static boolean noWindowsLeft() {
      synchronized (LOCK) {
         if (!stack.isEmpty()) {
            return false;
         }
      }
      for (Window w : Window.getWindows()) {
         if (w.displayable) {
            return false;
         }
      }
      return true;
   }

   static Window activeWindow() {
      return active;
   }

   static Window[] windowsOnScreen() {
      synchronized (LOCK) {
         return stack.toArray(new Window[stack.size()]);
      }
   }

   static void windowShown(Window w) {
      init();
      fitOnScreen(w);
      ensurePixels(w);
      synchronized (LOCK) {
         stack.remove(w);
         insertOnTop(w);
      }
      EventQueue.postPaint(w, new Rectangle(0, 0, w.width, w.height));
      damageScreen(w.x, w.y, w.width, w.height);
      if (w.focusableWindowState && !(w instanceof PopupWindow)) {
         activate(w);
      }
   }

   private static void insertOnTop(Window w) {
      int i = stack.size();
      if (!w.alwaysOnTop && !(w instanceof PopupWindow)) {
         while (i > 0 && (stack.get(i - 1).alwaysOnTop || stack.get(i - 1) instanceof PopupWindow)) {
            i--;
         }
      }
      stack.add(i, w);
   }

   /**
    * One screen: a Frame takes all of it (the 2004 client's main window was
    * as big as the desktop allowed); other windows are kept on it, centred if
    * they do not fit.
    */
   private static void fitOnScreen(Window w) {
      if (w instanceof PopupWindow) {
         // placed by their menu or choice, and they must not take the tree lock (setBounds)
         return;
      }
      int nx = w.x;
      int ny = w.y;
      int nw = w.width;
      int nh = w.height;
      if (w instanceof Frame && !((Frame) w).undecorated) {
         nx = 0;
         ny = 0;
         nw = screenWidth;
         nh = screenHeight;
      } else {
         if (nw > screenWidth) {
            nw = screenWidth;
         }
         if (nh > screenHeight) {
            nh = screenHeight;
         }
         if (nx < 0 || nx + nw > screenWidth) {
            nx = Math.max(0, (screenWidth - nw) / 2);
         }
         if (ny < 0 || ny + nh > screenHeight) {
            ny = Math.max(0, (screenHeight - nh) / 2);
         }
      }
      if (nx != w.x || ny != w.y || nw != w.width || nh != w.height) {
         w.setBounds(nx, ny, nw, nh);
         w.validate();
      }
   }

   static void windowHidden(Window w) {
      if (!(w instanceof PopupWindow)) {
         PopupWindow.windowGone(w);
      }
      boolean wasActive;
      synchronized (LOCK) {
         if (!stack.remove(w)) {
            return;
         }
         wasActive = active == w;
      }
      damageScreen(w.x, w.y, w.width, w.height);
      if (pressedWindow == w) {
         pressed = null;
         pressedWindow = null;
      }
      if (hovered != null && hovered.windowAncestor() == w) {
         hovered = null;
      }
      if (wasActive) {
         activate(topFocusable());
      }
   }

   private static Window topFocusable() {
      synchronized (LOCK) {
         for (int i = stack.size() - 1; i >= 0; i--) {
            Window w = stack.get(i);
            if (w.focusableWindowState && !(w instanceof PopupWindow)) {
               return w;
            }
         }
      }
      return null;
   }

   static void windowToFront(Window w) {
      synchronized (LOCK) {
         if (!stack.remove(w)) {
            return;
         }
         insertOnTop(w);
      }
      damageScreen(w.x, w.y, w.width, w.height);
      if (w.focusableWindowState && !(w instanceof PopupWindow)) {
         activate(w);
      }
   }

   static void windowToBack(Window w) {
      synchronized (LOCK) {
         if (!stack.remove(w)) {
            return;
         }
         stack.add(0, w);
      }
      damageScreen(w.x, w.y, w.width, w.height);
      if (active == w) {
         activate(topFocusable());
      }
   }

   static void activate(Window w) {
      if (w != null && modalBlocker(w) != null) {
         w = modalBlocker(w);
      }
      synchronized (LOCK) {
         if (active == w) {
            return;
         }
         active = w;
      }
      KeyboardFocusManager.getCurrentKeyboardFocusManager().activeWindowChanged(w);
   }

   static void windowBoundsChanged(Window w, Rectangle old, boolean resized) {
      if (!isOnScreen(w)) {
         return;
      }
      if (resized) {
         ensurePixels(w);
         EventQueue.postPaint(w, new Rectangle(0, 0, w.width, w.height));
      }
      damageScreen(old.x, old.y, old.width, old.height);
      damageScreen(w.x, w.y, w.width, w.height);
   }

   static void decorationsChanged(Window w) {
      if (w.isShowing()) {
         Insets in = w.getInsets();
         w.repaint(0, 0, w.width, Math.max(in.top, 1));
      }
   }

   private static void ensurePixels(Window w) {
      int pw = Math.max(1, w.width);
      int ph = Math.max(1, w.height);
      synchronized (w) {
         if (w.pixels == null || w.pixelsWidth != pw || w.pixelsHeight != ph) {
            int[] p = new int[pw * ph];
            Color bg = w.getBackground();
            java.util.Arrays.fill(p, bg != null ? bg.getRGB() | 0xFF000000 : 0xFFD4D0C8);
            w.pixels = p;
            w.pixelsWidth = pw;
            w.pixelsHeight = ph;
         }
      }
   }

   /** A modal dialog that keeps the input away from this window, or null. */
   static Window modalBlocker(Window target) {
      synchronized (LOCK) {
         for (int i = stack.size() - 1; i >= 0; i--) {
            Window w = stack.get(i);
            if (w instanceof Dialog && ((Dialog) w).modal && w != target && !ownedBy(target, w)) {
               return w;
            }
         }
      }
      return null;
   }

   private static boolean ownedBy(Window w, Window owner) {
      for (Window o = w.owner; o != null; o = o.owner) {
         if (o == owner) {
            return true;
         }
      }
      return false;
   }

   // ------------------------------------------------------------------ painting

   /** The area of a window that its client draws on (inside the decorations), in the window's pixels. */
   private static Rectangle clientArea(Window w) {
      Insets in = w.getInsets();
      return new Rectangle(in.left, in.top, w.width - in.left - in.right, w.height - in.top - in.bottom);
   }

   /** Paints a component and what is on it within area (its own coordinates), on the event thread. */
   static void paintNow(Component c, Rectangle area, boolean update) {
      if (!c.isShowing()) {
         return;
      }
      Window w = c.windowAncestor();
      if (w == null) {
         return;
      }
      ensurePixels(w);
      Point o = c.originInWindow();
      Rectangle r = area == null ? new Rectangle(o.x, o.y, c.width, c.height) : new Rectangle(o.x + area.x, o.y + area.y, area.width, area.height);
      r = r.intersection(c.visibleInWindow());
      if (r.width <= 0 || r.height <= 0) {
         return;
      }
      paintComponent(w, c, r, update);
      damage(w, r.x, r.y, r.width, r.height);
   }

   /** area is in the window's pixels and inside c. */
   private static void paintComponent(Window w, Component c, Rectangle area, boolean update) {
      Point o = c.originInWindow();
      SurfaceGraphics g = new SurfaceGraphics(w, o.x, o.y, area);
      g.setColor(c.getForeground());
      g.setFont(c.getFont());
      g.setBackground(c.getBackground());
      try {
         c.paintPeer(g);
      } catch (RuntimeException e) {
         e.printStackTrace();
      }
      if (c.callsPaint()) {
         Rectangle client = area;
         if (c instanceof Window) {
            client = area.intersection(clientArea((Window) c));
         } else if (c instanceof ScrollPane) {
            // the edge and the bars are the native control's (its non-client area)
            Rectangle v = ((ScrollPane) c).viewport();
            client = area.intersection(new Rectangle(o.x + v.x, o.y + v.y, v.width, v.height));
         }
         if (client.width > 0 && client.height > 0) {
            SurfaceGraphics pg = new SurfaceGraphics(w, o.x, o.y, client);
            pg.setColor(c.getForeground());
            pg.setFont(c.getFont());
            pg.setBackground(c.getBackground());
            try {
               if (update) {
                  c.update(pg);
               } else {
                  if (erasesBackground(c)) {
                     pg.clearRect(0, 0, c.width, c.height);
                  }
                  c.paint(pg);
               }
            } catch (RuntimeException e) {
               System.err.println("Exception while painting " + c.getClass().getName() + ": " + e);
               e.printStackTrace();
            } finally {
               pg.dispose();
            }
         }
      }
      g.dispose();
      if (c instanceof Container) {
         Component[] children = ((Container) c).getComponents();
         for (int i = children.length - 1; i >= 0; i--) {
            Component child = children[i];
            if (!child.visible || child.isLightweight() || child.width <= 0 || child.height <= 0) {
               continue;
            }
            Rectangle cr = area.intersection(child.visibleInWindow());
            if (cr.width > 0 && cr.height > 0) {
               paintComponent(w, child, cr, false);
            }
         }
      }
   }

   /** The native window erased these before a paint: Windows' background brush. */
   private static boolean erasesBackground(Component c) {
      return !c.isLightweight() && (c instanceof Canvas || c instanceof Panel || c instanceof Window || c instanceof ScrollPane);
   }

   /** Component.paintAll: the component and everything on it, with this Graphics. */
   static void paintTree(Component c, Graphics g, boolean update) {
      if (!c.visible) {
         return;
      }
      if (c.callsPaint()) {
         if (update) {
            c.update(g);
         } else {
            c.paint(g);
         }
      }
      if (c instanceof Container) {
         Component[] children = ((Container) c).getComponents();
         for (int i = children.length - 1; i >= 0; i--) {
            Component child = children[i];
            if (child.visible && !child.isLightweight()) {
               Graphics cg = g.create(child.x, child.y, child.width, child.height);
               try {
                  child.paintPeer(cg);
                  paintTree(child, cg, false);
               } finally {
                  cg.dispose();
               }
            }
         }
      }
   }

   static Graphics graphicsFor(Component c) {
      Window w = c.windowAncestor();
      if (w == null) {
         return null;
      }
      ensurePixels(w);
      Point o = c.originInWindow();
      Rectangle clip = c.visibleInWindow();
      if (c instanceof Window) {
         clip = clip.intersection(clientArea((Window) c));
      } else {
         clip = clip.intersection(clientArea(w));
      }
      SurfaceGraphics g = new SurfaceGraphics(w, o.x, o.y, clip);
      g.setColor(c.getForeground());
      g.setFont(c.getFont());
      g.setBackground(c.getBackground());
      return g;
   }

   static Graphics nullGraphics() {
      return new SurfaceGraphics(new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_RGB));
   }

   /** BufferStrategy.show: the drawing is already in the window, show it now. */
   static void showNow(Component c) {
      synchronized (LOCK) {
         LOCK.notifyAll();
      }
   }

   /** Something was drawn in a window (its pixels' coordinates). */
   static void damage(Window w, int x, int y, int width, int height) {
      if (w instanceof Window && isOnScreen(w)) {
         damageScreen(w.x + x, w.y + y, width, height);
      }
   }

   static void damageScreen(int x, int y, int width, int height) {
      if (width <= 0 || height <= 0) {
         return;
      }
      synchronized (LOCK) {
         Rectangle r = new Rectangle(x, y, width, height).intersection(new Rectangle(0, 0, screenWidth, screenHeight));
         if (r.width <= 0 || r.height <= 0) {
            return;
         }
         dirty = dirty == null ? r : dirty.union(r);
         LOCK.notifyAll();
      }
   }

   private static long lastPresent;

   private static void composeLoop() {
      while (true) {
         Rectangle r;
         synchronized (LOCK) {
            while (dirty == null) {
               try {
                  LOCK.wait();
               } catch (InterruptedException e) {
                  return;
               }
            }
            // at most one picture every 10 ms: what is drawn meanwhile goes in the same one
            long wait = lastPresent + 10 - System.currentTimeMillis();
            if (wait > 0) {
               try {
                  LOCK.wait(wait);
               } catch (InterruptedException e) {
                  return;
               }
            }
            r = dirty;
            dirty = null;
         }
         try {
            compose(r);
            screen.present(composed, r.x, r.y, r.width, r.height);
         } catch (Throwable t) {
            t.printStackTrace();
         }
         lastPresent = System.currentTimeMillis();
      }
   }

   private static void compose(Rectangle r) {
      int[] out = composed;
      int sw = screenWidth;
      for (int y = r.y; y < r.y + r.height; y++) {
         java.util.Arrays.fill(out, y * sw + r.x, y * sw + r.x + r.width, DESKTOP);
      }
      Window[] windows = windowsOnScreen();
      for (Window w : windows) {
         int[] px = w.pixels;
         if (px == null) {
            continue;
         }
         int pw = w.pixelsWidth;
         int ph = w.pixelsHeight;
         Rectangle wr = new Rectangle(w.x, w.y, Math.min(pw, w.width), Math.min(ph, w.height)).intersection(r);
         if (wr.width <= 0 || wr.height <= 0) {
            continue;
         }
         for (int y = wr.y; y < wr.y + wr.height; y++) {
            System.arraycopy(px, (y - w.y) * pw + (wr.x - w.x), out, y * sw + wr.x, wr.width);
         }
      }
      if (screen.drawsOwnCursor() && pointerX >= 0) {
         Theme.drawCursor(out, sw, screenHeight, pointerX, pointerY, r);
      }
   }

   // ------------------------------------------------------------------ input

   private static int pointerX = -1;
   private static int pointerY = -1;
   private static int buttonsDown;
   private static int keyModifiers;
   /** Where the mouse is, and the component pressed (it gets the drag and release, as a native capture). */
   private static Component hovered;
   private static Component pressed;
   private static Window pressedWindow;
   private static int pressedButton;
   private static long lastClickTime;
   private static int lastClickX;
   private static int lastClickY;
   private static int clickCount;
   private static boolean dragged;
   /** A window being dragged by its title bar: where it was grabbed. */
   private static Window movingWindow;
   private static int moveDX;
   private static int moveDY;

   private static void inputLoop() {
      int[] ev = new int[7];
      while (true) {
         try {
            if (!screen.nextEvent(ev, 1000)) {
               continue;
            }
            handle(ev);
         } catch (Throwable t) {
            t.printStackTrace();
         }
      }
   }

   private static void handle(int[] ev) {
      switch (ev[0]) {
         case Screen.POINTER_MOVED:
            pointer(MouseEvent.MOUSE_MOVED, ev[1], ev[2], 0, ev[5]);
            break;
         case Screen.POINTER_PRESSED:
            pointer(MouseEvent.MOUSE_PRESSED, ev[1], ev[2], ev[3], ev[5]);
            break;
         case Screen.POINTER_RELEASED:
            pointer(MouseEvent.MOUSE_RELEASED, ev[1], ev[2], ev[3], ev[5]);
            break;
         case Screen.WHEEL:
            wheel(ev[1], ev[2], ev[3]);
            break;
         case Screen.KEY_PRESSED:
         case Screen.KEY_RELEASED:
            key(ev[0] == Screen.KEY_PRESSED, ev[3], (char) ev[4], ev[5], ev[6]);
            break;
         case Screen.TEXT:
            text((char) ev[4]);
            break;
         case Screen.QUIT:
            quit();
            break;
         default:
      }
   }

   private static Window windowAt(int x, int y) {
      synchronized (LOCK) {
         for (int i = stack.size() - 1; i >= 0; i--) {
            Window w = stack.get(i);
            if (x >= w.x && y >= w.y && x < w.x + w.width && y < w.y + w.height) {
               return w;
            }
         }
      }
      return null;
   }

   private static int buttonMask(int button) {
      switch (button) {
         case 2:
            return InputEvent.BUTTON2_DOWN_MASK;
         case 3:
            return InputEvent.BUTTON3_DOWN_MASK;
         default:
            return InputEvent.BUTTON1_DOWN_MASK;
      }
   }

   private static void pointer(int id, int x, int y, int button, int modifiers) {
      int oldX = pointerX;
      int oldY = pointerY;
      pointerX = x;
      pointerY = y;
      if (screen.drawsOwnCursor() && (oldX != x || oldY != y)) {
         damageScreen(oldX - 2, oldY - 2, 20, 24);
         damageScreen(x - 2, y - 2, 20, 24);
      }
      long when = System.currentTimeMillis();
      if (id == MouseEvent.MOUSE_PRESSED) {
         buttonsDown |= buttonMask(button);
      } else if (id == MouseEvent.MOUSE_RELEASED) {
         buttonsDown &= ~buttonMask(button);
      }
      int mods = (keyModifiers & ~(InputEvent.BUTTON1_DOWN_MASK | InputEvent.BUTTON2_DOWN_MASK | InputEvent.BUTTON3_DOWN_MASK))
            | buttonsDown | (id == MouseEvent.MOUSE_RELEASED ? buttonMask(button) : 0);

      if (movingWindow != null) {
         if (id == MouseEvent.MOUSE_RELEASED) {
            movingWindow = null;
         } else {
            Window w = movingWindow;
            w.setLocation(x - moveDX, y - moveDY);
         }
         return;
      }

      if (PopupWindow.anyOpen()) {
         // an open menu or list has the pointer, as Windows' menu loop captured it
         pressed = null;
         pressedWindow = null;
         PopupWindow.pointer(id, x, y, button, mods, when);
         return;
      }

      Window w;
      Component target;
      if (pressed != null && id != MouseEvent.MOUSE_PRESSED) {
         w = pressedWindow;
         target = pressed;
      } else {
         w = windowAt(x, y);
         if (w == null) {
            setHovered(null, x, y, mods, when);
            return;
         }
         if (modalBlocker(w) != null) {
            if (id == MouseEvent.MOUSE_PRESSED) {
               Window blocker = modalBlocker(w);
               windowToFront(blocker);
               Toolkit.getDefaultToolkit().beep();
            }
            setHovered(null, x, y, mods, when);
            return;
         }
         int wx = x - w.x;
         int wy = y - w.y;
         if (id == MouseEvent.MOUSE_PRESSED) {
            windowToFront(w);
            int hit = Theme.decorationHit(w, wx, wy);
            if (hit == Theme.HIT_CLOSE) {
               w.postWindowEvent(WindowEvent.WINDOW_CLOSING);
               return;
            }
            if (hit == Theme.HIT_TITLE) {
               movingWindow = w;
               moveDX = wx;
               moveDY = wy;
               return;
            }
            if (hit == Theme.HIT_MENUBAR) {
               MenuWindow.menuBarPressed((Frame) w, wx, wy);
               return;
            }
         }
         target = w.findComponentAt(wx, wy, false);
         if (target == null) {
            target = w;
         }
         while (target != null && !target.enabled) {
            target = target.parent;
         }
         if (target == null) {
            return;
         }
      }

      Point origin = target.locationOnScreen();
      int cx = x - origin.x;
      int cy = y - origin.y;

      switch (id) {
         case MouseEvent.MOUSE_MOVED:
            if (pressed != null) {
               dragged = true;
               post(new MouseEvent(target, MouseEvent.MOUSE_DRAGGED, when, mods, cx, cy, x, y, 0, false, MouseEvent.NOBUTTON));
            } else {
               setHovered(target, x, y, mods, when);
               post(new MouseEvent(target, MouseEvent.MOUSE_MOVED, when, mods, cx, cy, x, y, 0, false, MouseEvent.NOBUTTON));
            }
            break;
         case MouseEvent.MOUSE_PRESSED: {
            setHovered(target, x, y, mods, when);
            if (when - lastClickTime < 500 && Math.abs(x - lastClickX) < 5 && Math.abs(y - lastClickY) < 5 && button == pressedButton) {
               clickCount++;
            } else {
               clickCount = 1;
            }
            lastClickTime = when;
            lastClickX = x;
            lastClickY = y;
            pressed = target;
            pressedWindow = target.windowAncestor();
            pressedButton = button;
            dragged = false;
            if (takesFocusOnClick(target)) {
               final Component f = target;
               EventQueue.invokeLater(new Runnable() {
                  public void run() {
                     f.requestFocus();
                  }
               });
            }
            post(new MouseEvent(target, MouseEvent.MOUSE_PRESSED, when, mods, cx, cy, x, y, clickCount, button == 3, button));
            break;
         }
         case MouseEvent.MOUSE_RELEASED: {
            Component was = pressed;
            pressed = null;
            pressedWindow = null;
            if (was == null) {
               break;
            }
            post(new MouseEvent(was, MouseEvent.MOUSE_RELEASED, when, mods, cx, cy, x, y, clickCount, false, button));
            if (cx >= 0 && cy >= 0 && cx < was.width && cy < was.height) {
               post(new MouseEvent(was, MouseEvent.MOUSE_CLICKED, when, mods, cx, cy, x, y, clickCount, false, button));
            }
            Window now = windowAt(x, y);
            Component under = null;
            if (now != null && modalBlocker(now) == null) {
               under = now.findComponentAt(x - now.x, y - now.y, false);
            }
            setHovered(under, x, y, mods & ~buttonMask(button), when);
            break;
         }
         default:
      }
   }

   /** On Windows a click gave the focus to controls and canvases (the 3D view), not to panels. */
   private static boolean takesFocusOnClick(Component c) {
      return c.isFocusable() && (c.traversable() || c instanceof Canvas) && !c.isFocusOwner();
   }

   private static void setHovered(Component c, int x, int y, int mods, long when) {
      Component old = hovered;
      if (old == c) {
         return;
      }
      hovered = c;
      if (old != null && old.isShowing()) {
         Point o = old.locationOnScreen();
         post(new MouseEvent(old, MouseEvent.MOUSE_EXITED, when, mods, x - o.x, y - o.y, x, y, 0, false, MouseEvent.NOBUTTON));
      }
      if (c != null) {
         Point o = c.locationOnScreen();
         post(new MouseEvent(c, MouseEvent.MOUSE_ENTERED, when, mods, x - o.x, y - o.y, x, y, 0, false, MouseEvent.NOBUTTON));
         Cursor cur = c.getCursor();
         screen.setCursorShape(cur == null ? Cursor.DEFAULT_CURSOR : cur.getType());
      }
   }

   private static void wheel(int x, int y, int rotation) {
      if (PopupWindow.anyOpen()) {
         PopupWindow.wheel(x, y, rotation);
         return;
      }
      Window w = windowAt(x, y);
      if (w == null || modalBlocker(w) != null) {
         return;
      }
      Component target = w.findComponentAt(x - w.x, y - w.y, false);
      if (target == null) {
         return;
      }
      Point o = target.locationOnScreen();
      post(new MouseWheelEvent(target, MouseEvent.MOUSE_WHEEL, System.currentTimeMillis(), keyModifiers, x - o.x, y - o.y, 0, false,
            MouseWheelEvent.WHEEL_UNIT_SCROLL, 3, rotation));
   }

   private static void post(java.awt.AWTEvent e) {
      EventQueue.post(e);
   }

   static void componentRemoved(Component c) {
      if (hovered == c || (c instanceof Container && hovered != null && ((Container) c).isAncestorOf(hovered))) {
         hovered = null;
      }
      if (pressed == c || (c instanceof Container && pressed != null && ((Container) c).isAncestorOf(pressed))) {
         pressed = null;
         pressedWindow = null;
      }
   }

   static void cursorChanged(Component c) {
      if (screen != null && hovered == c) {
         Cursor cur = c.getCursor();
         screen.setCursorShape(cur == null ? Cursor.DEFAULT_CURSOR : cur.getType());
      }
   }

   private static Component keyTarget() {
      Window w = active;
      if (w == null) {
         return null;
      }
      Component f = KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner();
      if (f != null && f.windowAncestor() == w && f.isShowing()) {
         return f;
      }
      return w;
   }

   private static void key(boolean press, int vk, char c, int modifiers, int location) {
      int bit = 0;
      switch (vk) {
         case KeyEvent.VK_SHIFT:
            bit = InputEvent.SHIFT_DOWN_MASK | InputEvent.SHIFT_MASK;
            break;
         case KeyEvent.VK_CONTROL:
            bit = InputEvent.CTRL_DOWN_MASK | InputEvent.CTRL_MASK;
            break;
         case KeyEvent.VK_ALT:
            bit = InputEvent.ALT_DOWN_MASK | InputEvent.ALT_MASK;
            break;
         default:
      }
      if (bit != 0) {
         keyModifiers = press ? keyModifiers | bit : keyModifiers & ~bit;
      }
      if (PopupWindow.anyOpen()) {
         PopupWindow.key(press, vk, c, modifiers != 0 ? modifiers : keyModifiers);
         return;
      }
      final Component target = keyTarget();
      if (target == null) {
         return;
      }
      int mods = modifiers != 0 ? modifiers : keyModifiers;
      long when = System.currentTimeMillis();
      if (location == 0) {
         location = KeyEvent.KEY_LOCATION_STANDARD;
      }
      if (press) {
         final KeyEvent pressedEvent = new KeyEvent(target, KeyEvent.KEY_PRESSED, when, mods, vk, c == 0 ? KeyEvent.CHAR_UNDEFINED : c, location);
         final KeyEvent typed = (c == 0 || c == KeyEvent.CHAR_UNDEFINED || (mods & (InputEvent.CTRL_MASK | InputEvent.ALT_MASK)) != 0 && c >= ' ') ? null
               : new KeyEvent(target, KeyEvent.KEY_TYPED, when, mods, KeyEvent.VK_UNDEFINED, c, KeyEvent.KEY_LOCATION_UNKNOWN);
         post(new KeyStroke(target, pressedEvent, typed));
      } else {
         post(new KeyEvent(target, KeyEvent.KEY_RELEASED, when, mods, vk, c == 0 ? KeyEvent.CHAR_UNDEFINED : c, location));
      }
   }

   /** A character from the IME: as if its key was pressed and released. */
   private static void text(char c) {
      int vk = KeyEvent.getExtendedKeyCodeForChar(c);
      if (vk > 0xFFFF) {
         vk = KeyEvent.VK_UNDEFINED;
      }
      key(true, vk, c, 0, KeyEvent.KEY_LOCATION_STANDARD);
      key(false, vk, c, 0, KeyEvent.KEY_LOCATION_STANDARD);
   }

   /**
    * KEY_PRESSED and then, unless it was consumed (a 1.0 keyDown that
    * returned true, a listener that consumed it), the KEY_TYPED that types
    * the character, as a native control would only see the character then.
    */
   static final class KeyStroke extends java.awt.AWTEvent implements ActiveEvent {
      private final Component target;
      private final KeyEvent pressedEvent;
      private final KeyEvent typed;

      KeyStroke(Component target, KeyEvent pressedEvent, KeyEvent typed) {
         super(target, java.awt.AWTEvent.RESERVED_ID_MAX + 7);
         this.target = target;
         this.pressedEvent = pressedEvent;
         this.typed = typed;
      }

      public void dispatch() {
         target.dispatchEvent(pressedEvent);
         if (typed != null && !pressedEvent.isConsumed()) {
            if (pressedEvent.getKeyChar() != typed.getKeyChar() && pressedEvent.getKeyChar() != KeyEvent.CHAR_UNDEFINED) {
               typed.setKeyChar(pressedEvent.getKeyChar());
            }
            target.dispatchEvent(typed);
         }
      }
   }

   private static void quit() {
      Window main = null;
      synchronized (LOCK) {
         for (int i = stack.size() - 1; i >= 0; i--) {
            if (stack.get(i) instanceof Frame) {
               main = stack.get(i);
               break;
            }
         }
      }
      if (main != null) {
         main.postWindowEvent(WindowEvent.WINDOW_CLOSING);
      } else {
         System.exit(0);
      }
   }

   static Point pointer() {
      return new Point(pointerX, pointerY);
   }

   /** The text fields ask for the system's keyboard while they have the focus. */
   static void textFocus(TextComponent field, boolean gained) {
      if (screen == null) {
         return;
      }
      if (gained && field.isEditable()) {
         String title = "";
         Window w = field.windowAncestor();
         if (w instanceof Dialog) {
            title = ((Dialog) w).getTitle();
         } else if (w instanceof Frame) {
            title = ((Frame) w).getTitle();
         }
         screen.requestText(field.getText(), field instanceof TextArea,
               field instanceof TextField && ((TextField) field).echoCharIsSet(), title);
      } else {
         screen.endText();
      }
   }
}

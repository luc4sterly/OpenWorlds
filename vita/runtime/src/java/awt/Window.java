package java.awt;

import java.awt.event.WindowEvent;
import java.awt.event.WindowFocusListener;
import java.awt.event.WindowListener;
import java.awt.event.WindowStateListener;
import java.util.ArrayList;

/**
 * A top-level window, as java.awt.Window. Its pixels live in
 * {@link #pixels} and {@link WindowSystem} composes the windows on the
 * screen; decorations (Frame and Dialog title bars, the menu bar) are drawn
 * here too, as Windows drew them around the client area.
 */
public class Window extends Container {
   static final ArrayList<Window> allWindows = new ArrayList<Window>();

   transient Window owner;
   final ArrayList<Window> ownedWindows = new ArrayList<Window>();
   transient WindowListener windowListener;
   transient WindowFocusListener windowFocusListener;
   transient WindowStateListener windowStateListener;
   boolean opened;
   boolean focusableWindowState = true;
   boolean alwaysOnTop;
   /** The component that has (or last had) the keyboard focus in this window. */
   transient Component focusOwner;

   /** ARGB pixels of the whole window, decorations included (WindowSystem). */
   int[] pixels;
   int pixelsWidth;
   int pixelsHeight;

   Window() {
      visible = false;
      setLayout(new BorderLayout());
      synchronized (allWindows) {
         allWindows.add(this);
      }
   }

   public Window(Frame owner) {
      this((Window) owner);
   }

   public Window(Window owner) {
      this();
      setOwner(owner);
   }

   public Window(Window owner, GraphicsConfiguration gc) {
      this(owner);
   }

   void setOwner(Window owner) {
      this.owner = owner;
      if (owner != null) {
         synchronized (owner.ownedWindows) {
            owner.ownedWindows.add(this);
         }
      }
   }

   public Window getOwner() {
      return owner;
   }

   public Window[] getOwnedWindows() {
      synchronized (ownedWindows) {
         return ownedWindows.toArray(new Window[ownedWindows.size()]);
      }
   }

   public static Window[] getWindows() {
      synchronized (allWindows) {
         return allWindows.toArray(new Window[allWindows.size()]);
      }
   }

   public static Window[] getOwnerlessWindows() {
      ArrayList<Window> out = new ArrayList<Window>();
      for (Window w : getWindows()) {
         if (w.owner == null) {
            out.add(w);
         }
      }
      return out.toArray(new Window[out.size()]);
   }

   public void addNotify() {
      synchronized (LOCK) {
         if (owner != null && !owner.displayable) {
            owner.addNotify();
         }
         if (background == null) {
            background = Theme.windowBackground(this);
         }
         if (foreground == null) {
            foreground = Color.black;
         }
         if (font == null) {
            font = Theme.DIALOG_FONT;
         }
         super.addNotify();
      }
   }

   public void removeNotify() {
      synchronized (LOCK) {
         for (Window w : getOwnedWindows()) {
            w.removeNotify();
         }
         super.removeNotify();
      }
   }

   public void pack() {
      Container p = parent;
      if (p != null && !p.displayable) {
         p.addNotify();
      }
      if (!displayable) {
         addNotify();
      }
      Dimension d = getPreferredSize();
      setSize(d.width, d.height);
      validate();
   }

   public void setVisible(boolean b) {
      super.setVisible(b);
   }

   public void show() {
      if (!displayable) {
         addNotify();
      }
      validate();
      if (visible) {
         toFront();
      } else {
         visible = true;
         WindowSystem.windowShown(this);
         for (Window w : getOwnedWindows()) {
            if (w.showWithParent) {
               w.showWithParent = false;
               w.show();
            }
         }
      }
      if (!opened) {
         opened = true;
         postWindowEvent(WindowEvent.WINDOW_OPENED);
      }
   }

   /** Owned windows hidden with their owner come back with it, as the JDK. */
   boolean showWithParent;

   public void hide() {
      synchronized (ownedWindows) {
         for (Window w : ownedWindows) {
            if (w.visible) {
               w.hide();
               w.showWithParent = true;
            }
         }
      }
      if (visible) {
         visible = false;
         WindowSystem.windowHidden(this);
      }
   }

   public void dispose() {
      for (Window w : getOwnedWindows()) {
         w.dispose();
      }
      hide();
      boolean was = displayable;
      if (displayable) {
         removeNotify();
      }
      if (was) {
         postWindowEvent(WindowEvent.WINDOW_CLOSED);
      }
   }

   public void toFront() {
      if (visible) {
         WindowSystem.windowToFront(this);
      }
   }

   public void toBack() {
      if (visible) {
         WindowSystem.windowToBack(this);
      }
   }

   public boolean isShowing() {
      return visible && displayable && WindowSystem.isOnScreen(this);
   }

   public Point getLocationOnScreen() {
      return new Point(x, y);
   }

   Point locationOnScreen() {
      return new Point(x, y);
   }

   public Insets getInsets() {
      return insets();
   }

   public Insets insets() {
      return Theme.decorationInsets(this);
   }

   public void setLocationRelativeTo(Component c) {
      Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
      if (c == null || !c.isShowing()) {
         setLocation((screen.width - width) / 2, (screen.height - height) / 2);
         return;
      }
      Point p = c.getLocationOnScreen();
      int nx = p.x + (c.width - width) / 2;
      int ny = p.y + (c.height - height) / 2;
      nx = Math.max(0, Math.min(nx, screen.width - width));
      ny = Math.max(0, Math.min(ny, screen.height - height));
      setLocation(nx, ny);
   }

   void boundsChanged(int oldX, int oldY, int oldW, int oldH, boolean resized, boolean moved) {
      WindowSystem.windowBoundsChanged(this, new Rectangle(oldX, oldY, oldW, oldH), resized);
   }

   public void setAlwaysOnTop(boolean alwaysOnTop) {
      this.alwaysOnTop = alwaysOnTop;
      if (alwaysOnTop) {
         toFront();
      }
   }

   public boolean isAlwaysOnTop() {
      return alwaysOnTop;
   }

   public String getWarningString() {
      return null;
   }

   public Toolkit getToolkit() {
      return Toolkit.getDefaultToolkit();
   }

   public boolean isActive() {
      return WindowSystem.activeWindow() == this;
   }

   public boolean isFocused() {
      return isActive();
   }

   public Component getFocusOwner() {
      return isActive() ? focusOwner : null;
   }

   public Component getMostRecentFocusOwner() {
      return focusOwner;
   }

   public boolean isFocusableWindow() {
      return focusableWindowState;
   }

   public boolean getFocusableWindowState() {
      return focusableWindowState;
   }

   public void setFocusableWindowState(boolean state) {
      focusableWindowState = state;
   }

   public boolean isFocusCycleRoot() {
      return true;
   }

   public void setCursor(Cursor cursor) {
      super.setCursor(cursor == null ? Cursor.getDefaultCursor() : cursor);
   }

   public boolean postEvent(Event e) {
      if (handleEvent(e)) {
         e.consume();
         return true;
      }
      return false;
   }

   /** The title bar, frame and menu bar, which Windows drew. */
   void paintPeer(Graphics g) {
      Theme.paintDecorations(this, g);
   }

   void postWindowEvent(int id) {
      if (windowListener != null || (eventMask & AWTEvent.WINDOW_EVENT_MASK) != 0 || !newEventsOnly) {
         EventQueue.post(new WindowEvent(this, id));
      }
   }

   void postWindowFocusEvent(int id, Window opposite) {
      EventQueue.post(new WindowEvent(this, id, opposite));
   }

   public synchronized void addWindowListener(WindowListener l) {
      if (l == null) {
         return;
      }
      newEventsOnly = true;
      windowListener = AWTEventMulticaster.add(windowListener, l);
   }

   public synchronized void removeWindowListener(WindowListener l) {
      if (l == null) {
         return;
      }
      windowListener = AWTEventMulticaster.remove(windowListener, l);
   }

   public synchronized WindowListener[] getWindowListeners() {
      ArrayList<WindowListener> out = new ArrayList<WindowListener>();
      collect(windowListener, out);
      return out.toArray(new WindowListener[out.size()]);
   }

   private static void collect(WindowListener l, ArrayList<WindowListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((WindowListener) ((AWTEventMulticaster) l).a, out);
         collect((WindowListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   public synchronized void addWindowFocusListener(WindowFocusListener l) {
      if (l == null) {
         return;
      }
      windowFocusListener = AWTEventMulticaster.add(windowFocusListener, l);
   }

   public synchronized void removeWindowFocusListener(WindowFocusListener l) {
      windowFocusListener = AWTEventMulticaster.remove(windowFocusListener, l);
   }

   public synchronized void addWindowStateListener(WindowStateListener l) {
      if (l == null) {
         return;
      }
      windowStateListener = AWTEventMulticaster.add(windowStateListener, l);
   }

   public synchronized void removeWindowStateListener(WindowStateListener l) {
      windowStateListener = AWTEventMulticaster.remove(windowStateListener, l);
   }

   boolean eventEnabled(AWTEvent e) {
      switch (e.id) {
         case WindowEvent.WINDOW_OPENED:
         case WindowEvent.WINDOW_CLOSING:
         case WindowEvent.WINDOW_CLOSED:
         case WindowEvent.WINDOW_ICONIFIED:
         case WindowEvent.WINDOW_DEICONIFIED:
         case WindowEvent.WINDOW_ACTIVATED:
         case WindowEvent.WINDOW_DEACTIVATED:
            return (eventMask & AWTEvent.WINDOW_EVENT_MASK) != 0 || windowListener != null;
         case WindowEvent.WINDOW_GAINED_FOCUS:
         case WindowEvent.WINDOW_LOST_FOCUS:
            return (eventMask & AWTEvent.WINDOW_FOCUS_EVENT_MASK) != 0 || windowFocusListener != null;
         case WindowEvent.WINDOW_STATE_CHANGED:
            return (eventMask & AWTEvent.WINDOW_STATE_EVENT_MASK) != 0 || windowStateListener != null;
         default:
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof WindowEvent) {
         switch (e.getID()) {
            case WindowEvent.WINDOW_OPENED:
            case WindowEvent.WINDOW_CLOSING:
            case WindowEvent.WINDOW_CLOSED:
            case WindowEvent.WINDOW_ICONIFIED:
            case WindowEvent.WINDOW_DEICONIFIED:
            case WindowEvent.WINDOW_ACTIVATED:
            case WindowEvent.WINDOW_DEACTIVATED:
               processWindowEvent((WindowEvent) e);
               break;
            case WindowEvent.WINDOW_GAINED_FOCUS:
            case WindowEvent.WINDOW_LOST_FOCUS:
               processWindowFocusEvent((WindowEvent) e);
               break;
            case WindowEvent.WINDOW_STATE_CHANGED:
               processWindowStateEvent((WindowEvent) e);
               break;
            default:
         }
         return;
      }
      super.processEvent(e);
   }

   protected void processWindowEvent(WindowEvent e) {
      WindowListener listener = windowListener;
      if (listener != null) {
         switch (e.getID()) {
            case WindowEvent.WINDOW_OPENED:
               listener.windowOpened(e);
               break;
            case WindowEvent.WINDOW_CLOSING:
               listener.windowClosing(e);
               break;
            case WindowEvent.WINDOW_CLOSED:
               listener.windowClosed(e);
               break;
            case WindowEvent.WINDOW_ICONIFIED:
               listener.windowIconified(e);
               break;
            case WindowEvent.WINDOW_DEICONIFIED:
               listener.windowDeiconified(e);
               break;
            case WindowEvent.WINDOW_ACTIVATED:
               listener.windowActivated(e);
               break;
            case WindowEvent.WINDOW_DEACTIVATED:
               listener.windowDeactivated(e);
               break;
            default:
         }
      }
   }

   protected void processWindowFocusEvent(WindowEvent e) {
      WindowFocusListener listener = windowFocusListener;
      if (listener != null) {
         if (e.getID() == WindowEvent.WINDOW_GAINED_FOCUS) {
            listener.windowGainedFocus(e);
         } else if (e.getID() == WindowEvent.WINDOW_LOST_FOCUS) {
            listener.windowLostFocus(e);
         }
      }
   }

   protected void processWindowStateEvent(WindowEvent e) {
      WindowStateListener listener = windowStateListener;
      if (listener != null && e.getID() == WindowEvent.WINDOW_STATE_CHANGED) {
         listener.windowStateChanged(e);
      }
   }

   protected void finalize() throws Throwable {
      synchronized (allWindows) {
         allWindows.remove(this);
      }
   }
}

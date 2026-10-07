package java.awt;

import java.awt.event.WindowEvent;
import java.util.ArrayList;

/** A window with a title and a menu bar, as java.awt.Frame. */
public class Frame extends Window implements MenuContainer {
   public static final int DEFAULT_CURSOR = Cursor.DEFAULT_CURSOR;
   public static final int CROSSHAIR_CURSOR = Cursor.CROSSHAIR_CURSOR;
   public static final int TEXT_CURSOR = Cursor.TEXT_CURSOR;
   public static final int WAIT_CURSOR = Cursor.WAIT_CURSOR;
   public static final int SW_RESIZE_CURSOR = Cursor.SW_RESIZE_CURSOR;
   public static final int SE_RESIZE_CURSOR = Cursor.SE_RESIZE_CURSOR;
   public static final int NW_RESIZE_CURSOR = Cursor.NW_RESIZE_CURSOR;
   public static final int NE_RESIZE_CURSOR = Cursor.NE_RESIZE_CURSOR;
   public static final int N_RESIZE_CURSOR = Cursor.N_RESIZE_CURSOR;
   public static final int S_RESIZE_CURSOR = Cursor.S_RESIZE_CURSOR;
   public static final int W_RESIZE_CURSOR = Cursor.W_RESIZE_CURSOR;
   public static final int E_RESIZE_CURSOR = Cursor.E_RESIZE_CURSOR;
   public static final int HAND_CURSOR = Cursor.HAND_CURSOR;
   public static final int MOVE_CURSOR = Cursor.MOVE_CURSOR;

   public static final int NORMAL = 0;
   public static final int ICONIFIED = 1;
   public static final int MAXIMIZED_HORIZ = 2;
   public static final int MAXIMIZED_VERT = 4;
   public static final int MAXIMIZED_BOTH = MAXIMIZED_VERT | MAXIMIZED_HORIZ;

   static final ArrayList<Frame> allFrames = new ArrayList<Frame>();

   String title = "";
   Image icon;
   MenuBar menuBar;
   boolean resizable = true;
   boolean undecorated;
   int state = NORMAL;

   public Frame() {
      this("");
   }

   public Frame(GraphicsConfiguration gc) {
      this("");
   }

   public Frame(String title) {
      super();
      this.title = title == null ? "" : title;
      synchronized (allFrames) {
         allFrames.add(this);
      }
   }

   public Frame(String title, GraphicsConfiguration gc) {
      this(title);
   }

   public static Frame[] getFrames() {
      synchronized (allFrames) {
         return allFrames.toArray(new Frame[allFrames.size()]);
      }
   }

   public String getTitle() {
      return title;
   }

   public void setTitle(String title) {
      this.title = title == null ? "" : title;
      WindowSystem.decorationsChanged(this);
   }

   public Image getIconImage() {
      return icon;
   }

   public void setIconImage(Image image) {
      icon = image;
   }

   public MenuBar getMenuBar() {
      return menuBar;
   }

   public void setMenuBar(MenuBar mb) {
      synchronized (LOCK) {
         if (menuBar == mb) {
            return;
         }
         if (mb != null && mb.parent != null) {
            mb.parent.remove(mb);
         }
         if (menuBar != null) {
            remove(menuBar);
         }
         menuBar = mb;
         if (mb != null) {
            mb.parent = this;
            if (displayable) {
               mb.addNotify();
            }
         }
         invalidate();
      }
      if (isShowing()) {
         validate();
         WindowSystem.decorationsChanged(this);
         repaint();
      }
   }

   public void remove(MenuComponent m) {
      if (m == null) {
         return;
      }
      synchronized (LOCK) {
         if (m == menuBar) {
            menuBar = null;
            if (displayable) {
               m.removeNotify();
            }
            m.parent = null;
            invalidate();
            if (isShowing()) {
               validate();
               WindowSystem.decorationsChanged(this);
               repaint();
            }
            return;
         }
      }
      super.remove(m);
   }

   public boolean isResizable() {
      return resizable;
   }

   public void setResizable(boolean resizable) {
      this.resizable = resizable;
   }

   public boolean isUndecorated() {
      return undecorated;
   }

   public void setUndecorated(boolean undecorated) {
      if (displayable) {
         throw new IllegalComponentStateException("The frame is displayable.");
      }
      this.undecorated = undecorated;
   }

   public synchronized void setState(int state) {
      int old = this.state;
      this.state = state;
      if (old != state) {
         if (state == ICONIFIED) {
            postWindowEvent(WindowEvent.WINDOW_ICONIFIED);
         } else if (old == ICONIFIED) {
            postWindowEvent(WindowEvent.WINDOW_DEICONIFIED);
         }
      }
   }

   public synchronized int getState() {
      return (state & ICONIFIED) != 0 ? ICONIFIED : NORMAL;
   }

   public synchronized void setExtendedState(int state) {
      setState(state);
   }

   public synchronized int getExtendedState() {
      return state;
   }

   public void setMaximizedBounds(Rectangle bounds) {
   }

   public Rectangle getMaximizedBounds() {
      return null;
   }

   public void setCursor(int cursorType) {
      setCursor(Cursor.getPredefinedCursor(cursorType));
   }

   public int getCursorType() {
      return getCursor().getType();
   }

   public void addNotify() {
      synchronized (LOCK) {
         super.addNotify();
         if (menuBar != null) {
            menuBar.addNotify();
         }
      }
   }

   public void removeNotify() {
      synchronized (LOCK) {
         if (menuBar != null) {
            menuBar.removeNotify();
         }
         super.removeNotify();
      }
   }

   protected String paramString() {
      String str = super.paramString();
      if (title != null) {
         str += ",title=" + title;
      }
      if (resizable) {
         str += ",resizable";
      }
      return str;
   }
}

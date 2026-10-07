package java.awt;

import java.awt.event.KeyEvent;

/**
 * The JDK 1.0 event, which most of the 2004 client still handles
 * (handleEvent, action, mouseDown, keyDown...). AWTEvent.convertToOld makes
 * one from each 1.1 event, as the JDK does.
 */
public class Event implements java.io.Serializable {
   public static final int SHIFT_MASK = 1 << 0;
   public static final int CTRL_MASK = 1 << 1;
   public static final int META_MASK = 1 << 2;
   public static final int ALT_MASK = 1 << 3;

   public static final int HOME = 1000;
   public static final int END = 1001;
   public static final int PGUP = 1002;
   public static final int PGDN = 1003;
   public static final int UP = 1004;
   public static final int DOWN = 1005;
   public static final int LEFT = 1006;
   public static final int RIGHT = 1007;
   public static final int F1 = 1008;
   public static final int F2 = 1009;
   public static final int F3 = 1010;
   public static final int F4 = 1011;
   public static final int F5 = 1012;
   public static final int F6 = 1013;
   public static final int F7 = 1014;
   public static final int F8 = 1015;
   public static final int F9 = 1016;
   public static final int F10 = 1017;
   public static final int F11 = 1018;
   public static final int F12 = 1019;
   public static final int PRINT_SCREEN = 1020;
   public static final int SCROLL_LOCK = 1021;
   public static final int CAPS_LOCK = 1022;
   public static final int NUM_LOCK = 1023;
   public static final int PAUSE = 1024;
   public static final int INSERT = 1025;
   public static final int ENTER = '\n';
   public static final int BACK_SPACE = '\b';
   public static final int TAB = '\t';
   public static final int ESCAPE = 27;
   public static final int DELETE = 127;

   private static final int WINDOW_EVENT = 200;
   public static final int WINDOW_DESTROY = 1 + WINDOW_EVENT;
   public static final int WINDOW_EXPOSE = 2 + WINDOW_EVENT;
   public static final int WINDOW_ICONIFY = 3 + WINDOW_EVENT;
   public static final int WINDOW_DEICONIFY = 4 + WINDOW_EVENT;
   public static final int WINDOW_MOVED = 5 + WINDOW_EVENT;

   private static final int KEY_EVENT = 400;
   public static final int KEY_PRESS = 1 + KEY_EVENT;
   public static final int KEY_RELEASE = 2 + KEY_EVENT;
   public static final int KEY_ACTION = 3 + KEY_EVENT;
   public static final int KEY_ACTION_RELEASE = 4 + KEY_EVENT;

   private static final int MOUSE_EVENT = 500;
   public static final int MOUSE_DOWN = 1 + MOUSE_EVENT;
   public static final int MOUSE_UP = 2 + MOUSE_EVENT;
   public static final int MOUSE_MOVE = 3 + MOUSE_EVENT;
   public static final int MOUSE_ENTER = 4 + MOUSE_EVENT;
   public static final int MOUSE_EXIT = 5 + MOUSE_EVENT;
   public static final int MOUSE_DRAG = 6 + MOUSE_EVENT;

   private static final int SCROLL_EVENT = 600;
   public static final int SCROLL_LINE_UP = 1 + SCROLL_EVENT;
   public static final int SCROLL_LINE_DOWN = 2 + SCROLL_EVENT;
   public static final int SCROLL_PAGE_UP = 3 + SCROLL_EVENT;
   public static final int SCROLL_PAGE_DOWN = 4 + SCROLL_EVENT;
   public static final int SCROLL_ABSOLUTE = 5 + SCROLL_EVENT;
   public static final int SCROLL_BEGIN = 6 + SCROLL_EVENT;
   public static final int SCROLL_END = 7 + SCROLL_EVENT;

   private static final int LIST_EVENT = 700;
   public static final int LIST_SELECT = 1 + LIST_EVENT;
   public static final int LIST_DESELECT = 2 + LIST_EVENT;

   private static final int MISC_EVENT = 1000;
   public static final int ACTION_EVENT = 1 + MISC_EVENT;
   public static final int LOAD_FILE = 2 + MISC_EVENT;
   public static final int SAVE_FILE = 3 + MISC_EVENT;
   public static final int GOT_FOCUS = 4 + MISC_EVENT;
   public static final int LOST_FOCUS = 5 + MISC_EVENT;

   public Object target;
   public long when;
   public int id;
   public int x;
   public int y;
   public int key;
   public int modifiers;
   public int clickCount;
   public Object arg;
   public Event evt;

   /** Set when a handleEvent returned true (Component.postEvent). */
   boolean consumed;

   public Event(Object target, long when, int id, int x, int y, int key, int modifiers, Object arg) {
      this.target = target;
      this.when = when;
      this.id = id;
      this.x = x;
      this.y = y;
      this.key = key;
      this.modifiers = modifiers;
      this.arg = arg;
      this.clickCount = 0;
      this.evt = null;
   }

   public Event(Object target, long when, int id, int x, int y, int key, int modifiers) {
      this(target, when, id, x, y, key, modifiers, null);
   }

   public Event(Object target, int id, Object arg) {
      this(target, 0, id, 0, 0, 0, 0, arg);
   }

   public void translate(int dx, int dy) {
      this.x += dx;
      this.y += dy;
   }

   public boolean shiftDown() {
      return (modifiers & SHIFT_MASK) != 0;
   }

   public boolean controlDown() {
      return (modifiers & CTRL_MASK) != 0;
   }

   public boolean metaDown() {
      return (modifiers & META_MASK) != 0;
   }

   void consume() {
      switch (id) {
         case KEY_PRESS:
         case KEY_RELEASE:
         case KEY_ACTION:
         case KEY_ACTION_RELEASE:
            consumed = true;
            break;
         default:
      }
   }

   boolean isConsumed() {
      return consumed;
   }

   /** The 1.0 key of a 1.1 key event: the character, or HOME..INSERT for the action keys. */
   static int getOldEventKey(KeyEvent e) {
      int keyCode = e.getKeyCode();
      switch (keyCode) {
         case KeyEvent.VK_HOME:
            return HOME;
         case KeyEvent.VK_END:
            return END;
         case KeyEvent.VK_PAGE_UP:
            return PGUP;
         case KeyEvent.VK_PAGE_DOWN:
            return PGDN;
         case KeyEvent.VK_UP:
            return UP;
         case KeyEvent.VK_DOWN:
            return DOWN;
         case KeyEvent.VK_LEFT:
            return LEFT;
         case KeyEvent.VK_RIGHT:
            return RIGHT;
         case KeyEvent.VK_F1:
            return F1;
         case KeyEvent.VK_F2:
            return F2;
         case KeyEvent.VK_F3:
            return F3;
         case KeyEvent.VK_F4:
            return F4;
         case KeyEvent.VK_F5:
            return F5;
         case KeyEvent.VK_F6:
            return F6;
         case KeyEvent.VK_F7:
            return F7;
         case KeyEvent.VK_F8:
            return F8;
         case KeyEvent.VK_F9:
            return F9;
         case KeyEvent.VK_F10:
            return F10;
         case KeyEvent.VK_F11:
            return F11;
         case KeyEvent.VK_F12:
            return F12;
         case KeyEvent.VK_PRINTSCREEN:
            return PRINT_SCREEN;
         case KeyEvent.VK_SCROLL_LOCK:
            return SCROLL_LOCK;
         case KeyEvent.VK_CAPS_LOCK:
            return CAPS_LOCK;
         case KeyEvent.VK_NUM_LOCK:
            return NUM_LOCK;
         case KeyEvent.VK_PAUSE:
            return PAUSE;
         case KeyEvent.VK_INSERT:
            return INSERT;
         default:
      }
      return e.getKeyChar();
   }

   /** The character a 1.0 key would type, for the 1.1 event that comes back from a 1.0 handler. */
   char getKeyEventChar() {
      switch (key) {
         case HOME:
         case END:
         case PGUP:
         case PGDN:
         case UP:
         case DOWN:
         case LEFT:
         case RIGHT:
         case F1:
         case F2:
         case F3:
         case F4:
         case F5:
         case F6:
         case F7:
         case F8:
         case F9:
         case F10:
         case F11:
         case F12:
         case PRINT_SCREEN:
         case SCROLL_LOCK:
         case CAPS_LOCK:
         case NUM_LOCK:
         case PAUSE:
         case INSERT:
            return KeyEvent.CHAR_UNDEFINED;
         default:
            return (char) key;
      }
   }

   protected String paramString() {
      String str = "id=" + id + ",x=" + x + ",y=" + y;
      if (key != 0) {
         str += ",key=" + key;
      }
      if (shiftDown()) {
         str += ",shift";
      }
      if (controlDown()) {
         str += ",control";
      }
      if (metaDown()) {
         str += ",meta";
      }
      if (target != null) {
         str += ",target=" + target;
      }
      if (arg != null) {
         str += ",arg=" + arg;
      }
      return str;
   }

   public String toString() {
      return getClass().getName() + "[" + paramString() + "]";
   }
}

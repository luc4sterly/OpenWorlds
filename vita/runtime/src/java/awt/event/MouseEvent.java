package java.awt.event;

import java.awt.Component;
import java.awt.Point;

public class MouseEvent extends InputEvent {
   public static final int MOUSE_FIRST = 500;
   public static final int MOUSE_LAST = 507;
   public static final int MOUSE_CLICKED = MOUSE_FIRST;
   public static final int MOUSE_PRESSED = 1 + MOUSE_FIRST;
   public static final int MOUSE_RELEASED = 2 + MOUSE_FIRST;
   public static final int MOUSE_MOVED = 3 + MOUSE_FIRST;
   public static final int MOUSE_ENTERED = 4 + MOUSE_FIRST;
   public static final int MOUSE_EXITED = 5 + MOUSE_FIRST;
   public static final int MOUSE_DRAGGED = 6 + MOUSE_FIRST;
   public static final int MOUSE_WHEEL = 7 + MOUSE_FIRST;
   public static final int NOBUTTON = 0;
   public static final int BUTTON1 = 1;
   public static final int BUTTON2 = 2;
   public static final int BUTTON3 = 3;

   int x;
   int y;
   private int xAbs;
   private int yAbs;
   int clickCount;
   int button;
   boolean popupTrigger;

   public MouseEvent(Component source, int id, long when, int modifiers, int x, int y, int xAbs, int yAbs, int clickCount,
         boolean popupTrigger, int button) {
      super(source, id, when, modifiers);
      this.x = x;
      this.y = y;
      this.xAbs = xAbs;
      this.yAbs = yAbs;
      this.clickCount = clickCount;
      this.popupTrigger = popupTrigger;
      if (button < NOBUTTON || button > BUTTON3) {
         throw new IllegalArgumentException("Invalid button value");
      }
      this.button = button;
      syncModifiers();
   }

   public MouseEvent(Component source, int id, long when, int modifiers, int x, int y, int clickCount, boolean popupTrigger, int button) {
      this(source, id, when, modifiers, x, y, x, y, clickCount, popupTrigger, button);
      if (source != null && source.isShowing()) {
         Point p = source.getLocationOnScreen();
         this.xAbs = p.x + x;
         this.yAbs = p.y + y;
      }
   }

   public MouseEvent(Component source, int id, long when, int modifiers, int x, int y, int clickCount, boolean popupTrigger) {
      this(source, id, when, modifiers, x, y, clickCount, popupTrigger, NOBUTTON);
   }

   public int getX() {
      return x;
   }

   public int getY() {
      return y;
   }

   public int getXOnScreen() {
      return xAbs;
   }

   public int getYOnScreen() {
      return yAbs;
   }

   public Point getPoint() {
      return new Point(x, y);
   }

   public Point getLocationOnScreen() {
      return new Point(xAbs, yAbs);
   }

   public synchronized void translatePoint(int dx, int dy) {
      x += dx;
      y += dy;
   }

   public int getClickCount() {
      return clickCount;
   }

   public int getButton() {
      return button;
   }

   public boolean isPopupTrigger() {
      return popupTrigger;
   }

   public static String getMouseModifiersText(int modifiers) {
      StringBuilder buf = new StringBuilder();
      if ((modifiers & ALT_MASK) != 0) {
         buf.append("Alt+");
      }
      if ((modifiers & META_MASK) != 0) {
         buf.append("Meta+");
      }
      if ((modifiers & CTRL_MASK) != 0) {
         buf.append("Ctrl+");
      }
      if ((modifiers & SHIFT_MASK) != 0) {
         buf.append("Shift+");
      }
      if ((modifiers & BUTTON1_MASK) != 0) {
         buf.append("Button1+");
      }
      if (buf.length() > 0) {
         buf.setLength(buf.length() - 1);
      }
      return buf.toString();
   }

   public String paramString() {
      String type;
      switch (id) {
         case MOUSE_PRESSED:
            type = "MOUSE_PRESSED";
            break;
         case MOUSE_RELEASED:
            type = "MOUSE_RELEASED";
            break;
         case MOUSE_CLICKED:
            type = "MOUSE_CLICKED";
            break;
         case MOUSE_ENTERED:
            type = "MOUSE_ENTERED";
            break;
         case MOUSE_EXITED:
            type = "MOUSE_EXITED";
            break;
         case MOUSE_MOVED:
            type = "MOUSE_MOVED";
            break;
         case MOUSE_DRAGGED:
            type = "MOUSE_DRAGGED";
            break;
         case MOUSE_WHEEL:
            type = "MOUSE_WHEEL";
            break;
         default:
            type = "unknown type";
      }
      return type + ",(" + x + "," + y + "),absolute(" + xAbs + "," + yAbs + "),button=" + button + ",clickCount=" + clickCount;
   }
}

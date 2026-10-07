package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.AdjustmentEvent;
import java.awt.event.ComponentEvent;
import java.awt.event.FocusEvent;
import java.awt.event.InputEvent;
import java.awt.event.ItemEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.WindowEvent;

/** The root of the 1.1 AWT events, as java.awt.AWTEvent, with the JDK's conversion to 1.0 events. */
public abstract class AWTEvent extends java.util.EventObject {
   protected int id;
   protected boolean consumed;

   public static final long COMPONENT_EVENT_MASK = 0x01;
   public static final long CONTAINER_EVENT_MASK = 0x02;
   public static final long FOCUS_EVENT_MASK = 0x04;
   public static final long KEY_EVENT_MASK = 0x08;
   public static final long MOUSE_EVENT_MASK = 0x10;
   public static final long MOUSE_MOTION_EVENT_MASK = 0x20;
   public static final long WINDOW_EVENT_MASK = 0x40;
   public static final long ACTION_EVENT_MASK = 0x80;
   public static final long ADJUSTMENT_EVENT_MASK = 0x100;
   public static final long ITEM_EVENT_MASK = 0x200;
   public static final long TEXT_EVENT_MASK = 0x400;
   public static final long INPUT_METHOD_EVENT_MASK = 0x800;
   public static final long PAINT_EVENT_MASK = 0x2000;
   public static final long INVOCATION_EVENT_MASK = 0x4000;
   public static final long HIERARCHY_EVENT_MASK = 0x8000;
   public static final long HIERARCHY_BOUNDS_EVENT_MASK = 0x10000;
   public static final long MOUSE_WHEEL_EVENT_MASK = 0x20000;
   public static final long WINDOW_STATE_EVENT_MASK = 0x40000;
   public static final long WINDOW_FOCUS_EVENT_MASK = 0x80000;
   public static final int RESERVED_ID_MAX = 1999;

   public AWTEvent(Event event) {
      this(event.target, event.id);
   }

   public AWTEvent(Object source, int id) {
      super(source);
      this.id = id;
      switch (id) {
         case ActionEvent.ACTION_PERFORMED:
         case ItemEvent.ITEM_STATE_CHANGED:
         case AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED:
         case 900: // TextEvent.TEXT_VALUE_CHANGED
            consumed = true;
            break;
         default:
      }
   }

   public void setSource(Object newSource) {
      this.source = newSource;
   }

   public int getID() {
      return id;
   }

   public String paramString() {
      return "";
   }

   public String toString() {
      String srcName = null;
      if (source instanceof Component) {
         srcName = ((Component) source).getName();
      } else if (source instanceof MenuComponent) {
         srcName = ((MenuComponent) source).getName();
      }
      return getClass().getName() + "[" + paramString() + "] on " + (srcName != null ? srcName : source);
   }

   protected void consume() {
      switch (id) {
         case KeyEvent.KEY_PRESSED:
         case KeyEvent.KEY_RELEASED:
         case MouseEvent.MOUSE_PRESSED:
         case MouseEvent.MOUSE_RELEASED:
         case MouseEvent.MOUSE_MOVED:
         case MouseEvent.MOUSE_DRAGGED:
         case MouseEvent.MOUSE_ENTERED:
         case MouseEvent.MOUSE_EXITED:
         case MouseEvent.MOUSE_WHEEL:
            consumed = true;
            break;
         default:
      }
   }

   protected boolean isConsumed() {
      return consumed;
   }

   boolean consumedFlag() {
      return consumed;
   }

   void consumeAny() {
      consumed = true;
   }

   /** The 1.0 event the JDK makes from this one, or null (AWTEvent.convertToOld). */
   Event convertToOld() {
      Object src = getSource();
      int newid = id;
      switch (id) {
         case KeyEvent.KEY_PRESSED:
         case KeyEvent.KEY_RELEASED: {
            KeyEvent ke = (KeyEvent) this;
            if (ke.isActionKey()) {
               newid = (id == KeyEvent.KEY_PRESSED ? Event.KEY_ACTION : Event.KEY_ACTION_RELEASE);
            }
            int keyCode = ke.getKeyCode();
            if (keyCode == KeyEvent.VK_SHIFT || keyCode == KeyEvent.VK_CONTROL || keyCode == KeyEvent.VK_ALT) {
               return null;
            }
            return new Event(src, ke.getWhen(), newid, 0, 0, Event.getOldEventKey(ke), (ke.getModifiers() & ~InputEvent.BUTTON1_MASK));
         }
         case MouseEvent.MOUSE_PRESSED:
         case MouseEvent.MOUSE_RELEASED:
         case MouseEvent.MOUSE_MOVED:
         case MouseEvent.MOUSE_DRAGGED:
         case MouseEvent.MOUSE_ENTERED:
         case MouseEvent.MOUSE_EXITED: {
            MouseEvent me = (MouseEvent) this;
            Event olde = new Event(src, me.getWhen(), newid, me.getX(), me.getY(), 0, (me.getModifiers() & ~InputEvent.BUTTON1_MASK));
            olde.clickCount = me.getClickCount();
            return olde;
         }
         case FocusEvent.FOCUS_GAINED:
            return new Event(src, Event.GOT_FOCUS, null);
         case FocusEvent.FOCUS_LOST:
            return new Event(src, Event.LOST_FOCUS, null);
         case WindowEvent.WINDOW_CLOSING:
         case WindowEvent.WINDOW_ICONIFIED:
         case WindowEvent.WINDOW_DEICONIFIED:
            return new Event(src, newid, null);
         case ComponentEvent.COMPONENT_MOVED:
            if (src instanceof Frame || src instanceof Dialog) {
               Point p = ((Component) src).getLocation();
               return new Event(src, 0, Event.WINDOW_MOVED, p.x, p.y, 0, 0);
            }
            break;
         case ActionEvent.ACTION_PERFORMED: {
            ActionEvent ae = (ActionEvent) this;
            String cmd;
            if (src instanceof Button) {
               cmd = ((Button) src).getLabel();
            } else if (src instanceof MenuItem) {
               cmd = ((MenuItem) src).getLabel();
            } else {
               cmd = ae.getActionCommand();
            }
            return new Event(src, 0, newid, 0, 0, 0, ae.getModifiers(), cmd);
         }
         case ItemEvent.ITEM_STATE_CHANGED: {
            ItemEvent ie = (ItemEvent) this;
            Object arg;
            if (src instanceof List) {
               newid = (ie.getStateChange() == ItemEvent.SELECTED ? Event.LIST_SELECT : Event.LIST_DESELECT);
               arg = ie.getItem();
            } else {
               newid = Event.ACTION_EVENT;
               if (src instanceof Choice) {
                  arg = ie.getItem();
               } else {
                  arg = Boolean.valueOf(ie.getStateChange() == ItemEvent.SELECTED);
               }
            }
            return new Event(src, newid, arg);
         }
         case AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED: {
            AdjustmentEvent aje = (AdjustmentEvent) this;
            switch (aje.getAdjustmentType()) {
               case AdjustmentEvent.UNIT_INCREMENT:
                  newid = Event.SCROLL_LINE_DOWN;
                  break;
               case AdjustmentEvent.UNIT_DECREMENT:
                  newid = Event.SCROLL_LINE_UP;
                  break;
               case AdjustmentEvent.BLOCK_INCREMENT:
                  newid = Event.SCROLL_PAGE_DOWN;
                  break;
               case AdjustmentEvent.BLOCK_DECREMENT:
                  newid = Event.SCROLL_PAGE_UP;
                  break;
               case AdjustmentEvent.TRACK:
                  newid = aje.getValueIsAdjusting() ? Event.SCROLL_ABSOLUTE : Event.SCROLL_END;
                  break;
               default:
                  return null;
            }
            return new Event(src, newid, Integer.valueOf(aje.getValue()));
         }
         default:
      }
      return null;
   }
}

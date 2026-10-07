package java.awt;

import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

/** A scroll bar, as java.awt.Scrollbar: AdjustmentEvents (1.0: SCROLL_* events with the value). */
public class Scrollbar extends Component implements Adjustable {
   public static final int HORIZONTAL = 0;
   public static final int VERTICAL = 1;

   final ScrollState state;
   int orientation;
   transient AdjustmentListener adjustmentListener;
   private int pressedPart;
   private int dragOffset;
   private boolean dragging;

   public Scrollbar() {
      this(VERTICAL, 0, 10, 0, 100);
   }

   public Scrollbar(int orientation) {
      this(orientation, 0, 10, 0, 100);
   }

   public Scrollbar(int orientation, int value, int visible, int minimum, int maximum) {
      if (orientation != HORIZONTAL && orientation != VERTICAL) {
         throw new IllegalArgumentException("illegal scrollbar orientation");
      }
      this.orientation = orientation;
      this.state = new ScrollState(orientation == VERTICAL);
      state.set(value, visible, minimum, maximum);
   }

   public int getOrientation() {
      return orientation;
   }

   public void setOrientation(int orientation) {
      this.orientation = orientation;
      state.vertical = orientation == VERTICAL;
      invalidate();
      repaint();
   }

   public int getValue() {
      return state.value;
   }

   public void setValue(int newValue) {
      setValues(newValue, state.visible, state.minimum, state.maximum);
   }

   public int getMinimum() {
      return state.minimum;
   }

   public void setMinimum(int newMinimum) {
      setValues(state.value, state.visible, newMinimum, state.maximum);
   }

   public int getMaximum() {
      return state.maximum;
   }

   public void setMaximum(int newMaximum) {
      setValues(state.value, state.visible, state.minimum, newMaximum);
   }

   public int getVisibleAmount() {
      return getVisible();
   }

   public int getVisible() {
      return state.visible;
   }

   public void setVisibleAmount(int newAmount) {
      setValues(state.value, newAmount, state.minimum, state.maximum);
   }

   public void setUnitIncrement(int v) {
      setLineIncrement(v);
   }

   public synchronized void setLineIncrement(int v) {
      state.unit = Math.max(1, v);
   }

   public int getUnitIncrement() {
      return getLineIncrement();
   }

   public int getLineIncrement() {
      return state.unit;
   }

   public void setBlockIncrement(int v) {
      setPageIncrement(v);
   }

   public synchronized void setPageIncrement(int v) {
      state.block = Math.max(1, v);
   }

   public int getBlockIncrement() {
      return getPageIncrement();
   }

   public int getPageIncrement() {
      return state.block;
   }

   public void setValues(int value, int visible, int minimum, int maximum) {
      synchronized (this) {
         state.set(value, visible, minimum, maximum);
      }
      repaint();
   }

   public boolean getValueIsAdjusting() {
      return dragging;
   }

   public void setValueIsAdjusting(boolean b) {
   }

   public synchronized void addAdjustmentListener(AdjustmentListener l) {
      if (l == null) {
         return;
      }
      adjustmentListener = AWTEventMulticaster.add(adjustmentListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeAdjustmentListener(AdjustmentListener l) {
      if (l == null) {
         return;
      }
      adjustmentListener = AWTEventMulticaster.remove(adjustmentListener, l);
   }

   public synchronized AdjustmentListener[] getAdjustmentListeners() {
      ArrayList<AdjustmentListener> out = new ArrayList<AdjustmentListener>();
      collect(adjustmentListener, out);
      return out.toArray(new AdjustmentListener[out.size()]);
   }

   private static void collect(AdjustmentListener l, ArrayList<AdjustmentListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((AdjustmentListener) ((AWTEventMulticaster) l).a, out);
         collect((AdjustmentListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   boolean eventEnabled(AWTEvent e) {
      if (e.id == AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED) {
         return (eventMask & AWTEvent.ADJUSTMENT_EVENT_MASK) != 0 || adjustmentListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof AdjustmentEvent) {
         processAdjustmentEvent((AdjustmentEvent) e);
         return;
      }
      super.processEvent(e);
   }

   protected void processAdjustmentEvent(AdjustmentEvent e) {
      AdjustmentListener listener = adjustmentListener;
      if (listener != null) {
         listener.adjustmentValueChanged(e);
      }
   }

   Dimension peerMinimumSize() {
      return orientation == VERTICAL ? new Dimension(Theme.SCROLLBAR, 50) : new Dimension(50, Theme.SCROLLBAR);
   }

   boolean traversable() {
      return false;
   }

   private void step(int type, int delta) {
      int nv = state.clamp(state.value + delta);
      if (nv != state.value) {
         state.value = nv;
         repaint();
         EventQueue.post(new AdjustmentEvent(this, AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED, type, nv, false));
      }
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED: {
            MouseEvent m = (MouseEvent) e;
            pressedPart = state.hit(m.getX(), m.getY(), width, height);
            switch (pressedPart) {
               case ScrollState.ARROW_DEC:
                  Repeater.start(new Runnable() {
                     public void run() {
                        step(AdjustmentEvent.UNIT_DECREMENT, -state.unit);
                     }
                  });
                  break;
               case ScrollState.ARROW_INC:
                  Repeater.start(new Runnable() {
                     public void run() {
                        step(AdjustmentEvent.UNIT_INCREMENT, state.unit);
                     }
                  });
                  break;
               case ScrollState.TRACK_DEC:
                  Repeater.start(new Runnable() {
                     public void run() {
                        step(AdjustmentEvent.BLOCK_DECREMENT, -state.block);
                     }
                  });
                  break;
               case ScrollState.TRACK_INC:
                  Repeater.start(new Runnable() {
                     public void run() {
                        step(AdjustmentEvent.BLOCK_INCREMENT, state.block);
                     }
                  });
                  break;
               case ScrollState.THUMB: {
                  int[] t = state.thumb(orientation == VERTICAL ? height : width);
                  dragOffset = (orientation == VERTICAL ? m.getY() : m.getX()) - t[0];
                  dragging = true;
                  break;
               }
               default:
            }
            repaint();
            break;
         }
         case MouseEvent.MOUSE_DRAGGED:
            if (dragging) {
               MouseEvent m = (MouseEvent) e;
               int along = (orientation == VERTICAL ? m.getY() : m.getX()) - dragOffset;
               int nv = state.valueAt(along, orientation == VERTICAL ? height : width);
               if (nv != state.value) {
                  state.value = nv;
                  repaint();
                  EventQueue.post(new AdjustmentEvent(this, AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED, AdjustmentEvent.TRACK, nv, true));
               }
            }
            break;
         case MouseEvent.MOUSE_RELEASED:
            Repeater.stop();
            if (dragging) {
               dragging = false;
               EventQueue.post(new AdjustmentEvent(this, AdjustmentEvent.ADJUSTMENT_VALUE_CHANGED, AdjustmentEvent.TRACK, state.value, false));
            }
            pressedPart = ScrollState.NONE;
            repaint();
            break;
         case KeyEvent.KEY_PRESSED: {
            int k = ((KeyEvent) e).getKeyCode();
            boolean v = orientation == VERTICAL;
            if (k == (v ? KeyEvent.VK_UP : KeyEvent.VK_LEFT)) {
               step(AdjustmentEvent.UNIT_DECREMENT, -state.unit);
            } else if (k == (v ? KeyEvent.VK_DOWN : KeyEvent.VK_RIGHT)) {
               step(AdjustmentEvent.UNIT_INCREMENT, state.unit);
            } else if (k == KeyEvent.VK_PAGE_UP) {
               step(AdjustmentEvent.BLOCK_DECREMENT, -state.block);
            } else if (k == KeyEvent.VK_PAGE_DOWN) {
               step(AdjustmentEvent.BLOCK_INCREMENT, state.block);
            }
            break;
         }
         default:
      }
   }

   void paintPeer(Graphics g) {
      state.paint(g, 0, 0, width, height, enabled, pressedPart);
   }

   protected String paramString() {
      return super.paramString() + ",val=" + state.value + ",vis=" + state.visible + ",min=" + state.minimum + ",max=" + state.maximum
            + (orientation == VERTICAL ? ",vert" : ",horz");
   }
}

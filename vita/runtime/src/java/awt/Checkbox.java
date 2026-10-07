package java.awt;

import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

/** A check box, or a radio button in a CheckboxGroup, as java.awt.Checkbox. */
public class Checkbox extends Component implements ItemSelectable {
   String label;
   boolean state;
   CheckboxGroup group;
   transient ItemListener itemListener;
   private boolean armed;

   public Checkbox() {
      this("", false, null);
   }

   public Checkbox(String label) {
      this(label, false, null);
   }

   public Checkbox(String label, boolean state) {
      this(label, state, null);
   }

   public Checkbox(String label, boolean state, CheckboxGroup group) {
      this.label = label;
      this.state = state;
      this.group = group;
      if (state && group != null) {
         group.setSelectedCheckbox(this);
      }
   }

   public Checkbox(String label, CheckboxGroup group, boolean state) {
      this(label, state, group);
   }

   public String getLabel() {
      return label;
   }

   public synchronized void setLabel(String label) {
      this.label = label;
      if (valid) {
         invalidate();
      }
      repaint();
   }

   public boolean getState() {
      return state;
   }

   void setStateInternal(boolean state) {
      if (this.state != state) {
         this.state = state;
         repaint();
      }
   }

   public void setState(boolean state) {
      CheckboxGroup g = group;
      if (g != null) {
         if (state) {
            g.setSelectedCheckbox(this);
         } else if (g.getSelectedCheckbox() == this) {
            state = true;
         }
      }
      setStateInternal(state);
   }

   public Object[] getSelectedObjects() {
      return state ? new Object[]{label} : null;
   }

   public CheckboxGroup getCheckboxGroup() {
      return group;
   }

   public void setCheckboxGroup(CheckboxGroup g) {
      CheckboxGroup old = group;
      if (old == g) {
         return;
      }
      if (old != null && old.getSelectedCheckbox() == this) {
         old.setSelectedCheckbox(null);
      }
      group = g;
      if (g != null) {
         if (g.getSelectedCheckbox() != null && state) {
            setStateInternal(false);
         } else if (state) {
            g.setSelectedCheckbox(this);
         }
      }
      repaint();
   }

   public synchronized void addItemListener(ItemListener l) {
      if (l == null) {
         return;
      }
      itemListener = AWTEventMulticaster.add(itemListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeItemListener(ItemListener l) {
      if (l == null) {
         return;
      }
      itemListener = AWTEventMulticaster.remove(itemListener, l);
   }

   public synchronized ItemListener[] getItemListeners() {
      ArrayList<ItemListener> out = new ArrayList<ItemListener>();
      collect(itemListener, out);
      return out.toArray(new ItemListener[out.size()]);
   }

   static void collect(ItemListener l, ArrayList<ItemListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((ItemListener) ((AWTEventMulticaster) l).a, out);
         collect((ItemListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   boolean eventEnabled(AWTEvent e) {
      if (e.id == ItemEvent.ITEM_STATE_CHANGED) {
         return (eventMask & AWTEvent.ITEM_EVENT_MASK) != 0 || itemListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof ItemEvent) {
         processItemEvent((ItemEvent) e);
         return;
      }
      super.processEvent(e);
   }

   protected void processItemEvent(ItemEvent e) {
      ItemListener listener = itemListener;
      if (listener != null) {
         listener.itemStateChanged(e);
      }
   }

   boolean traversable() {
      return true;
   }

   boolean focusDrawn() {
      return true;
   }

   Dimension peerMinimumSize() {
      FontMetrics fm = getFontMetrics(getFont());
      String l = label == null ? "" : label;
      return new Dimension(fm.stringWidth(l) + 13 + 6 + 4, Math.max(fm.getHeight() + 8, 13 + 8));
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED:
            armed = true;
            repaint();
            break;
         case MouseEvent.MOUSE_RELEASED: {
            MouseEvent m = (MouseEvent) e;
            boolean inside = m.getX() >= 0 && m.getY() >= 0 && m.getX() < width && m.getY() < height;
            if (armed && inside) {
               toggle();
            }
            armed = false;
            repaint();
            break;
         }
         case KeyEvent.KEY_RELEASED:
            if (((KeyEvent) e).getKeyCode() == KeyEvent.VK_SPACE) {
               toggle();
            }
            break;
         default:
      }
   }

   private void toggle() {
      if (group != null) {
         if (state) {
            return;
         }
         setState(true);
      } else {
         setState(!state);
      }
      EventQueue.post(new ItemEvent(this, ItemEvent.ITEM_STATE_CHANGED, label, state ? ItemEvent.SELECTED : ItemEvent.DESELECTED));
   }

   void paintPeer(Graphics g) {
      Color bg = getBackground();
      if (bg != null) {
         g.setColor(bg);
         g.fillRect(0, 0, width, height);
      }
      Font f = getFont();
      if (f != null) {
         g.setFont(f);
      }
      FontMetrics fm = g.getFontMetrics();
      int box = 13;
      int by = (height - box) / 2;
      if (group == null) {
         Theme.sunken(g, 0, by, box, box);
         g.setColor(enabled && !armed ? Theme.WINDOW : Theme.CONTROL);
         g.fillRect(2, by + 2, box - 4, box - 4);
         if (state) {
            g.setColor(enabled ? Color.black : Theme.SHADOW);
            int cx = 3;
            int cy = by + 5;
            for (int i = 0; i < 3; i++) {
               g.drawLine(cx + i, cy + i, cx + i, cy + i + 2);
            }
            for (int i = 0; i < 4; i++) {
               g.drawLine(cx + 3 + i, cy + 1 - i, cx + 3 + i, cy + 3 - i);
            }
         }
      } else {
         g.setColor(Theme.SHADOW);
         g.drawArc(0, by, box - 1, box - 1, 45, 180);
         g.setColor(Theme.HIGHLIGHT);
         g.drawArc(0, by, box - 1, box - 1, 225, 180);
         g.setColor(enabled && !armed ? Theme.WINDOW : Theme.CONTROL);
         g.fillOval(2, by + 2, box - 4, box - 4);
         if (state) {
            g.setColor(enabled ? Color.black : Theme.SHADOW);
            g.fillOval(4, by + 4, 5, 5);
         }
      }
      String l = label == null ? "" : label;
      int tx = box + 4;
      int ty = (height - fm.getHeight()) / 2 + fm.getAscent();
      if (enabled) {
         Color fg = getForeground();
         g.setColor(fg != null ? fg : Color.black);
         g.drawString(l, tx, ty);
      } else {
         Theme.disabledString(g, l, tx, ty);
      }
      if (isFocusOwner() && l.length() > 0) {
         Theme.focusRect(g, tx - 2, (height - fm.getHeight()) / 2, fm.stringWidth(l) + 4, fm.getHeight());
      }
   }

   protected String paramString() {
      return super.paramString() + ",label=" + label + ",state=" + state;
   }
}

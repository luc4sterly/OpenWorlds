package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.MouseWheelEvent;
import java.util.ArrayList;
import java.util.Vector;

/**
 * A scrolling list of items, as java.awt.List (Windows' list box): a click
 * selects (ItemEvent, 1.0: LIST_SELECT/LIST_DESELECT), a double click or
 * Enter acts (ActionEvent, 1.0: ACTION_EVENT with the item).
 */
public class List extends Component implements ItemSelectable {
   final Vector<String> items = new Vector<String>();
   int rows;
   boolean multipleMode;
   final ArrayList<Integer> selected = new ArrayList<Integer>();
   int visibleIndex = -1;
   transient ActionListener actionListener;
   transient ItemListener itemListener;
   private int top;
   /** The item with the dotted focus frame. */
   private int focusIndex;
   private final ScrollState bar = new ScrollState(true);
   private int barPressed;
   private boolean dragging;
   private int dragOffset;

   static final int DEFAULT_VISIBLE_ROWS = 4;

   public List() {
      this(0, false);
   }

   public List(int rows) {
      this(rows, false);
   }

   public List(int rows, boolean multipleMode) {
      this.rows = rows != 0 ? rows : DEFAULT_VISIBLE_ROWS;
      this.multipleMode = multipleMode;
   }

   public int getItemCount() {
      return countItems();
   }

   public int countItems() {
      return items.size();
   }

   public String getItem(int index) {
      return items.elementAt(index);
   }

   public synchronized String[] getItems() {
      String[] s = new String[items.size()];
      items.copyInto(s);
      return s;
   }

   public void add(String item) {
      addItem(item);
   }

   public void add(String item, int index) {
      addItem(item, index);
   }

   public void addItem(String item) {
      addItem(item, -1);
   }

   public synchronized void addItem(String item, int index) {
      if (index < -1 || index >= items.size()) {
         index = -1;
      }
      if (item == null) {
         item = "";
      }
      if (index == -1) {
         items.addElement(item);
      } else {
         items.insertElementAt(item, index);
         for (int i = 0; i < selected.size(); i++) {
            int s = selected.get(i).intValue();
            if (s >= index) {
               selected.set(i, Integer.valueOf(s + 1));
            }
         }
      }
      changed();
   }

   public synchronized void replaceItem(String newValue, int index) {
      items.setElementAt(newValue == null ? "" : newValue, index);
      repaint();
   }

   public void removeAll() {
      clear();
   }

   public synchronized void clear() {
      items.removeAllElements();
      selected.clear();
      top = 0;
      focusIndex = 0;
      changed();
   }

   public synchronized void remove(String item) {
      int index = items.indexOf(item);
      if (index < 0) {
         throw new IllegalArgumentException("item " + item + " not found in list");
      }
      remove(index);
   }

   public void remove(int position) {
      delItem(position);
   }

   public void delItem(int position) {
      delItems(position, position);
   }

   public synchronized void delItems(int start, int end) {
      for (int i = end; i >= start; i--) {
         items.removeElementAt(i);
         ArrayList<Integer> keep = new ArrayList<Integer>();
         for (Integer s : selected) {
            int v = s.intValue();
            if (v < i) {
               keep.add(s);
            } else if (v > i) {
               keep.add(Integer.valueOf(v - 1));
            }
         }
         selected.clear();
         selected.addAll(keep);
      }
      changed();
   }

   private void changed() {
      updateBar();
      repaint();
   }

   public synchronized int getSelectedIndex() {
      int[] sel = getSelectedIndexes();
      return sel.length == 1 ? sel[0] : -1;
   }

   public synchronized int[] getSelectedIndexes() {
      int[] out = new int[selected.size()];
      for (int i = 0; i < out.length; i++) {
         out[i] = selected.get(i).intValue();
      }
      java.util.Arrays.sort(out);
      return out;
   }

   public synchronized String getSelectedItem() {
      int index = getSelectedIndex();
      return index < 0 ? null : getItem(index);
   }

   public synchronized String[] getSelectedItems() {
      int[] sel = getSelectedIndexes();
      String[] str = new String[sel.length];
      for (int i = 0; i < sel.length; i++) {
         str[i] = getItem(sel[i]);
      }
      return str;
   }

   public Object[] getSelectedObjects() {
      return getSelectedItems();
   }

   public void select(int index) {
      synchronized (this) {
         if (index < 0 || index >= items.size()) {
            return;
         }
         if (!multipleMode) {
            selected.clear();
         }
         if (!selected.contains(Integer.valueOf(index))) {
            selected.add(Integer.valueOf(index));
         }
         focusIndex = index;
      }
      repaint();
   }

   public synchronized void deselect(int index) {
      selected.remove(Integer.valueOf(index));
      repaint();
   }

   public boolean isIndexSelected(int index) {
      return isSelected(index);
   }

   public synchronized boolean isSelected(int index) {
      return selected.contains(Integer.valueOf(index));
   }

   public int getRows() {
      return rows;
   }

   public boolean isMultipleMode() {
      return allowsMultipleSelections();
   }

   public boolean allowsMultipleSelections() {
      return multipleMode;
   }

   public void setMultipleMode(boolean b) {
      setMultipleSelections(b);
   }

   public synchronized void setMultipleSelections(boolean b) {
      multipleMode = b;
      if (!b && selected.size() > 1) {
         Integer last = selected.get(selected.size() - 1);
         selected.clear();
         selected.add(last);
      }
      repaint();
   }

   public int getVisibleIndex() {
      return visibleIndex;
   }

   public synchronized void makeVisible(int index) {
      visibleIndex = index;
      int page = pageRows();
      if (index < top) {
         top = index;
      } else if (index >= top + page) {
         top = index - page + 1;
      }
      updateBar();
      repaint();
   }

   public Dimension getPreferredSize(int rows) {
      return preferredSize(rows);
   }

   public Dimension preferredSize(int rows) {
      return minimumSize(rows);
   }

   public Dimension getMinimumSize(int rows) {
      return minimumSize(rows);
   }

   public Dimension minimumSize(int rows) {
      FontMetrics fm = getFontMetrics(getFont());
      return new Dimension(20 + fm.stringWidth("0123456789abcde"), fm.getHeight() * rows + 4);
   }

   Dimension peerMinimumSize() {
      return minimumSize(rows > 0 ? rows : DEFAULT_VISIBLE_ROWS);
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
      Checkbox.collect(itemListener, out);
      return out.toArray(new ItemListener[out.size()]);
   }

   public synchronized void addActionListener(ActionListener l) {
      if (l == null) {
         return;
      }
      actionListener = AWTEventMulticaster.add(actionListener, l);
      newEventsOnly = true;
   }

   public synchronized void removeActionListener(ActionListener l) {
      if (l == null) {
         return;
      }
      actionListener = AWTEventMulticaster.remove(actionListener, l);
   }

   public synchronized ActionListener[] getActionListeners() {
      ArrayList<ActionListener> out = new ArrayList<ActionListener>();
      Button.collect(actionListener, out);
      return out.toArray(new ActionListener[out.size()]);
   }

   boolean eventEnabled(AWTEvent e) {
      switch (e.id) {
         case ActionEvent.ACTION_PERFORMED:
            return (eventMask & AWTEvent.ACTION_EVENT_MASK) != 0 || actionListener != null;
         case ItemEvent.ITEM_STATE_CHANGED:
            return (eventMask & AWTEvent.ITEM_EVENT_MASK) != 0 || itemListener != null;
         default:
      }
      return super.eventEnabled(e);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof ItemEvent) {
         processItemEvent((ItemEvent) e);
         return;
      } else if (e instanceof ActionEvent) {
         processActionEvent((ActionEvent) e);
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

   protected void processActionEvent(ActionEvent e) {
      ActionListener listener = actionListener;
      if (listener != null) {
         listener.actionPerformed(e);
      }
   }

   boolean traversable() {
      return true;
   }

   boolean focusDrawn() {
      return true;
   }

   boolean handlesWheel() {
      return true;
   }

   // ------------------------------------------------------------------ the control

   private int rowHeight() {
      return Math.max(1, getFontMetrics(getFont()).getHeight());
   }

   private int pageRows() {
      return Math.max(1, (height - 4) / rowHeight());
   }

   private boolean barShown() {
      return items.size() > pageRows();
   }

   private void updateBar() {
      int page = pageRows();
      bar.set(top, page, 0, Math.max(items.size(), page));
      bar.unit = 1;
      bar.block = Math.max(1, page - 1);
      top = bar.value;
   }

   void boundsChanged(int oldX, int oldY, int oldW, int oldH, boolean resized, boolean moved) {
      if (resized) {
         updateBar();
      }
      super.boundsChanged(oldX, oldY, oldW, oldH, resized, moved);
   }

   private void choose(int index, boolean ctrl) {
      if (index < 0 || index >= items.size()) {
         return;
      }
      focusIndex = index;
      if (multipleMode) {
         boolean was = isSelected(index);
         if (was) {
            deselect(index);
         } else {
            select(index);
         }
         EventQueue.post(new ItemEvent(this, ItemEvent.ITEM_STATE_CHANGED, Integer.valueOf(index), was ? ItemEvent.DESELECTED : ItemEvent.SELECTED));
      } else {
         if (isSelected(index) && selected.size() == 1) {
            makeVisible(index);
            return;
         }
         select(index);
         makeVisible(index);
         EventQueue.post(new ItemEvent(this, ItemEvent.ITEM_STATE_CHANGED, Integer.valueOf(index), ItemEvent.SELECTED));
      }
   }

   private void act(int index, int modifiers) {
      if (index >= 0 && index < items.size()) {
         EventQueue.post(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, getItem(index), System.currentTimeMillis(), modifiers));
      }
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      int barX = width - 2 - Theme.SCROLLBAR;
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED: {
            MouseEvent m = (MouseEvent) e;
            if (barShown() && m.getX() >= barX) {
               pressBar(m.getY() - 2);
               return;
            }
            int index = top + (m.getY() - 2) / rowHeight();
            if (index < items.size()) {
               if (m.getClickCount() >= 2) {
                  act(index, m.getModifiers());
               } else {
                  choose(index, m.isControlDown());
               }
            }
            break;
         }
         case MouseEvent.MOUSE_DRAGGED:
            if (dragging) {
               MouseEvent m = (MouseEvent) e;
               bar.value = bar.valueAt(m.getY() - 2 - dragOffset, height - 4);
               top = bar.value;
               repaint();
            }
            break;
         case MouseEvent.MOUSE_RELEASED:
            Repeater.stop();
            dragging = false;
            barPressed = ScrollState.NONE;
            repaint();
            break;
         case MouseEvent.MOUSE_WHEEL:
            bar.value = bar.clamp(bar.value + ((MouseWheelEvent) e).getUnitsToScroll());
            top = bar.value;
            repaint();
            break;
         case KeyEvent.KEY_PRESSED: {
            KeyEvent k = (KeyEvent) e;
            int n = items.size();
            if (n == 0) {
               break;
            }
            int cur = focusIndex;
            int target = -1;
            switch (k.getKeyCode()) {
               case KeyEvent.VK_UP:
                  target = Math.max(0, cur - 1);
                  break;
               case KeyEvent.VK_DOWN:
                  target = Math.min(n - 1, cur + 1);
                  break;
               case KeyEvent.VK_PAGE_UP:
                  target = Math.max(0, cur - pageRows() + 1);
                  break;
               case KeyEvent.VK_PAGE_DOWN:
                  target = Math.min(n - 1, cur + pageRows() - 1);
                  break;
               case KeyEvent.VK_HOME:
                  target = 0;
                  break;
               case KeyEvent.VK_END:
                  target = n - 1;
                  break;
               case KeyEvent.VK_ENTER:
                  act(cur, k.getModifiers());
                  break;
               case KeyEvent.VK_SPACE:
                  if (multipleMode) {
                     choose(cur, true);
                  }
                  break;
               default:
            }
            if (target >= 0) {
               if (multipleMode) {
                  focusIndex = target;
                  makeVisible(target);
               } else {
                  choose(target, false);
               }
            }
            break;
         }
         default:
      }
   }

   private void pressBar(int py) {
      int h = height - 4;
      barPressed = bar.hit(Theme.SCROLLBAR / 2, py, Theme.SCROLLBAR, h);
      final int delta;
      switch (barPressed) {
         case ScrollState.ARROW_DEC:
            delta = -1;
            break;
         case ScrollState.ARROW_INC:
            delta = 1;
            break;
         case ScrollState.TRACK_DEC:
            delta = -bar.block;
            break;
         case ScrollState.TRACK_INC:
            delta = bar.block;
            break;
         default: {
            int[] t = bar.thumb(h);
            dragOffset = py - t[0];
            dragging = true;
            repaint();
            return;
         }
      }
      Repeater.start(new Runnable() {
         public void run() {
            bar.value = bar.clamp(bar.value + delta);
            top = bar.value;
            repaint();
         }
      });
   }

   void paintPeer(Graphics g) {
      Theme.sunken(g, 0, 0, width, height);
      Color bg = getBackground();
      if (bg == null || bg.equals(Theme.CONTROL)) {
         bg = Theme.WINDOW;
      }
      g.setColor(bg);
      g.fillRect(2, 2, width - 4, height - 4);
      Font f = getFont();
      if (f != null) {
         g.setFont(f);
      }
      FontMetrics fm = g.getFontMetrics();
      boolean showBar = barShown();
      int textW = width - 4 - (showBar ? Theme.SCROLLBAR : 0);
      Graphics inner = g.create(2, 2, textW, height - 4);
      try {
         int rh = fm.getHeight();
         Color fg = enabled ? (getForeground() != null ? getForeground() : Color.black) : Theme.DISABLED_TEXT;
         boolean focused = isFocusOwner();
         for (int i = top, y = 0; i < items.size() && y < height - 4; i++, y += rh) {
            boolean sel = isSelected(i);
            if (sel) {
               inner.setColor(focused || !multipleMode ? Theme.SELECTION : Theme.CONTROL);
               inner.fillRect(0, y, textW, rh);
               inner.setColor(Theme.SELECTION_TEXT);
            } else {
               inner.setColor(fg);
            }
            inner.drawString(items.elementAt(i), 2, y + fm.getAscent());
            if (focused && i == focusIndex) {
               Theme.focusRect(inner, 0, y, textW, rh);
            }
         }
      } finally {
         inner.dispose();
      }
      if (showBar) {
         bar.paint(g, width - 2 - Theme.SCROLLBAR, 2, Theme.SCROLLBAR, height - 4, enabled, barPressed);
      }
   }

   protected String paramString() {
      return super.paramString() + ",selected=" + getSelectedItem();
   }
}

package java.awt;

import java.awt.event.InputEvent;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.util.EventListener;
import java.util.Vector;

/**
 * A drop-down list of strings, as java.awt.Choice (Windows' drop-down list
 * combo box): a field with the selected item and a button that opens
 * {@link ChoiceList}. A choice by the user selects the item on the event
 * thread and then posts an ItemEvent (1.0: ACTION_EVENT with the item), as
 * WChoicePeer.handleAction did.
 */
public class Choice extends Component implements ItemSelectable {
   Vector<String> pItems = new Vector<String>();
   int selectedIndex = -1;
   transient ItemListener itemListener;

   private static int nameCounter;

   public Choice() {
   }

   String constructComponentName() {
      synchronized (Choice.class) {
         return "choice" + nameCounter++;
      }
   }

   public int getItemCount() {
      return countItems();
   }

   /** @deprecated */
   @Deprecated
   public int countItems() {
      return pItems.size();
   }

   public String getItem(int index) {
      return pItems.elementAt(index);
   }

   public void add(String item) {
      addItem(item);
   }

   public void addItem(String item) {
      synchronized (this) {
         insertNoInvalidate(item, pItems.size());
      }
      if (valid) {
         invalidate();
      }
   }

   private void insertNoInvalidate(String item, int index) {
      if (item == null) {
         throw new NullPointerException("cannot add null item to Choice");
      }
      pItems.insertElementAt(item, index);
      // no selection, or the selection moved down: the first item, as the JDK
      if (selectedIndex < 0 || selectedIndex >= index) {
         select(0);
      }
      changed();
   }

   public void insert(String item, int index) {
      synchronized (this) {
         if (index < 0) {
            throw new IllegalArgumentException("index less than zero.");
         }
         index = Math.min(index, pItems.size());
         insertNoInvalidate(item, index);
      }
      if (valid) {
         invalidate();
      }
   }

   public void remove(String item) {
      synchronized (this) {
         int index = pItems.indexOf(item);
         if (index < 0) {
            throw new IllegalArgumentException("item " + item + " not found in choice");
         }
         removeNoInvalidate(index);
      }
      if (valid) {
         invalidate();
      }
   }

   public void remove(int position) {
      synchronized (this) {
         removeNoInvalidate(position);
      }
      if (valid) {
         invalidate();
      }
   }

   private void removeNoInvalidate(int position) {
      pItems.removeElementAt(position);
      if (pItems.size() == 0) {
         selectedIndex = -1;
      } else if (selectedIndex == position) {
         select(0);
      } else if (selectedIndex > position) {
         select(selectedIndex - 1);
      }
      changed();
   }

   public void removeAll() {
      synchronized (this) {
         pItems.removeAllElements();
         selectedIndex = -1;
      }
      changed();
      if (valid) {
         invalidate();
      }
   }

   public synchronized String getSelectedItem() {
      return selectedIndex >= 0 ? getItem(selectedIndex) : null;
   }

   public synchronized Object[] getSelectedObjects() {
      if (selectedIndex >= 0) {
         return new Object[]{getItem(selectedIndex)};
      }
      return null;
   }

   public int getSelectedIndex() {
      return selectedIndex;
   }

   public synchronized void select(int pos) {
      if (pos >= pItems.size() || pos < 0) {
         throw new IllegalArgumentException("illegal Choice item position: " + pos);
      }
      if (pItems.size() > 0) {
         selectedIndex = pos;
         repaint();
      }
   }

   public synchronized void select(String str) {
      int index = pItems.indexOf(str);
      if (index >= 0) {
         select(index);
      }
   }

   private void changed() {
      repaint();
      ChoiceList.choiceChanged(this);
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

   @SuppressWarnings("unchecked")
   public <T extends EventListener> T[] getListeners(Class<T> listenerType) {
      if (listenerType == ItemListener.class) {
         return (T[]) getItemListeners();
      }
      return super.getListeners(listenerType);
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

   protected String paramString() {
      return super.paramString() + ",current=" + getSelectedItem();
   }

   // ------------------------------------------------------------- the native control

   boolean traversable() {
      return true;
   }

   boolean focusDrawn() {
      return true;
   }

   boolean handlesWheel() {
      return true;
   }

   /** WChoicePeer.minimumSize. */
   Dimension peerMinimumSize() {
      FontMetrics fm = getFontMetrics(getFont());
      int w = 0;
      for (int i = pItems.size(); i-- > 0;) {
         w = Math.max(fm.stringWidth(getItem(i)), w);
      }
      return new Dimension(28 + w, Math.max(fm.getHeight() + 6, 15));
   }

   /** The field's height (a combo box's is fixed by its font), centred in the component as AwtChoice::Reshape did. */
   Rectangle fieldBounds() {
      FontMetrics fm = getFontMetrics(getFont());
      int fh = Math.max(fm.getHeight() + 6, 15);
      if (fh >= height) {
         return new Rectangle(0, 0, width, height);
      }
      return new Rectangle(0, (height - fh) / 2, width, fh);
   }

   /** The native control did not take the parent's colours: white field, black text unless set. */
   Color fieldBackground() {
      if (!enabled) {
         return Theme.CONTROL;
      }
      return background != null ? background : Theme.WINDOW;
   }

   Color fieldForeground() {
      return foreground != null ? foreground : Theme.TEXT;
   }

   void handlePeerEvent(AWTEvent e) {
      if (!enabled) {
         return;
      }
      switch (e.getID()) {
         case MouseEvent.MOUSE_PRESSED: {
            MouseEvent m = (MouseEvent) e;
            if ((m.getModifiers() & InputEvent.BUTTON1_MASK) != 0 && pItems.size() > 0) {
               ChoiceList.open(this);
            }
            break;
         }
         case MouseEvent.MOUSE_WHEEL: {
            int n = pItems.size();
            int r = ((java.awt.event.MouseWheelEvent) e).getWheelRotation();
            if (n > 0 && r != 0) {
               keySelect(Math.max(0, Math.min(n - 1, selectedIndex + (r > 0 ? 1 : -1))));
            }
            break;
         }
         case KeyEvent.KEY_PRESSED: {
            KeyEvent k = (KeyEvent) e;
            int n = pItems.size();
            if (n == 0) {
               break;
            }
            int cur = selectedIndex;
            switch (k.getKeyCode()) {
               case KeyEvent.VK_DOWN:
                  if (k.isAltDown()) {
                     ChoiceList.open(this);
                  } else {
                     keySelect(Math.min(n - 1, cur + 1));
                  }
                  break;
               case KeyEvent.VK_RIGHT:
                  keySelect(Math.min(n - 1, cur + 1));
                  break;
               case KeyEvent.VK_UP:
               case KeyEvent.VK_LEFT:
                  keySelect(Math.max(0, cur - 1));
                  break;
               case KeyEvent.VK_HOME:
                  keySelect(0);
                  break;
               case KeyEvent.VK_END:
                  keySelect(n - 1);
                  break;
               case KeyEvent.VK_PAGE_DOWN:
                  keySelect(Math.min(n - 1, cur + ChoiceList.MAX_ROWS - 1));
                  break;
               case KeyEvent.VK_PAGE_UP:
                  keySelect(Math.max(0, cur - ChoiceList.MAX_ROWS + 1));
                  break;
               case KeyEvent.VK_F4:
                  ChoiceList.open(this);
                  break;
               default:
            }
            break;
         }
         case KeyEvent.KEY_TYPED: {
            char c = ((KeyEvent) e).getKeyChar();
            if (c > ' ' && c != KeyEvent.CHAR_UNDEFINED) {
               int i = ChoiceList.nextStartingWith(this, selectedIndex, c);
               if (i >= 0) {
                  keySelect(i);
               }
            }
            break;
         }
         default:
      }
   }

   /** A key changed the selection (CBN_SELCHANGE): only when it really changes. */
   private void keySelect(int index) {
      if (index != selectedIndex && index >= 0 && index < pItems.size()) {
         userSelected(index);
      }
   }

   /** WChoicePeer.handleAction: select on the event thread, then the ItemEvent. */
   void userSelected(final int index) {
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            if (index >= pItems.size()) {
               return;
            }
            select(index);
            EventQueue.post(new ItemEvent(Choice.this, ItemEvent.ITEM_STATE_CHANGED, getItem(index), ItemEvent.SELECTED));
         }
      });
   }

   void paintPeer(Graphics g) {
      Rectangle f = fieldBounds();
      Font font = getFont();
      if (font != null) {
         g.setFont(font);
      }
      FontMetrics fm = g.getFontMetrics();
      Theme.sunken(g, f.x, f.y, f.width, f.height);
      g.setColor(fieldBackground());
      g.fillRect(f.x + 2, f.y + 2, f.width - 4, f.height - 4);
      int bw = Theme.SCROLLBAR;
      int bx = f.x + f.width - 2 - bw;
      int by = f.y + 2;
      int bh = f.height - 4;
      boolean pressed = ChoiceList.isOpenFor(this);
      Theme.paintButtonFace(g, bx, by, bw, bh, pressed);
      Theme.arrow(g, bx + (pressed ? 1 : 0), by + (pressed ? 1 : 0), bw, bh, Theme.DOWN, enabled ? Color.black : Theme.SHADOW);
      String s = getSelectedItem();
      int tx = f.x + 3;
      int tw = bx - tx - 1;
      int ty = f.y + (f.height - fm.getHeight()) / 2 + fm.getAscent();
      Graphics tg = g.create(tx, f.y + 3, Math.max(0, tw), Math.max(0, f.height - 6));
      try {
         boolean focused = isFocusOwner() && enabled;
         if (focused) {
            tg.setColor(Theme.SELECTION);
            tg.fillRect(0, 0, tw, f.height - 6);
         }
         if (s != null) {
            if (!enabled) {
               tg.setColor(Theme.DISABLED_TEXT);
            } else {
               tg.setColor(focused ? Theme.SELECTION_TEXT : fieldForeground());
            }
            tg.drawString(s, 1, ty - f.y - 3);
         }
         if (focused) {
            Theme.focusRect(tg, 0, 0, tw, f.height - 6);
         }
      } finally {
         tg.dispose();
      }
   }
}

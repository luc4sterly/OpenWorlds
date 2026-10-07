package java.awt;

import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.ArrayList;
import java.util.EventListener;

/** A menu item with a check mark, as java.awt.CheckboxMenuItem. */
public class CheckboxMenuItem extends MenuItem implements ItemSelectable {
   boolean state;
   transient ItemListener itemListener;

   private static int nameCounter;

   public CheckboxMenuItem() {
      this("", false);
   }

   public CheckboxMenuItem(String label) {
      this(label, false);
   }

   public CheckboxMenuItem(String label, boolean state) {
      super(label);
      this.state = state;
   }

   String constructComponentName() {
      synchronized (CheckboxMenuItem.class) {
         return "chkmenuitem" + nameCounter++;
      }
   }

   public boolean getState() {
      return state;
   }

   public synchronized void setState(boolean b) {
      state = b;
      changed();
   }

   public synchronized Object[] getSelectedObjects() {
      return state ? new Object[]{label} : null;
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

   /** Chosen: the state flips on the event thread, then the ItemEvent (the Windows peer's handleAction). */
   void doMenuEvent(long when, int modifiers) {
      final boolean newState = !state;
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            setState(newState);
            EventQueue.post(new ItemEvent(CheckboxMenuItem.this, ItemEvent.ITEM_STATE_CHANGED, getLabel(),
                  newState ? ItemEvent.SELECTED : ItemEvent.DESELECTED));
         }
      });
   }

   public String paramString() {
      return super.paramString() + ",state=" + state;
   }
}

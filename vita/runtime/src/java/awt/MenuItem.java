package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.EventListener;

/** An item of a menu, as java.awt.MenuItem; a label of "-" is a separator, as Windows' peer had it. */
public class MenuItem extends MenuComponent {
   boolean enabled = true;
   String label;
   String actionCommand;
   long eventMask;
   transient ActionListener actionListener;
   private MenuShortcut shortcut;

   private static int nameCounter;

   public MenuItem() {
      this("", null);
   }

   public MenuItem(String label) {
      this(label, null);
   }

   public MenuItem(String label, MenuShortcut s) {
      this.label = label;
      this.shortcut = s;
   }

   String constructComponentName() {
      synchronized (MenuItem.class) {
         return "menuitem" + nameCounter++;
      }
   }

   public void addNotify() {
      synchronized (getTreeLock()) {
         displayable = true;
      }
   }

   public String getLabel() {
      return label;
   }

   public synchronized void setLabel(String label) {
      this.label = label;
      changed();
   }

   public boolean isEnabled() {
      return enabled;
   }

   public synchronized void setEnabled(boolean b) {
      enable(b);
   }

   /** @deprecated */
   @Deprecated
   public synchronized void enable() {
      enabled = true;
      changed();
   }

   /** @deprecated */
   @Deprecated
   public void enable(boolean b) {
      if (b) {
         enable();
      } else {
         disable();
      }
   }

   /** @deprecated */
   @Deprecated
   public synchronized void disable() {
      enabled = false;
      changed();
   }

   public MenuShortcut getShortcut() {
      return shortcut;
   }

   public void setShortcut(MenuShortcut s) {
      shortcut = s;
      changed();
   }

   public void deleteShortcut() {
      shortcut = null;
      changed();
   }

   void deleteShortcut(MenuShortcut s) {
      if (s.equals(shortcut)) {
         shortcut = null;
         changed();
      }
   }

   boolean isSeparator() {
      return "-".equals(label);
   }

   /** The item was chosen in its menu (or by its shortcut): what the peer posted. */
   void doMenuEvent(long when, int modifiers) {
      EventQueue.post(new ActionEvent(this, ActionEvent.ACTION_PERFORMED, getActionCommand(), when, modifiers));
   }

   /** As JDK 1.4: a matching shortcut posts the action on key press and eats the release. */
   boolean handleShortcut(KeyEvent e) {
      MenuShortcut s = new MenuShortcut(e.getKeyCode(), (e.getModifiers() & InputEvent.SHIFT_MASK) > 0);
      if (s.equals(shortcut) && enabled) {
         if (e.getID() == KeyEvent.KEY_PRESSED) {
            doMenuEvent(e.getWhen(), e.getModifiers());
         }
         return true;
      }
      return false;
   }

   MenuItem getShortcutMenuItem(MenuShortcut s) {
      return s.equals(shortcut) ? this : null;
   }

   protected final void enableEvents(long eventsToEnable) {
      eventMask |= eventsToEnable;
      newEventsOnly = true;
   }

   protected final void disableEvents(long eventsToDisable) {
      eventMask &= ~eventsToDisable;
   }

   public void setActionCommand(String command) {
      actionCommand = command;
   }

   public String getActionCommand() {
      return actionCommand == null ? label : actionCommand;
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
      collect(actionListener, out);
      return out.toArray(new ActionListener[out.size()]);
   }

   private static void collect(ActionListener l, ArrayList<ActionListener> out) {
      if (l instanceof AWTEventMulticaster) {
         collect((ActionListener) ((AWTEventMulticaster) l).a, out);
         collect((ActionListener) ((AWTEventMulticaster) l).b, out);
      } else if (l != null) {
         out.add(l);
      }
   }

   @SuppressWarnings("unchecked")
   public <T extends EventListener> T[] getListeners(Class<T> listenerType) {
      if (listenerType == ActionListener.class) {
         return (T[]) getActionListeners();
      }
      return (T[]) java.lang.reflect.Array.newInstance(listenerType, 0);
   }

   protected void processEvent(AWTEvent e) {
      if (e instanceof ActionEvent) {
         processActionEvent((ActionEvent) e);
      }
   }

   boolean eventEnabled(AWTEvent e) {
      if (e.id == ActionEvent.ACTION_PERFORMED) {
         return (eventMask & AWTEvent.ACTION_EVENT_MASK) != 0 || actionListener != null;
      }
      return super.eventEnabled(e);
   }

   protected void processActionEvent(ActionEvent e) {
      ActionListener listener = actionListener;
      if (listener != null) {
         listener.actionPerformed(e);
      }
   }

   public String paramString() {
      String str = ",label=" + label;
      if (shortcut != null) {
         str += ",shortcut=" + shortcut;
      }
      return super.paramString() + str;
   }
}

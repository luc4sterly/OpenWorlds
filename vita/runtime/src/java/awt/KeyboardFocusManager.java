package java.awt;

import java.awt.event.FocusEvent;
import java.awt.event.KeyEvent;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

/**
 * Who has the keyboard focus, as java.awt.KeyboardFocusManager: one focus
 * owner in the active window, focus events when it changes, Tab and
 * Shift-Tab between the controls, and menu shortcuts.
 */
public class KeyboardFocusManager {
   private static final KeyboardFocusManager instance = new KeyboardFocusManager();

   private Component focusOwner;
   private Window activeWindow;
   /** Set when Tab moved the focus: the KEY_TYPED and KEY_RELEASED of that Tab are swallowed. */
   private boolean swallowTab;

   KeyboardFocusManager() {
   }

   public static KeyboardFocusManager getCurrentKeyboardFocusManager() {
      return instance;
   }

   public Component getFocusOwner() {
      return focusOwner;
   }

   public Component getPermanentFocusOwner() {
      return focusOwner;
   }

   public Window getActiveWindow() {
      return activeWindow;
   }

   public Window getFocusedWindow() {
      return activeWindow;
   }

   public void clearGlobalFocusOwner() {
      Component old;
      synchronized (this) {
         old = focusOwner;
         focusOwner = null;
      }
      if (old != null) {
         EventQueue.post(new FocusEvent(old, FocusEvent.FOCUS_LOST, false, null));
      }
   }

   /** Component.requestFocus / requestFocusInWindow. */
   boolean requestFocus(Component c, boolean inWindowOnly) {
      if (c == null || !c.isFocusable() || !c.enabled || !c.isShowing()) {
         return false;
      }
      Window w = c.windowAncestor();
      if (w == null) {
         return false;
      }
      Component old;
      synchronized (this) {
         w.focusOwner = c;
         if (w != activeWindow) {
            if (inWindowOnly) {
               return true;
            }
            WindowSystem.activate(w);
            return true;
         }
         old = focusOwner;
         if (old == c) {
            return true;
         }
         focusOwner = c;
      }
      if (old != null) {
         EventQueue.post(new FocusEvent(old, FocusEvent.FOCUS_LOST, false, c));
      }
      EventQueue.post(new FocusEvent(c, FocusEvent.FOCUS_GAINED, false, old));
      return true;
   }

   /** WindowSystem: another window became the active one (or none). */
   void activeWindowChanged(Window newActive) {
      Window oldActive;
      Component oldFocus;
      Component newFocus = null;
      synchronized (this) {
         oldActive = activeWindow;
         if (oldActive == newActive) {
            return;
         }
         oldFocus = focusOwner;
         activeWindow = newActive;
         if (newActive != null) {
            newFocus = newActive.focusOwner;
            if (newFocus == null || !newFocus.isShowing() || !newFocus.enabled || newFocus.windowAncestor() != newActive) {
               newFocus = firstFocusable(newActive);
               newActive.focusOwner = newFocus;
            }
         }
         focusOwner = newFocus;
      }
      if (oldFocus != null) {
         EventQueue.post(new FocusEvent(oldFocus, FocusEvent.FOCUS_LOST, true, newFocus));
      }
      if (oldActive != null) {
         EventQueue.post(new WindowEvent(oldActive, WindowEvent.WINDOW_LOST_FOCUS, newActive));
         oldActive.postWindowEvent(WindowEvent.WINDOW_DEACTIVATED);
         WindowSystem.decorationsChanged(oldActive);
      }
      if (newActive != null) {
         newActive.postWindowEvent(WindowEvent.WINDOW_ACTIVATED);
         EventQueue.post(new WindowEvent(newActive, WindowEvent.WINDOW_GAINED_FOCUS, oldActive));
         WindowSystem.decorationsChanged(newActive);
      }
      if (newFocus != null) {
         EventQueue.post(new FocusEvent(newFocus, FocusEvent.FOCUS_GAINED, false, oldFocus));
      }
   }

   /** The first control Tab would reach in a window: what gets the focus when it is shown. */
   static Component firstFocusable(Container root) {
      ArrayList<Component> order = new ArrayList<Component>();
      traversalOrder(root, order, true);
      if (!order.isEmpty()) {
         return order.get(0);
      }
      order.clear();
      traversalOrder(root, order, false);
      for (Component c : order) {
         if (c instanceof Canvas) {
            return c;
         }
      }
      return root instanceof Window && root.isFocusable() ? root : null;
   }

   private static void traversalOrder(Container c, ArrayList<Component> out, boolean traversableOnly) {
      for (Component child : c.getComponents()) {
         if (!child.visible || !child.enabled) {
            continue;
         }
         if (child.isFocusable() && (!traversableOnly || child.traversable())) {
            out.add(child);
         }
         if (child instanceof Container) {
            traversalOrder((Container) child, out, traversableOnly);
         }
      }
   }

   public void focusNextComponent(Component c) {
      traverse(c, 1);
   }

   public void focusPreviousComponent(Component c) {
      traverse(c, -1);
   }

   public void focusNextComponent() {
      traverse(focusOwner, 1);
   }

   public void focusPreviousComponent() {
      traverse(focusOwner, -1);
   }

   private void traverse(Component from, int step) {
      if (from == null) {
         return;
      }
      Window w = from.windowAncestor();
      if (w == null) {
         return;
      }
      ArrayList<Component> order = new ArrayList<Component>();
      traversalOrder(w, order, true);
      if (order.isEmpty()) {
         return;
      }
      int i = order.indexOf(from);
      int next = i < 0 ? (step > 0 ? 0 : order.size() - 1) : (i + step + order.size()) % order.size();
      requestFocus(order.get(next), false);
   }

   /** Before a key event is dispatched: Tab moves the focus. True if the event was used up. */
   boolean preDispatchKey(Component target, KeyEvent e) {
      int id = e.getID();
      if (e.getKeyCode() == KeyEvent.VK_TAB || e.getKeyChar() == '\t') {
         if (swallowTab && (id == KeyEvent.KEY_TYPED || id == KeyEvent.KEY_RELEASED)) {
            if (id == KeyEvent.KEY_RELEASED) {
               swallowTab = false;
            }
            return true;
         }
         if (id == KeyEvent.KEY_PRESSED && target.focusTraversalKeysEnabled && !(target instanceof TextArea)
               && (e.getModifiers() & ~InputEvent_SHIFT) == 0) {
            swallowTab = true;
            if ((e.getModifiers() & InputEvent_SHIFT) != 0) {
               focusPreviousComponent(target);
            } else {
               focusNextComponent(target);
            }
            return true;
         }
      }
      return false;
   }

   private static final int InputEvent_SHIFT = java.awt.event.InputEvent.SHIFT_MASK;

   /** After a key event: menu shortcuts of the window's menu bar, if nobody consumed it. */
   void postDispatchKey(Component target, KeyEvent e) {
      if (e.isConsumed() || e.getID() != KeyEvent.KEY_PRESSED) {
         return;
      }
      Window w = target.windowAncestor();
      while (w != null && !(w instanceof Frame)) {
         w = w.owner;
      }
      if (w != null && ((Frame) w).menuBar != null) {
         ((Frame) w).menuBar.handleShortcut(e);
      }
   }

   /** The focus owner (or an ancestor of it) became disabled, hidden or removed: the focus moves on. */
   void componentDisabled(Component c) {
      lose(c);
   }

   void componentHidden(Component c) {
      lose(c);
   }

   void componentRemoved(Component c) {
      lose(c);
      Window w = c.windowAncestor();
      if (w != null && w.focusOwner != null && (w.focusOwner == c || (c instanceof Container && ((Container) c).isAncestorOf(w.focusOwner)))) {
         w.focusOwner = null;
      }
   }

   private void lose(Component c) {
      Component owner = focusOwner;
      if (owner == null) {
         return;
      }
      if (owner == c || (c instanceof Container && ((Container) c).isAncestorOf(owner))) {
         Window w = owner.windowAncestor();
         Component next = null;
         if (w != null && w != c) {
            ArrayList<Component> order = new ArrayList<Component>();
            traversalOrder(w, order, true);
            for (Component o : order) {
               if (o != owner && !(c instanceof Container && ((Container) c).isAncestorOf(o)) && o != c) {
                  next = o;
                  break;
               }
            }
            w.focusOwner = next;
         }
         synchronized (this) {
            focusOwner = next;
         }
         EventQueue.post(new FocusEvent(owner, FocusEvent.FOCUS_LOST, false, next));
         if (next != null) {
            EventQueue.post(new FocusEvent(next, FocusEvent.FOCUS_GAINED, false, owner));
         }
      }
   }
}

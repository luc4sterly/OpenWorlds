package NET.worlds.core;

import java.awt.AWTEvent;
import java.awt.Button;
import java.awt.Component;
import java.awt.Container;
import java.awt.Event;
import java.awt.EventQueue;
import java.awt.KeyboardFocusManager;
import java.awt.MenuItem;
import java.awt.Point;
import java.awt.TextComponent;
import java.awt.TextField;
import java.awt.Toolkit;
import java.awt.Window;
import java.awt.event.AWTEventListener;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.HierarchyEvent;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.util.EventListener;

/**
 * PLATFORM ADAPTATION, not client logic: gives the 1996 client's
 * {@link TextComponent}s back the 1.0-model events
 * ({@code handleEvent}/{@code keyDown}/{@code action}/{@code gotFocus}) that
 * the modern JDK no longer generates for them. There is nothing of gamma.dll
 * here.
 *
 * <p>Why it is needed (measured with JDK 25 on macOS, 2026-09-23): the
 * lightweight text peer
 * ({@code sun.lwawt.LWTextComponentPeer.initializeImpl}) registers itself
 * with {@code addInputMethodListener} on the
 * {@code TextField}/{@code TextArea} when it is created. Registering any
 * listener sets {@code Component.newEventsOnly = true}, and then
 * {@code Component.dispatchEventImpl} (bytecode 488-504) only calls
 * {@code processEvent} and skips the {@code AWTEvent.convertToOld()} +
 * {@code postEvent} conversion (bytecode 543-664). Result: Enter in the chat
 * line does not reach {@code DuplexPart.action}, nor does Enter in the
 * password field, nor Esc/Ctrl+letter of
 * {@code FocusPreservingTextField.handleEvent}. Probe of all AWT components
 * after {@code addNotify}: only {@code TextField} and {@code TextArea} come
 * with a listener installed by the peer
 * ({@code LWTextFieldPeer}/{@code LWTextAreaPeer}); {@code Button},
 * {@code Checkbox}, {@code Choice}, {@code List}, {@code Label},
 * {@code Scrollbar}, {@code Canvas} and {@code Panel} come with none.
 *
 * <p>The fix: those components (and only if all their listeners are the
 * peer's, that is, if the client did not ask for new events on its own) get
 * {@link #ADAPTER} registered, which does in {@code processEvent} the same as
 * the JDK would do at that point of the dispatch if {@code newEventsOnly}
 * were false: convert with the rules of {@code AWTEvent.convertToOld}
 * (disassembled with javap from this JDK's {@code java.desktop}), call
 * {@code postEvent} and reflect back the consumption and the changes to
 * {@code key}/{@code modifiers}. The order is preserved: the
 * {@code KeyboardFocusManager} (Tab) and the input methods have already
 * acted, and the peer sees the key afterwards (in
 * {@code DefaultKeyboardFocusManager.postProcessKeyEvent}), only if it was
 * not consumed. On a {@code TextComponent} the 1.0 model never receives the
 * mouse ({@code postsOldMouseEvents()} is false outside
 * {@code Canvas}/{@code Container}), so the adapter covers keys, focus and
 * action.
 */
public final class NativeUiEvents {
   private NativeUiEvents() {
   }

   /** Event.java: actionKeyCodes table (VK -> public constant Event.HOME...). */
   private static final int[][] ACTION_KEYS = {
      {KeyEvent.VK_HOME, Event.HOME}, {KeyEvent.VK_END, Event.END},
      {KeyEvent.VK_PAGE_UP, Event.PGUP}, {KeyEvent.VK_PAGE_DOWN, Event.PGDN},
      {KeyEvent.VK_UP, Event.UP}, {KeyEvent.VK_DOWN, Event.DOWN},
      {KeyEvent.VK_LEFT, Event.LEFT}, {KeyEvent.VK_RIGHT, Event.RIGHT},
      {KeyEvent.VK_F1, Event.F1}, {KeyEvent.VK_F2, Event.F2}, {KeyEvent.VK_F3, Event.F3},
      {KeyEvent.VK_F4, Event.F4}, {KeyEvent.VK_F5, Event.F5}, {KeyEvent.VK_F6, Event.F6},
      {KeyEvent.VK_F7, Event.F7}, {KeyEvent.VK_F8, Event.F8}, {KeyEvent.VK_F9, Event.F9},
      {KeyEvent.VK_F10, Event.F10}, {KeyEvent.VK_F11, Event.F11}, {KeyEvent.VK_F12, Event.F12},
      {KeyEvent.VK_PRINTSCREEN, Event.PRINT_SCREEN}, {KeyEvent.VK_SCROLL_LOCK, Event.SCROLL_LOCK},
      {KeyEvent.VK_CAPS_LOCK, Event.CAPS_LOCK}, {KeyEvent.VK_NUM_LOCK, Event.NUM_LOCK},
      {KeyEvent.VK_PAUSE, Event.PAUSE}, {KeyEvent.VK_INSERT, Event.INSERT}};

   /** Event.getOldEventKey: the action key's constant, otherwise the character. */
   static int oldEventKey(KeyEvent e) {
      int code = e.getKeyCode();
      for (int[] p : ACTION_KEYS) {
         if (p[0] == code) {
            return p[1];
         }
      }
      return e.getKeyChar();
   }

   /** Event.getKeyEventChar: CHAR_UNDEFINED for action keys. */
   static char keyEventChar(Event e) {
      for (int[] p : ACTION_KEYS) {
         if (p[1] == e.key) {
            return KeyEvent.CHAR_UNDEFINED;
         }
      }
      return (char) e.key;
   }

   /**
    * AWTEvent.convertToOld for KEY_PRESSED/KEY_RELEASED (401/402): KEY_ACTION
    * (403/404) if it is an action key; null for Shift/Ctrl/Alt; without the
    * BUTTON1_MASK bit (16) in the modifiers.
    */
   static Event convertKey(KeyEvent ke) {
      int id = ke.getID();
      if (id != KeyEvent.KEY_PRESSED && id != KeyEvent.KEY_RELEASED) {
         return null;
      }
      if (ke.isActionKey()) {
         id = id == KeyEvent.KEY_PRESSED ? Event.KEY_ACTION : Event.KEY_ACTION_RELEASE;
      }
      int code = ke.getKeyCode();
      if (code == KeyEvent.VK_SHIFT || code == KeyEvent.VK_CONTROL || code == KeyEvent.VK_ALT) {
         return null;
      }
      return new Event(ke.getSource(), ke.getWhen(), id, 0, 0, oldEventKey(ke), ke.getModifiers() & ~InputEvent.BUTTON1_MASK);
   }

   /** AWTEvent.convertToOld for ACTION_PERFORMED: the label if it is a Button/MenuItem, otherwise the command. */
   static Event convertAction(ActionEvent ae) {
      Object src = ae.getSource();
      String cmd;
      if (src instanceof Button) {
         cmd = ((Button) src).getLabel();
      } else if (src instanceof MenuItem) {
         cmd = ((MenuItem) src).getLabel();
      } else {
         cmd = ae.getActionCommand();
      }
      return new Event(src, 0L, Event.ACTION_EVENT, 0, 0, 0, ae.getModifiers(), cmd);
   }

   /**
    * Component.dispatchEventImpl 553-664: postEvent and, if the 1.0 Event
    * ends up consumed (Event.consume only marks ids 401-404), consume the
    * new one; for keys, reflect a change of key/modifiers.
    */
   static void deliver(AWTEvent e, Event old) {
      if (old == null || !(e.getSource() instanceof Component)) {
         return;
      }
      int key = old.key;
      int modifiers = old.modifiers;
      boolean handled = ((Component) e.getSource()).postEvent(old);
      boolean keyId = old.id >= Event.KEY_PRESS && old.id <= Event.KEY_ACTION_RELEASE;
      if (handled && keyId && e instanceof InputEvent) {
         ((InputEvent) e).consume();
      }
      if (keyId && e instanceof KeyEvent) {
         KeyEvent ke = (KeyEvent) e;
         if (old.key != key) {
            ke.setKeyChar(keyEventChar(old));
         }
         if (old.modifiers != modifiers) {
            setModifiers(ke, old.modifiers);
         }
      }
   }

   @SuppressWarnings("deprecation")
   private static void setModifiers(KeyEvent ke, int modifiers) {
      ke.setModifiers(modifiers);
   }

   /** The listener that replaces the 1.0 conversion the JDK skips. */
   static final Adapter ADAPTER = new Adapter();

   static final class Adapter implements KeyListener, FocusListener, ActionListener {
      public void keyPressed(KeyEvent e) {
         deliver(e, convertKey(e));
      }

      public void keyReleased(KeyEvent e) {
         deliver(e, convertKey(e));
      }

      public void keyTyped(KeyEvent e) {
         // convertToOld has no case for KEY_TYPED (400): the 1.0 model does not see it
      }

      public void focusGained(FocusEvent e) {
         deliver(e, new Event(e.getSource(), Event.GOT_FOCUS, null));
      }

      public void focusLost(FocusEvent e) {
         deliver(e, new Event(e.getSource(), Event.LOST_FOCUS, null));
      }

      public void actionPerformed(ActionEvent e) {
         deliver(e, convertAction(e));
      }
   }

   private static Class<?> peerClass;

   /** Is it the peer itself? (java.awt.peer is not exported: it is compared through Class.isInstance). */
   private static boolean isPeer(Object l) {
      if (peerClass == null) {
         try {
            peerClass = Class.forName("java.awt.peer.ComponentPeer");
         } catch (ClassNotFoundException e) {
            return false;
         }
      }
      return peerClass.isInstance(l);
   }

   /**
    * Counts the listeners: returns -1 if there is any that is neither the
    * peer's nor the adapter (the client asked for new events: the original
    * JDK would not give it the 1.0 ones either), or the number of the
    * peer's listeners.
    */
   private static int peerListeners(Component c) {
      java.util.List<EventListener> all = new java.util.ArrayList<EventListener>();
      java.util.Collections.addAll(all, c.getKeyListeners());
      java.util.Collections.addAll(all, c.getFocusListeners());
      java.util.Collections.addAll(all, c.getMouseListeners());
      java.util.Collections.addAll(all, c.getMouseMotionListeners());
      java.util.Collections.addAll(all, c.getMouseWheelListeners());
      java.util.Collections.addAll(all, c.getInputMethodListeners());
      java.util.Collections.addAll(all, c.getComponentListeners());
      java.util.Collections.addAll(all, c.getHierarchyListeners());
      java.util.Collections.addAll(all, c.getHierarchyBoundsListeners());
      if (c instanceof TextComponent) {
         java.util.Collections.addAll(all, ((TextComponent) c).getTextListeners());
      }
      if (c instanceof TextField) {
         java.util.Collections.addAll(all, ((TextField) c).getActionListeners());
      }
      int peers = 0;
      for (EventListener l : all) {
         if (l == ADAPTER) {
            continue;
         }
         if (!isPeer(l)) {
            return -1;
         }
         peers++;
      }
      return peers;
   }

   static boolean adapted(Component c) {
      for (KeyListener l : c.getKeyListeners()) {
         if (l == ADAPTER) {
            return true;
         }
      }
      return false;
   }

   /** Installs the adapter if the peer left the component without the 1.0 model. */
   static synchronized boolean maybeAdapt(Component c) {
      if (!(c instanceof TextComponent) || !c.isDisplayable() || adapted(c)) {
         return false;
      }
      if (peerListeners(c) <= 0) {
         return false;
      }
      c.addKeyListener(ADAPTER);
      c.addFocusListener(ADAPTER);
      if (c instanceof TextField) {
         ((TextField) c).addActionListener(ADAPTER);
      }
      if (LOG) {
         System.err.println("[UI-EVENTS] modelo 1.0 restituido en " + c.getClass().getName());
      }
      return true;
   }

   private static void sweep(Component c) {
      maybeAdapt(c);
      if (c instanceof Container) {
         for (Component k : ((Container) c).getComponents()) {
            sweep(k);
         }
      }
   }

   private static final boolean LOG = Boolean.getBoolean("openworlds.uiEventsLog");
   private static boolean installed;

   /**
    * Hooks the adapter onto each TextComponent as soon as its peer is
    * created (HierarchyEvent DISPLAYABILITY_CHANGED, which
    * Component.addNotify emits after creating the peer) and onto those
    * that already had one. Idempotent.
    */
   public static synchronized void install() {
      if (installed) {
         return;
      }
      installed = true;
      Toolkit.getDefaultToolkit().addAWTEventListener(new AWTEventListener() {
         public void eventDispatched(AWTEvent e) {
            if (e instanceof HierarchyEvent
               && (((HierarchyEvent) e).getChangeFlags() & HierarchyEvent.DISPLAYABILITY_CHANGED) != 0) {
               maybeAdapt(((HierarchyEvent) e).getComponent());
            }
         }
      }, AWTEvent.HIERARCHY_EVENT_MASK);
      for (Window w : Window.getWindows()) {
         sweep(w);
      }
      typeChatScript();
   }

   /**
    * Harness diagnostic, disabled by default:
    * {@code -Dopenworlds.typeChat=MS:text[;MS:text...]} does what a person
    * would do with the chat line: MS ms after it is shown, a click on its
    * centre (MOUSE_PRESSED/RELEASED/CLICKED) and, for each character,
    * KEY_PRESSED/KEY_TYPED/KEY_RELEASED, ending with Enter. The events are
    * queued on AWT's system queue, just like the peer's, so they go through
    * the KeyboardFocusManager, the peer (which inserts the text) and this
    * adapter; nobody calls action() by hand. java.awt.Robot is of no use on
    * this machine (no accessibility permission: the keys do not arrive).
    * The chat line is located through the static field
    * FocusPreservingTextField.chatLine (reflection: only the harness reads
    * it).
    */
   private static void typeChatScript() {
      typeScript("openworlds.typeChat", "linea de chat", false);
      typeScript("openworlds.typePassword", "campo de contrasena", true);
   }

   /**
    * The same harness for the LoginWizard:
    * {@code -Dopenworlds.typePassword=MS:text} types into the first
    * visible TextField with echo ({@code setEchoChar}) and presses
    * Enter; with empty text it only presses Enter (password already
    * filled in by "Remember password").
    */
   private static void typeScript(final String prop, final String what, final boolean password) {
      final String spec = System.getProperty(prop);
      if (spec == null || spec.length() == 0) {
         return;
      }
      Thread t = new Thread("openworlds-" + prop) {
         public void run() {
            try {
               Component line = null;
               while (line == null || !line.isShowing()) {
                  Thread.sleep(250);
                  line = password ? passwordField() : chatLine();
               }
               long t0 = System.currentTimeMillis();
               System.err.println("[TYPECHAT] " + what + " visible");
               for (String item : spec.split(";")) {
                  int colon = item.indexOf(':');
                  long at = Long.parseLong(item.substring(0, colon).trim());
                  String text = item.substring(colon + 1);
                  long wait = t0 + at - System.currentTimeMillis();
                  if (wait > 0) {
                     Thread.sleep(wait);
                  }
                  if (password && text.startsWith("[x]")) {
                     typeInto(line, text.substring(3), false, false);
                     clickCheckbox(line);
                     clickForward(line);
                  } else {
                     typeInto(line, text, !password, true);
                  }
               }
            } catch (InterruptedException e) {
               return;
            } catch (Exception e) {
               System.err.println("[TYPECHAT] fallo: " + e);
            }
         }
      };
      t.setDaemon(true);
      t.start();
   }

   /**
    * "[x]" in front of typePassword's text: first, a mouse click (through the
    * system queue) on the "Remember password" checkbox of the same window, as
    * a person would do (the LoginWizard leaves it unchecked if there was no
    * saved password: LoginWizard.java:384).
    */
   private static void clickCheckbox(Component field) throws InterruptedException {
      Window w = javax.swing.SwingUtilities.getWindowAncestor(field);
      java.awt.Checkbox box = w == null ? null : findCheckbox(w);
      if (box == null) {
         System.err.println("[TYPECHAT] no hay casilla en la ventana");
         return;
      }
      requestForeground(box);
      EventQueue q = Toolkit.getDefaultToolkit().getSystemEventQueue();
      int cx = 6;
      int cy = box.getHeight() / 2;
      Point s = box.getLocationOnScreen();
      long now = System.currentTimeMillis();
      q.postEvent(new MouseEvent(box, MouseEvent.MOUSE_PRESSED, now, InputEvent.BUTTON1_DOWN_MASK, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(box, MouseEvent.MOUSE_RELEASED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(box, MouseEvent.MOUSE_CLICKED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      Thread.sleep(400);
      System.err.println("[TYPECHAT] clic en la casilla \"" + box.getLabel() + "\": marcada=" + box.getState());
   }

   /** Click on the ForwardButton ("Sign In") of the field's window. */
   private static void clickForward(Component field) throws InterruptedException {
      Window w = javax.swing.SwingUtilities.getWindowAncestor(field);
      Component b = w == null ? null : findClass(w, "NET.worlds.console.ForwardButton");
      if (b == null) {
         System.err.println("[TYPECHAT] no hay ForwardButton");
         return;
      }
      EventQueue q = Toolkit.getDefaultToolkit().getSystemEventQueue();
      int cx = b.getWidth() / 2;
      int cy = b.getHeight() / 2;
      Point s = b.getLocationOnScreen();
      long now = System.currentTimeMillis();
      q.postEvent(new MouseEvent(b, MouseEvent.MOUSE_PRESSED, now, InputEvent.BUTTON1_DOWN_MASK, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(b, MouseEvent.MOUSE_RELEASED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(b, MouseEvent.MOUSE_CLICKED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      System.err.println("[TYPECHAT] clic en \"" + ((java.awt.Button) b).getLabel() + "\"");
   }

   private static Component findClass(Component c, String name) {
      if (c.getClass().getName().equals(name) && c.isShowing()) {
         return c;
      }
      if (c instanceof Container) {
         for (Component k : ((Container) c).getComponents()) {
            Component f = findClass(k, name);
            if (f != null) {
               return f;
            }
         }
      }
      return null;
   }

   private static java.awt.Checkbox findCheckbox(Component c) {
      if (c instanceof java.awt.Checkbox && c.isShowing()) {
         return (java.awt.Checkbox) c;
      }
      if (c instanceof Container) {
         for (Component k : ((Container) c).getComponents()) {
            java.awt.Checkbox f = findCheckbox(k);
            if (f != null) {
               return f;
            }
         }
      }
      return null;
   }

   private static Component passwordField() {
      for (Window w : Window.getWindows()) {
         Component f = findEcho(w);
         if (f != null) {
            return f;
         }
      }
      return null;
   }

   private static Component findEcho(Component c) {
      if (c instanceof TextField && ((TextField) c).echoCharIsSet() && c.isShowing()) {
         return c;
      }
      if (c instanceof Container) {
         for (Component k : ((Container) c).getComponents()) {
            Component f = findEcho(k);
            if (f != null) {
               return f;
            }
         }
      }
      return null;
   }

   private static Component chatLine() {
      try {
         java.lang.reflect.Field f = Class.forName("NET.worlds.console.FocusPreservingTextField").getDeclaredField("chatLine");
         f.setAccessible(true);
         return (Component) f.get(null);
      } catch (Exception e) {
         return null;
      }
   }

   /**
    * A JVM launched from a terminal is not the active macOS application and
    * then there is no focus owner (the KeyboardFocusManager throws the keys
    * away). A person would activate it with the mouse; the harness asks for
    * it with Desktop.requestForeground (a Java 9 API: through reflection,
    * the bridge is compiled with --release 8).
    */
   private static void requestForeground(Component c) {
      try {
         Class<?> d = Class.forName("java.awt.Desktop");
         Object desk = d.getMethod("getDesktop").invoke(null);
         d.getMethod("requestForeground", boolean.class).invoke(desk, Boolean.TRUE);
      } catch (Throwable e) {
         // without the API: it stays as it is
      }
      java.awt.Window w = javax.swing.SwingUtilities.getWindowAncestor(c);
      if (w != null) {
         w.toFront();
      }
   }

   static void typeInto(Component line, String text, boolean showText, boolean enter) throws InterruptedException {
      EventQueue q = Toolkit.getDefaultToolkit().getSystemEventQueue();
      int cx = line.getWidth() / 2;
      int cy = line.getHeight() / 2;
      Point s = line.getLocationOnScreen();
      requestForeground(line);
      long now = System.currentTimeMillis();
      q.postEvent(new MouseEvent(line, MouseEvent.MOUSE_PRESSED, now, InputEvent.BUTTON1_DOWN_MASK, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(line, MouseEvent.MOUSE_RELEASED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      q.postEvent(new MouseEvent(line, MouseEvent.MOUSE_CLICKED, now, 0, cx, cy, s.x + cx, s.y + cy, 1, false, MouseEvent.BUTTON1));
      Thread.sleep(300);
      Component owner = KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner();
      if (owner != line) {
         // a person's click also requests focus from the enclosing
         // window: if the window is not the system's active one, the
         // focus stays pending
         line.requestFocus();
         Thread.sleep(300);
         owner = KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner();
      }
      if (owner != line) {
         KeyboardFocusManager k = KeyboardFocusManager.getCurrentKeyboardFocusManager();
         System.err.println("[TYPECHAT] sin foco: ventana activa " + (k.getActiveWindow() == null ? "ninguna (la JVM no es la aplicacion activa)"
            : k.getActiveWindow().getClass().getName()) + ", dueno del foco " + (owner == null ? "ninguno" : owner.getClass().getName()));
      }
      System.err.println("[TYPECHAT] foco en el campo: " + (owner == line) + "; tecleo " + (showText ? "\"" + text + "\"" : text.length() + " caracteres") + " + Intro");
      Component target = owner != null ? owner : line;
      for (int i = 0; i <= text.length(); i++) {
         if (i == text.length() && !enter) {
            break;
         }
         if (i == text.length()) {
            Thread.sleep(200);
            String typed = ((java.awt.TextComponent) line).getText();
            System.err.println("[TYPECHAT] antes de Intro el campo tiene " + (showText ? "\"" + typed + "\"" : typed.length() + " caracteres"));
         }
         char ch = i < text.length() ? text.charAt(i) : '\n';
         int code = ch == '\n' ? KeyEvent.VK_ENTER : KeyEvent.getExtendedKeyCodeForChar(ch);
         int mods = Character.isUpperCase(ch) ? InputEvent.SHIFT_DOWN_MASK : 0;
         long w = System.currentTimeMillis();
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_PRESSED, w, mods, code, ch));
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_TYPED, w, mods, KeyEvent.VK_UNDEFINED, ch));
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_RELEASED, w, mods, code, ch));
         Thread.sleep(40);
      }
      Thread.sleep(300);
      System.err.println("[TYPECHAT] tras Intro el campo tiene " + ((java.awt.TextComponent) line).getText().length() + " caracteres");
   }
}

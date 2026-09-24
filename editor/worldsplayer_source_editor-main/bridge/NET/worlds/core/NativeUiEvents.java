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
 * ADAPTACION DE PLATAFORMA, no logica del cliente: devuelve a los
 * {@link TextComponent} del cliente de 1996 los eventos del modelo 1.0
 * ({@code handleEvent}/{@code keyDown}/{@code action}/{@code gotFocus})
 * que el JDK moderno deja de generarles. No hay nada de gamma.dll aqui.
 *
 * <p>Por que hace falta (medido con JDK 25 en macOS, 2026-09-23): el peer
 * ligero de texto ({@code sun.lwawt.LWTextComponentPeer.initializeImpl})
 * se registra a si mismo con {@code addInputMethodListener} en el
 * {@code TextField}/{@code TextArea} al crearse. Registrar cualquier listener
 * pone {@code Component.newEventsOnly = true}, y entonces
 * {@code Component.dispatchEventImpl} (bytecode 488-504) solo llama a
 * {@code processEvent} y se salta la conversion
 * {@code AWTEvent.convertToOld()} + {@code postEvent} (bytecode 543-664).
 * Resultado: Intro en la linea de chat no llega a {@code DuplexPart.action},
 * ni Intro en la contrasena, ni Esc/Ctrl+letra de
 * {@code FocusPreservingTextField.handleEvent}. Sondeo de todos los
 * componentes AWT tras {@code addNotify}: solo {@code TextField} y
 * {@code TextArea} traen un listener puesto por el peer
 * ({@code LWTextFieldPeer}/{@code LWTextAreaPeer}); {@code Button},
 * {@code Checkbox}, {@code Choice}, {@code List}, {@code Label},
 * {@code Scrollbar}, {@code Canvas} y {@code Panel} no traen ninguno.
 *
 * <p>El arreglo: a esos componentes (y solo si todos sus listeners son del
 * peer, es decir, si el cliente no pidio eventos nuevos por su cuenta) se
 * les registra {@link #ADAPTER}, que hace en {@code processEvent} lo mismo
 * que el JDK haria en ese punto del despacho si {@code newEventsOnly} fuera
 * falso: convertir con las reglas de {@code AWTEvent.convertToOld}
 * (desensamblada del {@code java.desktop} de este JDK con javap), llamar a
 * {@code postEvent} y reflejar de vuelta el consumo y los cambios de
 * {@code key}/{@code modifiers}. El orden se conserva: el
 * {@code KeyboardFocusManager} (Tab) y los metodos de entrada ya han
 * actuado, y el peer ve la tecla despues (en
 * {@code DefaultKeyboardFocusManager.postProcessKeyEvent}), solo si no se
 * consumio. En un {@code TextComponent} el modelo 1.0 nunca recibe raton
 * ({@code postsOldMouseEvents()} es falso fuera de {@code Canvas}/
 * {@code Container}), asi que el adaptador cubre teclas, foco y accion.
 */
public final class NativeUiEvents {
   private NativeUiEvents() {
   }

   /** Event.java: tabla actionKeyCodes (VK -> constante publica Event.HOME...). */
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

   /** Event.getOldEventKey: la constante de la tecla de accion, si no el caracter. */
   static int oldEventKey(KeyEvent e) {
      int code = e.getKeyCode();
      for (int[] p : ACTION_KEYS) {
         if (p[0] == code) {
            return p[1];
         }
      }
      return e.getKeyChar();
   }

   /** Event.getKeyEventChar: CHAR_UNDEFINED para las teclas de accion. */
   static char keyEventChar(Event e) {
      for (int[] p : ACTION_KEYS) {
         if (p[1] == e.key) {
            return KeyEvent.CHAR_UNDEFINED;
         }
      }
      return (char) e.key;
   }

   /**
    * AWTEvent.convertToOld para KEY_PRESSED/KEY_RELEASED (401/402): KEY_ACTION
    * (403/404) si es tecla de accion; null para Mayus/Ctrl/Alt; sin el bit
    * BUTTON1_MASK (16) en los modificadores.
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

   /** AWTEvent.convertToOld para ACTION_PERFORMED: la etiqueta si es Button/MenuItem, si no el comando. */
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
    * Component.dispatchEventImpl 553-664: postEvent y, si el Event 1.0 queda
    * consumido (Event.consume solo marca los ids 401-404), consumir el
    * nuevo; en las teclas, reflejar un cambio de key/modifiers.
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

   /** El listener que sustituye a la conversion 1.0 que el JDK se salta. */
   static final Adapter ADAPTER = new Adapter();

   static final class Adapter implements KeyListener, FocusListener, ActionListener {
      public void keyPressed(KeyEvent e) {
         deliver(e, convertKey(e));
      }

      public void keyReleased(KeyEvent e) {
         deliver(e, convertKey(e));
      }

      public void keyTyped(KeyEvent e) {
         // convertToOld no tiene caso para KEY_TYPED (400): el modelo 1.0 no lo ve
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

   /** ¿Es el propio peer? (java.awt.peer no se exporta: se compara por Class.isInstance). */
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
    * Cuenta los listeners: devuelve -1 si hay alguno que no es del peer ni
    * el adaptador (el cliente pidio eventos nuevos: el JDK original tampoco
    * le daria los 1.0), o el numero de listeners del peer.
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

   /** Pone el adaptador si el peer dejo al componente sin modelo 1.0. */
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

   private static final boolean LOG = Boolean.getBoolean("freeworlds.uiEventsLog");
   private static boolean installed;

   /**
    * Engancha el adaptador a cada TextComponent en cuanto se crea su peer
    * (HierarchyEvent DISPLAYABILITY_CHANGED, que Component.addNotify emite
    * despues de crear el peer) y a los que ya lo tuvieran. Idempotente.
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
    * Diagnostico del arnes, desactivado por defecto:
    * {@code -Dfreeworlds.typeChat=MS:texto[;MS:texto...]} hace lo que haria
    * una persona con la linea de chat: a los MS ms de mostrarse, un clic en
    * su centro (MOUSE_PRESSED/RELEASED/CLICKED) y, por cada caracter,
    * KEY_PRESSED/KEY_TYPED/KEY_RELEASED, terminando con Intro. Los eventos
    * se encolan en la cola de sistema de AWT, igual que los del peer, asi
    * que pasan por el KeyboardFocusManager, el peer (que inserta el texto)
    * y este adaptador; nadie llama a action() a mano. java.awt.Robot no
    * sirve en esta maquina (sin permiso de accesibilidad: las teclas no
    * llegan). La linea de chat se localiza por el campo estatico
    * FocusPreservingTextField.chatLine (reflexion: solo el arnes lo lee).
    */
   private static void typeChatScript() {
      final String spec = System.getProperty("freeworlds.typeChat");
      if (spec == null || spec.length() == 0) {
         return;
      }
      Thread t = new Thread("freeworlds-typeChat") {
         public void run() {
            try {
               Component line = null;
               while (line == null || !line.isShowing()) {
                  Thread.sleep(250);
                  line = chatLine();
               }
               long t0 = System.currentTimeMillis();
               System.err.println("[TYPECHAT] linea de chat visible");
               for (String item : spec.split(";")) {
                  int colon = item.indexOf(':');
                  long at = Long.parseLong(item.substring(0, colon).trim());
                  String text = item.substring(colon + 1);
                  long wait = t0 + at - System.currentTimeMillis();
                  if (wait > 0) {
                     Thread.sleep(wait);
                  }
                  typeInto(line, text);
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
    * Una JVM lanzada desde un terminal no es la aplicacion activa de macOS y
    * entonces no hay dueno del foco (el KeyboardFocusManager tira las
    * teclas). Una persona la activaria con el raton; el arnes lo pide con
    * Desktop.requestForeground (API de Java 9: por reflexion, el puente se
    * compila con --release 8).
    */
   private static void requestForeground(Component c) {
      try {
         Class<?> d = Class.forName("java.awt.Desktop");
         Object desk = d.getMethod("getDesktop").invoke(null);
         d.getMethod("requestForeground", boolean.class).invoke(desk, Boolean.TRUE);
      } catch (Throwable e) {
         // sin la API: se queda como este
      }
      java.awt.Window w = javax.swing.SwingUtilities.getWindowAncestor(c);
      if (w != null) {
         w.toFront();
      }
   }

   static void typeInto(Component line, String text) throws InterruptedException {
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
         // el clic de una persona tambien pide el foco al ventanal: si la
         // ventana no es la activa del sistema, el foco queda pendiente
         line.requestFocus();
         Thread.sleep(300);
         owner = KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner();
      }
      System.err.println("[TYPECHAT] foco en la linea de chat: " + (owner == line) + "; tecleo \"" + text + "\" + Intro");
      Component target = owner != null ? owner : line;
      for (int i = 0; i <= text.length(); i++) {
         char ch = i < text.length() ? text.charAt(i) : '\n';
         int code = ch == '\n' ? KeyEvent.VK_ENTER : KeyEvent.getExtendedKeyCodeForChar(ch);
         int mods = Character.isUpperCase(ch) ? InputEvent.SHIFT_DOWN_MASK : 0;
         long w = System.currentTimeMillis();
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_PRESSED, w, mods, code, ch));
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_TYPED, w, mods, KeyEvent.VK_UNDEFINED, ch));
         q.postEvent(new KeyEvent(target, KeyEvent.KEY_RELEASED, w, mods, code, ch));
         Thread.sleep(40);
      }
   }
}

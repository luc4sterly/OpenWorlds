import java.awt.Component;
import java.awt.Event;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.GraphicsEnvironment;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.InputEvent;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.List;

/**
 * NativeUiEvents (adaptacion de plataforma): conversion al modelo 1.0 con
 * las reglas de AWTEvent.convertToOld y, si hay pantalla, el recorrido
 * completo por la cola de AWT de un TextField real: Intro llega como
 * ACTION_EVENT con el texto al contenedor padre (como DuplexPart.action),
 * Esc llega como KEY_PRESS 27 y, consumido por handleEvent, no se inserta.
 * Casos calculados a mano con las constantes publicas de java.awt.Event.
 */
public class UiEventsCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   static Event convertKey(KeyEvent e) throws Exception {
      java.lang.reflect.Method m = Class.forName("NET.worlds.core.NativeUiEvents").getDeclaredMethod("convertKey", KeyEvent.class);
      m.setAccessible(true);
      return (Event) m.invoke(null, e);
   }

   static Event convertAction(ActionEvent e) throws Exception {
      java.lang.reflect.Method m = Class.forName("NET.worlds.core.NativeUiEvents").getDeclaredMethod("convertAction", ActionEvent.class);
      m.setAccessible(true);
      return (Event) m.invoke(null, e);
   }

   public static void main(String[] a) throws Exception {
      Component src = new Component() {
      };
      // 'a' pulsada: KEY_PRESS (401), key 97, sin BUTTON1_MASK (16)
      Event e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 5L, InputEvent.SHIFT_MASK | InputEvent.BUTTON1_MASK, KeyEvent.VK_A, 'a'));
      check(e.id == 401 && e.key == 97 && e.modifiers == 1 && e.when == 5L, "KEY_PRESSED 'a' -> KEY_PRESS 97 mods 1");
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_RELEASED, 0L, 0, KeyEvent.VK_ENTER, '\n'));
      check(e.id == 402 && e.key == 10, "KEY_RELEASED Intro -> KEY_RELEASE 10");
      // flecha izquierda: tecla de accion -> KEY_ACTION (403) con Event.LEFT = 1006
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, 0, KeyEvent.VK_LEFT, KeyEvent.CHAR_UNDEFINED));
      check(e.id == 403 && e.key == 1006, "VK_LEFT -> KEY_ACTION 1006");
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_RELEASED, 0L, 0, KeyEvent.VK_F12, KeyEvent.CHAR_UNDEFINED));
      check(e.id == 404 && e.key == 1019, "VK_F12 soltada -> KEY_ACTION_RELEASE 1019");
      // Ctrl+A: caracter de control 1 con CTRL_MASK (2), como espera FocusPreservingTextField
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, InputEvent.CTRL_MASK, KeyEvent.VK_A, (char) 1));
      check(e.id == 401 && e.key == 1 && e.modifiers == 2, "Ctrl+A -> KEY_PRESS 1 mods 2");
      check(convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, 0, KeyEvent.VK_SHIFT, KeyEvent.CHAR_UNDEFINED)) == null, "Mayus sola -> null");
      check(convertKey(new KeyEvent(src, KeyEvent.KEY_TYPED, 0L, 0, KeyEvent.VK_UNDEFINED, 'a')) == null, "KEY_TYPED -> null");
      e = convertAction(new ActionEvent(src, ActionEvent.ACTION_PERFORMED, "hola", 0L, 0));
      check(e.id == 1001 && "hola".equals(e.arg) && e.when == 0L, "ACTION_PERFORMED -> ACTION_EVENT arg=comando");

      if (GraphicsEnvironment.isHeadless()) {
         System.out.println("sin pantalla: se omite la parte con TextField real");
      } else {
         integration();
      }
      System.out.println(fails == 0 ? "UiEventsCheck: todo OK" : "UiEventsCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }

   static void integration() throws Exception {
      final List<String> seen = new ArrayList<String>();
      Class.forName("NET.worlds.core.NativeUiEvents").getMethod("install").invoke(null);
      Frame f = new Frame("UiEventsCheck");
      final TextField tf = new TextField(20) {
         public boolean handleEvent(Event ev) {
            if (ev.id == Event.KEY_PRESS && ev.key == 27) {
               seen.add("esc");
               return true;
            }
            return super.handleEvent(ev);
         }
      };
      Panel p = new Panel(new FlowLayout()) {
         public boolean action(Event ev, Object arg) {
            if (ev.target == tf) {
               seen.add("action:" + arg);
               return true;
            }
            return false;
         }
      };
      p.add(tf);
      f.add(p);
      f.pack();
      f.setVisible(true);
      Thread.sleep(800);
      // la JVM lanzada desde un terminal no es la aplicacion activa de macOS:
      // sin eso no hay dueno del foco y el KeyboardFocusManager tira las teclas
      if (java.awt.Desktop.isDesktopSupported()
         && java.awt.Desktop.getDesktop().isSupported(java.awt.Desktop.Action.APP_REQUEST_FOREGROUND)) {
         java.awt.Desktop.getDesktop().requestForeground(true);
      }
      f.toFront();
      Thread.sleep(500);
      tf.requestFocus();
      Thread.sleep(400);
      System.out.println("  foco: " + (java.awt.KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner() == tf)
         + ", adaptador puesto: " + (tf.getKeyListeners().length > 0));
      EventQueue q = Toolkit.getDefaultToolkit().getSystemEventQueue();
      String text = "hola";
      for (char ch : (text + "\u001b\n").toCharArray()) {
         int code = ch == '\n' ? KeyEvent.VK_ENTER : ch == 27 ? KeyEvent.VK_ESCAPE : KeyEvent.getExtendedKeyCodeForChar(ch);
         long w = System.currentTimeMillis();
         q.postEvent(new KeyEvent(tf, KeyEvent.KEY_PRESSED, w, 0, code, ch));
         q.postEvent(new KeyEvent(tf, KeyEvent.KEY_TYPED, w, 0, KeyEvent.VK_UNDEFINED, ch));
         q.postEvent(new KeyEvent(tf, KeyEvent.KEY_RELEASED, w, 0, code, ch));
      }
      Thread.sleep(1000);
      System.out.println("  eventos 1.0 vistos: " + seen + ", texto: [" + tf.getText() + "]");
      check(seen.contains("esc"), "Esc llega a handleEvent como KEY_PRESS 27");
      check(seen.contains("action:hola"), "Intro llega al padre como ACTION_EVENT con el texto");
      f.dispose();
   }
}

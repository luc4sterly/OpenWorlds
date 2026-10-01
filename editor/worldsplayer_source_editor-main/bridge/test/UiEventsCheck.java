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
 * NativeUiEvents (platform adaptation): conversion to the 1.0 model with
 * the rules of AWTEvent.convertToOld and, if there is a display, the full
 * path through the AWT queue of a real TextField: Enter arrives as
 * ACTION_EVENT with the text at the parent container (like DuplexPart.action),
 * Esc arrives as KEY_PRESS 27 and, consumed by handleEvent, is not inserted.
 * Cases calculated by hand with the public constants of java.awt.Event.
 */
public class UiEventsCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + what);
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
      // 'a' pressed: KEY_PRESS (401), key 97, without BUTTON1_MASK (16)
      Event e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 5L, InputEvent.SHIFT_MASK | InputEvent.BUTTON1_MASK, KeyEvent.VK_A, 'a'));
      check(e.id == 401 && e.key == 97 && e.modifiers == 1 && e.when == 5L, "KEY_PRESSED 'a' -> KEY_PRESS 97 mods 1");
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_RELEASED, 0L, 0, KeyEvent.VK_ENTER, '\n'));
      check(e.id == 402 && e.key == 10, "KEY_RELEASED Enter -> KEY_RELEASE 10");
      // left arrow: action key -> KEY_ACTION (403) with Event.LEFT = 1006
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, 0, KeyEvent.VK_LEFT, KeyEvent.CHAR_UNDEFINED));
      check(e.id == 403 && e.key == 1006, "VK_LEFT -> KEY_ACTION 1006");
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_RELEASED, 0L, 0, KeyEvent.VK_F12, KeyEvent.CHAR_UNDEFINED));
      check(e.id == 404 && e.key == 1019, "VK_F12 released -> KEY_ACTION_RELEASE 1019");
      // Ctrl+A: control character 1 with CTRL_MASK (2), as FocusPreservingTextField expects
      e = convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, InputEvent.CTRL_MASK, KeyEvent.VK_A, (char) 1));
      check(e.id == 401 && e.key == 1 && e.modifiers == 2, "Ctrl+A -> KEY_PRESS 1 mods 2");
      check(convertKey(new KeyEvent(src, KeyEvent.KEY_PRESSED, 0L, 0, KeyEvent.VK_SHIFT, KeyEvent.CHAR_UNDEFINED)) == null, "Shift alone -> null");
      check(convertKey(new KeyEvent(src, KeyEvent.KEY_TYPED, 0L, 0, KeyEvent.VK_UNDEFINED, 'a')) == null, "KEY_TYPED -> null");
      e = convertAction(new ActionEvent(src, ActionEvent.ACTION_PERFORMED, "hello", 0L, 0));
      check(e.id == 1001 && "hello".equals(e.arg) && e.when == 0L, "ACTION_PERFORMED -> ACTION_EVENT arg=command");

      if (GraphicsEnvironment.isHeadless()) {
         System.out.println("no display: the part with a real TextField is skipped");
      } else {
         integration();
      }
      System.out.println(fails == 0 ? "UiEventsCheck: all OK" : "UiEventsCheck: " + fails + " failures");
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
      // a JVM launched from a terminal is not macOS's active application:
      // without that there is no focus owner and the KeyboardFocusManager drops the keys
      if (java.awt.Desktop.isDesktopSupported()
         && java.awt.Desktop.getDesktop().isSupported(java.awt.Desktop.Action.APP_REQUEST_FOREGROUND)) {
         java.awt.Desktop.getDesktop().requestForeground(true);
      }
      f.toFront();
      Thread.sleep(500);
      tf.requestFocus();
      Thread.sleep(400);
      boolean focused = java.awt.KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner() == tf;
      System.out.println("  focus: " + focused + ", adapter set: " + (tf.getKeyListeners().length > 0));
      EventQueue q = Toolkit.getDefaultToolkit().getSystemEventQueue();
      if (focused) {
         String text = "hello";
         for (char ch : (text + "\u001b\n").toCharArray()) {
            int code = ch == '\n' ? KeyEvent.VK_ENTER : ch == 27 ? KeyEvent.VK_ESCAPE : KeyEvent.getExtendedKeyCodeForChar(ch);
            long w = System.currentTimeMillis();
            q.postEvent(new KeyEvent(tf, KeyEvent.KEY_PRESSED, w, 0, code, ch));
            q.postEvent(new KeyEvent(tf, KeyEvent.KEY_TYPED, w, 0, KeyEvent.VK_UNDEFINED, ch));
            q.postEvent(new KeyEvent(tf, KeyEvent.KEY_RELEASED, w, 0, code, ch));
         }
      } else {
         // macOS does not allow activating the JVM while the person uses another application:
         // without a focus owner the KeyboardFocusManager drops the keys. The
         // events that do not depend on the focus are queued: the ActionEvent that the
         // peer publishes when Enter is pressed, and the Esc key via processEvent.
         System.out.println("  (the JVM is not the active application: Enter as the peer's ActionEvent, Esc via processEvent)");
         tf.setText("hello");
         q.postEvent(new ActionEvent(tf, ActionEvent.ACTION_PERFORMED, "hello", System.currentTimeMillis(), 0));
         final KeyEvent esc = new KeyEvent(tf, KeyEvent.KEY_PRESSED, System.currentTimeMillis(), 0, KeyEvent.VK_ESCAPE, (char) 27);
         EventQueue.invokeAndWait(new Runnable() {
            public void run() {
               try {
                  java.lang.reflect.Method m = java.awt.Component.class.getDeclaredMethod("processEvent", java.awt.AWTEvent.class);
                  m.setAccessible(true);
                  m.invoke(tf, esc);
               } catch (Exception e) {
                  // java.awt not opened: checked through the adapter directly
                  for (java.awt.event.KeyListener l : tf.getKeyListeners()) {
                     l.keyPressed(esc);
                  }
               }
            }
         });
         check(esc.isConsumed(), "Esc consumed by handleEvent is also consumed as a KeyEvent");
      }
      Thread.sleep(1000);
      System.out.println("  1.0 events seen: " + seen + ", text: [" + tf.getText() + "]");
      check(seen.contains("esc"), "Esc reaches handleEvent as KEY_PRESS 27");
      check(seen.contains("action:hello"), "Enter reaches the parent as ACTION_EVENT with the text");
      f.dispose();
   }
}

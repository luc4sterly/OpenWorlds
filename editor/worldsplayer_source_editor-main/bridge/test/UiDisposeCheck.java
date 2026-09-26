import java.awt.Dialog;
import java.awt.EventQueue;
import java.awt.Frame;
import java.awt.GraphicsEnvironment;
import java.awt.KeyboardFocusManager;
import java.awt.TextField;
import java.awt.Window;
import java.awt.event.ComponentAdapter;
import java.awt.event.ComponentListener;

import NET.worlds.core.AwtCompat;

/**
 * PolledDialog.mainCallback is synchronized and closes the dialog with
 * setVisible(false), parent.requestFocus() and dispose(). On X11 today's AWT
 * takes the window's monitor on the event thread when a text field gains the
 * focus or is removed (InputContext.add/removeClientWindowListeners). So
 * WorldsMark > Change Location... stayed black and froze the UI.
 * AwtCompat.closeHoldingLock does the three calls on the event thread and
 * releases the monitor while they run.
 *
 * <p>Needs a screen (the CI runs the checks under xvfb-run); without one it
 * only says so. The last part runs the original close to show that the
 * deadlock is real on this Java. It is informational, since it depends on the
 * input method, and when it hangs the check ends with halt.
 */
public class UiDisposeCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLA ") + what);
      if (!ok) {
         fails++;
      }
   }

   /** Takes its own monitor on the event thread while it is disposed, like InputContext does. */
   static class Grabby extends Dialog {
      final ComponentListener l = new ComponentAdapter() {
      };

      Grabby(Frame f) {
         super(f, "UiDisposeCheck", false);
         this.addComponentListener(this.l);
      }

      public void removeNotify() {
         this.removeComponentListener(this.l); // synchronized (this)
         super.removeNotify();
      }
   }

   /** Fails when it is hidden. */
   static final class Faulty extends Grabby {
      Faulty(Frame f) {
         super(f);
      }

      public void setVisible(boolean b) {
         if (!b) {
            throw new IllegalStateException("prueba");
         }
         super.setVisible(b);
      }
   }

   /**
    * Closes w on a thread that holds w's monitor, like the Gamma Main thread
    * in PolledDialog.mainCallback: with AwtCompat, or with the calls of the
    * original. Returns whether it ended within ms; out[0] says whether the
    * monitor was held afterwards, out[1] what was thrown.
    */
   static boolean closeUnderLock(final Window w, final Frame parent, final boolean compat, long ms, final Object[] out)
      throws InterruptedException {
      Thread t = new Thread(new Runnable() {
         public void run() {
            synchronized (w) {
               try {
                  if (compat) {
                     AwtCompat.closeHoldingLock(w, parent);
                  } else {
                     w.setVisible(false);
                     parent.requestFocus();
                     w.dispose();
                  }
               } catch (Throwable e) {
                  out[1] = e;
               }
               out[0] = Thread.holdsLock(w);
            }
         }
      }, "gamma-main-sim");
      t.setDaemon(true);
      t.start();
      t.join(ms);
      return !t.isAlive();
   }

   /**
    * Shows a dialog and gives the focus to its text field. With settle, it
    * also waits for the event thread to finish the focus events; without,
    * it returns as soon as the focus owner changes, while they may still be
    * running. Null if the focus never arrives.
    */
   static Dialog focusedTextDialog(Frame f, boolean settle) throws Exception {
      final Dialog d = new Dialog(f, "UiDisposeCheck texto", false);
      final TextField tf = new TextField("home:Chaos/chaos.world", 40);
      d.add(tf);
      d.pack();
      d.setVisible(true);
      for (int i = 0; i < 60; i++) {
         EventQueue.invokeAndWait(new Runnable() {
            public void run() {
               tf.requestFocus();
            }
         });
         if (KeyboardFocusManager.getCurrentKeyboardFocusManager().getFocusOwner() == tf) {
            if (settle) {
               Thread.sleep(200);
               EventQueue.invokeAndWait(new Runnable() {
                  public void run() {
                  }
               });
            }
            return d;
         }
         Thread.sleep(50);
      }
      return null;
   }

   static void giveUp() {
      // the event thread is stuck for good: what follows could not run
      System.out.println("UiDisposeCheck: " + fails + " fallos");
      Runtime.getRuntime().halt(1);
   }

   public static void main(String[] a) throws Exception {
      if (GraphicsEnvironment.isHeadless()) {
         System.out.println("sin pantalla: se omite (la CI lo pasa bajo xvfb-run)");
         System.exit(0);
      }
      Frame f = new Frame("UiDisposeCheck");
      f.setSize(200, 100);
      f.setVisible(true);
      Object[] out = new Object[2];

      // 1: the event thread needs the window's monitor during dispose
      Grabby g = new Grabby(f);
      g.pack();
      g.setVisible(true);
      boolean ended = closeUnderLock(g, f, true, 10000L, out);
      check(ended, "con el monitor tomado y el hilo de eventos pidiendolo: termina");
      if (!ended) {
         giveUp();
      }
      check(!g.isVisible() && !g.isDisplayable(), "al volver la ventana ya esta oculta y cerrada (como el dispose de 2004)");
      check(Boolean.TRUE.equals(out[0]) && out[1] == null, "al volver el llamante vuelve a tener el monitor");

      // 2: from the event thread and without the monitor the calls run right there
      final Grabby g2 = new Grabby(f);
      g2.pack();
      final Frame owner = f;
      EventQueue.invokeAndWait(new Runnable() {
         public void run() {
            AwtCompat.closeHoldingLock(g2, owner);
         }
      });
      check(!g2.isDisplayable(), "desde el hilo de eventos: se cierra ahi mismo");
      Grabby g3 = new Grabby(f);
      g3.pack();
      AwtCompat.closeHoldingLock(g3, f);
      check(!g3.isDisplayable(), "sin el monitor: se cierra ahi mismo");

      // 3: an exception on the event thread reaches the caller, as on its own thread
      Faulty bad = new Faulty(f);
      bad.pack();
      ended = closeUnderLock(bad, f, true, 10000L, out);
      check(ended && out[1] instanceof IllegalStateException && "prueba".equals(((Throwable) out[1]).getMessage()),
         "una excepcion del cierre llega al llamante");
      bad.dispose();

      // 4: the real case, a text field with the focus (LocationDialog),
      // after the focus events and while they still run
      int tried = 0;
      int closed = 0;
      for (int i = 0; i < 8; i++) {
         Dialog d = focusedTextDialog(f, i % 2 == 0);
         if (d == null) {
            continue;
         }
         tried++;
         out[1] = null;
         if (closeUnderLock(d, f, true, 10000L, out) && !d.isDisplayable() && out[1] == null) {
            closed++;
         } else {
            check(false, "dialogo con campo de texto enfocado " + i + ": no se cerro");
            giveUp();
         }
      }
      if (tried == 0) {
         System.out.println("(el campo de texto nunca tuvo el foco: se omite el caso real)");
      } else {
         check(closed == tried, "dialogo con campo de texto enfocado: se cierra " + closed + " de " + tried + " veces");
      }

      // 5: informational, the original close on this Java
      Dialog r = focusedTextDialog(f, true);
      boolean hung = false;
      if (r == null) {
         System.out.println("(sin foco en el campo de texto: no se prueba el cierre original)");
      } else {
         hung = !closeUnderLock(r, f, false, 5000L, out);
         System.out.println(hung
            ? "info: el cierre original con el monitor tomado se bloquea en este Java (lo que evita AwtCompat)"
            : "info: el cierre original con el monitor tomado no se bloquea en este Java (depende del metodo de entrada)");
      }

      System.out.println(fails == 0 ? "UiDisposeCheck: todo OK" : "UiDisposeCheck: " + fails + " fallos");
      if (hung) {
         Runtime.getRuntime().halt(fails == 0 ? 0 : 1);
      }
      f.dispose();
      System.exit(fails == 0 ? 0 : 1);
   }
}

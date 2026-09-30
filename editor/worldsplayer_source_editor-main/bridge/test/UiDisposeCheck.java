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
      System.out.println((ok ? "OK   " : "FAIL ") + what);
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
      System.out.println("UiDisposeCheck: " + fails + " failures");
      Runtime.getRuntime().halt(1);
   }

   public static void main(String[] a) throws Exception {
      if (GraphicsEnvironment.isHeadless()) {
         System.out.println("no display: skipped (the CI runs it under xvfb-run)");
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
      check(ended, "with the monitor held and the event thread asking for it: it finishes");
      if (!ended) {
         giveUp();
      }
      check(!g.isVisible() && !g.isDisplayable(), "on return the window is already hidden and closed (like the 2004 dispose)");
      check(Boolean.TRUE.equals(out[0]) && out[1] == null, "on return the caller holds the monitor again");

      // 2: from the event thread and without the monitor the calls run right there
      final Grabby g2 = new Grabby(f);
      g2.pack();
      final Frame owner = f;
      EventQueue.invokeAndWait(new Runnable() {
         public void run() {
            AwtCompat.closeHoldingLock(g2, owner);
         }
      });
      check(!g2.isDisplayable(), "from the event thread: it closes right there");
      Grabby g3 = new Grabby(f);
      g3.pack();
      AwtCompat.closeHoldingLock(g3, f);
      check(!g3.isDisplayable(), "without the monitor: it closes right there");

      // 3: an exception on the event thread reaches the caller, as on its own thread
      Faulty bad = new Faulty(f);
      bad.pack();
      ended = closeUnderLock(bad, f, true, 10000L, out);
      check(ended && out[1] instanceof IllegalStateException && "prueba".equals(((Throwable) out[1]).getMessage()),
         "an exception from the close reaches the caller");
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
            check(false, "dialog with a focused text field " + i + ": did not close");
            giveUp();
         }
      }
      if (tried == 0) {
         System.out.println("(the text field never got the focus: the real case is skipped)");
      } else {
         check(closed == tried, "dialog with a focused text field: it closes " + closed + " of " + tried + " times");
      }

      // 5: informational, the original close on this Java
      Dialog r = focusedTextDialog(f, true);
      boolean hung = false;
      if (r == null) {
         System.out.println("(no focus on the text field: the original close is not tested)");
      } else {
         hung = !closeUnderLock(r, f, false, 5000L, out);
         System.out.println(hung
            ? "info: the original close with the monitor held blocks on this Java (which AwtCompat avoids)"
            : "info: the original close with the monitor held does not block on this Java (it depends on the input method)");
      }

      System.out.println(fails == 0 ? "UiDisposeCheck: all OK" : "UiDisposeCheck: " + fails + " failures");
      if (hung) {
         Runtime.getRuntime().halt(fails == 0 ? 0 : 1);
      }
      f.dispose();
      System.exit(fails == 0 ? 0 : 1);
   }
}

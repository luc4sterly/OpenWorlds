package NET.worlds.core;

import java.awt.Component;
import java.awt.EventQueue;
import java.awt.Window;

/**
 * AWT behaviour that the 2004 client relies on and today's AWT does not have.
 * These are Java differences, not gamma.dll.
 */
public final class AwtCompat {
   private AwtCompat() {
   }

   /**
    * How PolledDialog.mainCallback closes a finished dialog:
    * w.setVisible(false), focusTo.requestFocus() and, while w is displayable,
    * w.dispose(), in that order. The caller holds w's monitor, because
    * mainCallback is synchronized and runs on the Gamma Main thread.
    *
    * <p>With today's AWT on X11 that deadlocks. The X11 input method asks for
    * client window notification (XInputMethod.setInputMethodContext calls
    * enableClientWindowNotification; the macOS and Windows ones do not). So
    * the event thread takes the window's monitor, while holding the AWT tree
    * lock, whenever a text field of the window gains the focus or is removed
    * (InputContext.addClientWindowListeners and removeClientWindowListeners,
    * then Component.add/removeComponentListener, which are synchronized).
    * Two deadlocks follow:
    * <ul>
    * <li>dispose() waits for the event thread (Window.doDispose,
    *     EventQueue.invokeAndWait), and the event thread waits for the
    *     monitor to remove the text field. The dialog stays on screen, black,
    *     and the whole AWT UI stops. This happens every time with
    *     WorldsMark > Change Location..., a LocationDialog with a text
    *     field.</li>
    * <li>setVisible(false) wants the tree lock, which the event thread holds
    *     while it waits for the monitor to hand the focus to a text field of
    *     the dialog.</li>
    * </ul>
    * In the Java the client was written for, dispose ran on the caller's
    * thread and none of this took the window's monitor.
    *
    * <p>Here the event thread does the three calls. Meanwhile the caller
    * waits with its hold on w's monitor released (Object.wait releases
    * re-entrant holds too) and holds no AWT lock. It takes the monitor again
    * before returning, with the dialog already closed, as the original
    * continued after dispose. An exception from the three calls is thrown
    * here, as it would have been on the caller's thread.
    *
    * <p>Waiters on w that re-check their condition in a loop, as
    * NewVersionDialog.confirmRestart and UpgradeDialog.confirmUpgrade do, are
    * not affected by the notifyAll.
    *
    * <p>⚠️ VERIFICAR: other code of the client still touches AWT while it
    * holds a dialog's monitor: build/pack/show on a dialog's first
    * mainCallback, and the activeCallback of LoginWizard or
    * TransformEditorDialog. On X11 that can deadlock the same way if a text
    * field of that dialog gains the focus at that moment. It has not been
    * seen, and nothing is changed there.
    */
   public static void closeHoldingLock(final Window w, final Component focusTo) {
      runReleasing(w, new Runnable() {
         public void run() {
            w.setVisible(false);
            focusTo.requestFocus();
            if (w.isDisplayable()) { // Component.getPeer() != null until Java 8
               w.dispose();
            }
         }
      });
   }

   /**
    * Runs r on the event thread while the caller's hold on w's monitor is
    * released; returns when r has ended. Without that hold, or on the event
    * thread, r runs right here.
    */
   static void runReleasing(final Window w, final Runnable r) {
      if (EventQueue.isDispatchThread() || !Thread.holdsLock(w)) {
         r.run();
         return;
      }
      final boolean[] done = new boolean[1];
      final Throwable[] failure = new Throwable[1];
      EventQueue.invokeLater(new Runnable() {
         public void run() {
            try {
               r.run();
            } catch (Throwable t) {
               failure[0] = t;
            } finally {
               synchronized (w) {
                  done[0] = true;
                  w.notifyAll();
               }
            }
         }
      });
      boolean interrupted = false;
      while (!done[0]) {
         try {
            w.wait();
         } catch (InterruptedException e) {
            interrupted = true;
         }
      }
      if (interrupted) {
         Thread.currentThread().interrupt();
      }
      Throwable t = failure[0];
      if (t instanceof RuntimeException) {
         throw (RuntimeException) t;
      } else if (t instanceof Error) {
         throw (Error) t;
      } else if (t != null) {
         throw new RuntimeException(t);
      }
   }
}

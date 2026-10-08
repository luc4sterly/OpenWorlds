package javax.swing;

import java.awt.Component;
import java.awt.Container;
import java.awt.EventQueue;
import java.awt.Window;
import java.lang.reflect.InvocationTargetException;

/** The few javax.swing.SwingUtilities methods the bridge uses (there is no Swing here). */
public class SwingUtilities {
   private SwingUtilities() {
   }

   /** The first Window above c (a window's own parent is its owner, as in the JDK). */
   public static Window getWindowAncestor(Component c) {
      for (Container p = c.getParent(); p != null; p = p.getParent()) {
         if (p instanceof Window) {
            return (Window) p;
         }
      }
      return null;
   }

   public static boolean isEventDispatchThread() {
      return EventQueue.isDispatchThread();
   }

   public static void invokeLater(Runnable doRun) {
      EventQueue.invokeLater(doRun);
   }

   public static void invokeAndWait(Runnable doRun) throws InterruptedException, InvocationTargetException {
      EventQueue.invokeAndWait(doRun);
   }
}

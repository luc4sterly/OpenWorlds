package java.awt;

import java.awt.event.InvocationEvent;
import java.awt.event.PaintEvent;
import java.lang.reflect.InvocationTargetException;
import java.util.HashMap;
import java.util.LinkedList;

/**
 * The AWT event queue and its dispatch thread, as java.awt.EventQueue.
 * Repaint requests are merged per component (one UPDATE with the union of
 * the areas), as the JDK coalesces PaintEvents.
 */
public class EventQueue {
   private static final EventQueue systemQueue = new EventQueue();

   private final LinkedList<AWTEvent> queue = new LinkedList<AWTEvent>();
   private final HashMap<Component, PaintEvent> pendingRepaints = new HashMap<Component, PaintEvent>();
   private Thread dispatchThread;
   private static volatile AWTEvent currentEvent;
   private static volatile long mostRecentEventTime = System.currentTimeMillis();

   public EventQueue() {
   }

   static EventQueue get() {
      return systemQueue;
   }

   /** Posts to the system queue. */
   static void post(AWTEvent e) {
      systemQueue.postEvent(e);
   }

   public void postEvent(AWTEvent theEvent) {
      if (theEvent == null) {
         throw new NullPointerException();
      }
      synchronized (this) {
         queue.add(theEvent);
         startDispatchThread();
         notifyAll();
      }
   }

   static void postRepaint(Component c, Rectangle r) {
      systemQueue.repaint(c, r);
   }

   private synchronized void repaint(Component c, Rectangle r) {
      PaintEvent pending = pendingRepaints.get(c);
      if (pending != null) {
         pending.setUpdateRect(pending.getUpdateRect().union(r));
         return;
      }
      PaintEvent e = new PaintEvent(c, PaintEvent.UPDATE, r);
      pendingRepaints.put(c, e);
      queue.add(e);
      startDispatchThread();
      notifyAll();
   }

   /** A full PAINT of a component (a window shown or uncovered), merged with any pending repaint of it. */
   static void postPaint(Component c, Rectangle r) {
      systemQueue.paint(c, r);
   }

   private synchronized void paint(Component c, Rectangle r) {
      PaintEvent e = new PaintEvent(c, PaintEvent.PAINT, r);
      queue.add(e);
      startDispatchThread();
      notifyAll();
   }

   static void wakeUp() {
      synchronized (systemQueue) {
         systemQueue.notifyAll();
      }
   }

   private void startDispatchThread() {
      if (dispatchThread == null) {
         dispatchThread = new Thread("AWT-EventQueue-0") {
            public void run() {
               pumpWhile(null);
            }
         };
         dispatchThread.start();
      }
   }

   public AWTEvent getNextEvent() throws InterruptedException {
      synchronized (this) {
         while (queue.isEmpty()) {
            wait();
         }
         return take();
      }
   }

   private AWTEvent take() {
      AWTEvent e = queue.removeFirst();
      if (e instanceof PaintEvent && e.getID() == PaintEvent.UPDATE) {
         pendingRepaints.remove(e.getSource());
      }
      return e;
   }

   public synchronized AWTEvent peekEvent() {
      return queue.isEmpty() ? null : queue.getFirst();
   }

   public synchronized AWTEvent peekEvent(int id) {
      for (AWTEvent e : queue) {
         if (e.getID() == id) {
            return e;
         }
      }
      return null;
   }

   protected void dispatchEvent(AWTEvent event) {
      Object src = event.getSource();
      if (event instanceof ActiveEvent) {
         currentEvent = event;
         ((ActiveEvent) event).dispatch();
      } else if (src instanceof Component) {
         currentEvent = event;
         ((Component) src).dispatchEvent(event);
      } else if (src instanceof MenuComponent) {
         currentEvent = event;
         ((MenuComponent) src).dispatchEvent(event);
      } else {
         System.err.println("unable to dispatch event: " + event);
      }
      if (event instanceof java.awt.event.InputEvent) {
         mostRecentEventTime = ((java.awt.event.InputEvent) event).getWhen();
      }
      currentEvent = null;
   }

   interface Condition {
      boolean holds();
   }

   /**
    * Dispatches events on this thread while the condition holds (forever for
    * null): the dispatch thread's loop, and the nested loop of a modal
    * dialog shown from the dispatch thread.
    */
   static void pumpWhile(Condition condition) {
      EventQueue q = systemQueue;
      while (condition == null || condition.holds()) {
         AWTEvent e;
         synchronized (q) {
            // checked before each event: what a closed menu or dialog posted goes to the outer loop
            while (true) {
               if (condition != null && !condition.holds()) {
                  return;
               }
               if (!q.queue.isEmpty()) {
                  break;
               }
               try {
                  q.wait(condition == null ? 0 : 100);
               } catch (InterruptedException ex) {
                  if (condition != null) {
                     Thread.currentThread().interrupt();
                     return;
                  }
               }
            }
            e = q.take();
         }
         try {
            q.dispatchEvent(e);
         } catch (ThreadDeath td) {
            throw td;
         } catch (Throwable t) {
            System.err.println("Exception in thread \"" + Thread.currentThread().getName() + "\" " + t);
            t.printStackTrace();
         }
         if (condition == null && WindowSystem.noWindowsLeft() && q.isEmpty()) {
            // the JDK's dispatch thread ends with the last window (AWT auto-shutdown)
            synchronized (q) {
               if (q.queue.isEmpty() && WindowSystem.noWindowsLeft()) {
                  q.dispatchThread = null;
                  return;
               }
            }
         }
      }
   }

   private synchronized boolean isEmpty() {
      return queue.isEmpty();
   }

   public static boolean isDispatchThread() {
      return Thread.currentThread() == systemQueue.dispatchThread;
   }

   public static AWTEvent getCurrentEvent() {
      return isDispatchThread() ? currentEvent : null;
   }

   public static long getMostRecentEventTime() {
      return mostRecentEventTime;
   }

   public static void invokeLater(Runnable runnable) {
      post(new InvocationEvent(Toolkit.getDefaultToolkit(), runnable));
   }

   public static void invokeAndWait(Runnable runnable) throws InterruptedException, InvocationTargetException {
      if (isDispatchThread()) {
         throw new Error("Cannot call invokeAndWait from the event dispatcher thread");
      }
      Object lock = new Object();
      InvocationEvent event = new InvocationEvent(Toolkit.getDefaultToolkit(), runnable, lock, true);
      synchronized (lock) {
         post(event);
         while (!event.isDispatched()) {
            lock.wait();
         }
      }
      Throwable t = event.getThrowable();
      if (t != null) {
         throw new InvocationTargetException(t);
      }
   }

   public void push(EventQueue newEventQueue) {
      throw new UnsupportedOperationException("EventQueue.push");
   }

   protected void pop() {
      throw new UnsupportedOperationException("EventQueue.pop");
   }
}

package java.awt.event;

import java.awt.AWTEvent;
import java.awt.ActiveEvent;

public class InvocationEvent extends AWTEvent implements ActiveEvent {
   public static final int INVOCATION_FIRST = 1200;
   public static final int INVOCATION_DEFAULT = INVOCATION_FIRST;
   public static final int INVOCATION_LAST = INVOCATION_DEFAULT;

   protected Runnable runnable;
   protected Object notifier;
   protected boolean catchExceptions;
   private Exception exception;
   private Throwable throwable;
   private long when;
   private volatile boolean dispatched;

   protected InvocationEvent(Object source, int id, Runnable runnable, Object notifier, boolean catchThrowables) {
      super(source, id);
      this.runnable = runnable;
      this.notifier = notifier;
      this.catchExceptions = catchThrowables;
      this.when = System.currentTimeMillis();
   }

   public InvocationEvent(Object source, Runnable runnable) {
      this(source, INVOCATION_DEFAULT, runnable, null, false);
   }

   public InvocationEvent(Object source, Runnable runnable, Object notifier, boolean catchThrowables) {
      this(source, INVOCATION_DEFAULT, runnable, notifier, catchThrowables);
   }

   public void dispatch() {
      try {
         if (catchExceptions) {
            try {
               runnable.run();
            } catch (Throwable t) {
               if (t instanceof Exception) {
                  exception = (Exception) t;
               }
               throwable = t;
            }
         } else {
            runnable.run();
         }
      } finally {
         dispatched = true;
         if (notifier != null) {
            synchronized (notifier) {
               notifier.notifyAll();
            }
         }
      }
   }

   public boolean isDispatched() {
      return dispatched;
   }

   public Exception getException() {
      return catchExceptions ? exception : null;
   }

   public Throwable getThrowable() {
      return catchExceptions ? throwable : null;
   }

   public long getWhen() {
      return when;
   }
}

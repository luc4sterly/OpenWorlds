package java.awt;

/**
 * Auto-repeat while a scroll arrow or a track is held: the action now, again
 * after 350 ms, then every 50 ms, on the event thread, until stop().
 */
final class Repeater {
   private static Thread thread;
   private static Runnable action;
   private static long next;
   private static final Object LOCK = new Object();

   private Repeater() {
   }

   static void start(Runnable r) {
      r.run();
      synchronized (LOCK) {
         action = r;
         next = System.currentTimeMillis() + 350;
         if (thread == null) {
            thread = new Thread("AWT-Repeat") {
               public void run() {
                  loop();
               }
            };
            thread.setDaemon(true);
            thread.start();
         }
         LOCK.notifyAll();
      }
   }

   static void stop() {
      synchronized (LOCK) {
         action = null;
         LOCK.notifyAll();
      }
   }

   private static void loop() {
      while (true) {
         Runnable r;
         synchronized (LOCK) {
            while (action == null) {
               try {
                  LOCK.wait();
               } catch (InterruptedException e) {
                  return;
               }
            }
            long wait = next - System.currentTimeMillis();
            if (wait > 0) {
               try {
                  LOCK.wait(wait);
               } catch (InterruptedException e) {
                  return;
               }
               continue;
            }
            r = action;
            next = System.currentTimeMillis() + 50;
         }
         EventQueue.invokeLater(r);
      }
   }
}

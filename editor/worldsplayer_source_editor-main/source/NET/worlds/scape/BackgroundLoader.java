package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import NET.worlds.network.URL;
import java.util.Vector;

public class BackgroundLoader implements MainCallback, Runnable {
   private static BackgroundLoader bg = new BackgroundLoader();
   private BackgroundLoaderQueue readQueue = new BackgroundLoaderQueue();
   private BackgroundLoaderQueue asyncLoadQueue = new BackgroundLoaderQueue();
   private Vector syncLoadQueue = new Vector();
   private Thread asyncLoaderThread;
   int nextSync = 0;

   public static void get(BGLoaded var0, URL var1) {
      get(var0, var1, false);
   }

   public static void get(BGLoaded var0, URL var1, boolean var2) {
      new BackgroundLoaderElement(var0, var1, var2);
   }

   static void activeRoomChanged(Room var0) {
      bg.asyncLoadQueue.activeRoomChanged(var0);
   }

   static void asyncLoad(BackgroundLoaderElement var0) {
      bg.asyncLoadQueue.add(var0);
   }

   static void syncLoad(BackgroundLoaderElement var0) {
      bg.syncLoadQueue.addElement(var0);
   }

   private BackgroundLoader() {
      this.asyncLoaderThread = new Thread(this);
      this.asyncLoaderThread.setDaemon(true);
      this.asyncLoaderThread.start();
      Main.register(this);
   }

   public void run() {
      Debug.dAssert(Thread.currentThread() == this.asyncLoaderThread);

      while (true) {
         BackgroundLoaderElement var1 = this.asyncLoadQueue.getItem();
         var1.asyncLoad();
         synchronized (this) {
            this.syncLoadQueue.addElement(var1);

            while (this.syncLoadQueue.size() > 0) {
               try {
                  this.wait();
               } catch (InterruptedException var5) {
               }

               if (this.asyncLoadQueue.hasHighPriorityItems()) {
                  break;
               }
            }
         }
      }
   }

   public synchronized void mainCallback() {
      if (this.syncLoadQueue.size() != 0) {
         if (this.nextSync >= this.syncLoadQueue.size()) {
            this.nextSync = 0;
         }

         BackgroundLoaderElement var1 = (BackgroundLoaderElement)this.syncLoadQueue.elementAt(this.nextSync);
         if (!var1.syncLoad()) {
            this.syncLoadQueue.removeElementAt(this.nextSync);
            if (this.syncLoadQueue.size() == 0) {
               this.notify();
            }
         } else {
            if (this.asyncLoadQueue.hasHighPriorityItems()) {
               this.notify();
            }

            this.nextSync++;
         }
      }
   }
}

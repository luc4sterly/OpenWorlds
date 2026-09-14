package NET.worlds.network;

import NET.worlds.console.Cursor;
import java.util.Observer;

public class CacheFile {
   private URL url;
   private CacheEntry entry;
   private boolean active;

   CacheFile(URL var1, CacheEntry var2) {
      this.url = var1;
      this.active = true;
      this.entry = var2;
      if (var2 != null) {
         var2.incRef();
      }
   }

   public void finalize() {
      if (this.active) {
         this.active = false;
         if (this.entry != null) {
            this.entry.safeDecRef();
         }
      }
   }

   public synchronized void close() {
      this.finalize();
   }

   public synchronized void markTemporary() {
      if (this.entry != null) {
         this.entry.remoteTime = 0L;
      }
   }

   public boolean isActive() {
      return this.active;
   }

   public void callWhenLoaded(Observer var1) {
      if (this.entry == null) {
         var1.update(null, this.url);
      } else {
         this.entry.addObserver(var1);
      }
   }

   public void waitUntilLoaded() {
      if (this.entry != null) {
         synchronized (this.entry) {
            boolean var2 = true;
            Cursor var3 = Cursor.getActive();
            if (var3 == null) {
               var3 = new Cursor(URL.make("system:WAIT_CURSOR"));
               var3.activate();
            }

            URL var4 = var3.getURL();
            var3.setURL(URL.make("system:WAIT_CURSOR"));

            while (this.active && !this.done()) {
               try {
                  this.entry.wait();
               } catch (InterruptedException var7) {
               }
            }

            var3.setURL(var4);
         }
      }
   }

   public boolean error() {
      return this.entry == null ? false : this.entry.state == 5 || this.entry.state == 6;
   }

   public boolean done() {
      return this.entry == null ? true : this.entry.done();
   }

   public String getLocalName() {
      return this.entry != null ? this.entry.localName : this.url.unalias();
   }

   public int bytesLoaded() {
      return this.entry.bytes;
   }
}

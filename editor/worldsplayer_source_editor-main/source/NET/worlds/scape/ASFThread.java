package NET.worlds.scape;

import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.URL;

class ASFThread extends Thread {
   private URL url;
   private ASFSoundPlayer player;
   private static ASFThread asfThread;
   private static boolean paused;

   ASFThread(URL var1, ASFSoundPlayer var2) {
      this.url = var1;
      this.player = var2;
      setASF(this);
   }

   public void run() {
      CacheFile var1 = Cache.getFile(this.url);
      var1.waitUntilLoaded();
      if (var1.error()) {
         this.player.running = 3;
         releaseASF(this);
      } else if (!paused) {
         String var2 = var1.getLocalName().replace('/', '\\');
         if (!ASFSoundPlayer.nativePlay(var2)) {
            this.player.running = 3;
         }

         releaseASF(this);
      }
   }

   static synchronized void pauseASF() {
      if (!paused && asfThread != null) {
         ASFThread var0 = asfThread;
         stopASF();
         paused = true;
         new ASFThread(var0.url, var0.player);
      }

      paused = true;
   }

   static synchronized void resumeASF() {
      if (paused) {
         ASFThread var0 = asfThread;
         paused = false;
         if (var0 != null) {
            new ASFThread(var0.url, var0.player);
         }
      }
   }

   static synchronized void releaseASF(ASFThread var0) {
      if (asfThread == var0) {
         asfThread = null;
      }
   }

   static synchronized void setASF(ASFThread var0) {
      if (asfThread == null || !asfThread.url.equals(var0.url)) {
         asfThread = var0;
         asfThread.setDaemon(true);
         asfThread.start();
      }
   }

   static synchronized void stopASF() {
      if (asfThread != null) {
         asfThread = null;
         if (!paused) {
            ASFSoundPlayer.nativePlay("");
         }
      }
   }

   static boolean isActive() {
      return asfThread != null;
   }
}

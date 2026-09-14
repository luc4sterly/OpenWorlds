package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.core.IniFile;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.URL;
import java.util.Observable;
import java.util.Observer;

class BackgroundLoaderElement implements Observer {
   private BGLoaded object;
   private Object arg;
   private URL url;
   private Room room;
   private boolean inAllRooms;
   private CacheFile rfile;
   private static boolean immedLoadLocals = IniFile.gamma().getIniInt("BackgroundLoadLocalFiles", 0) == 0;

   BackgroundLoaderElement(BGLoaded var1, URL var2, boolean var3) {
      boolean var4 = Main.isMainThread();
      this.object = var1;
      this.url = var2;
      if (var3) {
         this.inAllRooms = true;
      } else {
         this.getRoom(var4);
      }

      this.read(var4);
   }

   public void update(Observable var1, Object var2) {
      BackgroundLoader.asyncLoad(this);
   }

   private void read(boolean var1) {
      this.rfile = this.url != null && this.url.isRemote() ? Cache.getFile(this.url) : null;
      if ((this.rfile == null || this.rfile.done()) && immedLoadLocals) {
         this.asyncLoad();
         if (!var1 || this.syncLoad()) {
            BackgroundLoader.syncLoad(this);
         }
      } else if (this.rfile == null) {
         BackgroundLoader.asyncLoad(this);
      } else {
         this.rfile.callWhenLoaded(this);
      }
   }

   void asyncLoad() {
      String var1;
      if (this.rfile == null) {
         var1 = this.url.unalias();
      } else {
         var1 = this.rfile.getLocalName();
      }

      this.arg = this.object.asyncBackgroundLoad(var1, this.url);
   }

   boolean syncLoad() {
      if (this.object.syncBackgroundLoad(this.arg, this.url)) {
         return true;
      }

      if (this.rfile != null) {
         this.rfile.finalize();
         this.rfile = null;
      }

      return false;
   }

   boolean inAllRooms() {
      return this.inAllRooms;
   }

   Room getRoom(boolean var1) {
      if (this.room == null && !this.inAllRooms && var1) {
         this.room = this.object.getBackgroundLoadRoom();
      }

      return this.room;
   }
}

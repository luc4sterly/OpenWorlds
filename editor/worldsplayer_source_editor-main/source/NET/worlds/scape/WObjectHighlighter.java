package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;

class WObjectHighlighter implements MainCallback {
   private WObject target;
   private Room room;
   private boolean newState;
   private boolean registered;

   public WObjectHighlighter(WObject var1) {
      this.target = var1;
      this.start();
   }

   public synchronized void mainCallback() {
      if (this.newState != this.target.getHighlit()) {
         this.target.setHighlit(this.newState);
         if (this.newState) {
            this.room = this.target.getRoom();
            if (this.room != null) {
               this.room.highlightTarget = this.target;
            }
         } else if (this.room != null) {
            this.room.highlightTarget = null;
            this.room = null;
         }
      }

      Main.unregister(this);
      this.registered = false;
   }

   public synchronized void start() {
      this.newState = true;
      this.registerMe();
   }

   public synchronized void stop() {
      this.newState = false;
      this.registerMe();
   }

   private synchronized void registerMe() {
      if (!this.registered) {
         Main.register(this);
         this.registered = true;
      }
   }
}

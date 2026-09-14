package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import java.util.Vector;

class MCIThread implements MainCallback, MainTerminalCallback {
   private Vector queue = new Vector();
   private int frameNum;

   public MCIThread() {
      Main.register(this);
   }

   public synchronized void pushCommand(MCISoundCommand var1) {
      this.queue.addElement(var1);
      var1.onQueue(true);
      var1.frameNum = this.frameNum + 2;
   }

   public synchronized void mainCallback() {
      this.frameNum++;

      while (this.queue.size() > 0) {
         MCISoundCommand var1 = (MCISoundCommand)this.queue.elementAt(0);
         if (var1.frameNum > this.frameNum) {
            return;
         }

         var1.onQueue(false);
         this.queue.removeElementAt(0);
         var1.run();
      }
   }

   public synchronized void terminalCallback() {
      MCISoundPlayer.shutdown();
      ASFSoundPlayer.shutdown();
      Main.unregister(this);
   }
}

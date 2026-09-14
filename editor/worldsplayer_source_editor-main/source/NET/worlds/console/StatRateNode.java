package NET.worlds.console;

import NET.worlds.core.Std;
import java.awt.List;

class StatRateNode extends StatMan implements MainCallback {
   private static StatRateNode _singleInstance = new StatRateNode();
   private int _lastTime;
   private static final int TITLE = 0;
   private static final int BLANK1 = 1;
   private static final int THREADS = 2;
   private int lastQueueLength;

   public static StatRateNode getNode() {
      return _singleInstance;
   }

   private StatRateNode() {
      StatisticsRoot.getNode().addChild(this);
   }

   public String toString() {
      return "Active Threads";
   }

   synchronized void grabList(List var1) {
      super.grabList(var1);
      Main.register(this);
   }

   synchronized void releaseList(boolean var1) {
      if (!var1) {
         Main.unregister(this);
      }

      super.releaseList(var1);
   }

   public synchronized void mainCallback() {
      int var1 = Std.getFastTime();
      if (var1 - this._lastTime > 1000) {
         this.updateList();
         this._lastTime = var1;
      }
   }

   void createList() {
      this._grabbedList.addItem("Active Thread Statistics", 0);
      this._grabbedList.addItem("", 1);
      this.lastQueueLength = Main.queueLength();
      this._grabbedList.addItem("Number main threads: " + this.lastQueueLength, 2);
   }

   void updateList() {
      if (Main.queueLength() != this.lastQueueLength) {
         this.lastQueueLength = Main.queueLength();
         this._grabbedList.replaceItem("Number main threads: " + this.lastQueueLength, 2);
      }
   }
}

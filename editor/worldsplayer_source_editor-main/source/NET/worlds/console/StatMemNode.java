package NET.worlds.console;

import NET.worlds.core.Std;
import java.awt.List;

public class StatMemNode extends StatMan implements MainCallback {
   private static StatMemNode _singleInstance = new StatMemNode();
   private int _lastTime;
   private static final int TITLE = 0;
   private static final int BLANK1 = 1;
   private static final int TOTMEM = 2;
   private static final int FREEMEM = 3;
   private static final int BLANK2 = 4;
   private static final int TOTPHYSMEM = 5;
   private static final int AVAILPHYSMEM = 6;
   private static final int SWAPUSED = 7;
   private static final int AVAILVIRTMEM = 8;
   private static final int TOTUSED = 9;
   private long _lastTotMem;
   public int _totPhysMem;
   public int _availPhysMem;
   public int _totPageMem;
   public int _availPageMem;

   public static StatMemNode getNode() {
      return _singleInstance;
   }

   private StatMemNode() {
      StatisticsRoot.getNode().addChild(this);
   }

   public static native void nativeInit();

   public String toString() {
      return "System Memory";
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

   public int getVMAvail() {
      this.updateMemoryStatus();
      return this._availPageMem;
   }

   void createList() {
      this._grabbedList.addItem("System Memory Stats", 0);
      this._grabbedList.addItem("", 1);
      this._lastTotMem = Runtime.getRuntime().totalMemory();
      this._grabbedList.addItem("Total " + Std.getProductName() + " Memory Available: " + this._lastTotMem + " bytes", 2);
      this.updateMemoryStatus();
      this._grabbedList.addItem(" Free " + Std.getProductName() + " Memory Available: " + Runtime.getRuntime().freeMemory() + " bytes", 3);
      this._grabbedList.addItem("", 4);
      this._grabbedList.addItem("Total System Physical Memory: " + this._totPhysMem + " bytes", 5);
      this._grabbedList.addItem("Available System Physical Memory: " + this._availPhysMem + " bytes", 6);
      this._grabbedList.addItem("Total System Swapfile Usage: " + (this._totPageMem - this._availPageMem) + " bytes", 7);
      this._grabbedList.addItem("Available Virtual Memory: " + this._availPageMem + " bytes", 8);
   }

   void updateList() {
      long var1 = Runtime.getRuntime().totalMemory();
      if (var1 != this._lastTotMem) {
         this._lastTotMem = var1;
         this._grabbedList.replaceItem("Total " + Std.getProductName() + " Memory Available: " + this._lastTotMem + " bytes", 2);
      }

      this.updateMemoryStatus();
      this._grabbedList.replaceItem(" Free " + Std.getProductName() + " Memory Available: " + Runtime.getRuntime().freeMemory() + " bytes", 3);
      this._grabbedList.replaceItem("Total System Physical Memory: " + this._totPhysMem + " bytes", 5);
      this._grabbedList.replaceItem("Available System Physical Memory: " + this._availPhysMem + " bytes", 6);
      this._grabbedList.replaceItem("Total System Swapfile Usage: " + (this._totPageMem - this._availPageMem) + " bytes", 7);
      this._grabbedList.replaceItem("Available Virtual Memory: " + this._availPageMem + " bytes", 8);
   }

   public native void updateMemoryStatus();

   static {
      nativeInit();
   }
}

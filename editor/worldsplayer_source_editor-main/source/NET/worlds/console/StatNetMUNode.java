package NET.worlds.console;

import NET.worlds.core.Std;
import java.awt.List;

public class StatNetMUNode extends StatMan implements MainCallback {
   private static StatNetMUNode _singleInstance = new StatNetMUNode();
   private int _totBytesSent;
   private int _totBytesRcvd;
   private int _totPacketsSent;
   private int _totPacketsRcvd;
   private int _lastTime;
   private static final int TITLE = 0;
   private static final int BLANK1 = 1;
   private static final int TOTBYTESSENT = 2;
   private static final int TOTBYTESRCVD = 3;
   private static final int BLANK2 = 4;
   private static final int TOTPKTSSENT = 5;
   private static final int TOTPKTSRCVD = 6;

   public static StatNetMUNode getNode() {
      return _singleInstance;
   }

   private StatNetMUNode() {
      StatNetNode.getNode().addChild(this);
   }

   public String toString() {
      return "Multiuser Server Connections";
   }

   public void addBytesSent(int var1) {
      this._totBytesSent += var1;
   }

   public void addBytesRcvd(int var1) {
      this._totBytesRcvd += var1;
   }

   public void addPacketsSent(int var1) {
      this._totPacketsSent += var1;
   }

   public void addPacketsRcvd(int var1) {
      this._totPacketsRcvd += var1;
   }

   void grabList(List var1) {
      super.grabList(var1);
      Main.register(this);
   }

   void releaseList(boolean var1) {
      if (!var1) {
         Main.unregister(this);
      }

      super.releaseList(var1);
   }

   public void mainCallback() {
      int var1 = Std.getFastTime();
      if (var1 - this._lastTime > 1000) {
         this.updateList();
         this._lastTime = var1;
      }
   }

   void createList() {
      this._grabbedList.addItem("Overall Multiuser Server Network Statistics:", 0);
      this._grabbedList.addItem("", 1);
      this._grabbedList.addItem("      Total bytes sent: " + this._totBytesSent + " bytes", 2);
      this._grabbedList.addItem("Total bytes received: " + this._totBytesRcvd + " bytes", 3);
      this._grabbedList.addItem("", 4);
      this._grabbedList.addItem("      Total packets sent: " + this._totPacketsSent + " packets", 5);
      this._grabbedList.addItem("Total packets received: " + this._totPacketsRcvd + " packets", 6);
   }

   void updateList() {
      this._grabbedList.replaceItem("      Total bytes sent: " + this._totBytesSent + " bytes", 2);
      this._grabbedList.replaceItem("Total bytes received: " + this._totBytesRcvd + " bytes", 3);
      this._grabbedList.replaceItem("      Total packets sent: " + this._totPacketsSent + " packets", 5);
      this._grabbedList.replaceItem("Total packets received: " + this._totPacketsRcvd + " packets", 6);
   }
}

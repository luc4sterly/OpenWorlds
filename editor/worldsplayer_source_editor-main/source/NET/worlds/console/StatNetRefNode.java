package NET.worlds.console;

import NET.worlds.core.Std;
import NET.worlds.network.NetworkRoom;
import NET.worlds.network.WorldServer;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Room;
import java.awt.List;
import java.util.Vector;

public class StatNetRefNode extends StatMan implements MainCallback {
   private static StatNetRefNode _singleInstance = new StatNetRefNode();
   private int _totBytesSent;
   private int _totBytesRcvd;
   private int _totPacketsSent;
   private int _totPacketsRcvd;
   private int _lastTime;
   private static final int TITLE = 0;
   private static final int BLANK = 1;
   private int _listCount = 0;

   public static StatNetRefNode getNode() {
      return _singleInstance;
   }

   private StatNetRefNode() {
      StatNetNode.getNode().addChild(this);
   }

   public String toString() {
      return "Drone Referrers to Current Server";
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
      this._grabbedList.addItem("Drones Referring to Current Server:", 0);
      this._grabbedList.addItem("", 1);
      Pilot var1 = Pilot.getActive();
      Room var2 = var1.getRoom();
      NetworkRoom var3 = null;
      if (var2 != null) {
         var3 = var2.getNetworkRoom();
      }

      WorldServer var4 = null;
      if (var3 != null) {
         var4 = var3.getServer();
      }

      if (var4 != null) {
         Vector var5 = var4.printDroneReferrers();

         for (int var6 = var5.size() - 1; var6 >= 0; var6--) {
            String var7 = (String)var5.elementAt(var6);
            this._grabbedList.addItem(var7);
         }
      }
   }

   void updateList() {
      this._grabbedList.delItems(0, this._grabbedList.countItems() - 1);
      this.createList();
   }
}

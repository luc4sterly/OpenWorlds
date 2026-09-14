package NET.worlds.network;

import java.io.IOException;

public class PropertyUpdateCmd extends receivedNetPacket {
   public static final byte PROPUPDCMD = 16;
   protected PropertyList _propList;

   public PropertyUpdateCmd() {
      this._commandType = 16;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._propList = new PropertyList();
      this._propList.parseNetData(var1);
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 != null) {
         var2.propertyUpdate(this._propList);
      } else if ((Galaxy.getDebugLevel() & 32) != 0) {
         System.err.println("PropertyUpdateCmd.process()  status:  message dropped because destination object is null");
      }
   }

   public String toString(WorldServer var1) {
      return "PROPUPD  " + this._objID.toString(var1) + " " + this._propList;
   }
}

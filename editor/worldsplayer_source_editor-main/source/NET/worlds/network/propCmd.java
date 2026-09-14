package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

public class propCmd extends receivedNetPacket {
   public static final byte PROPCMD = 3;
   protected OldPropertyList _propList;

   public propCmd() {
      this._commandType = 3;
      this._propList = new OldPropertyList();
   }

   public propCmd(OldPropertyList var1) {
      super(null, 3);
      this._propList = var1;
   }

   public propCmd(ObjID var1, OldPropertyList var2) {
      super(var1, 3);
      this._propList = var2;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._propList = new OldPropertyList();
      this._propList.parseNetData(var1);
   }

   int packetSize() {
      return super.packetSize() + this._propList.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      Debug.dAssert(this._propList != null);
      this._propList.send(var1);
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 == null) {
         System.err.println("propCmd::process() error:  cannot find object with name " + this._objID);
      } else {
         var2.property(this._propList);
      }
   }

   public String toString(WorldServer var1) {
      return "PROP     " + this._objID.toString(var1) + " " + this._propList;
   }
}

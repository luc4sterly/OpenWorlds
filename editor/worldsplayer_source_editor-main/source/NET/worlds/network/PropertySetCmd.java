package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

public class PropertySetCmd extends receivedNetPacket {
   public static final byte PROPSETCMD = 15;
   private PropertyList _propList;
   private String _fromUser;

   public PropertySetCmd() {
      this._commandType = 15;
   }

   public PropertySetCmd(PropertyList var1) {
      super(null, 15);
      this._propList = var1;
      this._fromUser = new String("");
   }

   public PropertySetCmd(ObjID var1, PropertyList var2) {
      super(var1, 15);
      this._propList = var2;
      this._fromUser = new String("");
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._fromUser = var1.readUTF();
      this._propList = new PropertyList();
      this._propList.parseNetData(var1);
   }

   int packetSize() {
      int var1 = super.packetSize();
      Debug.dAssert(this._fromUser != null);
      var1 += 1 + ServerOutputStream.utfLength(this._fromUser);
      return var1 + this._propList.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeUTF(this._fromUser);
      this._propList.send(var1);
   }

   void process(WorldServer var1) throws Exception {
   }

   public String toString(WorldServer var1) {
      return "PROPSET  \"" + this._fromUser + "\"->" + this._objID.toString(var1) + " " + this._propList;
   }
}

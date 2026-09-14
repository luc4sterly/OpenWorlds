package NET.worlds.network;

import java.io.IOException;

public class regObjIDCmd extends receivedNetPacket {
   public static final byte REGOBJIDCMD = 13;
   private String _longObjID;
   private int _shortObjID;

   public regObjIDCmd() {
      this._commandType = 13;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._longObjID = var1.readUTF();
      this._shortObjID = var1.readByte();
   }

   void process(WorldServer var1) throws Exception {
      var1.regShortID(this._shortObjID, this._longObjID);
   }

   public String toString(WorldServer var1) {
      return "REGOBJID " + this._shortObjID + " --> " + this._longObjID;
   }
}

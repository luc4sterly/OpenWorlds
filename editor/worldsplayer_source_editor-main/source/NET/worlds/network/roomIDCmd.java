package NET.worlds.network;

import java.io.IOException;

public class roomIDCmd extends receivedNetPacket {
   public static final byte ROOMIDCMD = 21;
   protected String _roomName;
   protected int _roomNumber;

   public roomIDCmd() {
      this._commandType = 21;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomName = var1.readUTF();
      this._roomNumber = var1.readUnsignedShort();
   }

   void process(WorldServer var1) throws Exception {
      var1.regRoomID(this._roomNumber, this._roomName, false);
   }

   public String toString(WorldServer var1) {
      return "ROOMID   " + this._roomName + " <--> " + this._roomNumber;
   }
}

package NET.worlds.network;

import java.io.IOException;

public class roomIDReqCmd extends netPacket {
   public static final byte ROOMIDREQCMD = 20;
   protected String _roomName;

   public roomIDReqCmd(String var1) {
      super(null, 20);
      this._roomName = var1;
   }

   int packetSize() {
      return ServerOutputStream.utfLength(this._roomName) + 1 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeUTF(this._roomName);
   }

   public String toString(WorldServer var1) {
      return "ROOMIDRQ " + this._roomName;
   }
}

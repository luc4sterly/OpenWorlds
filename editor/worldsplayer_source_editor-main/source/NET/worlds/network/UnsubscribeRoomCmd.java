package NET.worlds.network;

import java.io.IOException;

public class UnsubscribeRoomCmd extends netPacket {
   public static final byte UNSUBSCRIBEROOMCMD = 23;
   protected int _roomNumber;

   public UnsubscribeRoomCmd(int var1) {
      super(null, 23);
      this._roomNumber = (short)var1;
   }

   int packetSize() {
      return 2 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._roomNumber);
   }

   public String toString(WorldServer var1) {
      return "UNSUBSCR " + this._roomNumber;
   }
}

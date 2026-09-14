package NET.worlds.network;

import NET.worlds.scape.RoomSubscribeInfo;
import java.io.IOException;

public class SubscribeRoomCmd extends netPacket {
   public static final byte SUBSCRIBEROOMCMD = 22;
   protected short _distance;
   protected short _x;
   protected short _y;
   protected short _z;
   protected short _roomNumber;

   public SubscribeRoomCmd(RoomSubscribeInfo var1, int var2) {
      super(null, 22);
      this._roomNumber = (short)var2;
      this._distance = (short)(var1.d - 100.0F);
      this._x = (short)var1.x;
      this._y = (short)var1.y;
      this._z = (short)var1.z;
   }

   int packetSize() {
      return 10 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._roomNumber);
      var1.writeShort(this._x);
      var1.writeShort(this._y);
      var1.writeShort(this._z);
      var1.writeShort(this._distance);
   }

   public String toString(WorldServer var1) {
      return "SUBSCRIB " + this._roomNumber + ": " + this._distance + "cm @ " + this._x + "," + this._y + "," + this._z;
   }
}

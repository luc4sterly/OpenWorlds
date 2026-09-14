package NET.worlds.network;

import java.io.IOException;

public class SubscribeDistCmd extends netPacket {
   public static final byte SUBSCRIBEDISTCMD = 24;
   protected short _distance;
   protected short _roomNumber;

   public SubscribeDistCmd(float var1, int var2) {
      super(null, 24);
      this._distance = (short)(var1 - 100.0F);
      this._roomNumber = (short)var2;
   }

   int packetSize() {
      return 4 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._roomNumber);
      var1.writeShort(this._distance);
   }

   public String toString(WorldServer var1) {
      return "SUB-DIST " + this._roomNumber + ":  " + this._distance + "cm";
   }
}

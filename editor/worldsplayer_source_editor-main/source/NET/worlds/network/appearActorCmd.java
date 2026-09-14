package NET.worlds.network;

import NET.worlds.scape.Drone;
import java.io.IOException;

public class appearActorCmd extends receivedNetPacket {
   public static final byte APPEARACTORCMD = 12;
   protected int _roomID;
   protected short _x;
   protected short _y;
   protected short _z;
   protected short _direction;

   public appearActorCmd() {
      this._commandType = 12;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomID = var1.readUnsignedShort();
      this._x = var1.readShort();
      this._y = var1.readShort();
      this._z = var1.readShort();
      this._direction = var1.readShort();
   }

   void process(WorldServer var1) throws Exception {
      Drone var2 = Drone.make(this._objID, var1);
      this._direction = (short)(90 - this._direction);
      this._direction = (short)(360 - this._direction);
      NetworkRoom var3 = var1.getNetworkRoom(this._roomID);
      if (var3 != null) {
         var2.appear(var3.getRoom(), this._x, this._y, this._z, this._direction);
      }
   }

   public String toString(WorldServer var1) {
      return "APPRACTR " + this._objID.toString(var1) + " in " + this._roomID + " @ " + this._x + "," + this._y + "," + this._z + "," + this._direction;
   }
}

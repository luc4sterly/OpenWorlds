package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.scape.Drone;
import NET.worlds.scape.Room;
import java.io.IOException;

public class roomChangeCmd extends receivedNetPacket {
   public static final byte ROOMCHNGCMD = 5;
   protected int _roomID;
   protected short _x;
   protected short _y;
   protected short _z;
   protected short _direction;

   public roomChangeCmd() {
      this._commandType = 5;
   }

   public roomChangeCmd(Room var1, short var2, short var3, short var4, short var5) {
      super(null, 5);
      this._roomID = var1.getNetworkRoom().getRoomID();
      Debug.dAssert(this._roomID != 0);
      this._x = var2;
      this._y = var3;
      this._z = var4;
      this._direction = var5;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomID = var1.readUnsignedShort();
      this._x = var1.readShort();
      this._y = var1.readShort();
      this._z = var1.readShort();
      this._direction = var1.readShort();
   }

   int packetSize() {
      return 10 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._roomID);
      var1.writeShort(this._x);
      var1.writeShort(this._y);
      var1.writeShort(this._z);
      var1.writeShort(this._direction);
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 instanceof Drone) {
         Debug.dAssert(this._roomID != 0);
         Room var3 = null;
         NetworkRoom var4 = var1.getNetworkRoom(this._roomID);
         if (var4 != null) {
            var3 = var4.getRoom();
         }

         this._direction = (short)(90 - this._direction);
         this._direction = (short)(360 - this._direction);
         ((Drone)var2).roomChange(var3, this._x, this._y, this._z, this._direction);
      }
   }

   public String toString(WorldServer var1) {
      return "ROOMCHNG " + this._objID.toString(var1) + " in " + this._roomID + " @ " + this._x + "," + this._y + "," + this._z + "," + this._direction;
   }
}

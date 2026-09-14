package NET.worlds.network;

import NET.worlds.scape.Drone;
import NET.worlds.scape.Room;
import java.io.IOException;

public class teleportCmd extends receivedNetPacket {
   public static final byte TELEPORTCMD = 18;
   protected int _roomID;
   protected byte _exittype;
   protected byte _entrytype;
   protected short _x;
   protected short _y;
   protected short _z;
   protected short _direction;

   public teleportCmd() {
      this._commandType = 18;
   }

   public teleportCmd(Room var1, byte var2, byte var3, short var4, short var5, short var6, short var7) {
      super(null, 18);
      this._roomID = 0;
      if (var1 != null) {
         this._roomID = var1.getNetworkRoom().getRoomID();
      }

      this._exittype = var2;
      this._entrytype = var3;
      this._x = var4;
      this._y = var5;
      this._z = var6;
      this._direction = var7;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomID = var1.readUnsignedShort();
      this._exittype = var1.readByte();
      this._entrytype = var1.readByte();
      this._x = var1.readShort();
      this._y = var1.readShort();
      this._z = var1.readShort();
      this._direction = var1.readShort();
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 == null) {
         var2 = Drone.make(this._objID, var1);
      }

      NetworkRoom var3 = var1.getNetworkRoom(this._roomID);
      Room var4 = null;
      if (var3 != null) {
         var4 = var3.getRoom();
      }

      this._direction = (short)(90 - this._direction);
      this._direction = (short)(360 - this._direction);
      if (var2 instanceof Drone) {
         ((Drone)var2).teleport(var1, this._exittype, this._entrytype, var4, this._x, this._y, this._z, this._direction);
      }
   }

   int packetSize() {
      return 12 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._roomID);
      var1.writeByte(this._exittype);
      var1.writeByte(this._entrytype);
      var1.writeShort(this._x);
      var1.writeShort(this._y);
      var1.writeShort(this._z);
      var1.writeShort(this._direction);
   }

   public String toString(WorldServer var1) {
      return "TELEPORT "
         + this._objID.toString(var1)
         + " <"
         + this._exittype
         + "  >"
         + this._entrytype
         + " in "
         + this._roomID
         + " @ "
         + this._x
         + ","
         + this._y
         + ","
         + this._z
         + ","
         + this._direction;
   }
}

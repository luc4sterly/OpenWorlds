package NET.worlds.network;

import NET.worlds.scape.Drone;
import java.io.IOException;

public class longLocCmd extends receivedNetPacket {
   public static final byte LONGLOCCMD = 1;
   protected short _x;
   protected short _y;
   protected short _z;
   protected short _dir;

   public longLocCmd() {
      this._commandType = 1;
   }

   public longLocCmd(short var1, short var2, short var3, short var4) {
      super(null, 1);
      this._x = var1;
      this._y = var2;
      this._z = var3;
      this._dir = var4;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._x = var1.readShort();
      this._y = var1.readShort();
      this._z = var1.readShort();
      this._dir = var1.readShort();
   }

   int packetSize() {
      return 8 + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeShort(this._x);
      var1.writeShort(this._y);
      var1.writeShort(this._z);
      var1.writeShort(this._dir);
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 instanceof Drone) {
         this._dir = (short)(90 - this._dir);
         this._dir = (short)(360 - this._dir);
         if (var2 == null) {
            System.out.println("error in message: " + this.toString(var1));
         }

         ((Drone)var2).longLoc(this._x, this._y, this._z, this._dir);
      }
   }

   public String toString(WorldServer var1) {
      return "LONGLOC  " + this._objID.toString(var1) + " @ " + this._x + "," + this._y + "," + this._z + "," + this._dir;
   }
}

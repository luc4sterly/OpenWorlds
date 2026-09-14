package NET.worlds.network;

import java.io.IOException;

public class RedirectCmd extends receivedNetPacket {
   public static final byte REDIRECTCMD = 25;
   protected int _roomNumber;
   protected int _ip1;
   protected int _ip2;
   protected int _ip3;
   protected int _ip4;
   protected int _port;

   public RedirectCmd() {
      this._commandType = 25;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomNumber = var1.readUnsignedShort();
      this._ip1 = var1.readUnsignedByte();
      this._ip2 = var1.readUnsignedByte();
      this._ip3 = var1.readUnsignedByte();
      this._ip4 = var1.readUnsignedByte();
      this._port = var1.readUnsignedShort();
   }

   void process(WorldServer var1) throws Exception {
   }

   String toStringHlpr() {
      return this._roomNumber + " -> " + this._ip1 + "." + this._ip2 + "." + this._ip3 + "." + this._ip4 + ":" + this._port;
   }

   public String toString(WorldServer var1) {
      return "REDIRECT " + this.toStringHlpr();
   }
}

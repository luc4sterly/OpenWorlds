package NET.worlds.network;

import NET.worlds.console.StatNetMUNode;
import NET.worlds.core.Debug;
import java.io.IOException;

public abstract class netPacket {
   protected ObjID _objID;
   protected int _commandType;

   public netPacket(ObjID var1, int var2) {
      if (var1 != null) {
         this._objID = var1;
      } else {
         this._objID = new ObjID(1);
      }

      this._commandType = var2;
   }

   public netPacket() {
      this._objID = new ObjID(1);
   }

   public int msgID() {
      return this._commandType;
   }

   int packetSize() {
      return 2 + this._objID.packetSize();
   }

   public String toString(WorldServer var1) {
      return new Integer(this._commandType).toString();
   }

   void send(ServerOutputStream var1) throws IOException {
      int var2 = this.packetSize();
      if (var2 >= 256) {
         throw new PacketTooLargeException();
      }

      StatNetMUNode var3 = StatNetMUNode.getNode();
      var3.addBytesSent(var2);
      var3.addPacketsSent(1);
      Debug.dAssert(this._commandType > 0);
      var1.writeByte(var2);
      this._objID.send(var1);
      var1.writeByte(this._commandType);
   }
}

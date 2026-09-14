package NET.worlds.network;

import java.io.IOException;

public abstract class receivedNetPacket extends netPacket {
   public receivedNetPacket(ObjID var1, int var2) {
      super(var1, var2);
   }

   public receivedNetPacket() {
   }

   public final void init(ObjID var1) {
      this._objID = var1;
   }

   abstract void parseNetData(ServerInputStream var1) throws IOException;

   abstract void process(WorldServer var1) throws Exception;
}

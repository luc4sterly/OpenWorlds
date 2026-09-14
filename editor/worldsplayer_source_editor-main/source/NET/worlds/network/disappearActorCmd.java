package NET.worlds.network;

import NET.worlds.scape.Drone;
import java.io.IOException;

public class disappearActorCmd extends receivedNetPacket {
   public static final byte DISAPPEARACTORCMD = 11;

   public disappearActorCmd() {
      this._commandType = 11;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 instanceof Drone) {
         ((Drone)var2).disappear();
      }
   }

   public String toString(WorldServer var1) {
      return "DISAPPR  " + this._objID.toString(var1);
   }
}

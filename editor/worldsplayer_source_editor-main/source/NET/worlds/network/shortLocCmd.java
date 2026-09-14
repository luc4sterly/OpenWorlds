package NET.worlds.network;

import NET.worlds.scape.Drone;
import java.io.IOException;

public class shortLocCmd extends receivedNetPacket {
   public static final byte SHORTLOCCMD = 4;
   protected byte _dx;
   protected byte _dy;
   protected byte _ddirection;

   public shortLocCmd() {
      this._commandType = 4;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._dx = var1.readByte();
      this._dy = var1.readByte();
      this._ddirection = var1.readByte();
   }

   void process(WorldServer var1) throws Exception {
      NetworkObject var2 = var1.getObject(this._objID);
      if (var2 == null) {
         System.out.println("Unknown short id: " + this.toString(var1));
         new Exception().printStackTrace(System.out);
      } else {
         if (var2 instanceof Drone) {
            ((Drone)var2).shortLoc(this._dx, this._dy, this._ddirection);
         }
      }
   }

   public String toString(WorldServer var1) {
      return "SHORTLOC " + this._objID.toString(var1) + " delta=" + this._dx + "," + this._dy + "," + this._ddirection;
   }

   public String toString() {
      return "SHORTLOC " + this._objID + " delta=" + this._dx + "," + this._dy + "," + this._ddirection;
   }
}

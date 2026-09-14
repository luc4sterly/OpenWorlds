package NET.worlds.console;

import NET.worlds.scape.Drone;
import NET.worlds.scape.HoloPilot;
import NET.worlds.scape.Pilot;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBDroneDeltaPosCommand extends BlackBoxCommand {
   private byte dx;
   private byte dy;
   private byte dyaw;
   private String droneID;

   public BBDroneDeltaPosCommand() {
      this.commandType = 8;
   }

   public BBDroneDeltaPosCommand(String var1, byte var2, byte var3, byte var4) {
      this();
      this.droneID = var1;
      this.dx = var2;
      this.dy = var3;
      this.dyaw = var4;
   }

   public boolean execute() {
      Drone var1 = null;
      if (this.droneID.equals("@Pilot")) {
         Pilot var2 = Pilot.getActive();
         if (var2 != null && var2 instanceof HoloPilot) {
            HoloPilot var3 = (HoloPilot)var2;
            Drone var4 = var3.getInternalDrone();
            if (var4 != null && var4 instanceof Drone) {
               var1 = var4;
            }
         }
      } else {
         var1 = ArmyOfZombies.instance().get(this.droneID);
      }

      if (var1 != null) {
         var1.shortLoc(this.dx, this.dy, this.dyaw);
         this.doCallback(true);
         return true;
      } else {
         this.doCallback(true);
         return true;
      }
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeUTF(this.droneID);
      var1.writeByte(this.dx);
      var1.writeByte(this.dy);
      var1.writeByte(this.dyaw);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.droneID = var1.readUTF();
      this.dx = var1.readByte();
      this.dy = var1.readByte();
      this.dyaw = var1.readByte();
   }
}

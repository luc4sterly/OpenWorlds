package NET.worlds.console;

import NET.worlds.scape.Drone;
import NET.worlds.scape.HoloPilot;
import NET.worlds.scape.Pilot;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBMoveDroneCommand extends BlackBoxCommand {
   private short x;
   private short y;
   private short z;
   private short dir;
   private String droneID;

   public BBMoveDroneCommand() {
      this.commandType = 3;
   }

   public BBMoveDroneCommand(String var1, short var2, short var3, short var4, short var5) {
      this();
      this.droneID = var1;
      this.x = var2;
      this.y = var3;
      this.z = var4;
      this.dir = var5;
   }

   public boolean execute() {
      Drone var1 = null;
      if (this.droneID.equals("@Pilot")) {
         Pilot var2 = Pilot.getActive();
         if (var2 != null && var2 instanceof HoloPilot) {
            HoloPilot var3 = (HoloPilot)var2;
            var1 = var3.getInternalDrone();
         }
      } else {
         var1 = ArmyOfZombies.instance().get(this.droneID);
      }

      if (var1 != null) {
         short var4 = this.dir;
         var4 = (short)(90 - var4);
         var4 = (short)(360 - var4);
         var1.longLoc(this.x, this.y, this.z, var4);
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
      var1.writeShort(this.x);
      var1.writeShort(this.y);
      var1.writeShort(this.z);
      var1.writeShort(this.dir);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.droneID = var1.readUTF();
      this.x = var1.readShort();
      this.y = var1.readShort();
      this.z = var1.readShort();
      this.dir = var1.readShort();
   }
}

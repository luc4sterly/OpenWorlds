package NET.worlds.console;

import NET.worlds.scape.Drone;
import NET.worlds.scape.HoloPilot;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.TeleportStatus;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBTeleportCommand extends BlackBoxCommand implements TeleportStatus {
   private String location;

   public BBTeleportCommand() {
      this.commandType = 1;
   }

   public BBTeleportCommand(String var1) {
      this();
      if (var1 != null) {
         this.location = new String(var1);
      }
   }

   public boolean execute() {
      if (this.location != null) {
         TeleportAction.teleport(this.location, this);
      }

      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      if (this.location == null) {
         var1.writeUTF("");
      } else {
         var1.writeUTF(this.location);
      }
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.location = var1.readUTF();
      if (this.location.equals("")) {
         this.location = null;
      }
   }

   public void teleportStatus(String var1, String var2) {
      Pilot var3 = Pilot.getActive();
      if (var3 instanceof HoloPilot) {
         HoloPilot var4 = (HoloPilot)var3;
         Drone var5 = var4.getInternalDrone();
         if (var5 != null) {
            short var6 = (short)(-var3.getYaw() + 90.0F);
            var6 = (short)(var6 % 360);

            while (var6 < 0) {
               var6 = (short)(var6 + 360);
            }

            var6 = (short)(90 - var6);
            var6 = (short)(360 - var6);
            var5.reset((short)var3.getX(), (short)var3.getY(), (short)var3.getFootHeight(), var6);
         }
      }

      if (var1 == null) {
         this.doCallback(true);
      } else {
         this.doCallback(false);
      }
   }
}

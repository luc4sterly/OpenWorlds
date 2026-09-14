package NET.worlds.console;

import NET.worlds.scape.Drone;
import NET.worlds.scape.Pilot;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBAnimateDroneCommand extends BlackBoxCommand {
   private String animation;
   private String droneName;

   public BBAnimateDroneCommand() {
      this.commandType = 9;
   }

   public BBAnimateDroneCommand(String var1, String var2) {
      this();
      this.animation = new String(var2);
      this.droneName = new String(var1);
   }

   public boolean execute() {
      if (this.droneName.equals("@Pilot")) {
         Pilot var1 = Pilot.getActive();
         if (var1 != null) {
            var1.animate(this.animation);
         }
      } else {
         Drone var2 = ArmyOfZombies.instance().get(this.droneName);
         if (var2 != null) {
            var2.animate(this.animation);
         }
      }

      this.doCallback(true);
      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeUTF(this.animation);
      var1.writeUTF(this.droneName);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.animation = new String(var1.readUTF());
      this.droneName = new String(var1.readUTF());
   }
}

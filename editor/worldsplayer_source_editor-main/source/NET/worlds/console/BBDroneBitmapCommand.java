package NET.worlds.console;

import NET.worlds.network.URL;
import NET.worlds.scape.Drone;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBDroneBitmapCommand extends BlackBoxCommand {
   private String name;
   private String bitmap;

   public BBDroneBitmapCommand(String var1, String var2) {
      this();
      this.name = new String(var1);
      this.bitmap = new String(var2);
   }

   public BBDroneBitmapCommand() {
      this.commandType = 7;
   }

   public boolean execute() {
      Drone var1 = ArmyOfZombies.instance().get(this.name);
      if (var1 != null) {
         Drone var2 = var1.handleVAR_BITMAP(this.bitmap);
         ArmyOfZombies.instance().replaceZombie(this.name, var2);
      } else if (this.name.equals("@Pilot")) {
         Console var3 = Console.getActive();
         if (var3 != null) {
            var3.setAvatar(URL.make(this.bitmap));
         }
      } else {
         System.out.println("Couldn't find drone " + this.name + " for bitmap command.");
      }

      this.doCallback(true);
      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeUTF(this.name);
      var1.writeUTF(this.bitmap);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.name = new String(var1.readUTF());
      this.bitmap = new String(var1.readUTF());
   }
}

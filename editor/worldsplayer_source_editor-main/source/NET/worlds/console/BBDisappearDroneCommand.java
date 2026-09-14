package NET.worlds.console;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBDisappearDroneCommand extends BlackBoxCommand {
   private String name;

   public BBDisappearDroneCommand(String var1) {
      this();
      this.name = new String(var1);
   }

   public BBDisappearDroneCommand() {
      this.commandType = 6;
   }

   public boolean execute() {
      ArmyOfZombies.instance().killZombie(this.name);
      this.doCallback(true);
      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeUTF(this.name);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.name = new String(var1.readUTF());
   }
}

package NET.worlds.console;

import NET.worlds.scape.HoloDrone;
import NET.worlds.scape.Room;
import NET.worlds.scape.World;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBAppearDroneCommand extends BlackBoxCommand {
   private short x;
   private short y;
   private short z;
   private short dir;
   private String room;
   private String name;

   public BBAppearDroneCommand(String var1, String var2, short var3, short var4, short var5, short var6) {
      this();
      this.x = var3;
      this.y = var4;
      this.z = var5;
      this.dir = var6;
      this.room = new String(var1);
      this.name = new String(var2);
   }

   public BBAppearDroneCommand() {
      this.commandType = 5;
   }

   public boolean execute() {
      HoloDrone var1 = new HoloDrone(null, null);
      var1.setName(this.name);
      Room var2 = World.findRoomByName(this.room);
      if (var2 != null) {
         var1.appear(var2, this.x, this.y, this.z, this.dir);
         var1.makeTag(true);
         ArmyOfZombies.instance().addZombie(var1);
         this.doCallback(true);
      } else {
         this.doCallback(false);
      }

      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeShort(this.x);
      var1.writeShort(this.y);
      var1.writeShort(this.z);
      var1.writeShort(this.dir);
      var1.writeUTF(this.room);
      var1.writeUTF(this.name);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.x = var1.readShort();
      this.y = var1.readShort();
      this.z = var1.readShort();
      this.dir = var1.readShort();
      this.room = new String(var1.readUTF());
      this.name = new String(var1.readUTF());
   }
}

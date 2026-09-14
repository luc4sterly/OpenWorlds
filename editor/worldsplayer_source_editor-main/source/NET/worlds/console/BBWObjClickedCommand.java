package NET.worlds.console;

import NET.worlds.scape.DeepEnumeration;
import NET.worlds.scape.MouseDownEvent;
import NET.worlds.scape.MouseDownHandler;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Room;
import NET.worlds.scape.SuperRoot;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBWObjClickedCommand extends BlackBoxCommand {
   private String objUrl;
   int x;
   int y;
   char key;

   public BBWObjClickedCommand() {
      this.commandType = 4;
   }

   public BBWObjClickedCommand(String var1, char var2, int var3, int var4) {
      this();
      this.objUrl = new String(var1);
      this.key = var2;
      this.x = var3;
      this.y = var4;
   }

   public boolean execute() {
      MouseDownHandler var1 = null;
      if (Pilot.getActive() == null) {
         return false;
      }

      Room var2 = Pilot.getActive().getRoom();
      if (var2 == null) {
         return false;
      }

      DeepEnumeration var3 = new DeepEnumeration();
      var2.getChildren(var3);

      while (var3.hasMoreElements()) {
         Object var4 = var3.nextElement();
         if (var4 instanceof MouseDownHandler && ((SuperRoot)var4).getName().equals(this.objUrl)) {
            var1 = (MouseDownHandler)var4;
            break;
         }
      }

      if (var1 == null) {
         this.doCallback(false);
         return false;
      } else {
         MouseDownEvent var5 = new MouseDownEvent(0, null, this.key, this.x, this.y);
         var1.handle(var5);
         this.doCallback(true);
         return true;
      }
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeInt(this.x);
      var1.writeInt(this.y);
      var1.writeChar(this.key);
      var1.writeUTF(this.objUrl);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.x = var1.readInt();
      this.y = var1.readInt();
      this.key = var1.readChar();
      this.objUrl = var1.readUTF();
   }
}

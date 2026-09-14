package NET.worlds.console;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BBChatCommand extends BlackBoxCommand {
   private String chatLine;

   public BBChatCommand(String var1) {
      this();
      this.chatLine = new String(var1);
   }

   public BBChatCommand() {
      this.commandType = 0;
   }

   public boolean execute() {
      Console.println(this.chatLine);
      this.doCallback(true);
      return true;
   }

   public void save(DataOutputStream var1) throws IOException {
      super.save(var1);
      var1.writeUTF(this.chatLine);
   }

   public void load(DataInputStream var1) throws IOException {
      super.load(var1);
      this.chatLine = new String(var1.readUTF());
   }
}

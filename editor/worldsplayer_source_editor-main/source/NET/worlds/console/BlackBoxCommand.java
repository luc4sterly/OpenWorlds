package NET.worlds.console;

import NET.worlds.core.Std;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public abstract class BlackBoxCommand {
   int commandType;
   long startTime;
   BlackBoxCallback callback;
   boolean waiting = false;

   void timestamp(long var1) {
      this.startTime = Std.getFastTime() - var1;
   }

   public boolean execute(BlackBoxCallback var1) {
      if (this.waiting) {
         return false;
      }

      this.callback = var1;
      if (var1 != null) {
         this.waiting = true;
      }

      return this.execute();
   }

   abstract boolean execute();

   void save(DataOutputStream var1) throws IOException {
      var1.writeInt(this.commandType);
      var1.writeLong(this.startTime);
   }

   void load(DataInputStream var1) throws IOException {
      this.startTime = var1.readLong();
   }

   void doCallback(boolean var1) {
      if (this.callback != null) {
         this.waiting = false;
         this.callback.commandCompleted(this, var1);
      }
   }
}

package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

class ExceptionCmd extends receivedNetPacket {
   private Exception _exception;

   public ExceptionCmd(Exception var1) {
      this._exception = var1;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      Debug.dAssert(false);
   }

   void process(WorldServer var1) throws Exception {
      throw this._exception;
   }

   public String toString(WorldServer var1) {
      return "EXCEPT  " + this._exception.getMessage();
   }
}

package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

public class FingerReqCmd extends netPacket {
   public static final byte FINGERREQCMD = 27;
   private String _user;

   public FingerReqCmd(String var1) {
      super(null, 27);
      this._user = var1;
   }

   int packetSize() {
      int var1 = super.packetSize();
      Debug.dAssert(this._user != null);
      return var1 + 1 + ServerOutputStream.utfLength(this._user);
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeUTF(this._user);
   }

   public String toString(WorldServer var1) {
      return "FINGREQ  " + this._user;
   }
}

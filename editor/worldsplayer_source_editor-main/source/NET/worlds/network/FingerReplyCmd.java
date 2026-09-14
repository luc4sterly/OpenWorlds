package NET.worlds.network;

import java.io.IOException;

public class FingerReplyCmd extends receivedNetPacket {
   public static final byte FINGERREPLYCMD = 28;
   private String _user;
   private PropertyList _propList;

   public FingerReplyCmd() {
      this._commandType = 28;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._user = var1.readUTF();
      this._propList = new PropertyList();
      this._propList.parseNetData(var1);
   }

   void process(WorldServer var1) throws Exception {
   }

   public String toString(WorldServer var1) {
      return "FINGREP  " + this._user + " " + this._propList;
   }
}

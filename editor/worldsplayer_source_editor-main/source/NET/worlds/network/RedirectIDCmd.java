package NET.worlds.network;

import java.io.IOException;

public class RedirectIDCmd extends RedirectCmd {
   public static final byte REDIRECTIDCMD = 26;
   protected String _roomName;

   public RedirectIDCmd() {
      this._commandType = 26;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._roomName = var1.readUTF();
      super.parseNetData(var1);
   }

   void process(WorldServer var1) throws Exception {
      var1.regRoomID(this._roomNumber, this._roomName, true);
      String var2 = "worldserver://" + this._ip1 + "." + this._ip2 + "." + this._ip3 + "." + this._ip4 + ":" + this._port + "/RoomServer";
      ServerURL var3 = new ServerURL(var2);
      var1.redirectRoom(this._roomName, var3);
   }

   public String toString(WorldServer var1) {
      return "REDIRID  " + this._roomName + "==" + super.toStringHlpr();
   }
}

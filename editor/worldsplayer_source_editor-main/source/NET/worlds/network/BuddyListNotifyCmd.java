package NET.worlds.network;

import NET.worlds.console.FriendsListPart;
import java.io.IOException;

public class BuddyListNotifyCmd extends receivedNetPacket {
   public static final byte BUDDYLISTNOTIFYCMD = 30;
   protected String buddyName;
   protected int loggedOn;

   public BuddyListNotifyCmd() {
      this._commandType = 30;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this.buddyName = var1.readUTF();
      this.loggedOn = var1.readByte();
   }

   void process(WorldServer var1) throws Exception {
      FriendsListPart.processBuddyListNotify(var1, this.buddyName, this.loggedOn);
   }

   public String toString(WorldServer var1) {
      return "BUDDYLISTNOTIFY " + this.buddyName + " " + this.loggedOn;
   }
}

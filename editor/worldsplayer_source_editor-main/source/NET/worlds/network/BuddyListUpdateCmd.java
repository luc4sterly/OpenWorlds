package NET.worlds.network;

import java.io.IOException;

public class BuddyListUpdateCmd extends netPacket {
   public static final byte BUDDYLISTUPDATECMD = 29;
   private String buddy;
   private int add;

   public BuddyListUpdateCmd(String var1, int var2) {
      super(null, 29);
      this.buddy = var1;
      this.add = var2;
   }

   int packetSize() {
      return super.packetSize() + ServerOutputStream.utfLength(this.buddy) + 2;
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeUTF(this.buddy);
      var1.writeByte(this.add);
   }

   public String toString(WorldServer var1) {
      return "BUDDYLISTUPDATE  " + this.buddy + " " + this.add;
   }
}

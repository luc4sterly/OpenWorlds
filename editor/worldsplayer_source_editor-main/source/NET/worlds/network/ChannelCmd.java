package NET.worlds.network;

import java.io.IOException;

public class ChannelCmd extends netPacket {
   public static final byte CHANNELCMD = 31;
   protected String _channel;

   public ChannelCmd(String var1) {
      super(null, 31);
      this._channel = var1;
   }

   int packetSize() {
      return 1 + ServerOutputStream.utfLength(this._channel) + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      var1.writeUTF(this._channel);
   }

   public String toString(WorldServer var1) {
      return "CHANNEL  " + this._channel;
   }
}

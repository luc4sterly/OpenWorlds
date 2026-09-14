package NET.worlds.network;

import java.io.IOException;

public class PacketTooLargeException extends IOException {
   PacketTooLargeException() {
   }

   PacketTooLargeException(String var1) {
      super(var1);
   }
}

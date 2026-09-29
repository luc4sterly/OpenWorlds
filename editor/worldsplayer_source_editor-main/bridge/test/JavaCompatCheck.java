package NET.worlds.core;

import java.io.IOException;
import java.io.InputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * WorldServer.cleanup lets go of a server: stop() on its packet reader, which
 * is blocked reading the socket, then closes that socket. Thread.stop() only
 * throws since Java 20 (JDK-8289610); JavaCompat.stopThread plus the close
 * must still end the reader, as netPacketReader.run does on an IOException.
 */
public final class JavaCompatCheck {
   public static void main(String[] args) throws Exception {
      boolean ok = true;
      int feature = Runtime.version().feature();
      Thread probe = new Thread(() -> { });
      boolean threw = false;
      try {
         probe.stop();
      } catch (UnsupportedOperationException e) {
         threw = true;
      }
      if (feature >= 20) {
         System.out.println("  " + (threw ? "ok   " : "FALLA") + " Java " + feature + ": Thread.stop() lanza UnsupportedOperationException");
         ok &= threw;
      }
      try (ServerSocket server = new ServerSocket(0, 1, InetAddress.getLoopbackAddress())) {
         Socket client = new Socket(InetAddress.getLoopbackAddress(), server.getLocalPort());
         Socket peer = server.accept();
         final boolean[] ioe = {false};
         Thread reader = new Thread(() -> {
            try (InputStream in = client.getInputStream()) {
               while (in.read() >= 0) {
                  // como buildMsg: lee hasta que falle
               }
            } catch (IOException e) {
               ioe[0] = true;
            }
         }, "lector");
         reader.start();
         Thread.sleep(200);
         JavaCompat.stopThread(reader);
         client.close();
         reader.join(2000);
         peer.close();
         boolean ended = !reader.isAlive() && ioe[0];
         System.out.println("  " + (ended ? "ok   " : "FALLA") + " el lector bloqueado termina con stopThread y el cierre del socket");
         ok &= ended;
      }
      System.exit(ok ? 0 : 1);
   }
}

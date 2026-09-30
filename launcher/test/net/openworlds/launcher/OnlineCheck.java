package net.openworlds.launcher;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Comparator;
import java.util.stream.Stream;

/**
 * What the launcher needs to go online and to install worlds, without a
 * network: the server address as the player types it (J Solar Server's port
 * for plain and encrypted connections when none is typed), the certificates
 * it remembers (Trust), and the full installer that a world's upgrades.lst
 * offers to a client without the world.
 */
public final class OnlineCheck {
   private static int failures;

   public static void main(String[] args) throws IOException {
      addresses();
      upgradesList();
      trust();
      if (failures > 0) {
         System.out.println("OnlineCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("OnlineCheck: all good");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FAIL  ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static void addresses() {
      System.out.println("Server addresses:");
      check("192.168.1.20:6650".equals(Launcher.serverAddress("192.168.1.20", false)), "a host alone takes the plain port 6650");
      check("192.168.1.20:6651".equals(Launcher.serverAddress(" 192.168.1.20 ", true)), "encrypted, the TLS port 6651");
      check("worlds.example.org:7000".equals(Launcher.serverAddress("worlds.example.org:7000", true)), "a typed port stays");
      check("host:6650".equals(Launcher.serverAddress("worldserver://host:6650/", false)), "a worldserver:// URL is read too");
      boolean refused = true;
      for (String bad : new String[]{"", "   ", "a b", "host:0", "host:70000", "host:port", ":6650", "http://host/x"}) {
         refused &= Launcher.serverAddress(bad, false) == null;
      }
      check(refused, "not addresses: empty, spaces, port 0 or too big or not a number, no host, a path");
   }

   private static void upgradesList() {
      System.out.println("upgrades.lst:");
      String meteor = "-1 25#511534:1692\r\n1 2#237506:1193\r\n2 3#186577:1205\r\n24 25#1000:1692\r\n";
      check(WorldInstall.latestFull(meteor) == 25, "Meteor's (as the mirror serves it): the full installer is version 25");
      check(WorldInstall.latestFull("-1 30#1:99999\n-1 26#1:1700\n") == 26, "an installer for a newer client is skipped");
      check(WorldInstall.latestFull("-1 5#10 7#20\n") == 7, "several versions on one line: the newest");
      check(WorldInstall.latestFull("3 4#1:1\n# nothing\n\n") == -1, "only upgrades from a version: no installer");
   }

   private static void trust() throws IOException {
      System.out.println("Trusted certificates:");
      File tmp = Files.createTempDirectory("online-check").toFile();
      try {
         Layout l = new Layout(tmp, tmp, new File(tmp, "data"));
         check(Trust.known(l, "127.0.0.1:6651") == null, "nothing is trusted at first");
         String fp = "0F:40:AA:4C:96:22:99:4F:22:C4:CA:46:91:39:22:AE:28:51:57:0D:BD:B4:63:8B:CB:5F:39:2C:F2:1B:FD:6B";
         Trust.remember(l, "Worlds.Example.org:6651 ", fp);
         check(fp.equals(Trust.known(l, "worlds.example.org:6651")), "a remembered fingerprint is found again (any case)");
         Trust.Check same = new Trust.Check("worlds.example.org:6651", fp, Trust.known(l, "worlds.example.org:6651"));
         Trust.Check other = new Trust.Check("worlds.example.org:6651", fp.replace("0F:40", "0F:41"), fp);
         Trust.Check first = new Trust.Check("other:6651", fp, null);
         check(same.trusted() && !same.changed(), "the same certificate is trusted");
         check(!other.trusted() && other.changed(), "another certificate for a known server is a change");
         check(!first.trusted() && !first.changed(), "an unknown server is neither");
         String pretty = Trust.pretty(fp);
         check(pretty.split("\n").length == 2 && pretty.replace("\n", ":").equals(fp), "the fingerprint in two lines of 16 bytes");
      } finally {
         try (Stream<java.nio.file.Path> walk = Files.walk(tmp.toPath())) {
            walk.sorted(Comparator.reverseOrder()).map(java.nio.file.Path::toFile).forEach(File::delete);
         }
      }
   }
}

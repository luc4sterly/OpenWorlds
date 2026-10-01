import NET.worlds.core.IniFile;
import NET.worlds.network.DNSLookup;

/**
 * Clean-room network probe: exercises the REAL network path of the
 * decompiled client (DNSLookup, URL.make/unalias, HttpURLConnection via the
 * resolved URL, TCP Socket) without starting the UI or Gamma's main loop.
 *
 * It does not reimplement the protocol: each step calls the classes of
 * editor/worldsplayer_source_editor-main/source as they are, with explicit
 * timeouts so it does not hang. Every failure is reported, not hidden.
 *
 * The CWD must be a real install directory (assets/WorldsPlayer), same as
 * run_mock.sh, so that IniFile reads the real worlds.ini.
 */
public final class NetProbe {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      System.out.println("== [1] DNS via NET.worlds.network.DNSLookup ==");
      dns("us1.worlds.net");
      dns("worlds.worlio.com");

      System.out.println("== [2] Upgrade URL built the way NetUpdate does ==");
      String uServer = IniFile.gamma().getIniString("upgradeServer", "");
      System.out.println("upgradeServer ini = " + uServer);
      String built = uServer + "upgrades.lst";
      String alias = NET.worlds.network.URL.make(built).unalias();
      System.out.println("URL.make(uServer+\"upgrades.lst\").unalias() = " + alias);

      System.out.println("== [3] HTTP GET via DNSLookup.lookup + openConnection (CacheEntry.openURL pattern) ==");
      httpGet(alias);

      System.out.println("== [4] TCP 6650 (WorldServer port) via the IP resolved by DNSLookup ==");
      tcp("us1.worlds.net", 6650);
      tcp("worlds.worlio.com", 6650);

      System.out.println(failures == 0 ? "NETPROBE: ALL OK" : "NETPROBE: " + failures + " FAILURES");
      System.exit(failures == 0 ? 0 : 1);
   }

   private static void dns(String host) {
      try {
         String ip = DNSLookup.lookup(host, 15);
         System.out.println("DNS " + host + " -> " + ip);
      } catch (Exception e) {
         failures++;
         System.out.println("DNS " + host + " FAILED: " + e);
      }
   }

   private static void httpGet(String url) {
      try {
         java.net.URL resolved = DNSLookup.lookup(new java.net.URL(url), 15);
         System.out.println("resolved = " + resolved);
         java.net.URLConnection conn = resolved.openConnection();
         conn.setConnectTimeout(15000);
         conn.setReadTimeout(20000);
         conn.connect();
         int len = conn.getContentLength();
         System.out.println("contentLength = " + len + ", lastModified = " + conn.getLastModified());
         java.io.InputStream in = conn.getInputStream();
         byte[] buf = new byte[8192];
         int total = 0, n;
         java.security.MessageDigest md = java.security.MessageDigest.getInstance("SHA-256");
         while ((n = in.read(buf)) != -1) {
            md.update(buf, 0, n);
            total += n;
         }
         in.close();
         System.out.println("downloaded bytes = " + total + ", sha256 = " + toHex(md.digest()));
      } catch (Exception e) {
         failures++;
         System.out.println("HTTP FAILED: " + e);
      }
   }

   private static void tcp(String host, int port) {
      try {
         String ip = DNSLookup.lookup(host, 15);
         java.net.Socket s = new java.net.Socket();
         s.connect(new java.net.InetSocketAddress(ip, port), 10000);
         System.out.println("TCP " + host + " (" + ip + "):" + port + " CONNECTED (local=" + s.getLocalSocketAddress() + ")");
         s.close();
      } catch (Exception e) {
         failures++;
         System.out.println("TCP " + host + ":" + port + " FAILED: " + e);
      }
   }

   private static String toHex(byte[] b) {
      StringBuilder sb = new StringBuilder();
      for (byte x : b) {
         sb.append(String.format("%02x", x));
      }
      return sb.toString();
   }
}

package net.openworlds.launcher;

import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLSocket;
import javax.net.ssl.TrustManager;
import javax.net.ssl.X509TrustManager;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.InetSocketAddress;
import java.security.GeneralSecurityException;
import java.security.MessageDigest;
import java.security.cert.CertificateException;
import java.security.cert.X509Certificate;
import java.util.Properties;

/**
 * Encrypted connections to J Solar Server: its certificate is its own (no
 * certificate authority vouches for it), so the launcher does what SSH does
 * with host keys. The first time, it shows the certificate's SHA-256
 * fingerprint for the player to compare with the one in the server's window,
 * and remembers it (known_servers.properties in the data folder); later it
 * warns if the server shows another. The game (the "tls" patch) then trusts
 * only that fingerprint.
 */
final class Trust {
   private Trust() {
   }

   /** The fingerprint of the certificate {@code host:port} presents (a TLS handshake, nothing more). */
   static String fingerprint(String hostPort, int timeoutMs) throws IOException {
      int colon = hostPort.lastIndexOf(':');
      String host = hostPort.substring(0, colon);
      int port = Integer.parseInt(hostPort.substring(colon + 1));
      String[] seen = {null};
      try {
         SSLContext ctx = SSLContext.getInstance("TLS");
         ctx.init(null, new TrustManager[]{new X509TrustManager() {
            @Override
            public void checkClientTrusted(X509Certificate[] chain, String authType) throws CertificateException {
               throw new CertificateException("not a server");
            }

            @Override
            public void checkServerTrusted(X509Certificate[] chain, String authType) throws CertificateException {
               if (chain == null || chain.length == 0) {
                  throw new CertificateException("no certificate");
               }
               seen[0] = of(chain[0]);
            }

            @Override
            public X509Certificate[] getAcceptedIssuers() {
               return new X509Certificate[0];
            }
         }}, null);
         try (SSLSocket s = (SSLSocket) ctx.getSocketFactory().createSocket()) {
            s.connect(new InetSocketAddress(host, port), timeoutMs);
            s.setSoTimeout(timeoutMs);
            s.startHandshake();
         }
      } catch (GeneralSecurityException e) {
         throw new IOException(e.getMessage(), e);
      } catch (IOException e) {
         if (seen[0] == null) {
            throw e;
         }
      }
      if (seen[0] == null) {
         throw new IOException("the server did not show a certificate");
      }
      return seen[0];
   }

   static String of(X509Certificate c) throws CertificateException {
      try {
         byte[] d = MessageDigest.getInstance("SHA-256").digest(c.getEncoded());
         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < d.length; i++) {
            if (i > 0) {
               sb.append(':');
            }
            sb.append(String.format("%02X", d[i] & 0xff));
         }
         return sb.toString();
      } catch (GeneralSecurityException e) {
         throw new CertificateException(e.getMessage());
      }
   }

   /** What an encrypted server shows now, next to what was trusted before. */
   static final class Check {
      final String server;
      final String fingerprint;
      /** The fingerprint trusted before for this server, or null. */
      final String known;

      Check(String server, String fingerprint, String known) {
         this.server = server;
         this.fingerprint = fingerprint;
         this.known = known;
      }

      boolean trusted() {
         return fingerprint.equals(known);
      }

      /** Trusted before, but the server shows another certificate now. */
      boolean changed() {
         return known != null && !trusted();
      }
   }

   /** Asks {@code server} (host:port) for its certificate; throws if it does not answer over TLS. */
   static Check check(Layout l, String server) throws IOException {
      return new Check(server, fingerprint(server, 8000), known(l, server));
   }

   /** The fingerprint remembered for {@code server}, or null. */
   static String known(Layout l, String server) {
      return load(l).getProperty(server.trim().toLowerCase(java.util.Locale.ROOT));
   }

   static synchronized void remember(Layout l, String server, String fingerprint) {
      Properties p = load(l);
      p.setProperty(server.trim().toLowerCase(java.util.Locale.ROOT), fingerprint);
      File f = file(l);
      f.getParentFile().mkdirs();
      try (OutputStream out = new FileOutputStream(f)) {
         p.store(out, "J Solar Server certificates this launcher trusts (host:port = SHA-256 fingerprint)");
      } catch (IOException e) {
         System.err.println("[launcher] cannot save " + f + ": " + e);
      }
   }

   private static Properties load(Layout l) {
      Properties p = new Properties();
      File f = file(l);
      if (f.isFile()) {
         try (InputStream in = new FileInputStream(f)) {
            p.load(in);
         } catch (IOException e) {
            // an unreadable file: nothing is trusted yet
         }
      }
      return p;
   }

   private static File file(Layout l) {
      return new File(l.dataDir, "known_servers.properties");
   }

   /** "AB:CD:...:EF" in two lines of 16 bytes, easier to compare. */
   static String pretty(String fp) {
      if (fp.length() < 48) {
         return fp;
      }
      return fp.substring(0, 47) + "\n" + fp.substring(48);
   }
}

package net.openworlds.solar;

import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import javax.net.ssl.SSLServerSocket;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.math.BigInteger;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;
import java.security.GeneralSecurityException;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.KeyStore;
import java.security.MessageDigest;
import java.security.PrivateKey;
import java.security.SecureRandom;
import java.security.Signature;
import java.security.cert.Certificate;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.security.spec.ECGenParameterSpec;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Enumeration;
import java.util.TimeZone;

/**
 * Encrypted connections: the server's TLS certificate and listening socket.
 * Without a keystore of your own the server makes a self-signed certificate
 * the first time (an EC P-256 key, valid 20 years) and keeps it in
 * tls/server.p12 in the data folder; players' launchers pin its SHA-256
 * fingerprint the first time they connect, like SSH does with host keys.
 */
final class Tls {
   private static final char[] GENERATED_PASSWORD = "j-solar-server".toCharArray();

   final X509Certificate certificate;
   private final SSLContext context;

   private Tls(X509Certificate certificate, SSLContext context) {
      this.certificate = certificate;
      this.context = context;
   }

   /** The configured keystore, or the generated one (made now if missing). */
   static Tls load(Config config, File dataDir) throws IOException, GeneralSecurityException {
      File ks;
      char[] password;
      if (config.tlsKeystore != null && !config.tlsKeystore.trim().isEmpty()) {
         ks = new File(config.tlsKeystore.trim());
         password = config.tlsPassword.toCharArray();
      } else {
         ks = generatedKeystore(dataDir);
         password = GENERATED_PASSWORD;
         if (!ks.isFile()) {
            generate(ks, config.name);
         }
      }
      KeyStore store = KeyStore.getInstance("PKCS12");
      try (InputStream in = new FileInputStream(ks)) {
         store.load(in, password);
      }
      X509Certificate cert = null;
      for (Enumeration<String> e = store.aliases(); e.hasMoreElements(); ) {
         String alias = e.nextElement();
         if (store.isKeyEntry(alias) && store.getCertificate(alias) instanceof X509Certificate) {
            cert = (X509Certificate) store.getCertificate(alias);
            break;
         }
      }
      if (cert == null) {
         throw new GeneralSecurityException("no private key with a certificate in " + ks);
      }
      KeyManagerFactory kmf = KeyManagerFactory.getInstance(KeyManagerFactory.getDefaultAlgorithm());
      kmf.init(store, password);
      SSLContext ctx = SSLContext.getInstance("TLS");
      ctx.init(kmf.getKeyManagers(), null, new SecureRandom());
      return new Tls(cert, ctx);
   }

   static File generatedKeystore(File dataDir) {
      return new File(new File(dataDir, "tls"), "server.p12");
   }

   SSLServerSocket listen(int port, InetAddress bind) throws IOException {
      SSLServerSocket s = (SSLServerSocket) context.getServerSocketFactory().createServerSocket(port, 50, bind);
      s.setEnabledProtocols(supported(s.getSupportedProtocols(), "TLSv1.3", "TLSv1.2"));
      return s;
   }

   private static String[] supported(String[] have, String... want) {
      java.util.List<String> out = new java.util.ArrayList<>();
      for (String w : want) {
         for (String h : have) {
            if (h.equals(w)) {
               out.add(w);
            }
         }
      }
      return out.toArray(new String[0]);
   }

   String fingerprint() {
      return fingerprint(certificate);
   }

   /** SHA-256 of the certificate, as "AB:CD:..." (what players compare and pin). */
   static String fingerprint(Certificate c) {
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
         throw new IllegalStateException(e);
      }
   }

   /** Makes a new self-signed certificate and key in {@code ks} (replacing any there). */
   static void generate(File ks, String commonName) throws IOException, GeneralSecurityException {
      KeyPairGenerator g = KeyPairGenerator.getInstance("EC");
      g.initialize(new ECGenParameterSpec("secp256r1"), new SecureRandom());
      KeyPair kp = g.generateKeyPair();
      X509Certificate cert = selfSigned(kp, commonName == null || commonName.isEmpty() ? "J Solar Server" : commonName);
      KeyStore store = KeyStore.getInstance("PKCS12");
      store.load(null, null);
      store.setKeyEntry("solar", kp.getPrivate(), GENERATED_PASSWORD, new Certificate[]{cert});
      File dir = ks.getAbsoluteFile().getParentFile();
      dir.mkdirs();
      File tmp = new File(dir, ks.getName() + ".tmp");
      try (OutputStream out = new FileOutputStream(tmp)) {
         store.store(out, GENERATED_PASSWORD);
      }
      tmp.setReadable(false, false);
      tmp.setReadable(true, true);
      java.nio.file.Files.move(tmp.toPath(), ks.toPath(), java.nio.file.StandardCopyOption.REPLACE_EXISTING);
   }

   // ------------------------------------------------------------------ X.509

   /** A minimal X.509 v3 certificate signed by its own key (ECDSA with SHA-256). */
   static X509Certificate selfSigned(KeyPair kp, String cn) throws GeneralSecurityException {
      byte[] ecdsaSha256 = seq(oid(1, 2, 840, 10045, 4, 3, 2));
      byte[] name = seq(set(seq(oid(2, 5, 4, 3), tlv(0x0c, cn.getBytes(StandardCharsets.UTF_8)))));
      long now = System.currentTimeMillis();
      byte[] validity = seq(utcTime(new Date(now - 86_400_000L)), utcTime(new Date(now + 20L * 365 * 86_400_000L)));
      byte[] serial = new byte[16];
      new SecureRandom().nextBytes(serial);
      serial[0] &= 0x7f;
      serial[0] |= 0x01;
      byte[] tbs = seq(
         tlv(0xa0, integer(BigInteger.valueOf(2))),
         integer(new BigInteger(serial)),
         ecdsaSha256,
         name,
         validity,
         name,
         kp.getPublic().getEncoded());
      Signature s = Signature.getInstance("SHA256withECDSA");
      PrivateKey key = kp.getPrivate();
      s.initSign(key);
      s.update(tbs);
      byte[] sig = s.sign();
      byte[] bits = new byte[sig.length + 1];
      System.arraycopy(sig, 0, bits, 1, sig.length);
      byte[] der = seq(tbs, ecdsaSha256, tlv(0x03, bits));
      return (X509Certificate) CertificateFactory.getInstance("X.509").generateCertificate(new ByteArrayInputStream(der));
   }

   private static byte[] tlv(int tag, byte[] value) {
      ByteArrayOutputStream b = new ByteArrayOutputStream(value.length + 4);
      b.write(tag);
      int n = value.length;
      if (n < 0x80) {
         b.write(n);
      } else if (n < 0x100) {
         b.write(0x81);
         b.write(n);
      } else {
         b.write(0x82);
         b.write(n >> 8);
         b.write(n & 0xff);
      }
      b.write(value, 0, value.length);
      return b.toByteArray();
   }

   private static byte[] concat(byte[]... parts) {
      ByteArrayOutputStream b = new ByteArrayOutputStream();
      for (byte[] p : parts) {
         b.write(p, 0, p.length);
      }
      return b.toByteArray();
   }

   private static byte[] seq(byte[]... parts) {
      return tlv(0x30, concat(parts));
   }

   private static byte[] set(byte[]... parts) {
      return tlv(0x31, concat(parts));
   }

   private static byte[] integer(BigInteger v) {
      return tlv(0x02, v.toByteArray());
   }

   private static byte[] oid(int... arcs) {
      ByteArrayOutputStream b = new ByteArrayOutputStream();
      b.write(arcs[0] * 40 + arcs[1]);
      for (int i = 2; i < arcs.length; i++) {
         int v = arcs[i];
         int len = 1;
         for (int t = v >>> 7; t != 0; t >>>= 7) {
            len++;
         }
         for (int k = len - 1; k >= 0; k--) {
            int septet = (v >>> (7 * k)) & 0x7f;
            b.write(k == 0 ? septet : septet | 0x80);
         }
      }
      return tlv(0x06, b.toByteArray());
   }

   private static byte[] utcTime(Date d) {
      SimpleDateFormat f = new SimpleDateFormat("yyMMddHHmmss'Z'");
      f.setTimeZone(TimeZone.getTimeZone("UTC"));
      return tlv(0x17, f.format(d).getBytes(StandardCharsets.US_ASCII));
   }
}

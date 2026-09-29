package net.openworlds.launcher;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.URI;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.text.SimpleDateFormat;
import java.util.Collections;
import java.util.Date;
import java.util.HashSet;
import java.util.Locale;
import java.util.Set;
import java.util.TimeZone;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.Executors;

/**
 * The client's upgrade server (worlds.ini upgradeServer), the Java port of
 * tools/local-upgrade-server.py: files of the 2004 install under /3DCDup/,
 * the official base avatars under /3DCDup/avatar/, names matched without
 * case as on Windows. Bound to 127.0.0.1 only.
 *
 * <p>What the install lacks (other worlds' upgrades.lst and packages, avatar
 * wardrobe) is asked, when a mirror is given, of the upgrade server the 2004
 * install points at: http://us1.worlds.net/3DCDup is alive again as
 * LibreWorlds' mirror (upgrade.libreworlds.org). Each file fetched is kept in
 * the user's data folder (mirror/), so it is fetched once; a 404 or a network
 * error is answered with an immediate 404 and not asked again this session.
 */
final class UpgradeServer {
   private static final String PREFIX = "/3DCDup/";
   private static final String AVATAR_PREFIX = PREFIX + "avatar/";

   private final HttpServer server;
   private final File root;
   private final File avatars;
   private final String mirror;
   private final File cache;
   private final Log log;
   private final Set<String> missing = Collections.synchronizedSet(new HashSet<>());
   private final ConcurrentHashMap<String, Object> locks = new ConcurrentHashMap<>();

   UpgradeServer(File root, File avatars, String mirror, File cache, Log log) throws IOException {
      this.root = root;
      this.avatars = avatars;
      this.mirror = mirror;
      this.cache = cache;
      this.log = log;
      this.server = HttpServer.create(new InetSocketAddress(InetAddress.getLoopbackAddress(), 0), 16);
      this.server.createContext("/", this::handle);
      this.server.setExecutor(Executors.newCachedThreadPool(r -> {
         Thread t = new Thread(r, "openworlds-upgrade-server");
         t.setDaemon(true);
         return t;
      }));
   }

   void start() {
      server.start();
   }

   int port() {
      return server.getAddress().getPort();
   }

   void stop() {
      server.stop(0);
   }

   private void handle(HttpExchange ex) throws IOException {
      try {
         String path = URI.create(ex.getRequestURI().toString()).getPath();
         File f = resolve(path);
         String method = ex.getRequestMethod();
         if (f == null || !f.isFile() || !(method.equals("GET") || method.equals("HEAD"))) {
            log.line("[local server] 404 " + path);
            ex.sendResponseHeaders(404, -1);
            return;
         }
         long modified = f.lastModified() / 1000L * 1000L;
         ex.getResponseHeaders().set("Content-Type", "application/octet-stream");
         ex.getResponseHeaders().set("Last-Modified", httpDate(modified));
         String ims = ex.getRequestHeaders().getFirst("If-Modified-Since");
         if (ims != null) {
            try {
               if (parseHttpDate(ims) >= modified) {
                  ex.sendResponseHeaders(304, -1);
                  return;
               }
            } catch (java.text.ParseException ignored) {
               // odd header: served whole, as SimpleHTTPRequestHandler does
            }
         }
         byte[] data = Files.readAllBytes(f.toPath());
         if (method.equals("HEAD")) {
            ex.getResponseHeaders().set("Content-Length", Integer.toString(data.length));
            ex.sendResponseHeaders(200, -1);
            return;
         }
         ex.sendResponseHeaders(200, data.length);
         try (OutputStream os = ex.getResponseBody()) {
            os.write(data);
         }
      } finally {
         ex.close();
      }
   }

   /** The file behind a request path, or null. */
   File resolve(String path) {
      if (path == null || !path.startsWith(PREFIX)) {
         return null;
      }
      if (path.startsWith(AVATAR_PREFIX) && avatars != null && avatars.isDirectory()) {
         String name = path.substring(AVATAR_PREFIX.length());
         if (!name.contains("/") && !name.contains("\\")) {
            File hit = Install.findNoCase(avatars, name);
            if (hit != null && hit.isFile()) {
               return hit;
            }
         }
      }
      String rel = safeRelative(path.substring(PREFIX.length()));
      if (rel == null) {
         return null;
      }
      File local = lookup(root, rel);
      if (local != null && local.isFile()) {
         return local;
      }
      if (cache == null) {
         return null;
      }
      File cached = lookup(cache, rel);
      if (cached != null && cached.isFile()) {
         return cached;
      }
      return fetch(rel);
   }

   /** The path's segments joined with '/', or null if one is "..", has a backslash or a NUL. */
   private static String safeRelative(String p) {
      StringBuilder sb = new StringBuilder();
      for (String part : p.split("/")) {
         if (part.isEmpty() || part.equals(".")) {
            continue;
         }
         if (part.equals("..") || part.contains("\\") || part.indexOf('\0') >= 0 || part.indexOf(':') >= 0) {
            return null;
         }
         sb.append(sb.length() == 0 ? "" : "/").append(part);
      }
      return sb.toString();
   }

   private static File lookup(File dir, String rel) {
      File cur = dir;
      for (String part : rel.split("/")) {
         if (part.isEmpty()) {
            continue;
         }
         cur = Install.findNoCase(cur, part);
         if (cur == null) {
            return null;
         }
      }
      return cur;
   }

   /** GET mirror/rel into the cache; null (and remembered) when it is not there. */
   private File fetch(String rel) {
      if (mirror == null || rel.isEmpty() || missing.contains(rel.toLowerCase(Locale.ROOT))) {
         return null;
      }
      Object lock = locks.computeIfAbsent(rel.toLowerCase(Locale.ROOT), k -> new Object());
      synchronized (lock) {
         File cached = lookup(cache, rel);
         if (cached != null && cached.isFile()) {
            return cached;
         }
         if (missing.contains(rel.toLowerCase(Locale.ROOT))) {
            return null;
         }
         File to = new File(cache, rel);
         File tmp = new File(to.getPath() + ".part");
         try {
            URL url = URI.create(mirror + "/").resolve(new URI(null, null, rel, null)).toURL();
            HttpURLConnection c = (HttpURLConnection) url.openConnection();
            c.setConnectTimeout(5000);
            c.setReadTimeout(30000);
            c.setInstanceFollowRedirects(true);
            c.setRequestProperty("User-Agent", "OpenWorlds/" + Layout.version());
            int code = c.getResponseCode();
            if (code != 200) {
               c.disconnect();
               missing.add(rel.toLowerCase(Locale.ROOT));
               log.line("[local server] mirror " + code + " " + rel);
               return null;
            }
            to.getParentFile().mkdirs();
            try (InputStream in = c.getInputStream()) {
               Files.copy(in, tmp.toPath(), StandardCopyOption.REPLACE_EXISTING);
            }
            Files.move(tmp.toPath(), to.toPath(), StandardCopyOption.REPLACE_EXISTING);
            log.line("[local server] mirror: " + rel + " (" + to.length() + " bytes)");
            return to;
         } catch (IOException | java.net.URISyntaxException | RuntimeException e) {
            tmp.delete();
            missing.add(rel.toLowerCase(Locale.ROOT));
            log.line("[local server] no answer from the mirror for " + rel + ": " + e);
            return null;
         }
      }
   }

   private static String httpDate(long ms) {
      SimpleDateFormat f = new SimpleDateFormat("EEE, dd MMM yyyy HH:mm:ss 'GMT'", Locale.US);
      f.setTimeZone(TimeZone.getTimeZone("GMT"));
      return f.format(new Date(ms));
   }

   private static long parseHttpDate(String s) throws java.text.ParseException {
      SimpleDateFormat f = new SimpleDateFormat("EEE, dd MMM yyyy HH:mm:ss 'GMT'", Locale.US);
      f.setTimeZone(TimeZone.getTimeZone("GMT"));
      return f.parse(s.trim()).getTime();
   }
}

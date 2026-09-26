package net.freeworlds.launcher;

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpServer;

import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.URI;
import java.nio.file.Files;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.TimeZone;
import java.util.concurrent.Executors;

/**
 * Local stand-in for http://us1.worlds.net/3DCDup (gone), the Java port of
 * tools/local-upgrade-server.py: files of the 2004 install under /3DCDup/,
 * the official base avatars under /3DCDup/avatar/, names matched without
 * case as on Windows, and an immediate 404 for what does not exist instead
 * of the client waiting on a dead host. Bound to 127.0.0.1 only.
 */
final class UpgradeServer {
   private static final String PREFIX = "/3DCDup/";
   private static final String AVATAR_PREFIX = PREFIX + "avatar/";

   private final HttpServer server;
   private final File root;
   private final File avatars;
   private final Log log;

   UpgradeServer(File root, File avatars, Log log) throws IOException {
      this.root = root;
      this.avatars = avatars;
      this.log = log;
      this.server = HttpServer.create(new InetSocketAddress(InetAddress.getLoopbackAddress(), 0), 16);
      this.server.createContext("/", this::handle);
      this.server.setExecutor(Executors.newCachedThreadPool(r -> {
         Thread t = new Thread(r, "freeworlds-upgrade-server");
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
            log.line("[servidor local] 404 " + path);
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
               // cabecera rara: se sirve entero, como SimpleHTTPRequestHandler
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
      File cur = root;
      for (String part : path.substring(PREFIX.length()).split("/")) {
         if (part.isEmpty() || part.equals(".")) {
            continue;
         }
         if (part.equals("..") || part.contains("\\") || part.indexOf('\0') >= 0) {
            return null;
         }
         cur = Install.findNoCase(cur, part);
         if (cur == null) {
            return null;
         }
      }
      return cur;
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

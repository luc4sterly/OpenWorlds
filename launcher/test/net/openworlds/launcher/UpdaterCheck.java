package net.openworlds.launcher;

import com.sun.net.httpserver.HttpServer;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.jar.Attributes;
import java.util.jar.JarEntry;
import java.util.jar.JarOutputStream;
import java.util.jar.Manifest;
import java.util.stream.Stream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

/**
 * The automatic update, end to end, against a fake GitHub on 127.0.0.1:
 * versions and JSON with hand-made cases; then a bundled launcher 1.0.100
 * (the real classes, in a jar with that version) is run as a separate JVM:
 * --update installs the newest stable release, checked against its digest,
 * without sending the token past the API's host; the next start hands over to
 * it; pre-releases only when asked; a wrong checksum or a zip with "../"
 * install nothing; a downloaded version that does not start falls back to the
 * bundled one and is skipped from then on.
 */
public final class UpdaterCheck {
   private static int failures;

   public static void main(String[] args) throws Exception {
      versions();
      json();
      endToEnd();
      if (failures > 0) {
         System.out.println("UpdaterCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("UpdaterCheck: all good");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FAIL  ") + what);
      if (!ok) {
         failures++;
      }
   }

   // ----------------------------------------------------------------- Version

   private static void versions() {
      System.out.println("Version:");
      check(Version.parse("v1.0.150").text.equals("1.0.150"), "v1.0.150 -> 1.0.150");
      check(Version.parse("1.0.150").compareTo(Version.parse("1.0.151")) < 0, "1.0.150 < 1.0.151");
      check(Version.parse("1.0.9").compareTo(Version.parse("1.0.10")) < 0, "1.0.9 < 1.0.10 (numeric, not text)");
      check(Version.parse("1.1.0").compareTo(Version.parse("1.0.999")) > 0, "1.1.0 > 1.0.999");
      check(Version.parse("1.0.150-pre.3").compareTo(Version.parse("1.0.150")) < 0, "1.0.150-pre.3 < 1.0.150");
      check(Version.parse("1.0.151-pre.1").compareTo(Version.parse("1.0.150")) > 0, "1.0.151-pre.1 > 1.0.150");
      check(Version.parse("1.0.150-pre.10").compareTo(Version.parse("1.0.150-pre.9")) > 0, "pre.10 > pre.9");
      check(Version.parse("1.0").compareTo(Version.parse("1.0.0")) == 0, "1.0 == 1.0.0");
      check(Version.parse("65a3e83") == null, "commit hash: no version");
      check(Version.parse("dev") == null, "dev: no version");
      check(Version.parse("1") == null, "a single number: no version");
      check(Version.parse("1..2") == null, "1..2: no version");
   }

   // -------------------------------------------------------------------- Json

   private static void json() {
      System.out.println("Json:");
      Object o = Json.parse("[{\"tag_name\":\"v1.0.2\",\"draft\":false,\"size\":12345,\"x\":-1.5e2,"
         + "\"name\":\"Caf\\u00e9 \\\"con\\\" \\\\ leche\\n\",\"assets\":[],\"n\":null,\"t\":true}]");
      List<Object> list = Json.array(o);
      Map<String, Object> r = Json.object(list.get(0));
      check(list.size() == 1, "one element");
      check("v1.0.2".equals(Json.string(r, "tag_name")), "string");
      check(!Json.bool(r, "draft") && Json.bool(r, "t"), "booleans");
      check(Json.number(r, "size") == 12345, "integer");
      check(Double.valueOf(-150.0).equals(r.get("x")), "decimal with exponent");
      check("Café \"con\" \\ leche\n".equals(Json.string(r, "name")), "escapes and \\u00e9");
      check(r.containsKey("n") && r.get("n") == null, "null");
      check(Json.array(r.get("assets")).isEmpty(), "empty array");
      boolean threw = false;
      try {
         Json.parse("{\"a\":1,}");
      } catch (IllegalArgumentException e) {
         threw = true;
      }
      check(threw, "trailing comma: error");
   }

   // ------------------------------------------------------------- end to end

   private static final Map<String, String> AUTH_SEEN = new ConcurrentHashMap<>();

   private static void endToEnd() throws Exception {
      System.out.println("Full update (fake GitHub on 127.0.0.1):");
      Path tmp = Files.createTempDirectory("fw-updater-check");
      try {
         endToEnd(tmp);
      } finally {
         Layout.deleteTree(tmp);
      }
   }

   private static void endToEnd(Path tmp) throws Exception {
      File classes = new File(Launcher.class.getProtectionDomain().getCodeSource().getLocation().toURI());
      // the "bundled" launcher: the real classes with version 1.0.100
      Path bundled = tmp.resolve("bundled");
      Files.createDirectories(bundled.resolve("lib"));
      Path bundledJar = bundled.resolve("lib/openworlds-launcher.jar");
      Files.write(bundledJar, launcherJar(classes, "1.0.100"));
      Files.createDirectories(bundled.resolve("game/assets/WorldsPlayer"));
      Files.write(bundled.resolve("game/assets/WorldsPlayer/worlds.ini"), "[Gamma]\r\n".getBytes(StandardCharsets.ISO_8859_1));

      byte[] zip300 = portableZip(launcherJar(classes, "1.0.300"), false);
      byte[] zipPre = portableZip(launcherJar(classes, "1.0.400-pre.1"), false);
      byte[] zipBad = portableZip(launcherJar(classes, "1.0.500"), false);

      HttpServer srv = HttpServer.create(new InetSocketAddress(InetAddress.getLoopbackAddress(), 0), 8);
      int port = srv.getAddress().getPort();
      String api = "http://127.0.0.1:" + port;
      Map<String, byte[]> blobs = new ConcurrentHashMap<>();
      blobs.put("300", zip300);
      blobs.put("pre", zipPre);
      blobs.put("bad", zipBad);
      String[] releases = {releasesJson(api, zip300, zipPre, false)};
      srv.createContext("/repos/o/r/releases", ex -> {
         AUTH_SEEN.put("api", String.valueOf(ex.getRequestHeaders().getFirst("Authorization")));
         byte[] b = releases[0].getBytes(StandardCharsets.UTF_8);
         ex.getResponseHeaders().set("Content-Type", "application/json");
         ex.sendResponseHeaders(200, b.length);
         try (OutputStream os = ex.getResponseBody()) {
            os.write(b);
         }
      });
      // the assets "API" redirects to another host (localhost instead of 127.0.0.1)
      srv.createContext("/assets/", ex -> {
         AUTH_SEEN.put("asset", String.valueOf(ex.getRequestHeaders().getFirst("Authorization")));
         String id = ex.getRequestURI().getPath().substring("/assets/".length());
         ex.getResponseHeaders().set("Location", "http://localhost:" + port + "/blob/" + id);
         ex.sendResponseHeaders(302, -1);
         ex.close();
      });
      srv.createContext("/blob/", ex -> {
         AUTH_SEEN.put("blob", String.valueOf(ex.getRequestHeaders().getFirst("Authorization")));
         byte[] b = blobs.get(ex.getRequestURI().getPath().substring("/blob/".length()));
         if (b == null) {
            ex.sendResponseHeaders(404, -1);
            ex.close();
            return;
         }
         ex.sendResponseHeaders(200, b.length);
         try (OutputStream os = ex.getResponseBody()) {
            os.write(b);
         }
      });
      srv.start();
      try {
         Path data = tmp.resolve("data");
         Run r = run(bundledJar, data, api, "--update");
         check(r.code == 0, "--update exits with 0 (" + r.code + ")");
         check("1.0.300".equals(read(data.resolve("app/current"))), "app/current = 1.0.300 (the newest stable, not the pre-release nor the draft)");
         check(Files.isRegularFile(data.resolve("app/1.0.300/.complete")), "app/1.0.300 complete");
         check("Bearer secret".equals(AUTH_SEEN.get("api")), "the token goes to the API");
         check("null".equals(AUTH_SEEN.get("blob")), "the token does NOT go to the download host");
         check(!Files.exists(data.resolve("app/download/OpenWorlds-1.0.300-portable.zip")), "the downloaded zip is deleted after installing");

         r = run(bundledJar, data, api, "--version");
         check(r.out.contains("OpenWorlds 1.0.300"), "the next start is 1.0.300: " + r.out.trim());
         r = run(bundledJar, data, api, "--no-update", "--version");
         check(r.out.contains("OpenWorlds 1.0.100"), "--no-update starts the bundled one: " + r.out.trim());

         // with pre-releases asked for, 1.0.400-pre.1 is taken (and 1.0.300 runs it)
         Files.write(data.resolve("launcher.properties"), "prerelease=true\n".getBytes(StandardCharsets.ISO_8859_1));
         r = run(bundledJar, data, api, "--update");
         check(r.code == 0 && "1.0.400-pre.1".equals(read(data.resolve("app/current"))), "pre-release asked for: app/current = 1.0.400-pre.1");

         // a digest that does not match installs nothing
         releases[0] = releasesJson(api, zipBad, null, true);
         Files.write(data.resolve("launcher.properties"), "prerelease=false\n".getBytes(StandardCharsets.ISO_8859_1));
         r = run(bundledJar, data, api, "--update");
         check(r.code != 0, "SHA-256 mismatch: --update fails (" + r.code + ")");
         check("1.0.400-pre.1".equals(read(data.resolve("app/current"))), "SHA-256 mismatch: app/current does not change");
         check(!Files.exists(data.resolve("app/1.0.500")), "SHA-256 mismatch: nothing of 1.0.500 is left");

         // a zip with "../" is not unpacked outside
         Path evil = tmp.resolve("evil.zip");
         Files.write(evil, portableZip(launcherJar(classes, "1.0.600"), true));
         boolean refused = false;
         try {
            Updater.install(evil.toFile(), Version.parse("1.0.600"), data.resolve("app").toFile());
         } catch (IOException e) {
            refused = e.getMessage().contains("outside the package");
         }
         check(refused && !Files.exists(data.resolve("app/escaped.txt")), "zip with ../: refused");

         // a downloaded version that does not start: back to the bundled one, recorded in app/bad
         Path broken = data.resolve("app/1.0.700");
         Files.createDirectories(broken.resolve("lib"));
         Files.createDirectories(broken.resolve("game/assets/WorldsPlayer"));
         Files.write(broken.resolve("game/assets/WorldsPlayer/worlds.ini"), new byte[0]);
         Files.write(broken.resolve("lib/worldsplayer.jar"), emptyJar());
         Files.write(broken.resolve("lib/openworlds-launcher.jar"), emptyJar());
         Files.write(broken.resolve(".complete"), "1.0.700".getBytes(StandardCharsets.UTF_8));
         Files.write(data.resolve("app/current"), "1.0.700".getBytes(StandardCharsets.UTF_8));
         r = run(bundledJar, data, api, "--version");
         check(r.out.contains("OpenWorlds 1.0.100"), "broken version: the bundled one starts: " + r.out.trim());
         check(read(data.resolve("app/bad")).contains("1.0.700"), "broken version: recorded in app/bad");
         r = run(bundledJar, data, api, "--version");
         check(!r.err.contains("1.0.700"), "broken version: not retried");
      } finally {
         srv.stop(0);
      }
   }

   private static final class Run {
      int code;
      String out;
      String err;
   }

   private static Run run(Path jar, Path data, String api, String... args) throws Exception {
      List<String> cmd = new ArrayList<>();
      cmd.add(Layout.javaExecutable());
      cmd.add("-Dopenworlds.data=" + data);
      cmd.add("-Dopenworlds.updateApi=" + api);
      cmd.add("-Dopenworlds.updateRepo=o/r");
      cmd.add("-Djava.awt.headless=true");
      cmd.add("-jar");
      cmd.add(jar.toString());
      for (String a : args) {
         cmd.add(a);
      }
      ProcessBuilder pb = new ProcessBuilder(cmd);
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      pb.environment().put("OPENWORLDS_GITHUB_TOKEN", "secret");
      pb.environment().remove("OPENWORLDS_NO_UPDATE");
      File out = Files.createTempFile("fw-run", ".out").toFile();
      File err = Files.createTempFile("fw-run", ".err").toFile();
      pb.redirectOutput(out);
      pb.redirectError(err);
      Process p = pb.start();
      Run r = new Run();
      if (!p.waitFor(60, java.util.concurrent.TimeUnit.SECONDS)) {
         p.destroyForcibly();
         r.code = -1;
      } else {
         r.code = p.exitValue();
      }
      r.out = new String(Files.readAllBytes(out.toPath()), StandardCharsets.UTF_8);
      r.err = new String(Files.readAllBytes(err.toPath()), StandardCharsets.UTF_8);
      out.delete();
      err.delete();
      if (r.code != 0 && !r.err.isEmpty()) {
         System.out.println("    (stderr: " + r.err.trim().replace("\n", " | ") + ")");
      }
      return r;
   }

   private static String read(Path p) throws IOException {
      return Files.isRegularFile(p) ? new String(Files.readAllBytes(p), StandardCharsets.UTF_8).trim() : "";
   }

   private static String releasesJson(String api, byte[] stable, byte[] pre, boolean wrongDigest) throws Exception {
      String stableVer = wrongDigest ? "1.0.500" : "1.0.300";
      String stableId = wrongDigest ? "bad" : "300";
      StringBuilder sb = new StringBuilder("[");
      sb.append(release("v1.0.999", false, true, api, "999", new byte[]{1}, false)).append(',');
      if (pre != null) {
         sb.append(release("v1.0.400-pre.1", true, false, api, "pre", pre, false)).append(',');
      }
      sb.append(release("v" + stableVer, false, false, api, stableId, stable, wrongDigest)).append(',');
      sb.append(release("v1.0.250", false, false, api, "250", new byte[]{2}, false));
      return sb.append(']').toString();
   }

   private static String release(String tag, boolean pre, boolean draft, String api, String id, byte[] zip, boolean wrongDigest)
      throws Exception {
      String v = tag.substring(1);
      String sha = Updater.hex(MessageDigest.getInstance("SHA-256").digest(zip));
      if (wrongDigest) {
         sha = sha.replace(sha.charAt(0), sha.charAt(0) == '0' ? '1' : '0');
      }
      return "{\"tag_name\":\"" + tag + "\",\"draft\":" + draft + ",\"prerelease\":" + pre
         + ",\"html_url\":\"https://example.invalid/" + tag + "\",\"assets\":["
         + "{\"name\":\"OpenWorlds-" + v + "-linux-x64.tar.gz\",\"size\":1,\"url\":\"" + api + "/assets/none\"},"
         + "{\"name\":\"OpenWorlds-" + v + "-portable.zip\",\"size\":" + zip.length + ",\"url\":\"" + api + "/assets/" + id
         + "\",\"digest\":\"sha256:" + sha + "\"},"
         // the server's package is in the same release: never the launcher's update
         + "{\"name\":\"JSolarServer-" + v + "-portable.zip\",\"size\":1,\"url\":\"" + api + "/assets/none\"}]}";
   }

   /** The launcher's classes (and resources) in a jar that says it is the given version. */
   private static byte[] launcherJar(File classes, String version) throws IOException {
      Manifest m = new Manifest();
      m.getMainAttributes().put(Attributes.Name.MANIFEST_VERSION, "1.0");
      m.getMainAttributes().put(Attributes.Name.MAIN_CLASS, "net.openworlds.launcher.Launcher");
      m.getMainAttributes().put(Attributes.Name.IMPLEMENTATION_VERSION, version);
      m.getMainAttributes().putValue("OpenWorlds-Update-Repo", "o/r");
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      Path base = classes.toPath();
      try (JarOutputStream jar = new JarOutputStream(bytes, m); Stream<Path> walk = Files.walk(base)) {
         for (Path p : (Iterable<Path>) walk.filter(Files::isRegularFile)::iterator) {
            String name = base.relativize(p).toString().replace(File.separatorChar, '/');
            if (name.endsWith("Check.class") || name.contains("UpdaterCheck")) {
               continue;
            }
            jar.putNextEntry(new JarEntry(name));
            jar.write(Files.readAllBytes(p));
            jar.closeEntry();
         }
      }
      return bytes.toByteArray();
   }

   private static byte[] emptyJar() throws IOException {
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      Manifest m = new Manifest();
      m.getMainAttributes().put(Attributes.Name.MANIFEST_VERSION, "1.0");
      try (JarOutputStream jar = new JarOutputStream(bytes, m)) {
         jar.putNextEntry(new JarEntry("empty.txt"));
         jar.closeEntry();
      }
      return bytes.toByteArray();
   }

   /** The portable package's layout: OpenWorlds/lib/*.jar and OpenWorlds/game/assets/WorldsPlayer. */
   private static byte[] portableZip(byte[] launcherJar, boolean evil) throws IOException {
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      try (ZipOutputStream z = new ZipOutputStream(bytes)) {
         put(z, "OpenWorlds/lib/openworlds-launcher.jar", launcherJar);
         put(z, "OpenWorlds/lib/worldsplayer.jar", emptyJar());
         put(z, "OpenWorlds/game/assets/WorldsPlayer/worlds.ini", "[Gamma]\r\n".getBytes(StandardCharsets.ISO_8859_1));
         if (evil) {
            put(z, "OpenWorlds/../../escaped.txt", new byte[]{1});
         }
      }
      return bytes.toByteArray();
   }

   private static void put(ZipOutputStream z, String name, byte[] data) throws IOException {
      z.putNextEntry(new ZipEntry(name));
      z.write(data);
      z.closeEntry();
   }
}

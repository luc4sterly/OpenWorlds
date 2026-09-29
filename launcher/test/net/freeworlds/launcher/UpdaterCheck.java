package net.freeworlds.launcher;

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
         System.out.println("UpdaterCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("UpdaterCheck: todo bien");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FALLA ") + what);
      if (!ok) {
         failures++;
      }
   }

   // ----------------------------------------------------------------- Version

   private static void versions() {
      System.out.println("Version:");
      check(Version.parse("v1.0.150").text.equals("1.0.150"), "v1.0.150 -> 1.0.150");
      check(Version.parse("1.0.150").compareTo(Version.parse("1.0.151")) < 0, "1.0.150 < 1.0.151");
      check(Version.parse("1.0.9").compareTo(Version.parse("1.0.10")) < 0, "1.0.9 < 1.0.10 (numerico, no texto)");
      check(Version.parse("1.1.0").compareTo(Version.parse("1.0.999")) > 0, "1.1.0 > 1.0.999");
      check(Version.parse("1.0.150-pre.3").compareTo(Version.parse("1.0.150")) < 0, "1.0.150-pre.3 < 1.0.150");
      check(Version.parse("1.0.151-pre.1").compareTo(Version.parse("1.0.150")) > 0, "1.0.151-pre.1 > 1.0.150");
      check(Version.parse("1.0.150-pre.10").compareTo(Version.parse("1.0.150-pre.9")) > 0, "pre.10 > pre.9");
      check(Version.parse("1.0").compareTo(Version.parse("1.0.0")) == 0, "1.0 == 1.0.0");
      check(Version.parse("65a3e83") == null, "hash de commit: sin version");
      check(Version.parse("dev") == null, "dev: sin version");
      check(Version.parse("1") == null, "un solo numero: sin version");
      check(Version.parse("1..2") == null, "1..2: sin version");
   }

   // -------------------------------------------------------------------- Json

   private static void json() {
      System.out.println("Json:");
      Object o = Json.parse("[{\"tag_name\":\"v1.0.2\",\"draft\":false,\"size\":12345,\"x\":-1.5e2,"
         + "\"name\":\"Caf\\u00e9 \\\"con\\\" \\\\ leche\\n\",\"assets\":[],\"n\":null,\"t\":true}]");
      List<Object> list = Json.array(o);
      Map<String, Object> r = Json.object(list.get(0));
      check(list.size() == 1, "un elemento");
      check("v1.0.2".equals(Json.string(r, "tag_name")), "cadena");
      check(!Json.bool(r, "draft") && Json.bool(r, "t"), "booleanos");
      check(Json.number(r, "size") == 12345, "entero");
      check(Double.valueOf(-150.0).equals(r.get("x")), "decimal con exponente");
      check("Café \"con\" \\ leche\n".equals(Json.string(r, "name")), "escapes y \\u00e9");
      check(r.containsKey("n") && r.get("n") == null, "null");
      check(Json.array(r.get("assets")).isEmpty(), "array vacio");
      boolean threw = false;
      try {
         Json.parse("{\"a\":1,}");
      } catch (IllegalArgumentException e) {
         threw = true;
      }
      check(threw, "coma de sobra: error");
   }

   // ----------------------------------------------------------- de punta a punta

   private static final Map<String, String> AUTH_SEEN = new ConcurrentHashMap<>();

   private static void endToEnd() throws Exception {
      System.out.println("Actualizacion completa (GitHub falso en 127.0.0.1):");
      Path tmp = Files.createTempDirectory("fw-updater-check");
      try {
         endToEnd(tmp);
      } finally {
         Layout.deleteTree(tmp);
      }
   }

   private static void endToEnd(Path tmp) throws Exception {
      File classes = new File(Launcher.class.getProtectionDomain().getCodeSource().getLocation().toURI());
      // el lanzador "incluido": las clases reales con la version 1.0.100
      Path bundled = tmp.resolve("bundled");
      Files.createDirectories(bundled.resolve("lib"));
      Path bundledJar = bundled.resolve("lib/freeworlds-launcher.jar");
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
      // la "API" de assets redirige a otro host (localhost en vez de 127.0.0.1)
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
         check(r.code == 0, "--update sale con 0 (" + r.code + ")");
         check("1.0.300".equals(read(data.resolve("app/current"))), "app/current = 1.0.300 (la estable mas nueva, no la prerelease ni el borrador)");
         check(Files.isRegularFile(data.resolve("app/1.0.300/.complete")), "app/1.0.300 completa");
         check("Bearer secreto".equals(AUTH_SEEN.get("api")), "el token va a la API");
         check("null".equals(AUTH_SEEN.get("blob")), "el token NO va al host de la descarga");
         check(!Files.exists(data.resolve("app/download/FreeWorlds-1.0.300-portable.zip")), "el zip descargado se borra tras instalar");

         r = run(bundledJar, data, api, "--version");
         check(r.out.contains("FreeWorlds 1.0.300"), "el siguiente arranque es la 1.0.300: " + r.out.trim());
         r = run(bundledJar, data, api, "--no-update", "--version");
         check(r.out.contains("FreeWorlds 1.0.100"), "--no-update arranca la incluida: " + r.out.trim());

         // con prereleases pedidas se toma la 1.0.400-pre.1 (y la corre la 1.0.300)
         Files.write(data.resolve("launcher.properties"), "prerelease=true\n".getBytes(StandardCharsets.ISO_8859_1));
         r = run(bundledJar, data, api, "--update");
         check(r.code == 0 && "1.0.400-pre.1".equals(read(data.resolve("app/current"))), "prerelease pedida: app/current = 1.0.400-pre.1");

         // un digest que no cuadra no instala nada
         releases[0] = releasesJson(api, zipBad, null, true);
         Files.write(data.resolve("launcher.properties"), "prerelease=false\n".getBytes(StandardCharsets.ISO_8859_1));
         r = run(bundledJar, data, api, "--update");
         check(r.code != 0, "SHA-256 distinto: --update falla (" + r.code + ")");
         check("1.0.400-pre.1".equals(read(data.resolve("app/current"))), "SHA-256 distinto: app/current no cambia");
         check(!Files.exists(data.resolve("app/1.0.500")), "SHA-256 distinto: no queda nada de la 1.0.500");

         // un zip con "../" no se desempaqueta fuera
         Path evil = tmp.resolve("evil.zip");
         Files.write(evil, portableZip(launcherJar(classes, "1.0.600"), true));
         boolean refused = false;
         try {
            Updater.install(evil.toFile(), Version.parse("1.0.600"), data.resolve("app").toFile());
         } catch (IOException e) {
            refused = e.getMessage().contains("fuera del paquete");
         }
         check(refused && !Files.exists(data.resolve("app/escapado.txt")), "zip con ../: rechazado");

         // una version descargada que no arranca: se vuelve a la incluida y se apunta en app/bad
         Path broken = data.resolve("app/1.0.700");
         Files.createDirectories(broken.resolve("lib"));
         Files.createDirectories(broken.resolve("game/assets/WorldsPlayer"));
         Files.write(broken.resolve("game/assets/WorldsPlayer/worlds.ini"), new byte[0]);
         Files.write(broken.resolve("lib/worldsplayer.jar"), emptyJar());
         Files.write(broken.resolve("lib/freeworlds-launcher.jar"), emptyJar());
         Files.write(broken.resolve(".complete"), "1.0.700".getBytes(StandardCharsets.UTF_8));
         Files.write(data.resolve("app/current"), "1.0.700".getBytes(StandardCharsets.UTF_8));
         r = run(bundledJar, data, api, "--version");
         check(r.out.contains("FreeWorlds 1.0.100"), "version rota: arranca la incluida: " + r.out.trim());
         check(read(data.resolve("app/bad")).contains("1.0.700"), "version rota: apuntada en app/bad");
         r = run(bundledJar, data, api, "--version");
         check(!r.err.contains("1.0.700"), "version rota: no se reintenta");
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
      cmd.add("-Dfreeworlds.data=" + data);
      cmd.add("-Dfreeworlds.updateApi=" + api);
      cmd.add("-Dfreeworlds.updateRepo=o/r");
      cmd.add("-Djava.awt.headless=true");
      cmd.add("-jar");
      cmd.add(jar.toString());
      for (String a : args) {
         cmd.add(a);
      }
      ProcessBuilder pb = new ProcessBuilder(cmd);
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      pb.environment().put("FREEWORLDS_GITHUB_TOKEN", "secreto");
      pb.environment().remove("FREEWORLDS_NO_UPDATE");
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
         + "{\"name\":\"FreeWorlds-" + v + "-linux-x64.tar.gz\",\"size\":1,\"url\":\"" + api + "/assets/none\"},"
         + "{\"name\":\"FreeWorlds-" + v + "-portable.zip\",\"size\":" + zip.length + ",\"url\":\"" + api + "/assets/" + id
         + "\",\"digest\":\"sha256:" + sha + "\"}]}";
   }

   /** The launcher's classes (and resources) in a jar that says it is the given version. */
   private static byte[] launcherJar(File classes, String version) throws IOException {
      Manifest m = new Manifest();
      m.getMainAttributes().put(Attributes.Name.MANIFEST_VERSION, "1.0");
      m.getMainAttributes().put(Attributes.Name.MAIN_CLASS, "net.freeworlds.launcher.Launcher");
      m.getMainAttributes().put(Attributes.Name.IMPLEMENTATION_VERSION, version);
      m.getMainAttributes().putValue("FreeWorlds-Update-Repo", "o/r");
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
         jar.putNextEntry(new JarEntry("vacio.txt"));
         jar.closeEntry();
      }
      return bytes.toByteArray();
   }

   /** The portable package's layout: FreeWorlds/lib/*.jar and FreeWorlds/game/assets/WorldsPlayer. */
   private static byte[] portableZip(byte[] launcherJar, boolean evil) throws IOException {
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      try (ZipOutputStream z = new ZipOutputStream(bytes)) {
         put(z, "FreeWorlds/lib/freeworlds-launcher.jar", launcherJar);
         put(z, "FreeWorlds/lib/worldsplayer.jar", emptyJar());
         put(z, "FreeWorlds/game/assets/WorldsPlayer/worlds.ini", "[Gamma]\r\n".getBytes(StandardCharsets.ISO_8859_1));
         if (evil) {
            put(z, "FreeWorlds/../../escapado.txt", new byte[]{1});
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

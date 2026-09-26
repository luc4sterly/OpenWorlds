package net.freeworlds.launcher;

import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileVisitResult;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.SimpleFileVisitor;
import java.nio.file.StandardCopyOption;
import java.nio.file.attribute.BasicFileAttributes;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The user's writable copy of the 2004 install (what run_gamma.sh did in a
 * temp dir on every run, but persistent: worlds.ini keeps the friends list,
 * the remembered login and the settings between sessions).
 *
 * <ul>
 * <li>first run, or a new FreeWorlds version: every template file is copied
 *     except the user's worlds.ini once it exists;</li>
 * <li>every run: files missing from the copy are restored and cachedir/ is
 *     taken again from the template (an orphan cache.open from an unclean
 *     exit makes the client throw the whole index away, as run_gamma.sh
 *     already noted);</li>
 * <li>worlds.ini/worlds.dst point upgradeServer at the local server of this
 *     session and LogFile is emptied so the client's output reaches the
 *     launcher's log (FREEWORLDS_GAMMA_LOG kept it in run_gamma.sh);</li>
 * <li>override.ini [Runtime] WorldServer and worlds.ini [host:port] User0
 *     select a world server, the client's own mechanism
 *     (NetUpdate.&lt;clinit&gt; / LoginWizard), exactly as run_gamma.sh.</li>
 * </ul>
 * The Windows-only parts of the template (bin/: the 2004 JRE and DLLs,
 * lib/: its class libraries, CVS/) are left out of the package: nothing
 * in the client reads them once the bridge replaces gamma.dll.
 */
final class Install {
   private static final String MARKER = ".freeworlds-version";

   private Install() {
   }

   static void prepare(Layout l, Log log) throws IOException {
      Path src = l.template.toPath();
      Path dst = l.workDir.toPath();
      Files.createDirectories(dst);
      Path marker = dst.resolve(MARKER);
      String version = Layout.version() + " " + src.toRealPath();
      boolean refresh = !Files.isRegularFile(marker)
         || !new String(Files.readAllBytes(marker), StandardCharsets.UTF_8).equals(version);
      boolean firstRun = !Files.isRegularFile(dst.resolve("worlds.ini"));
      Layout.deleteTree(dst.resolve("cachedir"));
      int[] copied = {0};
      Files.walkFileTree(src, new SimpleFileVisitor<Path>() {
         @Override
         public FileVisitResult preVisitDirectory(Path dir, BasicFileAttributes attrs) throws IOException {
            String n = dir.getFileName() == null ? "" : dir.getFileName().toString();
            if (dir.equals(src)) {
               return FileVisitResult.CONTINUE;
            }
            if (n.equals("CVS") || dir.getParent().equals(src) && (n.equalsIgnoreCase("bin") || n.equalsIgnoreCase("lib"))) {
               return FileVisitResult.SKIP_SUBTREE;
            }
            Files.createDirectories(dst.resolve(src.relativize(dir).toString()));
            return FileVisitResult.CONTINUE;
         }

         @Override
         public FileVisitResult visitFile(Path file, BasicFileAttributes attrs) throws IOException {
            Path to = dst.resolve(src.relativize(file).toString());
            boolean userState = to.getParent().equals(dst) && to.getFileName().toString().equalsIgnoreCase("worlds.ini") && !firstRun;
            if (!Files.exists(to) || refresh && !userState) {
               Files.copy(file, to, StandardCopyOption.REPLACE_EXISTING, StandardCopyOption.COPY_ATTRIBUTES);
               copied[0]++;
            }
            return FileVisitResult.CONTINUE;
         }
      });
      Files.write(marker, version.getBytes(StandardCharsets.UTF_8));
      if (copied[0] > 0) {
         log.line("[instalacion] " + copied[0] + " ficheros copiados a " + dst + (firstRun ? " (primera vez)" : ""));
      }
   }

   /** Points the copy at this session's local upgrade server and world server choice. */
   static void configure(Layout l, int upgradePort, String worldServer, String user, boolean keepGammaLog, Log log) throws IOException {
      File work = l.workDir;
      for (String f : new String[]{"worlds.ini", "worlds.dst"}) {
         File ini = findNoCase(work, f);
         if (ini != null) {
            setKey(ini, "Gamma", "upgradeServer", "http://127.0.0.1:" + upgradePort + "/3DCDup");
            if (!keepGammaLog && f.equals("worlds.ini")) {
               setKey(ini, "Gamma", "LogFile", "");
            }
         }
      }
      File override = findNoCase(work, "override.ini");
      if (override == null) {
         override = new File(work, "override.ini");
      }
      if (worldServer != null && !worldServer.isEmpty()) {
         setKey(override, "Runtime", "WorldServer", "worldserver://" + worldServer);
         if (user != null && !user.isEmpty()) {
            setKey(new File(work, "worlds.ini"), worldServer, "User0", user);
         }
         log.line("[instalacion] servidor de mundos: worldserver://" + worldServer + (user == null || user.isEmpty() ? "" : " (usuario " + user + ")"));
      } else if (override.isFile()) {
         removeKey(override, "Runtime", "WorldServer");
      }
   }

   /**
    * The upgrade server of the 2004 install ([Gamma] upgradeServer of the
    * template's worlds.ini: http://us1.worlds.net/3DCDup, today LibreWorlds'
    * mirror), without a trailing slash; null if there is none.
    */
   static String mirrorOf(Layout l) {
      String forced = System.getProperty("freeworlds.mirror");
      if (forced != null) {
         return forced.isEmpty() ? null : trimSlash(forced);
      }
      File ini = findNoCase(l.template, "worlds.ini");
      if (ini == null) {
         return null;
      }
      try {
         String v = getKey(ini, "Gamma", "upgradeServer");
         return v == null || v.isEmpty() ? null : trimSlash(v);
      } catch (IOException e) {
         return null;
      }
   }

   private static String trimSlash(String s) {
      return s.endsWith("/") ? s.substring(0, s.length() - 1) : s;
   }

   /** GetPrivateProfileString: first section with the name, key without case; null if missing. */
   static String getKey(File ini, String section, String key) throws IOException {
      boolean inSec = false;
      for (String ln : read(ini)) {
         Matcher m = SECTION.matcher(ln);
         if (m.matches()) {
            inSec = m.group(1).trim().equalsIgnoreCase(section);
         } else if (inSec && isKey(ln, key)) {
            return ln.substring(ln.indexOf('=') + 1).trim();
         }
      }
      return null;
   }

   static File findNoCase(File dir, String name) {
      File exact = new File(dir, name);
      if (exact.exists()) {
         return exact;
      }
      String[] names = dir.list();
      if (names != null) {
         for (String n : names) {
            if (n.equalsIgnoreCase(name)) {
               return new File(dir, n);
            }
         }
      }
      return null;
   }

   private static final Pattern SECTION = Pattern.compile("\\s*\\[(.*)\\]\\s*");

   /**
    * Like WritePrivateProfileString (and run_gamma.sh's set_key): section and
    * key without case, the value replaced in place or appended at the end of
    * its section, the section created at the end; CRLF kept.
    */
   static void setKey(File ini, String section, String key, String value) throws IOException {
      List<String> lines = read(ini);
      List<String> out = new ArrayList<>();
      boolean inSec = false, foundSec = false, done = false;
      for (String ln : lines) {
         Matcher m = SECTION.matcher(ln);
         if (m.matches()) {
            if (inSec && !done) {
               out.add(key + "=" + value);
               done = true;
            }
            inSec = m.group(1).trim().equalsIgnoreCase(section);
            foundSec |= inSec;
         } else if (inSec && isKey(ln, key)) {
            if (!done) {
               out.add(key + "=" + value);
               done = true;
            }
            continue;
         }
         out.add(ln);
      }
      if (!done) {
         if (!foundSec) {
            out.add("[" + section + "]");
         }
         out.add(key + "=" + value);
      }
      write(ini, out);
   }

   static void removeKey(File ini, String section, String key) throws IOException {
      List<String> lines = read(ini);
      List<String> out = new ArrayList<>();
      boolean inSec = false, changed = false;
      for (String ln : lines) {
         Matcher m = SECTION.matcher(ln);
         if (m.matches()) {
            inSec = m.group(1).trim().equalsIgnoreCase(section);
         } else if (inSec && isKey(ln, key)) {
            changed = true;
            continue;
         }
         out.add(ln);
      }
      if (changed) {
         write(ini, out);
      }
   }

   private static boolean isKey(String line, String key) {
      int eq = line.indexOf('=');
      return eq > 0 && line.substring(0, eq).trim().toLowerCase(Locale.ROOT).equals(key.toLowerCase(Locale.ROOT));
   }

   private static List<String> read(File ini) throws IOException {
      List<String> lines = new ArrayList<>();
      if (!ini.isFile()) {
         return lines;
      }
      String text = new String(Files.readAllBytes(ini.toPath()), StandardCharsets.ISO_8859_1);
      for (String s : text.split("\r?\n", -1)) {
         lines.add(s);
      }
      if (!lines.isEmpty() && lines.get(lines.size() - 1).isEmpty()) {
         lines.remove(lines.size() - 1);
      }
      return lines;
   }

   private static void write(File ini, List<String> lines) throws IOException {
      StringBuilder sb = new StringBuilder();
      for (String s : lines) {
         sb.append(s).append("\r\n");
      }
      Files.write(ini.toPath(), sb.toString().getBytes(StandardCharsets.ISO_8859_1));
   }

   /** The .world files of the copy, as the client's home: URLs (GroundZero first). */
   /**
    * Worlds to offer, {label, home: URL}: GroundZero, the other .world files
    * at the top of the install, and the places of GroundZero's map
    * (GroundZero/groundzero-map.inf: "x y w h Name -URL" after the count),
    * which the client downloads from the upgrade server the first time.
    */
   static List<String[]> worlds(Layout l) {
      List<String[]> out = new ArrayList<>();
      out.add(new String[]{"GroundZero", "home:GroundZero/groundzero.world"});
      File[] top = l.template.listFiles();
      if (top != null) {
         java.util.Arrays.sort(top);
         for (File f : top) {
            String n = f.getName();
            if (f.isFile() && n.toLowerCase(Locale.ROOT).endsWith(".world") && !n.equalsIgnoreCase("ad.world")) {
               out.add(new String[]{n.substring(0, n.length() - 6), "home:" + n});
            }
         }
      }
      File gz = findNoCase(l.template, "GroundZero");
      File inf = gz == null ? null : findNoCase(gz, "groundzero-map.inf");
      if (inf != null) {
         try {
            for (String ln : read(inf)) {
               String[] f = ln.trim().split("\\s+");
               if (f.length >= 6 && f[5].startsWith("-home:")) {
                  String url = f[5].substring(1);
                  String pkg = url.substring(5).replaceFirst("^/", "");
                  pkg = pkg.contains("/") ? pkg.substring(0, pkg.indexOf('/')) : pkg;
                  boolean installed = new File(new File(l.workDir, pkg), "ver.txt").isFile()
                     || new File(new File(l.template, pkg), "ver.txt").isFile();
                  out.add(new String[]{f[4].replace('_', ' ') + (installed ? "" : "  (se descarga la primera vez)"), url});
               }
            }
         } catch (IOException e) {
            // sin mapa: solo los mundos de la instalacion
         }
      }
      return out;
   }
}

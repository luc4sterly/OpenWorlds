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
   static List<String> worlds(Layout l) {
      List<String> out = new ArrayList<>();
      out.add("home:GroundZero/groundzero.world");
      File[] top = l.template.listFiles();
      if (top != null) {
         java.util.Arrays.sort(top);
         for (File f : top) {
            if (f.isFile() && f.getName().toLowerCase(Locale.ROOT).endsWith(".world") && !f.getName().equalsIgnoreCase("ad.world")) {
               out.add("home:" + f.getName());
            }
         }
      }
      return out;
   }
}

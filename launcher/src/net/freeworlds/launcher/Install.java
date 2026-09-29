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
import java.util.Properties;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * The user's writable copy of the 2004 install (what run_gamma.sh did in a
 * temp dir on every run, but persistent: worlds.ini keeps the friends list,
 * the remembered login and the settings between sessions).
 *
 * <ul>
 * <li>every run: files missing from the copy are restored and cachedir/ is
 *     taken again from the template (an orphan cache.open from an unclean
 *     exit makes the client throw the whole index away, as run_gamma.sh
 *     already noted);</li>
 * <li>a template file that changed (a new FreeWorlds version) replaces the
 *     copy's only if the copy is still as the launcher left it: the
 *     manifest ({@value #MANIFEST}) keeps, per file, the template's and the
 *     copy's size and date when it was copied. A file the client or gdkup
 *     changed since (an upgraded GroundZero, worlds.dst, a world's files) is
 *     marked as the game's and never overwritten again; the user's
 *     worlds.ini is not even compared;</li>
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
   /** Version and template of the last preparation (for diagnosis only). */
   private static final String MARKER = ".freeworlds-version";
   static final String MANIFEST = ".freeworlds-manifest";
   /** Manifest mark of a file the game changed: it is never overwritten again. */
   private static final String GAME = "juego";

   private Install() {
   }

   static void prepare(Layout l, Log log) throws IOException {
      Path src = l.template.toPath();
      Path dst = l.workDir.toPath();
      Files.createDirectories(dst);
      boolean firstRun = !Files.isRegularFile(dst.resolve("worlds.ini"));
      Properties manifest = new Properties();
      Path manifestFile = dst.resolve(MANIFEST);
      if (Files.isRegularFile(manifestFile)) {
         try (java.io.InputStream in = Files.newInputStream(manifestFile)) {
            manifest.load(in);
         }
      }
      Layout.deleteTree(dst.resolve("cachedir"));
      int[] copied = {0};
      int[] kept = {0};
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
            String rel = src.relativize(file).toString().replace(File.separatorChar, '/');
            Path to = dst.resolve(src.relativize(file).toString());
            String template = stamp(attrs.size(), attrs.lastModifiedTime().toMillis());
            if (!Files.exists(to)) {
               copy(file, to, rel, template);
               return FileVisitResult.CONTINUE;
            }
            if (!firstRun && rel.equalsIgnoreCase("worlds.ini")) {
               return FileVisitResult.CONTINUE;
            }
            String copy = stamp(Files.size(to), Files.getLastModifiedTime(to).toMillis());
            String entry = manifest.getProperty(rel);
            if (entry == null) {
               // copia de un lanzador anterior al manifiesto: si es igual a la
               // plantilla se apunta; si no, no se sabe quien la cambio y se respeta
               if (copy.equals(template)) {
                  manifest.setProperty(rel, template + "|" + copy);
               } else {
                  manifest.setProperty(rel, GAME + "|" + copy);
                  kept[0]++;
               }
               return FileVisitResult.CONTINUE;
            }
            int bar = entry.indexOf('|');
            String wasTemplate = bar < 0 ? entry : entry.substring(0, bar);
            String wasCopy = bar < 0 ? entry : entry.substring(bar + 1);
            if (wasTemplate.equals(GAME)) {
               return FileVisitResult.CONTINUE;
            }
            if (!copy.equals(wasCopy)) {
               // la cambio el cliente o gdkup: desde ahora es suya
               manifest.setProperty(rel, GAME + "|" + copy);
               kept[0]++;
            } else if (!template.equals(wasTemplate)) {
               copy(file, to, rel, template); // plantilla nueva y copia intacta
            }
            return FileVisitResult.CONTINUE;
         }

         private void copy(Path file, Path to, String rel, String template) throws IOException {
            Files.copy(file, to, StandardCopyOption.REPLACE_EXISTING, StandardCopyOption.COPY_ATTRIBUTES);
            manifest.setProperty(rel, template + "|" + stamp(Files.size(to), Files.getLastModifiedTime(to).toMillis()));
            copied[0]++;
         }
      });
      Path tmp = dst.resolve(MANIFEST + ".tmp");
      try (java.io.OutputStream out = Files.newOutputStream(tmp)) {
         manifest.store(out, "FreeWorlds: tamano:fecha de la plantilla|de la copia al copiarla (Install.prepare)");
      }
      Files.move(tmp, manifestFile, StandardCopyOption.REPLACE_EXISTING);
      Files.write(dst.resolve(MARKER), (Layout.versionLong() + " " + src.toRealPath()).getBytes(StandardCharsets.UTF_8));
      int restored = copied[0];
      if (restored > 0 || kept[0] > 0) {
         log.line("[instalacion] " + restored + " ficheros copiados a " + dst + (firstRun ? " (primera vez)" : "")
            + (kept[0] > 0 ? "; " + kept[0] + " cambiados por el juego se respetan desde ahora" : ""));
      }
   }

   private static String stamp(long size, long millis) {
      return size + ":" + millis;
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
      seedWindow(findNoCase(work, "worlds.ini"), log);
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
    * The game window's first size. GammaFrameState keeps the window in
    * worlds.ini [Gamma] Window&lt;W&gt;X&lt;H&gt; ("x y width height state", per screen
    * size of Toolkit.getScreenSize) and without that key opens it at 568x424,
    * the size of 2004: tiny on today's screens. The first time on each screen
    * size the launcher writes one two thirds of the screen high, with the same
    * proportions and centred; from then on the client saves the player's own
    * (GammaFrameState.saveBorder, when it quits). A bigger window is more
    * pixels for the software rasterizer, hence not the whole screen.
    */
   static void seedWindow(File ini, Log log) {
      if (ini == null || java.awt.GraphicsEnvironment.isHeadless()) {
         return;
      }
      try {
         java.awt.Dimension screen = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
         String key = "Window" + screen.width + "X" + screen.height;
         if (getKey(ini, "Gamma", key) != null) {
            return;
         }
         int h = screen.height * 2 / 3;
         int w = h * 568 / 424;
         if (w > screen.width * 9 / 10) {
            w = screen.width * 9 / 10;
            h = w * 424 / 568;
         }
         if (w <= 568 || h <= 424) {
            return; // pantalla pequena: el tamano de 2004 ya cabe justo
         }
         setKey(ini, "Gamma", key, (screen.width - w) / 2 + " " + (screen.height - h) / 2 + " " + w + " " + h + " 0");
         log.line("[instalacion] ventana del juego de " + w + "x" + h + " para la pantalla de " + screen.width + "x" + screen.height);
      } catch (IOException | RuntimeException | Error e) {
         // sin pantalla o sin worlds.ini escribible: el cliente usa su 568x424
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

   /** A place the launcher offers: a name, the client's home: URL and whether the copy already has it. */
   static final class World {
      final String name;
      final String url;
      final boolean installed;

      World(String name, String url, boolean installed) {
         this.name = name;
         this.url = url;
         this.installed = installed;
      }
   }

   /**
    * Worlds to offer: GroundZero, the other .world files at the top of the
    * install, the places of GroundZero's map (GroundZero/groundzero-map.inf:
    * "x y w h Name -URL" after the count), which the client downloads from the
    * upgrade server the first time, and the worlds installed later from the
    * universe map or Teleport ([InstalledWorlds] of the copy's worlds.ini),
    * one entry per .world file of their folder.
    */
   static List<World> worlds(Layout l) {
      List<World> out = new ArrayList<>();
      java.util.Set<String> folders = new java.util.HashSet<>();
      out.add(new World("GroundZero", "home:GroundZero/groundzero.world", true));
      folders.add("groundzero");
      File[] top = l.template.listFiles();
      if (top != null) {
         java.util.Arrays.sort(top);
         for (File f : top) {
            String n = f.getName();
            // ad.world es el marco de anuncios y NewWorld.world la plantilla
            // vacia del editor (Shaper, y el ultimo recurso de TeleportAction)
            if (f.isFile() && n.toLowerCase(Locale.ROOT).endsWith(".world") && !n.equalsIgnoreCase("ad.world")
               && !n.equalsIgnoreCase("NewWorld.world")) {
               out.add(new World(n.substring(0, n.length() - 6), "home:" + n, true));
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
                  folders.add(pkg.toLowerCase(Locale.ROOT));
                  out.add(new World(f[4].replace('_', ' '), url, installed(l, pkg)));
               }
            }
         } catch (IOException e) {
            // sin mapa: solo los mundos de la instalacion
         }
      }
      File ini = findNoCase(l.workDir, "worlds.ini");
      if (ini != null) {
         try {
            int max = parseInt(getKey(ini, "InstalledWorlds", "MaxInstalledWorlds"));
            // algun instalador apunta su mundo sin subir MaxInstalledWorlds
            // (Chaos14, docs/pruebas-juego.md): se miran unos cuantos de mas
            for (int i = 0; i <= Math.max(max, 0) + 8; i++) {
               String pkg = getKey(ini, "InstalledWorlds", "InstalledWorld" + i);
               if (pkg == null || pkg.isEmpty() || !folders.add(pkg.toLowerCase(Locale.ROOT))) {
                  continue;
               }
               File dir = findNoCase(l.workDir, pkg);
               File[] ws = dir == null ? null : dir.listFiles((d, n) -> n.toLowerCase(Locale.ROOT).endsWith(".world"));
               if (ws == null || ws.length == 0) {
                  continue;
               }
               java.util.Arrays.sort(ws);
               for (File w : ws) {
                  String base = w.getName().substring(0, w.getName().length() - 6);
                  out.add(new World(ws.length == 1 ? dir.getName() : dir.getName() + " · " + base,
                     "home:" + dir.getName() + "/" + w.getName(), true));
               }
            }
         } catch (IOException e) {
            // worlds.ini ilegible: la lista se queda con lo de arriba
         }
      }
      return out;
   }

   /** A world package is installed when its folder (any case) has its ver.txt, in the copy or in the template. */
   static boolean installed(Layout l, String pkg) {
      for (File base : new File[]{l.workDir, l.template}) {
         File dir = findNoCase(base, pkg);
         if (dir != null && dir.isDirectory() && findNoCase(dir, "ver.txt") != null) {
            return true;
         }
      }
      return false;
   }

   private static int parseInt(String s) {
      try {
         return s == null ? 0 : Integer.parseInt(s.trim());
      } catch (NumberFormatException e) {
         return 0;
      }
   }
}

package net.openworlds.launcher;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.nio.file.AtomicMoveNotSupportedException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Enumeration;
import java.util.Locale;
import java.util.Map;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.jar.JarFile;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * Automatic updates from the project's GitHub releases.
 *
 * <p>The CI publishes a release for every push to main (tag
 * {@code v1.0.<commits>}, see .github/workflows/build.yml) with the portable
 * package among its assets. That zip runs on any Java 17+, the one inside the
 * app included, so an update is always the same: the portable package is
 * downloaded, checked against the release's SHA-256 and unpacked in the data
 * folder ({@code app/<version>/}; {@code app/current} names it). The
 * installed app is never rewritten (no admin rights, no files in use on
 * Windows, the macOS bundle keeps its signature): on the next start
 * {@link Bootstrap} finds the newer version and runs it instead of the
 * bundled one, on the same Java. Updating the app itself (its Java) is a
 * matter of downloading it again.
 *
 * <p>The repository is public, so no token is needed; one (the githubToken
 * setting, or OPENWORLDS_GITHUB_TOKEN) only raises GitHub's rate limit, and
 * is what a private fork would need (without it GitHub answers 404, as if
 * there were no releases).
 */
final class Updater {
   static final String DEFAULT_REPO = "luc4sterly/OpenWorlds";
   /** GitHub's API; -Dopenworlds.updateApi points elsewhere (the tests' fake GitHub). */
   private static final String API = System.getProperty("openworlds.updateApi", "https://api.github.com");
   /** Automatic checks at most this often (GitHub allows 60 anonymous calls an hour per address). */
   private static final long THROTTLE_MS = 10 * 60 * 1000L;

   enum Phase { DISABLED, IDLE, CHECKING, UP_TO_DATE, DOWNLOADING, READY, FAILED }

   /** What the updater is doing, for the window, the terminal menu and --update. */
   static final class Status {
      final Phase phase;
      /** Version on offer (DOWNLOADING, READY), or null. */
      final String version;
      final int percent;
      final String detail;

      Status(Phase phase, String version, int percent, String detail) {
         this.phase = phase;
         this.version = version;
         this.percent = percent;
         this.detail = detail;
      }
   }

   interface Listener {
      void changed(Status s);
   }

   /** A release worth installing: its version and the assets we need. */
   static final class Release {
      final Version version;
      final String page;
      final Map<String, Object> zip;
      final Map<String, Object> sums;

      Release(Version version, String page, Map<String, Object> zip, Map<String, Object> sums) {
         this.version = version;
         this.page = page;
         this.zip = zip;
         this.sums = sums;
      }
   }

   private final Layout layout;
   private final Settings settings;
   private final CopyOnWriteArrayList<Listener> listeners = new CopyOnWriteArrayList<>();
   private final AtomicBoolean busy = new AtomicBoolean();
   private volatile Status status;

   Updater(Layout layout, Settings settings) {
      this.layout = layout;
      this.settings = settings;
      String why = disabledReason();
      status = why != null ? new Status(Phase.DISABLED, null, 0, why) : new Status(Phase.IDLE, null, 0, "");
   }

   Status status() {
      return status;
   }

   void addListener(Listener l) {
      listeners.add(l);
      l.changed(status);
   }

   void removeListener(Listener l) {
      listeners.remove(l);
   }

   private void set(Status s) {
      status = s;
      for (Listener l : listeners) {
         l.changed(s);
      }
   }

   /** The running launcher's version, or null for a development build (then nothing is updated). */
   static Version running() {
      return Version.parse(Layout.version());
   }

   private static String disabledReason() {
      if (running() == null) {
         return "development build (" + Layout.version() + "): no updates";
      }
      if (Boolean.getBoolean("openworlds.noUpdate") || !env("OPENWORLDS_NO_UPDATE").isEmpty()) {
         return "updates turned off (OPENWORLDS_NO_UPDATE)";
      }
      return null;
   }

   String repo() {
      String forced = System.getProperty("openworlds.updateRepo");
      if (forced != null && !forced.trim().isEmpty()) {
         return forced.trim();
      }
      if (!settings.updateRepo.trim().isEmpty()) {
         return settings.updateRepo.trim();
      }
      String baked = Layout.manifestAttribute("OpenWorlds-Update-Repo");
      return baked == null || baked.trim().isEmpty() ? DEFAULT_REPO : baked.trim();
   }

   private String token() {
      String t = env("OPENWORLDS_GITHUB_TOKEN");
      return t.isEmpty() ? settings.githubToken.trim() : t;
   }

   private static String env(String name) {
      String v = System.getenv(name);
      return v == null ? "" : v.trim();
   }

   /** Checks (and downloads) in the background, unless disabled or already under way. */
   void checkInBackground(boolean manual) {
      if (status.phase == Phase.DISABLED || busy.get()) {
         return;
      }
      Thread t = new Thread(() -> checkNow(manual), "openworlds-updater");
      t.setDaemon(true);
      t.start();
   }

   /**
    * Looks for a newer release and installs it; returns how it ended. Automatic
    * checks (manual = false) skip the network if the last one was recent.
    */
   Status checkNow(boolean manual) {
      if (status.phase == Phase.DISABLED) {
         return status;
      }
      if (!busy.compareAndSet(false, true)) {
         return status;
      }
      try {
         Version own = running();
         File root = appRoot(layout);
         prune(root, own);
         Version ready = installed(root);
         if (ready != null && ready.compareTo(own) > 0 && !Bootstrap.isBad(root, ready)) {
            set(new Status(Phase.READY, ready.text, 100, "downloaded; used after a restart"));
         }
         long now = System.currentTimeMillis();
         if (!manual && now - settings.lastUpdateCheck < THROTTLE_MS && now >= settings.lastUpdateCheck) {
            if (status.phase != Phase.READY) {
               set(new Status(Phase.UP_TO_DATE, null, 0, "comprobado hace poco"));
            }
            return status;
         }
         set(new Status(Phase.CHECKING, null, 0, "buscando en " + repo()));
         Release r = latest(settings.prerelease);
         settings.lastUpdateCheck = now;
         settings.save(layout.settingsFile);
         Version have = ready != null && ready.compareTo(own) > 0 ? ready : own;
         if (r == null || r.version.compareTo(have) <= 0) {
            if (have == own) {
               set(new Status(Phase.UP_TO_DATE, null, 0, r == null ? "no published versions" : "latest: " + r.version));
            } else {
               set(new Status(Phase.READY, have.text, 100, "downloaded; used after a restart"));
            }
            return status;
         }
         File zip = download(r, root);
         install(zip, r.version, root);
         set(new Status(Phase.READY, r.version.text, 100, "downloaded; used after a restart"));
         return status;
      } catch (IOException | RuntimeException e) {
         set(new Status(Phase.FAILED, null, 0, message(e)));
         return status;
      } finally {
         busy.set(false);
      }
   }

   private static String message(Exception e) {
      String m = e.getMessage();
      if (e instanceof java.net.UnknownHostException) {
         return "no connection to GitHub";
      }
      if (e instanceof java.net.SocketTimeoutException) {
         return "GitHub does not answer";
      }
      return m == null || m.isEmpty() ? e.toString() : m;
   }

   // ------------------------------------------------------------- GitHub

   /** The newest non-draft release with a portable package, or null. */
   Release latest(boolean includePre) throws IOException {
      String body = new String(get(API + "/repos/" + repo() + "/releases?per_page=30", "application/vnd.github+json"),
         StandardCharsets.UTF_8);
      Release best = null;
      for (Object o : Json.array(Json.parse(body))) {
         Map<String, Object> r = Json.object(o);
         Version v = Version.parse(Json.string(r, "tag_name"));
         if (v == null || Json.bool(r, "draft") || (!includePre && (Json.bool(r, "prerelease") || v.isPrerelease()))) {
            continue;
         }
         Map<String, Object> zip = null;
         Map<String, Object> sums = null;
         for (Object ao : Json.array(r.get("assets"))) {
            Map<String, Object> a = Json.object(ao);
            String name = Json.string(a, "name");
            if (name == null) {
               continue;
            }
            if (name.startsWith("OpenWorlds-") && name.endsWith("-portable.zip")) {
               zip = a; // not J Solar Server's, which comes in the same release
            } else if (name.equalsIgnoreCase("SHA256SUMS.txt") || name.equalsIgnoreCase("SHA256SUMS")) {
               sums = a;
            }
         }
         if (zip != null && (best == null || v.compareTo(best.version) > 0)) {
            best = new Release(v, Json.string(r, "html_url"), zip, sums);
         }
      }
      return best;
   }

   private File download(Release r, File root) throws IOException {
      String name = Json.string(r.zip, "name");
      File dir = new File(root, "download");
      Files.createDirectories(dir.toPath());
      File part = new File(dir, name + ".part");
      File done = new File(dir, name);
      long size = Json.number(r.zip, "size");
      MessageDigest sha = sha256();
      set(new Status(Phase.DOWNLOADING, r.version.text, 0, name));
      HttpURLConnection c = open(assetUrl(r.zip), "application/octet-stream");
      long total = c.getContentLengthLong() > 0 ? c.getContentLengthLong() : size;
      try (InputStream in = c.getInputStream(); OutputStream out = new FileOutputStream(part)) {
         byte[] buf = new byte[64 * 1024];
         long got = 0;
         int last = -1;
         for (int n; (n = in.read(buf)) > 0; ) {
            out.write(buf, 0, n);
            sha.update(buf, 0, n);
            got += n;
            int pct = total > 0 ? (int) Math.min(99, got * 100 / total) : 0;
            if (pct != last) {
               last = pct;
               set(new Status(Phase.DOWNLOADING, r.version.text, pct, name));
            }
         }
      } finally {
         c.disconnect();
      }
      String actual = hex(sha.digest());
      String expected = expectedSha(r, name);
      if (expected != null && !expected.equalsIgnoreCase(actual)) {
         Files.deleteIfExists(part.toPath());
         throw new IOException("the download of " + name + " does not match its SHA-256 (discarded)");
      }
      Files.move(part.toPath(), done.toPath(), StandardCopyOption.REPLACE_EXISTING);
      return done;
   }

   /** SHA-256 of the asset: GitHub's own digest field, else the release's SHA256SUMS; null if neither. */
   private String expectedSha(Release r, String name) throws IOException {
      String digest = Json.string(r.zip, "digest");
      if (digest != null && digest.toLowerCase(Locale.ROOT).startsWith("sha256:")) {
         return digest.substring(7).trim();
      }
      if (r.sums == null) {
         return null;
      }
      String text = new String(get(assetUrl(r.sums), "application/octet-stream"), StandardCharsets.UTF_8);
      for (String line : text.split("\r?\n")) {
         String[] f = line.trim().split("\\s+", 2);
         if (f.length == 2 && f[1].replaceFirst("^\\*", "").trim().equals(name)) {
            return f[0];
         }
      }
      return null;
   }

   private static String assetUrl(Map<String, Object> asset) {
      String api = Json.string(asset, "url");
      return api != null ? api : Json.string(asset, "browser_download_url");
   }

   private byte[] get(String url, String accept) throws IOException {
      HttpURLConnection c = open(url, accept);
      try (InputStream in = c.getInputStream()) {
         return in.readAllBytes();
      } finally {
         c.disconnect();
      }
   }

   /**
    * GET with GitHub's headers. Redirects are followed by hand so the token
    * only ever goes to the API's host (the asset download is redirected to a
    * signed URL on another host, which must not receive it).
    */
   private HttpURLConnection open(String url, String accept) throws IOException {
      String token = token();
      String current = url;
      for (int hop = 0; hop < 6; hop++) {
         URL u = URI.create(current).toURL();
         HttpURLConnection c = (HttpURLConnection) u.openConnection();
         c.setInstanceFollowRedirects(false);
         c.setConnectTimeout(10000);
         c.setReadTimeout(30000);
         c.setRequestProperty("Accept", accept);
         c.setRequestProperty("User-Agent", "OpenWorlds/" + Layout.version());
         boolean github = URI.create(API).getHost().equalsIgnoreCase(u.getHost());
         if (github) {
            c.setRequestProperty("X-GitHub-Api-Version", "2022-11-28");
            if (!token.isEmpty()) {
               c.setRequestProperty("Authorization", "Bearer " + token);
            }
         }
         int code = c.getResponseCode();
         if (code == 301 || code == 302 || code == 303 || code == 307 || code == 308) {
            String loc = c.getHeaderField("Location");
            c.disconnect();
            if (loc == null) {
               throw new IOException("redirect without a target from " + u.getHost());
            }
            current = URI.create(u.toString()).resolve(loc).toString();
            continue;
         }
         if (code == 200) {
            return c;
         }
         String remaining = c.getHeaderField("X-RateLimit-Remaining");
         c.disconnect();
         if (github && (code == 403 || code == 429) && "0".equals(remaining)) {
            throw new IOException("GitHub rate limit reached; will retry later");
         }
         if (github && code == 401) {
            throw new IOException("GitHub does not accept the token in settings.properties");
         }
         if (github && code == 404) {
            throw new IOException(token.isEmpty() ? "no published versions can be seen"
               : "no published versions can be seen with that token");
         }
         throw new IOException("HTTP " + code + " from " + u.getHost());
      }
      throw new IOException("demasiadas redirecciones");
   }

   // ------------------------------------------------------------ install

   static File appRoot(Layout l) {
      return new File(l.dataDir, "app");
   }

   /** The version app/current names, or null. */
   static Version installed(File root) {
      try {
         Path p = new File(root, "current").toPath();
         return Files.isRegularFile(p) ? Version.parse(new String(Files.readAllBytes(p), StandardCharsets.UTF_8).trim()) : null;
      } catch (IOException e) {
         return null;
      }
   }

   /** Unpacks the portable package into app/&lt;version&gt;, checks it and makes it current. */
   static void install(File zip, Version v, File root) throws IOException {
      File staging = new File(root, ".staging");
      Layout.deleteTree(staging.toPath());
      Files.createDirectories(staging.toPath());
      Path base = staging.toPath().toAbsolutePath().normalize();
      try (ZipFile z = new ZipFile(zip)) {
         Enumeration<? extends ZipEntry> en = z.entries();
         while (en.hasMoreElements()) {
            ZipEntry e = en.nextElement();
            Path to = base.resolve(e.getName()).normalize();
            if (!to.startsWith(base)) {
               throw new IOException("entry outside the package: " + e.getName());
            }
            if (e.isDirectory()) {
               Files.createDirectories(to);
            } else {
               Files.createDirectories(to.getParent());
               try (InputStream in = z.getInputStream(e)) {
                  Files.copy(in, to, StandardCopyOption.REPLACE_EXISTING);
               }
            }
         }
      }
      File pkg = new File(staging, "OpenWorlds");
      File jar = new File(pkg, "lib/openworlds-launcher.jar");
      if (!jar.isFile() || !new File(pkg, "lib/worldsplayer.jar").isFile()
         || !new File(pkg, "game/assets/WorldsPlayer/worlds.ini").isFile()) {
         throw new IOException("the downloaded package is incomplete");
      }
      String inside;
      try (JarFile j = new JarFile(jar)) {
         inside = j.getManifest() == null ? null : j.getManifest().getMainAttributes().getValue("Implementation-Version");
      }
      Version iv = Version.parse(inside);
      if (iv == null || iv.compareTo(v) != 0) {
         throw new IOException("the package says it is version " + inside + ", not " + v);
      }
      File dest = new File(root, v.text);
      Layout.deleteTree(dest.toPath());
      move(pkg.toPath(), dest.toPath());
      Files.write(new File(dest, ".complete").toPath(), v.text.getBytes(StandardCharsets.UTF_8));
      File tmp = new File(root, "current.tmp");
      Files.write(tmp.toPath(), v.text.getBytes(StandardCharsets.UTF_8));
      move(tmp.toPath(), new File(root, "current").toPath());
      Layout.deleteTree(staging.toPath());
      Files.deleteIfExists(zip.toPath());
   }

   private static void move(Path from, Path to) throws IOException {
      try {
         Files.move(from, to, StandardCopyOption.ATOMIC_MOVE, StandardCopyOption.REPLACE_EXISTING);
      } catch (AtomicMoveNotSupportedException e) {
         Files.move(from, to, StandardCopyOption.REPLACE_EXISTING);
      }
   }

   /**
    * Removes what is no longer used: versions other than the current one and
    * the running one, the current one too once the bundled app is as new,
    * and leftovers of an interrupted download. Failures are left for next
    * time (on Windows a jar in use cannot be deleted).
    */
   void prune(File root, Version own) {
      File[] all = root.listFiles();
      if (all == null) {
         return;
      }
      Version cur = installed(root);
      if (cur != null && cur.compareTo(own) <= 0 && !isRunningFrom(root, cur.text)) {
         new File(root, "current").delete();
         cur = null;
      }
      for (File d : all) {
         String n = d.getName();
         if (!d.isDirectory() || isRunningFrom(root, n) || cur != null && n.equals(cur.text)) {
            continue;
         }
         if (Version.parse(n) != null || n.equals(".staging") || n.equals("download")) {
            try {
               Layout.deleteTree(d.toPath());
            } catch (IOException e) {
               // retried on the next check
            }
         }
      }
   }

   private boolean isRunningFrom(File root, String name) {
      File lib = layout.libDir;
      File dir = lib.getParentFile();
      return dir != null && dir.getName().equals(name) && root.getAbsoluteFile().equals(dir.getParentFile().getAbsoluteFile());
   }

   private static MessageDigest sha256() {
      try {
         return MessageDigest.getInstance("SHA-256");
      } catch (NoSuchAlgorithmException e) {
         throw new IllegalStateException(e);
      }
   }

   static String hex(byte[] b) {
      StringBuilder sb = new StringBuilder(b.length * 2);
      for (byte x : b) {
         sb.append(Character.forDigit((x >> 4) & 15, 16)).append(Character.forDigit(x & 15, 16));
      }
      return sb.toString();
   }

   /** For --update: waits for the check and prints each step. */
   static int runFromCli(Layout layout, Settings settings) {
      Updater u = new Updater(layout, settings);
      int[] lastPct = {-10};
      u.addListener(s -> {
         if (s.phase == Phase.DOWNLOADING) {
            if (s.percent - lastPct[0] >= 10 || s.percent == 0) {
               lastPct[0] = s.percent;
               System.out.println("[update] downloading " + s.version + ": " + s.percent + "%");
            }
         } else if (s.phase != Phase.IDLE) {
            System.out.println("[update] " + describe(s));
         }
      });
      Status end = u.checkNow(true);
      return end.phase == Phase.FAILED ? 1 : 0;
   }

   /** One line for a status, in the words the window uses. */
   static String describe(Status s) {
      switch (s.phase) {
         case DISABLED:
            return s.detail;
         case CHECKING:
            return "Checking for updates…";
         case UP_TO_DATE:
            return "Up to date" + (s.detail.isEmpty() ? "" : " (" + s.detail + ")");
         case DOWNLOADING:
            return "Downloading version " + s.version + "… " + s.percent + "%";
         case READY:
            return "Version " + s.version + " is ready: used after restarting OpenWorlds";
         case FAILED:
            return "Could not update: " + s.detail;
         default:
            return "";
      }
   }
}

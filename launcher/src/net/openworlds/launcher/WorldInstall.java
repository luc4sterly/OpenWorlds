package net.openworlds.launcher;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Installs a world from the mirror before the game starts, the way the 2004
 * client's own "download this world" does (NetUpdate.listWorldUpgrades), but
 * without its detour through GroundZero and a restart: the world's
 * upgrades.lst on the upgrade server names the full installer for a world
 * that is not installed yet ("-1 25#511534:1692": from nothing to version 25,
 * that many bytes, for clients from build 1692 on), the installer is
 * &lt;World&gt;/&lt;World&gt;N.exe, and gdkup (NET.worlds.core.GdkUp, the
 * bridge's translation) installs it into the game copy.
 */
final class WorldInstall {
   /** The client's build (Std.getVersion of the 2004 client) for the ":minimum" of upgrades.lst. */
   private static final int CLIENT_BUILD = 1920;

   interface Progress {
      void step(String text, int percent);
   }

   private WorldInstall() {
   }

   /** Downloads and installs world package {@code pkg} (a folder name such as "Meteor"); throws with a message for the player. */
   static void install(Layout l, String pkg, String mirror, Log log, Progress progress) throws IOException, InterruptedException {
      if (mirror == null || mirror.isEmpty()) {
         throw new IOException(pkg + " is not installed, and downloading worlds is turned off (Settings).");
      }
      progress.step("Looking for " + pkg + "…", 0);
      String list = fetchText(mirror + "/" + pkg + "/upgrades.lst");
      int version = latestFull(list);
      if (version < 0) {
         throw new IOException("The mirror has no installer for " + pkg + ".");
      }
      String name = pkg + version + ".exe";
      File dir = new File(l.workDir, pkg);
      dir.mkdirs();
      File target = new File(dir, name);
      log.line("[launcher] installing " + pkg + " " + version + " from " + mirror);
      download(mirror + "/" + pkg + "/" + name, target, pct -> progress.step("Downloading " + pkg + "… " + pct + "%", pct));
      progress.step("Installing " + pkg + "…", 100);
      File script = new File(l.workDir, "openworlds-install.lst");
      Files.write(script.toPath(), (pkg + "\\" + name + "\r\n").getBytes(StandardCharsets.ISO_8859_1));
      List<String> cmd = new ArrayList<>();
      cmd.add(Layout.javaExecutable());
      cmd.add("-cp");
      cmd.add(l.jar("worldsplayer.jar").getPath());
      cmd.add("NET.worlds.core.GdkUp");
      cmd.add(script.getName());
      cmd.add("0");
      ProcessBuilder pb = new ProcessBuilder(cmd).directory(l.workDir).redirectErrorStream(true);
      pb.environment().remove("JAVA_TOOL_OPTIONS");
      Process p = pb.start();
      try (BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream(), StandardCharsets.ISO_8859_1))) {
         for (String s; (s = r.readLine()) != null; ) {
            log.line(s);
         }
      }
      int rc = p.waitFor();
      Files.deleteIfExists(script.toPath());
      Files.deleteIfExists(target.toPath());
      if (rc != 0 || !Install.installed(l, pkg)) {
         throw new IOException("Installing " + pkg + " did not work (gdkup ended with " + rc + "; see the log).");
      }
      log.line("[launcher] " + pkg + " " + version + " installed");
   }

   /** The newest full version upgrades.lst offers to a client without the world (-1 means "not installed"), or -1. */
   static int latestFull(String upgradesLst) {
      int best = -1;
      for (String line : upgradesLst.split("\n")) {
         StringTokenizer t = new StringTokenizer(line.trim());
         if (!t.hasMoreTokens()) {
            continue;
         }
         int from;
         try {
            from = Integer.parseInt(t.nextToken());
         } catch (NumberFormatException e) {
            continue;
         }
         if (from > 0 || from < -1) {
            continue;
         }
         while (t.hasMoreTokens()) {
            String tok = t.nextToken();
            try {
               int colon = tok.indexOf(':');
               if (colon >= 0) {
                  int min = Integer.parseInt(tok.substring(colon + 1));
                  if ((min > 9999 ? min / 10 : min) > CLIENT_BUILD) {
                     continue;
                  }
                  tok = tok.substring(0, colon);
               }
               int hash = tok.indexOf('#');
               if (hash >= 0) {
                  tok = tok.substring(0, hash);
               }
               int v = Integer.parseInt(tok);
               if (v < 999000000 && v > best) {
                  best = v;
               }
            } catch (NumberFormatException e) {
               // a token of another form: not a version
            }
         }
      }
      return best;
   }

   private static String fetchText(String url) throws IOException {
      HttpURLConnection c = open(url);
      try (InputStream in = c.getInputStream()) {
         return new String(in.readAllBytes(), StandardCharsets.ISO_8859_1);
      } finally {
         c.disconnect();
      }
   }

   interface Percent {
      void at(int pct);
   }

   private static void download(String url, File target, Percent percent) throws IOException {
      HttpURLConnection c = open(url);
      long total = c.getContentLengthLong();
      File tmp = new File(target.getPath() + ".part");
      try (InputStream in = c.getInputStream(); OutputStream out = new FileOutputStream(tmp)) {
         byte[] buf = new byte[65536];
         long got = 0;
         int last = -1;
         for (int n; (n = in.read(buf)) > 0; ) {
            out.write(buf, 0, n);
            got += n;
            int pct = total > 0 ? (int) (got * 100 / total) : 0;
            if (pct != last) {
               last = pct;
               percent.at(pct);
            }
         }
      } finally {
         c.disconnect();
      }
      Files.move(tmp.toPath(), target.toPath(), StandardCopyOption.REPLACE_EXISTING);
   }

   private static HttpURLConnection open(String url) throws IOException {
      HttpURLConnection c = (HttpURLConnection) new URL(url).openConnection();
      c.setConnectTimeout(15000);
      c.setReadTimeout(30000);
      c.setRequestProperty("User-Agent", "OpenWorlds/" + Layout.version());
      int code = c.getResponseCode();
      if (code != 200) {
         c.disconnect();
         throw new IOException(url + " answered " + code);
      }
      return c;
   }
}

package net.openworlds.launcher;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.FileTime;
import java.util.Properties;

/**
 * Install.prepare with a new template (a OpenWorlds update, or the same
 * template at another path, as macOS App Translocation does on every start):
 * a file still as the launcher copied it takes the new template's; one the
 * game changed (worlds.dst, an upgraded GroundZero file) is kept for good;
 * missing files come back; cachedir/ is taken again every time; a copy from
 * before the manifest keeps whatever differs from the template.
 */
public final class InstallCheck {
   private static int failures;

   public static void main(String[] args) throws Exception {
      Path tmp = Files.createTempDirectory("fw-install-check");
      try {
         run(tmp);
      } finally {
         Layout.deleteTree(tmp);
      }
      if (failures > 0) {
         System.out.println("InstallCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("InstallCheck: all good");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FAIL  ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static void run(Path tmp) throws Exception {
      Path gameA = tmp.resolve("appA");
      Path t = gameA.resolve("assets/WorldsPlayer");
      write(t, "worlds.ini", "[Gamma]\r\ntemplate=1\r\n", 1000);
      write(t, "worlds.dst", "dst v1", 1000);
      write(t, "GroundZero/ver.txt", "37", 1000);
      write(t, "GroundZero/groundzero.world", "gz v1", 1000);
      write(t, "readme.txt", "readme v1", 1000);
      write(t, "cachedir/cache.index", "index", 1000);
      write(t, "bin/java.exe", "2004 jre", 1000);
      Path data = tmp.resolve("data");
      Layout l = new Layout(tmp.toFile(), gameA.toFile(), data.toFile());
      Log log = new Log(data.resolve("logs").toFile(), "check");
      Path w = l.workDir.toPath();

      System.out.println("First time:");
      Install.prepare(l, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz v1"), "GroundZero copied");
      check(read(w, "worlds.ini").contains("template=1"), "worlds.ini copied");
      check(!Files.exists(w.resolve("bin")), "bin/ (2004 JRE and DLLs) is not copied");
      Properties m = manifest(w);
      check(m.getProperty("GroundZero/groundzero.world", "").contains("|"), "manifest with template|copy");

      System.out.println("The game changes files:");
      write(w, "worlds.ini", "[Gamma]\r\nfriends=pepe\r\n", 5000);
      write(w, "GroundZero/ver.txt", "40", 5000);          // Upgrade Now 37 -> 40
      write(w, "worlds.dst", "game dst", 5000);
      write(w, "cachedir/extra.bin", "old cache", 5000);
      Files.delete(w.resolve("readme.txt"));

      System.out.println("New OpenWorlds version (different template at another path):");
      Path gameB = tmp.resolve("appB");
      Path t2 = gameB.resolve("assets/WorldsPlayer");
      write(t2, "worlds.ini", "[Gamma]\r\ntemplate=2\r\n", 2000);
      write(t2, "worlds.dst", "dst v2", 2000);
      write(t2, "GroundZero/ver.txt", "38", 2000);
      write(t2, "GroundZero/groundzero.world", "gz v2", 2000);
      write(t2, "readme.txt", "readme v2", 2000);
      write(t2, "cachedir/cache.index", "index", 1000);
      write(t2, "new.txt", "new", 2000);
      Layout l2 = new Layout(tmp.toFile(), gameB.toFile(), data.toFile());
      Install.prepare(l2, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz v2"), "untouched since the copy: takes the new template");
      check(read(w, "GroundZero/ver.txt").equals("40"), "GroundZero upgraded by the game: kept (40, not 38)");
      check(read(w, "worlds.dst").equals("game dst"), "worlds.dst changed by the game: kept");
      check(read(w, "worlds.ini").contains("friends=pepe"), "the user's worlds.ini: not touched");
      check(read(w, "readme.txt").equals("readme v2"), "deleted: comes back from the template");
      check(read(w, "new.txt").equals("new"), "new file in the template: copied");
      check(!Files.exists(w.resolve("cachedir/extra.bin")) && Files.exists(w.resolve("cachedir/cache.index")),
         "cachedir/ is taken from the template again");
      check(manifest(w).getProperty("GroundZero/ver.txt", "").startsWith("game|"), "what the game changed is recorded as the game's");

      System.out.println("An even newer template: what the game changed stays the game's:");
      write(t2, "GroundZero/ver.txt", "41", 3000);
      Install.prepare(l2, log);
      check(read(w, "GroundZero/ver.txt").equals("40"), "still 40");

      System.out.println("Same template at another path (App Translocation): nothing is copied:");
      Path gameC = tmp.resolve("appC");
      copyTree(gameB, gameC);
      Layout l3 = new Layout(tmp.toFile(), gameC.toFile(), data.toFile());
      FileTime before = Files.getLastModifiedTime(w.resolve("GroundZero/groundzero.world"));
      Install.prepare(l3, log);
      check(Files.getLastModifiedTime(w.resolve("GroundZero/groundzero.world")).equals(before), "groundzero.world untouched");

      System.out.println("Copy from an older launcher (no manifest):");
      Files.delete(w.resolve(Install.MANIFEST));
      write(w, "GroundZero/groundzero.world", "gz edited", 9000);
      write(t2, "GroundZero/groundzero.world", "gz v3", 4000);
      Install.prepare(l2, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz edited"), "different from the template: kept");
      check(read(w, "new.txt").equals("new") && manifest(w).getProperty("new.txt", "").contains("|"),
         "same as the template: recorded");
   }

   private static void write(Path base, String rel, String text, long seconds) throws IOException {
      Path p = base.resolve(rel);
      Files.createDirectories(p.getParent());
      Files.write(p, text.getBytes(StandardCharsets.ISO_8859_1));
      Files.setLastModifiedTime(p, FileTime.fromMillis(1_700_000_000_000L + seconds * 1000L));
   }

   private static String read(Path base, String rel) throws IOException {
      Path p = base.resolve(rel);
      return Files.isRegularFile(p) ? new String(Files.readAllBytes(p), StandardCharsets.ISO_8859_1) : "";
   }

   private static Properties manifest(Path work) throws IOException {
      Properties p = new Properties();
      try (InputStream in = Files.newInputStream(work.resolve(Install.MANIFEST))) {
         p.load(in);
      }
      return p;
   }

   private static void copyTree(Path from, Path to) throws IOException {
      try (java.util.stream.Stream<Path> s = Files.walk(from)) {
         for (Path p : (Iterable<Path>) s::iterator) {
            Path q = to.resolve(from.relativize(p).toString());
            if (Files.isDirectory(p)) {
               Files.createDirectories(q);
            } else {
               Files.copy(p, q, java.nio.file.StandardCopyOption.COPY_ATTRIBUTES);
            }
         }
      }
   }
}

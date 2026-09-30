package net.openworlds.injector;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

/**
 * J Worlds Injector: the diff reader and applier on small cases (a hunk that
 * moved, a new file, a hunk that does not match), then every patch in
 * injector/patches, alone and all together, applied to the client's source
 * as the bridge builds it (editor/.build-gamma/source) and compiled against
 * the bridge's classes, as the launcher does at start.
 */
public final class InjectorCheck {
   private static int failures;

   public static void main(String[] args) throws Exception {
      Path root = Path.of(args.length > 0 ? args[0] : ".").toAbsolutePath().normalize();
      diffs();
      Path source = root.resolve("editor/.build-gamma/source");
      Path classes = root.resolve("editor/.build-gamma/out");
      if (!Files.isDirectory(source) || !Files.isDirectory(classes)) {
         System.out.println("(no bridge build in editor/.build-gamma: the patches are not built; run build_gamma.sh)");
      } else {
         patches(root, source, classes);
      }
      if (failures > 0) {
         System.out.println("InjectorCheck: " + failures + " failures");
         System.exit(1);
      }
      System.out.println("InjectorCheck: all good");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FAIL  ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static void diffs() {
      System.out.println("Diffs:");
      String base = "a\nb\nc\nd\ne\nf\n";
      String diff = "--- a/x.txt\n+++ b/x.txt\n@@ -3,3 +3,3 @@\n c\n-d\n+D\n e\n";
      UnifiedDiff.FileDiff f = UnifiedDiff.parse(diff).get(0);
      check(f.path.equals("x.txt") && f.hunks.size() == 1, "reads the file and its hunk");
      check("a\nb\nc\nD\ne\nf\n".equals(UnifiedDiff.apply(f, base)), "applies it");
      check("0\n1\na\nb\nc\nD\ne\nf\n".equals(UnifiedDiff.apply(f, "0\n1\n" + base)), "finds a hunk that moved down 2 lines");
      boolean refused = false;
      try {
         UnifiedDiff.apply(f, "a\nb\nc\nX\ne\nf\n");
      } catch (IllegalStateException e) {
         refused = e.getMessage().contains("does not match");
      }
      check(refused, "refuses a hunk whose lines are not there");
      UnifiedDiff.FileDiff n = UnifiedDiff.parse("--- /dev/null\n+++ b/p/New.java\n@@ -0,0 +1,2 @@\n+class New {\n+}\n").get(0);
      check(n.creates && n.path.equals("p/New.java") && "class New {\n}\n".equals(UnifiedDiff.apply(n, null)), "creates a new file");
   }

   private static void patches(Path root, Path source, Path classes) throws IOException {
      List<Patch> all = Patch.fromFolder(root.resolve("injector/patches").toFile(), true);
      System.out.println("Patches (" + all.size() + "):");
      check(all.size() >= 5, "injector/patches has the built-in patches");
      Path tmp = Files.createTempDirectory("injector-check");
      try {
         File zip = tmp.resolve("worldsplayer-src.zip").toFile();
         zipTree(source, zip);
         for (Patch p : all) {
            check(!p.description.isEmpty() && !p.name.equals(p.id), p.id + ": has a name and a description");
            File out = build(List.of(p), zip, classes, tmp.resolve("cache"));
            boolean built = out != null;
            if (built) {
               for (String path : p.files()) {
                  String cls = path.replace(".java", ".class");
                  built &= new File(out, cls).isFile();
               }
            }
            check(built, p.id + ": applies and compiles against the bridge (" + String.join(", ", p.files()) + ")");
         }
         File together = build(all, zip, classes, tmp.resolve("cache"));
         check(together != null, "all " + all.size() + " together");
         File again = build(all, zip, classes, tmp.resolve("cache"));
         check(together != null && together.equals(again), "the second time comes from the cache");
      } finally {
         deleteTree(tmp);
      }
   }

   private static File build(List<Patch> patches, File zip, Path classes, Path cache) {
      try {
         return Injector.build(patches, zip, classes.toFile(), cache.toFile(), line -> { });
      } catch (IOException e) {
         System.out.println("    " + e.getMessage().replace("\n", "\n    "));
         return null;
      }
   }

   private static void zipTree(Path dir, File zip) throws IOException {
      try (ZipOutputStream z = new ZipOutputStream(new FileOutputStream(zip)); Stream<Path> walk = Files.walk(dir)) {
         List<Path> files = new ArrayList<>();
         walk.filter(Files::isRegularFile).forEach(files::add);
         for (Path f : files) {
            z.putNextEntry(new ZipEntry(dir.relativize(f).toString().replace(File.separatorChar, '/')));
            z.write(Files.readAllBytes(f));
            z.closeEntry();
         }
      }
   }

   private static void deleteTree(Path p) throws IOException {
      if (!Files.exists(p)) {
         return;
      }
      try (Stream<Path> walk = Files.walk(p)) {
         Path[] all = walk.toArray(Path[]::new);
         Arrays.sort(all, (a, b) -> b.getNameCount() - a.getNameCount());
         for (Path x : all) {
            Files.deleteIfExists(x);
         }
      }
   }

   static byte[] utf8(String s) {
      return s.getBytes(StandardCharsets.UTF_8);
   }
}

package net.openworlds.injector;

import javax.tools.Diagnostic;
import javax.tools.DiagnosticCollector;
import javax.tools.JavaCompiler;
import javax.tools.JavaFileObject;
import javax.tools.StandardJavaFileManager;
import javax.tools.ToolProvider;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.function.Consumer;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * J Worlds Injector: builds the chosen patches into classes that the game
 * loads before worldsplayer.jar. For each file the patches touch, it takes
 * the client's source as the bridge builds it (worldsplayer-src.zip), applies
 * the patches' diffs in order and compiles the result against
 * worldsplayer.jar with the Java compiler that comes with the app. The
 * classes are cached by a hash of the game and the patches, so only a new
 * choice (or a new version) compiles again.
 */
public final class Injector {
   /** The cache folders kept (the newest ones). */
   private static final int KEEP = 6;

   private Injector() {
   }

   /**
    * The folder of patched classes for {@code patches}, building it if
    * needed; null when there are no patches. Throws IOException with a
    * message for the player when a patch does not apply or compile.
    */
   public static File build(List<Patch> patches, File sourceZip, File gameJar, File cacheRoot, Consumer<String> log)
      throws IOException {
      if (patches.isEmpty()) {
         return null;
      }
      String key = key(patches, gameJar);
      File dir = new File(cacheRoot, key);
      File classes = new File(dir, "classes");
      if (new File(dir, "ok").isFile()) {
         log.accept("[injector] patches " + ids(patches) + ": ready (" + dir.getName() + ")");
         touch(dir);
         return classes;
      }
      if (!sourceZip.isFile()) {
         throw new IOException("The patches need the game's source (" + sourceZip.getName() + "), which is not in this package.");
      }
      JavaCompiler javac = ToolProvider.getSystemJavaCompiler();
      if (javac == null) {
         throw new IOException("The patches need Java's compiler, which this Java does not have. The OpenWorlds app"
            + " includes it; for the portable package, install a JDK 17 or newer (not just a JRE).");
      }
      log.accept("[injector] applying " + ids(patches) + "...");
      Map<String, String> files = patchedSources(patches, sourceZip);
      deleteTree(dir);
      File src = new File(dir, "src");
      List<File> toCompile = new ArrayList<>();
      for (Map.Entry<String, String> e : files.entrySet()) {
         File f = new File(src, e.getKey());
         f.getParentFile().mkdirs();
         Files.write(f.toPath(), e.getValue().getBytes(StandardCharsets.UTF_8));
         if (f.getName().endsWith(".java")) {
            toCompile.add(f);
         }
      }
      classes.mkdirs();
      DiagnosticCollector<JavaFileObject> diags = new DiagnosticCollector<>();
      boolean ok;
      try (StandardJavaFileManager fm = javac.getStandardFileManager(diags, Locale.ENGLISH, StandardCharsets.UTF_8)) {
         List<String> opts = Arrays.asList("--release", "8", "-nowarn", "-proc:none", "-encoding", "UTF-8",
            "-cp", gameJar.getPath(), "-d", classes.getPath());
         ok = javac.getTask(null, fm, diags, opts, null, fm.getJavaFileObjectsFromFiles(toCompile)).call();
      }
      if (!ok) {
         StringBuilder why = new StringBuilder();
         int n = 0;
         for (Diagnostic<? extends JavaFileObject> d : diags.getDiagnostics()) {
            if (d.getKind() == Diagnostic.Kind.ERROR && n++ < 3) {
               String where = d.getSource() == null ? "" : new File(d.getSource().getName()).getName() + ":" + d.getLineNumber() + ": ";
               why.append("\n").append(where).append(d.getMessage(Locale.ENGLISH));
            }
         }
         throw new IOException("The patches do not compile together with this version of the game." + why);
      }
      Files.write(new File(dir, "ok").toPath(), ids(patches).getBytes(StandardCharsets.UTF_8));
      log.accept("[injector] patches " + ids(patches) + " built (" + toCompile.size() + " source files)");
      prune(cacheRoot, dir);
      return classes;
   }

   /**
    * The patched text of every file the patches touch, applying them in
    * order; throws IOException naming the patch that does not fit.
    */
   static Map<String, String> patchedSources(List<Patch> patches, File sourceZip) throws IOException {
      Map<String, String> files = new LinkedHashMap<>();
      try (ZipFile zip = new ZipFile(sourceZip)) {
         for (Patch p : patches) {
            for (Map.Entry<String, String> diff : p.diffs.entrySet()) {
               List<UnifiedDiff.FileDiff> changes;
               try {
                  changes = UnifiedDiff.parse(diff.getValue());
               } catch (IllegalArgumentException e) {
                  throw new IOException("The patch \"" + p.name + "\" is broken (" + diff.getKey() + ": " + e.getMessage() + ").");
               }
               for (UnifiedDiff.FileDiff f : changes) {
                  String text = files.containsKey(f.path) ? files.get(f.path) : read(zip, f.path);
                  try {
                     files.put(f.path, UnifiedDiff.apply(f, text));
                  } catch (IllegalStateException e) {
                     String others = files.containsKey(f.path) ? " (another chosen patch changes the same place)" : "";
                     throw new IOException("The patch \"" + p.name + "\" does not fit this version of the game" + others
                        + ": " + e.getMessage());
                  }
               }
            }
         }
      }
      return files;
   }

   private static String read(ZipFile zip, String path) throws IOException {
      ZipEntry e = zip.getEntry(path);
      if (e == null) {
         return null;
      }
      try (InputStream in = zip.getInputStream(e)) {
         return new String(in.readAllBytes(), StandardCharsets.UTF_8);
      }
   }

   /** The cache key: the game jar (size and time) and the patches' ids and diffs. */
   static String key(List<Patch> patches, File gameJar) {
      try {
         MessageDigest md = MessageDigest.getInstance("SHA-256");
         md.update((gameJar.length() + ":" + gameJar.lastModified() + "\n").getBytes(StandardCharsets.UTF_8));
         for (Patch p : patches) {
            md.update((p.id + "\n").getBytes(StandardCharsets.UTF_8));
            for (Map.Entry<String, String> d : p.diffs.entrySet()) {
               md.update((d.getKey() + "\n" + d.getValue()).getBytes(StandardCharsets.UTF_8));
            }
         }
         byte[] h = md.digest();
         StringBuilder sb = new StringBuilder();
         for (int i = 0; i < 8; i++) {
            sb.append(String.format("%02x", h[i] & 0xff));
         }
         return sb.toString();
      } catch (NoSuchAlgorithmException e) {
         throw new IllegalStateException(e);
      }
   }

   static String ids(List<Patch> patches) {
      List<String> ids = new ArrayList<>();
      for (Patch p : patches) {
         ids.add(p.id);
      }
      return String.join(", ", ids);
   }

   private static void touch(File dir) {
      if (!dir.setLastModified(System.currentTimeMillis())) {
         // only affects which cache folders are pruned first
         return;
      }
   }

   /** Deletes the oldest cache folders beyond {@link #KEEP}. */
   private static void prune(File root, File keep) {
      File[] dirs = root.listFiles(File::isDirectory);
      if (dirs == null || dirs.length <= KEEP) {
         return;
      }
      Arrays.sort(dirs, (a, b) -> Long.compare(b.lastModified(), a.lastModified()));
      for (int i = KEEP; i < dirs.length; i++) {
         if (!dirs[i].equals(keep)) {
            deleteTree(dirs[i]);
         }
      }
   }

   private static void deleteTree(File f) {
      File[] kids = f.listFiles();
      if (kids != null) {
         for (File k : kids) {
            deleteTree(k);
         }
      }
      if (f.exists() && !f.delete()) {
         f.deleteOnExit();
      }
   }
}

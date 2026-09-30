package net.openworlds.injector;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.StringReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Properties;

/**
 * A patch for the 2004 client: a folder with patch.properties (name,
 * description, category) and one or more unified diffs (*.diff, applied in
 * file name order) against the client's source as the bridge builds it. The
 * built-in ones travel inside the launcher (net/openworlds/injector/patches/,
 * listed in index.txt); your own go in the patches folder of the launcher's
 * data folder, one folder each, in the same format.
 */
public final class Patch {
   public final String id;
   public final String name;
   public final String description;
   public final String category;
   public final boolean builtIn;
   /** The diffs' text, in order, keyed by file name. */
   final Map<String, String> diffs;

   private Patch(String id, Properties p, boolean builtIn, Map<String, String> diffs) {
      this.id = id;
      this.name = p.getProperty("name", id).trim();
      this.description = p.getProperty("description", "").trim();
      this.category = p.getProperty("category", "Other").trim();
      this.builtIn = builtIn;
      this.diffs = diffs;
   }

   /** The source files (paths in the tree) this patch changes or adds. */
   public List<String> files() {
      List<String> out = new ArrayList<>();
      for (String text : diffs.values()) {
         for (UnifiedDiff.FileDiff f : UnifiedDiff.parse(text)) {
            if (!out.contains(f.path)) {
               out.add(f.path);
            }
         }
      }
      return out;
   }

   @Override
   public String toString() {
      return id + " (" + name + ")";
   }

   // ------------------------------------------------------------ loading

   /** The patches that come with OpenWorlds (resources next to this class). */
   public static List<Patch> builtIn() {
      Map<String, Map<String, String>> byId = new LinkedHashMap<>();
      String index = resource("patches/index.txt");
      if (index == null) {
         return Collections.emptyList();
      }
      for (String line : index.split("\n")) {
         line = line.trim();
         int slash = line.indexOf('/');
         if (line.isEmpty() || line.startsWith("#") || slash < 0) {
            continue;
         }
         String id = line.substring(0, slash);
         String text = resource("patches/" + line);
         if (text != null) {
            byId.computeIfAbsent(id, k -> new LinkedHashMap<>()).put(line.substring(slash + 1), text);
         }
      }
      List<Patch> out = new ArrayList<>();
      for (Map.Entry<String, Map<String, String>> e : byId.entrySet()) {
         Patch p = make(e.getKey(), e.getValue(), true);
         if (p != null) {
            out.add(p);
         }
      }
      return out;
   }

   /** The patches in a folder of patch folders (the user's, or injector/patches in the repository). */
   public static List<Patch> fromFolder(File root, boolean builtIn) {
      List<Patch> out = new ArrayList<>();
      File[] dirs = root.listFiles(File::isDirectory);
      if (dirs == null) {
         return out;
      }
      Arrays.sort(dirs);
      for (File d : dirs) {
         Map<String, String> files = new LinkedHashMap<>();
         File[] fs = d.listFiles(f -> f.isFile() && (f.getName().equals("patch.properties") || f.getName().endsWith(".diff")));
         if (fs == null) {
            continue;
         }
         Arrays.sort(fs);
         try {
            for (File f : fs) {
               files.put(f.getName(), new String(Files.readAllBytes(f.toPath()), StandardCharsets.UTF_8));
            }
         } catch (IOException e) {
            continue;
         }
         Patch p = make(d.getName(), files, builtIn);
         if (p != null) {
            out.add(p);
         }
      }
      return out;
   }

   /** Built-in patches plus the user's (a user patch with a built-in's id replaces it). */
   public static List<Patch> all(File userFolder) {
      Map<String, Patch> m = new LinkedHashMap<>();
      for (Patch p : builtIn()) {
         m.put(p.id, p);
      }
      if (userFolder != null) {
         for (Patch p : fromFolder(userFolder, false)) {
            m.put(p.id, p);
         }
      }
      return new ArrayList<>(m.values());
   }

   /** The patches named in a comma-separated list, in the catalog's order; unknown names are left out. */
   public static List<Patch> pick(List<Patch> all, String ids) {
      List<String> wanted = new ArrayList<>();
      for (String s : ids == null ? new String[0] : ids.split(",")) {
         if (!s.trim().isEmpty()) {
            wanted.add(s.trim());
         }
      }
      List<Patch> out = new ArrayList<>();
      for (Patch p : all) {
         if (wanted.contains(p.id)) {
            out.add(p);
         }
      }
      return out;
   }

   private static Patch make(String id, Map<String, String> files, boolean builtIn) {
      String props = files.get("patch.properties");
      Map<String, String> diffs = new LinkedHashMap<>();
      List<String> names = new ArrayList<>(files.keySet());
      Collections.sort(names);
      for (String n : names) {
         if (n.endsWith(".diff")) {
            diffs.put(n, files.get(n));
         }
      }
      if (diffs.isEmpty() || !id.matches("[A-Za-z0-9._-]+")) {
         return null;
      }
      Properties p = new Properties();
      if (props != null) {
         try {
            p.load(new StringReader(props));
         } catch (IOException e) {
            // an unreadable properties file: the patch keeps its id as name
         }
      }
      return new Patch(id, p, builtIn, diffs);
   }

   private static String resource(String name) {
      try (InputStream in = Patch.class.getResourceAsStream(name)) {
         if (in == null) {
            return null;
         }
         ByteArrayOutputStream b = new ByteArrayOutputStream();
         byte[] buf = new byte[8192];
         for (int n; (n = in.read(buf)) > 0; ) {
            b.write(buf, 0, n);
         }
         return new String(b.toByteArray(), StandardCharsets.UTF_8);
      } catch (IOException e) {
         return null;
      }
   }
}

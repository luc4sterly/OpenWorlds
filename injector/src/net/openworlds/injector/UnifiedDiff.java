package net.openworlds.injector;

import java.util.ArrayList;
import java.util.List;

/**
 * Unified diffs (what {@code diff -u} and {@code git diff} write), applied
 * exactly: every context and removed line must match, though a hunk may sit
 * a few lines away from where its header says (another patch may have added
 * lines above it). A file whose old name is /dev/null is created.
 */
final class UnifiedDiff {
   /** One file's changes. */
   static final class FileDiff {
      /** Path in the source tree (without the a/ or b/ prefix). */
      final String path;
      final boolean creates;
      final List<Hunk> hunks = new ArrayList<>();

      FileDiff(String path, boolean creates) {
         this.path = path;
         this.creates = creates;
      }
   }

   static final class Hunk {
      final int oldStart;
      /** Lines with their marker: ' ' context, '-' removed, '+' added. */
      final List<String> lines = new ArrayList<>();

      Hunk(int oldStart) {
         this.oldStart = oldStart;
      }

      List<String> before() {
         List<String> out = new ArrayList<>();
         for (String l : lines) {
            if (l.charAt(0) != '+') {
               out.add(l.substring(1));
            }
         }
         return out;
      }

      List<String> after() {
         List<String> out = new ArrayList<>();
         for (String l : lines) {
            if (l.charAt(0) != '-') {
               out.add(l.substring(1));
            }
         }
         return out;
      }
   }

   private UnifiedDiff() {
   }

   /** The files a diff text changes; throws IllegalArgumentException when it is not a unified diff. */
   static List<FileDiff> parse(String text) {
      List<FileDiff> files = new ArrayList<>();
      String[] lines = text.replace("\r\n", "\n").split("\n", -1);
      FileDiff cur = null;
      Hunk hunk = null;
      int oldLeft = 0;
      int newLeft = 0;
      for (int i = 0; i < lines.length; i++) {
         String l = lines[i];
         if (hunk != null && (oldLeft > 0 || newLeft > 0)) {
            if (l.startsWith("\\")) {
               continue; // "\ No newline at end of file"
            }
            char c = l.isEmpty() ? ' ' : l.charAt(0);
            String body = l.isEmpty() ? " " : l;
            if (c == ' ') {
               oldLeft--;
               newLeft--;
            } else if (c == '-') {
               oldLeft--;
            } else if (c == '+') {
               newLeft--;
            } else {
               throw new IllegalArgumentException("line " + (i + 1) + ": hunk ends early");
            }
            hunk.lines.add(body);
            continue;
         }
         if (l.startsWith("--- ") && i + 1 < lines.length && lines[i + 1].startsWith("+++ ")) {
            String oldName = name(l.substring(4));
            String newName = name(lines[i + 1].substring(4));
            boolean creates = oldName.equals("/dev/null");
            cur = new FileDiff(creates ? strip(newName) : strip(oldName), creates);
            files.add(cur);
            hunk = null;
            i++;
         } else if (l.startsWith("@@ ")) {
            if (cur == null) {
               throw new IllegalArgumentException("line " + (i + 1) + ": hunk before any file header");
            }
            // @@ -oldStart[,oldCount] +newStart[,newCount] @@
            String[] f = l.split(" ");
            int[] o = range(f[1].substring(1));
            int[] n = range(f[2].substring(1));
            hunk = new Hunk(o[0]);
            oldLeft = o[1];
            newLeft = n[1];
            cur.hunks.add(hunk);
         }
         // anything else (diff/index lines, comments before the headers) is ignored
      }
      if (files.isEmpty()) {
         throw new IllegalArgumentException("no file changes in the diff");
      }
      return files;
   }

   private static String name(String s) {
      int tab = s.indexOf('\t');
      return (tab >= 0 ? s.substring(0, tab) : s).trim();
   }

   private static String strip(String path) {
      if (path.startsWith("a/") || path.startsWith("b/")) {
         return path.substring(2);
      }
      return path;
   }

   private static int[] range(String s) {
      int comma = s.indexOf(',');
      if (comma < 0) {
         return new int[]{Integer.parseInt(s), 1};
      }
      return new int[]{Integer.parseInt(s.substring(0, comma)), Integer.parseInt(s.substring(comma + 1))};
   }

   /**
    * Applies a file's hunks to its text (null for a new file); throws
    * IllegalStateException naming the hunk that does not match.
    */
   static String apply(FileDiff diff, String text) {
      if (diff.creates && text != null) {
         throw new IllegalStateException(diff.path + " already exists");
      }
      List<String> lines = new ArrayList<>();
      boolean trailingNewline = true;
      if (text != null && !text.isEmpty()) {
         String[] split = text.split("\n", -1);
         trailingNewline = text.endsWith("\n");
         for (int i = 0; i < split.length - (trailingNewline ? 1 : 0); i++) {
            lines.add(split[i]);
         }
      }
      int shift = 0;
      for (int h = 0; h < diff.hunks.size(); h++) {
         Hunk hunk = diff.hunks.get(h);
         List<String> before = hunk.before();
         List<String> after = hunk.after();
         int want = Math.max(0, hunk.oldStart - 1 + shift);
         if (before.isEmpty()) {
            want = Math.min(want, lines.size());
         }
         int at = find(lines, before, want);
         if (at < 0) {
            throw new IllegalStateException(diff.path + ": change " + (h + 1) + " of " + diff.hunks.size()
               + " does not match the source (near line " + hunk.oldStart + ")");
         }
         for (int k = 0; k < before.size(); k++) {
            lines.remove(at);
         }
         lines.addAll(at, after);
         shift += after.size() - before.size() + (at - want);
      }
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < lines.size(); i++) {
         sb.append(lines.get(i));
         if (i < lines.size() - 1 || trailingNewline) {
            sb.append('\n');
         }
      }
      return sb.toString();
   }

   /** Where {@code block} occurs in {@code lines}, nearest to {@code near}; -1 if nowhere. */
   private static int find(List<String> lines, List<String> block, int near) {
      if (block.isEmpty()) {
         return near;
      }
      int max = lines.size() - block.size();
      for (int d = 0; d <= Math.max(near, max - near) + 1; d++) {
         for (int at : new int[]{near - d, near + d}) {
            if (at >= 0 && at <= max && matches(lines, block, at)) {
               return at;
            }
         }
      }
      return -1;
   }

   private static boolean matches(List<String> lines, List<String> block, int at) {
      for (int k = 0; k < block.size(); k++) {
         if (!lines.get(at + k).equals(block.get(k))) {
            return false;
         }
      }
      return true;
   }
}

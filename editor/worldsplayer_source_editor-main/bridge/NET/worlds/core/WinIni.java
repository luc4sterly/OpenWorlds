package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * GetPrivateProfileString / WritePrivateProfileString (kernel32) over one
 * file, for the code that runs without the client: {@link GdkUp} and the
 * world installers it replaces ({@link WisePackage}, {@link NsisPackage}).
 * Same rules as the IniFile mock of the client (apply_mock.sh): section and
 * key names without case, the first section with the name is the one used,
 * a key that exists keeps its line and only its value changes, a new key
 * goes after the last non-empty line of its section, a new section at the
 * end of the file, and the file keeps its line ends (CRLF when it is new).
 */
final class WinIni {
   private WinIni() {
   }

   /** GetPrivateProfileString: the value (spaces around it removed), or def. */
   static String get(File f, String section, String key, String def) throws IOException {
      if (!f.isFile()) {
         return def;
      }
      boolean in = false;
      boolean seen = false;
      for (String raw : read(f)) {
         String line = raw.trim();
         if (line.startsWith("[") && line.endsWith("]")) {
            if (seen) {
               break;
            }
            in = line.substring(1, line.length() - 1).trim().equalsIgnoreCase(section);
            seen = in;
         } else if (in) {
            int eq = line.indexOf('=');
            if (eq > 0 && line.substring(0, eq).trim().equalsIgnoreCase(key)) {
               return line.substring(eq + 1).trim();
            }
         }
      }
      return def;
   }

   /** WritePrivateProfileString with a value. */
   static void put(File f, String section, String key, String value) throws IOException {
      List<String> lines = f.isFile() ? read(f) : new ArrayList<String>();
      String eol = f.isFile() ? eol(f) : "\r\n";
      int start = -1;
      int last = -1;
      for (int i = 0; i < lines.size(); i++) {
         String line = lines.get(i).trim();
         if (line.startsWith("[") && line.endsWith("]")) {
            if (start >= 0) {
               break;
            }
            if (line.substring(1, line.length() - 1).trim().equalsIgnoreCase(section)) {
               start = i;
               last = i;
            }
         } else if (start >= 0 && !line.isEmpty()) {
            last = i;
            int eq = line.indexOf('=');
            if (eq > 0 && line.substring(0, eq).trim().equalsIgnoreCase(key)) {
               lines.set(i, line.substring(0, eq).trim() + "=" + value);
               write(f, lines, eol);
               return;
            }
         }
      }
      if (start < 0) {
         lines.add("[" + section + "]");
         lines.add(key + "=" + value);
      } else {
         lines.add(last + 1, key + "=" + value);
      }
      write(f, lines, eol);
   }

   private static List<String> read(File f) throws IOException {
      String s = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
      List<String> out = new ArrayList<String>();
      for (String l : s.split("\r?\n", -1)) {
         out.add(l);
      }
      if (!out.isEmpty() && out.get(out.size() - 1).isEmpty()) {
         out.remove(out.size() - 1);
      }
      return out;
   }

   private static String eol(File f) throws IOException {
      String s = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
      return !s.contains("\r\n") && s.contains("\n") ? "\n" : "\r\n";
   }

   private static void write(File f, List<String> lines, String eol) throws IOException {
      StringBuilder sb = new StringBuilder();
      for (String l : lines) {
         sb.append(l).append(eol);
      }
      Files.write(f.toPath(), sb.toString().getBytes("ISO-8859-1"));
   }
}

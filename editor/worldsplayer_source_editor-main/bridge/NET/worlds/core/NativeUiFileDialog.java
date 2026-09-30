package NET.worlds.core;

import java.awt.FileDialog;
import java.awt.Frame;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * FileSysDialog.nativeRun (0x004051d0): GetOpenFileNameA (mode 0) or
 * GetSaveFileNameA (mode 1) with AWT's {@link FileDialog}.
 *
 * <p>From the original: OPENFILENAME with Flags 0x180e (OFN_OVERWRITEPROMPT |
 * OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_PATHMUSTEXIST |
 * OFN_FILEMUSTEXIST), nFilterIndex 1, nMaxFile 0x104; fileName is split at
 * the last '\\' (strrchr, FUN_0044d7d0): what comes after goes to lpstrFile
 * and what comes before to lpstrInitialDir (leaving "C:\\" if the separator
 * follows ':'); typesAndExts "desc|pattern|desc|pattern" becomes the Windows
 * filter list by changing '|' to '\0'. Returns the chosen path or null
 * (cancel, or a mode other than 0/1).
 *
 * <p>Equivalences: AWT's native dialog already asks for confirmation when
 * overwriting and only lets you open files that exist. The path is split at
 * the system separator as well as '\\' (Windows also accepted a full path in
 * lpstrFile, which opens in that directory: it is the same effect).
 * ⚠️ AWT has no drop-down list of filters: files of ANY filter in the list
 * are accepted (the union of what the user could choose in Windows; with
 * nFilterIndex 1 Windows showed only the first one).
 * ⚠️ lpstrDefExt points to the first pattern ("*.world"): the extension that
 * comdlg32 would append to a name without an extension does not come from
 * gamma.dll, and it is not appended.
 */
public final class NativeUiFileDialog {
   private NativeUiFileDialog() {
   }

   /** The patterns ("*.world", "*.*"...) of the filter list. */
   static List<String> patterns(String typesAndExts) {
      List<String> out = new ArrayList<String>();
      if (typesAndExts == null) {
         return out;
      }
      String[] parts = typesAndExts.split("\\|", -1);
      for (int i = 1; i < parts.length; i += 2) {
         for (String p : parts[i].split(";")) {
            if (p.trim().length() > 0) {
               out.add(p.trim().toLowerCase());
            }
         }
      }
      return out;
   }

   /** Windows wildcard comparison (* and ?), case-insensitive. */
   static boolean matches(String name, List<String> pats) {
      if (pats.isEmpty()) {
         return true;
      }
      String n = name.toLowerCase();
      for (String p : pats) {
         if (p.equals("*.*") || p.equals("*") || glob(n, 0, p, 0)) {
            return true;
         }
      }
      return false;
   }

   private static boolean glob(String s, int i, String p, int j) {
      if (j == p.length()) {
         return i == s.length();
      }
      char c = p.charAt(j);
      if (c == '*') {
         for (int k = i; k <= s.length(); k++) {
            if (glob(s, k, p, j + 1)) {
               return true;
            }
         }
         return false;
      }
      return i < s.length() && (c == '?' || c == s.charAt(i)) && glob(s, i + 1, p, j + 1);
   }

   /** {directory or null, file}, like the original's split. */
   static String[] split(String fileName) {
      if (fileName == null) {
         return new String[]{null, ""};
      }
      int k = Math.max(fileName.lastIndexOf('\\'), fileName.lastIndexOf(File.separatorChar));
      if (k < 0) {
         return new String[]{null, fileName};
      }
      String dir = k > 0 && fileName.charAt(k - 1) == ':' ? fileName.substring(0, k + 1) : fileName.substring(0, k);
      if (dir.length() == 0) {
         dir = fileName.substring(0, 1);
      }
      return new String[]{dir, fileName.substring(k + 1)};
   }

   public static String run(Frame parent, String title, String typesAndExts, String fileName, int mode) {
      if (mode != 0 && mode != 1) {
         return null;
      }
      String[] df = split(fileName);
      final List<String> pats = patterns(typesAndExts);
      FileDialog d = new FileDialog(parent, title == null ? "" : title, mode == 0 ? FileDialog.LOAD : FileDialog.SAVE);
      if (df[0] != null) {
         d.setDirectory(df[0]);
      }
      d.setFile(df[1]);
      d.setFilenameFilter(new java.io.FilenameFilter() {
         public boolean accept(File dir, String name) {
            return matches(name, pats);
         }
      });
      d.setVisible(true);
      String f = d.getFile();
      if (f == null) {
         return null;
      }
      return d.getDirectory() == null ? f : new File(d.getDirectory(), f).getPath();
   }
}

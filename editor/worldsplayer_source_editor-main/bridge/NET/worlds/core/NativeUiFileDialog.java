package NET.worlds.core;

import java.awt.FileDialog;
import java.awt.Frame;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 * FileSysDialog.nativeRun (0x004051d0): GetOpenFileNameA (modo 0) o
 * GetSaveFileNameA (modo 1) con {@link FileDialog} de AWT.
 *
 * <p>Del original: OPENFILENAME con Flags 0x180e (OFN_OVERWRITEPROMPT |
 * OFN_HIDEREADONLY | OFN_NOCHANGEDIR | OFN_PATHMUSTEXIST |
 * OFN_FILEMUSTEXIST), nFilterIndex 1, nMaxFile 0x104; fileName se parte en
 * el ultimo '\\' (strrchr, FUN_0044d7d0): lo de detras va a lpstrFile y lo de
 * delante a lpstrInitialDir (dejando "C:\\" si el separador sigue a ':');
 * typesAndExts "desc|patron|desc|patron" pasa a la lista de filtros de
 * Windows cambiando '|' por '\0'. Devuelve la ruta elegida o null (cancelar,
 * o modo distinto de 0/1).
 *
 * <p>Equivalencias: el dialogo nativo de AWT ya pide confirmacion al
 * sobrescribir y solo deja abrir ficheros que existen. La ruta se parte por
 * el separador del sistema ademas de '\\' (Windows aceptaba tambien una ruta
 * completa en lpstrFile, que abre en ese directorio: es el mismo efecto).
 * ⚠️ AWT no tiene la lista desplegable de filtros: se aceptan los ficheros
 * de CUALQUIER filtro de la lista (el union de lo que el usuario podia
 * elegir en Windows; con nFilterIndex 1 Windows mostraba solo el primero).
 * ⚠️ lpstrDefExt apunta al primer patron ("*.world"): la extension que
 * comdlg32 anadiria a un nombre sin extension no sale de gamma.dll y no se
 * anade.
 */
public final class NativeUiFileDialog {
   private NativeUiFileDialog() {
   }

   /** Los patrones ("*.world", "*.*"...) de la lista de filtros. */
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

   /** Comparacion de comodines de Windows (* y ?), sin distinguir mayusculas. */
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

   /** {directorio o null, fichero} como el reparto del original. */
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

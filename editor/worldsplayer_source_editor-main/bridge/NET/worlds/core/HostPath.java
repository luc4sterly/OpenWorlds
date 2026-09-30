package NET.worlds.core;

import java.io.File;

/**
 * Platform, not gamma.dll: the paths that the 2004 client builds with
 * {@code URL.unalias()}/{@code homeUnalias} carry the synthetic drive "u:"
 * of the {@code URL.normalizeCurrentDir} patch, are lowercase
 * ({@code URL.validateFile}) and sometimes use '\'. Windows accepted them
 * as they were (real drive, case-insensitive file system); on macOS/Linux
 * {@code new File("u:/.../rtpanel.gif")} does not exist, and that is why the
 * window's buttons were not painted (ImageCanvas), redir.txt was not read, etc.
 *
 * build_gamma.sh (bridge/host_paths.py) wraps the first argument of every
 * {@code new File/FileInputStream/FileOutputStream/
 * FileReader/FileWriter/RandomAccessFile/ZipFile(...)} and of
 * {@code Toolkit.getImage(...)} in the decompiled Java with {@link #of}. On
 * Windows it changes nothing; elsewhere it removes the drive, turns '\' into
 * '/' and resolves each segment case-insensitively against the disk
 * (NativeMock.resolveCaseInsensitive).
 */
public final class HostPath {
   private HostPath() {
   }

   private static final boolean WINDOWS = File.separatorChar == '\\';

   public static String of(String path) {
      if (path == null || WINDOWS) {
         return path;
      }
      String p = path.replace('\\', '/');
      if (p.length() > 1 && p.charAt(1) == ':' && Character.isLetter(p.charAt(0))) {
         p = p.substring(2);
      }
      if (p.isEmpty()) {
         return p;
      }
      return NativeMock.resolveCaseInsensitive(p).getPath();
   }

   public static File of(File file) {
      if (file == null || WINDOWS) {
         return file;
      }
      String p = file.getPath();
      String q = of(p);
      return q.equals(p) ? file : new File(q);
   }

   public static java.net.URL of(java.net.URL url) {
      return url;
   }
}

package NET.worlds.core;

import java.io.File;

/**
 * Plataforma, no gamma.dll: las rutas que el cliente de 2004 construye con
 * {@code URL.unalias()}/{@code homeUnalias} llevan la unidad sintetica "u:"
 * del parche de {@code URL.normalizeCurrentDir}, van en minusculas
 * ({@code URL.validateFile}) y a veces con '\'. Windows las aceptaba tal
 * cual (unidad real, sistema de ficheros sin mayusculas); en macOS/Linux
 * {@code new File("u:/.../rtpanel.gif")} no existe, y por eso no se pintaban
 * los botones de la ventana (ImageCanvas), no se leia redir.txt, etc.
 *
 * build_gamma.sh (bridge/host_paths.py) envuelve con {@link #of} el primer
 * argumento de cada {@code new File/FileInputStream/FileOutputStream/
 * FileReader/FileWriter/RandomAccessFile/ZipFile(...)} y de
 * {@code Toolkit.getImage(...)} del Java decompilado. En Windows no cambia
 * nada; fuera, quita la unidad, pasa '\' a '/' y resuelve cada tramo sin
 * distinguir mayusculas contra el disco (NativeMock.resolveCaseInsensitive).
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

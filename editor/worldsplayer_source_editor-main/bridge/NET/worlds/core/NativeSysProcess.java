package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * {@code NetUpdate.CreateProcSpecial} (gamma.dll 0x00404740): lanza el
 * actualizador ({@code .\bin\gdkup.exe <lista>}) con el PID del cliente.
 *
 * <p>De gamma.dll: la línea de órdenes es {@code wsprintfA("%s %s %lu",
 * programa, argumentos, GetCurrentProcessId())} (0x0046d620); si
 * CreateProcessA falla, escribe en su flujo de log (0x49eda8, el mismo que
 * NativeAssert lleva a stderr) {@code Internal error - can't execute "} +
 * línea + {@code "} (0x0046d630 / 0x0046d62c) con fin de línea, luego el
 * texto de FormatMessageA(GetLastError()) con fin de línea, y devuelve
 * false; si arranca, WaitForInputIdle, cierra las asas y devuelve true.
 *
 * <p>Sustituto de CreateProcessA(NULL, línea, ..., DETACHED_PROCESS): el
 * primer elemento de la línea (entre comillas si las lleva) es el programa,
 * con ".exe" si no tiene extensión, relativo al directorio actual y
 * resuelto por {@code NativeMock.localFile}; el resto se parte en
 * argumentos por espacios respetando comillas; se arranca con
 * {@code ProcessBuilder} sin esperar. El texto de FormatMessageA es el
 * mensaje del error del sistema operativo. En macOS un .exe no se puede
 * ejecutar ("Exec format error"), así que se toma la rama de fallo del
 * original; en Linux con binfmt_misc + Wine arrancaría gdkup.exe como en
 * Windows. WaitForInputIdle no tiene equivalente (espera a que una
 * aplicación gráfica atienda su cola de mensajes) y no se espera.
 * ⚠️ VERIFICAR: el reparto en argumentos es el sencillo (sin las reglas de
 * barras invertidas de CommandLineToArgvW); la única llamada del cliente
 * no lleva comillas.
 */
public final class NativeSysProcess {
   private NativeSysProcess() {
   }

   /**
    * CreateProcSpecial (0x00404740). The client's only call is the updater
    * (NetUpdate.runUpdates: {@code .\bin\gdkup.exe updates.lst}), a Windows
    * program: its command line without the program ("updates.lst &lt;pid&gt;")
    * is left in {@link GdkUp#PENDING} and true is returned, as if it had
    * started. Whoever started the client (the launcher, run_gamma.sh) runs
    * {@link GdkUp} with it once the client has ended, which is what
    * gdkup.exe does by waiting for its parent process.
    */
   public static boolean createProcSpecial(String program, String args) {
      String line = commandLine(program, args, pid());
      List<String> argv = split(line);
      if (!argv.isEmpty() && isGdkUp(argv.get(0))) {
         StringBuilder rest = new StringBuilder();
         for (int i = 1; i < argv.size(); i++) {
            rest.append(i > 1 ? " " : "").append(argv.get(i));
         }
         try {
            java.nio.file.Files.write(new File(System.getProperty("user.dir"), GdkUp.PENDING).toPath(),
               (rest + System.lineSeparator()).getBytes("ISO-8859-1"));
            System.err.println("[gdkup] pendiente: " + rest);
            return true;
         } catch (IOException e) {
            System.err.println("Internal error - can't execute \"" + line + "\"");
            System.err.println(e.getMessage());
            System.err.flush();
            return false;
         }
      }
      if (!argv.isEmpty()) {
         String exe = argv.get(0);
         String base = exe.substring(Math.max(exe.lastIndexOf('\\'), exe.lastIndexOf('/')) + 1);
         if (base.indexOf('.') < 0) {
            exe = exe + ".exe";
         }
         argv.set(0, NativeMock.localFile(exe).getPath());
      }
      try {
         new ProcessBuilder(argv).directory(new File(System.getProperty("user.dir"))).inheritIO().start();
         return true;
      } catch (IOException | RuntimeException e) {
         System.err.println("Internal error - can't execute \"" + line + "\"");
         System.err.println(e.getMessage());
         System.err.flush();
         return false;
      }
   }

   static boolean isGdkUp(String exe) {
      String base = exe.substring(Math.max(exe.lastIndexOf('\\'), exe.lastIndexOf('/')) + 1).toLowerCase(java.util.Locale.ROOT);
      return base.equals("gdkup.exe") || base.equals("gdkup");
   }

   /** wsprintfA "%s %s %lu" (0x0046d620). */
   static String commandLine(String program, String args, long pid) {
      return program + " " + args + " " + pid;
   }

   /** Elementos de la línea: espacios o tabuladores separan, las comillas agrupan y se quitan. */
   static List<String> split(String line) {
      List<String> out = new ArrayList<String>();
      StringBuilder cur = new StringBuilder();
      boolean quoted = false;
      boolean any = false;
      for (int i = 0; i < line.length(); i++) {
         char c = line.charAt(i);
         if (c == '"') {
            quoted = !quoted;
            any = true;
         } else if (!quoted && (c == ' ' || c == '\t')) {
            if (any) {
               out.add(cur.toString());
               cur.setLength(0);
               any = false;
            }
         } else {
            cur.append(c);
            any = true;
         }
      }
      if (any) {
         out.add(cur.toString());
      }
      return out;
   }

   /** GetCurrentProcessId: el PID del JVM ("pid@host" de RuntimeMXBean, válido con --release 8). */
   static long pid() {
      String n = java.lang.management.ManagementFactory.getRuntimeMXBean().getName();
      int at = n.indexOf('@');
      try {
         return Long.parseLong(at > 0 ? n.substring(0, at) : n);
      } catch (NumberFormatException e) {
         return 0L;
      }
   }
}

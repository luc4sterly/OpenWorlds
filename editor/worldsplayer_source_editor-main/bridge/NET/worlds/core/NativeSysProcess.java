package NET.worlds.core;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * {@code NetUpdate.CreateProcSpecial} (gamma.dll 0x00404740): launches the
 * updater ({@code .\bin\gdkup.exe <list>}) with the client's PID.
 *
 * <p>From gamma.dll: the command line is {@code wsprintfA("%s %s %lu",
 * program, arguments, GetCurrentProcessId())} (0x0046d620); if
 * CreateProcessA fails, it writes to its log stream (0x49eda8, the same one
 * that NativeAssert sends to stderr) {@code Internal error - can't execute "}
 * + line + {@code "} (0x0046d630 / 0x0046d62c) with a line ending, then the
 * text of FormatMessageA(GetLastError()) with a line ending, and returns
 * false; if it starts, WaitForInputIdle, closes the handles and returns true.
 *
 * <p>Substitute for CreateProcessA(NULL, line, ..., DETACHED_PROCESS): the
 * first element of the line (in quotes if it has them) is the program,
 * with ".exe" if it has no extension, relative to the current directory and
 * resolved by {@code NativeMock.localFile}; the rest is split into
 * arguments at spaces, respecting quotes; it is started with
 * {@code ProcessBuilder} without waiting. The FormatMessageA text is the
 * operating system's error message. On macOS a .exe cannot be
 * executed ("Exec format error"), so the original's failure branch is taken;
 * on Linux with binfmt_misc + Wine it would start gdkup.exe as on
 * Windows. WaitForInputIdle has no equivalent (it waits for a graphical
 * application to service its message queue) and is not waited for.
 * ⚠️ VERIFY: the split into arguments is the simple one (without the
 * backslash rules of CommandLineToArgvW); the client's only call
 * has no quotes.
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

   /** Elements of the line: spaces or tabs separate, quotes group and are removed. */
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

   /** GetCurrentProcessId: the JVM's PID ("pid@host" from RuntimeMXBean, valid with --release 8). */
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

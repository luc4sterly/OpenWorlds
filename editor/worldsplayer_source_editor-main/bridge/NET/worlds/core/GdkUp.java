package NET.worlds.core;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;

/**
 * gdkup.exe (\GAMMA\network\gdkup\gdkup.cpp, decompiled-native/gdkup_exe) in
 * Java, in the mode the client uses: {@code gdkup <scriptFile> <parentProcID>}
 * (NetUpdate.runUpdates through CreateProcSpecial, gamma.dll 0x00404740).
 * gdkup.exe cannot run outside Windows, so {@link NativeSysProcess} leaves the
 * request in gdkup.pending and whoever started the client (the launcher,
 * run_gamma.sh) runs this once the client has exited; the original waits for
 * the parent process in a thread too (0x00401ced).
 *
 * <p>From WinMain (0x004020a9) and the dialog procedure (0x00401e75): the
 * command line is split at its last space (script, parent PID); up to 0x400
 * lines of the script are read (fgets, without the newline); none is
 * "Script file is not valid". Then each line runs
 * in order as a command line (0x00401d52: CreateProcessA with the line;
 * DETACHED_PROCESS, CREATE_NEW_CONSOLE for the last one) and the status shows
 * the lines still to go ("%d"). When a line's process ends: a line with
 * "xdelta patch " deletes the patch file (the word after it), any other line
 * deletes the file named by the whole line, which is the downloaded package;
 * then the next line runs. The last line (run.exe world:restart) is started
 * and gdkup ends without waiting for it. A line that cannot start shows
 * "Internal error - can't execute %s" and ends gdkup. The exit code of a
 * line's process is never read (the 0x402 message of 0x00401e75): an
 * installer that stops after its own message box (NSIS "This update
 * requires world version 37...", Wise "You can't install...") still has its
 * package deleted, and the next line runs, the restart included.
 *
 * <p>What "running" a line means here, since the programs are Windows ones:
 * a world package (&lt;World&gt;\&lt;World&gt;N.exe) is installed by
 * {@link WisePackage} or {@link NsisPackage}, as its installer would; run.exe
 * is the client itself, so the restart is handed back to the caller (exit
 * code {@link #RESTART}, arguments on a "[gdkup] restart:" line); an xdelta
 * patch (the incremental upgrades of the old worlds) is not supported and ends
 * like an installer that fails. Only a missing file or one that is not a
 * Windows executable (no "MZ") counts as a line that cannot start.
 *
 * <p>Exit codes: 0 done, {@link #RESTART} done and the client must start
 * again, 1 bad script, 2 a line could not start.
 */
public final class GdkUp {
   public static final int RESTART = 10;
   public static final String PENDING = "gdkup.pending";

   private GdkUp() {
   }

   public static void main(String[] args) {
      System.exit(run(args, new File("."), System.out));
   }

   /** Runs "gdkup script [pid]" with dir as the current directory (the client's home). */
   public static int run(String[] args, File dir, PrintStream log) {
      if (args.length < 1) {
         log.println("Usage: gdkup scriptFile parentProcID OR gdkup url");
         return 1;
      }
      File script = child(dir, args[0]);
      List<String> lines;
      try {
         lines = readScript(script);
      } catch (IOException e) {
         log.println("[gdkup] Error opening script file \"" + args[0] + "\"");
         return 1;
      }
      if (lines.isEmpty()) {
         log.println("[gdkup] Script file is not valid");
         return 1;
      }
      for (int i = 0; i < lines.size(); i++) {
         String line = lines.get(i);
         log.println("[gdkup] " + (lines.size() - i - 1) + "  " + line);
         List<String> argv = NativeSysProcess.split(line);
         String prog = argv.isEmpty() ? "" : base(argv.get(0)).toLowerCase(java.util.Locale.ROOT);
         if (prog.equals("run.exe") || prog.equals("run")) {
            StringBuilder rest = new StringBuilder();
            for (int k = 1; k < argv.size(); k++) {
               rest.append(k > 1 ? " " : "").append(argv.get(k));
            }
            log.println("[gdkup] restart: " + rest);
            return RESTART;
         }
         try {
            runLine(argv, dir, log);
         } catch (CannotStart e) {
            log.println("[gdkup] Internal error - can't execute " + line);
            log.println("[gdkup] " + e.getMessage());
            return 2;
         } catch (IOException e) {
            // the installer ran and failed (an abort after its own message,
            // or what the bridge cannot do): gdkup.exe does not read exit
            // codes, it goes on as with any line whose process ended
            log.println("[gdkup] " + line + ": " + e.getMessage());
         }
         int x = line.indexOf("xdelta patch ");
         String done = line;
         if (x >= 0) {
            done = line.substring(x + 13);
            int sp = done.indexOf(' ');
            done = sp >= 0 ? done.substring(0, sp) : done;
         }
         File f = child(dir, done.replace('\\', '/'));
         if (f.isFile() && !f.delete()) {
            log.println("[gdkup] could not delete " + f);
         }
      }
      return 0;
   }

   /** CreateProcessA would fail: the line ends gdkup (0x00401d52). */
   static final class CannotStart extends IOException {
      CannotStart(String m) {
         super(m);
      }
   }

   private static void runLine(List<String> argv, File dir, PrintStream log) throws IOException {
      if (argv.isEmpty()) {
         throw new CannotStart("linea vacia");
      }
      String prog = argv.get(0);
      if (base(prog).toLowerCase(java.util.Locale.ROOT).startsWith("xdelta")) {
         throw new IOException("los parches xdelta no estan soportados");
      }
      File exe = child(dir, prog.replace('\\', '/'));
      if (!exe.isFile()) {
         throw new CannotStart("no existe " + exe);
      }
      byte[] head = new byte[4096];
      FileInputStream in = new FileInputStream(exe);
      try {
         int n = in.read(head);
         if (n < 2 || head[0] != 'M' || head[1] != 'Z') {
            throw new CannotStart(exe.getName() + " no es un ejecutable de Windows");
         }
      } finally {
         in.close();
      }
      byte[] d = Files.readAllBytes(exe.toPath());
      if (NsisPackage.is(d)) {
         NsisPackage.install(exe, log);
      } else if (WisePackage.is(d)) {
         WisePackage.install(exe, dir, log);
      } else {
         throw new IOException(exe.getName() + " is not a known world package (Wise or NSIS)");
      }
   }

   /**
    * The script's lines, 0x400 at most. gdkup reads them with fgets and drops
    * each one's last character (the newline); readLine gives the same, except
    * for a last line with no newline, whose last character gdkup would lose
    * (NetUpdate.writeScriptFile ends every line with println).
    */
   static List<String> readScript(File f) throws IOException {
      List<String> out = new ArrayList<String>();
      BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(f), "ISO-8859-1"));
      try {
         String s;
         while (out.size() < 0x400 && (s = r.readLine()) != null) {
            out.add(s);
         }
      } finally {
         r.close();
      }
      return out;
   }

   private static String base(String p) {
      String s = p.replace('\\', '/');
      return s.substring(s.lastIndexOf('/') + 1);
   }

   /** dir/name with each segment matched without case when it exists (Windows lookup). */
   static File child(File dir, String name) {
      File cur = dir;
      for (String part : name.replace('\\', '/').split("/")) {
         if (part.isEmpty() || part.equals(".")) {
            continue;
         }
         File exact = new File(cur, part);
         if (!exact.exists()) {
            String[] names = cur.list();
            if (names != null) {
               for (String n : names) {
                  if (n.equalsIgnoreCase(part)) {
                     exact = new File(cur, n);
                     break;
                  }
               }
            }
         }
         cur = exact;
      }
      return cur;
   }
}

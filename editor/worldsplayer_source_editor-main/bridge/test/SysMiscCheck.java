package NET.worlds.core;

import NET.worlds.scape.Persister;
import NET.worlds.scape.RenderWare;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.PrintStream;
import java.util.List;

/**
 * The rest of the system natives: NetUpdate.CreateProcSpecial (0x00404740),
 * Restorer.makeArray (0x0041a8d0) through a real save/restore,
 * RenderWare.get3DHardware* (0x0043c4f0/510) and Pilot.nativeInit
 * (0x0041a900). Exits with 1 if anything fails.
 */
public final class SysMiscCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // wsprintfA "%s %s %lu"
      eqs("line", NativeSysProcess.commandLine(".\\bin\\gdkup.exe", "updates.lst", 1234L), ".\\bin\\gdkup.exe updates.lst 1234");
      List<String> a = NativeSysProcess.split("\"c:\\Program Files\\x.exe\" a  \"b c\" 7");
      eqs("split", a.toString(), "[c:\\Program Files\\x.exe, a, b c, 7]");
      check("pid", NativeSysProcess.pid() > 0);

      // CreateProcessA that fails: two lines in the native log and false
      PrintStream err = System.err;
      ByteArrayOutputStream buf = new ByteArrayOutputStream();
      System.setErr(new PrintStream(buf, true));
      boolean ok = NativeSysProcess.createProcSpecial(".\\nonexistent", "updates.lst");
      System.setErr(err);
      String log = buf.toString();
      check("fails -> false", !ok);
      String want = "Internal error - can't execute \".\\nonexistent updates.lst " + NativeSysProcess.pid() + "\"\n";
      check("literal message: " + log, log.startsWith(want) && log.length() > want.length() + 1);

      // makeArray = NewObjectArray: a Persister[] saved and restored
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      Saver s = new Saver(new DataOutputStream(bytes));
      s.saveArray(new Persister[2]);
      Restorer r = new Restorer(new DataInputStream(new ByteArrayInputStream(bytes.toByteArray())));
      Persister[] back = r.restoreArray();
      check("restoreArray not null", back != null);
      check("type Persister[]", back != null && back.getClass() == Persister[].class);
      check("length 2 with nulls", back != null && back.length == 2 && back[0] == null && back[1] == null);

      // DAT_00489578 / DAT_0048957c: only the Direct3D driver sets them to 1
      check("3D hardware in use", !RenderWare.get3DHardwareInUse());
      check("3D hardware available", !RenderWare.get3DHardwareAvailable());

      // Pilot.nativeInit: the cameraMode field exists and is an int (otherwise, exit 41)
      NET.worlds.scape.Pilot.nativeInit();

      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("SysMiscCheck OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}

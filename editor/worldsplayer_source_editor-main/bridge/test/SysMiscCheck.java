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
 * El resto de nativos de sistema: NetUpdate.CreateProcSpecial (0x00404740),
 * Restorer.makeArray (0x0041a8d0) por un guardado/restaurado real,
 * RenderWare.get3DHardware* (0x0043c4f0/510) y Pilot.nativeInit
 * (0x0041a900). Sale con 1 si algo falla.
 */
public final class SysMiscCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // wsprintfA "%s %s %lu"
      eqs("línea", NativeSysProcess.commandLine(".\\bin\\gdkup.exe", "updates.lst", 1234L), ".\\bin\\gdkup.exe updates.lst 1234");
      List<String> a = NativeSysProcess.split("\"c:\\Program Files\\x.exe\" a  \"b c\" 7");
      eqs("reparto", a.toString(), "[c:\\Program Files\\x.exe, a, b c, 7]");
      check("pid", NativeSysProcess.pid() > 0);

      // CreateProcessA que falla: dos líneas en el log nativo y false
      PrintStream err = System.err;
      ByteArrayOutputStream buf = new ByteArrayOutputStream();
      System.setErr(new PrintStream(buf, true));
      boolean ok = NativeSysProcess.createProcSpecial(".\\no\\existe", "updates.lst");
      System.setErr(err);
      String log = buf.toString();
      check("falla -> false", !ok);
      String want = "Internal error - can't execute \".\\no\\existe updates.lst " + NativeSysProcess.pid() + "\"\n";
      check("mensaje literal: " + log, log.startsWith(want) && log.length() > want.length() + 1);

      // makeArray = NewObjectArray: un Persister[] guardado y restaurado
      ByteArrayOutputStream bytes = new ByteArrayOutputStream();
      Saver s = new Saver(new DataOutputStream(bytes));
      s.saveArray(new Persister[2]);
      Restorer r = new Restorer(new DataInputStream(new ByteArrayInputStream(bytes.toByteArray())));
      Persister[] back = r.restoreArray();
      check("restoreArray no nulo", back != null);
      check("tipo Persister[]", back != null && back.getClass() == Persister[].class);
      check("longitud 2 con nulos", back != null && back.length == 2 && back[0] == null && back[1] == null);

      // DAT_00489578 / DAT_0048957c: solo el driver Direct3D los pone a 1
      check("3D hardware en uso", !RenderWare.get3DHardwareInUse());
      check("3D hardware disponible", !RenderWare.get3DHardwareAvailable());

      // Pilot.nativeInit: el campo cameraMode existe y es int (si no, exit 41)
      NET.worlds.scape.Pilot.nativeInit();

      if (failures > 0) {
         System.out.println(failures + " fallos");
         System.exit(1);
      }
      System.out.println("SysMiscCheck OK");
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FALLA " + what);
      }
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}

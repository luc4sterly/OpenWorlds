package NET.worlds.core;

import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

/**
 * RegKey (gamma.dll 0x00402360-0x00402770) over NativeSysRegistry: roots,
 * "Key not found: N" messages with the Win32 code, handle rights, value
 * types, 0x400-byte buffer, closed handles and REGEDIT4 persistence.
 * Exits with 1 if anything fails.
 */
public final class SysRegKeyCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File store = File.createTempFile("fw-registry", ".reg");
      store.delete();
      System.setProperty("openworlds.registry", store.getPath());
      final int HKLM = 0x80000002;

      // getReservedKey 0x004023f0: table of 4 and literal "Key not found: 0"
      eq("HKCR", NativeSysRegistry.reservedKey(0), 0x80000000);
      eq("HKLM", NativeSysRegistry.reservedKey(2), HKLM);
      eq("HKU", NativeSysRegistry.reservedKey(3), 0x80000003);
      eqs("root 4", thrown(() -> NativeSysRegistry.reservedKey(4)), "Key not found: 0");
      eqs("root -1", thrown(() -> NativeSysRegistry.reservedKey(-1)), "Key not found: 0");

      // nonexistent key: RegOpenKeyExA -> ERROR_FILE_NOT_FOUND (2)
      String path = "SOFTWARE\\Worlds, Inc.\\3DCD";
      eqs("open nonexistent", thrown(() -> NativeSysRegistry.openKey(HKLM, path, 0)), "Key not found: 2");
      check("without changes there is no file", !store.exists());

      // createKey 0x00402770: creates the intermediate ones, handle with write access
      int h = NativeSysRegistry.createKey(HKLM, path);
      check("handle created != 0", h != 0);
      check("creating writes the store", store.isFile());
      check("setString", NativeSysRegistry.setString(h, "InstallDir", "C:\\Worlds", false));
      eqs("getString case-insensitive", NativeSysRegistry.getString(h, "installdir"), "C:\\Worlds");
      check("overwrite", NativeSysRegistry.setString(h, "INSTALLDIR", "C:\\Worlds2", false));
      eqs("overwritten", NativeSysRegistry.getString(h, "InstallDir"), "C:\\Worlds2");
      check("default value", NativeSysRegistry.setString(h, "", "def", false));
      eqs("@", NativeSysRegistry.getString(h, ""), "def");
      eqs("nonexistent value", NativeSysRegistry.getString(h, "nada"), null);

      // REG_EXPAND_SZ (setStringValue var3 = true): returned unexpanded
      check("expand", NativeSysRegistry.setString(h, "Path", "%WINDIR%\\x", true));
      eqs("expand unexpanded", NativeSysRegistry.getString(h, "Path"), "%WINDIR%\\x");

      // REG_DWORD 0x004025c0 / 0x00402640
      check("setInt", NativeSysRegistry.setInt(h, "Count", 0x7f));
      eq("getInt", NativeSysRegistry.getInt(h, "Count"), 127);
      check("negative setInt", NativeSysRegistry.setInt(h, "Neg", -2));
      eq("negative getInt", NativeSysRegistry.getInt(h, "Neg"), -2);
      eqs("getString of a DWORD -> null (type 4)", NativeSysRegistry.getString(h, "Count"), null);
      eq("getInt of a string -> 0", NativeSysRegistry.getInt(h, "InstallDir"), 0);
      eq("nonexistent getInt -> 0", NativeSysRegistry.getInt(h, "nada"), 0);

      // 0x400 buffer: strlen + 1 <= 1024
      check("1023 ASCII", NativeSysRegistry.setString(h, "Big", rep('a', 1023), false));
      eq("1023 ASCII fit (1024 bytes)", len(NativeSysRegistry.getString(h, "Big")), 1023);
      NativeSysRegistry.setString(h, "Big", rep('a', 1024), false);
      eqs("1024 ASCII -> ERROR_MORE_DATA -> null", NativeSysRegistry.getString(h, "Big"), null);
      NativeSysRegistry.setString(h, "Big", rep('\u00e9', 511), false);
      eq("511 x 'é' = 1022 + 1 bytes fit", len(NativeSysRegistry.getString(h, "Big")), 511);
      NativeSysRegistry.setString(h, "Big", rep('\u00e9', 512), false);
      eqs("512 x 'é' = 1024 + 1 bytes do not fit", NativeSysRegistry.getString(h, "Big"), null);
      NativeSysRegistry.setString(h, "Big", "x", false);

      // openKey mode 0 = KEY_READ 0x20019: read yes, write no (ERROR_ACCESS_DENIED)
      int r = NativeSysRegistry.openKey(HKLM, "software\\WORLDS, INC.\\3dcd", 0);
      check("new handle", r != h);
      eqs("read via KEY_READ", NativeSysRegistry.getString(r, "InstallDir"), "C:\\Worlds2");
      check("writing via KEY_READ fails", !NativeSysRegistry.setString(r, "InstallDir", "otro", false));
      check("setInt via KEY_READ fails", !NativeSysRegistry.setInt(r, "Count", 1));
      eqs("no change", NativeSysRegistry.getString(h, "InstallDir"), "C:\\Worlds2");
      eqs("create under KEY_READ", thrown(() -> NativeSysRegistry.createKey(r, "Nueva")), "Key not found: 5");
      int r2 = NativeSysRegistry.createKey(r, "");
      check("createKey of the same key under KEY_READ works", r2 != 0);
      // mode 1 (0x2001f) does write
      int w = NativeSysRegistry.openKey(HKLM, path, 1);
      check("writing via mode 1", NativeSysRegistry.setString(w, "Mode1", "si", false));
      // "" = the key itself
      int same = NativeSysRegistry.openKey(w, "", 0);
      eqs("empty subkey", NativeSysRegistry.getString(same, "Mode1"), "si");
      eqs("empty component", thrown(() -> NativeSysRegistry.openKey(HKLM, "SOFTWARE\\\\Worlds, Inc.", 0)), "Key not found: 2");

      // closed handle: ERROR_INVALID_HANDLE (6)
      NativeSysRegistry.close(r);
      eqs("getString of a closed handle", NativeSysRegistry.getString(r, "InstallDir"), null);
      eq("getInt of a closed handle", NativeSysRegistry.getInt(r, "Count"), 0);
      check("setString of a closed handle", !NativeSysRegistry.setString(r, "x", "y", false));
      eqs("openKey under a closed handle", thrown(() -> NativeSysRegistry.openKey(r, "", 0)), "Key not found: 6");
      eqs("createKey under handle 0", thrown(() -> NativeSysRegistry.createKey(0, "x")), "Key not found: 6");
      // closing a predefined root does not invalidate it
      NativeSysRegistry.close(HKLM);
      check("HKLM after closing it", NativeSysRegistry.openKey(HKLM, path, 0) != 0);

      // REGEDIT4 escapes and persistence
      check("quotes", NativeSysRegistry.setString(h, "Q\"n\\", "a\"b\\c", false));
      String text = new String(Files.readAllBytes(store.toPath()), StandardCharsets.UTF_8);
      check("REGEDIT4 header", text.startsWith("REGEDIT4\r\n"));
      check("section", text.contains("\r\n[HKEY_LOCAL_MACHINE\\SOFTWARE\\Worlds, Inc.\\3DCD]\r\n"));
      check("intermediate", text.contains("\r\n[HKEY_LOCAL_MACHINE\\SOFTWARE]\r\n"));
      check("REG_SZ", text.contains("\"InstallDir\"=\"C:\\\\Worlds2\"\r\n"));
      check("@", text.contains("@=\"def\"\r\n"));
      check("REG_DWORD", text.contains("\"Count\"=dword:0000007f\r\n"));
      check("negative REG_DWORD", text.contains("\"Neg\"=dword:fffffffe\r\n"));
      check("REG_EXPAND_SZ", text.contains("\"Path\"=hex(2):25,57,49,4e,44,49,52,25,5c,78,00\r\n"));
      check("escapes", text.contains("\"Q\\\"n\\\\\"=\"a\\\"b\\\\c\"\r\n"));

      NativeSysRegistry.reload();
      eqs("old handle does not survive", NativeSysRegistry.getString(h, "InstallDir"), null);
      int again = NativeSysRegistry.openKey(HKLM, path, 0);
      eqs("persisted REG_SZ", NativeSysRegistry.getString(again, "InstallDir"), "C:\\Worlds2");
      eqs("persisted @", NativeSysRegistry.getString(again, ""), "def");
      eq("persisted DWORD", NativeSysRegistry.getInt(again, "Count"), 127);
      eq("persisted negative DWORD", NativeSysRegistry.getInt(again, "Neg"), -2);
      eqs("persisted EXPAND", NativeSysRegistry.getString(again, "Path"), "%WINDIR%\\x");
      eqs("persisted escapes", NativeSysRegistry.getString(again, "q\"N\\"), "a\"b\\c");
      eq("EXPAND is still not a DWORD", NativeSysRegistry.getInt(again, "Path"), 0);

      // through the client's own class: the NetUpdate path (opens with 0 and
      // writes InstallDir: in the original it fails the same way, KEY_READ)
      RegKey lm = RegKey.getRootKey(2);
      RegKey k = new RegKey(lm, path, 0);
      eqs("RegKey.getStringValue", k.getStringValue("InstallDir"), "C:\\Worlds2");
      check("RegKey.setStringValue via KEY_READ = false", !k.setStringValue("InstallDir", "D:\\x", false));
      k.close();
      eqs("RegKey after close", k.getStringValue("InstallDir"), null);
      eqs("RegKey.getRootKey(9)", thrown(() -> RegKey.getRootKey(9)), "Key not found: 0");
      eqs("new RegKey nonexistent", thrown(() -> new RegKey(lm, "SOFTWARE\\No", 0)), "Key not found: 2");
      RegKey c = new RegKey(lm, "SOFTWARE\\Classes\\world", 2);
      check("RegKey mode 2 creates", c.setIntValue("n", 5));
      eq("RegKey.getIntValue", c.getIntValue("n"), 5);
      // createKey throws RegKeyNotFoundException without declaring it, like JNI
      String sneaky;
      try {
         new RegKey(k, "x", 2);
         sneaky = null;
      } catch (RegKeyNotFoundException e) {
         sneaky = e.getMessage();
      }
      eqs("createKey under a closed handle", sneaky, "Key not found: 6");

      store.delete();
      if (failures > 0) {
         System.out.println(failures + " failures");
         System.exit(1);
      }
      System.out.println("SysRegKeyCheck OK");
   }

   interface Call {
      Object run() throws Exception;
   }

   private static String thrown(Call c) {
      try {
         c.run();
         return "(no exception)";
      } catch (RegKeyNotFoundException e) {
         return e.getMessage();
      } catch (Exception e) {
         return "other: " + e;
      }
   }

   private static String rep(char c, int n) {
      StringBuilder b = new StringBuilder();
      for (int i = 0; i < n; i++) {
         b.append(c);
      }
      return b.toString();
   }

   private static int len(String s) {
      return s == null ? -1 : s.length();
   }

   private static void check(String what, boolean ok) {
      if (!ok) {
         failures++;
         System.out.println("FAIL " + what);
      }
   }

   private static void eq(String what, int got, int want) {
      check(what + ": " + got + " != " + want, got == want);
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}

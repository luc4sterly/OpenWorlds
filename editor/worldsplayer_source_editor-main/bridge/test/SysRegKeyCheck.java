package NET.worlds.core;

import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;

/**
 * RegKey (gamma.dll 0x00402360-0x00402770) sobre NativeSysRegistry: raíces,
 * mensajes "Key not found: N" con el código Win32, derechos del asa, tipos
 * de valor, búfer de 0x400 bytes, asas cerradas y persistencia REGEDIT4.
 * Sale con 1 si algo falla.
 */
public final class SysRegKeyCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File store = File.createTempFile("fw-registry", ".reg");
      store.delete();
      System.setProperty("freeworlds.registry", store.getPath());
      final int HKLM = 0x80000002;

      // getReservedKey 0x004023f0: tabla de 4 y "Key not found: 0" literal
      eq("HKCR", NativeSysRegistry.reservedKey(0), 0x80000000);
      eq("HKLM", NativeSysRegistry.reservedKey(2), HKLM);
      eq("HKU", NativeSysRegistry.reservedKey(3), 0x80000003);
      eqs("raíz 4", thrown(() -> NativeSysRegistry.reservedKey(4)), "Key not found: 0");
      eqs("raíz -1", thrown(() -> NativeSysRegistry.reservedKey(-1)), "Key not found: 0");

      // clave inexistente: RegOpenKeyExA -> ERROR_FILE_NOT_FOUND (2)
      String path = "SOFTWARE\\Worlds, Inc.\\3DCD";
      eqs("abrir inexistente", thrown(() -> NativeSysRegistry.openKey(HKLM, path, 0)), "Key not found: 2");
      check("sin cambios no hay fichero", !store.exists());

      // createKey 0x00402770: crea las intermedias, asa con escritura
      int h = NativeSysRegistry.createKey(HKLM, path);
      check("asa creada != 0", h != 0);
      check("crear escribe el almacén", store.isFile());
      check("setString", NativeSysRegistry.setString(h, "InstallDir", "C:\\Worlds", false));
      eqs("getString sin distinguir mayúsculas", NativeSysRegistry.getString(h, "installdir"), "C:\\Worlds");
      check("sobrescribir", NativeSysRegistry.setString(h, "INSTALLDIR", "C:\\Worlds2", false));
      eqs("sobrescrito", NativeSysRegistry.getString(h, "InstallDir"), "C:\\Worlds2");
      check("valor por defecto", NativeSysRegistry.setString(h, "", "def", false));
      eqs("@", NativeSysRegistry.getString(h, ""), "def");
      eqs("valor inexistente", NativeSysRegistry.getString(h, "nada"), null);

      // REG_EXPAND_SZ (setStringValue var3 = true): se devuelve sin expandir
      check("expand", NativeSysRegistry.setString(h, "Path", "%WINDIR%\\x", true));
      eqs("expand sin expandir", NativeSysRegistry.getString(h, "Path"), "%WINDIR%\\x");

      // REG_DWORD 0x004025c0 / 0x00402640
      check("setInt", NativeSysRegistry.setInt(h, "Count", 0x7f));
      eq("getInt", NativeSysRegistry.getInt(h, "Count"), 127);
      check("setInt negativo", NativeSysRegistry.setInt(h, "Neg", -2));
      eq("getInt negativo", NativeSysRegistry.getInt(h, "Neg"), -2);
      eqs("getString de un DWORD -> null (tipo 4)", NativeSysRegistry.getString(h, "Count"), null);
      eq("getInt de una cadena -> 0", NativeSysRegistry.getInt(h, "InstallDir"), 0);
      eq("getInt inexistente -> 0", NativeSysRegistry.getInt(h, "nada"), 0);

      // búfer de 0x400: strlen + 1 <= 1024
      check("1023 ASCII", NativeSysRegistry.setString(h, "Big", rep('a', 1023), false));
      eq("1023 ASCII caben (1024 bytes)", len(NativeSysRegistry.getString(h, "Big")), 1023);
      NativeSysRegistry.setString(h, "Big", rep('a', 1024), false);
      eqs("1024 ASCII -> ERROR_MORE_DATA -> null", NativeSysRegistry.getString(h, "Big"), null);
      NativeSysRegistry.setString(h, "Big", rep('\u00e9', 511), false);
      eq("511 x 'é' = 1022 + 1 bytes caben", len(NativeSysRegistry.getString(h, "Big")), 511);
      NativeSysRegistry.setString(h, "Big", rep('\u00e9', 512), false);
      eqs("512 x 'é' = 1024 + 1 bytes no caben", NativeSysRegistry.getString(h, "Big"), null);
      NativeSysRegistry.setString(h, "Big", "x", false);

      // openKey modo 0 = KEY_READ 0x20019: leer sí, escribir no (ERROR_ACCESS_DENIED)
      int r = NativeSysRegistry.openKey(HKLM, "software\\WORLDS, INC.\\3dcd", 0);
      check("asa nueva", r != h);
      eqs("leer por KEY_READ", NativeSysRegistry.getString(r, "InstallDir"), "C:\\Worlds2");
      check("escribir por KEY_READ falla", !NativeSysRegistry.setString(r, "InstallDir", "otro", false));
      check("setInt por KEY_READ falla", !NativeSysRegistry.setInt(r, "Count", 1));
      eqs("sin cambio", NativeSysRegistry.getString(h, "InstallDir"), "C:\\Worlds2");
      eqs("crear bajo KEY_READ", thrown(() -> NativeSysRegistry.createKey(r, "Nueva")), "Key not found: 5");
      int r2 = NativeSysRegistry.createKey(r, "");
      check("createKey de la misma clave bajo KEY_READ vale", r2 != 0);
      // modo 1 (0x2001f) sí escribe
      int w = NativeSysRegistry.openKey(HKLM, path, 1);
      check("escribir por modo 1", NativeSysRegistry.setString(w, "Mode1", "si", false));
      // "" = la propia clave
      int same = NativeSysRegistry.openKey(w, "", 0);
      eqs("subclave vacía", NativeSysRegistry.getString(same, "Mode1"), "si");
      eqs("componente vacío", thrown(() -> NativeSysRegistry.openKey(HKLM, "SOFTWARE\\\\Worlds, Inc.", 0)), "Key not found: 2");

      // asa cerrada: ERROR_INVALID_HANDLE (6)
      NativeSysRegistry.close(r);
      eqs("getString de asa cerrada", NativeSysRegistry.getString(r, "InstallDir"), null);
      eq("getInt de asa cerrada", NativeSysRegistry.getInt(r, "Count"), 0);
      check("setString de asa cerrada", !NativeSysRegistry.setString(r, "x", "y", false));
      eqs("openKey bajo asa cerrada", thrown(() -> NativeSysRegistry.openKey(r, "", 0)), "Key not found: 6");
      eqs("createKey bajo asa 0", thrown(() -> NativeSysRegistry.createKey(0, "x")), "Key not found: 6");
      // cerrar una raíz predefinida no la invalida
      NativeSysRegistry.close(HKLM);
      check("HKLM tras cerrarla", NativeSysRegistry.openKey(HKLM, path, 0) != 0);

      // escapes de REGEDIT4 y persistencia
      check("comillas", NativeSysRegistry.setString(h, "Q\"n\\", "a\"b\\c", false));
      String text = new String(Files.readAllBytes(store.toPath()), StandardCharsets.UTF_8);
      check("cabecera REGEDIT4", text.startsWith("REGEDIT4\r\n"));
      check("sección", text.contains("\r\n[HKEY_LOCAL_MACHINE\\SOFTWARE\\Worlds, Inc.\\3DCD]\r\n"));
      check("intermedia", text.contains("\r\n[HKEY_LOCAL_MACHINE\\SOFTWARE]\r\n"));
      check("REG_SZ", text.contains("\"InstallDir\"=\"C:\\\\Worlds2\"\r\n"));
      check("@", text.contains("@=\"def\"\r\n"));
      check("REG_DWORD", text.contains("\"Count\"=dword:0000007f\r\n"));
      check("REG_DWORD negativo", text.contains("\"Neg\"=dword:fffffffe\r\n"));
      check("REG_EXPAND_SZ", text.contains("\"Path\"=hex(2):25,57,49,4e,44,49,52,25,5c,78,00\r\n"));
      check("escapes", text.contains("\"Q\\\"n\\\\\"=\"a\\\"b\\\\c\"\r\n"));

      NativeSysRegistry.reload();
      eqs("asa vieja no sobrevive", NativeSysRegistry.getString(h, "InstallDir"), null);
      int again = NativeSysRegistry.openKey(HKLM, path, 0);
      eqs("persistido REG_SZ", NativeSysRegistry.getString(again, "InstallDir"), "C:\\Worlds2");
      eqs("persistido @", NativeSysRegistry.getString(again, ""), "def");
      eq("persistido DWORD", NativeSysRegistry.getInt(again, "Count"), 127);
      eq("persistido DWORD negativo", NativeSysRegistry.getInt(again, "Neg"), -2);
      eqs("persistido EXPAND", NativeSysRegistry.getString(again, "Path"), "%WINDIR%\\x");
      eqs("persistido escapes", NativeSysRegistry.getString(again, "q\"N\\"), "a\"b\\c");
      eq("EXPAND sigue sin ser DWORD", NativeSysRegistry.getInt(again, "Path"), 0);

      // por la propia clase del cliente: el camino de NetUpdate (abre con 0 y
      // escribe InstallDir: en el original falla igual, KEY_READ)
      RegKey lm = RegKey.getRootKey(2);
      RegKey k = new RegKey(lm, path, 0);
      eqs("RegKey.getStringValue", k.getStringValue("InstallDir"), "C:\\Worlds2");
      check("RegKey.setStringValue por KEY_READ = false", !k.setStringValue("InstallDir", "D:\\x", false));
      k.close();
      eqs("RegKey tras close", k.getStringValue("InstallDir"), null);
      eqs("RegKey.getRootKey(9)", thrown(() -> RegKey.getRootKey(9)), "Key not found: 0");
      eqs("new RegKey inexistente", thrown(() -> new RegKey(lm, "SOFTWARE\\No", 0)), "Key not found: 2");
      RegKey c = new RegKey(lm, "SOFTWARE\\Classes\\world", 2);
      check("RegKey modo 2 crea", c.setIntValue("n", 5));
      eq("RegKey.getIntValue", c.getIntValue("n"), 5);
      // createKey lanza RegKeyNotFoundException sin declararla, como JNI
      String sneaky;
      try {
         new RegKey(k, "x", 2);
         sneaky = null;
      } catch (RegKeyNotFoundException e) {
         sneaky = e.getMessage();
      }
      eqs("createKey bajo asa cerrada", sneaky, "Key not found: 6");

      store.delete();
      if (failures > 0) {
         System.out.println(failures + " fallos");
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
         return "(sin excepción)";
      } catch (RegKeyNotFoundException e) {
         return e.getMessage();
      } catch (Exception e) {
         return "otra: " + e;
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
         System.out.println("FALLA " + what);
      }
   }

   private static void eq(String what, int got, int want) {
      check(what + ": " + got + " != " + want, got == want);
   }

   private static void eqs(String what, String got, String want) {
      check(what + ": \"" + got + "\" != \"" + want + "\"", got == null ? want == null : got.equals(want));
   }
}

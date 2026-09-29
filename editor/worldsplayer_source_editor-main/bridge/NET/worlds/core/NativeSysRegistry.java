package NET.worlds.core;

import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

/**
 * {@code NET.worlds.core.RegKey}: el registro de Windows de gamma.dll
 * (0x00402360-0x00402770) sobre un almacén portable.
 *
 * <p>Lo que es de gamma.dll se traduce tal cual:
 * <ul>
 * <li>{@code getReservedKey} (0x004023f0): 0..3 -> 0x80000000..0x80000003
 *     (HKCR, HKCU, HKLM, HKU); otro valor lanza
 *     {@code RegKeyNotFoundException("Key not found: 0")}. El %d de
 *     "Key not found: %d" (0x0046d2ac) es un {@code push 0} literal
 *     (0x00402436), no el argumento.</li>
 * <li>{@code openKey} (0x004026d0): KEY_READ 0x20019, o 0x2001f
 *     (lectura + escritura) si {@code modo & 1}; si falla, la misma
 *     excepción con el código de error Win32 ({@code push ebx} con el
 *     LSTATUS, 0x00402737).</li>
 * <li>{@code createKey} (0x00402770): RegCreateKeyExA con KEY_ALL_ACCESS
 *     0xf003f; si falla, igual que openKey.</li>
 * <li>{@code getStringValue} (0x00402470): búfer de 0x400 bytes; solo
 *     REG_SZ (1) o REG_EXPAND_SZ (2) ({@code tipo - 1 < 2}), sin expandir;
 *     cualquier otro caso, {@code null}.</li>
 * <li>{@code setStringValue} (0x00402510): tipo 2 si {@code expand}, si no 1;
 *     se guardan strlen + 1 bytes; devuelve {@code (char) LSTATUS == 0}.</li>
 * <li>{@code getIntValue} (0x004025c0): solo REG_DWORD (4) de 4 bytes; si no,
 *     0. {@code setIntValue} (0x00402640): REG_DWORD.</li>
 * <li>{@code close} (0x004026a0): RegCloseKey, sin mirar el resultado.</li>
 * </ul>
 *
 * <p>Lo que es de Win32 (advapi32) se sustituye: el registro es un árbol de
 * claves con nombres sin distinguir mayúsculas (conservando las que se
 * escribieron), valores con tipo, y asas numéricas con su derecho de
 * escritura; los códigos de error que el cliente puede ver son los de
 * advapi32 (2 = ERROR_FILE_NOT_FOUND para una clave que no existe, 5 =
 * ERROR_ACCESS_DENIED al escribir por un asa abierta solo para lectura, 6 =
 * ERROR_INVALID_HANDLE, 234 = ERROR_MORE_DATA si el valor no cabe en el
 * búfer). El árbol se guarda entero, en formato REGEDIT4 (el de
 * {@code regedit /e}) y UTF-8, en {@code openworlds-registry.reg} del
 * directorio de trabajo (o en la propiedad {@code openworlds.registry}) tras
 * cada cambio. Un fallo al escribir el fichero no hace fallar la llamada:
 * Windows tampoco vuelca la colmena en RegSetValueEx (eso es RegFlushKey).
 * Equivale para el cliente porque sus dos usos (NetUpdate: InstallDir tras
 * una actualización; IClassFactory.register: el manejador del protocolo
 * {@code world:}) solo leen lo que ellos u otro programa escribieron antes.
 * Las cuatro raíces son árboles independientes (en Windows HKCR mezcla
 * HKLM\SOFTWARE\Classes y HKCU\SOFTWARE\Classes, y HKCU cuelga de HKU).
 */
public final class NativeSysRegistry {
   static final int ERROR_FILE_NOT_FOUND = 2;
   static final int ERROR_ACCESS_DENIED = 5;
   static final int ERROR_INVALID_HANDLE = 6;
   static final int REG_SZ = 1;
   static final int REG_EXPAND_SZ = 2;
   static final int REG_DWORD = 4;
   /** Búfer de getStringValue (local_418[1024], 0x00402470). */
   static final int STRING_BUFFER = 0x400;
   static final int HKEY_BASE = 0x80000000;
   static final String[] ROOT_NAMES = {"HKEY_CLASSES_ROOT", "HKEY_CURRENT_USER", "HKEY_LOCAL_MACHINE", "HKEY_USERS"};

   private static final class Key {
      final String name;
      final LinkedHashMap<String, Key> sub = new LinkedHashMap<String, Key>();
      final LinkedHashMap<String, Value> values = new LinkedHashMap<String, Value>();

      Key(String name) {
         this.name = name;
      }
   }

   private static final class Value {
      final String name;
      final int type;
      final String str;
      final int dword;

      Value(String name, int type, String str, int dword) {
         this.name = name;
         this.type = type;
         this.str = str;
         this.dword = dword;
      }
   }

   private static final class Handle {
      final Key key;
      final boolean write;

      Handle(Key key, boolean write) {
         this.key = key;
         this.write = write;
      }
   }

   private static final Key[] roots = new Key[4];
   private static final Map<Integer, Handle> handles = new HashMap<Integer, Handle>();
   private static int nextHandle = 0x100;
   private static boolean loaded = false;
   private static boolean warned = false;

   private NativeSysRegistry() {
   }

   // ---------------------------------------------------------------- API

   /** getReservedKey (0x004023f0). */
   public static int reservedKey(int which) throws RegKeyNotFoundException {
      if (which < 0 || which > 3) {
         throw new RegKeyNotFoundException("Key not found: 0");
      }
      return HKEY_BASE + which;
   }

   /** openKey (0x004026d0): RegOpenKeyExA. */
   public static synchronized int openKey(int parent, String sub, int mode) throws RegKeyNotFoundException {
      load();
      Handle p = resolve(parent);
      if (p == null) {
         throw notFound(ERROR_INVALID_HANDLE);
      }
      Key k = walk(p.key, sub);
      if (k == null) {
         throw notFound(ERROR_FILE_NOT_FOUND);
      }
      return newHandle(k, (mode & 1) != 0);
   }

   /**
    * createKey (0x00402770): RegCreateKeyExA crea las claves intermedias que
    * falten y devuelve un asa con KEY_ALL_ACCESS. Java no declara la
    * excepción; JNI la deja pendiente igual (NativeSysJni).
    */
   public static synchronized int createKey(int parent, String sub) {
      load();
      Handle p = resolve(parent);
      if (p == null) {
         throw NativeSysJni.throwNew(notFound(ERROR_INVALID_HANDLE));
      }
      Key k = walk(p.key, sub);
      if (k == null) {
         // ⚠️ VERIFICAR: se supone que crear una subclave exige
         // KEY_CREATE_SUB_KEY en el asa padre (no la tiene la de KEY_READ
         // 0x20019) y que abrir una ya existente no; ningún llamador del
         // cliente crea bajo un asa de solo lectura.
         if (!p.write) {
            throw NativeSysJni.throwNew(notFound(ERROR_ACCESS_DENIED));
         }
         String[] parts = split(sub);
         if (parts == null) {
            throw NativeSysJni.throwNew(notFound(ERROR_FILE_NOT_FOUND));
         }
         k = p.key;
         for (String part : parts) {
            Key c = k.sub.get(fold(part));
            if (c == null) {
               c = new Key(part);
               k.sub.put(fold(part), c);
            }
            k = c;
         }
         save();
      }
      return newHandle(k, true);
   }

   /** getStringValue (0x00402470). */
   public static synchronized String getString(int h, String name) {
      load();
      Value v = value(h, name);
      if (v == null || (v.type != REG_SZ && v.type != REG_EXPAND_SZ)) {
         return null;
      }
      // ERROR_MORE_DATA: strlen + 1 (en el UTF-8 modificado de
      // GetStringUTFChars con el que se escribió) no cabe en 0x400 bytes
      return mutf8Length(v.str) + 1 > STRING_BUFFER ? null : v.str;
   }

   /** setStringValue (0x00402510). */
   public static synchronized boolean setString(int h, String name, String data, boolean expand) {
      load();
      Handle p = resolve(h);
      if (p == null || !p.write) {
         return false;
      }
      if (data == null) {
         throw new NullPointerException();
      }
      put(p.key, new Value(name == null ? "" : name, expand ? REG_EXPAND_SZ : REG_SZ, data, 0));
      return true;
   }

   /** getIntValue (0x004025c0). */
   public static synchronized int getInt(int h, String name) {
      load();
      Value v = value(h, name);
      return v != null && v.type == REG_DWORD ? v.dword : 0;
   }

   /** setIntValue (0x00402640). */
   public static synchronized boolean setInt(int h, String name, int data) {
      load();
      Handle p = resolve(h);
      if (p == null || !p.write) {
         return false;
      }
      put(p.key, new Value(name == null ? "" : name, REG_DWORD, null, data));
      return true;
   }

   /** close (0x004026a0): las raíces predefinidas siguen valiendo tras cerrarlas. */
   public static synchronized void close(int h) {
      handles.remove(h);
   }

   /** Vuelve a leer el almacén desde el disco, como un proceso nuevo (para las comprobaciones). */
   static synchronized void reload() {
      loaded = false;
      handles.clear();
      load();
   }

   /** Ruta del almacén. */
   static File storeFile() {
      String p = System.getProperty("openworlds.registry");
      return p != null ? new File(p) : new File(System.getProperty("user.dir"), "openworlds-registry.reg");
   }

   // ---------------------------------------------------------- internals

   private static RegKeyNotFoundException notFound(int status) {
      return new RegKeyNotFoundException("Key not found: " + status);
   }

   private static Handle resolve(int h) {
      int root = h - HKEY_BASE;
      if (root >= 0 && root < 4) {
         return new Handle(roots[root], true);
      }
      return handles.get(h);
   }

   private static int newHandle(Key k, boolean write) {
      int h = nextHandle;
      nextHandle += 4;
      handles.put(h, new Handle(k, write));
      return h;
   }

   private static Value value(int h, String name) {
      Handle p = resolve(h);
      return p == null ? null : p.key.values.get(fold(name == null ? "" : name));
   }

   /** Sobrescribir un valor conserva el nombre con que se creó (solo cambian tipo y datos). */
   private static void put(Key k, Value v) {
      Value old = k.values.get(fold(v.name));
      k.values.put(fold(v.name), old == null ? v : new Value(old.name, v.type, v.str, v.dword));
      save();
   }

   private static String fold(String s) {
      return s.toUpperCase(Locale.ROOT);
   }

   /**
    * Componentes de una subclave. "" o null es la propia clave (RegOpenKeyEx
    * devuelve un asa nueva a la misma). ⚠️ VERIFICAR: un componente vacío
    * ("a\\\\b", barra inicial o final) se rechaza como clave inexistente; no
    * está comprobado qué código da advapi32 ni lo usa ningún llamador.
    */
   private static String[] split(String sub) {
      if (sub == null || sub.isEmpty()) {
         return new String[0];
      }
      String[] parts = sub.split("\\\\", -1);
      for (String part : parts) {
         if (part.isEmpty()) {
            return null;
         }
      }
      return parts;
   }

   private static Key walk(Key from, String sub) {
      String[] parts = split(sub);
      if (parts == null) {
         return null;
      }
      Key k = from;
      for (String part : parts) {
         k = k.sub.get(fold(part));
         if (k == null) {
            return null;
         }
      }
      return k;
   }

   static int mutf8Length(String s) {
      int n = 0;
      for (int i = 0; i < s.length(); i++) {
         char c = s.charAt(i);
         n += c >= 1 && c <= 0x7f ? 1 : (c <= 0x7ff ? 2 : 3);
      }
      return n;
   }

   // --------------------------------------------------- REGEDIT4 on disk

   private static void load() {
      if (loaded) {
         return;
      }
      loaded = true;
      for (int i = 0; i < 4; i++) {
         roots[i] = new Key(ROOT_NAMES[i]);
      }
      File f = storeFile();
      if (!f.isFile()) {
         return;
      }
      try (BufferedReader r = new BufferedReader(new InputStreamReader(new FileInputStream(f), StandardCharsets.UTF_8))) {
         Key cur = null;
         for (String line = r.readLine(); line != null; line = r.readLine()) {
            line = line.trim();
            if (line.startsWith("[") && line.endsWith("]")) {
               cur = section(line.substring(1, line.length() - 1));
            } else if (cur != null && (line.startsWith("@=") || line.startsWith("\""))) {
               parseValue(cur, line);
            }
         }
      } catch (IOException | RuntimeException e) {
         System.err.println("openworlds: registro " + f + " ilegible desde la línea que falla: " + e);
      }
   }

   private static Key section(String path) {
      String[] parts = path.split("\\\\");
      for (int i = 0; i < 4; i++) {
         if (ROOT_NAMES[i].equalsIgnoreCase(parts[0])) {
            Key k = roots[i];
            for (int j = 1; j < parts.length; j++) {
               if (parts[j].isEmpty()) {
                  continue;
               }
               Key c = k.sub.get(fold(parts[j]));
               if (c == null) {
                  c = new Key(parts[j]);
                  k.sub.put(fold(parts[j]), c);
               }
               k = c;
            }
            return k;
         }
      }
      return null;
   }

   private static void parseValue(Key k, String line) {
      int[] pos = {0};
      String name;
      if (line.startsWith("@=")) {
         name = "";
         pos[0] = 2;
      } else {
         name = quoted(line, pos);
         if (pos[0] >= line.length() || line.charAt(pos[0]) != '=') {
            return;
         }
         pos[0]++;
      }
      String rest = line.substring(pos[0]);
      if (rest.startsWith("\"")) {
         int[] p2 = {0};
         k.values.put(fold(name), new Value(name, REG_SZ, quoted(rest, p2), 0));
      } else if (rest.startsWith("dword:")) {
         k.values.put(fold(name), new Value(name, REG_DWORD, null, (int) Long.parseLong(rest.substring(6).trim(), 16)));
      } else if (rest.startsWith("hex(2):")) {
         ByteArrayOutputStream b = new ByteArrayOutputStream();
         for (String x : rest.substring(7).split(",")) {
            if (!x.trim().isEmpty()) {
               b.write(Integer.parseInt(x.trim(), 16));
            }
         }
         byte[] bytes = b.toByteArray();
         int n = bytes.length;
         while (n > 0 && bytes[n - 1] == 0) {
            n--;
         }
         k.values.put(fold(name), new Value(name, REG_EXPAND_SZ, new String(bytes, 0, n, StandardCharsets.UTF_8), 0));
      }
   }

   /** Cadena entre comillas de REGEDIT4 desde pos[0] ({@code \\} y {@code \"}); deja pos[0] tras la comilla final. */
   private static String quoted(String s, int[] pos) {
      StringBuilder b = new StringBuilder();
      int i = pos[0] + 1;
      while (i < s.length() && s.charAt(i) != '"') {
         char c = s.charAt(i);
         if (c == '\\' && i + 1 < s.length()) {
            c = s.charAt(++i);
         }
         b.append(c);
         i++;
      }
      pos[0] = i + 1;
      return b.toString();
   }

   private static String escape(String s) {
      return s.replace("\\", "\\\\").replace("\"", "\\\"");
   }

   private static void save() {
      File f = storeFile();
      StringBuilder out = new StringBuilder("REGEDIT4\r\n");
      for (Key r : roots) {
         write(out, r, r.name, true);
      }
      try (Writer w = new OutputStreamWriter(new FileOutputStream(f), StandardCharsets.UTF_8)) {
         w.write(out.toString());
      } catch (IOException e) {
         if (!warned) {
            warned = true;
            System.err.println("openworlds: no se puede escribir el registro en " + f + ": " + e);
         }
      }
   }

   private static void write(StringBuilder out, Key k, String path, boolean root) {
      if (!root || !k.values.isEmpty()) {
         out.append("\r\n[").append(path).append("]\r\n");
         for (Value v : k.values.values()) {
            out.append(v.name.isEmpty() ? "@" : "\"" + escape(v.name) + "\"").append('=');
            if (v.type == REG_DWORD) {
               out.append(String.format("dword:%08x", v.dword));
            } else if (v.type == REG_EXPAND_SZ) {
               out.append("hex(2):");
               byte[] bytes = v.str.getBytes(StandardCharsets.UTF_8);
               List<String> hex = new ArrayList<String>();
               for (byte x : bytes) {
                  hex.add(String.format("%02x", x & 0xff));
               }
               hex.add("00");
               out.append(String.join(",", hex));
            } else {
               out.append('"').append(escape(v.str)).append('"');
            }
            out.append("\r\n");
         }
      }
      for (Key c : k.sub.values()) {
         write(out, c, path + "\\" + c.name, false);
      }
   }
}

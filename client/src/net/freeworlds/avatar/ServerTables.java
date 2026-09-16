package net.freeworlds.avatar;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Lector de `tables/tables.dat`, el fichero de tablas que el cliente
 * original descarga del upgrade server y del que salen `permittedList`,
 * `faceList`, `humanList`, `secretList`, etc.
 *
 * Port literal de NET/worlds/core/ServerTableManager.java (Java pristino
 * decompilado):
 *
 * <pre>
 * parseFile()   ServerTableManager.java:99-147
 *   RandomAccessFile.readInt() -> longitud (int32 big-endian)
 *   readFully(payload); decrypt(payload)
 *   lineas: se ignoran "" y las que empiezan por "//"
 *   "VERSION ..."                      -> fileVersion (ultimo token)
 *   "private static String[] <nombre>" -> parseTable()
 * decrypt()     ServerTableManager.java:230-245
 *   dec[0] = enc[0]; dec[i] = enc[i] ^ enc[i-1]   (XOR encadenado sobre
 *   el CIFRADO, no sobre el descifrado); el texto resultante es UTF-8
 * parseTable()  ServerTableManager.java:167-206
 *   lee hasta "};"; StringTokenizer con delimitadores ",\n\r";
 *   un token que empieza por "+ \"" se concatena al anterior
 * stripQuotes() ServerTableManager.java:149-165
 *   quita la comilla inicial, la final, y TODAS las restantes
 * </pre>
 *
 * Comprobado sobre assets/WorldsPlayer/tables/tables.dat (45164 bytes,
 * identico a assets/WorldsPlayer/cachedir/44.dat): VERSION 2, 12 tablas.
 */
public final class ServerTables {
   private static final String TABLE_START = "private static String[] ";
   private static final String VERSION = "VERSION";

   private final Map<String, String[]> tables = new LinkedHashMap<>();
   private int fileVersion;

   private ServerTables() {
   }

   /** Descifra y parsea un tables.dat completo. */
   public static ServerTables load(Path file) throws IOException {
      byte[] raw = Files.readAllBytes(file);
      if (raw.length < 4) {
         throw new IOException("tables.dat demasiado corto: " + raw.length);
      }
      // readInt() de RandomAccessFile = int32 big-endian (ServerTableManager.java:102).
      int len = ((raw[0] & 0xFF) << 24) | ((raw[1] & 0xFF) << 16) | ((raw[2] & 0xFF) << 8) | (raw[3] & 0xFF);
      if (len < 0 || len > raw.length - 4) {
         throw new IOException("longitud declarada invalida: " + len + " (fichero " + raw.length + ")");
      }
      byte[] enc = new byte[len];
      System.arraycopy(raw, 4, enc, 0, len);
      return parse(decrypt(enc));
   }

   /** ServerTableManager.decrypt (ServerTableManager.java:230-245). */
   public static String decrypt(byte[] enc) {
      byte[] dec = new byte[enc.length];
      if (enc.length > 0) {
         dec[0] = enc[0];
      }
      for (int i = 1; i < enc.length; i++) {
         dec[i] = (byte) (enc[i] ^ enc[i - 1]);
      }
      return new String(dec, StandardCharsets.UTF_8);
   }

   /** ServerTableManager.parseFile, ya con el texto descifrado. */
   public static ServerTables parse(String text) throws IOException {
      ServerTables out = new ServerTables();
      BufferedReader in = new BufferedReader(new StringReader(text));
      String line;
      while ((line = in.readLine()) != null) {
         line = line.trim();
         if (line.startsWith("//") || line.isEmpty()) {
            continue;
         }
         if (line.startsWith(VERSION)) {
            StringTokenizer tok = new StringTokenizer(line);
            String last = "";
            while (tok.hasMoreTokens()) {
               last = tok.nextToken();
            }
            if (!last.isEmpty()) {
               try {
                  out.fileVersion = (int) Double.parseDouble(last);
               } catch (NumberFormatException ignored) {
                  // el original usa Double.valueOf(...).intValue() sin proteccion
               }
            }
         }
         if (line.startsWith(TABLE_START)) {
            StringTokenizer tok = new StringTokenizer(line.substring(TABLE_START.length()));
            if (tok.hasMoreTokens()) {
               out.parseTable(in, tok.nextToken().trim());
            }
         }
      }
      in.close();
      return out;
   }

   /** ServerTableManager.parseTable (ServerTableManager.java:167-206). */
   private void parseTable(BufferedReader in, String name) throws IOException {
      String prev = null;
      List<String> values = new ArrayList<>();
      String line;
      while ((line = in.readLine()) != null) {
         line = line.trim();
         if (line.isEmpty() || line.startsWith("//")) {
            continue;
         }
         if (line.startsWith("};")) {
            break;
         }
         StringTokenizer tok = new StringTokenizer(line, ",\n\r");
         while (tok.hasMoreTokens()) {
            String t = tok.nextToken().trim();
            if (t.startsWith("+ \"")) {
               if (prev != null) {
                  prev = prev + stripQuotes(t.substring(2));
                  values.remove(values.size() - 1);
                  values.add(prev);
               }
            } else {
               prev = stripQuotes(t);
               values.add(prev);
            }
         }
      }
      tables.put(name, values.toArray(new String[0]));
   }

   /** ServerTableManager.stripQuotes (ServerTableManager.java:149-165). */
   private static String stripQuotes(String s) {
      String r = s;
      if (!r.isEmpty() && r.charAt(0) == '"') {
         r = r.substring(1);
      }
      if (!r.isEmpty() && r.charAt(r.length() - 1) == '"') {
         r = r.substring(0, r.length() - 1);
      }
      int i;
      while ((i = r.indexOf('"')) != -1) {
         r = r.substring(0, i) + r.substring(i + 1);
      }
      return r;
   }

   public String[] getTable(String name) {
      return tables.get(name);
   }

   public Map<String, String[]> tables() {
      return tables;
   }

   public int fileVersion() {
      return fileVersion;
   }

   /**
    * permittedHash del bloque static de PosableShape
    * (PosableShape.java:1324-1335): pares (nombre, nombre codificado).
    */
   public Map<String, String> permittedHash() {
      Map<String, String> map = new LinkedHashMap<>();
      String[] list = getTable("permittedList");
      if (list == null) {
         return map;
      }
      for (int i = 0; i + 1 < list.length; i += 2) {
         if (list[i + 1] != null) {
            map.put(list[i], list[i + 1]);
         }
      }
      return map;
   }

   /** faceTextures (PosableShape.java:1341-1343). */
   public Map<String, String> faceTextures() {
      return pairs("faceList");
   }

   /** humanHash (PosableShape.java:1337-1339): pares desplazados en 1. */
   public Map<String, String> humanHash() {
      return pairs("humanList");
   }

   private Map<String, String> pairs(String table) {
      Map<String, String> map = new LinkedHashMap<>();
      String[] list = getTable(table);
      if (list == null) {
         return map;
      }
      for (int i = 0; i + 1 < list.length; i += 2) {
         map.put(list[i], list[i + 1]);
      }
      return map;
   }
}

package net.freeworlds.cmp;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.util.zip.CRC32;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * CmpTexture sobre CmpFrames (2026-09-22). Sale con 1 si algo falla.
 *
 * Valores de referencia (GroundZero/content.zip, tex/):
 * - windr3.mov: cabecera u16@8 = 154 (ancho) y u16@6 = 128 (alto); la ruta
 *   vieja devolvia 128x154. Tabla de frames (20 bytes por entrada, tras la
 *   region de tablas): offsets 1037/3049/5075/8555, tamanos
 *   2012/2026/3480/3074; comprobado a mano que son contiguos y que el
 *   ultimo acaba en el final del fichero (8555 + 3074 = 11629 bytes). La
 *   referencia de cada frame es el anterior (0xFFFF, 0, 1, 2).
 * - cave.mov: frames en 1037/5061/8479/12774 (+2733 = 15507 = longitud).
 *   El escaneo por firma de la ruta vieja (decodeMovFrame0) se paraba en
 *   12774, el ULTIMO grupo: su salida tenia CRC32 9978ee96 (medido antes
 *   del cambio), que es exactamente el frame 3 de CmpFrames.
 * - Los CRC32 del RGB de frame 0 (8b07695b, e933c3eb) y del still
 *   avflr1.cmp (375d1bfe, identico antes y despues: los 159 .cmp no
 *   cambian) son valores de regresion medidos el 2026-09-22; lo que los
 *   justifica son las igualdades de arriba (frame 0 = primer grupo de la
 *   tabla, frame 3 = lo que se veia antes), que el check tambien exige.
 */
public final class CmpTextureCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      File zip = findContentZip();
      File tmp = Files.createTempDirectory("cmpcheck").toFile();
      try (ZipFile z = new ZipFile(zip)) {
         File windr3 = extract(z, "tex/windr3.mov", tmp);
         File cave = extract(z, "tex/cave.mov", tmp);
         File avflr1 = extract(z, "tex/avflr1.cmp", tmp);

         byte[] w3 = Files.readAllBytes(windr3.toPath());
         check("windr3 u16@8 (ancho)", u16(w3, 8), 154);
         check("windr3 u16@6 (alto)", u16(w3, 6), 128);
         int[][] t = CmpStage1.frameTable(w3);
         check("windr3 frames", t.length, 4);
         int[] offs = {1037, 3049, 5075, 8555};
         int[] sizes = {2012, 2026, 3480, 3074};
         int[] refs = {0xFFFF, 0, 1, 2};
         for (int i = 0; i < 4; i++) {
            check("windr3 frame " + i + " offset", t[i][0], offs[i]);
            check("windr3 frame " + i + " size", t[i][1], sizes[i]);
            check("windr3 frame " + i + " ref", t[i][3], refs[i]);
         }
         check("windr3 ultimo grupo acaba en EOF", t[3][0] + t[3][1], w3.length);
         CmpTexture f0 = CmpTexture.loadMov(windr3);
         check("windr3 ancho", f0.width, 154);
         check("windr3 alto", f0.height, 128);
         checkCrc("windr3 frame 0", f0.rgb, "8b07695b");

         byte[] cv = Files.readAllBytes(cave.toPath());
         int[][] ct = CmpStage1.frameTable(cv);
         check("cave frames", ct.length, 4);
         check("cave frame 0 offset", ct[0][0], 1037);
         check("cave frame 3 offset (donde paraba la ruta vieja)", ct[3][0], 12774);
         check("cave ultimo grupo acaba en EOF", ct[3][0] + ct[3][1], cv.length);
         CmpTexture[] all = CmpTexture.loadMovFrames(cave);
         check("cave frames decodificados", all.length, 4);
         CmpTexture c0 = CmpTexture.loadMov(cave);
         checkCrc("cave frame 0", c0.rgb, "e933c3eb");
         checkCrc("cave loadMovFrames[0] = loadMov", all[0].rgb, "e933c3eb");
         checkCrc("cave frame 3 = salida de la ruta vieja", all[3].rgb, "9978ee96");

         CmpTexture s = CmpTexture.loadRaw(avflr1);
         check("avflr1 ancho", s.width, 128);
         check("avflr1 alto", s.height, 128);
         checkCrc("avflr1.cmp (still, sin cambio)", s.rgb, "375d1bfe");
      } finally {
         File[] fs = tmp.listFiles();
         if (fs != null) {
            for (File f : fs) {
               f.delete();
            }
         }
         tmp.delete();
      }
      if (failures > 0) {
         System.out.println("CmpTextureCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("CmpTextureCheck: OK");
   }

   private static int u16(byte[] b, int o) {
      return (b[o] & 0xFF) | (b[o + 1] & 0xFF) << 8;
   }

   private static void check(String what, long got, long want) {
      if (got != want) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void checkCrc(String what, byte[] rgb, String want) {
      CRC32 c = new CRC32();
      c.update(rgb);
      String got = String.format("%08x", c.getValue());
      if (!got.equals(want)) {
         failures++;
         System.out.println("FALLO " + what + ": crc " + got + " (esperado " + want + ")");
      }
   }

   private static File extract(ZipFile z, String name, File dir) throws IOException {
      ZipEntry e = z.getEntry(name);
      if (e == null) {
         throw new IOException(name + " no esta en " + z.getName());
      }
      File out = new File(dir, name.substring(name.lastIndexOf('/') + 1));
      try (InputStream in = z.getInputStream(e)) {
         Files.copy(in, out.toPath());
      }
      return out;
   }

   /** assets/WorldsPlayer/GroundZero/content.zip subiendo desde el directorio actual. */
   static File findContentZip() throws IOException {
      File d = new File(".").getAbsoluteFile();
      while (d != null) {
         File f = new File(d, "assets/WorldsPlayer/GroundZero/content.zip");
         if (f.isFile()) {
            return f;
         }
         d = d.getParentFile();
      }
      throw new IOException("no encuentro assets/WorldsPlayer/GroundZero/content.zip desde " + new File(".").getAbsolutePath());
   }
}

package net.freeworlds.launcher;

import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.FileTime;
import java.util.Properties;

/**
 * Install.prepare with a new template (a FreeWorlds update, or the same
 * template at another path, as macOS App Translocation does on every start):
 * a file still as the launcher copied it takes the new template's; one the
 * game changed (worlds.dst, an upgraded GroundZero file) is kept for good;
 * missing files come back; cachedir/ is taken again every time; a copy from
 * before the manifest keeps whatever differs from the template.
 */
public final class InstallCheck {
   private static int failures;

   public static void main(String[] args) throws Exception {
      Path tmp = Files.createTempDirectory("fw-install-check");
      try {
         run(tmp);
      } finally {
         Layout.deleteTree(tmp);
      }
      if (failures > 0) {
         System.out.println("InstallCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("InstallCheck: todo bien");
   }

   private static void check(boolean ok, String what) {
      System.out.println((ok ? "  ok    " : "  FALLA ") + what);
      if (!ok) {
         failures++;
      }
   }

   private static void run(Path tmp) throws Exception {
      Path gameA = tmp.resolve("appA");
      Path t = gameA.resolve("assets/WorldsPlayer");
      write(t, "worlds.ini", "[Gamma]\r\nplantilla=1\r\n", 1000);
      write(t, "worlds.dst", "dst v1", 1000);
      write(t, "GroundZero/ver.txt", "37", 1000);
      write(t, "GroundZero/groundzero.world", "gz v1", 1000);
      write(t, "readme.txt", "leeme v1", 1000);
      write(t, "cachedir/cache.index", "indice", 1000);
      write(t, "bin/java.exe", "jre de 2004", 1000);
      Path data = tmp.resolve("data");
      Layout l = new Layout(tmp.toFile(), gameA.toFile(), data.toFile());
      Log log = new Log(data.resolve("logs").toFile(), "check");
      Path w = l.workDir.toPath();

      System.out.println("Primera vez:");
      Install.prepare(l, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz v1"), "copiado GroundZero");
      check(read(w, "worlds.ini").contains("plantilla=1"), "copiado worlds.ini");
      check(!Files.exists(w.resolve("bin")), "bin/ (JRE y DLL de 2004) no se copia");
      Properties m = manifest(w);
      check(m.getProperty("GroundZero/groundzero.world", "").contains("|"), "manifiesto con plantilla|copia");

      System.out.println("El juego cambia ficheros:");
      write(w, "worlds.ini", "[Gamma]\r\namigos=pepe\r\n", 5000);
      write(w, "GroundZero/ver.txt", "40", 5000);          // Upgrade Now 37 -> 40
      write(w, "worlds.dst", "dst del juego", 5000);
      write(w, "cachedir/extra.bin", "cache vieja", 5000);
      Files.delete(w.resolve("readme.txt"));

      System.out.println("Version nueva de FreeWorlds (plantilla distinta y en otra ruta):");
      Path gameB = tmp.resolve("appB");
      Path t2 = gameB.resolve("assets/WorldsPlayer");
      write(t2, "worlds.ini", "[Gamma]\r\nplantilla=2\r\n", 2000);
      write(t2, "worlds.dst", "dst v2", 2000);
      write(t2, "GroundZero/ver.txt", "38", 2000);
      write(t2, "GroundZero/groundzero.world", "gz v2", 2000);
      write(t2, "readme.txt", "leeme v2", 2000);
      write(t2, "cachedir/cache.index", "indice", 1000);
      write(t2, "nuevo.txt", "nuevo", 2000);
      Layout l2 = new Layout(tmp.toFile(), gameB.toFile(), data.toFile());
      Install.prepare(l2, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz v2"), "intacto desde la copia: toma la plantilla nueva");
      check(read(w, "GroundZero/ver.txt").equals("40"), "GroundZero actualizado por el juego: se respeta (40, no 38)");
      check(read(w, "worlds.dst").equals("dst del juego"), "worlds.dst cambiado por el juego: se respeta");
      check(read(w, "worlds.ini").contains("amigos=pepe"), "worlds.ini del usuario: no se toca");
      check(read(w, "readme.txt").equals("leeme v2"), "borrado: vuelve de la plantilla");
      check(read(w, "nuevo.txt").equals("nuevo"), "fichero nuevo de la plantilla: se copia");
      check(!Files.exists(w.resolve("cachedir/extra.bin")) && Files.exists(w.resolve("cachedir/cache.index")),
         "cachedir/ se toma otra vez de la plantilla");
      check(manifest(w).getProperty("GroundZero/ver.txt", "").startsWith("juego|"), "lo del juego queda apuntado como suyo");

      System.out.println("Otra plantilla mas nueva: lo del juego sigue siendo suyo:");
      write(t2, "GroundZero/ver.txt", "41", 3000);
      Install.prepare(l2, log);
      check(read(w, "GroundZero/ver.txt").equals("40"), "sigue 40");

      System.out.println("Misma plantilla en otra ruta (App Translocation): no se copia nada:");
      Path gameC = tmp.resolve("appC");
      copyTree(gameB, gameC);
      Layout l3 = new Layout(tmp.toFile(), gameC.toFile(), data.toFile());
      FileTime before = Files.getLastModifiedTime(w.resolve("GroundZero/groundzero.world"));
      Install.prepare(l3, log);
      check(Files.getLastModifiedTime(w.resolve("GroundZero/groundzero.world")).equals(before), "groundzero.world sin tocar");

      System.out.println("Copia de un lanzador anterior (sin manifiesto):");
      Files.delete(w.resolve(Install.MANIFEST));
      write(w, "GroundZero/groundzero.world", "gz tocado", 9000);
      write(t2, "GroundZero/groundzero.world", "gz v3", 4000);
      Install.prepare(l2, log);
      check(read(w, "GroundZero/groundzero.world").equals("gz tocado"), "distinto de la plantilla: se respeta");
      check(read(w, "nuevo.txt").equals("nuevo") && manifest(w).getProperty("nuevo.txt", "").contains("|"),
         "igual que la plantilla: se apunta");
   }

   private static void write(Path base, String rel, String text, long seconds) throws IOException {
      Path p = base.resolve(rel);
      Files.createDirectories(p.getParent());
      Files.write(p, text.getBytes(StandardCharsets.ISO_8859_1));
      Files.setLastModifiedTime(p, FileTime.fromMillis(1_700_000_000_000L + seconds * 1000L));
   }

   private static String read(Path base, String rel) throws IOException {
      Path p = base.resolve(rel);
      return Files.isRegularFile(p) ? new String(Files.readAllBytes(p), StandardCharsets.ISO_8859_1) : "";
   }

   private static Properties manifest(Path work) throws IOException {
      Properties p = new Properties();
      try (InputStream in = Files.newInputStream(work.resolve(Install.MANIFEST))) {
         p.load(in);
      }
      return p;
   }

   private static void copyTree(Path from, Path to) throws IOException {
      try (java.util.stream.Stream<Path> s = Files.walk(from)) {
         for (Path p : (Iterable<Path>) s::iterator) {
            Path q = to.resolve(from.relativize(p).toString());
            if (Files.isDirectory(p)) {
               Files.createDirectories(q);
            } else {
               Files.copy(p, q, java.nio.file.StandardCopyOption.COPY_ATTRIBUTES);
            }
         }
      }
   }
}

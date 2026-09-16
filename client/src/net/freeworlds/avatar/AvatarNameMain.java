package net.freeworlds.avatar;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeMap;
import java.util.stream.Stream;

/**
 * CLI de verificacion del decodificador de nombres de avatar.
 *
 * Uso:
 *   AvatarNameMain [--tables f] [--assets dir]... --tablas
 *       lista las tablas de tables.dat y su tamano
 *   AvatarNameMain [...] &lt;nombre|avatar:...rwg&gt;
 *       decodifica un nombre y vuelca el arbol de partes
 *   AvatarNameMain [...] --todos
 *       decodifica los 148 nombres de permittedList y resume: nombres sin
 *       anomalias, tokens desconocidos (con avatar y posicion), texturas y
 *       .bod referenciados y cuales existen en el repo
 *
 * Por defecto tables = assets/WorldsPlayer/tables/tables.dat y se buscan
 * los ficheros en assets/gammatutorial-samples/base-avatars,
 * assets/WorldsPlayer y assets/WorldsPlayer/cachedir.
 */
public final class AvatarNameMain {
   private static final String[] ASSETS_POR_DEFECTO = {
      "assets/gammatutorial-samples/base-avatars",
      "assets/WorldsPlayer",
      "assets/WorldsPlayer/cachedir"
   };

   public static void main(String[] args) throws IOException {
      Path tables = Paths.get("assets/WorldsPlayer/tables/tables.dat");
      List<Path> assets = new ArrayList<>();
      List<String> libres = new ArrayList<>();
      for (int i = 0; i < args.length; i++) {
         if (args[i].equals("--tables") && i + 1 < args.length) {
            tables = Paths.get(args[++i]);
         } else if (args[i].equals("--assets") && i + 1 < args.length) {
            assets.add(Paths.get(args[++i]));
         } else {
            libres.add(args[i]);
         }
      }
      if (assets.isEmpty()) {
         for (String d : ASSETS_POR_DEFECTO) {
            Path p = Paths.get(d);
            if (Files.isDirectory(p)) {
               assets.add(p);
            }
         }
      }

      ServerTables st = ServerTables.load(tables);
      Map<String, String> permitted = st.permittedHash();

      if (libres.isEmpty() || libres.contains("--tablas")) {
         System.out.println("tables.dat: " + tables + "  VERSION " + st.fileVersion());
         for (Map.Entry<String, String[]> e : st.tables().entrySet()) {
            System.out.println("  " + e.getKey() + ": " + e.getValue().length + " entradas");
         }
         if (libres.isEmpty()) {
            return;
         }
         libres.remove("--tablas");
         if (libres.isEmpty()) {
            return;
         }
      }

      Map<String, Path> indice = indexar(assets);
      if (libres.contains("--todos")) {
         todos(st, permitted, indice, assets);
         return;
      }
      for (String nombre : libres) {
         String url = nombre.startsWith("avatar:") ? nombre : "avatar:" + nombre + ".rwg";
         System.out.println("=== " + url + " ===");
         volcar(AvatarNameDecoder.decode(url, permitted), indice);
         System.out.println();
      }
   }

   // ------------------------------------------------------------------
   private static void volcar(AvatarFigure f, Map<String, Path> indice) {
      System.out.println("base            : " + f.base + (f.desdePermittedList ? "  (via permittedList)" : ""));
      System.out.println("cadena          : " + f.cadena);
      System.out.println("tras findStarts : " + f.cadenaReescrita);
      StringBuilder ar = new StringBuilder();
      for (char c = 'A'; c <= 'Z'; c++) {
         if (f.arranques[c - 'A'] > 0) {
            ar.append(c).append('@').append(f.arranques[c - 'A']).append(' ');
         }
      }
      System.out.println("arranques       : " + ar.toString().trim());
      if (!f.letrasNoUsadas.isEmpty()) {
         System.out.println("letras no usadas: " + f.letrasNoUsadas + "  (createSubparts solo consume 17 letras)");
      }
      System.out.println("prepFigure      : " + f.prepFigure);
      System.out.println("paleta (" + f.paleta.size() + "):");
      for (AvatarMaterial m : f.paleta) {
         System.out.println("  " + m + (m.kind == AvatarMaterial.Kind.TEXTURA ? existe(indice, m.textureFile) : ""));
      }
      System.out.println("partes:");
      for (AvatarPart p : f.partes) {
         if (!p.adjunta) {
            System.out.println("  " + p.letra + " tag=" + p.tag + "  DESCARTADA: " + p.motivoDescarte);
            continue;
         }
         System.out.println("  " + p.letra + " tag=" + String.format("%02d", p.tag) + " padre=" + p.letraPadre
               + "  " + p.bodUrl() + "  -> fichero " + p.bodFile() + " parte " + p.bodPartNum()
               + existe(indice, p.bodFile())
               + (p.animacion != null ? "  animacion=" + p.animacion : ""));
         for (AvatarPart.Nodo n : p.nodos) {
            StringBuilder sb = new StringBuilder("      ").append(n.tipo);
            if (n.subRelativo >= 0) {
               sb.append(" (url ").append(n.url).append(")");
            }
            if (n.escalaX != 1.0F || n.escalaY != 1.0F || n.escalaZ != 1.0F) {
               sb.append(String.format("  escala=(%.3f,%.3f,%.3f)", n.escalaX, n.escalaY, n.escalaZ));
            }
            if (n.material >= 0) {
               AvatarMaterial m = f.paleta.get(n.material);
               sb.append("  material=").append(m);
            } else if (!n.materiales.isEmpty()) {
               sb.append("  material=origMat (sin cambio)");
            } else {
               sb.append("  material=(hereda)");
            }
            System.out.println(sb);
            if (!n.cambios.isEmpty()) {
               StringBuilder c = new StringBuilder("        cambios: ");
               for (AvatarPart.Cambio ch : n.cambios) {
                  c.append(ch.cuandoMs).append("ms->").append((char) ('a' + ch.material)).append(' ');
               }
               System.out.println(c.toString().trim());
            }
         }
      }
      if (!f.anomalias.isEmpty()) {
         System.out.println("anomalias:");
         for (String a : f.anomalias) {
            System.out.println("  " + a);
         }
      }
   }

   private static String existe(Map<String, Path> indice, String fichero) {
      if (fichero == null) {
         return "";
      }
      Path p = indice.get(fichero.toLowerCase());
      return p != null ? "  [EXISTE: " + p + "]" : "  [FALTA]";
   }

   // ------------------------------------------------------------------
   private static void todos(ServerTables st, Map<String, String> permitted, Map<String, Path> indice,
         List<Path> assets) {
      String[] lista = st.getTable("permittedList");
      int pares = lista.length / 2;
      int ok = 0;
      int fallo = 0;
      List<String> conAnomalias = new ArrayList<>();
      List<String> descartadas = new ArrayList<>();
      Set<String> texturas = new LinkedHashSet<>();
      Set<String> bods = new LinkedHashSet<>();
      Map<Character, Integer> letrasNoUsadas = new TreeMap<>();
      int partesTotales = 0;
      int partesAdjuntas = 0;
      int materialesTotales = 0;
      int coloresFueraDeRango = 0;

      for (int i = 0; i < lista.length; i += 2) {
         String nombre = lista[i];
         AvatarFigure f;
         try {
            f = AvatarNameDecoder.decode("avatar:" + nombre + ".rwg", permitted);
         } catch (RuntimeException e) {
            fallo++;
            conAnomalias.add(nombre + ": EXCEPCION " + e);
            continue;
         }
         if (f.anomalias.isEmpty()) {
            ok++;
         } else {
            for (String a : f.anomalias) {
               conAnomalias.add(nombre + ": " + a);
            }
         }
         for (Character c : f.letrasNoUsadas) {
            letrasNoUsadas.merge(c, 1, Integer::sum);
         }
         materialesTotales += f.paleta.size();
         for (AvatarMaterial m : f.paleta) {
            if (m.kind == AvatarMaterial.Kind.TEXTURA) {
               texturas.add(m.textureFile);
            } else if (m.origMat) {
               coloresFueraDeRango++;
            }
         }
         for (AvatarPart p : f.partes) {
            partesTotales++;
            if (p.adjunta) {
               partesAdjuntas++;
               if (p.bodFile() != null) {
                  bods.add(p.bodFile());
               }
            } else {
               descartadas.add(nombre + ": limb " + p.letra + " (tag " + p.tag + ") " + p.motivoDescarte);
            }
         }
      }

      System.out.println("permittedList: " + lista.length + " entradas = " + pares + " avatares");
      System.out.println("decodificados sin anomalias: " + ok + "/" + pares
            + "   con anomalias: " + (pares - ok - fallo) + "   excepciones: " + fallo);
      System.out.println("partes instanciadas: " + partesAdjuntas + " de " + partesTotales
            + " intentos (17 letras x " + pares + ")");
      System.out.println("materiales de paleta: " + materialesTotales
            + "   colores con indice fuera de colorTable (origMat): " + coloresFueraDeRango);
      System.out.println("letras de arranque que createSubparts NO consume: " + letrasNoUsadas);
      if (!descartadas.isEmpty()) {
         System.out.println("limbs descartadas (" + descartadas.size() + "):");
         for (String d : descartadas) {
            System.out.println("  " + d);
         }
      }
      if (!conAnomalias.isEmpty()) {
         System.out.println("anomalias (" + conAnomalias.size() + "):");
         for (String a : conAnomalias) {
            System.out.println("  " + a);
         }
      }

      System.out.println();
      System.out.println("raices de busqueda: " + assets);
      informe("texturas", texturas, indice);
      informe(".bod", bods, indice);
   }

   private static void informe(String que, Set<String> ficheros, Map<String, Path> indice) {
      List<String> faltan = new ArrayList<>();
      List<String> estan = new ArrayList<>();
      for (String f : ficheros) {
         if (indice.containsKey(f.toLowerCase())) {
            estan.add(f);
         } else {
            faltan.add(f);
         }
      }
      System.out.println(que + " referenciadas: " + ficheros.size() + "   presentes en el repo: " + estan.size()
            + "   ausentes: " + faltan.size());
      if (!estan.isEmpty()) {
         System.out.println("  presentes: " + estan);
      }
      if (!faltan.isEmpty()) {
         int n = 0;
         StringBuilder sb = new StringBuilder("  ausentes:");
         for (String f : faltan) {
            sb.append(' ').append(f);
            if (++n % 8 == 0) {
               sb.append("\n           ");
            }
         }
         System.out.println(sb);
      }
   }

   private static Map<String, Path> indexar(List<Path> raices) throws IOException {
      Map<String, Path> map = new LinkedHashMap<>();
      for (Path raiz : raices) {
         if (!Files.isDirectory(raiz)) {
            continue;
         }
         try (Stream<Path> s = Files.walk(raiz)) {
            s.filter(Files::isRegularFile).forEach(p -> map.putIfAbsent(p.getFileName().toString().toLowerCase(), p));
         }
      }
      return map;
   }
}

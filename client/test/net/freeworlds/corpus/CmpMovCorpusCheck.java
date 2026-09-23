package net.freeworlds.corpus;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * *Check de tools/run-checks.sh (contrato de COMUN.md: main que sale con
 * codigo != 0 si falla). A diferencia de {@link CmpMovCorpusCount} (que
 * necesita que el llamador ya haya extraido tex/*.cmp y tex/*.mov con
 * `unzip`), este check es autonomo: extrae el propio content.zip con
 * java.util.zip a un directorio temporal y reusa CmpMovCorpusCount.count().
 *
 * Corpus y cifra esperada (159 .cmp / 52 .mov) documentados en
 * CmpMovCorpusCount; ver tambien docs/cmp-stage1-coverage.md.
 */
public final class CmpMovCorpusCheck {
   private static final int EXPECTED_CMP = 159;
   private static final int EXPECTED_MOV = 52;

   public static void main(String[] args) throws Exception {
      File zip = new File(args.length > 0 ? args[0] : "assets/WorldsPlayer/GroundZero/content.zip");
      if (!zip.isFile()) {
         System.out.println("FALLO: no existe " + zip.getAbsolutePath());
         System.exit(2);
      }

      Path tmp = Files.createTempDirectory("cmpmov-check");
      try {
         extractTex(zip, tmp.toFile());
         CmpMovCorpusCount.Result r = CmpMovCorpusCount.count(tmp.toFile());
         System.out.println("CMP " + r.cmpOk + "/" + r.cmpTotal + " (esperado " + EXPECTED_CMP + ")");
         System.out.println("MOV " + r.movOk + "/" + r.movTotal + " (esperado " + EXPECTED_MOV + ")");

         boolean ok = r.cmpTotal == EXPECTED_CMP && r.cmpOk == EXPECTED_CMP
               && r.movTotal == EXPECTED_MOV && r.movOk == EXPECTED_MOV;
         if (!ok) {
            System.out.println("FALLO: recuento distinto del esperado (" + EXPECTED_CMP + "/" + EXPECTED_MOV + ")");
            System.exit(1);
         }
         System.out.println("OK");
      } finally {
         deleteRecursive(tmp.toFile());
      }
   }

   /** Extrae tex/*.cmp y tex/*.mov (cualquier mayus/minus) de zip a destDir, sin subcarpetas. */
   private static void extractTex(File zip, File destDir) throws IOException {
      try (ZipFile zf = new ZipFile(zip)) {
         Enumeration<? extends ZipEntry> entries = zf.entries();
         while (entries.hasMoreElements()) {
            ZipEntry e = entries.nextElement();
            if (e.isDirectory()) continue;
            String name = e.getName();
            int slash = name.lastIndexOf('/');
            String base = slash >= 0 ? name.substring(slash + 1) : name;
            String lower = base.toLowerCase();
            if (!lower.endsWith(".cmp") && !lower.endsWith(".mov")) continue;
            // Solo tex/ (evita duplicados de otras carpetas del zip, si las hubiera).
            if (!name.toLowerCase().startsWith("tex/")) continue;
            File out = new File(destDir, base);
            try (InputStream in = zf.getInputStream(e)) {
               Files.copy(in, out.toPath());
            }
         }
      }
   }

   private static void deleteRecursive(File f) {
      File[] children = f.listFiles();
      if (children != null) {
         for (File c : children) deleteRecursive(c);
      }
      f.delete();
   }
}

package net.openworlds.corpus;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

/**
 * A *Check run by tools/run-checks.sh (its contract: a main that exits
 * with code != 0 if it fails). Unlike {@link CmpMovCorpusCount} (which
 * needs the caller to have already extracted tex/*.cmp and tex/*.mov with
 * `unzip`), this check is self-contained: it extracts content.zip itself with
 * java.util.zip into a temporary directory and reuses CmpMovCorpusCount.count().
 *
 * Corpus and expected figures (159 .cmp / 52 .mov) documented in
 * CmpMovCorpusCount; see also docs/cmp-stage1-coverage.md.
 */
public final class CmpMovCorpusCheck {
   private static final int EXPECTED_CMP = 159;
   private static final int EXPECTED_MOV = 52;

   public static void main(String[] args) throws Exception {
      File zip = new File(args.length > 0 ? args[0] : "assets/WorldsPlayer/GroundZero/content.zip");
      if (!zip.isFile()) {
         System.out.println("FAIL: not found: " + zip.getAbsolutePath());
         System.exit(2);
      }

      Path tmp = Files.createTempDirectory("cmpmov-check");
      try {
         extractTex(zip, tmp.toFile());
         CmpMovCorpusCount.Result r = CmpMovCorpusCount.count(tmp.toFile());
         System.out.println("CMP " + r.cmpOk + "/" + r.cmpTotal + " (expected " + EXPECTED_CMP + ")");
         System.out.println("MOV " + r.movOk + "/" + r.movTotal + " (expected " + EXPECTED_MOV + ")");

         boolean ok = r.cmpTotal == EXPECTED_CMP && r.cmpOk == EXPECTED_CMP
               && r.movTotal == EXPECTED_MOV && r.movOk == EXPECTED_MOV;
         if (!ok) {
            System.out.println("FAIL: count differs from the expected one (" + EXPECTED_CMP + "/" + EXPECTED_MOV + ")");
            System.exit(1);
         }
         System.out.println("OK");
      } finally {
         deleteRecursive(tmp.toFile());
      }
   }

   /** Extracts tex/*.cmp and tex/*.mov (any letter case) from zip into destDir, without subfolders. */
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
            // Only tex/ (avoids duplicates from other folders of the zip, if there were any).
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

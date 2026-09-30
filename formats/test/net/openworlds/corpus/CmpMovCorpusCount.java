package net.openworlds.corpus;

import java.io.File;
import java.util.Arrays;
import java.util.Comparator;

import net.openworlds.cmp.CmpTexture;

/**
 * Counting main for the regression runner (tools/verify-corpus.sh, milestone
 * H0 of docs/roadmap.md). There is no *Main in formats/src that prints
 * an aggregate count of .cmp/.mov (CmpStage2 only compares a file of
 * captured evidence, CmpTexture has no CLI): this main calls
 * {@link CmpTexture#loadRaw(File)} and
 * {@link CmpTexture#loadMov(File)} directly, which are the real path used by
 * the materials pipeline, over the whole real corpus.
 *
 * Corpus: the 159 `.cmp` and 52 `.mov` under `tex/` inside
 * assets/WorldsPlayer/GroundZero/content.zip (identical by hash to
 * assets/GROUNDZERO/CONTENT.ZIP) - see docs/cmp-stage1-coverage.md and
 * docs/cmp-texture-format-reference.md ("159/159 ... 52/52"). The zip is not
 * read directly here (Files.readAllBytes expects a real File, and
 * CmpTexture.loadRaw/loadMov take a File): tools/verify-corpus.sh extracts
 * `tex/*.cmp` and `tex/*.mov` into a temporary directory with `unzip` before
 * invoking this main. {@link CmpMovCorpusCheck} does the same extraction in
 * Java (without depending on `unzip`) and reuses {@link #count(File)}.
 *
 * Usage: java -cp ... net.openworlds.corpus.CmpMovCorpusCount <dir-with-extracted-tex>
 * Prints one line per failing file and the final summary
 * "CMP ok/total" / "MOV ok/total"; exits with 0 only if both are 100%.
 */
public final class CmpMovCorpusCount {

   /** ok/total of .cmp and .mov under dir (non-recursive), really decoding each one. */
   public static final class Result {
      public final int cmpOk, cmpTotal, movOk, movTotal;
      Result(int cmpOk, int cmpTotal, int movOk, int movTotal) {
         this.cmpOk = cmpOk; this.cmpTotal = cmpTotal; this.movOk = movOk; this.movTotal = movTotal;
      }
   }

   public static Result count(File dir) {
      File[] all = dir.listFiles();
      if (all == null) {
         throw new IllegalArgumentException("Not a directory: " + dir);
      }
      Arrays.sort(all, Comparator.comparing(File::getName));

      int cmpOk = 0, cmpTotal = 0, movOk = 0, movTotal = 0;
      for (File f : all) {
         String n = f.getName().toLowerCase();
         if (n.endsWith(".cmp")) {
            cmpTotal++;
            try {
               CmpTexture t = CmpTexture.loadRaw(f);
               if (t.width <= 0 || t.height <= 0) {
                  throw new IllegalStateException("invalid geometry " + t.width + "x" + t.height);
               }
               cmpOk++;
            } catch (Exception e) {
               System.out.println("CMP FAIL " + f.getName() + ": " + e);
            }
         } else if (n.endsWith(".mov")) {
            movTotal++;
            try {
               CmpTexture t = CmpTexture.loadMov(f);
               if (t.width <= 0 || t.height <= 0) {
                  throw new IllegalStateException("invalid geometry " + t.width + "x" + t.height);
               }
               movOk++;
            } catch (Exception e) {
               System.out.println("MOV FAIL " + f.getName() + ": " + e);
            }
         }
      }
      return new Result(cmpOk, cmpTotal, movOk, movTotal);
   }

   public static void main(String[] args) {
      if (args.length < 1) {
         System.err.println("Usage: CmpMovCorpusCount <dir-with-tex-extracted-from-content.zip>");
         System.exit(2);
      }
      Result r = count(new File(args[0]));
      System.out.println("CMP " + r.cmpOk + "/" + r.cmpTotal);
      System.out.println("MOV " + r.movOk + "/" + r.movTotal);
      boolean ok = r.cmpTotal > 0 && r.movTotal > 0 && r.cmpOk == r.cmpTotal && r.movOk == r.movTotal;
      System.exit(ok ? 0 : 1);
   }
}

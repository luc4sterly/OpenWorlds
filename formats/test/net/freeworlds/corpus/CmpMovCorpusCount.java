package net.freeworlds.corpus;

import java.io.File;
import java.util.Arrays;
import java.util.Comparator;

import net.freeworlds.cmp.CmpTexture;

/**
 * Main de recuento para el runner de regresion (tools/verify-corpus.sh, hito
 * H0 de docs/roadmap.md). No existe ningun *Main en formats/src que imprima
 * un recuento agregado de .cmp/.mov (CmpStage2 solo compara un fichero de
 * evidencia capturada, CmpTexture no tiene CLI): este main llama
 * directamente a {@link CmpTexture#loadRaw(File)} y
 * {@link CmpTexture#loadMov(File)}, que son el camino real usado por el
 * pipeline de materiales, sobre el corpus real completo.
 *
 * Corpus: los 159 `.cmp` y 52 `.mov` bajo `tex/` dentro de
 * assets/WorldsPlayer/GroundZero/content.zip (identico por hash a
 * assets/GROUNDZERO/CONTENT.ZIP) - ver docs/cmp-stage1-coverage.md y
 * docs/cmp-texture-format-reference.md ("159/159 ... 52/52"). El zip no se
 * lee directamente aqui (Files.readAllBytes espera un File real, y
 * CmpTexture.loadRaw/loadMov toman un File): tools/verify-corpus.sh extrae
 * `tex/*.cmp` y `tex/*.mov` a un directorio temporal con `unzip` antes de
 * invocar este main. {@link CmpMovCorpusCheck} hace la misma extraccion en
 * Java (sin depender de `unzip`) y reusa {@link #count(File)}.
 *
 * Uso: java -cp ... net.freeworlds.corpus.CmpMovCorpusCount <dir-con-tex-extraido>
 * Imprime una linea por fichero que falla y el resumen final
 * "CMP ok/total" / "MOV ok/total"; sale con 0 solo si ambos son 100%.
 */
public final class CmpMovCorpusCount {

   /** ok/total de .cmp y .mov bajo dir (no recursivo), decodificando cada uno de verdad. */
   public static final class Result {
      public final int cmpOk, cmpTotal, movOk, movTotal;
      Result(int cmpOk, int cmpTotal, int movOk, int movTotal) {
         this.cmpOk = cmpOk; this.cmpTotal = cmpTotal; this.movOk = movOk; this.movTotal = movTotal;
      }
   }

   public static Result count(File dir) {
      File[] all = dir.listFiles();
      if (all == null) {
         throw new IllegalArgumentException("No es un directorio: " + dir);
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
                  throw new IllegalStateException("geometria invalida " + t.width + "x" + t.height);
               }
               cmpOk++;
            } catch (Exception e) {
               System.out.println("CMP FALLO " + f.getName() + ": " + e);
            }
         } else if (n.endsWith(".mov")) {
            movTotal++;
            try {
               CmpTexture t = CmpTexture.loadMov(f);
               if (t.width <= 0 || t.height <= 0) {
                  throw new IllegalStateException("geometria invalida " + t.width + "x" + t.height);
               }
               movOk++;
            } catch (Exception e) {
               System.out.println("MOV FALLO " + f.getName() + ": " + e);
            }
         }
      }
      return new Result(cmpOk, cmpTotal, movOk, movTotal);
   }

   public static void main(String[] args) {
      if (args.length < 1) {
         System.err.println("Uso: CmpMovCorpusCount <dir-con-tex-extraido-de-content.zip>");
         System.exit(2);
      }
      Result r = count(new File(args[0]));
      System.out.println("CMP " + r.cmpOk + "/" + r.cmpTotal);
      System.out.println("MOV " + r.movOk + "/" + r.movTotal);
      boolean ok = r.cmpTotal > 0 && r.movTotal > 0 && r.cmpOk == r.cmpTotal && r.movOk == r.movTotal;
      System.exit(ok ? 0 : 1);
   }
}

package net.freeworlds.rwg;

import java.util.List;

/**
 * One ATOM chunk = one joint/segment: a 52-byte STRT header (mostly
 * unresolved), two 4x4 MATX transforms (verified identity matrices in
 * every real sample, matching GammaDocs' "joint matrices must be
 * identity"), a VLST vertex list and a PLST polygon list.
 *
 * ⚠️ VERIFICAR: whether/how multiple ATOMs nest to form a joint hierarchy
 * has NOT been verified - both real .rwg samples contain exactly one
 * ATOM each. See docs/rwg-bod-format-reference.md, "Hallazgo central".
 */
public final class RwgAtom {
   /** Raw 52-byte / 13-int STRT header. First two ints confirmed [1, 4] in both samples; rest unresolved. */
   public final int[] headerRaw;
   /** First MATX, 16 floats row-major-vs-column-major undetermined (identity in every sample so far - can't distinguish). */
   public final float[] matrix1;
   /** Second MATX, same caveats as matrix1. */
   public final float[] matrix2;
   public final List<RwgVertex> vertices;
   public final List<RwgPolygon> polygons;

   public RwgAtom(int[] headerRaw, float[] matrix1, float[] matrix2,
                   List<RwgVertex> vertices, List<RwgPolygon> polygons) {
      this.headerRaw = headerRaw;
      this.matrix1 = matrix1;
      this.matrix2 = matrix2;
      this.vertices = vertices;
      this.polygons = polygons;
   }
}

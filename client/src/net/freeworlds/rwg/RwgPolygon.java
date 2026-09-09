package net.freeworlds.rwg;

/**
 * One PLST polygon record: [id/flag][vertexCount][vertexCount x 1-based
 * index][trailing ints, first 3 = face normal (x,y,z)]. Verified against
 * a real 6-face cube (assets/gammatutorial-samples/cube.rwg, one real
 * normal per axis direction) and IDLE.RWG's single quad - see
 * docs/rwg-bod-format-reference.md. The leading id/flag field is NOT the
 * constant 1 it first appeared to be: assets/gammatutorial-samples/
 * ball.rwg's real bytes show it counting 1..512, one per polygon -
 * discarded here (RwgParser reads and ignores it). Trailing ints beyond
 * the first 3 (normal) remain ⚠️ VERIFICAR - always seen as 0 so far,
 * meaning unknown (reserved? material index? unused).
 */
public final class RwgPolygon {
   /** 0-based vertex indices into the owning ATOM's vertex list (converted from the file's 1-based indices). */
   public final int[] vertexIndices;
   /** ⚠️ VERIFICAR (medium-high confidence) - face normal, first 3 trailing floats: (trailingRaw[0], trailingRaw[1], trailingRaw[2]) reinterpreted as floats. */
   public final int[] trailingRaw;

   public RwgPolygon(int[] vertexIndices, int[] trailingRaw) {
      this.vertexIndices = vertexIndices;
      this.trailingRaw = trailingRaw;
   }

   /** Face normal decoded from the first 3 trailing ints, or null if this record has fewer than 3 trailing fields. */
   public float[] normal() {
      if (trailingRaw.length < 3) {
         return null;
      }
      return new float[]{
         Float.intBitsToFloat(trailingRaw[0]),
         Float.intBitsToFloat(trailingRaw[1]),
         Float.intBitsToFloat(trailingRaw[2])
      };
   }
}

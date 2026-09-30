package net.openworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * An ATOM = a clump, as read by RWL21.DLL's RwReadStreamChunk(ATOM)
 * (0x1003b569). The 13-integer STRT is distributed like this (0x1003b648..):
 *
 * <pre>
 *  [0]  clump+0x8c (RwCreateClump sets 1)   ⚠️ VERIFY meaning
 *  [1]  clump+0x90 (RwCreateClump sets 4)   ⚠️ VERIFY meaning
 *  [2]  tag                                 clump+0xe8 (RwGetClumpTag 0x100044a0)
 *  [3..7] not read by RW
 *  [8]  hints                               RwSetClumpHints at the end
 *  [9]  axis alignment                      clump+0x18c (RwGetClumpAxisAlignment)
 *  [10] state (1 OFF, 2 ON)                 clump+0x190 (RwGetClumpState)
 *  [11] number of child ATOMs               read after PLST and hung with RwAddChildToClump
 *  [12] light sampling rate                 RwSetClumpLightSampleRate (real; 0 sets +0x19b to 0)
 * </pre>
 *
 * Then two MATX (16 reals each, RwSetMatrixElements) that go to
 * clump+0xec and clump+0x130, VLST and PLST, and the children. ⚠️ no real
 * sample: all the corpus's .rwg files have [11] = 0, so the reading of
 * children follows the binary but has never been seen in a file.
 */
public final class RwgAtom {
   /** The 13 STRT integers as they are. */
   public final int[] headerRaw;
   /** First MATX (clump+0xec), 16 reals in file order. */
   public final float[] matrix1;
   /** Second MATX (clump+0x130). */
   public final float[] matrix2;
   /** VLST records 0..7: the local box (RwGetClumpNumVertices 0x10003fe0 subtracts 8). */
   public final List<RwgVertex> boundingBoxCorners;
   /** VLST records 8..: PLST's index n (1-based) is vertices.get(n - 1). */
   public final List<RwgVertex> vertices;
   public final List<RwgPolygon> polygons;
   public final List<RwgAtom> children = new ArrayList<>();

   public RwgAtom(int[] headerRaw, float[] matrix1, float[] matrix2, List<RwgVertex> boundingBoxCorners,
                  List<RwgVertex> vertices, List<RwgPolygon> polygons) {
      this.headerRaw = headerRaw;
      this.matrix1 = matrix1;
      this.matrix2 = matrix2;
      this.boundingBoxCorners = boundingBoxCorners;
      this.vertices = vertices;
      this.polygons = polygons;
   }

   public int tag() {
      return this.headerRaw[2];
   }

   public int hints() {
      return this.headerRaw[8];
   }

   public int axisAlignment() {
      return this.headerRaw[9];
   }

   public int state() {
      return this.headerRaw[10];
   }

   public int childCount() {
      return this.headerRaw[11];
   }

   public float lightSampleRate() {
      return Float.intBitsToFloat(this.headerRaw[12]);
   }
}

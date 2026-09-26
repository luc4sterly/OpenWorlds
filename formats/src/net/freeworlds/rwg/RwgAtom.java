package net.freeworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * Un ATOM = un clump, como lo lee RwReadStreamChunk(ATOM) de RWL21.DLL
 * (0x1003b569). El STRT de 13 enteros se reparte así (0x1003b648..):
 *
 * <pre>
 *  [0]  clump+0x8c (RwCreateClump pone 1)   ⚠️ VERIFICAR significado
 *  [1]  clump+0x90 (RwCreateClump pone 4)   ⚠️ VERIFICAR significado
 *  [2]  tag                                 clump+0xe8 (RwGetClumpTag 0x100044a0)
 *  [3..7] no los lee RW
 *  [8]  hints                               RwSetClumpHints al final
 *  [9]  alineación de ejes                  clump+0x18c (RwGetClumpAxisAlignment)
 *  [10] estado (1 OFF, 2 ON)                clump+0x190 (RwGetClumpState)
 *  [11] número de ATOM hijos                se leen tras PLST y se cuelgan con RwAddChildToClump
 *  [12] frecuencia de muestreo de luz       RwSetClumpLightSampleRate (real; 0 pone +0x19b a 0)
 * </pre>
 *
 * Después, dos MATX (16 reales cada uno, RwSetMatrixElements) que van a
 * clump+0xec y clump+0x130, VLST y PLST, y los hijos. ⚠️ sin muestra real:
 * todos los .rwg del corpus tienen [11] = 0, así que la lectura de hijos
 * sigue al binario pero no se ha visto nunca en un fichero.
 */
public final class RwgAtom {
   /** Los 13 enteros del STRT tal cual. */
   public final int[] headerRaw;
   /** Primer MATX (clump+0xec), 16 reales en el orden del fichero. */
   public final float[] matrix1;
   /** Segundo MATX (clump+0x130). */
   public final float[] matrix2;
   /** Registros 0..7 de VLST: la caja local (RwGetClumpNumVertices 0x10003fe0 resta 8). */
   public final List<RwgVertex> boundingBoxCorners;
   /** Registros 8.. de VLST: el índice n (base 1) de PLST es vertices.get(n - 1). */
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

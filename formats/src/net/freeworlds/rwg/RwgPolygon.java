package net.freeworlds.rwg;

/**
 * Un registro de PLST tal como lo lee RwReadStreamChunk(PLST) de
 * RWL21.DLL (0x1003a6d9):
 *
 * <pre>
 *  siempre      material (índice base 1 en la lista de MALT; 0 o fuera de
 *               rango = sin material), número de vértices n
 *  siempre      n índices base 1 (contando desde el vértice 1 de RW, o sea
 *               el registro 8 de VLST)
 *  bandera 1    normal de cara (3 reales)            -> polígono +0x10..
 *  bandera 4    3 reales a 16.16 (x 65536)           -> polígono +0x04..+0x0c
 *  bandera 0x10 tag (entero; se guarda en 16 bits)   -> polígono +0x38
 * </pre>
 *
 * El primer campo, que antes se leía como "id/flag", es el índice de
 * material: en ball.rwg cuenta 1..512 porque ese fichero trae 512
 * materiales en MALT, uno por triángulo.
 */
public final class RwgPolygon {
   /** Índice base 1 en {@link RwgModel#materials}; 0 = sin material. */
   public final int materialIndex;
   /** Índices 0-based en {@link RwgAtom#vertices} (el fichero los trae base 1). */
   public final int[] vertexIndices;
   /** Normal de cara (bandera 1), o null. */
   private final float[] normal;
   /**
    * ⚠️ VERIFICAR: los 3 reales de la bandera 4 (polígono +0x04..+0x0c a
    * 16.16); ninguna función de RWL21 revisada los nombra. En el corpus
    * son siempre 0.
    */
   public final float[] extra;
   /** Tag del polígono (bandera 0x10), truncado a 16 bits como en +0x38; 0 sin bandera. */
   public final short tag;

   public RwgPolygon(int materialIndex, int[] vertexIndices, float[] normal, float[] extra, short tag) {
      this.materialIndex = materialIndex;
      this.vertexIndices = vertexIndices;
      this.normal = normal;
      this.extra = extra;
      this.tag = tag;
   }

   /** Normal de cara guardada (bandera 1 del STRT de PLST), o null si el fichero no la trae. */
   public float[] normal() {
      return this.normal == null ? null : this.normal.clone();
   }
}

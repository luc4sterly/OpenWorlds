package net.openworlds.rwg;

/**
 * Un RAST de la lista RALT, como lo lee RwReadStreamChunk(RAST) de
 * RWL21.DLL (0x1003c72a): un STRT de 10 enteros y un chunk DATA con los
 * píxeles. RW crea un raster de [0] x [1] (RwCreateRaster 0x100210d0); si
 * los campos [4..9] coinciden con el formato de ese raster copia DATA fila
 * a fila con el paso [3] (0x1003c905), y si no lo convierte con el driver
 * (dispositivo+0x48, 0x1003c9ef).
 *
 * ⚠️ sin muestra real: ningún .rwg del corpus tiene RALT con registros
 * (todos dicen 0), así que aquí solo se guardan los campos y los bytes;
 * el significado exacto de [2] y [4..9] (formato del raster del driver) no
 * se ha extraído.
 */
public final class RwgRaster {
   /** Los 10 enteros del STRT: [0] ancho, [1] alto, [3] bytes por fila, resto formato. */
   public final int[] fields;
   public final byte[] data;

   public RwgRaster(int[] fields, byte[] data) {
      this.fields = fields;
      this.data = data;
   }

   public int width() {
      return this.fields[0];
   }

   public int height() {
      return this.fields[1];
   }
}

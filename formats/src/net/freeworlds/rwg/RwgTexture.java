package net.freeworlds.rwg;

/**
 * Una entrada de TELT, como la lee RwReadStreamChunk(TELT) de RWL21.DLL
 * (0x1003cc1c): 5 enteros (0x14 bytes, big-endian) y después el primer
 * sub-chunk STNG que aparezca, con el nombre.
 *
 * <pre>
 *  [0] raster: índice base 1 en la lista de RALT, o 0 = textura con nombre
 *  [1] raster del mipmap: índice base 1 en RALT, o 0 (solo con [0] != 0)
 *  [2..4] no los lee nadie en RWL21 (se guardan tal cual)
 * </pre>
 *
 * Con raster 0 la textura se resuelve por nombre (0x1003cde9): en el
 * diccionario (FUN_100184d0) y, si no está y existe un fichero con ese
 * nombre en la ruta de formas (FUN_10021270), RwGetNamedTexture; si no hay
 * textura, el error 0x5e y el CLUM entero falla. Con raster != 0
 * (0x1003cd40) se crea una textura sobre ese raster de RALT, se le pone el
 * mipmap y se mete en el diccionario con este nombre.
 */
public final class RwgTexture {
   public final int rasterIndex;
   public final int mipmapRasterIndex;
   /** Los 5 enteros del registro tal cual. */
   public final int[] raw;
   /** Contenido del STNG hasta el primer NUL; null si el STNG tiene longitud 0. */
   public final String name;

   public RwgTexture(int[] raw, String name) {
      this.raw = raw;
      this.rasterIndex = raw[0];
      this.mipmapRasterIndex = raw[1];
      this.name = name;
   }
}

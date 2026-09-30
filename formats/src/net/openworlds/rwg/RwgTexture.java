package net.openworlds.rwg;

/**
 * A TELT entry, as read by RWL21.DLL's RwReadStreamChunk(TELT)
 * (0x1003cc1c): 5 integers (0x14 bytes, big-endian) and then the first
 * STNG sub-chunk that appears, with the name.
 *
 * <pre>
 *  [0] raster: 1-based index into the RALT list, or 0 = named texture
 *  [1] mipmap raster: 1-based index into RALT, or 0 (only with [0] != 0)
 *  [2..4] nobody reads them in RWL21 (stored as they are)
 * </pre>
 *
 * With raster 0 the texture is resolved by name (0x1003cde9): in the
 * dictionary (FUN_100184d0) and, if it is not there and a file with that
 * name exists on the shapes path (FUN_10021270), RwGetNamedTexture; if there
 * is no texture, error 0x5e and the whole CLUM fails. With raster != 0
 * (0x1003cd40) a texture is created over that RALT raster, the
 * mipmap is set on it and it is put in the dictionary under this name.
 */
public final class RwgTexture {
   public final int rasterIndex;
   public final int mipmapRasterIndex;
   /** The record's 5 integers as they are. */
   public final int[] raw;
   /** STNG contents up to the first NUL; null if the STNG has length 0. */
   public final String name;

   public RwgTexture(int[] raw, String name) {
      this.raw = raw;
      this.rasterIndex = raw[0];
      this.mipmapRasterIndex = raw[1];
      this.name = name;
   }
}

package net.openworlds.rwg;

/**
 * A RAST of the RALT list, as read by RWL21.DLL's RwReadStreamChunk(RAST)
 * (0x1003c72a): an STRT of 10 integers and a DATA chunk with the
 * pixels. RW creates a raster of [0] x [1] (RwCreateRaster 0x100210d0); if
 * fields [4..9] match that raster's format it copies DATA row
 * by row with pitch [3] (0x1003c905), and if not it converts it with the
 * driver (device+0x48, 0x1003c9ef).
 *
 * ⚠️ no real sample: no .rwg in the corpus has a RALT with records
 * (they all say 0), so only the fields and the bytes are stored here;
 * the exact meaning of [2] and [4..9] (the driver raster's format) has
 * not been extracted.
 */
public final class RwgRaster {
   /** The 10 STRT integers: [0] width, [1] height, [3] bytes per row, the rest is format. */
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

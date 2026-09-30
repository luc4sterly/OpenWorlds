package net.openworlds.rwg;

/**
 * A MALT record: the 10 4-byte (big-endian) integers that
 * RWL21.DLL's RwReadStreamChunk(MALT) reads per material (0x1003c0ab: reads
 * 0x28 bytes, and if the STRT's record size is larger it skips the rest)
 * and how it applies them to a new RwCreateMaterial (0x1003c10a..0x1003c180):
 *
 * <pre>
 *  [0] texture: 1-based index into the list that TELT leaves (0 = no texture;
 *      out of range also gives texture 0)         -> RwSetMaterialTexture
 *  [1] material word 0 (sampling)                 -> material+0
 *  [2] low byte: texture and material modes       -> material+0x30
 *  [3..5] color r, g, b (reals)                   -> RwSetMaterialColor
 *  [6] opacity (real)                             -> RwSetMaterialOpacity
 *  [7..9] ambient, diffuse, specular (reals)      -> RwSetMaterialSurface
 * </pre>
 *
 * Word 0 is read the way RWL21's getters read it:
 * RwGetMaterialGeometrySampling (0x10019e40) and RwGetMaterialLightSampling
 * (0x10019ea0). The +0x30 byte is split between RwGetMaterialTextureModes
 * (0x10019d70, {@code & 0x1f}) and RwGetMaterialModes (0x10019d90,
 * {@code & 0xc0}).
 */
public final class RwgMaterial {
   public final int textureIndex;
   public final int samplingWord;
   public final int modesByte;
   public final float r;
   public final float g;
   public final float b;
   public final float opacity;
   public final float ambient;
   public final float diffuse;
   public final float specular;

   public RwgMaterial(int[] rec) {
      this.textureIndex = rec[0];
      this.samplingWord = rec[1];
      this.modesByte = rec[2] & 0xFF;
      this.r = Float.intBitsToFloat(rec[3]);
      this.g = Float.intBitsToFloat(rec[4]);
      this.b = Float.intBitsToFloat(rec[5]);
      this.opacity = Float.intBitsToFloat(rec[6]);
      this.ambient = Float.intBitsToFloat(rec[7]);
      this.diffuse = Float.intBitsToFloat(rec[8]);
      this.specular = Float.intBitsToFloat(rec[9]);
   }

   /**
    * RwGetMaterialGeometrySampling (0x10019e40): word &lt; 4 -&gt; 1
    * (point cloud), &lt; 8 -&gt; 2 (wireframe), &lt; 0xc -&gt; 3, otherwise -&gt; 4
    * (solid); a word &gt; 0x3f is error 0x67 and gives 0.
    */
   public int geometrySampling() {
      int w = this.samplingWord;
      if (w < 0 || w > 0x3f) {
         return 0;
      }
      if (w < 4) {
         return 1;
      }
      if (w < 8) {
         return 2;
      }
      return w < 0xc ? 3 : 4;
   }

   /** RwGetMaterialLightSampling (0x10019ea0): bit 0 -&gt; 2 (per vertex), otherwise 1 (per facet). */
   public int lightSampling() {
      return (this.samplingWord & 1) == 0 ? 1 : 2;
   }

   /** RwGetMaterialTextureModes (0x10019d70): 1 lit, 2 foreshorten, 4 filter, 0x10 trilinear (and 8, internal). */
   public int textureModes() {
      return this.modesByte & 0x1f;
   }

   /** RwGetMaterialModes (0x10019d90): 0x80 double-sided, 0x40 decal. */
   public int materialModes() {
      return this.modesByte & 0xc0;
   }
}

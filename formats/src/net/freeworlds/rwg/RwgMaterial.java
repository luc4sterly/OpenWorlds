package net.freeworlds.rwg;

/**
 * Un registro de MALT: los 10 enteros de 4 bytes (big-endian) que
 * RwReadStreamChunk(MALT) de RWL21.DLL lee por material (0x1003c0ab: lee
 * 0x28 bytes, y si el tamaño de registro del STRT es mayor salta el resto)
 * y cómo los aplica a un RwCreateMaterial nuevo (0x1003c10a..0x1003c180):
 *
 * <pre>
 *  [0] textura: índice base 1 en la lista que deja TELT (0 = sin textura;
 *      fuera de rango también da textura 0)        -> RwSetMaterialTexture
 *  [1] palabra 0 del material (muestreo)           -> material+0
 *  [2] byte bajo: modos de textura y de material   -> material+0x30
 *  [3..5] color r, g, b (reales)                   -> RwSetMaterialColor
 *  [6] opacidad (real)                             -> RwSetMaterialOpacity
 *  [7..9] ambiente, difusa, especular (reales)     -> RwSetMaterialSurface
 * </pre>
 *
 * La palabra 0 se lee como la leen los getters de RWL21:
 * RwGetMaterialGeometrySampling (0x10019e40) y RwGetMaterialLightSampling
 * (0x10019ea0). El byte de +0x30 lo reparten RwGetMaterialTextureModes
 * (0x10019d70, {@code & 0x1f}) y RwGetMaterialModes (0x10019d90,
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
    * RwGetMaterialGeometrySampling (0x10019e40): palabra &lt; 4 -&gt; 1
    * (nube de puntos), &lt; 8 -&gt; 2 (alambre), &lt; 0xc -&gt; 3, resto -&gt; 4
    * (sólido); una palabra &gt; 0x3f es el error 0x67 y da 0.
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

   /** RwGetMaterialLightSampling (0x10019ea0): bit 0 -&gt; 2 (por vértice), si no 1 (por faceta). */
   public int lightSampling() {
      return (this.samplingWord & 1) == 0 ? 1 : 2;
   }

   /** RwGetMaterialTextureModes (0x10019d70): 1 lit, 2 foreshorten, 4 filter, 0x10 trilinear (y 8, interno). */
   public int textureModes() {
      return this.modesByte & 0x1f;
   }

   /** RwGetMaterialModes (0x10019d90): 0x80 doble cara, 0x40 decal. */
   public int materialModes() {
      return this.modesByte & 0xc0;
   }
}

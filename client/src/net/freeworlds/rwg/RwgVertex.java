package net.freeworlds.rwg;

/**
 * Un registro de VLST tal como lo lee RwReadStreamChunk(VLST) de
 * RWL21.DLL (0x1003b328). Las banderas del STRT de VLST dicen qué campos
 * trae cada registro, en este orden:
 *
 * <pre>
 *  siempre      x, y, z (3 reales)                  -> vértice +0x0c..
 *  bandera 1    normal (3 reales), marca 0x40        -> vértice +0x04.. (normal puesta)
 *  bandera 2    u, v (2 reales) a 16.16 (x 65536)    -> vértice +0x1c/+0x20
 *  bandera 4    3 reales a 16.16 (x 65536)           -> vértice +0x10/+0x14/+0x18
 * </pre>
 *
 * El factor 65536.0 es DAT_10052298 (double leído del binario) y el paso
 * a entero es __ftol (0x10044788). Los campos que el registro no trae
 * quedan a 0 aquí y {@link #hasNormal}/{@link #hasUv}/{@link #hasExtra}
 * lo dicen.
 */
public final class RwgVertex {
   public final float x;
   public final float y;
   public final float z;
   public final boolean hasNormal;
   public final float normalX;
   public final float normalY;
   public final float normalZ;
   public final boolean hasUv;
   public final float u;
   public final float v;
   public final boolean hasExtra;
   /**
    * ⚠️ VERIFICAR: los 3 reales de la bandera 4 (vértice +0x10..+0x18, a
    * 16.16). Ninguna función exportada de RWL21 revisada lee esos campos
    * con nombre, y en el corpus son siempre 0.
    */
   public final float unknown8;
   public final float unknown9;
   public final float unknown10;

   public RwgVertex(float x, float y, float z, boolean hasNormal, float normalX, float normalY, float normalZ,
                    boolean hasUv, float u, float v, boolean hasExtra, float unknown8, float unknown9, float unknown10) {
      this.x = x;
      this.y = y;
      this.z = z;
      this.hasNormal = hasNormal;
      this.normalX = normalX;
      this.normalY = normalY;
      this.normalZ = normalZ;
      this.hasUv = hasUv;
      this.u = u;
      this.v = v;
      this.hasExtra = hasExtra;
      this.unknown8 = unknown8;
      this.unknown9 = unknown9;
      this.unknown10 = unknown10;
   }

   /** RW guarda la UV como 16.16 (__ftol trunca hacia cero): el valor que ve el rasterizador. */
   public static int toFixed(float f) {
      return (int) (f * 65536.0);
   }
}

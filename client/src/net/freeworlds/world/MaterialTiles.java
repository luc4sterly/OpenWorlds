package net.freeworlds.world;

import java.util.ArrayList;
import java.util.List;

/**
 * Como reparte el cliente original las texturas de UN Material entre las
 * celdas de un Rect: sufijos "Nh*", "Nv*", "Ns*" del nombre de textura, a
 * que fichero y a que frame de un .mov va cada celda, y la geometria de
 * las celdas.
 *
 * Fuentes (Java original, editor/.../source/NET/worlds/scape):
 * - Material.calcRes: nombre acabado en ".mov" => sPos = 0; si acaba en
 *   "*.xxx", se leen hacia atras grupos "&lt;digito 1-9&gt;&lt;letra&gt;*":
 *   h = hRes, v = vRes, s = sPos + 1 (solo en .mov); devuelve la longitud
 *   del sufijo (grupos + extension) o -1.
 * - Material.loadTextures: hRes*vRes texturas. Con .mov, un unico fichero
 *   (nombre sin sufijo + ".mov"); sin .mov, un .cmp por celda llamado
 *   nombre + fila (vRes..1) + columna (1..hRes) + ".cmp".
 * - Material.syncBackgroundLoad: con .mov, textura[k*hRes + c] = frame
 *   hRes*vRes*sPos + (vRes-1-k)*hRes + c de la pelicula (si la pelicula
 *   tiene menos de hRes*vRes*(sPos+1) frames, error de carga).
 * - Surface.recursiveAddRwChildren: con hRes o vRes &gt; 1 el Rect se parte
 *   en celdas (Surface.addSubPolys, gamma.dll 0x004206d0) y
 *   Surface.nativeSetMaterial (0x00420500) da al poligono i el material
 *   i mod (hRes*vRes).
 *
 * Resultado para un Rect con u = v = 1: el frame 0 de la pelicula queda
 * arriba a la izquierda y siguen en orden de lectura (ver
 * client/test/.../world/MaterialTilesCheck).
 */
public final class MaterialTiles {
   public final int hRes;
   public final int vRes;
   /** Grupo de frames (sufijo "Ns*" menos 1); -1 si no es un .mov. */
   public final int sPos;
   /** Fichero de cada textura (nombre base, sin directorio). */
   public final String[] files;
   /** Frame de cada textura dentro de su fichero (0 en los .cmp). */
   public final int[] frames;

   private MaterialTiles(int hRes, int vRes, int sPos, String[] files, int[] frames) {
      this.hRes = hRes;
      this.vRes = vRes;
      this.sPos = sPos;
      this.files = files;
      this.frames = frames;
   }

   /** Material.getHiRes(): el Rect se parte en celdas. */
   public boolean hiRes() {
      return hRes > 1 || vRes > 1;
   }

   public boolean movie() {
      return sPos >= 0;
   }

   /** Frames que exige Material.syncBackgroundLoad a la pelicula. */
   public int framesNeeded() {
      return hRes * vRes * (sPos + 1);
   }

   /** Material.calcRes + loadTextures + syncBackgroundLoad para un nombre de textura. */
   public static MaterialTiles of(String url) {
      int hRes = 1;
      int vRes = 1;
      int sPos = -1;
      int n = url.length();
      if (n >= 4 && url.regionMatches(true, n - 4, ".mov", 0, 4)) {
         sPos = 0;
      }
      int suffix = -1;
      if (n > 7 && url.regionMatches(true, n - 5, "*.", 0, 2)) {
         int i;
         int d;
         for (i = n - 5; i > 2 && url.charAt(i) == '*' && (d = url.charAt(i - 2) - '0') > 0 && d <= 9; i -= 3) {
            char c = Character.toLowerCase(url.charAt(i - 1));
            if (c == 'h') {
               hRes = d;
            } else if (c == 'v') {
               vRes = d;
            } else if (c == 's' && sPos >= 0) {
               sPos = d - 1;
            }
         }
         suffix = n - (i + 1);
      }
      String base = url.substring(url.lastIndexOf('/') + 1);
      if (suffix < 0 || suffix > base.length()) {
         // Material.loadTextures, rama sin sufijo: una textura, el propio
         // nombre; con .mov syncBackgroundLoad toma el frame 0.
         return new MaterialTiles(1, 1, sPos, new String[]{base}, new int[]{0});
      }
      String stem = base.substring(0, base.length() - suffix);
      int count = hRes * vRes;
      String[] files = new String[count];
      int[] frames = new int[count];
      for (int k = 0; k < count; k++) {
         int row = k / hRes;
         int col = k % hRes;
         if (sPos >= 0) {
            files[k] = stem + ".mov";
            frames[k] = hRes * vRes * sPos + (vRes - 1 - row) * hRes + col;
         } else {
            files[k] = stem + (vRes - row) + (col + 1) + ".cmp";
         }
      }
      return new MaterialTiles(hRes, vRes, sPos, files, frames);
   }

   /**
    * Celdas de un Rect (Surface.addSubPolys, gamma.dll 0x004206d0) con los
    * cuatro vertices que le pone Rect.addRwChildren: 1 = (0,0,0) uv
    * (uo, v+vo), 2 = (1,0,0) uv (u+uo, v+vo), 3 = (1,0,1), 4 = (0,0,1) uv
    * (uo, vo), con uo = (uOff*u) mod 2 y vo = (vOff*v) mod 2 (0 si el
    * offset es 0). Cada celda es {xc, xd, za, zb, c, d, a, b, material}:
    * vertices (xc,0,za) uv (c,a), (xd,0,za) (d,a), (xd,0,zb) (d,b),
    * (xc,0,zb) (c,b) en coordenadas locales del Rect; v de RW cuenta desde
    * la fila de arriba de la textura.
    *
    * Leido del binario (el C de Ghidra de esta funcion mezcla dos
    * lecturas de vertice, ver docs/world-format-reference.md): x y u salen
    * de los vertices 1 y 2 (0x00420768-0x00420794 guarda x2-x1 y u2-u1 en
    * [ebp-0x8c]/[ebp-0x88] antes de leer el vertice 4; 0x00420b0c-0x00420b1a
    * divide x2-x1 entre hRes*(u2-u1)), z y v de los vertices 1 y 4
    * (0x00420b00-0x00420b0b: (z4-z1)/(vRes*(v4-v1))). La
    * celda inicial se redondea hacia abajo y la final hacia arriba: frndint
    * con la palabra de control de 0x00480a7c (0x077f, RC = hacia -inf) para
    * uMin y vMin y la de 0x00480a78 (0x0b7f, RC = hacia +inf) para uMax y
    * vMax. Bits de flags: 0x100000 volteo en V, 0x80000 en U
    * (Surface.setVFlip/setUFlip), que alternan de bloque en bloque.
    */
   public static List<float[]> rectCells(float u, float v, float uOff, float vOff, int flags, int hRes, int vRes) {
      float uo = uOff;
      if (uo != 0.0F) {
         uo *= u;
         uo = (float) (uo - 2.0 * Math.floor(uo / 2.0F));
      }
      float vo = vOff;
      if (vo != 0.0F) {
         vo *= v;
         vo = (float) (vo - 2.0 * Math.floor(vo / 2.0F));
      }
      float x1 = 0f, z1 = 0f, u1 = uo, v1 = v + vo;
      float x2 = 1f, u2 = u + uo;
      float z4 = 1f, v4 = vo;
      float du = u2 - u1;
      float dv = v4 - v1;
      float uEnd = u1 + du;
      float vEnd = v1 + dv;
      float uMin = uEnd < u1 ? uEnd : u1;
      float vMin = vEnd < v1 ? vEnd : v1;
      float uMax = u1 < uEnd ? uEnd : u1;
      float vMax = v1 < vEnd ? vEnd : v1;
      int col0 = (int) Math.floor(uMin) * hRes;
      int row0 = (int) Math.floor(vMin) * vRes;
      int colEnd = (int) Math.ceil(uMax) * hRes;
      int rowEnd = (int) Math.ceil(vMax) * vRes;
      List<float[]> cells = new ArrayList<>();
      if ((colEnd - col0) * (rowEnd - row0) == 0) {
         return cells;
      }
      float vLo = vRes * vMin;
      float vHi = vRes * vMax;
      float uLo = hRes * uMin;
      float uHi = hRes * uMax;
      float dz = (z4 - z1) / ((float) vRes * dv);
      float dx = (x2 - x1) / ((float) hRes * du);
      boolean vFlipOn = (flags & 0x100000) != 0;
      boolean uFlipOn = (flags & 0x80000) != 0;
      boolean vFlip = vFlipOn && ((row0 / vRes) & 1) != 0;
      boolean uFlipStart = uFlipOn && ((col0 / hRes) & 1) != 0;
      int mats = hRes * vRes;
      int n = 0;
      for (int row = row0; row < rowEnd; row += vRes) {
         boolean uFlip = uFlipStart;
         for (int col = col0; col < colEnd; col += hRes) {
            for (int sv = vFlip ? 0 : vRes - 1; sv > -1 && sv < vRes; sv += vFlip ? 1 : -1) {
               int iv = row + sv;
               float a = (float) (iv + 1) <= vHi ? (float) (iv + 1) : vHi;
               float b = !((float) iv < vLo) ? (float) iv : vLo;
               if (a < b) {
                  a = vHi;
                  b = vHi;
               }
               float za = (a - vRes * v1) * dz + z1;
               float zb = (b - vRes * v1) * dz + z1;
               a -= iv;
               b -= iv;
               if (vFlip) {
                  a = 1.0F - a;
                  b = 1.0F - b;
               }
               for (int su = uFlip ? hRes - 1 : 0; su > -1 && su < hRes; su += uFlip ? -1 : 1) {
                  int iu = col + su;
                  float c = !((float) iu < uLo) ? (float) iu : uLo;
                  float d = (float) (iu + 1) <= uHi ? (float) (iu + 1) : uHi;
                  if (d < c) {
                     c = uHi;
                     d = uHi;
                  }
                  float xc = (c - hRes * u1) * dx + x1;
                  float xd = (d - hRes * u1) * dx + x1;
                  c -= iu;
                  d -= iu;
                  if (uFlip) {
                     c = 1.0F - c;
                     d = 1.0F - d;
                  }
                  cells.add(new float[]{xc, xd, za, zb, c, d, a, b, n % mats});
                  n++;
               }
            }
            uFlip ^= uFlipOn;
         }
         vFlip ^= vFlipOn;
      }
      return cells;
   }
}

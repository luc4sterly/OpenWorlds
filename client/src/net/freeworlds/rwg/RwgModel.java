package net.freeworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * Un .rwg leído como lo leen gamma.dll y RWL21.DLL: la cabecera de gamma
 * con la lista de texturas que pide antes de leer (FUN_00419af0 /
 * FUN_0041c970), y el CLUM de RW con sus tablas RALT (rasters), TELT
 * (texturas) y MALT (materiales) y el ATOM raíz.
 */
public final class RwgModel {
   /**
    * Primer nombre de la lista de la cabecera, o "" si está vacía. Antes se
    * leía como "nombre del objeto"; es el primer nombre de textura (en
    * IDLE.RWG "idle", en e3.rwg "earthkin", igual que su STNG de TELT).
    */
   public final String name;
   /** Nombres de la cabecera tal cual, hasta el nombre vacío que la cierra. */
   public final List<String> headerTextures;
   public final List<RwgRaster> rasters;
   public final List<RwgTexture> textures;
   public final List<RwgMaterial> materials;
   public final RwgAtom atom;
   public final List<String> warnings = new ArrayList<>();

   public RwgModel(List<String> headerTextures, List<RwgRaster> rasters, List<RwgTexture> textures,
                   List<RwgMaterial> materials, RwgAtom atom) {
      this.headerTextures = headerTextures;
      this.name = headerTextures.isEmpty() ? "" : headerTextures.get(0);
      this.rasters = rasters;
      this.textures = textures;
      this.materials = materials;
      this.atom = atom;
   }

   /** Lo que gamma.dll pide a Java antes de leer el CLUM: ver {@link RwgParser.Header#textureRequests}. */
   public List<String> textureRequests() {
      return new RwgParser.Header(this.headerTextures, true).textureRequests();
   }

   /** Material de un polígono (MALT base 1; 0 o fuera de rango = ninguno, como 0x1003a7bc). */
   public RwgMaterial materialOf(RwgPolygon p) {
      int i = p.materialIndex;
      return i >= 1 && i <= this.materials.size() ? this.materials.get(i - 1) : null;
   }
}

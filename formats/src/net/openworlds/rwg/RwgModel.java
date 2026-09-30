package net.openworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * A .rwg read the way gamma.dll and RWL21.DLL read it: gamma's header
 * with the texture list it requests before reading (FUN_00419af0 /
 * FUN_0041c970), and RW's CLUM with its RALT (rasters), TELT
 * (textures) and MALT (materials) tables and the root ATOM.
 */
public final class RwgModel {
   /**
    * First name of the header list, or "" if it is empty. It used to be
    * read as the "object name"; it is the first texture name (in
    * IDLE.RWG "idle", in e3.rwg "earthkin", the same as its TELT's STNG).
    */
   public final String name;
   /** The header's names as they are, up to the empty name that closes it. */
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

   /** What gamma.dll requests from Java before reading the CLUM: see {@link RwgParser.Header#textureRequests}. */
   public List<String> textureRequests() {
      return new RwgParser.Header(this.headerTextures, true).textureRequests();
   }

   /** Material of a polygon (1-based MALT; 0 or out of range = none, like 0x1003a7bc). */
   public RwgMaterial materialOf(RwgPolygon p) {
      int i = p.materialIndex;
      return i >= 1 && i <= this.materials.size() ? this.materials.get(i - 1) : null;
   }
}

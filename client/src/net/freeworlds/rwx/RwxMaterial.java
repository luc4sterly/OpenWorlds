package net.freeworlds.rwx;

import java.util.EnumSet;
import java.util.Set;

/** Snapshot of the material state in effect when a triangle was emitted.
 *
 * Material semantics follow the reference renderer (three-rwx-loader,
 * the only working RWX renderer available to compare against) wherever
 * the real RenderWare 2 behavior is not directly evidenced — see
 * docs/rwx-format-reference.md and the "texturas bien" session notes in
 * worlds-chat-project.md:
 * - surface defaults to [0.69, 0, 0] ("Ambience (recommended AW 2.2)",
 *   Diffusion, Specularity) — NOT [0, 1, 0].
 * - TextureModes default to Lit+Foreshorten+Filter all enabled.
 * - The parsed surface triple only applies when Lit is enabled; without
 *   Lit the default triple above is used instead.
 * - Textured materials use a WHITE base color (the file's Color is
 *   ignored for them — tint is never enabled in practice); untextured
 *   ones use Color. Both are scaled by brightnessRatio = max(surface).
 */
public final class RwxMaterial {
   public enum TextureMode { LIT, FORESHORTEN, FILTER }

   /** AW 2.2 recommended ambience, per the reference. */
   public static final float DEFAULT_AMBIENCE = 0.69f;

   public float colorR = 0.0f;
   public float colorG = 0.0f;
   public float colorB = 0.0f;
   public float opacity = 1.0f;
   public float ambient = DEFAULT_AMBIENCE;
   public float diffuse = 0.0f;
   public float specular = 0.0f;
   public String textureName;
   public String maskName;
   /** MaterialModes Double/Null - real corpus evidence: assets/GROUNDZERO/YARD_TABLE.RWX uses "MaterialModes Double". Default false (single-sided/backface-culled) per the RWX spec. */
   public boolean doubleSided = false;
   public Set<TextureMode> textureModes = EnumSet.of(TextureMode.LIT, TextureMode.FORESHORTEN, TextureMode.FILTER);
   /** Whether the script set the ambient (Ambient/Surface). RenderWare 2.1
    * starts every material at surface (0, 0, 0): RwCreateMaterial
    * (RWL21 0x1001b340) calls RwSetMaterialSurface(mat, 0, 0, 0); the
    * 0.69 default above is three-rwx-loader's, so the RW lighting
    * (render/DriverLight) reads {@link #rwAmbient()}. */
   public boolean ambientSet = false;
   /** LightSampling: 1 Facet (RwCreateMaterial's default), 2 Vertex. */
   public int lightSampling = 1;

   public RwxMaterial copy() {
      RwxMaterial c = new RwxMaterial();
      c.colorR = colorR;
      c.colorG = colorG;
      c.colorB = colorB;
      c.opacity = opacity;
      c.ambient = ambient;
      c.diffuse = diffuse;
      c.specular = specular;
      c.textureName = textureName;
      c.maskName = maskName;
      c.doubleSided = doubleSided;
      c.textureModes = textureModes.isEmpty() ? EnumSet.noneOf(TextureMode.class) : EnumSet.copyOf(textureModes);
      c.ambientSet = ambientSet;
      c.lightSampling = lightSampling;
      return c;
   }

   /** The ambient RenderWare 2.1 uses: the script's, or 0 (see {@link #ambientSet}). */
   public float rwAmbient() {
      return ambientSet ? ambient : 0f;
   }

   /** TextureModes Lit: a textured polygon goes through the driver's light ramp; without it the texel is drawn as is. */
   public boolean rwLit() {
      return textureModes.contains(TextureMode.LIT);
   }

   /** Effective surface triple: parsed values only under Lit, else the AW default. */
   public float effectiveAmbient() {
      return textureModes.contains(TextureMode.LIT) ? ambient : DEFAULT_AMBIENCE;
   }

   public float effectiveDiffuse() {
      return textureModes.contains(TextureMode.LIT) ? diffuse : 0.0f;
   }

   /** brightnessRatio = max(surface), applied to the base color in both cases. */
   public float brightnessRatio() {
      return Math.max(effectiveAmbient(), Math.max(effectiveDiffuse(), specular));
   }

   /** Base color: white for textured materials (file Color ignored — tint
    * never enabled in practice), file Color otherwise. */
   public float[] baseColor() {
      if (textureName != null) {
         return new float[]{1f, 1f, 1f};
      }
      return new float[]{colorR, colorG, colorB};
   }
}

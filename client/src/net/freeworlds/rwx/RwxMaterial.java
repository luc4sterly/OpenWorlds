package net.freeworlds.rwx;

/** Snapshot of the material state in effect when a triangle was emitted. */
public final class RwxMaterial {
   public float colorR = 0.7f;
   public float colorG = 0.7f;
   public float colorB = 0.7f;
   public float opacity = 1.0f;
   public float ambient = 0.0f;
   public float diffuse = 1.0f;
   public float specular = 0.0f;
   public String textureName;
   public String maskName;

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
      return c;
   }
}

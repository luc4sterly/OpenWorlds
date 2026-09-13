package net.freeworlds.render;

import net.freeworlds.rwx.RwxMaterial;

import static org.lwjgl.opengl.GL11.*;

/**
 * Fixed-function (glLight/glMaterial, NOT a shader) two-light model matching
 * what the real decompiled client actually does - see
 * NET.worlds.scape.RoomEnvironment.addLight() and the Room.lightPosition/
 * lightColor default field initializers in
 * editor/worldsplayer_source_editor-main/source/NET/worlds/scape/Room.java:
 *
 *   private Point3 lightPosition = new Point3(-1.0F, 1.0F, -1.0F);
 *   private Color lightColor = new Color(255, 255, 255);
 *   ...
 *   this.lightid = Room.addLight(sceneID, pos.x, pos.y, pos.z, r, g, b);
 *   this.lightid2 = Room.addLight(sceneID, -pos.x, -pos.y, -pos.z, r*0.5, g*0.5, b*0.5);
 *
 * i.e. exactly two lights per room: a "key" light at a fixed default
 * direction, white, and a "fill" light at the opposite direction with half
 * the color intensity - not a single light, not more than two, not colored
 * by default. No shadows, no per-pixel/PBR anything - this matches
 * RenderWare 2's real fixed-function per-vertex lighting model, which is
 * exactly what a GL_LIGHTING/glLight/glMaterial pipeline already is.
 *
 * ⚠️ VERIFICAR: RWX's material "ambient" scalar (RwxMaterial.ambient) has no
 * corresponding "ambient light color" anywhere in the decompiled client (no
 * separate ambient light source exists, only the two colored lights above) -
 * lacking real evidence for how RenderWare 2 combined ambient with these two
 * lights, each GL light gets an AMBIENT component of 0.15× its DIFFUSE
 * (key 0.15, fill 0.075). History: this used to equal DIFFUSE (1.0/0.5),
 * which was harmless while material ambient was ~zero — but once textured
 * materials gained their real 0.69 white-based ambient response (see the
 * "texturas bien" session), 1.5× total ambient clipped every textured
 * surface to unshaded white (measured 19.8% pure-white pixels in
 * Auditorium); 0.25 still left clipped streaks on ideally-lit faces
 * (7.9%). 0.15 keeps shadowed faces visible while holding clipping to a
 * trace — a documented heuristic, not a verified RW2 value. Likewise the specular shininess exponent
 * (GL_SHININESS) has no RWX-exposed equivalent - a conservative fixed
 * value is used and flagged below, not presented as verified.
 */
final class GlLighting {
   private GlLighting() {
   }

   // ⚠️ VERIFICAR - no RWX-exposed value for this; a low, non-glossy
   // exponent typical of era fixed-function specular highlights.
   private static final float SHININESS = 8f;

   static void init() {
      glEnable(GL_LIGHTING);
      glEnable(GL_LIGHT0);
      glEnable(GL_LIGHT1);
      glEnable(GL_NORMALIZE); // vertices may be transformed/rotated; keep lighting correct without renormalizing normals by hand
      glShadeModel(GL_FLAT); // no smoothing-group/vertex-normal data parsed yet (see docs) - flat per-face shading is honest about what we actually know, not smoothed-over guesswork
      glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE); // Rect surfaces render double-sided (no MaterialModes on them, winding unverified) - two-sided lighting flips the normal for backfaces automatically; single-sided culled shapes are unaffected
      glLightModelfv(GL_LIGHT_MODEL_AMBIENT, new float[]{0f, 0f, 0f, 1f}); // no evidence of extra global ambient beyond the two lights themselves
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // real RWX "Opacity" material attribute, applied via material alpha - simple alpha blending, not a modern OIT/premultiplied scheme

      setLight(GL_LIGHT0, -1f, 1f, -1f, 1.0f, 1.0f, 1.0f);
      setLight(GL_LIGHT1, 1f, -1f, 1f, 0.5f, 0.5f, 0.5f);
   }

    private static void setLight(int light, float dx, float dy, float dz, float r, float g, float b) {
       // w=0 -> directional light (matches treating Room's lightPosition as a
       // fixed direction rather than a point that would need real-world
       // room-scale attenuation data we don't have).
       glLightfv(light, GL_POSITION, new float[]{dx, dy, dz, 0f});
       glLightfv(light, GL_DIFFUSE, new float[]{r, g, b, 1f});
       glLightfv(light, GL_SPECULAR, new float[]{r, g, b, 1f});
       glLightfv(light, GL_AMBIENT, new float[]{r * 0.15f, g * 0.15f, b * 0.15f, 1f}); // see class javadoc VERIFICAR note
    }

   /** Real per-material RWX pipeline state: opacity (alpha blending) + MaterialModes Double/Null (backface culling) - see RwxMaterial javadoc for the real-corpus evidence (assets/GROUNDZERO/YARD_TABLE.RWX). */
   static void applyCulling(boolean doubleSided) {
      if (doubleSided) {
         glDisable(GL_CULL_FACE);
      } else {
         glEnable(GL_CULL_FACE);
         glCullFace(GL_BACK);
      }
   }

    static void applyMaterial(RwxMaterial mat) {
       // Reference material model (see RwxMaterial javadoc): the base is
       // white for textured materials (file Color ignored) and the file
       // Color otherwise, scaled in both cases by brightnessRatio =
       // max(effective surface). The same scaled base feeds BOTH the
       // ambient and the diffuse response — mirroring how the reference
       // multiplies one three.js color into every light term — instead of
       // the old color×scalar diffuse with a ~zero ambient that stacked
       // texture×color×N·L into near-black on every textured surface.
       float[] base = mat.baseColor();
       float ratio = mat.brightnessRatio();
       float[] ambDiff = {base[0] * ratio, base[1] * ratio, base[2] * ratio, mat.opacity};
       float[] specular = {mat.specular, mat.specular, mat.specular, mat.opacity};
       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambDiff);
       glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ambDiff);
       glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
       glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, SHININESS);
    }

   /** Flat per-triangle face normal from real vertex positions (no explicit vertex normals are parsed yet - see docs). */
   static float[] faceNormal(float ax, float ay, float az, float bx, float by, float bz, float cx, float cy, float cz) {
      float ux = bx - ax, uy = by - ay, uz = bz - az;
      float vx = cx - ax, vy = cy - ay, vz = cz - az;
      float nx = uy * vz - uz * vy;
      float ny = uz * vx - ux * vz;
      float nz = ux * vy - uy * vx;
      float len = (float) Math.sqrt(nx * nx + ny * ny + nz * nz);
      if (len < 1e-8f) {
         return new float[]{0f, 0f, 1f};
      }
      return new float[]{nx / len, ny / len, nz / len};
   }
}

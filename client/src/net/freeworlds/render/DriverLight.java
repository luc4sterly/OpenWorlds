package net.freeworlds.render;

/**
 * The original's lighting, computed on the CPU for the fixed-function GL
 * renderer (WorldViewer draws with GL_LIGHTING off and these colours).
 *
 * <p>Everything here is the portable bridge's translation of the 2004
 * binaries, which draws GroundZero like the original
 * (editor/worldsplayer_source_editor-main/bridge/NET/worlds/core/NativeCamera.java,
 * {@code light()} and {@code buildRamp()}; NativeScene for the materials):
 *
 * <ul>
 * <li>Two directional lights per room (Room.addRwChildren and
 *     RoomEnvironment.addLight): vector {@code lightPosition}, colour
 *     {@code lightColor / 256}; the second one at {@code -lightPosition}
 *     with half the colour. Room's defaults are (-1, 1, -1) and white.</li>
 * <li>Per object, each light goes to the object's own space:
 *     {@code L = normalize(inv(LTM) . -vector)}, dotted with the unit
 *     normal of the polygon in that space. With a non-uniform scale (a
 *     Rect is a unit quad scaled to its size) this is not the world-space
 *     cosine, and the original looks the way it does because of it.</li>
 * <li>Intensity per channel on the driver's 0..31 scale (RWDL6D21
 *     1000d230 / 1000d5c0 / 1000d950):
 *     {@code I = 31 amb + sum 31 lc (dif d + (d > 0.7 ? spec S(d) : 0))},
 *     {@code d = N.L > 0}, {@code S(d) = (floor(256 d) / 256)^16},
 *     truncated to 1/65536 and saturated at 31.</li>
 * <li>The colour ramp of the 16-bit driver (FUN_10008d00), indexed by the
 *     integer part of I: up to 0.75 of the scale a component goes from
 *     black to itself, above it from itself to WHITE. A surface at
 *     ambient 0.75 without diffuse is drawn in its own colour, and one
 *     facing a light comes out lighter than its colour. GL's lighting can
 *     never go above the material colour, which is why the old
 *     glLight/glMaterial path looked much darker than the original.</li>
 * <li>A textured polygon uses its texels as the components, per polygon
 *     (the driver never lights a textured polygon per vertex), and only
 *     when its material is lit (TextureModes Lit / not "self-lit");
 *     otherwise the texel is drawn as it is.</li>
 * </ul>
 *
 * <p>In GL a lit texture is {@code texel * P + S}: GL_MODULATE with the
 * primary colour P and GL_COLOR_SUM with the secondary colour S (see
 * {@link #rampFactors}). ⚠️ That is the ramp without its 5-bit steps and
 * without the driver's clamp of every component to [1/31, 30/31], which
 * fixed-function texturing cannot do per texel; untextured colours use the
 * exact table ({@link #rampColor}).
 */
final class DriverLight {
   private DriverLight() {
   }

   /** Room.java field initialisers: {@code lightPosition = (-1, 1, -1)}, {@code lightColor = white}. */
   static final float[] DEFAULT_POSITION = {-1f, 1f, -1f};
   static final int DEFAULT_COLOR = 0xFFFFFF;

   /** gamma.dll FUN_00417950: ambient in (0.7421875, 0.7578125) with no diffuse or specular = self-lit material. */
   static boolean selfLit(float amb, float dif, float spec) {
      return 0.7421875f < amb && amb < 0.7578125f && dif == 0f && spec == 0f;
   }

   // light vectors (as the room stores them) and colours of the room being drawn
   private static final float[][] VEC = new float[2][3];
   private static final float[][] COL = new float[2][3];
   // the same lights in the current object's space: direction towards the light, unit
   private static final float[][] LOCAL = new float[2][3];

   private static final float[] IDENTITY = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};

   static {
      room(null, DEFAULT_COLOR);
   }

   /** Lights of the room about to be drawn (null position = Room's default). */
   static void room(float[] position, int rgb) {
      float[] p = position != null ? position : DEFAULT_POSITION;
      float r = clamp01(((rgb >> 16) & 0xFF) / 256f);
      float g = clamp01(((rgb >> 8) & 0xFF) / 256f);
      float b = clamp01((rgb & 0xFF) / 256f);
      for (int i = 0; i < 3; i++) {
         VEC[0][i] = p[i];
         VEC[1][i] = -p[i];
      }
      COL[0][0] = r;
      COL[0][1] = g;
      COL[0][2] = b;
      COL[1][0] = r * 0.5f;
      COL[1][1] = g * 0.5f;
      COL[1][2] = b * 0.5f;
      object(IDENTITY);
   }

   /**
    * The object being drawn: its object-to-world matrix (GL column-major,
    * the same layout as RW's LTM). The lights go to its space with the
    * inverse of the linear part, as the bridge does per clump.
    */
   static void object(float[] m) {
      float a = m[0], b = m[4], c = m[8];
      float d = m[1], e = m[5], f = m[9];
      float g = m[2], h = m[6], k = m[10];
      // inverse of the 3x3 [a b c; d e f; g h k] (rows), by cofactors
      float A = e * k - f * h, B = -(d * k - f * g), C = d * h - e * g;
      float det = a * A + b * B + c * C;
      float[] inv;
      if (det == 0f) {
         inv = new float[]{1, 0, 0, 0, 1, 0, 0, 0, 1};
      } else {
         float s = 1f / det;
         inv = new float[]{
            A * s, -(b * k - c * h) * s, (b * f - c * e) * s,
            B * s, (a * k - c * g) * s, -(a * f - c * d) * s,
            C * s, -(a * h - b * g) * s, (a * e - b * d) * s};
      }
      for (int l = 0; l < 2; l++) {
         float x = -VEC[l][0], y = -VEC[l][1], z = -VEC[l][2];
         float lx = inv[0] * x + inv[1] * y + inv[2] * z;
         float ly = inv[3] * x + inv[4] * y + inv[5] * z;
         float lz = inv[6] * x + inv[7] * y + inv[8] * z;
         float len = (float) Math.sqrt(lx * lx + ly * ly + lz * lz);
         if (len > 0f) {
            lx /= len;
            ly /= len;
            lz /= len;
         }
         LOCAL[l][0] = lx;
         LOCAL[l][1] = ly;
         LOCAL[l][2] = lz;
      }
   }

   /**
    * Everything the colours of an object depend on besides its materials
    * and normals (its local lights and their colours), for caching its
    * display list. Rounded so that the same orientation gives the same key.
    */
   static long objectKey() {
      long h = 1125899906842597L;
      for (int l = 0; l < 2; l++) {
         for (int i = 0; i < 3; i++) {
            h = 31 * h + Math.round(LOCAL[l][i] * 65536f);
            h = 31 * h + Math.round(COL[l][i] * 65536f);
         }
      }
      return h;
   }

   /** Specular table S(d) of the driver: (k/256)^16, entries 256 and 257 = (255/256)^16. */
   private static final float[] SPEC = new float[258];

   static {
      for (int k = 0; k < 256; k++) {
         SPEC[k] = (float) Math.pow(k / 256.0, 16.0);
      }
      SPEC[256] = SPEC[257] = (float) Math.pow(255.0 / 256.0, 16.0);
   }

   /** Intensity per channel (0..31) of a surface with unit normal (nx, ny, nz) in the current object's space. */
   static void intensity(float amb, float dif, float spec, float nx, float ny, float nz, float[] out) {
      for (int ch = 0; ch < 3; ch++) {
         out[ch] = 31.0f * amb;
      }
      for (int l = 0; l < 2; l++) {
         float[] v = LOCAL[l];
         float d = nx * v[0] + ny * v[1] + nz * v[2];
         if (d > 0.0f) {
            float s = d > 0.7f ? spec * SPEC[Math.min(257, (int) (d * 256.0f))] : 0.0f;
            for (int ch = 0; ch < 3; ch++) {
               out[ch] += 31.0f * COL[l][ch] * (dif * d + s);
            }
         }
      }
      for (int ch = 0; ch < 3; ch++) {
         float i = out[ch];
         out[ch] = i >= 31.0f ? 31.0f : (float) ((int) (i * 65536.0f)) / 65536.0f;
      }
   }

   /** Ramp row of an intensity: its integer part, 0..31. */
   static int row(float intensity) {
      int i = (int) intensity;
      return i < 0 ? 0 : (i > 31 ? 31 : i);
   }

   /**
    * The colour ramp of RWDL6D21 (FUN_10008d00), as the bridge builds it:
    * [row][5-bit component] -> 5-bit output in [1, 30]. The intensity is
    * normalised by 1/31 (_DAT_10078098), the curve flag DAT_10079234 is 0
    * (linear) and the threshold DAT_10079238 is 0.75.
    */
   static final byte[] RAMP = buildRamp();

   private static byte[] buildRamp() {
      byte[] t = new byte[32 * 32];
      for (int i = 0; i < 32; i++) {
         float x = i * (1.0f / 31.0f);
         for (int c = 0; c < 32; c++) {
            int comp16 = c << 11;
            int v;
            if (x >= 0.75f) {
               int s = (int) ((x - 0.75f) / 0.25f * 65536.0f);
               v = (0x10080 - (0x10000 - s) & 0xFFFFFF00) + ((comp16 + 0x80) >> 8) * (0x10080 - s >> 8);
            } else {
               int s = (int) (x / 0.75f * 65536.0f);
               v = ((comp16 + 0x80) >> 8) * (s + 0x80 >> 8);
            }
            if (v > 0xFFFF) {
               v = 0xFFFF;
            }
            int out = v >> 11;
            if (out > 0x1E) {
               out = 0x1E;
            }
            t[i * 32 + c] = (byte) (out == 0 ? 1 : out);
         }
      }
      return t;
   }

   /**
    * Lit colour of an untextured surface, exactly as the driver writes it:
    * the material colour goes to the device's 565 (floor(c * 32) per 5-bit
    * channel, 6 bits for green), each channel through the ramp row of its
    * intensity, and the 565 result back to 0..1 (green keeps its 6 bits).
    */
   static void rampColor(float r, float g, float b, float[] intensity, float[] out) {
      int r5 = Math.min(31, (int) (r * 65536.0f) >> 11);
      int g5 = Math.min(63, (int) (g * 65536.0f) >> 10) >> 1;
      int b5 = Math.min(31, (int) (b * 65536.0f) >> 11);
      out[0] = RAMP[row(intensity[0]) * 32 + r5] / 31f;
      out[1] = (RAMP[row(intensity[1]) * 32 + g5] << 1) / 63f;
      out[2] = RAMP[row(intensity[2]) * 32 + b5] / 31f;
   }

   /**
    * The ramp of an intensity as {@code out = c * p + s} for a component c
    * in 0..1 (textures in GL): below 0.75 of the scale p = x / 0.75 and
    * s = 0; from 0.75 up p = 1 - t and s = t * 32/31 with t = (x - 0.75) / 0.25
    * (the ramp's 16.16 blend towards 0xffff, read in 5-bit units), where
    * x = row / 31.
    */
   static void rampFactors(float[] intensity, float[] p, float[] s) {
      for (int ch = 0; ch < 3; ch++) {
         float x = row(intensity[ch]) / 31f;
         if (x >= 0.75f) {
            float t = (x - 0.75f) / 0.25f;
            p[ch] = 1f - t;
            s[ch] = t * (32f / 31f);
         } else {
            p[ch] = x / 0.75f;
            s[ch] = 0f;
         }
      }
   }

   /**
    * Unit polygon normal (RWL21 0x10001100): the sum of the cross products
    * of the fan from the first vertex, normalised; zero for a degenerate
    * polygon (then only the ambient lights it).
    */
   static float[] polygonNormal(float[][] v) {
      float nx = 0, ny = 0, nz = 0;
      for (int i = 1; i + 1 < v.length; i++) {
         float ax = v[i][0] - v[0][0], ay = v[i][1] - v[0][1], az = v[i][2] - v[0][2];
         float bx = v[i + 1][0] - v[0][0], by = v[i + 1][1] - v[0][1], bz = v[i + 1][2] - v[0][2];
         nx += ay * bz - az * by;
         ny += az * bx - ax * bz;
         nz += ax * by - ay * bx;
      }
      float len = (float) Math.sqrt(nx * nx + ny * ny + nz * nz);
      return len == 0f ? new float[3] : new float[]{nx / len, ny / len, nz / len};
   }

   private static float clamp01(float f) {
      return f < 0f ? 0f : (f > 1f ? 1f : f);
   }
}

package net.openworlds.rwg;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

/**
 * CLI smoke-test/inspector for RwgParser: parses a .rwg file and prints a
 * human-readable summary of everything decoded (and everything left raw)
 * so the parser's output can be sanity-checked against the hex-dump
 * analysis in docs/rwg-bod-format-reference.md. There is no independent
 * reference implementation to diff against for this format (unlike RWX -
 * see the docs for why), so self-consistency + this printed summary is
 * the verification method available.
 *
 * Usage: java -cp out net.openworlds.rwg.RwgExtractMain <file.rwg>
 */
public final class RwgExtractMain {
   public static void main(String[] args) throws IOException {
      if (args.length < 1) {
         System.err.println("Usage: RwgExtractMain <file.rwg>");
         System.exit(2);
      }

      byte[] data = Files.readAllBytes(new File(args[0]).toPath());
      RwgModel model;
      try {
         model = RwgParser.parse(data);
      } catch (RuntimeException e) {
         System.out.println("PARSE ERROR: " + e.getClass().getSimpleName() + ": " + e.getMessage());
         System.exit(1);
         return;
      }

      System.out.println("header textures: " + model.headerTextures + " -> requests " + model.textureRequests());
      for (String w : model.warnings) {
         System.out.println("warning: " + w);
      }
      System.out.println("RALT: " + model.rasters.size() + " rasters");
      for (int i = 0; i < model.textures.size(); i++) {
         RwgTexture t = model.textures.get(i);
         System.out.println("TELT[" + (i + 1) + "] raster=" + t.rasterIndex + " mipmap=" + t.mipmapRasterIndex
            + " name=" + (t.name == null ? "null" : "\"" + t.name + "\""));
      }
      for (int i = 0; i < model.materials.size(); i++) {
         RwgMaterial m = model.materials.get(i);
         System.out.printf("MALT[%d] texture=%d geom=%d light=%d modes=0x%02x/0x%02x color=(%.4f, %.4f, %.4f) opacity=%.4f"
               + " surface=(%.4f, %.4f, %.4f)%n", i + 1, m.textureIndex, m.geometrySampling(), m.lightSampling(),
            m.textureModes(), m.materialModes(), m.r, m.g, m.b, m.opacity, m.ambient, m.diffuse, m.specular);
      }

      if (model.atom == null) {
         System.out.println("no ATOM");
         return;
      }
      RwgAtom a = model.atom;
      System.out.print("ATOM header (13 ints):");
      for (int v : a.headerRaw) {
         System.out.print(" " + v);
      }
      System.out.println();
      System.out.println("tag=" + a.tag() + " hints=" + a.hints() + " axes=" + a.axisAlignment() + " state=" + a.state()
         + " children=" + a.childCount() + " light sampling=" + a.lightSampleRate());
      System.out.println("matrix1 identity? " + isIdentity(a.matrix1));
      System.out.println("matrix2 identity? " + isIdentity(a.matrix2));

      System.out.println("bbox corners (VLST records 0-7): " + a.boundingBoxCorners.size());
      for (int i = 0; i < a.boundingBoxCorners.size(); i++) {
         RwgVertex v = a.boundingBoxCorners.get(i);
         System.out.printf("  [bbox %d] pos=(%.4f, %.4f, %.4f)%n", i, v.x, v.y, v.z);
      }
      System.out.println("vertices: " + a.vertices.size());
      for (int i = 0; i < a.vertices.size(); i++) {
         RwgVertex v = a.vertices.get(i);
         System.out.printf(
            "  [%2d] pos=(%.4f, %.4f, %.4f)  normal=(%.4f, %.4f, %.4f)  uv?=(%.4f, %.4f)  flag4=(%.4f, %.4f, %.4f)%n",
            i, v.x, v.y, v.z, v.normalX, v.normalY, v.normalZ, v.u, v.v, v.unknown8, v.unknown9, v.unknown10);
      }

      System.out.println("polygons: " + a.polygons.size());
      for (int i = 0; i < a.polygons.size(); i++) {
         RwgPolygon p = a.polygons.get(i);
         StringBuilder sb = new StringBuilder("  [" + i + "] indices=[");
         for (int idx : p.vertexIndices) {
            sb.append(idx).append(' ');
         }
         sb.append("] material=").append(p.materialIndex).append(" tag=").append(p.tag);
         float[] n = p.normal();
         if (n != null) {
            sb.append(String.format(" normal=(%.4f, %.4f, %.4f)", n[0], n[1], n[2]));
         }
         System.out.println(sb);
      }
   }

   private static boolean isIdentity(float[] m) {
      float[] id = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
      for (int i = 0; i < 16; i++) {
         if (Math.abs(m[i] - id[i]) > 1e-6f) {
            return false;
         }
      }
      return true;
   }
}

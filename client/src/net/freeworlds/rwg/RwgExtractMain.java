package net.freeworlds.rwg;

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
 * Usage: java -cp out net.freeworlds.rwg.RwgExtractMain <file.rwg>
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

      System.out.println("name: \"" + model.name + "\"");
      for (String w : model.warnings) {
         System.out.println("warning: " + w);
      }
      System.out.println("RALT raw bytes: " + (model.raltRaw == null ? 0 : model.raltRaw.length));
      System.out.println("TELT raw bytes: " + (model.teltRaw == null ? 0 : model.teltRaw.length));
      System.out.println("MALT raw bytes: " + (model.maltRaw == null ? 0 : model.maltRaw.length));

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
      System.out.println("matrix1 identity? " + isIdentity(a.matrix1));
      System.out.println("matrix2 identity? " + isIdentity(a.matrix2));

      System.out.println("vertices: " + a.vertices.size());
      for (int i = 0; i < a.vertices.size(); i++) {
         RwgVertex v = a.vertices.get(i);
         System.out.printf(
            "  [%2d] pos=(%.4f, %.4f, %.4f)  normal=(%.4f, %.4f, %.4f)  uv?=(%.4f, %.4f)  raw8-10=(%.4f, %.4f, %.4f)%n",
            i, v.x, v.y, v.z, v.normalX, v.normalY, v.normalZ, v.u, v.v, v.unknown8, v.unknown9, v.unknown10);
      }

      System.out.println("polygons: " + a.polygons.size());
      for (int i = 0; i < a.polygons.size(); i++) {
         RwgPolygon p = a.polygons.get(i);
         StringBuilder sb = new StringBuilder("  [" + i + "] indices=[");
         for (int idx : p.vertexIndices) {
            sb.append(idx).append(' ');
         }
         sb.append("] trailingRaw=[");
         for (int t : p.trailingRaw) {
            sb.append(t).append(' ');
         }
         sb.append(']');
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

import net.freeworlds.cmp.CmpTexture;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;

/**
 * Minimal CLI wrapper around net.freeworlds.cmp.CmpTexture.load, for the
 * corpus-wide coverage harness (docs/cmp-stage1-coverage.md /
 * cmp_stage1_coverage.py). Writes a top-down P6 PPM on success (so the
 * Python side can diff it against real ground truth with ImageMagick's
 * `compare`), or prints the real failure reason to stderr and exits 1 -
 * never fabricates output for a file it can't actually decode.
 *
 * Usage: java CmpDecodeCli <dir> <base> <out.ppm>
 *   <dir>/<base>.cmp must exist (same dir+base convention as CmpTexture.load).
 */
public final class CmpDecodeCli {
   public static void main(String[] args) {
      if (args.length < 3) {
         System.err.println("Usage: CmpDecodeCli <dir> <base> <out.ppm>");
         System.exit(2);
      }
      File dir = new File(args[0]);
      String base = args[1];
      File outPpm = new File(args[2]);
      try {
         CmpTexture tex = CmpTexture.load(dir, base);
         try (OutputStream out = new FileOutputStream(outPpm)) {
            String header = "P6\n" + tex.width + " " + tex.height + "\n255\n";
            out.write(header.getBytes("US-ASCII"));
            out.write(tex.rgb);
         }
         System.out.println("OK " + tex.width + "x" + tex.height);
      } catch (Throwable t) {
         System.err.println("FAIL " + t.getClass().getSimpleName() + ": " + t.getMessage());
         System.exit(1);
      }
   }
}

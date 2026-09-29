import net.openworlds.cmp.CmpTexture;

import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStream;

/**
 * CLI wrapper around net.openworlds.cmp.CmpTexture.loadRaw (the real Stage 1
 * decoder, CmpStage1 - no pre-captured streams, no hand-written palette.txt,
 * works against ANY real .cmp file) - for the corpus-wide coverage harness
 * (docs/cmp-stage1-coverage.md / cmp_stage1_coverage.py). Writes a top-down
 * P6 PPM on success, or prints the real failure reason to stderr and exits
 * 1 - never fabricates output for a file it can't actually decode.
 *
 * Usage: java CmpDecodeRawCli <path-to.cmp> <out.ppm>
 */
public final class CmpDecodeRawCli {
   public static void main(String[] args) {
      if (args.length < 2) {
         System.err.println("Usage: CmpDecodeRawCli <path-to.cmp> <out.ppm>");
         System.exit(2);
      }
      File cmpFile = new File(args[0]);
      File outPpm = new File(args[1]);
      try {
         CmpTexture tex = CmpTexture.loadRaw(cmpFile);
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

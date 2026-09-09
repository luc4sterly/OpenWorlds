package net.freeworlds.rwx;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;

/**
 * CLI counterpart to tools/rwx-harness/extract.mjs: parses a .rwx file with
 * our own Java parser and prints the same canonical JSON shape, so the two
 * can be diffed by tools/rwx-harness/compare.py.
 *
 * Usage: java -cp out net.freeworlds.rwx.RwxExtractMain <file.rwx>
 */
public final class RwxExtractMain {
   public static void main(String[] args) {
      if (args.length < 1) {
         System.err.println("Usage: RwxExtractMain <file.rwx>");
         System.exit(2);
      }

      try {
         File f = new File(args[0]);
         String text = new String(Files.readAllBytes(f.toPath()), "ISO-8859-1");
         RwxModel model = new RwxParser().parse(text);
         System.out.println(RwxJsonWriter.toJson(model));
      } catch (IOException e) {
         System.out.println("{\"error\":\"" + e.getMessage() + "\"}");
         System.exit(1);
      } catch (RuntimeException e) {
         System.out.println("{\"error\":\"" + e.getClass().getSimpleName() + ": " + e.getMessage() + "\"}");
         System.exit(1);
      }
   }
}

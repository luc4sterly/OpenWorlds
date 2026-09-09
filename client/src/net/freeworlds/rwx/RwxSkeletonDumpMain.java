package net.freeworlds.rwx;

import java.io.File;
import java.nio.file.Files;

/**
 * CLI verification tool: parses an RWX file's named-clump hierarchy and
 * prints it as an indented tree (name, vertex/triangle counts) so it can be
 * checked against real evidence (e.g. the manually reconstructed SPIN.RWX
 * joint list in worlds-chat-project.md).
 *
 * Usage: java -cp out net.freeworlds.rwx.RwxSkeletonDumpMain <file.rwx>
 */
public final class RwxSkeletonDumpMain {
   public static void main(String[] args) throws Exception {
      if (args.length < 1) {
         System.err.println("Usage: RwxSkeletonDumpMain <file.rwx>");
         System.exit(2);
      }

      String text = new String(Files.readAllBytes(new File(args[0]).toPath()), "ISO-8859-1");
      RwxSkeletonParser parser = new RwxSkeletonParser();
      RwxJoint root = parser.parse(text);

      for (String w : parser.warnings()) {
         System.out.println("WARN: " + w);
      }
      dump(root, 0);
   }

   private static void dump(RwxJoint joint, int depth) {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < depth; i++) {
         sb.append("  ");
      }
      sb.append(joint.name == null ? "(unnamed)" : joint.name);
      sb.append("  [v=").append(joint.vertices.size());
      sb.append(" t=").append(joint.triangles.size()).append("]");
      System.out.println(sb);
      for (RwxJoint child : joint.children) {
         dump(child, depth + 1);
      }
   }
}

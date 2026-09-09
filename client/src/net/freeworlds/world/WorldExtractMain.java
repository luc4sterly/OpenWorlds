package net.freeworlds.world;

import java.io.File;
import java.nio.file.Files;
import java.util.List;

/**
 * CLI smoke-test/inspector for WorldRestorer: parses a .world file and
 * prints a summary (room count, object counts by class, tree depth) so
 * the parser's output can be sanity-checked against the real file - see
 * docs/world-format-reference.md. There is no independent reference
 * parser for this format (it's the client's own bespoke object-graph
 * protocol), so verification here is: does the byte stream fully consume
 * without desyncing (an IOException means a class's field order is
 * wrong), and do the resulting counts/positions look real.
 *
 * Usage: java -cp ... net.freeworlds.world.WorldExtractMain <file.world>
 */
public final class WorldExtractMain {
   public static void main(String[] args) throws Exception {
      if (args.length < 1) {
         System.err.println("Usage: WorldExtractMain <file.world>");
         System.exit(2);
      }

      byte[] data = Files.readAllBytes(new File(args[0]).toPath());
      WNode world = WorldRestorer.parse(data);

      System.out.println("World: " + world.name + " (default room: " + world.defaultRoomName + ")");
      System.out.println("Rooms: " + world.roomsByName.size());

      int[] counts = new int[3]; // [shapes, totalNodes, maxDepth]
      for (var entry : world.roomsByName.entrySet()) {
         WNode room = entry.getValue();
         int shapesBefore = counts[0];
         walk(room, 0, counts);
         System.out.println("  Room \"" + entry.getKey() + "\": " + (counts[0] - shapesBefore) + " shapes");
      }
      System.out.println("Total shapes (Shape/PosableShape with a geometry URL): " + counts[0]);
      System.out.println("Total nodes in object graph reachable from rooms: " + counts[1]);
      System.out.println("Max tree depth: " + counts[2]);
   }

   private static void walk(WNode node, int depth, int[] counts) {
      counts[1]++;
      counts[2] = Math.max(counts[2], depth);
      if (node.geometryUrl != null) {
         counts[0]++;
      }
      for (WNode child : node.children) {
         walk(child, depth + 1, counts);
      }
   }
}

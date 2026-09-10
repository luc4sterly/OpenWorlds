package net.freeworlds.bod;

import java.io.File;
import java.nio.file.Files;
import java.util.List;

/**
 * CLI smoke-test/inspector for BodParser: parses a .bod file and prints a
 * summary (parts, per-clump tag/vertex/triangle/child counts, whether the
 * whole file was consumed). There is no independent reference decoder for
 * .bod anywhere (checked in an earlier session) - so verification here is
 * structural: does the byte stream fully consume without desyncing (any
 * exception, or leftover unconsumed bytes, means a field is being read
 * wrong), and do the resulting tags/counts look like a real avatar
 * (recognizable limb tags, plausible vertex/triangle counts, no negative
 * or wildly out-of-range values).
 *
 * Usage: java -cp ... net.freeworlds.bod.BodExtractMain <file.bod> [...]
 */
public final class BodExtractMain {
    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            System.err.println("Usage: BodExtractMain <file.bod> [more.bod ...]");
            System.exit(2);
        }
        int okCount = 0;
        for (String path : args) {
            System.out.println("=== " + path + " ===");
            byte[] data = Files.readAllBytes(new File(path).toPath());
            try {
                BodFile bod = BodParser.parse(data);
                boolean fullyConsumed = bod.consumedThroughOffset == bod.byteLength;
                System.out.println("version=" + bod.version + " parts=" + bod.parts.size()
                    + " bytes=" + bod.byteLength + " consumedThrough=" + bod.consumedThroughOffset
                    + (fullyConsumed ? " [FULLY CONSUMED]" : " [!!! LEFTOVER BYTES]"));
                int[] totals = new int[3]; // verts, tris, clumps
                for (BodClump part : bod.parts) {
                    printClump(part, 1, totals);
                }
                System.out.println("totals: clumps=" + totals[2] + " vertices=" + totals[0] + " triangles=" + totals[1]);
                if (fullyConsumed) {
                    okCount++;
                }
            } catch (Exception e) {
                System.out.println("PARSE ERROR: " + e);
            }
            System.out.println();
        }
        System.out.println(okCount + " / " + args.length + " files fully consumed without error");
    }

    private static void printClump(BodClump c, int depth, int[] totals) {
        totals[2]++;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < depth; i++) sb.append("  ");
        sb.append("tag=").append(c.tag);
        if (c.placeholder) {
            sb.append(" [placeholder] t=(").append(c.tx).append(",").append(c.ty).append(",").append(c.tz).append(")");
        } else {
            int nv = c.vertices.size();
            int nt = c.triangles.size();
            totals[0] += nv;
            totals[1] += nt;
            sb.append(" rgb=(").append(c.r).append(",").append(c.g).append(",").append(c.b).append(")")
              .append(" t=(").append(c.tx).append(",").append(c.ty).append(",").append(c.tz).append(")")
              .append(" verts=").append(nv).append(" tris=").append(nt)
              .append(" children=").append(c.children.size());
        }
        System.out.println(sb);
        if (!c.placeholder) {
            for (BodClump child : c.children) {
                printClump(child, depth + 1, totals);
            }
        }
    }
}

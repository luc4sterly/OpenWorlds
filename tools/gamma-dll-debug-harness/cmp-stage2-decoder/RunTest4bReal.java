import java.io.*;
import java.nio.file.*;
import java.util.*;

/** Same as RunTest4b but seeds history from the REAL captured call0/history.bin
 * (512 bytes back / 512 forward from edi0) instead of an all-zero buffer,
 * zero-padding only OUTSIDE that real window. */
public class RunTest4bReal {
    public static void main(String[] args) throws Exception {
        String outerDir = args[0];    // dir containing stream_*.bin, bits.bin
        String callDir = args[1];     // dir containing history.bin, extract_log.txt, esi_all_passes.csv
        byte[] a = Files.readAllBytes(Paths.get(outerDir, "stream_a.bin"));
        byte[] ctrl = Files.readAllBytes(Paths.get(outerDir, "stream_ctrl.bin"));
        byte[] lit = Files.readAllBytes(Paths.get(outerDir, "stream_lit.bin"));
        byte[] fillidx = Files.readAllBytes(Paths.get(outerDir, "stream_fillidx.bin"));
        byte[] bits = Files.readAllBytes(Paths.get(outerDir, "bits.bin"));
        byte[] realHistory = Files.readAllBytes(Paths.get(callDir, "history.bin"));

        // parse call0/extract_log.txt for edi0/esi0/outer0/ch0/stride0 and the real margins used
        int ch0 = -1, outerCount = -1, stride = 0;
        int backMargin = -1, fwdMargin = -1;
        for (String line : Files.readAllLines(Paths.get(callDir, "extract_log.txt"))) {
            if (line.startsWith("edi0=")) {
                for (String part : line.split(" ")) {
                    if (part.startsWith("outer0=")) outerCount = Integer.parseInt(part.substring(7));
                    if (part.startsWith("ch0=")) ch0 = Integer.parseInt(part.substring(4));
                    if (part.startsWith("stride0=")) stride = Integer.parseInt(part.substring(8));
                }
            }
            if (line.startsWith("history.bin:")) {
                for (String part : line.replace(")", "").split("[; ]")) {
                    if (part.startsWith("back_margin=")) backMargin = Integer.parseInt(part.substring("back_margin=".length()));
                    if (part.startsWith("fwd_margin=")) fwdMargin = Integer.parseInt(part.substring("fwd_margin=".length()));
                }
            }
        }
        System.out.println("ch0=" + ch0 + " outerCount=" + outerCount + " stride=" + stride + " backMargin=" + backMargin + " fwdMargin=" + fwdMargin);
        int marginUsed = backMargin; // kept for the existing seeding math below (backward offset into realHistory)

        int outerAdvance = 2 * stride - ch0 * 4;
        int netAdvancePerPass = 2 * stride;
        int totalNetMovement = outerCount * netAdvancePerPass;
        int predictorMargin = 4096;
        int backwardRoom = Math.max(0, -totalNetMovement) + predictorMargin;
        int forwardRoom = Math.max(0, totalNetMovement) + predictorMargin;
        int newEdi0Offset = backwardRoom;
        byte[] bigHistory = new byte[backwardRoom + forwardRoom]; // zero everywhere...
        // ...except where we have REAL captured bytes: realHistory[0..] corresponds
        // to real addresses [edi0-marginUsed, edi0+marginUsed), i.e. window offset
        // [newEdi0Offset - marginUsed, newEdi0Offset + marginUsed) in bigHistory.
        int dst = newEdi0Offset - marginUsed;
        System.arraycopy(realHistory, 0, bigHistory, dst, realHistory.length);
        System.out.println("seeded real bytes at bigHistory[" + dst + ".." + (dst + realHistory.length) + ")");

        CmpStage2 dec = new CmpStage2(bigHistory, newEdi0Offset, stride, a, ctrl, lit, fillidx, bits);

        int edi = newEdi0Offset;
        List<byte[]> passes = new ArrayList<>();
        for (int o = 0; o < outerCount; o++) {
            dec.outPos = 0;
            CmpStage2.TRACE = (o == 0);
            try {
                byte[] passOut = dec.decode(ch0, edi);
                passes.add(passOut);
            } catch (Exception e) {
                System.out.println("EXCEPTION at pass " + o + ": " + e);
                passes.add(java.util.Arrays.copyOf(dec.out == null ? new byte[0] : dec.out, dec.outPos));
                break;
            }
            edi += ch0 * 4;
            edi += outerAdvance;
        }

        List<String> csv = Files.readAllLines(Paths.get(callDir, "esi_all_passes.csv"));
        Map<Long, Integer> real = new HashMap<>();
        for (String line : csv) {
            if (line.startsWith("pass")) continue;
            String[] parts = line.split(",");
            int p = Integer.parseInt(parts[0]);
            int off = Integer.parseInt(parts[1]);
            int val = Integer.parseInt(parts[2]);
            real.put((long) p * 100000 + off, val);
        }

        int total = 0, matches = 0;
        StringBuilder mismatches = new StringBuilder();
        for (int p = 0; p < passes.size(); p++) {
            byte[] po = passes.get(p);
            for (int off = 0; off < po.length; off++) {
                Long key = (long) p * 100000 + off;
                if (!real.containsKey(key)) continue;
                int expected = real.get(key);
                int got = po[off] & 0xFF;
                total++;
                if (got == expected) {
                    matches++;
                } else if (mismatches.length() < 4000) {
                    mismatches.append(String.format("pass=%d off=%d got=%d expected=%d%n", p, off, got, expected));
                }
            }
        }
        System.out.println("MATCHES: " + matches + " / " + total);
        System.out.print(mismatches);

        // dump the full history grid around edi0 for visual/RGB inspection
        StringBuilder sb = new StringBuilder();
        int W = 32;
        for (int row = -4; row < 36; row++) {
            int rowBase = newEdi0Offset + row * stride;
            sb.append(String.format("row%3d: ", row));
            for (int col = 0; col < W; col++) {
                int idx = rowBase + col;
                int v = (idx >= 0 && idx < dec.history.length) ? (dec.history[idx] & 0xFF) : -1;
                sb.append(String.format("%3d ", v));
            }
            sb.append("\n");
        }
        Files.write(Paths.get(callDir, "history_grid.txt"), sb.toString().getBytes());
        System.out.println("wrote history_grid.txt");
    }
}

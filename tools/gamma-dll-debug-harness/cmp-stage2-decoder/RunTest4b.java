import java.io.*;
import java.nio.file.*;
import java.util.*;

public class RunTest4b {
    public static void main(String[] args) throws Exception {
        String dir = args[0];
        byte[] a = Files.readAllBytes(Paths.get(dir, "stream_a.bin"));
        byte[] ctrl = Files.readAllBytes(Paths.get(dir, "stream_ctrl.bin"));
        byte[] lit = Files.readAllBytes(Paths.get(dir, "stream_lit.bin"));
        byte[] fillidx = Files.readAllBytes(Paths.get(dir, "stream_fillidx.bin"));
        byte[] bits = Files.readAllBytes(Paths.get(dir, "bits.bin"));

        int ch0 = 8, outerCount = 16, stride = -32;
        int outerAdvance = 2 * stride - ch0 * 4;

        int netAdvancePerPass = 2 * stride;
        int totalNetMovement = outerCount * netAdvancePerPass;
        int predictorMargin = 4096;
        int backwardRoom = Math.max(0, -totalNetMovement) + predictorMargin;
        int forwardRoom = Math.max(0, totalNetMovement) + predictorMargin;
        int newEdi0Offset = backwardRoom;
        byte[] bigHistory = new byte[backwardRoom + forwardRoom]; // zero-seeded

        CmpStage2 dec = new CmpStage2(bigHistory, newEdi0Offset, stride, a, ctrl, lit, fillidx, bits);

        // replicate decodeFull manually so we can capture EVERY pass's output,
        // not just the last one
        Map<Integer, Integer> resultMap = new TreeMap<>(); // (pass*1000+offset) -> value
        int edi = newEdi0Offset;
        List<byte[]> passes = new ArrayList<>();
        for (int o = 0; o < outerCount; o++) {
            dec.outPos = 0;
            try {
                byte[] passOut = dec.decode(ch0, edi);
                passes.add(passOut);
            } catch (Exception e) {
                System.out.println("EXCEPTION at pass " + o + ": " + e
                    + " posA=" + dec.posA + " posCtrl=" + dec.posCtrl + " posLit=" + dec.posLit
                    + " posFillIdx=" + dec.posFillIdx + " outPos=" + dec.outPos);
                passes.add(java.util.Arrays.copyOf(dec.out == null ? new byte[0] : dec.out, dec.outPos));
                break;
            }
            edi += ch0 * 4;
            edi += outerAdvance;
        }

        // load real captured per-pass values
        List<String> csv = Files.readAllLines(Paths.get(dir, "esi_all_passes.csv"));
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
                } else {
                    if (mismatches.length() < 4000) {
                        mismatches.append(String.format("pass=%d off=%d got=%d expected=%d%n", p, off, got, expected));
                    }
                }
            }
        }
        System.out.println("MATCHES: " + matches + " / " + total);
        System.out.print(mismatches);

        // also dump full decoded grid (all passes concatenated) for inspection
        StringBuilder sb = new StringBuilder();
        for (int p = 0; p < passes.size(); p++) {
            sb.append("pass ").append(p).append(": ");
            for (byte b : passes.get(p)) sb.append(String.format("%3d ", b & 0xFF));
            sb.append("\n");
        }
        Files.write(Paths.get(dir, "decoded_passes.txt"), sb.toString().getBytes());
    }
}

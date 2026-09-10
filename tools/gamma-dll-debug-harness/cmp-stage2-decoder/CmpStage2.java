import java.io.*;
import java.nio.file.*;

/**
 * Re-implementation of gamma.dll's FUN_00457d88 (scanline pixel
 * reconstruction), built from real dynamic-debugging evidence. Operates on
 * ALREADY-decoded symbol streams (the output of the Huffman bit-decoder,
 * FUN_00426af0 - not reimplemented here) plus a real "history" window
 * (dumped live from the process) providing 2D-predictor context.
 */
public class CmpStage2 {
    static int[] PRED_TABLE = new int[50];
    static {
        int[] vals = {
            0,-6,-5,-4,-3,-2,512,513,514,515,516,517,518,506,507,508,509,510,511,
            384,385,386,387,388,389,390,378,379,380,381,382,383,256,257,258,259,260,
            261,262,250,251,252,253,254,255,122,123,124,125,126
        };
        PRED_TABLE = vals;
    }

    byte[] history; // window around edi0, mutable copy
    int historyBase; // absolute "edi0" address this window's index 0 represents offset from (edi0 - historyBase = offset of edi0 in window)
    int edi0OffsetInWindow;
    int stride;

    byte[] streamA;   int posA = 0;
    byte[] streamCtrl; int posCtrl = 0;
    byte[] streamLit;  int posLit = 0;
    byte[] streamFillIdx; int posFillIdx = 0;
    byte[] bits; int bitsBytePos = 0;
    int reg; // 32-bit shift register
    int bitsLeftInReg = 0;

    byte[] out; // output row, growing
    int outPos = 0;

    CmpStage2(byte[] history, int edi0OffsetInWindow, int stride, byte[] streamA, byte[] streamCtrl, byte[] streamLit, byte[] streamFillIdx, byte[] bits) {
        // pad generously: late iterations can reference offsets beyond what a
        // static one-time memory snapshot captured (real evidence: the real
        // process's forward-accessible region ends ~124 bytes past edi0, yet
        // it doesn't crash there - likely a lazily-committed page that later
        // writes trigger the OS to grow, which a single read_memory() at one
        // point in time can't replicate). Padding with zeros lets decode
        // finish; positions that actually depend on this padding are flagged
        // separately rather than silently trusted.
        this.history = java.util.Arrays.copyOf(history, history.length + 4096);
        this.edi0OffsetInWindow = edi0OffsetInWindow;
        this.stride = stride;
        this.streamA = streamA;
        this.streamCtrl = streamCtrl;
        this.streamLit = streamLit;
        this.streamFillIdx = streamFillIdx;
        this.bits = bits;
        refillWord();
    }

    void refillWord() {
        int b0 = bits[bitsBytePos] & 0xFF;
        int b1 = bits[bitsBytePos + 1] & 0xFF;
        int b2 = bits[bitsBytePos + 2] & 0xFF;
        int b3 = bits[bitsBytePos + 3] & 0xFF;
        int word = (b0) | (b1 << 8) | (b2 << 16) | (b3 << 24); // little-endian load
        bitsBytePos += 4;
        // rol $0x10: swap upper/lower 16-bit halves
        reg = ((word << 16) | (word >>> 16));
        bitsLeftInReg = 32;
    }

    // shift out MSB; refill happens when the shift's RESULT is exactly zero
    // (matches the real "je" after "add edx,edx" seen live - only fires when
    // the bit just shifted out was the last surviving 1-bit, i.e. reg was
    // a power of two before the shift). This models the real instruction
    // sequence literally rather than assuming a fixed 32-bit cadence.
    boolean shiftBit() {
        boolean carry = (reg & 0x80000000) != 0;
        reg = reg << 1;
        bitsLeftInReg--;
        if (reg == 0) {
            refillWord();
        }
        return carry;
    }

    int rd32(int histIdx) {
        return (history[histIdx] & 0xFF) | ((history[histIdx+1] & 0xFF) << 8)
             | ((history[histIdx+2] & 0xFF) << 16) | ((history[histIdx+3] & 0xFF) << 24);
    }
    void wr32(int histIdx, int v) {
        history[histIdx] = (byte) v;
        history[histIdx+1] = (byte) (v >>> 8);
        history[histIdx+2] = (byte) (v >>> 16);
        history[histIdx+3] = (byte) (v >>> 24);
    }
    int rd16(int histIdx) {
        return (history[histIdx] & 0xFF) | ((history[histIdx+1] & 0xFF) << 8);
    }
    void wr16(int histIdx, int v) {
        history[histIdx] = (byte) v;
        history[histIdx+1] = (byte) (v >>> 8);
    }
    // byte[1] of a 32-bit value (matches ROL 8 then take low byte)
    static int byte1(int v) { return (v >>> 8) & 0xFF; }

    void emit(int b) {
        if (out == null) { out = new byte[1024]; }
        if (outPos >= out.length) { out = java.util.Arrays.copyOf(out, out.length * 2); }
        out[outPos++] = (byte) b;
    }

    int lookback(int offsetFromCurrent) {
        int idx = outPos + offsetFromCurrent;
        return out[idx] & 0xFF;
    }

    /** Decode `ch` iterations (each produces 2 output bytes), edi starts at edi0. */
    byte[] decode(int ch) {
        int edi = edi0OffsetInWindow;
        for (int i = 0; i < ch; i++) {
            boolean bit1 = shiftBit();
            if (!bit1) {
                // single 4-byte predictor copy
                int idx = streamA[posA++] & 0xFF;
                if (idx == 0) {
                    throw new IllegalStateException("idx==0 special case not modeled (never observed live)");
                }
                int off = PRED_TABLE[idx];
                int v1 = rd32(edi + off);
                wr32(edi, v1);
                int v2 = rd32(edi + stride + off);
                wr32(edi + stride, v2);
                emit(byte1(v1));
                emit(byte1(v2));
            } else {
                boolean bit2 = shiftBit();
                if (bit2) {
                    int ctrl = streamCtrl[posCtrl++] & 0xFF;
                    if (ctrl == 0x24) {
                        int lo = (streamLit[posLit] & 0xFF) | ((streamLit[posLit+1] & 0xFF) << 8)
                               | ((streamLit[posLit+2] & 0xFF) << 16) | ((streamLit[posLit+3] & 0xFF) << 24);
                        posLit += 4;
                        wr32(edi, lo);
                        emit(byte1(lo));
                        int hi = (streamLit[posLit] & 0xFF) | ((streamLit[posLit+1] & 0xFF) << 8)
                               | ((streamLit[posLit+2] & 0xFF) << 16) | ((streamLit[posLit+3] & 0xFF) << 24);
                        posLit += 4;
                        wr32(edi + stride, hi);
                        emit(byte1(hi));
                        // raw-escape does NOT consume streamFillIdx / do the extra broadcast (confirmed via static Ghidra disasm: jumps straight to loop top)
                    } else {
                        int al, ah;
                        int low3 = ctrl & 7;
                        if (low3 == 0) {
                            if (ctrl == 0) {
                                al = streamLit[posLit++] & 0xFF;
                                ah = streamLit[posLit++] & 0xFF;
                            } else {
                                al = streamLit[posLit++] & 0xFF;
                                int off = (ctrl >>> 3) - 3;
                                ah = lookback(off);
                            }
                        } else {
                            int off1 = low3 - 3;
                            al = lookback(off1);
                            int off2 = (ctrl >>> 3) - 3;
                            if ((ctrl >>> 3) == 0) {
                                ah = streamLit[posLit++] & 0xFF;
                            } else {
                                ah = lookback(off2);
                            }
                        }
                        emit(al);
                        emit(ah);
                        // every non-0x24 control-byte iteration ALSO consumes a
                        // streamFillIdx byte and does a run-fill-style broadcast
                        // of `al` into history (4 bytes, both rows) - discovered
                        // live: the 256-entry trivial fill-handler table is
                        // called here too, seeded with whatever ended up in AL
                        // for this iteration (real evidence: gdb trace showing
                        // 0x3a97f68-0x3a97f9a executes unconditionally after the
                        // esi write for every ctrl!=0x24 case).
                        posFillIdx++; // handler selection only affects alignment, not the broadcast value
                        int bcast = (al & 0xFF) * 0x01010101;
                        wr32(edi, bcast);
                        wr32(edi + stride, bcast);
                    }
                } else {
                    // dual 2-byte predictor copy
                    int idx1 = streamA[posA++] & 0xFF;
                    int idx2 = streamA[posA++] & 0xFF;
                    int off1 = PRED_TABLE[idx1];
                    int r1a = rd16(edi + off1);
                    wr16(edi, r1a);
                    int r1b = rd16(edi + stride + off1);
                    wr16(edi + stride, r1b);
                    emit((r1b >>> 8) & 0xFF);

                    int off2 = PRED_TABLE[idx2];
                    int r2a = rd16(edi + 2 + off2);
                    wr16(edi + 2, r2a);
                    int r2b = rd16(edi + stride + 2 + off2);
                    wr16(edi + stride + 2, r2b);
                    emit((r2b >>> 8) & 0xFF);
                }
            }
            edi += 4;
        }
        return java.util.Arrays.copyOf(out, outPos);
    }

    static byte[] readFile(String path) throws IOException {
        return Files.readAllBytes(Paths.get(path));
    }

    public static void main(String[] args) throws Exception {
        // args[0] = directory, args[1] = filename prefix (e.g. "4i_" or
        // "adworlds_") matching the real evidence files checked into this
        // directory (<prefix>edi_window.bin, <prefix>stream_a.bin, etc.)
        String dir = args[0];
        String prefix = args.length > 1 ? args[1] : "";
        byte[] edi = readFile(dir + "/" + prefix + "edi_window.bin");
        byte[] a = readFile(dir + "/" + prefix + "stream_a.bin");
        byte[] ctrl = readFile(dir + "/" + prefix + "stream_ctrl.bin");
        byte[] lit = readFile(dir + "/" + prefix + "stream_lit.bin");
        byte[] fillidx = readFile(dir + "/" + prefix + "stream_fillidx.bin");
        byte[] bits = readFile(dir + "/" + prefix + "bits.bin");
        byte[] real = readFile(dir + "/" + prefix + "esi_row_real.bin");

        // edi0 offset in window: printed by the extractor; read from extract_log.txt for robustness
        int edi0Offset = -1, stride = -1;
        for (String line : Files.readAllLines(Paths.get(dir + "/" + prefix + "extract_log.txt"))) {
            if (line.contains("edi window:")) {
                int i = line.indexOf("offset in window = ");
                edi0Offset = Integer.parseInt(line.substring(i + "offset in window = ".length()).replace(")", "").trim());
            }
            if (line.startsWith("edi0=")) {
                for (String part : line.split(" ")) {
                    if (part.startsWith("stride0=")) stride = Integer.parseInt(part.substring(8));
                }
            }
        }
        System.out.println("edi0Offset=" + edi0Offset + " stride=" + stride);

        CmpStage2 dec = new CmpStage2(edi, edi0Offset, stride, a, ctrl, lit, fillidx, bits);
        byte[] result = dec.decode(32);

        System.out.println("produced " + result.length + " bytes, expected " + real.length);
        boolean match = java.util.Arrays.equals(result, real);
        System.out.println("BYTE-EXACT MATCH: " + match);
        if (!match) {
            int n = Math.min(result.length, real.length);
            int diffs = 0;
            for (int i = 0; i < n; i++) {
                if (result[i] != real[i]) {
                    diffs++;
                    if (diffs <= 20) {
                        System.out.printf("  diff at %d: got 0x%02x expected 0x%02x%n", i, result[i] & 0xFF, real[i] & 0xFF);
                    }
                }
            }
            System.out.println("total diffs: " + diffs + " / " + n);
        }
    }
}

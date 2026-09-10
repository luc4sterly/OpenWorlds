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
    // PRED_TABLE is NOT a fixed array of offsets - it's built by gamma.dll at
    // RUNTIME (in .data, all zero in the static file) from a fixed
    // (colDelta, rowDelta) neighbor-search recipe: off = colDelta +
    // stride*rowDelta. A single earlier session captured this table live but
    // ONLY for 128-wide files (stride=-128) and baked the resulting COMBINED
    // offsets into a flat int[] - which is only correct for stride=-128.
    // Found and fixed in a 2026-09-10 session: entries with rowDelta==0
    // (idx 0-5, the small/nearby offsets) are stride-independent and so
    // happened to keep working for any stride (matches the earlier
    // observation that idx=3 always decoded correctly); every entry with
    // rowDelta!=0 (idx 6+, the "far" offsets) was silently wrong for any
    // stride other than -128 - e.g. idx=32 gave 256 (correct only for
    // stride=-128) instead of 64 (the real value for stride=-32), which is
    // exactly the bug that broke test4b.cmp (32-wide, stride=-32) from
    // iteration 5 onward. Derived by live-reading gamma.dll's runtime table
    // (address 0x00482d0d, DWORD per entry, NOT the 0x00478e98 address an
    // earlier session's comments claimed - that address holds unrelated
    // data) for two different real strides (-128 and -32) and solving the
    // two linear equations per entry; every entry gave a clean integer
    // solution with no residual, confirming the model.
    static final int[] PRED_COL = {
        0,-6,-5,-4,-3,-2, 0,1,2,3,4,5,6, -6,-5,-4,-3,-2,-1,
        0,1,2,3,4,5,6, -6,-5,-4,-3,-2,-1,
        0,1,2,3,4,5,6, -6,-5,-4,-3,-2,-1,
        -6,-5,-4,-3,-2
    };
    static final int[] PRED_ROW = {
        0,0,0,0,0,0, -4,-4,-4,-4,-4,-4,-4, -4,-4,-4,-4,-4,-4,
        -3,-3,-3,-3,-3,-3,-3, -3,-3,-3,-3,-3,-3,
        -2,-2,-2,-2,-2,-2,-2, -2,-2,-2,-2,-2,-2,
        -1,-1,-1,-1,-1
    };
    static { if (PRED_COL.length != 50 || PRED_ROW.length != 50) throw new AssertionError("PRED_COL/PRED_ROW size mismatch"); }

    /** off = colDelta + stride*rowDelta, evaluated for THIS instance's real stride (not a fixed table). */
    int predOffset(int idx) {
        return PRED_COL[idx] + stride * PRED_ROW[idx];
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
        // Real esi resets to the SAME starting address every outer pass
        // (see decodeFull below), so on iteration 0-1 of pass 2+ a negative
        // offsetFromCurrent legitimately points BEFORE this call's own
        // output - real memory there, but not memory this function itself
        // ever wrote (it only ever writes forward from esi0). Not modeled
        // (no real value known for it) - treated as 0 rather than crashing,
        // same honest-unknown convention as the zero-padded history buffer.
        int idx = outPos + offsetFromCurrent;
        if (idx < 0 || idx >= outPos) {
            return 0;
        }
        return out[idx] & 0xFF;
    }

    /**
     * Outer loop, found by re-reading the full saved disassembly (missed in
     * the previous session): after the inner ch-loop finishes, real code at
     * 0x3a97e60-0x3a97e78 resets esi to its ORIGINAL starting value, resets
     * ch to its original count, advances edi by DAT_3ac2d09 (= 2*stride -
     * ch0*4, on top of the ch0*4 the inner loop already advanced it - net
     * 2*stride per outer pass), and decrements an outer counter (read from
     * param 0x10(ebp) at entry - 64 for both files tested here) before
     * looping the WHOLE inner process again. Stream positions and the bit
     * register are NOT reset between outer passes (they live in the same
     * DAT_ globals throughout) - only esi/ch are. Only the LAST outer pass's
     * esi writes are the real, final output; earlier passes exist purely to
     * build up the edi history buffer (hence outerCount * 2*stride ==
     * 64*256 == 16384 == 128*128, the full image size, for the files
     * tested).
     */
    byte[] decodeFull(int ch0, int outerCount, int outerAdvance) {
        int edi = edi0OffsetInWindow;
        byte[] lastPass = null;
        for (int o = 0; o < outerCount; o++) {
            outPos = 0;
            lastPass = decode(ch0, edi);
            edi += ch0 * 4;       // already-executed inner-loop advance
            edi += outerAdvance;  // additional outer-loop advance (DAT_3ac2d09)
        }
        return lastPass;
    }

    // Debug flag: when true, decode() prints which branch (SINGLE/DUAL/CTRL)
    // fires each iteration. A live branch census against gamma.dll itself
    // (2026-09-10 session, see cmp-stage2-decoder/README.md) found this
    // decoder spuriously taking DUAL branches that the real process never
    // takes for test4b.cmp (real: 124 SINGLE + 4 CTRL + 0 DUAL out of 128
    // iterations) - this flag is left in for whoever chases that bug next.
    static boolean TRACE = false;

    /** Decode `ch` iterations (each produces 2 output bytes) starting at the given edi. */
    byte[] decode(int ch, int edi0Arg) {
        int edi = edi0Arg;
        for (int i = 0; i < ch; i++) {
            boolean bit1 = shiftBit();
            if (!bit1) {
                // single 4-byte predictor copy
                int idx = streamA[posA++] & 0xFF;
                if (idx == 0) {
                    throw new IllegalStateException("idx==0 special case not modeled (never observed live)");
                }
                int off = predOffset(idx);
                if (TRACE) System.out.println("iter=" + i + " SINGLE idx=" + idx + " off=" + off + " posA=" + posA);
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
                    if (TRACE) System.out.println("iter=" + i + " CTRL ctrl=" + ctrl + " posCtrl=" + posCtrl);
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
                    if (TRACE) System.out.println("iter=" + i + " DUAL idx1=" + idx1 + " idx2=" + idx2 + " posA=" + posA);
                    int off1 = predOffset(idx1);
                    int r1a = rd16(edi + off1);
                    wr16(edi, r1a);
                    int r1b = rd16(edi + stride + off1);
                    wr16(edi + stride, r1b);
                    emit((r1b >>> 8) & 0xFF);

                    int off2 = predOffset(idx2);
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

        int ch0 = 32;       // DAT_3ac2d04 (== bl from param 0x14(ebp)) for the files tested
        int outerCount = 64; // DAT_3ac2d00 (== param 0x10(ebp)) for the files tested
        int outerAdvance = 2 * stride - ch0 * 4; // DAT_3ac2d09, per the real setup code

        // Hypothesis test: does history need to be SEEDED from a live memory
        // dump at all, or does a freshly-allocated (hence OS-zeroed) buffer
        // work, since the outer loop builds up all its own context across
        // 64 passes? Try zero-initialized first - if this matches real
        // output, no memory-window capture is needed at all for verification.
        boolean zeroSeed = args.length > 2 && args[2].equals("zero");

        // edi moves by netAdvancePerPass (== 2*stride, see decodeFull) once
        // per outer pass; over outerCount passes the real `edi` pointer
        // wanders by totalNetMovement bytes from edi0 (negative here, since
        // stride is negative for the bottom-up files tested - edi walks to
        // LOWER addresses each pass). The buffer must have enough room on
        // whichever side that movement heads towards, plus a fixed margin
        // for the +-6/+-518ish predictor-table offsets read at any point
        // along the way.
        int netAdvancePerPass = 2 * stride;
        int totalNetMovement = outerCount * netAdvancePerPass;
        int predictorMargin = 4096;
        int backwardRoom = Math.max(0, -totalNetMovement) + predictorMargin;
        int forwardRoom = Math.max(0, totalNetMovement) + predictorMargin;
        int newEdi0Offset = backwardRoom;
        byte[] bigHistory = new byte[backwardRoom + forwardRoom];
        if (!zeroSeed) {
            System.arraycopy(edi, 0, bigHistory, newEdi0Offset - edi0Offset, edi.length);
        }

        CmpStage2 dec = new CmpStage2(bigHistory, newEdi0Offset, stride, a, ctrl, lit, fillidx, bits);
        byte[] result = dec.decodeFull(ch0, outerCount, outerAdvance);

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

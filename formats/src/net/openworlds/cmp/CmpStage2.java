package net.openworlds.cmp;

import java.io.*;
import java.nio.file.*;

/**
 * Re-implementation of gamma.dll's FUN_00457d88 (scanline pixel
 * reconstruction), built from real dynamic-debugging evidence. Operates on
 * ALREADY-decoded symbol streams (the output of the Huffman bit-decoder,
 * FUN_00426af0 - not reimplemented here) plus a real "history" window
 * (dumped live from the process) providing 2D-predictor context.
 *
 * PORTED from tools/gamma-dll-debug-harness/cmp-stage2-decoder/CmpStage2.java
 * (the verified artifact - byte-exact on test4b/rustwood/sball.cmp, see that
 * directory's README round-5 section). The harness copy is authoritative for
 * verification; this copy is the runtime one (CmpFrames, which the bridge
 * uses for ScapePic textures, and CmpTexture). Keep the decode logic in sync;
 * only the package declaration and this header differ.
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
    //
    // IMPORTANT: this refill-guarded form matches every "add edx,edx" site
    // in FUN_00457d88 EXCEPT bit1's own test (0x457e1a: "add edx,edx; jb
    // 0x457e80" - no accompanying "je" at all). Use shiftBit1NoRefill() for
    // that one site; see its comment for why the distinction is real, not
    // cosmetic (2026-09-10, LINEA A session, found via rustwood.cmp - a
    // rare case genuinely hits this since it needs the register's lowest
    // set bit to land exactly on a bit1 test).
    boolean shiftBit() {
        boolean carry = (reg & 0x80000000) != 0;
        reg = reg << 1;
        bitsLeftInReg--;
        if (reg == 0) {
            refillWord();
        }
        return carry;
    }

    // bit1's test (0x457e1a) is the ONE "add edx,edx" in this function with
    // NO accompanying "je [refill]" - confirmed directly from disassembly.
    // If the register's last surviving bit is shifted out exactly here, real
    // hardware does NOT refill immediately: reg is left sitting at literal 0,
    // and the refill is deferred to whichever refill-guarded site runs next
    // (bit2, or SINGLE's extra pad bit) - which, shifting an already-zero
    // register, produces a genuine "fake" 0 bit (0<<1==0, carry==0) BEFORE
    // that site's own "je" finally triggers the real refill. An earlier
    // version of shiftBit() refilled eagerly regardless of call site,
    // silently dropping that one fake bit whenever this edge case hit -
    // desyncing every bit read after it by exactly one position. Found via a
    // real branch-dispatch trace against rustwood.cmp: the decoder read
    // CTRL where the real process took DUAL, several iterations after the
    // last verified-correct one, with no other explanation surviving
    // (predictor table, idx values, and the fill-broadcast formula were all
    // independently re-verified live and were NOT the cause here). No
    // change needed elsewhere: once the next guarded shiftBit() call
    // performs its own deferred refill, the two streams naturally
    // resynchronize with no additional state to track.
    boolean shiftBit1NoRefill() {
        boolean carry = (reg & 0x80000000) != 0;
        reg = reg << 1;
        bitsLeftInReg--;
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
    // Emitted byte of a 32-bit history word on the SINGLE and 0x24 paths.
    // Both do "rol eax,8; mov [esi(+1)],al" (SINGLE @0x457e36/0x457e39 and
    // @0x457e4c/0x457e4f; 0x24 @0x457fba/0x457fbd and @0x457fd0/0x457fd3).
    // x86 ROL r32,8 rotates toward the MSB, so the new AL is the OLD HIGH
    // byte (bits 24-31), NOT byte 1: al = byte3(v). An earlier version of
    // this decoder emitted byte1 (as if the rotation were ROR) - invisible
    // against test4b.cmp (flat quadrants: every history word has all four
    // bytes equal, so byte1==byte3) and nearly invisible against
    // rustwood.cmp (26/4096), but wrong on varied content: found via a live
    // mem-after-store trace of sball.cmp pass 0 (2026-09-10, LINEA A
    // session) - real iter-8 SINGLE reads v1=[07,07,07,1f] and really emits
    // 0x1f (memcap.txt "ev pass=0 off=16 site=SW0 regal=31 mem=31"),
    // while byte1(v1) is 0x07. DUAL is unaffected: it stores ah with NO
    // rotation (0x457ebb/0x457ee5), i.e. genuinely byte1 of the 16-bit
    // half-word - left as-is below.
    static int byte3(int v) { return (v >>> 24) & 0xFF; }

    void emit(int b) {
        if (out == null) { out = new byte[1024]; }
        if (outPos >= out.length) { out = java.util.Arrays.copyOf(out, out.length * 2); }
        out[outPos++] = (byte) b;
    }

    /** esi += n with no store: the bytes already there (an earlier pass's, or 0) stay. */
    void skipOut(int n) {
        if (out == null) { out = new byte[1024]; }
        while (outPos + n > out.length) { out = java.util.Arrays.copyOf(out, out.length * 2); }
        outPos += n;
    }

    int lookback(int offsetFromCurrent) {
        // Real esi resets to the SAME starting address every outer pass (see
        // decodeFull below) and, like the edi/history buffer, is NEVER
        // cleared between passes - a lookback with idx >= outPos(this pass)
        // legitimately reads a PREVIOUS pass's leftover byte at that same
        // array slot, not "unwritten" memory. Confirmed with real evidence
        // (2026-09-10, LINEA A session): test4b.cmp pass 8 iter 0 computes
        // `ah` via lookback(off=0) - i.e. idx==outPos exactly, BEFORE this
        // iteration's own write lands (real al/ah are only stored together,
        // as one word, at the very end of the iteration) - and the real
        // captured value there (63) exactly equals pass 7's real value at
        // that SAME output position (also 63, esi_all_passes.csv "7,0,63"),
        // not pass 8's own freshly-computed al (60). So: any idx within the
        // buffer's real bounds is valid to read regardless of the CURRENT
        // pass's outPos; only idx outside the buffer entirely (never
        // written by any pass so far) is genuinely unknown, treated as 0
        // (same honest-unknown convention as the zero-padded history
        // buffer) rather than crashing.
        int idx = outPos + offsetFromCurrent;
        if (idx < 0 || out == null || idx >= out.length) {
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
    static int DEBUG_BASE = 0; // for relative-address debug prints only

    /** Decode `ch` iterations (each produces 2 output bytes) starting at the given edi. */
    byte[] decode(int ch, int edi0Arg) {
        int edi = edi0Arg;
        for (int i = 0; i < ch; i++) {
            boolean bit1 = shiftBit1NoRefill();
            if (!bit1) {
                // single 4-byte predictor copy
                int idx = streamA[posA++] & 0xFF;
                if (idx == 0) {
                    // Skip (gamma.dll 0x457e22 "and ebx,0xff / je 0x457e0c"):
                    // nothing is stored, neither the two history words nor
                    // the two esi bytes. 0x457e0c shifts out the pad bit
                    // (add edx,edx / je 0x457df8 refill), as 0x457e52 does on
                    // the copy path, then 0x457e10 advances edi by 4 and,
                    // unless the row ends, esi by 2. So the 2x4 block keeps
                    // what it held: the previous frame's pixels in a .mov,
                    // and in the esi row the byte of an earlier pass.
                    // ⚠️ VERIFY: read from the disassembly only; no file in
                    // the corpus or in the worlds tried takes it (tex/mug.cmp
                    // of the Blair Witch world threw here only because the
                    // old single-group CmpFrames ran past its first group's
                    // streams into the zero padding).
                    if (TRACE) System.out.println("iter=" + i + " SKIP posA=" + posA);
                    shiftBit();
                    skipOut(2);
                    edi += 4;
                    continue;
                }
                int off = predOffset(idx);
                if (TRACE) System.out.println("iter=" + i + " SINGLE idx=" + idx + " off=" + off + " posA=" + posA);
                int v1 = rd32(edi + off);
                wr32(edi, v1);
                int v2 = rd32(edi + stride + off);
                wr32(edi + stride, v2);
                emit(byte3(v1));
                emit(byte3(v2));
                // Real disassembly (FUN_00457d88 @0x457e52, gamma.dll) shows the
                // SINGLE path does a SECOND "add edx,edx" here before rejoining
                // the loop tail - a bit is shifted out of the register and its
                // value is NEVER tested (only the resulting refill-check "je"
                // uses it, via ZF - the carry/bit VALUE itself feeds no branch).
                // DUAL/CTRL jump straight to the shared tail (0x457e10) with no
                // such extra shift. Every iteration consumes exactly 2 bits from
                // the stream either way (bit1+bit2 for DUAL/CTRL, bit1+this
                // discarded pad bit for SINGLE) - the encoder apparently keeps a
                // fixed 2-bit-per-iteration budget regardless of branch. Missing
                // this desynced the bit reader by 1 bit starting from the first
                // SINGLE iteration, which is exactly why the decoder started
                // spuriously taking DUAL branches the real process never takes
                // (see README.md, "second, deeper bug").
                shiftBit();
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
                        emit(byte3(lo));
                        int hi = (streamLit[posLit] & 0xFF) | ((streamLit[posLit+1] & 0xFF) << 8)
                               | ((streamLit[posLit+2] & 0xFF) << 16) | ((streamLit[posLit+3] & 0xFF) << 24);
                        posLit += 4;
                        wr32(edi + stride, hi);
                        emit(byte3(hi));
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
                            if (TRACE) System.out.println("  CTRL low3!=0: ctrl=" + ctrl + " off1=" + off1 + " al(lookback)=" + al
                                + " outPos=" + outPos + " lookbackIdx=" + (outPos + off1));
                            if ((ctrl >>> 3) == 0) {
                                ah = streamLit[posLit++] & 0xFF;
                            } else {
                                ah = lookback(off2);
                            }
                        }
                        emit(al);
                        emit(ah);
                        // every non-0x24 control-byte iteration ALSO consumes a
                        // streamFillIdx byte and writes 4 history bytes into
                        // BOTH rows (double-row write, like SINGLE/DUAL) via the
                        // 256-entry PTR_LAB_00483844 handler table.
                        //
                        // NOT a uniform "broadcast AL 4x" (an earlier session's
                        // static read of a handful of handler bodies concluded
                        // that - wrong, and it never showed up as a bug against
                        // test4b.cmp because that file's literal byte pairs
                        // always had al==ah, making the two formulas
                        // indistinguishable). Real evidence (2026-09-10, LINEA A
                        // session): live-traced EAX/EDX/ECX/EBX immediately
                        // before/after the `call [edx*4+0x483844]` against
                        // rustwood.cmp (real varied content, al!=ah). The
                        // fillIdx BYTE ITSELF is an 8-bit shuffle mask - bit n
                        // independently selects `ah` (1) or `al` (0) for ONE of
                        // 8 output byte-lanes. Confirmed exactly (all 8 bits) on
                        // 3 independent live samples, e.g. fillIdx=0x70=0b01110000
                        // (al=0xd3,ah=0x9c) -> real DL=0xd3(al) DH=0xd3(al)
                        // CL=0xd3(al) CH=0xd3(al) BL=0x9c(ah) BH=0x9c(ah)
                        // AL_out=0x9c(ah) AH_out=0xd3(al) - bit0..7 in that exact
                        // order (DL,DH,CL,CH,BL,BH,ALout,AHout), MSB=bit7=ALout's
                        // pair partner (AHout). The memory writes actually done
                        // (`mov [edi],dx; mov [edi+2],cx; add edi,stride;
                        // mov [edi],bx; mov [edi+2],ax`) only use the low 16 bits
                        // of each register, so upper-bit "garbage" left over from
                        // unrelated earlier code in edx/ecx/ebx (also observed
                        // live) never reaches memory - safe to ignore.
                        int fillIdx = streamFillIdx[posFillIdx++] & 0xFF;
                        int dl = (fillIdx & 0x01) != 0 ? ah : al;
                        int dh = (fillIdx & 0x02) != 0 ? ah : al;
                        int cl = (fillIdx & 0x04) != 0 ? ah : al;
                        int ch2 = (fillIdx & 0x08) != 0 ? ah : al;
                        int bl = (fillIdx & 0x10) != 0 ? ah : al;
                        int bh = (fillIdx & 0x20) != 0 ? ah : al;
                        int axLo = (fillIdx & 0x40) != 0 ? ah : al;
                        int axHi = (fillIdx & 0x80) != 0 ? ah : al;
                        int row1 = dl | (dh << 8) | (cl << 16) | (ch2 << 24);
                        int row2 = bl | (bh << 8) | (axLo << 16) | (axHi << 24);
                        if (TRACE) System.out.println("  CTRL fill: edi(rel)=" + (edi - DEBUG_BASE) + " al=" + al + " ah=" + ah
                            + " fillIdx=" + fillIdx + " row1(@" + (edi - DEBUG_BASE) + ")=" + row1 + " row2(@" + (edi + stride - DEBUG_BASE) + ")=" + row2);
                        wr32(edi, row1);
                        wr32(edi + stride, row2);
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
                    if (TRACE) System.out.println("  edi(rel)=" + (edi - DEBUG_BASE) + " off1=" + off1
                        + " readAddr1(rel)=" + (edi + stride + off1 - DEBUG_BASE) + " r1b_raw=" + r1b
                        + " emitted=" + ((r1b >>> 8) & 0xFF));
                    emit((r1b >>> 8) & 0xFF);

                    int off2 = predOffset(idx2);
                    if (TRACE) System.out.println("  edi(rel)=" + (edi - DEBUG_BASE) + " off1=" + off1 + " off2=" + off2
                        + " readAddr2(rel)=" + (edi + 2 + off2 - DEBUG_BASE) + " r2a_raw=" + rd16(edi + 2 + off2));
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

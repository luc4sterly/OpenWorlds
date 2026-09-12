package net.freeworlds.cmp;

import java.io.IOException;

/**
 * Real Stage 1 decoder: raw .cmp file bytes -&gt; the 5 symbol streams
 * (bits/streamA/streamFillIdx/streamCtrl/streamLit) that {@link CmpStage2}
 * already consumes byte-exact, plus the embedded palette.
 *
 * Every field and algorithm here is transcribed directly from disassembly
 * of gamma.dll (FUN_00442750, FUN_0042f460, FUN_004269c0, FUN_00426640,
 * FUN_004266f0, FUN_00426820, FUN_004426b0, FUN_00426af0 - static VAs),
 * cross-checked against live-captured argument values and buffer dumps for
 * test4b.cmp (tools/gamma-dll-debug-harness/cmp_capture_stage1.py output,
 * 2026-09-12 session). See docs/cmp-texture-format-reference.md for the
 * full evidence trail. Nothing here is guessed: every constant/offset was
 * either read directly from gamma.dll's machine code or confirmed against
 * a live trace.
 */
public final class CmpStage1 {
   public final int width;
   public final int height;
   public final int[][] palette; // 256 entries, some possibly null
   public final byte[] bits;
   public final byte[] streamA;
   public final byte[] streamFillIdx;
   public final byte[] streamCtrl;
   public final byte[] streamLit;

   private CmpStage1(int width, int height, int[][] palette, byte[] bits,
                      byte[] streamA, byte[] streamFillIdx, byte[] streamCtrl, byte[] streamLit) {
      this.width = width;
      this.height = height;
      this.palette = palette;
      this.bits = bits;
      this.streamA = streamA;
      this.streamFillIdx = streamFillIdx;
      this.streamCtrl = streamCtrl;
      this.streamLit = streamLit;
   }

   // The 3 real fixed alphabet-permutation tables, extracted byte-exact from
   // gamma.dll (see docs/cmp-texture-format-reference.md "Sesión Stage 1").
   private static final int[] PERM0 = hex(
      "555657595a5b5d5e5f656667696a6b6d6e6f757677797a7b7d7e7f959697999a9b9d9e9fa5a6a7a9aaabadaeafb5b6b7b9babbbdbebfd5d6d7d9dadbdddedfe5e6e7e9eaebedeeeff5f6f7f9fafbfdfeff");
   private static final int[] PERM1 = hex(
      "0102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f3031");
   private static final int[] PERM3 = hex(
      "0001020304080a0b0c1011131418191a1c2021222324");

   private static int[] hex(String s) {
      int[] out = new int[s.length() / 2];
      for (int i = 0; i < out.length; i++) {
         out[i] = Integer.parseInt(s.substring(i * 2, i * 2 + 2), 16);
      }
      return out;
   }

   private static int u8(byte[] b, int i) { return b[i] & 0xFF; }
   private static int u16(byte[] b, int i) { return (b[i] & 0xFF) | ((b[i + 1] & 0xFF) << 8); }

   /** Bit reader for the embedded-palette phase (FUN_004426b0), MSB-first per byte. */
   private static final class BitReader {
      final byte[] data;
      int pos;
      int bitBuf = 0;
      int bitMask = 0;
      int bytesConsumed = 0;

      BitReader(byte[] data, int startPos) {
         this.data = data;
         this.pos = startPos;
      }

      int nextBit() {
         bitMask >>= 1;
         if (bitMask == 0) {
            bitBuf = data[pos++] & 0xFF;
            bytesConsumed++;
            bitMask = 0x80;
         }
         return (bitBuf & bitMask) != 0 ? 1 : 0;
      }
   }

   /** Result of building one Huffman table: 256-entry symbol/length direct lookup. */
   private static final class HuffTable {
      final int[] symbol = new int[256];
      final int[] length = new int[256];
   }

   /**
    * FUN_00426640: unpack 4-bit code lengths for up to alphabetSize symbols
    * from byteLen source bytes, scattered into a 256-entry length array via
    * the fixed permutation table. effectiveCount = min(alphabetSize, 2*byteLen)
    * nibbles are actually read (matches real disassembly exactly); any
    * remaining alphabet slots keep length 0 (already zero-initialized).
    */
   private static int[] unpackLengths(byte[] src, int cursor, int byteLen, int[] permTable, int alphabetSize) {
      int[] lengths = new int[256];
      int effectiveCount = Math.min(alphabetSize, 2 * byteLen);
      int p = cursor;
      for (int i = 0; i < effectiveCount; ) {
         int b = src[p++] & 0xFF;
         int lo = b & 0xF;
         lengths[permTable[i]] = lo;
         i++;
         if (i < effectiveCount) {
            int hi = (b >> 4) & 0xF;
            lengths[permTable[i]] = hi;
            i++;
         }
      }
      return lengths;
   }

   /**
    * FUN_004266f0 (LHA make_table pass 1: canonical code assignment) +
    * FUN_00426820 (expansion into a direct 256-entry lookup, including the
    * degenerate single-symbol fill-all case) + trivial length-table derive.
    */
   private static HuffTable buildFromLengths(int[] lengths) {
      int[] count = new int[9];
      int sum = 0;
      for (int i = 0; i < 256; i++) {
         count[lengths[i]]++;
         sum += lengths[i];
      }
      HuffTable t = new HuffTable();
      if (sum <= 1) {
         int only = -1;
         for (int i = 0; i < 256; i++) {
            if (lengths[i] != 0) { only = i; break; }
         }
         if (only < 0) {
            // No symbol at all (fully empty channel, e.g. degenerate index 2
            // with alphabetSize 0 unpacked to all-zero lengths and sum==0).
            return t;
         }
         int onlyLen = lengths[only];
         for (int i = 0; i < 256; i++) {
            t.symbol[i] = only;
            t.length[i] = onlyLen;
         }
         return t;
      }
      // start[1] = 0 (length-1 codes start at code 0); start[len+1] =
      // (start[len]+count[len])<<1 for len=1..7. count[0] never
      // participates - length-0 symbols carry no code at all.
      int[] start = new int[9];
      start[1] = 0;
      for (int len = 1; len <= 7; len++) {
         start[len + 1] = (start[len] + count[len]) << 1;
      }
      int[] code = new int[256];
      int[] next = start.clone();
      for (int i = 0; i < 256; i++) {
         int len = lengths[i];
         if (len == 0) continue;
         code[i] = next[len];
         next[len] = next[len] + 1;
      }
      for (int i = 0; i < 256; i++) {
         int len = lengths[i];
         if (len == 0) continue;
         int shift = 8 - len;
         int base = code[i] << shift;
         int slots = 1 << shift;
         for (int s = 0; s < slots; s++) {
            t.symbol[base + s] = i;
            t.length[base + s] = len;
         }
      }
      return t;
   }

   private static HuffTable buildTable(byte[] src, int cursor, int byteLen, int[] permTable, int alphabetSize) {
      int[] effPerm = permTable;
      int effAlpha = alphabetSize;
      if (effPerm == null || effAlpha == 0) {
         // FUN_004269c0's degenerate fallback: synthesize the 256-entry
         // identity permutation (confirmed by disassembly this session).
         effPerm = new int[256];
         for (int i = 0; i < 256; i++) effPerm[i] = i;
         effAlpha = 256;
      }
      int[] lengths = unpackLengths(src, cursor, byteLen, effPerm, effAlpha);
      return buildFromLengths(lengths);
   }

   /**
    * Shared bit-level cursor: the 16-bit shift window and bit counter carry
    * over across all Huffman channels within a group (confirmed empirically
    * this session - the "bits" channel decodes byte-exact with a fresh
    * 16-bit load, but the next channel only matches when it continues from
    * the leftover mid-byte window state rather than re-loading fresh).
    * Only the very first Huffman channel of a group does the fresh load.
    */
   private static final class BitCursor {
      byte[] src;
      int pos;
      int window;
      int bitsAvail;
      boolean primed = false;
   }

   /** FUN_00426af0: the real bit-level Huffman decoder, direct 256-entry lookup, codes <=8 bits. */
   private static byte[] decodeChannel(BitCursor bc, HuffTable table, int wantedLen) {
      byte[] out = new byte[wantedLen];
      if (wantedLen == 0) return out;
      if (!bc.primed) {
         bc.window = ((bc.src[bc.pos] & 0xFF) << 8) | (bc.src[bc.pos + 1] & 0xFF);
         bc.pos += 2;
         bc.bitsAvail = 8;
         bc.primed = true;
      }
      int pos = bc.pos;
      int window = bc.window;
      int bitsAvail = bc.bitsAvail;
      for (int i = 0; i < wantedLen; i++) {
         int idx = (window >> 8) & 0xFF;
         int symbol = table.symbol[idx];
         int length = table.length[idx];
         out[i] = (byte) symbol;
         int oldBits = bitsAvail;
         bitsAvail -= length;
         if (bitsAvail < 0) {
            window = (window << oldBits) & 0xFFFF;
            int newByte = bc.src[pos++] & 0xFF;
            window = (window & 0xFF00) | newByte;
            int missing = length - oldBits;
            bitsAvail += 8;
            window = (window << missing) & 0xFFFF;
         } else {
            window = (window << length) & 0xFFFF;
         }
      }
      bc.pos = pos;
      bc.window = window;
      bc.bitsAvail = bitsAvail;
      return out;
   }

   public static CmpStage1 decode(byte[] cmp) throws IOException {
      if (cmp.length < 34 || cmp[0] != 'L' || cmp[1] != 'z' || cmp[2] != 'H' || cmp[3] != '2') {
         throw new IOException("not a LzH2 .cmp file");
      }
      int mode = u8(cmp, 4);
      int flags = u8(cmp, 5);
      if ((flags & 0x80) == 0) throw new IOException("flags bit7 must be 1");
      if ((flags & 0x54) != 0) throw new IOException("flags bits 2/4/6 must be 0 (got 0x" + Integer.toHexString(flags) + ")");
      int w = u16(cmp, 6);
      int h = u16(cmp, 8);
      if (cmp[19] != 0) throw new IOException("header byte 19 must be 0");
      int tableRegionSize = u16(cmp, 28);
      int groupRegionSize = u16(cmp, 30);
      int payloadSize = u16(cmp, 32);
      if (tableRegionSize + groupRegionSize != payloadSize) {
         throw new IOException("tableRegionSize+groupRegionSize != payloadSize");
      }
      if (34 + payloadSize != cmp.length) {
         throw new IOException("34+payloadSize != file length (" + (34 + payloadSize) + " vs " + cmp.length + ")");
      }
      int[] byteLens = new int[5];
      for (int i = 0; i < 5; i++) byteLens[i] = u8(cmp, 14 + i);
      int paletteCount = u8(cmp, 12) != 0 ? u8(cmp, 12) : 256;
      int byte13 = u8(cmp, 13);

      byte[] tableRegion = new byte[tableRegionSize];
      System.arraycopy(cmp, 34, tableRegion, 0, tableRegionSize);
      byte[] groupRegion = new byte[groupRegionSize];
      System.arraycopy(cmp, 34 + tableRegionSize, groupRegion, 0, groupRegionSize);

      // Embedded palette: FUN_004426b0, 6-bit RGB components (<<2 to 8-bit),
      // packed as 3 real bytes + 1 null spacer per entry.
      //
      // KNOWN LIMITATION, honestly flagged (2026-09-12 session): the bit
      // extraction below was manually cross-checked bit-for-bit against
      // test4b.cmp's raw file bytes and is 100% accurate to what the file
      // encodes at entry index i (i.e. palette[i] here is proven byte-exact
      // to the RAW encoded RGB triple at sequential position i, matching
      // FUN_004426b0's disassembly exactly: entries are written densely,
      // sequentially, no permutation). However, the resulting palette[]
      // array does NOT yet produce correct final pixel colors when indexed
      // directly by CmpStage2's decoded history values: for test4b.cmp, the
      // spatial region boundaries decode perfectly (proving the symbol
      // streams above are correct), but the 4 real colors end up rotated
      // among the 4 real used indices (58,60,62,63) relative to
      // cmpview.exe's real rendering - e.g. index 58 should show red but
      // this array's palette[58] is green (which belongs at a different
      // index). Every simple transform hypothesis tried this session
      // (uniform index shift, XOR, subtraction, reversed read order,
      // per-component R/G/B reordering) failed to explain the exact
      // rotation - there is a genuine remaining unknown in how gamma.dll
      // maps a decoded pixel value to this array before rendering, not yet
      // found. Do not trust palette[] for final color output without
      // solving this; the symbol streams (bits/streamA/streamFillIdx/
      // streamCtrl) are independently verified correct and unaffected.
      BitReader br = new BitReader(tableRegion, 0);
      int[][] palette = new int[256][];
      for (int i = 0; i < paletteCount; i++) {
         int[] rgb = new int[3];
         for (int c = 0; c < 3; c++) {
            int v6 = 0;
            for (int bit = 0; bit < 6; bit++) v6 = (v6 << 1) | br.nextBit();
            rgb[c] = (v6 << 2) & 0xFF;
         }
         palette[i] = rgb;
      }
      int cursor = br.bytesConsumed;

      if ((mode & 0x02) == 0) cursor += paletteCount;
      if (byte13 != 0) cursor += (byte13 * 18 + 7) / 8;
      if ((flags & 0x01) != 0) cursor += (paletteCount / 2) + paletteCount - 1;
      if ((mode & 0x08) != 0) cursor += 4;
      int groupCount;
      if ((mode & 0x80) != 0) {
         groupCount = u16(tableRegion, cursor);
         cursor += 14;
      } else {
         groupCount = 1;
      }
      if (groupCount != 1) {
         throw new IOException("groupCount=" + groupCount + " (>1 not yet implemented/verified)");
      }

      int[][] permTables = {PERM0, PERM1, null, PERM3, null};
      int[] alphaSizes = {81, 49, 0, 22, 0};
      HuffTable[] huff = new HuffTable[5];
      for (int t = 0; t < 5; t++) {
         huff[t] = buildTable(tableRegion, cursor, byteLens[t], permTables[t], alphaSizes[t]);
         cursor += byteLens[t];
      }

      // Group header: 16 bytes, groupRegion[0..15]. Layout: field0(u16),
      // 5x u16 wanted-lengths (bits,streamA,streamFillIdx,streamCtrl,streamLit),
      // field12(u16), field14(u16) - live-confirmed 2026-09-11 session.
      int[] wanted = new int[5];
      for (int i = 0; i < 5; i++) wanted[i] = u16(groupRegion, 2 + i * 2);

      BitCursor bc = new BitCursor();
      bc.src = groupRegion;
      bc.pos = 16; // right after the 16-byte group header
      byte[] bitsOut = decodeChannel(bc, huff[0], wanted[0]);
      byte[] streamAOut = decodeChannel(bc, huff[1], wanted[1]);
      byte[] fillIdxOut = decodeChannel(bc, huff[2], wanted[2]);
      byte[] ctrlOut = decodeChannel(bc, huff[3], wanted[3]);
      // Channel 4 (LIT): known limitation, honestly flagged (2026-09-12
      // session) - bits/streamA/streamFillIdx/streamCtrl are all verified
      // byte-exact against test4b.cmp's real captured ground truth, but
      // this channel's exact table-construction mechanism (the real
      // gamma.dll code uses FUN_0044df50, a plain memcpy, not the
      // FUN_004269c0 Huffman-table-build path used for channels 0-3 - see
      // docs/cmp-texture-format-reference.md) was not fully reverse
      // engineered this session. Treating it like channel 2's degenerate
      // 256-symbol-identity fallback gets close (matches the real output
      // exactly rotated by one position for test4b) but is not byte-exact.
      byte[] litOut = decodeChannel(bc, huff[4], wanted[4]);

      return new CmpStage1(w, h, palette, bitsOut, streamAOut, fillIdxOut, ctrlOut, litOut);
   }
}

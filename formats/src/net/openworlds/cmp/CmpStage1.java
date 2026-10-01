package net.openworlds.cmp;

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
   // Width/height are not kept here: CmpFrames reads them from the header
   // (width = u16@8, height = u16@6, as gamma.dll's ScapePic reader).
   public final int[][] palette; // 256 entries, some possibly null
   public final byte[] bits;
   public final byte[] streamA;
   public final byte[] streamFillIdx;
   public final byte[] streamCtrl;
   public final byte[] streamLit;
   /**
    * Group header fields (FUN_00442bc0 reads them from the 16 bytes at the
    * group's start as puVar3[0], [6] and [7]): the row pairs this group
    * decodes (the outer count handed to FUN_00457d88), the byte size of
    * the next group of the same frame, and a word that must be 0 (with
    * its top bit also 0) or the frame fails with error 6.
    */
   public final int rowPairs;
   public final int nextGroupSize;
   public final int groupFlags;

   private CmpStage1(int[][] palette, byte[] bits,
                      byte[] streamA, byte[] streamFillIdx, byte[] streamCtrl, byte[] streamLit,
                      int rowPairs, int nextGroupSize, int groupFlags) {
      this.palette = palette;
      this.bits = bits;
      this.streamA = streamA;
      this.streamFillIdx = streamFillIdx;
      this.streamCtrl = streamCtrl;
      this.streamLit = streamLit;
      this.rowPairs = rowPairs;
      this.nextGroupSize = nextGroupSize;
      this.groupFlags = groupFlags;
   }

   // The 3 real fixed alphabet-permutation tables, extracted byte-exact from
   // gamma.dll (see docs/cmp-texture-format-reference.md "Stage 1 session").
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
         // A single-symbol alphabet needs 0 bits per code, not lengths[only]
         // (whatever nibble value the encoder happened to write - always 1 in
         // every real corpus occurrence, since sum<=1 here forces it) - there
         // is nothing to disambiguate with only one possible symbol. This was
         // invisible whenever the channel's own wanted-symbol count was too
         // small to ever trigger a byte reload either way (8/9 real corpus
         // occurrences of this exact case have wanted-count 1, where lengths
         // 0 and 1 produce byte-identical cursor state) but broke
         // vendside2.cmp, whose degenerate streamCtrl channel wants 63
         // symbols - decoding it with length 1 spuriously advances the
         // shared bit cursor by ~7 bytes it should never have consumed,
         // corrupting every following LIT symbol. See the matching
         // `reloadedDuringChannel` fix below for the other half of this bug
         // (the byte-realign amount before the next channel).
         for (int i = 0; i < 256; i++) {
            t.symbol[i] = only;
            t.length[i] = 0;
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
         }
      }
      // Length table is indexed by SYMBOL VALUE, not by lookup-window slot -
      // confirmed via live capture of gamma.dll's real table memory for
      // sball.cmp (2026-09-12 session, second pass): the length half of the
      // real 512-byte table object is nonzero only at symbol-value indices
      // (e.g. table[256+0x55]=4 for PERM0's first real symbol), never at
      // the many lookup slots that alias to that symbol. FUN_00426af0's
      // real disassembly confirms why: `mov bl,[ebx]` loads the symbol into
      // BL, the low byte of EBX - and since EBX is the 256-byte-aligned
      // table pointer OR'd with the lookup index, this MUTATES ebx's low
      // byte to the symbol value itself, so the immediately following
      // `mov cl,[ebx+0x100]` reads length[symbol], not length[lookupIndex].
      // This was invisible against test4b.cmp (whose real alphabets are
      // all either degenerate-to-1-symbol or small enough that slot==symbol
      // for the codes actually hit) but broke every real corpus file with
      // a richer alphabet - see decodeChannel below for the matching fix.
      System.arraycopy(lengths, 0, t.length, 0, 256);
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
      // Whether decodeChannel's per-symbol loop ever had to refill the
      // window from bc.src (i.e. consumed more than the 1 byte the initial
      // ensurePrimed prefetch already covers). A channel whose every symbol
      // costs 0 bits (the single-symbol-degenerate case above, when its
      // wanted-count is large enough to matter, e.g. vendside2.cmp's 63-
      // symbol streamCtrl) never touches its own prefetched 2nd byte at
      // all - so the standard "back up 1 byte" before the next channel's
      // byte-realign over-corrects by exactly 1 byte in that case. See use
      // below.
      boolean reloadedDuringChannel = false;
   }

   /** Skip n<=8 raw bits from the shared window without any table lookup. */
   private static void skipRawBits(BitCursor bc, int n) {
      if (n <= 0) return;
      int pos = bc.pos;
      int window = bc.window;
      int bitsAvail = bc.bitsAvail;
      int oldBits = bitsAvail;
      bitsAvail -= n;
      if (bitsAvail < 0) {
         window = (window << oldBits) & 0xFFFF;
         int newByte = bc.src[pos++] & 0xFF;
         window = (window & 0xFF00) | newByte;
         int missing = n - oldBits;
         bitsAvail += 8;
         window = (window << missing) & 0xFFFF;
      } else {
         window = (window << n) & 0xFFFF;
      }
      bc.pos = pos;
      bc.window = window;
      bc.bitsAvail = bitsAvail;
   }

   private static void ensurePrimed(BitCursor bc) {
      if (!bc.primed) {
         bc.window = ((bc.src[bc.pos] & 0xFF) << 8) | (bc.src[bc.pos + 1] & 0xFF);
         bc.pos += 2;
         bc.bitsAvail = 8;
         bc.primed = true;
      }
   }

   /** FUN_00426af0: the real bit-level Huffman decoder, direct 256-entry lookup, codes <=8 bits. */
   private static byte[] decodeChannel(BitCursor bc, HuffTable table, int wantedLen) {
      byte[] out = new byte[wantedLen];
      if (wantedLen == 0) return out;
      ensurePrimed(bc);
      bc.reloadedDuringChannel = false;
      int pos = bc.pos;
      int window = bc.window;
      int bitsAvail = bc.bitsAvail;
      for (int i = 0; i < wantedLen; i++) {
         int idx = (window >> 8) & 0xFF;
         int symbol = table.symbol[idx];
         int length = table.length[symbol & 0xFF];
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
            bc.reloadedDuringChannel = true;
         } else {
            window = (window << length) & 0xFFFF;
         }
      }
      bc.pos = pos;
      bc.window = window;
      bc.bitsAvail = bitsAvail;
      return out;
   }

   /**
    * One group of a .cmp/.mov read the way gamma.dll's ScapePic reader does
    * (FUN_00442750 / FUN_00442bc0): the table region is file[34..34+u16@28),
    * and for movies (mode bit 7) a frame table of 20-byte entries follows it
    * (u32 absolute group offset, u16 group size, u16 next frame, u16
    * reference frame or 0xFFFF, rest 0xFF). Stills have one group right
    * after the table region, size u16@30.
    */
   public static CmpStage1 decodeGroupAt(byte[] file, int groupOffset, int groupSize) throws IOException {
      int tableRegionSize = u16(file, 28);
      if (groupOffset < 34 + tableRegionSize || groupOffset + groupSize > file.length) {
         throw new IOException("group outside file (off=" + groupOffset + " size=" + groupSize + ")");
      }
      byte[] groupRegion = new byte[groupSize + 64];
      System.arraycopy(file, groupOffset, groupRegion, 0, groupSize);
      return decodeRegions(file, tableRegionSize, groupRegion);
   }

   /** Frame count as gamma.dll reads it: 1, or the u16 at the table cursor for movies. */
   public static int[][] frameTable(byte[] file) throws IOException {
      int mode = u8(file, 4);
      int tableRegionSize = u16(file, 28);
      if ((mode & 0x80) == 0) {
         return new int[][]{{34 + tableRegionSize, u16(file, 30), 0xFFFF, 0xFFFF}};
      }
      int frames = movieFrameCount(file);
      int[][] out = new int[frames][];
      int ft = 34 + tableRegionSize;
      for (int i = 0; i < frames; i++) {
         int o = ft + 20 * i;
         int off = (file[o] & 0xFF) | (file[o + 1] & 0xFF) << 8 | (file[o + 2] & 0xFF) << 16 | (file[o + 3] & 0xFF) << 24;
         out[i] = new int[]{off, u16(file, o + 4), u16(file, o + 6), u16(file, o + 8)};
      }
      return out;
   }

   private static int movieFrameCount(byte[] file) throws IOException {
      int mode = u8(file, 4);
      int flags = u8(file, 5);
      int b12 = u8(file, 12);
      int paletteCount = b12 != 0 ? b12 : 256;
      int byte13 = u8(file, 13);
      byte[] tableRegion = new byte[u16(file, 28)];
      System.arraycopy(file, 34, tableRegion, 0, tableRegion.length);
      BitReader br = new BitReader(tableRegion, 0);
      for (int i = 0; i < paletteCount * 18; i++) br.nextBit();
      int cursor = br.bytesConsumed;
      if ((mode & 0x02) == 0) cursor += paletteCount;
      // gamma.dll 0x442963..0x442983: (byte13*18+7)>>3 and then the palette
      // count as well (only kcl.mov, avatar wardrobe, has byte13 != 0)
      if (byte13 != 0) cursor += (byte13 * 18 + 7) / 8 + paletteCount;
      if ((flags & 0x01) != 0) cursor += (paletteCount / 2) + paletteCount - 1;
      if ((mode & 0x08) != 0) cursor += 4;
      return u16(file, 34 + cursor);
   }

   /** Shared .cmp/.mov Stage 1 core: header fields from file[0..33],
    * table region = file[34..34+tableRegionSize), first group decoded
    * from groupRegion[0..]. */
   private static CmpStage1 decodeRegions(byte[] cmp, int tableRegionSize, byte[] groupRegion) throws IOException {
      int mode = u8(cmp, 4);
      int flags = u8(cmp, 5);
      if ((flags & 0x80) == 0) throw new IOException("flags bit7 must be 1");
      if ((flags & 0x54) != 0) throw new IOException("flags bits 2/4/6 must be 0 (got 0x" + Integer.toHexString(flags) + ")");
      if (cmp[19] != 0) throw new IOException("header byte 19 must be 0");
      int[] byteLens = new int[5];
      for (int i = 0; i < 5; i++) byteLens[i] = u8(cmp, 14 + i);
      // Palette entry count: 0 means full 256 (verified: 154/159 stills;
      // other non-zero values, e.g. 0xEC in 5 stills, are literal counts).
      // .mov files carry 0xFF here AND parse 255 entries cleanly (table
      // cursor lands exactly on a valid groupCount; windr1.mov then
      // renders byte-exact) - so 0xFF is a genuine 255, not an alias
      // for 256 (forcing 256 desyncs the cursor: groupCount reads 0).
      // cbirda4.mov's unmapped-index-255 pixels are a separate,
      // file-specific matter (see .mov notes), not a count error.
      int b12 = u8(cmp, 12);
      int paletteCount = b12 != 0 ? b12 : 256;
      int byte13 = u8(cmp, 13);

      byte[] tableRegion = new byte[tableRegionSize];
      System.arraycopy(cmp, 34, tableRegion, 0, tableRegionSize);
      // groupRegion arrives pre-sliced (with read-ahead slack) from the
      // caller: the exact group of one frame-table entry (decodeGroupAt).
      // (The old +64 slack comment's rationale still applies: the shared
      // bit-window refill peeks 1-2 bytes ahead, per-channel realign backs
      // up, and LIT needs a couple of bytes past the true end.)

      // Embedded palette: FUN_004426b0, 6-bit RGB components (<<2 to 8-bit),
      // packed as 3 real bytes + 1 null spacer per entry, entries written
      // densely and sequentially (palette[i] = i-th entry read, no
      // permutation, no off-by-one). Verified two independent ways this
      // session: (1) manual bit-for-bit extraction against test4b.cmp's raw
      // file bytes matches this loop's output exactly; (2) direct index-for-
      // index comparison against sball.cmp's pre-existing, independently
      // hand-voted palette.txt matches on all 16 checkable entries with
      // plain identity indexing, no shift. (An earlier pass this session
      // mistakenly concluded a "+1" shift was needed, and separately the
      // final rendered pixels for test4b.cmp looked like they needed a
      // rotated palette - both were the SAME misdiagnosis: the real bug was
      // in the LIT channel's symbol decode below, not here. See that
      // channel's comment; with it fixed, this identity-indexed palette is
      // byte-exact end to end.)
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
      // gamma.dll 0x442963..0x442983: (byte13*18+7)>>3 and then the palette
      // count as well (only kcl.mov, avatar wardrobe, has byte13 != 0)
      if (byte13 != 0) cursor += (byte13 * 18 + 7) / 8 + paletteCount;
      if ((flags & 0x01) != 0) cursor += (paletteCount / 2) + paletteCount - 1;
      if ((mode & 0x08) != 0) cursor += 4;
      int groupCount;
      if ((mode & 0x80) != 0) {
         groupCount = u16(tableRegion, cursor);
         cursor += 14;
      } else {
         groupCount = 1;
      }
      if (groupCount < 1) {
         throw new IOException("groupCount=" + groupCount + " (<1 invalid)");
      }
      // groupCount > 1 = movie frames (.mov): only the first group (frame
      // 0) is decoded - subsequent groups are per-frame data for animation
      // over time, read through frameTable/decodeGroupAt by CmpFrames. .cmp enforces
      // exactly 1 via its header size checks in decode().

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

      // Channel transition mode - live-capture-verified (2026-09-12 session,
      // second pass) against test4b.cmp (flags=0x81, bit0=1) and sball.cmp
      // (flags=0x80, bit0=0): when flags bit0=1, each channel's decode
      // continues the previous channel's bit window exactly (mid-byte,
      // "primed" stays true - the original BitCursor model). When flags
      // bit0=0, the real gamma.dll caller instead re-primes with a 1-byte
      // backed-up, byte-realigned window before each subsequent channel
      // (bc.pos-=1; primed=false). Confirmed both ways: applying realign
      // to test4b (bit0=1) breaks ctrl/lit; NOT applying it to sball
      // (bit0=0) leaves streamA/fillIdx/ctrl 50-97% wrong.
      boolean realign = (flags & 0x01) == 0;
      BitCursor bc = new BitCursor();
      bc.src = groupRegion;
      bc.pos = 16; // right after the 16-byte group header
      byte[] bitsOut = decodeChannel(bc, huff[0], wanted[0]);
      if (realign) { bc.pos -= (bc.reloadedDuringChannel ? 1 : 2); bc.primed = false; }
      byte[] streamAOut = decodeChannel(bc, huff[1], wanted[1]);
      if (realign) { bc.pos -= (bc.reloadedDuringChannel ? 1 : 2); bc.primed = false; }
      byte[] fillIdxOut = decodeChannel(bc, huff[2], wanted[2]);
      if (realign) { bc.pos -= (bc.reloadedDuringChannel ? 1 : 2); bc.primed = false; }
      byte[] ctrlOut = decodeChannel(bc, huff[3], wanted[3]);
      if (realign) { bc.pos -= (bc.reloadedDuringChannel ? 1 : 2); bc.primed = false; }
      // Channel 4 (LIT): table construction traced fully via disassembly
      // (FUN_0044df50 is a plain memcpy of byteLen[4] raw bytes into a
      // scratch buffer, later lazily fed through the SAME
      // FUN_004269c0/FUN_00426930 canonical-Huffman-build path used for
      // channels 0-3, with permTablePtr=0 and alphabetSize=0 - i.e.
      // mechanically identical to channel 2's degenerate 256-identity
      // fallback, confirmed byte-for-byte against the real call site at
      // 0x442bc0/0x442bee).
      //
      // LIT always starts reading its real wanted[4] symbols at a byte
      // boundary: whatever bits are left in the shared window at LIT's
      // entry (`bc.bitsAvail` right after priming) must be skipped first.
      // This is a RAW bit-skip (skipRawBits), not "decode and discard
      // whole Huffman symbols via the table until enough bits are
      // consumed" - an earlier version of this fix did the latter and
      // broke on rkgrnd.cmp, whose real LIT alphabet has a genuinely
      // mixed code-length distribution ([5,0,0,0,0,0,0,5,246] symbols at
      // lengths 0/7/8): discarding by decoded-symbol-length can overshoot
      // the byte boundary (e.g. a 7-bit symbol then an 8-bit symbol
      // blows past an 8-bit target by 7 bits), silently eating real
      // wanted[4] data. A raw bit-skip has no such edge case. Verified
      // byte-exact against live-captured ground truth for 4 independent
      // real files spanning both flags-bit0 modes and both uniform and
      // mixed LIT code-length distributions: test4b.cmp (continue-mode,
      // target=2 bits), avdoor.cmp (realign-mode, uniform length-8,
      // target=8), sball.cmp (realign-mode, mixed lengths, target=8),
      // rkgrnd.cmp (realign-mode, mixed lengths, target=8 - the file
      // that exposed the bug). Root cause (why LIT specifically needs
      // byte alignment) still not pinned to a disassembly instruction,
      // but the empirical rule is exact and reproducible. This is a
      // SEPARATE, additional backup on top of the normal channel-transition
      // one just above (LIT needs 1 extra byte of backup beyond every other
      // channel, verified unconditionally across all 5 originally-fixed
      // files) - so it stays a plain, unconditional -1 here; the
      // reloadedDuringChannel adjustment for a fully zero-consumption
      // preceding channel (vendside2.cmp's degenerate 63-symbol streamCtrl)
      // is already applied once, on the transition above.
      if (realign) { bc.pos -= 1; bc.primed = false; }
      ensurePrimed(bc);
      skipRawBits(bc, bc.bitsAvail);
      byte[] litOut = decodeChannel(bc, huff[4], wanted[4]);

      return new CmpStage1(palette, bitsOut, streamAOut, fillIdxOut, ctrlOut, litOut,
         u16(groupRegion, 0), u16(groupRegion, 12), u16(groupRegion, 14));
   }
}

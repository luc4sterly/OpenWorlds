package net.freeworlds.bod;

import java.util.ArrayList;
import java.util.List;

/**
 * Parser for the .bod format - the real, compressed, network-transferred
 * articulated-avatar format (as opposed to .rwg, which turned out in an
 * earlier session to be a trivial local-only single-clump placeholder
 * format).
 *
 * This is NOT reverse-engineered from bytes or from gamma.dll - it is a
 * direct, careful translation of the OFFICIAL encoder source,
 * RWXTOBOD.PL (Worlds Inc., 1995-1999, found in the "gdk.zip" Gamma
 * Developer Kit - see worlds-chat-project.md for provenance). .bod has no
 * independent decoder anywhere (checked in an earlier session - Worlds
 * Inc. never shipped one; the only way to read a .bod was to feed it back
 * through the same client that plays it), so this parser's correctness is
 * verified structurally (every real .bod in the project's corpus parses
 * to completion, consuming every byte, with byte tables/limb tags/vertex
 * counts/triangle counts all self-consistent - see BodExtractMain) rather
 * than against an independent reference implementation.
 *
 * File layout:
 *   u8       version (always 1 in every real file seen)
 *   u8       numParts
 *   numParts x { u8 tag, u16le offset }   -- offset from the START of the
 *                                            part-data region (right after
 *                                            this table) to that part's
 *                                            root clump
 *   numParts x <clump>                     -- one recursive clump tree per
 *                                              part, in table order
 *
 * Clump (recursive):
 *   u8   tagByte           -- high bit set (0x80) => PLACEHOLDER: this
 *                              clump is JUST a transform stub (used to
 *                              re-attach a "part" at the correct place in
 *                              its parent's hierarchy) and has NO further
 *                              fields at all past the translation below -
 *                              not even a children count.
 *   u8   flag              -- bit7=hasUV, bit6=xPresent, bit5=yPresent,
 *                              bit4=zPresent; for non-placeholder clumps
 *                              with hasUV, bit3=vEqualsZ, bit2=vInvertY,
 *                              bit1=uEqualsX (quantization shortcuts that
 *                              drop redundant per-vertex byte columns)
 *   f3   xTranslation      -- only if xPresent
 *   f3   yTranslation      -- only if yPresent
 *   f3   zTranslation      -- only if zPresent
 *   -- placeholder clumps stop here --
 *   u8   r, g, b            -- clump color
 *   u16le numVerts
 *   if numVerts > 0:
 *     [if hasUV] f3 minV, f3 maxV
 *     f3 minY, f3 maxY
 *     f3 minZ, f3 maxZ
 *     f3 minX, f3 maxX
 *     [if hasUV] f3 minU, f3 maxU
 *     numVerts x u8   -- quantized X (always present)
 *     numVerts x u8   -- quantized Y (always present)
 *     numVerts x u8   -- quantized Z (always present)
 *     [if hasUV && !uEqualsX] numVerts x u8  -- quantized U
 *     [if hasUV && !(vEqualsZ || vInvertY)] numVerts x u8  -- quantized V
 *   u16le numTris
 *   if numTris > 0:
 *     triangle[0] = (0, 1, 2)  -- implicit, not stored
 *     then a bit-packed stream (LSB-first within each byte, continuous
 *     across the whole triangle list) encoding triangles 1..numTris-1 -
 *     see decodeTriangles().
 *   u8   numChildren
 *   numChildren x <clump>   -- recursively, same format. NOT present at
 *                               all for placeholder clumps (see above).
 *
 * f3 = a 3-byte float: the 4-byte IEEE-754 encoding with its least-
 * significant mantissa byte (byte 0 in little-endian) dropped, so
 * reconstruction is: read 3 bytes, prepend a 0x00 low byte, interpret as
 * a normal little-endian float.
 */
public final class BodParser {
    static boolean DEBUG = "1".equals(System.getenv("BOD_DEBUG"));
    private final byte[] data;
    private int pos;
    // Continuous LSB-first bit reader state for the triangle bitstream -
    // matches RWXTOBOD.PL's pushBits() exactly (nextPartialBit doubles
    // 1,2,4,...128 then wraps, consuming one byte from `data` on wrap).
    private int bitBuf;
    private int bitBufBitsLeft;

    private BodParser(byte[] data) {
        this.data = data;
    }

    public static BodFile parse(byte[] data) {
        BodParser p = new BodParser(data);
        return p.parseFile();
    }

    private BodFile parseFile() {
        int version = u8();
        int numParts = u8();
        int[] partTags = new int[numParts];
        int[] partOffsets = new int[numParts];
        for (int i = 0; i < numParts; i++) {
            partTags[i] = u8();
            partOffsets[i] = u16le();
        }
        int partDataStart = pos;
        List<BodClump> parts = new ArrayList<>(numParts);
        for (int i = 0; i < numParts; i++) {
            pos = partDataStart + partOffsets[i];
            BodClump clump = parseClump();
            if (clump.tag != partTags[i]) {
                throw new IllegalStateException("part " + i + ": table tag " + partTags[i]
                    + " != clump's own tag " + clump.tag);
            }
            parts.add(clump);
        }
        BodFile file = new BodFile();
        file.version = version;
        file.parts = parts;
        file.byteLength = data.length;
        file.consumedThroughOffset = pos;
        return file;
    }

    private BodClump parseClump() {
        int startPos = pos;
        int tagByte = u8();
        boolean placeholder = (tagByte & 0x80) != 0;
        int tag = tagByte & 0x7F;
        int flag = u8();
        if (DEBUG) System.err.println("clump@" + startPos + " tagByte=" + tagByte + " placeholder=" + placeholder + " tag=" + tag + " flag=0x" + Integer.toHexString(flag));
        float x = (flag & 0x40) != 0 ? f3() : 0f;
        float y = (flag & 0x20) != 0 ? f3() : 0f;
        float z = (flag & 0x10) != 0 ? f3() : 0f;

        BodClump c = new BodClump();
        c.tag = tag;
        c.placeholder = placeholder;
        c.tx = x;
        c.ty = y;
        c.tz = z;

        if (placeholder) {
            return c;
        }

        boolean hasUV = (flag & 0x80) != 0;
        boolean vEqualsZ = (flag & 0x08) != 0;
        boolean vInvertY = (flag & 0x04) != 0;
        boolean uEqualsX = (flag & 0x02) != 0;

        c.r = u8();
        c.g = u8();
        c.b = u8();

        int numVerts = u16le();
        if (DEBUG) System.err.println("  rgb=(" + c.r + "," + c.g + "," + c.b + ") numVerts=" + numVerts + " hasUV=" + hasUV);
        float minV = 0, maxV = 0, minY = 0, maxY = 0, minZ = 0, maxZ = 0, minX = 0, maxX = 0, minU = 0, maxU = 0;
        int[] qx = new int[0], qy = new int[0], qz = new int[0], qu = new int[0], qv = new int[0];
        if (numVerts > 0) {
            if (hasUV) {
                minV = f3();
                maxV = f3();
            }
            minY = f3();
            maxY = f3();
            minZ = f3();
            maxZ = f3();
            minX = f3();
            maxX = f3();
            if (hasUV) {
                minU = f3();
                maxU = f3();
            }
            qx = readQuantBytes(numVerts);
            qy = readQuantBytes(numVerts);
            qz = readQuantBytes(numVerts);
            boolean hasUCol = hasUV && !uEqualsX;
            boolean hasVCol = hasUV && !(vEqualsZ || vInvertY);
            qu = hasUCol ? readQuantBytes(numVerts) : new int[0];
            qv = hasVCol ? readQuantBytes(numVerts) : new int[0];
        }

        c.vertices = new ArrayList<>(numVerts);
        for (int i = 0; i < numVerts; i++) {
            float vx = dequant(qx[i], minX, maxX);
            float vy = dequant(qy[i], minY, maxY);
            float vz = dequant(qz[i], minZ, maxZ);
            float vu, vv;
            if (!hasUV) {
                vu = 0;
                vv = 0;
            } else {
                // uEqualsX/vEqualsZ/vInvertY are shortcuts the encoder takes
                // when U/V's QUANTIZED BYTE happens to closely match another
                // axis's quantized byte (checked in raw 0-255 byte space,
                // NOT float space - the two axes can have entirely different
                // min/max ranges). So decode must dequantize the OTHER
                // axis's byte using U/V's OWN min/max, not reuse the other
                // axis's already-dequantized float value directly.
                vu = uEqualsX ? dequant(qx[i], minU, maxU) : dequant(qu[i], minU, maxU);
                if (vEqualsZ) {
                    vv = dequant(qz[i], minV, maxV);
                } else if (vInvertY) {
                    vv = dequant(255 - qy[i], minV, maxV);
                } else {
                    vv = dequant(qv[i], minV, maxV);
                }
            }
            c.vertices.add(new BodVertex(vx, vy, vz, vu, vv));
        }

        int numTris = u16le();
        if (DEBUG) System.err.println("  numTris=" + numTris + " (bitstream starts at pos=" + pos + ")");
        c.triangles = new ArrayList<>(numTris);
        if (numTris > 0) {
            c.triangles.add(new int[]{0, 1, 2});
            resetBitReader();
            int highest = 2;
            for (int i = 1; i < numTris; i++) {
                int cap = highest + 4;
                int k = bitsFor(cap);
                int v1, v2, v3;
                while (true) {
                    int v1Delta = readBits(1);
                    if (v1Delta == 1) {
                        int v2Delta = readBits(k);
                        if (v2Delta == cap - 1) {
                            // escape: skip a vertex without emitting a triangle
                            highest++;
                            cap++;
                            k = bitsFor(cap);
                            continue;
                        }
                        v1 = highest + 1;
                        v2 = highest - v2Delta;
                        int v3Delta = readBits(k);
                        v3 = highest - v3Delta;
                    } else {
                        v1 = highest;
                        int v2Delta = readBits(k);
                        v2 = highest - v2Delta;
                        int v3Delta = readBits(k);
                        v3 = highest - v3Delta;
                    }
                    break;
                }
                // v2/v3 can legitimately reference a vertex ABOVE `highest`
                // (not just the one new vertex `v1` introduces) when a
                // triangle's other two corners aren't both already-seen -
                // the encoder stores (highest-v2) wrapped into 0..cap-1 by
                // adding cap when negative (RWXTOBOD.PL's pushBits does the
                // same for any negative value passed in), so decode must
                // undo that same single wrap. Found empirically: the
                // unwrapped version produced negative/out-of-range vertex
                // indices on real files; wrapping fixes 100% of the corpus.
                if (v2 < 0) v2 += cap;
                if (v3 < 0) v3 += cap;
                c.triangles.add(new int[]{v1, v2, v3});
                highest = Math.max(v1, Math.max(v2, v3));
                if (DEBUG && i <= 8) System.err.println("    tri[" + i + "]=(" + v1 + "," + v2 + "," + v3 + ") highest=" + highest);
            }
            alignBitReaderToByte();
        }

        if (DEBUG && numTris > 0) System.err.println("  tri bitstream ended at pos=" + pos);
        int numChildren = u8();
        if (DEBUG) System.err.println("  numChildren=" + numChildren + " (pos now " + pos + ")");
        c.children = new ArrayList<>(numChildren);
        for (int i = 0; i < numChildren; i++) {
            c.children.add(parseClump());
        }
        return c;
    }

    private static float dequant(int byteVal, float min, float max) {
        if (max == min) {
            return min;
        }
        return min + (max - min) * (byteVal / 255f);
    }

    private int[] readQuantBytes(int n) {
        int[] out = new int[n];
        for (int i = 0; i < n; i++) {
            out[i] = u8();
        }
        return out;
    }

    private static int bitsFor(int cap) {
        int k = 0;
        int bit = 1;
        while (bit < cap) {
            bit <<= 1;
            k++;
        }
        return k;
    }

    // --- continuous LSB-first bit reader, matching pushBits() ---
    private void resetBitReader() {
        bitBuf = 0;
        bitBufBitsLeft = 0;
    }

    private int readBits(int k) {
        int result = 0;
        for (int i = 0; i < k; i++) {
            if (bitBufBitsLeft == 0) {
                bitBuf = u8();
                bitBufBitsLeft = 8;
            }
            int bit = bitBuf & 1;
            bitBuf >>= 1;
            bitBufBitsLeft--;
            result |= (bit << i);
        }
        return result;
    }

    private void alignBitReaderToByte() {
        // pushBits(0, 128) at encode time flushes a final partial byte with
        // 7 padding bits if one was pending - if our reader has unconsumed
        // bits from the last byte read, that byte is fully spent (it held
        // real data followed by zero padding); nothing to do but drop the
        // partial state so the next u8()/f3() call starts a fresh byte.
        bitBuf = 0;
        bitBufBitsLeft = 0;
    }

    // --- primitive readers ---
    private int u8() {
        return data[pos++] & 0xFF;
    }

    private int u16le() {
        int lo = u8();
        int hi = u8();
        return lo | (hi << 8);
    }

    private float f3() {
        int b1 = u8();
        int b2 = u8();
        int b3 = u8();
        int bits = (b3 << 24) | (b2 << 16) | (b1 << 8); // byte0 (LSB mantissa) = 0
        return Float.intBitsToFloat(bits);
    }
}

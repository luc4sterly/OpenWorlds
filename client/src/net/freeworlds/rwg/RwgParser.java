package net.freeworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * Binary parser for .rwg (and, tentatively, the .bod container - NOT
 * verified, see below) built entirely from real-byte reverse engineering.
 * There is no known external reference implementation or public format
 * spec for this container (checked: aw-sequence-parser is unrelated, the
 * documented RenderWare Binary Stream format is little-endian/numeric-ID
 * and structurally different) - see docs/rwg-bod-format-reference.md for
 * the full evidence trail. Every field below that isn't backed by strong
 * evidence is preserved raw rather than guessed, and flagged in the model
 * classes' javadoc.
 *
 * Container: 4-byte ASCII magic "ZZZ[", then chunks of
 * [4-byte ASCII tag][4-byte big-endian length = payload size, NOT
 * including this length field][payload]. Verified self-consistent to the
 * exact byte against both real .rwg samples (AVATAR.RWG, IDLE.RWG).
 *
 * ⚠️ VERIFICAR: this parser only handles a single top-level ATOM (both
 * real samples have exactly one). Whether/how a real multi-joint avatar
 * nests several ATOMs was NOT possible to verify - no such sample was
 * found in the project's asset corpus. Do not treat this as a solved
 * "articulated avatar" parser; it's a verified single-clump geometry
 * reader.
 */
public final class RwgParser {
   private static final int MAGIC = 0x5A5A5A5B; // "ZZZ["

   private final byte[] data;
   private int pos;

   private RwgParser(byte[] data) {
      this.data = data;
   }

   public static RwgModel parse(byte[] data) {
      RwgParser p = new RwgParser(data);
      return p.parseFile();
   }

   private RwgModel parseFile() {
      int magic = readI32();
      if (magic != MAGIC) {
         throw new IllegalArgumentException(
            String.format("not a .rwg file: expected magic ZZZ[ (0x%08X), got 0x%08X", MAGIC, magic));
      }
      int headerLen = readI32();
      int headerEnd = pos + headerLen;
      // Header: 4 bytes constant (0x13765342), 4 bytes constant
      // (0x00000001), then a null-padded ASCII name string filling the
      // rest of the declared header length. Both constants are
      // ⚠️ VERIFICAR (unknown meaning, only ever observed at these fixed
      // values) - kept as a sanity check rather than silently skipped.
      int magic2 = readI32();
      int const1 = readI32();
      if (magic2 != 0x13765342 || const1 != 1) {
         throw new IllegalArgumentException(String.format(
            "unexpected .rwg header constants: 0x%08X / 0x%08X (expected 0x13765342 / 0x00000001) - format assumption may not hold",
            magic2, const1));
      }
      String name = readAsciiZ(headerEnd - pos);
      pos = headerEnd;

      String tag = readTag();
      if (!tag.equals("CLUM")) {
         throw new IllegalArgumentException("expected top-level CLUM chunk, found " + tag);
      }
      int clumLen = readI32();
      int clumEnd = pos + clumLen;

      byte[] raltRaw = null, teltRaw = null, maltRaw = null;
      RwgAtom atom = null;
      while (pos < clumEnd) {
         String childTag = readTag();
         int childLen = readI32();
         int childEnd = pos + childLen;
         switch (childTag) {
            case "RALT":
               raltRaw = readBytes(childLen);
               break;
            case "TELT":
               teltRaw = readBytes(childLen);
               break;
            case "MALT":
               maltRaw = readBytes(childLen);
               break;
            case "ATOM":
               atom = parseAtom(childEnd);
               break;
            default:
               // Unknown sibling chunk - skip but don't silently lose data shape info.
               pos = childEnd;
         }
         pos = childEnd;
      }
      pos = clumEnd;

      RwgModel model = new RwgModel(name, atom, raltRaw, teltRaw, maltRaw);
      if (atom == null) {
         model.warnings.add("no ATOM chunk found under CLUM - unexpected for every real sample seen so far");
      }
      return model;
   }

   private RwgAtom parseAtom(int atomEnd) {
      expectTag("STRT");
      int strtLen = readI32();
      if (strtLen != 52) {
         throw new IllegalArgumentException("ATOM STRT expected 52 bytes, got " + strtLen);
      }
      int[] headerRaw = new int[13];
      for (int i = 0; i < 13; i++) {
         headerRaw[i] = readI32();
      }

      float[] matrix1 = readMatx();
      float[] matrix2 = readMatx();

      List<RwgVertex> vertices = new ArrayList<>();
      List<RwgPolygon> polygons = new ArrayList<>();

      while (pos < atomEnd) {
         String tag = readTag();
         int len = readI32();
         int end = pos + len;
         if (tag.equals("VLST")) {
            vertices.addAll(parseVlst(end));
         } else if (tag.equals("PLST")) {
            polygons.addAll(parsePlst(end));
         }
         pos = end;
      }
      pos = atomEnd;

      return new RwgAtom(headerRaw, matrix1, matrix2, vertices, polygons);
   }

   private float[] readMatx() {
      expectTag("MATX");
      int matxLen = readI32();
      int matxEnd = pos + matxLen;
      expectTag("STRT");
      int strtLen = readI32();
      if (strtLen != 64) {
         throw new IllegalArgumentException("MATX STRT expected 64 bytes (16 floats), got " + strtLen);
      }
      float[] m = new float[16];
      for (int i = 0; i < 16; i++) {
         m[i] = readF32();
      }
      pos = matxEnd;
      return m;
   }

   private List<RwgVertex> parseVlst(int vlstEnd) {
      expectTag("STRT");
      int strtLen = readI32();
      if (strtLen != 12) {
         throw new IllegalArgumentException("VLST STRT expected 12 bytes, got " + strtLen);
      }
      int count = readI32();
      int bytesPerVertex = readI32();
      int trailingConst = readI32(); // ⚠️ VERIFICAR - always 23 (0x17) in every sample seen.
      if (bytesPerVertex != 44) {
         throw new IllegalArgumentException("VLST vertex record size expected 44 bytes, got " + bytesPerVertex);
      }
      List<RwgVertex> out = new ArrayList<>(count);
      for (int i = 0; i < count; i++) {
         float x = readF32(), y = readF32(), z = readF32();
         float u3 = readF32(), u4 = readF32(), u5 = readF32();
         float u = readF32(), v = readF32();
         float u8 = readF32(), u9 = readF32(), u10 = readF32();
         out.add(new RwgVertex(x, y, z, u3, u4, u5, u, v, u8, u9, u10));
      }
      int consumed = 12 + count * 44;
      if (pos != vlstEnd) {
         // Shouldn't happen given the verified byte-exact match on real samples - surface it loudly if it ever does.
         throw new IllegalArgumentException("VLST payload size mismatch: consumed " + consumed
            + " but chunk declared a different size (trailingConst=" + trailingConst + ")");
      }
      return out;
   }

   private List<RwgPolygon> parsePlst(int plstEnd) {
      expectTag("STRT");
      int strtLen = readI32();
      if (strtLen != 12) {
         throw new IllegalArgumentException("PLST STRT expected 12 bytes, got " + strtLen);
      }
      int polyCount = readI32();
      readI32(); // ⚠️ VERIFICAR - second STRT field, always 36 (0x24) in samples seen, meaning unresolved.
      readI32(); // ⚠️ VERIFICAR - always 23 (0x17) in every sample seen.

      List<RwgPolygon> out = new ArrayList<>(polyCount);
      if (polyCount == 0) {
         pos = plstEnd;
         return out;
      }

      // Verified against a real 6-face cube (assets/gammatutorial-samples/
      // cube.rwg) and IDLE.RWG's single quad: each polygon record is
      // [flag=1][vertexCount][vertexCount x 1-based vertex index][trailing
      // ints - the first 3 of which are consistently a face normal
      // (nx,ny,nz), one axis near +-1.0 matching the face's real
      // orientation, confirmed for all 6 cube faces]. Record size is NOT
      // fixed across files (12 ints in cube.rwg, 13 in IDLE.RWG) - the
      // trailing field count varies. Every real PLST seen so far has a
      // uniform vertexCount across all its polygons, so total record size
      // (in ints) can be derived as totalPayloadInts / polyCount and used
      // to size each record's trailing data - NOT verified against a PLST
      // with mixed vertex counts per polygon (no such sample exists in
      // the real corpus), which would break this assumption.
      int totalInts = (plstEnd - pos) / 4;
      if ((plstEnd - pos) % 4 != 0 || totalInts % polyCount != 0) {
         throw new IllegalArgumentException(
            "PLST payload (" + (plstEnd - pos) + " bytes) doesn't divide evenly across " + polyCount
               + " polygons - the uniform-record-size assumption doesn't hold for this file");
      }
      int intsPerRecord = totalInts / polyCount;

      for (int i = 0; i < polyCount; i++) {
         int flag = readI32(); // ⚠️ VERIFICAR - always 1 in every sample seen.
         int vertCount = readI32();
         int[] indices = new int[vertCount];
         for (int j = 0; j < vertCount; j++) {
            indices[j] = readI32() - 1; // file uses 1-based indices (RWX convention)
         }
         int trailingCount = intsPerRecord - 2 - vertCount;
         if (trailingCount < 0) {
            throw new IllegalArgumentException("PLST record " + i + ": vertexCount " + vertCount
               + " leaves no room for the derived record size " + intsPerRecord + " ints");
         }
         int[] trailing = new int[trailingCount];
         for (int j = 0; j < trailingCount; j++) {
            trailing[j] = readI32();
         }
         out.add(new RwgPolygon(indices, trailing));
      }
      pos = plstEnd;
      return out;
   }

   private void expectTag(String expected) {
      String tag = readTag();
      if (!tag.equals(expected)) {
         throw new IllegalArgumentException("expected " + expected + " chunk, found " + tag);
      }
   }

   private String readTag() {
      String s = new String(data, pos, 4, java.nio.charset.StandardCharsets.US_ASCII);
      pos += 4;
      return s;
   }

   private String readAsciiZ(int len) {
      int end = pos;
      int limit = pos + len;
      while (end < limit && data[end] != 0) {
         end++;
      }
      String s = new String(data, pos, end - pos, java.nio.charset.StandardCharsets.US_ASCII);
      return s;
   }

   private byte[] readBytes(int len) {
      byte[] out = new byte[len];
      System.arraycopy(data, pos, out, 0, len);
      pos += len;
      return out;
   }

   private int readI32() {
      int v = ((data[pos] & 0xFF) << 24) | ((data[pos + 1] & 0xFF) << 16)
         | ((data[pos + 2] & 0xFF) << 8) | (data[pos + 3] & 0xFF);
      pos += 4;
      return v;
   }

   private float readF32() {
      return Float.intBitsToFloat(readI32());
   }
}

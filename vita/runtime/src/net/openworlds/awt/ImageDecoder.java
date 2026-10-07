package net.openworlds.awt;

import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.util.zip.DataFormatException;
import java.util.zip.Inflater;

/**
 * Decodes the image files the 2004 client loads through Toolkit and the
 * bridge through ImageIO: GIF, JPEG (baseline), PNG and BMP, into ARGB
 * BufferedImages. Pure Java, so the same on a JVM and transpiled.
 */
public final class ImageDecoder {
   private ImageDecoder() {
   }

   /** The image, or null if the bytes are not one of these formats or are broken. */
   public static BufferedImage decode(byte[] d) {
      if (d == null || d.length < 8) {
         return null;
      }
      try {
         if (d[0] == 'G' && d[1] == 'I' && d[2] == 'F') {
            return gif(d);
         }
         if ((d[0] & 0xFF) == 0x89 && d[1] == 'P' && d[2] == 'N' && d[3] == 'G') {
            return png(d);
         }
         if ((d[0] & 0xFF) == 0xFF && (d[1] & 0xFF) == 0xD8) {
            return new JpegDecoder(d).decode();
         }
         if (d[0] == 'B' && d[1] == 'M') {
            return bmp(d);
         }
      } catch (RuntimeException e) {
         return null;
      }
      return null;
   }

   private static int u16le(byte[] d, int i) {
      return (d[i] & 0xFF) | ((d[i + 1] & 0xFF) << 8);
   }

   private static int s32le(byte[] d, int i) {
      return (d[i] & 0xFF) | ((d[i + 1] & 0xFF) << 8) | ((d[i + 2] & 0xFF) << 16) | ((d[i + 3] & 0xFF) << 24);
   }

   private static int s32be(byte[] d, int i) {
      return ((d[i] & 0xFF) << 24) | ((d[i + 1] & 0xFF) << 16) | ((d[i + 2] & 0xFF) << 8) | (d[i + 3] & 0xFF);
   }

   // ------------------------------------------------------------------ GIF

   /** The first frame of a GIF, over a transparent screen. */
   private static BufferedImage gif(byte[] d) {
      int sw = u16le(d, 6);
      int sh = u16le(d, 8);
      int flags = d[10] & 0xFF;
      int p = 13;
      int[] global = null;
      if ((flags & 0x80) != 0) {
         int n = 2 << (flags & 7);
         global = palette(d, p, n);
         p += 3 * n;
      }
      int transparent = -1;
      while (p < d.length) {
         int block = d[p++] & 0xFF;
         if (block == 0x21) {
            int label = d[p++] & 0xFF;
            if (label == 0xF9 && (d[p] & 0xFF) >= 4) {
               int gflags = d[p + 1] & 0xFF;
               if ((gflags & 1) != 0) {
                  transparent = d[p + 4] & 0xFF;
               }
            }
            while (p < d.length) {
               int len = d[p++] & 0xFF;
               if (len == 0) {
                  break;
               }
               p += len;
            }
         } else if (block == 0x2C) {
            int ix = u16le(d, p);
            int iy = u16le(d, p + 2);
            int iw = u16le(d, p + 4);
            int ih = u16le(d, p + 6);
            int iflags = d[p + 8] & 0xFF;
            p += 9;
            int[] pal = global;
            if ((iflags & 0x80) != 0) {
               int n = 2 << (iflags & 7);
               pal = palette(d, p, n);
               p += 3 * n;
            }
            if (pal == null) {
               pal = new int[256];
               for (int i = 0; i < 256; i++) {
                  pal[i] = 0xFF000000 | (i << 16) | (i << 8) | i;
               }
            }
            int minCode = d[p++] & 0xFF;
            ByteArrayOutputStream data = new ByteArrayOutputStream();
            while (p < d.length) {
               int len = d[p++] & 0xFF;
               if (len == 0) {
                  break;
               }
               data.write(d, p, Math.min(len, d.length - p));
               p += len;
            }
            byte[] indices = lzw(data.toByteArray(), minCode, iw * ih);
            if (sw <= 0 || sh <= 0) {
               sw = iw;
               sh = ih;
            }
            BufferedImage img = new BufferedImage(Math.max(1, sw), Math.max(1, sh), BufferedImage.TYPE_INT_ARGB);
            int[] out = img.intPixels();
            boolean interlaced = (iflags & 0x40) != 0;
            int[] rows = new int[ih];
            if (interlaced) {
               int k = 0;
               int[][] passes = {{0, 8}, {4, 8}, {2, 4}, {1, 2}};
               for (int[] pass : passes) {
                  for (int r = pass[0]; r < ih; r += pass[1]) {
                     rows[k++] = r;
                  }
               }
            } else {
               for (int r = 0; r < ih; r++) {
                  rows[r] = r;
               }
            }
            for (int r = 0; r < ih; r++) {
               int y = iy + rows[r];
               if (y < 0 || y >= sh) {
                  continue;
               }
               for (int c = 0; c < iw; c++) {
                  int x = ix + c;
                  if (x < 0 || x >= sw) {
                     continue;
                  }
                  int idx = indices[r * iw + c] & 0xFF;
                  if (idx == transparent || idx >= pal.length) {
                     continue;
                  }
                  out[y * sw + x] = pal[idx];
               }
            }
            return img;
         } else if (block == 0x3B) {
            break;
         } else {
            break;
         }
      }
      return null;
   }

   private static int[] palette(byte[] d, int p, int n) {
      int[] pal = new int[n];
      for (int i = 0; i < n && p + 2 < d.length; i++, p += 3) {
         pal[i] = 0xFF000000 | ((d[p] & 0xFF) << 16) | ((d[p + 1] & 0xFF) << 8) | (d[p + 2] & 0xFF);
      }
      return pal;
   }

   private static byte[] lzw(byte[] data, int minCode, int pixels) {
      byte[] out = new byte[pixels];
      int clear = 1 << minCode;
      int end = clear + 1;
      int[] prefix = new int[4096];
      byte[] suffix = new byte[4096];
      byte[] first = new byte[4096];
      int[] length = new int[4096];
      for (int i = 0; i < clear; i++) {
         suffix[i] = (byte) i;
         first[i] = (byte) i;
         length[i] = 1;
      }
      int codeSize = minCode + 1;
      int next = end + 1;
      int old = -1;
      int bits = 0;
      int bitCount = 0;
      int pos = 0;
      int outPos = 0;
      byte[] stack = new byte[4097];
      while (outPos < pixels) {
         while (bitCount < codeSize) {
            if (pos >= data.length) {
               return out;
            }
            bits |= (data[pos++] & 0xFF) << bitCount;
            bitCount += 8;
         }
         int code = bits & ((1 << codeSize) - 1);
         bits >>>= codeSize;
         bitCount -= codeSize;
         if (code == clear) {
            codeSize = minCode + 1;
            next = end + 1;
            old = -1;
            continue;
         }
         if (code == end) {
            break;
         }
         int emit;
         if (old == -1) {
            if (code >= clear) {
               break;
            }
            out[outPos++] = suffix[code];
            old = code;
            continue;
         }
         if (code < next) {
            emit = code;
            if (next < 4096) {
               prefix[next] = old;
               suffix[next] = first[code];
               first[next] = first[old];
               length[next] = length[old] + 1;
               next++;
            }
         } else {
            // KwKwK: the code being defined
            if (next < 4096) {
               prefix[next] = old;
               suffix[next] = first[old];
               first[next] = first[old];
               length[next] = length[old] + 1;
               emit = next;
               next++;
            } else {
               break;
            }
         }
         int len = length[emit];
         int c = emit;
         for (int i = len - 1; i >= 0; i--) {
            stack[i] = suffix[c];
            c = prefix[c];
         }
         for (int i = 0; i < len && outPos < pixels; i++) {
            out[outPos++] = stack[i];
         }
         old = code;
         if (next == (1 << codeSize) && codeSize < 12) {
            codeSize++;
         }
      }
      return out;
   }

   // ------------------------------------------------------------------ PNG

   private static BufferedImage png(byte[] d) throws RuntimeException {
      int p = 8;
      int w = 0, h = 0, depth = 0, type = 0, interlace = 0;
      int[] pal = null;
      byte[] trns = null;
      ByteArrayOutputStream idat = new ByteArrayOutputStream();
      while (p + 8 <= d.length) {
         int len = s32be(d, p);
         String t = new String(new char[]{(char) d[p + 4], (char) d[p + 5], (char) d[p + 6], (char) d[p + 7]});
         int body = p + 8;
         if (t.equals("IHDR")) {
            w = s32be(d, body);
            h = s32be(d, body + 4);
            depth = d[body + 8] & 0xFF;
            type = d[body + 9] & 0xFF;
            interlace = d[body + 12] & 0xFF;
         } else if (t.equals("PLTE")) {
            pal = new int[len / 3];
            for (int i = 0; i < pal.length; i++) {
               pal[i] = 0xFF000000 | ((d[body + 3 * i] & 0xFF) << 16) | ((d[body + 3 * i + 1] & 0xFF) << 8) | (d[body + 3 * i + 2] & 0xFF);
            }
         } else if (t.equals("tRNS")) {
            trns = new byte[len];
            System.arraycopy(d, body, trns, 0, len);
         } else if (t.equals("IDAT")) {
            idat.write(d, body, len);
         } else if (t.equals("IEND")) {
            break;
         }
         p = body + len + 4;
      }
      if (w <= 0 || h <= 0) {
         return null;
      }
      byte[] raw = inflate(idat.toByteArray());
      int channels;
      switch (type) {
         case 0:
            channels = 1;
            break;
         case 2:
            channels = 3;
            break;
         case 3:
            channels = 1;
            break;
         case 4:
            channels = 2;
            break;
         case 6:
            channels = 4;
            break;
         default:
            return null;
      }
      if (pal != null && trns != null && type == 3) {
         for (int i = 0; i < trns.length && i < pal.length; i++) {
            pal[i] = (pal[i] & 0x00FFFFFF) | ((trns[i] & 0xFF) << 24);
         }
      }
      BufferedImage img = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
      int[] out = img.intPixels();
      int bpp = Math.max(1, channels * depth / 8);
      int pos = 0;
      if (interlace == 0) {
         pos = unfilterPass(raw, pos, w, h, channels, depth, bpp, out, w, 0, 0, 1, 1, type, pal, trns);
      } else {
         int[][] adam = {{0, 0, 8, 8}, {4, 0, 8, 8}, {0, 4, 4, 8}, {2, 0, 4, 4}, {0, 2, 2, 4}, {1, 0, 2, 2}, {0, 1, 1, 2}};
         for (int[] a : adam) {
            int pw = (w - a[0] + a[2] - 1) / a[2];
            int ph = (h - a[1] + a[3] - 1) / a[3];
            if (pw > 0 && ph > 0) {
               pos = unfilterPass(raw, pos, pw, ph, channels, depth, bpp, out, w, a[0], a[1], a[2], a[3], type, pal, trns);
            }
         }
      }
      return img;
   }

   private static int unfilterPass(byte[] raw, int pos, int pw, int ph, int channels, int depth, int bpp, int[] out, int w, int x0, int y0, int dx,
         int dy, int type, int[] pal, byte[] trns) {
      int stride = (pw * channels * depth + 7) / 8;
      byte[] prev = new byte[stride];
      byte[] cur = new byte[stride];
      for (int row = 0; row < ph; row++) {
         int filter = raw[pos++] & 0xFF;
         System.arraycopy(raw, pos, cur, 0, stride);
         pos += stride;
         for (int i = 0; i < stride; i++) {
            int a = i >= bpp ? cur[i - bpp] & 0xFF : 0;
            int b = prev[i] & 0xFF;
            int c = i >= bpp ? prev[i - bpp] & 0xFF : 0;
            int v = cur[i] & 0xFF;
            switch (filter) {
               case 1:
                  v += a;
                  break;
               case 2:
                  v += b;
                  break;
               case 3:
                  v += (a + b) >> 1;
                  break;
               case 4: {
                  int pp = a + b - c;
                  int pa = Math.abs(pp - a);
                  int pb = Math.abs(pp - b);
                  int pc = Math.abs(pp - c);
                  v += (pa <= pb && pa <= pc) ? a : pb <= pc ? b : c;
                  break;
               }
               default:
            }
            cur[i] = (byte) v;
         }
         int y = y0 + row * dy;
         for (int col = 0; col < pw; col++) {
            int x = x0 + col * dx;
            out[y * w + x] = pngPixel(cur, col, channels, depth, type, pal, trns);
         }
         byte[] t = prev;
         prev = cur;
         cur = t;
      }
      return pos;
   }

   private static int sample(byte[] row, int index, int depth) {
      if (depth == 8) {
         return row[index] & 0xFF;
      }
      if (depth == 16) {
         return row[index * 2] & 0xFF;
      }
      int perByte = 8 / depth;
      int b = row[index / perByte] & 0xFF;
      int shift = 8 - depth * (index % perByte + 1);
      return (b >> shift) & ((1 << depth) - 1);
   }

   private static int pngPixel(byte[] row, int col, int channels, int depth, int type, int[] pal, byte[] trns) {
      switch (type) {
         case 3: {
            int i = sample(row, col, depth);
            return pal != null && i < pal.length ? pal[i] : 0;
         }
         case 0: {
            int g = sample(row, col, depth);
            int raw16 = depth == 16 ? ((row[col * 2] & 0xFF) << 8) | (row[col * 2 + 1] & 0xFF) : g;
            if (depth < 8) {
               g = g * 255 / ((1 << depth) - 1);
            }
            int a = 255;
            if (trns != null && trns.length >= 2 && raw16 == (((trns[0] & 0xFF) << 8) | (trns[1] & 0xFF))) {
               a = 0;
            }
            return (a << 24) | (g << 16) | (g << 8) | g;
         }
         case 2: {
            int r = sample(row, col * 3, depth);
            int g = sample(row, col * 3 + 1, depth);
            int b = sample(row, col * 3 + 2, depth);
            int a = 255;
            if (trns != null && trns.length >= 6 && depth == 8 && r == (trns[1] & 0xFF) && g == (trns[3] & 0xFF) && b == (trns[5] & 0xFF)) {
               a = 0;
            }
            return (a << 24) | (r << 16) | (g << 8) | b;
         }
         case 4: {
            int g = sample(row, col * 2, depth);
            int a = sample(row, col * 2 + 1, depth);
            return (a << 24) | (g << 16) | (g << 8) | g;
         }
         default: {
            int r = sample(row, col * 4, depth);
            int g = sample(row, col * 4 + 1, depth);
            int b = sample(row, col * 4 + 2, depth);
            int a = sample(row, col * 4 + 3, depth);
            return (a << 24) | (r << 16) | (g << 8) | b;
         }
      }
   }

   private static byte[] inflate(byte[] z) {
      Inflater inf = new Inflater();
      inf.setInput(z);
      ByteArrayOutputStream out = new ByteArrayOutputStream(z.length * 4);
      byte[] buf = new byte[65536];
      try {
         while (!inf.finished()) {
            int n = inf.inflate(buf);
            if (n == 0) {
               if (inf.needsInput() || inf.needsDictionary()) {
                  break;
               }
            }
            out.write(buf, 0, n);
         }
      } catch (DataFormatException e) {
         throw new IllegalArgumentException("broken PNG data");
      } finally {
         inf.end();
      }
      return out.toByteArray();
   }

   // ------------------------------------------------------------------ BMP

   private static BufferedImage bmp(byte[] d) {
      int dataOffset = s32le(d, 10);
      int headerSize = s32le(d, 14);
      int w;
      int h;
      int bpp;
      int compression = 0;
      int colors = 0;
      if (headerSize == 12) {
         w = u16le(d, 18);
         h = (short) u16le(d, 20);
         bpp = u16le(d, 24);
      } else {
         w = s32le(d, 18);
         h = s32le(d, 22);
         bpp = u16le(d, 28);
         compression = s32le(d, 30);
         colors = s32le(d, 46);
      }
      boolean topDown = h < 0;
      h = Math.abs(h);
      if (w <= 0 || h <= 0) {
         return null;
      }
      int[] pal = null;
      if (bpp <= 8) {
         int n = colors != 0 ? colors : 1 << bpp;
         int entry = headerSize == 12 ? 3 : 4;
         pal = new int[n];
         int p = 14 + headerSize;
         for (int i = 0; i < n; i++, p += entry) {
            pal[i] = 0xFF000000 | ((d[p + 2] & 0xFF) << 16) | ((d[p + 1] & 0xFF) << 8) | (d[p] & 0xFF);
         }
      }
      int rmask = 0x7C00, gmask = 0x03E0, bmask = 0x001F;
      if (compression == 3 && headerSize >= 40) {
         int m = 14 + 40;
         rmask = s32le(d, m);
         gmask = s32le(d, m + 4);
         bmask = s32le(d, m + 8);
      }
      if (compression != 0 && compression != 3) {
         return null;
      }
      BufferedImage img = new BufferedImage(w, h, BufferedImage.TYPE_INT_RGB);
      int[] out = img.intPixels();
      int stride = ((w * bpp + 31) / 32) * 4;
      for (int row = 0; row < h; row++) {
         int y = topDown ? row : h - 1 - row;
         int p = dataOffset + row * stride;
         for (int x = 0; x < w; x++) {
            int c;
            switch (bpp) {
               case 1:
                  c = pal[((d[p + x / 8] & 0xFF) >> (7 - x % 8)) & 1];
                  break;
               case 4:
                  c = pal[((d[p + x / 2] & 0xFF) >> (x % 2 == 0 ? 4 : 0)) & 0xF];
                  break;
               case 8:
                  c = pal[d[p + x] & 0xFF];
                  break;
               case 16: {
                  int v = u16le(d, p + x * 2);
                  c = 0xFF000000 | (scale(v, rmask) << 16) | (scale(v, gmask) << 8) | scale(v, bmask);
                  break;
               }
               case 24:
                  c = 0xFF000000 | ((d[p + x * 3 + 2] & 0xFF) << 16) | ((d[p + x * 3 + 1] & 0xFF) << 8) | (d[p + x * 3] & 0xFF);
                  break;
               case 32:
                  c = 0xFF000000 | ((d[p + x * 4 + 2] & 0xFF) << 16) | ((d[p + x * 4 + 1] & 0xFF) << 8) | (d[p + x * 4] & 0xFF);
                  break;
               default:
                  return null;
            }
            out[y * w + x] = c;
         }
      }
      return img;
   }

   private static int scale(int v, int mask) {
      if (mask == 0) {
         return 0;
      }
      int shift = Integer.numberOfTrailingZeros(mask);
      int bits = Integer.bitCount(mask);
      int c = (v & mask) >>> shift;
      return bits >= 8 ? c >> (bits - 8) : (c * 255 + ((1 << bits) - 1) / 2) / ((1 << bits) - 1);
   }
}

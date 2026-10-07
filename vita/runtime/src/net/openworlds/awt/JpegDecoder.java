package net.openworlds.awt;

import java.awt.image.BufferedImage;

/**
 * Baseline JPEG (sequential Huffman, 8-bit, 1 or 3 components with any
 * sampling, restart markers). Progressive files are refused (null image).
 */
final class JpegDecoder {
   private static final int[] ZIGZAG = {0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 32, 25, 18, 11, 4, 5, 12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13, 6, 7,
         14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55,
         62, 63};

   private final byte[] d;
   private int pos;
   private final int[][] quant = new int[4][64];
   private final Huffman[] dcTables = new Huffman[4];
   private final Huffman[] acTables = new Huffman[4];
   private int width;
   private int height;
   private Component[] components;
   private int restartInterval;
   private int hmax = 1;
   private int vmax = 1;
   private boolean adobeRgb;

   private static final class Component {
      int id;
      int h;
      int v;
      int tq;
      int td;
      int ta;
      int pred;
      int blocksW;
      int blocksH;
      byte[] plane;
      int stride;
   }

   private static final class Huffman {
      final int[] maxCode = new int[18];
      final int[] valPtr = new int[17];
      final int[] minCode = new int[17];
      final int[] values;
      /** Fast lookup: 9 bits → (length << 8) | value, or 0. */
      final int[] fast = new int[512];

      Huffman(int[] counts, int[] values) {
         this.values = values;
         int code = 0;
         int k = 0;
         for (int len = 1; len <= 16; len++) {
            valPtr[len] = k;
            minCode[len] = code;
            code += counts[len];
            k += counts[len];
            maxCode[len] = counts[len] > 0 ? code - 1 : -1;
            code <<= 1;
         }
         maxCode[17] = Integer.MAX_VALUE;
         code = 0;
         k = 0;
         for (int len = 1; len <= 9; len++) {
            for (int i = 0; i < counts[len]; i++, k++, code++) {
               int shift = 9 - len;
               for (int j = 0; j < (1 << shift); j++) {
                  fast[(code << shift) | j] = (len << 8) | values[k];
               }
            }
            code <<= 1;
         }
      }
   }

   JpegDecoder(byte[] d) {
      this.d = d;
   }

   private int u8() {
      return d[pos++] & 0xFF;
   }

   private int u16() {
      int v = ((d[pos] & 0xFF) << 8) | (d[pos + 1] & 0xFF);
      pos += 2;
      return v;
   }

   BufferedImage decode() {
      pos = 2;
      while (pos < d.length) {
         if ((d[pos] & 0xFF) != 0xFF) {
            pos++;
            continue;
         }
         int marker = d[pos + 1] & 0xFF;
         pos += 2;
         if (marker == 0xD8 || (marker >= 0xD0 && marker <= 0xD7) || marker == 0x01 || marker == 0xFF) {
            if (marker == 0xFF) {
               pos--;
            }
            continue;
         }
         if (marker == 0xD9) {
            break;
         }
         int len = u16();
         int end = pos + len - 2;
         switch (marker) {
            case 0xDB:
               while (pos < end) {
                  int pq = u8();
                  int t = pq & 3;
                  boolean wide = (pq >> 4) != 0;
                  for (int i = 0; i < 64; i++) {
                     quant[t][ZIGZAG[i]] = wide ? u16() : u8();
                  }
               }
               break;
            case 0xC4:
               while (pos < end) {
                  int tc = u8();
                  int[] counts = new int[17];
                  int total = 0;
                  for (int i = 1; i <= 16; i++) {
                     counts[i] = u8();
                     total += counts[i];
                  }
                  int[] values = new int[total];
                  for (int i = 0; i < total; i++) {
                     values[i] = u8();
                  }
                  Huffman table = new Huffman(counts, values);
                  if ((tc >> 4) == 0) {
                     dcTables[tc & 3] = table;
                  } else {
                     acTables[tc & 3] = table;
                  }
               }
               break;
            case 0xC0:
            case 0xC1: {
               u8();
               height = u16();
               width = u16();
               int n = u8();
               components = new Component[n];
               for (int i = 0; i < n; i++) {
                  Component c = new Component();
                  c.id = u8();
                  int hv = u8();
                  c.h = Math.max(1, hv >> 4);
                  c.v = Math.max(1, hv & 15);
                  c.tq = u8() & 3;
                  hmax = Math.max(hmax, c.h);
                  vmax = Math.max(vmax, c.v);
                  components[i] = c;
               }
               break;
            }
            case 0xC2:
            case 0xC3:
            case 0xC5:
            case 0xC6:
            case 0xC7:
            case 0xC9:
            case 0xCA:
            case 0xCB:
            case 0xCD:
            case 0xCE:
            case 0xCF:
               return null;
            case 0xDD:
               restartInterval = u16();
               break;
            case 0xEE:
               if (len >= 12 && d[pos] == 'A' && d[pos + 1] == 'd' && d[pos + 2] == 'o' && d[pos + 3] == 'b' && d[pos + 4] == 'e') {
                  adobeRgb = (d[pos + 11] & 0xFF) == 0;
               }
               break;
            case 0xDA:
               scan();
               return toImage();
            default:
         }
         pos = end;
      }
      return null;
   }

   private int bitBuf;
   private int bitCnt;
   private boolean hitMarker;

   private void scan() {
      int n = u8();
      Component[] scomp = new Component[n];
      for (int i = 0; i < n; i++) {
         int id = u8();
         int t = u8();
         for (Component c : components) {
            if (c.id == id) {
               c.td = t >> 4;
               c.ta = t & 15;
               scomp[i] = c;
            }
         }
      }
      pos += 3;
      int mcuW = 8 * hmax;
      int mcuH = 8 * vmax;
      int mcusX = (width + mcuW - 1) / mcuW;
      int mcusY = (height + mcuH - 1) / mcuH;
      for (Component c : components) {
         c.blocksW = mcusX * c.h;
         c.blocksH = mcusY * c.v;
         c.stride = c.blocksW * 8;
         c.plane = new byte[c.stride * c.blocksH * 8];
      }
      int[] block = new int[64];
      int total = mcusX * mcusY;
      int todo = restartInterval > 0 ? restartInterval : total;
      int mcu = 0;
      bitBuf = 0;
      bitCnt = 0;
      while (mcu < total) {
         for (int r = 0; r < todo && mcu < total; r++, mcu++) {
            int mx = mcu % mcusX;
            int my = mcu / mcusX;
            for (Component c : scomp) {
               if (c == null) {
                  continue;
               }
               for (int by = 0; by < c.v; by++) {
                  for (int bx = 0; bx < c.h; bx++) {
                     decodeBlock(c, block);
                     idct(block, c, (mx * c.h + bx) * 8, (my * c.v + by) * 8);
                  }
               }
            }
         }
         // restart marker
         bitBuf = 0;
         bitCnt = 0;
         hitMarker = false;
         for (Component c : components) {
            c.pred = 0;
         }
         while (pos + 1 < d.length && !((d[pos] & 0xFF) == 0xFF && (d[pos + 1] & 0xFF) >= 0xD0 && (d[pos + 1] & 0xFF) <= 0xD7)) {
            if ((d[pos] & 0xFF) == 0xFF && (d[pos + 1] & 0xFF) != 0 && (d[pos + 1] & 0xFF) != 0xFF) {
               break;
            }
            pos++;
         }
         if (pos + 1 < d.length && (d[pos] & 0xFF) == 0xFF && (d[pos + 1] & 0xFF) >= 0xD0 && (d[pos + 1] & 0xFF) <= 0xD7) {
            pos += 2;
         }
      }
   }

   private int bit() {
      if (bitCnt == 0) {
         fill();
      }
      bitCnt--;
      return (bitBuf >>> bitCnt) & 1;
   }

   private void fill() {
      int b = 0;
      if (!hitMarker && pos < d.length) {
         b = d[pos] & 0xFF;
         if (b == 0xFF) {
            int next = pos + 1 < d.length ? d[pos + 1] & 0xFF : 0;
            if (next == 0) {
               pos += 2;
            } else {
               hitMarker = true;
               b = 0;
            }
         } else {
            pos++;
         }
      }
      bitBuf = (bitBuf << 8) | b;
      bitCnt += 8;
   }

   private int bits(int n) {
      int v = 0;
      for (int i = 0; i < n; i++) {
         v = (v << 1) | bit();
      }
      return v;
   }

   private int huff(Huffman h) {
      while (bitCnt < 9) {
         fill();
      }
      int look = (bitBuf >>> (bitCnt - 9)) & 511;
      int f = h.fast[look];
      if (f != 0) {
         bitCnt -= f >> 8;
         return f & 0xFF;
      }
      int code = 0;
      for (int len = 1; len <= 16; len++) {
         code = (code << 1) | bit();
         if (code <= h.maxCode[len]) {
            return h.values[h.valPtr[len] + code - h.minCode[len]];
         }
      }
      return 0;
   }

   private static int extend(int v, int t) {
      return t == 0 ? 0 : v < (1 << (t - 1)) ? v - (1 << t) + 1 : v;
   }

   private void decodeBlock(Component c, int[] block) {
      java.util.Arrays.fill(block, 0);
      Huffman dc = dcTables[c.td];
      Huffman ac = acTables[c.ta];
      int t = dc == null ? 0 : huff(dc);
      int diff = t == 0 ? 0 : extend(bits(t), t);
      c.pred += diff;
      int[] q = quant[c.tq];
      block[0] = c.pred * q[0];
      for (int k = 1; k < 64; ) {
         int rs = ac == null ? 0 : huff(ac);
         int s = rs & 15;
         int r = rs >> 4;
         if (s == 0) {
            if (r != 15) {
               break;
            }
            k += 16;
            continue;
         }
         k += r;
         if (k > 63) {
            break;
         }
         int z = ZIGZAG[k];
         block[z] = extend(bits(s), s) * q[z];
         k++;
      }
   }

   private static final float[][] COS = new float[8][8];

   static {
      for (int x = 0; x < 8; x++) {
         for (int u = 0; u < 8; u++) {
            double cu = u == 0 ? Math.sqrt(0.5) : 1.0;
            COS[x][u] = (float) (cu * Math.cos((2 * x + 1) * u * Math.PI / 16) / 2);
         }
      }
   }

   private final float[] tmp = new float[64];

   private void idct(int[] block, Component c, int px, int py) {
      for (int y = 0; y < 8; y++) {
         for (int u = 0; u < 8; u++) {
            float s = 0;
            for (int v = 0; v < 8; v++) {
               s += COS[y][v] * block[v * 8 + u];
            }
            tmp[y * 8 + u] = s;
         }
      }
      for (int y = 0; y < 8; y++) {
         int row = (py + y) * c.stride + px;
         for (int x = 0; x < 8; x++) {
            float s = 0;
            for (int u = 0; u < 8; u++) {
               s += COS[x][u] * tmp[y * 8 + u];
            }
            int v = Math.round(s + 128);
            c.plane[row + x] = (byte) (v < 0 ? 0 : v > 255 ? 255 : v);
         }
      }
   }

   private BufferedImage toImage() {
      if (width <= 0 || height <= 0 || components == null) {
         return null;
      }
      BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
      int[] out = img.intPixels();
      int n = components.length;
      for (int y = 0; y < height; y++) {
         for (int x = 0; x < width; x++) {
            if (n >= 3) {
               int yy = sampleAt(components[0], x, y);
               int cb = sampleAt(components[1], x, y);
               int cr = sampleAt(components[2], x, y);
               int r;
               int g;
               int b;
               if (adobeRgb) {
                  r = yy;
                  g = cb;
                  b = cr;
               } else {
                  r = clamp(yy + 1.402f * (cr - 128));
                  g = clamp(yy - 0.344136f * (cb - 128) - 0.714136f * (cr - 128));
                  b = clamp(yy + 1.772f * (cb - 128));
               }
               out[y * width + x] = 0xFF000000 | (r << 16) | (g << 8) | b;
            } else {
               int v = sampleAt(components[0], x, y);
               out[y * width + x] = 0xFF000000 | (v << 16) | (v << 8) | v;
            }
         }
      }
      return img;
   }

   private int sampleAt(Component c, int x, int y) {
      int sx = x * c.h / hmax;
      int sy = y * c.v / vmax;
      return c.plane[sy * c.stride + sx] & 0xFF;
   }

   private static int clamp(float v) {
      int i = Math.round(v);
      return i < 0 ? 0 : i > 255 ? 255 : i;
   }
}

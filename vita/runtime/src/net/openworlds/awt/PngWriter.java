package net.openworlds.awt;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.zip.CRC32;
import java.util.zip.Deflater;

/** PNG files (8-bit RGB or RGBA, no filter) with java.util.zip only. */
public final class PngWriter {
   private PngWriter() {
   }

   /** Writes w * h ARGB pixels; with alpha, as RGBA, else RGB. */
   public static void write(int[] argb, int w, int h, boolean alpha, OutputStream os) throws IOException {
      DataOutputStream out = new DataOutputStream(os);
      out.write(new byte[]{(byte) 0x89, 'P', 'N', 'G', '\r', '\n', 0x1A, '\n'});
      ByteArrayOutputStream ihdr = new ByteArrayOutputStream();
      DataOutputStream d = new DataOutputStream(ihdr);
      d.writeInt(w);
      d.writeInt(h);
      d.writeByte(8);
      d.writeByte(alpha ? 6 : 2);
      d.writeByte(0);
      d.writeByte(0);
      d.writeByte(0);
      chunk(out, "IHDR", ihdr.toByteArray());
      int channels = alpha ? 4 : 3;
      byte[] raw = new byte[h * (1 + w * channels)];
      int k = 0;
      for (int y = 0; y < h; y++) {
         raw[k++] = 0;
         for (int x = 0; x < w; x++) {
            int p = argb[y * w + x];
            raw[k++] = (byte) (p >> 16);
            raw[k++] = (byte) (p >> 8);
            raw[k++] = (byte) p;
            if (alpha) {
               raw[k++] = (byte) (p >>> 24);
            }
         }
      }
      Deflater def = new Deflater();
      def.setInput(raw);
      def.finish();
      ByteArrayOutputStream z = new ByteArrayOutputStream();
      byte[] buf = new byte[65536];
      while (!def.finished()) {
         int n = def.deflate(buf);
         z.write(buf, 0, n);
      }
      def.end();
      chunk(out, "IDAT", z.toByteArray());
      chunk(out, "IEND", new byte[0]);
      out.flush();
   }

   private static void chunk(DataOutputStream out, String type, byte[] data) throws IOException {
      out.writeInt(data.length);
      byte[] t = type.getBytes("US-ASCII");
      out.write(t);
      out.write(data);
      CRC32 crc = new CRC32();
      crc.update(t);
      crc.update(data);
      out.writeInt((int) crc.getValue());
   }
}

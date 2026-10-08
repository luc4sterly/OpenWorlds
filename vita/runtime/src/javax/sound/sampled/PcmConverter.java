package javax.sound.sampled;

import java.io.IOException;
import java.io.InputStream;

/**
 * The format conversions the bridge asks for, to 16-bit signed PCM at the
 * same rate, with the JDK's arithmetic (measured against it sample by
 * sample: every 8-bit and 24-bit value, millions of 32-bit and stereo
 * ones). Integer PCM goes through a float as the JDK's float converter
 * does: x / 2^(n-1) when negative, x / (2^(n-1) - 1) otherwise, and back
 * with f * 32768 or f * 32767 truncated; stereo to mono is the mean of the
 * two channels, mono to stereo copies it. u-law and A-law are the G.711
 * tables (same channels only, as the JDK). A different sample rate, other
 * channel counts and other target formats are not converted.
 */
final class PcmConverter extends InputStream {
   private static final int PCM = 0;
   private static final int FLOAT = 1;
   private static final int ULAW = 2;
   private static final int ALAW = 3;

   private final AudioInputStream src;
   private final int kind;
   private final int bytes;
   private final boolean signed;
   private final boolean srcBigEndian;
   private final int srcChannels;
   private final int srcFrameSize;
   private final int dstChannels;
   private final int dstFrameSize;
   private final boolean dstBigEndian;
   private final float negScale;
   private final float posScale;
   private byte[] buf = new byte[0];
   private final byte[] one;
   private int onePos;
   private int oneLen;

   private PcmConverter(AudioInputStream src, AudioFormat target) {
      this.src = src;
      AudioFormat f = src.getFormat();
      AudioFormat.Encoding e = f.getEncoding();
      kind = e.equals(AudioFormat.Encoding.PCM_FLOAT) ? FLOAT : e.equals(AudioFormat.Encoding.ULAW) ? ULAW : e.equals(AudioFormat.Encoding.ALAW) ? ALAW : PCM;
      bytes = f.getSampleSizeInBits() / 8;
      signed = !e.equals(AudioFormat.Encoding.PCM_UNSIGNED);
      srcBigEndian = f.isBigEndian();
      srcChannels = f.getChannels();
      srcFrameSize = f.getFrameSize();
      dstChannels = channels(target, f);
      dstFrameSize = 2 * dstChannels;
      dstBigEndian = target.isBigEndian();
      int bits = f.getSampleSizeInBits();
      negScale = (float) (1L << (bits - 1));
      posScale = (float) ((1L << (bits - 1)) - 1);
      one = new byte[dstFrameSize];
   }

   private static int channels(AudioFormat target, AudioFormat source) {
      return target.getChannels() == AudioSystem.NOT_SPECIFIED ? source.getChannels() : target.getChannels();
   }

   /** The format the converted stream has: the target with what it leaves unspecified taken from the source. */
   static AudioFormat resultFormat(AudioFormat target, AudioFormat source) {
      int ch = channels(target, source);
      return new AudioFormat(AudioFormat.Encoding.PCM_SIGNED, source.getSampleRate(), 16, ch, 2 * ch, source.getSampleRate(), target.isBigEndian());
   }

   static boolean supports(AudioFormat target, AudioFormat source) {
      AudioFormat.Encoding e = source.getEncoding();
      int bits = source.getSampleSizeInBits();
      int ch = source.getChannels();
      boolean law = e.equals(AudioFormat.Encoding.ULAW) || e.equals(AudioFormat.Encoding.ALAW);
      boolean pcm = e.equals(AudioFormat.Encoding.PCM_SIGNED) || e.equals(AudioFormat.Encoding.PCM_UNSIGNED);
      boolean flt = e.equals(AudioFormat.Encoding.PCM_FLOAT);
      if (ch < 1 || source.getSampleRate() == AudioSystem.NOT_SPECIFIED) {
         return false;
      }
      if (law ? bits != 8 : pcm ? bits != 8 && bits != 16 && bits != 24 && bits != 32 : !flt || bits != 32) {
         return false;
      }
      if (source.getFrameSize() != bits / 8 * ch) {
         return false;
      }
      if (!target.getEncoding().equals(AudioFormat.Encoding.PCM_SIGNED) || target.getSampleSizeInBits() != 16) {
         return false;
      }
      if (target.getSampleRate() != AudioSystem.NOT_SPECIFIED && target.getSampleRate() != source.getSampleRate()) {
         return false;
      }
      if (target.getFrameRate() != AudioSystem.NOT_SPECIFIED && target.getFrameRate() != source.getSampleRate()) {
         return false;
      }
      int tch = channels(target, source);
      if (target.getFrameSize() != AudioSystem.NOT_SPECIFIED && target.getFrameSize() != 2 * tch) {
         return false;
      }
      return tch == ch || !law && (tch == 1 && ch == 2 || tch == 2 && ch == 1);
   }

   static AudioInputStream convert(AudioFormat target, AudioInputStream src) {
      AudioFormat f = resultFormat(target, src.getFormat());
      return new AudioInputStream(new PcmConverter(src, f), f, src.getFrameLength());
   }

   public int read() throws IOException {
      if (onePos >= oneLen) {
         oneLen = read(one, 0, one.length);
         onePos = 0;
         if (oneLen <= 0) {
            return -1;
         }
      }
      return one[onePos++] & 0xFF;
   }

   public int read(byte[] b, int off, int len) throws IOException {
      int done = 0;
      while (onePos < oneLen && len > 0) {
         b[off++] = one[onePos++];
         len--;
         done++;
      }
      int frames = len / dstFrameSize;
      if (frames == 0) {
         return done;
      }
      int need = frames * srcFrameSize;
      if (buf.length < need) {
         buf = new byte[need];
      }
      int n = src.read(buf, 0, need);
      if (n < 0) {
         return done > 0 ? done : -1;
      }
      int got = n / srcFrameSize;
      float[] fr = new float[srcChannels];
      int o = off;
      for (int i = 0; i < got; i++) {
         int p = i * srcFrameSize;
         if (kind == ULAW || kind == ALAW) {
            for (int c = 0; c < srcChannels; c++) {
               int v = kind == ULAW ? ulaw(buf[p + c]) : alaw(buf[p + c]);
               o = put(b, o, v);
            }
            continue;
         }
         for (int c = 0; c < srcChannels; c++) {
            fr[c] = sample(buf, p + c * bytes);
         }
         if (dstChannels == srcChannels) {
            for (int c = 0; c < srcChannels; c++) {
               o = put(b, o, to16(fr[c]));
            }
         } else if (dstChannels == 1) {
            o = put(b, o, to16((fr[0] + fr[1]) * 0.5f));
         } else {
            int v = to16(fr[0]);
            o = put(b, o, v);
            o = put(b, o, v);
         }
      }
      return done + got * dstFrameSize;
   }

   private float sample(byte[] d, int p) {
      int x = 0;
      for (int k = 0; k < bytes; k++) {
         int v = d[p + (srcBigEndian ? k : bytes - 1 - k)] & 0xFF;
         x = (x << 8) | v;
      }
      if (kind == FLOAT) {
         return Float.intBitsToFloat(x);
      }
      int shift = 32 - 8 * bytes;
      if (signed) {
         x = (x << shift) >> shift;
      } else {
         x = x - (1 << (8 * bytes - 1));
      }
      return x < 0 ? x / negScale : x / posScale;
   }

   private static int to16(float f) {
      return (short) (int) (f < 0 ? f * 32768f : f * 32767f);
   }

   private int put(byte[] b, int o, int v) {
      if (dstBigEndian) {
         b[o] = (byte) (v >> 8);
         b[o + 1] = (byte) v;
      } else {
         b[o] = (byte) v;
         b[o + 1] = (byte) (v >> 8);
      }
      return o + 2;
   }

   /** G.711 u-law. */
   static int ulaw(byte code) {
      int u = ~code & 0xFF;
      int t = (((u & 0x0F) << 3) + 0x84) << ((u >> 4) & 7);
      return (u & 0x80) != 0 ? 0x84 - t : t - 0x84;
   }

   /** G.711 A-law. */
   static int alaw(byte code) {
      int a = (code ^ 0x55) & 0xFF;
      int t = (a & 0x0F) << 4;
      int seg = (a & 0x70) >> 4;
      if (seg == 0) {
         t += 8;
      } else {
         t = (t + 0x108) << (seg - 1);
      }
      return (a & 0x80) != 0 ? t : -t;
   }

   public long skip(long n) throws IOException {
      byte[] tmp = new byte[Math.max(dstFrameSize, 4096 / dstFrameSize * dstFrameSize)];
      long left = n;
      while (left > 0) {
         int r = read(tmp, 0, (int) Math.min(tmp.length, left));
         if (r <= 0) {
            break;
         }
         left -= r;
      }
      return n - left;
   }

   public int available() throws IOException {
      return (oneLen - onePos) + src.available() / srcFrameSize * dstFrameSize;
   }

   public void close() throws IOException {
      src.close();
   }
}

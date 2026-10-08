package javax.sound.sampled;

import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Reads the header of a WAV file as the JDK's readers do: PCM, A-law and
 * u-law (its classic reader: the "fmt " chunk is not padded to an even
 * length and its size is taken from the bits and channels), IEEE float and
 * WAVE_FORMAT_EXTENSIBLE (its RIFF readers: every chunk padded, the frame
 * size is the block alignment). Anything else (ADPCM, MP3...) is not read:
 * the bridge decodes IMA ADPCM itself (ImaAdpcmWav), as Windows did with
 * ACM.
 */
final class WaveReader {
   private static final int PCM = 1;
   private static final int IEEE_FLOAT = 3;
   private static final int ALAW = 6;
   private static final int MULAW = 7;
   private static final int EXTENSIBLE = 0xFFFE;
   /** The 12 bytes after the format code in the GUIDs of KSDATAFORMAT_SUBTYPE_PCM and _IEEE_FLOAT. */
   private static final int[] GUID_TAIL = {0x00, 0x00, 0x10, 0x00, 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71};

   private final InputStream in;

   private WaveReader(InputStream in) {
      this.in = in;
   }

   /** An AudioInputStream positioned at the samples, or null if this is not a WAV file we read. */
   static AudioInputStream read(InputStream in) throws IOException {
      try {
         return new WaveReader(in).parse();
      } catch (EOFException e) {
         return null;
      }
   }

   private AudioInputStream parse() throws IOException {
      if (id() != tag("RIFF")) {
         return null;
      }
      u32();
      if (id() != tag("WAVE")) {
         return null;
      }
      while (id() != tag("fmt ")) {
         skipChunk(u32());
      }
      long fmtLength = u32();
      int format = u16();
      int channels = u16();
      long sampleRate = u32();
      u32();
      int blockAlign = u16();
      int bits = u16();
      long rest = fmtLength - 16;
      AudioFormat.Encoding encoding;
      int frameSize;
      if (format == PCM || format == ALAW || format == MULAW) {
         if (channels == 0 || bits == 0) {
            return null;
         }
         encoding = format == ALAW ? AudioFormat.Encoding.ALAW : format == MULAW ? AudioFormat.Encoding.ULAW
               : bits == 8 ? AudioFormat.Encoding.PCM_UNSIGNED : AudioFormat.Encoding.PCM_SIGNED;
         frameSize = AudioFormat.pcmFrameSize(bits, channels);
         if (rest > 0) {
            skipFully(rest);
         }
      } else {
         if (channels == 0 || bits == 0 || blockAlign == 0) {
            return null;
         }
         if (format == IEEE_FLOAT) {
            encoding = AudioFormat.Encoding.PCM_FLOAT;
         } else if (format == EXTENSIBLE && rest >= 24) {
            u16();
            u16();
            u32();
            int sub = (int) u32();
            for (int i = 0; i < GUID_TAIL.length; i++) {
               if (u8() != GUID_TAIL[i]) {
                  return null;
               }
            }
            rest -= 24;
            if (sub == PCM) {
               encoding = bits <= 8 ? AudioFormat.Encoding.PCM_UNSIGNED : AudioFormat.Encoding.PCM_SIGNED;
            } else if (sub == IEEE_FLOAT) {
               encoding = AudioFormat.Encoding.PCM_FLOAT;
            } else {
               return null;
            }
         } else {
            return null;
         }
         frameSize = blockAlign;
         skipChunk(rest < 0 ? 0 : rest);
      }
      while (id() != tag("data")) {
         skipChunk(u32());
      }
      long dataLength = u32();
      AudioFormat f = new AudioFormat(encoding, sampleRate, bits, channels, frameSize, sampleRate, false);
      return new AudioInputStream(in, f, dataLength / frameSize);
   }

   private static int tag(String s) {
      return s.charAt(0) | s.charAt(1) << 8 | s.charAt(2) << 16 | s.charAt(3) << 24;
   }

   private int id() throws IOException {
      return (int) u32();
   }

   private int u8() throws IOException {
      int b = in.read();
      if (b < 0) {
         throw new EOFException();
      }
      return b;
   }

   private int u16() throws IOException {
      return u8() | u8() << 8;
   }

   private long u32() throws IOException {
      return (u16() | (long) u16() << 16) & 0xFFFFFFFFL;
   }

   /** A chunk's data and, when its length is odd, the pad byte after it. */
   private void skipChunk(long length) throws IOException {
      skipFully(length + (length & 1));
   }

   private void skipFully(long n) throws IOException {
      while (n > 0) {
         long s = in.skip(n);
         if (s <= 0) {
            u8();
            s = 1;
         }
         n -= s;
      }
   }
}

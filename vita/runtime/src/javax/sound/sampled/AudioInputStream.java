package javax.sound.sampled;

import java.io.IOException;
import java.io.InputStream;

/**
 * javax.sound.sampled.AudioInputStream: a stream of whole frames, at most
 * frameLength of them. As the JDK's, each read is one read of the
 * underlying stream, and the bytes of a frame read in part are kept for the
 * next one.
 */
public class AudioInputStream extends InputStream {
   private final InputStream stream;
   protected AudioFormat format;
   protected long frameLength;
   protected int frameSize;
   protected long framePos;
   private long markpos;
   private byte[] pushBackBuffer;
   private int pushBackLen;
   private byte[] markPushBackBuffer;
   private int markPushBackLen;

   public AudioInputStream(InputStream stream, AudioFormat format, long length) {
      this.stream = stream;
      this.format = format;
      this.frameLength = length;
      this.frameSize = format.getFrameSize();
      if (frameSize == AudioSystem.NOT_SPECIFIED || frameSize <= 0) {
         frameSize = 1;
      }
   }

   public AudioFormat getFormat() {
      return format;
   }

   public long getFrameLength() {
      return frameLength;
   }

   public int read() throws IOException {
      if (frameSize != 1) {
         throw new IOException("cannot read a single byte if frame size > 1");
      }
      byte[] b = new byte[1];
      int n = read(b, 0, 1);
      return n <= 0 ? -1 : b[0] & 0xFF;
   }

   public int read(byte[] b) throws IOException {
      return read(b, 0, b.length);
   }

   public int read(byte[] b, int off, int len) throws IOException {
      if (len % frameSize != 0) {
         len -= len % frameSize;
         if (len == 0) {
            return 0;
         }
      }
      if (frameLength != AudioSystem.NOT_SPECIFIED) {
         if (framePos >= frameLength) {
            return -1;
         }
         if (len / frameSize > frameLength - framePos) {
            len = (int) (frameLength - framePos) * frameSize;
         }
      }
      int bytesRead = 0;
      int thisOff = off;
      if (pushBackLen > 0 && len >= pushBackLen) {
         System.arraycopy(pushBackBuffer, 0, b, off, pushBackLen);
         thisOff += pushBackLen;
         len -= pushBackLen;
         bytesRead += pushBackLen;
         pushBackLen = 0;
      }
      int n = stream.read(b, thisOff, len);
      if (n == -1) {
         return -1;
      }
      if (n > 0) {
         bytesRead += n;
      }
      if (bytesRead > 0) {
         pushBackLen = bytesRead % frameSize;
         if (pushBackLen > 0) {
            if (pushBackBuffer == null) {
               pushBackBuffer = new byte[frameSize];
            }
            System.arraycopy(b, off + bytesRead - pushBackLen, pushBackBuffer, 0, pushBackLen);
            bytesRead -= pushBackLen;
         }
         framePos += bytesRead / frameSize;
      }
      return bytesRead;
   }

   public long skip(long n) throws IOException {
      if (n <= 0) {
         return 0;
      }
      if (n % frameSize != 0) {
         n -= n % frameSize;
      }
      if (frameLength != AudioSystem.NOT_SPECIFIED && n / frameSize > frameLength - framePos) {
         n = (frameLength - framePos) * frameSize;
      }
      long remaining = n;
      if (pushBackLen > 0) {
         // the bytes kept for a frame are the first ones skipped
         if (remaining >= pushBackLen) {
            remaining -= pushBackLen;
            pushBackLen = 0;
         } else {
            System.arraycopy(pushBackBuffer, (int) remaining, pushBackBuffer, 0, pushBackLen - (int) remaining);
            pushBackLen -= (int) remaining;
            remaining = 0;
         }
      }
      while (remaining > 0) {
         long r = stream.skip(remaining);
         if (r == 0) {
            if (stream.read() == -1) {
               break;
            }
            r = 1;
         } else if (r < 0) {
            break;
         }
         remaining -= r;
      }
      long skipped = n - remaining;
      if (skipped % frameSize != 0) {
         // a frame skipped in part: skip the rest of it too
         skip(frameSize - skipped % frameSize);
         skipped = skipped + frameSize - skipped % frameSize;
      }
      framePos += skipped / frameSize;
      return skipped;
   }

   public int available() throws IOException {
      int a = stream.available();
      if (frameLength != AudioSystem.NOT_SPECIFIED && a / frameSize > frameLength - framePos) {
         return (int) (frameLength - framePos) * frameSize;
      }
      return a;
   }

   public void close() throws IOException {
      stream.close();
   }

   public void mark(int readlimit) {
      stream.mark(readlimit);
      if (markSupported()) {
         markpos = framePos;
         markPushBackLen = pushBackLen;
         if (pushBackLen > 0) {
            if (markPushBackBuffer == null) {
               markPushBackBuffer = new byte[frameSize];
            }
            System.arraycopy(pushBackBuffer, 0, markPushBackBuffer, 0, pushBackLen);
         }
      }
   }

   public void reset() throws IOException {
      stream.reset();
      framePos = markpos;
      pushBackLen = markPushBackLen;
      if (pushBackLen > 0) {
         if (pushBackBuffer == null) {
            pushBackBuffer = new byte[frameSize];
         }
         System.arraycopy(markPushBackBuffer, 0, pushBackBuffer, 0, pushBackLen);
      }
   }

   public boolean markSupported() {
      return stream.markSupported();
   }
}

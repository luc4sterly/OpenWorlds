package net.openworlds.awt;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.Line;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;

/**
 * A SourceDataLine of our javax.sound: 8 or 16-bit PCM, mono or stereo, at
 * any rate, kept in a ring buffer that {@link AudioMixer} empties at the
 * pace of the sound output, resampled to its rate (linear interpolation).
 * write() blocks while the buffer is full and drain() until it has been
 * played, as the JDK's lines.
 */
public final class SoundLine implements SourceDataLine {
   private AudioFormat format;
   private boolean open;
   /** Read by the mixer without this line's lock (it must not take it while holding its own). */
   private volatile boolean running;
   private byte[] ring;
   private int head;
   private int count;
   private int frameSize;
   private int channels;
   private int sampleBytes;
   private boolean signed;
   private boolean bigEndian;
   private long framesPlayed;
   private long flushes;
   /** The mixer block during which the buffer last ran dry. */
   private long emptiedInBlock = -1;
   // resampling: position between the frames prev and cur, 16.16 fixed point
   private int step;
   private int phase = 0x10000;
   private int prevL;
   private int prevR;
   private int curL;
   private int curR;

   public SoundLine(AudioFormat format) {
      this.format = format;
   }

   /** The formats a line plays: PCM, 8 or 16 bits, mono or stereo. */
   public static boolean supports(AudioFormat f) {
      AudioFormat.Encoding e = f.getEncoding();
      int bits = f.getSampleSizeInBits();
      int ch = f.getChannels();
      boolean pcm = e.equals(AudioFormat.Encoding.PCM_SIGNED) || e.equals(AudioFormat.Encoding.PCM_UNSIGNED) && bits == 8;
      return pcm && (bits == 8 || bits == 16) && (ch == 1 || ch == 2) && f.getFrameSize() == bits / 8 * ch
            && (f.getSampleRate() == AudioSystem.NOT_SPECIFIED || f.getSampleRate() >= 1000 && f.getSampleRate() <= 192000);
   }

   public Line.Info getLineInfo() {
      return new DataLine.Info(SourceDataLine.class, format);
   }

   public void open() throws LineUnavailableException {
      open(format == null ? new AudioFormat(44100, 16, 2, true, false) : format, AudioSystem.NOT_SPECIFIED);
   }

   public void open(AudioFormat format) throws LineUnavailableException {
      open(format, AudioSystem.NOT_SPECIFIED);
   }

   public void open(AudioFormat f, int bufferSize) throws LineUnavailableException {
      synchronized (this) {
         if (open) {
            if (!f.matches(format)) {
               throw new IllegalStateException("Line is already open with format " + format + " and bufferSize " + ring.length);
            }
            return;
         }
         if (!supports(f) || f.getSampleRate() == AudioSystem.NOT_SPECIFIED) {
            throw new IllegalArgumentException("Line unsupported: " + f);
         }
         format = f;
         frameSize = f.getFrameSize();
         channels = f.getChannels();
         sampleBytes = f.getSampleSizeInBits() / 8;
         signed = f.getEncoding().equals(AudioFormat.Encoding.PCM_SIGNED);
         bigEndian = f.isBigEndian();
         int rate = (int) f.getSampleRate();
         int min = Math.max(frameSize, rate / 16 * frameSize);
         if (bufferSize == AudioSystem.NOT_SPECIFIED || bufferSize <= 0) {
            bufferSize = rate / 2 * frameSize;
         }
         bufferSize = Math.max(min, bufferSize - bufferSize % frameSize);
         ring = new byte[bufferSize];
         head = 0;
         count = 0;
         framesPlayed = 0;
         step = (int) (((long) rate << 16) / AudioDevice.RATE);
         phase = 0x10000;
         prevL = prevR = curL = curR = 0;
         open = true;
      }
      AudioMixer.get().add(this);
   }

   public void close() {
      synchronized (this) {
         if (!open) {
            return;
         }
         open = false;
         running = false;
         count = 0;
         notifyAll();
      }
      AudioMixer.get().remove(this);
   }

   public synchronized boolean isOpen() {
      return open;
   }

   public void start() {
      synchronized (this) {
         if (!open || running) {
            return;
         }
         running = true;
      }
      AudioMixer.get().wake();
   }

   public synchronized void stop() {
      running = false;
      notifyAll();
   }

   public boolean isRunning() {
      return running;
   }

   public synchronized boolean isActive() {
      return running && count >= frameSize;
   }

   public int write(byte[] b, int off, int len) {
      if (frameSize > 0 && len % frameSize != 0) {
         throw new IllegalArgumentException("illegal request to write non-integral number of frames (" + len + " bytes, frameSize = " + frameSize + " bytes)");
      }
      if (len < 0) {
         throw new ArrayIndexOutOfBoundsException(len);
      }
      int written = 0;
      boolean wake = false;
      synchronized (this) {
         long flushed = flushes;
         while (written < len && open && flushes == flushed) {
            int space = ring.length - count;
            if (space == 0) {
               if (wake) {
                  wake = false;
                  AudioMixer.get().wake();
               }
               try {
                  wait();
               } catch (InterruptedException e) {
                  Thread.currentThread().interrupt();
                  break;
               }
               continue;
            }
            int n = Math.min(space, len - written);
            int tail = (head + count) % ring.length;
            int first = Math.min(n, ring.length - tail);
            System.arraycopy(b, off + written, ring, tail, first);
            System.arraycopy(b, off + written + first, ring, 0, n - first);
            count += n;
            written += n;
            wake = running;
         }
      }
      if (wake) {
         AudioMixer.get().wake();
      }
      return written;
   }

   public void drain() {
      AudioMixer mixer = AudioMixer.get();
      long block;
      synchronized (this) {
         while (open && running && count >= frameSize) {
            try {
               wait();
            } catch (InterruptedException e) {
               Thread.currentThread().interrupt();
               return;
            }
         }
         if (!open || !running) {
            return;
         }
         block = emptiedInBlock;
      }
      try {
         // the block with the last samples has gone to the device
         mixer.awaitBlock(block, 1000);
      } catch (InterruptedException e) {
         Thread.currentThread().interrupt();
      }
   }

   public synchronized void flush() {
      count = 0;
      flushes++;
      notifyAll();
   }

   public AudioFormat getFormat() {
      return format;
   }

   public synchronized int getBufferSize() {
      return ring == null ? AudioSystem.NOT_SPECIFIED : ring.length;
   }

   public synchronized int available() {
      return ring == null ? 0 : ring.length - count;
   }

   public int getFramePosition() {
      return (int) getLongFramePosition();
   }

   public synchronized long getLongFramePosition() {
      return framesPlayed;
   }

   public synchronized long getMicrosecondPosition() {
      return format == null ? 0 : (long) (framesPlayed * 1000000.0 / format.getSampleRate());
   }

   public float getLevel() {
      return AudioSystem.NOT_SPECIFIED;
   }

   /** Adds this line's next frames frames, resampled to outRate, to acc (stereo); called by the mixer in its block number block. */
   synchronized void mixInto(int[] acc, int frames, int outRate, long block) {
      if (!open || !running) {
         return;
      }
      int o = 0;
      for (int i = 0; i < frames; i++) {
         while (phase >= 0x10000) {
            if (count < frameSize) {
               if (emptiedInBlock < block) {
                  emptiedInBlock = block;
               }
               notifyAll();
               return;
            }
            prevL = curL;
            prevR = curR;
            curL = sample(head);
            curR = channels == 2 ? sample((head + sampleBytes) % ring.length) : curL;
            head = (head + frameSize) % ring.length;
            count -= frameSize;
            framesPlayed++;
            phase -= 0x10000;
         }
         acc[o++] += prevL + (int) (((long) (curL - prevL) * phase) >> 16);
         acc[o++] += prevR + (int) (((long) (curR - prevR) * phase) >> 16);
         phase += step;
      }
      if (count < frameSize && emptiedInBlock < block) {
         emptiedInBlock = block;
      }
      notifyAll();
   }

   /** The 16-bit value of the sample at ring[i]. */
   private int sample(int i) {
      if (sampleBytes == 1) {
         int v = ring[i];
         return (signed ? v : (v & 0xFF) - 128) << 8;
      }
      int j = (i + 1) % ring.length;
      return bigEndian ? (short) (ring[i] << 8 | ring[j] & 0xFF) : (short) (ring[j] << 8 | ring[i] & 0xFF);
   }
}

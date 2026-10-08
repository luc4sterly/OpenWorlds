package net.openworlds.awt;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 * The machine's sound output, fed by {@link AudioMixer} with blocks of
 * {@link #FRAMES} stereo frames of 16-bit samples at {@link #RATE} Hz.
 * {@code -Dopenworlds.audio=} picks it: {@code native} (SDL2 on Linux and
 * the PSVita; the default), {@code null} (nothing is heard, but time passes
 * as if it were: the default with {@code -Dopenworlds.screen=headless}) or
 * {@code wav:<file>} (what would be heard, written to a WAV file, for
 * tests). If the native output cannot be opened, the null one is used.
 */
public abstract class AudioDevice {
   public static final int RATE = 48000;
   public static final int FRAMES = 1024;

   static AudioDevice open() {
      String headless = "headless".equals(System.getProperty("openworlds.screen")) ? "null" : "native";
      String kind = System.getProperty("openworlds.audio", headless);
      if (kind.startsWith("wav:")) {
         try {
            return new WavFile(new File(kind.substring(4)));
         } catch (IOException e) {
            System.err.println("[audio] cannot write " + kind.substring(4) + ": " + e);
            return new Silent();
         }
      }
      if (kind.equals("native")) {
         AudioDevice d = NativeAudioDevice.open();
         if (d != null) {
            return d;
         }
      }
      return new Silent();
   }

   /** Plays one block of FRAMES frames (left, right, left...); returns when the device can take the next one. */
   public abstract void play(short[] block);

   /** Nothing will be played for a while. */
   public void idle() {
   }

   /** Takes as long as the block would take to play. */
   static class Silent extends AudioDevice {
      private long due;

      public void play(short[] block) {
         long now = System.nanoTime();
         if (due == 0 || now - due > 200000000L) {
            due = now;
         }
         due += FRAMES * 1000000000L / RATE;
         long wait = (due - now) / 1000000L;
         if (wait > 0) {
            try {
               Thread.sleep(wait);
            } catch (InterruptedException e) {
               Thread.currentThread().interrupt();
            }
         }
      }

      public void idle() {
         due = 0;
      }
   }

   /** A WAV file of everything mixed, at the pace of real time. */
   static final class WavFile extends Silent {
      private final RandomAccessFile file;
      private final byte[] bytes = new byte[FRAMES * 4];
      private long dataLength;

      WavFile(File f) throws IOException {
         file = new RandomAccessFile(f, "rw");
         file.setLength(0);
         file.write(header(0));
      }

      private static byte[] header(long dataLength) {
         byte[] h = new byte[44];
         put(h, 0, 'R' | 'I' << 8 | 'F' << 16 | 'F' << 24);
         put(h, 4, (int) (36 + dataLength));
         put(h, 8, 'W' | 'A' << 8 | 'V' << 16 | 'E' << 24);
         put(h, 12, 'f' | 'm' << 8 | 't' << 16 | ' ' << 24);
         put(h, 16, 16);
         put(h, 20, 1 | 2 << 16);
         put(h, 24, RATE);
         put(h, 28, RATE * 4);
         put(h, 32, 4 | 16 << 16);
         put(h, 36, 'd' | 'a' << 8 | 't' << 16 | 'a' << 24);
         put(h, 40, (int) dataLength);
         return h;
      }

      private static void put(byte[] h, int i, int v) {
         h[i] = (byte) v;
         h[i + 1] = (byte) (v >> 8);
         h[i + 2] = (byte) (v >> 16);
         h[i + 3] = (byte) (v >> 24);
      }

      public void play(short[] block) {
         for (int i = 0; i < block.length; i++) {
            bytes[2 * i] = (byte) block[i];
            bytes[2 * i + 1] = (byte) (block[i] >> 8);
         }
         try {
            file.seek(44 + dataLength);
            file.write(bytes);
            dataLength += bytes.length;
            file.seek(0);
            file.write(header(dataLength));
         } catch (IOException e) {
            System.err.println("[audio] " + e);
         }
         super.play(block);
      }
   }
}

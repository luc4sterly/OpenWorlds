import java.io.File;
import java.io.IOException;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.SourceDataLine;

/**
 * Our sound output (net.openworlds.awt.SoundLine and AudioMixer), on a JVM
 * with java.base only and -Dopenworlds.audio=wav:<file>: what is mixed is
 * written to a WAV file at the pace of real time, then read back and
 * measured. The lines are used as NativeMediaSound uses them.
 *
 *   vita/tools/run-sound-check.sh
 */
public class SoundCheck {
   static int failures;

   static void check(String what, boolean ok) {
      System.out.println((ok ? "ok   " : "FAIL ") + what);
      if (!ok) {
         failures++;
      }
   }

   static byte[] sine(int rate, int channels, double hz, int amplitude, double seconds) {
      int frames = (int) (rate * seconds);
      byte[] b = new byte[frames * 2 * channels];
      for (int i = 0; i < frames; i++) {
         int v = (int) Math.round(amplitude * Math.sin(2 * Math.PI * hz * i / rate));
         for (int c = 0; c < channels; c++) {
            int o = (i * channels + c) * 2;
            b[o] = (byte) v;
            b[o + 1] = (byte) (v >> 8);
         }
      }
      return b;
   }

   /** Plays b on a line of format f as NativeMediaSound does (blocks of 4096 bytes, then drain); returns the seconds it took. */
   static double play(AudioFormat f, byte[] b) throws Exception {
      SourceDataLine line = AudioSystem.getSourceDataLine(f);
      line.open(f);
      line.start();
      long t0 = System.nanoTime();
      for (int off = 0; off < b.length; off += 4096) {
         line.write(b, off, Math.min(4096, b.length - off));
      }
      line.drain();
      double s = (System.nanoTime() - t0) / 1e9;
      check("frame position at the end is every frame written (" + line.getLongFramePosition() + ")", line.getLongFramePosition() == b.length / f.getFrameSize());
      line.close();
      return s;
   }

   public static void main(String[] args) throws Exception {
      File wav = new File(System.getProperty("openworlds.audio").substring(4));

      AudioFormat st = new AudioFormat(22050, 16, 2, true, false);
      SourceDataLine line = AudioSystem.getSourceDataLine(st);
      check("a line before open is not open", !line.isOpen() && line.getBufferSize() == AudioSystem.NOT_SPECIFIED);
      line.open(st);
      check("open: half a second of buffer (" + line.getBufferSize() + ")", line.isOpen() && line.getBufferSize() == 22050 / 2 * 4 && line.available() == line.getBufferSize());
      check("its format", line.getFormat().matches(st) && line.getLineInfo().getLineClass() == SourceDataLine.class);
      try {
         line.write(new byte[6], 0, 6);
         check("a write of a frame and a half is refused", false);
      } catch (IllegalArgumentException e) {
         check("a write of a frame and a half is refused", true);
      }
      // stopped: what is written stays in the buffer, nothing is played
      int n = line.write(new byte[8000], 0, 8000);
      Thread.sleep(200);
      check("stopped: written, not played (" + n + ", position " + line.getLongFramePosition() + ")", n == 8000 && line.getLongFramePosition() == 0 && line.available() == line.getBufferSize() - 8000);
      long t = System.nanoTime();
      line.drain();
      check("drain on a stopped line returns at once", System.nanoTime() - t < 100000000L);
      // a writer blocked on a full stopped line is released by flush
      final SourceDataLine l = line;
      final int[] written = new int[1];
      Thread w = new Thread() {
         public void run() {
            written[0] = l.write(new byte[200000], 0, 200000);
         }
      };
      w.start();
      Thread.sleep(300);
      check("the writer waits while the buffer is full", w.isAlive() && line.available() == 0);
      line.flush();
      w.join(2000);
      check("flush releases it (" + written[0] + " bytes went in)", !w.isAlive() && written[0] == line.getBufferSize() - 8000);
      check("and empties the buffer", line.available() == line.getBufferSize());
      // close releases a blocked writer too
      line.write(new byte[line.getBufferSize()], 0, line.getBufferSize());
      w = new Thread() {
         public void run() {
            written[0] = l.write(new byte[4000], 0, 4000);
         }
      };
      w.start();
      Thread.sleep(200);
      line.close();
      w.join(2000);
      check("close releases a blocked writer (" + written[0] + ")", !w.isAlive() && written[0] == 0 && !line.isOpen());

      // a second of a 441 Hz sine, mono 22050 Hz, as a WAV the client plays
      double s = play(new AudioFormat(22050, 16, 1, true, false), sine(22050, 1, 441, 10000, 1.0));
      check("one second takes about one second (" + s + ")", s > 0.85 && s < 1.35);
      Thread.sleep(300);
      // 8-bit unsigned at 11025 Hz and 16-bit stereo at 44100 Hz at the same time
      final byte[] u8 = new byte[11025];
      for (int i = 0; i < u8.length; i++) {
         u8[i] = (byte) (128 + (i / 25 % 2 == 0 ? 40 : -40));
      }
      Thread other = new Thread() {
         public void run() {
            try {
               play(new AudioFormat(11025, 8, 1, false, false), u8);
            } catch (Exception e) {
               check("8-bit line: " + e, false);
            }
         }
      };
      other.start();
      play(new AudioFormat(44100, 16, 2, true, false), sine(44100, 2, 1000, 8000, 1.0));
      other.join();
      Thread.sleep(400);

      // what came out
      AudioInputStream in = AudioSystem.getAudioInputStream(wav);
      AudioFormat f = in.getFormat();
      check("the output: 48000 Hz 16-bit stereo (" + f + ")", f.getSampleRate() == 48000 && f.getChannels() == 2 && f.getSampleSizeInBits() == 16);
      byte[] all = new byte[(int) in.getFrameLength() * 4];
      int got = 0;
      while (got < all.length && (n = in.read(all, got, all.length - got)) > 0) {
         got += n;
      }
      in.close();
      int frames = got / 4;
      short[] left = new short[frames];
      short[] right = new short[frames];
      for (int i = 0; i < frames; i++) {
         left[i] = (short) (all[4 * i] & 0xFF | all[4 * i + 1] << 8);
         right[i] = (short) (all[4 * i + 2] & 0xFF | all[4 * i + 3] << 8);
      }
      // the first sound: find where it starts, measure one second of it
      int start = 0;
      while (start < frames && Math.abs(left[start]) < 100) {
         start++;
      }
      int crossings = 0;
      int peak = 0;
      boolean same = true;
      for (int i = start + 1; i < start + 48000 && i < frames; i++) {
         if ((left[i - 1] < 0) != (left[i] < 0)) {
            crossings++;
         }
         peak = Math.max(peak, Math.abs(left[i]));
         same &= left[i] == right[i];
      }
      check("the sine is there: 441 Hz (" + crossings + " zero crossings in a second)", crossings >= 876 && crossings <= 888);
      check("at its amplitude (" + peak + ")", peak >= 9900 && peak <= 10010);
      check("mono played on both channels", same);
      int before = 0;
      int after = 0;
      for (int i = start + 47700; i < start + 47990; i++) {
         before = Math.max(before, Math.abs(left[i]));
      }
      for (int i = start + 48005; i < start + 49000; i++) {
         after = Math.max(after, Math.abs(left[i]));
      }
      check("it lasts one second (" + before + " until then, " + after + " after)", before > 9000 && after == 0);
      // the mix: square of +-40<<8 = 10240 plus a sine of 8000: peaks near 18240
      int next = start + 48005;
      while (next < frames && Math.abs(left[next]) < 100) {
         next++;
      }
      int mixPeak = 0;
      for (int i = next + 2000; i < next + 40000 && i < frames; i++) {
         mixPeak = Math.max(mixPeak, Math.abs(left[i]));
      }
      check("two lines mixed (peak " + mixPeak + ", about 10240 + 8000)", mixPeak > 17500 && mixPeak <= 18300);
      System.out.println(failures == 0 ? "all sound checks passed" : failures + " sound checks failed");
      System.exit(failures == 0 ? 0 : 1);
   }
}

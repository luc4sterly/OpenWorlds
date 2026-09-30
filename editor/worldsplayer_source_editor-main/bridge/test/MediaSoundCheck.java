import NET.worlds.core.NativeMediaSound;
import java.io.File;
import java.io.FileOutputStream;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

/**
 * gamma.dll's sound (NativeMediaSound), with -Dopenworlds.mute=1 (nothing is
 * heard; the times and states are the real ones). Hand-calculated cases:
 *  - waveOutSetVolume (0x00420120): ROUND(65535*x) to even, right<<16 + left as int.
 *  - PlaySound (0x00420190/0x00420200): synchronous lasts as long as the WAV,
 *    loop continues past its duration, SND_PURGE only for the same name
 *    (FUN_004508c0, case-insensitive A-Z/a-z), missing file -> false.
 *  - MCI (0x0041f890/0x0041fe40/0x0041fd20/0x0041fe30): owner, change of owner
 *    without restarting with the same file, mode STOP -> closes and true.
 *  - ASF (0x0041f670): without bin\playfile.exe -> false.
 */
public class MediaSoundCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + " " + what);
      if (!ok) {
         fails++;
      }
   }

   /** 16-bit mono 8000 Hz PCM WAV of n samples (RIFF header written by hand). */
   static File wav(File dir, String name, int n) throws Exception {
      File f = new File(dir, name);
      int data = n * 2;
      java.nio.ByteBuffer b = java.nio.ByteBuffer.allocate(44 + data).order(java.nio.ByteOrder.LITTLE_ENDIAN);
      b.put("RIFF".getBytes()).putInt(36 + data).put("WAVE".getBytes());
      b.put("fmt ".getBytes()).putInt(16).putShort((short)1).putShort((short)1).putInt(8000).putInt(16000).putShort((short)2).putShort((short)16);
      b.put("data".getBytes()).putInt(data);
      for (int i = 0; i < n; i++) {
         b.putShort((short)(Math.sin(i * 2 * Math.PI * 440 / 8000) * 8000));
      }

      FileOutputStream o = new FileOutputStream(f);
      o.write(b.array());
      o.close();
      return f;
   }

   public static void main(String[] args) throws Exception {
      System.setProperty("openworlds.mute", "1");
      check(NativeMediaSound.MUTE, "mute active in the test");

      // --- volume ---
      check(NativeMediaSound.waveOutVolumeDword(1.0F, 1.0F) == 0xFFFFFFFF, "vol(1,1) = 0xFFFFFFFF");
      check(NativeMediaSound.waveOutVolumeDword(0.0F, 0.0F) == 0, "vol(0,0) = 0");
      // 65535*0.5 = 32767.5 -> 32768 (to even) = 0x8000 in both channels
      check(NativeMediaSound.waveOutVolumeDword(0.5F, 0.5F) == 0x80008000, "vol(.5,.5) = 0x80008000");
      // left 65535*0.25 = 16383.75 -> 0x4000 ; right 65535*0.75 = 49151.25 -> 0xBFFF
      check(NativeMediaSound.waveOutVolumeDword(0.25F, 0.75F) == 0xBFFF4000, "vol(.25,.75) = 0xBFFF4000");
      // Sound with soundOn=false passes -1: left=right=-0.5 -> -32768 ; -32768*65536 + -32768 = 0x7FFF8000 (int)
      check(NativeMediaSound.waveOutVolumeDword(-0.5F, -0.5F) == 0x7FFF8000, "vol(-.5,-.5) = 0x7FFF8000");
      check(Math.abs(NativeMediaSound.channelGain(0xBFFF4000, 0) - 16384 / 65535.0) < 1e-12, "left gain 0x4000/0xFFFF");
      check(Math.abs(NativeMediaSound.channelGain(0xBFFF4000, 1) - 49151 / 65535.0) < 1e-12, "right gain 0xBFFF/0xFFFF");

      File dir = new File(System.getProperty("java.io.tmpdir"), "media-check-" + System.nanoTime());
      dir.mkdirs();
      File w = wav(dir, "tono.wav", 2400); // 2400 / 8000 = 0.30 s
      String wp = w.getPath();

      // --- synchronous PlaySound ---
      long t0 = System.nanoTime();
      boolean ok = NativeMediaSound.playSound(wp, false);
      double el = (System.nanoTime() - t0) / 1.0E9;
      check(ok, "synchronous PlaySound returns true");
      check(el >= 0.28 && el < 1.5, "synchronous PlaySound lasts ~0.30 s (measured " + el + ")");
      check(!NativeMediaSound.playSoundActive(), "after the synchronous one nothing is left playing");

      t0 = System.nanoTime();
      check(!NativeMediaSound.playSound(new File(dir, "noexiste.wav").getPath(), false), "missing file -> false (SND_NODEFAULT)");
      check((System.nanoTime() - t0) / 1.0E9 < 0.2, "missing file returns instantly");

      // --- loop + SND_PURGE ---
      check(NativeMediaSound.playSound(wp, true), "looping PlaySound returns true");
      Thread.sleep(700L); // more than two laps of 0.30 s
      check(NativeMediaSound.playSoundActive(), "the loop continues after 0.70 s");
      NativeMediaSound.purgeSound(new File(dir, "otro.wav").getPath());
      check(NativeMediaSound.playSoundActive(), "SND_PURGE of another name does not stop it");
      NativeMediaSound.purgeSound(wp.toUpperCase());
      check(!NativeMediaSound.playSoundActive(), "SND_PURGE of the same name (other case) stops it");

      // --- a new PlaySound cuts off another thread's synchronous one ---
      File largo = wav(dir, "largo.wav", 16000); // 2.0 s
      final double[] syncEl = new double[1];
      Thread th = new Thread(() -> {
         long s = System.nanoTime();
         NativeMediaSound.playSound(largo.getPath(), false);
         syncEl[0] = (System.nanoTime() - s) / 1.0E9;
      });
      th.start();
      Thread.sleep(200L);
      NativeMediaSound.playSound(wp, false);
      th.join(3000L);
      check(!th.isAlive() && syncEl[0] < 1.5, "the 2 s synchronous one returns when cut off (measured " + syncEl[0] + ")");

      // --- ASF ---
      check(!NativeMediaSound.asfNativePlay("u:\\x.asf"), "ASF: CreateProcess(bin\\playfile.exe) fails -> false");

      // --- MCI waveaudio ---
      Object a = new Object();
      Object b = new Object();
      check(!NativeMediaSound.mciIsActive(), "MCI inactive at the start");
      check(NativeMediaSound.mciStart(a, wp), "MCI waveaudio opens and plays");
      check(NativeMediaSound.mciIsActive(), "MCI active (owner = a)");
      check(NativeMediaSound.mciIsFinished(b), "isFinished of a non-owner -> true");
      check(!NativeMediaSound.mciIsFinished(a), "isFinished of the owner just started -> false");
      check(NativeMediaSound.mciStart(b, wp.toUpperCase()), "same file: changes owner without reopening -> true");
      check(NativeMediaSound.mciIsFinished(a), "the former owner is no longer the owner");
      Thread.sleep(600L);
      check(NativeMediaSound.mciIsFinished(b), "after 0.30 s the mode is STOP -> closes and true");
      check(!NativeMediaSound.mciIsActive(), "after closing, inactive");
      check(!NativeMediaSound.mciStart(a, new File(dir, "noexiste.wav").getPath()), "MCI with a missing file -> false");
      check(!NativeMediaSound.mciIsActive(), "a failed MCI leaves no owner");

      // --- MCI sequencer (.MID in uppercase: FUN_004508c0 is case-insensitive) ---
      Sequence seq = new Sequence(Sequence.PPQ, 480);
      Track tr = seq.createTrack();
      tr.add(new MidiEvent(new ShortMessage(ShortMessage.NOTE_ON, 0, 60, 90), 0L));
      tr.add(new MidiEvent(new ShortMessage(ShortMessage.NOTE_OFF, 0, 60, 0), 480L)); // 1 quarter note at 120 bpm = 0.5 s
      File mid = new File(dir, "nota.MID");
      MidiSystem.write(seq, 0, mid);
      check(NativeMediaSound.mciStart(a, mid.getPath()), "MCI sequencer opens a .MID");
      check(!NativeMediaSound.mciIsFinished(a), "MIDI playing at the start");
      Thread.sleep(1000L);
      check(NativeMediaSound.mciIsFinished(a), "0.5 s MIDI finished after 1 s");
      NativeMediaSound.mciStart(a, wp);
      NativeMediaSound.mciStop(b);
      check(NativeMediaSound.mciIsActive(), "nativeStop by a non-owner does not close");
      NativeMediaSound.mciStop(a);
      check(!NativeMediaSound.mciIsActive(), "nativeStop by the owner closes");

      // --- IMA ADPCM (Windows ACM codec), by hand ---
      NET.worlds.core.ImaAdpcmWav.Channel c = new NET.worlds.core.ImaAdpcmWav.Channel(0, 0);
      // step 7: nibble 7 -> 0 + 1 + 3 + 7 = 11 ; index 0+8 = 8
      check(c.decode(7) == 11 && c.index == 8, "IMA: (0,0) nibble 7 -> 11, index 8");
      // step 16: nibble 8 -> -(16>>3) = -2 -> 9 ; index 7
      check(c.decode(8) == 9 && c.index == 7, "IMA: nibble 8 -> 9, index 7");
      // step 14: nibble 15 -> -(1+3+7+14) = -25 -> -16 ; index 15
      check(c.decode(15) == -16 && c.index == 15, "IMA: nibble 15 -> -16, index 15");
      NET.worlds.core.ImaAdpcmWav.Channel sat = new NET.worlds.core.ImaAdpcmWav.Channel(32760, 88);
      check(sat.decode(7) == 32767 && sat.index == 88, "IMA: saturates at 32767 and index 88");

      // --- the real WAV/MIDI files of GroundZero/wav ---
      File gz = new File("assets/WorldsPlayer/GroundZero/wav");
      File s = new File(gz, "S.wav");
      check(s.isFile() && NET.worlds.core.ImaAdpcmWav.isImaAdpcm(s), "S.wav is IMA ADPCM (format 0x11)");
      javax.sound.sampled.AudioInputStream sin = NET.worlds.core.ImaAdpcmWav.open(s);
      // data = 121856 bytes / nBlockAlign 256 = 476 blocks x wSamplesPerBlock 505
      // = 240380 samples; fact says 0x3ab67 = 240487 (more than there are: the
      // minimum wins). At 0x2bf2 = 11250 Hz: 21.367 s.
      check(sin.getFrameLength() == 240380 && sin.getFormat().getSampleRate() == 11250.0F, "S.wav: 476 blocks x 505 = 240380 samples at 11250 Hz");
      sin.close();
      check(NativeMediaSound.playSound(s.getPath(), true), "looping PlaySound of S.wav opens");
      Thread.sleep(300L);
      check(NativeMediaSound.playSoundActive(), "S.wav playing");
      NativeMediaSound.purgeSound(s.getPath());
      File lion = new File(gz, "Liondoor.wav");
      // 8-bit mono PCM 22050 Hz, data 0xa8e0 = 43232 bytes -> 1.96 s
      t0 = System.nanoTime();
      check(NativeMediaSound.playSound(lion.getPath(), false), "synchronous PlaySound of Liondoor.wav");
      el = (System.nanoTime() - t0) / 1.0E9;
      check(el >= 1.9 && el < 3.5, "Liondoor.wav lasts ~1.96 s (measured " + el + ")");
      File glee = new File(gz, "Glee3.mid");
      check(NativeMediaSound.mciStart(a, glee.getPath()), "MCI sequencer opens Glee3.mid");
      check(!NativeMediaSound.mciIsFinished(a), "Glee3.mid playing");
      NativeMediaSound.mciStop(a);
      check(!NativeMediaSound.mciIsActive(), "Glee3.mid stopped");

      for (File f : dir.listFiles()) {
         f.delete();
      }

      dir.delete();
      System.out.println(fails == 0 ? "MediaSoundCheck: all OK" : "MediaSoundCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

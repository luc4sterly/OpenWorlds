import NET.worlds.core.NativeMediaSound;
import java.io.File;
import java.io.FileOutputStream;
import javax.sound.midi.MidiEvent;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.ShortMessage;
import javax.sound.midi.Track;

/**
 * Sonido de gamma.dll (NativeMediaSound), con -Dopenworlds.mute=1 (no suena
 * nada; los tiempos y estados son los reales). Casos calculados a mano:
 *  - waveOutSetVolume (0x00420120): ROUND(65535*x) al par, der<<16 + izq en int.
 *  - PlaySound (0x00420190/0x00420200): sincrono dura lo que el WAV, bucle
 *    sigue tras su duracion, SND_PURGE solo para el mismo nombre (FUN_004508c0,
 *    sin distinguir A-Z/a-z), fichero ausente -> false.
 *  - MCI (0x0041f890/0x0041fe40/0x0041fd20/0x0041fe30): dueno, cambio de dueno
 *    sin reiniciar con el mismo fichero, modo STOP -> cierra y true.
 *  - ASF (0x0041f670): sin bin\playfile.exe -> false.
 */
public class MediaSoundCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLO") + " " + what);
      if (!ok) {
         fails++;
      }
   }

   /** WAV PCM 16 bits mono 8000 Hz de n muestras (cabecera RIFF escrita a mano). */
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
      check(NativeMediaSound.MUTE, "mute activo en la prueba");

      // --- volumen ---
      check(NativeMediaSound.waveOutVolumeDword(1.0F, 1.0F) == 0xFFFFFFFF, "vol(1,1) = 0xFFFFFFFF");
      check(NativeMediaSound.waveOutVolumeDword(0.0F, 0.0F) == 0, "vol(0,0) = 0");
      // 65535*0.5 = 32767.5 -> 32768 (al par) = 0x8000 en los dos canales
      check(NativeMediaSound.waveOutVolumeDword(0.5F, 0.5F) == 0x80008000, "vol(.5,.5) = 0x80008000");
      // izq 65535*0.25 = 16383.75 -> 0x4000 ; der 65535*0.75 = 49151.25 -> 0xBFFF
      check(NativeMediaSound.waveOutVolumeDword(0.25F, 0.75F) == 0xBFFF4000, "vol(.25,.75) = 0xBFFF4000");
      // Sound con soundOn=false pasa -1: izq=der=-0.5 -> -32768 ; -32768*65536 + -32768 = 0x7FFF8000 (int)
      check(NativeMediaSound.waveOutVolumeDword(-0.5F, -0.5F) == 0x7FFF8000, "vol(-.5,-.5) = 0x7FFF8000");
      check(Math.abs(NativeMediaSound.channelGain(0xBFFF4000, 0) - 16384 / 65535.0) < 1e-12, "ganancia izq 0x4000/0xFFFF");
      check(Math.abs(NativeMediaSound.channelGain(0xBFFF4000, 1) - 49151 / 65535.0) < 1e-12, "ganancia der 0xBFFF/0xFFFF");

      File dir = new File(System.getProperty("java.io.tmpdir"), "media-check-" + System.nanoTime());
      dir.mkdirs();
      File w = wav(dir, "tono.wav", 2400); // 2400 / 8000 = 0.30 s
      String wp = w.getPath();

      // --- PlaySound sincrono ---
      long t0 = System.nanoTime();
      boolean ok = NativeMediaSound.playSound(wp, false);
      double el = (System.nanoTime() - t0) / 1.0E9;
      check(ok, "PlaySound sincrono devuelve true");
      check(el >= 0.28 && el < 1.5, "PlaySound sincrono dura ~0.30 s (medido " + el + ")");
      check(!NativeMediaSound.playSoundActive(), "tras el sincrono no queda nada sonando");

      t0 = System.nanoTime();
      check(!NativeMediaSound.playSound(new File(dir, "noexiste.wav").getPath(), false), "fichero ausente -> false (SND_NODEFAULT)");
      check((System.nanoTime() - t0) / 1.0E9 < 0.2, "fichero ausente vuelve al instante");

      // --- bucle + SND_PURGE ---
      check(NativeMediaSound.playSound(wp, true), "PlaySound en bucle devuelve true");
      Thread.sleep(700L); // mas de dos vueltas de 0.30 s
      check(NativeMediaSound.playSoundActive(), "el bucle sigue tras 0.70 s");
      NativeMediaSound.purgeSound(new File(dir, "otro.wav").getPath());
      check(NativeMediaSound.playSoundActive(), "SND_PURGE de otro nombre no lo para");
      NativeMediaSound.purgeSound(wp.toUpperCase());
      check(!NativeMediaSound.playSoundActive(), "SND_PURGE del mismo nombre (otra caja) lo para");

      // --- un PlaySound nuevo corta al sincrono de otro hilo ---
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
      check(!th.isAlive() && syncEl[0] < 1.5, "el sincrono de 2 s vuelve al ser cortado (medido " + syncEl[0] + ")");

      // --- ASF ---
      check(!NativeMediaSound.asfNativePlay("u:\\x.asf"), "ASF: CreateProcess(bin\\playfile.exe) falla -> false");

      // --- MCI waveaudio ---
      Object a = new Object();
      Object b = new Object();
      check(!NativeMediaSound.mciIsActive(), "MCI inactivo al empezar");
      check(NativeMediaSound.mciStart(a, wp), "MCI waveaudio abre y reproduce");
      check(NativeMediaSound.mciIsActive(), "MCI activo (dueno = a)");
      check(NativeMediaSound.mciIsFinished(b), "isFinished de quien no es dueno -> true");
      check(!NativeMediaSound.mciIsFinished(a), "isFinished del dueno recien empezado -> false");
      check(NativeMediaSound.mciStart(b, wp.toUpperCase()), "mismo fichero: cambia de dueno sin reabrir -> true");
      check(NativeMediaSound.mciIsFinished(a), "el antiguo dueno ya no es dueno");
      Thread.sleep(600L);
      check(NativeMediaSound.mciIsFinished(b), "tras 0.30 s el modo es STOP -> cierra y true");
      check(!NativeMediaSound.mciIsActive(), "tras cerrar, inactivo");
      check(!NativeMediaSound.mciStart(a, new File(dir, "noexiste.wav").getPath()), "MCI con fichero ausente -> false");
      check(!NativeMediaSound.mciIsActive(), "MCI fallido no deja dueno");

      // --- MCI sequencer (.MID en mayusculas: FUN_004508c0 no distingue caja) ---
      Sequence seq = new Sequence(Sequence.PPQ, 480);
      Track tr = seq.createTrack();
      tr.add(new MidiEvent(new ShortMessage(ShortMessage.NOTE_ON, 0, 60, 90), 0L));
      tr.add(new MidiEvent(new ShortMessage(ShortMessage.NOTE_OFF, 0, 60, 0), 480L)); // 1 negra a 120 bpm = 0.5 s
      File mid = new File(dir, "nota.MID");
      MidiSystem.write(seq, 0, mid);
      check(NativeMediaSound.mciStart(a, mid.getPath()), "MCI sequencer abre un .MID");
      check(!NativeMediaSound.mciIsFinished(a), "MIDI sonando al empezar");
      Thread.sleep(1000L);
      check(NativeMediaSound.mciIsFinished(a), "MIDI de 0.5 s terminado tras 1 s");
      NativeMediaSound.mciStart(a, wp);
      NativeMediaSound.mciStop(b);
      check(NativeMediaSound.mciIsActive(), "nativeStop de quien no es dueno no cierra");
      NativeMediaSound.mciStop(a);
      check(!NativeMediaSound.mciIsActive(), "nativeStop del dueno cierra");

      // --- IMA ADPCM (codec ACM de Windows), a mano ---
      NET.worlds.core.ImaAdpcmWav.Channel c = new NET.worlds.core.ImaAdpcmWav.Channel(0, 0);
      // paso 7: nibble 7 -> 0 + 1 + 3 + 7 = 11 ; indice 0+8 = 8
      check(c.decode(7) == 11 && c.index == 8, "IMA: (0,0) nibble 7 -> 11, indice 8");
      // paso 16: nibble 8 -> -(16>>3) = -2 -> 9 ; indice 7
      check(c.decode(8) == 9 && c.index == 7, "IMA: nibble 8 -> 9, indice 7");
      // paso 14: nibble 15 -> -(1+3+7+14) = -25 -> -16 ; indice 15
      check(c.decode(15) == -16 && c.index == 15, "IMA: nibble 15 -> -16, indice 15");
      NET.worlds.core.ImaAdpcmWav.Channel sat = new NET.worlds.core.ImaAdpcmWav.Channel(32760, 88);
      check(sat.decode(7) == 32767 && sat.index == 88, "IMA: satura a 32767 e indice 88");

      // --- los WAV/MIDI reales de GroundZero/wav ---
      File gz = new File("assets/WorldsPlayer/GroundZero/wav");
      File s = new File(gz, "S.wav");
      check(s.isFile() && NET.worlds.core.ImaAdpcmWav.isImaAdpcm(s), "S.wav es IMA ADPCM (formato 0x11)");
      javax.sound.sampled.AudioInputStream sin = NET.worlds.core.ImaAdpcmWav.open(s);
      // data = 121856 bytes / nBlockAlign 256 = 476 bloques x wSamplesPerBlock 505
      // = 240380 muestras; fact dice 0x3ab67 = 240487 (mas de las que hay: manda
      // el minimo). A 0x2bf2 = 11250 Hz: 21.367 s.
      check(sin.getFrameLength() == 240380 && sin.getFormat().getSampleRate() == 11250.0F, "S.wav: 476 bloques x 505 = 240380 muestras a 11250 Hz");
      sin.close();
      check(NativeMediaSound.playSound(s.getPath(), true), "PlaySound en bucle de S.wav abre");
      Thread.sleep(300L);
      check(NativeMediaSound.playSoundActive(), "S.wav sonando");
      NativeMediaSound.purgeSound(s.getPath());
      File lion = new File(gz, "Liondoor.wav");
      // PCM 8 bits mono 22050 Hz, data 0xa8e0 = 43232 bytes -> 1.96 s
      t0 = System.nanoTime();
      check(NativeMediaSound.playSound(lion.getPath(), false), "PlaySound sincrono de Liondoor.wav");
      el = (System.nanoTime() - t0) / 1.0E9;
      check(el >= 1.9 && el < 3.5, "Liondoor.wav dura ~1.96 s (medido " + el + ")");
      File glee = new File(gz, "Glee3.mid");
      check(NativeMediaSound.mciStart(a, glee.getPath()), "MCI sequencer abre Glee3.mid");
      check(!NativeMediaSound.mciIsFinished(a), "Glee3.mid sonando");
      NativeMediaSound.mciStop(a);
      check(!NativeMediaSound.mciIsActive(), "Glee3.mid parado");

      for (File f : dir.listFiles()) {
         f.delete();
      }

      dir.delete();
      System.out.println(fails == 0 ? "MediaSoundCheck: todo OK" : "MediaSoundCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

package NET.worlds.core;

import java.io.File;
import javax.sound.midi.MidiSystem;
import javax.sound.midi.Sequence;
import javax.sound.midi.Sequencer;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.SourceDataLine;

/**
 * Sonido de gamma.dll: {@code WavSoundPlayer} (PlaySound/waveOutSetVolume),
 * {@code MCISoundPlayer} (MCI "waveaudio"/"sequencer") y
 * {@code ASFSoundPlayer} (lanza {@code bin\playfile.exe}). La logica propia
 * del C decompilado (estado global, flags, comparaciones, codigos de modo)
 * se traduce tal cual; lo que en Windows hacia winmm.dll (sacar muestras por
 * la tarjeta, secuenciar MIDI) va por {@code javax.sound.sampled} y
 * {@code javax.sound.midi}.
 *
 * <p>{@code -Dfreeworlds.mute=1}: no se abre ninguna linea de audio ni
 * sintetizador, pero cada sonido "suena" igual en el tiempo (el WAV se
 * consume al ritmo de su frecuencia de muestreo y el MIDI corre en un
 * secuenciador sin receptor), asi que los estados, las duraciones y los
 * bucles del cliente son los mismos que con sonido.
 */
public final class NativeMediaSound {
   private NativeMediaSound() {
   }

   public static final boolean MUTE = "1".equals(System.getProperty("freeworlds.mute"))
      || "true".equalsIgnoreCase(System.getProperty("freeworlds.mute"));

   // Constructores estaticos de gamma.dll que Ghidra no listo como funcion:
   //   0x00420260: DAT_0049d108 = GetPrivateProfileInt("Gamma","disableWav",0,worlds.ini) != 0
   //   0x00420030: DAT_0049cfe0 = ... "disableMIDI" ... != 0 ; DAT_0049cfe4 = ... "disableASF" ... != 0
   // (FUN_004010c0 = GetPrivateProfileIntA con la seccion "Gamma" de worlds.ini,
   // lo mismo que lee IniFile.gamma() del Java).
   static final boolean DISABLE_WAV = iniFlag("disableWav");
   static final boolean DISABLE_MIDI = iniFlag("disableMIDI");
   static final boolean DISABLE_ASF = iniFlag("disableASF");

   private static boolean iniFlag(String key) {
      try {
         return IniFile.gamma().getIniInt(key, 0) != 0;
      } catch (Throwable e) {
         return false;
      }
   }

   static void log(String msg) {
      System.out.println("[media] " + msg);
   }

   // ------------------------------------------------------------------
   // Volumen: WavSoundPlayer.nativeVolume (0x00420120)
   //
   //    local_c = ROUND(65535.0f * right) ; hi = local_c * 0x10000
   //    local_c = ROUND(65535.0f * left)
   //    waveOutSetVolume(0, hi + local_c)
   //
   // _DAT_004711f8 = 65535.0f (bytes 00 ff 7f 47). ROUND es un fistp de x87 en
   // el modo por defecto (al par mas cercano), a 64 bits y truncado a 32. El
   // producto float*float es exacto en la precision extendida de la FPU, asi
   // que Math.rint sobre el double reproduce el redondeo. La suma se hace en
   // int (desborda igual que en el binario si right > 1 o es negativo).
   // waveOutSetVolume: palabra baja = canal izquierdo, alta = derecho,
   // 0xFFFF = volumen maximo. Es el volumen del DISPOSITIVO 0, global para
   // todo lo que suene por waveOut, no el de un sonido concreto.
   // ------------------------------------------------------------------
   public static int waveOutVolumeDword(float left, float right) {
      int hi = (int)(long)Math.rint((double)65535.0F * (double)right) * 0x10000;
      int lo = (int)(long)Math.rint((double)65535.0F * (double)left);
      return hi + lo;
   }

   /** Ganancia lineal del canal (0 = izquierdo, 1 = derecho) que aplica este puente. */
   public static double channelGain(int dword, int channel) {
      int w = channel == 0 ? dword & 0xFFFF : dword >>> 16;
      return w / 65535.0;
   }

   /**
    * Abre un WAV como lo haria Windows: PCM/u-law/a-law por javax.sound; IMA
    * ADPCM (0x11), que Windows decodificaba por ACM, con {@link ImaAdpcmWav}.
    */
   static AudioInputStream openAudio(File f) throws Exception {
      if (ImaAdpcmWav.isImaAdpcm(f)) {
         return ImaAdpcmWav.open(f);
      }

      return AudioSystem.getAudioInputStream(f);
   }

   /** Volumen actual del dispositivo waveOut 0 (arranca al maximo, como Windows). */
   private static volatile int waveOutVolume = 0xFFFFFFFF;

   public static void wavNativeVolume(float left, float right) {
      if (!DISABLE_WAV) {
         waveOutVolume = waveOutVolumeDword(left, right);
      }
   }

   public static int currentWaveOutVolume() {
      return waveOutVolume;
   }

   // ------------------------------------------------------------------
   // PlaySound (winmm): un solo sonido por proceso; cada llamada nueva corta
   // el que este sonando (incluido uno sincrono de otro hilo, que vuelve).
   // ------------------------------------------------------------------
   private static final Object PLAY_LOCK = new Object();
   private static Playback current;

   /** Una reproduccion de PlaySound; tambien la usa la parte "waveaudio" de MCI. */
   public static final class Playback {
      final String name;
      final File file;
      final boolean loop;
      volatile boolean stopped;
      volatile boolean finished;
      final boolean useWaveOutVolume;
      long frames;
      float rate;

      Playback(String name, File file, boolean loop, boolean useWaveOutVolume) {
         this.name = name;
         this.file = file;
         this.loop = loop;
         this.useWaveOutVolume = useWaveOutVolume;
      }

      public void stop() {
         this.stopped = true;
      }

      public boolean isFinished() {
         return this.finished;
      }

      /** Comprueba que el fichero se puede decodificar y lee su duracion. */
      boolean probe() {
         try {
            AudioInputStream in = openAudio(this.file);
            try {
               this.frames = in.getFrameLength();
               this.rate = in.getFormat().getFrameRate();
            } finally {
               in.close();
            }

            return true;
         } catch (Exception e) {
            return false;
         }
      }

      double seconds() {
         return this.rate > 0.0F && this.frames >= 0L ? this.frames / (double)this.rate : -1.0;
      }

      /** Reproduce hasta el final (o en bucle) o hasta stop(). */
      void run() {
         SourceDataLine line = null;

         try {
            do {
               AudioInputStream src = openAudio(this.file);
               AudioFormat f = src.getFormat();
               AudioFormat pcm = new AudioFormat(f.getSampleRate(), 16, 2, true, false);
               AudioInputStream in;
               if (f.getChannels() == 1) {
                  AudioFormat mono = new AudioFormat(f.getSampleRate(), 16, 1, true, false);
                  in = AudioSystem.getAudioInputStream(mono, src);
               } else {
                  in = AudioSystem.getAudioInputStream(pcm, src);
               }

               int inCh = in.getFormat().getChannels();
               if (!MUTE && line == null) {
                  line = AudioSystem.getSourceDataLine(pcm);
                  line.open(pcm);
                  line.start();
               }

               byte[] buf = new byte[4096 * inCh / 2 * 2];
               byte[] out = new byte[buf.length / inCh * 2];
               long t0 = System.nanoTime();
               long played = 0L;

               while (!this.stopped) {
                  int n = in.read(buf, 0, buf.length);
                  if (n <= 0) {
                     break;
                  }

                  n -= n % (2 * inCh);
                  int frames = n / (2 * inCh);
                  if (MUTE) {
                     played += frames;
                     long due = t0 + (long)(played * 1.0E9 / f.getSampleRate());
                     long wait;
                     while (!this.stopped && (wait = due - System.nanoTime()) > 0L) {
                        Thread.sleep(Math.min(50L, wait / 1000000L + 1L));
                     }
                  } else {
                     int vol = this.useWaveOutVolume ? waveOutVolume : 0xFFFFFFFF;
                     double gl = channelGain(vol, 0);
                     double gr = channelGain(vol, 1);
                     int o = 0;
                     for (int i = 0; i < frames; i++) {
                        int b = i * 2 * inCh;
                        int l = (short)(buf[b] & 0xFF | buf[b + 1] << 8);
                        int r = inCh == 1 ? l : (short)(buf[b + 2] & 0xFF | buf[b + 3] << 8);
                        l = (int)Math.round(l * gl);
                        r = (int)Math.round(r * gr);
                        out[o++] = (byte)l;
                        out[o++] = (byte)(l >> 8);
                        out[o++] = (byte)r;
                        out[o++] = (byte)(r >> 8);
                     }

                     line.write(out, 0, o);
                  }
               }

               in.close();
            } while (this.loop && !this.stopped);

            if (line != null) {
               if (this.stopped) {
                  line.flush();
               } else {
                  line.drain();
               }
            }
         } catch (Exception e) {
            log("sin salida de audio para " + this.file + ": " + e);
         } finally {
            if (line != null) {
               line.close();
            }

            this.finished = true;
         }
      }
   }

   /**
    * PlaySoundA(name, NULL, flags) con los flags que usa gamma.dll:
    * SND_FILENAME|SND_NODEFAULT (0x20002) y, si async, SND_ASYNC|SND_LOOP (9).
    * Devuelve false si el fichero no existe o no se decodifica (SND_NODEFAULT:
    * sin sonido por defecto). Sincrono: vuelve al acabar o al ser cortado.
    */
   public static boolean playSound(String name, boolean asyncLoop) {
      File file = NativeMock.localFile(name == null ? "" : name);
      Playback p = new Playback(name, file, asyncLoop, true);
      synchronized (PLAY_LOCK) {
         if (current != null) {
            current.stop();
            current = null;
         }

         if (!file.isFile() || !p.probe()) {
            log("PlaySound: no se puede abrir " + name);
            return false;
         }

         current = p;
      }

      log("PlaySound " + (asyncLoop ? "en bucle" : "sincrono") + ": " + file + " (" + fmtSeconds(p.seconds()) + ")" + (MUTE ? " [mute]" : ""));
      if (asyncLoop) {
         Thread t = new Thread(p::run, "PlaySound " + file.getName());
         t.setDaemon(true);
         t.start();
      } else {
         p.run();
      }

      return true;
   }

   /** PlaySoundA(name, NULL, SND_PURGE): para las instancias de ese sonido. */
   public static void purgeSound(String name) {
      synchronized (PLAY_LOCK) {
         if (current != null && current.name != null && name != null && asciiEqualsIgnoreCase(current.name, name)) {
            current.stop();
            current = null;
         }
      }
   }

   /** Para pruebas: si hay un PlaySound activo sin terminar. */
   public static boolean playSoundActive() {
      synchronized (PLAY_LOCK) {
         return current != null && !current.finished && !current.stopped;
      }
   }

   // WavSoundPlayer.nativePlay (0x00420190): lee el campo playingSoundFile
   // (resuelto en nativeInit 0x004200b0) y, si no esta disableWav,
   // PlaySoundA(fichero, NULL, (loop ? 9 : 0) | 0x20002).
   public static void wavNativePlay(String playingSoundFile, boolean loop) {
      if (!DISABLE_WAV) {
         playSound(playingSoundFile, loop);
      }
   }

   // WavSoundPlayer.nativeStop (0x00420200): PlaySoundA(fichero, NULL, 0x40).
   public static void wavNativeStop(String playingSoundFile) {
      if (!DISABLE_WAV) {
         purgeSound(playingSoundFile);
      }
   }

   static String fmtSeconds(double s) {
      return s < 0.0 ? "duracion desconocida" : String.format(java.util.Locale.ROOT, "%.2f s", s);
   }

   /** FUN_004508c0: comparacion con la tabla DAT_00482818 (solo A-Z -> a-z). */
   public static boolean asciiEqualsIgnoreCase(String a, String b) {
      if (a.length() != b.length()) {
         return false;
      }

      for (int i = 0; i < a.length(); i++) {
         char x = a.charAt(i);
         char y = b.charAt(i);
         if (x >= 'A' && x <= 'Z') {
            x = (char)(x + 32);
         }

         if (y >= 'A' && y <= 'Z') {
            y = (char)(y + 32);
         }

         if (x != y) {
            return false;
         }
      }

      return true;
   }

   // ------------------------------------------------------------------
   // MCI (MCISoundPlayer 0x0041f780..0x0041fe40). Estado global de gamma.dll:
   //   DAT_0049cfe8  referencia global al MCISoundPlayer dueno del dispositivo
   //   DAT_0049cfec  MCIDEVICEID abierto (0xffffffff si ninguno)
   //   DAT_0049cff0  char[256] nombre del fichero abierto
   //   DAT_0049d0f0  1 si el nombre acaba en ".mid" (sequencer), 0 waveaudio
   // ------------------------------------------------------------------
   static final int MCI_MODE_NOT_READY = 0x20c;
   static final int MCI_MODE_STOP = 0x20d;
   static final int MCI_MODE_PLAY = 0x20e;
   static final int MCI_MODE_OPEN = 0x212;

   private static Object mciOwner;
   private static MciDevice mciDevice;
   private static String mciOpenName = "";
   private static boolean mciIsMidi;

   /** Un dispositivo MCI abierto: "waveaudio" (javax.sound.sampled) o "sequencer" (javax.sound.midi). */
   interface MciDevice {
      void play() throws Exception;

      int mode();

      void close();

      String describe();
   }

   static final class WaveDevice implements MciDevice {
      final Playback p;
      Thread thread;

      WaveDevice(Playback p) {
         this.p = p;
      }

      public void play() {
         this.thread = new Thread(this.p::run, "MCI waveaudio " + this.p.file.getName());
         this.thread.setDaemon(true);
         this.thread.start();
      }

      public int mode() {
         return this.thread == null || this.p.finished ? MCI_MODE_STOP : MCI_MODE_PLAY;
      }

      public void close() {
         this.p.stop();
      }

      public String describe() {
         return "waveaudio " + this.p.file + " (" + fmtSeconds(this.p.seconds()) + ")";
      }
   }

   static final class SeqDevice implements MciDevice {
      final File file;
      final Sequencer seq;
      final double seconds;
      boolean started;

      SeqDevice(File file) throws Exception {
         this.file = file;
         Sequence s = MidiSystem.getSequence(file);
         // Mute: secuenciador sin receptor (mismo reloj, sin sintetizador).
         this.seq = MidiSystem.getSequencer(!MUTE);
         this.seq.open();
         this.seq.setSequence(s);
         this.seconds = s.getMicrosecondLength() / 1.0E6;
      }

      public void play() {
         this.seq.start();
         this.started = true;
      }

      public int mode() {
         return this.started && this.seq.isRunning() ? MCI_MODE_PLAY : MCI_MODE_STOP;
      }

      public void close() {
         try {
            this.seq.stop();
         } catch (Exception e) {
         }

         this.seq.close();
      }

      public String describe() {
         return "sequencer " + this.file + " (" + fmtSeconds(this.seconds) + ")";
      }
   }

   /** MCI_OPEN con MCI_OPEN_TYPE|MCI_OPEN_ELEMENT (0x2200); null y mensaje si falla. */
   static MciDevice mciOpen(String type, String element, String[] error) {
      File f = NativeMock.localFile(element);
      if (!f.isFile()) {
         error[0] = "MCIERR_FILE_NOT_FOUND: " + element;
         return null;
      }

      try {
         if ("sequencer".equals(type)) {
            return new SeqDevice(f);
         }

         Playback p = new Playback(element, f, false, false);
         if (!p.probe()) {
            error[0] = "MCIERR_INVALID_FILE: " + element;
            return null;
         }

         return new WaveDevice(p);
      } catch (Exception e) {
         error[0] = "MCIERR_DEVICE_OPEN (" + type + "): " + e;
         return null;
      }
   }

   /** Impresion de error de gamma.dll: "mci Error: " + texto + "\n" en el ostream global 0x49eda8. */
   static void mciError(String text) {
      System.out.println("mci Error: " + text);
   }

   private static void mciCloseCurrent() {
      // if (!disableMIDI) mciSendCommand(id, MCI_CLOSE); id = -1; DeleteGlobalRef(owner)
      if (!DISABLE_MIDI && mciDevice != null) {
         mciDevice.close();
      }

      mciDevice = null;
      mciOwner = null;
   }

   // MCISoundPlayer.nativeStart (0x0041f890)
   public static synchronized boolean mciStart(Object self, String name) {
      mciIsMidi = name.length() > 3 && asciiEqualsIgnoreCase(name.substring(name.length() - 4), ".mid");
      if (mciOwner != null) {
         if (asciiEqualsIgnoreCase(name, mciOpenName)) {
            // mismo fichero: solo cambia de dueno, no se reinicia
            mciOwner = self;
            return true;
         }

         mciCloseCurrent();
      }

      mciOpenName = name;
      String type = mciIsMidi ? "sequencer" : "waveaudio";
      if (DISABLE_MIDI) {
         return false;
      }

      String[] err = new String[1];
      MciDevice dev = mciOpen(type, name, err);
      if (dev == null) {
         mciError(err[0]);
         return false;
      }

      mciOwner = self;
      mciDevice = dev;

      try {
         dev.play();
      } catch (Exception e) {
         mciError("MCI_PLAY: " + e);
         mciCloseCurrent();
         return false;
      }

      log("MCI " + dev.describe() + (MUTE ? " [mute]" : ""));
      return true;
   }

   // MCISoundPlayer.nativeStop (0x0041fd20)
   public static synchronized void mciStop(Object self) {
      if (self == mciOwner && mciOwner != null) {
         mciCloseCurrent();
      }
   }

   // MCISoundPlayer.nativeIsFinished (0x0041fe40): MCI_STATUS_MODE; si no es
   // STOP (0x20d) ni OPEN (0x212) sigue sonando; si no, cierra y da true.
   public static synchronized boolean mciIsFinished(Object self) {
      if (self != mciOwner || mciOwner == null) {
         return true;
      }

      if (!DISABLE_MIDI) {
         int mode = mciDevice.mode();
         if (mode != MCI_MODE_STOP && mode != MCI_MODE_OPEN) {
            return false;
         }
      }

      mciCloseCurrent();
      return true;
   }

   // MCISoundPlayer.isActive (0x0041fe30)
   public static synchronized boolean mciIsActive() {
      return mciOwner != null;
   }

   // MCISoundPlayer.shutdown (0x0041f790)
   public static synchronized void mciShutdown() {
      if (mciOwner != null) {
         mciCloseCurrent();
      }
   }

   // ------------------------------------------------------------------
   // ASFSoundPlayer.nativePlay (0x0041f670): si disableASF devuelve true sin
   // hacer nada; si no, CreateProcess("<GetFullPathName(bin\playfile.exe)> " +
   // fichero), espera a que acabe y devuelve true; false si CreateProcess
   // falla. bin\playfile.exe no esta en la instalacion de 2004
   // (assets/WorldsPlayer/bin) y un .exe de Windows no se puede lanzar aqui:
   // es el camino de CreateProcess fallido. ASFThread lo trata poniendo
   // player.running = 3 (IS_ERROR).
   // ------------------------------------------------------------------
   public static boolean asfNativePlay(String name) {
      if (DISABLE_ASF) {
         return true;
      }

      log("ASF no disponible: CreateProcess(bin\\playfile.exe " + name + ") falla -> false");
      return false;
   }
}

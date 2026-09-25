package NET.worlds.core;

import java.io.IOException;

/**
 * {@code CDPlayerAction} de gamma.dll (0x004153e0..0x00415ea0): CD de audio
 * por MCI "cdaudio". El JDK no tiene acceso a CD de audio, asi que se
 * traduce cada nativo contra un MCI sin ninguna unidad "cdaudio": el mismo
 * resultado que el original en un PC sin lector. {@code MCI_OPEN} de
 * "cdaudio" en "C:".."Z:" falla, y cualquier orden sobre un MCIDEVICEID
 * falla (MCIERR_INVALID_DEVICE_ID); los nativos lanzan entonces la
 * {@code IOException} con el mensaje literal del binario. {@code CDAudio} y
 * {@code CDPlayerAction} recorren 0 unidades y no llegan a abrir ninguna.
 */
public final class NativeMediaCd {
   private NativeMediaCd() {
   }

   /** DAT_0046fd98: numero de unidades, -1 hasta el primer getNumDrives. */
   private static int numDrives = -1;
   /** DAT_0048949d: letras de las unidades encontradas (.bss, a cero). */
   private static final byte[] driveLetters = new byte[24];
   /** DAT_0049f960: codigo de autoplay de NT (solo se guarda). */
   private static int ntAutoPlayCode;

   /** mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE|ELEMENT|SHAREABLE..., "cdaudio", "X:"): sin unidades, falla. */
   static int mciOpenCdAudio(String element) {
      return 0;
   }

   /** Cualquier mciSendCommand sobre un dispositivo: sin cdaudio abierto, error. */
   static boolean mciCommand(int deviceId, int msg) {
      return false;
   }

   /** Bloque comun: si la orden falla, MCI_CLOSE si id != 0 y false. */
   private static boolean command(int id, int msg) {
      if (mciCommand(id, msg)) {
         return true;
      }

      if (id != 0) {
         mciCommand(id, 0x804);
      }

      return false;
   }

   // 0x004153e0: prueba "C:".."Z:" (DAT_0046fdc0 = "X:" con la letra cambiada)
   public static synchronized int getNumDrives() {
      if (numDrives == -1) {
         numDrives = 0;

         for (char c = 'C'; c < '['; c++) {
            int id = mciOpenCdAudio(c + ":");
            if (id != 0) {
               driveLetters[numDrives++] = (byte)c;
               mciCommand(id, 0x804);
            }
         }
      }

      return numDrives;
   }

   // 0x004154d0: (char)DAT_0048949d[i] - 'A'. Con la tabla a cero da -65; fuera
   // de la tabla el original lee memoria contigua (aqui tambien -65).
   public static synchronized int getDriveLetterOffset(int i) {
      byte b = i >= 0 && i < driveLetters.length ? driveLetters[i] : 0;
      return b - 0x41;
   }

   // 0x004154f0
   public static synchronized int openDrive(int i) throws IOException {
      byte b = i >= 0 && i < driveLetters.length ? driveLetters[i] : 0;
      int id = mciOpenCdAudio((char)b + ":");
      if (id != 0) {
         return id;
      }

      throw new IOException("openDrive");
   }

   // 0x004155e0: MCI_CLOSE (0x804) sin el cierre extra
   public static void closeDrive(int id) throws IOException {
      if (!mciCommand(id, 0x804)) {
         throw new IOException("closeDrive");
      }
   }

   // 0x00415650: MCI_STATUS (0x814) MCI_STATUS_NUMBER_OF_TRACKS
   public static void checkDrive(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("checkDrive");
      }
   }

   // 0x004156e0: el primer MCI_STATUS fallido da "getDriveTrackList2"; el
   // "getDriveTrackList" es para un fallo a mitad de la lista de pistas.
   public static Object getDriveTrackList(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("getDriveTrackList2");
      }

      throw new IllegalStateException("inalcanzable: no hay dispositivo cdaudio");
   }

   /** 0x00415a80: frames (1/75 s) a MCI_FORMAT_MSF, 0x1194 = 4500 = 60*75. */
   public static int toMsf(int frames) {
      int u = frames;
      return Integer.remainderUnsigned(Integer.remainderUnsigned(u, 0x1194), 0x4b) << 16
         | Integer.divideUnsigned(Integer.remainderUnsigned(u, 0x1194), 0x4b) << 8
         | Integer.divideUnsigned(u, 0x1194) & 0xFF;
   }

   /** 0x00415dc0: MCI_FORMAT_MSF a frames. */
   public static int fromMsf(int msf) {
      return ((msf & 0xFFFF) >> 8) * 0x4b + (msf & 0xFF) * 0x1194 + (msf >>> 16 & 0xFF);
   }

   // 0x00415a80: MCI_PLAY (0x806) MCI_FROM|MCI_TO con MSF
   public static void playAudio(int id, int from, int to) throws IOException {
      int msfFrom = toMsf(from);
      int msfTo = toMsf(to);
      if (!command(id, 0x806)) {
         NativeMediaSound.log(String.format("CD no disponible: MCI_PLAY %06x..%06x (MSF)", msfFrom, msfTo));
         throw new IOException("playAudio");
      }
   }

   // 0x00415ba0: MCI_STOP (0x808)
   public static void stopAudio(int id) throws IOException {
      if (!command(id, 0x808)) {
         throw new IOException("stopAudio");
      }
   }

   // 0x00415c20: MCI_PAUSE (0x809)
   public static void pauseAudio(int id) throws IOException {
      if (!command(id, 0x809)) {
         throw new IOException("pauseAudio");
      }
   }

   // 0x00415ca0: MCI_RESUME (0x855); el binario reutiliza la cadena
   // s_pauseAudio_0046fe64 para el mensaje.
   public static void resumeAudio(int id) throws IOException {
      if (!command(id, 0x855)) {
         throw new IOException("pauseAudio");
      }
   }

   // 0x00415d20: MCI_STATUS_MODE == MCI_MODE_PLAY (0x20e)
   public static boolean isPlaying(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("isPlaying");
      }

      throw new IllegalStateException("inalcanzable: no hay dispositivo cdaudio");
   }

   // 0x00415dc0: MCI_STATUS_POSITION en MSF
   public static int getPosition(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("getPosition");
      }

      throw new IllegalStateException("inalcanzable: no hay dispositivo cdaudio");
   }

   // 0x00415e90
   public static synchronized void setNTAutoPlayCode(int code) {
      ntAutoPlayCode = code;
   }

   // 0x00415ea0: FindWindow("Volume Control") y si no ShellExecuteEx("sndvol32.exe");
   // aqui no hay ni ventana ni ejecutable -> false (hInstApp <= 32).
   public static boolean launchVolumeControlApp() {
      NativeMediaSound.log("sndvol32.exe no disponible");
      return false;
   }
}

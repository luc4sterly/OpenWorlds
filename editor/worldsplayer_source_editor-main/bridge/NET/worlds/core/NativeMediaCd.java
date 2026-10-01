package NET.worlds.core;

import java.io.IOException;

/**
 * gamma.dll's {@code CDPlayerAction} (0x004153e0..0x00415ea0): audio CD
 * through MCI "cdaudio". The JDK has no access to audio CDs, so each native
 * is translated against an MCI without any "cdaudio" drive: the same
 * result as the original on a PC with no reader. {@code MCI_OPEN} of
 * "cdaudio" on "C:".."Z:" fails, and any command on an MCIDEVICEID
 * fails (MCIERR_INVALID_DEVICE_ID); the natives then throw the
 * {@code IOException} with the binary's literal message. {@code CDAudio} and
 * {@code CDPlayerAction} iterate over 0 drives and never get to open any.
 */
public final class NativeMediaCd {
   private NativeMediaCd() {
   }

   /** DAT_0046fd98: number of drives, -1 until the first getNumDrives. */
   private static int numDrives = -1;
   /** DAT_0048949d: letters of the drives found (.bss, zeroed). */
   private static final byte[] driveLetters = new byte[24];
   /** DAT_0049f960: NT autoplay code (only stored). */
   private static int ntAutoPlayCode;

   /** mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE|ELEMENT|SHAREABLE..., "cdaudio", "X:"): with no drives, it fails. */
   static int mciOpenCdAudio(String element) {
      return 0;
   }

   /** Any mciSendCommand on a device: with no cdaudio open, error. */
   static boolean mciCommand(int deviceId, int msg) {
      return false;
   }

   /** Common block: if the command fails, MCI_CLOSE if id != 0, and false. */
   private static boolean command(int id, int msg) {
      if (mciCommand(id, msg)) {
         return true;
      }

      if (id != 0) {
         mciCommand(id, 0x804);
      }

      return false;
   }

   // 0x004153e0: tries "C:".."Z:" (DAT_0046fdc0 = "X:" with the letter changed)
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

   // 0x004154d0: (char)DAT_0048949d[i] - 'A'. With the table zeroed it gives
   // -65; outside the table the original reads adjacent memory (here also -65).
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

   // 0x004155e0: MCI_CLOSE (0x804) without the extra close
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

   // 0x004156e0: the first failed MCI_STATUS gives "getDriveTrackList2";
   // "getDriveTrackList" is for a failure halfway through the track list.
   public static Object getDriveTrackList(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("getDriveTrackList2");
      }

      throw new IllegalStateException("unreachable: there is no cdaudio device");
   }

   /** 0x00415a80: frames (1/75 s) to MCI_FORMAT_MSF, 0x1194 = 4500 = 60*75. */
   public static int toMsf(int frames) {
      int u = frames;
      return Integer.remainderUnsigned(Integer.remainderUnsigned(u, 0x1194), 0x4b) << 16
         | Integer.divideUnsigned(Integer.remainderUnsigned(u, 0x1194), 0x4b) << 8
         | Integer.divideUnsigned(u, 0x1194) & 0xFF;
   }

   /** 0x00415dc0: MCI_FORMAT_MSF to frames. */
   public static int fromMsf(int msf) {
      return ((msf & 0xFFFF) >> 8) * 0x4b + (msf & 0xFF) * 0x1194 + (msf >>> 16 & 0xFF);
   }

   // 0x00415a80: MCI_PLAY (0x806) MCI_FROM|MCI_TO with MSF
   public static void playAudio(int id, int from, int to) throws IOException {
      int msfFrom = toMsf(from);
      int msfTo = toMsf(to);
      if (!command(id, 0x806)) {
         NativeMediaSound.log(String.format("CD not available: MCI_PLAY %06x..%06x (MSF)", msfFrom, msfTo));
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

   // 0x00415ca0: MCI_RESUME (0x855); the binary reuses the string
   // s_pauseAudio_0046fe64 for the message.
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

      throw new IllegalStateException("unreachable: there is no cdaudio device");
   }

   // 0x00415dc0: MCI_STATUS_POSITION in MSF
   public static int getPosition(int id) throws IOException {
      if (!command(id, 0x814)) {
         throw new IOException("getPosition");
      }

      throw new IllegalStateException("unreachable: there is no cdaudio device");
   }

   // 0x00415e90
   public static synchronized void setNTAutoPlayCode(int code) {
      ntAutoPlayCode = code;
   }

   // 0x00415ea0: FindWindow("Volume Control") and, failing that, ShellExecuteEx("sndvol32.exe");
   // here there is neither a window nor an executable -> false (hInstApp <= 32).
   public static boolean launchVolumeControlApp() {
      NativeMediaSound.log("sndvol32.exe not available");
      return false;
   }
}

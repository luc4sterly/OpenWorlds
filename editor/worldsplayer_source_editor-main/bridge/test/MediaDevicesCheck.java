import NET.worlds.core.NativeMediaCd;
import NET.worlds.core.NativeMediaVideo;
import NET.worlds.scape.DirectShow;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;

/**
 * DirectShow y CD de audio sin sus equivalentes: el camino de fallo del
 * binario. Casos a mano:
 *  - nInit(0) -> renderer de audio; nInit(hwnd) -> DX8 falla -> DX7, con los
 *    mensajes literales de 0x00477cf0/0x00478354/0x004780a4 en ese orden.
 *  - nOpen imprime "Can't create filter graph for <f>" (0x00478030) y el
 *    estado sigue en 0: nTick = 0 -> WMPSoundPlayer.getState = IS_STOPPED.
 *  - CD: 0 unidades, cada nativo lanza IOException con la cadena del binario
 *    (resumeAudio con "pauseAudio"); MSF: 4500 frames = 1 min.
 */
public class MediaDevicesCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FALLO") + " " + what);
      if (!ok) {
         fails++;
      }
   }

   interface Io {
      void run() throws IOException;
   }

   static void throwsIo(String msg, Io r) {
      try {
         r.run();
         check(false, msg + ": deberia lanzar IOException");
      } catch (IOException e) {
         check(msg.equals(e.getMessage()), "IOException(\"" + msg + "\") (lanzada: " + e.getMessage() + ")");
      }
   }

   static String capture(Runnable r) {
      PrintStream old = System.out;
      ByteArrayOutputStream b = new ByteArrayOutputStream();
      System.setOut(new PrintStream(b, true));
      try {
         r.run();
      } finally {
         System.setOut(old);
      }

      return b.toString();
   }

   public static void main(String[] args) throws Exception {
      // --- DirectShow, audio (WMPSoundPlayer) ---
      final int[] h = new int[1];
      String out = capture(() -> h[0] = NativeMediaVideo.nInit(0));
      check("audio".equals(NativeMediaVideo.kindOf(h[0])), "nInit(0) crea el renderer de audio");
      check(out.isEmpty(), "el renderer de audio no imprime nada al iniciar");
      check(NativeMediaVideo.nTick(h[0]) == 0, "estado inicial 0");
      out = capture(() -> NativeMediaVideo.nOpen(h[0], "c:\\x.mp3"));
      check(out.contains("Can't create filter graph for c:\\x.mp3\n"), "nOpen: mensaje de 0x00478030 con el nombre");
      NativeMediaVideo.nPlay(h[0], 1);
      check(NativeMediaVideo.nTick(h[0]) == 0, "tras nPlay sigue en 0 (play exige estado 1 o 2)");
      NativeMediaVideo.nPause(h[0]);
      NativeMediaVideo.nStop(h[0]);
      check(NativeMediaVideo.nTick(h[0]) == 0, "pause/stop sin efecto");
      NativeMediaVideo.nShutdown(h[0]);
      check(NativeMediaVideo.kindOf(h[0]) == null, "nShutdown borra el renderer");

      // --- DirectShow, video (VideoSurface/VideoTexture) ---
      out = capture(() -> h[0] = NativeMediaVideo.nInit(0x1234));
      String esperado = "Could not create filter graph.\n"
         + "Could not create DirectX 8 media renderer; falling back to DX7.\n"
         + "Couldn't create DirectDrawFactory\n";
      check(esperado.equals(out), "nInit(hwnd): DX8 falla, cae a DX7, un solo DirectDrawFactory (recibido: " + out.replace("\n", "|") + ")");
      check("DX7".equals(NativeMediaVideo.kindOf(h[0])), "renderer DX7 de respaldo");
      out = capture(() -> NativeMediaVideo.nOpen(h[0], "http://x/eminem.asf"));
      check(out.contains("Could not create a CLSID_MultiMediaStream object\nCheck you have run regsvr32 amstream.dll\n\n"), "nOpen DX7: mensaje de 0x004781b4");
      NativeMediaVideo.nPlay(h[0], 1);
      NativeMediaVideo.nRenderTo(h[0], 0x1234, 0);
      check(NativeMediaVideo.nTick(h[0]) == 0, "video: estado 0");
      NativeMediaVideo.nShutdown(h[0]);

      // --- la clase Java real ---
      DirectShow ds = new DirectShow();
      ds.nOpen("u:\\sonido.asf");
      ds.nPlay(1);
      check(ds.nTick() == 0, "DirectShow Java: nTick 0 -> WMPSoundPlayer IS_STOPPED");
      ds.finalize();

      // --- CD ---
      check(NativeMediaCd.getNumDrives() == 0, "getNumDrives = 0");
      check(NativeMediaCd.getNumDrives() == 0, "getNumDrives cacheado = 0");
      check(NativeMediaCd.getDriveLetterOffset(0) == -65, "getDriveLetterOffset(0) = 0 - 'A' = -65");
      throwsIo("openDrive", () -> NativeMediaCd.openDrive(0));
      throwsIo("closeDrive", () -> NativeMediaCd.closeDrive(1));
      throwsIo("checkDrive", () -> NativeMediaCd.checkDrive(1));
      throwsIo("getDriveTrackList2", () -> NativeMediaCd.getDriveTrackList(1));
      throwsIo("playAudio", () -> NativeMediaCd.playAudio(1, 0, 4500));
      throwsIo("stopAudio", () -> NativeMediaCd.stopAudio(1));
      throwsIo("pauseAudio", () -> NativeMediaCd.pauseAudio(1));
      throwsIo("pauseAudio", () -> NativeMediaCd.resumeAudio(1));
      throwsIo("isPlaying", () -> NativeMediaCd.isPlaying(1));
      throwsIo("getPosition", () -> NativeMediaCd.getPosition(1));
      check(!NativeMediaCd.launchVolumeControlApp(), "launchVolumeControlApp -> false");
      // MSF: 4500 frames = 1:00:00 -> 0x000001 ; 4500+75*2+3 = 1:02:03 -> 0x030201
      check(NativeMediaCd.toMsf(4500) == 0x000001, "toMsf(4500) = 0x000001");
      check(NativeMediaCd.toMsf(4653) == 0x030201, "toMsf(4653) = 0x030201");
      check(NativeMediaCd.fromMsf(0x030201) == 4653, "fromMsf(0x030201) = 4653");
      check(NET.worlds.scape.CDPlayerAction.getNumDrives() == 0, "CDPlayerAction.getNumDrives Java = 0");

      System.out.println(fails == 0 ? "MediaDevicesCheck: todo OK" : "MediaDevicesCheck: " + fails + " fallos");
      System.exit(fails == 0 ? 0 : 1);
   }
}

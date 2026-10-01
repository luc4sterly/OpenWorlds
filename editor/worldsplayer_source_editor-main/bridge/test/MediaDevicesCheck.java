import NET.worlds.core.NativeMediaCd;
import NET.worlds.core.NativeMediaVideo;
import NET.worlds.scape.DirectShow;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.PrintStream;

/**
 * DirectShow and audio CD with no system equivalent available: the binary's
 * failure path. Hand-made cases:
 *  - nInit(0) -> audio renderer; nInit(hwnd) -> DX8 fails -> DX7, with the
 *    literal messages of 0x00477cf0/0x00478354/0x004780a4 in that order.
 *  - nOpen prints "Can't create filter graph for <f>" (0x00478030) and the
 *    state stays at 0: nTick = 0 -> WMPSoundPlayer.getState = IS_STOPPED.
 *  - CD: 0 drives, each native throws IOException with the binary's string
 *    (resumeAudio with "pauseAudio"); MSF: 4500 frames = 1 min.
 */
public class MediaDevicesCheck {
   static int fails = 0;

   static void check(boolean ok, String what) {
      System.out.println((ok ? "OK   " : "FAIL ") + " " + what);
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
         check(false, msg + ": should throw IOException");
      } catch (IOException e) {
         check(msg.equals(e.getMessage()), "IOException(\"" + msg + "\") (thrown: " + e.getMessage() + ")");
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
      check("audio".equals(NativeMediaVideo.kindOf(h[0])), "nInit(0) creates the audio renderer");
      check(out.isEmpty(), "the audio renderer prints nothing on start");
      check(NativeMediaVideo.nTick(h[0]) == 0, "initial state 0");
      out = capture(() -> NativeMediaVideo.nOpen(h[0], "c:\\x.mp3"));
      check(out.contains("Can't create filter graph for c:\\x.mp3\n"), "nOpen: message of 0x00478030 with the name");
      NativeMediaVideo.nPlay(h[0], 1);
      check(NativeMediaVideo.nTick(h[0]) == 0, "after nPlay it stays at 0 (play requires state 1 or 2)");
      NativeMediaVideo.nPause(h[0]);
      NativeMediaVideo.nStop(h[0]);
      check(NativeMediaVideo.nTick(h[0]) == 0, "pause/stop have no effect");
      NativeMediaVideo.nShutdown(h[0]);
      check(NativeMediaVideo.kindOf(h[0]) == null, "nShutdown deletes the renderer");

      // --- DirectShow, video (VideoSurface/VideoTexture) ---
      out = capture(() -> h[0] = NativeMediaVideo.nInit(0x1234));
      String expected = "Could not create filter graph.\n"
         + "Could not create DirectX 8 media renderer; falling back to DX7.\n"
         + "Couldn't create DirectDrawFactory\n";
      check(expected.equals(out), "nInit(hwnd): DX8 fails, falls back to DX7, a single DirectDrawFactory (received: " + out.replace("\n", "|") + ")");
      check("DX7".equals(NativeMediaVideo.kindOf(h[0])), "fallback DX7 renderer");
      out = capture(() -> NativeMediaVideo.nOpen(h[0], "http://x/eminem.asf"));
      check(out.contains("Could not create a CLSID_MultiMediaStream object\nCheck you have run regsvr32 amstream.dll\n\n"), "nOpen DX7: message of 0x004781b4");
      NativeMediaVideo.nPlay(h[0], 1);
      NativeMediaVideo.nRenderTo(h[0], 0x1234, 0);
      check(NativeMediaVideo.nTick(h[0]) == 0, "video: state 0");
      NativeMediaVideo.nShutdown(h[0]);

      // --- the real Java class ---
      DirectShow ds = new DirectShow();
      ds.nOpen("u:\\sound.asf");
      ds.nPlay(1);
      check(ds.nTick() == 0, "DirectShow Java: nTick 0 -> WMPSoundPlayer IS_STOPPED");
      ds.finalize();

      // --- CD ---
      check(NativeMediaCd.getNumDrives() == 0, "getNumDrives = 0");
      check(NativeMediaCd.getNumDrives() == 0, "getNumDrives cached = 0");
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

      System.out.println(fails == 0 ? "MediaDevicesCheck: all OK" : "MediaDevicesCheck: " + fails + " failures");
      System.exit(fails == 0 ? 0 : 1);
   }
}

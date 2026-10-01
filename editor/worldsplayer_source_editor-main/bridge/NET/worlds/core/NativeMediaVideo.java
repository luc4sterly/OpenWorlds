package NET.worlds.core;

import java.util.HashMap;

/**
 * gamma.dll's {@code DirectShow} (0x0043f180..0x0043f450) without DirectShow.
 *
 * <p>The Java code keeps in {@code mediaRendererInstancePtr} a C++ object of
 * one of three classes, all with the same vtable (+0 destructor, +4 renderTo,
 * +8 init, +0xc shutdown, +0x10 tick, +0x14 open, +0x18 play, +0x1c pause,
 * +0x20 stop), the state at +8 (0 uninitialized, 1 stopped, 2 paused,
 * 3 playing) and the repeat count at +4:
 * <ul>
 * <li>audio, {@code nInit(0)}: 0x34 bytes, vtable 0x00478b20
 *     ({@code WMPSoundPlayer});</li>
 * <li>"DX8", {@code nInit(hwnd)}: 0x28 bytes, vtable 0x004788f0;</li>
 * <li>"DX7" as a fallback if DX8 does not start: 0x60 bytes, vtable
 *     0x00478af4 ({@code VideoSurface}/{@code VideoTexture}).</li>
 * </ul>
 * Each one starts by creating a DirectShow/DirectDraw COM object with
 * {@code CoCreateInstance}. This system has neither COM nor DirectShow, so
 * the binary's own path for that failure is followed (that of a Windows
 * without DirectX Media): it prints its message, leaves the state at 0 and
 * all later operations are skipped by their state guards.
 * {@code nTick} returns 0, so {@code WMPSoundPlayer.getState} gives
 * IS_STOPPED and the {@code Sound} closes itself; no sound or video
 * appears to play.
 */
public final class NativeMediaVideo {
   private NativeMediaVideo() {
   }

   /** States of the C++ object (+8), equal to the static finals in the Java code. */
   public static final int UNINITIALIZED = 0;
   public static final int STOPPED = 1;
   public static final int PAUSED = 2;
   public static final int PLAYING = 3;

   /** C++ renderer; the path that does not depend on COM is translated in full. */
   abstract static class Renderer {
      int state; // +8
      int repeats; // +4

      abstract String kind();

      abstract boolean init();

      abstract void open(String name);

      abstract void play(int n);

      abstract void pause();

      abstract void stop();

      int tick() {
         return this.state;
      }

      void renderTo(int hwnd, int hdc) {
      }

      void shutdown() {
      }
   }

   /** 0x0043fdb0: audio. graph = +0xc (IGraphBuilder), event = +0x10. */
   static final class AudioRenderer extends Renderer {
      String kind() {
         return "audio";
      }

      // 0x0043fdf0: CoInitialize; state = 0; return 1
      boolean init() {
         this.state = 0;
         return true;
      }

      // 0x0043ffc0 -> 0x0043fe30: CoCreateInstance(CLSID_FilterGraph) fails ->
      // printf("Can't create filter graph for %s\n", name), returns 0 and the
      // state stays at 0 (it sets it to 0 before trying).
      void open(String name) {
         if (name != null) {
            this.state = 0;
            System.out.println("Can't create filter graph for " + name);
         }
      }

      // 0x0043fff0: only from 1 or 2
      void play(int n) {
         if (this.state == STOPPED || this.state == PAUSED) {
            throw new IllegalStateException("unreachable without a filter graph");
         }
      }

      // 0x00440070: only from 3 or 1
      void pause() {
         if (this.state == PLAYING || this.state == STOPPED) {
            throw new IllegalStateException("unreachable without a filter graph");
         }
      }

      // 0x004400f0: only from 3 or 2
      void stop() {
         if (this.state == PLAYING || this.state == PAUSED) {
            throw new IllegalStateException("unreachable without a filter graph");
         }
      }
      // tick 0x004401a0: without an event (+0x10 == 0) it returns the state.
      // renderTo 0x00441870: empty. shutdown 0x0043fe10: CoUninitialize.
   }

   /** 0x00440f60: DX8. */
   static final class Dx8Renderer extends Renderer {
      String kind() {
         return "DX8";
      }

      // 0x00440fa0: state = 0; CoCreateInstance(CLSID_FilterGraph) fails ->
      // "Could not create filter graph." + "\n" and returns 0.
      boolean init() {
         this.state = 0;
         System.out.print("Could not create filter graph.");
         System.out.print("\n");
         return false;
      }

      // init always fails and nInit replaces it with DX7: the rest is never called.
      void open(String name) {
         throw new IllegalStateException("DX8 without a filter graph: nInit falls back to DX7");
      }

      void play(int n) {
         throw new IllegalStateException("DX8 without a filter graph: nInit falls back to DX7");
      }

      void pause() {
         throw new IllegalStateException("DX8 without a filter graph: nInit falls back to DX7");
      }

      void stop() {
         throw new IllegalStateException("DX8 without a filter graph: nInit falls back to DX7");
      }
   }

   /** 0x00440320: fallback DX7; hwnd at +0x3c, ddInit at +0x34, opened at +0x38. */
   static final class Dx7Renderer extends Renderer {
      final int hwnd;
      boolean ddInit;
      boolean opened;

      Dx7Renderer(int hwnd) {
         this.hwnd = hwnd;
      }

      String kind() {
         return "DX7";
      }

      // 0x00440380: CoInitialize; state = 0; if hwnd and not ddInit ->
      // FUN_00440460 (its result is ignored) and ddInit = 1. FUN_00440460:
      // CoCreateInstance(CLSID_DirectDrawFactory) fails ->
      // "Couldn't create DirectDrawFactory" + "\n".
      boolean init() {
         this.state = 0;
         if (this.hwnd != 0 && !this.ddInit) {
            System.out.print("Couldn't create DirectDrawFactory");
            System.out.print("\n");
            this.ddInit = true;
         }

         return true;
      }

      // 0x004403f0 -> 0x00440770: CoCreateInstance(CLSID_AMMultiMediaStream) fails.
      void open(String name) {
         if (name != null && this.ddInit) {
            System.out.print("Could not create a CLSID_MultiMediaStream object\nCheck you have run regsvr32 amstream.dll\n");
            System.out.print("\n");
         }
      }

      // 0x00440ba0 / 0x00440c00 / 0x00440c50: require opened (+0x38)
      void play(int n) {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("unreachable without DirectDraw");
         }
      }

      void pause() {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("unreachable without DirectDraw");
         }
      }

      void stop() {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("unreachable without DirectDraw");
         }
      }

      // 0x00440430: requires ddInit and opened
      void renderTo(int hwnd, int hdc) {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("unreachable without DirectDraw");
         }
      }

      // 0x004403c0: if ddInit, releases (everything null), ddInit = opened = 0
      void shutdown() {
         if (this.ddInit) {
            this.opened = false;
            this.ddInit = false;
         }
      }
   }

   private static final HashMap<Integer, Renderer> RENDERERS = new HashMap<>();
   private static int nextHandle = 0x10000;

   // 0x0043f210 DirectShow.nInit: returns the value for mediaRendererInstancePtr.
   public static synchronized int nInit(int hwnd) {
      Renderer r;
      if (hwnd == 0) {
         r = new AudioRenderer();
      } else {
         r = new Dx8Renderer();
         if (!r.init()) {
            System.out.print("Could not create DirectX 8 media renderer; falling back to DX7.\n");
            r = new Dx7Renderer(hwnd);
            r.init();
         }
      }

      int h = nextHandle;
      nextHandle += 0x100;
      RENDERERS.put(h, r);
      r.init();
      return h;
   }

   private static synchronized Renderer get(int h) {
      return RENDERERS.get(h);
   }

   // 0x0043f310: shutdown (+0xc) and delete. A later call with the freed
   // pointer touches freed memory in the original; here it does nothing.
   public static synchronized void nShutdown(int h) {
      Renderer r = RENDERERS.remove(h);
      if (r != null) {
         r.shutdown();
      }
   }

   // 0x0043f450: open (+0x14) and then stop (+0x20)
   public static void nOpen(int h, String name) {
      Renderer r = get(h);
      if (r != null) {
         NativeMediaSound.log("DirectShow " + r.kind() + " not available: " + name);
         r.open(name);
         r.stop();
      }
   }

   // 0x0043f390 (+0x18)
   public static void nPlay(int h, int n) {
      Renderer r = get(h);
      if (r != null) {
         r.play(n);
      }
   }

   // 0x0043f3c0 (+0x20)
   public static void nStop(int h) {
      Renderer r = get(h);
      if (r != null) {
         r.stop();
      }
   }

   // 0x0043f420 (+0x1c)
   public static void nPause(int h) {
      Renderer r = get(h);
      if (r != null) {
         r.pause();
      }
   }

   // 0x0043f350 (+4)
   public static void nRenderTo(int h, int hwnd, int hdc) {
      Renderer r = get(h);
      if (r != null) {
         r.renderTo(hwnd, hdc);
      }
   }

   // 0x0043f3f0 (+0x10)
   public static int nTick(int h) {
      Renderer r = get(h);
      return r == null ? 0 : r.tick();
   }

   /** For tests: class of the renderer after nInit ("audio", "DX7"...). */
   public static synchronized String kindOf(int h) {
      Renderer r = RENDERERS.get(h);
      return r == null ? null : r.kind();
   }
}

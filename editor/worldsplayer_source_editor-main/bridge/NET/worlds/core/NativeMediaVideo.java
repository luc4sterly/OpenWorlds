package NET.worlds.core;

import java.util.HashMap;

/**
 * {@code DirectShow} de gamma.dll (0x0043f180..0x0043f450) sin DirectShow.
 *
 * <p>El Java guarda en {@code mediaRendererInstancePtr} un objeto C++ de una
 * de tres clases, todas con la misma vtable (+0 destructor, +4 renderTo,
 * +8 init, +0xc shutdown, +0x10 tick, +0x14 open, +0x18 play, +0x1c pause,
 * +0x20 stop), el estado en +8 (0 sin inicializar, 1 parado, 2 en pausa,
 * 3 reproduciendo) y las repeticiones en +4:
 * <ul>
 * <li>audio, {@code nInit(0)}: 0x34 bytes, vtable 0x00478b20
 *     ({@code WMPSoundPlayer});</li>
 * <li>"DX8", {@code nInit(hwnd)}: 0x28 bytes, vtable 0x004788f0;</li>
 * <li>"DX7" de respaldo si DX8 no arranca: 0x60 bytes, vtable 0x00478af4
 *     ({@code VideoSurface}/{@code VideoTexture}).</li>
 * </ul>
 * Cada una empieza creando un objeto COM de DirectShow/DirectDraw con
 * {@code CoCreateInstance}. En este sistema no hay COM ni DirectShow, asi que
 * se sigue el camino que el propio binario tiene para ese fallo (el de un
 * Windows sin DirectX Media): imprime su mensaje, deja el estado en 0 y
 * todas las operaciones posteriores se saltan por sus guardas de estado.
 * {@code nTick} devuelve 0, con lo que {@code WMPSoundPlayer.getState} da
 * IS_STOPPED y el {@code Sound} se cierra solo; ningun sonido ni video
 * aparenta sonar.
 */
public final class NativeMediaVideo {
   private NativeMediaVideo() {
   }

   /** Estados del objeto C++ (+8), iguales a los static final del Java. */
   public static final int UNINITIALIZED = 0;
   public static final int STOPPED = 1;
   public static final int PAUSED = 2;
   public static final int PLAYING = 3;

   /** Renderer C++; el camino que no depende de COM se traduce entero. */
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

   /** 0x0043fdb0: audio. graph = +0xc (IGraphBuilder), evento = +0x10. */
   static final class AudioRenderer extends Renderer {
      String kind() {
         return "audio";
      }

      // 0x0043fdf0: CoInitialize; state = 0; return 1
      boolean init() {
         this.state = 0;
         return true;
      }

      // 0x0043ffc0 -> 0x0043fe30: CoCreateInstance(CLSID_FilterGraph) falla ->
      // printf("Can't create filter graph for %s\n", nombre), devuelve 0 y el
      // estado queda en 0 (lo pone a 0 antes de intentarlo).
      void open(String name) {
         if (name != null) {
            this.state = 0;
            System.out.println("Can't create filter graph for " + name);
         }
      }

      // 0x0043fff0: solo desde 1 o 2
      void play(int n) {
         if (this.state == STOPPED || this.state == PAUSED) {
            throw new IllegalStateException("inalcanzable sin filter graph");
         }
      }

      // 0x00440070: solo desde 3 o 1
      void pause() {
         if (this.state == PLAYING || this.state == STOPPED) {
            throw new IllegalStateException("inalcanzable sin filter graph");
         }
      }

      // 0x004400f0: solo desde 3 o 2
      void stop() {
         if (this.state == PLAYING || this.state == PAUSED) {
            throw new IllegalStateException("inalcanzable sin filter graph");
         }
      }
      // tick 0x004401a0: sin evento (+0x10 == 0) devuelve el estado.
      // renderTo 0x00441870: vacio. shutdown 0x0043fe10: CoUninitialize.
   }

   /** 0x00440f60: DX8. */
   static final class Dx8Renderer extends Renderer {
      String kind() {
         return "DX8";
      }

      // 0x00440fa0: state = 0; CoCreateInstance(CLSID_FilterGraph) falla ->
      // "Could not create filter graph." + "\n" y devuelve 0.
      boolean init() {
         this.state = 0;
         System.out.print("Could not create filter graph.");
         System.out.print("\n");
         return false;
      }

      // init siempre falla y nInit lo sustituye por DX7: el resto no se llama.
      void open(String name) {
         throw new IllegalStateException("DX8 sin filter graph: nInit cae a DX7");
      }

      void play(int n) {
         throw new IllegalStateException("DX8 sin filter graph: nInit cae a DX7");
      }

      void pause() {
         throw new IllegalStateException("DX8 sin filter graph: nInit cae a DX7");
      }

      void stop() {
         throw new IllegalStateException("DX8 sin filter graph: nInit cae a DX7");
      }
   }

   /** 0x00440320: DX7 de respaldo; hwnd en +0x3c, ddInit en +0x34, abierto en +0x38. */
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

      // 0x00440380: CoInitialize; state = 0; si hwnd y no ddInit ->
      // FUN_00440460 (su resultado se ignora) y ddInit = 1. FUN_00440460:
      // CoCreateInstance(CLSID_DirectDrawFactory) falla ->
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

      // 0x004403f0 -> 0x00440770: CoCreateInstance(CLSID_AMMultiMediaStream) falla.
      void open(String name) {
         if (name != null && this.ddInit) {
            System.out.print("Could not create a CLSID_MultiMediaStream object\nCheck you have run regsvr32 amstream.dll\n");
            System.out.print("\n");
         }
      }

      // 0x00440ba0 / 0x00440c00 / 0x00440c50: exigen abierto (+0x38)
      void play(int n) {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("inalcanzable sin DirectDraw");
         }
      }

      void pause() {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("inalcanzable sin DirectDraw");
         }
      }

      void stop() {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("inalcanzable sin DirectDraw");
         }
      }

      // 0x00440430: exige ddInit y abierto
      void renderTo(int hwnd, int hdc) {
         if (this.ddInit && this.opened) {
            throw new IllegalStateException("inalcanzable sin DirectDraw");
         }
      }

      // 0x004403c0: si ddInit libera (todo nulo), ddInit = abierto = 0
      void shutdown() {
         if (this.ddInit) {
            this.opened = false;
            this.ddInit = false;
         }
      }
   }

   private static final HashMap<Integer, Renderer> RENDERERS = new HashMap<>();
   private static int nextHandle = 0x10000;

   // 0x0043f210 DirectShow.nInit: devuelve el valor para mediaRendererInstancePtr.
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

   // 0x0043f310: shutdown (+0xc) y delete. Una llamada posterior con el
   // puntero liberado es memoria libre en el original; aqui no hace nada.
   public static synchronized void nShutdown(int h) {
      Renderer r = RENDERERS.remove(h);
      if (r != null) {
         r.shutdown();
      }
   }

   // 0x0043f450: open (+0x14) y despues stop (+0x20)
   public static void nOpen(int h, String name) {
      Renderer r = get(h);
      if (r != null) {
         NativeMediaSound.log("DirectShow " + r.kind() + " no disponible: " + name);
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

   /** Para pruebas: clase del renderer tras nInit ("audio", "DX7"...). */
   public static synchronized String kindOf(int h) {
      Renderer r = RENDERERS.get(h);
      return r == null ? null : r.kind();
   }
}

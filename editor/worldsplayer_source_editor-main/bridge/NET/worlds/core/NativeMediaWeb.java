package NET.worlds.core;

import java.io.IOException;
import java.util.HashMap;

/**
 * Web embebida de gamma.dll sin Internet Explorer, DDE ni ventanas Win32:
 * el camino de fallo que el propio binario tiene para un Windows sin esos
 * componentes, con sus valores de retorno y excepciones.
 *
 * <ul>
 * <li>{@code IEWebControlImp.nativeInit} (0x0043ce30): el contenedor ActiveX
 *     (0x0043dd70) crea el control con {@code CoCreateInstance}
 *     (0x0043e690); si falla, el puntero del control (+0x24) queda nulo,
 *     {@code FUN_0043e960} devuelve 0, la interfaz +0xc queda nula y
 *     nativeInit llama a nativeDestroy y devuelve false. El Java lanza
 *     {@code NoWebControlException("Could not initialize IE control")}:
 *     AdBanner, Billboard, WebPageWall, OpenURLAction y los scripts ya
 *     manejan esa excepcion. El resto de nativos del control solo se llaman
 *     sobre un control creado, asi que son inalcanzables.</li>
 * <li>{@code WebBrowser.openBrowser} (0x0040fd60):
 *     {@code CoCreateInstance(CLSID_InternetExplorer)} falla ->
 *     {@code IOException("nWebBrowser")}; el Java deja WebBrowser
 *     deshabilitado y SendURLAction cae a launchViaRegistry
 *     ({@link NativeMediaUrl}).</li>
 * <li>{@code IWebBrowserApp} (0x0040b560..0x0040b690): cada metodo llama a
 *     la interfaz COM y, si el HRESULT no es 0, lanza
 *     {@code IOException("nIWebBrowserApp")}.</li>
 * <li>DDE ({@code DDEMLClass} 0x00404290..0x00404530, {@code sendURL.init}
 *     0x00421220): no hay DDEML; DdeInitialize falla y las conversaciones
 *     no se conectan.</li>
 * <li>{@code TextureSurface} (0x0043fa70..0x0043fd80): la ventana oculta y
 *     el DIB de 16 bits 5-6-5 donde IE o DirectShow pintaban. Se crean
 *     como asas propias; como ningun renderer puede crearse aqui, nadie
 *     pinta en ellas y {@code TextureSurface.draw} no se llega a llamar.</li>
 * </ul>
 */
public final class NativeMediaWeb {
   private NativeMediaWeb() {
   }

   /** Lanza una excepcion comprobada sin declararla, como ThrowNew desde JNI. */
   @SuppressWarnings("unchecked")
   static <T extends Throwable> RuntimeException sneaky(Throwable t) throws T {
      throw (T)t;
   }

   // ---------------- IEWebControlImp ----------------

   // 0x0043ce30: sin control IE -> nativeDestroy (0x0043d1b0) y false.
   public static boolean ieNativeInit(int hwnd, boolean adBanner) {
      NativeMediaSound.log("control IE no disponible (CoCreateInstance falla): hwnd " + hwnd + (adBanner ? ", banner" : ""));
      return false;
   }

   /** Los nativos que exigen un control creado. */
   public static IllegalStateException ieUnreachable(String name) {
      return new IllegalStateException("IEWebControlImp." + name + ": inalcanzable, nativeInit devuelve false siempre");
   }

   // ---------------- WebBrowser ----------------

   // 0x0040fd60
   public static int openBrowser() {
      NativeMediaSound.log("Internet Explorer no disponible: WebBrowser.openBrowser -> IOException(nWebBrowser)");
      throw sneaky(new IOException("nWebBrowser"));
   }

   // 0x0040fee0 / 0x0040fec0: el Java solo los llama con nativeBrowserPointer
   // != 0, y openBrowser nunca lo devuelve.
   public static IllegalStateException browserUnreachable(String name) {
      return new IllegalStateException("WebBrowser." + name + ": inalcanzable, openBrowser lanza siempre");
   }

   // ---------------- IWebBrowserApp ----------------

   // 0x0040b560/0x0040b5b0/0x0040b600/0x0040b650/0x0040b690: HRESULT != 0 ->
   // ThrowNew(IOException, "nIWebBrowserApp"). Sin objeto COM detras (lo crea
   // IUnknown, del agente de sistema) la llamada falla.
   public static void webBrowserAppCall(String name) {
      NativeMediaSound.log("IWebBrowserApp." + name + " sin Internet Explorer -> IOException(nIWebBrowserApp)");
      throw sneaky(new IOException("nIWebBrowserApp"));
   }

   // ---------------- DDE ----------------

   // FUN_00404140 (la conversacion de DDEMLClass.create): DdeInitialize
   // falla -> DAT_004a0430 = 0, conectado (+0x10) = 0. create devuelve el
   // flag de conectado; Request/Poke devuelven false (iVar = -1) sin
   // conexion; destroy solo libera.
   public static boolean ddeCreate(String service, String topic) {
      NativeMediaSound.log("DDE no disponible: " + service + "/" + topic);
      return false;
   }

   // 0x00421220 sendURL.init: DdeInitialize falla -> 0.
   public static int sendUrlInit(String browser) {
      return 0;
   }

   // ---------------- TextureSurface ----------------

   /** Un DIB 5-6-5 de 16 bits (0x0043fb20: biBitCount 16, BI_BITFIELDS 0xF800/0x7E0/0x1F). */
   public static final class Dib {
      public final int width;
      public final int height;
      public final short[] pixels;

      Dib(int width, int height) {
         this.width = width;
         this.height = height;
         this.pixels = new short[Math.max(0, width) * Math.max(0, height)];
      }
   }

   private static final HashMap<Integer, Dib> DCS = new HashMap<>();
   private static int nextWindow = 0x7000;
   private static int nextDc = 0x7100000;

   // 0x0043fa70: CreateWindowExA("TextureSurface", WS_CAPTION, sin WS_VISIBLE):
   // una ventana que nunca se muestra; devuelve su HWND.
   public static synchronized int surfaceInit(int w, int h) {
      nextWindow += 4;
      return nextWindow;
   }

   // 0x0043fb20: DC compatible con un DIB 5-6-5 de w x h; el objeto anterior
   // del DC se guarda en _oldObject (aqui 0: no hay objeto GDI previo).
   public static synchronized int surfaceMakeDC(int hwnd, int w, int h) {
      nextDc += 4;
      DCS.put(nextDc, new Dib(w, h));
      return nextDc;
   }

   /** El DIB de un DC de TextureSurface, o null. */
   public static synchronized Dib dibOf(int hdc) {
      return DCS.get(hdc);
   }

   // 0x0043fc20: SelectObject(_oldObject), DeleteObject(dib), DeleteDC.
   public static synchronized void surfaceDestroyDC(int hdc) {
      DCS.remove(hdc);
   }

   // 0x0043fae0 GetDC(hwnd) (nativeReleaseDC 0x0043fb00: ReleaseDC). El Java
   // declara ambos pero no los llama; el DC de la ventana oculta es su asa.
   public static int surfaceGetDC(int hwnd) {
      return hwnd;
   }

   // 0x0043fd80 -> FUN_0043fca0: ChildWindowFromPointEx y WM_SETFOCUS +
   // WM_LBUTTONDOWN/UP a la ventana hija bajo el punto. La ventana oculta no
   // tiene hijas (el control IE no se pudo crear) y su WndProc (0x0043f9b0,
   // registrada en 0x0043f9d0) es solo DefWindowProcA: sin efecto.
   public static void surfaceLeftClick(int hwnd, int x, int y) {
   }
}

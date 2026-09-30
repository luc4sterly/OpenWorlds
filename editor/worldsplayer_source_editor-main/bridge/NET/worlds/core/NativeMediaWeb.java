package NET.worlds.core;

import java.io.IOException;
import java.util.HashMap;

/**
 * gamma.dll's embedded web control without Internet Explorer, DDE or Win32
 * windows: the failure path that the binary itself has for a Windows
 * without those components, with its return values and exceptions.
 *
 * <ul>
 * <li>{@code IEWebControlImp.nativeInit} (0x0043ce30): the ActiveX container
 *     (0x0043dd70) creates the control with {@code CoCreateInstance}
 *     (0x0043e690); if that fails, the control pointer (+0x24) stays null,
 *     {@code FUN_0043e960} returns 0, the +0xc interface stays null and
 *     nativeInit calls nativeDestroy and returns false. The Java code throws
 *     {@code NoWebControlException("Could not initialize IE control")}:
 *     AdBanner, Billboard, WebPageWall, OpenURLAction and the scripts already
 *     handle that exception. The control's remaining natives are only called
 *     on a created control, so they are unreachable.</li>
 * <li>{@code WebBrowser.openBrowser} (0x0040fd60):
 *     {@code CoCreateInstance(CLSID_InternetExplorer)} fails ->
 *     {@code IOException("nWebBrowser")}; the Java code leaves WebBrowser
 *     disabled and SendURLAction falls back to launchViaRegistry
 *     ({@link NativeMediaUrl}).</li>
 * <li>{@code IWebBrowserApp} (0x0040b560..0x0040b690): each method calls
 *     the COM interface and, if the HRESULT is not 0, throws
 *     {@code IOException("nIWebBrowserApp")}.</li>
 * <li>DDE ({@code DDEMLClass} 0x00404290..0x00404530, {@code sendURL.init}
 *     0x00421220): there is no DDEML; DdeInitialize fails and the
 *     conversations do not connect.</li>
 * <li>{@code TextureSurface} (0x0043fa70..0x0043fd80): the hidden window and
 *     the 16-bit 5-6-5 DIB where IE or DirectShow used to paint. They are
 *     created as handles of our own; since no renderer can be created here,
 *     nobody paints on them and {@code TextureSurface.draw} is never
 *     reached.</li>
 * </ul>
 */
public final class NativeMediaWeb {
   private NativeMediaWeb() {
   }

   /** Throws a checked exception without declaring it, like ThrowNew from JNI. */
   @SuppressWarnings("unchecked")
   static <T extends Throwable> RuntimeException sneaky(Throwable t) throws T {
      throw (T)t;
   }

   // ---------------- IEWebControlImp ----------------

   // 0x0043ce30: without an IE control -> nativeDestroy (0x0043d1b0) and false.
   public static boolean ieNativeInit(int hwnd, boolean adBanner) {
      NativeMediaSound.log("control IE no disponible (CoCreateInstance falla): hwnd " + hwnd + (adBanner ? ", banner" : ""));
      return false;
   }

   /** The natives that require a created control. */
   public static IllegalStateException ieUnreachable(String name) {
      return new IllegalStateException("IEWebControlImp." + name + ": inalcanzable, nativeInit devuelve false siempre");
   }

   // ---------------- WebBrowser ----------------

   // 0x0040fd60
   public static int openBrowser() {
      NativeMediaSound.log("Internet Explorer no disponible: WebBrowser.openBrowser -> IOException(nWebBrowser)");
      throw sneaky(new IOException("nWebBrowser"));
   }

   // 0x0040fee0 / 0x0040fec0: the Java code only calls them with
   // nativeBrowserPointer != 0, and openBrowser never returns that.
   public static IllegalStateException browserUnreachable(String name) {
      return new IllegalStateException("WebBrowser." + name + ": inalcanzable, openBrowser lanza siempre");
   }

   // ---------------- IWebBrowserApp ----------------

   // 0x0040b560/0x0040b5b0/0x0040b600/0x0040b650/0x0040b690: HRESULT != 0 ->
   // ThrowNew(IOException, "nIWebBrowserApp"). With no COM object behind it
   // (created by IUnknown, from the system agent) the call fails.
   public static void webBrowserAppCall(String name) {
      NativeMediaSound.log("IWebBrowserApp." + name + " sin Internet Explorer -> IOException(nIWebBrowserApp)");
      throw sneaky(new IOException("nIWebBrowserApp"));
   }

   // ---------------- DDE ----------------

   // FUN_00404140 (the conversation of DDEMLClass.create): DdeInitialize
   // fails -> DAT_004a0430 = 0, connected (+0x10) = 0. create returns the
   // connected flag; Request/Poke return false (iVar = -1) without a
   // connection; destroy only frees.
   public static boolean ddeCreate(String service, String topic) {
      NativeMediaSound.log("DDE no disponible: " + service + "/" + topic);
      return false;
   }

   // 0x00421220 sendURL.init: DdeInitialize fails -> 0.
   public static int sendUrlInit(String browser) {
      return 0;
   }

   // ---------------- TextureSurface ----------------

   /** A 16-bit 5-6-5 DIB (0x0043fb20: biBitCount 16, BI_BITFIELDS 0xF800/0x7E0/0x1F). */
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

   // 0x0043fa70: CreateWindowExA("TextureSurface", WS_CAPTION, without WS_VISIBLE):
   // a window that is never shown; returns its HWND.
   public static synchronized int surfaceInit(int w, int h) {
      nextWindow += 4;
      return nextWindow;
   }

   // 0x0043fb20: DC compatible with a w x h 5-6-5 DIB; the DC's previous object
   // is saved in _oldObject (here 0: there is no previous GDI object).
   public static synchronized int surfaceMakeDC(int hwnd, int w, int h) {
      nextDc += 4;
      DCS.put(nextDc, new Dib(w, h));
      return nextDc;
   }

   /** The DIB of a TextureSurface DC, or null. */
   public static synchronized Dib dibOf(int hdc) {
      return DCS.get(hdc);
   }

   // 0x0043fc20: SelectObject(_oldObject), DeleteObject(dib), DeleteDC.
   public static synchronized void surfaceDestroyDC(int hdc) {
      DCS.remove(hdc);
   }

   // 0x0043fae0 GetDC(hwnd) (nativeReleaseDC 0x0043fb00: ReleaseDC). The Java
   // code declares both but does not call them; the hidden window's DC is its handle.
   public static int surfaceGetDC(int hwnd) {
      return hwnd;
   }

   // 0x0043fd80 -> FUN_0043fca0: ChildWindowFromPointEx and WM_SETFOCUS +
   // WM_LBUTTONDOWN/UP to the child window under the point. The hidden window has
   // no children (the IE control could not be created) and its WndProc (0x0043f9b0,
   // registered at 0x0043f9d0) is just DefWindowProcA: no effect.
   public static void surfaceLeftClick(int hwnd, int x, int y) {
   }
}

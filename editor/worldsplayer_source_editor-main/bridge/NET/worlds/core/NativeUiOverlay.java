package NET.worlds.core;

import java.awt.Component;
import java.util.ArrayList;
import java.util.List;

/**
 * RenderCanvasOverlay (0x0043ef30 / 0x0043f0d0 / 0x0043f160): la ventana
 * hija, clase "RenderCanvasOverlay" (registrada por FUN_0043ee90), que
 * aloja el control web (IEWebControlImp) sobre la vista 3D.
 *
 * <ul>
 * <li>nativeMakeChild: GetWindowRect del padre (la ventana de render);
 * ancho = ROUND(anchoPadre * xPercent * _DAT_00477c68) con
 * _DAT_00477c68 = 0.01 (bytes 7b 14 ae 47 e1 7a 84 3f), igual el alto;
 * AdjustWindowRect(WS_CHILD, sin menu) no cambia el rectangulo (WS_CHILD
 * no tiene marco); CreateWindowEx(WS_EX_NOPARENTNOTIFY, WS_CHILD |
 * WS_VISIBLE) en la esquina inferior derecha del padre (anchoPadre-ancho,
 * altoPadre-alto), con id de control DAT_00477c3c (empieza en 1, +1 cada
 * vez); guarda en GWL_USERDATA {allowFocus, env, NewGlobalRef(this),
 * methodID de handleCommand(I)V}; ShowWindow, UpdateWindow y
 * SetFocus(padre).
 * <li>su WndProc (LAB_0043edd0, desensamblada): WM_COMMAND -&gt;
 * handleCommand(LOWORD(wParam)); WM_DESTROY -&gt; DeleteGlobalRef y libera
 * el bloque; el resto a DefWindowProc.
 * <li>nativeResizeChild: el mismo AdjustWindowRect y SetWindowPos a la
 * esquina inferior derecha del area cliente del padre (SWP_NOZORDER);
 * nada si no hay padre.
 * <li>nativeKillChild: DestroyWindow.
 * </ul>
 * Aqui la hija es un registro con su rectangulo (como las "TempClass" de
 * NativeWindows) y la llamada a handleCommand; los handles empiezan en
 * {@link #BASE} para no confundirse con los de NativeWindows. ⚠️ No se crea
 * un componente AWT visible: solo aloja el control web, que en el puente
 * es un stub (grupo "Web embebida" de H5, pendiente de decidir); un panel
 * vacio encima de la vista 3D no seria mas fiel que no pintarlo.
 */
public final class NativeUiOverlay {
   private NativeUiOverlay() {
   }

   static final int BASE = 0x10000;
   static final double PERCENT = 0.01;

   public interface Command {
      void handle(int id);
   }

   public static final class Child {
      public final int parent;
      public final int controlId;
      public final boolean allowFocus;
      public int x;
      public int y;
      public int w;
      public int h;
      final Command command;

      Child(int parent, int controlId, boolean allowFocus, Command command) {
         this.parent = parent;
         this.controlId = controlId;
         this.allowFocus = allowFocus;
         this.command = command;
      }
   }

   private static final List<Child> children = new ArrayList<Child>();
   /** DAT_00477c3c. */
   private static int nextControlId = 1;

   public static synchronized Child get(int h) {
      int i = h - BASE;
      return i >= 1 && i <= children.size() ? children.get(i - 1) : null;
   }

   /** ROUND de x87 (FISTP con el redondeo por defecto: al par mas cercano). */
   static int round(double v) {
      return (int) Math.rint(v);
   }

   /** Tamano de la hija para un padre de pw x ph y los porcentajes dados. */
   static int[] size(int pw, int ph, int xPercent, int yPercent) {
      return new int[]{round((double) (pw * xPercent) * PERCENT), round((double) (ph * yPercent) * PERCENT)};
   }

   public static synchronized int makeChild(int parentHwnd, int xPercent, int yPercent, boolean allowFocus, Command command) {
      final Component p = NativeWindows.component(parentHwnd);
      int pw = p == null ? 0 : p.getWidth();
      int ph = p == null ? 0 : p.getHeight();
      int[] s = size(pw, ph, xPercent, yPercent);
      Child c = new Child(parentHwnd, nextControlId++, allowFocus, command);
      c.w = s[0];
      c.h = s[1];
      c.x = pw - c.w;
      c.y = ph - c.h;
      children.add(c);
      if (p != null) {
         // SetFocus(padre)
         java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
               p.requestFocus();
            }
         });
      }
      return BASE + children.size();
   }

   public static synchronized void resizeChild(int hwnd, int w, int h) {
      Child c = get(hwnd);
      if (c == null) {
         return;
      }
      Component p = NativeWindows.component(c.parent);
      if (p == null) {
         return;
      }
      c.x = p.getWidth() - w;
      c.y = p.getHeight() - h;
      c.w = w;
      c.h = h;
   }

   public static synchronized void killChild(int hwnd) {
      int i = hwnd - BASE;
      if (i >= 1 && i <= children.size()) {
         children.set(i - 1, null);
      }
   }

   /** WM_COMMAND a la hija (LAB_0043edd0): handleCommand(LOWORD(wParam)). */
   public static void command(int hwnd, int wParam) {
      Child c = get(hwnd);
      if (c != null && c.command != null) {
         c.command.handle(wParam & 0xffff);
      }
   }
}

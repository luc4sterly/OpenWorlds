package NET.worlds.core;

import java.awt.Component;
import java.util.ArrayList;
import java.util.List;

/**
 * RenderCanvasOverlay (0x0043ef30 / 0x0043f0d0 / 0x0043f160): the child
 * window, class "RenderCanvasOverlay" (registered by FUN_0043ee90), that
 * hosts the web control (IEWebControlImp) over the 3D view.
 *
 * <ul>
 * <li>nativeMakeChild: GetWindowRect of the parent (the render window);
 * width = ROUND(parentWidth * xPercent * _DAT_00477c68) with
 * _DAT_00477c68 = 0.01 (bytes 7b 14 ae 47 e1 7a 84 3f), the same for the
 * height; AdjustWindowRect(WS_CHILD, no menu) does not change the rectangle
 * (WS_CHILD has no frame); CreateWindowEx(WS_EX_NOPARENTNOTIFY, WS_CHILD |
 * WS_VISIBLE) at the parent's bottom right corner (parentWidth-width,
 * parentHeight-height), with control id DAT_00477c3c (starts at 1, +1 each
 * time); it stores in GWL_USERDATA {allowFocus, env, NewGlobalRef(this),
 * methodID of handleCommand(I)V}; ShowWindow, UpdateWindow and
 * SetFocus(parent).
 * <li>its WndProc (LAB_0043edd0, disassembled): WM_COMMAND -&gt;
 * handleCommand(LOWORD(wParam)); WM_DESTROY -&gt; DeleteGlobalRef and frees
 * the block; everything else goes to DefWindowProc.
 * <li>nativeResizeChild: the same AdjustWindowRect and SetWindowPos to the
 * bottom right corner of the parent's client area (SWP_NOZORDER);
 * nothing if there is no parent.
 * <li>nativeKillChild: DestroyWindow.
 * </ul>
 * Here the child is a record with its rectangle (like NativeWindows'
 * "TempClass" ones) and the call to handleCommand; the handles start at
 * {@link #BASE} so as not to be confused with NativeWindows'. ⚠️ No visible
 * AWT component is created: it only hosts the web control, which in the
 * bridge is a stub (the "Embedded web" group of H5, still to be decided); an
 * empty panel on top of the 3D view would not be more faithful than not
 * painting it.
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

   /** x87 ROUND (FISTP with the default rounding: to the nearest even). */
   static int round(double v) {
      return (int) Math.rint(v);
   }

   /** Size of the child for a pw x ph parent and the given percentages. */
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
         // SetFocus(parent)
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

   /** WM_COMMAND to the child (LAB_0043edd0): handleCommand(LOWORD(wParam)). */
   public static void command(int hwnd, int wParam) {
      Child c = get(hwnd);
      if (c != null && c.command != null) {
         c.command.handle(wParam & 0xffff);
      }
   }
}

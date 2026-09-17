package NET.worlds.core;

import java.awt.Dialog;
import java.awt.Frame;
import java.awt.Window;
import java.util.ArrayList;
import java.util.List;

/**
 * Portable stand-in for the Win32 window handles that gamma.dll's
 * NET.worlds.console.Window natives hand back to Java (HWND as int).
 * Every method mirrors the real native read in decompiled-native/gamma_dll,
 * translated from Win32 to the AWT windows this process really owns:
 *
 * - findWindow (0x40df20): EnumWindows over this process's top-level
 *   windows, return the one whose title matches, else 0. Here: the
 *   displayable java.awt.Window (Frame/Dialog) with that exact title.
 * - nativeFindOrMakeChildWindow (0x40e3f0): look for an existing child
 *   window of the frame at those screen coordinates/size; if none, create
 *   a "TempClass" child (the surface RenderWare draws into) and return it.
 *   nativeFindChildWindow is the find-only half.
 * - getWindowState (0x40ed00): IsIconic -> 1, IsZoomed -> 2, else 0.
 * - setWindowState (0x40ed50): ShowWindow(SW_MINIMIZE / SW_MAXIMIZE /
 *   SW_RESTORE).
 * - getWindowWidth/Height (0x40f1b0 / 0x40f1e0): GetWindowRect size.
 *
 * Handles are 1-based indices into a table (0 keeps meaning "no window",
 * exactly as the Java callers expect). Child windows only record the
 * rectangle for now: nothing draws into them yet.
 */
public final class NativeWindows {
   private NativeWindows() {
   }

   private static final class Child {
      final int parent;
      final int x;
      final int y;
      final int w;
      final int h;

      Child(int parent, int x, int y, int w, int h) {
         this.parent = parent;
         this.x = x;
         this.y = y;
         this.w = w;
         this.h = h;
      }
   }

   private static final List<Object> handles = new ArrayList<Object>();

   private static synchronized int handleFor(Object o) {
      for (int i = 0; i < handles.size(); i++) {
         if (handles.get(i) == o) {
            return i + 1;
         }
      }
      handles.add(o);
      return handles.size();
   }

   private static synchronized Object get(int handle) {
      return handle > 0 && handle <= handles.size() ? handles.get(handle - 1) : null;
   }

   private static String titleOf(Window w) {
      if (w instanceof Frame) {
         return ((Frame) w).getTitle();
      }
      if (w instanceof Dialog) {
         return ((Dialog) w).getTitle();
      }
      return null;
   }

   private static int findCalls = 0;

   /** Diagnostico del arnes: que ventanas AWT existen de verdad cuando el cliente busca una. */
   private static void dumpWindows(String wanted) {
      findCalls++;
      if (findCalls > 5 && findCalls % 5000 != 0) {
         return;
      }
      StringBuilder sb = new StringBuilder("[WINDOWS] findWindow#" + findCalls + " \"" + wanted + "\":");
      for (Window w : Window.getWindows()) {
         sb.append(" [").append(w.getClass().getSimpleName()).append(" \"").append(titleOf(w)).append("\" displayable=")
            .append(w.isDisplayable()).append(" visible=").append(w.isVisible()).append(' ')
            .append(w.getWidth()).append('x').append(w.getHeight()).append(']');
      }
      System.err.println(sb);
   }

   public static int findWindow(String title) {
      dumpWindows(title);
      if (title == null) {
         return 0;
      }
      for (Window w : Window.getWindows()) {
         if (w.isDisplayable() && title.equals(titleOf(w))) {
            return handleFor(w);
         }
      }
      return 0;
   }

   public static synchronized int findChildWindow(int parent, int x, int y, int w, int h) {
      for (int i = 0; i < handles.size(); i++) {
         Object o = handles.get(i);
         if (o instanceof Child) {
            Child c = (Child) o;
            if (c.parent == parent && c.x == x && c.y == y && c.w == w && c.h == h) {
               return i + 1;
            }
         }
      }
      return 0;
   }

   public static synchronized int findOrMakeChildWindow(int parent, int x, int y, int w, int h) {
      if (!(get(parent) instanceof Window)) {
         return 0;
      }
      int existing = findChildWindow(parent, x, y, w, h);
      if (existing != 0) {
         return existing;
      }
      handles.add(new Child(parent, x, y, w, h));
      return handles.size();
   }

   public static int getWindowState(int handle) {
      Object o = get(handle);
      if (o instanceof Frame) {
         int s = ((Frame) o).getExtendedState();
         if ((s & Frame.ICONIFIED) != 0) {
            return 1;
         }
         if ((s & Frame.MAXIMIZED_BOTH) == Frame.MAXIMIZED_BOTH) {
            return 2;
         }
      }
      return 0;
   }

   public static void setWindowState(int handle, int state) {
      Object o = get(handle);
      if (o instanceof Frame) {
         Frame f = (Frame) o;
         f.setExtendedState(state == 1 ? Frame.ICONIFIED : state == 2 ? Frame.MAXIMIZED_BOTH : Frame.NORMAL);
      }
   }

   public static int getWindowWidth(int handle) {
      Object o = get(handle);
      if (o instanceof Window) {
         return ((Window) o).getWidth();
      }
      return o instanceof Child ? ((Child) o).w : 0;
   }

   public static int getWindowHeight(int handle) {
      Object o = get(handle);
      if (o instanceof Window) {
         return ((Window) o).getHeight();
      }
      return o instanceof Child ? ((Child) o).h : 0;
   }
}

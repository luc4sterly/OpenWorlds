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
 * exactly as the Java callers expect).
 */
public final class NativeWindows {
   private NativeWindows() {
   }

   /**
    * DAT_004891cc: set only by Window.doMicrosoftVMHacks (0x0040de30), which
    * Gamma.main calls when java.vendor contains "Microsoft"; read by
    * usingMicrosoftVMHacks (0x0040de40) and by reShape and the child-window
    * lookups. It stays false on any other Java. The mock answered true, and
    * RenderCanvas.handle then called getLocationOnScreen on a hidden canvas:
    * opening the Universe Map closed the game (IllegalComponentStateException
    * out of the main loop).
    */
   public static volatile boolean microsoftVMHacks;

   /**
    * Diagnostico (opt-in): -Dopenworlds.dumpWindow=DIR escribe, en los
    * segundos 12/20/30/40, el arbol de componentes AWT de cada ventana
    * (clase, nombre, texto y limites) y ademas intenta un PNG con
    * Component.printAll.
    *
    * ⚠️ El PNG sale NEGRO en macOS y es esperable: la UI del cliente son
    * componentes AWT PESADOS (Panel, Canvas, Button), que pinta el peer
    * nativo, no Java, y printAll no los captura. El arbol de texto si es
    * fiable y sirve para comprobar la maquetacion (tamanos, solapes,
    * componentes de tamano cero). El render 3D se ve con
    * -Dopenworlds.dumpFrames; una captura real de la ventana solo la puede
    * hacer el sistema operativo.
    */
   private static final int[] DUMP_WINDOW_SECONDS = {12, 20, 30, 40};

   static {
      final String dir = System.getProperty("openworlds.dumpWindow");
      if (dir != null) {
         Thread t = new Thread(new Runnable() {
            public void run() {
               for (int i = 0; i < DUMP_WINDOW_SECONDS.length; i++) {
                  int wait = DUMP_WINDOW_SECONDS[i] - (i == 0 ? 0 : DUMP_WINDOW_SECONDS[i - 1]);
                  try {
                     Thread.sleep(wait * 1000L);
                  } catch (InterruptedException e) {
                     return;
                  }
                  dumpWindows(dir, DUMP_WINDOW_SECONDS[i]);
               }
            }
         }, "openworlds-dumpWindow");
         t.setDaemon(true);
         t.start();
      }
   }

   private static void dumpWindows(String dir, int sec) {
      Frame[] fr = Frame.getFrames();
      for (int i = 0; i < fr.length; i++) {
         final Frame f = fr[i];
         if (!f.isShowing() || f.getWidth() <= 0 || f.getHeight() <= 0) {
            continue;
         }
         final java.awt.image.BufferedImage img =
            new java.awt.image.BufferedImage(f.getWidth(), f.getHeight(), java.awt.image.BufferedImage.TYPE_INT_RGB);
         try {
            java.awt.EventQueue.invokeAndWait(new Runnable() {
               public void run() {
                  java.awt.Graphics2D g = img.createGraphics();
                  f.printAll(g);
                  g.dispose();
               }
            });
            boolean blank = true;
            for (int y = 0; y < img.getHeight() && blank; y += 4) {
               for (int x = 0; x < img.getWidth(); x += 4) {
                  if ((img.getRGB(x, y) & 0xFFFFFF) != 0) {
                     blank = false;
                     break;
                  }
               }
            }
            if (!blank) {
               java.io.File png = new java.io.File(dir, "win-" + i + "-s" + sec + ".png");
               javax.imageio.ImageIO.write(img, "png", png);
               System.err.println("[WIN] " + png);
            }
            java.io.File txt = new java.io.File(dir, "win-" + i + "-s" + sec + ".txt");
            java.io.PrintWriter pw = new java.io.PrintWriter(txt, "UTF-8");
            pw.println(f.getWidth() + "x" + f.getHeight() + " \"" + f.getTitle() + "\"");
            tree(pw, f, 0);
            pw.close();
            System.err.println("[WIN] " + txt + " " + f.getWidth() + "x" + f.getHeight() + " \"" + f.getTitle() + "\""
               + (blank ? " (sin PNG: AWT pesado, lo pinta el peer nativo)" : ""));
         } catch (Throwable ex) {
            System.err.println("[WIN] error al volcar la ventana: " + ex);
         }
      }
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

   /** Screen rectangle of an AWT component, or null if it is not showing. */
   private static java.awt.Rectangle screenRect(java.awt.Component c) {
      try {
         if (!c.isShowing()) {
            return null;
         }
         java.awt.Point p = c.getLocationOnScreen();
         return new java.awt.Rectangle(p.x, p.y, c.getWidth(), c.getHeight());
      } catch (java.awt.IllegalComponentStateException e) {
         return null;
      }
   }

   /**
    * EnumChildWindows callback 0x0040e060: a child window of the frame
    * whose screen rectangle is exactly (x, y, w, h). Under the original
    * JVM every heavyweight AWT component (the RenderCanvas) was itself a
    * Win32 child window, so this finds the canvas.
    */
   private static java.awt.Component findComponent(java.awt.Container parent, int x, int y, int w, int h) {
      for (java.awt.Component c : parent.getComponents()) {
         // innermost first: a container and the canvas inside it can share
         // the rectangle, and the child window the native code finds is the
         // innermost one (the render canvas, not the panel around it)
         if (c instanceof java.awt.Container) {
            java.awt.Component f = findComponent((java.awt.Container) c, x, y, w, h);
            if (f != null) {
               return f;
            }
         }
         java.awt.Rectangle r = screenRect(c);
         if (r != null && r.x == x && r.y == y && r.width == w && r.height == h) {
            return c;
         }
      }
      return null;
   }

   public static synchronized int findChildWindow(int parent, int x, int y, int w, int h) {
      Object p = get(parent);
      if (p instanceof java.awt.Container) {
         java.awt.Component c = findComponent((java.awt.Container) p, x, y, w, h);
         if (c != null) {
            return handleFor(c);
         }
      }
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

   /**
    * nativeFindOrMakeChildWindow (0x0040e3f0): the existing child at that
    * rectangle, else a new "TempClass" child. The TempClass branch only
    * records the rectangle (nothing in this client draws into one).
    */
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

   /** The AWT component behind a child handle (null for TempClass children). */
   public static java.awt.Component component(int handle) {
      Object o = get(handle);
      return o instanceof java.awt.Component ? (java.awt.Component) o : null;
   }

   /**
    * Window instance created by Window.install (FUN_0040f250, 0x30 bytes):
    * +0 hwnd, +0x1c / +0x20 render width / height set by maybeResize.
    */
   public static final class Instance {
      public final int hwnd;
      public int width;
      public int height;

      Instance(int hwnd) {
         this.hwnd = hwnd;
      }
   }

   private static Instance mainInstance;

   /** Window.install: new instance; the one installed as main is DAT_0049ff1c. */
   public static synchronized int install(int hWndGamma, boolean main) {
      Instance in = new Instance(hWndGamma);
      if (main) {
         if (mainInstance != null) {
            NativeAssert.fail("nWindow", 0x8e0);
         }
         mainInstance = in;
      }
      handles.add(in);
      return handles.size();
   }

   public static Instance instance(int handle) {
      Object o = get(handle);
      return o instanceof Instance ? (Instance) o : null;
   }

   /** FUN_0040c120: hwnd of the main instance, 0 if none. */
   public static synchronized int mainHwnd() {
      return mainInstance == null ? 0 : mainInstance.hwnd;
   }

   /** Window.maybeResize (0x0040d950): sizes below 2 become 1, width rounded up to a multiple of 4. */
   public static void maybeResize(int handle, int w, int h) {
      Instance in = instance(handle);
      if (in == null) {
         return;
      }
      if (w < 2) {
         w = 1;
      }
      if (h < 2) {
         h = 1;
      }
      int w4 = w + 3 & ~3;
      synchronized (in) {
         in.width = w4;
         in.height = h;
      }
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
   private static void tree(java.io.PrintWriter pw, java.awt.Component c, int depth) {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < depth; i++) {
         sb.append("  ");
      }
      java.awt.Rectangle b = c.getBounds();
      sb.append(c.getClass().getName()).append(" [").append(b.x).append(",").append(b.y)
        .append(" ").append(b.width).append("x").append(b.height).append("]");
      if (!c.isVisible()) {
         sb.append(" OCULTO");
      }
      if (b.width == 0 || b.height == 0) {
         sb.append(" TAMANO-CERO");
      }
      String text = null;
      if (c instanceof java.awt.Label) {
         text = ((java.awt.Label) c).getText();
      } else if (c instanceof java.awt.Button) {
         text = ((java.awt.Button) c).getLabel();
      } else if (c instanceof java.awt.TextComponent) {
         text = ((java.awt.TextComponent) c).getText();
      }
      if (text != null && text.length() > 0) {
         sb.append(" \"").append(text.length() > 60 ? text.substring(0, 60) + "..." : text).append("\"");
      }
      pw.println(sb);
      if (c instanceof java.awt.Container) {
         java.awt.Component[] kids = ((java.awt.Container) c).getComponents();
         for (int i = 0; i < kids.length; i++) {
            tree(pw, kids[i], depth + 1);
         }
      }
   }

}

package NET.worlds.core;

import java.awt.Point;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * gamma.dll's cursors (Console.Cursor, 0x0040bd70..0x0040bfb0) and their
 * application (Window.setCursor 0x0040e710 + WndProc 0x0040c970).
 *
 * <p>An HCURSOR here is an index (&gt;0) into a table of {@link java.awt.Cursor}.
 * LoadCursor(NULL, IDC_*) always returns the same shared handle for
 * each IDC, so each system cursor has a fixed handle.
 */
public final class NativeUiCursor {
   private NativeUiCursor() {
   }

   /**
    * Table at 0x0046e81c (12 name / IDC_* pairs, read from .data with
    * pe), compared with strcmp (FUN_0044d730, case-sensitive).
    * AWT equivalent by shape of the Windows cursor; the ones AWT lacks
    * are marked:
    */
   static final String[] NAMES = {"IDC_APPSTARTING", "IDC_ARROW", "IDC_CROSS", "IDC_IBEAM", "IDC_NO", "IDC_SIZEALL",
      "IDC_SIZENESW", "IDC_SIZENS", "IDC_SIZENWSE", "IDC_SIZEWE", "IDC_UPARROW", "IDC_WAIT"};
   static final int[] IDC = {32650, 32512, 32515, 32513, 32648, 32646, 32643, 32645, 32642, 32644, 32516, 32514};
   static final int[] AWT = {
      java.awt.Cursor.WAIT_CURSOR, // APPSTARTING (arrow + hourglass): ⚠️ AWT does not have the mix
      java.awt.Cursor.DEFAULT_CURSOR, java.awt.Cursor.CROSSHAIR_CURSOR, java.awt.Cursor.TEXT_CURSOR,
      java.awt.Cursor.DEFAULT_CURSOR, // NO (crossed-out circle): ⚠️ no predefined AWT equivalent
      java.awt.Cursor.MOVE_CURSOR, java.awt.Cursor.NE_RESIZE_CURSOR, java.awt.Cursor.N_RESIZE_CURSOR,
      java.awt.Cursor.NW_RESIZE_CURSOR, java.awt.Cursor.E_RESIZE_CURSOR,
      java.awt.Cursor.HAND_CURSOR, // UPARROW (vertical arrow), which the client calls HAND_CURSOR: ⚠️ different shape
      java.awt.Cursor.WAIT_CURSOR};

   private static final List<java.awt.Cursor> handles = new ArrayList<java.awt.Cursor>();
   private static final Map<Integer, Integer> systemHandles = new HashMap<Integer, Integer>();

   static synchronized int add(java.awt.Cursor c) {
      handles.add(c);
      return handles.size();
   }

   public static synchronized java.awt.Cursor get(int h) {
      return h >= 1 && h <= handles.size() ? handles.get(h - 1) : null;
   }

   /** Cursor.loadSystemCursor (0x0040bed0): 0 if the name is not in the table. */
   public static synchronized int loadSystemCursor(String name) {
      if (name == null) {
         return 0;
      }
      for (int i = 0; i < NAMES.length; i++) {
         if (NAMES[i].equals(name)) {
            Integer h = systemHandles.get(IDC[i]);
            if (h == null) {
               h = add(java.awt.Cursor.getPredefinedCursor(AWT[i]));
               systemHandles.put(IDC[i], h);
            }
            return h;
         }
      }
      return 0;
   }

   /**
    * Cursor.loadCursor (0x0040bd70): null -> 0. A path that does not start
    * with '\\' or '/' and has no ':' in the second position -> the current
    * directory is prepended (_getcwd, 300 bytes) with '\\' if it does not end
    * in a separator; if strlen(path)+strlen(cwd)+2 &gt;= 300, assertion
    * "nCursor" line 0x25. Then LoadCursorFromFileA: here the .cur is decoded
    * with {@link #decodeCur}; an unreadable file returns 0 like the API.
    */
   public static int loadCursor(String path) {
      if (path == null) {
         return 0;
      }
      String full = path;
      boolean absolute = path.startsWith("\\") || path.startsWith("/") || (path.length() > 1 && path.charAt(1) == ':');
      if (!absolute) {
         String cwd = System.getProperty("user.dir");
         if (path.length() + cwd.length() + 2 >= 300) {
            NativeAssert.fail("nCursor", 0x25);
         }
         full = new File(cwd, path).getPath();
      }
      try {
         byte[] b = java.nio.file.Files.readAllBytes(NativeMock.localFile(full).toPath());
         Object[] cur = decodeCur(b);
         if (cur == null) {
            return 0;
         }
         Point hot = (Point) cur[1];
         return add(Toolkit.getDefaultToolkit().createCustomCursor((BufferedImage) cur[0], hot, path));
      } catch (Exception e) {
         return 0;
      }
   }

   /** Cursor.destroyCursor (0x0040bf50): DestroyCursor. */
   public static synchronized void destroyCursor(int h) {
      if (h >= 1 && h <= handles.size() && !systemHandles.containsValue(h)) {
         handles.set(h - 1, null);
      }
   }

   /** getSystemCursorWidth/Height (GetSystemMetrics SM_CXCURSOR 13 / SM_CYCURSOR 14): system cursor size. */
   public static int systemCursorSize(boolean height) {
      try {
         java.awt.Dimension d = Toolkit.getDefaultToolkit().getBestCursorSize(32, 32);
         return height ? d.height : d.width;
      } catch (Exception e) {
         return 0;
      }
   }

   /** getSystemCursorDepth (GetDeviceCaps(GetDC(NULL), BITSPIXEL)): bits per pixel of the screen. */
   public static int systemCursorDepth() {
      try {
         java.awt.GraphicsDevice g = java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice();
         int bits = g.getDisplayMode().getBitDepth();
         return bits > 0 ? bits : g.getDefaultConfiguration().getColorModel().getPixelSize();
      } catch (Exception e) {
         return 0;
      }
   }

   /**
    * .cur file (ICO format with type 2): 6-byte header, 16-byte entries with
    * the hot spot in the planes/bits fields (u16 @+4/+6), and one DIB per
    * entry (BITMAPINFOHEADER with double height: XOR map and 1 bpp AND mask,
    * rows bottom to top, padded to 4 bytes). The first entry is taken, as
    * LoadCursorFromFile does with single-size cursors. AND=1 and XOR=0 is
    * transparent; AND=0 is the XOR color; AND=1 and XOR!=0 (invert the
    * screen) ⚠️ does not exist in AWT: it is painted black.
    * Returns {BufferedImage, Point} or null. .ani files (RIFF) are not decoded.
    */
   public static Object[] decodeCur(byte[] b) {
      if (b.length < 22 || u16(b, 0) != 0 || u16(b, 2) != 2 || u16(b, 4) < 1) {
         return null;
      }
      int hotX = u16(b, 10);
      int hotY = u16(b, 12);
      int off = (int) u32(b, 18);
      if (off + 40 > b.length) {
         return null;
      }
      int w = (int) u32(b, off + 4);
      int h2 = (int) u32(b, off + 8);
      int h = h2 / 2;
      int bpp = u16(b, off + 14);
      int hdr = (int) u32(b, off);
      int nColors = bpp <= 8 ? ((int) u32(b, off + 32) != 0 ? (int) u32(b, off + 32) : 1 << bpp) : 0;
      int pal = off + hdr;
      int xor = pal + nColors * 4;
      int xorStride = ((w * bpp + 31) / 32) * 4;
      int and = xor + xorStride * h;
      int andStride = ((w + 31) / 32) * 4;
      if (w <= 0 || h <= 0 || and + andStride * h > b.length) {
         return null;
      }
      BufferedImage img = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
      for (int y = 0; y < h; y++) {
         int row = h - 1 - y;
         for (int x = 0; x < w; x++) {
            int color;
            if (bpp <= 8) {
               int bit = x * bpp;
               int v = (b[xor + row * xorStride + bit / 8] & 0xFF) >> (8 - bpp - bit % 8) & ((1 << bpp) - 1);
               int p = pal + v * 4;
               color = (b[p + 2] & 0xFF) << 16 | (b[p + 1] & 0xFF) << 8 | (b[p] & 0xFF);
            } else {
               int p = xor + row * xorStride + x * (bpp / 8);
               color = (b[p + 2] & 0xFF) << 16 | (b[p + 1] & 0xFF) << 8 | (b[p] & 0xFF);
            }
            boolean mask = ((b[and + row * andStride + x / 8] & 0xFF) >> (7 - x % 8) & 1) != 0;
            int argb;
            if (!mask) {
               argb = 0xFF000000 | color;
            } else if (color == 0) {
               argb = 0;
            } else {
               argb = 0xFF000000;
            }
            img.setRGB(x, y, argb);
         }
      }
      return new Object[]{img, new Point(hotX, hotY)};
   }

   private static int u16(byte[] b, int o) {
      return (b[o] & 0xFF) | (b[o + 1] & 0xFF) << 8;
   }

   private static long u32(byte[] b, int o) {
      return (u16(b, o) | (long) u16(b, o + 2) << 16) & 0xFFFFFFFFL;
   }

   // --------------------------------------------------- cursor application

   /** DAT_004891c8: the chosen cursor. */
   private static int current;

   /**
    * Window.setCursor (0x0040e710): without a main window it is only stored
    * (Window.install sends it later, 0x0040db60); with one, message 0x8067
    * to the WndProc (0x0040c970), which stores the cursor and sets it right
    * away if the mouse is over the window; on WM_SETCURSOR with HTCLIENT the
    * WndProc sets it again. AWT equivalent: {@code Component.setCursor} on the
    * main window's component (the RenderCanvas), which AWT shows while the
    * mouse is over its client area.
    */
   public static synchronized void setCursor(int h) {
      current = h;
      apply();
   }

   /**
    * The chosen cursor (DAT_004891c8), or the default one if there is none:
    * what the WndProc sets again with WM_SETCURSOR on leaving hidden-cursor
    * mode.
    */
   public static synchronized java.awt.Cursor current() {
      java.awt.Cursor c = get(current);
      return c != null ? c : java.awt.Cursor.getDefaultCursor();
   }

   /** Window.install (0x0040db60): SendMessage(hWnd, 0x8067, DAT_004891c8). */
   public static synchronized void installed() {
      apply();
   }

   private static void apply() {
      final java.awt.Cursor c = get(current);
      final java.awt.Component comp = NativeWindows.component(NativeWindows.mainHwnd());
      if (c == null || comp == null) {
         return;
      }
      java.awt.EventQueue.invokeLater(new Runnable() {
         public void run() {
            comp.setCursor(c);
         }
      });
   }
}

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
 * Cursores de gamma.dll (Console.Cursor, 0x0040bd70..0x0040bfb0) y su
 * aplicacion (Window.setCursor 0x0040e710 + WndProc 0x0040c970).
 *
 * <p>Un HCURSOR es aqui un indice (&gt;0) en una tabla de {@link java.awt.Cursor}.
 * LoadCursor(NULL, IDC_*) devuelve siempre el mismo handle compartido para
 * cada IDC, asi que cada cursor de sistema tiene un handle fijo.
 */
public final class NativeUiCursor {
   private NativeUiCursor() {
   }

   /**
    * Tabla de 0x0046e81c (12 pares nombre / IDC_*, leida del .data con
    * pe), comparada con strcmp (FUN_0044d730, distingue mayusculas).
    * Equivalente AWT por forma del cursor de Windows; las que AWT no tiene
    * van marcadas:
    */
   static final String[] NAMES = {"IDC_APPSTARTING", "IDC_ARROW", "IDC_CROSS", "IDC_IBEAM", "IDC_NO", "IDC_SIZEALL",
      "IDC_SIZENESW", "IDC_SIZENS", "IDC_SIZENWSE", "IDC_SIZEWE", "IDC_UPARROW", "IDC_WAIT"};
   static final int[] IDC = {32650, 32512, 32515, 32513, 32648, 32646, 32643, 32645, 32642, 32644, 32516, 32514};
   static final int[] AWT = {
      java.awt.Cursor.WAIT_CURSOR, // APPSTARTING (flecha + reloj): ⚠️ AWT no tiene la mezcla
      java.awt.Cursor.DEFAULT_CURSOR, java.awt.Cursor.CROSSHAIR_CURSOR, java.awt.Cursor.TEXT_CURSOR,
      java.awt.Cursor.DEFAULT_CURSOR, // NO (circulo tachado): ⚠️ sin equivalente AWT predefinido
      java.awt.Cursor.MOVE_CURSOR, java.awt.Cursor.NE_RESIZE_CURSOR, java.awt.Cursor.N_RESIZE_CURSOR,
      java.awt.Cursor.NW_RESIZE_CURSOR, java.awt.Cursor.E_RESIZE_CURSOR,
      java.awt.Cursor.HAND_CURSOR, // UPARROW (flecha vertical), que el cliente llama HAND_CURSOR: ⚠️ forma distinta
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

   /** Cursor.loadSystemCursor (0x0040bed0): 0 si el nombre no esta en la tabla. */
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
    * Cursor.loadCursor (0x0040bd70): null -> 0. Ruta que no empieza por
    * '\\' o '/' ni tiene ':' en la segunda posicion -> se antepone el
    * directorio actual (_getcwd, 300 bytes) con '\\' si no acaba en
    * separador; si strlen(ruta)+strlen(cwd)+2 &gt;= 300, asercion "nCursor"
    * linea 0x25. Luego LoadCursorFromFileA: aqui el .cur se decodifica con
    * {@link #decodeCur}; un fichero ilegible devuelve 0 como la API.
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

   /** getSystemCursorWidth/Height (GetSystemMetrics SM_CXCURSOR 13 / SM_CYCURSOR 14): tamano de cursor del sistema. */
   public static int systemCursorSize(boolean height) {
      try {
         java.awt.Dimension d = Toolkit.getDefaultToolkit().getBestCursorSize(32, 32);
         return height ? d.height : d.width;
      } catch (Exception e) {
         return 0;
      }
   }

   /** getSystemCursorDepth (GetDeviceCaps(GetDC(NULL), BITSPIXEL)): bits por pixel de la pantalla. */
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
    * Fichero .cur (formato ICO con tipo 2): cabecera de 6 bytes, entradas de
    * 16 con el punto caliente en los campos planos/bits (u16 @+4/+6), y un
    * DIB por entrada (BITMAPINFOHEADER con alto doble: mapa XOR y mascara
    * AND de 1 bpp, filas de abajo arriba, rellenas a 4 bytes). Se toma la
    * primera entrada, como hace LoadCursorFromFile con cursores de un
    * tamano. AND=1 y XOR=0 es transparente; AND=0 es el color XOR; AND=1 y
    * XOR!=0 (invertir la pantalla) ⚠️ no existe en AWT: se pinta negro.
    * Devuelve {BufferedImage, Point} o null. Los .ani (RIFF) no se decodifican.
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

   // --------------------------------------------------- aplicacion del cursor

   /** DAT_004891c8: el cursor elegido. */
   private static int current;

   /**
    * Window.setCursor (0x0040e710): sin ventana principal solo se guarda
    * (Window.install lo manda despues, 0x0040db60); con ella, mensaje 0x8067
    * a la WndProc (0x0040c970), que guarda el cursor y lo pone ya si el
    * raton esta sobre la ventana; en WM_SETCURSOR con HTCLIENT la WndProc
    * vuelve a ponerlo. Equivalente AWT: {@code Component.setCursor} en el
    * componente de la ventana principal (el RenderCanvas), que AWT muestra
    * mientras el raton esta sobre su area cliente.
    */
   public static synchronized void setCursor(int h) {
      current = h;
      apply();
   }

   /**
    * El cursor elegido (DAT_004891c8), o el de por defecto si no hay: lo que
    * el WndProc vuelve a poner con WM_SETCURSOR al salir del modo de cursor
    * oculto.
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

package net.openworlds.awt;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayDeque;

/**
 * A screen in memory: what tests and the desktop JVM use. Input is what the
 * test {@link #inject}s; the picture can be read or saved as a PNG.
 * Size: -Dopenworlds.screen.size=960x544 (the Vita's).
 */
public class HeadlessScreen extends Screen {
   private final int width;
   private final int height;
   private final int[] shown;
   private final ArrayDeque<int[]> events = new ArrayDeque<int[]>();
   private long frames;

   public HeadlessScreen() {
      this(sizeProperty(0, 960), sizeProperty(1, 544));
   }

   public HeadlessScreen(int width, int height) {
      this.width = width;
      this.height = height;
      this.shown = new int[width * height];
   }

   private static int sizeProperty(int i, int def) {
      String s = System.getProperty("openworlds.screen.size");
      if (s != null) {
         String[] p = s.toLowerCase().split("x");
         if (p.length == 2) {
            try {
               return Integer.parseInt(p[i].trim());
            } catch (NumberFormatException e) {
               // the default below
            }
         }
      }
      return def;
   }

   public int width() {
      return width;
   }

   public int height() {
      return height;
   }

   public void present(int[] pixels, int x, int y, int w, int h) {
      synchronized (shown) {
         for (int row = y; row < y + h; row++) {
            System.arraycopy(pixels, row * width + x, shown, row * width + x, w);
         }
         frames++;
         shown.notifyAll();
      }
   }

   public boolean nextEvent(int[] event, long timeoutMillis) {
      synchronized (events) {
         long end = System.currentTimeMillis() + timeoutMillis;
         while (events.isEmpty()) {
            long left = end - System.currentTimeMillis();
            if (left <= 0) {
               return false;
            }
            try {
               events.wait(left);
            } catch (InterruptedException e) {
               return false;
            }
         }
         int[] e = events.removeFirst();
         System.arraycopy(e, 0, event, 0, Math.min(e.length, event.length));
         for (int i = e.length; i < event.length; i++) {
            event[i] = 0;
         }
         return true;
      }
   }

   /** Queues an input event (see {@link Screen} for the fields). */
   public void inject(int... event) {
      synchronized (events) {
         events.addLast(event.clone());
         events.notifyAll();
      }
   }

   public void click(int x, int y) {
      inject(POINTER_MOVED, x, y, 0, 0, 0, 0);
      inject(POINTER_PRESSED, x, y, 1, 0, 1 << 10, 0);
      inject(POINTER_RELEASED, x, y, 1, 0, 0, 0);
   }

   public void type(String text) {
      for (char c : text.toCharArray()) {
         int vk = java.awt.event.KeyEvent.getExtendedKeyCodeForChar(c);
         if (vk > 0xFFFF) {
            vk = 0;
         }
         inject(KEY_PRESSED, 0, 0, vk, c, 0, 1);
         inject(KEY_RELEASED, 0, 0, vk, c, 0, 1);
      }
   }

   public void key(int vk, char c) {
      inject(KEY_PRESSED, 0, 0, vk, c, 0, 1);
      inject(KEY_RELEASED, 0, 0, vk, c, 0, 1);
   }

   /** How many times something was shown. */
   public long frames() {
      synchronized (shown) {
         return frames;
      }
   }

   /** Waits until something is shown after frame number {@code after}, up to timeoutMillis. */
   public boolean awaitFrame(long after, long timeoutMillis) {
      synchronized (shown) {
         long end = System.currentTimeMillis() + timeoutMillis;
         while (frames <= after) {
            long left = end - System.currentTimeMillis();
            if (left <= 0) {
               return false;
            }
            try {
               shown.wait(left);
            } catch (InterruptedException e) {
               return false;
            }
         }
         return true;
      }
   }

   /** A copy of what is on the screen. */
   public int[] snapshot() {
      synchronized (shown) {
         return shown.clone();
      }
   }

   public int pixel(int x, int y) {
      synchronized (shown) {
         return shown[y * width + x];
      }
   }

   public void savePng(File file) throws IOException {
      OutputStream out = new FileOutputStream(file);
      try {
         writePng(snapshot(), width, height, out);
      } finally {
         out.close();
      }
   }

   /** A PNG (8-bit RGB) of ARGB pixels. */
   public static void writePng(int[] argb, int w, int h, OutputStream os) throws IOException {
      PngWriter.write(argb, w, h, false, os);
   }
}

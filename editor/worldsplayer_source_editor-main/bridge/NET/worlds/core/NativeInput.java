package NET.worlds.core;

import java.awt.Component;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

/**
 * gamma.dll's input path: the window procedure it subclasses onto the
 * render window (0x0040c970) turns Win32 keyboard and mouse messages into
 * records of the native event queue (0x00416940 add, 0x00416b00 read) that
 * NET.worlds.scape.EventQueue polls. Here the same translation is driven
 * by the AWT events of the render canvas (the component that was that
 * window under the original JVM).
 *
 * Clock: GetTickCount / GetMessageTime are {@link #tick()}; Std.getTimeZero
 * is tick() - 1 at start-up (0x00403e6a) and Std.nativeGetMillis is
 * tick() - zero (0x00402d10).
 */
public final class NativeInput {
   private NativeInput() {
   }

   // ------------------------------------------------------------------ clock

   private static final long START_NANOS = System.nanoTime();

   /**
    * Length of a Windows clock tick in nanoseconds: GetTickCount advances in
    * steps of the system timer, 15.625 ms (64 Hz) on NT/2000/XP, the systems
    * of the 2004 client. gamma.dll takes its time from GetTickCount
    * (0x00402d10; the timeGetTime branch depends on DAT_00489054, which
    * nothing in the binary writes). The game logic counts on that step:
    * SmoothDriver zeroes a velocity under minFB_vel / minLR_vel after each
    * frame, and with a 1 ms clock at the bridge's hundreds of frames per
    * second the push of one frame never gets past them (turning dropped to
    * about 1 degree a second instead of about 100). -Dfreeworlds.tickMs
    * changes the step (0 = one millisecond).
    */
   private static final long TICK_NANOS = tickNanos();

   private static long tickNanos() {
      String s = System.getProperty("freeworlds.tickMs");
      try {
         double ms = s == null ? 15.625 : Double.parseDouble(s);
         return ms <= 0 ? 1000000L : Math.round(ms * 1000000.0);
      } catch (NumberFormatException e) {
         return 15625000L;
      }
   }

   /** GetTickCount: whole milliseconds at the start of the current system tick. */
   public static int tick() {
      long ns = System.nanoTime() - START_NANOS;
      return (int) (ns / TICK_NANOS * TICK_NANOS / 1000000L) + 1000;
   }

   public static final int TIME_ZERO = tick() - 1;

   public static int millis() {
      int d = tick() - TIME_ZERO;
      if (d < 0) {
         NativeAssert.fail("nStd", 0xbc);
      }
      return d;
   }

   // ------------------------------------------------------------------ queue

   private static final class Rec {
      int key;
      int type;
      int time;
      int x;
      int y;
      String url;
   }

   private static final java.util.ArrayDeque<Rec> queue = new java.util.ArrayDeque<Rec>();

   /**
    * 0x00416940: append, except that a mouse move (6) or mouse delta (7)
    * of the same type as the last queued record updates it (move: new
    * position, delta: accumulated).
    */
   public static void addEvent(int key, int type, int time, int x, int y) {
      synchronized (queue) {
         Rec last = queue.peekLast();
         if (last != null && last.type == type && type - 6 >= 0 && type - 6 <= 1) {
            if (type == 6) {
               last.x = x;
               last.y = y;
            } else {
               last.x += x;
               last.y += y;
            }
            return;
         }
         Rec r = new Rec();
         r.key = key & 0xFFFF;
         r.type = type;
         r.time = time;
         r.x = x;
         r.y = y;
         queue.addLast(r);
      }
   }

   /** 0x00416aa0 (WM_COPYDATA from a second instance): a teleport record. */
   public static void addTeleport(String url) {
      synchronized (queue) {
         Rec r = new Rec();
         r.type = 10;
         r.url = url;
         queue.addLast(r);
      }
   }

   public static int eventCount() {
      synchronized (queue) {
         return queue.size();
      }
   }

   /**
    * 0x00416b00: pop records into {key, type, time, x, y}; teleport records
    * are consumed by calling TeleportAction.teleport(url, null) and the
    * loop continues. Returns null when the queue is empty.
    */
   public static int[] nextEvent() {
      while (true) {
         Rec r;
         synchronized (queue) {
            r = queue.pollFirst();
         }
         if (r == null) {
            return null;
         }
         if (r.type != 10) {
            return new int[]{r.key, r.type, r.time, r.x, r.y};
         }
         try {
            NET.worlds.scape.TeleportAction.teleport(r.url, null);
         } catch (RuntimeException e) {
            e.printStackTrace();
         }
      }
   }

   // ------------------------------------------------------------------ window procedure

   /** Keys held down, indexed by virtual key (DAT_0048927c). */
   private static final boolean[] down = new boolean[256];
   /** DAT_00489244: user actions since Window.getAndResetUserActionCount. */
   private static int userActions;
   /** Window instance delta flag (+0x24) and the global capture flag DAT_00489278. */
   private static boolean instanceDelta;
   private static boolean captured;
   /** Last screen position (+0x28 / +0x2c). */
   private static int lastX;
   private static int lastY;
   private static Component canvas;
   private static boolean charAllowed;

   public static synchronized int getAndResetUserActionCount() {
      int n = userActions;
      userActions = 0;
      return n;
   }

   public static boolean getDeltaMode() {
      return instanceDelta;
   }

   /**
    * Window.setDeltaMode (0x0040c6a0): switching on needs a mouse button
    * held; then message 0x8065 (0x0040c780) captures the mouse, hides the
    * cursor and re-centres it, or releases it.
    */
   public static synchronized void setDeltaMode(boolean on) {
      if (instanceDelta == on) {
         return;
      }
      if (on && !down[1] && !down[4] && !down[2]) {
         return;
      }
      instanceDelta = on;
      captured = on;
      Component c = canvas;
      if (c != null) {
         if (on) {
            c.setCursor(c.getToolkit().createCustomCursor(new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_ARGB), new java.awt.Point(0, 0), "hidden"));
            recentre();
         } else {
            c.setCursor(NativeUiCursor.current());
         }
      }
   }

   private static void recentre() {
      try {
         new java.awt.Robot().mouseMove(0x140, 0xf0);
         lastX = 0x140;
         lastY = 0xf0;
      } catch (Exception e) {
         // no Robot permission: the delta keeps accumulating from the real position
      }
   }

   /** Virtual key as gamma.dll puts it in a record: digits and letters as is, the rest | 0xE300. */
   private static int recordKey(int vk) {
      if (vk >= 0x100) {
         return 0;
      }
      if (vk >= 0x30 && vk <= 0x39 || vk >= 0x41 && vk <= 0x5a || vk == 0x20) {
         return vk;
      }
      return vk | 0xe300;
   }

   /**
    * 0x0040c2c0: first a mouse move (6, client coordinates) or, in delta
    * mode, a mouse delta (7, screen delta, cursor re-centred outside
    * 160..480 x 120..360) when the pointer moved; then the event itself.
    */
   private static synchronized void post(int type, int key, int time, int screenX, int screenY, int clientX, int clientY) {
      if (captured == instanceDelta) {
         if (!instanceDelta) {
            if (screenX != lastX || screenY != lastY) {
               addEvent(0, 6, time, clientX, clientY);
            }
            lastX = screenX;
            lastY = screenY;
         } else {
            int dx = screenX - lastX, dy = screenY - lastY;
            int sx = screenX, sy = screenY;
            if (sx < 0xa0 || sx > 0x1e0 || sy < 0x78 || sy > 0x168) {
               recentre();
               sx = lastX;
               sy = lastY;
            }
            if (dx != 0 || dy != 0) {
               addEvent(0, 7, time, dx, dy);
            }
            lastX = sx;
            lastY = sy;
         }
      }
      if (type != 6) {
         addEvent(key, type, time, clientX, clientY);
      }
   }

   private static int[] pointer(Component c) {
      java.awt.PointerInfo pi = java.awt.MouseInfo.getPointerInfo();
      java.awt.Point p = pi == null ? new java.awt.Point(lastX, lastY) : pi.getLocation();
      java.awt.Point o;
      try {
         o = c.getLocationOnScreen();
      } catch (Exception e) {
         o = new java.awt.Point(0, 0);
      }
      return new int[]{p.x, p.y, p.x - o.x, p.y - o.y};
   }

   /**
    * 0x0040c440: key down / up for a virtual key (mouse buttons are VK 1, 2,
    * 4 and become mouse down 4 / up 5). A key already down gets an up
    * first; auto-repeat is ignored.
    */
   private static synchronized void key(Component c, int vk, boolean isDown, boolean repeat) {
      if (repeat) {
         return;
      }
      int rk = recordKey(vk);
      if (rk == 0) {
         return;
      }
      boolean mouse = vk < 5 && vk != 0 && vk != 3;
      if (mouse) {
         setCapture(c, isDown);
      }
      int[] p = pointer(c);
      int time = tick();
      if (down[vk]) {
         post(mouse ? 5 : 2, rk, time, p[0], p[1], p[2], p[3]);
         down[vk] = false;
      }
      if (!isDown) {
         post(mouse ? 5 : 2, rk, time, p[0], p[1], p[2], p[3]);
      } else {
         post(mouse ? 4 : 1, rk, time, p[0], p[1], p[2], p[3]);
         down[vk] = true;
      }
   }

   /** Message 0x8065 without the delta bit: plain capture while a button is held (focus to the window). */
   private static void setCapture(Component c, boolean on) {
      if (on) {
         c.requestFocus();
      }
   }

   /** Every held key gets a key up (focus lost, all mouse buttons released). */
   private static synchronized void releaseAll(Component c) {
      if (instanceDelta) {
         setDeltaMode(false);
      }
      int[] p = pointer(c);
      int time = tick();
      for (int vk = 255; vk >= 0; vk--) {
         if (down[vk]) {
            int rk = recordKey(vk);
            if (rk != 0) {
               post(2, rk, time, p[0], p[1], p[2], p[3]);
            }
            down[vk] = false;
         }
      }
   }

   /**
    * AWT key code to the Win32 virtual key the original window received.
    * Most codes coincide; the table covers the ones that do not.
    */
   static int virtualKey(KeyEvent e) {
      int k = e.getKeyCode();
      switch (k) {
         case KeyEvent.VK_ENTER:
            return 0x0d;
         case KeyEvent.VK_DELETE:
            return 0x2e;
         case KeyEvent.VK_INSERT:
            return 0x2d;
         case KeyEvent.VK_SEMICOLON:
            return 0xba;
         case KeyEvent.VK_EQUALS:
            return 0xbb;
         case KeyEvent.VK_COMMA:
            return 0xbc;
         case KeyEvent.VK_MINUS:
            return 0xbd;
         case KeyEvent.VK_PERIOD:
            return 0xbe;
         case KeyEvent.VK_SLASH:
            return 0xbf;
         case KeyEvent.VK_BACK_QUOTE:
            return 0xc0;
         case KeyEvent.VK_OPEN_BRACKET:
            return 0xdb;
         case KeyEvent.VK_BACK_SLASH:
            return 0xdc;
         case KeyEvent.VK_CLOSE_BRACKET:
            return 0xdd;
         case KeyEvent.VK_QUOTE:
            return 0xde;
         case KeyEvent.VK_META:
         case KeyEvent.VK_WINDOWS:
            return 0x5b;
         default:
            return k < 0x100 ? k : 0;
      }
   }

   /** Window.install on the main instance: hook the render canvas (the subclassed window procedure). */
   public static synchronized void attach(final Component c) {
      if (c == null || canvas == c) {
         return;
      }
      canvas = c;
      c.setFocusable(true);
      c.addKeyListener(new KeyAdapter() {
         public void keyPressed(KeyEvent e) {
            int vk = virtualKey(e);
            if (vk == 0) {
               return;
            }
            synchronized (NativeInput.class) {
               userActions++;
            }
            boolean repeat = down[vk];
            charAllowed = !repeat;
            key(c, vk, true, repeat);
         }

         public void keyReleased(KeyEvent e) {
            int vk = virtualKey(e);
            if (vk != 0) {
               key(c, vk, false, false);
            }
         }

         public void keyTyped(KeyEvent e) {
            // WM_CHAR (0x102): key char record 3; repeats are ignored like the key downs
            if (!charAllowed) {
               return;
            }
            charAllowed = false;
            char ch = e.getKeyChar();
            if (ch == KeyEvent.CHAR_UNDEFINED) {
               return;
            }
            if (ch == '\n') {
               ch = '\r';
            }
            synchronized (NativeInput.class) {
               userActions++;
               int[] p = pointer(c);
               post(3, ch, tick(), p[0], p[1], p[2], p[3]);
            }
         }
      });
      MouseAdapter m = new MouseAdapter() {
         private int vk(MouseEvent e) {
            switch (e.getButton()) {
               case MouseEvent.BUTTON1:
                  return 1;
               case MouseEvent.BUTTON2:
                  return 4;
               case MouseEvent.BUTTON3:
                  return 2;
               default:
                  return 0;
            }
         }

         private boolean anyButton(MouseEvent e) {
            return (e.getModifiersEx() & (MouseEvent.BUTTON1_DOWN_MASK | MouseEvent.BUTTON2_DOWN_MASK | MouseEvent.BUTTON3_DOWN_MASK)) != 0;
         }

         public void mousePressed(MouseEvent e) {
            hiddenCursor(c, 0x201, true, e.getXOnScreen(), e.getYOnScreen());
            int v = vk(e);
            if (v == 0) {
               return;
            }
            if (v == 1) {
               synchronized (NativeInput.class) {
                  userActions++;
               }
            }
            key(c, v, true, false);
         }

         public void mouseReleased(MouseEvent e) {
            hiddenCursor(c, e.getButton() == MouseEvent.BUTTON1 ? 0x202 : e.getButton() == MouseEvent.BUTTON3 ? 0x205 : 0x208, anyButton(e), e.getXOnScreen(), e.getYOnScreen());
            int v = vk(e);
            if (v == 0) {
               return;
            }
            key(c, v, false, false);
            int held = e.getModifiersEx() & (MouseEvent.BUTTON1_DOWN_MASK | MouseEvent.BUTTON2_DOWN_MASK | MouseEvent.BUTTON3_DOWN_MASK);
            if (held == 0) {
               releaseAll(c);
            }
         }

         public void mouseMoved(MouseEvent e) {
            hiddenCursor(c, 0x200, false, e.getXOnScreen(), e.getYOnScreen());
            post(6, 0, tick(), e.getXOnScreen(), e.getYOnScreen(), e.getX(), e.getY());
         }

         public void mouseDragged(MouseEvent e) {
            hiddenCursor(c, 0x200, true, e.getXOnScreen(), e.getYOnScreen());
            post(6, 0, tick(), e.getXOnScreen(), e.getYOnScreen(), e.getX(), e.getY());
         }

         public void mouseEntered(MouseEvent e) {
            post(8, 0, tick(), e.getXOnScreen(), e.getYOnScreen(), e.getX(), e.getY());
         }

         public void mouseExited(MouseEvent e) {
            post(9, 0, tick(), e.getXOnScreen(), e.getYOnScreen(), e.getX(), e.getY());
         }
      };
      c.addMouseListener(m);
      c.addMouseMotionListener(m);
      scriptedKeys(c);
      c.addFocusListener(new FocusAdapter() {
         public void focusLost(FocusEvent e) {
            releaseAll(c);
         }
      });
   }
   // ------------------------------------------------------------------ hidden cursor (DAT_00489220)

   private static int hiddenState;
   private static int hiddenStartX;
   private static int hiddenStartY;
   private static int hiddenLastX;
   private static int hiddenLastY;
   private static int hiddenDX;
   private static int hiddenDY;

   /** Window.hideCursor (0x0040e670). */
   public static synchronized void hideCursor() {
      hiddenState = 1;
   }

   /** Window.getHiddenCursorDelta (0x0040e680): accumulated {dx, dy}, then reset. */
   public static synchronized int[] getHiddenCursorDelta() {
      int[] d = {hiddenDX, hiddenDY};
      hiddenDX = 0;
      hiddenDY = 0;
      return d;
   }

   /**
    * Top of the window procedure (0x0040c970): in state 1 a button-up or a
    * move with no button held cancels; with the mouse captured (a button
    * held) the cursor is hidden and state 2 accumulates the moves,
    * re-centring outside 160..480 x 120..360; left-button up restores it.
    */
   private static synchronized void hiddenCursor(Component c, int msg, boolean anyButton, int sx, int sy) {
      if (hiddenState == 1) {
         if ((msg == 0x202 || msg == 0x208 || msg == 0x205 || msg == 0x200) && !anyButton) {
            hiddenState = 0;
         } else if (anyButton) {
            hiddenStartX = hiddenLastX = sx;
            hiddenStartY = hiddenLastY = sy;
            c.setCursor(c.getToolkit().createCustomCursor(new java.awt.image.BufferedImage(1, 1, java.awt.image.BufferedImage.TYPE_INT_ARGB), new java.awt.Point(0, 0), "hidden"));
            hiddenState = 2;
            hiddenDX = 0;
            hiddenDY = 0;
         }
      }
      if (msg == 0x200 && hiddenState == 2 && anyButton) {
         hiddenDX += sx - hiddenLastX;
         hiddenDY += sy - hiddenLastY;
         hiddenLastX = sx;
         hiddenLastY = sy;
         if (sx < 0xa0 || sx > 0x1e0 || sy < 0x78 || sy > 0x168) {
            try {
               new java.awt.Robot().mouseMove(0x140, 0xf0);
               hiddenLastX = 0x140;
               hiddenLastY = 0xf0;
            } catch (Exception e) {
               // no Robot permission
            }
         }
      } else if (msg == 0x202 && hiddenState == 2) {
         try {
            new java.awt.Robot().mouseMove(hiddenStartX, hiddenStartY);
         } catch (Exception e) {
            // no Robot permission
         }
         c.setCursor(NativeUiCursor.current());
         hiddenState = 0;
      }
   }
   /**
    * Harness diagnostic, off by default: -Dfreeworlds.scriptKeys=START_MS:KEYCODE:HOLD_MS[,...]
    * dispatches synthetic AWT key presses/releases to the render canvas so the
    * input path can be exercised without a person at the keyboard.
    */
   private static void scriptedKeys(final Component c) {
      final String spec = System.getProperty("freeworlds.scriptKeys");
      if (spec == null) {
         return;
      }
      Thread t = new Thread("freeworlds-scriptKeys") {
         public void run() {
            long t0 = System.currentTimeMillis();
            for (String item : spec.split(",")) {
               String[] f = item.split(":");
               long start = Long.parseLong(f[0]);
               int code = Integer.parseInt(f[1]);
               long hold = Long.parseLong(f[2]);
               try {
                  long wait = t0 + start - System.currentTimeMillis();
                  if (wait > 0) {
                     Thread.sleep(wait);
                  }
                  System.err.println("[scriptKeys] press " + code);
                  c.dispatchEvent(new KeyEvent(c, KeyEvent.KEY_PRESSED, System.currentTimeMillis(), 0, code, KeyEvent.CHAR_UNDEFINED));
                  Thread.sleep(hold);
                  c.dispatchEvent(new KeyEvent(c, KeyEvent.KEY_RELEASED, System.currentTimeMillis(), 0, code, KeyEvent.CHAR_UNDEFINED));
                  System.err.println("[scriptKeys] release " + code);
               } catch (InterruptedException e) {
                  return;
               }
            }
         }
      };
      t.setDaemon(true);
      t.start();
   }
}

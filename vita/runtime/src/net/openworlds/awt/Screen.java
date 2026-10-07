package net.openworlds.awt;

/**
 * What our java.awt needs from the machine: a screen of ARGB pixels to show
 * and the input to read. {@link #get()} picks the implementation:
 * {@code -Dopenworlds.screen=headless} (memory only, for tests on a JVM) or
 * the native one (SDL2 on Linux and on the PSVita, through Clearwing VM).
 *
 * Input comes as events of seven ints (see the constants): the AWT's input
 * thread asks for them with {@link #nextEvent}.
 */
public abstract class Screen {
   /** event[0]: what happened */
   public static final int POINTER_MOVED = 1;
   public static final int POINTER_PRESSED = 2;
   public static final int POINTER_RELEASED = 3;
   public static final int WHEEL = 4;
   public static final int KEY_PRESSED = 5;
   public static final int KEY_RELEASED = 6;
   /** A character typed (event[4]), with no key event of its own: the IME's text. */
   public static final int TEXT = 7;
   /** The system asks the program to close (the window's close button, the Vita's PS button menu). */
   public static final int QUIT = 8;

   // pointer events: event[1] x, event[2] y, event[3] button (1 left, 2 middle, 3 right), event[5] modifiers (InputEvent *_DOWN_MASK)
   // wheel: event[1] x, event[2] y, event[3] rotation (+1 towards the user)
   // key events: event[3] java.awt.event.KeyEvent.VK_*, event[4] the character or 0xFFFF, event[5] modifiers, event[6] location

   private static Screen instance;

   public static synchronized Screen get() {
      if (instance == null) {
         String kind = System.getProperty("openworlds.screen", "native");
         instance = "headless".equals(kind) ? new HeadlessScreen() : NativeScreen.open();
      }
      return instance;
   }

   /** For tests: use this screen (before the AWT starts). */
   public static synchronized void use(Screen screen) {
      instance = screen;
   }

   public abstract int width();

   public abstract int height();

   /**
    * Shows the screen: pixels is width() * height() ARGB, and only the
    * rectangle (x, y, w, h) changed since the last call.
    */
   public abstract void present(int[] pixels, int x, int y, int w, int h);

   /** Waits up to timeoutMillis for an input event; false if none came. */
   public abstract boolean nextEvent(int[] event, long timeoutMillis);

   /** The pointer's shape changed (java.awt.Cursor types); for a system mouse cursor. */
   public void setCursorShape(int type) {
   }

   /** Whether a pointer is shown on the screen (a mouse, or the stick driving one): the AWT then draws the cursor. */
   public boolean drawsOwnCursor() {
      return false;
   }

   /**
    * A text field got the focus and wants text: on the Vita, the system's
    * keyboard (IME) opens with the current text; what is typed comes back
    * as TEXT events (and Enter as a key). Elsewhere, nothing.
    */
   public void requestText(String current, boolean multiline, boolean password, String title) {
   }

   /** The text field lost the focus. */
   public void endText() {
   }
}

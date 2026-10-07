package net.openworlds.awt;

/**
 * The screen of the machine the transpiled client runs on: SDL2 (a window
 * on Linux, the whole screen on the PSVita). Its native methods are C++
 * (vita/native/screen.cpp), compiled with the transpiled program.
 */
final class NativeScreen extends Screen {
   private final int width;
   private final int height;

   private NativeScreen(int width, int height) {
      this.width = width;
      this.height = height;
   }

   static Screen open() {
      int[] size = new int[2];
      if (!nativeOpen(size)) {
         throw new java.awt.AWTError("no screen: " + nativeError());
      }
      return new NativeScreen(size[0], size[1]);
   }

   public int width() {
      return width;
   }

   public int height() {
      return height;
   }

   public void present(int[] pixels, int x, int y, int w, int h) {
      nativePresent(pixels, width, height, x, y, w, h);
   }

   public boolean nextEvent(int[] event, long timeoutMillis) {
      return nativeNextEvent(event, (int) Math.min(Integer.MAX_VALUE, timeoutMillis));
   }

   public boolean drawsOwnCursor() {
      return nativeDrawsCursor();
   }

   public void requestText(String current, boolean multiline, boolean password, String title) {
      nativeRequestText(current == null ? "" : current, multiline, password, title == null ? "" : title);
   }

   public void endText() {
      nativeEndText();
   }

   private static native boolean nativeOpen(int[] size);

   private static native String nativeError();

   private static native void nativePresent(int[] pixels, int width, int height, int x, int y, int w, int h);

   private static native boolean nativeNextEvent(int[] event, int timeoutMillis);

   private static native boolean nativeDrawsCursor();

   private static native void nativeRequestText(String current, boolean multiline, boolean password, String title);

   private static native void nativeEndText();
}

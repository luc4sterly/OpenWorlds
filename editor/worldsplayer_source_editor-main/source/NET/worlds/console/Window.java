package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.scape.Camera;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.TextArea;

public class Window {
   private static Window activeWindow;
   private int hWndGamma;
   private int hWndFrame;
   private static int hInstGamma;
   private static int hWndFrameStatic;
   public static final int NORMAL = 0;
   public static final int MINIMIZED = 1;
   public static final int MAXIMIZED = 2;
   private int windowInstancePtr;

   public Window(String var1, Point var2, Dimension var3, Camera var4, boolean var5) throws WindowNotFoundException {
      nativeInit();
      if (hWndFrameStatic != 0) {
         this.hWndFrame = hWndFrameStatic;
      } else {
         this.hWndFrame = findWindow(var1);
      }

      if (this.hWndFrame != 0) {
         this.hWndGamma = findOrMakeChildWindow(this.hWndFrame, var2.x, var2.y, var3.width, var3.height);
      }

      if (this.hWndGamma == 0) {
         throw new WindowNotFoundException("No such window");
      }

      if (hWndFrameStatic == 0) {
         hWndFrameStatic = this.hWndFrame;
      }

      hInstGamma = this.install(var5);
      this.maybeResize(var3.width, var3.height);
      if (var5) {
         activeWindow = this;
      }
   }

   public void hookChatLine(Component var1) throws WindowNotFoundException {
      Debug.assert_(activeWindow == this);
      Dimension var2 = var1.size();

      try {
         Point var3 = var1.getLocationOnScreen();
         int var4 = findChildWindow(hWndFrameStatic, var3.x, var3.y, var2.width, var2.height);
         if (var4 != 0) {
            setChatLine(var4);
            return;
         }
      } catch (Exception var5) {
      }

      throw new WindowNotFoundException();
   }

   private static native void setChatLine(int var0);

   public static native int getVoiceChatWParam();

   public static native int getVoiceChatLParam();

   public static native void resetVoiceChatMsg();

   public static native void doMicrosoftVMHacks();

   public static native boolean usingMicrosoftVMHacks();

   public static native boolean getActivated();

   public static native boolean isActivated();

   public static native int getGammaProcessID();

   public native void dispose();

   public static Window getMainWindow() {
      return activeWindow;
   }

   public native int getHwnd();

   public void hideNativeWindow() {
      if (this.hWndGamma != 0) {
         this.nativeHideChildWindow(this.hWndGamma);
      }
   }

   public void showNativeWindow() {
      if (this.hWndGamma != 0) {
         this.nativeShowChildWindow(this.hWndGamma);
      }
   }

   native void nativeHideChildWindow(int var1);

   native void nativeShowChildWindow(int var1);

   public static int getHWnd() {
      return activeWindow == null ? 0 : activeWindow.hWndGamma;
   }

   public static int getHInst() {
      return hInstGamma;
   }

   public native void maybeResize(int var1, int var2);

   public native void setDeltaMode(boolean var1);

   public static native int getAndResetUserActionCount();

   public native boolean getDeltaMode();

   public static native void makeJavaReleaseCapture();

   public native void reShape(int var1, int var2, int var3, int var4);

   public native int fullWidth();

   public native int fullHeight();

   public static native int findWindow(String var0);

   public static native int getFrameWindow();

   public static native void hideCursor();

   public static native int[] getHiddenCursorDelta();

   public static native void setCursor(int var0);

   public static native int getWindowState(int var0);

   public static native void setWindowState(int var0, int var1);

   public static native void setForegroundWindow(int var0);

   public static native void setVideoMode(int var0, int var1, int var2);

   public static native void nativeInit();

   private native int install(boolean var1);

   static synchronized int findChildWindow(int var0, int var1, int var2, int var3, int var4) {
      return nativeFindChildWindow(var0, var1, var2, var3, var4);
   }

   static synchronized int findOrMakeChildWindow(int var0, int var1, int var2, int var3, int var4) {
      return nativeFindOrMakeChildWindow(var0, var1, var2, var3, var4);
   }

   public static boolean isLastLineVisible(int var0, TextArea var1) {
      Dimension var2 = var1.size();
      return nativeIsLastLineVisible(var0, var2.width, var2.height) != 0;
   }

   private static native int nativeIsLastLineVisible(int var0, int var1, int var2);

   private static native int nativeFindChildWindow(int var0, int var1, int var2, int var3, int var4);

   private static native int nativeFindOrMakeChildWindow(int var0, int var1, int var2, int var3, int var4);

   public static int playVideoClip(Component var0, String var1) {
      Point var2 = var0.getLocationOnScreen();
      Dimension var3 = var0.size();
      return playVideoClip(var1, findChildWindow(activeWindow.hWndFrame, var2.x, var2.y, var3.width, var3.height));
   }

   public static native boolean isVideoPlaying(int var0);

   private static native int playVideoClip(String var0, int var1);

   public static native void hookWinAPIs(String var0);

   public static native int getWindowWidth(int var0);

   public static native int getWindowHeight(int var0);

   public static native void allowFGJavaPalette(boolean var0);

   public static int getFrameHandle() {
      return hWndFrameStatic;
   }

   public static native int getSystemMetrics(int var0);
}

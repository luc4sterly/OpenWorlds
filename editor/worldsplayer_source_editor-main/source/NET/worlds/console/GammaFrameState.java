package NET.worlds.console;

import NET.worlds.core.IniFile;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.Toolkit;
import java.util.StringTokenizer;

public class GammaFrameState implements MainCallback {
   private static final int defaultWidth = 568;
   private static final int defaultHeight = 424;
   private static final int minimumWidth = 142;
   private static final int minimumHeight = 106;
   private static int[] frameState = new int[5];
   private static GammaFrame frame;
   private static int handle;
   private static String borderKey;
   private static final String layoutKey = "ShaperLayout";
   private static final String modeKey = "ChangeVideoMode";
   private static final float scale = 100.0F;
   private boolean initMaximized;
   private int[] videoMode;

   GammaFrameState(GammaFrame var1) {
      frame = var1;
      if (borderKey == null) {
         borderKey = Gamma.shaperEnabled() ? "ShaperWindow" : "Window";
      }

      this.restoreBorder();
      int[] var2 = new int[2];
      if (strToInts(IniFile.gamma().getIniString("ChangeVideoMode", ""), var2) == 2) {
         this.videoMode = var2;
      }

      Main.register(this);
   }

   public static void saveBorder() {
      int var0;
      if (handle != 0 && !isIconic(var0 = getFrameState())) {
         Point var1 = frame.location();
         Dimension var2 = new Dimension(Window.getWindowWidth(handle), Window.getWindowHeight(handle));
         int[] var3 = new int[frameState.length];
         if (!isMaximized(var3[4] = var0)) {
            var3[0] = var1.x;
            var3[1] = var1.y;
            var3[2] = var2.width;
            var3[3] = var2.height;
         } else {
            for (int var4 = 0; var4 < 4; var4++) {
               var3[var4] = frameState[var4];
            }
         }

         for (int var5 = 0; var5 < frameState.length; var5++) {
            if (var3[var5] != frameState[var5]) {
               IniFile var10000 = IniFile.gamma();
               String var10001 = makeKey(borderKey);
               frameState = var3;
               var10000.setIniString(var10001, intsToStr(var3));
               break;
            }
         }
      }
   }

   private void restoreBorder() {
      if (strToInts(IniFile.gamma().getIniString(makeKey(borderKey), ""), frameState) == 5) {
         if (frameState[0] >= 0 && frameState[2] >= 142 && frameState[1] >= 0 && frameState[3] >= 106) {
            if (isMaximized(frameState[4])) {
               this.initMaximized = true;
            } else {
               frameState[4] = 0;
               this.initMaximized = false;
            }

            frame.reshape(frameState[0], frameState[1], frameState[2], frameState[3]);
         } else {
            this.makeDefaultBorder();
         }
      } else {
         this.makeDefaultBorder();
      }
   }

   private void makeDefaultBorder() {
      Dimension var1 = getScreenSize();
      int var2 = var1.width - 568;
      int var3 = var1.height - 424;
      if (var2 <= 0) {
         var2 = 0;
      } else {
         var2 /= 2;
      }

      if (var3 <= 0) {
         var3 = 0;
      } else {
         var3 /= 2;
      }

      frameState[0] = var2;
      frameState[1] = var3;
      frameState[2] = 568;
      frameState[3] = 424;
      frameState[4] = 0;
      this.initMaximized = false;
      frame.reshape(var2, var3, 568, 424);
   }

   public static void saveLayout(int[] var0, float[] var1, boolean var2) {
      IniFile.gamma().setIniString(makeKey("ShaperLayout"), intsToStr(var0) + " " + floatsToStr(var1) + " " + (var2 ? "0" : "1"));
   }

   public static boolean restoreLayout(int[] var0, float[] var1) {
      int[] var2 = new int[var0.length];
      float[] var3 = new float[var1.length];
      int[] var4 = new int[var2.length + var3.length + 1];
      var4[var2.length + var3.length] = 0;
      if (strToInts(IniFile.gamma().getIniString(makeKey("ShaperLayout"), ""), var4) < var2.length + var3.length) {
         return true;
      }

      int[] var5 = new int[var2.length];

      for (int var6 = 0; var6 < var2.length; var6++) {
         try {
            var5[var2[var6] = var4[var6]]++;
         } catch (ArrayIndexOutOfBoundsException var8) {
            return true;
         }
      }

      for (int var9 = 0; var9 < var2.length; var9++) {
         if (var5[var9] != 1) {
            return true;
         }
      }

      for (int var10 = 0; var10 < var3.length; var10++) {
         float var7 = var4[var10 + var2.length] / 100.0F;
         if (var7 < 0.0F || var7 > 1.0F) {
            return true;
         }

         var3[var10] = var7;
      }

      System.arraycopy(var2, 0, var0, 0, var0.length);
      System.arraycopy(var3, 0, var1, 0, var1.length);
      return var4[var2.length + var3.length] == 0;
   }

   private static int getFrameState() {
      return Window.getWindowState(handle);
   }

   public static boolean isIconic() {
      return handle != 0 ? isIconic(getFrameState()) : false;
   }

   private static boolean isIconic(int var0) {
      return var0 == 1;
   }

   private static boolean isMaximized(int var0) {
      return var0 == 2;
   }

   private static Dimension getScreenSize() {
      return Toolkit.getDefaultToolkit().getScreenSize();
   }

   private static String makeKey(String var0) {
      Dimension var1 = getScreenSize();
      return var0 + var1.width + "X" + var1.height;
   }

   private static String intsToStr(int[] var0) {
      String var1 = "" + var0[0];

      for (int var2 = 1; var2 < var0.length; var2++) {
         var1 = var1 + " " + var0[var2];
      }

      return var1;
   }

   private static String floatsToStr(float[] var0) {
      int[] var1 = new int[var0.length];

      for (int var2 = 0; var2 < var0.length; var2++) {
         var1[var2] = (int)(var0[var2] * 100.0F);
      }

      return intsToStr(var1);
   }

   private static int strToInts(String var0, int[] var1) {
      if (var0 == null) {
         return 0;
      }

      StringTokenizer var2 = new StringTokenizer(var0, " ");

      int var3;
      for (var3 = 0; var3 < var1.length && var2.hasMoreTokens(); var3++) {
         try {
            var1[var3] = Integer.parseInt(var2.nextToken());
         } catch (NumberFormatException var5) {
            break;
         }
      }

      return var3;
   }

   public void mainCallback() {
      handle = Window.findWindow(frame.getTitle());
      if (handle != 0) {
         if (this.videoMode != null) {
            Window.setVideoMode(handle, this.videoMode[0], this.videoMode[1]);
         } else if (this.initMaximized) {
            Window.setWindowState(handle, 2);
         }

         Main.unregister(this);
      }
   }
}

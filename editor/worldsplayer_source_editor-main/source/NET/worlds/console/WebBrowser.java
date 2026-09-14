package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.Rectangle;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Stack;

public class WebBrowser {
   private static Stack browsers = new Stack();
   private static boolean disabled = IniFile.gamma().getIniInt("DISABLEIE", 0) != 0;
   private static boolean everWorked;
   private int nativeBrowserPointer;
   private InternetExplorer _activeX;
   private static boolean toolbarON = true;
   private static boolean windowFrameON = true;
   private static boolean _stayMinimized = false;
   private String browserTag = null;

   public static WebBrowser reuseOrMake(String var0, String var1) throws IOException {
      return reuseOrMake(var0, var1, defaultPlacement());
   }

   public static void useToolbar() {
      toolbarON = true;
   }

   public static void dontUseToolbar() {
      toolbarON = false;
   }

   public static void useWindowFrame() {
      windowFrameON = true;
   }

   public static void dontUseWindowFrame() {
      windowFrameON = false;
   }

   public static void forceMinimized(boolean var0) {
      _stayMinimized = var0;
   }

   public static WebBrowser findTag(String var0) {
      Enumeration var1 = browsers.elements();

      while (var1.hasMoreElements()) {
         WebBrowser var2 = (WebBrowser)var1.nextElement();
         if (var0 != null) {
            if (var0.equals(var2.getTag())) {
               return var2;
            }
         } else if (var2.getTag() == null) {
            return var2;
         }
      }

      return null;
   }

   public static WebBrowser reuseOrMake(String var0, String var1, Rectangle var2) throws IOException {
      Enumeration var3 = browsers.elements();

      while (var3.hasMoreElements()) {
         WebBrowser var4 = (WebBrowser)var3.nextElement();
         if (var4.getTag() == null) {
            try {
               var4.browse(var0, var1, null);
               return var4;
            } catch (IOException var6) {
            }
         }
      }

      return new WebBrowser(var0, var1, var2);
   }

   private String getTag() {
      return this.browserTag;
   }

   public static WebBrowser reuseOrMake(String var0, String var1, Rectangle var2, String var3) throws IOException {
      Enumeration var4 = browsers.elements();

      while (var4.hasMoreElements()) {
         WebBrowser var5 = (WebBrowser)var4.nextElement();
         if (var3.equals(var5.getTag())) {
            try {
               var5.browse(var0, var1, null);
               return var5;
            } catch (IOException var7) {
            }
         }
      }

      return new WebBrowser(var0, var1, var2, var3);
   }

   public static Rectangle defaultPlacement() {
      Console var0 = Console.getActive();
      return var0 instanceof DefaultConsole ? ((DefaultConsole)var0).getBrowserPlacement() : new Rectangle(0, 0, 200, 200);
   }

   public static boolean isDisabled() {
      return disabled;
   }

   public static void setDisabled(boolean var0) {
      IniFile.gamma().setIniInt("DISABLEIE", var0 ? 1 : 0);
      disabled = var0;
   }

   public WebBrowser(String var1, String var2) throws IOException {
      this(var1, var2, defaultPlacement());
   }

   public WebBrowser(String var1, String var2, Rectangle var3) throws IOException {
      this(var1, var2, var3, null);
   }

   public WebBrowser(String var1, String var2, Rectangle var3, String var4) throws IOException {
      if (!disabled) {
         this._activeX = new InternetExplorer(this);

         try {
            this.nativeBrowserPointer = openBrowser();
         } catch (IOException var8) {
            try {
               this._activeX.Release();
            } catch (OLEInvalidObjectException var7) {
               Debug.dAssert(false);
            }

            this._activeX = null;
            disabled = true;
            throw var8;
         }

         browsers.push(this);
         if (var4 != null) {
            this.browserTag = var4;
         }

         try {
            this.browse(var1, var2, var3);
            everWorked = true;
         } catch (IOException var9) {
            if (!everWorked) {
               disabled = true;
            }

            throw var9;
         }
      } else {
         throw new IOException();
      }
   }

   public void browse(String var1, String var2, Rectangle var3) throws IOException {
      if (this.nativeBrowserPointer != 0) {
         int var4 = -1;
         int var5 = -1;
         int var6 = -1;
         int var7 = -1;
         if (var3 != null) {
            var4 = var3.x;
            var5 = var3.y;
            var6 = var3.width;
            var7 = var3.height;
         }

         try {
            browse(var1, var2, var4, var5, var6, var7, this.nativeBrowserPointer);
         } catch (IOException var9) {
            this.close();
            throw var9;
         }
      } else {
         throw new IOException();
      }
   }

   public void close() {
      if (this.nativeBrowserPointer != 0) {
         closeBrowser(this.nativeBrowserPointer);
         this.nativeBrowserPointer = 0;

         try {
            this._activeX.Release();
         } catch (OLEInvalidObjectException var2) {
            Debug.dAssert(false);
         }

         this._activeX = null;
         browsers.removeElement(this);
      }
   }

   private static native void browse(String var0, String var1, int var2, int var3, int var4, int var5, int var6) throws IOException;

   private static native int openBrowser() throws IOException;

   private static native void closeBrowser(int var0);

   public static Rectangle getMapPartPlacement() {
      Rectangle var0 = null;
      Console var1 = Console.getActive();
      if (var1 != null) {
         MapPart var2 = null;
         Enumeration var3 = var1.getParts();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof MapPart) {
               var2 = (MapPart)var4;
               break;
            }
         }

         if (var2 != null) {
            var0 = new Rectangle(var2.getLocationOnScreen(), var2.getSize());
            var0.grow(0, 10);
            var0.translate(0, -9);
         }
      }

      return var0;
   }

   public static Rectangle getAdPartPlacement() {
      Rectangle var0 = null;
      Console var1 = Console.getActive();
      if (var1 != null) {
         AdPart var2 = null;
         Enumeration var3 = var1.getParts();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof AdPart) {
               var2 = (AdPart)var4;
               break;
            }
         }

         if (var2 != null) {
            var0 = new Rectangle(var2.getLocationOnScreen(), var2.getSize());
            var0.grow(0, 10);
            var0.translate(0, -9);
         }
      }

      return var0;
   }

   public static Rectangle getRenderPartPlacement() {
      Rectangle var0 = null;
      Console var1 = Console.getActive();
      if (var1 != null) {
         RenderCanvas var2 = null;
         Enumeration var3 = var1.getParts();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof RenderCanvas) {
               var2 = (RenderCanvas)var4;
               break;
            }
         }

         if (var2 != null) {
            var0 = new Rectangle(var2.getLocationOnScreen(), var2.getSize());
            var0.grow(2, 10);
            var0.translate(-1, 7);
         }
      }

      return var0;
   }

   public static Rectangle getLeftRenderPartPlacement() {
      Rectangle var0 = null;
      Console var1 = Console.getActive();
      if (var1 != null) {
         RenderCanvas var2 = null;
         Enumeration var3 = var1.getParts();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof RenderCanvas) {
               var2 = (RenderCanvas)var4;
               break;
            }
         }

         if (var2 != null) {
            var0 = new Rectangle(var2.getLocationOnScreen(), var2.getSize());
            var0.grow(2, 10);
            var0.translate(-1, 7);
            Dimension var5 = var0.getSize();
            var0.setSize(var5.width / 2, var5.height);
         }
      }

      return var0;
   }

   public static Rectangle getOutsidePlacement() {
      Rectangle var0 = null;
      Console var1 = Console.getActive();
      if (var1 != null) {
         RenderCanvas var2 = null;
         Enumeration var3 = var1.getParts();

         while (var3.hasMoreElements()) {
            Object var4 = var3.nextElement();
            if (var4 instanceof RenderCanvas) {
               var2 = (RenderCanvas)var4;
               break;
            }
         }

         if (var2 != null) {
            Point var6 = var2.getLocationOnScreen();
            Dimension var7 = new Dimension(250, 500);
            Point var5 = new Point(0, var6.y);
            if (var6.x > 254) {
               var5.x = var6.x - 254;
            } else {
               var5.x = 0;
            }

            var0 = new Rectangle(var5, var7);
         }
      }

      return var0;
   }
}

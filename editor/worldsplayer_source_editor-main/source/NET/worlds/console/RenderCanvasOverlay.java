package NET.worlds.console;

import NET.worlds.core.Debug;

public abstract class RenderCanvasOverlay {
   private RenderCanvas canvas;
   private int xPercent;
   private int yPercent;
   private int xFixed;
   private int yFixed;
   private boolean isFixed;
   private boolean fullscreen;
   private int hwnd;
   private boolean allowFocus;

   public RenderCanvasOverlay(RenderCanvas var1, int var2, int var3, boolean var4, boolean var5) throws NoWebControlException {
      Debug.assert_(var2 > 0 || var3 > 0);
      if (var1 != null && var1.getWindow() != null) {
         this.canvas = var1;
         this.isFixed = var4;
         this.allowFocus = var5;
         if (this.isFixed) {
            this.xFixed = var2;
            this.yFixed = var3;
            this.xPercent = this.yPercent = 1;
         } else {
            this.xPercent = var2;
            this.yPercent = var3;
         }

         this.fullscreen = false;
      } else {
         throw new NoWebControlException("RenderCanvas does not exist");
      }
   }

   public RenderCanvasOverlay(RenderCanvas var1) {
      Debug.assert_(var1 != null);
      this.canvas = var1;
      this.xPercent = this.yPercent = 100;
      this.isFixed = false;
      this.allowFocus = true;
      this.fullscreen = true;
      this.hwnd = this.canvas.getWindow().getHwnd();
   }

   public void activate() {
      this.canvas.addOverlay(this);
   }

   int getNativeWindowHandle() {
      Debug.assert_(this.canvas.getWindow() != null);
      if (this.hwnd == 0) {
         if (this.fullscreen) {
            this.hwnd = this.canvas.getWindow().getHwnd();
         } else {
            this.hwnd = this.nativeMakeChild(this.canvas.getWindow().getHwnd(), this.xPercent, this.yPercent, this.allowFocus);
         }
      }

      return this.hwnd;
   }

   int getXPercent() {
      return this.xPercent;
   }

   int getYPercent() {
      return this.yPercent;
   }

   int getFixedWidth() {
      return this.xFixed;
   }

   int getFixedHeight() {
      return this.yFixed;
   }

   boolean getIsFixedSize() {
      return this.isFixed;
   }

   void canvasResized(int var1, int var2) {
      int var3;
      int var4;
      if (this.isFixed) {
         var3 = this.xFixed;
         var4 = this.yFixed;
         if (var3 > var1) {
            var3 = var1;
         }

         if (var4 > var2) {
            var4 = var2;
         }

         this.xPercent = (int)Math.ceil((double)var3 / var1 * 100.0);
         this.yPercent = (int)Math.ceil((double)var4 / var2 * 100.0);
      } else {
         var3 = (int)(var1 * this.xPercent * 0.01);
         var4 = (int)(var2 * this.yPercent * 0.01);
      }

      if (this.hwnd != 0) {
         this.nativeResizeChild(this.hwnd, var3, var4);
      }
   }

   boolean isFullscreen() {
      return this.fullscreen || !this.isFixed && this.xPercent == 100 && this.yPercent == 100;
   }

   protected abstract void handleCommand(int var1);

   void detach() {
      this.canvas.removeOverlay(this);
      if (!this.fullscreen && this.hwnd != 0) {
         this.nativeKillChild(this.hwnd);
      }
   }

   private native int nativeMakeChild(long var1, int var3, int var4, boolean var5);

   private native void nativeKillChild(long var1);

   private native void nativeResizeChild(int var1, int var2, int var3);
}

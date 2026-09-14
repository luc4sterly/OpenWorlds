package NET.worlds.scape;

public class DirectShow implements TextureSurfaceRenderer {
   static final int nUnitialized = 0;
   static final int nStopped = 1;
   static final int nPaused = 2;
   static final int nPlaying = 3;
   private int mediaRendererInstancePtr;
   private int m_hwnd;

   public DirectShow() {
      nativeInit();
      this.nInit(0);
   }

   public DirectShow(int var1) {
      this.m_hwnd = var1;
      nativeInit();
      this.nInit(var1);
   }

   public void finalize() {
      this.nTick();
      this.nStop();
      this.nShutdown();
   }

   public void renderTo(int var1) {
      this.nRenderTo(this.m_hwnd, var1);
   }

   public static native void nativeInit();

   protected native void nInit(int var1);

   protected native void nShutdown();

   public native void nOpen(String var1);

   public native void nPlay(int var1);

   public native void nStop();

   public native void nPause();

   public native void nRenderTo(int var1, int var2);

   public native int nTick();
}

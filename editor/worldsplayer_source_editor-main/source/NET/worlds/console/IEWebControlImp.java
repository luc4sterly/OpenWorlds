package NET.worlds.console;

class IEWebControlImp extends WebControlImp {
   private int nativeIEInstance;
   private int m_hwnd;
   private boolean detached;

   private native boolean nativeInit(int var1, boolean var2);

   private native void nativeDestroy();

   private native void nativeSetURL(String var1, String var2);

   private native void nativeGoBack();

   private native void nativeGoForward();

   private native void nativeStop();

   private native void nativeRefresh();

   private native void nativeHome();

   private native void nativePrint(int var1, int var2);

   private native void nativeResize(int var1, int var2, int var3, int var4);

   private native void nativeAddToolbar();

   private native int nativeGetHWND();

   public IEWebControlImp(int var1, boolean var2, boolean var3) throws NoWebControlException {
      super(var1);
      this.m_hwnd = var1;
      this.nativeIEInstance = 0;
      this.detached = false;
      if (!this.nativeInit(var1, var3)) {
         this.detached = true;
         throw new NoWebControlException("Could not initialize IE control");
      }

      if (var2) {
         this.nativeAddToolbar();
      }
   }

   public void finalize() {
      this.detach();
   }

   public void renderTo(int var1) {
      this.nativePrint(var1, this.m_hwnd);
   }

   public boolean setURL(String var1) {
      var1 = processURL(var1);
      if (var1 == null) {
         return false;
      }

      this.nativeSetURL(var1, null);
      return true;
   }

   public boolean setURL(String var1, String var2) {
      var1 = processURL(var1);
      if (var1 == null) {
         return false;
      }

      if (var2 != null) {
         var2 = processURL(var2);
         if (var2 == null) {
            return false;
         }
      }

      this.nativeSetURL(var1, var2);
      return true;
   }

   public void detach() {
      if (!this.detached) {
         this.nativeDestroy();
         super.detach();
         this.nativeIEInstance = 0;
         this.detached = true;
      }
   }

   public void resize(int var1, int var2, int var3, int var4) {
      this.nativeResize(var1, var2, var3, var4);
   }

   public void goBack() {
      this.nativeGoBack();
   }

   public void goForward() {
      this.nativeGoForward();
   }

   public void stop() {
      this.nativeStop();
   }

   public void refresh() {
      this.nativeRefresh();
   }

   public void home() {
      this.nativeHome();
   }

   public int getHWND() {
      return this.nativeGetHWND();
   }
}

package NET.worlds.console;

public class WebControl extends RenderCanvasOverlay {
   private final int ID_GO_BACK = 32768;
   private final int ID_GO_FORWARD = 32769;
   private final int ID_VIEW_STOP = 32770;
   private final int ID_VIEW_REFRESH = 32771;
   private final int ID_GO_HOME = 32772;
   private final int ID_EXIT = 32773;
   private WebControlImp imp = null;

   public WebControl(RenderCanvas var1, boolean var2) throws NoWebControlException {
      super(var1);

      try {
         this.imp = WebControlFactory.createWebControlImp(this.getNativeWindowHandle(), var2, false);
      } catch (NoWebControlException var4) {
         super.detach();
         throw var4;
      }
   }

   public WebControl(RenderCanvas var1, int var2, int var3, boolean var4, boolean var5, boolean var6) throws NoWebControlException {
      super(var1, var2, var3, var5, !var6);
      this.imp = WebControlFactory.createWebControlImp(this.getNativeWindowHandle(), var4, var6);
   }

   public boolean setURL(String var1) {
      if (this.imp == null) {
         System.out.println("Null implementation in WebControl.setURL");
         return false;
      } else {
         return this.imp.setURL(var1);
      }
   }

   public boolean setURL(String var1, String var2) {
      if (this.imp == null) {
         System.out.println("Null implementation in WebControl.setURL");
         return false;
      } else {
         return var2 != null && !var2.equals("") ? this.imp.setURL(var1, var2) : this.imp.setURL(var1);
      }
   }

   protected void handleCommand(int var1) {
      if (this.imp == null) {
         System.out.println("Now this should be impossible. Null imp in WebControl.handleCommand.");
      } else {
         switch (var1) {
            case 32768:
               this.imp.goBack();
               break;
            case 32769:
               this.imp.goForward();
               break;
            case 32770:
               this.imp.stop();
               break;
            case 32771:
               this.imp.refresh();
               break;
            case 32772:
               this.imp.home();
               break;
            case 32773:
               this.detach();
         }
      }
   }

   void detach() {
      if (this.imp != null) {
         this.imp.detach();
      }

      super.detach();
   }

   void canvasResized(int var1, int var2) {
      super.canvasResized(var1, var2);
      if (this.imp == null) {
         System.out.println("Null imp in WebControl.canvasResized");
      } else {
         this.imp.resize(var1, var2, this.getXPercent(), this.getYPercent());
      }
   }
}

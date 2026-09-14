package NET.worlds.scape;

import java.io.IOException;

public class WebWallControlAction extends Action {
   private final int reload = 1;
   private final int setURL = 2;
   private final int refresh = 3;
   private final int back = 4;
   private final int forward = 5;
   private final int stop = 6;
   private final int home = 7;
   private int mode = 1;
   private String url;
   private String postData;
   private WebPageWall webWall = null;
   private static Object classCookie = new Object();

   WebWallControlAction() {
      this.postData = null;
      this.url = "http://www.worlds.com/";
   }

   public Persister trigger(Event var1, Persister var2) {
      if (!this.getWebWall()) {
         System.out.println("ERROR! Tried to attach WebWallControlAction to something other than a WebWall object.");
         return null;
      }

      switch (this.mode) {
         case 1:
            this.webWall.rebuild();
            break;
         case 2:
            this.webWall.getWebControlImp().setURL(this.url, this.postData);
            break;
         case 3:
            this.webWall.getWebControlImp().refresh();
            break;
         case 4:
            this.webWall.getWebControlImp().goBack();
            break;
         case 5:
            this.webWall.getWebControlImp().goForward();
            break;
         case 6:
            this.webWall.getWebControlImp().stop();
            break;
         case 7:
            this.webWall.getWebControlImp().home();
      }

      return null;
   }

   private boolean getWebWall() {
      if (this.webWall != null) {
         return true;
      } else {
         SuperRoot var1 = this.getOwner();
         if (var1 != null && var1 instanceof WebPageWall) {
            this.webWall = (WebPageWall)var1;
            return this.webWall == null ? false : this.webWall.getWebControlImp() != null;
         } else {
            return false;
         }
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveInt(this.mode);
      var1.saveString(this.url);
      var1.saveString(this.postData);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.mode = var1.restoreInt();
            this.url = var1.restoreString();
            this.postData = var1.restoreString();
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "1=Reload, 2=SetURL, 3=Refresh, 4=Back, 5=Fwd, 6=Stop, 7=Home"));
            } else if (var3 == 1) {
               var5 = new Integer(this.mode);
            } else if (var3 == 2) {
               this.mode = (Integer)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "URL for mode 2"));
            } else if (var3 == 1) {
               var5 = this.url;
            } else if (var3 == 2) {
               this.url = ((String)var4).trim();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "POST data for mode 2"));
            } else if (var3 == 1) {
               var5 = this.postData;
            } else if (var3 == 2) {
               this.postData = ((String)var4).trim();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }
}

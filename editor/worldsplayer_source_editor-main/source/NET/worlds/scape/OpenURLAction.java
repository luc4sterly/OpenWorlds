package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.NoWebControlException;
import NET.worlds.console.WebControl;
import java.io.IOException;

public class OpenURLAction extends Action {
   String targetURL = "http://www.worlds.com";
   int xPercent = 100;
   int yPercent = 100;
   boolean hasToolbar = true;
   boolean isFixed = false;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      if (var2 != null) {
         return var2;
      }

      Console var3 = Console.getActive();
      if (var3 != null && var3 instanceof DefaultConsole) {
         System.out.println("Opening up a URL now.");
         DefaultConsole var4 = (DefaultConsole)var3;

         try {
            WebControl var5 = new WebControl(var4.getRender(), this.xPercent, this.yPercent, this.hasToolbar, this.isFixed, false);
            var5.activate();
            var5.setURL(this.targetURL);
         } catch (NoWebControlException var6) {
         }

         new SuperRoot();
         return this;
      } else {
         return null;
      }
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Target URL"));
            } else if (var3 == 1) {
               var5 = this.targetURL;
            } else if (var3 == 2) {
               this.targetURL = (String)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "X Overlay % or Width"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this.xPercent);
            } else if (var3 == 2) {
               this.xPercent = (Integer)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Y Overlay % or Height"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this.yPercent);
            } else if (var3 == 2) {
               this.yPercent = (Integer)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Has Toolbar"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.hasToolbar);
            } else if (var3 == 2) {
               this.hasToolbar = (Boolean)var4;
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Fixed size"), "No - Percentage specified", "Yes - Pixels specified");
            } else if (var3 == 1) {
               var5 = new Boolean(this.isFixed);
            } else if (var3 == 2) {
               this.isFixed = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this.targetURL);
      var1.saveInt(this.xPercent);
      var1.saveInt(this.yPercent);
      var1.saveBoolean(this.hasToolbar);
      var1.saveBoolean(this.isFixed);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.targetURL = var1.restoreString();
            this.xPercent = var1.restoreInt();
            this.yPercent = var1.restoreInt();
            this.hasToolbar = var1.restoreBoolean();
            this.isFixed = var1.restoreBoolean();
            return;
         default:
            throw new TooNewException();
      }
   }
}

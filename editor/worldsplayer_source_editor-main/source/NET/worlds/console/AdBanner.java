package NET.worlds.console;

import NET.worlds.core.IniFile;

public class AdBanner {
   private WebControl wc = null;

   public AdBanner(int var1, int var2, String var3) {
      if (IniFile.gamma().getIniInt("NoAdBanners", 0) != 1) {
         Console var4 = Console.getActive();
         if (var4 != null && var4 instanceof DefaultConsole) {
            DefaultConsole var5 = (DefaultConsole)var4;

            try {
               RenderCanvas var6 = var5.getRender();
               if (var6 == null) {
                  return;
               }

               this.wc = new WebControl(var6, var1, var2, false, true, true);
               this.wc.activate();
               this.wc.setURL(var3);
            } catch (NoWebControlException var7) {
               System.out.println("Error creating IE control; " + var7.toString());
            }
         }
      }
   }

   public void detach() {
      if (this.wc != null) {
         this.wc.detach();
      }

      this.wc = null;
   }
}

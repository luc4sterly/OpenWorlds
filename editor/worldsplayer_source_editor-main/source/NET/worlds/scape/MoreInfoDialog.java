package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.ImageButtons;
import NET.worlds.console.ImageButtonsCallback;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.IniFile;
import java.awt.Component;
import java.awt.Rectangle;
import java.awt.Window;

public class MoreInfoDialog extends PolledDialog implements ImageButtonsCallback {
   private ImageButtons ib;

   public MoreInfoDialog(Window var1, DialogReceiver var2) {
      super(var1, var2, Console.message("BrowseQ"), false);
      this.setAlignment(1);
      Rectangle[] var3 = new Rectangle[2];
      int var4 = IniFile.override().getIniInt("moreinfoYesX", 48);
      int var5 = IniFile.override().getIniInt("moreinfoYesY", 22);
      int var6 = IniFile.override().getIniInt("moreinfoYesW", 60);
      int var7 = IniFile.override().getIniInt("moreinfoYesH", 19);
      var3[0] = new Rectangle(var4, var5, var6, var7);
      int var8 = IniFile.override().getIniInt("moreinfoNoX", 139);
      int var9 = IniFile.override().getIniInt("moreinfoNoY", 22);
      int var10 = IniFile.override().getIniInt("moreinfoNoW", 54);
      int var11 = IniFile.override().getIniInt("moreinfoNoH", 19);
      var3[1] = new Rectangle(var8, var9, var10, var11);
      String var12 = IniFile.override().getIniString("moreInfoDlg", Console.message("moreinfo.gif"));
      this.ib = new ImageButtons(var12, var3, this);
      this.ready();
   }

   protected void build() {
      this.add("Center", this.ib);
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      this.done(var2 == 0);
      return null;
   }

   public boolean keyDown(java.awt.Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else {
         return var2 == 10 ? this.done(true) : super.keyDown(var1, var2);
      }
   }
}

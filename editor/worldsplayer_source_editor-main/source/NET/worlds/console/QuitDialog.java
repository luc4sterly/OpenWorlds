package NET.worlds.console;

import NET.worlds.core.IniFile;
import java.awt.Component;
import java.awt.Event;
import java.awt.Rectangle;

public class QuitDialog extends PolledDialog implements ImageButtonsCallback {
   private ImageButtons ib;

   public QuitDialog(java.awt.Window var1, DialogReceiver var2) {
      super(var1, var2, Console.message("Quit"), true);
      Rectangle[] var3 = new Rectangle[2];
      int var4 = IniFile.override().getIniInt("quitYesX", 141);
      int var5 = IniFile.override().getIniInt("quitYesY", 76);
      int var6 = IniFile.override().getIniInt("quitYesW", 78);
      int var7 = IniFile.override().getIniInt("quitYesH", 22);
      var3[0] = new Rectangle(var4, var5, var6, var7);
      int var8 = IniFile.override().getIniInt("quitNoX", 141);
      int var9 = IniFile.override().getIniInt("quitNoY", 114);
      int var10 = IniFile.override().getIniInt("quitNoW", 78);
      int var11 = IniFile.override().getIniInt("quitNoH", 22);
      var3[1] = new Rectangle(var8, var9, var10, var11);
      String var12 = IniFile.override().getIniString("quitDlg", Console.message("DYRWTQ.GIF"));
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

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 27) {
         return this.done(false);
      } else {
         return var2 == 10 ? this.done(true) : super.keyDown(var1, var2);
      }
   }
}

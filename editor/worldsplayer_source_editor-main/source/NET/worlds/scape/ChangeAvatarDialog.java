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
import java.text.MessageFormat;

public class ChangeAvatarDialog extends PolledDialog implements ImageButtonsCallback {
   private ImageButtons ib;

   public ChangeAvatarDialog(Window var1, DialogReceiver var2, String var3) {
      super(var1, var2, Console.message("Change-Avatar"), false);
      this.setAlignment(1);
      Rectangle[] var4 = new Rectangle[2];
      int var5 = IniFile.override().getIniInt("changeavYesX", 39);
      int var6 = IniFile.override().getIniInt("changeavYesY", 23);
      int var7 = IniFile.override().getIniInt("changeavYesW", 48);
      int var8 = IniFile.override().getIniInt("changeavYesH", 18);
      var4[0] = new Rectangle(var5, var6, var7, var8);
      int var9 = IniFile.override().getIniInt("changeavNoX", 96);
      int var10 = IniFile.override().getIniInt("changeavNoY", 23);
      int var11 = IniFile.override().getIniInt("changeavNoW", 42);
      int var12 = IniFile.override().getIniInt("changeavnoH", 18);
      var4[1] = new Rectangle(var9, var10, var11, var12);
      Object[] var13 = new Object[]{new String(var3)};
      this.ib = new ChangeAvatarImageButtons(
         IniFile.override().getIniString("changeAvDlg", Console.message("changeav.gif")),
         var4,
         this,
         MessageFormat.format(Console.message("Change-avatar-to"), var13)
      );
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

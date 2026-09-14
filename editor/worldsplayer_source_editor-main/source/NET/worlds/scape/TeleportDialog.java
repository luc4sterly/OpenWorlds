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

public class TeleportDialog extends PolledDialog implements ImageButtonsCallback {
   private ImageButtons ib;

   public TeleportDialog(Window var1, DialogReceiver var2) {
      super(var1, var2, Console.message("Teleporting"), true);
      Rectangle[] var3 = new Rectangle[1];
      int var4 = IniFile.override().getIniInt("teleportCancelX", 61);
      int var5 = IniFile.override().getIniInt("teleportCancelY", 24);
      int var6 = IniFile.override().getIniInt("teleportCancelW", 84);
      int var7 = IniFile.override().getIniInt("teleportCancelH", 20);
      var3[0] = new Rectangle(var4, var5, var6, var7);
      String var8 = IniFile.override().getIniString("teleportDlg", Console.message("hangon.gif"));
      this.ib = new ImageButtons(var8, var3, this);
      this.ready();
   }

   protected void build() {
      this.add("Center", this.ib);
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      this.done(false);
      return null;
   }

   public boolean keyDown(java.awt.Event var1, int var2) {
      return var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }
}

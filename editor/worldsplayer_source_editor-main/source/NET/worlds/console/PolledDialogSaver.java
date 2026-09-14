package NET.worlds.console;

import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.Point;

class PolledDialogSaver {
   int x;
   int y;
   int w;
   int h;

   PolledDialogSaver(Dialog var1) {
      Point var2 = var1.location();
      Dimension var3 = var1.size();
      this.x = var2.x;
      this.y = var2.y;
      this.w = var3.width;
      this.h = var3.height;
   }

   static boolean restorePosAndSize(Object var0, PolledDialog var1) {
      if (var0 != null) {
         PolledDialogSaver var2 = (PolledDialogSaver)var0;
         var1.reshape(var2.x, var2.y, var2.w, var2.h);
         return true;
      } else {
         return false;
      }
   }
}

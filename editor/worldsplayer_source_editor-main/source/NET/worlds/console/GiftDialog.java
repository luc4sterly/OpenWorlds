package NET.worlds.console;

import NET.worlds.core.Std;
import NET.worlds.scape.InventoryManager;
import java.text.MessageFormat;
import java.util.Hashtable;

class GiftDialog extends OkCancelDialog {
   private String inv;
   private String msg;
   private int autoCloseTime;

   public static String calcMsg(String var0, int var1) {
      InventoryManager var2 = InventoryManager.getInventoryManager();
      Hashtable var3 = var2.parseInventoryString(var0);
      String var4 = TradeDialog.buildInvDesc(var3);
      Object[] var5 = new Object[]{new String(var4), new String("" + var1 / 1000)};
      return MessageFormat.format(Console.message("To-claim-hr"), var5);
   }

   public GiftDialog(String var1, int var2) {
      super(Console.getFrame(), null, Console.message("A-Gift"), null, "Accept", calcMsg(var1, var2), false);
      this.autoCloseTime = Std.getFastTime() + var2;
      this.inv = var1;
   }

   protected void activeCallback() {
      super.activeCallback();
      if (Std.getFastTime() > this.autoCloseTime && this.autoCloseTime != 0) {
         this.done(false);
      }
   }

   protected synchronized boolean done(boolean var1) {
      WhisperManager.whisperManager().giftDialogDone();
      if (var1) {
         TradeDialog.sendTradeMessage("&|+deal>TRADE ," + this.inv);
      }

      return super.done(var1);
   }
}

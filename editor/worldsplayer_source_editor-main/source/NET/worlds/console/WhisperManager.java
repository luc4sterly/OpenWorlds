package NET.worlds.console;

import NET.worlds.network.NetUpdate;
import NET.worlds.scape.InventoryManager;
import java.util.Enumeration;
import java.util.Hashtable;

public class WhisperManager {
   private static WhisperManager manager_;
   private Hashtable dialogs_;
   private Hashtable tradeDialogs_;
   private java.awt.Window parent;
   private String inventory = "";
   final String tradeServerName = "TRADE";
   static GiftDialog outstandingGift;

   private WhisperManager() {
      this.dialogs_ = new Hashtable();
      this.tradeDialogs_ = new Hashtable();
   }

   public static WhisperManager whisperManager() {
      if (manager_ == null) {
         manager_ = new WhisperManager();
      }

      return manager_;
   }

   void setParent(java.awt.Window var1) {
      this.parent = var1;
   }

   public Hashtable dialogs() {
      return this.dialogs_;
   }

   public Hashtable tradeDialogs() {
      return this.tradeDialogs_;
   }

   private WhisperDialog findWhisperDialog(String var1) {
      return !this.dialogs_.containsKey(var1) ? null : (WhisperDialog)this.dialogs_.get(var1);
   }

   private TradeDialog findTradeDialog(String var1) {
      return !this.tradeDialogs_.containsKey(var1) ? null : (TradeDialog)this.tradeDialogs_.get(var1);
   }

   private WhisperDialog start(String var1, boolean var2) {
      WhisperDialog var3 = this.findWhisperDialog(var1);
      if (var3 == null) {
         this.dialogs_.put(var1, var3 = new WhisperDialog(this.parent, var1));
      }

      if (var2) {
         var3.takeFocus();
      }

      var3.ready();
      return var3;
   }

   public void remove(String var1) {
      this.dialogs_.remove(var1);
   }

   public void startTo(String var1) {
      WhisperDialog var2 = this.start(var1, true);
   }

   public TradeDialog startToTrade(String var1) {
      TradeDialog var2 = this.findTradeDialog(var1);
      if (var2 == null) {
         this.tradeDialogs_.put(var1, var2 = new TradeDialog(this.parent, var1));
      }

      var2.takeFocus();
      var2.ready();
      var2.setTrading(true);
      var2.whisperPart.println(Console.message("trade-start"));
      return var2;
   }

   public void printFrom(String var1, String var2) {
      if (!var2.startsWith("&|+")) {
         WhisperDialog var5 = this.findWhisperDialog(var1);
         if (var2.equals("&|+trade>cancel") && (var5 == null || !var5.isActive() || !var5.isTrading)) {
            return;
         }

         var5 = this.start(var1, false);
         var5.print(var2);
      } else if (var2.startsWith("&|+gift>") && var1.equalsIgnoreCase("TRADE")) {
         maybeQueryGift(var2.substring(8));
      } else if (var2.startsWith("&|+inv>") && var1.equalsIgnoreCase("TRADE")) {
         this.tradeMsg(var2.substring(7));
      } else if (var2.startsWith("&|+trade>")) {
         TradeDialog var3 = this.findTradeDialog(var1);
         if (var2.equals("&|+trade>cancel") && (var3 == null || !var3.isActive() || !var3.isTrading)) {
            return;
         }

         var3 = this.startToTrade(var1);
         var3.print(var2);
      }
   }

   public void tradeMsg(String var1) {
      if (!var1.equals(this.inventory)) {
         Enumeration var2 = this.tradeDialogs_.elements();

         while (var2.hasMoreElements()) {
            TradeDialog var3 = (TradeDialog)var2.nextElement();
            var3.doneDeal();
         }

         InventoryManager.getInventoryManager().setInventory(var1);
      }
   }

   public void printTo(String var1, String var2) {
      if (!var1.equals("world") && !var1.equals("TRADE")) {
         if (!var2.startsWith("&|+") || var2.startsWith("&|+trade>")) {
            WhisperDialog var3 = this.start(var1, false);
            var3.send(var2);
         }
      }
   }

   public void giftDialogDone() {
      outstandingGift = null;
   }

   public static void maybeQueryGift(String var0) {
      if (NetUpdate.isInternalVersion()) {
         Console var1 = Console.getActive();
         if (var1 != null && outstandingGift == null && !var1.isSleeping()) {
            outstandingGift = new GiftDialog(var0, 3000000);
         }
      }
   }
}

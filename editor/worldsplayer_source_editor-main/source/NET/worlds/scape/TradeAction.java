package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.console.PolledDialog;
import java.io.IOException;

public class TradeAction extends DialogAction {
   int userItems = 1;
   String userItem = "A";
   int serverItems = 1;
   String serverItem = "A";
   private static Object classCookie = new Object();

   public void doIt() {
      StringBuffer var1 = new StringBuffer();
      var1.append("&|+deal>TRADE ");
      if (this.userItems > 0) {
         var1.append(this.userItem);
         var1.append(this.userItems);
      }

      var1.append(",");
      if (this.serverItems > 0) {
         var1.append(this.serverItem);
         var1.append(this.serverItems);
      }

      String var2 = var1.toString();
      Main.register(new TradeAction$1(this, var2));
   }

   public PolledDialog getDialog() {
      return InventoryManager.getInventoryManager().checkInventoryFor(this.userItem) >= this.userItems
         ? new OkCancelDialog(
            Console.getFrame(),
            this,
            "Trade?",
            "No",
            "Yes",
            "Do you want to give "
               + InventoryManager.getInventoryManager().itemName(this.userItem, this.userItems)
               + " in return for "
               + InventoryManager.getInventoryManager().itemName(this.serverItem, this.serverItems)
               + "?",
            false
         )
         : new OkCancelDialog(
            Console.getFrame(),
            this,
            "Can't trade!",
            "Ok",
            null,
            "You need " + InventoryManager.getInventoryManager().itemName(this.userItem, this.userItems) + " in order to trade here.",
            false
         );
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "User Item Type"));
            } else if (var3 == 1) {
               var5 = this.userItem;
            } else if (var3 == 2) {
               this.userItem = ((String)var4).toString().trim();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Number of User Items"));
            } else if (var3 == 1) {
               var5 = new Integer(this.userItems);
            } else if (var3 == 2) {
               this.userItems = (Integer)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Merchant Item Type"));
            } else if (var3 == 1) {
               var5 = this.serverItem;
            } else if (var3 == 2) {
               this.serverItem = ((String)var4).toString().trim();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Number of Merchant Items"));
            } else if (var3 == 1) {
               var5 = new Integer(this.serverItems);
            } else if (var3 == 2) {
               this.serverItems = (Integer)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public String toString() {
      return super.toString()
         + "[give "
         + InventoryManager.getInventoryManager().itemName(this.userItem, this.userItems)
         + " for "
         + InventoryManager.getInventoryManager().itemName(this.serverItem, this.serverItems)
         + "]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this.userItem);
      var1.saveInt(this.userItems);
      var1.saveString(this.serverItem);
      var1.saveInt(this.serverItems);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            this.userItem = var1.restoreString();
            this.userItems = var1.restoreInt();
            this.serverItem = var1.restoreString();
            this.serverItems = var1.restoreInt();
            return;
         default:
            throw new TooNewException();
      }
   }
}

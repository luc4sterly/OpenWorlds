package NET.worlds.scape;

import NET.worlds.console.ActionsPart;
import NET.worlds.console.Console;
import NET.worlds.console.TradeDialog;
import NET.worlds.console.WhisperManager;
import NET.worlds.core.ServerTableManager;
import NET.worlds.network.URL;
import java.net.MalformedURLException;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class InventoryManager {
   private static InventoryManager manager_;
   private Hashtable masterList_;
   private Hashtable inventory_ = new Hashtable();
   private boolean initialized_;
   private Vector equipped_;

   public synchronized void setEquippedItems(Vector var1) {
      this.removeEquippedItems();
      this.equipped_ = var1;
      this.equipItems();
   }

   public synchronized Vector getEquippedItems() {
      return this.equipped_;
   }

   private synchronized void removeEquippedItems() {
      for (int var1 = 0; var1 < this.equipped_.size(); var1++) {
         EquippableItem var2 = (EquippableItem)this.equipped_.elementAt(var1);
         Shape var3 = var2.getOwnedShape();
         if (var3 != null) {
            var3.detach();
         }

         var2.setOwnedShape(null);
      }
   }

   private synchronized void equipItems() {
      System.out.println("Equipped Items Size: " + this.equipped_.size());

      for (int var1 = 0; var1 < this.equipped_.size(); var1++) {
         Shape var2 = new Shape();
         new String();
         EquippableItem var7 = (EquippableItem)this.equipped_.elementAt(var1);
         if (var7 != null) {
            try {
               var2.setURL(new URL(var7.getModelLocation()));
            } catch (MalformedURLException var12) {
               System.out.println("Badly formed URL for " + var7.getItemName());
               continue;
            }

            float var6 = var7.getScale();
            var2.scale(var6, var6, var6);
            var2.pitch(var7.getPitch());
            var2.roll(var7.getRoll());
            var2.yaw(var7.getYaw());
            var2.moveBy(var7.getXPos(), var7.getYPos(), var7.getZPos());
            int var4 = var7.getBodyLocation();
            DeepEnumeration var8 = new DeepEnumeration();
            Pilot.getActive().getChildren(var8);

            while (var8.hasMoreElements()) {
               Object var9 = var8.nextElement();
               if (var9 instanceof Shape) {
                  Shape var10 = (Shape)var9;
                  int var11 = var10.getBodPartNum();
                  if (var11 == var4) {
                     var10.add(var2);
                     var7.setOwnedShape(var2);
                     break;
                  }
               }
            }
         }
      }
   }

   public Vector getEquippableItems() {
      Vector var1 = new Vector();
      Enumeration var2 = this.inventory_.elements();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (var3 instanceof EquippableItem) {
            var1.addElement(var3);
         }
      }

      return var1;
   }

   public Vector getInventoryAvatars() {
      Vector var1 = new Vector();
      Enumeration var2 = this.inventory_.elements();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (var3 instanceof InventoryAvatar) {
            var1.addElement(var3);
         }
      }

      return var1;
   }

   public Hashtable getInventoryItems() {
      return this.inventory_;
   }

   public int checkInventoryFor(String var1) {
      InventoryItem var2 = (InventoryItem)this.inventory_.get(var1);
      return var2 != null ? var2.getItemQuantity() : 0;
   }

   public Vector getInventoryActionList() {
      Vector var1 = new Vector();
      Enumeration var2 = this.inventory_.elements();

      while (var2.hasMoreElements()) {
         Object var3 = var2.nextElement();
         if (var3 instanceof InventoryAction) {
            var1.addElement(var3);
         }
      }

      return var1;
   }

   public void doInventoryAction(String var1) {
      Vector var2 = this.getInventoryActionList();

      for (int var3 = 0; var3 < var2.size(); var3++) {
         InventoryAction var4 = (InventoryAction)var2.elementAt(var3);
         if (var4.getItemName().equalsIgnoreCase(var1)) {
            var4.doAction();
            String var5 = "&|+deal>trade " + var4.getItemId() + ",";
            TradeDialog.sendTradeMessage(var5);
         }
      }
   }

   public void setInventory(String var1) {
      this.initialized_ = true;
      Hashtable var2 = this.parseInventoryString(var1);
      this.inventory_ = var2;
      Enumeration var3 = WhisperManager.whisperManager().tradeDialogs().elements();

      while (var3.hasMoreElements()) {
         TradeDialog var4 = (TradeDialog)var3.nextElement();
         var4.setTrading(true);
      }

      if (Console.getActive() != null) {
         Console var5 = Console.getActive();
         var5.inventoryChanged();
         if (var5.targetValid != var5.isValidAv()) {
            var5.resetAvatar();
         }
      }

      ActionsPart.updateActionDialog();
   }

   public Hashtable parseInventoryString(String var1) {
      Hashtable var2 = new Hashtable();
      if (var1 == null) {
         return var2;
      }

      int var3 = var1.length();
      int var4 = 0;

      while (var4 < var3) {
         char var5 = var1.charAt(var4);
         if (var5 < 'A' || var5 > 'Z') {
            System.out.println("Bad inventory: " + var1);
            return var2;
         }

         int var6;
         for (var6 = 1; var4 + var6 < var3; var6++) {
            var5 = var1.charAt(var4 + var6);
            if (var5 < 'a' || var5 > 'z') {
               break;
            }
         }

         String var7 = var1.substring(var4, var4 + var6);
         int var8 = var4 + var6;
         int var9 = 0;

         while (true) {
            if (var9 + var8 < var3) {
               var5 = var1.charAt(var8 + var9);
               if (var5 >= '0' && var5 <= '9') {
                  var9++;
                  continue;
               }
            }

            int var10 = 1;
            if (var9 > 0) {
               var10 = Integer.parseInt(var1.substring(var8, var8 + var9));
            }

            InventoryItem var11 = (InventoryItem)this.masterList_.get(var7);
            if (var11 != null) {
               InventoryItem var12 = var11.cloneItem();
               var12.setQuantity(var10);
               var2.put(var7, var12);
            }

            var4 = var8 + var9;
            break;
         }
      }

      return var2;
   }

   public String properCase(String var1) {
      return var1.equals("") ? var1 : var1.substring(0, 1).toUpperCase() + var1.substring(1);
   }

   public String getSingular(String var1) {
      InventoryItem var2 = (InventoryItem)this.masterList_.get(var1);
      return var2 != null ? var2.getItemName() : "unknown" + var1;
   }

   public String getPlural(String var1) {
      return this.getSingular(var1) + "s";
   }

   public String itemName(String var1, int var2) {
      return var2 == 1 ? "a " + this.getSingular(var1) : "" + var2 + " " + this.getPlural(var1);
   }

   public String itemName(InventoryItem var1) {
      return this.itemName(var1.getItemId(), var1.getItemQuantity());
   }

   private InventoryManager() {
      this.masterList_ = new Hashtable();
      this.initialized_ = false;
      this.equipped_ = new Vector();
      ServerTableManager var1 = ServerTableManager.instance();
      int var2 = var1.getFileVersion();
      String[] var3 = var1.getTable("invList");
      String[] var4 = new String[0];
      if (var2 > 1) {
         var4 = var1.getTable("graphicList");
      }

      URL var5 = URL.make("home:..\\default.gif");
      if (var3 != null) {
         byte var6 = 12;

         for (byte var19 = 0; var19 < var3.length; var19 += var6) {
            String var7 = var3[var19];
            String var8 = var3[var19 + 2];
            String var9 = var3[var19 + 3];
            int var10 = Double.valueOf(var3[var19 + 4]).intValue();
            float var14 = Double.valueOf(var3[var19 + 5]).floatValue();
            int var11 = Double.valueOf(var3[var19 + 6]).intValue();
            int var12 = Double.valueOf(var3[var19 + 7]).intValue();
            int var13 = Double.valueOf(var3[var19 + 8]).intValue();
            float var15 = Double.valueOf(var3[var19 + 9]).floatValue();
            float var16 = Double.valueOf(var3[var19 + 10]).floatValue();
            float var17 = Double.valueOf(var3[var19 + 11]).floatValue();
            URL var18 = null;
            if (var2 > 1 && var4.length > var19 / 6 + 1) {
               String var20 = var4[var19 / 6 + 1];
               if (var20 != "default") {
                  var18 = URL.make(var20);
               }
            }

            if (var18 == null) {
               var18 = var5;
            }

            InventoryItem var21;
            if (var7.charAt(0) == 'H') {
               var21 = InventoryAction.createAction(var7, var8, 1);
            } else if (var7.charAt(0) == 'W') {
               var21 = new EquippableItem(var7, var8, 1, var9, var14, var10, var15, var16, var17, var11, var12, var13);
            } else if (var7.charAt(0) == 'V') {
               var21 = new InventoryAvatar(var7, var8, 1);
            } else {
               var21 = new InventoryItem(var7, var8, 1);
            }

            var21.setItemGraphicLocation(var18);
            this.masterList_.put(var7, var21);
         }
      }
   }

   public static InventoryManager getInventoryManager() {
      if (manager_ == null) {
         manager_ = new InventoryManager();
      }

      return manager_;
   }

   public boolean inventoryInitialized() {
      return this.initialized_;
   }
}

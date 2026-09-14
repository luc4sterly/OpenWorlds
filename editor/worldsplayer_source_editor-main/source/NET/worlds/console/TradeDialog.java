package NET.worlds.console;

import NET.worlds.scape.InventoryItem;
import NET.worlds.scape.InventoryManager;
import java.awt.BorderLayout;
import java.awt.Checkbox;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.Label;
import java.awt.Panel;
import java.awt.ScrollPane;
import java.awt.TextField;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

public class TradeDialog extends WhisperDialog {
   public static final String tradeServerName = "TRADE";
   private Checkbox confirmBox = new Checkbox(Console.message("Its-a-Deal"));
   ScrollPane scrollPane;
   private static Font font = new Font(Console.message("DialogFont"), 0, 12);
   private String lastOfferSent = "";
   private String lastOfferReceived = "";
   private Vector fieldList;
   private int keyChange;
   protected Panel hisOffer = new Panel();
   protected Panel yourOffer = new Panel();

   public TradeDialog(java.awt.Window var1, String var2) {
      super(var1, var2);
   }

   public static void sendTradeMessage(String var0) {
      Main.register(new TradeDialog$1(var0));
   }

   public synchronized void setTrading(boolean var1) {
      this.lastOfferReceived = "";
      this.lastOfferSent = "";
      this.isTrading = var1;
      if (this.isTrading) {
         Object[] var2 = new Object[]{new String(this.partner)};
         Console.println(MessageFormat.format(Console.message("Trade-with"), var2));
      } else {
         Object[] var3 = new Object[]{new String(this.partner)};
         Console.println(MessageFormat.format(Console.message("Whisper-to-from"), var3));
      }

      if (this.built && !this.building) {
         this.building = true;
         Main.register(new TradeDialog$2(this));
      }
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.confirmBox && this.confirmBox.getState()) {
         this.sendOffer(true, false);
         return true;
      } else {
         return false;
      }
   }

   protected synchronized void activeCallback() {
      if (this.keyChange > 0 && --this.keyChange == 0) {
         this.sendOffer(false, true);
      }
   }

   private void displayOffer(String var1, Panel var2) {
      InventoryManager var3 = InventoryManager.getInventoryManager();
      Hashtable var4 = var3.parseInventoryString(var1);
      var2.removeAll();
      GridBagConstraints var5 = new GridBagConstraints();
      GridBagLayout var6 = new GridBagLayout();
      var2.setLayout(var6);
      var5.weightx = 1.0;
      var5.weighty = 0.0;
      var5.gridheight = 1;
      var5.gridwidth = 0;
      var5.insets = new Insets(6, 3, 0, 8);
      var5.anchor = 17;
      if (var4.size() == 0) {
         var5.gridwidth = -1;
         var5.insets = new Insets(36, 20, 36, 3);
         Label var7 = new Label(Console.message("Nothing"));
         var6.setConstraints(var7, var5);
         var2.add(var7);
      }

      if (var4.size() > 0) {
         Enumeration var12 = var4.elements();

         while (var12.hasMoreElements()) {
            InventoryItem var8 = (InventoryItem)var12.nextElement();
            var5.gridwidth = -1;
            var5.insets = new Insets(6, 3, 0, 8);
            ImageCanvas var9 = new ImageCanvas(var8.getItemGraphicLocation());
            var6.setConstraints(var9, var5);
            var2.add(var9);
            var5.gridwidth = 0;
            var5.insets = new Insets(3, 3, 0, 3);
            int var10 = var8.getItemQuantity();
            Label var11 = new Label(InventoryManager.getInventoryManager().itemName(var8));
            var6.setConstraints(var11, var5);
            var2.add(var11);
         }
      }

      var2.invalidate();
      var2.doLayout();
      var2.validate();
      var2.repaint();
      Container var13 = var2.getParent();
      if (var13 != null) {
         var13.invalidate();
         var13.doLayout();
         var13.validate();
         var13.repaint();
      }
   }

   private synchronized void clearOffer() {
      int var1 = this.fieldList.size();

      for (int var2 = 0; var2 < var1; var2++) {
         TextField var3 = (TextField)this.fieldList.elementAt(var2);
         var3.setFont(font);
         var3.setText("");
      }
   }

   private synchronized void sendOffer(boolean var1, boolean var2) {
      String var3 = "";
      InventoryManager var4 = InventoryManager.getInventoryManager();
      Hashtable var5 = var4.getInventoryItems();
      if (var5.size() > 0) {
         Enumeration var6 = var5.elements();
         int var8 = 0;
         int var9 = this.fieldList.size();

         while (var6.hasMoreElements()) {
            InventoryItem var7 = (InventoryItem)var6.nextElement();
            TextField var10 = (TextField)this.fieldList.elementAt(var8);
            var10.setFont(font);
            String var11 = var7.getItemId();
            int var12 = -1;
            if (var10.getText().trim().length() == 0) {
               var12 = 0;
            } else {
               try {
                  var12 = Integer.parseInt(var10.getText());
               } catch (NumberFormatException var14) {
               }
            }

            int var13 = var7.getItemQuantity();
            if (var12 < 0 || var12 > var13) {
               this.whisperPart.println("*** Invalid number of " + InventoryManager.getInventoryManager().getPlural(var11) + ": " + var10.getText() + ".");
               return;
            }

            if (var12 > 0) {
               var3 = var3 + var11;
               if (var12 > 1) {
                  var3 = var3 + Integer.toString(var12);
               }
            }

            var8++;
         }
      }

      String var15 = var3;
      if (var1) {
         int var16 = this.lastOfferReceived.indexOf(",");
         if (var16 < 0 || !var3.equals(this.lastOfferReceived.substring(var16 + 1))) {
            Object[] var18 = new Object[]{new String(this.partner)};
            this.whisperPart.println(MessageFormat.format(Console.message("proposed-deal"), var18));
            if (var16 < 0) {
               var16 = this.lastOfferReceived.length();
               if (this.lastOfferReceived.equals("cancel")) {
                  var16 = 0;
               }
            }
         }

         String var19 = this.lastOfferReceived.substring(0, var16) + "," + var3;
         this.lastOfferSent = var19;
         var3 = var3 + "," + this.lastOfferReceived.substring(0, var16);
      } else {
         String var17 = this.lastOfferSent;
         int var20 = var17.indexOf(",");
         if (var2 && var3.equals(var17.substring(var20 + 1))) {
            return;
         }

         this.lastOfferSent = var3;
      }

      this.displayOffer(var15, this.yourOffer);
      this.whisperPart.say("&|+trade>" + var3);
      if (var1) {
         sendTradeMessage("&|+deal>" + this.whisperPart.getPartner() + " " + var3);
      }
   }

   public static String buildInvDesc(Hashtable var0) {
      String var1 = "";
      Enumeration var2 = var0.elements();
      InventoryManager var3 = InventoryManager.getInventoryManager();
      if (var2.hasMoreElements()) {
         Object var4 = var2.nextElement();
         if (var4 != null) {
            InventoryItem var5 = (InventoryItem)var4;
            var1 = var1 + var3.itemName(var5);
         }

         while (var2.hasMoreElements()) {
            var4 = var2.nextElement();
            InventoryItem var8 = (InventoryItem)var4;
            var1 = var1 + ", ";
            var1 = var1 + var3.itemName(var8);
         }
      }

      return var1;
   }

   protected void cancelTrading() {
      if (this.isTrading && this.isActive()) {
         this.whisperPart.say("&|+trade>cancel");
         if (this.lastOfferSent.indexOf(",") >= 0) {
            sendTradeMessage("&|+deal>cancel");
         }

         this.lastOfferSent = "";
      }
   }

   protected synchronized boolean done(boolean var1) {
      this.cancelTrading();
      WhisperManager.whisperManager().remove(this.partner);
      return super.done(var1);
   }

   protected void doneDeal() {
      String var1 = "";
      InventoryManager var2 = InventoryManager.getInventoryManager();
      int var3 = this.lastOfferSent.indexOf(",");
      if (var3 >= 0) {
         Hashtable var4 = var2.parseInventoryString(this.lastOfferSent.substring(var3 + 1));
         var1 = buildInvDesc(var4);
         if (var1.length() == 0) {
            var1 = "nothing";
         }

         Hashtable var5 = var2.parseInventoryString(this.lastOfferSent.substring(0, var3));
         String var6 = buildInvDesc(var5);
         if (var6.length() == 0) {
            var6 = "nothing";
         }

         var1 = ": " + var1 + " for " + var6;
         this.setTrading(true);
         Object[] var7 = new Object[]{new String(var1)};
         this.whisperPart.println(MessageFormat.format(Console.message("Trans-complete"), var7));
      }
   }

   protected void processOffer(boolean var1) {
      if (this.lastOfferReceived.equals("cancel")) {
         this.lastOfferReceived = "";
         this.cancelTrading();
         this.setTrading(true);
         Object[] var6 = new Object[]{new String(this.partner)};
         this.whisperPart.println(MessageFormat.format(Console.message("Trans-complete"), var6));
      } else {
         String var2 = this.lastOfferReceived;
         int var3 = 0;
         int var4 = var2.indexOf(",");
         Object[] var5 = new Object[]{new String(this.partner)};
         if (var4 < 0) {
            if (!var1) {
               this.whisperPart.println(MessageFormat.format(Console.message("offer-changed"), var5));
            }
         } else if (!var2.equals(this.lastOfferSent)) {
            var3 = this.lastOfferSent.indexOf(",");
            if (var3 < 0) {
               var3 = this.lastOfferSent.length();
            }

            if (var2.substring(var4 + 1).equals(this.lastOfferSent.substring(0, var3))) {
               this.whisperPart.println(MessageFormat.format(Console.message("proposed-this"), var5));
            } else {
               this.whisperPart.println(MessageFormat.format(Console.message("proposed-new"), var5));
            }
         }

         if (var4 < 0) {
            var4 = var2.length();
         }

         this.displayOffer(var2.substring(0, var4), this.hisOffer);
      }
   }

   protected synchronized void build() {
      if (this.lastOfferSent.equals("")) {
         this.displayOffer("", this.yourOffer);
      }

      if (this.lastOfferReceived.equals("") || this.lastOfferReceived.equals("cancel")) {
         this.displayOffer("", this.hisOffer);
      }

      this.building = false;
      if (this.built) {
         this.removeAll();
      }

      this.built = true;
      Color var1 = new Color(0, 0, 0);
      Color var2 = new Color(0, 192, 192);
      Color var3 = new Color(0, 160, 160);
      Color var4 = new Color(255, 255, 255);
      Color var5 = var2;
      Color var7 = var2;
      Color var8 = var2;
      this.setBackground(this.isTrading ? var1 : Color.white);
      this.setForeground(Color.black);
      InsetPanel var9 = null;
      if (this.isTrading) {
         var9 = new InsetPanel(new BorderLayout(), 6, 10, 12, 11);
         var9.setBackground(var1);
         InventoryManager var10 = InventoryManager.getInventoryManager();
         Hashtable var11 = var10.getInventoryItems();
         Enumeration var12 = var11.elements();
         int var13 = var11.size();
         this.fieldList = new Vector(var13);
         Panel var14 = new Panel(new GridLayout(1, var13 == 0 ? 1 : var13));
         var14.setBackground(var2);
         int var16 = 0;
         if (var11.size() > 0) {
            while (var12.hasMoreElements()) {
               InventoryItem var15 = (InventoryItem)var12.nextElement();
               Panel var31 = new Panel(new BorderLayout());
               var31.setFont(font);
               var31.setBackground((var16 & 1) == 1 ? var2 : var3);
               MultiLineLabel var18 = new MultiLineLabel(var10.itemName(var15), 3, 0);
               var31.add("North", var18);
               ImageCanvas var19 = new ImageCanvas(var15.getItemGraphicLocation());
               InsetPanel var20 = new InsetPanel(new BorderLayout(), 5, 15, 5, 15);
               var20.add("Center", var19);
               var20.setBackground((var16 & 1) == 1 ? var2 : var3);
               var31.add("Center", var20);
               Panel var21 = new Panel(new BorderLayout());
               var21.setFont(font);
               TextField var22 = new TextField("", 1);
               var22.setFont(font);
               this.fieldList.addElement(var22);
               var21.add("West", var22);
               var18 = new MultiLineLabel("of " + var15.getItemQuantity(), 3, 0);
               var21.add("Center", var18);
               var21.add("South", new FixedSizePanel(5, 25));
               var31.add("South", var21);
               var14.add(var31);
               var16++;
            }
         } else {
            Label var17 = new Label(Console.message("You-have-nothing"));
            var14.add(var17);
         }

         this.scrollPane = new WideScrollPane(var14, true);
         this.scrollPane.setBackground(var2);
         Panel var32 = new Panel(new BorderLayout());
         var32.setFont(font);
         Label var34 = new Label(Console.message("Your-inventory"));
         var34.setBackground(var1);
         var34.setForeground(var4);
         var32.add("North", var34);
         var32.add("Center", this.scrollPane);
         var9.add("North", var32);
         Panel var35 = new Panel(new GridLayout(1, 2));
         this.scrollPane = new WideScrollPane(this.yourOffer, true);
         this.scrollPane.setBackground(var5);
         InsetPanel var36 = new InsetPanel(new BorderLayout(), 0, 0, 8, 9);
         Label var37 = new Label(Console.message("Your-offer"));
         var37.setBackground(var1);
         var37.setForeground(var4);
         var36.add("North", var37);
         var36.add("Center", this.scrollPane);
         var35.add(var36);
         this.scrollPane = new WideScrollPane(this.hisOffer, true);
         this.scrollPane.setBackground(var5);
         InsetPanel var38 = new InsetPanel(new BorderLayout(), 0, 9, 8, 0);
         Object[] var23 = new Object[]{new String(this.partner)};
         Label var24 = new Label(MessageFormat.format(Console.message("partner-offer"), var23));
         var24.setBackground(var1);
         var24.setForeground(var4);
         var38.add("North", var24);
         var38.add("Center", this.scrollPane);
         var35.add(var38);
         InsetPanel var25 = new InsetPanel(new BorderLayout(), 8, 18, 8, 18);
         var25.setBackground(var1);
         var25.add("Center", var35);
         var25.add("South", this.confirmBox);
         var9.add("Center", var25);
         this.processOffer(true);
      }

      this.whisperPart.line.setBackground(this.isTrading ? var8 : Color.white);
      if (this.isTrading) {
         if (!this.isBroadcast) {
            Panel var26 = new Panel(new BorderLayout());
            this.whisperPart.listen.setBackground(var7);
            Object[] var28 = new Object[]{new String(this.partner)};
            Label var30 = new Label(MessageFormat.format(Console.message("Whispers-with"), var28));
            var30.setBackground(var1);
            var30.setForeground(var4);
            var26.add("North", var30);
            var26.add("Center", this.whisperPart.listen.getComponent());
            var26.add("South", this.whisperPart.line);
            var9.add("South", var26);
         } else {
            var9.add("South", this.whisperPart.line);
         }

         this.add(var9);
      } else {
         this.whisperPart.listen.setBackground(Color.lightGray);
         InsetPanel var27 = new InsetPanel(new BorderLayout(), 3, 1, 1, 1);
         var27.setBackground(Color.lightGray);
         var27.add("Center", this.whisperPart.listen.getComponent());
         this.add("Center", var27);
         InsetPanel var29 = new InsetPanel(new BorderLayout(), 2, 1, 2, 1);
         var29.setBackground(Color.lightGray);
         var29.add("Center", this.whisperPart.line);
         this.add("South", var29);
      }

      this.validate();
   }

   protected synchronized void print(String var1) {
      if (var1.startsWith("&|+trade>")) {
         if (!this.isTrading) {
            this.setTrading(true);
         }

         this.lastOfferReceived = var1.substring(9);
         if (!this.building) {
            this.processOffer(false);
         }
      } else if (!var1.startsWith("&|+")) {
         this.whisperPart.println("> " + var1);
      }
   }

   public synchronized boolean keyDown(Event var1, int var2) {
      if (!this.isTrading) {
         this.whisperPart.line.requestFocus();
      } else {
         this.keyChange = 2;
      }

      if (var2 == 10) {
         this.whisperPart.trigger();
         return true;
      } else {
         return false;
      }
   }

   public Dimension preferredSize() {
      Dimension var1 = super.preferredSize();
      if (var1.width < 400) {
         var1.width = 400;
      }

      if (var1.height < 400) {
         var1.height = 400;
      }

      return var1;
   }

   public Dimension minimumSize() {
      Dimension var1 = super.minimumSize();
      if (var1.width < 400) {
         var1.width = 400;
      }

      if (var1.height < 400) {
         var1.height = 400;
      }

      return var1;
   }
}

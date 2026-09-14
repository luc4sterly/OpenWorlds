package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.MultiLineLabel;
import NET.worlds.console.PolledDialog;
import NET.worlds.core.IniFile;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Component;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.Panel;
import java.awt.ScrollPane;
import java.text.MessageFormat;
import java.text.NumberFormat;
import java.util.Locale;
import java.util.Vector;

public class UpgradeDialog extends PolledDialog {
   private Button yesButton = new Button(Console.message("Yes-now"));
   private Button noButton = new Button(Console.message("No-later"));
   private Button moreInfo = new Button(Console.message("Show-me-more"));
   private Checkbox startupCheck;
   private boolean forceUpgrades = IniFile.gamma().getIniInt("forceUpgrades", 1) == 1;
   private static String instructions = Console.message("Please-uncheck") + " \n" + " \n";
   private static String forcedInstructions = Console.message("you-can-continue") + " \n" + " \n";
   private static String title = Console.message("Upgrade");
   private Vector checkboxes;
   private String info;
   private Vector list;
   private Vector bytes;
   private boolean first;
   private boolean chooseOne;
   private String name;
   private Component getsFocus;
   private MultiLineLabel msgLabel;

   public UpgradeDialog(Vector var1, Vector var2, boolean var3, String var4, String var5, boolean var6) {
      super(Console.getFrame(), null, title, false);
      this.setAlignment(1);
      this.list = var1;
      this.info = var5;
      this.name = var4;
      this.first = var3;
      this.bytes = var2;
      this.chooseOne = var6;
      this.readySetGo();
   }

   protected void build() {
      this.startupCheck = new Checkbox(Console.message("Check-for-up-each"), IniFile.gamma().getIniInt("CheckUpgrades", 1) != 0);
      int var1 = this.list.size();
      this.checkboxes = new Vector();
      Panel var2 = new Panel(new GridLayout(var1, 1));
      Component var3 = null;

      for (int var4 = 0; var4 < var1; var4++) {
         int var5 = (Integer)this.bytes.elementAt(var4);
         String var6 = NumberFormat.getInstance().format(var5 / 1000);
         Object[] var7 = new Object[]{new String(this.list.elementAt(var4).toString()), new String(var6)};
         String var8 = MessageFormat.format(Console.message("Kbytes"), var7);
         var3 = new Checkbox(var8, true);
         if (!this.forceUpgrades) {
            var2.add(var3);
         } else {
            var2.add(new MultiLineLabel(var8));
         }

         this.checkboxes.addElement(var3);
      }

      GridBagLayout var12 = new GridBagLayout();
      this.setLayout(var12);
      GridBagConstraints var13 = new GridBagConstraints();
      var13.anchor = 10;
      var13.fill = 0;
      var13.weightx = 1.0;
      var13.weighty = 1.0;
      var13.gridwidth = 0;
      var13.gridheight = 1;
      var13.insets = new Insets(0, 15, 0, 15);
      Object[] var14 = new Object[]{new String(this.name)};
      String var15 = this.first ? MessageFormat.format(Console.message("dont-have"), var14) : MessageFormat.format(Console.message("update-available"), var14);
      this.add(var12, new MultiLineLabel(var15 + "\n ", 5, 5), var13);
      if (var1 > 3) {
         ScrollPane var9 = new ScrollPane();
         GridBagConstraints var10 = new GridBagConstraints();
         var10.fill = 1;
         var10.gridwidth = 0;
         var9.setSize(280, 100);
         var9.validate();
         this.add(var12, var9, var10);
         var9.add(var2);
      } else {
         this.add(var12, var2, var13);
      }

      if (!this.forceUpgrades) {
         this.add(var12, this.startupCheck, var13);
      }

      this.msgLabel = new MultiLineLabel(this.calcMsg(), 5, 5);
      this.add(var12, this.msgLabel, var13);
      var13.gridwidth = 2;
      this.add(var12, this.getsFocus = this.yesButton, var13);
      if (!this.forceUpgrades || this.first) {
         var13.gridwidth = 0;
         this.add(var12, this.noButton, var13);
         var13.insets.top = 5;
         var13.insets.bottom = 15;
         this.add(var12, this.moreInfo, var13);
      }
   }

   private String calcMsg() {
      int var1 = 0;
      if (this.bytes != null) {
         for (int var2 = 0; var2 < this.bytes.size(); var2++) {
            if (((Checkbox)this.checkboxes.elementAt(var2)).getState()) {
               var1 += (Integer)this.bytes.elementAt(var2);
            }
         }
      }

      String var11 = "";
      String var3 = this.forceUpgrades ? forcedInstructions : instructions;
      if (var1 == 0) {
         var11 = Console.message("no-entries");
         return "\n" + var11 + " \n \n \n \n" + var3;
      } else {
         int var4 = 10 * var1 / 288000 + 1;
         String var5 = "" + var4 / 10 + "." + var4 % 10 + " " + (var4 == 10 ? Console.message("minute") : Console.message("minutes"));
         int var6 = 10 * var1 / 1000000 + 1;
         String var7 = "" + var6 / 10 + "." + var6 % 10 + " " + (var6 == 10 ? Console.message("minute") : Console.message("minutes"));
         NumberFormat var8 = NumberFormat.getNumberInstance(Locale.getDefault());
         String var9 = var8.format(var1 / 1000);
         Object[] var10 = new Object[]{new String(var9), new String(var7), new String(var5)};
         var11 = MessageFormat.format(Console.message("entries-total"), var10);
         return var11 + var3;
      }
   }

   public void show() {
      super.show();
      this.getsFocus.requestFocus();
   }

   public synchronized boolean confirmUpgrade() {
      while (this.isActive()) {
         try {
            this.wait();
         } catch (InterruptedException var2) {
         }
      }

      return this.getConfirmed();
   }

   public int confirmUpgradeFromList() {
      if (!this.confirmUpgrade()) {
         return 0;
      }

      int var1 = 0;

      while (var1 < this.bytes.size() && ((Checkbox)this.checkboxes.elementAt(var1)).getState()) {
         var1++;
      }

      return var1;
   }

   public Vector rejectedList() {
      if (!this.confirmUpgrade()) {
         return this.list;
      }

      Vector var1 = new Vector();

      for (int var2 = 0; var2 < this.bytes.size(); var2++) {
         if (!((Checkbox)this.checkboxes.elementAt(var2)).getState()) {
            var1.addElement(this.list.elementAt(var2));
         }
      }

      return var1;
   }

   protected synchronized boolean done(boolean var1) {
      boolean var2 = super.done(var1);
      this.notify();
      return var2;
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.yesButton) {
         return this.done(true);
      }

      if (var1.target == this.noButton) {
         return this.done(false);
      }

      if (var1.target == this.moreInfo) {
         NetUpdate.showInfo(this.info);
      } else if (var1.target == this.startupCheck) {
         IniFile.gamma().setIniInt("CheckUpgrades", this.startupCheck.getState() ? 1 : 0);
      } else if (var1.target instanceof Checkbox) {
         if (this.chooseOne) {
            int var3 = this.checkboxes.indexOf(var1.target);
            if (((Checkbox)var1.target).getState()) {
               while (--var3 >= 0) {
                  ((Checkbox)this.checkboxes.elementAt(var3)).setState(true);
               }
            } else {
               while (++var3 < this.checkboxes.size()) {
                  ((Checkbox)this.checkboxes.elementAt(var3)).setState(false);
               }
            }
         }

         this.msgLabel.setLabel(this.calcMsg());
         return true;
      }

      return false;
   }

   public boolean handleEvent(Event var1) {
      return this.forceUpgrades && var1.id == 201 ? this.done(true) : super.handleEvent(var1);
   }

   public boolean keyDown(Event var1, int var2) {
      return !this.forceUpgrades && var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }
}

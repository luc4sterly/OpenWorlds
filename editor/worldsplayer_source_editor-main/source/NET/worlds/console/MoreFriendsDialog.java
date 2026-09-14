package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.List;
import java.awt.Menu;
import java.awt.MenuItem;
import java.util.Vector;

class MoreFriendsDialog extends PolledDialog {
   private List listbox = new List(10);
   private Button cancelButton = new Button(Console.message("Close"));
   private FriendsListPart friends;
   private Menu menu;
   private Vector buttons = new Vector();
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   private Object listMutex = new Object();

   MoreFriendsDialog(FriendsListPart var1, Menu var2, Vector var3) {
      super(Console.getFrame(), var1, Console.message("Friends-Online"), false);
      this.setAlignment(1);
      this.friends = var1;
      this.menu = var2;

      for (int var4 = 0; var4 < var3.size(); var4++) {
         this.listbox.addItem((String)var3.elementAt(var4));
      }

      this.ready();
   }

   protected void build() {
      int var1 = this.menu.getItemCount();
      GridBagLayout var2 = new GridBagLayout();
      this.setLayout(var2);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 1;
      var3.weightx = 1.0;
      var3.weighty = 1.0;
      var3.gridwidth = 2;
      var3.gridheight = var1 + 1;
      this.listbox.setFont(font);
      this.add(var2, this.listbox, var3);
      var3.weightx = 0.0;
      var3.weighty = 0.0;
      var3.gridwidth = 0;
      var3.gridheight = 1;
      var3.fill = 2;

      for (int var4 = 0; var4 < var1; var4++) {
         String var5 = this.menu.getItem(var4).getLabel();
         Button var6 = new Button(var5);
         var6.setFont(bfont);
         this.buttons.addElement(var6);
         this.add(var2, var6, var3);
      }

      var3.weighty = 1.0;
      var3.anchor = 15;
      this.cancelButton.setFont(bfont);
      this.add(var2, this.cancelButton, var3);
   }

   void addName(String var1) {
      synchronized (this.listMutex) {
         this.listbox.addItem(var1);
         if (this.listbox.countItems() == 1) {
            this.listbox.select(0);
            this.select(true);
         }
      }
   }

   void removeName(int var1) {
      synchronized (this.listMutex) {
         int var3 = this.listbox.getSelectedIndex();
         this.listbox.delItem(var1);
         if (var3 == var1) {
            int var4 = this.listbox.countItems();
            if (var1 < var4 - 1) {
               this.listbox.select(var1);
            } else if (var4 > 0) {
               this.listbox.select(var4 - 1);
            } else {
               this.select(false);
               this.listbox.requestFocus();
            }
         }
      }
   }

   private void select(boolean var1) {
      for (int var2 = 0; var2 < this.buttons.size(); var2++) {
         Button var3 = (Button)this.buttons.elementAt(var2);
         var3.enable(var1);
      }
   }

   public void show() {
      super.show();
      synchronized (this.listMutex) {
         if (this.listbox.countItems() != 0) {
            this.listbox.select(0);
            this.select(true);
         } else {
            this.select(false);
         }
      }

      this.listbox.requestFocus();
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 701) {
         this.select(true);
      } else if (var1.id == 702) {
         this.select(false);
      }

      return super.handleEvent(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.cancelButton) {
         return this.done(false);
      }

      int var4 = this.buttons.indexOf(var3);
      if (var4 != -1) {
         MenuItem var5 = this.menu.getItem(var4);
         String var6;
         synchronized (this.listMutex) {
            var6 = this.listbox.getSelectedItem();
         }

         if (var6 != null) {
            this.friends.moreFriendsAction(var6, var5);
            return true;
         }
      }

      return false;
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 != 27 && var2 != 10 ? super.keyDown(var1, var2) : this.done(false);
   }
}

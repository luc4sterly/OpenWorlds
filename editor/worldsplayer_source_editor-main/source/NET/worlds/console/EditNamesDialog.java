package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.List;

class EditNamesDialog extends PolledDialog implements DialogReceiver {
   private List listbox = new List(10);
   private Button addButton = new Button(Console.message("Add"));
   private Button delButton = new Button(Console.message("Delete"));
   private Button cancelButton = new Button(Console.message("Done"));
   private NameListOwner owner;
   private String addTitle;
   private static Font font = new Font(Console.message("ButtonFont"), 0, 12);

   EditNamesDialog(NameListOwner var1, String var2, String var3) {
      super(Console.getFrame(), null, var2, true);
      this.owner = var1;
      this.addTitle = var3;
      this.ready();
   }

   protected void build() {
      int var1 = this.owner.getNameListCount();

      for (int var2 = 0; var2 < var1; var2++) {
         this.listbox.addItem(this.owner.getNameListName(var2));
      }

      GridBagLayout var4 = new GridBagLayout();
      this.setLayout(var4);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 1;
      var3.weightx = 1.0;
      var3.weighty = 1.0;
      var3.gridwidth = 2;
      var3.gridheight = 3;
      this.add(var4, this.listbox, var3);
      var3.weightx = 0.0;
      var3.weighty = 0.0;
      var3.gridwidth = 0;
      var3.gridheight = 1;
      var3.fill = 2;
      this.addButton.setFont(font);
      this.delButton.setFont(font);
      this.cancelButton.setFont(font);
      this.add(var4, this.addButton, var3);
      this.add(var4, this.delButton, var3);
      var3.weighty = 1.0;
      var3.anchor = 15;
      this.add(var4, this.cancelButton, var3);
   }

   private void select(boolean var1) {
      this.delButton.enable(var1);
   }

   public void show() {
      super.show();
      if (this.listbox.countItems() != 0) {
         this.listbox.select(0);
         this.select(true);
      } else {
         this.select(false);
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

      if (var3 == this.delButton) {
         int var4 = this.listbox.getSelectedIndex();
         if (var4 != -1) {
            this.listbox.delItem(var4);
            this.owner.removeNameListName(var4);
            int var5 = this.listbox.countItems();
            if (var4 < var5 - 1) {
               this.listbox.select(var4);
            } else if (var5 > 0) {
               this.listbox.select(var5 - 1);
            } else {
               this.select(false);
               this.listbox.requestFocus();
            }
         }

         return true;
      } else if (var3 == this.addButton) {
         if (this.owner.mayAddNameListName(this)) {
            new AddNameDialog(this, this.addTitle);
         }

         return true;
      } else {
         return false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 != 27 && var2 != 10 ? super.keyDown(var1, var2) : this.done(false);
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var2) {
         String var3 = Console.parseUnicode(((AddNameDialog)var1).getName());
         int var4 = this.owner.addNameListName(var3);
         if (var4 == -1) {
            return;
         }

         if (var4 == this.listbox.countItems()) {
            this.listbox.addItem(var3);
         }

         this.listbox.makeVisible(var4);
         this.listbox.select(var4);
         this.select(true);
      }
   }
}

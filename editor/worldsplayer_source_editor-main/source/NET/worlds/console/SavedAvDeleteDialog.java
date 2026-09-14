package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.List;

class SavedAvDeleteDialog extends PolledDialog {
   private List listbox = new List(10);
   private Button delButton = new Button(Console.message("Delete"));
   private Button cancelButton = new Button(Console.message("Done"));
   private SavedAvPart avatars;

   SavedAvDeleteDialog(SavedAvPart var1) {
      super(Console.getFrame(), null, Console.message("Delete-Avatar"), true);
      this.avatars = var1;
      this.ready();
   }

   protected void build() {
      int var1 = SavedAvPart.getAvatarCount();

      for (int var2 = 0; var2 < var1; var2++) {
         this.listbox.addItem(SavedAvPart.getAvatarName(var2));
      }

      Label var5 = new Label(Console.message("Choose-Avatar"));
      GridBagLayout var3 = new GridBagLayout();
      this.setLayout(var3);
      GridBagConstraints var4 = new GridBagConstraints();
      var4.fill = 2;
      var4.gridwidth = 0;
      var4.gridheight = 1;
      var4.weightx = 1.0;
      var4.weighty = 0.0;
      this.add(var3, var5, var4);
      var4.fill = 1;
      var4.gridwidth = 0;
      var4.gridheight = 6;
      var4.weightx = 1.0;
      var4.weighty = 1.0;
      this.add(var3, this.listbox, var4);
      var4.fill = 0;
      var4.gridwidth = -1;
      var4.gridheight = 0;
      var4.anchor = 14;
      var4.weightx = 0.45;
      var4.weighty = 0.0;
      this.add(var3, this.delButton, var4);
      var4.gridwidth = 0;
      var4.anchor = 16;
      var4.weightx = 0.55;
      this.add(var3, this.cancelButton, var4);
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
            this.avatars.removeAvatar(var4);
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
      } else {
         return false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 != 27 && var2 != 10 ? super.keyDown(var1, var2) : this.done(false);
   }
}

package NET.worlds.scape;

import java.awt.Choice;
import java.util.Vector;

class InventoryList extends Choice {
   private Vector invItems_ = new Vector();

   public InventoryList() {
      super.add("None");
   }

   public EquippableItem getSelected() {
      int var1 = super.getSelectedIndex();
      return var1 > 0 ? (EquippableItem)this.invItems_.elementAt(var1 - 1) : null;
   }

   public void add(EquippableItem var1) {
      super.add(var1.getItemName());
      this.invItems_.add(var1);
   }

   public void selectItem(EquippableItem var1) {
      super.select(var1.getItemName());
   }
}

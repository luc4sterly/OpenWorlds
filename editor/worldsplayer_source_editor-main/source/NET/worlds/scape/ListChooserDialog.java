package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.GridBagConstraints;
import java.awt.List;

public abstract class ListChooserDialog extends OkCancelDialog {
   private List _listField = new List(5, false);
   protected EditTile _parent;

   protected ListChooserDialog(EditTile var1, String var2) {
      super(Console.getFrame(), var1, var2);
      this._parent = var1;
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      var1.fill = 1;
      this.add(this.gbag, this._listField, var1);
      super.build();
   }

   protected abstract String getEntry(int var1);

   protected abstract int getSelected();

   protected abstract boolean setValue(String var1, int var2);

   protected boolean setValue() {
      return this.setValue(this._listField.getSelectedItem(), this._listField.getSelectedIndex());
   }

   public void show() {
      super.show();
      int var1 = 0;

      for (String var2 = this.getEntry(var1); var2 != null; var2 = this.getEntry(++var1)) {
         this._listField.addItem(var2, var1);
      }

      var1 = this.getSelected();
      if (var1 != -1) {
         this._listField.select(var1);
      }

      this._listField.requestFocus();
   }
}

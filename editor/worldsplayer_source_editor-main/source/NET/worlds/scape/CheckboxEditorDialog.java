package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.Dimension;
import java.awt.GridBagConstraints;

public abstract class CheckboxEditorDialog extends OkCancelDialog {
   private CheckboxGroup group = new CheckboxGroup();
   private Checkbox[] choices;
   private String[] labels;
   protected EditTile parent;

   protected CheckboxEditorDialog(EditTile var1, String var2, String[] var3) {
      super(Console.getFrame(), var1, var2);
      this.labels = var3;
      this.parent = var1;
   }

   protected void build() {
      this.choices = new Checkbox[this.labels.length];
      GridBagConstraints var1 = new GridBagConstraints();
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;

      for (int var2 = 0; var2 < this.labels.length; var2++) {
         this.add(this.gbag, this.choices[var2] = new Checkbox(this.labels[var2], this.group, false), var1);
      }

      super.build();
   }

   protected abstract int getValue();

   protected abstract void setValue(int var1);

   protected boolean setValue() {
      Checkbox var1 = this.group.getCurrent();

      for (int var2 = 0; var2 < this.choices.length; var2++) {
         if (this.choices[var2] == var1) {
            this.setValue(var2);
            return true;
         }
      }

      return false;
   }

   public void show() {
      Dimension var1 = this.size();
      this.initialSize(var1.width < 160 ? 160 : var1.width, var1.height < 120 ? 120 : var1.height);
      super.show();
      int var2 = this.getValue();
      this.choices[var2].requestFocus();
      this.choices[var2].setState(true);
   }
}

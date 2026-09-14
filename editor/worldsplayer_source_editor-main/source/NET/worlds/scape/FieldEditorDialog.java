package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.TextField;

public abstract class FieldEditorDialog extends OkCancelDialog {
   private TextField strField = new TextField(40);
   protected EditTile parent;
   private static Font font = new Font(Console.message("GammaTextFont"), 0, 12);

   protected FieldEditorDialog(EditTile var1, String var2) {
      super(Console.getFrame(), var1, var2);
      this.parent = var1;
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.fill = 2;
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      this.strField.setFont(font);
      this.add(this.gbag, this.strField, var1);
      super.build();
   }

   protected abstract String getValue();

   protected abstract boolean setValue(String var1);

   protected boolean setValue() {
      return this.setValue(this.strField.getText().trim());
   }

   public void show() {
      super.show();
      this.strField.setText(this.getValue());
      this.strField.requestFocus();
      this.strField.selectAll();
   }
}

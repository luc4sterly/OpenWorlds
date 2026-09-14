package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.List;
import java.awt.TextField;
import java.util.Enumeration;
import java.util.Vector;

public abstract class FieldWithListEditorDialog extends OkCancelDialog {
   private TextField strField = new TextField(40);
   private List list = new List();
   private Vector choices;
   protected EditTile parent;
   private static Font font = new Font(Console.message("GammaTextFont"), 0, 12);

   protected FieldWithListEditorDialog(EditTile var1, String var2, Vector var3) {
      super(Console.getFrame(), var1, var2);
      this.choices = var3;
      this.parent = var1;
   }

   protected void build() {
      Enumeration var1 = this.choices.elements();

      while (var1.hasMoreElements()) {
         this.list.addItem((String)var1.nextElement());
      }

      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 2;
      var2.weightx = 0.0;
      var2.weighty = 0.0;
      var2.gridwidth = 0;
      this.strField.setFont(font);
      this.add(this.gbag, this.strField, var2);
      var2.fill = 1;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridheight = 6;
      this.add(this.gbag, this.list, var2);
      super.build();
   }

   public boolean handleEvent(java.awt.Event var1) {
      if (var1.id == 701) {
         this.strField.setText(this.list.getSelectedItem());
         this.strField.selectAll();
      }

      return super.handleEvent(var1);
   }

   public boolean action(java.awt.Event var1, Object var2) {
      if (var1.target == this.list) {
         var1.target = this.okButton;
      }

      return super.action(var1, var2);
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

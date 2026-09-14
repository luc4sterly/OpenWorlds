package NET.worlds.console;

import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Point;
import java.awt.TextField;

public class AttributeSortPanel extends Frame implements MainCallback, MainTerminalCallback {
   private AttributeList list;
   private Button addButton = new Button("Add");
   private Button deleteButton = new Button("Delete");
   private Button moveUpButton = new Button("MoveUp");
   private Button moveDownButton = new Button("MoveDown");
   private Button okButton = new Button("Ok");
   private Button cancelButton = new Button("Cancel");
   private Button clearButton = new Button("Clear");
   private TextField attNameField = new TextField(32);
   private Label attNameLabel = new Label("Attribute Name: ");

   public AttributeSortPanel(java.awt.Window var1) {
      super("Attribute Sorting");
      this.list = new AttributeList(10);
      GridBagLayout var2 = new GridBagLayout();
      GridBagConstraints var3 = new GridBagConstraints();
      this.setLayout(var2);
      this.setBackground(Color.gray);
      var3.gridx = 1;
      var3.gridy = 1;
      var3.gridheight = 7;
      var3.gridwidth = 3;
      var3.anchor = 18;
      var2.setConstraints(this.list, var3);
      this.add(this.list);
      var3.gridx = 4;
      var3.gridy = 1;
      var3.gridwidth = 1;
      var3.gridheight = 1;
      var2.setConstraints(this.moveUpButton, var3);
      this.add(this.moveUpButton);
      var3.gridx = 4;
      var3.gridy = 2;
      var3.gridwidth = 1;
      var3.gridheight = 1;
      var2.setConstraints(this.moveDownButton, var3);
      this.add(this.moveDownButton);
      var3.gridx = 4;
      var3.gridy = 5;
      var3.gridheight = 1;
      var3.gridwidth = 3;
      var2.setConstraints(this.attNameLabel, var3);
      this.add(this.attNameLabel);
      var3.gridy = 6;
      var3.gridheight = 1;
      var3.gridwidth = 3;
      var2.setConstraints(this.attNameField, var3);
      this.add(this.attNameField);
      var3.gridx = 7;
      var3.gridy = 6;
      var3.gridheight = 1;
      var3.gridwidth = 1;
      var2.setConstraints(this.addButton, var3);
      this.add(this.addButton);
      var3.gridx = 7;
      var3.gridy = 1;
      var3.gridwidth = 1;
      var3.gridheight = 1;
      var2.setConstraints(this.deleteButton, var3);
      this.add(this.deleteButton);
      var3.gridx = 7;
      var3.gridy = 2;
      var2.setConstraints(this.clearButton, var3);
      this.add(this.clearButton);
      var3.gridx = 5;
      var3.gridy = 8;
      var2.setConstraints(this.okButton, var3);
      this.add(this.okButton);
      var3.gridx = 7;
      var2.setConstraints(this.cancelButton, var3);
      this.add(this.cancelButton);
      this.pack();
      Point var4 = var1.location();
      Dimension var5 = var1.size();
      this.reshape(var4.x + (var5.width - 512) / 2, var4.y + (var5.height - 240) / 2, 512, 240);
      this.show();
      Main.register(this);
   }

   public boolean handleEvent(Event var1) {
      switch (var1.id) {
         case 201:
            this.dispose();
            return true;
         default:
            return super.handleEvent(var1);
      }
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.addButton) {
         String var6 = this.attNameField.getText();
         if (var6 != "") {
            this.list.add(var6);
         }

         this.attNameField.setText("");
         return true;
      } else {
         if (var1.target == this.deleteButton) {
            this.list.remove(this.list.getSelectedIndex());
            return true;
         }

         if (var1.target == this.moveUpButton) {
            int var5 = this.list.getSelectedIndex();
            if (var5 > 0) {
               String var7 = this.list.getItem(var5 - 1);
               this.list.remove(var5 - 1);
               this.list.add(var7, var5);
            }

            return true;
         } else if (var1.target == this.moveDownButton) {
            int var3 = this.list.getSelectedIndex();
            if (var3 < this.list.getItemCount()) {
               String var4 = this.list.getItem(var3 + 1);
               this.list.remove(var3 + 1);
               this.list.add(var4, var3);
            }

            return true;
         } else if (var1.target == this.cancelButton) {
            this.dispose();
            return true;
         } else if (var1.target == this.clearButton) {
            this.list.clear();
            return true;
         } else if (var1.target == this.okButton) {
            this.list.save();
            this.dispose();
            return true;
         } else {
            return false;
         }
      }
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      Main.unregister(this);
   }
}

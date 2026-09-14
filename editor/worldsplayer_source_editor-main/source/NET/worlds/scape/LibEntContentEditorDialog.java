package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.Choice;
import java.awt.GridBagConstraints;
import java.awt.List;
import java.awt.TextField;
import java.util.Enumeration;
import java.util.StringTokenizer;

class LibEntContentEditorDialog extends OkCancelDialog {
   private Property property;
   private TextField strField = new TextField(40);
   private List list = new List();
   private Choice choice = new Choice();
   private EditTile parent;
   private static String[] choices = new String[]{"WObject files", "Behavior/Action files", "Texture files"};
   private static String[] dirs = new String[]{LibrariesTile.getLibSubdir(), LibrariesTile.getLibSubdir(), LibrariesTile.getLibSubdir()};
   private static String[] exts = new String[]{WObject.getSaveExtension(), "class", TextureDecoder.getAllExts()};

   LibEntContentEditorDialog(EditTile var1, String var2, Property var3) {
      super(Console.getFrame(), var1, var2);
      this.property = var3;
      this.parent = var1;
      this.ready();
   }

   private void matchExt(String var1) {
      int var2 = var1.lastIndexOf(46);
      if (var2 != -1) {
         String var3 = var1.substring(var2 + 1).toLowerCase();

         for (int var4 = 0; var4 < exts.length; var4++) {
            StringTokenizer var5 = new StringTokenizer(exts[var4], ";");

            while (var5.hasMoreTokens()) {
               if (var3.equals(var5.nextToken())) {
                  this.choice.select(var4);
                  return;
               }
            }
         }
      }
   }

   protected void build() {
      for (int var1 = 0; var1 < choices.length; var1++) {
         this.choice.addItem(choices[var1]);
      }

      String var3 = (String)this.property.get();
      if (var3 == null) {
         var3 = "";
      }

      this.strField.setText(var3);
      this.matchExt(var3);
      this.setListContents();
      GridBagConstraints var2 = new GridBagConstraints();
      var2.fill = 2;
      var2.weightx = 1.0;
      var2.weighty = 1.0;
      var2.gridwidth = 0;
      this.add(this.gbag, this.strField, var2);
      var2.gridheight = 6;
      this.add(this.gbag, this.list, var2);
      var2.gridheight = 1;
      this.add(this.gbag, this.choice, var2);
      super.build();
   }

   private void setListContents() {
      int var1 = this.list.countItems();
      if (var1 != 0) {
         this.list.delItems(0, var1 - 1);
      }

      int var2 = this.choice.getSelectedIndex();
      Enumeration var3 = new FileList(dirs[var2], exts[var2]).getList().elements();

      while (var3.hasMoreElements()) {
         this.list.addItem((String)var3.nextElement());
      }

      String var4 = (String)this.property.get();
      this.strField.setText(var4 != null ? var4 : "");
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

      if (var1.target == this.choice) {
         this.setListContents();
      }

      return super.action(var1, var2);
   }

   protected boolean setValue() {
      String var1 = this.strField.getText().trim();
      if (var1.length() != 0) {
         this.parent.addUndoableSet(this.property, var1);
         return true;
      } else {
         return false;
      }
   }

   public void show() {
      super.show();
      this.strField.requestFocus();
      this.strField.selectAll();
   }
}

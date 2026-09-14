package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.OkCancelDialog;
import java.awt.Choice;
import java.awt.GridBagConstraints;
import java.util.Enumeration;
import java.util.Vector;

public abstract class ListAdderDialog extends OkCancelDialog {
   private Choice list = new Choice();
   private boolean doSet = false;
   private int choice;
   protected EditTile parent;

   public ListAdderDialog(EditTile var1, String var2) {
      super(Console.getFrame(), var1, var2);
      this.parent = var1;
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.fill = 1;
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      this.add(this.gbag, this.list, var1);
      super.build();
   }

   protected void setListContents(String[] var1) {
      this.list.removeAll();

      for (int var2 = 0; var2 < var1.length; var2++) {
         this.list.addItem(var1[var2]);
      }
   }

   protected void setListContents(Vector var1) {
      this.list.removeAll();
      Enumeration var2 = var1.elements();

      while (var2.hasMoreElements()) {
         this.list.addItem((String)var2.nextElement());
      }
   }

   protected abstract void add(int var1);

   protected final synchronized void activeCallback() {
      if (this.doSet) {
         this.add(this.choice);
         this.doSet = false;
         this.notify();
      }
   }

   protected synchronized boolean setValue() {
      if ((this.choice = this.list.getSelectedIndex()) == -1) {
         return false;
      }

      this.doSet = true;

      while (this.doSet) {
         try {
            this.wait();
         } catch (InterruptedException var2) {
         }
      }

      return true;
   }

   public void show() {
      super.show();
      this.list.select(0);
      this.list.requestFocus();
   }
}

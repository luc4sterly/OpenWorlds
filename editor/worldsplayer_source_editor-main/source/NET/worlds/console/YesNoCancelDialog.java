package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;

public class YesNoCancelDialog extends PolledDialog {
   private Button yesButton = new Button(Console.message("Yes"));
   private Button noButton = new Button(Console.message("No"));
   private Button cancelButton = new Button(Console.message("Cancel"));
   private GridBagLayout gbag = new GridBagLayout();
   private String prompt;
   private int choice = -2;
   public static final int UNDECIDED = -2;
   public static final int CANCEL = -1;
   public static final int NO = 0;
   public static final int YES = 1;

   public YesNoCancelDialog(java.awt.Window var1, DialogReceiver var2, String var3, String var4) {
      super(var1, var2, var3, true);
      this.prompt = var4;
      this.setLayout(this.gbag);
      this.ready();
   }

   public int getChoice() {
      return this.choice;
   }

   protected void build() {
      GridBagConstraints var1 = new GridBagConstraints();
      var1.weightx = 1.0;
      var1.weighty = 1.0;
      var1.gridwidth = 0;
      this.add(this.gbag, new MultiLineLabel(this.prompt, 5, 5), var1);
      var1.gridwidth = 3;
      var1.weightx = 1.0;
      var1.weighty = 0.0;
      this.add(this.gbag, this.yesButton, var1);
      this.add(this.gbag, this.noButton, var1);
      this.add(this.gbag, this.cancelButton, var1);
   }

   public void show() {
      super.show();
      this.yesButton.requestFocus();
   }

   private boolean yes() {
      this.choice = 1;
      return this.done(true);
   }

   private boolean no() {
      this.choice = 0;
      return this.done(false);
   }

   private boolean cancel() {
      this.choice = -1;
      return this.done(false);
   }

   public boolean handleEvent(Event var1) {
      return var1.id == 201 ? this.cancel() : super.handleEvent(var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.yesButton) {
         return this.yes();
      } else if (var3 == this.noButton) {
         return this.no();
      } else {
         return var3 == this.cancelButton ? this.cancel() : false;
      }
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 == 27 ? this.cancel() : super.keyDown(var1, var2);
   }
}

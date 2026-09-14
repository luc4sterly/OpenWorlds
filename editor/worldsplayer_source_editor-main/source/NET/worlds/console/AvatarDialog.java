package NET.worlds.console;

import NET.worlds.scape.EventQueue;
import java.awt.Button;
import java.awt.Choice;
import java.awt.Color;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.Point;
import java.util.Vector;

public class AvatarDialog extends PolledDialog {
   private Button okButton = new Button(Console.message("Close"));
   private AvatarDialogCallback callback;
   private Vector choices = new Vector();
   private Vector changes = new Vector();
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   private int checkChanges;
   static Point lastWindowLocation = null;

   public AvatarDialog(java.awt.Window var1, DialogReceiver var2, String var3, AvatarDialogCallback var4) {
      super(var1, var2, var3, false);
      this.callback = var4;
      this.setResizable(false);
      this.setAlignment(3);
      this.ready();
   }

   public void setChangeCheck() {
      this.checkChanges = 2;
   }

   protected void build() {
      Vector var1 = this.callback.getComponents();
      int var2 = var1.size();
      Panel var3 = new Panel(new GridLayout(var2, 2, 2, 2));
      var3.setFont(font);
      var3.setBackground(Color.black);

      for (int var4 = 0; var4 < var2; var4++) {
         Label var5 = new Label((String)var1.elementAt(var4), 2);
         var5.setForeground(Color.white);
         var5.setFont(font);
         var3.add(var5);
         Choice var6 = new Choice();
         var6.setForeground(Color.white);
         var6.setBackground(Color.black);
         var6.setFont(font);
         var3.add(var6);
         this.choices.addElement(var6);
         Vector var7 = this.callback.getChoices(var4);
         int var8 = var7.size();

         for (int var9 = 0; var9 < var8; var9++) {
            var6.add((String)var7.elementAt(var9));
         }

         var6.select(this.callback.getCurrentSelection(var4));
      }

      GridBagLayout var10 = new GridBagLayout();
      this.setLayout(var10);
      GridBagConstraints var11 = new GridBagConstraints();
      var11.weightx = 1.0;
      var11.weighty = 1.0;
      var11.gridheight = var2;
      var11.gridwidth = 0;
      var11.fill = 0;
      this.add(var10, var3, var11);
      Panel var12 = new Panel();
      this.okButton.setFont(bfont);
      var12.add(this.okButton);
      var12.setBackground(Color.black);
      var11.gridheight = 1;
      var11.weightx = 0.0;
      var11.weighty = 0.0;
      var11.fill = 1;
      this.add(var10, var12, var11);
      this.okButton.setBackground(Color.black);
      this.okButton.setForeground(Color.white);
   }

   public boolean handleEvent(Event var1) {
      if (EventQueue.redirectDrivingKeys(var1)) {
         return true;
      } else {
         return var1.id == 201 ? this.done(false) : super.handleEvent(var1);
      }
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton) {
         return this.done(true);
      }

      int var4 = this.choices.size();

      for (int var5 = 0; var5 < var4; var5++) {
         Choice var6 = (Choice)this.choices.elementAt(var5);
         if (var3 == var6) {
            int[] var7 = new int[]{var5, var6.getSelectedIndex()};
            this.changes.addElement(var7);
            return true;
         }
      }

      return false;
   }

   public boolean done(boolean var1) {
      lastWindowLocation = this.getLocation();
      return super.done(var1);
   }

   public void closeWin() {
      if (lastWindowLocation == null) {
         this.done(true);
      }
   }

   protected void initialSize(int var1, int var2) {
      if (lastWindowLocation == null) {
         super.initialSize(var1, var2);
      } else {
         this.setLocation(lastWindowLocation);
         lastWindowLocation = null;
         this.setSize(var1, var2);
      }
   }

   protected void activeCallback() {
      if (this.checkChanges > 0 && --this.checkChanges == 0) {
         for (int var1 = 0; var1 < this.choices.size(); var1++) {
            ((Choice)this.choices.elementAt(var1)).select(this.callback.getCurrentSelection(var1));
         }
      }

      while (this.changes.size() != 0) {
         int[] var2 = (int[])this.changes.elementAt(0);
         this.callback.setCurrentSelection(var2[0], var2[1]);
         this.checkChanges = 1;
         this.changes.removeElementAt(0);
      }
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }
}

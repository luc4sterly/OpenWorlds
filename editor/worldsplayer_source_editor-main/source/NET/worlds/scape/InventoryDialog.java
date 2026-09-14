package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.ImageCanvas;
import NET.worlds.console.PolledDialog;
import NET.worlds.network.URL;
import java.awt.Button;
import java.awt.Color;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.util.Vector;

public class InventoryDialog extends PolledDialog {
   private InventoryList rightWristItems_;
   private ImageCanvas rightWristIcon_;
   private InventoryList leftWristItems_;
   private ImageCanvas leftWristIcon_;
   private InventoryList headItems_;
   private ImageCanvas headIcon_;
   private InventoryList rightAnkleItems_;
   private ImageCanvas rightAnkleIcon_;
   private InventoryList leftAnkleItems_;
   private ImageCanvas leftAnkleIcon_;
   private Button okButton_;
   private Button cancelButton_;
   private Frame parent_;
   private static final URL defaultImageURL = URL.make("home:..\\default.gif");
   private static Object lastPosAndSize;

   public InventoryDialog(Frame var1) {
      super(var1, null, Console.message("Inventory"), true);
      InventoryManager var2 = InventoryManager.getInventoryManager();
      Vector var3 = var2.getEquippableItems();
      Vector var4 = var2.getEquippedItems();
      this.parent_ = var1;
      this.rightWristItems_ = new InventoryList();
      this.leftWristItems_ = new InventoryList();
      this.headItems_ = new InventoryList();
      this.rightAnkleItems_ = new InventoryList();
      this.leftAnkleItems_ = new InventoryList();
      this.rightWristIcon_ = new ImageCanvas(defaultImageURL);
      this.leftWristIcon_ = new ImageCanvas(defaultImageURL);
      this.headIcon_ = new ImageCanvas(defaultImageURL);
      this.leftAnkleIcon_ = new ImageCanvas(defaultImageURL);
      this.rightAnkleIcon_ = new ImageCanvas(defaultImageURL);
      this.okButton_ = new Button("Ok");
      this.cancelButton_ = new Button("Cancel");

      for (int var5 = 0; var5 < var3.size(); var5++) {
         EquippableItem var6 = (EquippableItem)var3.elementAt(var5);
         switch (var6.getBodyLocation()) {
            case 4:
               this.headItems_.add(var6);
               break;
            case 8:
               this.rightWristItems_.add(var6);
               break;
            case 13:
               this.leftWristItems_.add(var6);
               break;
            case 17:
               this.rightAnkleItems_.add(var6);
               break;
            case 21:
               this.leftAnkleItems_.add(var6);
         }
      }

      for (int var7 = 0; var7 < var4.size(); var7++) {
         EquippableItem var8 = (EquippableItem)var4.elementAt(var7);
         switch (var8.getBodyLocation()) {
            case 4:
               this.headItems_.selectItem(var8);
               break;
            case 8:
               this.rightWristItems_.selectItem(var8);
               break;
            case 13:
               this.leftWristItems_.selectItem(var8);
               break;
            case 17:
               this.rightAnkleItems_.selectItem(var8);
               break;
            case 21:
               this.leftAnkleItems_.selectItem(var8);
         }
      }

      this.ready();
   }

   protected void build() {
      this.setBackground(Color.cyan);
      this.setForeground(Color.black);
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();
      Font var3 = new Font(Console.message("ConsoleFont"), 1, 18);
      Font var4 = new Font(Console.message("ConsoleFont"), 0, 12);
      Label var5 = new Label("Inventory");
      var2.gridx = 2;
      var2.gridy = 0;
      var2.weightx = 3.0;
      var5.setFont(var3);
      this.add(var1, var5, var2);
      Label var6 = new Label("Right Hand");
      var2.gridx = 4;
      var2.gridy = 4;
      var2.weightx = 1.0;
      var6.setFont(var4);
      this.add(var1, var6, var2);
      var2.gridy = 5;
      var2.weighty = 1.0;
      this.rightWristItems_.setFont(var4);
      this.add(var1, this.rightWristItems_, var2);
      var2.gridx = 3;
      var2.gridy = 5;
      var2.weighty = 1.0;
      var2.weightx = 1.0;
      this.add(var1, this.rightWristIcon_, var2);
      Label var7 = new Label("Left Hand");
      var2.gridx = 0;
      var2.gridy = 4;
      var2.weighty = 1.0;
      var7.setFont(var4);
      this.add(var1, var7, var2);
      var2.gridy = 5;
      var2.weighty = 1.0;
      this.leftWristItems_.setFont(var4);
      this.add(var1, this.leftWristItems_, var2);
      var2.gridx = 1;
      var2.gridy = 5;
      var2.weighty = 1.0;
      var2.weightx = 1.0;
      this.add(var1, this.leftWristIcon_, var2);
      Label var8 = new Label("Head");
      var2.gridx = 2;
      var2.gridy = 2;
      var2.weighty = 1.0;
      var8.setFont(var4);
      this.add(var1, var8, var2);
      var2.gridy = 3;
      var2.weighty = 1.0;
      this.headItems_.setFont(var4);
      this.add(var1, this.headItems_, var2);
      var2.gridx = 2;
      var2.gridy = 4;
      var2.weighty = 1.0;
      var2.weightx = 1.0;
      this.add(var1, this.headIcon_, var2);
      Label var9 = new Label("Right Foot");
      var2.gridx = 4;
      var2.gridy = 6;
      var2.weightx = 1.0;
      var9.setFont(var4);
      this.add(var1, var9, var2);
      var2.gridy = 7;
      var2.weighty = 0.0;
      this.rightAnkleItems_.setFont(var4);
      this.add(var1, this.rightAnkleItems_, var2);
      var2.gridx = 3;
      var2.gridy = 7;
      var2.weighty = 1.0;
      var2.weightx = 1.0;
      this.add(var1, this.rightAnkleIcon_, var2);
      Label var10 = new Label("Left Foot");
      var2.gridx = 0;
      var2.gridy = 6;
      var2.weighty = 1.0;
      var10.setFont(var4);
      this.add(var1, var10, var2);
      var2.gridy = 7;
      var2.weighty = 0.0;
      this.leftAnkleItems_.setFont(var4);
      this.add(var1, this.leftAnkleItems_, var2);
      var2.gridx = 1;
      var2.gridy = 7;
      var2.weighty = 1.0;
      var2.weightx = 1.0;
      this.add(var1, this.leftAnkleIcon_, var2);
      var2.gridx = 0;
      var2.gridy = 10;
      var2.weightx = 2.0;
      var2.weighty = 1.0;
      this.okButton_.setFont(var4);
      this.add(var1, this.okButton_, var2);
      var2.gridx = 4;
      var2.gridy = 10;
      this.cancelButton_.setFont(var4);
      this.add(var1, this.cancelButton_, var2);
      this.setSize(360, 300);
   }

   public synchronized boolean done(boolean var1) {
      Vector var2 = new Vector();
      EquippableItem var3;
      if ((var3 = this.rightWristItems_.getSelected()) != null) {
         var2.add(var3);
      }

      if ((var3 = this.leftWristItems_.getSelected()) != null) {
         var2.add(var3);
      }

      if ((var3 = this.headItems_.getSelected()) != null) {
         var2.add(var3);
      }

      if ((var3 = this.leftAnkleItems_.getSelected()) != null) {
         var2.add(var3);
      }

      if ((var3 = this.rightAnkleItems_.getSelected()) != null) {
         var2.add(var3);
      }

      if (var1) {
         InventoryManager var4 = InventoryManager.getInventoryManager();
         var4.setEquippedItems(var2);
      }

      return super.done(var1);
   }

   public boolean handleEvent(java.awt.Event var1) {
      return super.handleEvent(var1);
   }

   public boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      URL var4 = defaultImageURL;
      if (var3 == this.leftWristItems_) {
         EquippableItem var9 = this.leftWristItems_.getSelected();
         if (var9 != null) {
            var4 = var9.getItemGraphicLocation();
         }

         this.setIcon(this.leftWristIcon_, var4);
         return true;
      } else if (var3 == this.rightWristItems_) {
         EquippableItem var8 = this.rightWristItems_.getSelected();
         if (var8 != null) {
            var4 = var8.getItemGraphicLocation();
         }

         this.setIcon(this.rightWristIcon_, var4);
         return true;
      } else if (var3 == this.headItems_) {
         EquippableItem var7 = this.headItems_.getSelected();
         if (var7 != null) {
            var4 = var7.getItemGraphicLocation();
         }

         this.setIcon(this.headIcon_, var4);
         return true;
      } else if (var3 == this.leftAnkleItems_) {
         EquippableItem var6 = this.leftAnkleItems_.getSelected();
         if (var6 != null) {
            var4 = var6.getItemGraphicLocation();
         }

         this.setIcon(this.leftAnkleIcon_, var4);
         return true;
      } else if (var3 == this.rightAnkleItems_) {
         EquippableItem var5 = this.rightAnkleItems_.getSelected();
         if (var5 != null) {
            var4 = var5.getItemGraphicLocation();
         }

         this.setIcon(this.rightAnkleIcon_, var4);
         return true;
      } else if (var3 == this.okButton_) {
         return this.done(true);
      } else {
         return var3 == this.cancelButton_ ? this.done(false) : false;
      }
   }

   private void setIcon(ImageCanvas var1, URL var2) {
      var1.setNewImage(var2, this.getGraphics());
      this.repaint();
   }

   public void savePosAndSize(Object var1) {
      lastPosAndSize = var1;
   }

   public Object restorePosAndSize() {
      return lastPosAndSize;
   }

   public boolean keyDown(java.awt.Event var1, int var2) {
      return var2 == 27 ? this.done(false) : super.keyDown(var1, var2);
   }

   protected synchronized void activeCallback() {
      this.notify();
   }
}

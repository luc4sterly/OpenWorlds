package NET.worlds.scape;

import NET.worlds.console.ConfirmDialog;
import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.PolledDialog;
import java.awt.Button;
import java.awt.Component;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.TextField;
import java.text.MessageFormat;
import java.util.StringTokenizer;
import java.util.Vector;

class TransformEditorDialog extends PolledDialog implements DialogReceiver {
   Property property;
   Transform transform;
   int undoCount;
   Button undoButton = new Button(Console.message("Undo"));
   Button okButton = new Button(Console.message("OK"));
   Button cancelButton = new Button(Console.message("Cancel"));
   Button pitch = new MyButton(Console.message("Pitch-N"), 0, 1);
   Button roll = new MyButton(Console.message("Roll-N"), 0, 1);
   Button yaw = new MyButton(Console.message("Yaw-N"), 0, 1);
   Button spin = new MyButton(Console.message("Spin-by-XYZN"), 3, 1);
   Button spinTo = new MyButton(Console.message("Spin-to-XYZN"), 3, 1);
   Button moveX = new MyButton(Console.message("Move-x-by-N"), 0, 1);
   Button moveY = new MyButton(Console.message("Move-y-by-N"), 0, 1);
   Button moveZ = new MyButton(Console.message("Move-z-by-N"), 0, 1);
   Button moveBy = new MyButton(Console.message("Move-by-XYZ"), 3, 0);
   Button moveTo = new MyButton(Console.message("Move-to-XYZ"), 3, 0);
   Button scaleX = new MyButton(Console.message("Scale-x-by-N"), 0, 1);
   Button scaleY = new MyButton(Console.message("Scale-y-by-N"), 0, 1);
   Button scaleZ = new MyButton(Console.message("Scale-z-by-N"), 0, 1);
   Button scaleBy = new MyButton(Console.message("Scale-by-N"), 0, 1);
   Button scaleTo = new MyButton(Console.message("Scale-to-N"), 0, 1);
   Label position = new Label();
   Label rotation = new Label();
   Label scale = new Label();
   TextField editXYZ = new TextField();
   TextField editN = new TextField();
   GridBagLayout gbag = new GridBagLayout();
   GridBagConstraints c = new GridBagConstraints();
   Font normalFont;
   Font selectedFont;
   Button selectedButton;
   TextField lastEdit;
   EditTile parent;
   Object queuedFunc;
   private static Object lastPosAndSize;

   TransformEditorDialog(EditTile var1, String var2, Property var3) {
      super(Console.getFrame(), var1, var2, false);
      this.property = var3;
      this.parent = var1;
      this.ready();
   }

   protected void build() {
      this.transform = (Transform)this.property.get();
      this.setLayout(this.gbag);
      this.add2(new Label("(X,Y,Z):"), this.editXYZ);
      this.add2(new Label("(N):"), this.editN);
      this.add3(this.moveX, this.pitch, this.scaleX);
      this.add3(this.moveY, this.roll, this.scaleY);
      this.add3(this.moveZ, this.yaw, this.scaleZ);
      this.add3(this.moveBy, this.spin, this.scaleBy);
      this.add3(this.moveTo, this.spinTo, this.scaleTo);
      this.add2(new Label(Console.message("Position")), this.position);
      this.add2(new Label(Console.message("Rotation:")), this.rotation);
      this.add2(new Label(Console.message("Scale:")), this.scale);
      this.addButtons(this.undoButton, this.okButton, this.cancelButton);
      this.normalFont = this.pitch.getFont();
      this.selectedFont = new Font(this.normalFont.getName(), this.normalFont.isBold() ? 0 : 1, this.normalFont.getSize());
      this.updateInfo();
   }

   private void add2(Component var1, Component var2) {
      this.c.fill = 0;
      this.c.anchor = 13;
      this.c.gridheight = 1;
      this.c.weightx = 1.0;
      this.c.weighty = 1.0;
      this.c.gridwidth = 1;
      this.add(this.gbag, var1, this.c);
      this.c.anchor = 17;
      this.c.fill = 2;
      this.c.gridwidth = 0;
      this.add(this.gbag, var2, this.c);
   }

   private void add3(Component var1, Component var2, Component var3) {
      this.c.fill = 2;
      this.c.anchor = 17;
      this.c.gridheight = 1;
      this.c.gridwidth = 3;
      this.c.weightx = 1.0;
      this.c.weighty = 1.0;
      this.add(this.gbag, var1, this.c);
      this.c.weightx = 0.0;
      this.c.weighty = 0.0;
      this.add(this.gbag, var2, this.c);
      this.c.gridwidth = 0;
      this.add(this.gbag, var3, this.c);
   }

   private void addButtons(Component var1, Component var2, Component var3) {
      this.c.fill = 0;
      this.c.anchor = 13;
      this.c.gridheight = 1;
      this.c.gridwidth = 3;
      this.c.weightx = 1.0;
      this.c.weighty = 1.0;
      this.add(this.gbag, var1, this.c);
      this.c.anchor = 10;
      this.add(this.gbag, var2, this.c);
      this.c.anchor = 17;
      this.add(this.gbag, var3, this.c);
   }

   private void selectButton(Button var1) {
      if (this.selectedButton != null) {
         this.selectedButton.setFont(this.normalFont);
      }

      this.selectedButton = var1;
      this.selectedButton.setFont(this.selectedFont);
   }

   private void updateInfo() {
      this.position.setText(this.transform.getPosition().toString());
      this.scale.setText(this.transform.getScale().toString());
      Point3Temp var1 = Point3Temp.make();
      float var2 = this.transform.getSpin(var1);
      Object[] var3 = new Object[]{new String("" + var1), new String("" + var2)};
      this.rotation.setText(MessageFormat.format(Console.message("angle"), var3));
      this.undoButton.enable(this.undoCount != 0);
   }

   private void set(Transform var1) {
      this.parent.addUndoableSet(this.property, var1);
      this.undoCount++;
      this.transform = (Transform)this.property.get();
   }

   protected synchronized void activeCallback() {
      if (this.queuedFunc == this.undoButton) {
         if (this.undoCount != 0) {
            this.parent.undo();
            this.undoCount--;
            this.transform = (Transform)this.property.get();
            this.updateInfo();
         }
      } else if (this.queuedFunc instanceof MyButton) {
         this.apply((MyButton)this.queuedFunc);
      }

      this.queuedFunc = null;
   }

   public boolean undoAll() {
      if (this.undoCount == 0) {
         return this.done(false);
      }

      new ConfirmDialog(this, Console.message("Cancel-Transform"), Console.message("undo-changes"));
      return true;
   }

   public synchronized void dialogDone(Object var1, boolean var2) {
      if (var2) {
         while (this.undoCount != 0) {
            this.parent.undo();
            this.undoCount--;
         }

         this.done(false);
      }
   }

   public synchronized boolean action(java.awt.Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton) {
         return this.done(true);
      } else if (var3 == this.cancelButton) {
         return this.undoAll();
      } else if ((var3 == this.undoButton || var3 instanceof MyButton) && this.queuedFunc == null) {
         this.queuedFunc = var3;
         return true;
      } else {
         return false;
      }
   }

   private float[] parseNumbers(TextField var1) {
      Vector var2 = new Vector();
      StringTokenizer var3 = new StringTokenizer(var1.getText().trim(), ", \t", false);

      while (var3.hasMoreElements()) {
         try {
            var2.addElement(Float.valueOf(var3.nextToken()));
         } catch (NumberFormatException var6) {
            var2.removeAllElements();
            break;
         }
      }

      float[] var4 = new float[var2.size()];

      for (int var5 = 0; var5 < var4.length; var5++) {
         var4[var5] = (Float)var2.elementAt(var5);
      }

      return var4;
   }

   private boolean apply(MyButton var1) {
      float[] var2 = this.parseNumbers(this.editN);
      float[] var3 = this.parseNumbers(this.editXYZ);
      if (var1.numParamsXYZ != 0 && var1.numParamsXYZ != var3.length) {
         return this.setEdit(this.editXYZ);
      }

      if (var1.numParamsN != 0 && var1.numParamsN != var2.length) {
         return this.setEdit(this.editN);
      }

      if (var1 == this.pitch) {
         this.transform.worldSpin(1.0F, 0.0F, 0.0F, var2[0]);
      } else if (var1 == this.roll) {
         this.transform.worldSpin(0.0F, 1.0F, 0.0F, var2[0]);
      } else if (var1 == this.yaw) {
         this.transform.worldSpin(0.0F, 0.0F, 1.0F, var2[0]);
      } else if (var1 == this.spin) {
         this.transform.worldSpin(var3[0], var3[1], var3[2], var2[0]);
      } else if (var1 == this.spinTo) {
         Point3Temp var6 = this.transform.getScale();
         Point3Temp var5 = this.transform.getPosition();
         this.transform.makeIdentity();
         this.transform.scale(var6);
         this.transform.worldSpin(var3[0], var3[1], var3[2], var2[0]);
         this.transform.moveTo(var5.x, var5.y, var5.z);
      } else if (var1 == this.moveX) {
         this.transform.moveBy(var2[0], 0.0F, 0.0F);
      } else if (var1 == this.moveY) {
         this.transform.moveBy(0.0F, var2[0], 0.0F);
      } else if (var1 == this.moveZ) {
         this.transform.moveBy(0.0F, 0.0F, var2[0]);
      } else if (var1 == this.moveBy) {
         this.transform.moveBy(var3[0], var3[1], var3[2]);
      } else if (var1 == this.moveTo) {
         this.transform.moveTo(var3[0], var3[1], var3[2]);
      } else if (var1 == this.scaleX && var2[0] != 0.0F && this.checkScale(var2[0], this.transform.getScaleX())) {
         this.transform.scale(var2[0], 1.0F, 1.0F);
      } else if (var1 == this.scaleY && var2[0] != 0.0F && this.checkScale(var2[0], this.transform.getScaleY())) {
         this.transform.scale(1.0F, var2[0], 1.0F);
      } else if (var1 == this.scaleZ && var2[0] != 0.0F && this.checkScale(var2[0], this.transform.getScaleZ())) {
         this.transform.scale(1.0F, 1.0F, var2[0]);
      } else if (var1 == this.scaleBy
         && var2[0] != 0.0F
         && this.checkScale(var2[0], this.transform.getScaleX())
         && this.checkScale(var2[0], this.transform.getScaleY())
         && this.checkScale(var2[0], this.transform.getScaleZ())) {
         this.transform.scale(var2[0]);
      } else {
         if (var1 != this.scaleTo || var2[0] == 0.0F) {
            return true;
         }

         Point3Temp var4 = this.transform.getScale();
         this.transform.scale(var2[0] / var4.x, var2[0] / var4.y, var2[0] / var4.z);
      }

      this.set(this.transform);
      this.selectButton(var1);
      this.updateInfo();
      return this.setEdit(this.lastEdit);
   }

   private boolean checkScale(float var1, float var2) {
      double var3 = (double)var1 * var2;
      if (var3 < 2.938736052218037E-39) {
         Console.println(Console.message("exceed-minimum"));
      } else {
         if (!(var3 > Float.MAX_VALUE)) {
            return true;
         }

         Console.println(Console.message("exceed-maximum"));
      }

      return false;
   }

   private boolean toggleEdit() {
      return this.lastEdit == this.editN ? this.setEdit(this.editXYZ) : this.setEdit(this.editN);
   }

   private boolean setEdit(TextField var1) {
      var1.requestFocus();
      var1.selectAll();
      this.lastEdit = var1;
      return true;
   }

   public boolean keyDown(java.awt.Event var1, int var2) {
      if (var1.target == this.editXYZ || var1.target == this.editN) {
         this.lastEdit = (TextField)var1.target;
      }

      if (var2 == 27) {
         return this.undoAll();
      } else if (var2 == 10) {
         return this.done(true);
      } else {
         return var2 == 9 ? this.toggleEdit() : super.keyDown(var1, var2);
      }
   }

   public void show() {
      super.show();
      this.setEdit(this.editXYZ);
   }

   public void savePosAndSize(Object var1) {
      lastPosAndSize = var1;
   }

   public Object restorePosAndSize() {
      return lastPosAndSize;
   }
}

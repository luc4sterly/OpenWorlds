package NET.worlds.console;

import java.awt.Button;
import java.awt.Checkbox;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Point;
import java.awt.TextField;

public class SnapToolPanel extends Frame implements MainCallback, MainTerminalCallback {
   private Label xLabel;
   private Label yLabel;
   private Label zLabel;
   private TextField xValue;
   private TextField yValue;
   private TextField zValue;
   private Checkbox useSnapBox;
   private Button okButton = new Button("Ok");
   private Button cancelButton = new Button("Cancel");
   private int snapX;
   private int snapY;
   private int snapZ;
   private boolean useSnap;

   public SnapToolPanel(java.awt.Window var1) {
      super("Snap Tool Settings");
      this.xLabel = new Label("X Snap Value");
      this.yLabel = new Label("Y Snap Value");
      this.zLabel = new Label("Z Snap Value");
      this.snapX = SnapTool.snapTool().getSnapX();
      this.snapY = SnapTool.snapTool().getSnapY();
      this.snapZ = SnapTool.snapTool().getSnapZ();
      this.useSnap = SnapTool.snapTool().useSnap();
      this.useSnapBox = new Checkbox("Use Snap Tool", this.useSnap);
      this.xValue = new TextField("" + this.snapX);
      this.yValue = new TextField("" + this.snapY);
      this.zValue = new TextField("" + this.snapZ);
      GridBagLayout var2 = new GridBagLayout();
      GridBagConstraints var3 = new GridBagConstraints();
      this.setLayout(var2);
      this.setBackground(Color.gray);
      var3.gridx = 1;
      var3.gridy = 1;
      var3.gridheight = 1;
      var3.gridwidth = 1;
      var3.anchor = 18;
      var2.setConstraints(this.xLabel, var3);
      this.add(this.xLabel);
      var3.gridx = 2;
      var3.gridy = 1;
      var2.setConstraints(this.xValue, var3);
      this.add(this.xValue);
      var3.gridx = 1;
      var3.gridy = 2;
      var2.setConstraints(this.yLabel, var3);
      this.add(this.yLabel);
      var3.gridx = 2;
      var3.gridy = 2;
      var2.setConstraints(this.yValue, var3);
      this.add(this.yValue);
      var3.gridx = 1;
      var3.gridy = 3;
      var2.setConstraints(this.zLabel, var3);
      this.add(this.zLabel);
      var3.gridx = 2;
      var3.gridy = 3;
      var2.setConstraints(this.zValue, var3);
      this.add(this.zValue);
      var3.gridx = 2;
      var3.gridy = 5;
      var2.setConstraints(this.useSnapBox, var3);
      this.add(this.useSnapBox);
      var3.gridx = 5;
      var3.gridy = 1;
      var2.setConstraints(this.okButton, var3);
      this.add(this.okButton);
      var3.gridx = 5;
      var3.gridy = 2;
      var2.setConstraints(this.cancelButton, var3);
      this.add(this.cancelButton);
      this.pack();
      Point var4 = var1.location();
      Dimension var5 = var1.size();
      this.reshape(var4.x + (var5.width - 320) / 2, var4.y + (var5.height - 240) / 2, 320, 240);
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
      if (var1.target == this.cancelButton) {
         this.dispose();
         return true;
      } else if (var1.target == this.okButton) {
         this.snapX = Integer.parseInt(this.xValue.getText());
         this.snapY = Integer.parseInt(this.yValue.getText());
         this.snapZ = Integer.parseInt(this.zValue.getText());
         this.useSnap = this.useSnapBox.getState();
         SnapTool.snapTool().setSnap(this.useSnap);
         SnapTool.snapTool().setSnapX(this.snapX);
         SnapTool.snapTool().setSnapY(this.snapY);
         SnapTool.snapTool().setSnapZ(this.snapZ);
         this.dispose();
         return true;
      } else {
         return false;
      }
   }

   public void mainCallback() {
   }

   public void terminalCallback() {
      Main.unregister(this);
   }
}

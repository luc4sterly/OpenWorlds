package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.network.Galaxy;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;

public class SetNumVisibleAvs extends PolledDialog {
   private Button okButton = new Button(Console.message("Apply-Vis"));
   CheckboxGroup numAvsChoice = new CheckboxGroup();
   CheckboxGroup fullAvsChoice = new CheckboxGroup();
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);

   public SetNumVisibleAvs() {
      super(Console.getFrame(), null, Console.message("Num-Visible"), true);
      this.ready();
   }

   protected void build() {
      this.setLayout(new BorderLayout());
      this.add("North", new Filler(5, 5));
      this.add("South", new Filler(10, 10));
      this.add("East", new Filler(5, 5));
      this.add("West", new Filler(5, 5));
      Panel var1 = new Panel(new BorderLayout());
      var1.setFont(font);
      var1.add("North", new MultiLineLabel(Console.message("sel-max-av"), 5, 5));
      Panel var2 = new Panel(new GridLayout(8, 2));
      int var3 = IniFile.gamma().getIniInt("avatars", 24);
      int var4 = IniFile.gamma().getIniInt("fullavpercent", 60);
      var2.add(new Label(""));
      var2.add(new Label(Console.message("Max-Avs")));
      var2.add(new Label(Console.message("Slower"), 1));
      var2.add(new Checkbox("24", this.numAvsChoice, var3 == 24));
      var2.add(new Label(""));
      var2.add(new Checkbox("16", this.numAvsChoice, var3 == 16));
      var2.add(new Label(""));
      var2.add(new Checkbox("11", this.numAvsChoice, var3 == 11));
      var2.add(new Label(""));
      var2.add(new Checkbox("8", this.numAvsChoice, var3 == 8));
      var2.add(new Label(""));
      var2.add(new Checkbox("6", this.numAvsChoice, var3 == 6));
      var2.add(new Label(""));
      var2.add(new Checkbox("4", this.numAvsChoice, var3 == 4));
      var2.add(new Label(Console.message("Faster"), 1));
      var2.add(new Checkbox("2", this.numAvsChoice, var3 == 2));
      var1.add("Center", var2);
      var1.add("South", this.okButton);
      this.add("Center", var1);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 == this.okButton) {
         this.done(true);
         return true;
      } else {
         return false;
      }
   }

   protected boolean done(boolean var1) {
      if (var1) {
         Checkbox var2 = this.numAvsChoice.getSelectedCheckbox();
         if (var2 != null) {
            try {
               IniFile.gamma().setIniInt("avatars", Integer.parseInt(var2.getLabel()));
            } catch (NumberFormatException var5) {
            }
         }

         var2 = this.fullAvsChoice.getSelectedCheckbox();
         if (var2 != null) {
            try {
               String var3 = var2.getLabel();
               var3 = var3.substring(0, var3.length() - 1);
               IniFile.gamma().setIniInt("fullavpercent", Integer.parseInt(var3));
            } catch (NumberFormatException var4) {
            }
         }

         Galaxy.forceOffline(true);
      }

      return super.done(var1);
   }
}

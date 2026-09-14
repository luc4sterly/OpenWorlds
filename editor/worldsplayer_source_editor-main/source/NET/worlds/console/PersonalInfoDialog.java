package NET.worlds.console;

import java.awt.Button;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.TextArea;
import java.util.StringTokenizer;
import java.util.Vector;

class PersonalInfoDialog extends PolledDialog {
   private Vector info;
   private Button okButton = new Button(Console.message("OK"));
   private static Font font = new Font(Console.message("MenuFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);

   public PersonalInfoDialog(String var1, Vector var2) {
      super(Console.getFrame(), null, Console.message("Personal-Info") + var1, false);
      this.info = var2;
      this.ready();
   }

   protected void build() {
      GridBagLayout var1 = new GridBagLayout();
      this.setLayout(var1);
      GridBagConstraints var2 = new GridBagConstraints();

      try {
         int var3 = this.info.size();
         int var15 = 0;

         while (var15 < var3) {
            StringTokenizer var5 = new StringTokenizer((String)this.info.elementAt(var15++), ":");
            String var6 = var5.nextToken();
            var2.gridwidth = -1;
            var2.gridheight = 1;
            var2.fill = 1;
            Label var7 = new Label(var6, 1);
            var7.setFont(font);
            this.add(var1, var7, var2);
            int var8 = Integer.parseInt(var5.nextToken());
            int var9 = Math.max(Math.min(3, var8), 1);
            int var10 = 0;

            for (int var11 = 0; var11 < var8; var11++) {
               var10 = Math.max(var10, ((String)this.info.elementAt(var15 + var11)).length());
            }

            byte var16 = 3;
            if (var10 > 40) {
               if (var8 > ++var9) {
                  var16 = 0;
               } else {
                  var16 = 2;
               }
            } else if (var8 > var9) {
               var16 = 1;
            }

            TextArea var12 = new TextArea("", var9, 40, var16);
            var12.setFont(font);

            for (int var13 = 0; var13 < var8; var13++) {
               if (var13 > 0) {
                  var12.append("\n");
               }

               var12.append((String)this.info.elementAt(var15++));
            }

            var2.fill = 0;
            var2.gridwidth = 0;
            var2.gridheight = var9;
            var12.setEditable(false);
            this.add(var1, var12, var2);
         }
      } catch (Exception var14) {
         this.removeAll();
         var2.fill = 0;
         var2.gridwidth = 0;
         var2.gridheight = 1;
         Label var4 = new Label(Console.message("Format-error"));
         var4.setFont(font);
         this.add(var1, var4, var2);
      }

      var2.fill = 0;
      var2.gridwidth = 0;
      var2.gridheight = 1;
      this.okButton.setFont(bfont);
      this.add(var1, this.okButton, var2);
   }

   public boolean action(Event var1, Object var2) {
      return var1.target == this.okButton ? this.done(false) : false;
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 != 27 && var2 != 10 ? super.keyDown(var1, var2) : this.done(false);
   }

   public void show() {
      super.show();
      this.okButton.requestFocus();
   }
}

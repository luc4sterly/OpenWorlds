package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.NetUpdate;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Component;
import java.awt.Event;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextArea;
import java.util.Enumeration;
import java.util.Vector;

public class AboutDialog extends PolledDialog {
   Button okButton = new Button(Console.message("OK"));
   private static Font font = new Font(Console.message("ConsoleFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   String apptitle;

   AboutDialog(String var1, Frame var2) {
      super(var2, null, Console.message("About") + Std.getProductName(), true);
      this.apptitle = var1;
      this.ready();
   }

   private Component setConstraints(GridBagLayout var1, Component var2, GridBagConstraints var3) {
      var1.setConstraints(var2, var3);
      return var2;
   }

   protected void build() {
      this.setBackground(Color.white);
      this.setLayout(new BorderLayout());
      this.add("North", new Filler(10, 10));
      this.add("South", new Filler(10, 10));
      this.add("East", new Filler(10, 10));
      this.add("West", new Filler(10, 10));
      GridBagLayout var1 = new GridBagLayout();
      Panel var2 = new Panel(var1);
      var2.setFont(font);
      GridBagConstraints var3 = new GridBagConstraints();
      var3.fill = 0;
      var3.weightx = 1.0;
      var3.weighty = 1.0;
      var3.gridwidth = 0;
      var3.gridheight = 1;
      String var4 = IniFile.override().getIniString("AboutLogo", Console.message("wlogo.gif"));
      var2.add(this.setConstraints(var1, new ImageCanvas(var4), var3));
      var3.weightx = 0.0;
      var3.weighty = 0.0;
      var2.add(this.setConstraints(var1, new Label(this.apptitle), var3));
      if (Gamma.getShaper() != null) {
         var2.add(this.setConstraints(var1, new Label(Console.message("about-box-build-date") + " " + Std.getBuildInfo()), var3));
      } else {
         var2.add(this.setConstraints(var1, new Label(Console.message("about-box-rev") + " " + Std.getVersion()), var3));
      }

      Vector var5 = NetUpdate.aboutWorlds();
      TextArea var6 = new TextArea(10, 40);
      var6.setEditable(false);
      var2.add(this.setConstraints(var1, var6, var3));
      Enumeration var7 = var5.elements();

      while (var7.hasMoreElements()) {
         var6.append((String)var7.nextElement() + "\n");
      }

      var2.add(this.setConstraints(var1, new Label(Console.message("about-box-1")), var3));
      var2.add(this.setConstraints(var1, new Label(Console.message("about-box-2")), var3));
      this.okButton.setFont(bfont);
      var2.add(this.setConstraints(var1, this.okButton, var3));
      this.add("Center", var2);
   }

   public boolean action(Event var1, Object var2) {
      return var1.target == this.okButton ? this.done(true) : false;
   }

   public boolean keyDown(Event var1, int var2) {
      return var2 != 27 && var2 != 10 ? super.keyDown(var1, var2) : this.done(true);
   }

   public void show() {
      super.show();
      this.okButton.requestFocus();
   }
}

package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.ServerTableManager;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Event;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.Point;
import java.util.Vector;

class ActionDialog extends PolledDialog implements ImageButtonsCallback {
   BorderLayout overall = new BorderLayout();
   static Point lastWindowLocation = null;
   private Vector hunks = new Vector();
   private Vector names = new Vector();
   private static final int buttonsPerHunk = 1;
   private static final int buttonWidth = 72;
   private static final int[] buttonHeights = new int[]{16};
   private static final int[] xText = new int[]{22};
   private static final String topImageName = IniFile.override().getIniString("actionsTopGif", Console.message("actt.gif"));
   private static final String buttonImageName = IniFile.override().getIniString("actionsButtonGif", "actm.gif");
   private static final String bottomImageName = IniFile.override().getIniString("actionsBottomGif", "actb.gif");

   ActionDialog(Vector var1) {
      super(Console.getFrame(), null, Console.message("Actions"), false);
      String[] var2 = ServerTableManager.instance().getTable("hiddenActions");
      String[] var3 = ServerTableManager.instance().getTable("actionAliases");
      if (IniFile.gamma().getIniInt("HideActions", 1) == 0) {
         var2 = null;
      }

      this.names = new Vector();

      for (int var4 = 0; var4 < var1.size(); var4++) {
         boolean var5 = false;
         if (var2 != null) {
            String var6 = (String)var1.elementAt(var4);
            var6 = var6.toLowerCase();

            for (int var7 = 0; var7 < var2.length; var7++) {
               if (var6.equals(var2[var7])) {
                  var5 = true;
               }
            }
         }

         if (!var5) {
            String var10 = (String)var1.elementAt(var4);
            if (var3 != null) {
               String var11 = var10;
               var11 = var11.toLowerCase();

               for (byte var8 = 0; var8 < var3.length; var8 += 2) {
                  if (var11.equals(var3[var8])) {
                     var10 = var3[var8 + 1];
                  }
               }
            }

            this.names.addElement(upperFirst(var10));
         }
      }

      this.setResizable(false);
      this.setAlignment(2);
      this.setLayout(this.overall);
      this.ready();
   }

   protected boolean done(boolean var1) {
      ActionsPart.showDialog = false;
      lastWindowLocation = this.getLocation();
      return super.done(var1);
   }

   private static String upperFirst(String var0) {
      String var1 = var0.substring(0, 1).toUpperCase();
      if (var0.length() > 1) {
         var1 = var1 + var0.substring(1);
      }

      return var1.replace('_', ' ');
   }

   public synchronized Object imageButtonsCallback(Component var1, int var2) {
      int var3 = this.hunks.indexOf(var1);
      if (var3 == -1) {
         return null;
      }

      Console.wake();
      ActionsPart.actionToPerform = var3 * 1 + var2;
      return null;
   }

   protected void build() {
      int var1 = (this.names.size() + 1 - 1) / 1;
      int var2 = (var1 + 1) / 2;
      var1 = var2 * 2;
      Panel var3 = new Panel(new GridLayout(var2, 2));
      var3.setBackground(Color.black);
      int var4 = 0;

      for (int var5 = 0; var5 < var1; var5++) {
         String[] var6 = new String[1];

         for (int var7 = 0; var7 < 1; var4++) {
            if (var4 < this.names.size()) {
               var6[var7] = (String)this.names.elementAt(var4);
            }

            var7++;
         }

         TextImageButtons var9 = new TextImageButtons(buttonImageName, 72, buttonHeights, xText, var6, this);
         this.hunks.addElement(var9);
         var3.add(var9);
      }

      this.add("North", new ImageCanvas(topImageName));
      this.add("Center", var3);
      this.add("South", new ImageCanvas(bottomImageName));
   }

   protected void initialSize(int var1, int var2) {
      if (lastWindowLocation == null) {
         super.initialSize(var1, var2);
      } else {
         this.setLocation(lastWindowLocation);
         this.setSize(var1, var2);
      }
   }

   public boolean handleEvent(Event var1) {
      if (var1.id == 1004) {
         Console.getFrame().requestFocus();
         return true;
      } else {
         return super.handleEvent(var1);
      }
   }
}

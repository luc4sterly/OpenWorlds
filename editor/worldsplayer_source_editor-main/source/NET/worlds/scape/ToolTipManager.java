package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.console.MultiLineLabel;
import NET.worlds.core.IniFile;
import java.awt.Color;
import java.awt.Font;
import java.awt.Window;

public class ToolTipManager {
   private static ToolTipManager manager_ = null;
   private static final int FRAME_DELAY = 15;
   private int savedX;
   private int savedY;
   private int savedLoops;
   private boolean toolTipActive;
   private WObject savedObject;
   private Window toolTipWindow;
   private MultiLineLabel toolTipTextArea;
   private Font toolTipFont;

   private ToolTipManager() {
      this.savedX = this.savedY = this.savedLoops = 0;
      this.toolTipActive = false;
      this.savedObject = null;
      this.toolTipFont = new Font("Arial", 0, 10);
      Console.getActive();
      this.toolTipWindow = new Window(Console.getFrame());
      this.toolTipTextArea = new MultiLineLabel();
      this.toolTipTextArea.setBackground(Color.yellow);
      this.toolTipTextArea.setForeground(Color.black);
      this.toolTipTextArea.setMarginWidth(2);
      this.toolTipTextArea.setMarginHeight(2);
      this.toolTipWindow.setFont(this.toolTipFont);
      this.toolTipWindow.add(this.toolTipTextArea);
   }

   public static ToolTipManager toolTipManager() {
      if (manager_ == null) {
         manager_ = new ToolTipManager();
      }

      return manager_;
   }

   public void heartbeat() {
      if (IniFile.gamma().getIniInt("DisableToolTips", 0) != 1) {
         WObject var1 = Camera.getMousePickWObject();
         int var2 = (int)Camera.getMousePickX();
         int var3 = (int)Camera.getMousePickY();
         if (var1 != null && var2 > 0 && var3 > 0 && var2 == this.savedX && var3 == this.savedY && this.savedObject == var1) {
            this.savedLoops++;
         } else {
            if (this.toolTipActive) {
               this.removeToolTip();
               this.toolTipActive = false;
            }

            this.savedLoops = 0;
         }

         if (!this.toolTipActive && var1 != null && this.savedLoops > 15) {
            this.toolTipActive = true;
            if (var1 != null) {
               this.savedObject = var1;
               if (var1.getToolTipText() != null) {
                  String var4 = var1.getToolTipText();
                  String var5 = var4.replace('|', '\n');
                  this.createToolTip(this.savedX, this.savedY, var5);
               }
            }
         }

         this.savedX = var2;
         this.savedY = var3;
         this.savedObject = var1;
      }
   }

   void createToolTip(int var1, int var2, String var3) {
      int var4 = ((DefaultConsole)Console.getActive()).getRender().getLocationOnScreen().x;
      int var5 = ((DefaultConsole)Console.getActive()).getRender().getLocationOnScreen().y;
      byte var6 = 16;
      byte var7 = 16;
      this.toolTipWindow.setLocation(var1 + var4 + var6, var2 + var5 + var7);
      this.toolTipTextArea.setLabel(var3);
      this.toolTipWindow.setSize(this.toolTipTextArea.preferredSize());
      this.toolTipWindow.setEnabled(false);
      this.toolTipWindow.show();
   }

   public void removeToolTip() {
      this.toolTipWindow.hide();
   }

   public void killToolTip() {
      this.savedLoops = 0;
      this.toolTipWindow.hide();
   }
}

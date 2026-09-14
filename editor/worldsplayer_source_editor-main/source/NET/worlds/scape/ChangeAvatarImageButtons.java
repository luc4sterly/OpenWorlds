package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.ImageButtons;
import NET.worlds.console.ImageButtonsCallback;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Rectangle;

class ChangeAvatarImageButtons extends ImageButtons {
   private static final int textBoxX = 0;
   private static final int textBoxY = 0;
   private static final int textBoxW = 177;
   private static final int textBoxH = 23;
   private static Font font = new Font(Console.message("AvatarFont"), 0, 12);
   private static int textWidth;
   private static int textX;
   private static int textY;
   private String text;

   public ChangeAvatarImageButtons(String var1, Rectangle[] var2, ImageButtonsCallback var3, String var4) {
      super(var1, var2, var3);
      this.text = var4;
   }

   public void paint(Graphics var1) {
      super.paint(var1);
      var1.setFont(font);
      var1.setColor(Color.white);
      if (textWidth == 0) {
         FontMetrics var2 = var1.getFontMetrics();
         textWidth = var2.stringWidth(this.text);
         textX = (177 - textWidth) / 2;
         textY = 23 - (23 - var2.getAscent()) / 2;
      }

      var1.drawString(this.text, textX, textY);
   }
}

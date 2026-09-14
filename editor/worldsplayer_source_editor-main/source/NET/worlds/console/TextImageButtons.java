package NET.worlds.console;

import NET.worlds.core.Debug;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Toolkit;

class TextImageButtons extends ImageButtons {
   private int buttonCount;
   private int[] xText;
   private String[] texts;
   private int[] buttonBottoms;
   private Font font;
   private static Font defFont = new Font(Console.message("ButtonFont"), 0, 9);
   private static final int yBaseline = 4;

   public static Dimension measure(String var0, Font var1) {
      Dimension var2 = new Dimension();
      FontMetrics var3 = Toolkit.getDefaultToolkit().getFontMetrics(var1);
      var2.width = var3.stringWidth(var0);
      var2.height = var3.getHeight();
      return var2;
   }

   public TextImageButtons(String var1, int var2, int[] var3, int[] var4, String[] var5, ImageButtonsCallback var6) {
      this(var1, var2, var3, var4, var5, var6, defFont);
   }

   public TextImageButtons(String var1, int var2, int[] var3, int[] var4, String[] var5, ImageButtonsCallback var6, Font var7) {
      super(var1, var2, var3, var6);
      this.xText = var4;
      this.texts = var5;
      this.buttonCount = var3.length;
      this.font = var7;
      this.buttonBottoms = new int[this.buttonCount];
      int var8 = 0;

      for (int var9 = 0; var9 < this.buttonCount; var9++) {
         var8 += var3[var9];
         this.buttonBottoms[var9] = var8;
      }
   }

   public void setTexts(String[] var1) {
      Debug.assert_(var1.length == this.texts.length);
      this.texts = var1;
      this.repaint();
   }

   public String getText(int var1) {
      return this.texts[var1];
   }

   protected Graphics drawButton(Graphics var1, int var2, int var3) {
      return this.drawButton(var1, var2, var3, Color.white);
   }

   protected Graphics drawButton(Graphics var1, int var2, int var3, Color var4) {
      if (var2 >= 0 && var2 < this.buttonCount && this.texts[var2] != null) {
         var1 = super.drawButton(var1, var2, var3);
         if (var1 != null || (var1 = this.getGraphics()) != null) {
            var1.setColor(var4);
            var1.setFont(this.font);
            var1.drawString(this.texts[var2], this.xText[var2], this.buttonBottoms[var2] - 4);
         }
      } else {
         var1 = super.drawButton(var1, var2, 0);
      }

      return var1;
   }
}

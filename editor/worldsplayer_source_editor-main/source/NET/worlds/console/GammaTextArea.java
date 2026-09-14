package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import java.awt.Color;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Panel;
import java.awt.Scrollbar;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.FocusEvent;
import java.awt.event.KeyEvent;
import java.util.StringTokenizer;
import java.util.Vector;

public class GammaTextArea extends Panel implements AdjustmentListener {
   public static final int SCROLLBARS_BOTH = 1;
   public static final int SCROLLBARS_VERTICAL_ONLY = 2;
   public static final int SCROLLBARS_HORIZONTAL_ONLY = 3;
   public static final int SCROLLBARS_NONE = 4;
   protected static final int _margin = 2;
   private int _width;
   private int _height;
   private StyledTextCanvas _canvas;
   private String _string;
   private Font _font;
   private int _currentStyle;
   private String _currentFontName;
   private int _currentPointSize;
   private Color _currentColor;
   private GammaTextScrollbar _vertBar;
   private GammaTextScrollbar _horzBar;
   private int _numLines;
   private int _canvasLines;
   private int _scrollLine;
   private Vector _lines;
   private boolean _hasFocus;
   public static String boldStartTag = "<b>";
   public static String boldEndTag = "</b>";
   public static String italicStartTag = "<i>";
   public static String italicEndTag = "</i>";
   public static String colorStartMagentaTag = "<color=\"#FF00FF\">";
   public static String colorStartBlueTag = "<color=\"#0000FF\">";
   public static String colorStartRedTag = "<color=\"#FF0000\">";
   public static String colorStartGreenTag = "<color=\"#00FF00\">";
   public static String colorEndTag = "</color>";
   public static String colorMagenta2Tag = "<color=magenta>";
   public static String colorBlue2Tag = "<color=blue>";
   public static String colorRed2Tag = "<color=red>";
   public static String colorGreen2Tag = "<color=green>";
   public static String colorCyanTag = "<color=cyan>";
   public static String colorDarkGrayTag = "<color=darkgray>";
   public static String colorGrayTag = "<color=gray>";
   public static String colorOrangeTag = "<color=orange>";
   public static String colorPinkTag = "<color=pink>";
   public static String colorYellowTag = "<color=yellow>";
   public static String colorWhiteTag = "<color=white>";
   public static String colorLightGrayTag = "<color=lightgray>";
   protected static String[] tagList = new String[]{
      boldStartTag,
      boldEndTag,
      italicStartTag,
      italicEndTag,
      colorStartMagentaTag,
      colorStartRedTag,
      colorStartGreenTag,
      colorStartBlueTag,
      colorEndTag,
      colorMagenta2Tag,
      colorBlue2Tag,
      colorRed2Tag,
      colorGreen2Tag,
      colorCyanTag,
      colorDarkGrayTag,
      colorGrayTag,
      colorOrangeTag,
      colorPinkTag,
      colorYellowTag,
      colorWhiteTag,
      colorLightGrayTag
   };

   public Font getFont() {
      return this._font;
   }

   public int getWidth() {
      return this._width;
   }

   public int getHeight() {
      return this._height;
   }

   public void setWidth(int var1) {
      this._width = var1 - 4;
   }

   public void setHeight(int var1) {
      this._height = var1 - 4;
   }

   public Vector getLines() {
      return this._lines;
   }

   public int getScrollLine() {
      return this._scrollLine;
   }

   public int getCanvasLines() {
      return this._canvasLines;
   }

   public int getNumLines() {
      return this._numLines;
   }

   public boolean getHasFocus() {
      return this._hasFocus;
   }

   public Scrollbar getVertScrollbar() {
      return this._vertBar;
   }

   static Color getBackgroundColor() {
      int var0 = IniFile.override().getIniInt("chatBgR", 255);
      int var1 = IniFile.override().getIniInt("chatBgG", 255);
      int var2 = IniFile.override().getIniInt("chatBgB", 203);
      return new Color(var0, var1, var2);
   }

   GammaTextArea(String var1, int var2, int var3, int var4) {
      this._string = var1;
      this._currentFontName = Console.message("GammaTextFont");
      this._currentStyle = 0;
      this._currentPointSize = 12;
      this._currentColor = Color.black;
      this._font = new Font(this._currentFontName, this._currentStyle, this._currentPointSize);
      this._canvas = new StyledTextCanvas();
      FontMetrics var5 = this._canvas.getFontMetrics(this._font);
      Debug.dAssert(var5 != null);
      int var6 = var5.getHeight();
      int var7 = var5.charWidth('M') * var3;
      int var8 = var5.getHeight() * var2;
      this._canvas.setSize(var7, var8);
      this.setWidth(var7);
      this.setHeight(var8);
      this._lines = new Vector();
      this._hasFocus = false;
      this._numLines = this._scrollLine = this._canvasLines = 0;
      switch (var4) {
         case 1:
            this._vertBar = new GammaTextScrollbar(1);
            this._horzBar = new GammaTextScrollbar(0);
            break;
         case 2:
            this._vertBar = new GammaTextScrollbar(1);
            this._horzBar = null;
            break;
         case 3:
            this._vertBar = null;
            this._horzBar = new GammaTextScrollbar(0);
            break;
         case 4:
            this._vertBar = this._horzBar = null;
      }

      GridBagLayout var9 = new GridBagLayout();
      this.setLayout(var9);
      GridBagConstraints var10 = new GridBagConstraints();
      var10.fill = 1;
      var10.weightx = 1.0;
      var10.weighty = 1.0;
      var9.setConstraints(this._canvas, var10);
      this.add(this._canvas);
      if (this._vertBar != null) {
         var10 = new GridBagConstraints();
         var10.fill = 3;
         var10.gridwidth = 0;
         var9.setConstraints(this._vertBar, var10);
         this.add(this._vertBar);
         this._vertBar.addAdjustmentListener(this);
      }

      if (this._horzBar != null) {
         var10 = new GridBagConstraints();
         var10.fill = 2;
         var10.gridwidth = 1;
         this.add(this._horzBar);
         this._horzBar.addAdjustmentListener(this);
      }

      this.enableEvents(31L);
      this._canvas.repaint();
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   protected void processFocusEvent(FocusEvent var1) {
      if (var1.getID() == 1004) {
         this._hasFocus = true;
      } else if (var1.getID() == 1005) {
         this._hasFocus = false;
      }

      this._canvas.repaint();
      super.processFocusEvent(var1);
   }

   protected void processKeyEvent(KeyEvent var1) {
      this._canvas.dispatchEvent(var1);
      super.processKeyEvent(var1);
   }

   public void adjustmentValueChanged(AdjustmentEvent var1) {
      this._scrollLine = this._vertBar.getValue();
      this._canvas.repaint();
   }

   public void setEditable(boolean var1) {
      if (var1) {
         System.out.println("Can't set GammaTextArea to be editable.");
      }
   }

   public synchronized String getText() {
      return this._string;
   }

   public synchronized void setText(String var1) {
      this._string = var1;
      this.wordWrapAll();
      this._scrollLine = this._numLines - this._canvasLines;
      if (this._scrollLine < 0) {
         this._scrollLine = 0;
      }

      this.setScrollBounds();
   }

   public void repaint() {
      this._canvas.repaint();
      super.repaint();
   }

   protected synchronized void wordWrapAll() {
      this._lines.removeAllElements();
      this._numLines = 0;
      this.wordWrap(this._string);
   }

   protected boolean isLastLineVisible() {
      return this._scrollLine == this._numLines - this._canvasLines || this._numLines <= this._canvasLines;
   }

   protected boolean handleTag(String var1) {
      if (var1.charAt(0) != '<') {
         return false;
      }

      for (int var2 = 0; var2 < tagList.length; var2++) {
         if (var1.equals(tagList[var2])) {
            switch (var2) {
               case 0:
                  this._currentStyle |= 1;
                  break;
               case 1:
                  this._currentStyle &= -2;
                  break;
               case 2:
                  this._currentStyle |= 2;
                  break;
               case 3:
                  this._currentStyle &= -3;
                  break;
               case 4:
                  this._currentColor = Color.magenta;
                  break;
               case 5:
                  this._currentColor = Color.red;
                  break;
               case 6:
                  this._currentColor = Color.green;
                  break;
               case 7:
                  this._currentColor = Color.blue;
                  break;
               case 8:
                  this._currentColor = Color.black;
                  break;
               case 9:
                  this._currentColor = Color.magenta;
                  break;
               case 10:
                  this._currentColor = Color.blue;
                  break;
               case 11:
                  this._currentColor = Color.red;
                  break;
               case 12:
                  this._currentColor = Color.green;
                  break;
               case 13:
                  this._currentColor = Color.cyan;
                  break;
               case 14:
                  this._currentColor = Color.darkGray;
                  break;
               case 15:
                  this._currentColor = Color.gray;
                  break;
               case 16:
                  this._currentColor = Color.orange;
                  break;
               case 17:
                  this._currentColor = Color.pink;
                  break;
               case 18:
                  this._currentColor = Color.yellow;
                  break;
               case 19:
                  this._currentColor = Color.white;
                  break;
               case 20:
                  this._currentColor = Color.lightGray;
            }

            try {
               this._font = new Font(this._currentFontName, this._currentStyle, this._currentPointSize);
            } catch (IllegalArgumentException var4) {
            }

            return true;
         }
      }

      return false;
   }

   protected void ClearTags(Graphics var1) {
      if (this._currentStyle != 0) {
         this._currentStyle = 0;
         this._font = new Font(this._currentFontName, this._currentStyle, this._currentPointSize);
      }

      if (this._currentColor != Color.black) {
         this._currentColor = Color.black;
      }

      var1.setFont(this._font);
      var1.setColor(this._currentColor);
   }

   protected synchronized void wordWrap(String var1) {
      int var2 = this._width;
      if (var2 > 0) {
         StringTokenizer var3 = new StringTokenizer(var1, "\n\r");

         while (var3.hasMoreTokens()) {
            String var4 = var3.nextToken();
            StringTokenizer var5 = new StringTokenizer(var4, "\n\r\t -", true);
            int var6 = 0;
            String var7 = "";
            int var8 = 0;
            FontMetrics var9 = this._canvas.getFontMetrics(this._font);
            Debug.dAssert(var9 != null);

            while (var5.hasMoreTokens()) {
               String var10 = var5.nextToken();
               if (!var10.equals("\n") && !var10.equals("\r")) {
                  if (this.handleTag(var10)) {
                     var6 -= var8;
                     var7 = var7 + var10;
                     if (var5.hasMoreTokens()) {
                        var7 = var7 + var5.nextToken();
                     }

                     var8 = 0;
                     var9 = this._canvas.getFontMetrics(this._font);
                     Debug.dAssert(var9 != null);
                  } else {
                     var8 = var9.stringWidth(var10);
                     if (var8 >= var2) {
                        if (!var7.equals("")) {
                           this._lines.addElement(var7.trim());
                           this._numLines++;
                           var6 = 0;
                        }

                        while (var8 >= var2) {
                           var10 = this.breakWord(var10, var9);
                           var6 = 0;
                           var7 = "";
                           var8 = var9.stringWidth(var10);
                        }
                     }

                     var6 += var8;
                     if (var6 >= var2) {
                        this._lines.addElement(var7.trim());
                        this._numLines++;
                        var6 = var8;
                        var7 = "";
                     }

                     var7 = var7 + var10;
                  }
               }
            }

            if (!var7.equals("")) {
               this._numLines++;
               this._lines.addElement(var7.trim());
            }
         }
      }
   }

   protected String breakWord(String var1, FontMetrics var2) {
      int var3 = 0;
      String var4 = "";

      for (int var5 = 0; var5 < var1.length(); var5++) {
         char var6 = var1.charAt(var5);
         var3 += var2.charWidth(var6);
         if (var3 >= this._width) {
            this._lines.addElement(var4);
            this._numLines++;
            return var1.substring(var5);
         }

         var4 = var4 + var6;
      }

      this._lines.addElement(var4);
      this._numLines++;
      return "";
   }

   public synchronized void rewrap() {
      if (this._width > 0 && this._height > 0) {
         this.wordWrapAll();
         this._scrollLine = this._numLines - this._canvasLines;
         if (this._scrollLine < 0) {
            this._scrollLine = 0;
         }

         this.setScrollBounds();
         this._canvas.repaint();
      }
   }

   private void setScrollBounds() {
      FontMetrics var1 = this._canvas.getFontMetrics(this._font);
      Debug.dAssert(var1 != null);
      int var2 = var1.getHeight();
      this._canvasLines = this._height / var2;
      if (this._vertBar != null) {
         if (this._numLines <= this._canvasLines) {
            this._vertBar.setEnabled(false);
         } else {
            this._vertBar.setEnabled(true);
            this._vertBar.setValues(this._scrollLine, this._canvasLines, 0, this._numLines);
            this._vertBar.setBlockIncrement(this._canvasLines);
         }
      }
   }

   public void append(String var1) {
      this._string = this._string + var1;
      this.wordWrap(var1);
      this._scrollLine = this._numLines - this._canvasLines;
      if (this._scrollLine < 0) {
         this._scrollLine = 0;
      }

      this.setScrollBounds();
   }

   public void replaceRange(String var1, int var2, int var3) {
      String var4 = this._string.substring(0, var2) + var1 + this._string.substring(var3);
      this._string = var4;
   }

   public void drawLine(Graphics var1, int var2, int var3) {
      String var4 = (String)this._lines.elementAt(var2);
      Debug.dAssert(var4 != null);
      StringTokenizer var5 = new StringTokenizer(var4, " \n\r", true);
      int var6 = 0;
      int var7 = 0;

      while (var5.hasMoreTokens()) {
         String var8 = var5.nextToken();
         if (!this.handleTag(var8)) {
            var1.drawString(var8, 2 + var6, var3 + 2);
            var7 = var1.getFontMetrics().stringWidth(var8);
            var6 += var7;
         } else {
            var6 -= var7;
            if (var5.hasMoreTokens()) {
               var5.nextToken();
            }

            var7 = 0;
            var1.setFont(this._font);
            var1.setColor(this._currentColor);
         }
      }

      this.ClearTags(var1);
   }
}

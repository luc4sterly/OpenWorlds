package java.awt;

import java.awt.font.FontRenderContext;
import java.awt.font.GlyphVector;
import java.awt.font.LineMetrics;
import java.awt.geom.AffineTransform;
import java.util.Locale;

import net.openworlds.awt.FontFace;
import net.openworlds.awt.Fonts;

/** A font, as java.awt.Font; drawn with {@link net.openworlds.awt.Fonts}. */
public class Font implements java.io.Serializable {
   public static final String DIALOG = "Dialog";
   public static final String DIALOG_INPUT = "DialogInput";
   public static final String SANS_SERIF = "SansSerif";
   public static final String SERIF = "Serif";
   public static final String MONOSPACED = "Monospaced";
   public static final int PLAIN = 0;
   public static final int BOLD = 1;
   public static final int ITALIC = 2;
   public static final int ROMAN_BASELINE = 0;
   public static final int CENTER_BASELINE = 1;
   public static final int HANGING_BASELINE = 2;
   public static final int TRUETYPE_FONT = 0;
   public static final int TYPE1_FONT = 1;
   public static final int LAYOUT_LEFT_TO_RIGHT = 0;
   public static final int LAYOUT_RIGHT_TO_LEFT = 1;
   public static final int LAYOUT_NO_START_CONTEXT = 2;
   public static final int LAYOUT_NO_LIMIT_CONTEXT = 4;

   protected String name;
   protected int style;
   protected int size;
   protected float pointSize;
   private transient FontFace face;

   public Font(String name, int style, int size) {
      this.name = name != null ? name : "Default";
      this.style = (style & ~0x03) == 0 ? style : 0;
      this.size = size;
      this.pointSize = size;
   }

   private Font(String name, int style, float sizePts) {
      this.name = name != null ? name : "Default";
      this.style = (style & ~0x03) == 0 ? style : 0;
      this.size = (int) (sizePts + 0.5);
      this.pointSize = sizePts;
   }

   protected Font(Font font) {
      this(font.name, font.style, font.pointSize);
   }

   FontFace face() {
      FontFace f = face;
      if (f == null) {
         f = Fonts.face(name, style, pointSize);
         face = f;
      }
      return f;
   }

   public String getName() {
      return name;
   }

   public String getFontName() {
      return getFontName(Locale.getDefault());
   }

   public String getFontName(Locale l) {
      String fam = getFamily();
      switch (style) {
         case BOLD:
            return fam + " Bold";
         case ITALIC:
            return fam + " Italic";
         case BOLD | ITALIC:
            return fam + " Bold Italic";
         default:
            return fam;
      }
   }

   public String getFamily() {
      return getFamily(Locale.getDefault());
   }

   public String getFamily(Locale l) {
      String n = name.toLowerCase(Locale.ROOT);
      if (n.equals("dialog") || n.equals("dialoginput") || n.equals("sansserif") || n.equals("serif") || n.equals("monospaced")) {
         return name;
      }
      return Fonts.familyName(name);
   }

   public String getPSName() {
      return getFontName().replace(' ', '-');
   }

   public int getStyle() {
      return style;
   }

   public int getSize() {
      return size;
   }

   public float getSize2D() {
      return pointSize;
   }

   public boolean isPlain() {
      return style == 0;
   }

   public boolean isBold() {
      return (style & BOLD) != 0;
   }

   public boolean isItalic() {
      return (style & ITALIC) != 0;
   }

   public boolean isTransformed() {
      return false;
   }

   public AffineTransform getTransform() {
      return new AffineTransform();
   }

   public Font deriveFont(int style, float size) {
      return new Font(name, style, size);
   }

   public Font deriveFont(float size) {
      return new Font(name, style, size);
   }

   public Font deriveFont(int style) {
      return new Font(name, style, pointSize);
   }

   public Font deriveFont(AffineTransform trans) {
      return this;
   }

   public Font deriveFont(int style, AffineTransform trans) {
      return deriveFont(style);
   }

   public boolean canDisplay(char c) {
      return true;
   }

   public int canDisplayUpTo(String str) {
      return -1;
   }

   public int getNumGlyphs() {
      return 65535;
   }

   public int getMissingGlyphCode() {
      return 0;
   }

   public LineMetrics getLineMetrics(String str, FontRenderContext frc) {
      FontFace f = face();
      return new LineMetrics(f.ascentF, f.descentF, f.leadingF, str == null ? 0 : str.length());
   }

   public LineMetrics getLineMetrics(String str, int beginIndex, int limit, FontRenderContext frc) {
      return getLineMetrics(str.substring(beginIndex, limit), frc);
   }

   public LineMetrics getLineMetrics(char[] chars, int beginIndex, int limit, FontRenderContext frc) {
      return getLineMetrics(new String(chars, beginIndex, limit - beginIndex), frc);
   }

   public java.awt.geom.Rectangle2D getStringBounds(String str, FontRenderContext frc) {
      FontFace f = face();
      return new java.awt.geom.Rectangle2D.Float(0, -f.ascentF, f.stringWidth(str), f.ascentF + f.descentF + f.leadingF);
   }

   public java.awt.geom.Rectangle2D getMaxCharBounds(FontRenderContext frc) {
      FontFace f = face();
      return new java.awt.geom.Rectangle2D.Float(0, -f.ascentF, pointSize, f.ascentF + f.descentF + f.leadingF);
   }

   public GlyphVector createGlyphVector(FontRenderContext frc, String str) {
      return new GlyphVector(this, frc, str);
   }

   public GlyphVector createGlyphVector(FontRenderContext frc, char[] chars) {
      return new GlyphVector(this, frc, new String(chars));
   }

   public static Font decode(String str) {
      String fontName = str;
      int fontSize = 12;
      int fontStyle = PLAIN;
      if (str == null) {
         return new Font(DIALOG, fontStyle, fontSize);
      }
      int lastHyphen = str.lastIndexOf('-');
      int lastSpace = str.lastIndexOf(' ');
      char sepChar = (lastHyphen > lastSpace) ? '-' : ' ';
      int sizeIndex = str.lastIndexOf(sepChar);
      int styleIndex = str.lastIndexOf(sepChar, sizeIndex - 1);
      int strlen = str.length();
      if (sizeIndex > 0 && sizeIndex + 1 < strlen) {
         try {
            fontSize = Integer.valueOf(str.substring(sizeIndex + 1)).intValue();
            if (fontSize <= 0) {
               fontSize = 12;
            }
         } catch (NumberFormatException e) {
            styleIndex = sizeIndex;
            sizeIndex = strlen;
            if (str.charAt(sizeIndex - 1) == sepChar) {
               sizeIndex--;
            }
         }
      }
      if (styleIndex >= 0 && styleIndex + 1 < strlen) {
         String styleName = str.substring(styleIndex + 1, sizeIndex).toLowerCase(Locale.ENGLISH);
         if (styleName.equals("bolditalic")) {
            fontStyle = BOLD | ITALIC;
         } else if (styleName.equals("italic")) {
            fontStyle = ITALIC;
         } else if (styleName.equals("bold")) {
            fontStyle = BOLD;
         } else if (styleName.equals("plain")) {
            fontStyle = PLAIN;
         } else {
            styleIndex = sizeIndex;
            if (str.charAt(styleIndex - 1) == sepChar) {
               styleIndex--;
            }
         }
         fontName = str.substring(0, styleIndex);
      } else {
         int fontEnd = strlen;
         if (styleIndex > 0) {
            fontEnd = styleIndex;
         } else if (sizeIndex > 0) {
            fontEnd = sizeIndex;
         }
         if (fontEnd > 0 && str.charAt(fontEnd - 1) == sepChar) {
            fontEnd--;
         }
         fontName = str.substring(0, fontEnd);
      }
      return new Font(fontName, fontStyle, fontSize);
   }

   public static Font getFont(String nm) {
      return getFont(nm, null);
   }

   public static Font getFont(String nm, Font font) {
      String str = System.getProperty(nm);
      return str == null ? font : decode(str);
   }

   public int hashCode() {
      return name.hashCode() ^ style ^ size;
   }

   public boolean equals(Object obj) {
      if (obj == this) {
         return true;
      }
      if (!(obj instanceof Font)) {
         return false;
      }
      Font f = (Font) obj;
      return size == f.size && style == f.style && pointSize == f.pointSize && name.equals(f.name);
   }

   public String toString() {
      String strStyle;
      if (isBold()) {
         strStyle = isItalic() ? "bolditalic" : "bold";
      } else {
         strStyle = isItalic() ? "italic" : "plain";
      }
      return getClass().getName() + "[family=" + getFamily() + ",name=" + name + ",style=" + strStyle + ",size=" + size + "]";
   }
}

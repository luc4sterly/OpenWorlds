package java.awt;

import java.awt.font.FontRenderContext;
import java.awt.font.LineMetrics;
import java.util.HashMap;

import net.openworlds.awt.FontFace;

/** The metrics of a font, as java.awt.FontMetrics (Java2D's integer ones). */
public class FontMetrics implements java.io.Serializable {
   private static final HashMap<Font, FontMetrics> cache = new HashMap<Font, FontMetrics>();

   protected Font font;
   private transient FontFace face;

   protected FontMetrics(Font font) {
      this.font = font;
   }

   static FontMetrics of(Font font) {
      if (font == null) {
         font = Theme.DIALOG_FONT;
      }
      synchronized (cache) {
         FontMetrics fm = cache.get(font);
         if (fm == null) {
            fm = new FontMetrics(font);
            cache.put(font, fm);
         }
         return fm;
      }
   }

   private FontFace face() {
      FontFace f = face;
      if (f == null) {
         f = font.face();
         face = f;
      }
      return f;
   }

   public Font getFont() {
      return font;
   }

   public FontRenderContext getFontRenderContext() {
      return new FontRenderContext(null, false, false);
   }

   public int getLeading() {
      return face().leading;
   }

   public int getAscent() {
      return face().ascent;
   }

   public int getDescent() {
      return face().descent;
   }

   public int getHeight() {
      return getLeading() + getAscent() + getDescent();
   }

   public int getMaxAscent() {
      return getAscent();
   }

   public int getMaxDescent() {
      return getDescent();
   }

   public int getMaxDecent() {
      return getMaxDescent();
   }

   public int getMaxAdvance() {
      return charWidth('W');
   }

   public int charWidth(int codePoint) {
      return charWidth((char) codePoint);
   }

   public int charWidth(char ch) {
      return face().advance(ch);
   }

   public int stringWidth(String str) {
      return face().stringWidth(str);
   }

   public int charsWidth(char[] data, int off, int len) {
      int w = 0;
      FontFace f = face();
      for (int i = off; i < off + len; i++) {
         w += f.advance(data[i]);
      }
      return w;
   }

   public int bytesWidth(byte[] data, int off, int len) {
      int w = 0;
      FontFace f = face();
      for (int i = off; i < off + len; i++) {
         w += f.advance((char) (data[i] & 0xFF));
      }
      return w;
   }

   public int[] getWidths() {
      int[] widths = new int[256];
      for (char ch = 0; ch < 256; ch++) {
         widths[ch] = charWidth(ch);
      }
      return widths;
   }

   public boolean hasUniformLineMetrics() {
      return true;
   }

   public LineMetrics getLineMetrics(String str, Graphics context) {
      return font.getLineMetrics(str, null);
   }

   public java.awt.geom.Rectangle2D getStringBounds(String str, Graphics context) {
      return font.getStringBounds(str, null);
   }

   public String toString() {
      return getClass().getName() + "[font=" + getFont() + "ascent=" + getAscent() + ", descent=" + getDescent() + ", height=" + getHeight() + "]";
   }
}

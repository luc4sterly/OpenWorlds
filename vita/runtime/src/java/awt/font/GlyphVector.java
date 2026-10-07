package java.awt.font;

import java.awt.Font;
import java.awt.Shape;

import net.openworlds.awt.Fonts;

/** Some text in one font, as java.awt.font.GlyphVector: its outline, to fill or draw. */
public class GlyphVector implements Cloneable {
   private final Font font;
   private final FontRenderContext frc;
   private final String text;

   public GlyphVector(Font font, FontRenderContext frc, String text) {
      this.font = font;
      this.frc = frc;
      this.text = text;
   }

   public Font getFont() {
      return font;
   }

   public FontRenderContext getFontRenderContext() {
      return frc;
   }

   public int getNumGlyphs() {
      return text.length();
   }

   public Shape getOutline() {
      return getOutline(0, 0);
   }

   public Shape getOutline(float x, float y) {
      return Fonts.face(font.getName(), font.getStyle(), font.getSize2D()).outline(text, x, y);
   }

   public java.awt.geom.Rectangle2D getLogicalBounds() {
      return font.getStringBounds(text, frc);
   }

   public java.awt.geom.Rectangle2D getVisualBounds() {
      java.awt.Rectangle r = getOutline().getBounds();
      return new java.awt.geom.Rectangle2D.Float(r.x, r.y, r.width, r.height);
   }
}

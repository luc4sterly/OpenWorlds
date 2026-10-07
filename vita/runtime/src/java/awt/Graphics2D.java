package java.awt;

import java.awt.font.FontRenderContext;
import java.util.Map;

/** The part of java.awt.Graphics2D the 2004 client uses. */
public abstract class Graphics2D extends Graphics {
   protected Graphics2D() {
   }

   public abstract void draw(Shape s);

   public abstract void fill(Shape s);

   public abstract void drawString(String str, float x, float y);

   public abstract void setRenderingHint(RenderingHints.Key hintKey, Object hintValue);

   public abstract Object getRenderingHint(RenderingHints.Key hintKey);

   public abstract void setRenderingHints(Map<?, ?> hints);

   public abstract void addRenderingHints(Map<?, ?> hints);

   public abstract RenderingHints getRenderingHints();

   public abstract void translate(double tx, double ty);

   public abstract void setBackground(Color color);

   public abstract Color getBackground();

   public abstract FontRenderContext getFontRenderContext();

   public void draw3DRect(int x, int y, int width, int height, boolean raised) {
      super.draw3DRect(x, y, width, height, raised);
   }

   public void fill3DRect(int x, int y, int width, int height, boolean raised) {
      super.fill3DRect(x, y, width, height, raised);
   }
}

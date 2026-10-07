package java.awt.font;

import java.awt.geom.AffineTransform;

public class FontRenderContext {
   private final AffineTransform tx;
   private final boolean antialiased;
   private final boolean fractionalMetrics;

   protected FontRenderContext() {
      this(null, false, false);
   }

   public FontRenderContext(AffineTransform tx, boolean isAntiAliased, boolean usesFractionalMetrics) {
      this.tx = tx;
      this.antialiased = isAntiAliased;
      this.fractionalMetrics = usesFractionalMetrics;
   }

   public AffineTransform getTransform() {
      return tx == null ? new AffineTransform() : new AffineTransform(tx);
   }

   public boolean isAntiAliased() {
      return antialiased;
   }

   public boolean usesFractionalMetrics() {
      return fractionalMetrics;
   }

   public boolean isTransformed() {
      return tx != null && !tx.isIdentity();
   }
}

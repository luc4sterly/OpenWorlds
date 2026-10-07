package java.awt.font;

/** A line's metrics, as java.awt.font.LineMetrics (exact, not rounded). */
public class LineMetrics {
   private final float ascent;
   private final float descent;
   private final float leading;
   private final int numChars;

   public LineMetrics(float ascent, float descent, float leading, int numChars) {
      this.ascent = ascent;
      this.descent = descent;
      this.leading = leading;
      this.numChars = numChars;
   }

   public int getNumChars() {
      return numChars;
   }

   public float getAscent() {
      return ascent;
   }

   public float getDescent() {
      return descent;
   }

   public float getLeading() {
      return leading;
   }

   public float getHeight() {
      return ascent + descent + leading;
   }

   public int getBaselineIndex() {
      return 0;
   }

   public float[] getBaselineOffsets() {
      return new float[]{0, (descent - ascent) / 2, -ascent};
   }

   public float getStrikethroughOffset() {
      return -ascent / 3;
   }

   public float getStrikethroughThickness() {
      return Math.max(1, ascent / 12);
   }

   public float getUnderlineOffset() {
      return descent / 3;
   }

   public float getUnderlineThickness() {
      return Math.max(1, ascent / 12);
   }
}

package net.openworlds.awt;

/** A rasterized glyph: 8-bit coverage, placed relative to the pen on the baseline. */
public final class Glyph {
   public final int width;
   public final int height;
   /** From the pen to the bitmap's left edge, and from the baseline to its top (negative: above). */
   public final int left;
   public final int top;
   public final byte[] coverage;

   public Glyph(int width, int height, int left, int top, byte[] coverage) {
      this.width = width;
      this.height = height;
      this.left = left;
      this.top = top;
      this.coverage = coverage;
   }
}

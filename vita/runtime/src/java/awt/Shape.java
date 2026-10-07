package java.awt;

/**
 * A geometric shape. Only what the 2004 client needs: its bounds and a
 * point test; Graphics2D fills it through {@link #getBounds()} and
 * {@link #contains(double, double)} unless it is one of our own shapes
 * (Rectangle, Polygon, glyph outlines), which it fills directly.
 */
public interface Shape {
   Rectangle getBounds();

   boolean contains(double x, double y);
}

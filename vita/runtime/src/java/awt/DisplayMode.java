package java.awt;

public final class DisplayMode {
   public static final int BIT_DEPTH_MULTI = -1;
   public static final int REFRESH_RATE_UNKNOWN = 0;

   private final Dimension size;
   private final int bitDepth;
   private final int refreshRate;

   public DisplayMode(int width, int height, int bitDepth, int refreshRate) {
      this.size = new Dimension(width, height);
      this.bitDepth = bitDepth;
      this.refreshRate = refreshRate;
   }

   public int getHeight() {
      return size.height;
   }

   public int getWidth() {
      return size.width;
   }

   public int getBitDepth() {
      return bitDepth;
   }

   public int getRefreshRate() {
      return refreshRate;
   }

   public boolean equals(Object o) {
      if (!(o instanceof DisplayMode)) {
         return false;
      }
      DisplayMode d = (DisplayMode) o;
      return size.equals(d.size) && bitDepth == d.bitDepth && refreshRate == d.refreshRate;
   }

   public int hashCode() {
      return size.hashCode() ^ bitDepth ^ refreshRate;
   }
}

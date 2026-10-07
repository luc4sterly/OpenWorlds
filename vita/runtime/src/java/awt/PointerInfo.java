package java.awt;

public class PointerInfo {
   private final GraphicsDevice device;
   private final Point location;

   PointerInfo(GraphicsDevice device, Point location) {
      this.device = device;
      this.location = location;
   }

   public GraphicsDevice getDevice() {
      return device;
   }

   public Point getLocation() {
      return location;
   }
}

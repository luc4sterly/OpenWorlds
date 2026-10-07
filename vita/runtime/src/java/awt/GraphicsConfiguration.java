package java.awt;

import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;

public class GraphicsConfiguration {
   private final GraphicsDevice device;

   GraphicsConfiguration(GraphicsDevice device) {
      this.device = device;
   }

   protected GraphicsConfiguration() {
      this.device = null;
   }

   public GraphicsDevice getDevice() {
      return device;
   }

   public ColorModel getColorModel() {
      return ColorModel.getRGBdefault();
   }

   public ColorModel getColorModel(int transparency) {
      return ColorModel.getRGBdefault();
   }

   public BufferedImage createCompatibleImage(int width, int height) {
      return new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
   }

   public BufferedImage createCompatibleImage(int width, int height, int transparency) {
      return new BufferedImage(width, height, transparency == Transparency.OPAQUE ? BufferedImage.TYPE_INT_RGB : BufferedImage.TYPE_INT_ARGB);
   }

   public AffineTransform getDefaultTransform() {
      return new AffineTransform();
   }

   public AffineTransform getNormalizingTransform() {
      return new AffineTransform();
   }

   public Rectangle getBounds() {
      Dimension d = WindowSystem.screenSize();
      return new Rectangle(0, 0, d.width, d.height);
   }
}

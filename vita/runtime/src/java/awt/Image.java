package java.awt;

import java.awt.image.BufferedImage;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;

/** An image, as java.awt.Image. */
public abstract class Image {
   public static final Object UndefinedProperty = new Object();
   public static final int SCALE_DEFAULT = 1;
   public static final int SCALE_FAST = 2;
   public static final int SCALE_SMOOTH = 4;
   public static final int SCALE_REPLICATE = 8;
   public static final int SCALE_AREA_AVERAGING = 16;

   protected float accelerationPriority = .5f;

   public abstract int getWidth(ImageObserver observer);

   public abstract int getHeight(ImageObserver observer);

   public abstract ImageProducer getSource();

   public abstract Graphics getGraphics();

   public abstract Object getProperty(String name, ImageObserver observer);

   public Image getScaledInstance(int width, int height, int hints) {
      BufferedImage src = pixelsOf(this, null);
      if (src == null) {
         return this;
      }
      int sw = src.getWidth();
      int sh = src.getHeight();
      if (width < 0 && height < 0) {
         return this;
      }
      if (width < 0) {
         width = Math.max(1, sw * height / sh);
      }
      if (height < 0) {
         height = Math.max(1, sh * width / sw);
      }
      BufferedImage out = new BufferedImage(Math.max(1, width), Math.max(1, height),
            src.getColorModel().hasAlpha() ? BufferedImage.TYPE_INT_ARGB : BufferedImage.TYPE_INT_RGB);
      for (int y = 0; y < out.getHeight(); y++) {
         for (int x = 0; x < out.getWidth(); x++) {
            out.setRGB(x, y, src.getRGB(x * sw / out.getWidth(), y * sh / out.getHeight()));
         }
      }
      return out;
   }

   public void flush() {
   }

   public float getAccelerationPriority() {
      return accelerationPriority;
   }

   public void setAccelerationPriority(float priority) {
      accelerationPriority = priority;
   }

   /** The pixels of any of our images (decoding it if it is a file's), or null if it cannot be had. */
   static BufferedImage pixelsOf(Image img, ImageObserver observer) {
      if (img instanceof BufferedImage) {
         return (BufferedImage) img;
      }
      if (img instanceof ToolkitImage) {
         return ((ToolkitImage) img).pixels(observer);
      }
      return null;
   }
}

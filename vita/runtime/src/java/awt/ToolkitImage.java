package java.awt;

import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.ImageConsumer;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;
import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.InputStream;
import java.net.URL;
import java.util.Hashtable;

import net.openworlds.awt.ImageDecoder;

/**
 * An image from a file, a URL, bytes or a producer (Toolkit.getImage and
 * createImage). The JDK decodes these in the background; here they are
 * decoded the first time they are needed, so an observer is told
 * everything at once.
 */
final class ToolkitImage extends Image {
   static final int LOADING = 1;
   static final int ERRORED = 4;
   static final int COMPLETE = 8;

   private final String file;
   private final URL url;
   private final byte[] data;
   private final ImageProducer producer;
   private BufferedImage pixels;
   private int status;
   private Hashtable<Object, Object> properties = new Hashtable<Object, Object>();

   ToolkitImage(String file) {
      this(file, null, null, null);
   }

   ToolkitImage(URL url) {
      this(null, url, null, null);
   }

   ToolkitImage(byte[] data) {
      this(null, null, data, null);
   }

   ToolkitImage(ImageProducer producer) {
      this(null, null, null, producer);
   }

   private ToolkitImage(String file, URL url, byte[] data, ImageProducer producer) {
      this.file = file;
      this.url = url;
      this.data = data;
      this.producer = producer;
   }

   synchronized BufferedImage pixels(ImageObserver observer) {
      load();
      if (observer != null) {
         if (status == COMPLETE) {
            observer.imageUpdate(this, ImageObserver.WIDTH | ImageObserver.HEIGHT | ImageObserver.ALLBITS, 0, 0, pixels.getWidth(),
                  pixels.getHeight());
         } else {
            observer.imageUpdate(this, ImageObserver.ERROR | ImageObserver.ABORT, -1, -1, -1, -1);
         }
      }
      return pixels;
   }

   synchronized int status() {
      load();
      return status;
   }

   private void load() {
      if (status != 0) {
         return;
      }
      try {
         if (producer != null) {
            pixels = produce(producer);
         } else {
            byte[] bytes = data;
            if (bytes == null) {
               InputStream in = file != null ? new FileInputStream(file) : url.openStream();
               try {
                  bytes = readAll(in);
               } finally {
                  in.close();
               }
            }
            pixels = ImageDecoder.decode(bytes);
         }
         status = pixels != null ? COMPLETE : ERRORED;
      } catch (Exception e) {
         status = ERRORED;
      } catch (OutOfMemoryError e) {
         status = ERRORED;
      }
   }

   static byte[] readAll(InputStream in) throws java.io.IOException {
      ByteArrayOutputStream out = new ByteArrayOutputStream();
      byte[] buf = new byte[16384];
      int n;
      while ((n = in.read(buf)) > 0) {
         out.write(buf, 0, n);
      }
      return out.toByteArray();
   }

   /** Runs a producer into an ARGB image. */
   private static BufferedImage produce(ImageProducer p) {
      final BufferedImage[] img = new BufferedImage[1];
      final int[][] argb = new int[1][];
      final int[] size = new int[2];
      final boolean[] done = new boolean[1];
      ImageConsumer c = new ImageConsumer() {
         public void setDimensions(int width, int height) {
            size[0] = width;
            size[1] = height;
            argb[0] = new int[Math.max(1, width * height)];
         }

         public void setProperties(Hashtable<?, ?> props) {
         }

         public void setColorModel(ColorModel model) {
         }

         public void setHints(int hintflags) {
         }

         public void setPixels(int x, int y, int w, int h, ColorModel model, byte[] pixels, int off, int scansize) {
            for (int j = 0; j < h; j++) {
               for (int i = 0; i < w; i++) {
                  put(x + i, y + j, model.getRGB(pixels[off + j * scansize + i] & 0xFF));
               }
            }
         }

         public void setPixels(int x, int y, int w, int h, ColorModel model, int[] pixels, int off, int scansize) {
            for (int j = 0; j < h; j++) {
               for (int i = 0; i < w; i++) {
                  put(x + i, y + j, model.getRGB(pixels[off + j * scansize + i]));
               }
            }
         }

         private void put(int x, int y, int c) {
            if (argb[0] != null && x >= 0 && y >= 0 && x < size[0] && y < size[1]) {
               argb[0][y * size[0] + x] = c;
            }
         }

         public void imageComplete(int status) {
            done[0] = true;
         }
      };
      p.startProduction(c);
      if (argb[0] == null || size[0] <= 0 || size[1] <= 0) {
         return null;
      }
      img[0] = new BufferedImage(size[0], size[1], BufferedImage.TYPE_INT_ARGB);
      img[0].setRGB(0, 0, size[0], size[1], argb[0], 0, size[0]);
      return img[0];
   }

   public int getWidth(ImageObserver observer) {
      BufferedImage p = pixels(null);
      return p == null ? -1 : p.getWidth();
   }

   public int getHeight(ImageObserver observer) {
      BufferedImage p = pixels(null);
      return p == null ? -1 : p.getHeight();
   }

   public ImageProducer getSource() {
      if (producer != null) {
         return producer;
      }
      BufferedImage p = pixels(null);
      return p != null ? p.getSource() : new BufferedImage(1, 1, BufferedImage.TYPE_INT_ARGB).getSource();
   }

   public Graphics getGraphics() {
      throw new UnsupportedOperationException("getGraphics() not valid for images created with createImage(producer)");
   }

   public Object getProperty(String name, ImageObserver observer) {
      Object o = properties.get(name);
      return o == null ? UndefinedProperty : o;
   }

   public void flush() {
   }
}

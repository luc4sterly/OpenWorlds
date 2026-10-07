package java.awt.image;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GraphicsEnvironment;
import java.awt.Image;
import java.awt.Transparency;
import java.util.Hashtable;

/**
 * An image in memory, as java.awt.image.BufferedImage: the packed pixel
 * types (int ARGB/RGB/BGR, 565 and 555 shorts, indexed and gray bytes).
 * Raster data arrays are the ones the bridge writes into directly.
 */
public class BufferedImage extends Image implements RenderedImage, Transparency {
   public static final int TYPE_CUSTOM = 0;
   public static final int TYPE_INT_RGB = 1;
   public static final int TYPE_INT_ARGB = 2;
   public static final int TYPE_INT_ARGB_PRE = 3;
   public static final int TYPE_INT_BGR = 4;
   public static final int TYPE_3BYTE_BGR = 5;
   public static final int TYPE_4BYTE_ABGR = 6;
   public static final int TYPE_4BYTE_ABGR_PRE = 7;
   public static final int TYPE_USHORT_565_RGB = 8;
   public static final int TYPE_USHORT_555_RGB = 9;
   public static final int TYPE_BYTE_GRAY = 10;
   public static final int TYPE_USHORT_GRAY = 11;
   public static final int TYPE_BYTE_BINARY = 12;
   public static final int TYPE_BYTE_INDEXED = 13;

   private final int type;
   private final int width;
   private final int height;
   private final ColorModel colorModel;
   private final WritableRaster raster;
   /** For the int ARGB/RGB types: the pixels themselves, as SurfaceGraphics draws them. */
   private final int[] ints;
   private final short[] shorts;
   private final byte[] bytes;
   private final boolean argbLayout;
   private Hashtable<?, ?> properties;

   public BufferedImage(int width, int height, int imageType) {
      if (width <= 0 || height <= 0) {
         throw new IllegalArgumentException("Width (" + width + ") and height (" + height + ") cannot be <= 0");
      }
      this.type = imageType;
      this.width = width;
      this.height = height;
      int n = width * height;
      switch (imageType) {
         case TYPE_INT_RGB:
            colorModel = new DirectColorModel(24, 0x00ff0000, 0x0000ff00, 0x000000ff, 0);
            ints = new int[n];
            break;
         case TYPE_INT_ARGB:
         case TYPE_INT_ARGB_PRE:
            colorModel = ColorModel.getRGBdefault();
            ints = new int[n];
            break;
         case TYPE_INT_BGR:
            colorModel = new DirectColorModel(24, 0x000000ff, 0x0000ff00, 0x00ff0000);
            ints = new int[n];
            break;
         case TYPE_USHORT_565_RGB:
            colorModel = new DirectColorModel(16, 0xF800, 0x07E0, 0x001F);
            ints = null;
            break;
         case TYPE_USHORT_555_RGB:
            colorModel = new DirectColorModel(15, 0x7C00, 0x03E0, 0x001F);
            ints = null;
            break;
         case TYPE_BYTE_GRAY: {
            byte[] lut = new byte[256];
            for (int i = 0; i < 256; i++) {
               lut[i] = (byte) i;
            }
            colorModel = new IndexColorModel(8, 256, lut, lut, lut);
            ints = null;
            break;
         }
         case TYPE_BYTE_INDEXED:
            colorModel = defaultPalette();
            ints = null;
            break;
         case TYPE_3BYTE_BGR:
         case TYPE_4BYTE_ABGR:
         case TYPE_4BYTE_ABGR_PRE:
            // stored as ARGB ints: the byte layouts' rasters are not offered
            colorModel = imageType == TYPE_3BYTE_BGR ? new DirectColorModel(24, 0x00ff0000, 0x0000ff00, 0x000000ff, 0)
                  : ColorModel.getRGBdefault();
            ints = new int[n];
            break;
         default:
            throw new IllegalArgumentException("Unknown image type " + imageType);
      }
      DataBuffer db;
      if (ints != null) {
         db = new DataBufferInt(ints, n);
         shorts = null;
         bytes = null;
      } else if (imageType == TYPE_USHORT_565_RGB || imageType == TYPE_USHORT_555_RGB) {
         shorts = new short[n];
         bytes = null;
         db = new DataBufferUShort(shorts, n);
      } else {
         bytes = new byte[n];
         shorts = null;
         db = new DataBufferByte(bytes, n);
      }
      raster = new WritableRaster(db, width, height, colorModel.getNumComponents());
      argbLayout = ints != null && imageType != TYPE_INT_BGR;
   }

   public BufferedImage(int width, int height, int imageType, IndexColorModel cm) {
      if (width <= 0 || height <= 0) {
         throw new IllegalArgumentException("Width (" + width + ") and height (" + height + ") cannot be <= 0");
      }
      this.type = TYPE_BYTE_INDEXED;
      this.width = width;
      this.height = height;
      this.colorModel = cm;
      this.ints = null;
      this.shorts = null;
      this.bytes = new byte[width * height];
      this.raster = new WritableRaster(new DataBufferByte(bytes, bytes.length), width, height, 1);
      this.argbLayout = false;
   }

   public BufferedImage(ColorModel cm, WritableRaster raster, boolean isRasterPremultiplied, Hashtable<?, ?> properties) {
      this.type = TYPE_CUSTOM;
      this.width = raster.getWidth();
      this.height = raster.getHeight();
      this.colorModel = cm;
      this.raster = raster;
      this.properties = properties;
      DataBuffer db = raster.getDataBuffer();
      this.ints = db instanceof DataBufferInt ? ((DataBufferInt) db).getData() : null;
      this.shorts = db instanceof DataBufferUShort ? ((DataBufferUShort) db).getData() : null;
      this.bytes = db instanceof DataBufferByte ? ((DataBufferByte) db).getData() : null;
      this.argbLayout = ints != null && cm instanceof DirectColorModel && ((DirectColorModel) cm).getRedMask() == 0x00ff0000
            && ((DirectColorModel) cm).getGreenMask() == 0x0000ff00 && ((DirectColorModel) cm).getBlueMask() == 0x000000ff
            && (((DirectColorModel) cm).getAlphaMask() == 0 || ((DirectColorModel) cm).getAlphaMask() == 0xff000000);
   }

   private static IndexColorModel defaultPalette() {
      // the JDK's TYPE_BYTE_INDEXED palette: a 6x6x6 colour cube and grays
      int[] cmap = new int[256];
      int i = 0;
      for (int r = 0; r < 256; r += 51) {
         for (int g = 0; g < 256; g += 51) {
            for (int b = 0; b < 256; b += 51) {
               cmap[i++] = (r << 16) | (g << 8) | b;
            }
         }
      }
      int grayIncr = 256 / (256 - i);
      int gray = grayIncr * 3;
      for (; i < 256; i++) {
         cmap[i] = (gray << 16) | (gray << 8) | gray;
         gray += grayIncr;
      }
      return new IndexColorModel(8, 256, cmap, 0, false, -1, DataBuffer.TYPE_BYTE);
   }

   public int getType() {
      return type;
   }

   public ColorModel getColorModel() {
      return colorModel;
   }

   public WritableRaster getRaster() {
      return raster;
   }

   public WritableRaster getAlphaRaster() {
      return null;
   }

   public Raster getData() {
      return raster;
   }

   public int getWidth() {
      return width;
   }

   public int getHeight() {
      return height;
   }

   public int getWidth(ImageObserver observer) {
      return width;
   }

   public int getHeight(ImageObserver observer) {
      return height;
   }

   public int getTransparency() {
      return colorModel.getTransparency();
   }

   public boolean isAlphaPremultiplied() {
      return type == TYPE_INT_ARGB_PRE || type == TYPE_4BYTE_ABGR_PRE;
   }

   /** The pixels as 0xAARRGGBB ints when they are stored that way (for drawing), else null. */
   public int[] intPixels() {
      return argbLayout ? ints : null;
   }

   public int getRGB(int x, int y) {
      if (x < 0 || y < 0 || x >= width || y >= height) {
         throw new ArrayIndexOutOfBoundsException("Coordinate out of bounds!");
      }
      int i = y * width + x;
      if (argbLayout) {
         int p = ints[i];
         return colorModel.hasAlpha() ? p : p | 0xFF000000;
      }
      if (ints != null) {
         return colorModel.getRGB(ints[i]);
      }
      if (shorts != null) {
         return colorModel.getRGB(shorts[i] & 0xFFFF);
      }
      return colorModel.getRGB(bytes[i] & 0xFF);
   }

   public int[] getRGB(int startX, int startY, int w, int h, int[] rgbArray, int offset, int scansize) {
      if (rgbArray == null) {
         rgbArray = new int[offset + h * scansize];
      }
      for (int y = 0; y < h; y++) {
         int yoff = offset + y * scansize;
         for (int x = 0; x < w; x++) {
            rgbArray[yoff + x] = getRGB(startX + x, startY + y);
         }
      }
      return rgbArray;
   }

   public void setRGB(int x, int y, int rgb) {
      if (x < 0 || y < 0 || x >= width || y >= height) {
         throw new ArrayIndexOutOfBoundsException("Coordinate out of bounds!");
      }
      int i = y * width + x;
      if (argbLayout) {
         ints[i] = rgb;
      } else if (ints != null) {
         ints[i] = colorModel.pixelOf(rgb);
      } else if (shorts != null) {
         shorts[i] = (short) colorModel.pixelOf(rgb);
      } else {
         bytes[i] = (byte) colorModel.pixelOf(rgb);
      }
   }

   public void setRGB(int startX, int startY, int w, int h, int[] rgbArray, int offset, int scansize) {
      for (int y = 0; y < h; y++) {
         int yoff = offset + y * scansize;
         for (int x = 0; x < w; x++) {
            setRGB(startX + x, startY + y, rgbArray[yoff + x]);
         }
      }
   }

   public Graphics getGraphics() {
      return createGraphics();
   }

   public Graphics2D createGraphics() {
      return GraphicsEnvironment.getLocalGraphicsEnvironment().createGraphics(this);
   }

   public BufferedImage getSubimage(int x, int y, int w, int h) {
      BufferedImage sub = new BufferedImage(w, h, colorModel.hasAlpha() ? TYPE_INT_ARGB : TYPE_INT_RGB);
      for (int j = 0; j < h; j++) {
         for (int i = 0; i < w; i++) {
            sub.setRGB(i, j, getRGB(x + i, y + j));
         }
      }
      return sub;
   }

   public ImageProducer getSource() {
      return new ImageProducer() {
         private final java.util.ArrayList<ImageConsumer> consumers = new java.util.ArrayList<ImageConsumer>();

         public synchronized void addConsumer(ImageConsumer ic) {
            if (!consumers.contains(ic)) {
               consumers.add(ic);
            }
         }

         public synchronized boolean isConsumer(ImageConsumer ic) {
            return consumers.contains(ic);
         }

         public synchronized void removeConsumer(ImageConsumer ic) {
            consumers.remove(ic);
         }

         public void startProduction(ImageConsumer ic) {
            addConsumer(ic);
            produce(ic);
            removeConsumer(ic);
         }

         public void requestTopDownLeftRightResend(ImageConsumer ic) {
            produce(ic);
         }

         private void produce(ImageConsumer ic) {
            int[] argb = getRGB(0, 0, width, height, null, 0, width);
            ic.setDimensions(width, height);
            ic.setProperties(new Hashtable<Object, Object>());
            ic.setColorModel(ColorModel.getRGBdefault());
            ic.setHints(ImageConsumer.TOPDOWNLEFTRIGHT | ImageConsumer.COMPLETESCANLINES | ImageConsumer.SINGLEPASS
                  | ImageConsumer.SINGLEFRAME);
            ic.setPixels(0, 0, width, height, ColorModel.getRGBdefault(), argb, 0, width);
            ic.imageComplete(ImageConsumer.STATICIMAGEDONE);
         }
      };
   }

   public Object getProperty(String name, ImageObserver observer) {
      return getProperty(name);
   }

   public Object getProperty(String name) {
      if (name == null) {
         throw new NullPointerException("null property name is not allowed");
      }
      Object o = properties == null ? null : properties.get(name);
      return o == null ? UndefinedProperty : o;
   }

   public String[] getPropertyNames() {
      return null;
   }

   public void flush() {
   }

   public String toString() {
      return "BufferedImage@" + Integer.toHexString(hashCode()) + ": type = " + type + " " + colorModel + " " + raster;
   }
}

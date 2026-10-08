package javax.imageio;

import java.awt.image.BufferedImage;
import java.awt.image.RenderedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import net.openworlds.awt.ImageDecoder;
import net.openworlds.awt.PngWriter;

/**
 * javax.imageio.ImageIO as the bridge uses it (its camera and window
 * captures are written as PNG): reads what our image decoder reads (GIF,
 * PNG, JPEG, BMP) and writes PNG.
 */
public final class ImageIO {
   private ImageIO() {
   }

   public static String[] getReaderFormatNames() {
      return new String[]{"gif", "GIF", "png", "PNG", "jpg", "JPG", "jpeg", "JPEG", "bmp", "BMP"};
   }

   public static String[] getWriterFormatNames() {
      return new String[]{"png", "PNG"};
   }

   private static void check(RenderedImage im, String formatName) {
      if (im == null) {
         throw new IllegalArgumentException("im == null!");
      }
      if (formatName == null) {
         throw new IllegalArgumentException("formatName == null!");
      }
   }

   public static boolean write(RenderedImage im, String formatName, OutputStream output) throws IOException {
      check(im, formatName);
      if (output == null) {
         throw new IllegalArgumentException("output == null!");
      }
      if (!formatName.equalsIgnoreCase("png")) {
         return false;
      }
      BufferedImage b = (BufferedImage) im;
      int w = b.getWidth();
      int h = b.getHeight();
      int[] argb = b.getRGB(0, 0, w, h, null, 0, w);
      PngWriter.write(argb, w, h, b.getColorModel().hasAlpha(), output);
      return true;
   }

   public static boolean write(RenderedImage im, String formatName, File output) throws IOException {
      if (output == null) {
         throw new IllegalArgumentException("output == null!");
      }
      check(im, formatName);
      if (!formatName.equalsIgnoreCase("png")) {
         return false;
      }
      output.delete();
      OutputStream out = new FileOutputStream(output);
      try {
         return write(im, formatName, out);
      } finally {
         out.close();
      }
   }

   public static BufferedImage read(InputStream input) throws IOException {
      if (input == null) {
         throw new IllegalArgumentException("input == null!");
      }
      ByteArrayOutputStream b = new ByteArrayOutputStream();
      byte[] buf = new byte[8192];
      int n;
      while ((n = input.read(buf)) > 0) {
         b.write(buf, 0, n);
      }
      return ImageDecoder.decode(b.toByteArray());
   }

   public static BufferedImage read(File input) throws IOException {
      if (input == null) {
         throw new IllegalArgumentException("input == null!");
      }
      if (!input.canRead()) {
         throw new IOException("Can't read input file!");
      }
      InputStream in = new FileInputStream(input);
      try {
         return read(in);
      } finally {
         in.close();
      }
   }

   public static BufferedImage read(URL input) throws IOException {
      if (input == null) {
         throw new IllegalArgumentException("input == null!");
      }
      InputStream in = input.openStream();
      try {
         return read(in);
      } finally {
         in.close();
      }
   }
}

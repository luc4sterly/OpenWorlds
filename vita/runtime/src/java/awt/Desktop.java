package java.awt;

import java.io.File;
import java.io.IOException;
import java.net.URI;

/**
 * java.awt.Desktop: no system browser or file opener is offered here (the
 * client then falls back to its own handling, as on a desktop without one).
 */
public class Desktop {
   public static enum Action {
      OPEN, EDIT, PRINT, MAIL, BROWSE
   }

   private static Desktop desktop;

   private Desktop() {
   }

   public static synchronized Desktop getDesktop() {
      if (desktop == null) {
         desktop = new Desktop();
      }
      return desktop;
   }

   public static boolean isDesktopSupported() {
      return false;
   }

   public boolean isSupported(Action action) {
      return false;
   }

   public void browse(URI uri) throws IOException {
      throw new UnsupportedOperationException("no browser");
   }

   public void open(File file) throws IOException {
      throw new UnsupportedOperationException("no file opener");
   }

   public void edit(File file) throws IOException {
      throw new UnsupportedOperationException("no editor");
   }

   public void mail(URI uri) throws IOException {
      throw new UnsupportedOperationException("no mail");
   }
}

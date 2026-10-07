package java.awt;

import java.util.ArrayList;

/** Waits for images, as java.awt.MediaTracker (ours decode when asked, so waiting is decoding). */
public class MediaTracker implements java.io.Serializable {
   public static final int LOADING = 1;
   public static final int ABORTED = 2;
   public static final int ERRORED = 4;
   public static final int COMPLETE = 8;

   private final Component target;
   private final ArrayList<Image> images = new ArrayList<Image>();
   private final ArrayList<Integer> ids = new ArrayList<Integer>();

   public MediaTracker(Component comp) {
      target = comp;
   }

   public void addImage(Image image, int id) {
      addImage(image, id, -1, -1);
   }

   public synchronized void addImage(Image image, int id, int w, int h) {
      images.add(image);
      ids.add(Integer.valueOf(id));
   }

   private static int statusOf(Image img) {
      if (img instanceof ToolkitImage) {
         int s = ((ToolkitImage) img).status();
         return s == ToolkitImage.COMPLETE ? COMPLETE : ERRORED;
      }
      return img == null ? ERRORED : COMPLETE;
   }

   public boolean checkAll() {
      return checkAll(false);
   }

   public synchronized boolean checkAll(boolean load) {
      return (statusAll(load) & LOADING) == 0;
   }

   public synchronized boolean isErrorAny() {
      return (statusAll(true) & ERRORED) != 0;
   }

   public synchronized Object[] getErrorsAny() {
      ArrayList<Image> out = new ArrayList<Image>();
      for (Image img : images) {
         if (statusOf(img) == ERRORED) {
            out.add(img);
         }
      }
      return out.isEmpty() ? null : out.toArray();
   }

   public void waitForAll() throws InterruptedException {
      statusAll(true);
   }

   public boolean waitForAll(long ms) throws InterruptedException {
      statusAll(true);
      return true;
   }

   public synchronized int statusAll(boolean load) {
      int s = 0;
      for (Image img : images) {
         s |= statusOf(img);
      }
      return s;
   }

   public boolean checkID(int id) {
      return checkID(id, false);
   }

   public synchronized boolean checkID(int id, boolean load) {
      return (statusID(id, load) & LOADING) == 0;
   }

   public synchronized boolean isErrorID(int id) {
      return (statusID(id, true) & ERRORED) != 0;
   }

   public synchronized Object[] getErrorsID(int id) {
      ArrayList<Image> out = new ArrayList<Image>();
      for (int i = 0; i < images.size(); i++) {
         if (ids.get(i).intValue() == id && statusOf(images.get(i)) == ERRORED) {
            out.add(images.get(i));
         }
      }
      return out.isEmpty() ? null : out.toArray();
   }

   public void waitForID(int id) throws InterruptedException {
      statusID(id, true);
   }

   public boolean waitForID(int id, long ms) throws InterruptedException {
      statusID(id, true);
      return true;
   }

   public synchronized int statusID(int id, boolean load) {
      int s = 0;
      for (int i = 0; i < images.size(); i++) {
         if (ids.get(i).intValue() == id) {
            s |= statusOf(images.get(i));
         }
      }
      return s;
   }

   public synchronized void removeImage(Image image) {
      for (int i = images.size() - 1; i >= 0; i--) {
         if (images.get(i) == image) {
            images.remove(i);
            ids.remove(i);
         }
      }
   }

   public synchronized void removeImage(Image image, int id) {
      for (int i = images.size() - 1; i >= 0; i--) {
         if (images.get(i) == image && ids.get(i).intValue() == id) {
            images.remove(i);
            ids.remove(i);
         }
      }
   }

   public synchronized void removeImage(Image image, int id, int width, int height) {
      removeImage(image, id);
   }
}

package java.awt;

import java.awt.event.AWTEventListener;
import java.awt.event.ActionEvent;
import java.awt.event.AdjustmentEvent;
import java.awt.event.ComponentEvent;
import java.awt.event.ContainerEvent;
import java.awt.event.FocusEvent;
import java.awt.event.HierarchyEvent;
import java.awt.event.InputMethodEvent;
import java.awt.event.InvocationEvent;
import java.awt.event.ItemEvent;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.awt.event.PaintEvent;
import java.awt.event.TextEvent;
import java.awt.event.WindowEvent;
import java.awt.image.ColorModel;
import java.awt.image.ImageObserver;
import java.awt.image.ImageProducer;
import java.net.URL;
import java.util.ArrayList;
import java.util.Map;

/** The AWT toolkit, as java.awt.Toolkit: there is only one, ours. */
public class Toolkit {
   private static Toolkit toolkit;

   private final ArrayList<AWTEventListener> eventListeners = new ArrayList<AWTEventListener>();
   private final ArrayList<Long> eventMasks = new ArrayList<Long>();

   protected Toolkit() {
   }

   public static synchronized Toolkit getDefaultToolkit() {
      if (toolkit == null) {
         toolkit = new Toolkit();
      }
      return toolkit;
   }

   /** Text antialiasing, unless -Dopenworlds.textAntialiasing=false (the 2004 Windows had none). */
   static boolean textAntialiasing() {
      return !"false".equals(System.getProperty("openworlds.textAntialiasing"));
   }

   public Dimension getScreenSize() {
      return WindowSystem.screenSize();
   }

   public Insets getScreenInsets(GraphicsConfiguration gc) {
      return new Insets(0, 0, 0, 0);
   }

   public int getScreenResolution() {
      return 96;
   }

   public ColorModel getColorModel() {
      return ColorModel.getRGBdefault();
   }

   @SuppressWarnings("deprecation")
   public String[] getFontList() {
      return new String[]{Font.DIALOG, Font.SANS_SERIF, Font.SERIF, Font.MONOSPACED, Font.DIALOG_INPUT};
   }

   public FontMetrics getFontMetrics(Font font) {
      return FontMetrics.of(font);
   }

   public void sync() {
   }

   public void beep() {
   }

   public Image getImage(String filename) {
      return new ToolkitImage(filename);
   }

   public Image getImage(URL url) {
      return new ToolkitImage(url);
   }

   public Image createImage(String filename) {
      return new ToolkitImage(filename);
   }

   public Image createImage(URL url) {
      return new ToolkitImage(url);
   }

   public Image createImage(ImageProducer producer) {
      return new ToolkitImage(producer);
   }

   public Image createImage(byte[] imagedata) {
      return createImage(imagedata, 0, imagedata.length);
   }

   public Image createImage(byte[] imagedata, int imageoffset, int imagelength) {
      byte[] copy = new byte[imagelength];
      System.arraycopy(imagedata, imageoffset, copy, 0, imagelength);
      return new ToolkitImage(copy);
   }

   public boolean prepareImage(Image image, int width, int height, ImageObserver observer) {
      return Image.pixelsOf(image, observer) != null;
   }

   public int checkImage(Image image, int width, int height, ImageObserver observer) {
      if (Image.pixelsOf(image, null) != null) {
         return ImageObserver.WIDTH | ImageObserver.HEIGHT | ImageObserver.ALLBITS;
      }
      return ImageObserver.ERROR | ImageObserver.ABORT;
   }

   public EventQueue getSystemEventQueue() {
      return EventQueue.get();
   }

   public int getMenuShortcutKeyMask() {
      return Event.CTRL_MASK;
   }

   public boolean getLockingKeyState(int keyCode) {
      return false;
   }

   public void setLockingKeyState(int keyCode, boolean on) {
   }

   public Cursor createCustomCursor(Image cursor, Point hotSpot, String name) {
      return new Cursor(cursor, hotSpot, name);
   }

   public Dimension getBestCursorSize(int preferredWidth, int preferredHeight) {
      return new Dimension(32, 32);
   }

   public int getMaximumCursorColors() {
      return 256;
   }

   public void setDynamicLayout(boolean dynamic) {
   }

   public boolean isDynamicLayoutActive() {
      return false;
   }

   public final Object getDesktopProperty(String propertyName) {
      return null;
   }

   public static String getProperty(String key, String defaultValue) {
      return defaultValue;
   }

   public boolean isFrameStateSupported(int state) {
      return state == Frame.NORMAL;
   }

   public Map<java.awt.font.TextAttribute, ?> mapInputMethodHighlight(Object highlight) {
      return null;
   }

   public void addAWTEventListener(AWTEventListener listener, long eventMask) {
      if (listener == null) {
         return;
      }
      synchronized (eventListeners) {
         eventListeners.add(listener);
         eventMasks.add(Long.valueOf(eventMask));
      }
   }

   public void removeAWTEventListener(AWTEventListener listener) {
      synchronized (eventListeners) {
         int i = eventListeners.indexOf(listener);
         if (i >= 0) {
            eventListeners.remove(i);
            eventMasks.remove(i);
         }
      }
   }

   public AWTEventListener[] getAWTEventListeners() {
      synchronized (eventListeners) {
         return eventListeners.toArray(new AWTEventListener[eventListeners.size()]);
      }
   }

   void notifyAWTEventListeners(AWTEvent e) {
      AWTEventListener[] ls;
      long[] masks;
      synchronized (eventListeners) {
         if (eventListeners.isEmpty()) {
            return;
         }
         ls = eventListeners.toArray(new AWTEventListener[eventListeners.size()]);
         masks = new long[ls.length];
         for (int i = 0; i < masks.length; i++) {
            masks[i] = eventMasks.get(i).longValue();
         }
      }
      long m = maskOf(e);
      for (int i = 0; i < ls.length; i++) {
         if ((masks[i] & m) != 0) {
            ls[i].eventDispatched(e);
         }
      }
   }

   private static long maskOf(AWTEvent e) {
      int id = e.getID();
      if (e instanceof MouseEvent) {
         if (id == MouseEvent.MOUSE_MOVED || id == MouseEvent.MOUSE_DRAGGED) {
            return AWTEvent.MOUSE_MOTION_EVENT_MASK;
         }
         if (id == MouseEvent.MOUSE_WHEEL) {
            return AWTEvent.MOUSE_WHEEL_EVENT_MASK;
         }
         return AWTEvent.MOUSE_EVENT_MASK;
      }
      if (e instanceof KeyEvent) {
         return AWTEvent.KEY_EVENT_MASK;
      }
      if (e instanceof FocusEvent) {
         return AWTEvent.FOCUS_EVENT_MASK;
      }
      if (e instanceof WindowEvent) {
         if (id == WindowEvent.WINDOW_GAINED_FOCUS || id == WindowEvent.WINDOW_LOST_FOCUS) {
            return AWTEvent.WINDOW_FOCUS_EVENT_MASK;
         }
         if (id == WindowEvent.WINDOW_STATE_CHANGED) {
            return AWTEvent.WINDOW_STATE_EVENT_MASK;
         }
         return AWTEvent.WINDOW_EVENT_MASK;
      }
      if (e instanceof PaintEvent) {
         return AWTEvent.PAINT_EVENT_MASK;
      }
      if (e instanceof ContainerEvent) {
         return AWTEvent.CONTAINER_EVENT_MASK;
      }
      if (e instanceof ComponentEvent) {
         return AWTEvent.COMPONENT_EVENT_MASK;
      }
      if (e instanceof ActionEvent) {
         return AWTEvent.ACTION_EVENT_MASK;
      }
      if (e instanceof ItemEvent) {
         return AWTEvent.ITEM_EVENT_MASK;
      }
      if (e instanceof AdjustmentEvent) {
         return AWTEvent.ADJUSTMENT_EVENT_MASK;
      }
      if (e instanceof TextEvent) {
         return AWTEvent.TEXT_EVENT_MASK;
      }
      if (e instanceof InvocationEvent) {
         return AWTEvent.INVOCATION_EVENT_MASK;
      }
      if (e instanceof HierarchyEvent) {
         return id == HierarchyEvent.HIERARCHY_CHANGED ? AWTEvent.HIERARCHY_EVENT_MASK : AWTEvent.HIERARCHY_BOUNDS_EVENT_MASK;
      }
      if (e instanceof InputMethodEvent) {
         return AWTEvent.INPUT_METHOD_EVENT_MASK;
      }
      return 0;
   }
}

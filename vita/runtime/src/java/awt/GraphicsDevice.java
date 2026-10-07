package java.awt;

/** The screen, as java.awt.GraphicsDevice. */
public class GraphicsDevice {
   public static final int TYPE_RASTER_SCREEN = 0;
   public static final int TYPE_PRINTER = 1;
   public static final int TYPE_IMAGE_BUFFER = 2;

   private final GraphicsConfiguration config = new GraphicsConfiguration(this);
   private Window fullScreen;

   protected GraphicsDevice() {
   }

   public int getType() {
      return TYPE_RASTER_SCREEN;
   }

   public String getIDstring() {
      return "screen0";
   }

   public GraphicsConfiguration[] getConfigurations() {
      return new GraphicsConfiguration[]{config};
   }

   public GraphicsConfiguration getDefaultConfiguration() {
      return config;
   }

   public DisplayMode getDisplayMode() {
      Dimension d = WindowSystem.screenSize();
      return new DisplayMode(d.width, d.height, 32, 60);
   }

   public DisplayMode[] getDisplayModes() {
      return new DisplayMode[]{getDisplayMode()};
   }

   public boolean isFullScreenSupported() {
      return false;
   }

   public boolean isDisplayChangeSupported() {
      return false;
   }

   public void setDisplayMode(DisplayMode dm) {
   }

   public void setFullScreenWindow(Window w) {
      fullScreen = w;
      if (w != null) {
         Dimension d = WindowSystem.screenSize();
         w.setBounds(0, 0, d.width, d.height);
         w.setVisible(true);
      }
   }

   public Window getFullScreenWindow() {
      return fullScreen;
   }

   public int getAvailableAcceleratedMemory() {
      return 0;
   }
}

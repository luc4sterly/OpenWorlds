package java.awt;

/** A mouse cursor shape, as java.awt.Cursor. The Vita shows it only when the pointer is driven by the stick. */
public class Cursor implements java.io.Serializable {
   public static final int DEFAULT_CURSOR = 0;
   public static final int CROSSHAIR_CURSOR = 1;
   public static final int TEXT_CURSOR = 2;
   public static final int WAIT_CURSOR = 3;
   public static final int SW_RESIZE_CURSOR = 4;
   public static final int SE_RESIZE_CURSOR = 5;
   public static final int NW_RESIZE_CURSOR = 6;
   public static final int NE_RESIZE_CURSOR = 7;
   public static final int N_RESIZE_CURSOR = 8;
   public static final int S_RESIZE_CURSOR = 9;
   public static final int W_RESIZE_CURSOR = 10;
   public static final int E_RESIZE_CURSOR = 11;
   public static final int HAND_CURSOR = 12;
   public static final int MOVE_CURSOR = 13;
   public static final int CUSTOM_CURSOR = -1;

   private static final String[] NAMES = {"Default Cursor", "Crosshair Cursor", "Text Cursor", "Wait Cursor",
         "Southwest Resize Cursor", "Southeast Resize Cursor", "Northwest Resize Cursor", "Northeast Resize Cursor",
         "North Resize Cursor", "South Resize Cursor", "West Resize Cursor", "East Resize Cursor", "Hand Cursor", "Move Cursor"};
   private static final Cursor[] predefined = new Cursor[NAMES.length];

   int type;
   protected String name;
   /** A custom cursor's image and hot spot. */
   Image image;
   Point hotSpot;

   public Cursor(int type) {
      if (type < 0 || type >= NAMES.length) {
         throw new IllegalArgumentException("illegal cursor type");
      }
      this.type = type;
      this.name = NAMES[type];
   }

   protected Cursor(String name) {
      this.type = CUSTOM_CURSOR;
      this.name = name;
   }

   Cursor(Image image, Point hotSpot, String name) {
      this(name);
      this.image = image;
      this.hotSpot = hotSpot;
   }

   public static Cursor getPredefinedCursor(int type) {
      if (type < 0 || type >= NAMES.length) {
         throw new IllegalArgumentException("illegal cursor type");
      }
      synchronized (predefined) {
         if (predefined[type] == null) {
            predefined[type] = new Cursor(type);
         }
         return predefined[type];
      }
   }

   public static Cursor getDefaultCursor() {
      return getPredefinedCursor(DEFAULT_CURSOR);
   }

   public int getType() {
      return type;
   }

   public String getName() {
      return name;
   }

   public String toString() {
      return getClass().getName() + "[" + getName() + "]";
   }
}

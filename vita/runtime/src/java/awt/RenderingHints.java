package java.awt;

import java.util.HashMap;
import java.util.Map;

/** Rendering hints, as java.awt.RenderingHints: only text antialiasing changes anything here. */
public class RenderingHints extends HashMap<Object, Object> implements Cloneable {
   public abstract static class Key {
      private final int privatekey;

      protected Key(int privatekey) {
         this.privatekey = privatekey;
      }

      public abstract boolean isCompatibleValue(Object val);

      protected final int intKey() {
         return privatekey;
      }

      public final int hashCode() {
         return privatekey;
      }

      public final boolean equals(Object o) {
         return this == o;
      }
   }

   static final class SimpleKey extends Key {
      private final String name;

      SimpleKey(int key, String name) {
         super(key);
         this.name = name;
      }

      public boolean isCompatibleValue(Object val) {
         return val instanceof Value && ((Value) val).key == this;
      }

      public String toString() {
         return name;
      }
   }

   static final class Value {
      final Key key;
      final String name;

      Value(Key key, String name) {
         this.key = key;
         this.name = name;
      }

      public String toString() {
         return name;
      }
   }

   public static final Key KEY_ANTIALIASING = new SimpleKey(0, "Global antialiasing enable key");
   public static final Object VALUE_ANTIALIAS_ON = new Value(KEY_ANTIALIASING, "Antialiased rendering mode");
   public static final Object VALUE_ANTIALIAS_OFF = new Value(KEY_ANTIALIASING, "Nonantialiased rendering mode");
   public static final Object VALUE_ANTIALIAS_DEFAULT = new Value(KEY_ANTIALIASING, "Default antialiasing rendering mode");
   public static final Key KEY_RENDERING = new SimpleKey(1, "Global rendering quality key");
   public static final Object VALUE_RENDER_SPEED = new Value(KEY_RENDERING, "Fastest rendering methods");
   public static final Object VALUE_RENDER_QUALITY = new Value(KEY_RENDERING, "Highest quality rendering methods");
   public static final Object VALUE_RENDER_DEFAULT = new Value(KEY_RENDERING, "Default rendering methods");
   public static final Key KEY_DITHERING = new SimpleKey(2, "Dithering quality key");
   public static final Object VALUE_DITHER_DISABLE = new Value(KEY_DITHERING, "Nondithered rendering mode");
   public static final Object VALUE_DITHER_ENABLE = new Value(KEY_DITHERING, "Dithered rendering mode");
   public static final Object VALUE_DITHER_DEFAULT = new Value(KEY_DITHERING, "Default dithering mode");
   public static final Key KEY_TEXT_ANTIALIASING = new SimpleKey(3, "Text-specific antialiasing enable key");
   public static final Object VALUE_TEXT_ANTIALIAS_ON = new Value(KEY_TEXT_ANTIALIASING, "Antialiased text mode");
   public static final Object VALUE_TEXT_ANTIALIAS_OFF = new Value(KEY_TEXT_ANTIALIASING, "Nonantialiased text mode");
   public static final Object VALUE_TEXT_ANTIALIAS_DEFAULT = new Value(KEY_TEXT_ANTIALIASING, "Default antialiasing text mode");
   public static final Key KEY_FRACTIONALMETRICS = new SimpleKey(4, "Fractional metrics enable key");
   public static final Object VALUE_FRACTIONALMETRICS_OFF = new Value(KEY_FRACTIONALMETRICS, "Integer text metrics mode");
   public static final Object VALUE_FRACTIONALMETRICS_ON = new Value(KEY_FRACTIONALMETRICS, "Fractional text metrics mode");
   public static final Object VALUE_FRACTIONALMETRICS_DEFAULT = new Value(KEY_FRACTIONALMETRICS, "Default fractional text metrics mode");
   public static final Key KEY_INTERPOLATION = new SimpleKey(5, "Image interpolation method key");
   public static final Object VALUE_INTERPOLATION_NEAREST_NEIGHBOR = new Value(KEY_INTERPOLATION, "Nearest Neighbor image interpolation mode");
   public static final Object VALUE_INTERPOLATION_BILINEAR = new Value(KEY_INTERPOLATION, "Bilinear image interpolation mode");
   public static final Object VALUE_INTERPOLATION_BICUBIC = new Value(KEY_INTERPOLATION, "Bicubic image interpolation mode");
   public static final Key KEY_STROKE_CONTROL = new SimpleKey(6, "Stroke normalization control key");
   public static final Object VALUE_STROKE_DEFAULT = new Value(KEY_STROKE_CONTROL, "Default stroke normalization");
   public static final Object VALUE_STROKE_NORMALIZE = new Value(KEY_STROKE_CONTROL, "Normalize strokes for consistent rendering");
   public static final Object VALUE_STROKE_PURE = new Value(KEY_STROKE_CONTROL, "Pure stroke conversion for accurate paths");

   public RenderingHints(Map<Key, ?> init) {
      if (init != null) {
         putAll(init);
      }
   }

   public RenderingHints(Key key, Object value) {
      put(key, value);
   }

   public Object clone() {
      RenderingHints r = new RenderingHints(null);
      r.putAll(this);
      return r;
   }
}

package javax.sound.sampled;

/** javax.sound.sampled.Line: what the bridge's audio output uses of it. */
public interface Line extends AutoCloseable {
   Line.Info getLineInfo();

   void open() throws LineUnavailableException;

   void close();

   boolean isOpen();

   class Info {
      private final Class<?> lineClass;

      public Info(Class<?> lineClass) {
         this.lineClass = lineClass == null ? Line.class : lineClass;
      }

      public Class<?> getLineClass() {
         return lineClass;
      }

      public boolean matches(Info info) {
         return getClass().isInstance(info) && lineClass.isAssignableFrom(info.getLineClass());
      }

      public String toString() {
         return "interface " + lineClass.getSimpleName();
      }
   }
}

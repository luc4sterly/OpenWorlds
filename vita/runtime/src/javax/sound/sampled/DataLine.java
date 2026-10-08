package javax.sound.sampled;

/** javax.sound.sampled.DataLine. */
public interface DataLine extends Line {
   void drain();

   void flush();

   void start();

   void stop();

   boolean isRunning();

   boolean isActive();

   AudioFormat getFormat();

   int getBufferSize();

   int available();

   int getFramePosition();

   long getLongFramePosition();

   long getMicrosecondPosition();

   float getLevel();

   class Info extends Line.Info {
      private final AudioFormat[] formats;
      private final int minBufferSize;
      private final int maxBufferSize;

      public Info(Class<?> lineClass, AudioFormat[] formats, int minBufferSize, int maxBufferSize) {
         super(lineClass);
         this.formats = formats == null ? new AudioFormat[0] : formats.clone();
         this.minBufferSize = minBufferSize;
         this.maxBufferSize = maxBufferSize;
      }

      public Info(Class<?> lineClass, AudioFormat format, int bufferSize) {
         this(lineClass, format == null ? null : new AudioFormat[]{format}, bufferSize, bufferSize);
      }

      public Info(Class<?> lineClass, AudioFormat format) {
         this(lineClass, format, AudioSystem.NOT_SPECIFIED);
      }

      public AudioFormat[] getFormats() {
         return formats.clone();
      }

      public boolean isFormatSupported(AudioFormat format) {
         for (AudioFormat f : formats) {
            if (format.matches(f)) {
               return true;
            }
         }
         return false;
      }

      public int getMinBufferSize() {
         return minBufferSize;
      }

      public int getMaxBufferSize() {
         return maxBufferSize;
      }
   }
}

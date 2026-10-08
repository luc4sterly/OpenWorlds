package javax.sound.midi;

/** javax.sound.midi.MidiDevice: what the sequencer needs of it. */
public interface MidiDevice extends AutoCloseable {
   Info getDeviceInfo();

   void open() throws MidiUnavailableException;

   void close();

   boolean isOpen();

   long getMicrosecondPosition();

   class Info {
      private final String name;
      private final String vendor;
      private final String description;
      private final String version;

      protected Info(String name, String vendor, String description, String version) {
         this.name = name;
         this.vendor = vendor;
         this.description = description;
         this.version = version;
      }

      public final String getName() {
         return name;
      }

      public final String getVendor() {
         return vendor;
      }

      public final String getDescription() {
         return description;
      }

      public final String getVersion() {
         return version;
      }

      public final String toString() {
         return name;
      }
   }
}

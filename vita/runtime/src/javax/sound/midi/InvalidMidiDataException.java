package javax.sound.midi;

public class InvalidMidiDataException extends Exception {
   public InvalidMidiDataException() {
      super("Invalid MIDI data.");
   }

   public InvalidMidiDataException(String message) {
      super(message);
   }
}

package javax.sound.midi;

/** javax.sound.midi.Receiver: where a sequencer sends its messages. */
public interface Receiver extends AutoCloseable {
   void send(MidiMessage message, long timeStamp);

   void close();
}

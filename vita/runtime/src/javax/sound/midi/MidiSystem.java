package javax.sound.midi;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

/**
 * javax.sound.midi.MidiSystem as the bridge uses it: Standard MIDI Files
 * in and a real-time sequencer. There is no synthesizer yet, so a
 * "connected" sequencer keeps the same time as an unconnected one but
 * nothing is heard (⚠️ the 2004 client's MIDI music is silent for now).
 */
public class MidiSystem {
   private MidiSystem() {
   }

   public static Sequence getSequence(File file) throws InvalidMidiDataException, IOException {
      InputStream in = new BufferedInputStream(new FileInputStream(file));
      try {
         return read(in, "could not get sequence from file");
      } finally {
         in.close();
      }
   }

   public static Sequence getSequence(InputStream stream) throws InvalidMidiDataException, IOException {
      return read(stream, "could not get sequence from input stream");
   }

   public static Sequence getSequence(URL url) throws InvalidMidiDataException, IOException {
      InputStream in = new BufferedInputStream(url.openStream());
      try {
         return read(in, "could not get sequence from URL");
      } finally {
         in.close();
      }
   }

   /** As the JDK: a file no reader takes is reported with one message, whatever the reason. */
   private static Sequence read(InputStream in, String failure) throws InvalidMidiDataException, IOException {
      try {
         return MidiFileReader.read(in, failure);
      } catch (InvalidMidiDataException e) {
         throw new InvalidMidiDataException(failure);
      }
   }

   public static Sequencer getSequencer() throws MidiUnavailableException {
      return getSequencer(true);
   }

   public static Sequencer getSequencer(boolean connected) throws MidiUnavailableException {
      return new RealTimeSequencer(connected ? defaultReceiver() : null);
   }

   /** The synthesizer a connected sequencer plays through: none yet. */
   static Receiver defaultReceiver() {
      return null;
   }
}

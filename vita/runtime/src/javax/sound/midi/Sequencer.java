package javax.sound.midi;

import java.io.IOException;
import java.io.InputStream;

/** javax.sound.midi.Sequencer: plays a Sequence in real time. */
public interface Sequencer extends MidiDevice {
   int LOOP_CONTINUOUSLY = -1;

   void setSequence(Sequence sequence) throws InvalidMidiDataException;

   void setSequence(InputStream stream) throws IOException, InvalidMidiDataException;

   Sequence getSequence();

   void start();

   void stop();

   boolean isRunning();

   long getTickLength();

   long getMicrosecondLength();

   long getTickPosition();

   void setTickPosition(long tick);

   void setMicrosecondPosition(long microseconds);

   float getTempoInBPM();

   float getTempoInMPQ();

   void setTempoFactor(float factor);

   float getTempoFactor();

   void setLoopCount(int count);

   int getLoopCount();
}

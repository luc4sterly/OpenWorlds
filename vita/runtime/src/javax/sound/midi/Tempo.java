package javax.sound.midi;

import java.util.ArrayList;

/**
 * Ticks to microseconds as the JDK's MidiUtils does it: the Set Tempo
 * events of the first track only (120 quarter notes per minute until the
 * first one), each stretch computed in double and truncated.
 */
final class Tempo {
   static final int DEFAULT_MPQ = 500000;

   final long[] ticks;
   final int[] tempos;

   Tempo(Sequence seq) {
      ArrayList<MidiEvent> list = new ArrayList<MidiEvent>();
      Track[] tracks = seq.getTracks();
      if (tracks.length > 0) {
         for (MidiEvent e : tracks[0].snapshot()) {
            if (isTempo(e.getMessage())) {
               list.add(e);
            }
         }
      }
      boolean fake = list.isEmpty() || list.get(0).getTick() != 0;
      int size = list.size() + (fake ? 1 : 0);
      ticks = new long[size];
      tempos = new int[size];
      int k = 0;
      if (fake) {
         ticks[0] = 0;
         tempos[0] = DEFAULT_MPQ;
         k = 1;
      }
      for (MidiEvent e : list) {
         ticks[k] = e.getTick();
         tempos[k] = mpq(e.getMessage());
         k++;
      }
   }

   static boolean isTempo(MidiMessage m) {
      if (m.getLength() != 6 || m.getStatus() != MetaMessage.META) {
         return false;
      }
      byte[] d = m.getMessage();
      return (d[1] & 0xFF) == 0x51 && d[2] == 3;
   }

   /** The microseconds per quarter note of a Set Tempo message. */
   static int mpq(MidiMessage m) {
      byte[] d = m.getMessage();
      return (d[3] & 0xFF) << 16 | (d[4] & 0xFF) << 8 | (d[5] & 0xFF);
   }

   static long ticksToMicros(long ticks, double mpq, int resolution) {
      return (long) (((double) ticks) * mpq / resolution);
   }

   static long tickToMicrosecond(Sequence seq, long tick) {
      if (seq.getDivisionType() != Sequence.PPQ) {
         double seconds = ((double) tick) / ((double) (seq.getDivisionType() * seq.getResolution()));
         return (long) (1000000 * seconds);
      }
      Tempo t = new Tempo(seq);
      int i = 0;
      long micro = 0;
      while (i + 1 < t.ticks.length && t.ticks[i + 1] <= tick) {
         micro += ticksToMicros(t.ticks[i + 1] - t.ticks[i], t.tempos[i], seq.getResolution());
         i++;
      }
      return micro + ticksToMicros(tick - t.ticks[i], t.tempos[i], seq.getResolution());
   }
}

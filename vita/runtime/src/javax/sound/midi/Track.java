package javax.sound.midi;

import java.util.ArrayList;
import java.util.HashSet;

/**
 * javax.sound.midi.Track: events sorted by tick (one added at the same tick
 * as others goes after them), always ending with a single End of Track
 * meta event whose tick is the track's length; adding another End of Track
 * only moves that one later.
 */
public final class Track {
   private final ArrayList<MidiEvent> events = new ArrayList<MidiEvent>();
   private final HashSet<MidiEvent> set = new HashSet<MidiEvent>();
   private final MidiEvent eot;

   Track() {
      MetaMessage end;
      try {
         end = new MetaMessage(0x2F, new byte[0], 0);
      } catch (InvalidMidiDataException e) {
         throw new IllegalStateException(e);
      }
      eot = new MidiEvent(end, 0);
      events.add(eot);
      set.add(eot);
   }

   static boolean isEndOfTrack(MidiMessage m) {
      return m.getLength() == 3 && m.getStatus() == MetaMessage.META && ((MetaMessage) m).getType() == 0x2F;
   }

   public boolean add(MidiEvent event) {
      if (event == null) {
         return false;
      }
      synchronized (events) {
         if (set.contains(event)) {
            return false;
         }
         if (isEndOfTrack(event.getMessage())) {
            if (event.getTick() > eot.getTick()) {
               eot.setTick(event.getTick());
            }
            return true;
         }
         set.add(event);
         int last = events.size() - 1;
         if (event.getTick() >= eot.getTick()) {
            eot.setTick(event.getTick());
            events.add(last, event);
            return true;
         }
         int i = last;
         while (i > 0 && event.getTick() < events.get(i - 1).getTick()) {
            i--;
         }
         events.add(i, event);
         return true;
      }
   }

   public boolean remove(MidiEvent event) {
      if (event == null || event == eot) {
         return false;
      }
      synchronized (events) {
         if (!set.remove(event)) {
            return false;
         }
         events.remove(event);
         return true;
      }
   }

   public MidiEvent get(int index) {
      synchronized (events) {
         return events.get(index);
      }
   }

   public int size() {
      synchronized (events) {
         return events.size();
      }
   }

   public long ticks() {
      synchronized (events) {
         return eot.getTick();
      }
   }

   /** The events as they are now, End of Track included (for the sequencer). */
   MidiEvent[] snapshot() {
      synchronized (events) {
         return events.toArray(new MidiEvent[events.size()]);
      }
   }
}

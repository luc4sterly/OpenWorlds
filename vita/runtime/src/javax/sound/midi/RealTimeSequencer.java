package javax.sound.midi;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

/**
 * A sequencer that plays in real time on a thread of its own: the events
 * of every track in tick order, the tempo changing with each Set Tempo
 * event met, each one sent to the receiver (if there is one) when its time
 * comes. It stops by itself at the sequence's last tick (End of Track), as
 * the JDK's does, unless it loops.
 */
final class RealTimeSequencer implements Sequencer {
   private static final MidiDevice.Info INFO = new MidiDevice.Info("Real Time Sequencer", "OpenWorlds", "Software sequencer", "1.0") {
   };

   private final Receiver receiver;
   private boolean open;
   private Sequence sequence;
   private MidiEvent[] events = new MidiEvent[0];
   private long tickLength;
   /** Position when stopped; while running, computed from the clock. */
   private long tickPos;
   private boolean running;
   private Thread player;
   private float tempoFactor = 1.0f;
   private int mpq = Tempo.DEFAULT_MPQ;
   private int loopCount;
   // the clock while running: tick baseTick at System.nanoTime() baseNanos, at the tempo mpq
   private long baseTick;
   private long baseNanos;
   private final boolean[][] notes = new boolean[16][128];

   RealTimeSequencer(Receiver receiver) {
      this.receiver = receiver;
   }

   public MidiDevice.Info getDeviceInfo() {
      return INFO;
   }

   public synchronized void open() {
      open = true;
   }

   public void close() {
      stop();
      synchronized (this) {
         open = false;
      }
   }

   public synchronized boolean isOpen() {
      return open;
   }

   public void setSequence(Sequence sequence) throws InvalidMidiDataException {
      if (sequence != getSequence()) {
         // not under this object's lock: stop() waits for the player thread, which takes it
         stop();
      }
      synchronized (this) {
         install(sequence);
      }
   }

   private void install(Sequence sequence) {
      this.sequence = sequence;
      tickPos = 0;
      mpq = Tempo.DEFAULT_MPQ;
      if (sequence == null) {
         events = new MidiEvent[0];
         tickLength = 0;
         return;
      }
      ArrayList<MidiEvent> all = new ArrayList<MidiEvent>();
      Track[] tracks = sequence.getTracks();
      int[] next = new int[tracks.length];
      MidiEvent[][] lists = new MidiEvent[tracks.length][];
      for (int i = 0; i < tracks.length; i++) {
         lists[i] = tracks[i].snapshot();
      }
      // merge the tracks by tick, the first track first on equal ticks
      while (true) {
         int best = -1;
         for (int i = 0; i < lists.length; i++) {
            if (next[i] < lists[i].length && (best < 0 || lists[i][next[i]].getTick() < lists[best][next[best]].getTick())) {
               best = i;
            }
         }
         if (best < 0) {
            break;
         }
         MidiEvent e = lists[best][next[best]++];
         if (!Track.isEndOfTrack(e.getMessage())) {
            all.add(e);
         }
      }
      events = all.toArray(new MidiEvent[all.size()]);
      tickLength = sequence.getTickLength();
   }

   public void setSequence(InputStream stream) throws IOException, InvalidMidiDataException {
      setSequence(stream == null ? null : MidiSystem.getSequence(stream));
   }

   public synchronized Sequence getSequence() {
      return sequence;
   }

   public void start() {
      synchronized (this) {
         if (!open) {
            throw new IllegalStateException("sequencer not open");
         }
         if (sequence == null) {
            throw new IllegalStateException("sequence not set");
         }
         if (running) {
            return;
         }
         running = true;
         baseTick = tickPos;
         baseNanos = System.nanoTime();
         final Thread t = new Thread("Java Sound Sequencer") {
            public void run() {
               play(this);
            }
         };
         t.setDaemon(true);
         player = t;
         t.start();
      }
   }

   public void stop() {
      Thread t;
      synchronized (this) {
         if (!running) {
            return;
         }
         tickPos = currentTick();
         running = false;
         t = player;
         player = null;
         notifyAll();
      }
      allNotesOff();
      if (t != null && t != Thread.currentThread()) {
         try {
            t.join(1000);
         } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
         }
      }
   }

   public synchronized boolean isRunning() {
      return running;
   }

   public synchronized long getTickLength() {
      return tickLength;
   }

   public synchronized long getMicrosecondLength() {
      return sequence == null ? 0 : sequence.getMicrosecondLength();
   }

   public synchronized long getTickPosition() {
      return running ? currentTick() : tickPos;
   }

   public synchronized void setTickPosition(long tick) {
      if (tick < 0) {
         return;
      }
      tickPos = tick;
      mpq = tempoAt(tick);
      if (running) {
         baseTick = tick;
         baseNanos = System.nanoTime();
         notifyAll();
      }
   }

   public long getMicrosecondPosition() {
      Sequence s;
      long tick;
      synchronized (this) {
         s = sequence;
         tick = running ? currentTick() : tickPos;
      }
      return s == null ? 0 : Tempo.tickToMicrosecond(s, tick);
   }

   public void setMicrosecondPosition(long microseconds) {
      Sequence s;
      synchronized (this) {
         s = sequence;
      }
      if (s == null || microseconds < 0) {
         return;
      }
      long lo = 0;
      long hi = s.getTickLength();
      while (lo < hi) {
         long mid = (lo + hi + 1) / 2;
         if (Tempo.tickToMicrosecond(s, mid) <= microseconds) {
            lo = mid;
         } else {
            hi = mid - 1;
         }
      }
      setTickPosition(lo);
   }

   public synchronized float getTempoInMPQ() {
      return mpq;
   }

   public synchronized float getTempoInBPM() {
      return 60000000.0f / mpq;
   }

   public synchronized void setTempoFactor(float factor) {
      if (factor <= 0) {
         return;
      }
      if (running) {
         baseTick = currentTick();
         baseNanos = System.nanoTime();
      }
      tempoFactor = factor;
      notifyAll();
   }

   public synchronized float getTempoFactor() {
      return tempoFactor;
   }

   public synchronized void setLoopCount(int count) {
      if (count != LOOP_CONTINUOUSLY && count < 0) {
         throw new IllegalArgumentException("illegal value for loop count: " + count);
      }
      loopCount = count;
   }

   public synchronized int getLoopCount() {
      return loopCount;
   }

   /** The tempo playing from a tick starts with: that of the last Set Tempo event before it (those at the tick are played). */
   private int tempoAt(long tick) {
      int t = Tempo.DEFAULT_MPQ;
      for (MidiEvent e : events) {
         if (e.getTick() >= tick) {
            break;
         }
         if (Tempo.isTempo(e.getMessage())) {
            t = Tempo.mpq(e.getMessage());
         }
      }
      return t;
   }

   /** Nanoseconds per tick at the current tempo. */
   private double nanosPerTick() {
      if (sequence.getDivisionType() == Sequence.PPQ) {
         return mpq * 1000.0 / sequence.getResolution() / tempoFactor;
      }
      return 1.0e9 / (sequence.getDivisionType() * sequence.getResolution()) / tempoFactor;
   }

   private long currentTick() {
      long t = baseTick + (long) ((System.nanoTime() - baseNanos) / nanosPerTick());
      return Math.min(t, tickLength);
   }

   private int indexAt(long tick) {
      int lo = 0;
      int hi = events.length;
      while (lo < hi) {
         int mid = (lo + hi) >>> 1;
         if (events[mid].getTick() < tick) {
            lo = mid + 1;
         } else {
            hi = mid;
         }
      }
      return lo;
   }

   private void play(Thread self) {
      int index;
      synchronized (this) {
         index = indexAt(baseTick);
      }
      while (true) {
         MidiMessage send = null;
         synchronized (this) {
            if (player != self) {
               return;
            }
            long tick = currentTick();
            if (index < events.length && events[index].getTick() > tick || index >= events.length && tick < tickLength) {
               long target = index < events.length ? events[index].getTick() : tickLength;
               long waitNanos = (long) ((target - baseTick) * nanosPerTick()) - (System.nanoTime() - baseNanos);
               long before = baseTick;
               try {
                  if (waitNanos > 0) {
                     wait(Math.max(1, waitNanos / 1000000L));
                  }
               } catch (InterruptedException e) {
                  return;
               }
               if (baseTick != before) {
                  // repositioned or tempo factor changed
                  index = indexAt(currentTick());
               }
               continue;
            }
            if (index >= events.length) {
               // the end
               if (loopCount != 0) {
                  if (loopCount > 0) {
                     loopCount--;
                  }
                  baseTick = 0;
                  baseNanos = System.nanoTime();
                  mpq = tempoAt(0);
                  index = 0;
                  continue;
               }
               tickPos = tickLength;
               running = false;
               player = null;
               notifyAll();
               return;
            }
            MidiEvent e = events[index++];
            MidiMessage m = e.getMessage();
            if (Tempo.isTempo(m)) {
               // the clock continues from this event at the new tempo
               long due = baseNanos + (long) ((e.getTick() - baseTick) * nanosPerTick());
               baseTick = e.getTick();
               baseNanos = due;
               mpq = Tempo.mpq(m);
            } else if (receiver != null && m.getStatus() != MetaMessage.META) {
               send = m;
            }
         }
         if (send != null) {
            track(send);
            receiver.send(send, -1);
         }
      }
   }

   /** Keeps which notes are on, to switch them off when stopped. */
   private void track(MidiMessage m) {
      int status = m.getStatus();
      if (m.getLength() < 3) {
         return;
      }
      byte[] d = m.getMessage();
      int ch = status & 0x0F;
      int note = d[1] & 0x7F;
      if ((status & 0xF0) == ShortMessage.NOTE_ON && d[2] != 0) {
         notes[ch][note] = true;
      } else if ((status & 0xF0) == ShortMessage.NOTE_OFF || (status & 0xF0) == ShortMessage.NOTE_ON) {
         notes[ch][note] = false;
      }
   }

   private void allNotesOff() {
      if (receiver == null) {
         return;
      }
      for (int ch = 0; ch < 16; ch++) {
         for (int n = 0; n < 128; n++) {
            if (notes[ch][n]) {
               notes[ch][n] = false;
               receiver.send(new ShortMessage(new byte[]{(byte) (ShortMessage.NOTE_OFF | ch), (byte) n, 0}), -1);
            }
         }
         // All Sound Off
         receiver.send(new ShortMessage(new byte[]{(byte) (ShortMessage.CONTROL_CHANGE | ch), 120, 0}), -1);
      }
   }
}

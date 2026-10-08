package javax.sound.midi;

import java.io.DataInputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Standard MIDI Files (types 0 and 1), read as the JDK's reader does:
 * running status only for channel messages, a track ends at its End of
 * Track event, an event cut short is an EOFException ("invalid MIDI file")
 * and meta or sysex data longer than its track is invalid.
 */
final class MidiFileReader {
   private static final int MTHD = 0x4D546864;
   private static final int MTRK = 0x4D54726B;

   private byte[] track;
   private int pos;

   private MidiFileReader() {
   }

   static Sequence read(InputStream stream, String failure) throws InvalidMidiDataException, IOException {
      DataInputStream in = new DataInputStream(stream);
      // the end of the file inside the header is an EOFException, as in the JDK
      if (in.readInt() != MTHD) {
         throw new InvalidMidiDataException(failure);
      }
      int length = in.readInt();
      int type = in.readUnsignedShort();
      int tracks = in.readUnsignedShort();
      int timing = in.readShort();
      if (length > 6) {
         in.skipBytes(length - 6);
      }
      if (type > 1) {
         throw new InvalidMidiDataException(failure);
      }
      float division;
      int resolution;
      if (timing > 0) {
         division = Sequence.PPQ;
         resolution = timing;
      } else {
         switch (-(timing >> 8)) {
            case 24:
               division = Sequence.SMPTE_24;
               break;
            case 25:
               division = Sequence.SMPTE_25;
               break;
            case 29:
               division = Sequence.SMPTE_30DROP;
               break;
            case 30:
               division = Sequence.SMPTE_30;
               break;
            default:
               throw new InvalidMidiDataException(failure);
         }
         resolution = timing & 0xFF;
      }
      Sequence seq = new Sequence(division, resolution);
      MidiFileReader r = new MidiFileReader();
      for (int i = 0; i < tracks; i++) {
         if (!r.nextTrack(in)) {
            break;
         }
         r.readTrack(seq.createTrack());
      }
      return seq;
   }

   /**
    * The next MTrk chunk, skipping chunks of other kinds. A file that ends
    * inside a chunk's header is invalid (EOFException); one that ends inside
    * a chunk's data is not: the tracks read so far are the sequence.
    */
   private boolean nextTrack(DataInputStream in) throws IOException, InvalidMidiDataException {
      int magic;
      int length = 0;
      do {
         if (in.skipBytes(length) != length) {
            return false;
         }
         try {
            magic = in.readInt();
            length = in.readInt();
         } catch (EOFException e) {
            throw new EOFException("invalid MIDI file");
         }
      } while (magic != MTRK);
      if (length < 0) {
         throw new InvalidMidiDataException("Track length is negative");
      }
      track = new byte[length];
      try {
         in.readFully(track);
      } catch (EOFException e) {
         return false;
      }
      pos = 0;
      return true;
   }

   private int next() throws EOFException {
      if (pos >= track.length) {
         throw new EOFException("invalid MIDI file");
      }
      return track[pos++] & 0xFF;
   }

   private long varInt() throws EOFException {
      long value = 0;
      int b;
      do {
         b = next();
         value = (value << 7) + (b & 0x7F);
      } while ((b & 0x80) != 0);
      return value;
   }

   /** The data of a meta or sysex event: longer than what is left of the track, it is invalid. */
   private byte[] bytes(int n) throws InvalidMidiDataException {
      if (n < 0 || n > track.length - pos) {
         throw new InvalidMidiDataException("event length too big: " + n);
      }
      byte[] b = new byte[n];
      System.arraycopy(track, pos, b, 0, n);
      pos += n;
      return b;
   }

   private void readTrack(Track t) throws IOException, InvalidMidiDataException {
      long tick = 0;
      int running = 0;
      boolean end = false;
      while (pos < track.length && !end) {
         int data1 = -1;
         tick += varInt();
         int b = next();
         int status;
         if (b >= 0x80) {
            status = b;
            if ((status & 0xF0) != 0xF0) {
               running = status;
            }
         } else {
            status = running;
            data1 = b;
         }
         MidiMessage m;
         switch (status & 0xF0) {
            case 0x80:
            case 0x90:
            case 0xA0:
            case 0xB0:
            case 0xE0:
               if (data1 == -1) {
                  data1 = next();
               }
               m = new ShortMessage(new byte[]{(byte) status, (byte) data1, (byte) next()});
               break;
            case 0xC0:
            case 0xD0:
               if (data1 == -1) {
                  data1 = next();
               }
               m = new ShortMessage(new byte[]{(byte) status, (byte) data1});
               break;
            case 0xF0:
               if (status == 0xF0 || status == 0xF7) {
                  int n = (int) varInt();
                  SysexMessage s = new SysexMessage();
                  s.setMessage(status, bytes(n), n);
                  m = s;
               } else if (status == 0xFF) {
                  int type = next();
                  int n = (int) varInt();
                  MetaMessage mm = new MetaMessage();
                  mm.setMessage(type, bytes(n), n);
                  m = mm;
                  end = type == 0x2F;
               } else {
                  throw new InvalidMidiDataException("Invalid status byte: " + status);
               }
               break;
            default:
               throw new InvalidMidiDataException("Invalid status byte: " + status);
         }
         t.add(new MidiEvent(m, tick));
      }
   }
}

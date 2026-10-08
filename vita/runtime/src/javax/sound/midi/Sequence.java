package javax.sound.midi;

import java.util.Vector;

/** javax.sound.midi.Sequence: tracks with a timing (ticks per quarter note, or per SMPTE frame). */
public class Sequence {
   public static final float PPQ = 0.0f;
   public static final float SMPTE_24 = 24.0f;
   public static final float SMPTE_25 = 25.0f;
   public static final float SMPTE_30DROP = 29.97f;
   public static final float SMPTE_30 = 30.0f;

   protected float divisionType;
   protected int resolution;
   protected Vector<Track> tracks = new Vector<Track>();

   public Sequence(float divisionType, int resolution) throws InvalidMidiDataException {
      if (divisionType != PPQ && divisionType != SMPTE_24 && divisionType != SMPTE_25 && divisionType != SMPTE_30DROP && divisionType != SMPTE_30) {
         throw new InvalidMidiDataException("Unsupported division type: " + divisionType);
      }
      this.divisionType = divisionType;
      this.resolution = resolution;
   }

   public Sequence(float divisionType, int resolution, int numTracks) throws InvalidMidiDataException {
      this(divisionType, resolution);
      for (int i = 0; i < numTracks; i++) {
         tracks.addElement(new Track());
      }
   }

   public float getDivisionType() {
      return divisionType;
   }

   public int getResolution() {
      return resolution;
   }

   public Track createTrack() {
      Track t = new Track();
      tracks.addElement(t);
      return t;
   }

   public boolean deleteTrack(Track track) {
      return tracks.removeElement(track);
   }

   public Track[] getTracks() {
      synchronized (tracks) {
         return tracks.toArray(new Track[tracks.size()]);
      }
   }

   public long getTickLength() {
      long length = 0;
      synchronized (tracks) {
         for (Track t : tracks) {
            length = Math.max(length, t.ticks());
         }
      }
      return length;
   }

   public long getMicrosecondLength() {
      return Tempo.tickToMicrosecond(this, getTickLength());
   }

   public Patch[] getPatchList() {
      return new Patch[0];
   }
}

package javax.sound.midi;

/** javax.sound.midi.MidiMessage: the bytes of a message, status first. */
public abstract class MidiMessage implements Cloneable {
   protected byte[] data;
   protected int length;

   protected MidiMessage(byte[] data) {
      this.data = data;
      this.length = data == null ? 0 : data.length;
   }

   protected void setMessage(byte[] data, int length) throws InvalidMidiDataException {
      if (length < 0 || (length > 0 && length > data.length)) {
         throw new IndexOutOfBoundsException("length out of bounds: " + length);
      }
      this.length = length;
      if (this.data == null || this.data.length < this.length) {
         this.data = new byte[this.length];
      }
      System.arraycopy(data, 0, this.data, 0, length);
   }

   public byte[] getMessage() {
      byte[] b = new byte[length];
      System.arraycopy(data, 0, b, 0, length);
      return b;
   }

   public int getStatus() {
      return length > 0 ? data[0] & 0xFF : 0;
   }

   public int getLength() {
      return length;
   }

   public abstract Object clone();
}

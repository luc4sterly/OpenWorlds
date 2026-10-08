package javax.sound.midi;

/** javax.sound.midi.MetaMessage: 0xFF, the type, the length (variable-length quantity) and the data. */
public class MetaMessage extends MidiMessage {
   public static final int META = 0xFF;

   private int dataLength;

   public MetaMessage() {
      this(new byte[]{(byte) META, 0});
   }

   public MetaMessage(int type, byte[] data, int length) throws InvalidMidiDataException {
      super(null);
      setMessage(type, data, length);
   }

   protected MetaMessage(byte[] data) {
      super(data);
      if (data.length >= 3) {
         dataLength = data.length - 3;
         int pos = 2;
         while (pos < data.length && (data[pos] & 0x80) != 0) {
            dataLength--;
            pos++;
         }
      }
   }

   public void setMessage(int type, byte[] data, int length) throws InvalidMidiDataException {
      if (type >= 128 || type < 0) {
         throw new InvalidMidiDataException("Invalid meta event with type " + type);
      }
      if ((length > 0 && length > data.length) || length < 0) {
         throw new InvalidMidiDataException("length out of bounds: " + length);
      }
      int lenBytes = varLength(length);
      this.length = 2 + lenBytes + length;
      this.dataLength = length;
      this.data = new byte[this.length];
      this.data[0] = (byte) META;
      this.data[1] = (byte) type;
      int shift = 7 * (lenBytes - 1);
      for (int i = 0; i < lenBytes; i++, shift -= 7) {
         this.data[2 + i] = (byte) (((length >> shift) & 0x7F) | (i < lenBytes - 1 ? 0x80 : 0));
      }
      if (length > 0) {
         System.arraycopy(data, 0, this.data, 2 + lenBytes, length);
      }
   }

   private static int varLength(int value) {
      int n = 1;
      while ((value >>>= 7) != 0) {
         n++;
      }
      return n;
   }

   public int getType() {
      return length >= 2 ? data[1] & 0xFF : 0;
   }

   public byte[] getData() {
      byte[] b = new byte[dataLength];
      System.arraycopy(data, length - dataLength, b, 0, dataLength);
      return b;
   }

   public Object clone() {
      byte[] b = new byte[length];
      System.arraycopy(data, 0, b, 0, b.length);
      return new MetaMessage(b);
   }
}

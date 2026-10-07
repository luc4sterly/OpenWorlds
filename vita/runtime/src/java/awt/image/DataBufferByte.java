package java.awt.image;

public final class DataBufferByte extends DataBuffer {
   final byte[] data;

   public DataBufferByte(int size) {
      super(TYPE_BYTE, size);
      data = new byte[size];
   }

   public DataBufferByte(byte[] dataArray, int size) {
      super(TYPE_BYTE, size);
      data = dataArray;
   }

   public byte[] getData() {
      return data;
   }

   public byte[] getData(int bank) {
      return data;
   }

   public int getElem(int bank, int i) {
      return data[i + offset] & 0xFF;
   }

   public void setElem(int bank, int i, int val) {
      data[i + offset] = (byte) val;
   }
}

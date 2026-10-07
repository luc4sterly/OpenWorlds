package java.awt.image;

public final class DataBufferUShort extends DataBuffer {
   final short[] data;

   public DataBufferUShort(int size) {
      super(TYPE_USHORT, size);
      data = new short[size];
   }

   public DataBufferUShort(short[] dataArray, int size) {
      super(TYPE_USHORT, size);
      data = dataArray;
   }

   public short[] getData() {
      return data;
   }

   public short[] getData(int bank) {
      return data;
   }

   public int getElem(int bank, int i) {
      return data[i + offset] & 0xFFFF;
   }

   public void setElem(int bank, int i, int val) {
      data[i + offset] = (short) val;
   }
}

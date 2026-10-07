package java.awt.image;

public final class DataBufferInt extends DataBuffer {
   final int[] data;

   public DataBufferInt(int size) {
      super(TYPE_INT, size);
      data = new int[size];
   }

   public DataBufferInt(int[] dataArray, int size) {
      super(TYPE_INT, size);
      data = dataArray;
   }

   public int[] getData() {
      return data;
   }

   public int[] getData(int bank) {
      return data;
   }

   public int getElem(int bank, int i) {
      return data[i + offset];
   }

   public void setElem(int bank, int i, int val) {
      data[i + offset] = val;
   }
}

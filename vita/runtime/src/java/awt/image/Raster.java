package java.awt.image;

/** The pixels of an image: one data element per pixel here (packed formats only). */
public class Raster {
   protected DataBuffer dataBuffer;
   protected int width;
   protected int height;
   protected int minX;
   protected int minY;
   protected int numBands;

   protected Raster(DataBuffer dataBuffer, int width, int height, int numBands) {
      this.dataBuffer = dataBuffer;
      this.width = width;
      this.height = height;
      this.numBands = numBands;
   }

   public DataBuffer getDataBuffer() {
      return dataBuffer;
   }

   public final int getWidth() {
      return width;
   }

   public final int getHeight() {
      return height;
   }

   public final int getMinX() {
      return minX;
   }

   public final int getMinY() {
      return minY;
   }

   public final int getNumBands() {
      return numBands;
   }

   public final int getNumDataElements() {
      return 1;
   }

   public final int getTransferType() {
      return dataBuffer.getDataType();
   }

   public Object getDataElements(int x, int y, Object outData) {
      int v = dataBuffer.getElem(y * width + x);
      switch (dataBuffer.getDataType()) {
         case DataBuffer.TYPE_BYTE: {
            byte[] o = outData instanceof byte[] ? (byte[]) outData : new byte[1];
            o[0] = (byte) v;
            return o;
         }
         case DataBuffer.TYPE_USHORT:
         case DataBuffer.TYPE_SHORT: {
            short[] o = outData instanceof short[] ? (short[]) outData : new short[1];
            o[0] = (short) v;
            return o;
         }
         default: {
            int[] o = outData instanceof int[] ? (int[]) outData : new int[1];
            o[0] = v;
            return o;
         }
      }
   }

   public int getSample(int x, int y, int b) {
      return dataBuffer.getElem(y * width + x);
   }
}

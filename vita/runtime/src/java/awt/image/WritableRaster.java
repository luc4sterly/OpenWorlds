package java.awt.image;

public class WritableRaster extends Raster {
   protected WritableRaster(DataBuffer dataBuffer, int width, int height, int numBands) {
      super(dataBuffer, width, height, numBands);
   }

   public void setDataElements(int x, int y, Object inData) {
      int v;
      if (inData instanceof byte[]) {
         v = ((byte[]) inData)[0] & 0xFF;
      } else if (inData instanceof short[]) {
         v = ((short[]) inData)[0] & 0xFFFF;
      } else {
         v = ((int[]) inData)[0];
      }
      dataBuffer.setElem(y * width + x, v);
   }

   public void setSample(int x, int y, int b, int s) {
      dataBuffer.setElem(y * width + x, s);
   }

   public static WritableRaster create(DataBuffer buffer, int width, int height, int bands) {
      return new WritableRaster(buffer, width, height, bands);
   }
}

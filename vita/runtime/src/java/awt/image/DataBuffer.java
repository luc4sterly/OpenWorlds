package java.awt.image;

public abstract class DataBuffer {
   public static final int TYPE_BYTE = 0;
   public static final int TYPE_USHORT = 1;
   public static final int TYPE_SHORT = 2;
   public static final int TYPE_INT = 3;
   public static final int TYPE_FLOAT = 4;
   public static final int TYPE_DOUBLE = 5;
   public static final int TYPE_UNDEFINED = 32;

   protected int dataType;
   protected int banks;
   protected int offset;
   protected int size;

   protected DataBuffer(int dataType, int size) {
      this.dataType = dataType;
      this.size = size;
      this.banks = 1;
   }

   public int getDataType() {
      return dataType;
   }

   public int getSize() {
      return size;
   }

   public int getOffset() {
      return offset;
   }

   public int getNumBanks() {
      return banks;
   }

   public int getElem(int i) {
      return getElem(0, i);
   }

   public abstract int getElem(int bank, int i);

   public void setElem(int i, int val) {
      setElem(0, i, val);
   }

   public abstract void setElem(int bank, int i, int val);

   public static int getDataTypeSize(int type) {
      switch (type) {
         case TYPE_BYTE:
            return 8;
         case TYPE_USHORT:
         case TYPE_SHORT:
            return 16;
         case TYPE_INT:
         case TYPE_FLOAT:
            return 32;
         case TYPE_DOUBLE:
            return 64;
         default:
            throw new IllegalArgumentException("Unknown data type " + type);
      }
   }
}

package NET.worlds.core;

import java.io.DataInput;
import java.io.IOException;

public class FastDataInput implements DataInput {
   private int nativeInfo;

   public FastDataInput(String var1) throws IOException {
      nativeInit();
      this.read(var1);
   }

   public native void close();

   public void readFully(byte[] var1) throws IOException {
      this.readFully(var1, 0, var1.length);
   }

   public static native void nativeInit();

   public native void readFully(byte[] var1, int var2, int var3) throws IOException;

   public native int skipBytes(int var1) throws IOException;

   public native boolean readBoolean() throws IOException;

   public native byte readByte() throws IOException;

   public native int readUnsignedByte() throws IOException;

   public native short readShort() throws IOException;

   public native int readUnsignedShort() throws IOException;

   public native char readChar() throws IOException;

   public native int readInt() throws IOException;

   public native long readLong() throws IOException;

   public native float readFloat() throws IOException;

   public native double readDouble() throws IOException;

   public String readLine() throws IOException {
      Debug.assert_(false);
      return null;
   }

   public native String readUTF() throws IOException;

   private native void read(String var1) throws IOException;
}

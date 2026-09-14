package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.UTFDataFormatException;

class netData {
   private byte[] _data;
   private int _packetSize;
   private int _offset;

   public netData(DataInputStream var1) {
      try {
         this._packetSize = var1.readUnsignedByte();
         this._data = new byte[256];
         var1.readFully(this._data, 1, this._packetSize - 1);
         this._data[0] = (byte)this._packetSize;
      } catch (Exception var3) {
         this._data = null;
         this._packetSize = 0;
      }

      this._offset = 1;
   }

   public final int packetSize() {
      return this._packetSize;
   }

   public final boolean isEmpty() {
      return this._offset >= this._packetSize;
   }

   public final byte getByte() {
      Debug.dAssert(this._offset < this._packetSize);
      return this._data[this._offset++];
   }

   public final short getShort() {
      Debug.dAssert(this._offset < this._packetSize);
      Debug.dAssert(this._offset + 1 < this._packetSize);
      short var1 = (short)(this._data[this._offset] << 8 | this._data[this._offset + 1] & 0xFF);
      this._offset += 2;
      return var1;
   }

   public String getUTFString(int var1) {
      char[] var2 = new char[var1];
      int var3 = 0;
      int var4 = 0;

      try {
         while (var3 < var1) {
            int var5 = this.getByte() & 255;
            switch (var5 >> 4) {
               case 0:
               case 1:
               case 2:
               case 3:
               case 4:
               case 5:
               case 6:
               case 7:
                  var3++;
                  var2[var4++] = (char)var5;
                  break;
               case 12:
               case 13:
                  var3 += 2;
                  if (var3 > var1) {
                     throw new UTFDataFormatException();
                  }

                  int var10 = this.getByte() & 255;
                  if ((var10 & 192) != 128) {
                     throw new UTFDataFormatException();
                  }

                  var2[var4++] = (char)((var5 & 31) << 6 | var10 & 63);
                  break;
               case 14:
                  var3 += 3;
                  if (var3 > var1) {
                     throw new UTFDataFormatException();
                  }

                  int var6 = this.getByte() & 255;
                  int var7 = this.getByte() & 255;
                  if ((var6 & 192) != 128 || (var7 & 192) != 128) {
                     throw new UTFDataFormatException();
                  }

                  var2[var4++] = (char)((var5 & 15) << 12 | (var6 & 63) << 6 | (var7 & 63) << 0);
               case 8:
               case 9:
               case 10:
               case 11:
               default:
                  throw new UTFDataFormatException();
            }
         }
      } catch (IOException var8) {
         System.err.println("Exception: " + var8.getMessage());
         var8.printStackTrace();
         Debug.assert_(false);
      }

      return new String(var2, 0, var4);
   }
}

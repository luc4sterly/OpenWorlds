package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.EOFException;
import java.io.FilterInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.UTFDataFormatException;

public class ServerInputStream extends FilterInputStream {
   private int _packetSize;

   public ServerInputStream(InputStream var1) {
      super(var1);
      Debug.dAssert(var1 != null);
      this._packetSize = 0;
   }

   public void readPacketSize() throws IOException {
      Debug.dAssert(this._packetSize == 0);
      this._packetSize = 1;
      this._packetSize = this.readUnsignedByte() - 1;
   }

   public boolean isEmpty() {
      return this._packetSize == 0;
   }

   public int bytesLeft() {
      return this._packetSize;
   }

   public final int read(byte[] var1) throws IOException {
      Debug.dAssert(this._packetSize >= var1.length);
      if (var1.length == 0) {
         return 0;
      }

      int var2 = this.in.read(var1, 0, var1.length);
      if (var2 < 0) {
         throw new EOFException();
      }

      this._packetSize -= var2;
      return var2;
   }

   public final int read(byte[] var1, int var2, int var3) throws IOException {
      Debug.dAssert(this._packetSize >= var3);
      int var4 = this.in.read(var1, var2, var3);
      if (var4 < 0) {
         throw new EOFException();
      }

      this._packetSize -= var4;
      return var4;
   }

   public final void readFully(byte[] var1) throws IOException {
      Debug.dAssert(this._packetSize >= var1.length);
      this.readFully(var1, 0, var1.length);
      this._packetSize -= var1.length;
   }

   public final void readFully(byte[] var1, int var2, int var3) throws IOException {
      Debug.dAssert(this._packetSize >= var3);
      this._packetSize -= var3;
      InputStream var4 = this.in;

      while (var3 > 0) {
         int var5 = var4.read(var1, var2, var3);
         if (var5 < 0) {
            throw new EOFException();
         }

         var3 -= var5;
         var2 += var5;
      }
   }

   public void skipBytes(int var1) throws IOException {
      Debug.dAssert(this._packetSize >= var1);
      this._packetSize -= var1;
      InputStream var2 = this.in;

      while (var1 > 0) {
         int var3 = (int)var2.skip(var1);
         if (var3 < 0) {
            throw new EOFException();
         }

         var1 -= var3;
      }
   }

   public final byte readByte() throws IOException {
      if (this._packetSize < 1) {
         throw new IOException();
      }

      int var1 = this.in.read();
      if (var1 < 0) {
         throw new EOFException();
      }

      this._packetSize--;
      return (byte)var1;
   }

   public final int readUnsignedByte() throws IOException {
      if (this._packetSize < 1) {
         throw new IOException();
      }

      int var1 = this.in.read();
      if (var1 < 0) {
         throw new EOFException();
      }

      this._packetSize--;
      return var1;
   }

   public final short readShort() throws IOException {
      Debug.dAssert(this._packetSize >= 2);
      InputStream var1 = this.in;
      int var2 = var1.read();
      int var3 = var1.read();
      if ((var2 | var3) < 0) {
         throw new EOFException();
      }

      this._packetSize -= 2;
      return (short)((var2 << 8) + (var3 << 0));
   }

   public final int readUnsignedShort() throws IOException {
      Debug.dAssert(this._packetSize >= 2);
      InputStream var1 = this.in;
      int var2 = var1.read();
      int var3 = var1.read();
      if ((var2 | var3) < 0) {
         throw new EOFException();
      }

      this._packetSize -= 2;
      return (var2 << 8) + (var3 << 0);
   }

   public String readUTF() throws IOException {
      if (this._packetSize < 1) {
         throw new IOException();
      }

      int var1 = this.readUnsignedByte();
      if (this._packetSize < var1) {
         throw new UTFDataFormatException();
      }

      char[] var2 = new char[var1];
      int var3 = 0;
      int var4 = 0;

      while (var3 < var1) {
         int var5 = this.readUnsignedByte();
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
            case 8:
            case 9:
            case 10:
            case 11:
            default:
               throw new UTFDataFormatException();
            case 12:
            case 13:
               var3 += 2;
               if (var3 > var1) {
                  throw new UTFDataFormatException();
               }

               int var8 = this.readUnsignedByte();
               if ((var8 & 192) != 128) {
                  throw new UTFDataFormatException();
               }

               var2[var4++] = (char)((var5 & 31) << 6 | var8 & 63);
               break;
            case 14:
               var3 += 3;
               if (var3 > var1) {
                  throw new UTFDataFormatException();
               }

               int var6 = this.readUnsignedByte();
               int var7 = this.readUnsignedByte();
               if ((var6 & 192) != 128 || (var7 & 192) != 128) {
                  throw new UTFDataFormatException();
               }

               var2[var4++] = (char)((var5 & 15) << 12 | (var6 & 63) << 6 | (var7 & 63) << 0);
         }
      }

      return new String(var2, 0, var4);
   }
}

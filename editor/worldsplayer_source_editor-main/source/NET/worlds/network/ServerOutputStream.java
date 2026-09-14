package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class ServerOutputStream extends FilterOutputStream {
   public ServerOutputStream(OutputStream var1) {
      super(var1);
   }

   public final void write(int var1) throws IOException {
      this.out.write(var1);
   }

   public final void write(byte[] var1, int var2, int var3) throws IOException {
      this.out.write(var1, var2, var3);
   }

   public final void writeByte(int var1) throws IOException {
      this.out.write(var1);
   }

   public final void writeShort(int var1) throws IOException {
      OutputStream var2 = this.out;
      var2.write(var1 >>> 8 & 0xFF);
      var2.write(var1 >>> 0 & 0xFF);
   }

   public final void writeInt(int var1) throws IOException {
      OutputStream var2 = this.out;
      var2.write(var1 >>> 24 & 0xFF);
      var2.write(var1 >>> 16 & 0xFF);
      var2.write(var1 >>> 8 & 0xFF);
      var2.write(var1 >>> 0 & 0xFF);
   }

   public static int utfLength(String var0) {
      int var1 = var0.length();
      int var2 = 0;

      for (int var3 = 0; var3 < var1; var3++) {
         char var4 = var0.charAt(var3);
         if (var4 >= 1 && var4 <= 127) {
            var2++;
         } else if (var4 > 2047) {
            var2 += 3;
         } else {
            var2 += 2;
         }
      }

      return var2;
   }

   public void writeUTF(String var1) throws IOException {
      OutputStream var2 = this.out;
      int var3 = var1.length();
      int var4 = utfLength(var1);
      Debug.dAssert(var4 < 256);
      var2.write(var4 >>> 0 & 0xFF);

      for (int var5 = 0; var5 < var3; var5++) {
         char var6 = var1.charAt(var5);
         if (var6 >= 1 && var6 <= 127) {
            var2.write(var6);
         } else if (var6 > 2047) {
            var2.write(224 | var6 >> '\f' & 15);
            var2.write(128 | var6 >> 6 & 63);
            var2.write(128 | var6 >> 0 & 63);
         } else {
            var2.write(192 | var6 >> 6 & 31);
            var2.write(128 | var6 >> 0 & 63);
         }
      }
   }
}

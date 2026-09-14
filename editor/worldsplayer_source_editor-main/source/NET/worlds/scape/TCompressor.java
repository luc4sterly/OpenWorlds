package NET.worlds.scape;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class TCompressor {
   private static final int CMAP_MAXPOSCOMP = 128;
   private static final int CMAP_DEFAULTAXIS = 0;
   private static final int CMAP_XUNITARY = 32;
   private static final int CMAP_YUNITARY = 64;
   private static final int CMAP_ZUNITARY = 96;
   private static final int CMAP_ROTATION = 16;
   private static final int CMAP_ROTSIGN1 = 8;
   private static final int CMAP_ROTSIGN2 = 4;
   private static final int CMAP_SCALE = 2;
   private static final int CMAP_UNIFORMSCALE = 1;
   private static final int MODE_SENDCMAP = 8388608;
   private static final int MODE_SENDZ = 4194304;
   private static final int MODE_MAXPOSCOMP = 128;
   private static final int MODE_SENDROTAXIS = 96;
   private static final int MODE_SENDROTATION = 16;
   private static final int MODE_SENDSCALE = 2;
   public static final int USER_SEND_POSITION = 32768;
   public static final int USER_SEND_ROTATION = 16384;
   public static final int USER_SEND_SCALE = 8192;
   public static final int USER_SEND_ALL = 57344;
   private static final int LOW21BITSMASK = 2097151;
   private static final int LOW18BITSMASK = 262143;
   private static final int LOW12BITSMASK = 4095;
   private static final int LOW10BITSMASK = 1023;
   private static final int LOW8BITSMASK = 255;
   private static final int BIT20 = 1048576;
   private static final double SCFACT = 16.0;
   private static final double SCOFFSET = 121.6;
   static int wroteBytes = 0;
   public static boolean dontSend = false;

   public static void compress(WObject var0, Point3Temp var1, Point3Temp var2, float var3, Point3Temp var4, int var5, DataOutputStream var6) throws IOException {
      Point3Temp var8 = var0.getPosition();
      Point3Temp var9 = Point3Temp.make();
      float var10 = var0.getSpin(var9);
      Point3Temp var11 = var0.getScale();
      if (dontSend) {
         System.err.println("DONTSEND is TRUE on COMPRESS CALL");
      } else {
         int var12 = var5;
         if ((var12 & 32768) != 0) {
            if (var8.x >= 0.0F && var8.x <= 4095.0 && var8.y >= 0.0F && var8.y <= 4095.0 && (var8.z >= 0.0F && var8.z <= 255.0 || var8.z == var1.z)) {
               var12 |= 128;
            }

            if (var8.z != var1.z) {
               var12 |= 4194304;
            }
         }

         int var13 = 0;
         int var14 = 0;
         if ((var12 & 16384) != 0 && !var9.sameValue(var2)) {
            byte var15 = 0;
            float var16 = var9.x;
            var15 = 32;
            if (Math.abs(var9.y) > Math.abs(var16)) {
               var16 = var9.y;
               var15 = 64;
            }

            if (Math.abs(var9.z) > Math.abs(var16)) {
               var16 = var9.z;
               var15 = 96;
            }

            var9.x /= var16;
            var9.y /= var16;
            var9.z /= var16;
            var12 |= var15;
            if (var16 < 0.0F) {
               var10 *= -1.0F;
            }

            switch (var15) {
               case 32:
                  if (var9.y < 0.0F) {
                     var12 |= 8;
                  }

                  if (var9.z < 0.0F) {
                     var12 |= 4;
                  }

                  var13 = Math.round(Math.abs(255.0F * var9.y));
                  var14 = Math.round(Math.abs(255.0F * var9.z));
                  break;
               case 64:
                  if (var9.x < 0.0F) {
                     var12 |= 8;
                  }

                  if (var9.z < 0.0F) {
                     var12 |= 4;
                  }

                  var13 = Math.round(Math.abs(255.0F * var9.x));
                  var14 = Math.round(Math.abs(255.0F * var9.z));
                  break;
               case 96:
                  if (var9.x < 0.0F) {
                     var12 |= 8;
                  }

                  if (var9.y < 0.0F) {
                     var12 |= 4;
                  }

                  var13 = Math.round(Math.abs(255.0F * var9.x));
                  var14 = Math.round(Math.abs(255.0F * var9.y));
            }

            if (var13 == 0 && var14 == 0 && var16 < 0.0F) {
               var12 |= 8;
               var12 |= 4;
            }

            while (var10 >= 360.0F) {
               var10 -= 360.0F;
            }

            while (var10 < 0.0F) {
               var10 += 360.0F;
            }

            if (var10 != var3) {
               var12 |= 8388608;
               var12 |= 16;
            }
         }

         if ((var12 & 8192) != 0 && !var11.sameValue(var4)) {
            var12 |= 8388608;
            var12 |= 2;
            if (var11.x == var11.y && var11.x == var11.z) {
               var12 |= 1;
            }
         }

         if ((var12 & 8388608) != 0) {
            var6.writeByte(var12 & 0xFF);
            wroteBytes++;
         }

         if ((var12 & 32768) != 0) {
            if ((var12 & 128) != 0) {
               maxCompressXY(var8.x, var8.y, var6);
               if ((var12 & 4194304) != 0 || (var12 & 8388608) != 0) {
                  short var25 = (short)Math.round(var8.z);
                  int var7 = var25 & 255;
                  var6.writeByte(var7);
                  wroteBytes++;
               }
            } else {
               minCompressXYZ(var8.x, var8.y, var8.z, var6);
            }
         }

         if ((var12 & 96) != 0) {
            var6.writeByte(var13);
            var6.writeByte(var14);
            wroteBytes += 2;
         }

         if ((var12 & 16) != 0) {
            int var17 = (int)Math.round(256.0 * (var10 / 360.0));
            var6.writeByte(var17);
            wroteBytes++;
         }

         if ((var12 & 2) != 0) {
            double var26 = 16.0 * Math.log(var11.x / var4.x) + 121.6;
            if (var26 < 0.0) {
               var26 = 0.0;
            }

            if (var26 > 255.0) {
               var26 = 255.0;
            }

            int var18 = (int)Math.round(var26);
            var6.writeByte(var18);
            wroteBytes++;
            if ((var12 & 1) == 0) {
               var26 = 16.0 * Math.log(var11.y / var4.y) + 121.6;
               if (var26 < 0.0) {
                  var26 = 0.0;
               }

               if (var26 > 255.0) {
                  var26 = 255.0;
               }

               var18 = (int)Math.round(var26);
               var6.writeByte(var18);
               wroteBytes++;
               var26 = 16.0 * Math.log(var11.z / var4.z) + 121.6;
               if (var26 < 0.0) {
                  var26 = 0.0;
               }

               if (var26 > 255.0) {
                  var26 = 255.0;
               }

               var18 = (int)Math.round(var26);
               var6.writeByte(var18);
               wroteBytes++;
            }
         }

         wroteBytes = 0;
      }
   }

   private static void maxCompressXY(float var0, float var1, DataOutputStream var2) throws IOException {
      short var3 = (short)Math.round(var0);
      short var4 = (short)Math.round(var1);
      var3 = (short)(var3 & 4095);
      var4 = (short)(var4 & 4095);
      int var5 = var3 >>> 4;
      var2.writeByte(var5);
      wroteBytes++;
      var3 = (short)(var3 << 4);
      var3 = (short)(var3 & 0xFF);
      var5 = var3 | var4 >>> 8;
      var2.writeByte(var5);
      wroteBytes++;
      var5 = var4 & 255;
      var2.writeByte(var5);
      wroteBytes++;
   }

   private static void minCompressXYZ(float var0, float var1, float var2, DataOutputStream var3) throws IOException {
      int var4 = floatTo21bits(var0);
      int var5 = floatTo21bits(var1);
      int var6 = floatTo21bits(var2);
      int var7 = var4 << 10 | var5 >>> 11;
      var3.writeInt(var7);
      wroteBytes += 4;
      var7 = var5 << 21 | var6;
      var3.writeInt(var7);
      wroteBytes += 4;
   }

   private static int floatTo21bits(float var0) {
      for (int var1 = 0; var1 <= 3; var1++) {
         double var2 = Math.pow(10.0, var1 - 2);
         float var4 = (float)(262144.0 * var2);
         float var5 = Math.abs(var0);
         if (var5 < var4 || var1 == 3) {
            int var6 = (int)Math.round(var5 / var2);
            var6 &= 262143;
            var6 <<= 2;
            var6 |= var1;
            if (var0 < 0.0F) {
               var6 |= 1048576;
            }

            return var6;
         }
      }

      return 0;
   }

   public static void decompress(WObject var0, Point3Temp var1, Point3Temp var2, float var3, Point3Temp var4, int var5, int var6, DataInputStream var7) throws IOException {
      int var8 = var5;
      Point3Temp var10 = var0.getPosition();
      Point3Temp var11 = Point3Temp.make();
      float var12 = var0.getSpin(var11);
      Point3Temp var13 = var0.getScale();
      dontSend = true;
      if (var6 == 0) {
         var0.moveTo(var1);
         var13.x = var4.x / var13.x;
         var13.y = var4.y / var13.y;
         var13.z = var4.z / var13.z;
         var0.scale(var13);
         dontSend = false;
      } else if (var6 == 24) {
         var10.x = var7.readFloat();
         var10.y = var7.readFloat();
         var10.z = var7.readFloat();
         var13.x = var7.readFloat() / var13.x;
         var13.y = var7.readFloat() / var13.y;
         var13.z = var7.readFloat() / var13.z;
         var0.moveTo(var10);
         var0.scale(var13);
         dontSend = false;
      } else {
         if (var6 > 4) {
            var8 |= 8388608;
         } else {
            var8 |= 128;
         }

         if (var6 == 4) {
            var8 |= 4194304;
         }

         if ((var8 & 8388608) != 0) {
            int var9 = var7.readUnsignedByte();
            var8 |= var9;
            var8 |= 4194304;
         }

         if ((var8 & 32768) != 0) {
            if ((var8 & 128) != 0) {
               var10 = maxDecompressXY(var10, var7);
               if ((var8 & 4194304) != 0) {
                  int var14 = var7.readUnsignedByte();
                  var10.z = var14;
               }
            } else {
               var10 = minDecompressXYZ(var10, var7);
            }

            var0.moveTo(var10);
         }

         if ((var8 & 8388608) == 0) {
            dontSend = false;
         } else {
            if ((var8 & 16) != 0) {
               var0.spin(var11.x, var11.y, var11.z, -var12);
            }

            var11.x = var2.x;
            var11.y = var2.y;
            var11.z = var2.z;
            if ((var8 & 96) != 0) {
               int var25 = var7.readUnsignedByte();
               int var15 = var7.readUnsignedByte();
               switch (var8 & 96) {
                  case 0:
                  default:
                     break;
                  case 32:
                     var11.x = 1.0F;
                     var11.y = (float)(var25 / 255.0);
                     var11.z = (float)(var15 / 255.0);
                     if ((var8 & 8) != 0) {
                        var11.y = (float)(var11.y * -1.0);
                     }

                     if ((var8 & 4) != 0) {
                        var11.z = (float)(var11.z * -1.0);
                     }

                     if (var11.y == 0.0F && var11.z == 0.0F && (var8 & 8) != 0 && (var8 & 4) != 0) {
                        var11.x = -1.0F;
                     }
                     break;
                  case 64:
                     var11.y = 1.0F;
                     var11.x = (float)(var25 / 255.0);
                     var11.z = (float)(var15 / 255.0);
                     if ((var8 & 8) != 0) {
                        var11.x = (float)(var11.x * -1.0);
                     }

                     if ((var8 & 4) != 0) {
                        var11.z = (float)(var11.z * -1.0);
                     }

                     if (var11.x == 0.0F && var11.z == 0.0F && (var8 & 8) != 0 && (var8 & 4) != 0) {
                        var11.y = -1.0F;
                     }
                     break;
                  case 96:
                     var11.z = 1.0F;
                     var11.x = (float)(var25 / 255.0);
                     var11.y = (float)(var15 / 255.0);
                     if ((var8 & 8) != 0) {
                        var11.x = (float)(var11.x * -1.0);
                     }

                     if ((var8 & 4) != 0) {
                        var11.y = (float)(var11.y * -1.0);
                     }

                     if (var11.x == 0.0F && var11.y == 0.0F && (var8 & 8) != 0 && (var8 & 4) != 0) {
                        var11.z = -1.0F;
                     }
               }
            }

            if ((var8 & 16) != 0) {
               int var19 = var7.readUnsignedByte();
               var12 = (float)(360.0 * (var19 / 256.0));
               var0.worldSpin(var11.x, var11.y, var11.z, var12);
            }

            if ((var8 & 2) != 0) {
               int var20 = var7.readUnsignedByte();
               double var26 = var4.x * Math.exp((var20 - 121.6) / 16.0);
               var13.x = (float)var26;
               if ((var8 & 1) != 0) {
                  var13.y = var13.x;
                  var13.z = var13.x;
               } else {
                  var20 = var7.readUnsignedByte();
                  var26 = var4.y * Math.exp((var20 - 121.6) / 16.0);
                  var13.y = (float)var26;
                  var20 = var7.readUnsignedByte();
                  var26 = var4.z * Math.exp((var20 - 121.6) / 16.0);
                  var13.z = (float)var26;
               }

               Point3Temp var16 = var0.getScale();
               var13.x = var13.x / var16.x;
               var13.y = var13.y / var16.y;
               var13.z = var13.z / var16.z;
               var0.scale(var13);
            }

            dontSend = false;
         }
      }
   }

   private static Point3Temp maxDecompressXY(Point3Temp var0, DataInputStream var1) throws IOException {
      int var2 = var1.readUnsignedByte();
      var2 <<= 4;
      int var3 = var1.readUnsignedByte();
      var2 |= var3 >>> 4;
      var3 &= 15;
      var3 <<= 8;
      var3 |= var1.readUnsignedByte();
      var0.x = var2;
      var0.y = var3;
      return var0;
   }

   private static Point3Temp minDecompressXYZ(Point3Temp var0, DataInputStream var1) throws IOException {
      int var3 = var1.readInt();
      int var4 = var1.readInt();
      int var2 = var3 >>> 10;
      var0.x = floatFrom21bits(var2);
      var2 = (var3 & 1023) << 11;
      var2 |= var4 >>> 21;
      var0.y = floatFrom21bits(var2);
      var2 = var4 & 2097151;
      var0.z = floatFrom21bits(var2);
      return var0;
   }

   private static float floatFrom21bits(int var0) {
      int var1 = var0 & 3;
      int var3 = (var0 & 1048576) << 11 | 1;
      int var2 = (var0 & -1048577) >>> 2;
      double var4 = Math.pow(10.0, var1 - 2);
      return (float)(var2 * var4 * var3);
   }
}

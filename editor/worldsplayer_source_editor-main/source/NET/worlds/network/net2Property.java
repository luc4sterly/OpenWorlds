package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;
import java.io.UTFDataFormatException;

public class net2Property {
   private int _propID;
   protected int _flags;
   protected int _access;
   protected String _stringValue;
   protected byte[] _binValue;

   public net2Property(int var1, int var2, int var3, byte[] var4) {
      this._propID = var1;
      this._flags = var2;
      this._access = var3;
      Debug.dAssert((var2 & 16) > 0);
      this._binValue = var4;
      this._stringValue = null;
   }

   public net2Property(int var1, int var2, int var3, String var4) {
      this._propID = var1;
      this._flags = var2;
      this._access = var3;
      Debug.dAssert((var2 & 16) == 0);
      this._stringValue = var4;
      this._binValue = null;
   }

   public net2Property() {
      this._propID = 0;
      this._flags = 0;
      this._access = 0;
      this._stringValue = null;
      this._binValue = null;
   }

   public int property() {
      return this._propID;
   }

   public int flags() {
      return this._flags;
   }

   public int access() {
      return this._access;
   }

   public byte[] data() {
      if ((this._flags & 16) > 0) {
         return this._binValue;
      }

      byte[] var1 = new byte[this._stringValue.length()];
      this._stringValue.getBytes(0, this._stringValue.length(), var1, 0);
      return var1;
   }

   public String value() {
      return (this._flags & 16) == 0 ? this._stringValue : new String(this._binValue, 0);
   }

   int packetSize() {
      if ((this._flags & 16) > 0) {
         Debug.dAssert(this._binValue != null);
         return 4 + this._binValue.length;
      } else {
         Debug.dAssert(this._stringValue != null);
         return 4 + ServerOutputStream.utfLength(this._stringValue);
      }
   }

   void parseNetData(ServerInputStream var1) throws IOException, UTFDataFormatException {
      this._propID = var1.readUnsignedByte();
      this._flags = var1.readUnsignedByte();
      this._access = var1.readUnsignedByte();
      if ((this._flags & 16) > 0) {
         int var2 = var1.readUnsignedByte();
         this._binValue = new byte[var2];
         var1.readFully(this._binValue);
         this._stringValue = null;
      } else {
         try {
            this._stringValue = var1.readUTF();
         } catch (UTFDataFormatException var3) {
            this._stringValue = "";
            throw var3;
         }

         this._binValue = null;
      }
   }

   void send(ServerOutputStream var1) throws IOException {
      var1.writeByte(this._propID);
      var1.writeByte(this._flags);
      var1.writeByte(this._access);
      if ((this._flags & 16) > 0) {
         var1.writeByte(this._binValue.length);
         var1.write(this._binValue);
      } else {
         var1.writeUTF(this._stringValue);
      }
   }

   private String flagString() {
      String var1 = "";
      if ((this._flags & 128) > 0) {
         var1 = var1 + "DBSTORE ";
      }

      if ((this._flags & 64) > 0) {
         var1 = var1 + "AUTOUPDATE ";
      }

      if ((this._flags & 32) > 0) {
         var1 = var1 + "FINGER ";
      }

      if ((this._flags & 16) > 0) {
         var1 = var1 + "BINARY ";
      }

      if (var1.length() == 0) {
         var1 = "NONE";
      }

      return var1;
   }

   private String accessString() {
      String var1 = "";
      if ((this._access & 1) > 0) {
         var1 = var1 + "POSSESS ";
      }

      if ((this._access & 2) > 0) {
         var1 = var1 + "PRIVATE ";
      }

      if (var1.length() == 0) {
         var1 = "NONE";
      }

      return var1;
   }

   public String toString() {
      String var1 = "#" + this._propID + " [" + this.flagString() + "/" + this.accessString() + "] ";
      if ((this._flags & 16) == 0) {
         return var1 + this._stringValue;
      }

      var1 = var1 + "val=[";

      for (int var2 = 0; var2 < this._binValue.length; var2++) {
         var1 = var1 + Integer.toString(this._binValue[var2], 16) + " ";
      }

      return var1 + "] (" + this._binValue + ")";
   }
}

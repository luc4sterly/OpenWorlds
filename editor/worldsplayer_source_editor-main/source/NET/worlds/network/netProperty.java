package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

public class netProperty {
   protected int _propID;
   protected String _value;

   public netProperty() {
      this._propID = 0;
   }

   public netProperty(int var1) {
      this._propID = var1;
   }

   public netProperty(int var1, String var2) {
      Debug.dAssert(var2 != null);
      this._propID = var1;
      this._value = var2;
   }

   public int property() {
      return this._propID;
   }

   public String value() {
      return this._value;
   }

   int packetSize() {
      return this._value != null ? 2 + ServerOutputStream.utfLength(this._value) : 0;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._propID = var1.readUnsignedByte();
      this._value = var1.readUTF();
   }

   void send(ServerOutputStream var1) throws IOException {
      var1.writeByte(this._propID);
      var1.writeUTF(this._value);
   }

   public String toString() {
      return netCmds.getPropName(this._propID) + "=" + this._value;
   }
}

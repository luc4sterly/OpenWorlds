package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;

public class ObjID {
   private int _shortObjID;
   private String _longObjID;

   public ObjID(int var1) {
      this._shortObjID = var1;
      this._longObjID = null;
   }

   public ObjID(String var1) {
      this._shortObjID = 0;
      if (var1.startsWith("!")) {
         var1 = var1.substring(1);
      }

      this._longObjID = var1;
   }

   public ObjID() {
      this._shortObjID = 0;
      this._longObjID = null;
   }

   public int shortID() {
      return this._shortObjID;
   }

   public String longID() {
      return this._longObjID;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._shortObjID = var1.readUnsignedByte();
      if (this._shortObjID == 0) {
         this._longObjID = var1.readUTF();
      }
   }

   int packetSize() {
      return this._longObjID != null ? 2 + ServerOutputStream.utfLength(this._longObjID) : 1;
   }

   void send(ServerOutputStream var1) throws IOException {
      if (this._longObjID != null) {
         var1.writeByte(0);
         var1.writeUTF(this._longObjID);
      } else {
         Debug.dAssert(this._shortObjID == 1 || this._shortObjID >= 253);
         var1.writeByte(this._shortObjID);
      }
   }

   public String toString(WorldServer var1) {
      return this._longObjID != null ? this._longObjID : Integer.toString(this._shortObjID) + "[" + var1.getLongID(this) + "]";
   }

   public String toString() {
      return this._longObjID != null ? this._longObjID : "[#" + Integer.toString(this._shortObjID) + "]";
   }
}

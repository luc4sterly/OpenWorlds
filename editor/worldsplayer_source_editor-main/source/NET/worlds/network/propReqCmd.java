package NET.worlds.network;

import java.io.IOException;
import java.util.Vector;

public class propReqCmd extends netPacket {
   public static final byte PROPREQCMD = 10;
   protected Vector _varids = new Vector();

   public propReqCmd(ObjID var1, int var2) {
      super(var1, 10);
      this.addProp(var2);
   }

   public propReqCmd(ObjID var1) {
      super(var1, 10);
   }

   public void addProp(int var1) {
      this._varids.addElement(new Integer(var1));
   }

   int packetSize() {
      return this._varids.size() + super.packetSize();
   }

   void send(ServerOutputStream var1) throws IOException {
      super.send(var1);
      int var2 = this._varids.size();

      for (int var4 = 0; var4 < var2; var4++) {
         Integer var3 = (Integer)this._varids.elementAt(var4);
         var1.writeByte(var3);
      }
   }

   public String toString(WorldServer var1) {
      String var2 = "PROPREQ  " + this._objID.toString(var1) + " ";
      int var3 = this._varids.size();

      for (int var4 = 0; var4 < var3; var4++) {
         var2 = var2 + " #" + (Integer)this._varids.elementAt(var4);
      }

      return var2;
   }
}

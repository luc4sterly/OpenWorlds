package NET.worlds.network;

import NET.worlds.core.Debug;
import java.io.IOException;
import java.io.UTFDataFormatException;
import java.util.Vector;

public class PropertyList {
   private Vector _propList = new Vector();

   public void addProperty(net2Property var1) {
      this._propList.addElement(var1);
   }

   public int size() {
      return this._propList.size();
   }

   public net2Property elementAt(int var1) {
      return (net2Property)this._propList.elementAt(var1);
   }

   public net2Property getProperty(int var1) {
      for (int var2 = this._propList.size() - 1; var2 >= 0; var2--) {
         if (this.elementAt(var2).property() == var1) {
            return this.elementAt(var2);
         }
      }

      return null;
   }

   void parseNetData(ServerInputStream var1) throws IOException {
      this._propList = new Vector();

      while (!var1.isEmpty()) {
         try {
            net2Property var2 = new net2Property();
            var2.parseNetData(var1);
            this._propList.addElement(var2);
         } catch (UTFDataFormatException var4) {
            System.out.println("Property list discarded; invalid UTF property.");
            this._propList.removeAllElements();
            var1.skipBytes(var1.bytesLeft());
            Debug.dAssert(var1.isEmpty());
            return;
         }
      }
   }

   int packetSize() {
      int var1 = 0;

      for (int var3 = this._propList.size() - 1; var3 >= 0; var3--) {
         net2Property var2 = (net2Property)this._propList.elementAt(var3);
         var1 += var2.packetSize();
      }

      return var1;
   }

   void send(ServerOutputStream var1) throws IOException {
      int var2 = this._propList.size();

      for (int var4 = 0; var4 < var2; var4++) {
         net2Property var3 = (net2Property)this._propList.elementAt(var4);
         var3.send(var1);
      }
   }

   public String toString() {
      String var1 = "(";
      int var2 = this._propList.size();

      for (int var4 = 0; var4 < var2; var4++) {
         net2Property var3 = (net2Property)this._propList.elementAt(var4);
         var1 = var1 + var3 + " ";
      }

      return var1 + ")";
   }
}

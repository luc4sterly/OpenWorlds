package NET.worlds.network;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Hashtable;

class ObjectMgr {
   private Hashtable nFlongID = new Hashtable();
   private Hashtable lFshortID = new Hashtable();
   private Galaxy _galaxy;

   ObjectMgr(Galaxy var1) {
      this._galaxy = var1;
   }

   void regShortID(int var1, String var2) {
      this.lFshortID.put(new Integer(var1), var2);
   }

   void regObject(String var1, NetworkObject var2) {
      this.nFlongID.put(var1, var2);
   }

   void regObject(ObjID var1, NetworkObject var2) {
      String var3 = this.getLongID(var1);
      this.nFlongID.put(var3, var2);
   }

   NetworkObject getObject(ObjID var1) {
      String var2 = this.getLongID(var1);
      NetworkObject var3 = (NetworkObject)this.nFlongID.get(var2);
      if (var3 == null) {
         Debug.dAssert(this._galaxy != null);
         var3 = this._galaxy.getObject(var2);
      }

      return var3;
   }

   void delObject(ObjID var1) {
      String var2 = this.getLongID(var1);
      NetworkObject var3 = (NetworkObject)this.nFlongID.get(var2);
      Debug.dAssert(var3 != null);
      this.nFlongID.remove(var2);
   }

   Enumeration objects() {
      return this.nFlongID.elements();
   }

   void clear() {
      this.nFlongID.clear();
      this.nFlongID = new Hashtable();
      this.lFshortID.clear();
      this.lFshortID = new Hashtable();
   }

   final String getLongID(ObjID var1) {
      String var2;
      if (var1.shortID() != 0) {
         var2 = (String)this.lFshortID.get(new Integer(var1.shortID()));
      } else {
         var2 = var1.longID();
      }

      return var2;
   }
}

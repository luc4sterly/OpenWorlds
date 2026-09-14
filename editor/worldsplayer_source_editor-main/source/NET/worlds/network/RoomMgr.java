package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import java.util.Enumeration;
import java.util.Hashtable;

class RoomMgr {
   Hashtable _roomFRoomID = new Hashtable();
   Hashtable _requestList = null;
   int _requestCount = 0;

   public RoomMgr() {
   }

   public synchronized void addRequest(String var1, NetworkRoom var2) {
      if (this._requestCount == 0) {
         this._requestList = new Hashtable();
      }

      Debug.dAssert(this._requestList.get(var1) == null);
      this._requestList.put(var1, var2);
      this._requestCount++;
   }

   public synchronized void delRequest(String var1) {
      if (this._requestList == null) {
         System.out.println(this + ": delRequest() - " + var1);
         new Exception().printStackTrace(System.out);
      } else {
         this._requestCount--;
         this._requestList.remove(var1);
         if (this._requestCount == 0) {
            this._requestList = null;
         }
      }
   }

   public synchronized NetworkRoom getRequest(String var1) {
      if (this._requestList == null) {
         return null;
      }

      NetworkRoom var2 = (NetworkRoom)this._requestList.get(var1);
      if (var2 != null) {
         this.delRequest(var1);
      }

      return var2;
   }

   public void regRoomID(int var1, NetworkRoom var2) {
      NetworkRoom var3 = (NetworkRoom)this._roomFRoomID.get(new Integer(var1));
      if (var3 != null && var3 != var2) {
         System.out.println("[" + Std.getRealTime() + "]: Weird - room is already registered.");
         System.out.println("new roomID = " + var1 + ", new room = " + var2);
         System.out.println(var2.debugStuff());
         System.out.println("old room is " + var3);
         System.out.println(var3.debugStuff());
         new Exception().printStackTrace(System.out);
      }

      this._roomFRoomID.put(new Integer(var1), var2);
   }

   public void delRoomID(int var1, NetworkRoom var2) {
      NetworkRoom var3 = (NetworkRoom)this._roomFRoomID.remove(new Integer(var1));
      if (var3 == null) {
         System.out.println("Error - deleting a bad roomID: " + var1);
         System.out.println(var2.debugStuff());
         new Exception().printStackTrace(System.out);
      }
   }

   public NetworkRoom getRoom(int var1) {
      return var1 == 0 ? null : (NetworkRoom)this._roomFRoomID.get(new Integer(var1));
   }

   public Enumeration rooms() {
      return this._roomFRoomID.elements();
   }
}

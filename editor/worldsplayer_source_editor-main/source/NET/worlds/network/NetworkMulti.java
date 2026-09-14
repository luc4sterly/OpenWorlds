package NET.worlds.network;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Vector;

public class NetworkMulti implements NetworkObject {
   String _longID;
   Vector _list;
   Galaxy _galaxy;

   public NetworkMulti(String var1, Galaxy var2) {
      this._longID = var1;
      this._list = new Vector();
      this._galaxy = var2;
      this.register();
   }

   public NetworkMulti(String var1, NetworkMulti var2, Galaxy var3) {
      this._longID = var1;
      this._list = var2.getList();
      this._galaxy = var3;
      this.register();
   }

   Vector getList() {
      return this._list;
   }

   public String getLongID() {
      return this._longID;
   }

   public WorldServer getServer() {
      Debug.dAssert(false);
      return null;
   }

   public Enumeration elements() {
      return this._list.elements();
   }

   void addObject(NetworkObject var1) {
      this._list.addElement(var1);
   }

   void delObject(NetworkObject var1) {
      boolean var2 = this._list.removeElement(var1);
      if (!var2) {
         System.out.println("Error - network object doesn't exist.");
         System.out.println("   obj = " + var1);
         System.out.println("   longID = " + this._longID);
         System.out.println("   galaxy = " + this._galaxy);
         System.out.println("  size(list) = " + this._list.size());
      }

      Debug.dAssert(var2);
   }

   public void property(OldPropertyList var1) {
      for (int var2 = this._list.size() - 1; var2 >= 0; var2--) {
         NetworkObject var3 = (NetworkObject)this._list.elementAt(var2);
         var3.property(var1);
      }
   }

   public void propertyUpdate(PropertyList var1) {
      for (int var2 = this._list.size() - 1; var2 >= 0; var2--) {
         NetworkObject var3 = (NetworkObject)this._list.elementAt(var2);
         var3.propertyUpdate(var1);
      }
   }

   public void register() {
      this._galaxy.regObject(this._longID, this);
   }

   public void galaxyDisconnected() {
      for (int var1 = this._list.size() - 1; var1 >= 0; var1--) {
         NetworkObject var2 = (NetworkObject)this._list.elementAt(var1);
         var2.galaxyDisconnected();
      }
   }

   public void reacquireServer(WorldServer var1) {
      for (int var2 = this._list.size() - 1; var2 >= 0; var2--) {
         NetworkObject var3 = (NetworkObject)this._list.elementAt(var2);
         var3.reacquireServer(var1);
      }
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
      for (int var4 = this._list.size() - 1; var4 >= 0; var4--) {
         NetworkObject var5 = (NetworkObject)this._list.elementAt(var4);
         var5.changeChannel(var1, var2, var3);
      }
   }
}

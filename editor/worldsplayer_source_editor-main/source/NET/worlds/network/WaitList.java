package NET.worlds.network;

import NET.worlds.core.Debug;
import java.util.Vector;

class WaitList {
   private Vector _waitList = new Vector();
   private Object _parent;

   protected WaitList(Object var1) {
      this._parent = var1;
   }

   protected synchronized void addWaiter(ConnectionWaiter var1) {
      if ((Galaxy.getDebugLevel() & 16384) > 0) {
         System.out.println(this._parent + ": waitForConnection(" + var1 + ")");
      }

      if (this._waitList.indexOf(var1) < 0) {
         this._waitList.addElement(var1);
      }
   }

   protected synchronized void abortWait(ConnectionWaiter var1) {
      Debug.dAssert(this._waitList.indexOf(var1) != -1);
      this._waitList.removeElement(var1);
   }

   protected synchronized void clear() {
      this._waitList = new Vector();
   }

   protected synchronized void notify(boolean var1) {
      if ((Galaxy.getDebugLevel() & 16384) > 0 && this._waitList.size() > 0) {
         System.out.println(this._parent + ": notify(" + var1 + ")");
      }

      for (int var2 = this._waitList.size() - 1; var2 >= 0; var2--) {
         ConnectionWaiter var3 = (ConnectionWaiter)this._waitList.elementAt(var2);
         if ((Galaxy.getDebugLevel() & 16384) > 0) {
            System.out.println("\tnotifying " + var3);
         }

         var3.connectionCallback(this._parent, var1);
         this._waitList.removeElementAt(var2);
      }
   }
}

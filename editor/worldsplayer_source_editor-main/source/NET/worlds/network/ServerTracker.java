package NET.worlds.network;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.Vector;

class ServerTracker {
   private Hashtable _serverHash = new Hashtable();
   private Vector _pendingOpenServers = new Vector();
   private Vector _activeServers = new Vector();
   private Vector _pendingCloseServers = new Vector();
   private Galaxy _galaxy;
   private ServerURL _serverURL;

   protected ServerTracker(Galaxy var1) {
      this._galaxy = var1;
      this._serverURL = this._galaxy.getServerURL();
   }

   public synchronized WorldServer getServer(String var1) throws InvalidServerURLException {
      if ((Galaxy.getDebugLevel() & 32) > 0) {
         System.out.println("Galaxy.getServer(" + var1 + ") from " + this._galaxy);
      }

      ServerURL var2 = new ServerURL(var1);
      WorldServer var3 = null;
      if (this._serverURL.getHost().equals(var2.getHost())) {
         var3 = this.getServer(this._activeServers, this);
         if (var3 == null) {
            var3 = this.getServer(this._pendingOpenServers, this);
         }
      }

      if (var3 == null) {
         var3 = this.findOrMake(var2, this);
      }

      var3.tmpRefCnt(this);
      return var3;
   }

   protected WorldServer getActive(Object var1) {
      return this.getServer(this._activeServers, var1);
   }

   protected synchronized WorldServer getServer(Vector var1, Object var2) {
      int var3 = var1.size() - 1;
      if (var3 >= 0) {
         WorldServer var4 = (WorldServer)var1.elementAt(var3);
         var4.incRefCnt(var2);
         return var4;
      } else {
         return null;
      }
   }

   private synchronized WorldServer findOrMake(ServerURL var1, Object var2) throws InvalidServerURLException {
      WorldServer var3 = (WorldServer)this._serverHash.get(var1.getHost());
      if (var3 == null) {
         int var4 = 0;
         var4 = Galaxy.getDebugLevel();
         if ((var4 & 32) > 0) {
            System.out.println("    Creating new server of type=" + var1.getType() + ".");
         }

         try {
            Class var11 = Class.forName("NET.worlds.network." + var1.getType());
            var3 = (WorldServer)var11.newInstance();
         } catch (Exception var9) {
            Exception var5 = var9;
            if ((var4 & 32) > 0) {
               synchronized (System.out) {
                  System.out.println("    Exception during class creation.");
                  var5.printStackTrace(System.out);
               }
            }

            throw new InvalidServerURLException("Bad class: " + var1.getType());
         }

         this._serverHash.put(var1.getHost(), var3);
         var3.initInstance(this._galaxy, var1);
      } else if ((Galaxy.getDebugLevel() & 32) > 0) {
         System.out.println("    Found old server.");
      }

      var3.incRefCnt(var2);
      return var3;
   }

   protected synchronized void swapServer(WorldServer var1, WorldServer var2) {
      String var3 = var1.getServerURL().getHost();
      Debug.dAssert(var3.equals(var2.getServerURL().getHost()));
      var3 = var1.getServerURL().getHost();
      this._serverHash.put(var3, var2);
      Debug.dAssert(!this._activeServers.contains(var1));
   }

   protected synchronized boolean isActive() {
      return this._activeServers.size() > 0 || this._pendingOpenServers.size() > 0 || this._pendingCloseServers.size() > 0;
   }

   protected synchronized boolean addPendingServer(WorldServer var1) {
      if ((Galaxy.getDebugLevel() & 8) > 0) {
         System.out.println(this._galaxy + ": addPendingServer(" + var1 + ")");
         System.out.println("\t_pendingOpen = " + this._pendingOpenServers);
         System.out.println("\t_activeServers = " + this._activeServers);
         System.out.println("\t_pendingClose = " + this._pendingCloseServers);
      }

      if (this._pendingOpenServers.indexOf(var1) < 0) {
         this._pendingOpenServers.addElement(var1);
      }

      return this._pendingOpenServers.size() == 1 && this._activeServers.size() == 0 && this._pendingCloseServers.size() == 0;
   }

   protected synchronized boolean addActiveServer(WorldServer var1) {
      if ((Galaxy.getDebugLevel() & 8) > 0) {
         System.out.println(this._galaxy + ": addActiveServer(" + var1 + ")");
         System.out.println("\t_pendingOpen = " + this._pendingOpenServers);
         System.out.println("\t_activeServers = " + this._activeServers);
         System.out.println("\t_pendingClose = " + this._pendingCloseServers);
      }

      this._pendingOpenServers.removeElement(var1);
      if (this._activeServers.indexOf(var1) < 0) {
         this._activeServers.addElement(var1);
      }

      return this._activeServers.size() == 1 && this._pendingCloseServers.size() == 0;
   }

   protected synchronized boolean addClosingServer(WorldServer var1) {
      if ((Galaxy.getDebugLevel() & 8) > 0) {
         System.out.println(this._galaxy + ": addClosingServer(" + var1 + ")");
         System.out.println("\t_pendingOpen = " + this._pendingOpenServers);
         System.out.println("\t_activeServers = " + this._activeServers);
         System.out.println("\t_pendingClose = " + this._pendingCloseServers);
      }

      this._pendingOpenServers.removeElement(var1);
      boolean var2 = this._activeServers.removeElement(var1);
      if (this._pendingCloseServers.indexOf(var1) < 0) {
         this._pendingCloseServers.addElement(var1);
      }

      return var2 && this._activeServers.size() == 0;
   }

   protected synchronized void markClosedServer(WorldServer var1) {
      if ((Galaxy.getDebugLevel() & 8) > 0) {
         System.out.println(this._galaxy + ": markClosedServer(" + var1 + ")");
         System.out.println("\t_pendingOpen = " + this._pendingOpenServers);
         System.out.println("\t_activeServers = " + this._activeServers);
         System.out.println("\t_pendingClose = " + this._pendingCloseServers);
      }

      this._pendingOpenServers.removeElement(var1);
      this._pendingCloseServers.removeElement(var1);
      this._activeServers.removeElement(var1);
   }

   protected synchronized void killServer(WorldServer var1) {
      if ((Galaxy.getDebugLevel() & 8) > 0) {
         System.out.println(this._galaxy + ": killServer(" + var1 + ")");
         System.out.println("\t_pendingOpen = " + this._pendingOpenServers);
         System.out.println("\t_activeServers = " + this._activeServers);
         System.out.println("\t_pendingClose = " + this._pendingCloseServers);
      }

      this._pendingOpenServers.removeElement(var1);
      this._pendingCloseServers.removeElement(var1);
      this._activeServers.removeElement(var1);
      if (this._serverHash.get(var1.getServerURL().getHost()) == var1) {
         this._serverHash.remove(var1.getServerURL().getHost());
      } else {
         System.out.println("DEBUG -- a server tried to murder another!");
         System.out.println("Caller = " + var1);
         System.out.println("Victim = " + this._serverHash.get(var1.getServerURL().getHost()));
         new Exception().printStackTrace();
      }
   }

   protected Enumeration getAllServers() {
      return this._serverHash.elements();
   }

   public String toString() {
      return "ServerTracker[\n\t_pendingOpen = "
         + this._pendingOpenServers
         + "\n\t_activeServers = "
         + this._activeServers
         + "\n\t_pendingClose = "
         + this._pendingCloseServers
         + "\n]";
   }
}

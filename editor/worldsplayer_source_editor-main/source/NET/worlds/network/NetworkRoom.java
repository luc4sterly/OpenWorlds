package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.scape.Room;
import NET.worlds.scape.RoomSubscribeInfo;
import NET.worlds.scape.World;

public class NetworkRoom implements NetworkObject, ConnectionWaiter {
   private static final int STATE_DISCONNECTED = 0;
   private static final int STATE_CONNECTING = 1;
   private static final int STATE_GETTINGROOMID = 2;
   private static final int STATE_CONNECTED = 3;
   private static final int STATE_SUBSCRIBED = 4;
   private static int _debugLevel = IniFile.gamma().getIniInt("roomdebug", 0);
   Room _room;
   String _worldName;
   String _roomName;
   String _longID;
   Galaxy _galaxy;
   String _debug1;
   String _debug2;
   private RoomSubscribeInfo _lastRSInfo = null;
   private URL _serverURL = null;
   private WorldServer _server = null;
   private int _roomID = 0;
   private boolean _wantsToBeSubscribed = false;
   private int _serverState = 0;

   public NetworkRoom(Room var1) {
      this._room = var1;
      this._debug1 = "";
      this._debug2 = "";
      this._galaxy = var1.getGalaxy();
      this.initNames();
      this.register();
   }

   synchronized void initNames() {
      this._roomName = this._room.getName();
      World var1 = this._room.getWorld();
      this._worldName = var1.getName();
      Galaxy var2 = this._room.getGalaxy();
      String var3 = var2.getChannel();
      if (var3.length() != 0) {
         var3 = "<" + var3 + ">";
      }

      this._longID = this._worldName + "#" + this._roomName + var3;
   }

   public Room getRoom() {
      return this._room;
   }

   public synchronized void setName(String var1) {
      Debug.dAssert(var1 != this._roomName);
      this.unregister();
      this.initNames();
      this.register();
   }

   void unregister() {
      Galaxy var1 = this._room.getGalaxy();
      Debug.dAssert(var1 != null);
      Debug.dAssert(this._galaxy == var1);
      var1.delObject(this._longID);
      if (this._roomID != 0) {
         var1.delRoomID(this._roomID, this);
      }

      this._debug2 = "";
      this._roomID = 0;
   }

   public synchronized void detach() {
      this.unregister();
      this._galaxy = null;
      this._room = null;
   }

   public String getLongID() {
      return this._longID;
   }

   public int getRoomID() {
      return this._roomID;
   }

   public boolean isServed() {
      return this._serverState == 4;
   }

   public synchronized void serverRedirect(WorldServer var1, String var2, ServerURL var3) {
      if (this._server != null) {
         if (var1.getGalaxy() == this._server.getGalaxy()) {
            if (var2.equals(this._longID)) {
               if ((_debugLevel & 2) > 0) {
                  System.out.println(this._room.getName() + ": serverRedirect(" + var3 + ")");
               }

               this._serverState = 3;
               int var4 = this._roomID;
               this.disconnect();
               Debug.dAssert(this._server == null);
               this._roomID = var4;
               this._debug2 = this._debug2 + "; [" + Std.getRealTime() + "]: serverDirect(" + var1 + ")";
               this._serverURL = URL.make(var3.toString());
               if (this._roomID != 0) {
                  this._room.getGalaxy().setRoomID(this._roomID, this);
               }

               if (this._wantsToBeSubscribed) {
                  this.acquireServer();
               }
            }
         }
      }
   }

   public synchronized void setRoomID(WorldServer var1, int var2, String var3, boolean var4) {
      Debug.dAssert(var1 != null);
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._longID + ": setRoomID(" + var1 + ", " + var2 + ", " + var3 + ", " + var4 + ")");
         System.out.println("last request made: " + this._debug1);
      }

      if (var1.getGalaxy() != this._server.getGalaxy()) {
         System.out.println(this._longID + ": setRoomID(" + var1 + ", " + var2 + ", " + var3 + ", " + var4 + ")");
         System.out.println("\twas expecting server " + this._server);
         System.out.println("last request made: " + this._debug1);
         new Exception().printStackTrace(System.out);
      }

      if (var1.getGalaxy() == this._server.getGalaxy()) {
         if (var3.equals(this._longID)) {
            if (var2 == 0) {
               this._serverState = 0;
               this.reacquireServer(var1);
            } else {
               if (this._roomID == 0) {
                  this._roomID = var2;
                  this._debug2 = this._debug2 + "; [" + Std.getRealTime() + "]: setRoomID(" + var1 + ", " + var4 + ")";
               }

               Debug.dAssert(this._roomID == var2);
               this._serverState = 3;
               if (!var4) {
                  if (this._wantsToBeSubscribed) {
                     Debug.dAssert(this._lastRSInfo != null);
                     this.subscribe();
                  } else {
                     this.disconnect();
                  }
               }
            }
         }
      }
   }

   public synchronized void subscribe(RoomSubscribeInfo var1) {
      Debug.dAssert(this._galaxy == this._room.getGalaxy());
      if ((_debugLevel & 1) > 0) {
         System.out.println(this._room.getName() + ": subscribe(Info)");
      }

      Debug.dAssert(this._room.getWorld() != null);
      Debug.dAssert(this._serverState != 4);
      this._lastRSInfo = var1;
      this._wantsToBeSubscribed = true;
      switch (this._serverState) {
         case 0:
            this.acquireServer();
            break;
         case 3:
            this.subscribe();
      }
   }

   private void subscribe() {
      if ((_debugLevel & 1) > 0) {
         System.out.println(this._room.getName() + ": subscribe()");
      }

      Debug.dAssert(this._server != null);
      Debug.dAssert(this._wantsToBeSubscribed);
      Debug.dAssert(this._lastRSInfo != null);
      Debug.dAssert(this._roomID != 0);
      Debug.dAssert(this._serverState == 3);
      Debug.dAssert(this._room.getWorld() != null);
      this._serverState = 4;
      this.sendNetworkMsg(new SubscribeRoomCmd(this._lastRSInfo, this._roomID));
   }

   private void sendNetworkMsg(netPacket var1) {
      Debug.dAssert(this._server != null);

      try {
         this._server.sendNetworkMsg(var1);
      } catch (InfiniteWaitException var3) {
         this.disconnect();
      } catch (PacketTooLargeException var4) {
         Debug.dAssert(false);
      }
   }

   public synchronized void subscribeDist(RoomSubscribeInfo var1) {
      this._lastRSInfo = var1;
      Debug.dAssert(this._wantsToBeSubscribed);
      Debug.dAssert(this._room.getWorld() != null);
      if (this._serverState == 4) {
         this.sendNetworkMsg(new SubscribeDistCmd(var1.d, this._roomID));
      }
   }

   public synchronized void unsubscribe() {
      if ((_debugLevel & 1) > 0) {
         System.out.println(this._room.getName() + ": unsubscribe()");
      }

      Debug.dAssert(this._wantsToBeSubscribed);
      this._wantsToBeSubscribed = false;
      this._lastRSInfo = null;
      switch (this._serverState) {
         case 0:
         case 3:
         default:
            break;
         case 1:
            Debug.dAssert(this._server != null);
            this._server.abortWaitForConnection(this);
            this.disconnect();
            break;
         case 2:
            this.disconnect();
            break;
         case 4:
            this.sendNetworkMsg(new UnsubscribeRoomCmd(this._roomID));
            this.disconnect();
      }
   }

   private synchronized void disconnect() {
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._room.getName() + ": disconnect()");
      }

      switch (this._serverState) {
         case 2:
            this._server.delRoomRequest(this._longID);
            if (this._debug1 == null) {
               this._debug1 = "";
            }

            this._debug1 = this._debug1 + "; [" + Std.getRealTime() + "]: deleted request for " + this._longID;
         default:
            this._serverURL = null;
            if (this._server != null && this._roomID != 0) {
               this._server.delRoomID(this._roomID, this);
            }

            this._roomID = 0;
            this._debug2 = "";
            if (this._server != null) {
               this._server.decRefCnt(this);
               this._server = null;
               this._serverState = 0;
            }

            Debug.dAssert(this._serverState == 0);
      }
   }

   private synchronized void acquireServer() {
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._room.getName() + ": acquireServer() - " + this._serverURL);
      }

      Debug.dAssert(this._serverState == 0);
      if (this._server == null) {
         World var1 = this._room.getWorld();
         Debug.dAssert(var1 != null);
         Galaxy var2 = var1.getConsole().getGalaxy();
         Debug.dAssert(var2 != null);
         if (this._serverURL == null) {
            this._serverURL = var1.getConsole().getGalaxyURL();
            if (this._serverURL == null) {
               return;
            }
         }

         try {
            this._server = var2.getServer(this._serverURL);
         } catch (InvalidServerURLException var4) {
            Console.println(">> " + var4.getMessage());
            this._serverURL = null;
            return;
         }

         if (this._server == null) {
            return;
         }

         this._server.incRefCnt(this);
      }

      this._serverState = 1;
      this._server.waitForConnection(this);
   }

   public void connectionCallback(Object var1, boolean var2) {
      if (var1 instanceof WorldServer) {
         WorldServer var3 = (WorldServer)var1;
         if ((_debugLevel & 2) > 0) {
            System.out.println(this._room.getName() + ": connectionCallback(" + var3 + ", connected=" + var2 + ")  _server=" + this._server);
         }

         if (this._server == var3) {
            if (!var2) {
               this.disconnect();
            } else {
               if (this._roomID == 0) {
                  synchronized (this) {
                     this._serverState = 2;
                     var3.requestRoomID(this._longID, this);
                     this._debug1 = "[" + Std.getRealTime() + "] " + var3 + ": requested roomID for " + this._longID;
                  }
               } else {
                  this.setRoomID(var3, this._roomID, this._longID, false);
               }
            }
         }
      }
   }

   public void property(OldPropertyList var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         netProperty var3 = var1.elementAt(var2);
         byte[] var4 = new byte[var3.value().length()];
         var3.value().getBytes(0, var3.value().length(), var4, 0);
         this._room.getSharer().setFromNetData(var3.property(), var4);
      }
   }

   public void propertyUpdate(PropertyList var1) {
      for (int var2 = 0; var2 < var1.size(); var2++) {
         net2Property var3 = var1.elementAt(var2);
         this._room.getSharer().setFromNetData(var3.property(), var3.data());
      }
   }

   public WorldServer getServer() {
      return this._server;
   }

   public void register() {
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._room.getName() + ": register()");
      }

      Debug.dAssert(this._room.getWorld() != null);
      Galaxy var1 = this._room.getGalaxy();
      Debug.dAssert(var1 != null);
      var1.regObject(this._longID, this);
      this._galaxy = var1;
      if (this._serverState != 0) {
         this.disconnect();
      }

      this._serverURL = null;
      if (this._wantsToBeSubscribed) {
         this.acquireServer();
      }
   }

   public void galaxyDisconnected() {
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._room.getName() + ": galaxyDisconnected()");
      }

      synchronized (this) {
         if (this._server != null) {
            this.reacquireServer(this._server);
         }
      }
   }

   public void reacquireServer(WorldServer var1) {
      if (this._debug1 == null) {
         this._debug1 = "";
      }

      this._debug1 = this._debug1 + "; [" + Std.getRealTime() + "]: reacquireServer(" + this._server + ", " + var1 + ")";
      if (this._server == var1) {
         if ((_debugLevel & 2) > 0) {
            System.out.println(this._room.getName() + ": reacquireServer()");
         }

         this.disconnect();
         if (this._wantsToBeSubscribed) {
            this.acquireServer();
         }
      }
   }

   public synchronized void changeChannel(Galaxy var1, String var2, String var3) {
      if ((_debugLevel & 2) > 0) {
         System.out.println(this._room.getName() + ": changeChannel(" + var2 + " -> " + var3 + ")");
      }

      boolean var4 = this._wantsToBeSubscribed;
      RoomSubscribeInfo var5 = this._lastRSInfo;
      if (var4) {
         this.unsubscribe();
      }

      var1.delObject(this._longID);
      this.initNames();
      this.register();
      if (var4) {
         this.subscribe(var5);
      }
   }

   public String toString() {
      return "NetworkRoom[" + this._room.getName() + "]";
   }

   public String debugStuff() {
      return this + ": debug1 = " + this._debug1 + "\n\tdebug2 = " + this._debug2;
   }

   static {
      if (_debugLevel > 0) {
         System.out.println("ROOM DEBUGGING LEVEL = " + _debugLevel);
      }
   }
}

package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.DialogReceiver;
import NET.worlds.console.InternetConnectionDialog;
import NET.worlds.console.LoginWizard;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import java.util.Enumeration;
import java.util.Hashtable;

public class Galaxy implements DialogReceiver {
   private static Hashtable _galaxyHash = new Hashtable();
   private static boolean _globalUserAllowsOnline = true;
   private boolean _localUserAllowsOnline = true;
   private ServerURL _serverURL;
   private int _serverType;
   private Hashtable _serverHash;
   private int _worldCount;
   private Hashtable _nFlongID;
   private ServerTracker _serverTracker;
   private RoomMgr _roomTable;
   private String _channel;
   private String _username;
   private String _usernameU;
   private String _password;
   private String _serial;
   private String _newUsername;
   private String _newPassword;
   private int _mode;
   private NetworkMulti _consoleList;
   private int _retriesLeft = 2;
   private InternetConnectionDialog _icd;
   private LoginWizard _wizard;
   private Object _wizardMutex = new Object();
   private static int _debugLevel = IniFile.gamma().getIniInt("netdebug", 0);
   private WaitList _waiters;
   private boolean _relogin;
   private boolean _onlineEnabled;
   private boolean _online;
   private boolean sentFriendsList;
   private int protocolLevel;

   private Galaxy(ServerURL var1) {
      this._serverURL = var1;
      this._serverHash = new Hashtable();
      this._serverType = 0;
      this._nFlongID = new Hashtable();
      this._worldCount = 0;
      this._channel = "";
      this._serverTracker = new ServerTracker(this);
      this._waiters = new WaitList(this);
      this._username = "";
      this._usernameU = "";
      this._consoleList = new NetworkMulti(this._username, this);
      this.regObject(this._username, this._consoleList);
      if (var1 == null) {
         this._onlineEnabled = false;
         this._online = false;
      } else {
         this._onlineEnabled = true;
         this._online = false;
      }

      this.setOnlineState(this._onlineEnabled, this._online);
   }

   private synchronized void incWorldCount() {
      this._worldCount++;
   }

   public synchronized void decWorldCount() {
      this._worldCount--;
      Debug.dAssert(this._worldCount >= 0);
      if (this._worldCount <= 0) {
         if (this._serverURL != null) {
            _galaxyHash.remove(this._serverURL.getHost());
         }

         this._waiters.clear();
         this._serverTracker = new ServerTracker(this);
      }
   }

   public static Galaxy getGalaxy(String var0) throws InvalidServerURLException {
      ServerURL var1 = new ServerURL(var0);
      String var2 = var1.getHost();
      Galaxy var3 = (Galaxy)_galaxyHash.get(var2);
      if (var3 == null) {
         var3 = new Galaxy(var1);
         _galaxyHash.put(var2, var3);
      }

      Debug.dAssert(var3 != null);
      var3.incWorldCount();
      return var3;
   }

   public static Galaxy getGalaxy(URL var0) throws InvalidServerURLException {
      return getGalaxy(var0.unalias());
   }

   public static Galaxy getAnonGalaxy() {
      Galaxy var0 = new Galaxy(null);
      var0.incWorldCount();
      return var0;
   }

   public boolean isAnonymous() {
      return this._serverURL == null;
   }

   public WorldServer getServer(String var1) throws InvalidServerURLException {
      if (this._serverURL == null) {
         return null;
      }

      if (!_globalUserAllowsOnline) {
         return null;
      }

      if (!this._localUserAllowsOnline) {
         return null;
      }

      if (this._icd != null) {
         return null;
      }

      synchronized (this._wizardMutex) {
         if (this._wizard != null && !this._wizard.waitingForConnection() && !this._wizard.safeToQueryServer()) {
            return null;
         }
      }

      return this._serverTracker.getServer(var1);
   }

   public WorldServer getServer(URL var1) throws InvalidServerURLException {
      return this.getServer(var1.unalias());
   }

   public boolean isActive() {
      return this._serverTracker.isActive();
   }

   protected boolean addPendingServer(WorldServer var1) {
      Debug.dAssert(var1 != null);
      boolean var2 = this._serverTracker.addPendingServer(var1);
      if (var2) {
         this._retriesLeft = 2;
         this.setOnlineState(true, true);
         synchronized (this) {
            this._roomTable = new RoomMgr();
         }
      }

      return var2;
   }

   void addActiveServer(WorldServer var1) {
      boolean var2 = this._serverTracker.addActiveServer(var1);
      if (var2) {
         this._waiters.notify(true);
         if (this._wizard != null) {
            System.out.println("LWDB: calling " + this._wizard + " setConnected");
            this._wizard.setConnected();
         }
      }
   }

   boolean addClosingServer(WorldServer var1) {
      Debug.dAssert(this._nFlongID != null);
      Debug.dAssert(var1 != null);
      boolean var2 = this._serverTracker.addClosingServer(var1);
      if (var2) {
         this.forceDisconnect();
      }

      return var2;
   }

   void markClosedServer(WorldServer var1) {
      this._serverTracker.markClosedServer(var1);
   }

   void killServer(WorldServer var1) {
      this._serverTracker.killServer(var1);
   }

   protected void noteServerDeath(VarErrorException var1) {
      synchronized (this._serverTracker) {
         if (!this._serverTracker.isActive()) {
            synchronized (this) {
               this._roomTable = null;
            }

            this.setOnlineState(false, false);
            if (this.getProtocol() == 0) {
               this._icd = new InternetConnectionDialog(this, var1);
            } else {
               if (var1 != null && (!var1.getStatusFlag() || this._relogin)) {
                  _globalUserAllowsOnline = true;
                  boolean var3 = false;
                  synchronized (this._serverTracker) {
                     Enumeration var5 = this._serverTracker.getAllServers();

                     while (var5.hasMoreElements()) {
                        WorldServer var6 = (WorldServer)var5.nextElement();
                        if (var6.useBackupServer()) {
                           var3 = true;
                        }
                     }
                  }

                  if (var3) {
                     System.out.println("Server death noted, trying alternate.");
                     this.setChatname(this._username);
                     this.goOnline();
                  } else {
                     System.out.println("Server death noted, no more alternates. How sad.");
                     if (this._retriesLeft <= 0 || !this._relogin && !var1.getRetryFlag()) {
                        this.setChatname("");
                        this.killZombies();
                        if (this._wizard == null) {
                           this._wizard = new LoginWizard(this, this.getIniSection(), var1.getMsg());
                           System.out.println("LWDB: brought up " + this._wizard + " error " + var1.getMsg());
                        } else {
                           System.out.println("LWDB: reporting error " + var1.getMsg() + " to " + this._wizard);
                           this._wizard.loginError(var1.getMsg());
                        }
                     } else {
                        System.out.println(this + ": doing retry on " + var1);
                        this._retriesLeft = this._retriesLeft - var1.getRetryCount();
                        this.setChatname(this._username);
                        this.goOnline();
                     }
                  }

                  this._relogin = false;
               } else {
                  this.setOnlineState(true, false);
               }
            }
         }
      }
   }

   public void waitForConnection(ConnectionWaiter var1) {
      this._waiters.addWaiter(var1);
   }

   public void goOffline(boolean var1) {
      this._relogin = var1;
      if (!this._serverTracker.isActive()) {
         this._relogin = false;
      }

      synchronized (this._serverTracker) {
         Enumeration var3 = this._serverTracker.getAllServers();

         while (var3.hasMoreElements()) {
            WorldServer var4 = (WorldServer)var3.nextElement();
            var4.forceOffline();
         }
      }
   }

   private void killZombies() {
      synchronized (this._serverTracker) {
         Enumeration var2 = this._serverTracker.getAllServers();

         while (var2.hasMoreElements()) {
            ((WorldServer)var2.nextElement()).killZombies();
         }
      }
   }

   void goOnline() {
      synchronized (this._serverTracker) {
         Enumeration var2 = this._serverTracker.getAllServers();

         while (var2.hasMoreElements()) {
            WorldServer var3 = (WorldServer)var2.nextElement();
            var3.goOnline();
         }
      }

      this.reacquireServer(null);
   }

   public static synchronized void forceOffline(boolean var0) {
      if (_globalUserAllowsOnline) {
         _globalUserAllowsOnline = false;
         synchronized (_galaxyHash) {
            Enumeration var2 = _galaxyHash.elements();

            while (var2.hasMoreElements()) {
               Galaxy var3 = (Galaxy)var2.nextElement();
               var3.goOffline(var0);
            }
         }
      }
   }

   public void localForceOnline() {
      _globalUserAllowsOnline = true;
      this._relogin = false;
      if (!this.isActive()) {
         this.setOnlineState(false, false);
         this._localUserAllowsOnline = true;
         if (this.getGalaxyType() != 0) {
            this.setChatname("");
            this._wizard = new LoginWizard(this, this.getIniSection());
            System.out.println("LWDB: brought up " + this._wizard + " in localForceOnline");
         } else {
            this.reacquireServer(null);
         }
      }
   }

   public static int getDebugLevel() {
      return _debugLevel;
   }

   public static void printDebugging() {
      System.out.println("----GALAXY DEBUGGING-------");
      Enumeration var0 = _galaxyHash.elements();

      while (var0.hasMoreElements()) {
         Galaxy var1 = (Galaxy)var0.nextElement();
         System.out.println(var1 + " : ");
         System.out.println(var1._serverTracker);
      }

      System.out.println("---------------------------");
   }

   public String getChannel() {
      return this._channel;
   }

   void setChannel(String var1) {
      this.changeChannel(var1, false);
   }

   public void changeChannel(String var1) {
      if (var1 == null) {
         var1 = "";
      }

      var1 = var1.replace(' ', '_');
      var1 = var1.replace('<', '{');
      var1 = var1.replace('>', '}');
      this.changeChannel(var1, true);
   }

   private void changeChannel(String var1, boolean var2) {
      if (!var1.equals(this._channel)) {
         String var3 = this._channel;
         this._channel = var1;
         Hashtable var4 = (Hashtable)this._nFlongID.clone();
         Enumeration var5 = var4.elements();

         while (var5.hasMoreElements()) {
            NetworkObject var6 = (NetworkObject)var5.nextElement();
            Debug.dAssert(var6 != null);
            var6.changeChannel(this, var3, this._channel);
         }

         if (var2) {
            WorldServer var10 = this._serverTracker.getActive(this);
            if (var10 != null) {
               var10.tmpRefCnt(this);

               try {
                  var10.sendNetworkMsg(new ChannelCmd(var1));
               } catch (PacketTooLargeException var8) {
                  Debug.dAssert(false);
               } catch (InfiniteWaitException var9) {
               }
            }
         }
      }
   }

   public ServerURL getServerURL() {
      return this._serverURL;
   }

   public String toString() {
      return this._serverURL == null ? "AnonGalaxy=" + super.toString() : "Galaxy[" + this._serverURL + "]";
   }

   void swapServer(WorldServer var1, WorldServer var2) {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".swapServer(" + var1 + ", " + var2 + ")");
      }

      this._serverTracker.swapServer(var1, var2);
      this.reacquireServer(var1);
   }

   void reacquireServer(WorldServer var1) {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".reacquireServer(" + var1 + ")");
      }

      Enumeration var2 = this._nFlongID.elements();

      while (var2.hasMoreElements()) {
         ((NetworkObject)var2.nextElement()).reacquireServer(var1);
      }
   }

   public void regObject(String var1, NetworkObject var2) {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".regObject(" + var1 + ", " + var2 + ")");
      }

      this._nFlongID.put(var1, var2);
   }

   public NetworkObject getObject(String var1) {
      return (NetworkObject)this._nFlongID.get(var1);
   }

   public void delObject(String var1) {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".delObject(" + var1 + ")");
      }

      this._nFlongID.remove(var1);
   }

   public void forceObjectRereg() {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".forceObjectRereg()");
      }

      Hashtable var1 = this._nFlongID;
      this._nFlongID = new Hashtable();
      Enumeration var2 = var1.elements();

      while (var2.hasMoreElements()) {
         ((NetworkObject)var2.nextElement()).register();
      }
   }

   private void forceDisconnect() {
      if ((_debugLevel & 8192) > 0) {
         System.out.println(this + ".forceDisconnect()");
      }

      Enumeration var1 = this._nFlongID.elements();

      while (var1.hasMoreElements()) {
         NetworkObject var2 = (NetworkObject)var1.nextElement();
         Debug.dAssert(var2 != null);
         var2.galaxyDisconnected();
      }
   }

   void addRoomRequest(String var1, NetworkRoom var2) {
      Debug.dAssert(this._roomTable != null);
      this._roomTable.addRequest(var1, var2);
   }

   void delRoomRequest(String var1) {
      if (this._roomTable != null) {
         this._roomTable.delRequest(var1);
      }
   }

   NetworkRoom regRoomID(int var1, String var2) {
      Debug.dAssert(this._roomTable != null);
      NetworkRoom var3 = this._roomTable.getRequest(var2);
      if (var1 != 0 && var3 != null) {
         this._roomTable.regRoomID(var1, var3);
      }

      return var3;
   }

   public void setRoomID(int var1, NetworkRoom var2) {
      Debug.dAssert(this._roomTable != null);
      Debug.dAssert(var1 != 0);
      Debug.dAssert(var2 != null);
      this._roomTable.regRoomID(var1, var2);
   }

   void delRoomID(int var1, NetworkRoom var2) {
      if (this._roomTable != null) {
         this._roomTable.delRoomID(var1, var2);
      }
   }

   NetworkRoom getRoom(int var1) {
      return this._roomTable == null ? null : this._roomTable.getRoom(var1);
   }

   void setGalaxyType(int var1) {
      this._serverType = var1;
      if (_globalUserAllowsOnline) {
         this.setOnlineState(false, this._online);
         this.setChatname("");
         this._wizard = new LoginWizard(this, this.getIniSection());
         System.out.println("LWDB: brought up " + this._wizard + " in setGalaxyType");
      }
   }

   public int getGalaxyType() {
      return this._serverType;
   }

   public synchronized void setAuthInfo(String var1, String var2, String var3, String var4, String var5, int var6) {
      _globalUserAllowsOnline = true;
      this._localUserAllowsOnline = true;
      Debug.dAssert(this._serverType != 0);
      this.setUsernameU(var1);
      this.setChatname(var1);
      this._newUsername = var2;
      this._password = var3;
      this._newPassword = var4;
      this._serial = var5;
      this._mode = var6;
      switch (this._serverType) {
         case 1:
            switch (this._mode) {
               case 1:
               default:
                  break;
               case 2:
                  this._serial = null;
                  break;
               case 3:
                  this._password = null;
                  this._serial = null;
            }

            Debug.dAssert(this._mode != 4);
            break;
         case 3:
            Debug.dAssert(false);
            break;
         case 4:
            Debug.dAssert(this._mode == 2);
         case 2:
            Debug.dAssert(this._mode != 1);
            Debug.dAssert(this._mode != 4);
            if (this._password != null && this._password.length() != 0) {
               System.out.println(this + ": Password shouldn't be specified.");
            }

            this._password = null;
            if (this._serial != null && this._serial.length() != 0) {
               System.out.println(this + ": Serial number shouldn't be specified.");
            }

            this._serial = null;
      }

      this.goOnline();
   }

   public String getSerialNum() {
      return this._serial;
   }

   public String getPassword() {
      return this._password;
   }

   String getNewPassword() {
      return this._newPassword;
   }

   public String getChatname() {
      return this._username;
   }

   String getNewChatname() {
      return this._newUsername;
   }

   String getGuestExpiration() {
      Debug.dAssert(false);
      return null;
   }

   public int getLoginMode() {
      return this._mode;
   }

   void setOnlineState(boolean var1, boolean var2) {
      synchronized (this) {
         this._onlineEnabled = var1;
         this._online = var2;
      }

      synchronized (this._consoleList) {
         Enumeration var4 = this.getConsoles();

         while (var4.hasMoreElements()) {
            Console var5 = (Console)var4.nextElement();
            var5.setOnlineState(var1, var2);
         }
      }
   }

   public boolean getOnlineEnabled() {
      return this._onlineEnabled;
   }

   public boolean getOnline() {
      return this._online;
   }

   void setPassword(String var1) {
      this._password = var1;
   }

   void setNewPassword(String var1) {
      this._newPassword = var1;
   }

   void setNewChatname(String var1) {
      this._newUsername = var1;
   }

   void setSerialNum(String var1) {
      this._serial = var1;
   }

   public void setUsernameU(String var1) {
      this._usernameU = var1;
   }

   public String getUsernameU() {
      return this._usernameU;
   }

   void setChatname(String var1) {
      synchronized (this) {
         this._consoleList = new NetworkMulti(var1, this._consoleList, this);
         if (this._username != null) {
            this.delObject(this._username);
         }

         this.regObject(var1, this._consoleList);
         this._username = var1;
      }

      synchronized (this._consoleList) {
         Enumeration var3 = this.getConsoles();

         while (var3.hasMoreElements()) {
            Console var4 = (Console)var3.nextElement();
            var4.setChatname(this._username);
         }
      }

      synchronized (this._serverTracker) {
         Enumeration var11 = this._serverTracker.getAllServers();

         while (var11.hasMoreElements()) {
            WorldServer var12 = (WorldServer)var11.nextElement();
            var12.regShortID(1, this._username);
         }
      }
   }

   public IniFile getIniSection() {
      if (this._serverURL == null) {
         return new IniFile("UNSHARED");
      }

      if (this._serverURL.getHost().equals("www.3dcd.com:6650")) {
         IniFile var1 = new IniFile("209.67.68.214:6650");
         if (var1.getIniString("User0", "").length() != 0) {
            return var1;
         }
      }

      return new IniFile(this._serverURL.getHost());
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var1 instanceof LoginWizard) {
         synchronized (this._wizardMutex) {
            System.out.println("LWDB: setting who " + var1 + " wiz " + this._wizard + " to null");
            this._wizard = null;
         }

         if (!var2) {
            this.setOnlineState(true, false);
            this._localUserAllowsOnline = false;
         } else {
            this._localUserAllowsOnline = true;
            _globalUserAllowsOnline = true;
         }
      } else if (var1 instanceof InternetConnectionDialog) {
         this._icd = null;
         if (!var2) {
            this.setOnlineState(true, false);
            this._localUserAllowsOnline = false;
         } else {
            this._localUserAllowsOnline = true;
            _globalUserAllowsOnline = true;
            this.reacquireServer(null);
         }
      } else {
         Debug.dAssert(false);
      }
   }

   public void addConsole(Console var1) {
      Debug.dAssert(this._consoleList != null);
      this._consoleList.addObject(var1);
      this.setOnlineState(this._onlineEnabled, this._online);
   }

   public void delConsole(Console var1) {
      Debug.dAssert(this._consoleList != null);
      this._consoleList.delObject(var1);
   }

   public Enumeration getConsoles() {
      return this._consoleList.elements();
   }

   public void sentFriendsList(boolean var1) {
      this.sentFriendsList = var1;
   }

   public boolean sentFriendsList() {
      return this.sentFriendsList;
   }

   public int getProtocol() {
      return this.protocolLevel;
   }

   void setProtocol(int var1) {
      this.protocolLevel = var1;
   }

   static {
      if (_debugLevel > 0) {
         System.out.println("NETWORK DEBUGGING LEVEL = " + _debugLevel);
      }
   }
}

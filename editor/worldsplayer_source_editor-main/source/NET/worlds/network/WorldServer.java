package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.MainTerminalCallback;
import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import NET.worlds.scape.Drone;
import NET.worlds.scape.WObject;
import java.io.ByteArrayOutputStream;
import java.io.EOFException;
import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Vector;

public class WorldServer implements MainCallback, MainTerminalCallback, NetworkObject {
   protected int _serverProtocolVersion;
   protected ServerURL _serverURL = null;
   protected String _clientVersion = Std.getClientVersion();
   protected WSConnecting _connectThread;
   protected OutputStream _ostr = null;
   protected Socket _sock = null;
   protected netPacketReader _reader = null;
   private WaitList _waiters;
   protected int _refCnt = 0;
   protected int _tmpRefCnt = 0;
   protected boolean _isMainRegistered = false;
   protected ObjectMgr _objTable = null;
   protected Galaxy _galaxy = null;
   protected SMState _state;
   protected boolean _firstLogon = false;
   protected boolean _requestOffline = false;
   private int _lastAccessTime = 0;
   protected int _retriesLeft = 5;
   protected VarErrorException _lastError = null;
   protected int _retryTimeout = 60000;
   private int _lastMsgProcCnt = 5;
   protected PropertyList _propList = null;
   protected int _updateTime = 2000;
   Vector _backupServers;
   String _currentBackupServer;
   private static final int STATE_DEAD = -1;
   protected static final int STATE_PRECONNECTED = 0;
   private static final int STATE_AUTHPROMPT = 1;
   private static final int STATE_AUTHREPLY = 2;
   protected static final int STATE_INITIALIZING = 3;
   private static final int STATE_CONNECTING = 4;
   private static final int STATE_XMIT_PROPREQ = 5;
   private static final int STATE_RCV_PROPS = 6;
   protected static final int STATE_XMIT_SI = 7;
   static final int STATE_RCV_SI_ACK = 8;
   static final int STATE_XMIT_AI = 9;
   static final int STATE_RCV_AI_ACK = 10;
   static final int STATE_XMIT_PROPS = 11;
   static final int STATE_MAINLOOP = 12;
   private static final int STATE_XMIT_AE = 13;
   private static final int STATE_RCV_AE_ACK = 14;
   private static final int STATE_XMIT_SE = 15;
   static final int STATE_RCV_SE_ACK = 16;
   static final int STATE_DETACHING = 17;
   static final int STATE_DISCONNECTED = 18;
   static final int STATE_SLEEPING = 19;
   private Vector _referrerList = new Vector();
   private String _scriptServer;
   private String _smtpServer;
   private String _mailDomain;
   private int _lastWhisperTick = 0;
   private int _whisperCnt = 0;
   private Vector zombies;

   protected WorldServer() {
      this._serverProtocolVersion = 24;
      this._state = new SMState(this, 0);
      this._currentBackupServer = null;
      this._backupServers = new Vector();
   }

   public void regShortID(int var1, String var2) {
      Debug.dAssert(var1 < 253);
      this._objTable.regShortID(var1, var2);
   }

   public NetworkObject getObject(ObjID var1) {
      return this._objTable.getObject(var1);
   }

   public void delObject(ObjID var1) {
      this._objTable.delObject(var1);
   }

   public void regObject(ObjID var1, NetworkObject var2) {
      this._objTable.regObject(var1, var2);
   }

   public void regObject(String var1, NetworkObject var2) {
      this._objTable.regObject(new ObjID(var1), var2);
   }

   public String getLongID(ObjID var1) {
      return this._objTable.getLongID(var1);
   }

   public InetAddress getLocalAddress() {
      return this._sock != null ? this._sock.getLocalAddress() : null;
   }

   public Galaxy getGalaxy() {
      return this._galaxy;
   }

   ServerURL getServerURL() {
      return this._serverURL;
   }

   void initInstance(Galaxy var1, ServerURL var2) {
      this._galaxy = var1;
      this._serverURL = var2;
      this._objTable = new ObjectMgr(this._galaxy);
      this._waiters = new WaitList(this);
   }

   public net2Property getProperty(int var1) {
      return this._propList.getProperty(var1);
   }

   public int getUpdateTime() {
      return this._updateTime;
   }

   void setUsername(String var1) {
      if ((getDebugLevel() & 4) > 0) {
         System.out.println(this + ": Server requested username change to " + var1);
      }

      this._galaxy.setChatname(var1);
      this.regShortID(1, var1);
   }

   public synchronized void printReferrers() {
      System.out.println("[" + Std.getRealTime() + "] " + this + ": Referrer list -");

      for (int var1 = this._referrerList.size() - 1; var1 >= 0; var1--) {
         Object var2 = this._referrerList.elementAt(var1);
         System.out.println("\t" + var2);
      }

      System.out.println(this + ": Referrer list complete.");
   }

   public synchronized Vector printDroneReferrers() {
      Vector var1 = new Vector();

      for (int var2 = this._referrerList.size() - 1; var2 >= 0; var2--) {
         Object var3 = this._referrerList.elementAt(var2);
         if (var3.toString().startsWith("!")) {
            var1.addElement(var3.toString());
         }
      }

      return var1;
   }

   public synchronized void incRefCnt(Object var1) {
      if (this._refCnt == 0 && !this._isMainRegistered) {
         Main.register(this);
         this._isMainRegistered = true;
      }

      this._lastAccessTime = Std.getFastTime();
      this._refCnt++;
      Debug.dAssert(!this._referrerList.removeElement(var1));
      this._referrerList.addElement(var1);
      if ((getDebugLevel() & 4096) > 0) {
         System.out.println(this + ": incRefCnt to " + this._refCnt + " by " + var1);
      }
   }

   public synchronized void tmpRefCnt(Object var1) {
      this._tmpRefCnt++;
      boolean var2 = this._referrerList.removeElement(var1);
      Debug.dAssert(var2);
   }

   public synchronized void decRefCnt(Object var1) {
      this._refCnt--;
      boolean var2 = this._referrerList.removeElement(var1);
      Debug.dAssert(var2);
      if ((getDebugLevel() & 4096) > 0) {
         System.out.println(this + ": decRefCnt to " + this._refCnt + " by " + var1);
      }

      Debug.dAssert(this._refCnt >= 0);
   }

   int getRefCnt() {
      return this._refCnt;
   }

   public int getVersion() {
      return this._serverProtocolVersion;
   }

   public void setVersion(int var1) {
      this._galaxy.setProtocol(var1);
      this._serverProtocolVersion = var1;
      if (var1 < 18) {
         System.out.println(this + ": WARNING: Old server running protocol #17!");
      }
   }

   public static int getDebugLevel() {
      return Galaxy.getDebugLevel();
   }

   public void sendNetworkMsg(netPacket var1) throws InfiniteWaitException, PacketTooLargeException {
      synchronized (this._state) {
         Debug.dAssert(this._refCnt != 0 || this._state.getState() != -1);
         if (this._state.getState() != 12) {
            throw new InfiniteWaitException();
         }

         this.sendNetMsg(var1);
      }
   }

   public int getServerType() {
      if (this._propList == null) {
         return 1;
      }

      net2Property var1 = this._propList.getProperty(15);
      int var2 = 0;

      try {
         var2 = Integer.parseInt(var1.value());
      } catch (NumberFormatException var4) {
         Debug.dAssert(false);
      }

      return var2;
   }

   private void setScriptServer(String var1) {
      if (!var1.endsWith("/")) {
         var1 = var1 + "/";
      }

      this._scriptServer = var1;
   }

   public String getScriptServer() {
      return this._scriptServer;
   }

   private void setSmtpServer(String var1) {
      this._smtpServer = var1;
   }

   public String getSmtpServer() {
      return this._smtpServer;
   }

   private void setMailDomain(String var1) {
      this._mailDomain = var1;
   }

   public String getMailDomain() {
      return this._mailDomain;
   }

   void sendNetMsg(netPacket var1) throws PacketTooLargeException {
      Debug.dAssert(var1 != null);
      if ((getDebugLevel() & 128) > 0) {
         System.out.println("[" + Std.getRealTime() + "] " + this + ": send(" + var1.toString(this) + ")");
      }

      if (this._ostr != null) {
         try {
            ByteArrayOutputStream var2 = new ByteArrayOutputStream(256);
            ServerOutputStream var14 = new ServerOutputStream(var2);
            var1.send(var14);
            if ((getDebugLevel() & 1024) > 0) {
               byte[] var4 = var2.toByteArray();
               int var5 = var4[0] & 255;
               synchronized (System.out) {
                  System.out.print(this + ": send[");

                  for (int var7 = 0; var7 < var5; var7++) {
                     System.out.print(Integer.toString(var4[var7] & 255, 16) + " ");
                  }

                  System.out.println("]");
               }
            }

            synchronized (this._ostr) {
               var2.writeTo(this._ostr);
            }

            this._lastAccessTime = Std.getFastTime();
         } catch (PacketTooLargeException var12) {
            throw var12;
         } catch (IOException var13) {
            VarErrorException var3 = new VarErrorException(101);
            if (this._lastError == null) {
               this._lastError = var3;
            }

            Debug.dAssert(this._connectThread == null);
            this._state.setState(17);
         }
      }
   }

   public void sendText(String var1) {
      this.sendText(null, var1);
   }

   private void _sendText(String var1, String var2) {
      if (var2.length() > 200) {
         Object[] var3 = new Object[]{new Integer(var2.length())};
         Console.println(MessageFormat.format(Console.message("msg-too-long"), var3));
         var2 = var2.substring(0, 199);
      }

      var2.trim();
      if (var2.length() >= 1) {
         if (var1 == null) {
            try {
               this.sendNetworkMsg(new textCmd(var2));
            } catch (InfiniteWaitException var6) {
               if (!var2.startsWith("&|+")) {
                  Console.println(Console.message("not-connected"));
               }
            } catch (PacketTooLargeException var7) {
               Debug.dAssert(false);
            }
         } else {
            if (!var2.startsWith("&|+")) {
               Console.printOwnWhisper(var1, var2);
            }

            if (!var2.startsWith("&|+trade>") && !var1.equalsIgnoreCase("trade")) {
               int var8 = Std.getRealTime();
               if (var8 - this._lastWhisperTick > 60000) {
                  this._whisperCnt = 0;
                  this._lastWhisperTick = var8;
               }

               this._whisperCnt++;
               if (this._whisperCnt > 15) {
                  Console.println(Console.message("whisper-too-fast"));
                  return;
               }
            }

            try {
               this.sendNetworkMsg(new whisperCmd(var1, var2));
            } catch (PacketTooLargeException var4) {
               Debug.dAssert(false);
            } catch (InfiniteWaitException var5) {
               if (!var2.startsWith("&|+")) {
                  Console.println(Console.message("not-connected"));
               }
            }
         }
      }
   }

   public void sendText(String var1, String var2) {
      if ((getDebugLevel() & 1) > 0) {
         System.out.println("[" + Std.getRealTime() + "] " + this + ": sendText(" + var2 + ")");
      }

      var2 = var2.trim();
      if (var2.length() > 200) {
         Console.println(Console.message("converting-long"));
         int var3 = 0;
         int var4 = 0;

         while (var2.length() - var3 > 200) {
            var4 = var2.lastIndexOf(32, var3 + 200);
            if (var4 <= var3) {
               var4 = var3 + 200;
            }

            this._sendText(var1, var2.substring(var3, var4));
            var3 = var4 + 1;
         }

         this._sendText(var1, var2.substring(var3));
      } else {
         this._sendText(var1, var2);
      }
   }

   public int getState() {
      return this._state.getState();
   }

   void setState(int var1) {
      this._state.setState(var1);
   }

   public void waitForConnection() throws InfiniteWaitException {
      this._state.waitForState(12);
   }

   public void requestRoomID(String var1, NetworkRoom var2) {
      this._galaxy.addRoomRequest(var1, var2);
      if (this._state.getState() == 12) {
         try {
            this.sendNetworkMsg(new roomIDReqCmd(var1));
         } catch (PacketTooLargeException var4) {
            Debug.dAssert(false);
         } catch (InfiniteWaitException var5) {
         }
      }
   }

   public void delRoomRequest(String var1) {
      this._galaxy.delRoomRequest(var1);
   }

   public void delRoomID(int var1, NetworkRoom var2) {
      this._galaxy.delRoomID(var1, var2);
   }

   void regRoomID(int var1, String var2, boolean var3) {
      NetworkRoom var4 = this._galaxy.regRoomID(var1, var2);
      if (var4 != null) {
         var4.setRoomID(this, var1, var2, var3);
      }
   }

   public void redirectRoom(String var1, ServerURL var2) {
      NetworkRoom var3 = (NetworkRoom)this._galaxy.getObject(var1);
      if (var3 != null) {
         var3.serverRedirect(this, var1, var2);
      }
   }

   NetworkRoom getNetworkRoom(int var1) {
      return this._galaxy.getRoom(var1);
   }

   public final boolean isConnected() {
      return this._state.getState() == 12;
   }

   void startConnect() {
      synchronized (this._state) {
         int var2 = this._state.getState();
         switch (var2) {
            case 0:
               Debug.dAssert(this._connectThread == null);
               this._state.setState(3);
               break;
            case 18:
               this._retriesLeft = 5;
               Debug.dAssert(this._connectThread == null);
               this._state.setState(3);
            case 19:
         }
      }

      this._lastAccessTime = Std.getFastTime();
   }

   void forceOffline() {
      this._retriesLeft = 0;
      this._lastError = new VarErrorException(205);
      this._requestOffline = true;
   }

   void goOnline() {
      this._requestOffline = false;
      this.startConnect();
   }

   protected void perFrame(int var1) {
      synchronized (this._state) {
         int var3 = this._state.getState();
         switch (var3) {
            case -1:
               this.state_Dead(var1);
            case 0:
            case 4:
            default:
               break;
            case 1:
            case 2:
               Debug.dAssert(false);
               break;
            case 3:
               this.state_Initializing();
               break;
            case 5:
               this.state_XMIT_PROPREQ();
               break;
            case 6:
            case 8:
            case 16:
               if (var1 - this._lastAccessTime > 30000) {
                  if (getDebugLevel() > 0) {
                     System.out.println("[" + var1 + "] " + this + ": Messaging timeout. (state=" + var3 + ")");
                  }

                  if (this._lastError == null) {
                     this._lastError = new VarErrorException(106);
                  }

                  switch (var3) {
                     case 6:
                     case 16:
                        this._state.setState(17);
                        return;
                     case 8:
                        this._state.setState(15);
                  }
               } else {
                  try {
                     this.processMsgs(var3, var1);
                  } catch (VarErrorException var14) {
                     if (getDebugLevel() > 0) {
                        System.out.println("[" + var1 + "] " + this + ": VarError#" + var14.getErrorNum());
                        System.out.println(this + ": " + var14.getMsg());
                     }

                     if (this._lastError == null) {
                        this._lastError = var14;
                     }

                     this._state.setState(17);
                  } catch (EOFException var15) {
                     EOFException var20 = var15;
                     VarErrorException var22 = new VarErrorException(100);
                     if (this._lastError == null) {
                        this._lastError = var22;
                     }

                     if (getDebugLevel() > 0) {
                        synchronized (System.out) {
                           var20.printStackTrace(System.out);
                        }
                     }

                     this._state.setState(17);
                  } catch (IOException var16) {
                     IOException var19 = var16;
                     VarErrorException var21 = new VarErrorException(102);
                     if (this._lastError == null) {
                        this._lastError = var21;
                     }

                     synchronized (System.out) {
                        System.out.println("[" + var1 + "] " + this + ": Read error:");
                        if (getDebugLevel() > 0) {
                           var19.printStackTrace(System.out);
                        }
                     }

                     this._state.setState(17);
                  } catch (Exception var17) {
                     Exception var4 = var17;
                     VarErrorException var5 = new VarErrorException(103);
                     if (this._lastError == null) {
                        this._lastError = var5;
                     }

                     synchronized (System.out) {
                        System.out.println("[" + var1 + "] " + this + ": Unexpected error:");
                        var4.printStackTrace(System.out);
                     }

                     this._state.setState(17);
                  }
               }
               break;
            case 7:
               this.state_XMIT_SI();
               break;
            case 9:
               this.state_XMIT_AI();
               break;
            case 10:
               Debug.dAssert(false);
               break;
            case 11:
               this.state_XMIT_Props();
               break;
            case 12:
               this.state_Mainloop(var1);
               break;
            case 13:
               this.state_XMIT_AE();
               break;
            case 14:
               Debug.dAssert(false);
               break;
            case 15:
               this.state_XMIT_SE();
               break;
            case 17:
               this.state_Detaching();
               break;
            case 18:
               this.state_Disconnected(var1);
               break;
            case 19:
               this.state_Sleeping(var1);
         }
      }
   }

   private void processMsgs(int var1, int var2) throws Exception {
      int var4 = this._reader.count();
      if (var4 > 0) {
         int var5 = (int)Math.sqrt(this._lastMsgProcCnt * var4);
         if ((getDebugLevel() & 2) > 0 && var4 > 30) {
            synchronized (System.out) {
               System.out.println(this + ": msgs on incoming queue = " + var4);
               System.out.println("     processed approx " + this._lastMsgProcCnt + " messages on last round.");
               System.out.println("    processing " + var5 + " messages.");
            }
         }

         if (5 > var5) {
            this._lastMsgProcCnt = 5;
         } else {
            this._lastMsgProcCnt = var5;
         }

         if (var4 < var5) {
            var5 = var4;
         }

         var5 = Math.min(var5, var4);

         while (this._state.getState() == var1 && var5-- != 0) {
            receivedNetPacket var3 = this._reader.get();
            Debug.dAssert(var3 != null);
            if ((getDebugLevel() & 64) > 0) {
               System.out.println(this + ": recv(" + var3.toString(this) + ")");
            }

            var3.process(this);
         }

         this._lastAccessTime = var2;
      }
   }

   protected void state_Initializing() {
      if (this._requestOffline) {
         this._state.setState(-1);
      } else if (this._serverURL.getHost().equals("0.0.0.0:0")) {
         System.out.println(this + ": DOA");
         this._state.setState(-1);
      } else {
         this._objTable.regShortID(255, this.getLongID());
         this._objTable.regObject(this.getLongID(), this);
         this._lastError = null;
         this._firstLogon = false;
         String var1 = this._serverURL.getHost();
         int var2 = 5100;
         Debug.dAssert(var1 != null);
         int var3 = this._serverURL.getHost().lastIndexOf(58);
         if (var3 >= 0) {
            try {
               var2 = Integer.parseInt(this._serverURL.getHost().substring(var3 + 1));
            } catch (NumberFormatException var9) {
               NumberFormatException var4 = var9;
               synchronized (System.out) {
                  System.out.println("######DEBUGGING######");
                  System.out.println("    server: " + this._serverURL.getHost());
                  System.out.println("   message: " + var4.getMessage());
                  var4.printStackTrace(System.out);
                  System.out.println("#####################");
               }

               VarErrorException var10 = new VarErrorException(103);
               if (this._lastError == null) {
                  this._lastError = var10;
               }

               System.out.println("Error in server URL format: " + this._serverURL.getHost());
               this._state.setState(17);
               return;
            }

            var1 = this._serverURL.getHost().substring(0, var3);
         }

         this._lastAccessTime = Std.getFastTime();
         if (this._currentBackupServer != null) {
            if (this._sock != null) {
               try {
                  this._sock.close();
               } catch (Exception var8) {
               }

               this._sock = null;
            }

            var1 = this._currentBackupServer;
         }

         if (this._sock == null) {
            this._state.setState(4);
            Debug.dAssert(this._connectThread == null);
            this._connectThread = new WSConnecting(this, var1, var2, 15);
         } else if (this._propList == null) {
            this._state.setState(5);
         } else {
            this._state.setState(7);
         }
      }
   }

   protected void setSocket(Socket var1, VarErrorException var2, String var3) {
      Vector var4 = this._connectThread.getBackupHosts();
      Enumeration var5 = var4.elements();

      while (var5.hasMoreElements()) {
         WorldServer.BackupServer var6 = new WorldServer.BackupServer((String)var5.nextElement());
         Enumeration var7 = this._backupServers.elements();
         boolean var8 = true;

         while (var7.hasMoreElements()) {
            if (((WorldServer.BackupServer)var7.nextElement()).GetHost().equals(var6.GetHost())) {
               var8 = false;
               break;
            }
         }

         if (var8) {
            this._backupServers.addElement(var6);
         }

         if (var3 != null && var3.equals(var6.GetHost())) {
            var6.IncTries();
         }
      }

      this._connectThread = null;
      if (this._state.getState() == 4) {
         if (var1 == null) {
            Debug.assert_(var2 != null);
            if (this._lastError == null) {
               this._lastError = var2;
            }

            this._state.setState(17);
         } else {
            this._sock = var1;

            try {
               this._ostr = this._sock.getOutputStream();
               this._reader = new netPacketReader(this, new ServerInputStream(this._sock.getInputStream()));
            } catch (Exception var9) {
               var2 = new VarErrorException(105);
               if (this._lastError == null) {
                  this._lastError = var2;
               }

               System.out.println(this + ": Error opening I/O streams.");
               this._state.setState(17);
               return;
            }

            this._reader.setDaemon(true);
            this._reader.start();
            this._state.setState(5);
         }
      }
   }

   protected void state_XMIT_PROPREQ() {
      if (this._requestOffline) {
         this._state.setState(17);
      } else {
         propReqCmd var1 = new propReqCmd(new ObjID(255));
         if (NetUpdate.isInternalVersion()) {
            var1.addProp(1);
            var1.addProp(3);
            var1.addProp(15);
            var1.addProp(29);
            var1.addProp(25);
            var1.addProp(26);
            var1.addProp(27);
         }

         try {
            this.sendNetMsg(var1);
         } catch (PacketTooLargeException var3) {
            Debug.dAssert(false);
         }

         this._state.setState(6);
      }
   }

   protected void state_XMIT_SI() {
      Debug.dAssert(false);
      if (this._requestOffline) {
         this._state.setState(17);
      } else {
         this._galaxy.addPendingServer(this);
         this._state.setState(8);
      }
   }

   protected void state_XMIT_AI() {
      Debug.dAssert(false);
      if (this._requestOffline) {
         this._state.setState(17);
      } else {
         this._state.setState(11);
      }
   }

   protected void state_XMIT_Props() {
      if (this._requestOffline) {
         this._state.setState(15);
      } else {
         this._state.setState(12);
         this._galaxy.addActiveServer(this);
      }
   }

   protected void state_Mainloop(int var1) {
      this.killZombies();
      if (this._requestOffline) {
         this._state.setState(15);
      } else if (var1 - this._lastAccessTime > 120000) {
         if (getDebugLevel() > 0) {
            System.out.println(this + ": Timeout during connection.");
         }

         System.out.println("[" + var1 + "] " + this + ": Timeout during connection.");
         System.out.println("\t_lastAccessTime = " + this._lastAccessTime);
         System.out.println("\t        timeNow = " + var1);
         this._retriesLeft = 0;
         this._state.setState(15);
      } else {
         this._waiters.notify(true);

         try {
            this.processMsgs(12, var1);
         } catch (VarErrorException var11) {
            Debug.dAssert(false);
            this._state.setState(17);
         } catch (EOFException var12) {
            EOFException var16 = var12;
            VarErrorException var18 = new VarErrorException(100);
            if (this._lastError == null) {
               this._lastError = var18;
            }

            synchronized (System.out) {
               System.out.println("[" + var1 + "] " + this + ": Server has shut down connection.");
               if (getDebugLevel() > 0) {
                  var16.printStackTrace(System.out);
               }
            }

            this._state.setState(17);
         } catch (IOException var13) {
            IOException var15 = var13;
            VarErrorException var17 = new VarErrorException(100);
            if (this._lastError == null) {
               this._lastError = var17;
            }

            synchronized (System.out) {
               System.out.println("[" + var1 + "] " + this + ": Error reading from network.");
               if (getDebugLevel() > 0) {
                  var15.printStackTrace(System.out);
               }
            }

            this._state.setState(17);
         } catch (Exception var14) {
            Exception var2 = var14;
            VarErrorException var3 = new VarErrorException(103);
            if (this._lastError == null) {
               this._lastError = var3;
            }

            synchronized (System.out) {
               System.out.println("[" + var1 + "] " + this + ": Unexpected error.");
               var2.printStackTrace(System.out);
            }

            this._state.setState(17);
         }
      }
   }

   protected void state_XMIT_AE() {
      Debug.dAssert(false);
      this._state.setState(14);
      this._state.setState(15);
   }

   protected void state_XMIT_SE() {
      boolean var1 = this._galaxy.addClosingServer(this);
      OldPropertyList var2 = new OldPropertyList();
      if (var1) {
         var2.addProperty(new netProperty(12, "1"));
      }

      try {
         this.sendNetMsg(new sessionExitCmd(var2));
      } catch (PacketTooLargeException var4) {
         Debug.dAssert(false);
      }

      this._state.setState(16);
   }

   protected void reuseConnection(WorldServer var1) {
      this._reader = var1._reader;
      var1._reader = null;
      this._ostr = var1._ostr;
      var1._ostr = null;
      this._sock = var1._sock;
      var1._sock = null;
      this._backupServers = (Vector)var1._backupServers.clone();
   }

   public boolean useBackupServer() {
      Enumeration var1 = this._backupServers.elements();

      while (var1.hasMoreElements()) {
         WorldServer.BackupServer var2 = (WorldServer.BackupServer)var1.nextElement();
         if (var2.tries == 0) {
            var2.IncTries();
            this._currentBackupServer = var2.GetHost();
            return true;
         }
      }

      this._currentBackupServer = null;
      return false;
   }

   private void addZombies() {
      Enumeration var1 = this._objTable.objects();

      while (var1.hasMoreElements()) {
         NetworkObject var2 = (NetworkObject)var1.nextElement();
         if (var2 instanceof WObject) {
            if (this.zombies == null) {
               this.zombies = new Vector();
            }

            this.zombies.addElement(var2);
         } else if (var2 instanceof Drone) {
            ((Drone)var2).disappear();
         }
      }

      this._objTable.clear();
   }

   public void killZombies() {
      if (this.zombies != null) {
         int var1 = this.zombies.size();

         while (--var1 >= 0) {
            NetworkObject var2 = (NetworkObject)this.zombies.elementAt(var1);
            this._objTable.regObject(var2.getLongID(), var2);
            if (var2 instanceof Drone) {
               ((Drone)var2).disappear();
            }
         }

         this.zombies = null;
      }
   }

   private void cleanup() {
      Debug.dAssert(this._objTable != null);
      if (this._lastError != null && !this._lastError.getStatusFlag()) {
         this.addZombies();
      } else {
         this.killZombies();
         Enumeration var1 = this._objTable.objects();

         while (var1.hasMoreElements()) {
            NetworkObject var2 = (NetworkObject)var1.nextElement();
            if (var2 instanceof Drone) {
               ((Drone)var2).disappear();
            }
         }

         this._objTable.clear();
      }

      if (this._reader != null) {
         if (this._reader.isAlive()) {
            this._reader.stop();
         }

         this._reader = null;
      }

      if (this._ostr != null) {
         try {
            this._ostr.close();
         } catch (Exception var4) {
         }

         this._ostr = null;
      }

      if (this._sock != null) {
         try {
            this._sock.close();
         } catch (Exception var3) {
         }

         this._sock = null;
      }

      Debug.dAssert(this._connectThread == null);
   }

   protected void state_Detaching_helper() {
      if (this._galaxy != null) {
         this._galaxy.addClosingServer(this);
         this._galaxy.markClosedServer(this);
      }

      this.cleanup();
      this._retryTimeout = 60000;
      if (this._galaxy != null) {
         this._galaxy.noteServerDeath(this._lastError);
      }
   }

   protected void state_Detaching() {
      this._state.setState(18);
      this.state_Detaching_helper();
      if (this._lastError != null) {
         System.out.println("[" + Std.getRealTime() + "] " + this + ": lastError=" + this._lastError);
         this._lastError = null;
         this._galaxy.reacquireServer(this);
      } else if (this._refCnt - this._tmpRefCnt > 0) {
         this.startConnect();
      }
   }

   protected void state_Sleeping(int var1) {
      if (this._requestOffline) {
         this._state.setState(-1);
      } else {
         if (var1 - this._lastAccessTime > this._retryTimeout) {
            if (this._refCnt == 0) {
               this._state.setState(18);
            } else {
               this._state.setState(3);
            }
         }
      }
   }

   protected void state_Disconnected(int var1) {
      this._waiters.notify(false);
      if (var1 - this._lastAccessTime > 1800000) {
         synchronized (this) {
            if (this._refCnt == 0) {
               Debug.dAssert(this._isMainRegistered);
               Main.unregister(this);
               this._isMainRegistered = false;
               if (this._galaxy != null) {
                  this._galaxy.killServer(this);
               }
            }
         }
      } else {
         this._lastAccessTime = var1;
      }
   }

   protected void state_Dead(int var1) {
      this.killZombies();
      this.state_Disconnected(var1);
   }

   public void mainCallback() {
      int var1 = Std.getRealTime();
      this.perFrame(var1);
      if ((getDebugLevel() & 4096) > 0 && this._tmpRefCnt > 0) {
         System.out.println(this + ": tmpRefCnt cleanup of " + this._tmpRefCnt + " refs.");
      }

      synchronized (this) {
         this._refCnt = this._refCnt - this._tmpRefCnt;
         this._tmpRefCnt = 0;
      }

      Debug.dAssert(this._refCnt >= 0);
   }

   public void terminalCallback() {
      synchronized (this) {
         if (this._isMainRegistered) {
            Main.unregister(this);
         }

         Galaxy.forceOffline(false);
         if (this._lastError == null) {
            this._lastError = new VarErrorException(201);
         }

         this._retriesLeft = 0;
         int var2 = this._state.getState();
         this._state.setState(-1);
         switch (var2) {
            case 4:
               this._connectThread = null;
            case 7:
            case 16:
            case 17:
               if ((getDebugLevel() & 512) > 0) {
                  System.out.println(this + ": terminalCallback(): Detach");
               }

               this.state_Detaching();
               break;
            case 5:
            case 6:
            case 13:
            case 14:
            default:
               if ((getDebugLevel() & 512) > 0) {
                  System.out.println(this + ": terminalCallback(): no operation");
               }
               break;
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 15:
               if ((getDebugLevel() & 512) > 0) {
                  System.out.println(this + ": terminalCallback(): XMIT_SE, Detach");
               }

               this.state_XMIT_SE();
               this.state_Detaching();
         }
      }
   }

   public void waitForConnection(ConnectionWaiter var1) {
      this._waiters.addWaiter(var1);
   }

   public void abortWaitForConnection(ConnectionWaiter var1) {
      this._waiters.abortWait(var1);
   }

   public String toString() {
      return this.getLongID();
   }

   public void property(OldPropertyList var1) {
      Debug.dAssert(false);
   }

   public void propertyUpdate(PropertyList var1) {
      this._propList = var1;
      net2Property var2 = this._propList.getProperty(3);
      if (var2 != null) {
         int var3;
         try {
            var3 = Integer.parseInt(var2.value());
         } catch (NumberFormatException var9) {
            System.err.println(this + ": Error converting protocol value: " + var2.value());
            var3 = 18;
         }

         int var4 = this.getVersion();
         this.setVersion(var3 < var4 ? var3 : var4);
      }

      net2Property var10 = this._propList.getProperty(8);
      if (var10 != null) {
         try {
            this._updateTime = Integer.parseInt(var10.value());
            this._updateTime /= 1000;
         } catch (NumberFormatException var8) {
            System.err.println(this + ": Error converting update value: " + var10.value());
         }
      }

      net2Property var11 = this._propList.getProperty(24);
      if (var11 == null) {
         var11 = this._propList.getProperty(29);
      }

      if (var11 != null) {
         NetUpdate.setUpgradeServerURL(var11.value());
      }

      net2Property var5 = this._propList.getProperty(25);
      if (var5 != null) {
         this.setScriptServer(var5.value());
      }

      net2Property var6 = this._propList.getProperty(26);
      if (var6 != null) {
         this.setSmtpServer(var6.value());
      }

      net2Property var7 = this._propList.getProperty(27);
      if (var7 != null) {
         this.setMailDomain(var7.value());
      }

      if (this._state.getState() == 6) {
         this._state.setState(7);
      }
   }

   public WorldServer getServer() {
      return this;
   }

   public String getLongID() {
      return this._serverURL.getHost();
   }

   public void register() {
      Debug.dAssert(false);
   }

   public void galaxyDisconnected() {
      Debug.dAssert(false);
   }

   public void reacquireServer(WorldServer var1) {
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
   }

   private class BackupServer {
      protected String hostName;
      protected int tries;

      public BackupServer() {
         this.hostName = "";
         this.tries = 0;
      }

      public BackupServer(String var2) {
         this.hostName = var2;
         this.tries = 0;
      }

      public String GetHost() {
         return this.hostName;
      }

      public void SetHost(String var1) {
         this.hostName = var1;
      }

      public void IncTries() {
         this.tries++;
      }
   }
}

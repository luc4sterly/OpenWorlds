package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import java.io.IOException;
import java.util.Vector;

public class ActiveX implements MainCallback, MainTerminalCallback {
   private static boolean disabled = IniFile.gamma().getIniInt("DISABLEACTIVEX", 0) != 0;
   private static ActiveX _instance;
   private static int _references;
   private static Vector _referrers = new Vector();
   private static int _serverLocks;
   private static int _activeComponents;
   private static int _debugLevel = IniFile.gamma().getIniInt("oledebug", 0);
   public int _shutdownCounter = 0;

   public static int getDebugLevel() {
      return _debugLevel;
   }

   public static ActiveX getInstance() {
      if (_instance == null) {
         _instance = new ActiveX();
      }

      return _instance;
   }

   private ActiveX() {
      Main.register(this);
   }

   public void mainCallback() {
      this.winProc();
   }

   public void terminalCallback() {
      Debug.dAssert(this == _instance);
      if (_serverLocks <= 0 && _activeComponents <= 0) {
         synchronized (this) {
            Debug.dAssert(_references == _referrers.size());

            while (_references > 0) {
               for (int var2 = _referrers.size() - 1; var2 >= 0; var2--) {
                  IUnknown var3 = (IUnknown)_referrers.elementAt(var2);

                  try {
                     var3.Release();
                  } catch (OLEInvalidObjectException var6) {
                     var6.printStackTrace(System.out);
                     System.out.println("ActiveX: misbehaved object detected: " + var3);
                     _referrers.removeElementAt(var2);
                  }
               }

               if (_referrers.size() > 0) {
                  System.out.println("ActiveX: bad referrers found:");

                  for (int var8 = _referrers.size() - 1; var8 >= 0; var8--) {
                     IUnknown var9 = (IUnknown)_referrers.elementAt(var8);
                     System.out.println("\t" + var9);
                  }
               }
            }

            Debug.dAssert(_references == 0);
            Main.unregister(this);
         }
      } else {
         this._shutdownCounter++;
         if (this._shutdownCounter == 10) {
            this._shutdownCounter = 0;
            System.out.println("Shutdown ignored: _serverLocks = " + _serverLocks + ", _activeComponents = " + _activeComponents);
            Exception var1 = new Exception();
            var1.printStackTrace(System.out);
         }
      }
   }

   public static void init(IUnknown var0) throws IOException {
      synchronized (getInstance()) {
         Debug.dAssert(!_referrers.contains(var0));
         if (_references == 0) {
            initActiveX();
         }

         _references++;
         _referrers.addElement(var0);
         if ((_debugLevel & 1) > 0) {
            System.out.println("ActiveX.init() - refCnt = " + _references);
         }
      }
   }

   public static void uninit(IUnknown var0) {
      synchronized (getInstance()) {
         Debug.dAssert(_references > 0);
         Debug.dAssert(_referrers.contains(var0));
         _references--;
         if (_references == 0) {
            uninitActiveX();
         }

         _referrers.removeElement(var0);
         if ((_debugLevel & 1) > 0) {
            System.out.println("ActiveX.uninit() - refCnt = " + _references);
         }
      }
   }

   public static synchronized void incServerLocks(int var0) {
      _serverLocks += var0;
      Debug.dAssert(_serverLocks >= 0);
   }

   public static synchronized void incActiveComponents(int var0) {
      _activeComponents += var0;
      Debug.dAssert(_activeComponents >= 0);
   }

   private static native void initActiveX() throws IOException;

   private static native void uninitActiveX();

   public static native int getClassFClsID(String var0, String var1) throws IOException;

   public static native int getClassFProgID(String var0, String var1) throws IOException;

   private static native int getClass(int var0, String var1) throws IOException;

   private native void winProc();

   static {
      if (_debugLevel > 0) {
         System.out.println("OLE DEBUGGING LEVEL = " + _debugLevel);
      }
   }
}

package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;

class SMState {
   private int _state;
   private WorldServer _ws;
   private static int _debugLevel;

   public SMState(WorldServer var1, int var2) {
      this._state = var2;
      this._ws = var1;
   }

   public int getState() {
      return this._state;
   }

   public synchronized void setState(int var1) {
      if ((_debugLevel & 8) > 0) {
         synchronized (System.out) {
            System.out.println(this._ws + ": *** new state: " + var1);
            if ((_debugLevel & 16) > 0) {
               try {
                  throw new InterruptedException();
               } catch (InterruptedException var5) {
                  var5.printStackTrace(System.out);
                  System.out.println("******************************");
               }
            }
         }
      }

      this._state = var1;
      this.notifyAll();
   }

   public synchronized void waitForState(int var1) throws InfiniteWaitException {
      while (this._state != var1) {
         try {
            this.wait();
         } catch (InterruptedException var3) {
            Debug.dAssert(false);
         }

         if (this._state == -1) {
            throw new InfiniteWaitException();
         }
      }
   }

   static {
      try {
         _debugLevel = Integer.parseInt(IniFile.gamma().getIniString("netdebug", "0"));
      } catch (NumberFormatException var1) {
         _debugLevel = 0;
      }
   }
}

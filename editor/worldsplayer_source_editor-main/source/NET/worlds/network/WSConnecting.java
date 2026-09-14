package NET.worlds.network;

import java.io.IOException;
import java.net.NoRouteToHostException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.StringTokenizer;
import java.util.Vector;

class WSConnecting implements Runnable {
   private WorldServer _serv;
   private String _host;
   private Vector _hosts;
   private int _unresolvedHosts;
   private int _port;
   private int _timeout;
   private int _error;
   private boolean _calledBack;
   private Vector _resolvedHosts;

   public WSConnecting(WorldServer var1, String var2, int var3, int var4) {
      this._serv = var1;
      this._host = var2;
      this._hosts = new Vector();
      this._port = var3;
      this._timeout = var4;
      this._error = 0;
      this.makeThread(-1);
      StringTokenizer var5 = new StringTokenizer(var2, ";");

      while (var5.hasMoreTokens()) {
         this._hosts.addElement(var5.nextToken());
      }

      this._unresolvedHosts = this._hosts.size();

      for (int var6 = 0; var6 < this._unresolvedHosts; var6++) {
         this.makeThread(var6);
      }
   }

   private void makeThread(int var1) {
      Thread var2 = new Thread(this, Integer.toString(var1));
      var2.setDaemon(true);
      var2.start();
   }

   public void run() {
      int var1 = Integer.parseInt(Thread.currentThread().getName());
      if (var1 == -1) {
         try {
            Thread.sleep(this._timeout * 1000);
         } catch (InterruptedException var12) {
         }

         synchronized (this) {
            if (!this._calledBack) {
               this._calledBack = true;
               if (this._error == 0) {
                  this._error = 106;
               }

               this._serv.setSocket(null, new VarErrorException(this._error), null);
            }
         }
      } else if (var1 < this._unresolvedHosts) {
         try {
            String var2 = (String)this._hosts.elementAt(var1);
            String[] var3 = DNSLookup.lookupAll(var2);
            if (var3.length > 1) {
               for (int var4 = 0; var4 < var3.length; var4++) {
                  int var5;
                  synchronized (this._hosts) {
                     var5 = this._hosts.size();
                     this._hosts.addElement(var3[var4]);
                  }

                  this.makeThread(var5);
               }
            } else {
               this.connectTo(var3[0], false);
            }
         } catch (UnknownHostException var13) {
            synchronized (this) {
               if (this._error == 0) {
                  this._error = 107;
               }
            }
         }
      } else {
         this.connectTo((String)this._hosts.elementAt(var1), false);
      }
   }

   public Vector getBackupHosts() {
      this._resolvedHosts = new Vector();

      for (int var1 = this._unresolvedHosts; var1 < this._hosts.size(); var1++) {
         this._resolvedHosts.addElement(this._hosts.elementAt(var1));
      }

      return this._resolvedHosts;
   }

   private void connectTo(String var1, boolean var2) {
      Socket var3 = null;

      try {
         var3 = new Socket(var1, this._port);
         synchronized (this) {
            if (var2) {
               try {
                  this.wait(this._timeout * 1000 * 2 / 3);
               } catch (InterruptedException var9) {
               }
            }

            System.out.println("Connected to " + var1);
            if (!this._calledBack) {
               this._calledBack = true;
               this._serv.setSocket(var3, null, var1);
            } else {
               try {
                  var3.close();
               } catch (IOException var8) {
               }
            }

            this.notifyAll();
         }
      } catch (IOException var12) {
         IOException var4 = var12;
         synchronized (this) {
            if (this._error == 0) {
               if (!(var4 instanceof NoRouteToHostException) && !(var4 instanceof UnknownHostException)) {
                  this._error = 104;
               } else {
                  this._error = 107;
               }
            }

            this.notifyAll();
         }
      }
   }
}

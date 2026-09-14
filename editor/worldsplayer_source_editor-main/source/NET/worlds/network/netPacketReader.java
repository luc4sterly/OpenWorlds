package NET.worlds.network;

import NET.worlds.console.StatNetMUNode;
import NET.worlds.core.Debug;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.util.Vector;

public class netPacketReader extends Thread {
   private Vector _msgQ;
   private ServerInputStream _in;
   private WorldServer _serv;
   private static Class[] msgTable = new Class[255];

   public netPacketReader(ServerInputStream var1) {
      this._in = var1;
      this._msgQ = new Vector();
   }

   public netPacketReader(WorldServer var1, ServerInputStream var2) {
      this._serv = var1;
      this._in = var2;
      this._msgQ = new Vector();
   }

   public void put(receivedNetPacket var1) {
      this._msgQ.addElement(var1);
   }

   public receivedNetPacket get() {
      Debug.dAssert(this._msgQ != null);
      if (this._msgQ.isEmpty()) {
         return null;
      }

      receivedNetPacket var1 = (receivedNetPacket)this._msgQ.firstElement();
      this._msgQ.removeElement(var1);
      return var1;
   }

   public int count() {
      return this._msgQ.size();
   }

   private final void buildMsg() throws IOException {
      this._in.readPacketSize();
      byte[] var1 = new byte[this._in.bytesLeft() + 1];
      var1[0] = (byte)(this._in.bytesLeft() + 1);
      this._in.readFully(var1, 1, this._in.bytesLeft());
      StatNetMUNode var2 = StatNetMUNode.getNode();
      var2.addBytesRcvd(var1.length);
      var2.addPacketsRcvd(1);
      ServerInputStream var10 = new ServerInputStream(new ByteArrayInputStream(var1));
      var10.readPacketSize();
      if ((WorldServer.getDebugLevel() & 2048) > 0) {
         synchronized (System.out) {
            System.out.print(this._serv + ": recv[");

            for (int var4 = 0; var4 < var1.length; var4++) {
               System.out.print(Integer.toString(var1[var4] & 255, 16) + " ");
            }

            System.out.println("]");
         }
      }

      receivedNetPacket var11 = null;
      ObjID var12 = new ObjID();
      var12.parseNetData(var10);
      boolean var5 = var12.shortID() == 254;
      int var6 = var10.readUnsignedByte();
      if (var6 < msgTable.length && msgTable[var6] != null) {
         do {
            if (var5) {
               var12 = new ObjID();
               var12.parseNetData(var10);
            }

            try {
               var11 = (receivedNetPacket)msgTable[var6].newInstance();
            } catch (Exception var8) {
               System.out.println(var8 + ": " + var8.getMessage());
               Debug.assert_(false);
            }

            var11.init(var12);
            var11.parseNetData(var10);
            this._msgQ.addElement(var11);
            yield();
         } while (!var10.isEmpty() && var5);

         Debug.dAssert(var10.isEmpty());
      } else {
         System.out.println("UNKNOWN SERVER MSG#" + String.valueOf(var6));
         var10.skipBytes(var10.bytesLeft());
         Debug.dAssert(var10.isEmpty());
      }
   }

   public void run() {
      try {
         while (true) {
            this.buildMsg();
         }
      } catch (IOException var2) {
         this._msgQ.addElement(new ExceptionCmd(var2));
      }
   }

   static {
      String var0 = "NET.worlds.network.";
      Vector var2 = new netCmds().recvCmdList();

      for (int var6 = 0; var6 < var2.size(); var6++) {
         String var1 = var0 + (String)var2.elementAt(var6);

         try {
            Class var3 = Class.forName(var1);
            receivedNetPacket var5 = (receivedNetPacket)var3.newInstance();
            int var4 = var5.msgID();
            Debug.dAssert(var4 > -1);
            Debug.dAssert(msgTable[var4] == null);
            msgTable[var4] = var3;
         } catch (NoSuchMethodError var13) {
            NoSuchMethodError var15 = var13;
            synchronized (System.out) {
               System.out.println("netPacketReader:: " + var15.getClass().getName() + " creating " + var1);
               System.out.println("netPacketReader:: Exception: " + var15.getMessage());
               var15.printStackTrace(System.out);
            }

            Debug.assert_(false);
         } catch (Exception var14) {
            Exception var7 = var14;
            synchronized (System.out) {
               System.out.println("netPacketReader:: " + var7.getClass().getName() + " creating " + var1);
               System.out.println("netPacketReader:: Exception: " + var7.getMessage());
               var7.printStackTrace(System.out);
            }

            Debug.assert_(false);
         }
      }
   }
}

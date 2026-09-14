package NET.worlds.console;

import java.util.Date;
import java.util.Vector;

class ConnectionRecord {
   private static Vector recordList = new Vector();
   private String _who = null;
   private Date _startDelayTime = null;

   public ConnectionRecord(String var1) {
      this._who = var1;
      this._startDelayTime = new Date();
   }

   public boolean isExpired(Date var1) {
      return var1.getTime() - this._startDelayTime.getTime() > 15000L;
   }

   public String getWho() {
      return this._who;
   }

   public static Vector getList() {
      return recordList;
   }

   public static synchronized boolean checkList(String var0) {
      boolean var1 = false;
      int var2 = 0;
      Date var3 = new Date();

      while (!recordList.isEmpty() && var2 < recordList.size()) {
         ConnectionRecord var4 = (ConnectionRecord)recordList.elementAt(var2);
         if (var4.isExpired(var3)) {
            recordList.removeElementAt(var2);
         } else {
            var2++;
            if (var4.getWho().equals(var0)) {
               var1 = true;
            }
         }
      }

      return var1;
   }
}

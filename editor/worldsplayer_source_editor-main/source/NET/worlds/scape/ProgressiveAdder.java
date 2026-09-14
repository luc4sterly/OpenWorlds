package NET.worlds.scape;

import NET.worlds.core.IniFile;
import java.util.Vector;

public class ProgressiveAdder implements FrameHandler {
   Vector addList = new Vector();
   static ProgressiveAdder theProgressiveAdder = null;

   public static ProgressiveAdder get() {
      if (theProgressiveAdder == null) {
         theProgressiveAdder = new ProgressiveAdder();
      }

      return theProgressiveAdder;
   }

   ProgressiveAdder() {
   }

   public boolean enabled() {
      return IniFile.gamma().getIniInt("ProgressiveAvLoading", 0) == 1;
   }

   void scheduleForAdd(WObject var1, WObject var2) {
      synchronized (this.addList) {
         WObject[] var4 = new WObject[]{var1, var2};
         this.addList.addElement(var4);
      }
   }

   public boolean handle(FrameEvent var1) {
      synchronized (this.addList) {
         if (this.addList.size() > 0) {
            WObject[] var3 = (WObject[])this.addList.elementAt(0);
            WObject var4 = var3[0];
            WObject var5 = var3[1];
            if (!var4.discarded && !var5.discarded) {
               var4.add(var5);
            }

            this.addList.removeElementAt(0);
         }

         return true;
      }
   }
}

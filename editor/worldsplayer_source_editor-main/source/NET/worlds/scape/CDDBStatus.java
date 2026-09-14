package NET.worlds.scape;

import java.io.IOException;

public class CDDBStatus implements Persister {
   private int status;
   private CDDiskInfo diskInfo;
   private static Object classCookie = new Object();

   public CDDBStatus(int var1, CDDiskInfo var2) {
      this.status = var1;
      this.diskInfo = var2;
   }

   public CDDBStatus(int var1) {
      this.status = var1;
   }

   public CDDBStatus() {
   }

   public int getStatus() {
      return this.status;
   }

   public CDDiskInfo getDiskInfo() {
      return this.diskInfo;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveInt(this.status);
      var1.saveMaybeNull(this.diskInfo);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.status = var1.restoreInt();
            this.diskInfo = (CDDiskInfo)var1.restoreMaybeNull();
            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}

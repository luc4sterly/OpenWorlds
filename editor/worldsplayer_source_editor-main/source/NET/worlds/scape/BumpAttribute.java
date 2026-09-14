package NET.worlds.scape;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class BumpAttribute extends Attribute {
   private static Object classCookie = new Object();

   public BumpAttribute(int var1) {
      super(var1);
   }

   public BumpAttribute() {
   }

   protected void noteAddingTo(SuperRoot var1) {
      WObject var2 = (WObject)((Sharer)var1).getOwner();
      var2._bumpableAttribute = this;
   }

   public void detach() {
      WObject var1 = (WObject)((Sharer)this.getOwner()).getOwner();
      var1._bumpableAttribute = null;
      super.detach();
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      var1.writeBoolean(((WObject)this.getOwner().getOwner()).getBumpable());
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      ((WObject)this.getOwner().getOwner()).setBumpable(var1.readBoolean());
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}

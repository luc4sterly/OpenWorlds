package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class ForwardAttribute extends Attribute implements NonPersister {
   private Attribute _from;

   ForwardAttribute(Attribute var1, int var2) {
      super(var2);
      this._from = var1;
   }

   protected void noteAddingTo(SuperRoot var1) {
      WObject var2 = (WObject)var1.getOwner();
      if ((var2.getSharer().getMode() & 1) != 0) {
         throw new ClassCastException("Must forward to unforwarded object");
      }
   }

   public void detach() {
      super.detach();
      this._from.unforward();
   }

   public int getFlags() {
      return this._from.getFlags();
   }

   public void setFlag(int var1, boolean var2) {
      this._from.setFlag(var1, var2);
   }

   public void generateNetData(DataOutputStream var1) throws IOException {
      this._from.generateNetData(var1);
   }

   public void setFromNetData(DataInputStream var1, int var2) throws IOException {
      this._from.setFromNetData(var1, var2);
      ValueEvent var3 = new ValueEvent(Std.getFastTime(), this._from.getOwner(), (WObject)this._from.getOwner().getOwner(), this._from);
      this._from.trigger(var3);
   }

   public String toString() {
      return super.toString() + "[forwarded from " + this._from.getName() + "]";
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      Debug.assert_(false);
   }
}

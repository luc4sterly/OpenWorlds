package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Vector;

public class AnimatedActionHandlerImp implements AnimatedActionHandler {
   Vector callbacks = new Vector();

   AnimatedActionHandlerImp() {
   }

   public void addCallback(AnimatedActionCallback var1) {
      Debug.dAssert(this.callbacks != null);
      this.callbacks.addElement(var1);
   }

   public void removeCallback(AnimatedActionCallback var1) {
      Debug.dAssert(this.callbacks != null);
      this.callbacks.removeElement(var1);
   }

   public void notifyCallbacks(int var1) {
      Debug.dAssert(this.callbacks != null);
      Enumeration var2 = this.callbacks.elements();

      while (var2.hasMoreElements()) {
         AnimatedActionCallback var3 = (AnimatedActionCallback)var2.nextElement();
         var3.motionComplete(var1);
      }
   }
}

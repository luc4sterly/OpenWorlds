package NET.worlds.scape;

import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class Sensor extends SuperRoot {
   protected Vector actions = new Vector();
   private static Object classCookie = new Object();

   public void addAction(Action var1) {
      this.actions.addElement(var1);
   }

   public void deleteAction(Action var1) {
      this.actions.removeElement(var1);
   }

   public void deleteActions() {
      while (this.actions.size() > 0) {
         this.deleteAction((Action)this.actions.elementAt(0));
      }
   }

   public Enumeration getActions() {
      return this.actions.elements();
   }

   public int countActions() {
      return this.actions.size();
   }

   public void trigger(Event var1) {
      RunningActionHandler.trigger(this.actions, this.getWorld(), var1);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = ObjectPropertyAdder.make(new VectorProperty(this, var1, "Targets"), this.getRoot(), "NET.worlds.scape.Action");
            } else if (var3 == 1) {
               var5 = this.actions.clone();
            } else if (var3 == 4) {
               this.deleteAction((Action)var4);
            } else if (var3 == 3) {
               this.addAction((Action)var4);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveVector(this.actions);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateVers(var1);
   }

   protected int restoreStateVers(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 1:
         case 2:
            super.restoreState(var1);
         case 0:
            this.actions = var1.restoreVector();
            return var2;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      Enumeration var2 = this.getActions();

      while (var2.hasMoreElements()) {
         Action var3 = (Action)var2.nextElement();
         if (this.getOwner() != null && var3.getOwner() == null) {
            System.out.println("Reparenting orphan action " + var3.getName());
            WObject var4 = (WObject)this.getOwner();
            var4.addAction(var3);
         }
      }
   }
}

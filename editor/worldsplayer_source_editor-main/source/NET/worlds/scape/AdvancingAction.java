package NET.worlds.scape;

import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class AdvancingAction extends Action {
   private Vector actions = new Vector();
   private int nextAction = 0;
   boolean singleTrigger = true;
   boolean inProgress = false;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      if (this.singleTrigger && this.inProgress && var2 == null) {
         return null;
      }

      if (this.nextAction >= this.actions.size()) {
         this.nextAction = 0;
      }

      Action var3 = (Action)this.actions.elementAt(this.nextAction);
      Persister var4 = null;
      if (var3 != null) {
         var4 = var3.trigger(var1, var2);
         this.inProgress = var4 != null;
      }

      if (var4 == null || !this.singleTrigger) {
         this.nextAction++;
      }

      return var4;
   }

   public void addComponent(Action var1) {
      this.actions.addElement(var1);
   }

   public void insertComponent(Action var1, int var2) {
      this.actions.insertElementAt(var1, var2);
   }

   public boolean removeComponent(Action var1) {
      return this.actions.removeElement(var1);
   }

   public Enumeration getComponents() {
      return this.actions.elements();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               VectorProperty var6 = new VectorProperty(this, var1, "Components");
               var6.allowSorting(false);
               var5 = ObjectPropertyAdder.make(var6, this.getRoot(), "NET.worlds.scape.Action");
            } else if (var3 == 1) {
               var5 = this.actions.clone();
            } else if (var3 == 4) {
               this.actions.removeElement(var4);
            } else if (var3 == 3) {
               this.actions.addElement((Action)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Prevent overlapping actions"), "Overlapping", "One at a time");
            } else if (var3 == 1) {
               var5 = new Boolean(this.singleTrigger);
            } else if (var3 == 2) {
               this.singleTrigger = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveVector(this.actions);
      var1.saveInt(this.nextAction);
      var1.saveBoolean(this.singleTrigger);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            this.nextAction = var1.restoreInt();
            break;
         case 1:
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            this.nextAction = var1.restoreInt();
            this.singleTrigger = var1.restoreBoolean();
            break;
         default:
            throw new TooNewException();
      }
   }
}

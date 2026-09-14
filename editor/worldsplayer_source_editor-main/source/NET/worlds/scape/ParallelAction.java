package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class ParallelAction extends Action implements RunningActionCallback {
   protected static final int NONE = 0;
   protected static final int FIRST = 1;
   protected static final int ALL = -1;
   protected Vector actions = new Vector();
   protected int waitState = -1;
   protected int waitingFor = 0;
   protected Object currentRun = null;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      if (var2 == null) {
         if (this.waitingFor == 0) {
            this.currentRun = new Object();
            if (this.waitState == -1) {
               this.waitingFor = this.actions.size();
               var2 = this;
            } else if (this.waitState == 1) {
               this.waitingFor = 1;
               var2 = this;
            } else {
               this.waitingFor = 0;
               var2 = null;
            }

            RunningActionHandler.trigger(this.actions, this.getWorld(), var1, this, this.currentRun);
         }
      } else if (this.waitingFor == 0) {
         var2 = null;
      }

      return var2;
   }

   public void actionDone(Action var1, Event var2, Object var3) {
      if (this.waitingFor > 0 && var3 == this.currentRun) {
         this.waitingFor--;
      }
   }

   public void setWaitForAll() {
      this.waitState = -1;
   }

   public void setWaitForFirst() {
      this.waitState = 1;
   }

   public void setWaitForNone() {
      this.waitState = 0;
   }

   public void addComponent(Action var1) {
      Debug.dAssert(var1 != null);
      this.actions.addElement(var1);
   }

   public void insertComponent(Action var1, int var2) {
      Debug.dAssert(var1 != null);
      this.actions.insertElementAt(var1, var2);
   }

   public boolean removeComponent(Action var1) {
      Debug.dAssert(var1 != null);
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
               var5 = ObjectPropertyAdder.make(new VectorProperty(this, var1, "Components"), this.getRoot(), "NET.worlds.scape.Action");
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
               String[] var6 = new String[]{"None", "First", "All"};
               int[] var7 = new int[]{0, 1, -1};
               var5 = EnumPropertyEditor.make(new Property(this, var1, "Wait for"), var6, var7);
            } else if (var3 == 1) {
               var5 = new Integer(this.waitState);
            } else if (var3 == 2) {
               this.waitState = (Integer)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveVector(this.actions);
      var1.saveInt(this.waitState);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            break;
         case 2:
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            this.waitState = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }
}

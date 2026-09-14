package NET.worlds.scape;

import java.io.IOException;
import java.util.Enumeration;
import java.util.Vector;

public class SequenceAction extends Action {
   protected int loopCount = 1;
   protected boolean loopInfinite = false;
   Vector actions = new Vector();
   SequenceActionState currentSeq;
   private static Object classCookie = new Object();

   public Persister trigger(Event var1, Persister var2) {
      if (var2 != this.currentSeq) {
         return null;
      }

      if (var2 == null) {
         this.currentSeq = new SequenceActionState(this);
      }

      if (!this.currentSeq.run(var1)) {
         this.currentSeq = null;
      }

      return this.currentSeq;
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

   public int getLoopCount() {
      return this.loopCount;
   }

   public void setLoopCount(int var1) {
      this.loopCount = var1;
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
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Loop Count"));
            } else if (var3 == 1) {
               var5 = new Integer(this.loopCount);
            } else if (var3 == 2) {
               this.loopCount = (Integer)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Loop Infinite"), "False", "True");
            } else if (var3 == 1) {
               var5 = new Boolean(this.loopInfinite);
            } else if (var3 == 2) {
               this.loopInfinite = (Boolean)var4;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 3, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(2, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.loopInfinite);
      var1.saveVector(this.actions);
      var1.saveInt(this.loopCount);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            var1.setOldFlag();
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            this.loopCount = var1.restoreInt();
            this.loopInfinite = this.loopCount < 0;
            this.loopCount = Math.abs(this.loopCount);
            var1.restoreBoolean();
            break;
         case 1:
            super.restoreState(var1);
            this.actions = var1.restoreVector();
            this.loopCount = var1.restoreInt();
            this.loopInfinite = this.loopCount < 0;
            this.loopCount = Math.abs(this.loopCount);
            break;
         case 2:
            super.restoreState(var1);
            this.loopInfinite = var1.restoreBoolean();
            this.actions = var1.restoreVector();
            this.loopCount = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }
   }
}

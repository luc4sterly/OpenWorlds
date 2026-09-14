package NET.worlds.scape;

import java.io.IOException;
import java.util.Vector;

class SequenceActionState implements Persister {
   int currentLoop;
   boolean loopInfinite;
   Vector actions;
   Persister seqID;
   int currentAct;
   private static Object classCookie = new Object();

   SequenceActionState() {
   }

   SequenceActionState(SequenceAction var1) {
      this.currentLoop = var1.loopCount;
      this.loopInfinite = var1.loopInfinite;
      this.actions = (Vector)var1.actions.clone();
   }

   boolean run(Event var1) {
      if (this.currentLoop <= 0 && !this.loopInfinite) {
         return false;
      }

      while (this.currentAct < this.actions.size()) {
         Action var2 = (Action)this.actions.elementAt(this.currentAct);
         if ((this.seqID = var2.trigger(var1, this.seqID)) != null) {
            return true;
         }

         this.currentAct++;
      }

      this.currentAct = 0;
      if (this.currentLoop > 0) {
         this.currentLoop--;
      }

      return true;
   }

   public String toString() {
      String var1 = "Action #" + this.currentAct + " of loop " + this.currentLoop + ", status " + this.seqID;
      if (!this.loopInfinite) {
         var1 = var1 + " NOT";
      }

      return var1 + " Infinite";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveBoolean(this.loopInfinite);
      var1.saveInt(this.currentLoop);
      var1.saveInt(this.currentAct);
      var1.saveVector(this.actions);
      var1.saveMaybeNull(this.seqID);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            this.currentLoop = var1.restoreInt();
            this.loopInfinite = this.currentLoop < 0;
            this.currentLoop = Math.abs(this.currentLoop);
            this.currentAct = var1.restoreInt();
            this.actions = var1.restoreVector();
            this.seqID = var1.restoreMaybeNull();
            break;
         case 1:
            this.loopInfinite = var1.restoreBoolean();
            this.currentLoop = var1.restoreInt();
            this.currentAct = var1.restoreInt();
            this.actions = var1.restoreVector();
            this.seqID = var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}

package NET.worlds.scape;

import NET.worlds.core.Std;
import java.io.IOException;

public class AnimateAction extends Action {
   int startTime;
   public int cycleTime = 1000;
   public String frameList = "";
   protected int frameListCount = 0;
   protected Material[] frameMaterialArray = null;
   public int cycles = 0;
   public boolean infiniteLoop = false;
   protected int cycleNo;
   protected int currentFrameNo;
   private boolean running = false;
   private static Object classCookie = new Object();

   public AnimateAction() {
      this.startAnimation();
   }

   public void startAnimation() {
      this.cycleNo = 0;
      this.currentFrameNo = -1;
      this.startTime = Std.getRealTime();
   }

   public void preprocessFrameList(String var1) {
      this.frameMaterialArray = AnimatingDoor.namesToMaterialArray(this, var1);
      this.frameListCount = this.frameMaterialArray == null ? 0 : this.frameMaterialArray.length;
   }

   public void detach() {
      if (this.frameMaterialArray != null) {
         int var1 = this.frameMaterialArray.length;

         while (--var1 >= 0) {
            this.frameMaterialArray[var1].setKeepLoaded(false);
         }

         this.frameMaterialArray = null;
         this.frameListCount = 0;
      }

      super.detach();
   }

   public Persister trigger(Event var1, Persister var2) {
      SuperRoot var3 = this.getOwner();
      if (!(var3 instanceof Animatable)) {
         this.frameMaterialArray = null;
         this.frameListCount = 0;
         return null;
      }

      Animatable var4 = (Animatable)var3;
      if (!var4.hasClump()) {
         this.frameMaterialArray = null;
         this.frameListCount = 0;
         return var2;
      }

      if (this.frameMaterialArray == null) {
         this.preprocessFrameList(this.frameList);
      }

      if (var2 == null) {
         if (this.running && !this.infiniteLoop) {
            return null;
         }

         this.startAnimation();
      }

      int var5 = 0;
      if (this.frameListCount != 0 && this.cycleTime > 0) {
         int var6 = Std.getRealTime() - this.startTime;
         long var7 = (long)this.frameListCount * var6 / this.cycleTime;
         this.cycleNo = (int)(var7 / this.frameListCount);
         var5 = (int)(var7 - this.cycleNo * this.frameListCount);
      } else {
         this.cycleNo = 1000000000;
      }

      if (this.cycleNo >= this.cycles && !this.infiniteLoop) {
         var5 = this.frameListCount - 1;
         this.running = false;
      } else {
         this.running = true;
      }

      if (var5 != this.currentFrameNo) {
         this.currentFrameNo = var5;
         if (var4.hasClump() && this.currentFrameNo >= 0) {
            var4.setMaterial(this.frameMaterialArray[this.currentFrameNo]);
         }
      }

      return this.running ? this : null;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Cycle Time"));
            } else if (var3 == 1) {
               var5 = new Integer(this.cycleTime);
            } else if (var3 == 2) {
               this.cycleTime = (Integer)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Cycles"));
            } else if (var3 == 1) {
               var5 = new Integer(this.cycles);
            } else if (var3 == 2) {
               this.cycles = (Integer)var4;
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Infinite Loop"), "False", "True");
            } else if (var3 == 1) {
               var5 = new Boolean(this.infiniteLoop);
            } else if (var3 == 2) {
               this.infiniteLoop = (Boolean)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Frame List"));
            } else if (var3 == 1) {
               var5 = new String(this.frameList);
            } else if (var3 == 2) {
               this.frameList = ((String)var4).toString().trim().toLowerCase();
               this.preprocessFrameList(this.frameList);
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 4, var3, var4);
      }

      return var5;
   }

   public String toString() {
      String var1 = super.toString() + "[cycleTime " + this.cycleTime + ", cycles " + this.cycles + ",";
      if (!this.infiniteLoop) {
         var1 = var1 + " not ";
      }

      return var1 + "Infinite ]";
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      var1.saveBoolean(this.infiniteLoop);
      var1.saveInt(this.cycleTime);
      var1.saveInt(this.cycles);
      var1.saveString(this.frameList);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            super.restoreState(var1);
         case 0:
            this.cycleTime = (int)var1.restoreFloat();
            this.cycles = var1.restoreInt();
            this.infiniteLoop = this.cycles == 0;
            this.frameList = var1.restoreString();
            break;
         case 2:
            super.restoreState(var1);
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.infiniteLoop = this.cycles == 0;
            this.frameList = var1.restoreString();
            break;
         case 3:
            super.restoreState(var1);
            this.infiniteLoop = var1.restoreBoolean();
            this.cycleTime = var1.restoreInt();
            this.cycles = var1.restoreInt();
            this.frameList = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }
   }
}

package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.core.Std;
import java.io.IOException;
import java.util.Enumeration;

public class DPAction extends Action {
   private static final int INFINITY = 60000;
   protected int loadDist = 2;
   protected int unloadDist = 4;
   protected DPState state = null;
   private static Object classCookie = new Object();

   public int getLoadDist() {
      return this.loadDist;
   }

   public int getUnloadDist() {
      return this.unloadDist;
   }

   public void setLoadDist(int var1) {
      Debug.dAssert(var1 > 0);
      if (var1 > 0) {
         this.loadDist = var1;
         if (this.unloadDist <= this.loadDist) {
            this.unloadDist = var1 + 1;
         }
      }
   }

   public void setUnloadDist(int var1) {
      Debug.dAssert(var1 > 1);
      if (var1 <= this.loadDist) {
         this.unloadDist = this.loadDist + 1;
      } else {
         this.unloadDist = var1;
      }
   }

   public Persister trigger(Event var1, Persister var2) {
      if (this.state == null) {
         return null;
      }

      if (var1 != null) {
         this.state.setDist(0, var1.time);
      } else {
         this.state.setDist(0, Std.getFastTime());
      }

      return null;
   }

   public void handleDist(int var1, int var2) {
      Debug.dAssert(this.loadDist < this.unloadDist);
      if (this.getOwner() instanceof Portal) {
         if (var1 <= this.loadDist) {
            ((Portal)this.getOwner()).triggerLoad();
            if (((Portal)this.getOwner()).active()) {
               this.informOtherSide(var1 + 1, var2);
            } else {
               new DPLoadTracker(this, var1 + 1, var2);
            }
         } else if (var1 > this.unloadDist) {
            ((Portal)this.getOwner()).reset();
         } else if (((Portal)this.getOwner()).active()) {
            this.informOtherSide(var1 + 1, var2);
         }
      }
   }

   void informOtherSide(int var1, int var2) {
      DPState var3 = null;
      Portal var4 = ((Portal)this.getOwner()).farSide();
      Enumeration var5 = var4.getActions();

      while (var5.hasMoreElements()) {
         Object var6 = var5.nextElement();
         if (var6 instanceof DPAction) {
            var3 = ((DPAction)var6).getState();
            Debug.dAssert(var3 != null);
         }
      }

      if (var3 != null) {
         var3.setDist(var1, var2);
      }
   }

   protected void noteAddingTo(SuperRoot var1) {
      super.noteAddingTo(var1);
      if (this.state == null) {
         if (var1 instanceof Portal) {
            Portal var2 = (Portal)var1;
            World var3 = var1.getWorld();
            if (var3 != null) {
               this.state = this.findState(var3);
            }

            if (this.state == null) {
               this.state = new DPState(60000, this);
            } else {
               this.state.addConnection(this);
            }
         }
      }
   }

   protected DPState findState(SuperRoot var1) {
      DPState var2 = null;
      Enumeration var3 = var1.getDeepOwned();

      while (var3.hasMoreElements() && var2 == null) {
         SuperRoot var4 = (SuperRoot)var3.nextElement();
         if (var4 instanceof DPAction) {
            var2 = ((DPAction)var4).getState();
         }
      }

      return var2;
   }

   public DPState getState() {
      return this.state;
   }

   public void detach() {
      if (this.state != null) {
         this.state.dropConnection(this);
         this.state = null;
      }

      super.detach();
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Load Distance"));
            } else if (var3 == 1) {
               var5 = new Integer(this.loadDist);
            } else if (var3 == 2) {
               this.setLoadDist((Integer)var4);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Unload Distance"));
            } else if (var3 == 1) {
               var5 = new Integer(this.unloadDist);
            } else if (var3 == 2) {
               this.setUnloadDist((Integer)var4);
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Cell State");
            } else if (var3 == 1) {
               var5 = this.state;
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
      var1.saveInt(this.loadDist);
      var1.saveInt(this.unloadDist);
      var1.saveMaybeNull(this.state);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.loadDist = var1.restoreInt();
            this.unloadDist = var1.restoreInt();
            this.state = (DPState)var1.restore();
            var1.restoreInt();
            break;
         case 1:
            super.restoreState(var1);
            this.loadDist = var1.restoreInt();
            this.unloadDist = var1.restoreInt();
            this.state = (DPState)var1.restore();
            break;
         case 2:
            super.restoreState(var1);
            this.loadDist = var1.restoreInt();
            this.unloadDist = var1.restoreInt();
            this.state = (DPState)var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }
   }

   public String toString() {
      return super.toString() + "[" + this.getOwner().getWorld().getName() + "|" + this.getOwner().getName() + "]";
   }
}

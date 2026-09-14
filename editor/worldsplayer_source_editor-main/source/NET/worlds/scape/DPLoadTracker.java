package NET.worlds.scape;

class DPLoadTracker extends WObject implements FrameHandler, NonPersister {
   protected DPAction src;
   protected int distance;
   protected int triggerTime = 0;

   public DPLoadTracker(DPAction var1, int var2, int var3) {
      this.src = var1;
      this.setDistance(var2, var3);
      ((Portal)this.src.getOwner()).addHandler(this);
   }

   public DPLoadTracker() {
   }

   public void setDistance(int var1, int var2) {
      if (var2 > this.triggerTime) {
         this.distance = var1;
         this.triggerTime = var2;
      }
   }

   public boolean handle(FrameEvent var1) {
      if (((Portal)this.src.getOwner()).active()) {
         this.src.informOtherSide(this.distance, this.triggerTime);
         this.finish();
      } else if (((Portal)this.src.getOwner()).unconnected()) {
         this.finish();
      }

      return true;
   }

   public void finish() {
      ((Portal)this.src.getOwner()).removeHandler(this);
   }

   public String toString() {
      return super.toString();
   }
}

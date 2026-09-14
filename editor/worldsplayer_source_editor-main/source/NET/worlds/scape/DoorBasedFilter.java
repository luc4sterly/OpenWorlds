package NET.worlds.scape;

import NET.worlds.core.Debug;

public class DoorBasedFilter extends AudibilityFilter {
   float stopDistance;
   public static final double log10 = Math.log(10.0);

   DoorBasedFilter(Sound var1, WObject var2, int var3, float var4) {
      super(var1, var2, var3, var4);
      this.debugOut(6, "DoorBasedFilter");
      this.stopDistance = var4;
   }

   private void debugOut(int var1, String var2) {
      if (Sound.debugLevel > var1) {
         System.out.println(var2);
      }
   }

   void fillOwnerEntry() {
      this.debugOut(9, "door fillOwnerEntry called " + this.sound.getURL());
      DoorBasedParams var1 = new DoorBasedParams();
      var1.room = this.owner.getRoom();
      var1.transform = Transform.make();
      var1.hopcount = 0;
      var1.portalCenter = new Point3(this.owner.getPosition());
      var1.localPortalCenter = new Point3(var1.portalCenter);
      var1.nextLastApparent = new Point3(var1.portalCenter);
      var1.position = new Point3(var1.portalCenter);
      var1.portalWidth = 0.0F;
      var1.next = null;
      var1.distance = 0.0;
      this.ownerPos = var1;
      this.roomList.addElement(this.ownerPos);
   }

   void fillNewAP(AudibleParams var1, Portal var2, int var3) {
      this.debugOut(9, "fillNewAP from " + var2.farSideRoom().getName());
      DoorBasedParams var4 = (DoorBasedParams)var1;
      this.debugOut(9, " to conRoom " + var4.room.getName());
      DoorBasedParams var5 = new DoorBasedParams();
      var5.room = var2.farSideRoom();
      var5.hopcount = var3;
      if (var2.p2pXform() == null) {
         var2.setTransform();
      }

      if (var2.p2pXform() != null) {
         var5.transform = var2.p2pXform().getTransform();
      } else {
         var5.transform = Transform.make();
      }

      var5.portalWidth = var2.getScaleX();
      var5.portalCenter = new Point3(var2.getPosition());
      var5.portalCenter.plus(var2.getFarCorner()).times(0.5F);
      var5.localPortalCenter = new Point3(var5.portalCenter);
      var5.localPortalCenter.times(var5.transform);
      var5.next = var4;
      var5.nextLastApparent = new Point3(var5.next.position);
      var5.nextLastApparent.times(var5.transform);
      var5.position = var5.nextLastApparent;
      var5.distance = Point3Temp.make(var5.portalCenter).minus(var5.next.localPortalCenter).length() + var5.next.distance;
      this.roomList.addElement(var5);
      this.localPos = var5;
   }

   public void adjustEmitterLocation() {
      this.debugOut(6, "DoorBasedFilter::adjustEmitterLocation");
      if (this.ownerPos.room != this.owner.getRoom()) {
         this.moveEmitter();
      } else {
         this.recursiveFindAttenuation((DoorBasedParams)this.localPos);
      }
   }

   public void recursiveFindAttenuation(DoorBasedParams var1) {
      this.debugOut(9, "recursiveFindAttenuation on " + var1.room.getName());
      if (var1.next == null) {
         var1.portalCenter.copy(this.owner.getPosition());
         var1.localPortalCenter.copy(var1.portalCenter);
         var1.nextLastApparent.copy(var1.portalCenter);
         var1.position.copy(var1.portalCenter);
      } else {
         this.recursiveFindAttenuation(var1.next);
         var1.nextLastApparent.copy(var1.next.position);
         var1.nextLastApparent.times(var1.transform);
         var1.distance = Point3Temp.make(var1.portalCenter).minus(var1.next.localPortalCenter).length() + var1.next.distance;
         this.calculateEmitterPosition(var1);
      }
   }

   public double calculateTau(Point3Temp var1, Point3Temp var2, float var3) {
      Debug.dAssert(var3 > 0.0F);
      double var4 = (Point3Temp.make(var1).minus(var2).length() - var3) / var3;
      var4 = Math.max(Math.min(var4, 1.0), 0.0);
      Debug.dAssert(var4 >= 0.0);
      Debug.dAssert(var4 <= 1.0);
      return var4;
   }

   public void getEmitterPosition(Point3Temp var1) {
      this.debugOut(9, "getEmitterPosition");
      this.calculateEmitterPosition((DoorBasedParams)this.localPos);
      var1.copy(((DoorBasedParams)this.localPos).position);
   }

   private void calculateEmitterPosition(DoorBasedParams var1) {
      if (var1.next != null) {
         float var2 = (float)this.calculateTau(Pilot.getActive().getPosition(), var1.localPortalCenter, var1.portalWidth);
         Point3Temp var3 = Point3Temp.make(var1.nextLastApparent);
         Point3Temp var4 = Point3Temp.make(var1.localPortalCenter);
         Point3Temp var5 = var4.times(var2).plus(var3.times(1.0F - var2));
         var1.position.copy(var5);
      }
   }

   public float getEmitterVolume() {
      float var1 = 1.0F;
      Debug.dAssert(this.localPos != null);
      DoorBasedParams var2 = (DoorBasedParams)this.localPos;
      if (var2.next == null) {
         return 1.0F;
      }

      Point3Temp var3 = Point3Temp.make(var2.position);
      double var4 = var3.minus(var2.localPortalCenter).length();
      double var6 = var2.distance - var4;
      double var8 = -2.0 / this.stopDistance * var6;
      return (float)Math.exp(var8 * log10);
   }
}

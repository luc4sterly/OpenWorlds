package NET.worlds.scape;

import NET.worlds.core.Debug;
import java.util.Vector;

public class AudibilityFilter {
   WObject owner;
   Room listenerRoom;
   AudibleParams ownerPos;
   AudibleParams localPos;
   Vector roomList = new Vector();
   int maxHopcount = 1;
   private boolean listenerOn = false;
   private boolean emitterOn = false;
   Sound sound;
   Vector breadthQueue = null;
   int breadthLevel;
   int breadthNextLevelIndex;
   int breadthIndex;

   public AudibilityFilter(Sound var1, WObject var2, int var3) {
      this.debugOut(9, "AudibilityFilter::AudibilityFilter in");
      this.sound = var1;
      this.owner = var2;
      this.maxHopcount = var3;
      if (this.owner.getRoom() != null) {
         this.floodFillRooms();
         this.updateListenerState();
      }
   }

   void fillOwnerEntry() {
      this.debugOut(9, "aud fillOwnerEntry called " + this.sound.getURL());
      this.ownerPos = new AudibleParams();
      this.ownerPos.room = this.owner.getRoom();
      this.ownerPos.position = new Point3(this.owner.getPosition());
      this.ownerPos.transform = Transform.make();
      this.ownerPos.hopcount = 0;
      this.roomList.addElement(this.ownerPos);
   }

   private void debugOut(int var1, String var2) {
      if (Sound.debugLevel > var1) {
         System.out.println(var2);
      }
   }

   public AudibilityFilter(Sound var1, WObject var2, int var3, float var4) {
      this(var1, var2, var3);
   }

   public AudibilityFilter() {
   }

   public void setHopcount(int var1) {
      this.debugOut(9, "AudibilityFilter::setHopcount");
      this.maxHopcount = var1;
      this.moveEmitter();
   }

   public int getHopcount() {
      this.debugOut(9, "AudibilityFilter::getHopcount");
      return this.maxHopcount;
   }

   void setEmitterOn(boolean var1) {
      this.debugOut(9, "setting emitterOn to " + var1);
      this.emitterOn = var1;
   }

   void updateListenerState() {
      Debug.dAssert(this.sound != null);
      this.debugOut(6, "updateListenerState " + this.sound.getURL());
      Room var1 = Pilot.getActiveRoom();
      if (this.listenerRoom != var1) {
         this.listenerRoom = var1;
         AudibleParams var2 = this.getRoomElement(var1);
         if (var2 == null) {
            this.listenerOn = false;
         } else {
            this.localPos = var2;
            this.adjustEmitterLocation();
            if (!this.listenerOn) {
               this.listenerOn = true;
               if (this.emitterOn) {
                  RunningActionHandler.trigger(this.sound, this.owner.getWorld(), null);
               }
            }
         }
      }
   }

   private void updateEmitterState() {
      if (this.isEmitterMoved()) {
         this.adjustEmitterLocation();
      }
   }

   public boolean isAudible() {
      this.updateListenerState();
      this.updateEmitterState();
      this.debugOut(6, "emitterOn " + this.emitterOn + " listenerOn " + this.listenerOn);
      return this.emitterOn && this.listenerOn;
   }

   void moveEmitter() {
      this.debugOut(9, "moveEmitter");
      this.removeRooms();
      this.floodFillRooms();
      this.updateListenerState();
   }

   private void removeRooms() {
      this.debugOut(9, "removeRooms for sound " + this.sound.getURL());

      for (int var1 = this.roomList.size() - 1; var1 >= 0; var1--) {
         AudibleParams var2 = (AudibleParams)this.roomList.elementAt(var1);
         Room var3 = var2.room;
         var3.removeAFilter(this);
         this.debugOut(9, "removing room " + var3.getName() + " from roomList");
         this.roomList.removeElementAt(var1);
      }
   }

   private void floodFillRooms() {
      this.debugOut(9, "floodFillRooms " + this.sound.getURL() + " count:" + this.maxHopcount);
      Debug.dAssert(this.roomList != null);
      Debug.dAssert(this.roomList.size() == 0);
      Debug.dAssert(this.owner != null);
      if (this.owner != null && this.owner.getRoom() != null) {
         this.breadthSearchStart();
         this.fillOwnerEntry();
         this.owner.getRoom().addAFilter(this);
         this.breadthAddChildren(this.owner.getRoom());

         for (Portal var1 = this.breadthNextElement(); var1 != null && this.breadthCurrentLevel() < this.maxHopcount; var1 = this.breadthNextElement()) {
            this.debugOut(6, " trying to add " + var1.farSideRoom().getName());
            if (this.getRoomElement(var1.farSideRoom()) == null) {
               this.addRoomListEntry(var1, this.breadthCurrentLevel() + 1);
               this.breadthAddChildren(var1.farSideRoom());
            }
         }

         this.breadthSearchEnd();
      }
   }

   private void breadthSearchStart() {
      this.breadthQueue = new Vector();
      this.breadthLevel = 0;
      this.breadthNextLevelIndex = 0;
      this.breadthIndex = 0;
   }

   private Portal breadthNextElement() {
      if (this.breadthQueue != null && this.breadthIndex < this.breadthQueue.size()) {
         if (this.breadthIndex == this.breadthNextLevelIndex) {
            this.breadthLevel++;
            this.breadthNextLevelIndex = this.breadthQueue.size();
         }

         Portal var1 = (Portal)this.breadthQueue.elementAt(this.breadthIndex);
         return (Portal)this.breadthQueue.elementAt(this.breadthIndex++);
      } else {
         return null;
      }
   }

   private void breadthAddChildren(Room var1) {
      Debug.dAssert(this.breadthQueue != null);
      Vector var2 = var1.getOutgoingPortals();

      for (int var3 = 0; var3 < var2.size(); var3++) {
         Portal var4 = (Portal)var2.elementAt(var3);
         Room var5 = var4.farSideRoom();
         if (var5 != null && var5.isActive()) {
            this.breadthQueue.addElement(var4);
         }
      }
   }

   private int breadthCurrentLevel() {
      return this.breadthLevel;
   }

   private void breadthSearchEnd() {
      this.breadthQueue = null;
   }

   private void addRoomListEntry(Portal var1, int var2) {
      this.debugOut(9, "addRoomListEntry " + var1.farSideRoom().getName());
      AudibleParams var3 = this.getRoomElement(var1.getRoom());
      Debug.dAssert(var3 != null);
      this.fillNewAP(var3, var1, var2);
      var1.farSideRoom().addAFilter(this);
   }

   AudibleParams getRoomElement(Room var1) {
      this.debugOut(6, "getRoomElement size " + this.roomList.size() + " room " + var1.getName());
      if (var1 == null) {
         return null;
      }

      for (int var2 = 0; var2 < this.roomList.size(); var2++) {
         Room var3 = ((AudibleParams)this.roomList.elementAt(var2)).room;
         this.debugOut(9, " comparing to " + var3.getName());
         if (((AudibleParams)this.roomList.elementAt(var2)).room == var1) {
            return (AudibleParams)this.roomList.elementAt(var2);
         }
      }

      return null;
   }

   void fillNewAP(AudibleParams var1, Portal var2, int var3) {
      this.debugOut(4, "AudibilityFilter::fillNewAP for room " + var2.farSideRoom().getName());
      AudibleParams var4 = new AudibleParams();
      var4.room = var2.farSideRoom();
      var4.hopcount = var3;
      Transform var5;
      if (var2.p2pXform() != null) {
         var5 = var2.p2pXform().getTransform();
      } else {
         var5 = Transform.make();
         this.debugOut(4, "  xform incomplete");
      }

      var4.transform = var1.transform.getTransform();
      var4.transform.post(var5);
      var5.recycle();
      var4.position = new Point3(var1.position);
      var4.position.times(var4.transform);
      this.roomList.addElement(var4);
   }

   public boolean isEmitterMoved() {
      Debug.dAssert(this.ownerPos != null);
      if (!this.ownerPos.position.sameValue(this.owner.getPosition())) {
         this.ownerPos.position = new Point3(this.owner.getPosition());
         return true;
      } else {
         return this.ownerPos.room != this.owner.getRoom();
      }
   }

   public void adjustEmitterLocation() {
      this.debugOut(4, "AudibilityFilter::adjustEmitterLocation");
      if (this.ownerPos.room != this.owner.getRoom()) {
         this.debugOut(9, " moveEmitter because emitter changed rooms");
         this.moveEmitter();
      } else {
         this.localPos.position = new Point3(this.ownerPos.position);
         this.localPos.position.times(this.localPos.transform);
      }
   }

   public void getListenerPosition(Point3Temp var1, Point3Temp var2, Point3Temp var3) {
      this.debugOut(9, "getListenerPosition");
      Pilot var4 = Pilot.getActive();
      Transform var5 = var4.getObjectToWorldMatrix();
      var2.copy(Point3Temp.make(0.0F, 0.0F, 1.0F).vectorTimes(var5).normalize());
      var3.copy(Point3Temp.make(0.0F, 1.0F, 0.0F).vectorTimes(var5).normalize());
      var1.copy(var4.getPosition());
      var5.recycle();
   }

   public void getEmitterPosition(Point3Temp var1) {
      this.debugOut(9, "getEmitterPosition");
      Debug.dAssert(this.localPos != null);
      var1.x = this.localPos.position.x;
      var1.y = this.localPos.position.y;
      var1.z = this.localPos.position.z;
   }

   public float getEmitterVolume() {
      this.debugOut(9, "getEmitterVolume");
      Debug.dAssert(this.localPos != null);
      return 1.0F;
   }
}

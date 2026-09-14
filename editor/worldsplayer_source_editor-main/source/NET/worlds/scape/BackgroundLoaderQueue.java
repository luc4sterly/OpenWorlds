package NET.worlds.scape;

import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Debug;
import java.util.Enumeration;
import java.util.Hashtable;

class BackgroundLoaderQueue implements MainCallback {
   private Room activeRoom;
   private int itemsInQueue;
   private BackgroundLoaderVector inAllRooms = new BackgroundLoaderVector();
   private BackgroundLoaderVector inUnknownRoom = new BackgroundLoaderVector();
   private Hashtable rooms = new Hashtable();
   private boolean mainRan;

   synchronized void activeRoomChanged(Room var1) {
      this.activeRoom = var1;
   }

   public boolean hasHighPriorityItems() {
      return this.inAllRooms.size() > 0;
   }

   synchronized void add(BackgroundLoaderElement var1) {
      if (!this.addHelper(var1, false)) {
         if (var1.inAllRooms()) {
            this.inAllRooms.insertElementAt(var1, 0);
         } else {
            this.inUnknownRoom.addElement(var1);
         }
      }

      this.itemsInQueue++;
      this.notify();
   }

   private boolean addHelper(BackgroundLoaderElement var1, boolean var2) {
      Room var3 = var1.getRoom(var2);
      if (var3 != null && var3.isActive()) {
         BackgroundLoaderVector var4 = (BackgroundLoaderVector)this.rooms.get(var3);
         if (var4 == null) {
            this.rooms.put(var3, var4 = new BackgroundLoaderVector());
         }

         var4.addElement(var1);
         return true;
      } else {
         return false;
      }
   }

   private BackgroundLoaderElement getHelper(Room var1) {
      BackgroundLoaderElement var2 = null;
      BackgroundLoaderVector var3 = (BackgroundLoaderVector)this.rooms.get(var1);
      if (var3 != null) {
         var2 = var3.removeFirst();
         if (var3.isEmpty()) {
            this.rooms.remove(var1);
         }
      }

      return var2;
   }

   synchronized BackgroundLoaderElement getItem() {
      BackgroundLoaderElement var1 = null;

      while (true) {
         while (this.itemsInQueue == 0) {
            try {
               this.wait();
            } catch (InterruptedException var3) {
            }
         }

         if (this.inAllRooms.size() != 0) {
            var1 = this.inAllRooms.removeFirst();
            break;
         }

         if (this.activeRoom != null && (var1 = this.getHelper(this.activeRoom)) != null) {
            break;
         }

         this.mainRan = false;
         Main.register(this);

         while (!this.mainRan) {
            try {
               this.wait();
            } catch (InterruptedException var4) {
            }
         }

         if (this.inAllRooms.size() == 0 && (this.activeRoom == null || this.rooms.get(this.activeRoom) == null)) {
            if ((var1 = this.getClosestObject()) == null) {
               if (this.inUnknownRoom.size() != 0) {
                  var1 = this.inUnknownRoom.removeFirst();
               } else {
                  Enumeration var2 = this.rooms.keys();
                  Debug.dAssert(var2.hasMoreElements());
                  var1 = this.getHelper((Room)var2.nextElement());
                  Debug.dAssert(var1 != null);
               }
            }
            break;
         }
      }

      Debug.dAssert(var1 != null);
      this.itemsInQueue--;
      Debug.dAssert(this.itemsInQueue >= 0);
      return var1;
   }

   private BackgroundLoaderElement getClosestObject() {
      synchronized (Pilot.visibleRooms) {
         float var2 = Float.MAX_VALUE;
         int var3 = -1;
         int var4 = Pilot.visibleRoomInfo.size();

         for (int var5 = 0; var5 < var4; var5++) {
            RoomSubscribeInfo var6 = (RoomSubscribeInfo)Pilot.visibleRoomInfo.elementAt(var5);
            if (var6.d < var2 && this.rooms.get(Pilot.visibleRooms.elementAt(var5)) != null) {
               var2 = var6.d;
               var3 = var5;
            }
         }

         return var3 == -1 ? null : this.getHelper((Room)Pilot.visibleRooms.elementAt(var3));
      }
   }

   public synchronized void mainCallback() {
      int var1 = this.inUnknownRoom.size();
      int var2 = 0;

      while (var1-- != 0) {
         BackgroundLoaderElement var3 = (BackgroundLoaderElement)this.inUnknownRoom.get(var2);
         if (this.addHelper(var3, true)) {
            this.inUnknownRoom.removeElementAt(var2);
         } else {
            var2++;
         }
      }

      this.mainRan = true;
      Main.unregister(this);
      this.notify();
   }
}

package NET.worlds.console;

import NET.worlds.scape.DeepEnumeration;
import NET.worlds.scape.Drone;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.Room;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.WObject;
import java.util.Enumeration;
import java.util.Hashtable;

class ArmyOfZombies {
   Hashtable zombies = new Hashtable();
   private static ArmyOfZombies instance = new ArmyOfZombies();

   public static ArmyOfZombies instance() {
      return instance;
   }

   protected ArmyOfZombies() {
   }

   public void killZombies() {
      Enumeration var1 = this.zombies.elements();

      while (var1.hasMoreElements()) {
         Drone var2 = (Drone)var1.nextElement();
         Enumeration var3 = var2.getContents();

         while (var3.hasMoreElements()) {
            WObject var4 = (WObject)var3.nextElement();
            var4.detach();
         }

         var2.detach();
         var2.discard();
      }

      this.zombies.clear();
   }

   public void addZombie(Drone var1) {
      String var2 = var1.getName();
      if (var2.charAt(0) == '!') {
         var2 = var2.substring(1);
      }

      this.zombies.put(var2, var1);
   }

   public void replaceZombie(String var1, Drone var2) {
      Drone var3 = this.get(var1);
      if (var3 != var2) {
         this.zombies.remove(var1);
         this.addZombie(var2);
         var2.makeTag(true);
      }
   }

   public void killZombie(String var1) {
      Drone var2 = this.get(var1);
      if (var2 != null) {
         this.zombies.remove(var1);
         var2.detach();
      }
   }

   public void zombify() {
      if (Pilot.getActive() != null) {
         if (Pilot.getActive().getRoom() != null) {
            if (Pilot.getActive().getRoom().getWorld() != null) {
               Enumeration var1 = Pilot.getActive().getRoom().getWorld().getRooms();

               while (var1.hasMoreElements()) {
                  Room var2 = (Room)var1.nextElement();
                  if (var2 != null) {
                     DeepEnumeration var3 = new DeepEnumeration();
                     var2.getChildren(var3);

                     while (var3.hasMoreElements()) {
                        Object var4 = var3.nextElement();
                        if (var4 instanceof Drone) {
                           Drone var5 = (Drone)var4;
                           short var6 = (short)var5.getX();
                           short var7 = (short)var5.getY();
                           short var8 = (short)var5.getZ();
                           short var9 = (short)(-var5.getYaw() + 90.0F);
                           var9 = (short)(var9 % 360);

                           while (var9 < 0) {
                              var9 = (short)(var9 + 360);
                           }

                           SuperRoot var10 = var5.getOwner();
                           if (var10 != null) {
                              Room var11 = var10.getRoom();
                              if (var11 != null && var5.getName() != null) {
                                 BlackBox.getInstance()
                                    .submitEvent(new BBAppearDroneCommand(var2.getRoom().toString(), var5.getName(), var6, var7, var8, var9));
                                 if (var5.getCurrentURL() != null) {
                                    BlackBox.getInstance().submitEvent(new BBDroneBitmapCommand(var5.getName(), var5.getCurrentURL().toString()));
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
   }

   Drone get(String var1) {
      if (var1.charAt(0) == '!') {
         var1 = var1.substring(1);
      }

      return (Drone)this.zombies.get(var1);
   }
}

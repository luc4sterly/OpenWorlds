package NET.worlds.br;

import NET.worlds.console.Console;
import NET.worlds.scape.Action;
import NET.worlds.scape.Event;
import NET.worlds.scape.IntegerPropertyEditor;
import NET.worlds.scape.MoveAction;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Persister;
import NET.worlds.scape.Point3;
import NET.worlds.scape.Point3Temp;
import NET.worlds.scape.Portal;
import NET.worlds.scape.Property;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Room;
import NET.worlds.scape.Saver;
import NET.worlds.scape.StringPropertyEditor;
import NET.worlds.scape.SuperRoot;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.WObject;
import NET.worlds.scape.WaitAction;
import java.io.IOException;

public class SlidingDoorAction extends Action {
   protected static final int DOOR_CLOSED = 0;
   protected static final int DOOR_OPENING = 1;
   protected static final int DOOR_OPEN = 2;
   protected static final int DOOR_CLOSING = 3;
   protected static final int MAX_TIME = 10000000;
   protected int doorState = 0;
   protected MoveAction open = null;
   protected MoveAction close = null;
   protected WaitAction wait = null;
   protected Portal portal = null;
   protected String portalName = null;
   protected boolean configured = false;
   protected int extent = 0;
   protected int openTime = 1000;
   protected int holdTime = 1000;
   protected int closeTime = 1000;
   protected int direction = 0;
   private static Object classCookie = new Object();

   public void loadInit() {
      this.open = new MoveAction();
      this.wait = new WaitAction(this.holdTime);
      this.close = new MoveAction();
   }

   public Persister trigger(Event var1, Persister var2) {
      if (var2 == null && this.doorState != 0) {
         System.out.println("Sliding Door: no multitriggers: " + this.doorState);
         return null;
      }

      if (!this.configured) {
         this.resetActions();
      }

      if (!this.configured) {
         System.out.println("Sliding Door: can't configure");
         return null;
      }

      if (this.doorState == 0 && var2 == null) {
         if (this.portal != null) {
            this.portal.setVisible(true);
         }

         this.doorState = 1;
      }

      if (this.doorState == 1) {
         var2 = this.open.trigger(var1, var2);
         if (var2 == null) {
            this.doorState = 2;
         }
      }

      if (this.doorState == 2) {
         var2 = this.wait.trigger(var1, var2);
         if (var2 == null) {
            this.doorState = 3;
         }
      }

      if (this.doorState == 3) {
         var2 = this.close.trigger(var1, var2);
         if (var2 == null) {
            if (this.portal != null) {
               this.portal.setVisible(false);
            }

            this.doorState = 0;
         }
      }

      return var2;
   }

   protected void resetActions() {
      SuperRoot var1 = this.getOwner();
      if (!(var1 instanceof WObject)) {
         Console.println(Console.message("must-be-WObject"));
      } else {
         WObject var2 = (WObject)var1;
         if (this.open != null) {
            this.open.detach();
            var2.addAction(this.open);
         }

         if (this.close != null) {
            this.close.detach();
            var2.addAction(this.close);
         }

         if (this.wait != null) {
            this.wait.detach();
            var2.addAction(this.wait);
         }

         if (this.openTime <= 0) {
            this.openTime = 1;
            Console.println(Console.message("open-time-pos"));
         } else if (this.openTime > 10000000) {
            this.openTime = 10000000;
            Console.println(Console.message("slow-door"));
         }

         if (this.holdTime < 0) {
            this.holdTime = 0;
            Console.println(Console.message("hold-time-pos"));
         } else if (this.holdTime > 10000000) {
            this.holdTime = 10000000;
            Console.println(Console.message("slow-door"));
         }

         if (this.closeTime <= 0) {
            this.closeTime = 1;
            Console.println(Console.message("close-time-pos"));
         } else if (this.closeTime > 10000000) {
            this.closeTime = 10000000;
            Console.println(Console.message("slow-door"));
         }

         Point3 var3 = new Point3(0.0F, 0.0F, 0.0F);
         if (this.direction >= 0 && this.direction <= 3) {
            switch (this.direction) {
               case 0:
                  var3.z = var3.z + this.extent;
                  break;
               case 1:
                  var3.x = (float)(var3.x + this.extent * Math.cos(var2.getYaw() * Math.PI / 180.0));
                  var3.y = (float)(var3.y + this.extent * Math.sin(var2.getYaw() * Math.PI / 180.0));
                  break;
               case 2:
                  var3.z = var3.z - this.extent;
                  break;
               case 3:
                  var3.x = (float)(var3.x - this.extent * Math.cos(var2.getYaw() * Math.PI / 180.0));
                  var3.y = (float)(var3.y - this.extent * Math.sin(var2.getYaw() * Math.PI / 180.0));
            }
         } else {
            this.direction = 0;
            Console.println(Console.message("dir-must-be"));
         }

         this.open.extentPoint = var3;
         this.open.startPoint.copy(var2.getPosition());
         this.open.startScale.copy(var2.getScale());
         this.open.startRotation = var2.getSpin(this.open.startSpin);
         this.open.cycleTime = this.openTime;
         Point3Temp var4 = this.P3T(this.open.startPoint);
         this.close.startPoint = this.P3(var4.plus(this.P3T(this.open.extentPoint)));
         this.close.extentPoint = this.P3(this.P3T(this.open.extentPoint).negate());
         this.close.startScale.copy(var2.getScale());
         this.close.startRotation = var2.getSpin(this.open.startSpin);
         this.close.cycleTime = this.closeTime;
         this.wait = new WaitAction(this.holdTime / 1000.0F);
         if (this.portalName == null) {
            this.portal = null;
         } else {
            this.portal = this.getPortalInRoomByName(var2.getRoom(), this.portalName);
            if (this.portal == null) {
               Console.println(Console.message("find-portal"));
            }
         }

         this.configured = true;
      }
   }

   public Portal getPortalInRoomByName(Room var1, String var2) {
      Portal var3 = null;
      if (var1 != null) {
         var3 = Portal.findByName(var1, var2);
      }

      return var3;
   }

   public Point3 P3(Point3Temp var1) {
      return new Point3(var1.x, var1.y, var1.z);
   }

   public Point3Temp P3T(Point3 var1) {
      return Point3Temp.make(var1.x, var1.y, var1.z);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Direction (0 = up)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.direction);
            } else if (var3 == 2) {
               this.direction = (Integer)var4;
               this.resetActions();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Move Extent"));
            } else if (var3 == 1) {
               var5 = new Integer(this.extent);
            } else if (var3 == 2) {
               this.extent = (Integer)var4;
               this.resetActions();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Open Time (ms)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.openTime);
            } else if (var3 == 2) {
               this.openTime = (Integer)var4;
               this.resetActions();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Hold Time (ms)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.holdTime);
            } else if (var3 == 2) {
               this.holdTime = (Integer)var4;
               this.resetActions();
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Close Time (ms)"));
            } else if (var3 == 1) {
               var5 = new Integer(this.closeTime);
            } else if (var3 == 2) {
               this.closeTime = (Integer)var4;
               this.resetActions();
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Portal Name"));
            } else if (var3 == 1) {
               var5 = this.portalName;
            } else if (var3 == 2) {
               this.portalName = (String)var4;
               this.resetActions();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveMaybeNull(null);
      var1.saveBoolean(this.configured);
      var1.saveMaybeNull(this.open);
      var1.saveMaybeNull(this.close);
      var1.saveMaybeNull(this.wait);
      var1.saveInt(this.direction);
      var1.saveInt(this.extent);
      var1.saveInt(this.openTime);
      var1.saveInt(this.holdTime);
      var1.saveInt(this.closeTime);
      var1.saveString(this.portalName);
      var1.saveMaybeNull(this.portal);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      this.restoreStateHelper(var1, classCookie);
   }

   public void restoreStateHelper(Restorer var1, Object var2) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            var1.restoreMaybeNull();
            this.configured = var1.restoreBoolean();
            this.open = (MoveAction)var1.restoreMaybeNull();
            this.close = (MoveAction)var1.restoreMaybeNull();
            this.wait = (WaitAction)var1.restoreMaybeNull();
            this.direction = var1.restoreInt();
            this.extent = var1.restoreInt();
            this.openTime = var1.restoreInt();
            this.holdTime = var1.restoreInt();
            this.closeTime = var1.restoreInt();
            this.portalName = var1.restoreString();
            break;
         case 1:
            super.restoreState(var1);
            var1.restoreMaybeNull();
            this.configured = var1.restoreBoolean();
            this.open = (MoveAction)var1.restoreMaybeNull();
            this.close = (MoveAction)var1.restoreMaybeNull();
            this.wait = (WaitAction)var1.restoreMaybeNull();
            this.direction = var1.restoreInt();
            this.extent = var1.restoreInt();
            this.openTime = var1.restoreInt();
            this.holdTime = var1.restoreInt();
            this.closeTime = var1.restoreInt();
            this.portalName = var1.restoreString();
            this.portal = (Portal)var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
      if (var1 < 7) {
         WObject var2 = (WObject)this.getOwner();
         if (var2 == null) {
            return;
         }

         if (this.open != null) {
            var2.addAction(this.open);
         }

         if (this.close != null) {
            var2.addAction(this.close);
         }

         if (this.wait != null) {
            var2.addAction(this.wait);
         }
      }
   }
}

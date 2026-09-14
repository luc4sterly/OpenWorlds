package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.DefaultConsole;
import NET.worlds.core.Timer;
import NET.worlds.core.TimerCallback;
import NET.worlds.network.URL;
import java.util.Vector;

public class AnimatedAction implements AnimatedActionCallback, TimerCallback {
   static final int noAction = 0;
   static final int addToInventory = 1;
   static final int removeObject = 2;
   static final int animateObject = 3;
   static final int moveObjectTo = 4;
   static final int playSound = 5;
   static final int obtainConsent = 0;
   static final int zoomOut = 1;
   static final int moveToObject = 2;
   static final int preAnimateAction = 3;
   static final int actOnObject1 = 4;
   static final int simulAnimateAction = 5;
   static final int postAnimateAction = 6;
   static final int actOnObject2 = 7;
   static final int zoomBack = 8;
   static String[] actions = new String[]{"noAction", "addToInventory", "removeObject", "animateObject", "moveObjectTo", "playSound"};
   String actionName;
   Vector avatarNames;
   Vector targetObjects;
   Shape _targetShape = null;
   boolean consentRequired;
   Point2 targetRelPosition;
   Point2 targetPosition;
   double targetRelYaw;
   float targetYaw;
   int preAnimationAction;
   String preAnimationParameter;
   String actionName1;
   int simultaneousAction;
   String simultaneousParameter;
   int postAnimationAction;
   String postAnimationParameter;
   String actionName2;
   int _oldMode;
   int _oldSpeed;
   private int _state;
   private HoloPilot _pilot;
   private float _waitTime;

   AnimatedAction() {
      this.avatarNames = new Vector();
      this.targetObjects = new Vector();
   }

   public static int getAction(String var0) {
      for (int var1 = 0; var1 < actions.length; var1++) {
         if (var0.equals(actions[var1])) {
            return var1;
         }
      }

      return 0;
   }

   void setTargetShape(Shape var1) {
      this._targetShape = var1;
      Point3Temp var2 = Point3Temp.make(this.targetRelPosition.x, this.targetRelPosition.y, 0.0F);
      this.targetYaw = this._targetShape.getObjectToWorldMatrix().getYaw();
      Transform var3 = new Transform();
      var3.yaw(-this.targetYaw);
      var2.vectorTimes(var3);
      var3.recycle();
      Point3Temp var4 = this._targetShape.getWorldPosition();
      var2.plus(var4);
      this.targetPosition = new Point2(var2.x, var2.y);
   }

   public void execute(HoloPilot var1) {
      if (this._targetShape == null) {
         System.out.println("No target shape for action " + this.actionName);
      } else {
         this._targetShape.setBumpable(false);
         this._pilot = var1;
         this._state = 0;
         this.stateChanged();
      }
   }

   public void motionComplete(int var1) {
      this._state++;
      this.stateChanged();
   }

   public void timerDone() {
      this.motionComplete(0);
   }

   private void stateChanged() {
      switch (this._state) {
         case 0:
            this.motionComplete(0);
            break;
         case 1:
            Console var6 = Console.getActive();
            if (var6 instanceof DefaultConsole) {
               Pilot var7 = Pilot.getActive();
               this._oldMode = var7.getOutsideCameraMode();
               this._oldSpeed = var7.getOutsideCameraSpeed();
               var7.setOutsideCameraMode(8, 1);
            }

            this.motionComplete(0);
            break;
         case 2:
            double var5 = this.targetYaw + this.targetRelYaw;
            this._pilot.addCallback(this);
            this._pilot.walkTo(new Point2(this.targetPosition.x, this.targetPosition.y), (float)var5);
            break;
         case 3:
            this._pilot.removeSmoothDriver();
            this._pilot.returnHandsOffDriver();
            this.doAction(this.preAnimationAction, this.preAnimationParameter);
            this.motionComplete(0);
            break;
         case 4:
         case 7:
            String var4;
            if (this._state == 4) {
               var4 = this.actionName1;
            } else {
               var4 = this.actionName2;
            }

            this._waitTime = this._pilot.animate(var4);
            this.motionComplete(0);
            break;
         case 5:
            this.doAction(this.simultaneousAction, this.simultaneousParameter + "|sender|" + this.actionName1);
            Timer var3 = new Timer(this._waitTime, this);
            var3.start();
            break;
         case 6:
            this.doAction(this.postAnimationAction, this.postAnimationParameter);
            this.motionComplete(0);
            break;
         case 8:
            Console var1 = Console.getActive();
            if (var1 instanceof DefaultConsole) {
               Pilot var2 = Pilot.getActive();
               var2.setOutsideCameraMode(this._oldMode, this._oldSpeed);
            }

            this._pilot.removeHandsOffDriver();
            this._pilot.returnSmoothDriver();
            AnimatedActionManager.get().actionCompleted(this);
            this.motionComplete(0);
      }
   }

   public void abort() {
      this._state = 8;
      this.stateChanged();
   }

   private void doAction(int var1, String var2) {
      switch (var1) {
         case 5:
            Sound var3 = new Sound(URL.make(var2));
            this._pilot.add(var3);
            var3.trigger(null, null);
         case 3:
            Drone var6 = null;
            if (this._targetShape != null && this._targetShape instanceof PosableShape) {
               SuperRoot var4 = this._targetShape.getOwner();
               if (var4 instanceof Drone) {
                  var6 = (Drone)var4;
               }
            }

            if (var6 != null) {
               Pilot.sendText(var6.getLongID(), "&|+action2>" + var2);
            }

            if (this._targetShape instanceof PosableShape) {
               String var7 = null;
               int var5 = var2.indexOf("|sender|");
               if (var5 != -1) {
                  var7 = var2.substring(0, var5);
               } else {
                  var7 = var2;
               }

               ((PosableShape)this._targetShape).animate(var7);
            }
         case 0:
         case 1:
         case 2:
         case 4:
      }
   }
}

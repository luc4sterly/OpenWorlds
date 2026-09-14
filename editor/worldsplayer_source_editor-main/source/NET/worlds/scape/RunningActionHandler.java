package NET.worlds.scape;

import NET.worlds.console.Console;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Vector;

public class RunningActionHandler extends SuperRoot implements FrameHandler, NonPersister {
   private Action action;
   private Persister seqID;
   private RunningActionCallback callback;
   private Object callbackCookie;
   private static Object classCookie = new Object();

   public static void trigger(Action var0, World var1, Event var2) {
      trigger(var0, var1, var2, null, null);
   }

   public static void trigger(Action var0, World var1, Event var2, RunningActionCallback var3, Object var4) {
      if (var0.isActive()) {
         Persister var5 = null;
         if ((var5 = var0.trigger(var2, var5)) != null) {
            new RunningActionHandler(var1, var0, var5, var3, var4);
         }
      }
   }

   public static void trigger(Vector var0, World var1, Event var2) {
      trigger(var0, var1, var2, null, null);
   }

   public static void trigger(Vector var0, World var1, Event var2, RunningActionCallback var3, Object var4) {
      Vector var5 = (Vector)var0.clone();
      int var6 = var5.size();

      for (int var7 = 0; var7 < var6; var7++) {
         Action var8 = (Action)var5.elementAt(var7);
         if (var0.contains(var8)) {
            trigger(var8, var1, var2, var3, var4);
         }
      }
   }

   RunningActionHandler() {
   }

   private RunningActionHandler(World var1, Action var2, Persister var3, RunningActionCallback var4, Object var5) {
      this.action = var2;
      this.seqID = var3;
      this.callback = var4;
      this.callbackCookie = var5;
      var1.addHandler(this);
   }

   public boolean handle(FrameEvent var1) {
      if (!this.action.isActive() || (this.seqID = this.action.trigger(var1, this.seqID)) == null) {
         if (this.callback != null) {
            this.callback.actionDone(this.action, var1, this.callbackCookie);
         }

         this.getWorld().removeHandler(this);
      }

      return true;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Action");
            } else if (var3 == 1) {
               var5 = this.action;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = new Property(this, var1, "Sequence ID Object");
            } else if (var3 == 1) {
               var5 = this.seqID;
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      Console.println(Console.message("Save-running"));
      var1.saveVersion(3, classCookie);
      super.saveState(var1);
      var1.save(this.action);
      var1.saveMaybeNull(this.seqID);
      var1.saveMaybeNull((Persister)this.callback);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            var1.restore();
            this.action = (Action)var1.restoreMaybeNull();
            this.callback = null;
            break;
         case 1:
            super.restoreState(var1);
            this.action = (Action)var1.restore();
            this.callback = null;
            break;
         case 2:
            super.restoreState(var1);
            this.action = (Action)var1.restore();
            this.seqID = var1.restoreMaybeNull();
            this.callback = null;
            break;
         case 3:
            super.restoreState(var1);
            this.action = (Action)var1.restore();
            this.seqID = var1.restoreMaybeNull();
            this.callback = (RunningActionCallback)var1.restoreMaybeNull();
            break;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      Object[] var2 = new Object[]{new String(this.getName())};
      Console.println(MessageFormat.format(Console.message("Discarding-old"), var2));
      SuperRoot var3 = this.getOwner();
      if (var3 instanceof WObject) {
         ((WObject)var3).removeHandler(this);
      } else if (var3 instanceof World) {
         ((World)var3).removeHandler(this);
      } else {
         Console.println(MessageFormat.format(Console.message("Unable-discard"), var2));
      }
   }

   public String toString() {
      return super.toString() + ":" + this.action.getName() + "[" + this.seqID + "]";
   }
}

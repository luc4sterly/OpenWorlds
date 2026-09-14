package NET.worlds.console;

import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.InventoryAction;
import NET.worlds.scape.InventoryManager;
import NET.worlds.scape.Pilot;
import java.awt.Container;
import java.awt.Event;
import java.util.Vector;

public class ActionsPart implements FramePart {
   static int actionToPerform = -1;
   private Pilot curPilot;
   private Vector curAnimations;
   private int numPilotAnims;
   private static ActionsPart activePart;
   private static ActionDialog dialog;
   static boolean showDialog;

   public void present() {
      showDialog = true;
      this.curPilot = null;
   }

   private static boolean anyAnimations(Vector var0) {
      return var0 != null && var0.size() != 0;
   }

   static ActionsPart access$000() {
      return activePart;
   }

   public void activate(Console var1, Container var2, Console var3) {
   }

   public void deactivate() {
   }

   public boolean action(Event var1, Object var2) {
      return false;
   }

   public static boolean listEquals(Vector var0, Vector var1) {
      if (var0 != null && var1 != null) {
         if (var0.size() != var1.size()) {
            return false;
         }

         int var2 = var0.size();

         while (--var2 >= 0) {
            Object var3 = var0.elementAt(var2);
            Object var4 = var1.elementAt(var2);
            if (var3 == null || var4 == null) {
               if (var3 != null || var4 != null) {
                  return false;
               }
            } else if (!var3.equals(var4)) {
               return false;
            }
         }

         return true;
      } else {
         return var0 == null == (var1 == null);
      }
   }

   public static void updateActionDialog() {
      if (activePart != null && dialog != null && showDialog && dialog.isVisible()) {
         Main.register(new ActionsPart$1());
      }
   }

   public void regenActionDialog() {
      Vector var1 = this.curPilot.getAnimationList();
      this.numPilotAnims = var1.size();
      Vector var2 = InventoryManager.getInventoryManager().getInventoryActionList();

      for (int var3 = 0; var3 < var2.size(); var3++) {
         InventoryAction var4 = (InventoryAction)var2.elementAt(var3);
         var1.addElement(var4.getItemName());
      }

      if (dialog != null) {
         boolean var5 = showDialog;
         if (var5 && dialog.isVisible() && listEquals(var1, this.curAnimations)) {
            return;
         }

         dialog.done(true);
         showDialog = var5;
      }

      this.curAnimations = var1;
      if (showDialog) {
         dialog = new ActionDialog(this.curAnimations);
      }
   }

   public synchronized boolean handle(FrameEvent var1) {
      Pilot var2 = Pilot.getActive();
      if (var2 != this.curPilot) {
         this.curPilot = var2;
         activePart = this;
         this.regenActionDialog();
      } else if (actionToPerform != -1 && actionToPerform < this.curAnimations.size()) {
         String var3 = (String)this.curAnimations.elementAt(actionToPerform);
         if (actionToPerform < this.numPilotAnims) {
            var2.animate(var3);
         } else {
            InventoryManager.getInventoryManager().doInventoryAction(var3);
         }
      }

      actionToPerform = -1;
      return true;
   }
}

package NET.worlds.scape;

import NET.worlds.console.DialogReceiver;
import java.util.Vector;

public abstract class WorldScript implements DialogReceiver, AnimatedActionCallback {
   public static final int CURRENT_SCRIPT_VERSION = 15;
   protected static WorldScriptToolkit toolkit = WorldScriptToolkit.getInstance();

   public int getMinScriptVersion() {
      return 15;
   }

   public abstract void roomEnter(String var1);

   public abstract void roomExit(String var1);

   public abstract void worldEnter();

   public abstract void worldExit();

   public abstract void onEachFrame();

   public void dialogDone(Object var1, boolean var2) {
   }

   public void onTriggerAction(String var1) {
   }

   public Vector onShapeClick(Object var1, String var2) {
      return null;
   }

   public void motionComplete(int var1) {
   }

   public void onMenuClick(String var1, Object var2) {
   }

   public void objectVisibilityNotification(Object var1, boolean var2) {
   }

   public void onConversation(String var1, String var2) {
   }
}

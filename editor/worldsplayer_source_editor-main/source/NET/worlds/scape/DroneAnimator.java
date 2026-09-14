package NET.worlds.scape;

import NET.worlds.console.Gamma;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.core.Std;
import java.util.Vector;

public class DroneAnimator implements MainCallback {
   public static final int INVALID_INDEX = -1;
   private static Vector deltypeList;
   protected int _rep = 0;

   public static native void init(String var0);

   public static native void loadconfig(String var0);

   public static native int getnameindex(String var0);

   public static native String getindexgeom(int var0);

   public static native void prepFigure(WObject var0, boolean var1);

   public static native void addtype(int var0);

   public static native void deltype(int var0);

   public void delayedDeltype(int var1) {
      if (deltypeList == null) {
         deltypeList = new Vector();
         Main.register(this);
      }

      deltypeList.addElement(new Integer(var1));
      deltypeList.addElement(new Integer(Std.getFastTime()));
   }

   public void mainCallback() {
      int var1 = Std.getFastTime() - 20000;

      while (deltypeList.size() > 1) {
         int var2 = (Integer)deltypeList.elementAt(1);
         if (var2 > var1) {
            break;
         }

         int var3 = (Integer)deltypeList.elementAt(0);
         deltype(var3);
         deltypeList.removeElementAt(0);
         deltypeList.removeElementAt(0);
      }
   }

   public DroneAnimator() {
      this._rep = CreateRep();
   }

   public void finalize() throws Throwable {
      DestroyRep(this._rep);
      super.finalize();
   }

   public native void endanimations();

   public native void moveto(int var1, short var2, short var3, short var4, short var5, int var6);

   public native void moveby(int var1, short var2, short var3, short var4, int var5);

   public native void update(WObject var1, WObject var2, int var3, float var4, boolean var5);

   public native float animate(int var1, String var2, int var3);

   public native float getAnimationTime(int var1, String var2);

   public static synchronized native Vector getActionList(int var0);

   protected static native int CreateRep();

   protected static native void DestroyRep(int var0);

   static {
      init(".");
      if (Gamma.loadProgress != null) {
         Gamma.loadProgress.setMessage("Loading avatar definitions...");
         Gamma.loadProgress.advance();
      }

      loadconfig(PendingCacheDrone.getAvatarDatPath());
   }
}

package NET.worlds.scape;

import NET.worlds.core.Debug;
import NET.worlds.network.Cache;
import NET.worlds.network.URL;

class SoundState implements State {
   public static final int IDLE = 0;
   public static final int start = 1;
   public static final int intel0 = 1000;
   public static final int intel10 = 1010;
   public static final int intel11 = 1011;
   public static final int intel20 = 1020;
   public static final int intel21 = 1021;
   public static final int intel30 = 1030;
   public static final int intel31 = 1031;
   public static final int intel32 = 1032;
   public static final int intel33 = 1033;
   public static final int realAudio0 = 2000;
   public static final int realAudio10 = 2010;
   public static final int realAudio11 = 2011;
   private static SoundState instance = new SoundState();
   private static URL dummy = URL.make("home:dummy.wav");

   private SoundState() {
   }

   private void debugOut(int var1, String var2) {
      if (Sound.debugLevel > var1) {
         System.out.println(var2);
      }
   }

   public static State instance() {
      return instance;
   }

   public Object doState(StateContext var1, Object var2) {
      Sound var4 = (Sound)var1;
      Object var3;
      switch (var4.state) {
         case 1:
            var3 = this.start(var4, var2);
            break;
         case 1000:
            var3 = this.intel0(var4, var2);
            break;
         case 1010:
            var3 = this.intel10(var4, var2);
            break;
         case 1011:
            var3 = this.intel11(var4, var2);
            break;
         case 1020:
            var3 = this.intel20(var4, var2);
            break;
         case 1021:
            var3 = this.intel21(var4, var2);
            break;
         case 1030:
            var3 = this.intel30(var4, var2);
            break;
         case 1031:
            var3 = this.intel31(var4, var2);
            break;
         case 1032:
            var3 = this.intel32(var4, var2);
            break;
         case 1033:
            var3 = this.intel33(var4, var2);
            break;
         case 2000:
            var3 = this.realAudio0(var4, var2);
            break;
         case 2010:
            var3 = this.realAudio10(var4, var2);
            break;
         case 2011:
            var3 = this.realAudio11(var4, var2);
            break;
         default:
            var3 = this.error(var4, var2);
      }

      return var3;
   }

   private Object error(Sound var1, Object var2) {
      this.debugOut(2, "Unknown state in SoundState " + var1.state);
      return null;
   }

   private Object start(Sound var1, Object var2) {
      this.debugOut(6, "Entering SoundState ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var1.isRealAudio(var1.getURL())) {
         var1.changeState(2000);
      } else {
         var1.changeState(1000);
      }

      var1.doState(null);
      return null;
   }

   private Object intel0(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel0 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (!SoundResource.instance().syncLock(1)) {
         return null;
      } else if (!var1.getURL().isRemote()) {
         var1.changeState(1010);
         BackgroundLoader.get(var1, var1.getURL());
         return null;
      } else {
         var1.cachedFile = Cache.getFile(var1.getURL());
         if (var1.cachedFile.done()) {
            var1.ensureClosure();
            var1.changeState(1020);
            BackgroundLoader.get(var1, var1.getURL());
            return null;
         } else {
            var1.cachedFile.finalize();
            var1.cachedFile = null;
            var1.changeState(1030);
            BackgroundLoader.get(var1, dummy);
            return null;
         }
      }
   }

   private Object intel10(Sound var1, Object var2) {
      Debug.dAssert(var1.backgroundState == 2);
      Debug.dAssert(var2 != null);
      SoundResource.instance().asyncLock();
      var1.changeState(1011);
      if (var1.openPlayer((URL)var2)) {
         return var2;
      }

      this.debugOut(2, "intel10: couldn't open sound " + var1.getURL());
      return null;
   }

   private Object intel11(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel11 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var2 != null) {
         if (var1.updateSound()) {
            var1.player.start(var1.getRepeat());
         } else {
            var1.closePlayer();
         }
      }

      var1.changeState(0);
      return null;
   }

   private Object intel20(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel20 ");
      Debug.dAssert(var1.backgroundState == 2);
      SoundResource.instance().asyncLock();
      if (var1.openPlayer((URL)var2)) {
         var1.changeState(1021);
         return var2;
      } else {
         this.debugOut(2, "intel20: couldn't open player on sound " + var1.getURL());
         var1.changeState(1021);
         return null;
      }
   }

   private Object intel21(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel21 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var2 == null) {
         var1.unlockCache();
      } else if (var1.updateSound()) {
         this.debugOut(6, "intel21 starting sound");
         var1.player.start(var1.getRepeat());
      } else {
         this.debugOut(6, "intel21 closing player");
         var1.closePlayer();
      }

      var1.changeState(0);
      return null;
   }

   private Object intel30(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel30 ");
      Debug.dAssert(var1.backgroundState == 2);
      SoundResource.instance().asyncLock();
      if (var1.openPlayer(dummy)) {
         var1.changeState(1031);
         return var2;
      } else {
         this.debugOut(2, "intel30: couldn't open player on file " + var1.getURL());
         var1.changeState(1031);
         return null;
      }
   }

   private Object intel31(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel31 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var2 == null) {
         var1.changeState(0);
      } else if (var1.updateSound()) {
         var1.player.start(1);
         var1.changeState(1032);
         BackgroundLoader.get(var1, var1.getURL());
      } else {
         var1.closePlayer();
         var1.changeState(0);
      }

      return null;
   }

   private Object intel32(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel32 ");
      Debug.dAssert(var1.backgroundState == 2);
      var1.changeState(1033);
      return var2;
   }

   private Object intel33(Sound var1, Object var2) {
      this.debugOut(6, "Entering intel33 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var2 != null && var1.playAfterLoading) {
         var1.closePlayer();
         var1.changeState(1000);
         var1.doState(var2);
      } else {
         var1.changeState(0);
      }

      return null;
   }

   private Object realAudio0(Sound var1, Object var2) {
      this.debugOut(6, "Entering RealAudio0 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (!SoundResource.instance().syncLock(2)) {
         return null;
      }

      var1.changeState(2010);
      BackgroundLoader.get(var1, dummy);
      return null;
   }

   private Object realAudio10(Sound var1, Object var2) {
      this.debugOut(6, "Entering realAudio10 ");
      Debug.dAssert(var1.backgroundState == 2);
      SoundResource.instance().asyncLock();
      if (var1.openPlayer(var1.getURL())) {
         var1.changeState(2011);
         return var1;
      } else {
         return null;
      }
   }

   private Object realAudio11(Sound var1, Object var2) {
      this.debugOut(6, "Entering realAudio11 ");
      Debug.dAssert(var1.backgroundState == 1);
      if (var2 != null) {
         if (var1.updateSound()) {
            var1.player.start(var1.getRepeat());
         } else {
            var1.closePlayer();
         }
      }

      var1.changeState(0);
      return null;
   }
}

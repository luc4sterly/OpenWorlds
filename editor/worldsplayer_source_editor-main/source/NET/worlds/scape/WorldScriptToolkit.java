package NET.worlds.scape;

public abstract class WorldScriptToolkit {
   public static final int videoWallNotFound = -1;
   public static final int videoUnitialized = 0;
   public static final int videoStopped = 1;
   public static final int videoPaused = 2;
   public static final int videoPlaying = 3;
   private static WorldScriptToolkit instance = new WorldScriptToolkitImp();

   public abstract int getTime();

   public abstract void teleport(String var1, boolean var2);

   public abstract float getPilotX();

   public abstract float getPilotY();

   public abstract float getPilotYaw();

   public abstract void walkTo(float var1, float var2, float var3, float var4);

   public abstract void walkTo(float var1, float var2, float var3);

   public abstract void walkTo(WorldScript var1, float var2, float var3, float var4, float var5);

   public abstract float getWalkFriction();

   public abstract void setWalkFriction(float var1);

   public abstract void showWebPage(String var1);

   public abstract void showWebPage(String var1, int var2, int var3);

   public abstract void showAdBanner(String var1, int var2, int var3);

   public abstract void showExternalWebPage(String var1);

   public abstract Object playSound(String var1, int var2);

   public abstract void stopSound(Object var1);

   public abstract boolean serviceSound(Object var1);

   public abstract String expandURLMacros(String var1);

   public abstract int getIniInt(String var1, int var2);

   public abstract String getIniString(String var1, String var2);

   public abstract void setIniInt(String var1, int var2);

   public abstract void setIniString(String var1, String var2);

   public abstract int getClientVersion();

   public abstract void messageBox(String var1, String var2);

   public abstract Object yesNoDialog(String var1, String var2, String var3, String var4, WorldScript var5);

   public abstract void printToChat(String var1);

   public abstract Object findObjectInRoom(String var1);

   public abstract void walkObjectTo(WorldScript var1, Object var2, float var3, float var4, float var5, float var6);

   public abstract void moveObjectTo(Object var1, float var2, float var3, float var4);

   public abstract void moveObjectTo(Object var1, float var2, float var3, float var4, float var5);

   public abstract boolean animateBot(Object var1, String var2);

   public abstract boolean watchVisibility(Object var1);

   public abstract boolean setShapeURL(Object var1, String var2);

   public abstract int getVideoWallStatus(Object var1);

   public abstract boolean playVideo(Object var1, int var2);

   public abstract boolean stopVideo(Object var1);

   public abstract boolean setVideoURL(Object var1, String var2, int var3, int var4);

   public abstract boolean setWebWallURL(Object var1, String var2);

   public abstract boolean setWebWallURL(Object var1, String var2, String var3);

   public abstract void setAdCube(boolean var1, boolean var2, String var3, String var4);

   public abstract boolean isLoggedIn();

   public abstract int getConcurrentDownloads();

   public abstract boolean getIsVIP();

   public static WorldScriptToolkit getInstance() {
      return instance;
   }
}

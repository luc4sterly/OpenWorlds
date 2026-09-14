package NET.worlds.network;

import NET.worlds.core.Debug;
import NET.worlds.scape.Room;

public class NetworkNobody {
   String _longID;
   WorldServer _server;

   public NetworkNobody(String var1, WorldServer var2) {
      this._longID = var1;
      this._server = var2;
   }

   public WorldServer getServer() {
      return this._server;
   }

   public String getLongID() {
      return this._longID;
   }

   public void appear(Room var1, short var2, short var3, short var4, short var5) {
      Debug.dAssert(false);
   }

   public void disappear() {
      Debug.dAssert(false);
   }

   public void longLoc(short var1, short var2, short var3, short var4) {
      Debug.dAssert(false);
   }

   public void roomChange(Room var1, short var2, short var3, short var4, short var5) {
      Debug.dAssert(false);
   }

   public void shortLoc(byte var1, byte var2, byte var3) {
      Debug.dAssert(false);
   }

   public void teleport(WorldServer var1, byte var2, byte var3, Room var4, short var5, short var6, short var7, short var8) {
      Debug.dAssert(false);
   }

   public void property(OldPropertyList var1) {
   }

   public void propertyUpdate(PropertyList var1) {
   }

   public void register() {
      Debug.dAssert(false);
   }

   public void galaxyDisconnected() {
      Debug.dAssert(false);
   }

   public void reacquireServer(WorldServer var1) {
      Debug.dAssert(false);
   }

   public void changeChannel(Galaxy var1, String var2, String var3) {
      Debug.dAssert(false);
   }
}

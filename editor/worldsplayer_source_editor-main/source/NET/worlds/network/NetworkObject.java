package NET.worlds.network;

public interface NetworkObject {
   void property(OldPropertyList var1);

   void propertyUpdate(PropertyList var1);

   WorldServer getServer();

   String getLongID();

   void register();

   void galaxyDisconnected();

   void reacquireServer(WorldServer var1);

   void changeChannel(Galaxy var1, String var2, String var3);
}

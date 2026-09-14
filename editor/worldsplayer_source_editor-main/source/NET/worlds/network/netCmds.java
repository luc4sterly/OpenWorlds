package NET.worlds.network;

import java.util.Hashtable;
import java.util.Vector;

class netCmds {
   private Vector _recvNetPacket = new Vector();
   private static Hashtable _propList = new Hashtable();

   public netCmds() {
      this._recvNetPacket.addElement("appInitCmd");
      this._recvNetPacket.addElement("appearActorCmd");
      this._recvNetPacket.addElement("disappearActorCmd");
      this._recvNetPacket.addElement("longLocCmd");
      this._recvNetPacket.addElement("propCmd");
      this._recvNetPacket.addElement("regObjIDCmd");
      this._recvNetPacket.addElement("roomChangeCmd");
      this._recvNetPacket.addElement("sessionExitCmd");
      this._recvNetPacket.addElement("sessionInitCmd");
      this._recvNetPacket.addElement("shortLocCmd");
      this._recvNetPacket.addElement("teleportCmd");
      this._recvNetPacket.addElement("textCmd");
      this._recvNetPacket.addElement("whisperCmd");
      this._recvNetPacket.addElement("roomIDCmd");
      this._recvNetPacket.addElement("PropertySetCmd");
      this._recvNetPacket.addElement("PropertyUpdateCmd");
      this._recvNetPacket.addElement("FingerReplyCmd");
      this._recvNetPacket.addElement("RedirectCmd");
      this._recvNetPacket.addElement("RedirectIDCmd");
      this._recvNetPacket.addElement("BuddyListNotifyCmd");
   }

   Vector recvCmdList() {
      return this._recvNetPacket;
   }

   static String getPropName(int var0) {
      return (String)_propList.get(new Integer(var0));
   }

   static {
      _propList.put(new Integer(1), "VAR_APPNAME");
      _propList.put(new Integer(2), "VAR_USERNAME");
      _propList.put(new Integer(3), "VAR_PROTOCOL");
      _propList.put(new Integer(4), "VAR_ERROR");
      _propList.put(new Integer(5), "VAR_CHANNEL");
      _propList.put(new Integer(6), "VAR_PASSWORD");
      _propList.put(new Integer(7), "VAR_AVATARS");
      _propList.put(new Integer(8), "VAR_UPDATETIME");
      _propList.put(new Integer(9), "VAR_CLIENT");
      _propList.put(new Integer(10), "VAR_SERIAL");
      _propList.put(new Integer(11), "VAR_EMAIL");
      _propList.put(new Integer(12), "VAR_LOGONOFF");
      _propList.put(new Integer(13), "VAR_DURATION");
      _propList.put(new Integer(14), "VAR_GUEST");
      _propList.put(new Integer(15), "VAR_SERVERTYPE");
      _propList.put(new Integer(16), "VAR_BIZCARD");
      _propList.put(new Integer(22), "VAR_PRIV");
      _propList.put(new Integer(20), "VAR_NEW_PASSWD");
      _propList.put(new Integer(23), "VAR_ASLEEP");
      _propList.put(new Integer(24), "VAR_EXTERNAL_HTTP_SERVER");
      _propList.put(new Integer(25), "VAR_SCRIPT_SERVER");
      _propList.put(new Integer(26), "VAR_SMTP_SERVER");
      _propList.put(new Integer(27), "VAR_MAIL_DOMAIN");
      _propList.put(new Integer(28), "VAR_NEW_USERNAME");
      _propList.put(new Integer(29), "VAR_INTERNAL_HTTP_SERVER");
   }
}

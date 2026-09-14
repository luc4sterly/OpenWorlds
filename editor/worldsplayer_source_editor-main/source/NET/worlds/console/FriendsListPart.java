package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.BuddyListUpdateCmd;
import NET.worlds.network.Galaxy;
import NET.worlds.network.InfiniteWaitException;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.PacketTooLargeException;
import NET.worlds.network.WorldServer;
import NET.worlds.network.netPacket;
import NET.worlds.network.whisperCmd;
import NET.worlds.scape.AnimatedActionManager;
import NET.worlds.scape.Drone;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.MouseDownEvent;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.PosableDrone;
import NET.worlds.scape.PosableShape;
import NET.worlds.scape.TeleportAction;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.PopupMenu;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.StringTokenizer;
import java.util.Vector;

public class FriendsListPart extends QuantizedCanvas implements FramePart, DialogReceiver, DialogDisabled, NameListOwner {
   private static final String oldIniItemName = "Friends";
   private static final String iniItemName = "Friend";
   private static int maxFriends = Gamma.shaperEnabled() ? 60 : 30;
   private static int absMaxFriends = 100;
   private static final String separator = ";";
   private static final String whereQuery = "&|+where?";
   private static final String whereResponse = "&|+where>";
   VoiceChat chatter = new VoiceChat();
   private static final int MOUSEMOVE = 0;
   private static final int MOUSEDRAG = 1;
   private static final int MOUSEDOWN = 2;
   private static final int MOUSEUP = 3;
   private static final int MOUSEENTER = 4;
   private static final int MOUSEEXIT = 5;
   private static final int BLANK = 0;
   private static final int NORMAL = 1;
   private static final int CURSED = 2;
   private static final int DOWN = 3;
   private static final int TELEPORT_IDLE = 0;
   private static final int TELEPORT_REQUEST_LOCATION = 1;
   private static final int TELEPORT_WAIT_FOR_LOCATION = 2;
   private static final int buttonWidth = 97;
   private static final int buttonHeight = 11;
   private static final int xText = 20;
   private static final int yText = 9;
   private static final int xTextClip = 94;
   private static Image friendsImage;
   private static Image moreFriendsImage;
   private static Font font;
   private static FriendsListPart active;
   private Vector friends = new Vector();
   private Vector onlineFriends = new Vector();
   private Vector mutedOnlineFriends = new Vector();
   private Vector serverUpdates = new Vector();
   private Object friendsMutex = new Object();
   private int cursedButton = -1;
   private int clickedButton = -1;
   private boolean clickedButtonDown;
   private PopupMenu menu;
   private MenuItem teleportItem = new MenuItem(Console.message("Go-There"));
   private MenuItem emailItem = new MenuItem(Console.message("E-Mail"));
   private MenuItem muteItem = new MenuItem(Console.message("Mute"));
   private MenuItem whisperItem = new MenuItem(Console.message("Whisper"));
   private MenuItem voiceChatItem = new MenuItem(Console.message("Voice-Chat"));
   private MenuItem infoItem = new MenuItem(Console.message("Personal-I"));
   private MenuItem tradeItem = new MenuItem(Console.message("Talk-Trade"));
   private PopupMenu droneMenu;
   private MenuItem droneAddItem = new MenuItem(Console.message("Add-2-friends"));
   private MenuItem droneEmailItem = new MenuItem(Console.message("E-Mail"));
   private MenuItem droneMuteItem = new MenuItem(Console.message("Mute"));
   private MenuItem droneWhisperItem = new MenuItem(Console.message("Whisper"));
   private MenuItem droneVoiceChatItem = new MenuItem(Console.message("Voice-Chat"));
   private MenuItem droneInfoItem = new MenuItem(Console.message("Personal-I"));
   private MenuItem droneTradeItem = new MenuItem(Console.message("Talk-Trade"));
   private String activeFriendName = "";
   private String teleportTarget;
   private int teleportState = 0;
   private int teleportWaitStartTime;
   private boolean teleportWaitSentMsg;
   private int friendsButtons;
   private int moreFriendsButton;
   private boolean moreFriendsActive;
   private MenuItem editItem;
   private Menu actionMenu;
   private MoreFriendsDialog moreFriendsDialog;
   private DefaultConsole console;
   private Galaxy galaxy;
   private IniFile serverSection;
   private boolean isDialogDisabled;
   private int showMenuY = -1;
   private static final String voiceChatWhisper = "&|+voicechat";

   public FriendsListPart() {
      AnimatedActionManager.get();
      if (font == null) {
         String var1 = IniFile.override().getIniString("friendsGif", "friends.gif");
         friendsImage = ImageCanvas.getSystemImage(var1, this);
         String var2 = IniFile.override().getIniString("moreFriendsGif", Console.message("mfriends.gif"));
         moreFriendsImage = ImageCanvas.getSystemImage(var2, this);
         int var3 = new Integer(Console.message("FriendsPointSize"));
         font = new Font(Console.message("FriendsFont"), 0, var3);
      }

      this.teleportItem.setFont(font);
      this.emailItem.setFont(font);
      this.muteItem.setFont(font);
      this.whisperItem.setFont(font);
      this.tradeItem.setFont(font);
      this.voiceChatItem.setFont(font);
      this.infoItem.setFont(font);
      this.menu = new PopupMenu();
      this.menu.add(this.teleportItem);
      String var4 = IniFile.override().getIniString("ProductName", "");
      if (!var4.equalsIgnoreCase("RedLightWorld")) {
         this.menu.add(this.emailItem);
      }

      this.menu.add(this.muteItem);
      this.menu.add(this.whisperItem);
      if (NetUpdate.isInternalVersion()) {
         this.menu.add(this.tradeItem);
      }

      this.menu.add(this.voiceChatItem);
      if (!VoiceChat.voiceChatAvailable()) {
         this.voiceChatItem.setEnabled(false);
      }

      this.menu.add(this.infoItem);
      this.add(this.menu);
      this.droneAddItem.setFont(font);
      this.droneEmailItem.setFont(font);
      this.droneMuteItem.setFont(font);
      this.droneWhisperItem.setFont(font);
      this.droneTradeItem.setFont(font);
      this.droneVoiceChatItem.setFont(font);
      this.droneInfoItem.setFont(font);
      this.droneMenu = new PopupMenu();
      this.droneMenu.setFont(font);
      this.droneMenu.add(this.droneAddItem);
      this.droneMenu.add(this.droneEmailItem);
      this.droneMenu.add(this.droneMuteItem);
      this.droneMenu.add(this.droneWhisperItem);
      if (NetUpdate.isInternalVersion()) {
         this.droneMenu.add(this.droneTradeItem);
      }

      this.droneMenu.add(this.droneVoiceChatItem);
      if (!VoiceChat.voiceChatAvailable()) {
         this.droneVoiceChatItem.setEnabled(false);
      }

      this.droneMenu.add(this.droneInfoItem);
      this.add(this.droneMenu);
   }

   public void update(Graphics var1) {
      this.paint(var1);
   }

   public void paint(Graphics var1) {
      int var2 = this.size().height;
      int var3 = var2 / 11;
      synchronized (this.friendsMutex) {
         int var5 = this.onlineFriends.size();
         this.moreFriendsButton = var3 - 1;
         if (var5 >= var3) {
            this.friendsButtons = var3 - 1;
            this.moreFriendsActive = true;
         } else {
            this.friendsButtons = var5;
            this.moreFriendsActive = false;
         }

         int var6 = var3 * 11;
         int var7 = var2 - var6;
         if (var7 > 0) {
            var1.setColor(Color.black);
            var1.fillRect(0, 0, 97, var7);
         }

         for (int var8 = 0; var8 < var3; var8++) {
            byte var9 = 1;
            if (var8 >= this.friendsButtons && !this.isMoreFriendsButton(var8)) {
               var9 = 0;
            } else if (var8 == this.clickedButton) {
               var9 = (byte)(this.clickedButtonDown ? 3 : 1);
            } else if (var8 == this.cursedButton) {
               var9 = 2;
            }

            this.drawButton(var1, var8, var9);
         }
      }
   }

   public int getRemainder(int var1) {
      int var2 = var1 / 11;
      int var3 = var2 * 11;
      return var1 - var3;
   }

   public Dimension preferredSize() {
      return new Dimension(97, 1);
   }

   public Dimension minimumSize() {
      return this.preferredSize();
   }

   public boolean mouseMove(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 0);
   }

   public boolean mouseDown(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 2);
   }

   public boolean mouseUp(Event var1, int var2, int var3) {
      if (this.buttonAction(var2, var3, 3)) {
         if (this.showMenuY != -1) {
            this.menu.show(this, 0, this.showMenuY);
            this.showMenuY = -1;
         }

         return true;
      } else {
         return false;
      }
   }

   public boolean mouseDrag(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 1);
   }

   public boolean mouseEnter(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 4);
   }

   public boolean mouseExit(Event var1, int var2, int var3) {
      return this.buttonAction(var2, var3, 5);
   }

   public boolean handleEvent(Event var1) {
      return this.isDialogDisabled ? false : super.handleEvent(var1);
   }

   private void loadFriends() {
      if (this.friends.size() != 0) {
         this.friends.removeAllElements();
      }

      if (Console.getActive().broadcastEnabled()) {
         maxFriends = 100;
      }

      for (int var1 = 0; var1 < absMaxFriends; var1++) {
         String var2 = this.serverSection.getIniString("Friend" + var1, "");
         if (var2.length() == 0) {
            break;
         }

         if (isValidUserName(var2) && !icontains(this.friends, var2)) {
            this.friends.addElement(var2);
         }
      }

      if (this.friends.size() == 0) {
         String var4 = this.serverSection.getIniString("Friends", "");
         StringTokenizer var5 = new StringTokenizer(var4, ";");

         while (var5.hasMoreTokens() && this.friends.size() < absMaxFriends) {
            String var3 = var5.nextToken();
            if (isValidUserName(var3) && !icontains(this.friends, var3)) {
               this.friends.addElement(var3);
            }
         }

         if (this.friends.size() != 0) {
            this.saveFriends();
            this.serverSection.setIniString("Friends", "");
         }
      }
   }

   void saveFriends() {
      if (this.serverSection != null) {
         int var1 = this.friends.size();

         for (int var2 = 0; var2 < var1; var2++) {
            this.serverSection.setIniString("Friend" + var2, (String)this.friends.elementAt(var2));
         }

         this.serverSection.setIniString("Friend" + var1, "");
      }
   }

   private boolean isMoreFriendsButton(int var1) {
      return var1 == this.moreFriendsButton && this.moreFriendsActive;
   }

   private Graphics drawButton(Graphics var1, int var2, int var3) {
      Image var4 = var2 == this.moreFriendsButton ? moreFriendsImage : friendsImage;
      if (var1 != null || (var1 = this.getGraphics()) != null) {
         int var5 = var2 * 11;
         Graphics var6 = var1.create(0, var5, 97, 11);
         var6.drawImage(var4, -var3 * 97, 0, null);
         if (var2 >= 0 && var2 < this.friendsButtons && var2 < this.onlineFriends.size()) {
            var6.clipRect(0, 0, 94, 11);
            var6.setFont(font);
            var6.setColor(Color.white);
            var6.drawString((String)this.onlineFriends.elementAt(var2), 20, 9);
         }

         var6.dispose();
      }

      return var1;
   }

   private boolean buttonAction(int var1, int var2, int var3) {
      synchronized (this.friendsMutex) {
         Graphics var5 = null;
         int var6 = var2 / 11;
         if ((var6 < 0 || var6 >= this.friendsButtons) && !this.isMoreFriendsButton(var6)) {
            var6 = -1;
         }

         if (var3 != 0 && var3 != 4) {
            if (var3 == 5) {
               if (this.cursedButton != -1) {
                  var5 = this.drawButton(var5, this.cursedButton, 1);
                  this.cursedButton = -1;
               }

               if (this.clickedButton != -1 && this.clickedButtonDown) {
                  var5 = this.drawButton(var5, this.clickedButton, 1);
                  this.clickedButtonDown = false;
               }
            } else if (var3 == 2) {
               if (this.clickedButton != -1) {
                  var5 = this.drawButton(var5, this.clickedButton, 1);
                  this.clickedButtonDown = false;
               }

               if ((this.clickedButton = var6) != -1) {
                  var5 = this.drawButton(var5, this.clickedButton, 3);
                  this.clickedButtonDown = true;
               }
            } else if (var3 == 1) {
               if (this.clickedButton != -1) {
                  if (this.clickedButtonDown) {
                     if (var6 != this.clickedButton) {
                        var5 = this.drawButton(var5, this.clickedButton, 1);
                        this.clickedButtonDown = false;
                     }
                  } else if (var6 == this.clickedButton) {
                     var5 = this.drawButton(var5, this.clickedButton, 3);
                     this.clickedButtonDown = true;
                  }
               }
            } else if (var3 == 3) {
               this.cursedButton = var6;
               if (this.clickedButtonDown) {
                  if (this.cursedButton == this.clickedButton) {
                     var5 = this.drawButton(var5, this.clickedButton, 2);
                  } else {
                     var5 = this.drawButton(var5, this.clickedButton, 1);
                  }

                  if (this.clickedButton == this.moreFriendsButton) {
                     if (this.moreFriendsDialog == null) {
                        this.moreFriendsDialog = new MoreFriendsDialog(this, this.menu, this.onlineFriends);
                     }
                  } else if (this.clickedButton >= 0 && this.clickedButton < this.onlineFriends.size()) {
                     this.activeFriendName = (String)this.onlineFriends.elementAt(this.clickedButton);
                     Debug.assert_(this.activeFriendName != null);
                     this.showMenuY = (this.clickedButton + 1) * 11;
                  }
               }

               if (this.cursedButton != this.clickedButton) {
                  var5 = this.drawButton(var5, this.cursedButton, 2);
               }

               this.clickedButtonDown = false;
               this.clickedButton = -1;
            }
         } else if (var6 != this.cursedButton) {
            var5 = this.drawButton(var5, this.cursedButton, 1);
            var5 = this.drawButton(var5, this.cursedButton = var6, 2);
         }

         if (var5 != null) {
            var5.dispose();
         }

         return true;
      }
   }

   private static boolean sendMsg(WorldServer var0, netPacket var1) {
      try {
         var0.sendNetworkMsg(var1);
         return true;
      } catch (InfiniteWaitException var3) {
      } catch (PacketTooLargeException var4) {
      }

      return false;
   }

   public void activate(Console var1, Container var2, Console var3) {
      active = this;
      this.console = (DefaultConsole)var1;
      this.editItem = var1.addMenuItem(Console.message("Edit-Friends"), "Options");
      this.editItem.setEnabled(this.friends != null);
   }

   public void deactivate() {
      active = null;
      this.editItem = null;
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.editItem) {
         new EditNamesDialog(this, Console.message("Edit-Friends2"), Console.message("Add-Friend"));
         return true;
      } else {
         return this.maybeFriendAction(var1.target);
      }
   }

   public boolean handle(FrameEvent var1) {
      synchronized (this.friendsMutex) {
         int var3 = this.serverUpdates.size();
         if (var3 != 0) {
            WorldServer var4 = this.console.getServerNew();
            if (var4 != null) {
               while (var3-- != 0 && sendMsg(var4, (netPacket)this.serverUpdates.elementAt(0))) {
                  this.serverUpdates.removeElementAt(0);
               }
            }
         }
      }

      synchronized (this) {
         if (this.teleportState == 1) {
            WorldServer var9 = this.console.getServerNew();
            if (var9 != null) {
               sendMsg(var9, new whisperCmd(this.teleportTarget, "&|+where?"));
               this.teleportState = 2;
               this.teleportWaitStartTime = Std.getRealTime();
               this.teleportWaitSentMsg = false;
            } else {
               Console.println(Console.message("Cant-go-there"));
               this.teleportState = 0;
            }
         }

         if (this.teleportState == 2) {
            int var10 = Std.getRealTime();
            if (var10 > this.teleportWaitStartTime + 5000) {
               if (var10 > this.teleportWaitStartTime + 30000) {
                  this.teleportState = 0;
                  if (this.teleportWaitSentMsg) {
                     Object[] var11 = new Object[]{new String(this.teleportTarget)};
                     Console.println(MessageFormat.format(Console.message("Cancel-teleport"), var11));
                  }
               } else if (!this.teleportWaitSentMsg) {
                  Object[] var12 = new Object[]{new String(this.teleportTarget)};
                  Console.println(MessageFormat.format(Console.message("Delay-locating"), var12));
                  this.teleportWaitSentMsg = true;
               }
            }
         }

         return true;
      }
   }

   public void dialogDisable(boolean var1) {
      if (this.isDialogDisabled = var1) {
         this.cursedButton = -1;
         this.clickedButton = -1;
         this.clickedButtonDown = false;
         this.repaint();
      }
   }

   public void setServer(WorldServer var1, IniFile var2) {
      this.serverSection = var2;
      this.galaxy = var1.getGalaxy();
      Debug.dAssert(var2 != null);
      Debug.dAssert(this.galaxy != null);
      this.loadFriends();
      if (this.editItem != null) {
         this.editItem.setEnabled(true);
      }

      this.sendAll(var1);
   }

   public void maybeServerDisconnect() {
      if (this.galaxy != null) {
         if (this.editItem != null) {
            this.editItem.setEnabled(false);
         }

         this.clearAll();
      }
   }

   public static boolean tryToRun(String var0) {
      try {
         Runtime.getRuntime().exec(var0);
         return true;
      } catch (IOException var2) {
         return false;
      }
   }

   private boolean maybeFriendAction(Object var1) {
      if (var1 == this.emailItem || var1 == this.droneEmailItem) {
         EMailPart.showMessage(this.console, this.activeFriendName);
      } else if (var1 == this.whisperItem || var1 == this.droneWhisperItem) {
         Console.startWhispering(this.activeFriendName);
      } else if (var1 == this.voiceChatItem || var1 == this.droneVoiceChatItem) {
         this.chatter.beginChat(this.activeFriendName, this.console);
      } else if (var1 == this.droneAddItem) {
         if (this.mayAddNameListName(Console.getFrame())) {
            this.addNameListName(this.activeFriendName);
         }
      } else if (var1 == this.teleportItem) {
         synchronized (this) {
            this.teleportTarget = this.activeFriendName;
            if (this.teleportState == 2 && this.teleportWaitSentMsg) {
               Console.println(Console.message("Cancel-new-tele"));
            }

            this.teleportState = 1;
         }
      } else if (var1 == this.muteItem || var1 == this.droneMuteItem) {
         if (this.console.getMutes().mayAddNameListName(Console.getFrame())) {
            this.console.getMutes().addNameListName(this.activeFriendName);
         }
      } else if (var1 != this.infoItem && var1 != this.droneInfoItem) {
         if (var1 != this.tradeItem && var1 != this.droneTradeItem) {
            return false;
         }

         WhisperManager.whisperManager().startToTrade(this.activeFriendName);
      } else {
         new PersonalInfoDownload(this.activeFriendName, this.console);
      }

      return true;
   }

   private void clearAll() {
      if (this.galaxy != null) {
         synchronized (this.friendsMutex) {
            this.onlineFriends.removeAllElements();
            this.mutedOnlineFriends.removeAllElements();
         }

         if (active == this) {
            this.repaint();
         }

         this.galaxy.sentFriendsList(false);
      }
   }

   private void sendAll(WorldServer var1) {
      if (!this.galaxy.sentFriendsList()) {
         synchronized (this.friendsMutex) {
            int var3 = this.friends.size();

            for (int var4 = 0; var4 < var3; var4++) {
               sendMsg(var1, new BuddyListUpdateCmd((String)this.friends.elementAt(var4), 1));
            }
         }

         this.galaxy.sentFriendsList(true);
      }
   }

   private static String getWorldName(String var0) {
      int var1 = var0.indexOf(".world#");
      int var2;
      return var1 == -1 || (var2 = var0.lastIndexOf(47, var1)) == -1 && (var2 = var0.lastIndexOf(58, var1)) == -1 ? null : var0.substring(var2 + 1, var1);
   }

   public static void processWhisper(WorldServer var0, String var1, String var2) {
      if (active != null && active.galaxy == var0.getGalaxy()) {
         active.instanceProcessWhisper(var0, var1, var2);
      }
   }

   private synchronized void instanceProcessWhisper(WorldServer var1, String var2, String var3) {
      if (var3.startsWith("&|+where?")) {
         Pilot var4;
         String var5;
         if ((var4 = Pilot.getActive()) != null && (var5 = var4.getTeleportURL()) != null) {
            if (this.console.getSpecialGuest()) {
               int var6 = var5.indexOf(60);
               int var7 = var5.indexOf(62);
               var5 = var5.substring(0, var6) + var5.substring(var7 + 1);
            }

            if (Pilot.getActive().getRoom().getAllowTeleport()) {
               sendMsg(var1, new whisperCmd(var2, "&|+where>" + var5));
            }
         }
      } else if (var3.startsWith("&|+where>")) {
         if (this.teleportState == 2 && this.teleportTarget.equals(var2)) {
            String var9 = var3.substring("&|+where>".length());
            boolean var10 = false;
            String var11 = getWorldName(var9);
            if (!var9.startsWith("home:") && !var9.startsWith("http://")) {
               if (var11 != null && var11.length() > 0) {
                  Pilot var12 = Pilot.getActive();
                  if (var12 != null) {
                     String var8 = var12.getTeleportURL();
                     if (var8 != null && var11.equals(getWorldName(var8))) {
                        var10 = true;
                        var9 = var8.substring(0, var8.lastIndexOf(35)) + var9.substring(var9.lastIndexOf(35));
                     }
                  }
               }

               if (!var10) {
                  String var13 = WorldsMarkPart.findPackage(var11);
                  if (var13 != null) {
                     var10 = true;
                     var9 = "home:" + var13 + "/" + var13 + ".world" + var9.substring(var9.lastIndexOf(35));
                  }
               }
            } else {
               var10 = true;
            }

            if (var10) {
               TeleportAction.teleport(var9, null);
               if (this.teleportWaitSentMsg) {
                  Object[] var14 = new Object[]{new String(this.teleportTarget)};
                  Console.println(MessageFormat.format(Console.message("Found-tele"), var14));
               }
            } else {
               Object[] var15 = new Object[]{new String(this.teleportTarget), new String(var11)};
               String var16 = MessageFormat.format(Console.message("Cant-go-world"), var15);
               Console.println(var16);
            }

            this.teleportState = 0;
            this.teleportTarget = null;
         }
      } else if (var3.startsWith("&|+voicechat")) {
         this.chatter.handleChatWhisper(var2, var3, this.console);
      } else if (var3.startsWith(VoiceChat.VCdebugCommand)) {
         VoiceChat.setExtra(var3);
      } else if (var3.startsWith(VoiceChat.VCdebugCommandReset)) {
         VoiceChat.resetExtra();
      }
   }

   public int getNameListCount() {
      return this.friends.size();
   }

   public String getNameListName(int var1) {
      return (String)this.friends.elementAt(var1);
   }

   public void removeNameListName(int var1) {
      synchronized (this.friendsMutex) {
         String var3 = (String)this.friends.elementAt(var1);
         this.friends.removeElementAt(var1);
         this.saveFriends();
         if ((var1 = iindexOf(this.onlineFriends, var3)) != -1) {
            this.onlineFriends.removeElementAt(var1);
            if (active == this) {
               this.repaint();
            }
         }

         if ((var1 = iindexOf(this.mutedOnlineFriends, var3)) != -1) {
            this.mutedOnlineFriends.removeElementAt(var1);
         }

         this.serverUpdates.addElement(new BuddyListUpdateCmd(var3, 0));
      }
   }

   public boolean mayAddNameListName(java.awt.Window var1) {
      if (this.friends.size() < maxFriends) {
         return true;
      }

      Object[] var2 = new Object[]{new String("" + maxFriends)};
      new OkCancelDialog(
         var1, null, Console.message("Too-many-names"), null, Console.message("OK"), MessageFormat.format(Console.message("You-are-limitedF"), var2), true
      );
      return false;
   }

   public int addNameListName(String var1) {
      synchronized (this.friendsMutex) {
         int var3 = iindexOf(this.friends, var1);
         if (var3 != -1) {
            return var3;
         }

         this.friends.addElement(var1);
         this.saveFriends();
         this.serverUpdates.addElement(new BuddyListUpdateCmd(var1, 1));
         return this.friends.size() - 1;
      }
   }

   public static void droneClick(Drone var0, MouseDownEvent var1) {
      if (active != null) {
         active.instanceDroneClick(var0, var1);
      }
   }

   private void instanceDroneClick(Drone var1, MouseDownEvent var2) {
      String var3 = var1.getLongID();
      if (var3 != null) {
         this.activeFriendName = var3;
         Object[] var4 = new Object[]{new String(this.activeFriendName)};
         this.droneAddItem = new MenuItem(MessageFormat.format(Console.message("Add-to-friends"), var4));
         this.droneMenu.remove(0);
         this.droneAddItem.setFont(font);
         this.droneMenu.insert(this.droneAddItem, 0);
         this.droneAddItem.setEnabled(!icontains(this.friends, this.activeFriendName));
         if (this.actionMenu != null) {
            this.droneMenu.remove(this.actionMenu);
         }

         if (var1 instanceof PosableDrone) {
            PosableDrone var5 = (PosableDrone)var1;
            PosableShape var6 = var5.getInternalPosableShape();
            if (var6 != null) {
               this.actionMenu = new Menu(Console.message("Actions"));
               if (AnimatedActionManager.get().buildActionMenu(this.actionMenu, var6)) {
                  this.droneMenu.add(this.actionMenu);
                  this.actionMenu.addActionListener(AnimatedActionManager.get());
               }
            }
         }

         this.droneMenu.show(this.console.getRender(), var2.x, var2.y);
      }
   }

   public static void processBuddyListNotify(WorldServer var0, String var1, int var2) {
      Galaxy var3 = var0.getGalaxy();
      Enumeration var4 = var3.getConsoles();

      while (var4.hasMoreElements()) {
         Object var5 = var4.nextElement();
         if (var5 instanceof DefaultConsole) {
            FriendsListPart var6 = ((DefaultConsole)var5).getFriends();
            if (var2 < 2) {
               boolean var7 = MuteListPart.isMuted(var0, var1);
               if (var2 == 1) {
                  var6.addOnlineFriend(var1, var7);
               } else {
                  var6.removeOnlineFriend(var1, var7);
               }
            } else {
               Debug.dAssert(var1.length() == 0);
               var6.clearAll();
            }
         }
      }

      if (var2 == 2) {
         var4 = var3.getConsoles();

         while (var4.hasMoreElements()) {
            Object var9 = var4.nextElement();
            if (var9 instanceof DefaultConsole) {
               FriendsListPart var10 = ((DefaultConsole)var9).getFriends();
               var10.sendAll(var0);
               break;
            }
         }
      }
   }

   public static String ilookup(Vector var0, String var1) {
      int var2 = var0.size();

      for (int var3 = 0; var3 < var2; var3++) {
         String var4 = (String)var0.elementAt(var3);
         if (var4.equalsIgnoreCase(var1)) {
            return var4;
         }
      }

      return null;
   }

   public static int iindexOf(Vector var0, String var1) {
      int var2 = var0.size();

      for (int var3 = 0; var3 < var2; var3++) {
         String var4 = (String)var0.elementAt(var3);
         if (var4.equalsIgnoreCase(var1)) {
            return var3;
         }
      }

      return -1;
   }

   public static boolean icontains(Vector var0, String var1) {
      return iindexOf(var0, var1) != -1;
   }

   public void changeMuteState(String var1, boolean var2) {
      synchronized (this.friendsMutex) {
         if (icontains(this.friends, var1)) {
            if (var2) {
               var1 = ilookup(this.onlineFriends, var1);
               if (var1 != null) {
                  this.removeOnlineFriend(var1, false);
                  this.addOnlineFriend(var1, true);
               }
            } else {
               var1 = ilookup(this.mutedOnlineFriends, var1);
               if (var1 != null) {
                  this.removeOnlineFriend(var1, true);
                  this.addOnlineFriend(var1, false);
               }
            }
         }
      }
   }

   private void listChanged() {
      this.cursedButton = -1;
      this.clickedButton = -1;
      this.clickedButtonDown = false;
      this.repaint();
   }

   private void addOnlineFriend(String var1, boolean var2) {
      synchronized (this.friendsMutex) {
         if (this.friends != null && icontains(this.friends, var1)) {
            if (!var2 && !icontains(this.onlineFriends, var1)) {
               this.onlineFriends.addElement(var1);
               if (active == this) {
                  this.listChanged();
                  if (this.moreFriendsDialog != null) {
                     this.moreFriendsDialog.addName(var1);
                  }
               }
            } else if (var2 && !icontains(this.mutedOnlineFriends, var1)) {
               this.mutedOnlineFriends.addElement(var1);
            }
         }
      }
   }

   private void removeOnlineFriend(String var1, boolean var2) {
      synchronized (this.friendsMutex) {
         if (!var2) {
            int var4 = this.onlineFriends.indexOf(var1);
            if (var4 != -1) {
               this.onlineFriends.removeElementAt(var4);
               if (active == this) {
                  this.listChanged();
                  if (this.moreFriendsDialog != null) {
                     this.moreFriendsDialog.removeName(var4);
                  }
               }
            }
         } else {
            this.mutedOnlineFriends.removeElement(var1);
         }
      }
   }

   public void dialogDone(Object var1, boolean var2) {
      synchronized (this.friendsMutex) {
         if (var1 == this.moreFriendsDialog) {
            this.moreFriendsDialog = null;
         }
      }
   }

   public static boolean isValidUserName(String var0) {
      String var1 = "_-";
      var0 = Console.parseUnicode(var0);
      int var2 = var0.length();
      if (var2 >= 2 && var2 <= 16) {
         char[] var3 = var0.toCharArray();

         for (int var4 = 0; var4 < var2; var4++) {
            if (!Character.isLetterOrDigit(var3[var4]) && var1.indexOf(var3[var4]) == -1) {
               return false;
            }
         }

         return true;
      } else {
         return false;
      }
   }

   void moreFriendsAction(String var1, MenuItem var2) {
      this.activeFriendName = var1;
      Debug.assert_(this.activeFriendName != null);
      this.maybeFriendAction(var2);
   }
}

package NET.worlds.console;

import NET.worlds.core.ArchiveMaker;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.Galaxy;
import NET.worlds.network.NetUpdate;
import NET.worlds.network.RemoteFileConst;
import NET.worlds.network.URL;
import NET.worlds.network.WorldServer;
import NET.worlds.scape.BooleanPropertyEditor;
import NET.worlds.scape.CDAudio;
import NET.worlds.scape.CDControl;
import NET.worlds.scape.CDPlayerAction;
import NET.worlds.scape.EquipAction;
import NET.worlds.scape.FrameEvent;
import NET.worlds.scape.MusicManager;
import NET.worlds.scape.NoSuchPropertyException;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.PosableShape;
import NET.worlds.scape.Property;
import NET.worlds.scape.RenderWare;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SelectAvatarAction;
import NET.worlds.scape.SendURLAction;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.TooNewException;
import NET.worlds.scape.URLPropertyEditor;
import NET.worlds.scape.VehicleShape;
import NET.worlds.scape.World;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.CheckboxMenuItem;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Menu;
import java.awt.MenuItem;
import java.awt.Panel;
import java.awt.Point;
import java.awt.PopupMenu;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;
import java.text.Collator;
import java.text.DateFormat;
import java.text.MessageFormat;
import java.util.Date;
import java.util.Locale;
import java.util.MissingResourceException;
import java.util.NoSuchElementException;
import java.util.ResourceBundle;
import java.util.StringTokenizer;
import java.util.Vector;

public class DefaultConsole extends Console implements DialogReceiver, ImageButtonsCallback, RemoteFileConst {
   MenuItem aboutItem;
   MenuItem statisticsItem;
   MenuItem upgradeItem;
   MenuItem channelItem;
   MenuItem infoItem;
   MenuItem sleepItem;
   MenuItem helpItem;
   MenuItem gettingStartedItem;
   MenuItem serverItem;
   MenuItem numVisItem;
   MenuItem checkAccountItem;
   MenuItem becomeVIPItem;
   MenuItem toggleVoiceChatItem;
   MenuItem shaperHelpItem;
   MenuItem inventoryItem;
   MenuItem proxyServerItem;
   MenuItem musicManItem;
   MenuItem condenseItem;
   MenuItem expandItem;
   MenuItem i18nTest;
   MenuItem currentLang;
   Menu switchLang;
   Vector downItems = null;
   Vector langItems = null;
   Vector fontItems = null;
   static final String LANGUAGES = "languages.lst";
   static final String FONTS = "fonts.lst";
   Vector viewItems = null;
   Vector camSpeedItems = null;
   CheckboxMenuItem currentViewItem;
   CheckboxMenuItem currentCamSpeedItem;
   ImageButtons driveButton;
   ImageButtons quitButton;
   ImageButtons exploreButton;
   ImageButtons menuButtons;
   String defaultAd = IniFile.override().getIniString("defaultAd", "home:adworlds.cmp");
   AdPart ad = new AdPart(URL.make(this.defaultAd));
   ChatPart chat = new ChatPart();
   RenderCanvas render = new RenderCanvas(this, new Dimension(560, 360));
   Panel renderAndUniverse;
   UniversePanel universe;
   CardLayout renderCard;
   InventoryPart inventory = new InventoryPart();
   WorldsMarkPart marks = new WorldsMarkPart();
   FriendsListPart friends = new FriendsListPart();
   ActionsPart actions = new ActionsPart();
   MuteListPart mutes = new MuteListPart();
   MapPart map = new MapPart();
   SavedAvPart savedAvs = new SavedAvPart();
   private static Font font = new Font(Console.message("ConsoleFont"), 0, 12);
   private static Font mfont = new Font(Console.message("MenuFont"), 0, 12);
   CDControl cdcontrol;
   boolean playedCD;
   MenuItem cdPlayerItem;
   MenuItem volumeItem;
   MenuItem graphicsItem;
   MenuItem nametagItem;
   MenuItem chatBoxItem;
   MenuItem broadcastToRoom;
   MenuItem broadcastToAll;
   MenuItem bootSomeone;
   CheckboxMenuItem orthographicViewItem;
   MenuItem recorderPlayItem;
   MenuItem recorderRecItem;
   MenuItem recorderStopItem;
   boolean universeMode;
   private static final int[] menuButtonHeights = new int[]{23, 21, 21, 21, 21, 21, 25, -29};
   private Vector viewNames;
   private Vector speedNames;
   private static final int HELP = 0;
   private static final int OPTIONS = 1;
   private static final int WORLDSMAIL = 2;
   private static final int WORLDSMARK = 3;
   private static final int LETS = 4;
   private static final int ACTIONS = 5;
   private static final int VIP = 6;
   static String loadingString = Console.message("Loading");
   static String arrowKeyMsg = Console.message("Use-arrow-keys");
   String statusMessage = arrowKeyMsg;
   String overrideMessage;
   String lastStatus = "";
   int lastUpdateTime = 0;
   boolean wasTeleporting = false;
   private int lastVMCheck;
   private int lastVMBigWarning;
   Component bottom;
   Component top;
   Label status = new UnpaddedLabel("", 2);
   Label yourName = new UnpaddedLabel("", 0);
   static String[] lNames = lpList();
   static int lLength = lNames.length;
   static MenuItem[] lLangs = new MenuItem[lLength];
   static Locale[] newLocale = new Locale[lLength];
   static String[][] lCodes = new String[lLength][2];
   Vector lList = new Vector();
   Vector sList = new Vector();
   int[] lSizes = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   int dLength = this.dpList(this.lList, this.sList, this.lSizes);
   MenuItem[] dLangs = this.dLength == 0 ? null : new MenuItem[this.dLength];
   Locale[] newdLocale = this.dLength == 0 ? null : new Locale[this.dLength];
   Vector flList = new Vector();
   Vector fsList = new Vector();
   int[] fSizes = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   int fLength = this.fpList(this.flList, this.fsList, this.fSizes);
   MenuItem[] dFonts = this.fLength == 0 ? null : new MenuItem[this.fLength];
   Locale[] newfLocale = this.fLength == 0 ? null : new Locale[this.fLength];
   static boolean wasDelta;
   static boolean doDrive;
   Panel mapPanel;
   private static String signIn = Console.message("Sign-In");
   private static String signOut = Console.message("Sign-Out");
   private static String signingIn = Console.message("Signing-In");
   private static String noMultiUser = Console.message("Network");
   private static String enable3D = Console.message("Enable3D");
   private static String disable3D = Console.message("Disable3D");
   private static String showTags = Console.message("ShowNametags");
   private static String hideTags = Console.message("HideNametags");
   private static String enableClassicChat = Console.message("EnableClassicChat");
   private static String disableClassicChat = Console.message("DisableClassicChat");
   Menu chatLogMenu;
   AvMenu avatarMenu;
   private int chooseView = -1;
   private int chooseCamSpeed = -1;
   private static String sleepStatus = Console.message("Sleeping");
   OkCancelDialog reloginDialog;
   private Object nextAvatarMutex = new Object();
   private URL nextAvatar;
   private CheckboxMenuItem nextAvatarItem;
   private CheckboxMenuItem curAvatarItem;
   private static String lastWorldName = "";
   private static String lowVMMsg = Console.message("Low-virt");
   private boolean showedMidWarn;
   private static boolean startupMemCheck = true;
   public static int physMem;
   protected URL avatarURL;
   private static Object classCookie = new Object();

   public UniversePanel getUniversePanel() {
      return this.universe;
   }

   public void printLine(String var1) {
      this.chat.println(var1);
      super.printLine(var1);
   }

   protected void printWhisperFrom(String var1, String var2) {
      WhisperManager.whisperManager().printFrom(var1, var2);
   }

   protected void printWhisperTo(String var1, String var2) {
      WhisperManager.whisperManager().printTo(var1, var2);
   }

   protected void startWhisperingTo(String var1) {
      WhisperManager.whisperManager().startTo(var1);
   }

   public DefaultConsole() {
      this.init();
      this.loadViewNames();
      this.speedNames = new Vector();
      this.speedNames.addElement(new DefaultConsole.CameraSpeed("Slow", 1));
      this.speedNames.addElement(new DefaultConsole.CameraSpeed("Medium", 2));
      this.speedNames.addElement(new DefaultConsole.CameraSpeed("Fast", 3));
   }

   public void loadViewNames() {
      this.viewNames = new Vector();
      this.viewNames.addElement(new DefaultConsole.CameraView("First-person", 1));
      this.viewNames.addElement(new DefaultConsole.CameraView("Low-first-person", 2));
      this.viewNames.addElement(new DefaultConsole.CameraView("Waist", 3));
      this.viewNames.addElement(new DefaultConsole.CameraView("Shoulder", 4));
      this.viewNames.addElement(new DefaultConsole.CameraView("Head", 5));
      this.viewNames.addElement(new DefaultConsole.CameraView("Overhead", 6));
      this.viewNames.addElement(new DefaultConsole.CameraView("Behind", 7));
      this.viewNames.addElement(new DefaultConsole.CameraView("Wide-shot", 8));
      if (Gamma.getShaper() != null) {
         this.viewNames.addElement(new DefaultConsole.CameraView("Orthographic", 9));
      }
   }

   public void setOrthoEnabled(boolean var1) {
      if (this.orthographicViewItem != null) {
         this.orthographicViewItem.setEnabled(var1);
      }
   }

   public void loadInit() {
      super.loadInit();
   }

   public void removeUseArrowStatusMsg() {
      if (this.statusMessage == arrowKeyMsg) {
         this.statusMessage = "";
      }
   }

   public void overrideStatusMsg(String var1) {
      synchronized (this.status) {
         this.overrideMessage = var1;
         if (var1 != null) {
            this.status.setText(var1);
         } else {
            this.status.setText(this.lastStatus);
         }
      }
   }

   public String message(String var1, Locale var2) {
      Locale.setDefault(var2);
      Console.println(var2.getDisplayName());

      try {
         ResourceBundle var3 = ResourceBundle.getBundle("MessagesBundle", var2);
         return var3.getString(var1);
      } catch (MissingResourceException var4) {
         return "NO MESSAGE for " + var1;
      }
   }

   private void init() {
      this.addPart(this.render);
      this.addPart(this.chat);
      this.addPart(this.inventory);
      this.addPart(this.marks);
      this.addPart(this.friends);
      this.addPart(this.actions);
      this.addPart(this.mutes);
      this.addPart(this.ad);
      this.addPart(this.map);
      this.addPart(this.savedAvs);
      Panel var1 = new Panel(new FlowLayout(1, 0, 0));
      String var2 = IniFile.override().getIniString("driveGif", "drive.gif");
      this.addPart(this.driveButton = new ImageButtons(var2, 81, 19, this));
      String var3 = IniFile.override().getIniString("quitGif", Console.message("quit.gif"));
      this.addPart(this.quitButton = new ImageButtons(var3, 65, 19, this));
      String var4 = IniFile.override().getIniString("exploreGif", Console.message("explore.gif"));
      this.addPart(this.exploreButton = new ImageButtons(var4, 98, 22, this));
      var1.add(this.driveButton);
      this.driveButton.setDownUpHandler(new DefaultConsole$1(this));
      Panel var5 = new Panel();
      var5.setLayout(new GridLayout(1, 3));
      int var6 = IniFile.override().getIniInt("uiBackgroundRed", 49);
      int var7 = IniFile.override().getIniInt("uiBackgroundGreen", 0);
      int var8 = IniFile.override().getIniInt("uiBackgroundBlue", 255);
      var5.setBackground(new Color(var6, var7, var8));
      var5.add(this.yourName);
      var5.add(var1);
      var5.add(this.status);
      this.chat.line.setBackground(Color.black);
      this.chat.line.setForeground(Color.white);
      this.chat.line.setFont(font);
      InsetPanel var9 = new InsetPanel(new BorderLayout(0, 3), 0, 0, 3, 0);
      var9.add("North", var5);
      var9.add("Center", this.chat.listen.getComponent());
      var9.add("South", this.chat.line);
      this.chat.listen.setBackground(Color.black);
      this.chat.listen.setForeground(Color.white);
      this.chat.listen.setFont(font);
      Panel var10 = new Panel(new BorderLayout());
      new Panel(new BorderLayout());
      Panel var12 = new Panel(new BorderLayout());
      Panel var13 = new Panel(new BorderLayout());
      ColorFiller var14 = new ColorFiller(65, 19);
      var14.setBackground(new Color(var6, var7, var8));
      var12.add("West", this.quitButton);
      var12.add("East", var14);
      var13.add("North", var12);
      var13.add("Center", this.ad);
      var10.add("West", var13);
      this.mapPanel = new Panel(new BorderLayout());
      this.mapPanel.add("Center", this.map);
      this.mapPanel.setBackground(Color.black);
      var12 = new Panel(new BorderLayout());
      ColorFiller var15 = new ColorFiller(60, 19);
      var15.setBackground(new Color(var6, var7, var8));
      var12.add("North", var15);
      ColorFiller var16 = new ColorFiller(60, 3);
      int var17 = IniFile.override().getIniInt("uiBackground2Red", 0);
      int var18 = IniFile.override().getIniInt("uiBackground2Green", 0);
      int var19 = IniFile.override().getIniInt("uiBackground2Blue", 0);
      var16.setBackground(new Color(var17, var18, var19));
      var12.add("South", var16);
      Panel var11 = new Panel(new BorderLayout());
      var11.add("East", this.exploreButton);
      var11.add("West", var12);
      this.mapPanel.add("North", var11);
      var10.add("East", this.mapPanel);
      var10.add("Center", var9);
      this.bottom = var10;
      this.renderCard = new CardLayout();
      this.renderAndUniverse = new Panel(this.renderCard);
      this.renderAndUniverse.add("render", this.render);
      var10 = new InsetPanel(new BorderLayout(), 3, 3, 0, 0);
      var10.add("Center", this.renderAndUniverse);
      int var21 = IniFile.override().getIniInt("uiBackground3Red", 0);
      int var23 = IniFile.override().getIniInt("uiBackground3Green", 0);
      int var24 = IniFile.override().getIniInt("uiBackground3Blue", 0);
      var14 = new ColorFiller(97, 1);
      var14.setBackground(new Color(var21, var23, var24));
      Panel var26 = new Panel(new QuantizedStackedLayout(var14));
      String var27 = IniFile.override().getIniString("rtPanel", Console.message("rtpanel.gif"));
      this.addPart(this.menuButtons = new ImageButtons(var27, 97, menuButtonHeights, this));
      var26.add(var14);
      var26.add(this.menuButtons);
      var26.add(this.friends);
      var10.add("East", var26);
      this.top = var10;
   }

   public void relayoutMap() {
      this.mapPanel.invalidate();
      this.mapPanel.validate();
      this.mapPanel.doLayout();
      this.mapPanel.repaint();
   }

   public void startDrive() {
      this.statusMessage = Console.message("Drag-mouse");
      doDrive = true;
      Window.makeJavaReleaseCapture();
   }

   public void setOnlineState(boolean var1, boolean var2) {
      synchronized (this) {
         if (this.serverItem != null) {
            this.serverItem.setEnabled(var1);
            if (!var1) {
               Galaxy var4 = this.getGalaxy();
               if (var4 != null && !var4.isAnonymous()) {
                  this.serverItem.setLabel(signingIn);
               } else {
                  this.serverItem.setLabel(noMultiUser);
               }
            } else if (var2) {
               this.serverItem.setLabel(signOut);
            } else {
               this.serverItem.setLabel(signIn);
            }
         }
      }
   }

   private void handleNametagsItem() {
      if (IniFile.gamma().getIniInt("SHOWNAMETAGS", 1) == 0) {
         IniFile.gamma().setIniInt("SHOWNAMETAGS", 1);
         this.nametagItem.setLabel(hideTags);
      } else {
         IniFile.gamma().setIniInt("SHOWNAMETAGS", 0);
         this.nametagItem.setLabel(showTags);
      }

      new OkCancelDialog(getFrame(), null, Console.message("Alert"), null, Console.message("OK"), Console.message("Change-exit"), true);
   }

   private void handleGraphicsItem() {
      if (IniFile.gamma().getIniInt("UserEnabled3DHardware", 0) == 0) {
         IniFile.gamma().setIniInt("UserEnabled3DHardware", 1);
         this.graphicsItem.setLabel(disable3D);
      } else {
         IniFile.gamma().setIniInt("UserEnabled3DHardware", 0);
         this.graphicsItem.setLabel(enable3D);
      }

      new OkCancelDialog(getFrame(), null, Console.message("Alert"), null, Console.message("OK"), Console.message("Change-exit"), true);
   }

   private void handleChatBoxItem() {
      if (IniFile.gamma().getIniInt("classicChatBox", 1) == 0) {
         IniFile.gamma().setIniInt("classicChatBox", 1);
         this.chatBoxItem.setLabel(disableClassicChat);
      } else {
         IniFile.gamma().setIniInt("classicChatBox", 0);
         this.chatBoxItem.setLabel(enableClassicChat);
      }

      new OkCancelDialog(getFrame(), null, Console.message("Alert"), null, Console.message("OK"), Console.message("Change-exit"), true);
   }

   public AvMenu getAvatarMenu() {
      return this.avatarMenu;
   }

   public void inventoryChanged() {
      super.inventoryChanged();
      if (this.avatarMenu != null) {
         this.avatarMenu.buildSpecialGuestMenu();
      }
   }

   public void setMenusWRTVIP() {
      if (this.avatarMenu != null) {
         this.avatarMenu.setEnabled(this.getVIP());
         this.avatarMenu.customize.setEnabled(this.getVIP());
      }

      if (this.savedAvs != null) {
         this.savedAvs.setEnabled(this.getVIP());
      }

      if (this.chatLogMenu != null) {
         this.chatLogMenu.setEnabled(this.getVIP());
      }

      if (this.toggleVoiceChatItem != null) {
         this.toggleVoiceChatItem.setLabel(this.getVIP() && VoiceChat.voiceChatEnabled ? Console.message("Reject-Voice") : Console.message("Accept-Voice"));
         this.toggleVoiceChatItem.setEnabled(this.getVIP() && VoiceChat.voiceChatAvailable());
      }

      if (this.becomeVIPItem != null) {
         this.becomeVIPItem.setLabel(vip > 0 ? (vip > 1 ? Console.message("Youre-a-VIP") : Console.message("Become-full-VIP")) : Console.message("Become-VIP"));
      }

      if (this.numVisItem != null) {
         this.numVisItem.setEnabled(this.getVIP());
      }
   }

   public void addBroadcastMenu() {
      if (this.bootSomeone == null) {
         if (IniFile.gamma().getIniInt("Broadcast", 0) != 0) {
            Menu var1 = new Menu(Console.message("Broadcast"));
            var1.add(this.broadcastToRoom = new MenuItem(Console.message("Users")));
            var1.add(this.broadcastToAll = new MenuItem(Console.message("All-users")));
            this.addMenuItem(var1, "Options");
         }

         this.bootSomeone = new MenuItem(Console.message("Boot-user"));
         this.addMenuItem(this.bootSomeone, "Options");
      }
   }

   private Menu updateChatLogMenu() {
      if (this.chatLogMenu == null) {
         this.chatLogMenu = new Menu(Console.message("View-Chat"));
      } else {
         this.chatLogMenu.removeAll();
      }

      DefaultConsole$2 var1 = new DefaultConsole$2(this);
      String[] var2 = this.logList();
      MenuItem var3 = null;

      for (int var4 = 0; var4 < var2.length; var4++) {
         int var5 = var2[var4].indexOf(".glog.html");
         if (var5 > 6) {
            Object[] var6 = new Object[]{new String(var2[var4].substring(5, var5))};
            var3 = new MenuItem(MessageFormat.format(Console.message("Chat-with"), var6));
         } else {
            if (var5 <= 0) {
               continue;
            }

            var3 = new MenuItem(Console.message("General-chat"));
         }

         var3.setActionCommand(var2[var4]);
         var3.addActionListener(var1);
         this.chatLogMenu.add(var3);
      }

      return this.chatLogMenu;
   }

   private String[] logList() {
      File var1 = new File(".");
      DefaultConsole$3 var2 = new DefaultConsole$3(this);
      return var1.list(var2);
   }

   private static String[] lpList() {
      File var0 = new File(".");
      DefaultConsole$4 var1 = new DefaultConsole$4();
      String[] var2 = var0.list(var1);
      Collator var3 = Collator.getInstance();
      sortStrings(var3, var2);
      return var2;
   }

   private int dpList(Vector var1, Vector var2, int[] var3) {
      String var4 = NetUpdate.getLanguages(URL.make(NetUpdate.getUpgradeServerURL() + "I18N/" + "languages.lst"), var1, var2, var3);
      if (var4 != null) {
         System.out.println(var4);
         return 0;
      } else {
         return var1.size();
      }
   }

   private int fpList(Vector var1, Vector var2, int[] var3) {
      String var4 = NetUpdate.getLanguages(URL.make(NetUpdate.getUpgradeServerURL() + "I18N/" + "fonts.lst"), var1, var2, var3);
      if (var4 != null) {
         System.out.println(var4);
         return 0;
      } else {
         return var1.size();
      }
   }

   public static void sortStrings(Collator var0, String[] var1, Locale[] var2, String[][] var3) {
      for (int var8 = 0; var8 < var1.length; var8++) {
         for (int var9 = var8 + 1; var9 < var1.length; var9++) {
            if (var0.compare(var1[var8], var1[var9]) > 0) {
               String var4 = var1[var8];
               Locale var5 = var2[var8];
               String var6 = var3[var8][0];
               String var7 = var3[var8][1];
               var1[var8] = var1[var9];
               var2[var8] = var2[var9];
               var3[var8][0] = var3[var9][0];
               var3[var8][1] = var3[var9][1];
               var1[var9] = var4;
               var2[var9] = var5;
               var3[var9][0] = var6;
               var3[var9][1] = var7;
            }
         }
      }
   }

   public static void sortStrings(Collator var0, String[] var1, Locale[] var2, Vector var3, Vector var4) {
      for (int var9 = 0; var9 < var1.length; var9++) {
         for (int var10 = var9 + 1; var10 < var1.length; var10++) {
            if (var0.compare(var1[var9], var1[var10]) > 0) {
               String var5 = var1[var9];
               Locale var6 = var2[var9];
               String var7 = (String)var3.elementAt(var9);
               String var8 = (String)var4.elementAt(var9);
               var1[var9] = var1[var10];
               var2[var9] = var2[var10];
               var3.setElementAt(var3.elementAt(var10), var9);
               var4.setElementAt(var4.elementAt(var10), var9);
               var1[var10] = var5;
               var2[var10] = var6;
               var3.setElementAt(var7, var10);
               var4.setElementAt(var8, var10);
            }
         }
      }
   }

   public static void sortStrings(Collator var0, String[] var1) {
      for (int var3 = 0; var3 < var1.length; var3++) {
         for (int var4 = var3 + 1; var4 < var1.length; var4++) {
            if (var0.compare(var1[var3], var1[var4]) > 0) {
               String var2 = var1[var3];
               var1[var3] = var1[var4];
               var1[var4] = var2;
            }
         }
      }
   }

   public void activate(Container var1) {
      super.activate(var1);
      var1.setBackground(Color.black);
      var1.setForeground(Color.white);
      var1.setLayout(new BorderLayout());
      var1.add("Center", this.top);
      var1.add("South", this.bottom);
      this.chat.line.setBackground(Color.white);
      this.chat.line.setForeground(Color.black);
      boolean var2 = Gamma.getShaper() != null;
      if (var2) {
         this.shaperHelpItem = this.addMenuItem(Console.message("using-shaper"), "Help");
      }

      if (NetUpdate.getInfoURL() != null) {
         this.helpItem = this.addMenuItem(Console.message("Help-Contents"), "Help");
         this.infoItem = this.addMenuItem(Console.message("Latest-info"), "Help");
      }

      Object[] var3 = new Object[]{new String(Std.getProductName())};
      this.aboutItem = this.addMenuItem(MessageFormat.format(Console.message("About-product"), var3), "Help");
      int var4 = IniFile.gamma().getIniInt("CAM_MODE", 7);
      int var5 = IniFile.gamma().getIniInt("CAM_SPEED", 3);
      if (!var2 && var4 == 9) {
         var4 = 7;
      }

      this.pilot.setOutsideCameraMode(var4, var5);
      Menu var6 = new Menu(Console.message("Change-View"));
      this.addMenuItem(var6, "Options");
      MenuItem var7 = new MenuItem(Console.message("CAMERA-VIEW"));
      var7.setFont(mfont);
      var6.add(var7);
      this.viewItems = new Vector();

      for (int var8 = 0; var8 < this.viewNames.size(); var8++) {
         DefaultConsole.CameraView var9 = (DefaultConsole.CameraView)this.viewNames.elementAt(var8);
         CheckboxMenuItem var10 = new CheckboxMenuItem("   " + Console.message(var9.viewName), var4 == var9.viewID);
         if (var4 == var9.viewID) {
            this.currentViewItem = var10;
         }

         var10.setFont(mfont);
         var6.add(var10);
         this.viewItems.addElement(var10);
         if (var9.viewName == "Orthographic") {
            this.orthographicViewItem = var10;
         }
      }

      var6.addSeparator();
      MenuItem var25 = new MenuItem(Console.message("CAMERA-SPEED"));
      var25.setFont(mfont);
      var6.add(var25);
      this.camSpeedItems = new Vector();

      for (int var26 = 0; var26 < this.speedNames.size(); var26++) {
         DefaultConsole.CameraSpeed var29 = (DefaultConsole.CameraSpeed)this.speedNames.elementAt(var26);
         CheckboxMenuItem var11 = new CheckboxMenuItem("   " + Console.message(var29.speedName), var29.speedID == var5);
         if (var29.speedID == var5) {
            this.currentCamSpeedItem = var11;
         }

         var11.setFont(mfont);
         var6.add(var11);
         this.camSpeedItems.addElement(var11);
      }

      this.becomeVIPItem = this.addMenuItem(vip == 1 ? Console.message("Become-full-VIP") : Console.message("Become-VIP"), "VIP");
      this.addMenuItem(this.avatarMenu = new AvMenu(this, this.lastPilotRequested), "VIP");
      this.addMenuItem(this.savedAvs, "VIP");
      this.addMenuItem(this.avatarMenu.customize, "VIP");
      this.toggleVoiceChatItem = this.addMenuItem(Console.message("Enable-Voice"), "VIP");
      this.toggleVoiceChatItem.setEnabled(false);
      this.numVisItem = this.addMenuItem(Console.message("Num-Visible"), "VIP");
      if (NetUpdate.isInternalVersion()) {
         this.inventoryItem = this.addMenuItem("Check Inventory", "VIP");
      }

      this.setMenusWRTVIP();
      this.proxyServerItem = this.addMenuItem(Console.message("Proxy-Server"), "Options");
      this.checkAccountItem = this.addMenuItem(Console.message("Account-Info"), "Options");
      if (var2) {
         this.statisticsItem = this.addMenuItem(Console.message("Display-Stat"), "Options");
      }

      this.upgradeItem = this.addMenuItem(Console.message("Upgrade-Now"), "Options");
      if (var2) {
         this.channelItem = this.addMenuItem(Console.message("Dimension-Sel"), "Options");
      }

      this.serverItem = this.addMenuItem(signIn, "Options");
      this.setOnlineState(this.galaxy.getOnlineEnabled(), this.galaxy.getOnline());
      if (IniFile.gamma().getIniInt("recorderEnabled", 1) == 1) {
         Menu var27 = new Menu(Console.message("Recorder"));
         this.addMenuItem(var27, "Options");
         this.recorderRecItem = new MenuItem(Console.message("Record"));
         var27.add(this.recorderRecItem);
         this.recorderStopItem = new MenuItem(Console.message("Stop"));
         var27.add(this.recorderStopItem);
         this.recorderPlayItem = new MenuItem(Console.message("Play"));
         var27.add(this.recorderPlayItem);
      }

      if (NetUpdate.isInternalVersion()) {
         Menu var28 = new Menu(Console.message("Languages"));
         this.addMenuItem(var28, "Options");
         Menu var30 = new Menu(Console.message("Download-Font"));
         var28.add(var30);
         var30.setFont(mfont);
         this.fontItems = new Vector();

         for (int var31 = 0; var31 < this.fLength; var31++) {
            if (this.flList.elementAt(var31) != null) {
               if (this.fsList.elementAt(var31) != null) {
                  this.newfLocale[var31] = new Locale((String)this.flList.elementAt(var31), (String)this.fsList.elementAt(var31));
                  String var12 = (String)this.flList.elementAt(var31) + "_" + (String)this.fsList.elementAt(var31);
                  if (var12.equals(Console.message(var12))) {
                     this.dFonts[var31] = new MenuItem(this.newfLocale[var31].getDisplayName());
                  } else {
                     this.dFonts[var31] = new MenuItem(Console.message(var12));
                  }
               } else {
                  String var33 = (String)this.flList.elementAt(var31);
                  if (var33.equals(Console.message(var33))) {
                     this.dFonts[var31] = new MenuItem((String)this.flList.elementAt(var31));
                  } else {
                     this.dFonts[var31] = new MenuItem(Console.message(var33));
                  }
               }

               this.dFonts[var31].setFont(mfont);
               var30.add(this.dFonts[var31]);
               this.fontItems.addElement(this.dFonts[var31]);
            }
         }

         Menu var32 = new Menu(Console.message("Download-Language"));
         var28.add(var32);
         var32.setFont(mfont);
         this.downItems = new Vector();
         String[] var34 = new String[this.dLength];

         for (int var13 = 0; var13 < this.dLength; var13++) {
            if (this.lList.elementAt(var13) != null) {
               this.newdLocale[var13] = new Locale((String)this.lList.elementAt(var13), (String)this.sList.elementAt(var13));
               String var15;
               if (var13 > 0) {
                  Locale var18 = new Locale((String)this.lList.elementAt(var13 - 1), (String)this.sList.elementAt(var13 - 1));
                  var15 = var18.getDisplayName();
               } else {
                  var15 = this.newdLocale[var13].getDisplayName();
               }

               String var16 = this.newdLocale[var13].getDisplayName();
               var16 = var16.substring(0, var16.indexOf(40) - 1);
               String var14;
               if (var13 < this.dLength - 1) {
                  Locale var20 = new Locale((String)this.lList.elementAt(var13 + 1), (String)this.sList.elementAt(var13 + 1));
                  String var17 = var20.getDisplayName();
                  var17 = var17.substring(0, var17.indexOf(40) - 1);
                  if (var17.equals(var16)) {
                     var14 = this.newdLocale[var13].getDisplayName();
                  } else {
                     var14 = var16;
                  }
               } else if (var13 == this.dLength - 1) {
                  var15 = var15.substring(0, var15.indexOf(40) - 1);
                  if (var16.equals(var15)) {
                     var14 = this.newdLocale[var13].getDisplayName();
                  } else {
                     var14 = var16;
                  }
               } else if (var34[var13 - 1].equals(var16)) {
                  var14 = this.newdLocale[var13].getDisplayName();
               } else {
                  var14 = var16;
               }

               String var21 = (String)this.lList.elementAt(var13) + "_" + (String)this.sList.elementAt(var13);
               if (var21.equals(Console.message(var21))) {
                  var34[var13] = var14;
               } else {
                  var34[var13] = Console.message(var21);
               }
            }
         }

         Collator var35 = Collator.getInstance();
         sortStrings(var35, var34, this.newdLocale, this.lList, this.sList);

         for (int var36 = 0; var36 < this.dLength; var36++) {
            this.dLangs[var36] = new MenuItem(var34[var36]);
            this.dLangs[var36].setFont(mfont);
            var32.add(this.dLangs[var36]);
            this.downItems.addElement(this.dLangs[var36]);
         }

         Menu var37 = new Menu(Console.message("Switch-Language"));
         var28.add(var37);
         var37.setFont(mfont);
         this.langItems = new Vector();

         for (int var39 = 0; var39 < lLength; var39++) {
            int var42 = lNames[var39].indexOf(95);
            if (var42 < 0) {
               lCodes[var39][0] = "en";
               lCodes[var39][1] = "US";
            } else {
               int var46 = lNames[var39].lastIndexOf(46);
               if (var46 < 0) {
                  var46 = 0;
               }

               lCodes[var39][0] = lNames[var39].substring(var42 + 1, var42 + 3);
               if (var46 > var42 + 4) {
                  lCodes[var39][1] = lNames[var39].substring(var42 + 4, var46);
               } else {
                  lCodes[var39][1] = lCodes[var39][0].toUpperCase();
               }
            }
         }

         String[] var40 = new String[lLength];

         for (int var43 = 0; var43 < lLength; var43++) {
            newLocale[var43] = new Locale(lCodes[var43][0], lCodes[var43][1]);
            String var48;
            if (var43 > 0) {
               Locale var53 = new Locale(lCodes[var43 - 1][0], lCodes[var43 - 1][1]);
               var48 = var53.getDisplayName();
            } else {
               var48 = newLocale[var43].getDisplayName();
            }

            String var19 = newLocale[var43].getDisplayName();
            var19 = var19.substring(0, var19.indexOf(40) - 1);
            String var47;
            if (var43 < lLength - 1) {
               Locale var23 = new Locale(lCodes[var43 + 1][0], lCodes[var43 + 1][1]);
               String var51 = var23.getDisplayName();
               var51 = var51.substring(0, var51.indexOf(40) - 1);
               if (var51.equals(var19)) {
                  var47 = newLocale[var43].getDisplayName();
               } else {
                  var47 = var19;
               }
            } else if (var43 == lLength - 1) {
               var48 = var48.substring(0, var48.indexOf(40) - 1);
               if (var19.equals(var48)) {
                  var47 = newLocale[var43].getDisplayName();
               } else {
                  var47 = var19;
               }
            } else if (var40[var43 - 1].equals(var19)) {
               var47 = newLocale[var43].getDisplayName();
            } else {
               var47 = var19;
            }

            String var24 = lCodes[var43][0] + "_" + lCodes[var43][1];
            if (var24.equals(Console.message(var24))) {
               var40[var43] = var47;
            } else {
               var40[var43] = Console.message(var24);
            }
         }

         sortStrings(var35, var40, newLocale, lCodes);

         for (int var44 = 0; var44 < lLength; var44++) {
            lLangs[var44] = new MenuItem(var40[var44]);
            lLangs[var44].setFont(mfont);
            var37.add(lLangs[var44]);
            this.langItems.addElement(lLangs[var44]);
         }

         this.currentLang = new MenuItem(Console.message("Current-Language"));
         var28.add(this.currentLang);
         this.currentLang.setFont(mfont);
      }

      if (var2) {
         this.condenseItem = this.addMenuItem(Console.message("Condense-Files"), "Options");
         this.expandItem = this.addMenuItem(Console.message("Expand-Files"), "Options");
         this.musicManItem = this.addMenuItem(Console.message("Music-Manager"), "Options");
         this.i18nTest = this.addMenuItem(Console.message("I18N-Test"), "Options");
      }

      this.cdPlayerItem = this.addMenuItem(Console.message("MusicM"), "Options");
      this.volumeItem = this.addMenuItem(Console.message("Volume-control"), "Options");
      if (RenderWare.get3DHardwareAvailable()) {
         if (RenderWare.get3DHardwareInUse()) {
            this.graphicsItem = this.addMenuItem(disable3D, "Options");
         } else {
            this.graphicsItem = this.addMenuItem(enable3D, "Options");
         }
      }

      if (IniFile.gamma().getIniInt("SHOWNAMETAGS", 1) == 1) {
         this.nametagItem = this.addMenuItem(hideTags, "Options");
      } else {
         this.nametagItem = this.addMenuItem(showTags, "Options");
      }

      if (IniFile.gamma().getIniInt("classicChatBox", 1) == 1) {
         this.chatBoxItem = this.addMenuItem(disableClassicChat, "Options");
      } else {
         this.chatBoxItem = this.addMenuItem(enableClassicChat, "Options");
      }

      if (Gamma.loadProgress != null) {
         Gamma.loadProgress.setMessage("Preloading avatars...");
         Gamma.loadProgress.advance();
      }

      this.menuDone();
      getFrame().activate();
      LogFile.mailLogIfPresent(this.getSmtpServer());
      this.render.requestFocus();
      this.setMenusWRTVIP();
      this.bootSomeone = null;
      if (this.broadcastEnabled()) {
         this.addBroadcastMenu();
      }

      this.universeMode = false;
   }

   public void setVIP(boolean var1) {
      super.setVIP(var1);
      this.setMenusWRTVIP();
      this.setNameStr();
   }

   public void checkCourtesyVIP() {
      super.checkCourtesyVIP();
      this.setMenusWRTVIP();
      this.setNameStr();
   }

   public void setNameStr() {
      String var1 = this.galaxy.getUsernameU();
      boolean var2 = this.galaxy.getOnline();
      if (!var2) {
         this.yourName.setText(Console.message("Off-line"));
      } else {
         if (var1.length() > 0) {
            if (var1.regionMatches(true, 0, "VIP ", 0, 4)) {
               var1 = var1.substring(4);
            }

            if (vip > 0) {
               if (vip > 1) {
                  var1 = Console.message("VIP") + " " + var1;
               } else {
                  var1 = Console.message("vip") + " " + var1;
               }
            }

            IniFile.gamma().setIniString("LASTCHATNAME", parseExtended(var1));
            this.yourName.setText(Console.parseUnicode(var1));
         }
      }
   }

   public void enableBroadcast(boolean var1) {
      super.enableBroadcast(var1);
      if (var1) {
         this.addBroadcastMenu();
      }
   }

   public void deactivate() {
      super.deactivate();
      this.universeMode = false;
   }

   protected void setSleepMode(String var1) {
      super.setSleepMode(var1);
      if (var1 != null && var1.equals(Console.message("asleep"))) {
         this.statusMessage = sleepStatus;
      } else if (this.statusMessage == sleepStatus) {
         this.statusMessage = "";
      }
   }

   private void relogin() {
      if (this.serverItem.getLabel().equals(signOut)) {
         this.reloginDialog = new OkCancelDialog(
            getFrame(), this, Console.message("Re-login"), Console.message("Cancel"), Console.message("OK"), Console.message("auto-sign-out"), true
         );
      }
   }

   public boolean action(Event var1, Object var2) {
      if (var1.target == this.aboutItem) {
         new AboutDialog(Std.getProductName(), getFrame());
      } else if (var1.target == this.statisticsItem && this.statisticsItem != null) {
         new StatisticsWindow(getFrame());
      } else if (this.viewItems.contains(var1.target)) {
         this.changeView((CheckboxMenuItem)var1.target);
      } else if (this.camSpeedItems.contains(var1.target)) {
         this.changeCamSpeed((CheckboxMenuItem)var1.target);
      } else if (var1.target == this.gettingStartedItem) {
         new SendURLAction(this.getHelpGettingStarted()).startBrowser();
      } else if (var1.target == this.shaperHelpItem) {
         String var28 = IniFile.override().getIniString("ShaperHelp", this.getScriptServer() + "shaperhelp.pl") + "?u=";
         String var36 = IniFile.gamma().getIniString("lastchatname", "");
         if (!var36.equals("")) {
            if (var36.startsWith("VIP ")) {
               var36 = var36.substring(4);
            }

            var28 = var28 + var36;
         }

         new SendURLAction(WebControlImp.processURL(var28)).startBrowser();
      } else if (var1.target == this.helpItem) {
         String var27 = NetUpdate.getUpgradeServerURL();
         String var35 = IniFile.override().getIniString("HelpDirectory", "help");
         String var39 = IniFile.override().getIniString("HelpPage", Std.getVersion() + Console.message(".html"));
         if (wasHttpNoSuchFile(var27 + var35 + "/" + var39)) {
            var39 = IniFile.override().getIniString("HelpPage", Std.getVersion() + ".html");
         }

         new SendURLAction(var27 + var35 + "/" + var39).startBrowser();
      } else if (var1.target == this.infoItem) {
         String var26 = IniFile.override().getIniString("infoOverride", "");
         if (var26.equals("")) {
            NetUpdate.showInfo();
         } else {
            new SendURLAction(var26).startBrowser();
         }
      } else if (var1.target == this.i18nTest) {
         Locale var25 = Locale.getDefault();
         Console.println("Default = " + var25.getDisplayName());
         DateFormat var34 = DateFormat.getDateTimeInstance(1, 1);
         Date var38 = new Date();
         Console.println("Today = " + var34.format(var38));
         Locale[] var41 = DateFormat.getAvailableLocales();
         Console.println("Avaliable Locales are:");

         for (int var7 = 0; var7 < var41.length; var7++) {
            Locale.setDefault(var41[var7]);
            Console.println(var41[var7].getDisplayName() + " " + var41[var7]);
         }

         new Locale("en", "US");
         Locale var8 = new Locale("fr", "FR");
         Locale var9 = new Locale("de", "DE");
         Locale var10 = new Locale("ja", "JP");
         Locale var11 = new Locale("zh", "CN");
         Locale var12 = new Locale("th", "TH");
         Locale var13 = new Locale("ru", "RU");
         Locale var14 = new Locale("iw", "IL");
         Console.println("file.encoding = " + System.getProperty("file.encoding"));
         Console.println(this.message("test-language", var8));
         Console.println(this.message("test-language", var9));
         Console.println(this.message("test-language", var10));
         Console.println(this.message("test-language", var11));
         Console.println(this.message("test-language", var12));
         Console.println(this.message("test-language", var13));
         Console.println(this.message("test-language", var14));
         Console.println(this.message("test-language", var25));
      } else if (var1.target == this.checkAccountItem) {
         String var24 = IniFile.override().getIniString("accountOverride", "");
         if (var24.equals("")) {
            String var33 = IniFile.override().getIniString("accountInfoPage", "account" + Console.message(".pl"));
            if (wasHttpNoSuchFile(this.getScriptServer() + var33)) {
               var33 = IniFile.override().getIniString("accountInfoPage", "account.pl");
            }

            new SendURLAction(this.getScriptServer() + var33, true).startBrowser();
         } else {
            new SendURLAction(var24).startBrowser();
         }

         this.relogin();
      } else if (var1.target == this.upgradeItem) {
         NetUpdate.doUpdate(true);
      } else if (var1.target == this.channelItem && this.channelItem != null) {
         Galaxy var23 = this.getGalaxy();
         String var32 = "";
         Debug.dAssert(var23 != null);
         if (var23 != null) {
            var32 = var23.getChannel();
         }

         new ChannelDialog(getFrame(), this, Console.message("Dimension-Sel"), var32);
      } else if (var1.target == this.becomeVIPItem) {
         String var22 = IniFile.override().getIniString("vipOverride", "");
         if (var22.equals("")) {
            String var31 = IniFile.override().getIniString("vipPage", "vip" + Console.message(".pl"));
            if (wasHttpNoSuchFile(this.getScriptServer() + var31)) {
               var31 = IniFile.override().getIniString("vipPage", "vip.pl");
            }

            new SendURLAction(this.getScriptServer() + var31, true).startBrowser();
         } else {
            new SendURLAction(var22, false).startBrowser();
         }

         this.relogin();
      } else if (var1.target == this.numVisItem) {
         new SetNumVisibleAvs();
      } else if (var1.target == this.inventoryItem) {
         EquipAction var21 = new EquipAction();
         var21.trigger(null, null);
      } else if (var1.target == this.proxyServerItem) {
         System.out.println("Triggering the Proxy Server dialog.");
         ProxyServerDialog var20 = new ProxyServerDialog();
         var20.show();
      } else if (var1.target == this.toggleVoiceChatItem) {
         VoiceChat.setVoiceChatEnabled(!VoiceChat.voiceChatEnabled);
         this.setMenusWRTVIP();
      } else if (var1.target == this.serverItem) {
         this.handleServerItem();
      } else if (var1.target == this.condenseItem) {
         new ArchiveMaker(true);
      } else if (var1.target == this.expandItem) {
         new ArchiveMaker(false);
      } else if (var1.target == this.musicManItem) {
         MusicManager.showDialog();
      } else if (var1.target == this.cdPlayerItem) {
         if (this.cdcontrol == null) {
            this.playedCD = true;
            this.cdcontrol = new CDControl(getFrame(), this);
         }
      } else if (var1.target == this.volumeItem) {
         if (!CDPlayerAction.launchVolumeControlApp()) {
            new OkCancelDialog(getFrame(), null, Console.message("No-Volume"), null, Console.message("OK"), Console.message("Cannot-locate"), true);
         }
      } else if (var1.target == this.graphicsItem) {
         this.handleGraphicsItem();
      } else if (var1.target == this.nametagItem) {
         this.handleNametagsItem();
      } else if (var1.target == this.chatBoxItem) {
         this.handleChatBoxItem();
      } else if (var1.target == this.bootSomeone) {
         new BootDialog(getFrame(), this, Console.message("Boot-user"));
      } else if (var1.target == this.broadcastToRoom) {
         startWhispering("room");
      } else if (var1.target == this.broadcastToAll) {
         startWhispering("world");
      } else if (var1.target == this.currentLang) {
         String var19 = Locale.getDefault().toString();
         if (var19 == Console.message(var19)) {
            Console.println(Console.message("Current-Language") + " = " + Locale.getDefault().getDisplayName());
         } else {
            Console.println(Console.message("Current-Language") + " = " + Console.message(var19));
         }
      } else if (var1.target == this.recorderPlayItem) {
         println(Console.message("BlackBoxPlay"));
         BlackBox.getInstance().play();
      } else if (var1.target == this.recorderRecItem) {
         println(Console.message("BlackBoxRec"));
         BlackBox.getInstance().record();
      } else if (var1.target == this.recorderStopItem) {
         println(Console.message("BlackBoxStop"));
         BlackBox.getInstance().stop();
      } else if (this.fontItems != null && this.fontItems.contains(var1.target)) {
         String var17 = IniFile.gamma().getIniString("upgradeServer", "") + "/I18N/font_";

         for (int var30 = 0; var30 < this.fLength; var30++) {
            if (var1.target == this.fontItems.elementAt(var30)) {
               if (this.fsList.elementAt(var30) != null) {
                  var17 = var17 + this.flList.elementAt(var30) + "_" + this.fsList.elementAt(var30) + ".EXE";
               } else {
                  var17 = var17 + this.flList.elementAt(var30) + ".EXE";
               }

               int var37 = this.fSizes[var30];
               String var40 = var17.substring(var17.lastIndexOf(47) + 1, var17.length());
               LanguageManager.handle(var17, var37, var40);
               break;
            }
         }
      } else if (this.downItems != null && this.downItems.contains(var1.target)) {
         String var15 = IniFile.gamma().getIniString("upgradeServer", "") + "/I18N/language_";

         for (int var29 = 0; var29 < this.dLength; var29++) {
            if (var1.target == this.downItems.elementAt(var29)) {
               if (this.sList.elementAt(var29) != null) {
                  var15 = var15 + this.lList.elementAt(var29) + "_" + this.sList.elementAt(var29) + ".zip";
                  IniFile.gamma().setIniString("DEFAULTLANGUAGE", (String)this.lList.elementAt(var29) + "_" + this.sList.elementAt(var29));
               } else {
                  var15 = var15 + this.lList.elementAt(var29) + ".zip";
                  IniFile.gamma().setIniString("DEFAULTLANGUAGE", (String)this.lList.elementAt(var29));
               }

               int var5 = this.lSizes[var29];
               String var6 = var15.substring(var15.lastIndexOf(47) + 1, var15.length());
               LanguageManager.handle(var15, var5, var6);
               break;
            }
         }
      } else if (this.langItems != null && this.langItems.contains(var1.target)) {
         for (int var3 = 0; var3 < lLength; var3++) {
            if (var1.target == this.langItems.elementAt(var3)) {
               Locale.setDefault(newLocale[var3]);
               String var4 = newLocale[var3].toString();
               if (var4 == Console.message(var4)) {
                  Console.println(message("Setting-to") + " " + newLocale[var3].getDisplayName());
               } else {
                  Console.println(message("Setting-to") + " " + Console.message(var4));
               }

               IniFile.gamma().setIniString("DEFAULTLANGUAGE", lCodes[var3][0] + "_" + lCodes[var3][1]);
               new OkCancelDialog(getFrame(), null, Console.message("Alert"), null, Console.message("OK"), Console.message("Change-exit"), true);
               break;
            }
         }
      } else if (this.avatarMenu == null || !this.avatarMenu.action(var1, var2)) {
         return super.action(var1, var2);
      }

      return true;
   }

   public void setCurrentAvatarItem(CheckboxMenuItem var1) {
      if (this.curAvatarItem != null) {
         this.curAvatarItem.setState(false);
      }

      this.curAvatarItem = var1;
      if (this.curAvatarItem != null) {
         this.curAvatarItem.setState(true);
      }
   }

   public CheckboxMenuItem getCurrentAvatarItem() {
      return this.curAvatarItem;
   }

   public void deletedSavedAvatar(CheckboxMenuItem var1) {
      if (this.curAvatarItem == var1) {
         this.findAvatarMenuItem(this.getDefaultAvatarURL());
      }
   }

   public void setNextAvatar(URL var1, CheckboxMenuItem var2) {
      synchronized (this.nextAvatarMutex) {
         this.nextAvatar = var1;
         this.nextAvatarItem = var2;
      }
   }

   private void findAvatarMenuItem(URL var1) {
      synchronized (this.nextAvatarMutex) {
         if (this.nextAvatarItem == null) {
            CheckboxMenuItem var3;
            if ((this.savedAvs == null || (var3 = this.savedAvs.findMenuItem(var1)) == null)
               && (this.avatarMenu == null || (var3 = this.avatarMenu.findMenuItem(var1)) == null)) {
               this.setCurrentAvatarItem(null);
            } else {
               this.setCurrentAvatarItem(var3);
            }
         }
      }
   }

   private URL getHelpGettingStarted() {
      IniFile var1 = new IniFile("InstalledWorlds");
      String var2 = Console.message("Getting-started");
      String var3 = var1.getIniString("InstalledWorld0", "");
      if (!var3.equals("")) {
         URL var4 = URL.make("home:" + var3 + "/" + var2);
         File var5 = new File(var4.unalias());
         if (var5.exists()) {
            return var4;
         }
      }

      return URL.make("home:" + var2);
   }

   private void changeView(CheckboxMenuItem var1) {
      this.chooseView = this.viewItems.indexOf(var1);
      if (var1 != this.currentViewItem) {
         this.currentViewItem.setState(false);
         this.currentViewItem = var1;
         this.currentViewItem.setState(true);
      }
   }

   private int getView() {
      return this.viewItems.indexOf(this.currentViewItem);
   }

   private void setView(int var1) {
      this.changeView((CheckboxMenuItem)this.viewItems.elementAt(var1));
   }

   private void changeCamSpeed(CheckboxMenuItem var1) {
      this.chooseCamSpeed = this.camSpeedItems.indexOf(var1);
      if (var1 != this.currentCamSpeedItem) {
         this.currentCamSpeedItem.setState(false);
         this.currentCamSpeedItem = var1;
         this.currentCamSpeedItem.setState(true);
      }
   }

   public void resetCamera() {
      if (this.viewItems != null && this.camSpeedItems != null) {
         this.chooseView = this.viewItems.indexOf(this.currentViewItem);
         this.chooseCamSpeed = this.camSpeedItems.indexOf(this.currentCamSpeedItem);
      }
   }

   private void handleServerItem() {
      if (!this.serverItem.getLabel().equals(signIn)) {
         Galaxy.forceOffline(false);
      } else {
         this.getGalaxy().localForceOnline();
         this.getGalaxy().waitForConnection(this);
      }
   }

   public UniversePanel getUniverse() {
      return this.universeMode ? this.universe : null;
   }

   public synchronized void setUniverseMode(boolean var1) {
      if (var1 != this.universeMode) {
         this.universeMode = var1;
         if (this.universeMode) {
            if (this.universe == null) {
               this.universe = new UniversePanel(this);
               this.renderAndUniverse.add("universe", this.universe);
            }

            this.renderCard.show(this.renderAndUniverse, "universe");
            this.universe.startWatch();
            this.render.requestFocus();
         } else {
            this.renderCard.show(this.renderAndUniverse, "render");
            if (physMem < 64000000) {
               this.renderAndUniverse.remove(this.universe);
               this.universe.stopWatch();
               this.universe.flushImage();
               this.universe = null;
            }

            this.renderAndUniverse.repaint();
         }
      }
   }

   public void toggleUniverseMode() {
      this.setUniverseMode(!this.universeMode);
   }

   public boolean isUniverseMode() {
      return this.universeMode;
   }

   public Object imageButtonsCallback(Component var1, int var2) {
      if (var1 != this.driveButton) {
         if (var1 == this.quitButton) {
            maybeQuit();
         } else if (var1 == this.exploreButton) {
            this.toggleUniverseMode();
         } else if (var1 == this.menuButtons) {
            switch (var2) {
               case 0:
                  return this.getMenu("Help");
               case 1:
                  return this.getMenu("Options");
               case 2:
                  String var3 = IniFile.override().getIniString("ProductName", "");
                  if (!var3.equalsIgnoreCase("RedLightWorld")) {
                     EMailPart.showMessage(this);
                  }
                  break;
               case 3:
                  return (PopupMenu)this.marks.getMenu();
               case 4:
                  return (PopupMenu)this.marks.getLetsMenu();
               case 5:
                  this.actions.present();
                  break;
               case 6:
                  return this.getMenu("VIP");
            }
         }
      }

      return null;
   }

   public RenderCanvas getRender() {
      return this.render;
   }

   public FriendsListPart getFriends() {
      return this.friends;
   }

   public MuteListPart getMutes() {
      return this.mutes;
   }

   public void generateFrameEvents(FrameEvent var1) {
      if (Window.getWindowState(Window.getFrameHandle()) == 1) {
         this.goToSleep();
      }

      if (doDrive) {
         doDrive = false;
         this.render.drive();
         wasDelta = true;
      }

      super.generateFrameEvents(var1);
      Pilot var2 = Pilot.getActive();
      GammaFrame var3 = getFrame();
      String var4 = var3.getTitle();
      String var5 = "";
      if (var2 != null) {
         World var6 = var2.getWorld();
         if (var6 != null) {
            String var7 = var6.getName();
            if (var7 != null) {
               var5 = var7;
            }
         }
      }

      if (!lastWorldName.equals(var5)) {
         lastWorldName = var5;
         String var14 = GammaFrame.getDefaultTitle();
         if (var5.length() != 0) {
            var14 = var14 + " - " + var5;
            if (!this.playedCD) {
               CDAudio.startupPlay();
               this.playedCD = true;
            }
         }

         var3.setTitle(var14);
      }

      if (var2 != null) {
         if (this.chooseView != -1 || this.chooseCamSpeed != -1) {
            int var15 = var2.getOutsideCameraMode();
            int var18 = var2.getOutsideCameraSpeed();
            int var8 = var15;
            int var9 = var18;
            if (this.chooseView != -1) {
               var8 = ((DefaultConsole.CameraView)this.viewNames.elementAt(this.chooseView)).viewID;
            }

            if (this.chooseCamSpeed != -1) {
               var9 = ((DefaultConsole.CameraSpeed)this.speedNames.elementAt(this.chooseCamSpeed)).speedID;
            }

            var2.setOutsideCameraMode(var8, var9);
            if (var8 != 99) {
               IniFile.gamma().setIniInt("CAM_MODE", var8);
               IniFile.gamma().setIniInt("CAM_SPEED", var9);
            }

            this.chooseView = -1;
            this.chooseCamSpeed = -1;
         }

         if (this.wasTeleporting != this.marks.isTeleporting()) {
            this.wasTeleporting = this.marks.isTeleporting();
            if (this.wasTeleporting) {
               this.statusMessage = loadingString;
            } else if (this.statusMessage == loadingString) {
               this.statusMessage = "";
            }
         }

         this.checkVMWarning();
         if (wasDelta && !this.render.getDeltaMode()) {
            this.statusMessage = arrowKeyMsg;
            wasDelta = false;
            this.driveButton.drawCursed();
         }

         synchronized (this.status) {
            if (this.statusMessage != this.lastStatus && this.overrideMessage == null) {
               this.lastStatus = this.statusMessage;
               this.status.setText(this.statusMessage);
            }
         }

         synchronized (this.nextAvatarMutex) {
            if (this.nextAvatar != null) {
               this.setAvatar(this.nextAvatar);
               this.nextAvatar = null;
               if (this.avatarMenu != null) {
                  this.avatarMenu.notifyOfChange();
               }

               if (this.nextAvatarItem != null) {
                  this.setCurrentAvatarItem(this.nextAvatarItem);
                  this.nextAvatarItem = null;
               }
            }
         }
      }
   }

   private void checkVMWarning() {
      int var1 = Std.getFastTime();
      if (var1 > this.lastVMCheck + 10000) {
         StatMemNode var2 = StatMemNode.getNode();
         var2.updateMemoryStatus();
         if (var2._availPageMem < 0) {
            var2._availPageMem = 2000000000;
         }

         if (var2._totPhysMem < 0) {
            var2._totPhysMem = 2000000000;
         }

         physMem = var2._totPhysMem;
         if (var2._availPageMem >= 4194304) {
            if (var2._availPageMem > 5242880 && this.lastVMBigWarning != 0) {
               if (var2._availPageMem > 10485760) {
                  Console.println(Console.message("plenty-virt"));
                  this.lastVMBigWarning = 0;
               } else if (!this.showedMidWarn) {
                  Console.println(Console.message("plenty-virt-mem"));
                  this.showedMidWarn = true;
               }

               if (this.statusMessage == lowVMMsg) {
                  this.statusMessage = "";
               }
            }
         } else {
            if (this.lastVMBigWarning == 0 || this.showedMidWarn || var1 > this.lastVMBigWarning + 300000) {
               Console.println(Console.message("Low-virt-mem"));
               this.lastVMBigWarning = var1;
               this.showedMidWarn = false;
            }

            this.statusMessage = lowVMMsg;
         }

         Object[] var3 = new Object[]{new String(Std.getProductName()), new Integer(24)};
         if (startupMemCheck) {
            if (var2._totPhysMem < 24000000) {
               String var4 = MessageFormat.format(Console.message("Mem-detected"), var3);
               new OkCancelDialog(getFrame(), null, Console.message("Too-Little-RAM"), null, Console.message("OK"), var4, true);
            }

            startupMemCheck = false;
            System.out.println("System has " + var2._totPhysMem + " bytes of physical RAM");
         }

         this.lastVMCheck = var1;
      }
   }

   public URL getAvatarName() {
      return this.avatarURL;
   }

   public void setServerURL(URL var1) {
      super.setServerURL(var1);
   }

   public void dialogDone(Object var1, boolean var2) {
      if (var1 instanceof QuitDialog) {
         if (var2) {
            Console.quit();
         }
      } else if (var1 instanceof BootDialog) {
         if (var2) {
            BootDialog var3 = (BootDialog)var1;
            String var4 = var3.getBoot();
            if (!var4.equals("")) {
               Pilot.sendText("world", "!boot " + var4);
            }
         }
      } else if (var1 instanceof ChannelDialog) {
         if (var2) {
            ChannelDialog var9 = (ChannelDialog)var1;
            String var10 = var9.getChannel();
            Pilot var5 = Pilot.getActive();
            String var6 = var5 != null ? var5.getURL() : null;
            if (var6 != null) {
               int var7 = var6.indexOf("<");
               int var8 = var6.indexOf(">");
               if (var7 >= 0 && var8 > var7) {
                  TeleportAction.teleport(var6.substring(0, var7 + 1) + var10 + var6.substring(var8), null);
               }
            } else {
               Console.println(Console.message("cant-determine"));
            }
         }
      } else if (var1 instanceof LoginWizard) {
         Debug.dAssert(false);
      } else if (var1 instanceof CDControl) {
         if (this.cdcontrol == var1) {
            this.cdcontrol = null;
         }
      } else if (var1 instanceof InternetConnectionDialog) {
         Debug.dAssert(false);
      } else if (var1 == this.reloginDialog) {
         if (var2) {
            Galaxy.forceOffline(true);
         }

         this.reloginDialog = null;
      }
   }

   public void setAvatar(URL var1) {
      this.avatarURL = var1;
      boolean var2 = var1.getInternal().toLowerCase().endsWith(".rwg");
      boolean var3 = var1.equals(getDefaultURL()) && !this.getGalaxy().getOnline();
      if (!this.getVIPAvatars() && var2 && !var3) {
         Console.println(Console.message("Only-VIPs") + " '" + SelectAvatarAction.getPrettyAvatarName(var1.getBase()) + "'.");
      } else if (VehicleShape.isVehicle(var1)) {
         this.tempCarAvatar = var1.getAbsolute();
         super.setAvatar(var1);
      } else {
         this.tempCarAvatar = "";
         if (this.avatarMenu != null) {
            this.avatarMenu.customize.setEnabled(!var1.getAbsolute().endsWith("mov"));
         }

         if (!var1.equals(this.getDefaultAvatarURL())) {
            if (this.getVIPAvatars()) {
               if (!var2) {
                  IniFile.gamma().setIniString("VIPAVATAR", "");
               } else {
                  IniFile.gamma().setIniString("VIPAVATAR", var1.getAbsolute());
               }
            }

            if (!var2) {
               IniFile.gamma().setIniString("AVATAR", var1.getAbsolute());
            }
         }

         super.setAvatar(var1);
      }
   }

   private CheckboxMenuItem findAvatar(Vector var1, String var2) {
      if (var1 != null) {
         int var3 = var1.size();

         for (int var4 = 0; var4 < var3; var4++) {
            CheckboxMenuItem var5 = (CheckboxMenuItem)var1.elementAt(var4);
            if (var5.getLabel().equals(var2)) {
               return var5;
            }
         }
      }

      return null;
   }

   protected void loadPilot(URL var1) {
      super.loadPilot(var1);
      this.findAvatarMenuItem(var1);
   }

   public void setChatname(String var1) {
      Debug.dAssert(var1 != null);
      if (var1.length() != 0) {
         String var2 = (this.getVIP() ? (vip > 1 ? Console.message("VIP") + " " : Console.message("vip")) + " " : "")
            + "\""
            + Console.parseUnicode(var1)
            + "\"";
         this.yourName.setText(var2);
         IniFile.gamma().setIniString("LASTCHATNAME", parseExtended(var2));
      } else {
         this.yourName.setText(Console.message("Off-line"));
      }
   }

   public void connectionCallback(Object var1, boolean var2) {
      super.connectionCallback(var1, var2);
      if (var1 instanceof Galaxy) {
         if (var1 != this.galaxy) {
            return;
         }

         if (var2) {
            WorldServer var3 = this.getServerNew();
            this.friends.setServer(var3, this.getGalaxy().getIniSection());
            this.mutes.setServer(var3, this.getGalaxy().getIniSection());
            if (vip < 2) {
               Console.println(vip == 1 ? Console.message("Press-full-VIP") : Console.message("Press-VIP"));
            }

            PosableShape.downloadPermittedNames();
         }
      }
   }

   public void galaxyDisconnected() {
      super.galaxyDisconnected();
      this.getFriends().maybeServerDisconnect();
   }

   public boolean okToQuit() {
      int var1 = IniFile.override().getIniInt("QuitDialog", 1);
      if (var1 == 1) {
         new QuitDialog(getFrame(), this);
         return false;
      } else {
         return true;
      }
   }

   public Rectangle getBrowserPlacement() {
      String var1 = IniFile.gamma().getIniString("BROWSERWINDOW", "");
      if (var1.length() != 0) {
         StringTokenizer var2 = new StringTokenizer(var1, " ,");

         try {
            return new Rectangle(
               Integer.parseInt(var2.nextToken()), Integer.parseInt(var2.nextToken()), Integer.parseInt(var2.nextToken()), Integer.parseInt(var2.nextToken())
            );
         } catch (NumberFormatException var10) {
         } catch (NoSuchElementException var11) {
         }
      }

      Point var12 = this.menuButtons.getLocationOnScreen();
      int var3 = this.menuButtons.getLocationOnScreen().x - (int)(this.menuButtons.getSize().width * 0.7);
      int var4 = Window.getSystemMetrics(32);
      int var5 = Toolkit.getDefaultToolkit().getScreenSize().width;
      int var6 = Math.min(var5, 640) + 2 * var4;
      int var7 = 0;
      if (var3 != var6) {
         if (var3 > var6) {
            var7 += var3 - var6;
         }

         var3 = var6;
      }

      if (var3 > var5) {
         var7 += -var4;
      }

      int var8 = this.chat.listen.getLocationOnScreen().y + this.chat.listen.getSize().height - this.chat.line.getSize().height;
      int var9 = 0;
      if (var8 > 540) {
         var9 += var8 - 540;
         var8 = 540;
      }

      return new Rectangle(var7, var9, var3, var8);
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Avatar"), "rwg;mov");
            } else if (var3 == 1) {
               var5 = this.lastPilotRequested;
            } else if (var3 == 2) {
               this.setNextAvatar((URL)var4, null);
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Collect garbage"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(false);
            } else if (var3 == 2 && (Boolean)var4) {
               System.gc();
               System.runFinalization();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 2, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      int var2 = var1.restoreVersion(classCookie);
      switch (var2) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }

   private class CameraSpeed {
      public String speedName;
      public int speedID;

      public CameraSpeed(String var2, int var3) {
         this.speedName = var2;
         this.speedID = var3;
      }
   }

   private class CameraView {
      public String viewName;
      public int viewID;

      public CameraView(String var2, int var3) {
         this.viewName = var2;
         this.viewID = var3;
      }
   }
}

package NET.worlds.console;

import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.Cache;
import NET.worlds.network.CacheFile;
import NET.worlds.network.Galaxy;
import NET.worlds.network.RemoteFileConst;
import NET.worlds.network.URL;
import NET.worlds.scape.SendURLAction;
import java.awt.Button;
import java.awt.CardLayout;
import java.awt.Checkbox;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Event;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextField;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Random;
import java.util.Vector;

public class LoginWizard extends PolledDialog implements DialogReceiver, DialogDisabled, RemoteFileConst {
   private static final int HAVE_USERS = 0;
   private static final int ACCOUNT_TYPE = 1;
   private static final int REGWAIT = 2;
   private static final int WELCOME = 3;
   private static final int CODEWORD_WAIT = 4;
   private static final int NEW_USER_INFO = 5;
   private static final int LOGGING_IN = 7;
   private static final int NOT_LOGGED_IN = 8;
   private static final int ERROR = 9;
   private static final int CONNECTION_DIED = 10;
   private static final int AUTO_LOGIN_FAILED = 11;
   private static final int REGWAIT2 = 12;
   private static final int BAD_PASSWORD = 13;
   private static final int SCREEN_COUNT = 14;
   private static final int STATE_GET_INFO = 0;
   private static final int STATE_SEND_INFO = 1;
   private static final int STATE_WAIT = 2;
   private static final int STATE_AUTO_LOGIN = 3;
   private static final int STATE_LOGGED_IN = 4;
   private static final String defaultRegisterScriptL = "register" + Console.message(".pl");
   private static final String defaultRegisterScript = "register.pl";
   private static final String nameConstraints = Console.message("n-contain-letters");
   private static final String passwordConstraints1 = Console.message("p-contain-letters");
   private static final int oldMinPasswordLen = 4;
   private static final int newMinPasswordLen = 6;
   private static final String savePasswordText = Console.message("Remember-password");
   private static final String passwordMismatchText = Console.message("do-not-match");
   private static final String userNameIniKey = "User";
   private static final String passwordIniKey = "Password";
   private static final String serialNumIniKey = "SNum";
   private static final String handshakeIDIniKey = "handshakeID";
   private static final String defaultUserIniKey = "DefaultUser";
   static final int width = 480;
   static final int height = 280;
   static final int textWidth = 400;
   private Galaxy galaxy;
   private IniFile iniFile;
   private CardLayout cardLayout = new CardLayout();
   private int currentScreen = -1;
   private int lastScreen = -1;
   private int loginFrom = -1;
   private int errorFrom;
   private Panel[] screens = new Panel[14];
   private boolean queryingServer;
   private Button createNewUsernameButton;
   private Button alternateBrowserButton;
   private Button signInButton;
   private Button noEmailButton;
   private Button showRegButton;
   private Button pwMailbackButtonKnown;
   private Button typeUsername;
   private TextField codewordField = null;
   private TextField newUserName = null;
   private TextField newPassword1 = null;
   private TextField newPassword2 = null;
   private TextField typedUsername = null;
   private static Font font = new Font(Console.message("GammaTextFont"), 0, 12);
   private static Font bfont = new Font(Console.message("ButtonFont"), 0, 12);
   private TextField knownPassword = null;
   private Checkbox savePassword = new Checkbox(savePasswordText, true);
   private Vector users = new Vector();
   private Vector passwords = new Vector();
   private int defaultUser;
   private String loginUserName;
   private String loginPassword;
   private String loginSerialNumber;
   private String newSerialNumber;
   private String newHandshakeID;
   private int loginMode;
   private int loginIndex = 0;
   private int loginState;
   private String errMsg;
   private boolean isDialogDisabled;
   private Component defComponent;
   private int id;
   private static boolean startUp = true;
   private static boolean firstTimeDone;
   private static int seq;
   private CacheFile cf;

   public static boolean isFirstTimeDone() {
      return firstTimeDone;
   }

   public boolean safeToQueryServer() {
      return this.queryingServer;
   }

   public LoginWizard(Galaxy var1, IniFile var2) {
      this(var1, var2, null);
   }

   boolean isAnonServer() {
      return this.galaxy.getGalaxyType() == 4 || this.galaxy.getGalaxyType() == 2;
   }

   public LoginWizard(Galaxy var1, IniFile var2, String var3) {
      super(Console.getFrame(), var1, "", false);
      this.galaxy = var1;
      this.iniFile = var2;
      this.errMsg = var3;
      this.id = seq++;
      this.queryingServer = false;
      int var4 = 0;

      while (true) {
         String var5 = var2.getIniString("User" + var4, "");
         if (var5.length() == 0) {
            this.defaultUser = var2.getIniInt("DefaultUser", 0);
            this.newSerialNumber = var2.getIniString("SNum", "");
            if (this.newSerialNumber.length() == 0) {
               this.newSerialNumber = null;
            }

            this.newHandshakeID = var2.getIniString("handshakeID", "");
            if (this.newHandshakeID.length() == 0) {
               this.newHandshakeID = null;
            }

            this.setTitle(Console.message("Logging-in"));
            this.setLayout(this.cardLayout);
            this.loginState = 0;
            if (var3 != null) {
               this.currentScreen = 10;
            } else if (this.users.size() <= 0 && !this.isAnonServer() && IniFile.override().getIniInt("nocreateaccount", 0) != 1) {
               this.setTitle(Console.message("Setting-Up-Acct"));
               if (this.newSerialNumber == null) {
                  if (this.newHandshakeID == null) {
                     this.currentScreen = 1;
                  } else {
                     this.currentScreen = 12;
                  }
               } else {
                  this.currentScreen = 5;
               }
            } else {
               this.currentScreen = 0;
            }

            startUp = false;
            if (this.loginState != 3) {
               this.disableParent();
               this.ready();
            }

            return;
         }

         this.users.addElement(var5);
         this.passwords.addElement(Console.decode(var2.getIniString("Password" + var4, "")));
         var4++;
      }
   }

   public boolean waitingForConnection() {
      return this.loginState == 3 || this.loginState == 2;
   }

   public void setConnected() {
      int var1 = this.loginState;
      this.loginState = 4;
      if (this.loginFrom != 0 || this.users.size() <= this.loginIndex) {
         this.users.addElement(this.loginUserName);
         this.passwords.addElement(null);
         this.iniFile.setIniString("User" + this.loginIndex, this.loginUserName);
         if (this.loginFrom == 5) {
            this.iniFile.setIniString("SNum" + this.loginIndex, this.loginSerialNumber);
         }
      }

      boolean var2 = this.savePassword.getState();
      String var3 = this.galaxy.getPassword();
      if (this.loginPassword != null
         && var3 != null
         && (var2 != this.isPasswordSaved(this.loginIndex) || !var3.equals((String)this.passwords.elementAt(this.loginIndex)))) {
         String var4 = var2 ? var3 : null;
         this.passwords.setElementAt(var4, this.loginIndex);
         this.iniFile.setIniString("Password" + this.loginIndex, Console.encode(var4));
      }

      String var6 = this.galaxy.getChatname();
      String var5 = this.galaxy.getUsernameU();
      if (this.loginFrom != 5 && !var6.equals((String)this.users.elementAt(this.loginIndex))) {
         this.users.setElementAt(var6, this.loginIndex);
         this.iniFile.setIniString("User" + this.loginIndex, var5);
      }

      this.iniFile.setIniInt("DefaultUser", this.loginIndex);
      this.defaultUser = this.loginIndex;
      if (this.newSerialNumber != null) {
         this.newHandshakeID = null;
         this.newSerialNumber = null;
         this.iniFile.setIniString("handshakeID", "");
         this.iniFile.setIniString("SNum", "");
      }

      if (this.loginFrom != 0) {
         this.selectScreen(3);
      } else if (var1 != 3) {
         this.done(true);
      } else {
         Debug.assert_(Main.isMainThread());
         this.galaxy.dialogDone(this, true);
         firstTimeDone = true;
      }
   }

   public void loginError(String var1) {
      this.removeScreen(8);
      if (var1 == null) {
         var1 = Console.message("Unknown-error");
      }

      this.errMsg = var1;
      if (this.loginState == 3) {
         this.currentScreen = 11;
         this.disableParent();
         this.ready();
      } else {
         if (this.loginFrom == -1) {
            this.loginFrom = 0;
         }

         this.selectScreen(8);
      }

      this.loginState = 0;
   }

   public void show() {
      super.show();
      if (this.defComponent != null) {
         this.defComponent.requestFocus();
      }
   }

   public void dispose() {
      super.dispose();
   }

   protected void activeCallback() {
      if (this.loginState == 1) {
         this.loginState = 2;
         this.galaxy.setAuthInfo(this.loginUserName, null, this.loginPassword, null, this.loginSerialNumber, this.loginMode);
      }
   }

   protected void build() {
      this.selectScreen(this.currentScreen);
   }

   public Dimension size() {
      return new Dimension(480, 280);
   }

   private void selectScreen(int var1) {
      String var2 = "" + var1;
      if (this.screens[var1] == null) {
         this.add(var2, this.screens[var1] = this.buildScreen(var1));
      }

      this.cardLayout.show(this, var2);
      if (this.lastScreen != var1 && this.lastScreen >= 0 && this.screens[this.lastScreen] != null) {
         this.removeScreen(this.lastScreen);
      }

      this.currentScreen = var1;
      this.lastScreen = var1;
      if (var1 == 2) {
         new SendURLAction(this.getRegisterScriptName()).startBrowser();
      } else if (var1 == 4) {
         new LoginWizard.AwaitCodeword(this.codewordField.getText());
      }
   }

   private Panel buildScreen(int var1) {
      GridBagLayout var2 = new GridBagLayout();
      GridBagConstraints var3 = new GridBagConstraints();
      Panel var4 = new Panel(var2);
      var3.weightx = 1.0;
      var3.weighty = 1.0;
      var3.gridwidth = 0;
      switch (var1) {
         case 0:
            return this.buildKnownUsersScreen(var4, var2, var3);
         case 1:
            return this.buildAccountTypeScreen(var4, var2, var3);
         case 2:
            return this.buildRegWait(var4, var2, var3);
         case 3:
            return this.buildWelcome(var4, var2, var3);
         case 4:
            return this.buildCodewordWaitScreen(var4, var2, var3);
         case 5:
            return this.buildNewUserInfoScreen(var4, var2, var3);
         case 6:
         default:
            return null;
         case 7:
            return this.buildLoggingInScreen(var4, var2, var3);
         case 8:
         case 9:
         case 10:
         case 11:
            return this.buildErrorScreen(var4, var2, var3, var1);
         case 12:
            return this.buildRegWait2(var4, var2, var3);
      }
   }

   private void removeScreen(int var1) {
      if (this.screens[var1] != null) {
         this.remove(this.screens[var1]);
         this.screens[var1] = null;
      }
   }

   private void selectErrorScreen(String var1) {
      this.errMsg = var1;
      this.errorFrom = this.currentScreen;
      this.selectScreen(9);
   }

   private Panel buildKnownUsersScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      this.typedUsername = new TextField(16);
      this.knownPassword = new TextField(12);
      this.knownPassword.setEchoChar('*');
      Panel var4 = new Panel();
      String var5 = Console.message("one-username");
      if (this.isAnonServer()) {
         var5 = Console.message("a-username");
      }

      TextCanvas var6 = new TextCanvas(var5, 400);
      var4.add(var6);
      add(var1, var4, var2, var3);
      if (this.createNewUsernameButton == null) {
         this.createNewUsernameButton = new Button(Console.message("Create-Username"));
      }

      if (this.pwMailbackButtonKnown == null) {
         this.pwMailbackButtonKnown = new Button(Console.message("Remind-Me"));
      }

      if (this.defaultUser < this.users.size()) {
         String var7 = (String)this.passwords.elementAt(this.defaultUser);
         boolean var8 = var7 != null;
         this.knownPassword.setText(var8 ? var7 : "");
         this.savePassword.setState(var8);
         this.typedUsername.setText((String)this.users.elementAt(this.defaultUser));
      }

      var4 = new Panel(new GridLayout(2, 2));
      Label var13 = new Label(Console.message("Username"), 1);
      var13.setFont(font);
      this.typedUsername.setFont(font);
      this.knownPassword.setFont(font);
      var4.add(var13);
      var4.add(this.typedUsername);
      if (this.isAnonServer()) {
         this.knownPassword.setText(Console.message("anonymous"));
         add(var1, var4, var2, var3);
      } else {
         Label var14 = new Label(Console.message("Password"), 1);
         var14.setFont(font);
         var4.add(var14);
         var4.add(this.knownPassword);
         add(var1, var4, var2, var3);
         this.savePassword.setFont(font);
         add(var1, this.savePassword, var2, var3);
      }

      var4 = new Panel();
      String var15 = Console.message("youve-upgraded");
      if (this.iniFile.getIniString("AutoLogin", "").equals("") && this.iniFile.getIniString("User1", "").equals("")) {
         var15 = "";
      }

      String var9 = Console.message("first-time-user" + var15);
      if (this.isAnonServer()) {
         var9 = var15;
      }

      var6 = new TextCanvas(var9, 400);
      var4.add(var6);
      add(var1, var4, var2, var3);
      if (!this.isAnonServer() && IniFile.override().getIniInt("nocreateaccount", 0) != 1) {
         this.addButtons(
            var1,
            var2,
            this.users.size() > 0 ? Console.message("Cancel") : "<< " + Console.message("Back"),
            this.createNewUsernameButton,
            this.pwMailbackButtonKnown,
            Console.message("Sign-In")
         );
      } else {
         this.addButtons(var1, var2, Console.message("Cancel"), null, null, Console.message("Sign-In"));
      }

      if (this.knownPassword.getText().length() == 0) {
         if (this.typedUsername.getText().length() == 0) {
            this.defComponent = this.typedUsername;
         } else {
            this.defComponent = this.knownPassword;
         }
      }

      return var1;
   }

   private void validateKnownUserInfo() {
      if (this.acceptLoginUserName(this.typedUsername.getText()) && this.acceptLoginPassword(this.knownPassword.getText(), this.loginUserName, 4)) {
         this.loginSerialNumber = null;
         this.loginMode = 2;
         this.loginIndex = 0;
         this.doLogin();
      }
   }

   private Panel buildAccountTypeScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      TextCanvas var4 = new TextCanvas(Console.message("first-time-user2"), 400);
      add(var1, var4, var2, var3);
      if (this.alternateBrowserButton == null) {
         this.alternateBrowserButton = new Button(Console.message("Alt-Browser"));
      }

      if (this.signInButton == null) {
         this.signInButton = new Button(Console.message("Sign-In"));
      }

      return this.addButtons(var1, var2, Console.message("Cancel"), this.signInButton, this.alternateBrowserButton, Console.message("Next"));
   }

   private Panel buildRegWaitCommon(Panel var1, GridBagLayout var2, GridBagConstraints var3, int var4) {
      String var5 = "";
      if (var4 == 0) {
         var5 = Console.message("registration");
      }

      TextCanvas var6 = new TextCanvas(var5 + Console.message("completed"), 400);
      add(var1, var6, var2, var3);
      Panel var7 = new Panel(new GridLayout());
      Label var8 = new Label(Console.message("Codeword"), 1);
      var8.setFont(font);
      var7.add(var8);
      this.codewordField = new TextField(10);
      if (this.newSerialNumber != null) {
         this.codewordField.setText(this.newSerialNumber);
      }

      this.codewordField.setFont(font);
      var7.add(this.codewordField);
      add(var1, var7, var2, var3);
      String var9 = new String();
      if (WebBrowser.isDisabled()) {
         if (var4 == 0) {
            var9 = var9 + Console.message("manually-view");
         } else {
            var9 = var9 + Console.message("just-view");
         }

         var9 = var9 + this.getRegisterScriptName();
      } else {
         var9 = var9 + Console.message("click-Back");
      }

      if (this.users.size() == 0) {
         String var10 = Console.message("within-20");
         if (var4 == 1) {
            var10 = Console.message("Show-Reg-Form1");
         }

         var6 = new TextCanvas(new String(var10 + var9), 400);
         add(var1, var6, var2, var3);
      } else if (var4 == 1) {
         var6 = new TextCanvas(Console.message("Show-Reg-Form1"), 400);
         add(var1, var6, var2, var3);
      }

      if (this.noEmailButton == null) {
         this.noEmailButton = new Button(Console.message("Didnt-Get-Email"));
      }

      if (this.showRegButton == null) {
         this.showRegButton = new Button(Console.message("Show-Reg-Form3"));
      }

      Button var15 = var4 == 0 ? null : this.showRegButton;
      return this.addButtons(var1, var2, "<< " + Console.message("Back"), var15, this.noEmailButton, Console.message("Next") + " >>");
   }

   private Panel buildRegWait(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      return this.buildRegWaitCommon(var1, var2, var3, 0);
   }

   private Panel buildRegWait2(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      return this.buildRegWaitCommon(var1, var2, var3, 1);
   }

   private Panel buildWelcome(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      add(var1, new Label(""), var2, var3);
      Object[] var4 = new Object[]{new String(Std.getProductName())};
      add(var1, new Label(MessageFormat.format(Console.message("Youre-signed"), var4), 1), var2, var3);
      Panel var5 = new Panel();
      TextCanvas var6 = new TextCanvas(Console.message("Use-arrow-keys2"), 400);
      var5.add(var6);
      add(var1, var5, var2, var3);
      add(var1, new Label(""), var2, var3);
      return this.addButtons(var1, var2, null, null, null, Console.message("Enter-Worlds"));
   }

   private static boolean isMadeOf(String var0, String var1) {
      char[] var2 = var0.toCharArray();

      for (int var3 = 0; var3 < var2.length; var3++) {
         if (var1.indexOf(var2[var3]) == -1) {
            return false;
         }
      }

      return true;
   }

   private Panel buildCodewordWaitScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      TextCanvas var4 = new TextCanvas(Console.message("Checking-codeword"), 400);
      add(var1, var4, var2, var3);
      return this.addButtons(var1, var2, Console.message("Cancel"), null, null, null);
   }

   private Panel buildNewUserInfoScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      this.newUserName = new TextField(16);
      this.newPassword1 = new TextField(12);
      this.newPassword2 = new TextField(12);
      Object[] var4 = new Object[]{new String(Std.getProductName())};
      TextCanvas var5 = new TextCanvas(MessageFormat.format(Console.message("Enter-username"), var4), 400);
      var5.setFont(font);
      add(var1, var5, var2, var3);
      Panel var6 = new Panel();
      var6.setFont(font);
      var6.add(new Label(Console.message("Type-username")));
      var6.add(this.newUserName);
      add(var1, var6, var2, var3);
      var5 = new TextCanvas(Console.message("Enter-password"), 400);
      add(var1, var5, var2, var3);
      var6 = new Panel(new GridLayout(2, 2));
      var6.setFont(font);
      var6.add(new Label(Console.message("Type-password"), 1));
      this.newPassword1.setEchoChar('*');
      var6.add(this.newPassword1);
      var6.add(new Label(Console.message("Re-type-password"), 1));
      this.newPassword2.setEchoChar('*');
      var6.add(this.newPassword2);
      add(var1, var6, var2, var3);
      add(var1, this.savePassword, var2, var3);
      return this.addButtons(
         var1,
         var2,
         this.newHandshakeID == null ? Console.message("Finish-Later") : "<< " + Console.message("Back"),
         null,
         null,
         Console.message("Next") + " >>"
      );
   }

   private void validateNewUserInfo() {
      if (this.acceptLoginUserName(this.newUserName.getText()) && this.acceptLoginPassword(this.newPassword1.getText(), this.newUserName.getText(), 6)) {
         if (!this.loginPassword.equals(this.newPassword2.getText())) {
            this.selectErrorScreen(passwordMismatchText);
         } else {
            this.loginMode = 1;
            this.loginSerialNumber = this.newSerialNumber;
            this.loginIndex = 0;
            this.doLogin();
         }
      }
   }

   private Panel buildLoggingInScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3) {
      Label var4 = new Label(Console.message("Logging-in-wait"));
      var4.setFont(font);
      add(var1, var4, var2, var3);
      return var1;
   }

   private Panel buildErrorScreen(Panel var1, GridBagLayout var2, GridBagConstraints var3, int var4) {
      this.errMsg = this.errMsg.replace('\n', ' ').replace('\t', '\n');
      TextCanvas var5 = new TextCanvas(this.errMsg, 400);
      this.errMsg = null;
      add(var1, var5, var2, var3);
      return this.addButtons(var1, var2, var4 != 9 && var4 != 8 ? Console.message("Continue") : "<< " + Console.message("Back"), null, null, null);
   }

   private boolean acceptLoginPassword(String var1, String var2, int var3) {
      if (FriendsListPart.isValidUserName(var1) && var1.length() >= var3) {
         this.loginPassword = var1;
         return true;
      } else {
         Object[] var5 = new Object[]{new String("" + var3)};
         String var4 = Console.message("password-not-valid") + MessageFormat.format(passwordConstraints1, var5);
         this.selectErrorScreen(var4);
         return false;
      }
   }

   private boolean acceptLoginUserName(String var1) {
      if (!FriendsListPart.isValidUserName(var1)) {
         this.selectErrorScreen(Console.message("username-not-valid") + nameConstraints + " - " + var1);
         return false;
      } else {
         this.loginUserName = var1;
         return true;
      }
   }

   private void doLogin() {
      this.loginFrom = this.currentScreen;
      this.selectScreen(7);
      this.loginState = 1;
   }

   private boolean isPasswordSaved(int var1) {
      return var1 < this.passwords.size() && this.passwords.elementAt(var1) != null;
   }

   private static void add(Container var0, Component var1, GridBagLayout var2, GridBagConstraints var3) {
      var2.setConstraints(var1, var3);
      var0.add(var1);
   }

   private Panel addButtons(Panel var1, GridBagLayout var2, String var3, Button var4, Button var5, String var6) {
      Panel var7 = new Panel();
      var7.setFont(bfont);
      if (var3 != null) {
         var7.add(new BackButton(var3));
      }

      if (var4 != null) {
         var7.add(var4);
      }

      if (var5 != null) {
         var7.add(var5);
      }

      if (var6 != null) {
         var7.add(this.defComponent = new ForwardButton(var6));
      }

      GridBagConstraints var8 = new GridBagConstraints();
      var8.anchor = 14;
      add(var1, var7, var2, var8);
      return var1;
   }

   private String getScriptServer() {
      Enumeration var1 = this.galaxy.getConsoles();
      Debug.assert_(var1.hasMoreElements());
      this.queryingServer = true;
      String var2 = ((Console)var1.nextElement()).getScriptServer();
      this.queryingServer = false;
      System.out.println("Scriptserver is " + var2);
      return var2;
   }

   private String getRegisterScriptName() {
      if (this.newHandshakeID == null) {
         int var1 = new Random(((long)Startup.getVolumeInfo() << 30) + (int)(Math.random() * 1.0737418E9F)).nextInt();
         if (var1 < 0) {
            var1 = -var1;
         }

         this.newHandshakeID = "" + var1;
         this.iniFile.setIniString("handshakeID", this.newHandshakeID);
      }

      IniFile var18 = IniFile.override();
      String var2 = var18.getIniString("register", "");
      if (var2.equals("")) {
         var2 = defaultRegisterScriptL;
         if (Console.wasHttpNoSuchFile(var2)) {
            var2 = "register.pl";
         }

         var18 = new IniFile("InstalledWorlds");
         String var3 = var18.getIniString("InstalledWorld0", "");
         if (!var3.equals("")) {
            String var4 = URL.make("home:" + var3 + "/register.txt").unalias();
            DataInputStream var5 = null;

            try {
               var5 = new DataInputStream(new FileInputStream(var4));
               String var6 = var5.readLine();
               if (var6 != null) {
                  var2 = var6;
               }
            } catch (IOException var16) {
            } finally {
               try {
                  if (var5 != null) {
                     var5.close();
                  }
               } catch (IOException var15) {
               }
            }
         }
      }

      return new String(this.getScriptServer() + var2 + "?id=" + this.newHandshakeID);
   }

   public boolean action(Event var1, Object var2) {
      Object var3 = var1.target;
      if (var3 instanceof ForwardButton) {
         if (this.currentScreen == 0) {
            this.validateKnownUserInfo();
         } else if (this.currentScreen == 1) {
            WebBrowser.setDisabled(false);
            this.selectScreen(2);
         } else if (this.currentScreen == 2 || this.currentScreen == 12) {
            this.selectScreen(4);
         } else if (this.currentScreen == 5) {
            this.validateNewUserInfo();
         } else if (this.currentScreen == 3) {
            this.done(true);
         }
      } else if (var3 instanceof BackButton) {
         if (this.currentScreen == 0) {
            if (this.users.size() > 0) {
               this.done(false);
            } else {
               this.selectScreen(1);
            }
         } else if (this.currentScreen == 1) {
            if (this.users.size() == 0) {
               this.done(false);
            } else {
               this.selectScreen(0);
            }
         } else if (this.currentScreen == 2 || this.currentScreen == 12) {
            this.selectScreen(this.users.size() > 0 ? 0 : 1);
         } else if (this.currentScreen == 5) {
            if (this.newSerialNumber != null && this.newSerialNumber.length() > 6 && this.newHandshakeID != null) {
               this.selectScreen(12);
            } else if (this.users.size() > 0) {
               this.selectScreen(0);
            } else {
               this.done(false);
            }
         } else if (this.currentScreen == 4) {
            if (this.cf != null) {
               this.cf.close();
            }

            this.selectScreen(12);
         } else if (this.currentScreen == 8) {
            this.selectScreen(this.loginFrom);
         } else if (this.currentScreen == 9) {
            this.selectScreen(this.errorFrom);
         } else if (this.currentScreen == 11 || this.currentScreen == 10) {
            this.selectScreen(0);
         }
      } else if (var3 == this.pwMailbackButtonKnown) {
         new SendURLAction(this.getScriptServer() + "emailback.pl", true).startBrowser();
      } else if (var3 == this.typedUsername) {
         this.knownPassword.requestFocus();
      } else if (var3 == this.knownPassword) {
         this.validateKnownUserInfo();
      } else if (var3 == this.createNewUsernameButton) {
         String var4 = IniFile.override().getIniString("CreateUserRedirect", "Fred");
         if (var4.equals("Fred")) {
            if (this.newHandshakeID != null) {
               this.selectScreen(12);
            } else if (this.newSerialNumber == null) {
               this.selectScreen(2);
            } else {
               this.selectScreen(5);
            }
         } else {
            new SendURLAction(URL.make(var4)).startBrowser();
         }
      } else if (var3 == this.alternateBrowserButton) {
         WebBrowser.setDisabled(true);
         this.selectScreen(2);
      } else if (var3 == this.signInButton) {
         this.selectScreen(0);
      } else {
         if (var3 != this.noEmailButton && var3 != this.showRegButton) {
            return false;
         }

         this.selectScreen(2);
      }

      return true;
   }

   public boolean keyDown(Event var1, int var2) {
      if (var2 == 10) {
         this.action(var1, null);
         return true;
      } else {
         return super.keyDown(var1, var2);
      }
   }

   public boolean handleEvent(Event var1) {
      if (this.isDialogDisabled) {
         return false;
      } else {
         return var1.id == 201 && this.loginState == 2 ? true : super.handleEvent(var1);
      }
   }

   protected boolean done(boolean var1) {
      boolean var2 = super.done(var1);
      firstTimeDone = true;
      return var2;
   }

   public void dialogDone(Object var1, boolean var2) {
   }

   public void dialogDisable(boolean var1) {
      this.isDialogDisabled = var1;
      super.dialogDisable(var1);
   }

   public String toString() {
      return "LoginWizard" + this.id;
   }

   class AwaitCodeword extends Thread {
      public AwaitCodeword(String var2) {
         if (var2.length() > 6) {
            LoginWizard.this.selectScreen(5);
            LoginWizard.this.newSerialNumber = var2;
            LoginWizard.this.iniFile.setIniString("SNum", LoginWizard.this.newSerialNumber);
         } else {
            LoginWizard.this.cf = Cache.getFile(
               URL.make(LoginWizard.this.getScriptServer() + "codeword.pl?id=" + LoginWizard.this.newHandshakeID + "&codeword=" + var2)
            );
            this.setDaemon(true);
            this.start();
         }
      }

      public void run() {
         LoginWizard.this.cf.waitUntilLoaded();
         if (LoginWizard.this.cf.isActive()) {
            if (LoginWizard.this.cf.error()) {
               LoginWizard.this.currentScreen = 12;
               LoginWizard.this.selectErrorScreen(Console.message("Error-accessing"));
            } else {
               DataInputStream var1 = null;

               label128: {
                  try {
                     var1 = new DataInputStream(new FileInputStream(LoginWizard.this.cf.getLocalName()));
                     String var2 = var1.readLine();
                     if (!var2.startsWith("1,0,") && !var2.startsWith("1,1,")) {
                        break label128;
                     }

                     LoginWizard.this.newSerialNumber = var2.substring(4);
                     LoginWizard.this.iniFile.setIniString("SNum", LoginWizard.this.newSerialNumber);
                     LoginWizard.this.newHandshakeID = null;
                     LoginWizard.this.iniFile.setIniString("handshakeID", "");
                     LoginWizard.this.selectScreen(5);
                     LoginWizard.this.cf.close();
                  } catch (FileNotFoundException var15) {
                     break label128;
                  } catch (IOException var16) {
                     break label128;
                  } finally {
                     try {
                        if (var1 != null) {
                           var1.close();
                        }
                     } catch (IOException var14) {
                     }
                  }

                  return;
               }

               LoginWizard.this.currentScreen = 12;
               LoginWizard.this.selectErrorScreen(Console.message("codeword-no-match"));
            }

            LoginWizard.this.cf.close();
         }
      }
   }
}

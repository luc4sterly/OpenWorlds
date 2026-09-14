package NET.worlds.console;

import NET.worlds.core.IniFile;
import NET.worlds.core.Std;
import NET.worlds.network.NetUpdate;
import NET.worlds.scape.MusicManager;
import NET.worlds.scape.Pilot;
import NET.worlds.scape.TeleportAction;
import NET.worlds.scape.TeleportStatus;
import NET.worlds.scape.World;
import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Frame;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.URLConnection;
import java.text.MessageFormat;
import java.util.Enumeration;
import java.util.Hashtable;
import java.util.NoSuchElementException;
import java.util.Properties;
import java.util.StringTokenizer;

public class Gamma implements Runnable, MainCallback, TeleportStatus {
   private static SplashScreen splash = null;
   public static ProgressBar loadProgress;
   static final int LOAD_PROGRESS_STEPS = 12;
   static final float failVersion = 1.13F;
   private static String _home = "file:";
   private static String _dllPath = "home:";
   private static Hashtable _params = new Hashtable();
   private static boolean _autoplay = false;
   static Shaper shaper;
   private String startingURL;
   private String loadErr;

   static boolean checkVersion(String var0) {
      StringTokenizer var1 = new StringTokenizer(var0, "._");
      float var2 = 0.0F;

      try {
         Integer var3 = new Integer(var1.nextToken());
         var2 = var3.intValue();
         var3 = new Integer(var1.nextToken());
         float var4 = var3.floatValue() / 10.0F;
         if (!(var4 < 1.0F)) {
            return true;
         }

         var2 += var4;
         var3 = new Integer(var1.nextToken());
         var4 = var3.floatValue() / 100.0F;
         var2 += var4;
      } catch (NoSuchElementException var9) {
      }

      if (var2 <= 1.13F) {
         BlockingDialog var12 = new BlockingDialog(new Frame(), "Worlds.com: Error", true);
         GridBagLayout var14 = new GridBagLayout();
         var12.setLayout(var14);
         var12.setSize(200, 150);
         MultiLineLabel var5 = new MultiLineLabel("Your system's Java Virtual Machine\nis out of date. Please download our\nfull installer and try again.");
         GridBagConstraints var6 = new GridBagConstraints();
         var6.gridx = 0;
         var6.gridy = 0;
         var14.setConstraints(var5, var6);
         var12.add(var5);
         Button var7 = new Button("OK");
         var7.addActionListener(var12);
         GridBagConstraints var8 = new GridBagConstraints();
         var8.gridx = 0;
         var8.gridy = 1;
         var14.setConstraints(var7, var8);
         var12.add(var7);
         var12.validate();
         var12.show();
         var12.waitForResponse();
         return false;
      } else {
         return true;
      }
   }

   public static void main(String[] var0) {
      String var1 = parseCommandLine(var0);
      String var2 = System.getProperty("java.version");
      if (!checkVersion(var2)) {
         System.exit(0);
      }

      String var3 = System.getProperty("java.vendor");
      System.out.println("User running java version " + var2 + " from vendor " + System.getProperty("java.vendor"));
      String var4 = "winawt";
      String var5 = "net";
      boolean var6 = false;
      if (var3.indexOf("Microsoft") != -1) {
         var4 = "MSAWT";
         var5 = "MSNET32";
         var6 = true;
      }

      System.out.println("Loading: " + earlyURLUnalias(_dllPath + "gamma.dll"));
      System.load(earlyURLUnalias(_dllPath + "gamma.dll"));
      if (var6) {
         Window.doMicrosoftVMHacks();
      }

      if (IniFile.gamma().getIniInt("MULTIRUN", 0) == 0 && !Startup.synchronizeStartup(var1, _autoplay)) {
         System.exit(0);
      }

      if (var2.charAt(2) <= '1' && !var6) {
         try {
            System.loadLibrary(var4);
         } catch (UnsatisfiedLinkError var35) {
         }

         try {
            System.loadLibrary(var5);
         } catch (UnsatisfiedLinkError var34) {
         }
      } else {
         if (!var6) {
            var4 = "awt";
         }

         new Color(0, 0, 0);

         try {
            URL var8 = new URL("http://127.0.0.1/");
            URLConnection var9 = var8.openConnection();
            var9.connect();
         } catch (MalformedURLException var36) {
         } catch (IOException var37) {
         }
      }

      if (!var6) {
         Window.hookWinAPIs(var4);
      }

      String var7 = earlyURLUnalias("home:worlds.ini");
      Std.initProductName();
      IniFile var38 = IniFile.override();
      String var39 = var38.getIniString("splashgif", Console.message("Opnscrnc.gif"));
      splash = new SplashScreen(GammaFrame.getDefaultTitle(), var39);
      splash.show();
      splash.toFront();
      String var10 = IniFile.gamma().getIniString("Proxy Server IP", "");
      String var11 = IniFile.gamma().getIniString("Proxy Server Port", "");
      if (var10.length() > 7) {
         Properties var12 = System.getProperties();
         System.out.println("Using Proxy Server: " + var10 + ":" + var11);
         var12.remove("socksProxyHost");
         var12.remove("socksProxyPort");
         var12.put("socksProxyHost", var10);
         var12.put("socksProxyPort", var11);
         System.setProperties(var12);
      }

      loadProgress = new ProgressBar("Loading Worldsplayer...", 12);
      Dimension var14 = splash.getSize();
      Dimension var15 = loadProgress.getSize();
      int var40 = splash.getLocationOnScreen().x + (var14.width >> 1) - (var15.width >> 1);
      int var13 = splash.getLocationOnScreen().y + var14.height;
      loadProgress.setLocation(var40, var13);
      loadProgress.show();
      java.awt.Cursor var16 = java.awt.Cursor.getPredefinedCursor(3);
      loadProgress.setCursor(var16);
      splash.setCursor(var16);
      if (var7.length() > 1 && var7.charAt(1) == ':') {
         Startup.computeVolumeInfo("" + var7.charAt(0) + ":\\");
      } else {
         Startup.computeVolumeInfo(null);
      }

      try {
         LogFile.open();
         Gamma var17 = new Gamma(var1);
         Main.register(var17);
         if (loadProgress != null) {
            loadProgress.setMessage("Starting main thread...");
            loadProgress.advance();
         }

         Thread var18 = new Thread(var17, "Gamma Main");
         var18.setDaemon(true);
         var18.start();
         new Gamma.PriorityAdjuster(var18);
         if (loadProgress != null) {
            loadProgress.setMessage("Initializing ActiveX...");
            loadProgress.advance();
         }

         new Netscape();

         try {
            var18.join();
         } catch (InterruptedException var30) {
            throw new Error(var30.toString());
         }

         GammaFrame var20 = Console.getFrame();
         if (var20 != null) {
            var20.setVisible(false);
         }
      } catch (OutOfMemoryError var31) {
         System.out.println("ERROR:  Ran out of memory!!");
         System.out.println("Details: " + var31);
      } catch (Throwable var32) {
         System.out.println("Uncaught throwable: " + var32);
      } finally {
         LogFile.close();
      }

      System.exit(0);
   }

   public static void hideSplash() {
      if (splash != null) {
         splash.hide();
         splash.dispose();
         splash = null;
         if (loadProgress != null) {
            loadProgress.hide();
            loadProgress.dispose();
            loadProgress = null;
         }
      }
   }

   public static String earlyURLUnalias(String var0) {
      if (var0.startsWith("home:")) {
         var0 = _home + var0.substring(5);
      }

      if (var0.startsWith("file:")) {
         var0 = var0.substring(5);
      }

      var0 = var0.replace('\\', '/');
      if (var0.length() < 2 || var0.charAt(1) != ':' && !var0.startsWith("//")) {
         String var1 = System.getProperty("user.dir").replace('\\', '/');
         if (!var1.endsWith("/")) {
            var1 = var1 + "/";
         }

         var0 = var1 + var0;
      }

      return var0;
   }

   public static String getParam(String var0) {
      return (String)_params.get(var0);
   }

   private static String parseCommandLine(String[] var0) {
      String var1 = null;

      for (int var2 = 0; var2 < var0.length; var2++) {
         if (var0[var2].length() > 0 && var0[var2].charAt(0) == '-') {
            if (var0[var2].equalsIgnoreCase("-help")) {
               usage("Help message");
            } else if (var0[var2].equalsIgnoreCase("-home")) {
               if (++var2 == var0.length) {
                  usage("-home must be followed by a path:");
               }

               _home = "file:" + var0[var2];
               System.out.println("Home: " + var0[var2]);
            } else if (var0[var2].equalsIgnoreCase("-dllpath")) {
               if (++var2 == var0.length) {
                  usage("-dllpath must be followed by a path:");
               }

               _dllPath = var0[var2];
            } else if (var0[var2].equalsIgnoreCase("-set")) {
               label55: {
                  if (++var2 != var0.length) {
                     if (++var2 != var0.length) {
                        break label55;
                     }
                  }

                  usage("-set must be followed by a name of a parameter to set and its value");
               }

               _params.put(var0[var2 - 1], var0[var2]);
            } else if (var0[var2].equalsIgnoreCase("-autoplay")) {
               _autoplay = true;
            } else if (!var0[var2].equalsIgnoreCase("-embedding")
               && !var0[var2].equalsIgnoreCase("/embedding")
               && !var0[var2].equalsIgnoreCase("-automation")
               && !var0[var2].equalsIgnoreCase("/automation")) {
               usage("Unrecognized command line option: " + var0[var2]);
            }
         } else {
            if (var1 != null) {
               usage("There may be only one command-line world URL");
            }

            var1 = var0[var2];
         }
      }

      _home = makeEndWithSlash(_home);
      _dllPath = makeEndWithSlash(_dllPath);
      return var1;
   }

   private static String makeEndWithSlash(String var0) {
      if (!var0.endsWith("\\") && !var0.endsWith("/") && !var0.endsWith(":")) {
         var0 = var0 + "\\";
      }

      return var0;
   }

   public static void usage(String var0) {
      System.out
         .println(
            "Usage: javaw {-java_options} NET.worlds.console.Gamma {-options} WorldURL\nWorldURL is optional, the default world is the first WorldsMark.\nYes, it's gross, but the 'NET.worlds.console.Gamma' is required\nSome useful -java_options:\n    -classpath Path   Class search path [default is CLASSPATH env var]\n-options:\n    -help             Print this message (still runs Gamma)\n    -home HomeDir     Gamma home directory [defaults to current dir]\n    -dllpath DLLPath  Path to the native code DLL [current directory]\n    -set Name Value   Set the named parameter to the specified value"
         );
      throw new Error(var0);
   }

   public static String getHome() {
      return _home;
   }

   public static String getExePath() {
      return getHome() + "bin\\";
   }

   public static void dllLoad(String var0) {
      System.load(NET.worlds.network.URL.make(_dllPath + var0).unalias());
   }

   public static Shaper getShaper() {
      return shaper;
   }

   public static boolean shaperEnabled() {
      return IniFile.gamma().getIniInt("DISABLESHAPER", 1) == 0 || IniFile.override().getIniInt("DISABLESHAPER", 1) == 0;
   }

   private Gamma(String var1) {
      this.startingURL = var1;
   }

   private void die(Throwable var1) {
      var1.printStackTrace(System.out);
      if (getShaper() != null) {
         Console.println(Console.message("Saving-modified"));
         Enumeration var2 = World.getWorlds();

         while (var2.hasMoreElements()) {
            World var3 = (World)var2.nextElement();
            if (var3.getEdited()) {
               String var4 = var3.getSourceURL().unalias();
               if (var4.toLowerCase().endsWith(".wor")) {
                  var4 = var4.substring(0, var4.length() - 4);
               }

               if (var4.toLowerCase().endsWith(".world")) {
                  var4 = var4.substring(0, var4.length() - 6);
               }

               int var5 = var4.lastIndexOf("-");
               if (var5 != -1) {
                  for (int var6 = var5 + 1; var6 < var4.length(); var6++) {
                     if (!Character.isDigit(var4.charAt(var6))) {
                        var5 = -1;
                        break;
                     }
                  }
               }

               if (var5 != -1) {
                  var4 = var4.substring(0, var5);
               }

               String var12 = var4 + ".world";

               for (int var7 = 1; new File(var12).exists(); var7++) {
                  var12 = var4 + "-" + var7 + ".world";
               }

               Object[] var8 = new Object[]{new String(var3.getName()), new String("" + var3.getSourceURL()), new String(var12)};
               Console.println(MessageFormat.format(Console.message("Saving-name"), var8));

               try {
                  Shaper.doSave(var12, var3, false);
               } catch (Exception var10) {
                  Console.println(Console.message("Ignoring") + var10);
               } catch (Error var11) {
                  Console.println(Console.message("Ignoring") + var11);
               }
            }
         }
      }
   }

   public void run() {
      Main.register(new Gamma.RecordPosition());

      try {
         Main.mainLoop();
      } catch (Throwable var2) {
         this.die(var2);
      }
   }

   public void mainCallback() {
      Main.unregister(this);
      if (NetUpdate.doUpdate(false)) {
         Main.end();
      } else {
         File var1 = new File(earlyURLUnalias("home:bin"));
         File var2 = new File(var1, "gdkup.prg");
         File var3 = new File(var1, "gdkup.exe");
         if (var2.exists() && (!var3.exists() || var2.lastModified() > var3.lastModified())) {
            if (var3.exists()) {
               var3.delete();
            }

            try {
               FileInputStream var4 = new FileInputStream(var2);
               FileOutputStream var5 = new FileOutputStream(var3);
               byte[] var6 = new byte[8192];

               int var7;
               while ((var7 = var4.read(var6)) > 0) {
                  var5.write(var6, 0, var7);
               }

               var4.close();
               var5.close();
            } catch (Exception var10) {
               var10.printStackTrace(System.out);
               throw new Error("Can't copy gdkup.prg");
            }
         }

         if (shaperEnabled()) {
            shaper = new Shaper();
         }

         IniFile var11 = IniFile.override();
         String var12 = var11.getIniString("splashover", Console.message("Pwc.gif"));
         int var13 = var11.getIniInt("splashxover", 141);
         int var14 = var11.getIniInt("splashyover", 140);
         if (var13 >= 0) {
            splash.addOverlay(var12, var13, var14);
         }

         if (loadProgress != null) {
            loadProgress.setMessage("Teleporting to start location...");
            loadProgress.advance();
         }

         try {
            TeleportAction.teleport(this.startingURL, this, false);
         } catch (Exception var9) {
            this.loadErr = "Couldn't teleport to " + this.startingURL + ": " + var9;
         }

         if (this.loadErr != null) {
            System.out.println(this.loadErr);
            this.loadErr = null;
            TeleportAction.teleport("world:", this, false);
            if (this.loadErr != null) {
               this.loadErr = null;
               TeleportAction.teleport("home:NewWorld.world", this, false);
               if (this.loadErr != null) {
                  Main.end();
                  return;
               }
            }

            Main.register(new Gamma.StartupTeleport());
         }

         new MusicManager();
      }
   }

   public void teleportStatus(String var1, String var2) {
      if (var1 == null) {
         this.loadErr = null;
      } else {
         this.loadErr = var1;
      }
   }

   static class PriorityAdjuster implements MainCallback {
      private Thread mainThread;
      boolean wasActivated = true;

      PriorityAdjuster(Thread var1) {
         this.mainThread = var1;
         this.mainThread.setPriority(5);
         Main.register(this);
      }

      public void mainCallback() {
         if (Window.isActivated() != this.wasActivated) {
            this.wasActivated = !this.wasActivated;
            this.mainThread.setPriority(this.wasActivated ? 5 : 1);
         }
      }
   }

   public class RecordPosition implements MainCallback, MainTerminalCallback {
      public void mainCallback() {
      }

      public void terminalCallback() {
         Pilot var1 = Pilot.getActive();
         if (var1 != null) {
            IniFile.gamma().setIniString("RestartAt", var1.getURL());
         }

         Main.unregister(this);
      }
   }

   class StartupTeleport implements MainCallback {
      public void mainCallback() {
         if (Console.getFrame() != null && Console.getFrame().isShowing()) {
            Main.unregister(this);

            try {
               TeleportAction.teleport(Gamma.this.startingURL, Gamma.this, true);
            } catch (Exception var2) {
            }
         }
      }
   }
}

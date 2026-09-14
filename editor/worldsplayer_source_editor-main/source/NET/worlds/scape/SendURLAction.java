package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.console.InternetExplorer;
import NET.worlds.console.Main;
import NET.worlds.console.MainCallback;
import NET.worlds.console.OkCancelDialog;
import NET.worlds.console.PolledDialog;
import NET.worlds.console.WebBrowser;
import NET.worlds.console.WebControlImp;
import NET.worlds.core.IniFile;
import NET.worlds.network.RemoteFileConst;
import NET.worlds.network.URL;
import java.io.IOException;
import java.net.MalformedURLException;
import java.text.MessageFormat;
import java.util.Hashtable;


public class SendURLAction extends DialogAction implements MainCallback, RemoteFileConst {
   URL destination;
   URL destinationOverride;
   String worldOverride;
   String description;
   String postData = null;
   protected boolean getUser;
   InternetExplorer bogusBrowser;
   private static String notAvailablePrefix = "http://www.worldsstore.com/superstore/en/product/";
   private static Hashtable notAvailable = new Hashtable();
   private String trigger;
   private int tries = 0;
   private Persister curSeq = null;
   private static Object classCookie = new Object();

   public SendURLAction() {
      this("http://www.worlds.net");
   }

   public SendURLAction(URL var1) {
      this.destination = var1;
      this.getUser = false;
   }

   public SendURLAction(String var1) {
      this(var1 == null ? null : URL.make(var1));
   }

   public SendURLAction(String var1, boolean var2) {
      this(var1 == null ? null : URL.make(var1), var2);
   }

   public SendURLAction(URL var1, boolean var2) {
      this.destination = var1;
      this.getUser = var2;
   }

   public void setDestination(URL var1) {
      this.destination = var1;
   }

   public void setTrigger(String var1) {
      this.trigger = var1;
   }

   public void startBrowser() {
      if (Main.isMainThread()) {
         this.tryLaunch();
      } else {
         Main.register(this);
      }
   }

   public void mainCallback() {
      Main.unregister(this);
      this.tryLaunch();
   }

   private URL getDestination() {
      if (this.worldOverride != null) {
         IniFile var1 = new IniFile("InstalledWorlds");
         String var2 = var1.getIniString("InstalledWorld0", "");
         if (this.worldOverride.equalsIgnoreCase(var2)) {
            return this.destinationOverride;
         }
      }

      return this.destination;
   }

   private void tryLaunch() {
      URL var1 = this.getDestination();
      if (var1 != null) {
         String var2 = var1.unalias();
         String var3 = WebControlImp.processURL(var2);
         if (var3 != null) {
            var2 = var3;
         }

         if (this.postData != null) {
            this.postData = WebControlImp.processURL(this.postData);
         }

         String var4 = null;
         Console var5 = Console.getActive();
         if (var5 != null && var5.getGalaxy().getChatname() != null && !var5.getGalaxy().getChatname().equals("")) {
            var4 = "Username=" + var5.getGalaxy().getUsernameU();
         }

         if (this.getUser && var4 != null) {
            var2 = var2 + "?" + var4;
         }

         String var6 = var2.substring(var2.indexOf(":") + 1);
         if (var2.startsWith("sound:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.forceMinimized(true);
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getAdPartPlacement(), "sound:");
               WebBrowser.forceMinimized(false);
               return;
            } catch (IOException var21) {
            }
         } else if (var2.startsWith("videoMap:") || var2.startsWith("overmap:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.dontUseToolbar();
               WebBrowser.dontUseWindowFrame();
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getMapPartPlacement(), "videoMap:");
               WebBrowser.useToolbar();
               return;
            } catch (IOException var22) {
            }
         } else if (var2.startsWith("videoAd:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.dontUseToolbar();
               WebBrowser.dontUseWindowFrame();
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getAdPartPlacement(), "videoAd:");
               WebBrowser.useToolbar();
               return;
            } catch (IOException var20) {
            }
         } else if (var2.startsWith("zoom:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.dontUseToolbar();
               WebBrowser.dontUseWindowFrame();
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getRenderPartPlacement(), "zoom:");
               WebBrowser.useToolbar();
               return;
            } catch (IOException var19) {
            }
         } else if (var2.startsWith("zoomLeft:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.dontUseToolbar();
               WebBrowser.dontUseWindowFrame();
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getLeftRenderPartPlacement(), "zoomLeft:");
               WebBrowser.useToolbar();
               return;
            } catch (IOException var18) {
            }
         } else if (var2.startsWith("outside:")) {
            var2 = URL.make(var6).unalias();
            WavSoundPlayer.pauseSystem();
            CDAudio.get().setEnabled(false);

            try {
               WebBrowser.dontUseToolbar();
               WebBrowser.reuseOrMake(var2, this.postData, WebBrowser.getOutsidePlacement(), "outside:");
               WebBrowser.useToolbar();
               return;
            } catch (IOException var17) {
            }
         } else if (var2.startsWith("pnm:")) {
            var2 = URL.make(var6).unalias();

            try {
               WebBrowser.reuseOrMake(var2, this.postData);
               return;
            } catch (IOException var16) {
            }
         } else if (var2.startsWith("http:")) {
            String var7 = IniFile.override().getIniString("ProductName", "");
            java.net.URL var8 = null;

            try {
               var8 = new java.net.URL(var2.toLowerCase());
            } catch (MalformedURLException var14) {
            }

            if (var7.equalsIgnoreCase("RedLightWorld") && var8 != null && var8.getHost().endsWith("theredlightworld.com")) {
               Console var9 = Console.getActive();
               if (var9 != null && var9.getGalaxy().getChatname() != null && !var9.getGalaxy().getChatname().equals("")) {
                  String var10 = var9.getGalaxy().getUsernameU();
                  String var11 = var9.getGalaxy().getPassword();
                  String var12 = var10 + ":" + var11;
                  this.postData = java.util.Base64.getEncoder().encodeToString(var12.getBytes());
               }
            }

            try {
               WebBrowser.reuseOrMake(var2, this.postData);
               return;
            } catch (IOException var15) {
            }
         }

         if (this.bogusBrowser == null) {
            try {
               this.bogusBrowser = new InternetExplorer(null);
            } catch (IOException var13) {
            }
         }

         if (!launchViaRegistry(var2)) {
            Console.println(var2 + Console.message("Unable-to-launch"));
         }
      }
   }

   public void doIt() {
      this.startBrowser();
   }

   public PolledDialog getDialog() {
      URL var1 = this.getDestination();
      if (var1 == null) {
         return new ItemNotAvailableDialog(Console.getFrame(), this);
      } else {
         String var2 = var1.unalias().toLowerCase();
         if (var2.startsWith(notAvailablePrefix) && notAvailable.containsKey(var2.substring(notAvailablePrefix.length()))) {
            return new ItemNotAvailableDialog(Console.getFrame(), this);
         } else {
            return this.description != null && !this.description.equals("Would you like more information?")
               ? new OkCancelDialog(
                  Console.getFrame(), this, Console.message("BrowseQ"), Console.message("Cancel"), Console.message("OK"), this.description, false, 1
               )
               : new MoreInfoDialog(Console.getFrame(), this);
         }
      }
   }

   private static native boolean launchViaRegistry(String var0);

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Destination").allowSetNull(), null);
            } else if (var3 == 1) {
               var5 = this.destination;
            } else if (var3 == 2) {
               this.destination = (URL)var4;
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Description"));
            } else if (var3 == 1) {
               var5 = this.description;
            } else if (var3 == 2) {
               this.description = ((String)var4).trim();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = URLPropertyEditor.make(new Property(this, var1, "Destination Override").allowSetNull(), null);
            } else if (var3 == 1) {
               var5 = this.destinationOverride;
            } else if (var3 == 2) {
               this.destinationOverride = (URL)var4;
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Override World").allowSetNull());
            } else if (var3 == 1) {
               var5 = this.worldOverride;
            } else if (var3 == 2) {
               if (var4 == null) {
                  this.worldOverride = null;
               } else {
                  this.worldOverride = ((String)var4).trim();
                  if (this.worldOverride.length() == 0) {
                     this.worldOverride = null;
                  }
               }
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Send User Info (auto-login)"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this.getUser);
            } else if (var3 == 2) {
               if ((Boolean)var4) {
                  this.getUser = true;
               } else {
                  this.getUser = false;
               }
            }
            break;
         case 5:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "POST data"));
            } else if (var3 == 1) {
               var5 = this.postData;
            } else if (var3 == 2) {
               this.postData = ((String)var4).trim();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 6, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(9, classCookie);
      super.saveState(var1);
      var1.saveString(this.description);
      URL.save(var1, this.destination);
      URL.save(var1, this.destinationOverride);
      var1.saveString(this.worldOverride);
      var1.saveBoolean(this.getUser);
      var1.saveString(this.postData);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      String var2 = null;
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            var1.setOldFlag();
            var1.restoreBoolean();
            var2 = var1.restoreString();
            var1.restoreString();
            break;
         case 2:
            var1.setOldFlag();
            var1.restoreBoolean();
            var2 = var1.restoreString();
            break;
         case 3:
            this.dialogActionSkipRestore(var1);
            var1.restoreBoolean();
            var2 = var1.restoreString();
            break;
         case 4:
            this.dialogActionSkipRestore(var1);
            var2 = var1.restoreString();
            break;
         case 5:
            this.dialogActionSkipRestore(var1);
            var2 = var1.restoreString();
            this.getUser = var1.restoreBoolean();
            var1.restoreBoolean();
            break;
         case 6:
            super.restoreState(var1);
            this.description = var1.restoreString();
            var2 = var1.restoreString();
            this.getUser = var1.restoreBoolean();
            var1.restoreBoolean();
            break;
         case 7:
            super.restoreState(var1);
            this.description = var1.restoreString();
            var2 = var1.restoreString();
            String var3 = var1.restoreString();
            if (var3 != null) {
               this.destinationOverride = URL.make(var3);
            }

            this.worldOverride = var1.restoreString();
            this.getUser = var1.restoreBoolean();
            var1.restoreBoolean();
            break;
         case 8:
            super.restoreState(var1);
            this.description = var1.restoreString();
            this.destination = URL.restore(var1, null);
            this.destinationOverride = URL.restore(var1, null);
            this.worldOverride = var1.restoreString();
            this.getUser = var1.restoreBoolean();
            var1.restoreBoolean();
            break;
         case 9:
            super.restoreState(var1);
            this.description = var1.restoreString();
            this.destination = URL.restore(var1, null);
            this.destinationOverride = URL.restore(var1, null);
            this.worldOverride = var1.restoreString();
            this.getUser = var1.restoreBoolean();
            this.postData = var1.restoreString();
            break;
         default:
            throw new TooNewException();
      }

      if (var2 != null) {
         this.destination = URL.make(var2);
      }
   }

   public void postRestore(int var1) {
      super.postRestore(var1);
      if (this.trigger != null) {
         SuperRoot var2 = this.getOwner();

         while (var2 != null && !(var2 instanceof WObject)) {
            var2 = var2.getOwner();
         }

         if (var2 == null) {
            Object[] var3 = new Object[]{new String(this.getName())};
            Console.println(MessageFormat.format(Console.message("Cannot-sensor"), var3));
         } else if (this.trigger.equals("click")) {
            ((WObject)var2).addHandler(new ClickSensor(this));
         } else if (this.trigger.equals("bump")) {
            ((WObject)var2).addHandler(new BumpSensor(this));
         } else {
            Room var5 = ((WObject)var2).getRoom();
            if (var5 != null) {
               Object[] var4 = new Object[]{new String(this.trigger), new String(this.getName()), new String(var5.getName())};
               Console.println(MessageFormat.format(Console.message("Trigger-value-in"), var4));
            } else {
               Object[] var6 = new Object[]{new String(this.trigger), new String(this.getName())};
               Console.println(MessageFormat.format(Console.message("Trigger-value"), var6));
            }
         }

         this.trigger = null;
      }
   }

   static {
      Object var0 = new Object();
      notAvailable.put("pa101", var0);
      notAvailable.put("pa102", var0);
      notAvailable.put("pg102", var0);
      notAvailable.put("pg105", var0);
      notAvailable.put("ph108", var0);
      notAvailable.put("ph502", var0);
   }
}

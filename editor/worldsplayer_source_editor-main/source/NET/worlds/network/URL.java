package NET.worlds.network;

import NET.worlds.console.Console;
import NET.worlds.console.Gamma;
import NET.worlds.core.Debug;
import NET.worlds.core.IniFile;
import NET.worlds.scape.Restorer;
import NET.worlds.scape.Saver;
import NET.worlds.scape.SuperRoot;
import java.io.File;
import java.io.IOException;
import java.io.Serializable;
import java.net.MalformedURLException;
import java.util.Hashtable;
import java.util.StringTokenizer;

public class URL implements Serializable {
   static final long serialVersionUID = 1L;
   private String _url;
   private static Hashtable psConversion = new Hashtable();
   private static IniFile protocols = new IniFile("Protocol");
   private static String currentDir = System.getProperty("user.dir").replace('\\', '/');
   private static URL home;
   private static URL file;
   private static boolean useCachedFiles;
   private static URL avatar;

   public URL(SuperRoot var1, String var2) throws MalformedURLException {
      this(getBestContainer(var1), var2);
   }

   public URL(URL var1, String var2) throws MalformedURLException {
      if (isAbsolute(var2)) {
         this._url = normalize(var2);
      } else {
         this._url = "rel:" + var1.getAbsolute(var2);
      }
   }

   public URL(String var1) throws MalformedURLException {
      this((SuperRoot)null, var1);
   }

   public static URL make(String var0) {
      return make(getCurDir(), var0);
   }

   public static URL make(URL var0, String var1) {
      try {
         return new URL(var0, var1);
      } catch (MalformedURLException var3) {
         var3.printStackTrace(System.out);
         throw new Error("Can't make URL");
      }
   }

   private String getAbsolute(String var1) throws MalformedURLException {
      if (!isAbsolute(var1)) {
         var1 = this._url.substring(0, this.getBaseIndex()) + var1;
      }

      if (var1.startsWith("rel:")) {
         var1 = var1.substring(4);
      }

      return normalize(var1);
   }

   private int getBaseIndex() {
      int var1 = this.getPackageIndex();
      if (this._url.endsWith(".class")) {
         int var2 = this._url.lastIndexOf(46, this._url.length() - 7) + 1;
         if (var2 > var1) {
            var1 = var2;
         }
      }

      return var1;
   }

   public String getAbsolute() {
      return this._url.startsWith("rel:") ? this._url.substring(4) : this._url;
   }

   public String toString() {
      return this.getInternal();
   }

   public String getInternal() {
      return this._url;
   }

   public String getBase() {
      return this._url.substring(this.getBaseIndex());
   }

   public String getBaseWithoutExt() {
      int var1 = this.getBaseIndex();
      int var2 = this._url.lastIndexOf(46);
      if (var2 < var1) {
         var2 = this._url.length();
      }

      return this._url.substring(var1, var2);
   }

   private static boolean isAbsolute(String var0) {
      return var0 != null && (var0.indexOf(58) >= 0 || var0.replace('\\', '/').startsWith("//"));
   }

   private static int getRelpathIndex(String var0) {
      int var1 = var0.indexOf(58) + 1;
      if (var0.regionMatches(var1, "//", 0, 2)) {
         var1 = var0.indexOf(47, var1 + 2) + 1;
      } else if (var0.startsWith("file:") && var0.regionMatches(var1 + 1, ":/", 0, 2)) {
         var1 += 3;
      }

      return var1;
   }

   private static String normalize(String var0) throws MalformedURLException {
      var0 = var0.replace('\\', '/').trim();
      int var1 = var0.indexOf(58) + 1;
      if (var1 == 1) {
         throw new MalformedURLException("Missing protocol specifier");
      }

      boolean var2 = var0.regionMatches(var1, "//", 0, 2);
      if (var1 <= 2) {
         if (var1 == 0 && !var2) {
            throw new MalformedURLException("Missing protocol specifier");
         }

         var0 = "file:" + var0;
         var1 = 5;
      }

      if (var0.lastIndexOf(47, var1 - 1) >= 0) {
         throw new MalformedURLException("/ in protocol specifier of " + var0);
      }

      var0 = var0.substring(0, var1).toLowerCase() + var0.substring(var1);
      if (var2) {
         var1 = var0.indexOf(47, var1 + 2) + 1;
         if (var1 == 0) {
            var0 = var0 + '/';
            var1 = var0.length();
         }
      }

      if (var0.startsWith("rel:")) {
         var0 = normalize(var0.substring(4));
         return var0.startsWith("rel:") ? var0 : "rel:" + var0;
      }

      if (var0.startsWith("file:")) {
         var0 = "file:" + validateFile(var0.substring(5));
         if (!var2) {
            Debug.dAssert(var0.indexOf(58, 5) == 6);
            Debug.dAssert(var0.charAt(7) == '/');
            var1 += 3;
         }
      } else if (var0.startsWith("http") && !var2) {
         throw new MalformedURLException("http must have //host/");
      }

      return var0.substring(0, var1) + removeDots(var0.substring(var1));
   }

   private static String validateFile(String var0) throws MalformedURLException {
      if (var0.startsWith("//")) {
         int var4 = var0.indexOf(47, 2);
         if (var4 < 0) {
            var0 = var0 + "/";
         }

         return var0;
      } else {
         var0 = var0.toLowerCase();
         int var1 = var0.indexOf(58);
         if (var1 != 1) {
            return var0.indexOf(47) == 0 ? currentDir.substring(0, 2) + var0 : currentDir + var0;
         } else if (var0.indexOf(47) != 2) {
            throw new MalformedURLException("Slash must follow colon");
         } else {
            char var2 = Character.toLowerCase(var0.charAt(0));
            if (!Character.isLowerCase(var2)) {
               throw new MalformedURLException("Invalid drive letter");
            } else {
               return "" + var2 + var0.substring(1);
            }
         }
      }
   }

   public String getRelativeTo(URL var1) {
      if (var1 != null && this._url.startsWith("rel:")) {
         String var2 = this.unalias();
         String var3 = var1.unalias();
         int var4 = var3.indexOf(58) + 1;
         boolean var5 = var4 == 2;
         if (!var5) {
            String var6 = null;
            if (var3.regionMatches(var4, "//", 0, 2)) {
               var6 = var3;
            } else if (var2.regionMatches(var4, "//", 0, 2)) {
               var6 = var2;
            }

            if (var6 != null) {
               var4 = var6.indexOf(47, var4 + 2) + 1;
               if (var4 == 0) {
                  return this._url;
               }
            }
         }

         if (!var3.regionMatches(var5, 0, var2, 0, var4)) {
            return this._url;
         }

         int var12 = var4;
         int var7 = Math.min(var2.length(), var3.length());

         for (int var8 = var4; var8 < var7; var8++) {
            char var9 = var2.charAt(var8);
            char var10 = var3.charAt(var8);
            if (var9 != var10 && (!var5 || Character.toLowerCase(var9) != Character.toLowerCase(var10))) {
               break;
            }

            if (var9 == '/') {
               var12 = var8 + 1;
            }
         }

         var2 = var2.substring(var12);
         int var13 = var12;

         while ((var13 = var3.indexOf(47, var13) + 1) != 0) {
            var2 = "../" + var2;
            if (this._url.startsWith("rel:home:")) {
               return this._url;
            }
         }

         return var2;
      } else {
         return this._url;
      }
   }

   public String getRelativeTo(SuperRoot var1) {
      return this.getRelativeTo(getBestContainer(var1));
   }

   public static URL getBestContainer(SuperRoot var0) {
      URL var1 = null;
      if (var0 != null) {
         var1 = var0.getContainingSourceURL();
      }

      return var1 == null ? getCurDir() : var1;
   }

   public static String getRelativeTo(URL var0, SuperRoot var1) {
      return var0 == null ? null : var0.getRelativeTo(var1);
   }

   public static URL getHome() {
      return home;
   }

   public static String homeUnalias(String var0) {
      return make("home:" + var0).unalias();
   }

   public static URL getContainingOrCurDir(SuperRoot var0) {
      URL var1 = var0.getContainingSourceURL();
      return var1 == null ? getCurDir() : make(var1._url.substring(0, var1.getBaseIndex()));
   }

   private static void setAvatarServer(String var0) {
      String var1 = protocols.getIniString("avatar", var0);

      try {
         psConversion.put("avatar", new URL(new URL(var1).unalias()));
      } catch (MalformedURLException var3) {
         System.out.println("Avatar protocol is invalid.");
         Debug.assert_(false);
      }
   }

   public static boolean usingCachedAvatars() {
      return useCachedFiles;
   }

   public static void setHttpServer(String var0) {
      psConversion.put("worldshttp", make(var0));
   }

   public static URL getCurDir() {
      return file;
   }

   public static URL getAvatar() {
      return avatar;
   }

   private int getPackageIndex() {
      int var1 = this._url.lastIndexOf(47) + 1;
      if (var1 == 0) {
         var1 = this._url.indexOf(58) + 1;
         if (var1 == 4 && this._url.startsWith("rel:")) {
            var1 = this._url.indexOf(58, 4) + 1;
         }
      }

      return var1;
   }

   public String unalias() {
      String var1 = this.getAbsolute();
      if (var1.endsWith(".class")) {
         int var2 = this.getPackageIndex();
         int var3 = var1.length();
         var1 = var1.substring(0, var2) + var1.substring(var2, var3 - 6).replace('.', '/') + ".class";
      }

      int var10 = var1.indexOf(58);
      String var11 = var1.substring(0, var10);
      Object var4 = psConversion.get(var11);
      if (var4 == null) {
         psConversion.put(var11, psConversion);
         String var5 = protocols.getIniString(var11, "");
         if (var5 != null && !var5.equals("")) {
            try {
               var4 = new URL(new URL(var5).unalias());
               psConversion.put(var11, var4);
            } catch (MalformedURLException var8) {
               System.out.println("Invalid inifile entry for " + var11);
            }
         }
      } else if (var11.equals("avatar") && var1.endsWith(".rwg")) {
         var4 = null;
      }

      if (var4 instanceof URL) {
         URL var12 = (URL)var4;
         Debug.dAssert(!var12._url.startsWith("rel:"));
         if (var12._url.startsWith("file:") && var1.length() > var10 + 1 && var1.charAt(var10 + 1) == '/') {
            var10++;
         }

         var1 = var12._url.substring(0, var12.getBaseIndex()) + var1.substring(var10 + 1);
      }

      if (!var1.startsWith("file:")) {
         return var1;
      }

      var1 = var1.substring(5);

      try {
         var1 = normalize(validateFile(var1));
      } catch (MalformedURLException var7) {
         return var1;
      }

      Debug.dAssert(var1.startsWith("file:"));
      return var1.substring(5);
   }

   public static String searchPath(String var0, String var1) {
      StringTokenizer var2 = new StringTokenizer(var1, File.pathSeparator);

      while (var2.hasMoreTokens()) {
         String var3 = var2.nextToken();
         String var4 = var0;
         if (!var3.equals(".")) {
            var4 = var3 + File.separator + var0;
         }

         File var5 = new File(var4);
         if (var5.exists()) {
            return var4;
         }
      }

      return null;
   }

   public String getClassName() {
      if (!this._url.endsWith(".class")) {
         return null;
      }

      int var1 = this.getPackageIndex();
      int var2 = this._url.length();
      return this._url.substring(var1, var2 - 6);
   }

   public URL getClassDir() {
      return !this._url.endsWith(".class") ? null : make(this._url.substring(0, this.getPackageIndex()));
   }

   public boolean endsWith(String var1) {
      return this._url.endsWith(var1);
   }

   public String getExt() {
      int var1 = this._url.lastIndexOf(46);
      return var1 != -1 && this._url.indexOf(47, var1) < 0 && this._url.indexOf(58, var1) < 0 ? this._url.substring(var1) : "";
   }

   public static String maybeAddExt(String var0, String var1) {
      int var2 = var0.lastIndexOf(46);
      return var2 >= 0 && var0.indexOf(47, var2) < 0 && var0.indexOf(92, var2) < 0 ? var0 : var0 + var1;
   }

   public static URL restore(Restorer var0, String var1) throws IOException {
      return restore(var0, var0.restoreString(), var1);
   }

   public static URL restore(Restorer var0, String var1, String var2) throws IOException {
      if (var1 == null) {
         return null;
      }

      if (var2 != null) {
         var1 = maybeAddExt(var1, var2);
      }

      if (isAbsolute(var1)) {
         return new URL(var1);
      }

      URL var3 = var0.getReferenceURL();
      if (var0.version() >= 6) {
         if (var3 == null) {
            throw new IOException("No absolute base for relative URL " + var1);
         } else {
            return new URL(var3, var1);
         }
      } else {
         if (var1.endsWith(".class")) {
            return make((var1.indexOf(47) < 0 ? "system:" : "file:") + var1);
         }

         String var4 = searchPath(var1, ".;..");
         if (var4 != null) {
            if (var3 == null) {
               return new URL("file:" + var4);
            }

            URL var5 = make(var3.unalias());
            String var6 = new URL("rel:file:" + var4).getRelativeTo(var5);
            return new URL(var3, var6);
         } else {
            System.out.println(var1 + " doesn't exist in RWSHAPEPATH");
            return make(var3, var1);
         }
      }
   }

   public static URL restore(Restorer var0) throws IOException {
      return restore(var0, null);
   }

   public void save(Saver var1) throws IOException {
      String var2 = this.getRelativeTo(var1.getReferenceURL());
      if (var2.startsWith("../") || var2.startsWith("rel:file:") || var2.startsWith("file:")) {
         Console.println(Console.message("path-to-outside") + var2);
      }

      var1.saveString(var2);
   }

   public static void save(Saver var0, URL var1) throws IOException {
      if (var1 == null) {
         var0.saveString(null);
      } else {
         var1.save(var0);
      }
   }

   public boolean equals(Object var1) {
      if (var1 instanceof URL) {
         URL var2 = (URL)var1;
         return this._url.equals(var2.getInternal()) ? true : this.unalias().equals(var2.unalias());
      } else {
         return false;
      }
   }

   public int hashCode() {
      return this.unalias().hashCode();
   }

   public boolean isRemote() {
      String var1 = this.unalias();
      return !var1.startsWith("//") && var1.indexOf(58) >= 2 ? !var1.startsWith("system:") && !var1.startsWith("session:") : false;
   }

   public static String removeDots(String var0) {
      var0 = "/" + var0;
      int var1 = 1;
      int var2 = var1 - 1;

      int var3;
      while ((var3 = var0.indexOf("/.", var2) + 1) > 0) {
         int var4 = var0.indexOf(47, var3);
         if (var4 < 0) {
            break;
         }

         int var5 = var4 - var3;
         int var6 = var3;

         while (var6 < var4 && var0.charAt(var6) == '.') {
            var6++;
         }

         if (var6 != var4) {
            var2 = var4;
         } else {
            while (true) {
               if (var5 == 1) {
                  var4++;
               } else {
                  if (var3 != var1) {
                     var3 = var0.lastIndexOf(47, var3 - 2) + 1;
                     if (var3 <= var1) {
                        var3 = var1;
                     }

                     var5--;
                     continue;
                  }

                  var4 -= var5;
                  var1 += var5 + 1;
               }

               var0 = var0.substring(0, var3) + var0.substring(var4);
               var2 = var1 - 1;
               break;
            }
         }
      }

      return var0.substring(1);
   }

   static {
      Debug.dAssert(currentDir.charAt(1) == ':' || currentDir.startsWith("//"));

      try {
         currentDir = validateFile(currentDir);
      } catch (MalformedURLException var2) {
         var2.printStackTrace(System.out);
         Debug.dAssert(false);
      }

      if (!currentDir.endsWith("/")) {
         currentDir = currentDir + "/";
      }

      home = make(Gamma.getHome());
      file = make("file:");
      psConversion.put("home", home);
      useCachedFiles = true;
      useCachedFiles = IniFile.gamma().getIniInt("useNetworkAvatars", 1) == 1;
      int var0 = IniFile.override().getIniInt("useNetworkAvatars", -1);
      if (var0 != -1) {
         useCachedFiles = var0 == 1;
      }

      String var1 = IniFile.gamma().getIniString("avatarDir", "avatar/");
      if (!var1.endsWith("/")) {
         var1 = var1 + "/";
      }

      if (useCachedFiles) {
         setAvatarServer(NetUpdate.getUpgradeServerURL() + var1);
      } else {
         setAvatarServer("home:avatars/");
      }

      avatar = make("avatar:");
   }
}

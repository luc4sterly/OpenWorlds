package NET.worlds.core;

public class IniFile {
   String file;
   String section;
   static boolean initialized = false;
   private static IniFile gamma_ = null;
   private static IniFile override_ = null;

   public IniFile(String var1) {
      this.file = null;
      this.section = var1;
   }

   private IniFile(String var1, String var2) {
      this.file = var1;
      this.section = var2;
   }

   public static IniFile gamma() {
      if (gamma_ == null) {
         gamma_ = new IniFile("Gamma");
      }

      if (!initialized) {
         nativeInit();
         initialized = true;
      }

      return gamma_;
   }

   public static IniFile override() {
      if (!initialized) {
         nativeInit();
         initialized = true;
      }

      if (override_ == null) {
         override_ = new IniFile(".\\override.ini", "Runtime");
      }

      return override_;
   }

   public native int getIniInt(String var1, int var2);

   public native void setIniInt(String var1, int var2);

   public native String getIniString(String var1, String var2);

   public native void setIniString(String var1, String var2);

   public static native void nativeInit();
}

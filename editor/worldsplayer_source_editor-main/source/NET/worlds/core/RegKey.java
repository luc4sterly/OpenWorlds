package NET.worlds.core;

public class RegKey {
   public static final int CLASSES_ROOT = 0;
   public static final int CURRENT_USER = 1;
   public static final int LOCAL_MACHINE = 2;
   public static final int USERS = 3;
   public static final int KEYOPEN_READ = 0;
   public static final int KEYOPEN_WRITE = 1;
   public static final int KEYOPEN_CREATE = 2;
   private int hKey;

   public static RegKey getRootKey(int var0) throws RegKeyNotFoundException {
      return new RegKey(getReservedKey(var0));
   }

   public RegKey(RegKey var1, String var2, int var3) throws RegKeyNotFoundException {
      if (var3 == 2) {
         this.hKey = createKey(var1.hKey, var2);
      } else {
         this.hKey = openKey(var1.hKey, var2, var3);
      }
   }

   public native String getStringValue(String var1);

   public native boolean setStringValue(String var1, String var2, boolean var3);

   public native int getIntValue(String var1);

   public native boolean setIntValue(String var1, int var2);

   public native void close();

   private static native int getReservedKey(int var0) throws RegKeyNotFoundException;

   private static native int openKey(int var0, String var1, int var2) throws RegKeyNotFoundException;

   private static native int createKey(int var0, String var1);

   public static native void nativeInit();

   private RegKey(int var1) {
      this.hKey = var1;
   }

   static {
      nativeInit();
   }
}

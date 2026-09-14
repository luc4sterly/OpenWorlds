package NET.worlds.network;

public class DDEMLClass {
   private int DDEMLptr = 0;

   public static native void nativeInit();

   public DDEMLClass(String var1, String var2) {
      this.create(var1, var2);
   }

   private native boolean create(String var1, String var2);

   public native void destroy();

   public native boolean Request(String var1);

   public native boolean Poke(String var1, String var2);

   static {
      nativeInit();
   }
}

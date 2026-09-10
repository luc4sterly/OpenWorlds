package NET.worlds.scape;

public class ScapePicTexture {
   private int w;
   private int h;
   private String _urlName;
   private Object _movie;
   private int _movieFrame;

   public static native void nativeInit();
   private native void makeTexture(String name, String mask);

   public ScapePicTexture() {
   }

   public void make(String name, String mask) {
      makeTexture(name, mask);
   }

   public int getW() {
      return w;
   }

   public int getH() {
      return h;
   }

   public static void main(String[] args) throws Exception {
      System.loadLibrary("gamma");
      System.out.println("gamma.dll loaded OK");
      System.out.flush();
      nativeInit();
      System.out.println("nativeInit() OK");
      System.out.flush();
      ScapePicTexture tex = new ScapePicTexture();
      System.out.println("calling makeTexture now:");
      System.out.flush();
      tex.make(args[0], null);
      System.out.println("makeTexture returned");
      System.out.flush();
      System.out.println("w:");
      System.out.println(tex.getW());
      System.out.println("h:");
      System.out.println(tex.getH());
      System.out.flush();
   }
}

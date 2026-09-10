package NET.worlds.console;

public class ScapePicImage {
   private int hDIB;
   private int width;
   private int height;

   public static native void nativeInit();
   private native void loadImage(String path);
   public native void flush();

   public ScapePicImage() {
   }

   public void load(String path) {
      loadImage(path);
   }

   public int getWidth() {
      return width;
   }

   public int getHeight() {
      return height;
   }

   public int getDIB() {
      return hDIB;
   }

   public static void main(String[] args) throws Exception {
      System.loadLibrary("gamma");
      System.out.println("gamma.dll loaded OK");
      nativeInit();
      System.out.println("nativeInit() OK");
      ScapePicImage img = new ScapePicImage();
      System.out.println("calling loadImage now:");
      img.load(args[0]);
      System.out.println("loadImage returned");
      System.out.println("width:");
      System.out.println(img.getWidth());
      System.out.println("height:");
      System.out.println(img.getHeight());
      System.out.println("hDIB:");
      System.out.println(img.getDIB());
   }
}

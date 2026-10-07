package java.awt;

public class MouseInfo {
   private MouseInfo() {
   }

   public static PointerInfo getPointerInfo() {
      return new PointerInfo(GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice(), WindowSystem.pointer());
   }

   public static int getNumberOfButtons() {
      return 3;
   }
}

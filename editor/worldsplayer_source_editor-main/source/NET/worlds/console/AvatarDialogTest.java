package NET.worlds.console;

import java.util.Vector;

public class AvatarDialogTest implements AvatarDialogCallback {
   private static final String[] components = new String[]{"Color", "Weather", "Height", "Shape"};
   private static final String[] colors = new String[]{"Red", "Orange", "Yellow", "Green", "Blue", "Violet"};
   private static final String[] weather = new String[]{"Sunny", "Cloudy", "Raining", "Snowing"};
   private static final String[] heights = new String[]{"Short", "Medium", "Tall"};
   private static final String[] shapes = new String[]{"Circle", "Rectangle", "Triangle"};
   private static final String[][] items = new String[][]{colors, weather, heights, shapes};
   private static int[] settings = new int[components.length];

   public Vector getComponents() {
      return stringsToVector(components);
   }

   public Vector getChoices(int var1) {
      return stringsToVector(items[var1]);
   }

   public int getCurrentSelection(int var1) {
      return settings[var1];
   }

   public void setCurrentSelection(int var1, int var2) {
      settings[var1] = var2;
   }

   private static Vector stringsToVector(String[] var0) {
      Vector var1 = new Vector();

      for (int var2 = 0; var2 < var0.length; var2++) {
         var1.addElement(var0[var2]);
      }

      return var1;
   }
}

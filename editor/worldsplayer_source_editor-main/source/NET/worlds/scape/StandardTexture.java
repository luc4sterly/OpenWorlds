package NET.worlds.scape;

import java.io.IOException;

public class StandardTexture extends Texture implements Persister {
   private String urlName;
   private static Object classCookie = new Object();

   public StandardTexture(String var1, String var2) {
      this.urlName = var1;
      this.makeTexture(var1, var2);
   }

   protected StandardTexture() {
   }

   private void makeTexture(String var1, String var2) {
      this.textureID = new ImageConverter(var1, var2).convert();
   }

   public String getName() {
      return this.urlName;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this.urlName);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this.urlName = var1.restoreString();
            this.makeTexture(this.urlName, this.urlName);
            return;
         default:
            throw new TooNewException();
      }
   }
}

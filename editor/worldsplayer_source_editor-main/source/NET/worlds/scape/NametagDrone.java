package NET.worlds.scape;

import NET.worlds.console.Console;
import java.awt.Color;
import java.io.IOException;

public class NametagDrone extends Drone {
   private static Object classCookie = new Object();

   public void loadInit() {
   }

   public void setName(String var1) {
      super.setName(var1);
      SuperRoot var2 = SuperRoot.nameSearch(this.getContents(), "nametag");
      if (var2 != null && var2 instanceof Hologram) {
         Hologram var3 = (Hologram)var2;
         String var4 = this.getLongID();
         Texture[] var5 = new Texture[]{new StringTexture(var4, Console.message("TextureFont"), 48, Color.black, Color.white)};
         var3.detach();
         Hologram var6 = new Hologram(var5);
         var6.post(var3);
         var6.setScale(var4.length() * 10, 1.0F, 10.0F);
         var6.setVisible(true);
         var6.setBumpable(false);
         var6.setLocalShadowed(false);
         var6.setShadowedLocally(true);
         this.add(var6);
      }
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            return;
         default:
            throw new TooNewException();
      }
   }
}

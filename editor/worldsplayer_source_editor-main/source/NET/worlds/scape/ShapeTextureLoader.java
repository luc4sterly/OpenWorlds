package NET.worlds.scape;

import NET.worlds.network.URL;

class ShapeTextureLoader implements BGLoaded {
   ShapeLoader shapeLoader;

   public ShapeTextureLoader(ShapeLoader var1) {
      this.shapeLoader = var1;
   }

   public Object asyncBackgroundLoad(String var1, URL var2) {
      this.shapeLoader.textureLoadEnd(TextureDecoder.decode(var2, var2.getBaseWithoutExt(), var1));
      return null;
   }

   public boolean syncBackgroundLoad(Object var1, URL var2) {
      return false;
   }

   public Room getBackgroundLoadRoom() {
      return this.shapeLoader.getBackgroundLoadRoom();
   }
}

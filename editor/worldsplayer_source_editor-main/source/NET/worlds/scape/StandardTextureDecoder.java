package NET.worlds.scape;

class StandardTextureDecoder extends TextureDecoder {
   private String exts = "gif;jpg;jpeg;jpe;jfif;xbm";

   protected String getExts() {
      return this.exts;
   }

   protected Texture read(String var1, String var2) {
      return new StandardTexture(var1, var2);
   }
}

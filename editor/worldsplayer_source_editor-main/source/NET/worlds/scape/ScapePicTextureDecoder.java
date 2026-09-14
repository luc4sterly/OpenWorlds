package NET.worlds.scape;

class ScapePicTextureDecoder extends TextureDecoder {
   private String exts = "cmp;mov";

   protected String getExts() {
      return this.exts;
   }

   protected Texture read(String var1, String var2) {
      return new ScapePicTexture(var1, var2);
   }
}

package NET.worlds.scape;

class FileTextureDecoder extends TextureDecoder {
   private String exts = "bmp;ras";

   protected String getExts() {
      return this.exts;
   }

   protected Texture read(String var1, String var2) {
      return new FileTexture(var1, var2);
   }
}

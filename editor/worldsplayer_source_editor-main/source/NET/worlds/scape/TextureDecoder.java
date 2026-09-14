package NET.worlds.scape;

import NET.worlds.network.URL;
import java.io.File;
import java.util.Hashtable;
import java.util.StringTokenizer;

public abstract class TextureDecoder {
   protected static Hashtable handlers = new Hashtable();
   private static TextureDecoder defaultDecoder;
   private static String allExts;

   protected abstract String getExts();

   protected abstract Texture read(String var1, String var2);

   private static void addHandler(TextureDecoder var0) {
      StringTokenizer var1 = new StringTokenizer(var0.getExts(), ";");

      while (var1.hasMoreTokens()) {
         String var2 = var1.nextToken().toLowerCase();
         handlers.put(var2, var0);
         if (allExts == null) {
            allExts = var2;
         } else {
            allExts = allExts + File.pathSeparator + var2;
         }
      }
   }

   public static String getAllExts() {
      return allExts;
   }

   public static String getJavaExts() {
      return new StandardTextureDecoder().getExts();
   }

   public static Texture decode(URL var0, String var1) {
      return decode(var0, var0.getAbsolute(), var1);
   }

   public static Texture decode(URL var0, String var1, String var2) {
      FileTexture var3 = FileTexture.dictLookup(var1);
      if (var3 != null) {
         return var3;
      }

      String var4 = var0.getInternal();
      int var5 = var4.lastIndexOf(46);
      int var6 = var4.lastIndexOf(47);
      var6 = Math.max(var6, var4.lastIndexOf(92));
      var6 = Math.max(var6, var4.lastIndexOf(58));
      if (var5 > var6) {
         String var7 = var4.substring(var5 + 1).toLowerCase();
         TextureDecoder var8 = (TextureDecoder)handlers.get(var7);
         if (var8 != null) {
            Texture var9 = var8.read(var1, var2);
            if (var9.textureID != 0) {
               return var9;
            }
         }
      }

      return null;
   }

   static {
      addHandler(defaultDecoder = new FileTextureDecoder());
      addHandler(new StandardTextureDecoder());
      addHandler(new ScapePicTextureDecoder());
   }
}

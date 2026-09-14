package NET.worlds.scape;

public class CDDBHash {
   public static String hashString(CDTrackInfo var0) {
      String var1 = Integer.toHexString(hash(var0));
      int var2 = var1.length();
      if (var2 >= 8) {
         return var1;
      }

      String var3 = "0";

      while (++var2 < 8) {
         var3 = var3 + "0";
      }

      return var3 + var1;
   }

   public static String lookupString(CDTrackInfo var0) {
      int var1 = var0.getNumTracks();
      String var2 = hashString(var0) + " " + var1;

      for (int var3 = 0; var3 < var1; var3++) {
         var2 = var2 + " " + var0.getStartFrames(var3);
      }

      return var2 + " " + leadOutSecs(var0);
   }

   private static int addDigits(int var0) {
      String var1 = "" + var0;
      int var2 = 0;

      for (int var3 = 0; var3 < var1.length(); var3++) {
         var2 += var1.charAt(var3) - '0';
      }

      return var2;
   }

   private static int leadOutSecs(CDTrackInfo var0) {
      int var1 = var0.getNumTracks() - 1;
      int var2 = var0.getPosM(var1);
      int var3 = var0.getPosS(var1);
      int var4 = var0.getPosF(var1);
      int var5 = var0.getLenM(var1);
      int var6 = var0.getLenS(var1);
      int var7 = var0.getLenF(var1);
      if (++var7 == 75) {
         var7 = 0;
         if (++var6 == 60) {
            var6 = 0;
            var5++;
         }
      }

      var4 += var7;
      var3 += var4 / 75 + var6;
      var2 += var3 / 60 + var5;
      var3 %= 60;
      return var2 * 60 + var3;
   }

   private static int hash(CDTrackInfo var0) {
      int var1 = 0;
      int var2 = var0.getNumTracks();

      for (int var3 = 0; var3 < var2; var3++) {
         var1 += addDigits(var0.getPosM(var3) * 60 + var0.getPosS(var3));
      }

      int var4 = leadOutSecs(var0) - var0.getPosM(0) * 60 - var0.getPosS(0);
      return var1 % 255 << 24 | var4 << 8 | var2;
   }
}

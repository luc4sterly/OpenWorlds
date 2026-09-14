package NET.worlds.scape;

public class CDTrackInfo {
   private int[] pos;
   private int[] len;

   public CDTrackInfo(int var1) {
      this.pos = new int[var1];
      this.len = new int[var1];
   }

   public int getNumTracks() {
      return this.pos.length;
   }

   public int getStartFrames(int var1) {
      return this.getPosM(var1) * 60 * 75 + this.getPosS(var1) * 75 + this.getPosF(var1);
   }

   public int getEndFrames(int var1) {
      return var1 == this.pos.length - 1
         ? this.getStartFrames(var1) + this.getLenM(var1) * 60 * 75 + this.getLenS(var1) * 75 + this.getLenF(var1)
         : this.getStartFrames(var1 + 1) - 1;
   }

   public int getPosM(int var1) {
      return minutes(this.pos[var1]);
   }

   public int getPosS(int var1) {
      return seconds(this.pos[var1]);
   }

   public int getPosF(int var1) {
      return frames(this.pos[var1]);
   }

   public int getLenM(int var1) {
      return minutes(this.len[var1]);
   }

   public int getLenS(int var1) {
      return seconds(this.len[var1]);
   }

   public int getLenF(int var1) {
      return frames(this.len[var1]);
   }

   private static int minutes(int var0) {
      return var0 & 0xFF;
   }

   private static int seconds(int var0) {
      return var0 >> 8 & 0xFF;
   }

   private static int frames(int var0) {
      return var0 >> 16 & 0xFF;
   }

   private static String format2(int var0) {
      String var1 = "";
      if (var0 < 10) {
         var1 = "0";
      }

      return var1 + var0;
   }

   private static String format(int var0) {
      return "" + minutes(var0) + ":" + format2(seconds(var0)) + ":" + format2(frames(var0));
   }

   public void dump() {
      System.out.println("Tracks: " + this.pos.length);

      for (int var1 = 0; var1 < this.pos.length; var1++) {
         System.out.println("Track " + var1 + " " + "start " + format(this.pos[var1]) + " length " + format(this.len[var1]));
      }
   }
}

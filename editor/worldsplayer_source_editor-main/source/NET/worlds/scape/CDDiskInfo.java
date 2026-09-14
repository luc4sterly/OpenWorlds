package NET.worlds.scape;

import java.io.IOException;

public class CDDiskInfo implements Persister {
   private String artist;
   private String title;
   private String category;
   private String[] trackNames;
   private static Object classCookie = new Object();

   public CDDiskInfo(String var1, String var2, String var3, String[] var4) {
      this.artist = var1;
      this.title = var2;
      this.category = var3;
      this.trackNames = new String[var4.length];
      System.arraycopy(var4, 0, this.trackNames, 0, var4.length);
   }

   public CDDiskInfo() {
   }

   public String getArtist() {
      return this.artist;
   }

   public String getTitle() {
      return this.title;
   }

   public String getCategory() {
      return this.category;
   }

   public int getNumTracks() {
      return this.trackNames.length;
   }

   public String getTrackName(int var1) {
      return this.trackNames[var1];
   }

   public String toString() {
      String var1 = "Artist: " + this.artist + "\n" + "Title: " + this.title + "\n" + "Category: " + this.category + "\n";

      for (int var2 = 0; var2 < this.trackNames.length; var2++) {
         var1 = var1 + "Track " + (var2 + 1) + ":";
         if (this.trackNames[var2] != null) {
            var1 = var1 + this.trackNames[var2];
         }

         var1 = var1 + "\n";
      }

      return var1;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      var1.saveString(this.artist);
      var1.saveString(this.title);
      var1.saveString(this.category);
      var1.saveInt(this.trackNames.length);

      for (int var2 = 0; var2 < this.trackNames.length; var2++) {
         var1.saveString(this.trackNames[var2]);
      }
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 1:
            this.artist = var1.restoreString();
            this.title = var1.restoreString();
            this.category = var1.restoreString();
            this.trackNames = new String[var1.restoreInt()];

            for (int var2 = 0; var2 < this.trackNames.length; var2++) {
               this.trackNames[var2] = var1.restoreString();
            }

            return;
         default:
            throw new TooNewException();
      }
   }

   public void postRestore(int var1) {
   }
}

package NET.worlds.scape;

class MusicTrack {
   private String name;
   private int vTrack;
   private String midi;
   private boolean loop;

   public MusicTrack(String var1, int var2, String var3, boolean var4) {
      this.name = var1;
      this.vTrack = var2;
      this.midi = var3.equals("-") ? "" : var3;
      this.loop = var4;
   }

   public String getName() {
      return this.name;
   }

   public void setName(String var1) {
      this.name = var1;
   }

   public int getVirtTrackNumber() {
      return this.vTrack;
   }

   public void setVirtTrackNumber(int var1) {
      this.vTrack = var1;
   }

   public String getMIDIFileName() {
      return this.midi;
   }

   public void setMIDIFileName(String var1) {
      this.midi = var1;
   }

   public boolean getLooping() {
      return this.loop;
   }

   public void setLooping(boolean var1) {
      this.loop = var1;
   }

   public String toString() {
      return this.name;
   }
}

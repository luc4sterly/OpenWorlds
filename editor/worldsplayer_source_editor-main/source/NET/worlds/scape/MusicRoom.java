package NET.worlds.scape;

class MusicRoom {
   private String roomName;
   private String musicName;

   public MusicRoom(String var1, String var2) {
      this.roomName = var1;
      this.musicName = var2;
   }

   public String getRoomName() {
      return this.roomName;
   }

   public void setRoomName(String var1) {
      this.roomName = var1;
   }

   public String getMusicName() {
      return this.musicName;
   }

   public void setMusicName(String var1) {
      this.musicName = var1;
   }

   public String toString() {
      return this.roomName;
   }
}

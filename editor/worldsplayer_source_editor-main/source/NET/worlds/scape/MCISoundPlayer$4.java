package NET.worlds.scape;

class MCISoundPlayer$4 extends MCISoundCommand {
   MCISoundPlayer this$0;

   MCISoundPlayer$4(MCISoundPlayer var1) {
      this.this$0 = var1;
   }

   public void run() {
      if (!WavSoundPlayer.ignoreVolumeChanges) {
         MCISoundPlayer.access$300(this.this$0, this.left, this.right);
      }
   }
}

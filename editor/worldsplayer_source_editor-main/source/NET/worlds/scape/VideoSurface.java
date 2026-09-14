package NET.worlds.scape;

public class VideoSurface extends TextureSurface {
   protected DirectShow _ds;
   protected String _currentURL;
   protected int referenceCount = 0;

   public VideoSurface(Texture[] var1, int var2, int var3, int var4) {
      super(var1, var2, var3, var4);
      this._ds = new DirectShow(this.getHwnd());
   }

   public void incReferenceCount() {
      this.referenceCount++;
   }

   public void decReferenceCount() {
      this.referenceCount--;
   }

   public int getReferenceCount() {
      return this.referenceCount;
   }

   public int tick() {
      return this._ds.nTick();
   }

   public String getVideoUrl() {
      return this._currentURL;
   }

   public void open(String var1) {
      if (this._currentURL == null || !this._currentURL.equals(var1)) {
         this._ds.nStop();
         this._ds.nOpen(var1);
         this._currentURL = var1;
      }
   }

   public void stop() {
      this._ds.nStop();
   }

   public void play(int var1) {
      this._ds.nPlay(var1);
   }

   public synchronized void draw(Texture[] var1, int var2) {
      this.setTextures(var1, var2);
      this.draw(this._ds);
   }
}

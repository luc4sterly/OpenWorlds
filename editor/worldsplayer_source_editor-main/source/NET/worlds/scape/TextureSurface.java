package NET.worlds.scape;

public class TextureSurface {
   private Texture[] _textures;
   private int _hwnd;
   private int _oldObject;
   private int _offscreen;
   private int _texWidth;
   private int _texHeight;
   private int _width;
   private int _height;
   private int _rows;
   private int _cols;

   public TextureSurface(Texture[] var1, int var2, int var3, int var4) {
      this._width = var3;
      this._height = var4;
      this._oldObject = 0;
      this._hwnd = this.nativeInit(var3, var4);
      this._offscreen = this.nativeMakeDC(this._hwnd, var3, var4);
      if (var1 != null) {
         this.setTextures(var1, var2);
      }
   }

   public void finalize() {
      this.nativeDestroyDC(this._offscreen);
      this._oldObject = 0;
   }

   public void setTextures(Texture[] var1, int var2) {
      this._textures = var1;
      this._rows = var2;
      this._cols = var1.length / var2;
      this._texWidth = this._width / this._cols;
      this._texHeight = this._height / this._rows;
   }

   public synchronized boolean draw(TextureSurfaceRenderer var1) {
      var1.renderTo(this._offscreen);
      int var2 = 0;

      for (int var3 = this._rows - 1; var3 >= 0; var3--) {
         for (int var4 = 0; var4 < this._cols; var4++) {
            if (this._textures[var2] != null) {
               this._textures[var2]
                  .copyFrom(this._offscreen, var4 * this._texWidth, (var4 + 1) * this._texWidth, var3 * this._texHeight, (var3 + 1) * this._texHeight);
            }

            var2++;
         }
      }

      return false;
   }

   public void sendLeftClick(int var1, int var2) {
      this.nativeLeftClick(this._hwnd, var1, var2);
   }

   public int getHwnd() {
      return this._hwnd;
   }

   public int getWidth() {
      return this._width;
   }

   public int getHeight() {
      return this._height;
   }

   private native int nativeInit(int var1, int var2);

   private native int nativeMakeDC(int var1, int var2, int var3);

   private native int nativeGetDC(int var1);

   private native void nativeReleaseDC(int var1, int var2);

   private native void nativeDestroyDC(int var1);

   private native void nativeLeftClick(int var1, int var2, int var3);
}

package NET.worlds.scape;

import NET.worlds.core.IniFile;
import NET.worlds.network.URL;
import java.io.IOException;

public class VideoWall extends Rect {
   VideoSurface _surface = null;
   Texture[] _textures;
   Material _material = null;
   String _textureURL = "http://dev.worlds.net/rr-worlds/video/fatboy.asf";
   String _defTextureURL = IniFile.override().getIniString("defaultAd", "adworlds.cmp");
   int _xSurface = 140;
   int _ySurface = 104;
   boolean _autoPlay = true;
   int _autoPlayRepeats = 1;
   int _rows = 1;
   private static Object classCookie = new Object();

   private void rebuild() {
      this.unbuild();
      int var1 = this._xSurface / 128 + 1;
      int var2 = this._ySurface / 128 + 1;
      this._surface = null;
      this._rows = var2;
      this._material = new Material(URL.make(this._defTextureURL), var1, var2);
      this.setMaterial(this._material);
      this._textures = this._material.getTextures();
      this._surface = VideoManager.get(this._textureURL, var2, this._xSurface, this._ySurface);
      if (this._autoPlay) {
         this._surface.play(1);
      }
   }

   public void finalize() {
      this.unbuild();
      super.finalize();
   }

   public void detach() {
      this.unbuild();
      super.detach();
   }

   private void unbuild() {
      if (this._surface != null) {
         this._surface.stop();
         VideoManager.release(this._surface);
         this._surface = null;
      }
   }

   public void changeURL(String var1, int var2, int var3) {
      this._textureURL = new String(var1);
      this._xSurface = var2;
      this._ySurface = var3;
      this.rebuild();
   }

   public boolean handle(FrameEvent var1) {
      this.getState();
      if (this.visible) {
         this.draw();
      }

      return false;
   }

   public void prerender(Camera var1) {
      Point3Temp var2 = this.inCamSpace(var1);
      boolean var3 = var2 != null && var2.z > 1.0F && var2.x < var2.z && -var2.x < var2.z;
      if (var3) {
         this.visible = true;
      }
   }

   public VideoSurface getVideoSurface() {
      return this._surface;
   }

   public synchronized void draw() {
      if (this._surface != null) {
         this._surface.draw(this._material.getTextures(), this._rows);
      }
   }

   public int getState() {
      return this._surface != null ? this._surface.tick() : 0;
   }

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Video URL"));
            } else if (var3 == 1) {
               var5 = this._textureURL;
            } else if (var3 == 2) {
               this._textureURL = (String)var4;
               this.rebuild();
            }
            break;
         case 1:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Video Width (pixels)"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._xSurface);
            } else if (var3 == 2) {
               this._xSurface = (Integer)var4;
               this.rebuild();
            }
            break;
         case 2:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Video Height (pixels)"), 0, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._ySurface);
            } else if (var3 == 2) {
               this._ySurface = (Integer)var4;
               this.rebuild();
            }
            break;
         case 3:
            if (var3 == 0) {
               var5 = BooleanPropertyEditor.make(new Property(this, var1, "Auto-play?"), "No", "Yes");
            } else if (var3 == 1) {
               var5 = new Boolean(this._autoPlay);
            } else if (var3 == 2) {
               this._autoPlay = (Boolean)var4;
               this.rebuild();
            }
            break;
         case 4:
            if (var3 == 0) {
               var5 = IntegerPropertyEditor.make(new Property(this, var1, "Repeats for Autoplay (-1 = infinite)"), -1, 1024);
            } else if (var3 == 1) {
               var5 = new Integer(this._autoPlayRepeats);
            } else if (var3 == 2) {
               this._autoPlayRepeats = (Integer)var4;
               this.rebuild();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 5, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(1, classCookie);
      super.saveState(var1);
      var1.saveString(this._textureURL);
      var1.saveInt(this._xSurface);
      var1.saveInt(this._ySurface);
      var1.saveBoolean(this._autoPlay);
      var1.saveInt(this._autoPlayRepeats);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._textureURL = var1.restoreString();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this._autoPlay = var1.restoreBoolean();
            break;
         case 1:
            super.restoreState(var1);
            this._textureURL = var1.restoreString();
            this._xSurface = var1.restoreInt();
            this._ySurface = var1.restoreInt();
            this._autoPlay = var1.restoreBoolean();
            this._autoPlayRepeats = var1.restoreInt();
            break;
         default:
            throw new TooNewException();
      }

      this.rebuild();
   }
}
